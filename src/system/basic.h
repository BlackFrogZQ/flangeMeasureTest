#pragma once
#include <QDialog>
#include <QDebug>
#include <QEventLoop>
#include <QTimer>
#include <QObject>

#define iToStr(num) QString::number(num)
#define iToHex(num, size) QString("%1").arg(QString::number(num, 16), size, '0')
#define dToStr(num,decimals) QString::number(num,'f',decimals)
#define cnStr(str) QString::fromLocal8Bit(str)
#define cnHStr(str) QString::fromLocal8Bit(str).toStdString().data()
#define qToHStr(str) (str).toStdString().data()
#define hToQStr(str) (str).S().Text()
#define cToHStr(str) (str).toStdString().c_str()

#define myDebug qDebug().noquote()
#define myInfo qInfo().noquote()
#define myWarning qWarning().noquote()

#ifdef Trace
#define myTrace(qDebugMsg) myDebug << "myTrace:" << qDebugMsg
#else
#define myTrace(qDebugMsg)
#endif

#ifdef Trace
#define trace(qDebugMsg) qDebug() << "trace:" << qDebugMsg
#else
#define trace(qDebugMsg)
#endif

#define delPtr(ptr)     \
    if (ptr != nullptr) \
    {                   \
        delete ptr;     \
        ptr = nullptr;  \
    }

void mySleepMs(int timeout);
int imageW();
int imageH();
QString getAppDir();
QString getAppConfigDir();