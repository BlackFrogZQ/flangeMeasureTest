#include "mainWindow.h"
#include "basic.h"
#include "system/basic.h"
#include "controlWindow/controlWindow.h"
#include "logTextBrowser/textBrowser.h"
#include "hal/DZSTMark/DZSTMark.h"
#include "menuBar/menuBar.h"
#include <QLabel>
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
    m_pMenuBar = new CMainWindowMenuBar(this);

    m_pImageLabel = new QLabel;
    m_pImageLabel->setFixedSize(500, 500);
    m_pImageLabel->setStyleSheet(cStyleSheet);

    m_pControl = new CControl(this, m_pCDZSTMark);

    QWidget *pCameraWidget = new QWidget;
    QHBoxLayout *pCameraLayout = new QHBoxLayout;
    pCameraLayout->addWidget(m_pImageLabel);
    pCameraLayout->addWidget(m_pControl);
    pCameraLayout->setMargin(0);
    pCameraLayout->setSpacing(2);
    pCameraWidget->setLayout(pCameraLayout);

    // 输入输出窗口
    m_pOutMsg = new CTextBrowser(this, this);
    m_pOutMsg->setStyleSheet(cStyleSheet);
    m_pOutMsg->document()->setMaximumBlockCount(300);
    m_pOutMsg->setFixedHeight(100);

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addWidget(m_pMenuBar);
    pLayout->addWidget(pCameraWidget);
    pLayout->addWidget(m_pOutMsg);
    pLayout->setMargin(0);
    pLayout->setSpacing(2);
    this->setLayout(pLayout);
}
