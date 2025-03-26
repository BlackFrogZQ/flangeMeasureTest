#include "locationFileScheme.h"
#include <QFileInfo>
#include <QProcess>
#include <QUrl>

namespace TIGER_Url
{
    CBSUrlLocationFileScheme::CBSUrlLocationFileScheme(QObject *p) : QObject(p)
    {
    }

    CBSUrlLocationFileScheme::~CBSUrlLocationFileScheme()
    {
    }

    QString CBSUrlLocationFileScheme::getScheme()
    {
        return "bslocationfile";
    }

    QString CBSUrlLocationFileScheme::getUrlSlotFunName()
    {
        return "openBSLocationFile";
    }

    QString CBSUrlLocationFileScheme::getLocationFileUrl(QString p_file)
    {
        QFileInfo info(p_file);
        return QString("%1:%2").arg(getScheme()).arg(info.absoluteFilePath());
    }

    QString CBSUrlLocationFileScheme::getOpenAndLocationFileUrl(QString p_file)
    {
        QFileInfo info(p_file);
        const QString httpStr = QObject::tr(" <a href=\"file:///%1\">点击打开文件(%2)</a>或<a href=\"%3:%1\">点击打开文件所在文件夹</a>");
        return httpStr.arg(info.absoluteFilePath()).arg(info.fileName()).arg(getScheme());
    }

    void CBSUrlLocationFileScheme::openBSLocationFile(const QUrl &p_url)
    {
        QString urlStr = p_url.toString();
        const QString cSchemeMark = getScheme().toLower() + ":";
        if (urlStr.left(cSchemeMark.size()) == cSchemeMark)
        {
            QFileInfo fileInfo(urlStr.remove(0, cSchemeMark.size()));
            if (fileInfo.exists())
            {
                QProcess::startDetached(QString("explorer /select, %1").arg(fileInfo.absoluteFilePath().replace("/", "\\")));
                return;
            }
        }
        myInfo << QString("open url fail. Url:%1").arg(urlStr);
    }

}