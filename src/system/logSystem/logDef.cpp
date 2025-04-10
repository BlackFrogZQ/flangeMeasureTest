#include "logDef.h"
#include "system/tool/fileTool.h"
#include <QDateTime>
#include <QMutex>
#include <QDir>
#include <QRegExp>
QString CLogDef::getInfoLogName()
{
    return getLogName(InfoLog);
}

QString CLogDef::getDateLogName()
{
    return getLogName(DateLog);
}

void CLogDef::writeLog(QString p_logName, QString p_msg)
{
    static QMutex gLogMutex;
    gLogMutex.lock();
    QFile file(p_logName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        file.write(p_msg.toStdString().data());
        file.write("\n");
        file.flush();
        file.close();
    }
    gLogMutex.unlock();
}

QString CLogDef::getLogName(const CLogType &p_type)
{
    auto dateTime = QDateTime::currentDateTime();
    const QString cDir = getAppDir() + QString("/%2_Log/%1").arg(dateTime.toString("yyyy.MM")).arg(_ProjectName);
    TIGER_FlieTool::createDir(cDir);
    switch (p_type)
    {
    case InfoLog:
        return cDir + QString("/%1_infoLog.txt").arg(dateTime.toString("yyyy.MM.dd"));
    case DateLog:
        return cDir + QString("/%1_dataLog.txt").arg(dateTime.toString("yyyy.MM.dd"));
    default:
        assert(false);
        break;
    }
    return "";
}

QList<CLogMonthInfo> CLogDef::getAllLog()
{
    const QString cDir = getAppDir() + QString("/%1_Log").arg(_ProjectName);

    auto getMonthNames = [](QString p_dir)
    {
        QDir dir(p_dir);
        assert(dir.exists());
        dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
        dir.setSorting(QDir::Name);
        QRegExp reg("^\\d{4}.\\d{2}$");
        QStringList names;
        for (auto name : dir.entryList())
        {
            if (reg.exactMatch(name))
            {
                names << name;
            }
        }
        return names;
    };

    auto getDayNames = [](QString p_monthdir, CLogMonthInfo &p_monthInfo)
    {
        QDir dir(p_monthdir);
        assert(dir.exists());
        dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
        dir.setSorting(QDir::Name);

        dir.setNameFilters(QStringList() << QString("*.txt"));
        auto &dayLogPaths = p_monthInfo.dayLogPaths;
        dayLogPaths.clear();
        const QString cPer = QString("%1.").arg(p_monthInfo.yearMonth);
        const QString cSuf = QString("_infoLog.txt");
        QRegExp reg(QString("^%1\\d{2}%2$").arg(cPer).arg(cSuf));
        for (auto name : dir.entryList())
        {
            if (reg.exactMatch(name))
            {
                dayLogPaths.append(CLogDayInfo(name.remove(cPer).remove(cSuf).toInt(), QString("%1/%2").arg(p_monthdir).arg(name)));
            }
        }
        return dayLogPaths.size() > 0;
    };

    auto monthNames = getMonthNames(cDir);
    QList<CLogMonthInfo> allLog;

    for (auto month : monthNames)
    {
        CLogMonthInfo monthInfo(month);
        if (getDayNames(cDir + "/" + month, monthInfo))
        {
            allLog << monthInfo;
        }
    }
    myTrace("getAllLog:" << allLog);
    return allLog;
}
