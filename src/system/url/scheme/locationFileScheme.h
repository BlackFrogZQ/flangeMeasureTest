#pragma once
#include "system/basic.h"
namespace TIGER_Url
{
    class CBSUrlLocationFileScheme : public QObject
    {
        Q_OBJECT
    public:
        CBSUrlLocationFileScheme(QObject *p = nullptr);
        ~CBSUrlLocationFileScheme();
        static QString getLocationFileUrl(QString p_file);
        static QString getOpenAndLocationFileUrl(QString p_file);
        static QString getScheme();
        static QString getUrlSlotFunName();
    public slots:
        void openBSLocationFile(const QUrl &url);
    };
}