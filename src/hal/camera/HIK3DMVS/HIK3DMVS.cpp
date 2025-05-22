#include "HIK3DMVS.h"
#include "system/basic.h"
#include "../iCameraDef.h"
#include <QThread>
#include <QMutex>

namespace TIGER_Camera
{
    QString CHIK3DMVS::formatErrorMsg(QString p_error, MV3D_LP_STATUS errorCode)
    {
        QString errorMsg;
        switch (errorCode)
        {
            case MV3D_LP_OK:
                errorMsg = p_error + "成功";
                break;
            case MV3D_LP_E_NODATA:
                errorMsg = p_error + "无数据";
                break;
            case MV3D_LP_E_OUTOFRANGE:
                errorMsg = p_error + "值超出范围";
                break;
            case MV3D_LP_E_UNKNOW:
                errorMsg = p_error + "未知错误";
                break;
            default:
                errorMsg = p_error + "未知错误";
                break;
        }
        return errorMsg;
    }

    void __stdcall CHIK3DMVS::CallBackFunc(MV3D_LP_IMAGE_DATA* pstImageData, void* pUser)
    {
        assert(pUser != nullptr);
        auto pCamera = static_cast<CHIK3DMVS*>(pUser);
    }

    void __stdcall CHIK3DMVS::ExceptCallBackFunc(MV3D_LP_EXCEPTION_INFO* pstExceptInfo, void* pUser)
    {
        if (pUser)
        {
            static_cast<CHIK3DMVS*>(pUser)->handleException(pstExceptInfo);
        }
    }
};

namespace TIGER_Camera
{
    CHIK3DMVS::CHIK3DMVS(WId p_hWndDisplay) : m_hWndDisplay(p_hWndDisplay), m_nDevNum(0), m_bConnect(false), m_handle(NULL), m_hProcessThread(NULL), m_bStartJob(false), m_pcDataBuf(NULL), pErrorCode(MV3D_LP_OK)
    {
        memset(&m_stDeviceInfoList, 0, sizeof(m_stDeviceInfoList));
        memset(&m_stImageInfo, 0, sizeof(MV3D_LP_IMAGE_DATA));
    }

    CHIK3DMVS::CHIK3DMVS() : m_hWndDisplay(NULL), m_nDevNum(0), m_bConnect(false), m_handle(NULL), m_hProcessThread(NULL), m_bStartJob(false), m_pcDataBuf(NULL), pErrorCode(MV3D_LP_OK)
    {
        memset(&m_stDeviceInfoList, 0, sizeof(m_stDeviceInfoList));
        memset(&m_stImageInfo, 0, sizeof(MV3D_LP_IMAGE_DATA));
    }

    CHIK3DMVS::~CHIK3DMVS()
    {
        pErrorCode = MV3D_LP_Finalize();
        if(pErrorCode != MV3D_LP_OK)
        {
            myInfo << cnStr("SDK运行环境释放失败，错误代码: %1").arg(pErrorCode);
        }
    }

    void CHIK3DMVS::init(CCameraPara paras)
    {
        if(!initHikvisionCameraEngine())
        {
            printError(tr("SDK运行环境初始化失败"));
            return;
        }
        m_paraInfo = paras;
        m_pTimer = new QTimer(this);
        connect(m_pTimer, &QTimer::timeout, this, &CHIK3DMVS::slotTimeout);
        slotConnect();
    }

    bool CHIK3DMVS::initHikvisionCameraEngine()
    {
        QString pSDKVersion = QString::fromUtf8(MV3D_LP_GetVersion());
        pErrorCode = MV3D_LP_Initialize();
        if(!checkErrorCode(pErrorCode, tr("SDK运行环境初始化失败，错误代码:")))
        {
            return false;
        }
        return true;
    }

    void CHIK3DMVS::enumtHikvisionDevices()
    {
        pErrorCode = MV3D_LP_GetDeviceNumber(&m_nDevNum);
        if(pErrorCode != MV3D_LP_OK)
        {
            myInfo << cnStr("查找设备失败，错误代码: %1").arg(pErrorCode);
            return;
        }

        pErrorCode = MV3D_LP_GetDeviceList(&m_stDeviceInfoList[0], 20, &m_nDevNum);
        if(pErrorCode != MV3D_LP_OK)
        {
            myInfo << cnStr("获取设备列表失败，错误代码: %1").arg(pErrorCode);
            return;
        }

        for (unsigned int i = 0; i < m_nDevNum; i++)
        {
            char pCurrentIP[16] = "";
            memcpy(pCurrentIP, m_stDeviceInfoList[i].chCurrentIp, strlen((const char*)m_stDeviceInfoList[i].chCurrentIp));
            myInfo << cnStr("Index[%1] Name[%2] IP[%3] SerialNum[%4]").arg(i).arg(m_stDeviceInfoList[i].chModelName).arg(pCurrentIP).arg(m_stDeviceInfoList[i].chSerialNumber);
        }
    }

    void CHIK3DMVS::slotTimeout()
    {

    }

