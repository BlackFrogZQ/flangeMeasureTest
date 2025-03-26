#include "basic.h"
// #include "para/define/cameraDef.h"
#include <QDir>
#include <QApplication>
#include <QTextCodec>
#include <QStandardPaths>

void mySleepMs(int timeout)
{
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timer.start(timeout);
    loop.exec();
    timer.stop();
}

int imageW()
{
    // return TIGER_CameraDef::cameraParas()->imageW;
    return 0;
}
int imageH()
{
    // return TIGER_CameraDef::cameraParas()->imageH;
    return 0;
}

QString getAppDir()
{
#ifdef Trace
    return QDir::currentPath();
#else
    return QApplication::applicationDirPath();
#endif
}

QString getAppConfigDir()
{
#ifdef Trace
    return QDir::currentPath();
#else
    return QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
#endif
}

#ifdef Q_OS_WIN
#include <Windows.h>
#include <clocale>
#include <QProcess>

void addDelayDllDir(QString p_path, bool p_isAbs)
{
    QString addPath = p_path;
    if (!p_isAbs)
    {
        addPath = QString("%1/%2").arg(QApplication::applicationDirPath()).arg(p_path);
    }
    myDebug << "addDelayDllDir:" << addPath;
    SetDefaultDllDirectories(LOAD_LIBRARY_SEARCH_APPLICATION_DIR | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS | LOAD_LIBRARY_SEARCH_SYSTEM32 | LOAD_LIBRARY_SEARCH_USER_DIRS);
    AddDllDirectory(addPath.toStdWString().c_str());
}

bool exeAdminCmd(QString p_cmd, QString &p_msg)
{
    p_cmd = QString("/c ") + p_cmd;
    int ret = (int)ShellExecuteW(nullptr,
                                 QString("runas").toStdWString().c_str(),
                                 QString("cmd.exe").toStdWString().c_str(),
                                 p_cmd.toStdWString().c_str(),
                                 getAppDir().toStdWString().c_str(),
                                 SW_HIDE);
    myDebug << QString("exeAdminCmd error code:0x%1").arg(iToHex(ret, 8)) << endl
            << "\t cmd: " << p_cmd;
    p_msg.clear();
    if (ret <= 32)
    {
#define caseError(code)         \
    case code:                  \
        p_msg = QString(#code); \
        break
        switch (ret)
        {
        case 0:
            p_msg = QString("ERROR_Not_Enough_Memory");
            break;
            caseError(ERROR_FILE_NOT_FOUND);
            caseError(ERROR_PATH_NOT_FOUND);
            caseError(ERROR_ACCESS_DENIED);
            caseError(ERROR_BAD_FORMAT);
            caseError(ERROR_INVALID_ACCESS);
            caseError(ERROR_NOT_DOS_DISK);
            caseError(ERROR_SECTOR_NOT_FOUND);
            caseError(ERROR_OUT_OF_PAPER);
            caseError(ERROR_WRITE_FAULT);
            caseError(ERROR_READ_FAULT);
            caseError(ERROR_GEN_FAILURE);
        default:
            p_msg = QString("ERROR_UNKNOWN");
            break;
        }
#undef caseError
    }
    return ret > 32;
}

void setConsoleOutputCPUtf8(QString locale)
{
    assert(!locale.isNull());
    std::setlocale(LC_ALL, QString("%1.utf8").arg(locale).toStdString().c_str());
    setlocale(LC_ALL, QString("%1.utf8").arg(locale).toStdString().c_str());
    SetConsoleOutputCP(CP_UTF8);
}

#endif