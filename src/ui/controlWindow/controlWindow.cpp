#include "controlWindow.h"
#include "system/basic.h"
#include "hal/DZSTMark/DZSTMark.h"
#include "hal/DZSTMark/DZSTMarkDef.h"
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>

using namespace TIGER_DZSTMarkDef;

CControl::CControl(QWidget *parent, CDZSTMark *p_CDZSTMark): QWidget(parent), m_pCDZSTMark(p_CDZSTMark)
{
    initLayout();
}

CControl::~CControl()
{
}

void CControl::initLayout()
{
    QGroupBox *pCameraConnect = new QGroupBox(cnStr("相机连接"));
    m_pFindDevices = new QPushButton(cnStr("发现设备"));
    m_pConnectCamera = new QPushButton(cnStr("连接相机"));
    m_pDisconnectCamera = new QPushButton(cnStr("断开相机"));
    QGridLayout *pCameraConnectLayout = new QGridLayout;
    pCameraConnectLayout->addWidget(m_pFindDevices, 0, 0, 1, 2);
    pCameraConnectLayout->addWidget(m_pConnectCamera, 1, 0, 1, 1);
    pCameraConnectLayout->addWidget(m_pDisconnectCamera, 1, 1, 1, 1);
    pCameraConnect->setLayout(pCameraConnectLayout);

    QGroupBox *pImageGrab = new QGroupBox(cnStr("图像采集"));
    m_pImageGrab = new QPushButton(cnStr("采集图像"));
    m_pImageStop = new QPushButton(cnStr("停止采集"));
    QGridLayout *pImageGrabLayout = new QGridLayout;
    pImageGrabLayout->addWidget(m_pImageGrab, 0, 0, 1, 1);
    pImageGrabLayout->addWidget(m_pImageStop, 0, 1, 1, 1);
    pImageGrab->setLayout(pImageGrabLayout);

    QGroupBox *pImageSave = new QGroupBox(cnStr("图像保存"));
    m_pSaveTIFF = new QPushButton(cnStr("保存TIFF"));
    m_pSaveBMP = new QPushButton(cnStr("保存BMP"));
    m_pSaveJPG = new QPushButton(cnStr("保存JPG"));
    m_pSavePLY = new QPushButton(cnStr("保存PLY"));
    m_pSaveCSV = new QPushButton(cnStr("保存CSV"));
    m_pSaveOBJ = new QPushButton(cnStr("保存OBJ"));
    m_pSaveRAW = new QPushButton(cnStr("保存RAW"));
    QGridLayout *pImageSaveLayout = new QGridLayout;
    pImageSaveLayout->addWidget(m_pSaveTIFF, 0, 0, 1, 1);
    pImageSaveLayout->addWidget(m_pSaveBMP, 0, 1, 1, 1);
    pImageSaveLayout->addWidget(m_pSaveJPG, 0, 2, 1, 1);
    pImageSaveLayout->addWidget(m_pSavePLY, 1, 0, 1, 1);
    pImageSaveLayout->addWidget(m_pSaveCSV, 1, 1, 1, 1);
    pImageSaveLayout->addWidget(m_pSaveOBJ, 1, 2, 1, 1);
    pImageSaveLayout->addWidget(m_pSaveRAW, 2, 0, 1, 3);
    pImageSave->setLayout(pImageSaveLayout);

    QVBoxLayout *pButtonLayout = new QVBoxLayout;
    pButtonLayout->addWidget(pCameraConnect);
    pButtonLayout->addWidget(pImageGrab);
    pButtonLayout->addWidget(pImageSave);
    pButtonLayout->setMargin(0);
    pButtonLayout->setSpacing(2);
    this->setLayout(pButtonLayout);

    connect(m_pConnectCamera, &QPushButton::clicked, this, &CControl::OnBnClickedButtonConnect);
    connect(m_pDisconnectCamera, &QPushButton::clicked, this, &CControl::OnBnClickedButtonDisconnect);
    connect(m_pSaveTIFF, &QPushButton::clicked, this, &CControl::OnBnClickedButtonCreateUDM);
    connect(m_pSaveBMP, &QPushButton::clicked, this, &CControl::OnBnClickedButtonDownloadUDM);
    connect(m_pSaveJPG, &QPushButton::clicked, this, &CControl::OnBnClickedButtonStartMark);
    connect(m_pSavePLY, &QPushButton::clicked, this, &CControl::OnBnClickedButtonPauseMark);
    connect(m_pSaveCSV, &QPushButton::clicked, this, &CControl::OnBnClickedButtonContinueMark);
    connect(m_pSaveOBJ, &QPushButton::clicked, this, &CControl::OnBnClickedButtonStopMark);
}

void CControl::OnBnClickedButtonConnect()
{
    m_pCDZSTMark->ipConnectDevice(DZSTMarkConnectPara()->ip);
}

void CControl::OnBnClickedButtonDisconnect()
{
    m_pCDZSTMark->disconnectDevice();
}



void CControl::OnBnClickedButtonCreateUDM()
{
    m_pCDZSTMark->creatUdmBin();
}

void CControl::OnBnClickedButtonDownloadUDM()
{
    m_pCDZSTMark->downloadMarkFile();
}



void CControl::OnBnClickedButtonStartMark()
{
    m_pCDZSTMark->starMark();
}

void CControl::OnBnClickedButtonPauseMark()
{
    m_pCDZSTMark->PauseMark();
}

void CControl::OnBnClickedButtonContinueMark()
{
    m_pCDZSTMark->ContinueMark();
}

void CControl::OnBnClickedButtonStopMark()
{
    m_pCDZSTMark->StopMark();
}