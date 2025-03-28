#pragma once
#include <QWidget>

class CDZSTMark;
class CHIK3DMVS;
class QPushButton;

class CControl: public QWidget
{
    Q_OBJECT
public:
    CControl(QWidget *parent = nullptr, CHIK3DMVS *p_CHIK3DMVS = nullptr);
    ~CControl();

protected:
	void initLayout();

protected slots:
    void clickEnumDevices();
    void clickConnectCamera();
    void clickDisconnectCamera();

    void clickStartGrab();
    void clickStopGrab();

    void clickSaveTIFF();
    void clickSaveBMP();
    void clickSaveJPG();
    void clickSavePLY();
    void clickSaveCSV();
    void clickSaveOBJ();
    void clickSaveRAW();

private:
    CDZSTMark *m_pCDZSTMark;
    CHIK3DMVS *m_pCHIK3DMVS;

    QPushButton *m_pFindDevices;
    QPushButton *m_pConnectCamera;
    QPushButton *m_pDisconnectCamera;

    QPushButton *m_pImageGrab;
    QPushButton *m_pImageStop;

    QPushButton *m_pSaveTIFF;
    QPushButton *m_pSaveBMP;
    QPushButton *m_pSaveJPG;
    QPushButton *m_pSavePLY;
    QPushButton *m_pSaveCSV;
    QPushButton *m_pSaveOBJ;
    QPushButton *m_pSaveRAW;
};
