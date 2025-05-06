#include "mainWindow.h"
#include "mainWindowDef.h"
#include "basic.h"
#include "system/basic.h"
#include "menuBar/menuBar.h"
#include "controlWindow/controlWindow.h"
#include "logTextBrowser/textBrowser.h"
#include "graphicsWindow/graphicsViewTest.h"
#include "imageProcess/hikrobotEngine/hikrobotEngine.h"
#include <QTextBrowser>
#include <QVBoxLayout>

using namespace TIGER_ProcessTool;

CMainWindow* g_pMainWindow = nullptr;
CMainWindow* mainWindow()
{
    return g_pMainWindow;
};

CMainWindow::CMainWindow(QWidget *parent) : QWidget(parent)
{
    g_pMainWindow = this;

	m_pHikrobotEngine = new CHikrobotEngine(this);
    init();

    connect(m_pHikrobotEngine, &CHikrobotEngine::sigGrabImage, this, &CMainWindow::slotUpdateImage);
}

CMainWindow::~CMainWindow()
{
    DisposeResource();
}

void CMainWindow::printMsg(QString p_msg)
{
    const QString cFont = "<font color=\"#0000FF\">%1</font>";
    m_pOutMsg->append(cFont.arg(p_msg.replace("\n", "<br>")));
    m_pOutMsg->moveCursor(m_pOutMsg->textCursor().End);
}

void CMainWindow::init()
{
    m_pMenuBar = new CMainWindowMenuBar(this);

    QWidget *pControlWidget = new QWidget;
    QVBoxLayout *pControlLayout = new QVBoxLayout;
    m_pControl = new CControl(this, m_pHikrobotEngine);
    m_pOutMsg = new CTextBrowser(this, this);
    m_pOutMsg->setStyleSheet(cStyleSheet);
    m_pOutMsg->document()->setMaximumBlockCount(300);
    m_pOutMsg->setFixedHeight(100);
    pControlLayout->addWidget(m_pControl);
    pControlLayout->addWidget(m_pOutMsg);
    pControlWidget->setLayout(pControlLayout);

	m_pImageView = new ImageView;
	m_pImageView->loadImage(QImage("C:/Users/12754/Desktop/111.jpeg"));

    QWidget *pMainWidget = new QWidget;
    QHBoxLayout *pMainLayout = new QHBoxLayout();
    pMainLayout->addWidget(pControlWidget);
    pMainLayout->addWidget(m_pImageView);
    pMainWidget->setLayout(pMainLayout);

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addWidget(m_pMenuBar);
    pLayout->addWidget(pMainWidget);
    pLayout->setMargin(0);
    pLayout->setSpacing(2);
    this->setLayout(pLayout);
}

void CMainWindow::slotUpdateImage(QImage p_image)
{
    m_pImageView->loadImage(p_image);
}