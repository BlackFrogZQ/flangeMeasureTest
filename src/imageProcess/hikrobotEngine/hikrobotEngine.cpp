#include "hikrobotEngine.h"
#include "hikrobotEngineDef.h"
#include "system/systemService.h"
#include <QThread>
#include <QAxWidget>

namespace TIGER_ProcessTool
{
    CHikrobotEngine::CHikrobotEngine(QWidget *parent) : QWidget(parent), m_bGetCallbackFlag(false), m_bRenderFlag(false)
    {
        init();
    }

    CHikrobotEngine::~CHikrobotEngine()
    {
    }

    void CHikrobotEngine::init()
    {
        try
        {
            m_pVmSol = CreateSolutionInstance();
            m_pVmSol->RegisterCallBack(CallBackModuRes, this);
            m_pVmSol->DisableModulesCallback();

            auto map = sys()->pNativeVmCOMObject;
            for(int i = 0; i < cCOMObjectEnName.size(); i++)
            {
                CAxWidget stAxWidget;
                stAxWidget.pCOMObject = (CCOMObject)i;
                stAxWidget.enName = cCOMObjectEnName[i];
                stAxWidget.cnName = cCOMObjectCnName[i];
                stAxWidget.CLSID = "";
                stAxWidget.isExist = false;
                stAxWidget.pAxWidget = nullptr;
                for (auto it = map.constBegin(); it != map.constEnd(); ++it)
                {
                    QString pCOMKye = it.key();
                    pCOMKye = pCOMKye.section('.', 0, 0);
                    if (pCOMKye == cCOMObjectEnName[i])
                    {
                        stAxWidget.CLSID = it.value();
                        stAxWidget.isExist = true;
                        stAxWidget.pAxWidget = new QAxWidget(it.value(), this);
                        stAxWidget.pAxWidget->dynamicCall("GetObjectPointer()");
                        break;
                    }
                }
                m_pAxWidgets.append(stAxWidget);
            }
        }
        catch(CVmException e)
        {
            myInfo << "0x" + QString::number(e.GetErrorCode(), 16) + " == CreateSolutionInstance()";
        }
        catch(...)
        {
            myInfo << "Interface Exception!";
        }
    }

    int __stdcall CHikrobotEngine::CallBackModuRes(OUT OutputPlatformInfo * const pstOutputPlatformInfo, IN void * const pUser)
    {
        CHikrobotEngine * pCtrlThis = static_cast<CHikrobotEngine *>(pUser);
        int nRet = IMVS_EC_UNKNOWN;
        nRet = pCtrlThis->CallBackModuResFunc(pstOutputPlatformInfo, true);
        if (IMVS_EC_OK != nRet)
        {
            return nRet;
        }
        return IMVS_EC_OK;
    }

    int CHikrobotEngine::CallBackModuResFunc(IN OutputPlatformInfo * const pstOutputPlatformInfo, bool bTime)
    {
        if (IMVS_NULL == pstOutputPlatformInfo)
        {
            return IMVS_EC_INVALID_HANDLE;
        }
        if (IMVS_NULL == (pstOutputPlatformInfo->pData))
        {
            return IMVS_EC_INVALID_HANDLE;
        }

        if (IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_MODULE_RESULT == pstOutputPlatformInfo->nInfoType)
        {
            IMVS_PF_MODULE_RESULT_INFO_LIST * pstPFModuResInfoList = (IMVS_PF_MODULE_RESULT_INFO_LIST *)pstOutputPlatformInfo->pData;
        }
        else if (IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_WORK_STATE == pstOutputPlatformInfo->nInfoType)
        {
            IMVS_PF_MODULE_WORK_STAUS * pstPFWorkStatus = (IMVS_PF_MODULE_WORK_STAUS *)pstOutputPlatformInfo->pData;

            float a = pstPFWorkStatus->fProcessTime;

            int m_nWorkStatus = pstPFWorkStatus->nWorkStatus;
            if (m_nWorkStatus == 0)
            {
                try
                {
                    // if (NULL == pModuleImageSourceTool)
                    // {
                    //     m_bGetCallbackFlag = true;
                    //     return IMVS_EC_PARAM;
                    // }
                    // ImageSourceResults * pModuleImageResult = pModuleImageSourceTool->GetResult();
                    // if (NULL != pModuleImageResult)
                    // {
                    //     mshowImageGloble = { 0 };
                    //     mshowImageGloble = pModuleImageResult->GetImageData();
                    // }

                    // if (NULL == pModuleCircleFindTool)
                    // {
                    //     m_bGetCallbackFlag = true;
                    //     return IMVS_EC_PARAM;
                    // }
                    // CircleFindResults * pModuleCircleFindResult = pModuleCircleFindTool->GetResult();
                    // if (NULL != pModuleCircleFindResult)
                    // {
                    //     CircleEx stCir = { 0 };
                    //     stCir.CenterX = pModuleCircleFindResult->GetCircleCenter().fX;
                    //     stCir.CenterY = pModuleCircleFindResult->GetCircleCenter().fY;
                    //     stCir.MajorRadius = pModuleCircleFindResult->GetCircleRadius();
                    //     stCir.MinorRadius = pModuleCircleFindResult->GetCircleRadius();

                    //     int nArgb = 0;
                    //     nArgb += 100 << 16;
                    //     nArgb += 200 << 8;
                    //     nArgb += 150;

                    //     stCir.Color = nArgb;
                    //     stCir.FillColor = nArgb;
                    //     stCir.Opacity = 1;
                    //     stCir.StrokeThickness = 1;

                    //     stCirGloble = stCir;
                    // }
                    m_bGetCallbackFlag = true;
                }
                catch (CVmException e)
                {
                    m_bGetCallbackFlag = true;
                    myInfo << QString("0x%1 == CallBackModuResFunc()").arg(e.GetErrorCode(), 0, 16);
                }
            }
        }
        return IMVS_EC_OK;
    }

