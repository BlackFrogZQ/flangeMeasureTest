#include "logDef.h"
#include "system/systemService.h"
#include <QDateTime>
void logOutput(QtMsgType type, const QMessageLogContext &context, const QString &p_msg)
{
    QString msg = p_msg;
    switch (type)
    {
    case QtInfoMsg:
        sys()->printMsg(msg);
        break;
    case QtDebugMsg:
    case QtWarningMsg:
        CLogDef::writeLog(CLogDef::getDateLogName(), QDateTime::currentDateTime().toString("[hh.mm.ss.zzz]:%1").arg(msg));
        break;
    case QtCriticalMsg:
        // msgType = QString("Critical");
        break;
    case QtFatalMsg:
        // msgType = QString("Fatal");
        break;
    default:
        // msgType = QString("Unknown Type");
        break;
    }
};