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

void logOutput(QtMsgType p_type, const QMessageLogContext& p_context, const QString& p_msg);

class CVmControl : public ISystemService
{
public:
    CVmControl();
    void init();
    virtual void printMsg(QString p_msg);
    virtual void restartSys() const;
    virtual void updateParas();
    // virtual void restartCamera(TIGER_Camera::CMatrixCameraId id = TIGER_Camera::visionCamera);
    void load();
    void save();

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
    myWarning << QObject::tr("程序开始");
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