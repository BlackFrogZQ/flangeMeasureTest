#pragma once
#include "Mv3dLpApi.h"
#include "Mv3dLpDefine.h"
#include "Mv3dLpImgProc.h"
#include <windows.h>
#include <iostream>
#include <QtGui>

class CHIK3DMVS
{
public:
    CHIK3DMVS(WId p_hWndDisplay);
    ~CHIK3DMVS();

    void enumDevices();
    void openCamera();
    void closeCamera();

    static DWORD WINAPI staticProcessThread(LPVOID lpParam);
    void processThread();
    void startGrabImage();
    void stopGrabImage();

    void displayImage(MV3D_LP_IMAGE_DATA* p_imageData);
    int saveImage(Mv3dLpFileType p_enFileType);
    void saveImageTiff();
    void saveImageBMP();
    void saveImageJPG();
    void saveImageRAW();

protected:
    void init();

private:
    unsigned int m_nDevNum;
    MV3D_LP_DEVICE_INFO m_stDeviceInfoList[20];

    bool m_bConnect;
    void* m_handle;

    bool m_bStartJob;
    HANDLE m_hProcessThread;
    DWORD m_threadid;

    QMutex m_mutex;
    WId  m_hWndDisplay;
    MV3D_LP_IMAGE_DATA m_stImageInfo;
    unsigned char* m_pcDataBuf;
};
