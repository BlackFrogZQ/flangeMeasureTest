#include "textBrowser.h"
#include "system/basic.h"
#include "logBrowser.h"
#include "system/logSystem/logDef.h"
#include <QDesktopServices>
#include <QEvent>
#include <QFileInfo>
CTextBrowser::CTextBrowser(QWidget *mainWindow, QWidget *parent) : QTextBrowser(parent), m_pMainWindow(mainWindow)
{
    assert(m_pMainWindow != nullptr);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
    this->setOpenLinks(false);
    this->setOpenExternalLinks(false);
    this->setMinimumHeight(75);
    connect(this, &QTextBrowser::anchorClicked, [](const QUrl &p_url)
            { QDesktopServices::openUrl(p_url); });
    this->viewport()->installEventFilter(this);
}

CTextBrowser::~CTextBrowser()
{
}


bool CTextBrowser::eventFilter(QObject *pObject, QEvent *pEvent)
{
    if (pObject == this->viewport() && pEvent->type() == QEvent::MouseButtonDblClick)
    {
        execLogTextBrowser();
        return true;
    }
    return QTextBrowser::eventFilter(pObject, pEvent);
}

void CTextBrowser::execLogTextBrowser()
{
    CLogBrowser aa(m_pMainWindow);
    aa.resize(m_pMainWindow->size() * 0.9);
    aa.showLogs(CLogDef::getAllLog());
}
