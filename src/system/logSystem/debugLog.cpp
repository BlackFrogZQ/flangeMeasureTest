#include "system/systemService.h"
#include <QString>
#include <QDateTime>
#include <iostream>

void logOutput(QtMsgType p_type, const QMessageLogContext &p_context, const QString &p_msg)
{
    QString msgType("");
    QString msg = p_msg;
    QString wirteMsg = QString("[%1]:%2").arg(QDateTime::currentDateTime().toString("hh.mm.ss.zzz")).arg(msg);
    switch (p_type)
    {
    case QtInfoMsg:
        msgType = QString("Info");
        sys()->printMsg(msg);
        break;
    case QtDebugMsg:
        msgType = QString("Debug");
        break;
    case QtWarningMsg:
        msgType = QString("Warning");
        break;
    case QtCriticalMsg:
        msgType = QString("Critical");
        break;
    case QtFatalMsg:
        msgType = QString("Fatal");
        break;
    default:
        msgType = QString("Unknown Type");
        break;
    }
    const QString cFile = QString("file:%1,line:%2")
                              .arg(p_context.file, 20, ' ')
                              .arg(p_context.line);

    wirteMsg = QString("%3%1msg--%2\n").arg(msgType, 12, '-').arg(wirteMsg).arg(cFile,-100,' ');
    // 设置输出信息格式
    std::cout << wirteMsg.toUtf8().data() << std::endl;
};