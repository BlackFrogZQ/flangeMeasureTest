#include "controlWindow.h"
#include "system/basic.h"
#include "hal/HIK3DMVS/HIK3DMVS.h"
#include "hal/DZSTMark/DZSTMark.h"
#include "hal/DZSTMark/DZSTMarkDef.h"
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>

using namespace TIGER_DZSTMarkDef;

CControl::CControl(QWidget *parent, CHIK3DMVS *p_CHIK3DMVS) : QWidget(parent), m_pCHIK3DMVS(p_CHIK3DMVS)
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

    connect(m_pFindDevices, &QPushButton::clicked, this, &CControl::clickEnumDevices);
    connect(m_pConnectCamera, &QPushButton::clicked, this, &CControl::clickConnectCamera);
    connect(m_pDisconnectCamera, &QPushButton::clicked, this, &CControl::clickDisconnectCamera);

    connect(m_pImageGrab, &QPushButton::clicked, this, &CControl::clickStartGrab);
    connect(m_pImageStop, &QPushButton::clicked, this, &CControl::clickStopGrab);

    connect(m_pSaveTIFF, &QPushButton::clicked, this, &CControl::clickSaveTIFF);
    connect(m_pSaveBMP, &QPushButton::clicked, this, &CControl::clickSaveBMP);
    connect(m_pSaveJPG, &QPushButton::clicked, this, &CControl::clickSaveJPG);
    connect(m_pSavePLY, &QPushButton::clicked, this, &CControl::clickSavePLY);
    connect(m_pSaveCSV, &QPushButton::clicked, this, &CControl::clickSaveCSV);
    connect(m_pSaveOBJ, &QPushButton::clicked, this, &CControl::clickSaveOBJ);
    connect(m_pSaveRAW, &QPushButton::clicked, this, &CControl::clickSaveRAW);
}

void CControl::clickEnumDevices()
{
    m_pCHIK3DMVS->enumDevices();
}

void CControl::clickConnectCamera()
{
    m_pCHIK3DMVS->openCamera();
}

void CControl::clickDisconnectCamera()
{
    m_pCHIK3DMVS->closeCamera();
}


void CControl::clickStartGrab()
{
    m_pCHIK3DMVS->startGrabImage();
}

void CControl::clickStopGrab()
{
    m_pCHIK3DMVS->stopGrabImage();
}


void CControl::clickSaveTIFF()
{
    m_pCHIK3DMVS->saveImageTiff();
}

void CControl::clickSaveBMP()
{
    m_pCHIK3DMVS->saveImageBMP();
}

void CControl::clickSaveJPG()
{
    m_pCHIK3DMVS->saveImageJPG();
}

void CControl::clickSavePLY()
{
}

void CControl::clickSaveCSV()
{
}

void CControl::clickSaveOBJ()
{
}

void CControl::clickSaveRAW()
{
    m_pCHIK3DMVS->saveImageRAW();
}