    void CHikrobotEngine::slotsException(int code, QString source, QString desc, QString help)
    {
        myInfo << QString("Error code: %1, Source: %2, Description: %3, Help: %4").arg(code).arg(source).arg(desc).arg(help);
    }

    void CHikrobotEngine::loadSolution(QString strSolPath, QString strPassword)
    {
        try
        {
            m_pVmSol = LoadSolution(strSolPath.toStdString().c_str(), strPassword.toStdString().c_str());
            if (NULL == m_pVmSol)
            {
                myInfo << "LoadSolutionFromFile fail.";
                return;
            }
        }
        catch (CVmException e)
        {
            myInfo << QString("0x%1 == LoadSolutionFromFile()").arg(e.GetErrorCode(), 0, 16);
            return;
        }
        myInfo << "LoadSolutionFromFile success.";
    }

    void CHikrobotEngine::executeOnce()
    {
        try
        {
            if (NULL == m_pVmSol)
            {
                return;
            }

            m_pVmPrc = (IVmProcedure *)(*m_pVmSol)["calibration"];
            if (NULL == m_pVmPrc)
            {
                myInfo << "LoadSolutionFromFile fail.";
                return;
            }

            pModuleImageSourceTool = (ImageSourceModuleTool *)(*m_pVmSol)["calibration.Image Source1"];
            if (NULL == pModuleImageSourceTool) return;
            pModuleCircleFindTool = (IMVSCircleFindModuTool *)(*m_pVmSol)["calibration.圆查找1"];
            if (NULL == pModuleCircleFindTool) return;
            pModuleImageSourceTool->EnableResultCallback();
            pModuleCircleFindTool->EnableResultCallback();

            m_pVmSol->DisableModulesCallback();
            //m_pVmSol->EnableModulesCallback();
            m_bGetCallbackFlag = false;
            m_pVmPrc->Run();

            while (!m_bGetCallbackFlag)
            {
                QThread::msleep(20);
            }
        }
        catch (CVmException e)
        {
            myInfo << QString("0x%1 == Run()").arg(e.GetErrorCode(), 0, 16);
            return;
        }
        catch (...)
        {
            myInfo << "Interface Exception!";
        }
        myInfo << "Run success.";
    }

    void CHikrobotEngine::getimagesourceresult()
    {
        try
        {
            if (NULL == m_pVmSol) return;

            m_pVmPrc = (IVmProcedure *)(*m_pVmSol)["calibration"];
            if (NULL == m_pVmPrc)
            {
                myInfo << "Procedure name doesn't exist!";
                return;
            }

            ImageSourceModuleTool * pImageSourceTool = (ImageSourceModuleTool *)(*m_pVmSol)["calibration.Image Source1"];
            if (NULL == pImageSourceTool) return;

            m_pVmSol->DisableModulesCallback();
            pImageSourceTool->EnableResultCallback();
            m_bGetCallbackFlag = false;
            m_pVmPrc->Run();

            while (!m_bGetCallbackFlag)  { QThread::msleep(20); }

            ImageSourceResults * pImageSourceResult = pImageSourceTool->GetResult();
            if (NULL == pImageSourceResult) return;
            ImageBaseData mshowImage = pImageSourceResult->GetImageData();
            if (NULL == mshowImage.ImageData) return;

            if (NULL == m_pstInputImage)
            {
                int nRet = CreateImageInstance(&m_pstInputImage);
                if (MVD_OK != nRet)
                {
                    myInfo << "Failed to create image instance!";
                    return;
                }
            }
            MVD_IMAGE_DATA_INFO stImageDataInfo;
            stImageDataInfo.stDataChannel[0].pData = (unsigned char*)mshowImage.ImageData;
            stImageDataInfo.stDataChannel[0].nRowStep = (unsigned int)mshowImage.Width;
            stImageDataInfo.stDataChannel[0].nLen = mshowImage.DataLen;
            stImageDataInfo.stDataChannel[0].nSize = mshowImage.DataLen;

            QImage img(reinterpret_cast<const uchar*>(mshowImage.ImageData), mshowImage.Width, mshowImage.Height,mshowImage.Width, QImage::Format_Grayscale8);
            // QString outputFile = "output.png";
            // img.save(outputFile);
            emit sigGrabImage(img);

            // m_pstInputImage->InitImage(mshowImage.Width, mshowImage.Height, MVD_PIXEL_FORMAT::MVD_PIXEL_MONO_08, stImageDataInfo);
            // char*  pcFileName = "Proimage.jpg";
            // m_pstInputImage->SaveImage(pcFileName);

            m_pVmSol->DisableModulesCallback();
        }
        catch (CVmException e)
        {
            myInfo << QString("0x%1 == Getprocedureresult()").arg(e.GetErrorCode(), 0, 16);
        }
    }
};