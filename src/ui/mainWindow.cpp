#include "mainWindow.h"
#include "mainWindowDef.h"
#include "basic.h"
#include "IVmSolution.h"
#include "VMException.h"
#include "system/basic.h"
#include "menuBar/menuBar.h"
#include "controlWindow/controlWindow.h"
#include "logTextBrowser/textBrowser.h"
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QAxWidget>

using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;

CMainWindow* g_pMainWindow = nullptr;
CMainWindow* mainWindow()
{
    return g_pMainWindow;
};

CMainWindow::CMainWindow(QWidget *parent) : QWidget(parent)
{
    g_pMainWindow = this;

    m_pVmSol = CreateSolutionInstance();

    init();

    myInfo << cnStr("程序开始");
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
    m_pControl = new CControl(this);

    QString selectedCLSID = "{4919FA4C-F224-4C1E-917C-89B7F37AAE90}";
    m_pActivex = new QAxWidget(selectedCLSID, this);
    m_pActivex->dynamicCall("GetObjectPointer()");

    // 输入输出窗口
    m_pOutMsg = new CTextBrowser(this, this);
    m_pOutMsg->setStyleSheet(cStyleSheet);
    m_pOutMsg->document()->setMaximumBlockCount(300);
    m_pOutMsg->setFixedHeight(100);

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addWidget(m_pMenuBar);
    pLayout->addWidget(m_pControl);
    pLayout->addWidget(m_pActivex);
    pLayout->addWidget(m_pOutMsg);
    pLayout->setMargin(0);
    pLayout->setSpacing(2);
    this->setLayout(pLayout);
}
