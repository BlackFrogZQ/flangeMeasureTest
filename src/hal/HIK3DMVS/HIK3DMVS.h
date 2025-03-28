#pragma once
#include "Mv3dLpApi.h"
#include "Mv3dLpDefine.h"
#include "Mv3dLpImgProc.h"
#include <windows.h>
#include <iostream>

class CHIK3DMVS
{
public:
    CHIK3DMVS();
    ~CHIK3DMVS();

    void enumDevices();
    void openCamera();
    void closeCamera();

    static DWORD WINAPI staticProcessThread(LPVOID lpParam);
    void processThread();
    void startGrabImage();
    void stopGrabImage();

protected:
    void init();

private:
    unsigned int m_nDevNum;
    MV3D_LP_DEVICE_INFO m_stDeviceInfoList[20];

    bool m_bConnect;
    void* m_handle;

    HANDLE hProcessThread;
    bool m_bStartJob;
    DWORD m_threadid;
};
