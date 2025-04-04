﻿#include "HIK3DMVS.h"
#include "system/basic.h"
#include <QThread>
#include <QMutex>

CHIK3DMVS::CHIK3DMVS(WId p_hWndDisplay) : m_hWndDisplay(p_hWndDisplay)
{
    m_nDevNum = 0;

    m_bConnect = false;
    m_handle = NULL;

    hProcessThread = NULL;
    m_bStartJob = false;

    init();
}

CHIK3DMVS::~CHIK3DMVS()
{
    if(MV3D_LP_Finalize() != MV3D_LP_OK)
    {
        myInfo << cnStr("SDK运行环境释放失败，错误代码: %1").arg(MV3D_LP_Finalize());
    }
}

void CHIK3DMVS::init()
{
    myInfo << cnStr("SDK版本号: %1").arg(MV3D_LP_GetVersion());
    if(MV3D_LP_Initialize() != MV3D_LP_OK)
    {
        myInfo << cnStr("SDK运行环境初始化失败，错误代码: %1").arg(MV3D_LP_GetVersion());
        return;
    }
}

void CHIK3DMVS::enumDevices()
{
    int nRet = MV3D_LP_GetDeviceNumber(&m_nDevNum);
    if(nRet != MV3D_LP_OK)
    {
        myInfo << cnStr("查找设备失败，错误代码: %1").arg(nRet);
        return;
    }

    memset(&m_stDeviceInfoList, 0, sizeof(m_stDeviceInfoList));

    nRet = MV3D_LP_GetDeviceList(&m_stDeviceInfoList[0], 20, &m_nDevNum);
    if(nRet != MV3D_LP_OK)
    {
        myInfo << cnStr("获取设备列表失败，错误代码: %1").arg(nRet);
        return;
    }

    for (unsigned int i = 0; i < m_nDevNum; i++)
    {
        char pCurrentIP[16] = "";
        memcpy(pCurrentIP, m_stDeviceInfoList[i].chCurrentIp, strlen((const char*)m_stDeviceInfoList[i].chCurrentIp));
        myInfo << cnStr("Index[%1] Name[%2] IP[%3] SerialNum[%4]").arg(i).arg(m_stDeviceInfoList[i].chModelName).arg(pCurrentIP).arg(m_stDeviceInfoList[i].chSerialNumber);
    }
}

void CHIK3DMVS::openCamera()
{
    if(m_bConnect == true)
    {
        myInfo << cnStr("设备已连接");
        return;
    }

    if (m_handle)
    {
        MV3D_LP_CloseDevice(&m_handle);
        m_handle = NULL;
    }

    QString ip = "169.254.133.34";
    QByteArray ipBytes = ip.toUtf8();
    char* pIp = ipBytes.data();
    int nRet = MV3D_LP_OpenDeviceByIP(&m_handle, pIp);
    if(nRet != MV3D_LP_OK)
    {
        myInfo << cnStr("相机打开失败，错误代码: %1").arg(nRet);
        return;
    }
    myInfo << cnStr("相机连接成功");
    m_bConnect = true;
}

void CHIK3DMVS::closeCamera()
{

}

DWORD WINAPI CHIK3DMVS::staticProcessThread(LPVOID lpParam)
{
	CHIK3DMVS* pMeasure3D = static_cast<CHIK3DMVS*>(lpParam);
	if (pMeasure3D != nullptr)
	{
		pMeasure3D->processThread();
	}
	return 0;
}

void CHIK3DMVS::processThread()
{
    int nRet = MV3D_LP_OK;
    while (m_bStartJob)
    {
        MV3D_LP_IMAGE_DATA stImageData;
        memset(&stImageData, 0, sizeof(MV3D_LP_IMAGE_DATA));
        nRet = MV3D_LP_GetImage(m_handle, &stImageData, 5);
        if (nRet == MV3D_LP_OK)
        {
            try
            {
                myInfo << cnStr("子线程ThreadID: ") << QThread::currentThreadId();
                myInfo << cnStr("获取图像数据成功");
                displayImage(&stImageData);
            }
            catch (...)
            {
                myInfo << cnStr("获取图像数据出错！！！");
            }
        }
        else
        {
            // myInfo << cnStr("获取图像数据失败");
            Sleep(1);
            continue;
        }
    }
}

void CHIK3DMVS::startGrabImage()
{
    if(m_bConnect == false)
    {
        myInfo << cnStr("未连接相机");
        return;
    }

    if (hProcessThread != NULL)
    {
        m_bStartJob = false;
        WaitForSingleObject(hProcessThread, INFINITE);
        CloseHandle(hProcessThread);
        hProcessThread = NULL;
    }

    m_bStartJob = true;

    hProcessThread = CreateThread(NULL, 0, staticProcessThread, this, 0, &m_threadid);
    if (hProcessThread == NULL)
    {
        myInfo << cnStr("创建处理线程失败");
    }

    int nRet = MV3D_LP_StartMeasure(m_handle);
    if(nRet != MV3D_LP_OK)
    {
        myInfo << cnStr("开始测量失败，错误代码: %1").arg(nRet);
        return;
    }

    myInfo << cnStr("主线程ThreadID: ") << QThread::currentThreadId();
}

void CHIK3DMVS::stopGrabImage()
{
    if(m_bConnect == false)
    {
        myInfo << cnStr("未连接相机");
        return;
    }

    m_bStartJob = false;
    if (MV3D_LP_StopMeasure(m_handle) != MV3D_LP_OK)
    {
        myInfo << cnStr("停止采集失败，错误代码: %1").arg(MV3D_LP_StopMeasure(m_handle));
        m_bStartJob = false;
        return ;
    }
}

void CHIK3DMVS::displayImage(MV3D_LP_IMAGE_DATA* p_imageData)
{
    myInfo << cnStr("显示图像ThreadID: ") << QThread::currentThreadId();
    int nRet = MV3D_LP_OK;
    void* hWnd = reinterpret_cast<void*>(m_hWndDisplay);
    nRet = MV3D_LP_DisplayImage(p_imageData, hWnd, DisplayType_Auto, 0, 0);
    if(nRet != MV3D_LP_OK)
    {
        myInfo << cnStr("保存图片失败，错误代码: %1").arg(nRet);
        return;
    }
}

void CHIK3DMVS::saveImage(MV3D_LP_IMAGE_DATA* p_imageData)
{
    myInfo << cnStr("保存图像ThreadID: ") << QThread::currentThreadId();
    int nRet = MV3D_LP_OK;

    QMutex mutex;
    mutex.lock();
    nRet = MV3D_LP_SaveImage(p_imageData, FileType_JPG, "");
    mutex.unlock();

    if(nRet != MV3D_LP_OK)
    {
        myInfo << cnStr("保存图片失败，错误代码: %1").arg(nRet);
        return;
    }
}
