#pragma once
#include "Mv3dLpApi.h"
#include "Mv3dLpDefine.h"
#include "Mv3dLpImgProc.h"
#include "../iCamera.h"
#include <windows.h>
#include <iostream>
#include <QtGui>
#include <QObject>

namespace TIGER_Camera
{
    class CHIK3DMVS : public ICamera
    {
        Q_OBJECT
    public:
        CHIK3DMVS(WId p_hWndDisplay);
        CHIK3DMVS();
        ~CHIK3DMVS();

    protected:
        bool initHikvisionCameraEngine();
        void enumtHikvisionDevices();

        bool connectCamera();
        void closeCamera();

        void startGrabImage();
        void stopGrabImage();
        static DWORD WINAPI staticProcessThread(LPVOID lpParam);
        void processThread();
        void displayImage(MV3D_LP_IMAGE_DATA* p_imageData);

        void printError(const QString &p_msg);
        bool checkErrorCode(int errorCode, QString preMsg = QString());
        void handleException(MV3D_LP_EXCEPTION_INFO* info);

    protected:
        static void __stdcall CallBackFunc(MV3D_LP_IMAGE_DATA* pstImageData, void* pUser);
        static void __stdcall ExceptCallBackFunc(MV3D_LP_EXCEPTION_INFO* pstExceptInfo, void* pUser);
        static QString formatErrorMsg(QString p_error, MV3D_LP_STATUS errorCode);

    public slots:
        virtual void init(CCameraPara paras) override;

    protected slots:
        void slotGrabImage(QImage p_image);
        void slotTimeout();
        void slotConnect();

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

        int pErrorCode;

        QTimer *m_pTimer;
    };
};