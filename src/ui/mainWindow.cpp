#include "mainWindow.h"
#include "basic.h"
#include "logTextBrowser/textBrowser.h"
#include "system/basic.h"
#include "hal/DZSTMark/DZSTMark.h"
#include "controlWindow/controlWindow.h"
#include "menuBar/menuBar.h"
#include <QTextBrowser>
#include <QVBoxLayout>

CMainWindow* g_pMainWindow = nullptr;
CMainWindow* mainWindow()
{
    return g_pMainWindow;
};

CMainWindow::CMainWindow(QWidget *parent) : QWidget(parent)
{
    g_pMainWindow = this;

    m_hWnd = (HWND)this->winId();
    m_pCDZSTMark = new CDZSTMark(m_hWnd);

    init();

    myInfo << cnStr("程序开始");
}

CMainWindow::~CMainWindow()
{
    delPtr(m_pCDZSTMark);
}

void CMainWindow::printMsg(QString p_msg)
{
    const QString cFont = "<font color=\"#0000FF\">%1</font>";
    m_pOutMsg->append(cFont.arg(p_msg.replace("\n", "<br>")));
    m_pOutMsg->moveCursor(m_pOutMsg->textCursor().End);
}

bool CMainWindow::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
	Q_UNUSED(eventType);

	MSG* msg = static_cast<MSG*>(message);
    m_pCDZSTMark->nativeEvent(msg);

	return QWidget::nativeEvent(eventType, message, result);
}

void CMainWindow::init()
{
    m_pControl = new CControl(this, m_pCDZSTMark);
    m_pMenuBar = new CMainWindowMenuBar(this);

    // 输入输出窗口
    m_pOutMsg = new CTextBrowser(this, this);
    const QString cStyleSheet = "border:1px groove rgb(203,217,235);border-radius:3px;background:transparent;background-color: rgba(255, 255, 255,150);";
    m_pOutMsg->setStyleSheet(cStyleSheet);
    m_pOutMsg->document()->setMaximumBlockCount(300);
    m_pOutMsg->setFixedHeight(100);

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addWidget(m_pMenuBar);
    pLayout->addWidget(m_pControl);
    pLayout->addWidget(m_pOutMsg);
    this->setLayout(pLayout);
}
