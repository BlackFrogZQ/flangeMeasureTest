#include "systemService.h"
#include "ui/mainWindow.h"
#include "para/para.h"
#include "para/define/paraDef.h"
#include "logSystem/logDef.h"
#include <QString>
#include <QDateTime>
#include <QProcess>
#include <QDir>
#include <QMutex>
#include <QApplication>
#include <QTranslator>
#include <QSettings>
#include <windows.h>

void logOutput(QtMsgType p_type, const QMessageLogContext& p_context, const QString& p_msg);

class CVmControl : public ISystemService
{
public:
    CVmControl();
    void init();
    QMap<QString, QString> enumVmNativeCOM();
    virtual void printMsg(QString p_msg);
    virtual void restartSys() const;
    virtual void updateParas();
    // virtual void restartCamera(TIGER_Camera::CMatrixCameraId id = TIGER_Camera::visionCamera);
    virtual void load();
    virtual void save();

protected:
    ~CVmControl();

protected:
    QStringList m_msgBuffer;
};

CVmControl::CVmControl()
    : ISystemService()
{
}

CVmControl::~CVmControl()
{
    myWarning << QObject::tr("程序结束");
}

void CVmControl::init()
{
    pNativeVmCOMObject = enumVmNativeCOM();
    myWarning << QObject::tr("程序开始");
}

QMap<QString, QString> CVmControl::enumVmNativeCOM()
{
    QMap<QString, QString> result;
    HKEY hKeyRoot = nullptr;
    if (RegOpenKeyExW(HKEY_CLASSES_ROOT, L"", 0, KEY_READ | KEY_WOW64_64KEY, &hKeyRoot) != ERROR_SUCCESS)
    {
        return result;
    }

    DWORD index = 0;
    wchar_t name[256];
    DWORD nameLen = _countof(name);
    while (RegEnumKeyExW(hKeyRoot, index++, name, &nameLen, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS)
    {
        QString keyName = QString::fromWCharArray(name);
        if (!keyName.startsWith("Vm"))
        {
            nameLen = _countof(name);
            continue;
        }

        HKEY hKeyClsid = nullptr;
        QString subPath = keyName + "\\CLSID";
        if (RegOpenKeyExW(hKeyRoot, (LPCWSTR)subPath.utf16(), 0, KEY_READ | KEY_WOW64_64KEY, &hKeyClsid) == ERROR_SUCCESS)
        {
            wchar_t data[64];
            DWORD dataLen = sizeof(data);
            DWORD type = 0;
            if (RegQueryValueExW(hKeyClsid, nullptr, nullptr, &type, (LPBYTE)data, &dataLen) == ERROR_SUCCESS && type == REG_SZ)
            {
                result[keyName] = QString::fromWCharArray(data);
            }
            RegCloseKey(hKeyClsid);
        }
        nameLen = _countof(name);
    }
    RegCloseKey(hKeyRoot);
    return result;
}

void CVmControl::printMsg(QString p_msg)
{
    p_msg = QDateTime::currentDateTime().toString("[hh:mm:ss.zzz]:%1").arg(p_msg);
    CLogDef::writeLog(CLogDef::getInfoLogName(), p_msg);
    m_msgBuffer << p_msg;
    if (mainWindow() != nullptr)
    {
        QMetaObject::invokeMethod(
            mainWindow(), [outMsg = m_msgBuffer.join("\n")]
            { mainWindow()->printMsg(outMsg); },
            Qt::QueuedConnection);
        m_msgBuffer.clear();
    }
}

void CVmControl::restartSys() const
{
    qApp->exit();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}

void CVmControl::updateParas()
{
    // for (int i = 0; i < TIGER_Camera::CMatrixCameraId::maxCamera; i++)
    // {
    //     auto cameraType = TIGER_Camera::CMatrixCameraId(i);
    //     auto pCamera = camera(cameraType);
    //     if (pCamera != nullptr)
    //     {
    //         QMetaObject::invokeMethod(pCamera, "updateParas", Qt::QueuedConnection, Q_ARG(TIGER_CameraDef::CCameraPara, *TIGER_CameraDef::cameraParas(cameraType)));
    //     }
    // }

    // QMetaObject::invokeMethod(mainWindow(), "updateGraphicsParas", Qt::QueuedConnection);
}

// void CVmControl::restartCamera(TIGER_Camera::CMatrixCameraId id)
// {
    // TIGER_Camera::CCameraCreator::destroyCamera(id);
    // TIGER_Camera::CCameraCreator::createCamera(TIGER_CameraDef::cameraParas(id)->cameraType, id);
// }



void CVmControl::load()
{
    paraService()->load();
}

void CVmControl::save()
{
    paraService()->save();
}

ISystemService *g_sysService = nullptr;
ISystemService *sys()
{
	return g_sysService;
}

void initSystemService()
{
	TIGER_ParaDef::initParaRootNode();
    g_sysService = new CVmControl;
	qInstallMessageHandler(logOutput);
    sys()->load();
    ((CVmControl *)g_sysService)->init();
}

void closeSystemService()
{
    sys()->save();
    delete g_sysService;
    g_sysService = nullptr;
}