    void CHIK3DMVS::slotConnect()
    {
        if(connectCamera())
        {
            m_pTimer->start(6000);
        }
        else
        {
            printError(tr("相机连接失败:%1,5s后尝试连接相机").arg(m_error));
            QTimer::singleShot(5000, this, &CHIK3DMVS::slotConnect);
        }
    }

    bool CHIK3DMVS::connectCamera()
    {
        if(m_bConnect == true)
        {
            printError(tr("设备已连接"));
            return true;
        }

        if (m_handle)
        {
            MV3D_LP_CloseDevice(&m_handle);
            m_handle = NULL;
        }

        QByteArray ipBytes = m_paraInfo.ip.toUtf8();
        pErrorCode = MV3D_LP_OpenDeviceByIP(&m_handle, ipBytes.data());
        if(!checkErrorCode(pErrorCode, tr("相机打开失败，错误代码")))
        {
            m_bConnect = false;
            return false;
        }
        m_bConnect = true;
        return true;
    }

    void CHIK3DMVS::closeCamera()
    {
        int nRet = MV3D_LP_OK;
        if(m_handle != NULL)
        {
            if(m_bStartJob == true)
            {
                m_bStartJob = false;
                nRet = MV3D_LP_StopMeasure(m_handle);
                if(nRet != MV3D_LP_OK)
                {
                    myInfo << cnStr("停止测量失败，错误代码: %1").arg(nRet);
                    return;
                }

                if (m_hProcessThread != NULL)
                {
                    WaitForSingleObject(m_hProcessThread, INFINITE);
                    CloseHandle(m_hProcessThread);
                    m_hProcessThread = NULL;
                }
            }

            if(m_handle != NULL)
            {
                nRet = MV3D_LP_CloseDevice(&m_handle);
                if(nRet != MV3D_LP_OK)
                {
                    myInfo << cnStr("关闭相机失败，错误代码: %1").arg(nRet);
                    return;
                }
            }
        }
        MV3D_LP_Finalize();
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

    void CHIK3DMVS::displayImage(MV3D_LP_IMAGE_DATA* p_imageData)
    {
        if ((NULL == p_imageData) || (NULL == m_hWndDisplay))
        {
            return;
        }

        int nRet = MV3D_LP_OK;
        void* hWnd = reinterpret_cast<void*>(m_hWndDisplay);
        nRet = MV3D_LP_DisplayImage(p_imageData, hWnd, DisplayType_Auto, 0, 0);
        if(nRet != MV3D_LP_OK)
        {
            myInfo << cnStr("显示图片失败，错误代码: %1").arg(nRet);
            return;
        }

        m_mutex.lock();
        int m_MaxImageSize = 0;
        {
            if (m_MaxImageSize <  p_imageData->nDataLen)
            {
                if (NULL != m_pcDataBuf)
                {
                    free(m_pcDataBuf);
                    m_pcDataBuf = NULL;
                }

                m_MaxImageSize =  p_imageData->nDataLen;
                m_pcDataBuf =  (unsigned char*)malloc(m_MaxImageSize);
                if (NULL == m_pcDataBuf)
                {
                    nRet = MV3D_LP_E_RESOURCE;
                }
                memset(m_pcDataBuf, 0, m_MaxImageSize);
            }

            memset(&m_stImageInfo, 0, sizeof(MV3D_LP_IMAGE_DATA));
            memcpy(&m_stImageInfo, p_imageData, sizeof(MV3D_LP_IMAGE_DATA));
            if (p_imageData->pData != NULL)
            {
                memcpy(m_pcDataBuf, p_imageData->pData, p_imageData->nDataLen);
                m_stImageInfo.pData = m_pcDataBuf;
            }
        }
        m_mutex.unlock();
    }

    void CHIK3DMVS::startGrabImage()
    {
        if(m_bConnect == false)
        {
            myInfo << cnStr("未连接相机");
            return;
        }

        if (m_hProcessThread != NULL)
        {
            m_bStartJob = false;
            WaitForSingleObject(m_hProcessThread, INFINITE);
            CloseHandle(m_hProcessThread);
            m_hProcessThread = NULL;
        }
        m_bStartJob = true;

        // m_hProcessThread = CreateThread(NULL, 0, staticProcessThread, this, 0, &m_threadid);
        if (m_hProcessThread == NULL)
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
            myInfo << cnStr("停止测量失败，错误代码: %1").arg(MV3D_LP_StopMeasure(m_handle));
            m_bStartJob = false;
            return ;
        }
    }

    void CHIK3DMVS::slotGrabImage(QImage p_image)
    {
        emit sigUpdateImage(p_image);
    }

    void CHIK3DMVS::printError(const QString &p_msg)
    {
        m_error = p_msg;
        emit sigError(m_error);
    }

    bool CHIK3DMVS::checkErrorCode(int errorCode, QString preMsg)
    {
        bool ok = (errorCode == MV3D_LP_OK);
        if (!ok)
        {
            printError(formatErrorMsg(preMsg, errorCode));
        }
        return ok;
    }

    void CHIK3DMVS::handleException(MV3D_LP_EXCEPTION_INFO* info)
    {

    }
};