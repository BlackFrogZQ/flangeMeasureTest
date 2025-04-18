#include "controlWindow.h"
#include "system/basic.h"
#include "IVmSolution.h"
#include "VMException.h"
#include "./mainWindow.h"
#include "hal/DZSTMark/DZSTMark.h"
#include "hal/DZSTMark/DZSTMarkDef.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFileDialog>

using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;

CControl::CControl(QWidget *parent) : QWidget(parent)
{
    initLayout();
}

CControl::~CControl()
{
}

void CControl::initLayout()
{
    QGroupBox *pCameraConnect = new QGroupBox(cnStr("方案控制接口"));
    QLabel *labelSchemePath = new QLabel(cnStr("方案路径："), this);
    QLabel *labelSchemePassword = new QLabel(cnStr("方案密码："), this);
    m_LineEditPath = new QLineEdit(this);
    m_LineEditPassword = new QLineEdit(this);
    m_pSolutionPath = new QPushButton(cnStr("选择方案路径"));
    m_pLoadSolution = new QPushButton(cnStr("加载方案"));
    QGridLayout *pCameraConnectLayout = new QGridLayout;
    pCameraConnectLayout->addWidget(labelSchemePath, 0, 0, 1, 1);
    pCameraConnectLayout->addWidget(m_LineEditPath, 0, 1, 1, 1);
    pCameraConnectLayout->addWidget(m_pSolutionPath, 0, 2, 1, 1);
    pCameraConnectLayout->addWidget(labelSchemePassword, 1, 0, 1, 1);
    pCameraConnectLayout->addWidget(m_LineEditPassword, 1, 1, 1, 1);
    pCameraConnectLayout->addWidget(m_pLoadSolution, 1, 2, 1, 1);
    pCameraConnect->setLayout(pCameraConnectLayout);

    QGroupBox *pObtainResults = new QGroupBox(cnStr("获取结果操作接口"));
    m_pImageResults = new QPushButton(cnStr("获取图像源结果"));
    m_pCallBackImageResults = new QPushButton(cnStr("回调获取图像源结果"));
    m_pProcessResults = new QPushButton(cnStr("获取流程结果"));
    QGridLayout *pObtainResultsLayout = new QGridLayout;
    pObtainResultsLayout->addWidget(m_pImageResults, 0, 0, 1, 1);
    pObtainResultsLayout->addWidget(m_pCallBackImageResults, 0, 1, 1, 1);
    pObtainResultsLayout->addWidget(m_pProcessResults, 0, 2, 1, 1);
    pObtainResults->setLayout(pObtainResultsLayout);

    QGroupBox *pRender = new QGroupBox(cnStr("渲染"));
    m_pRenderBind = new QPushButton(cnStr("渲染绑定"));
    m_pExecuteOnce = new QPushButton(cnStr("执行一次"));
    m_pRenderUnBind = new QPushButton(cnStr("渲染解绑"));
    QGridLayout *pRenderLayout = new QGridLayout;
    pRenderLayout->addWidget(m_pRenderBind, 0, 0, 1, 1);
    pRenderLayout->addWidget(m_pExecuteOnce, 0, 1, 1, 1);
    pRenderLayout->addWidget(m_pRenderUnBind, 0, 2, 1, 1);
    pRender->setLayout(pRenderLayout);

    QVBoxLayout *pButtonLayout = new QVBoxLayout;
    pButtonLayout->addWidget(pCameraConnect);
    pButtonLayout->addWidget(pObtainResults);
    pButtonLayout->addWidget(pRender);
    pButtonLayout->setMargin(0);
    pButtonLayout->setSpacing(2);
    this->setLayout(pButtonLayout);

    connect(m_pSolutionPath, &QPushButton::clicked, this, &CControl::clickSolutionPath);
    connect(m_pLoadSolution, &QPushButton::clicked, this, &CControl::clickLoadSolution);
    connect(m_pImageResults, &QPushButton::clicked, this, &CControl::clickImageResults);
    connect(m_pCallBackImageResults, &QPushButton::clicked, this, &CControl::clickCallBackImageResults);
    connect(m_pProcessResults, &QPushButton::clicked, this, &CControl::clickProcessResults);
    connect(m_pRenderBind, &QPushButton::clicked, this, &CControl::clickRenderBind);
    connect(m_pExecuteOnce, &QPushButton::clicked, this, &CControl::clickExecuteOnce);
    connect(m_pRenderUnBind, &QPushButton::clicked, this, &CControl::clickRenderUnBind);
}

void CControl::clickSolutionPath()
{
    QString strTemp = QStringLiteral("Choose solution path");
    QString strFileName = QFileDialog::getOpenFileName(this, strTemp, "", "SOL(*.sol)");
    if (!strFileName.isEmpty())
    {
        m_LineEditPath->setText(strFileName);
    }
}

void CControl::clickLoadSolution()
{
    QString strSolPath = m_LineEditPath->text();
    QString strPassword = m_LineEditPassword->text();
    QString strReMsg = "";

    if (strSolPath.isEmpty()) strSolPath = "";
    if (strPassword.isEmpty()) strPassword = "";

    mainWindow()->loadSolution(strSolPath, strPassword);
}

void CControl::clickImageResults()
{
    mainWindow()->clickImageResults();
}

void CControl::clickCallBackImageResults()
{
    mainWindow()->clickCallBackImageResults();
}

void CControl::clickProcessResults()
{
    mainWindow()->clickProcessResults();
}

void CControl::clickRenderBind()
{
    mainWindow()->clickRenderBind();
}

void CControl::clickExecuteOnce()
{
    mainWindow()->clickExecuteOnce();
}

void CControl::clickRenderUnBind()
{
    mainWindow()->clickRenderUnBind();
}
