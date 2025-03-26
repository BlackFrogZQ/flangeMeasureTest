#pragma once
#include "HM_HashuScan.h"
#include "HM_HashuUDM.h"
#include <windows.h>
#include <QString>

namespace TIGER_DZSTMarkDef
{}

class CDZSTMark
{
public:
    CDZSTMark(HWND p_hWnd);
    ~CDZSTMark();

protected:
    void init();

public:
    void nativeEvent(MSG* p_message);
    LRESULT OnMsgDeviceEhco(WPARAM wParam, LPARAM lParam);
    LRESULT OnMsgUDMDownloadEnd(WPARAM wParam, LPARAM lParam);
    LRESULT OnMsgUDMRunHalt(WPARAM wParam, LPARAM lParam);
    LRESULT ExecProcess(WPARAM wParam, LPARAM lParam);

    void indexConnectDevice();
    void ipConnectDevice(QString p_ip);
    void disconnectDevice();

    void starMark();
    void PauseMark();
    void ContinueMark();
    void StopMark();

    MarkParameter* getMarkParameter();
    void creatUdmBin();
    void downloadMarkFile();

private:
    HWND m_hWnd;
    int m_ipIndex;
};