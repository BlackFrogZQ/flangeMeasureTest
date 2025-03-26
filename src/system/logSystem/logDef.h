#pragma once
#include <QString>
#include <QColor>
#include <QDebug>
struct CLogDayInfo
{
    int day;
    QString path;
    CLogDayInfo(int p_day = 0, QString p_path = "")
        : day(p_day), path(p_path) {}
    bool operator==(const CLogDayInfo &a)
    {
        return a.day == day;
    }

    bool operator==(const int &p_day)
    {
        return p_day == day;
    }

    bool operator<(const CLogDayInfo &a)
    {
        return a.day < day;
    }
    friend QDebug operator<<(QDebug out, const CLogDayInfo &info)
    {
        out << QString("CLogDayInfo - day:%1,path:%2").arg(QString::number(info.day),2,'0').arg(info.path);
        return out;
    }
};
struct CLogMonthInfo
{
    QString yearMonth; // yyyy.dd
    QList<CLogDayInfo> dayLogPaths;
    CLogMonthInfo(QString p_yearMonth = "") : yearMonth(p_yearMonth) {}
    friend QDebug operator<<(QDebug out, const CLogMonthInfo &info)
    {
        out << QString("CLogMonthInfo - Month:%1").arg(info.yearMonth) << endl;
        for (const auto &day : info.dayLogPaths)
        {
            out << "\t" << day << endl;
        }

        return out;
    }
};

class CLogDef
{
public:
    static QString getInfoLogName();
    static QString getDateLogName();
    // 内部带锁
    static void writeLog(QString p_logName, QString p_msg);
    static QList<CLogMonthInfo> getAllLog();

protected:
    enum CLogType
    {
        InfoLog,
        DateLog
    };
    static QString getLogName(const CLogType &p_type);
};