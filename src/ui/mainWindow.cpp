#include "mainWindow.h"
#include "mainWindowDef.h"
#include "basic.h"
#include "system/basic.h"
#include "menuBar/menuBar.h"
#include "controlWindow/controlWindow.h"
#include "logTextBrowser/textBrowser.h"
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QAxWidget>
#include <QMessageBox>
#include <QThread>
#include <QImage>

int __stdcall CallBackModuRes(OUT OutputPlatformInfo * const pstOutputPlatformInfo, IN void * const pUser)
{
	CMainWindow * pCtrlThis = (CMainWindow *)pUser;
	int nRet = IMVS_EC_UNKNOWN;
    nRet = pCtrlThis->CallBackModuResFunc(pstOutputPlatformInfo, true);
    if (IMVS_EC_OK != nRet)
    {
        return nRet;
    }
	return IMVS_EC_OK;
}


CMainWindow* g_pMainWindow = nullptr;
CMainWindow* mainWindow()
{
    return g_pMainWindow;
};

CMainWindow::CMainWindow(QWidget *parent) : QWidget(parent), m_bRenderFlag(false), m_bGetCallbackFlag(false)
{
    g_pMainWindow = this;

    try
    {
        m_pVmSol = CreateSolutionInstance();
		m_pVmSol->RegisterCallBack(CallBackModuRes, this);
		m_pVmSol->DisableModulesCallback();

        m_pSolution = new QAxWidget(VmProcedureControlWinform, this);
        m_pSolution->dynamicCall("GetObjectPointer()");
        m_pSolution->setFixedSize(600, 600);
        m_pRender = new QAxWidget(VmRenderControlWinform, this);
        m_pRender->dynamicCall("GetObjectPointer()");
        m_pRender->setFixedSize(600, 600);
    }
    catch(CVmException e)
    {
        QString strReMsg = QString::number(e.GetErrorCode(), 16);
        strReMsg = "0x" + strReMsg + " == CreateSolutionInstance()";
        myInfo << strReMsg;
    }
    catch(...)
    {
        QString strReMsg = "Interface Exception!";
        myInfo << strReMsg;
    }

    init();

    connect(m_pSolution, SIGNAL(exception(int, QString, QString, QString)), this, SLOT(slotsException(int, QString, QString, QString)));
    connect(m_pRender, SIGNAL(exception(int, QString, QString, QString)), this, SLOT(slotsException(int, QString, QString, QString)));
}

CMainWindow::~CMainWindow()
{
    DisposeResource();
}

void CMainWindow::printMsg(QString p_msg)
{
    const QString cFont = "<font color=\"#0000FF\">%1</font>";
    m_pOutMsg->append(cFont.arg(p_msg.replace("\n", "<br>")));
    m_pOutMsg->moveCursor(m_pOutMsg->textCursor().End);
}

void CMainWindow::init()
{
    m_pMenuBar = new CMainWindowMenuBar(this);

    QWidget *pControlWidget = new QWidget;
    QVBoxLayout *pControlLayout = new QVBoxLayout;
    m_pControl = new CControl(this, m_pVmSol);
    m_pOutMsg = new CTextBrowser(this, this);
    m_pOutMsg->setStyleSheet(cStyleSheet);
    m_pOutMsg->document()->setMaximumBlockCount(300);
    m_pOutMsg->setFixedHeight(100);
    pControlLayout->addWidget(m_pControl);
    pControlLayout->addWidget(m_pOutMsg);
    pControlWidget->setLayout(pControlLayout);

    QWidget *pMainWidget = new QWidget;
    QHBoxLayout *pMainLayout = new QHBoxLayout();
    pMainLayout->addWidget(pControlWidget);
    pMainLayout->addWidget(m_pSolution);
    pMainLayout->addWidget(m_pRender);
    pMainWidget->setLayout(pMainLayout);

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addWidget(m_pMenuBar);
    pLayout->addWidget(pMainWidget);
    pLayout->setMargin(0);
    pLayout->setSpacing(2);
    this->setLayout(pLayout);
}

void CMainWindow::slotsException(int code, QString source, QString desc, QString help)
{
    QString errMsg = QString("Error code: %1, Source: %2, Description: %3, Help: %4").arg(code).arg(source).arg(desc).arg(help);
    myInfo << errMsg;
}

int CMainWindow::CallBackModuResFunc(IN OutputPlatformInfo * const pstOutputPlatformInfo, bool bTime)
{
	if (IMVS_NULL == pstOutputPlatformInfo)
	{
		return IMVS_EC_INVALID_HANDLE;
	}
	if (IMVS_NULL == (pstOutputPlatformInfo->pData))
	{
		return IMVS_EC_INVALID_HANDLE;
	}

	QString strReMsg = "";
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
			QString strReMsg = "";
			try
			{
				if (NULL == pModuleImageSourceTool)
				{ 
					m_bGetCallbackFlag = true;
					return IMVS_EC_PARAM;
				}
				ImageSourceResults * pModuleImageResult = pModuleImageSourceTool->GetResult();
				if (NULL != pModuleImageResult)
				{
					mshowImageGloble = { 0 };
					mshowImageGloble = pModuleImageResult->GetImageData();
				}

				if (NULL == pModuleCircleFindTool)
				{ 
					m_bGetCallbackFlag = true;
					return IMVS_EC_PARAM;
				}
				CircleFindResults * pModuleCircleFindResult = pModuleCircleFindTool->GetResult();
				if (NULL != pModuleCircleFindResult)
				{
					CircleEx stCir = { 0 };
					stCir.CenterX = pModuleCircleFindResult->GetCircleCenter().fX;
					stCir.CenterY = pModuleCircleFindResult->GetCircleCenter().fY;
					stCir.MajorRadius = pModuleCircleFindResult->GetCircleRadius();
					stCir.MinorRadius = pModuleCircleFindResult->GetCircleRadius();

					int nArgb = 0;
					nArgb += 100 << 16;
					nArgb += 200 << 8;
					nArgb += 150;

					stCir.Color = nArgb;
					stCir.FillColor = nArgb;
					stCir.Opacity = 1;
					stCir.StrokeThickness = 1;

					stCirGloble = stCir;
				}
				m_bGetCallbackFlag = true;
			}
			catch (CVmException e)
			{
				m_bGetCallbackFlag = true;
                strReMsg = QString("0x%1 == CallBackModuResFunc()").arg(e.GetErrorCode(), 0, 16);
				myInfo << strReMsg;
			}
		}
	}
	return IMVS_EC_OK;
}



void CMainWindow::loadSolution(QString strSolPath, QString strPassword)
{
	QString strReMsg = "";
	try
	{
		m_pVmSol = LoadSolution(strSolPath.toStdString().c_str(), strPassword.toStdString().c_str());
		if (NULL == m_pVmSol)
		{
			strReMsg = "LoadSolutionFromFile fail.";
			myInfo << strReMsg;
			return;
		}
		m_pVmPrc = (IVmProcedure *)(*m_pVmSol)["calibration"];
		if (NULL == m_pVmPrc)
		{
			QMessageBox::warning(this, QStringLiteral("Warning"), QStringLiteral("Procedure name doesn't exist!"), QMessageBox::Ok);
			return;
		}
		pModuleImageSourceTool = (ImageSourceModuleTool *)(*m_pVmSol)["calibration.Image Source1"];
		if (NULL == pModuleImageSourceTool) return;
		pModuleCircleFindTool = (IMVSCircleFindModuTool *)(*m_pVmSol)["calibration.圆查找1"];
		if (NULL == pModuleCircleFindTool) return;
	}
	catch (CVmException e)
	{
        QString strReMsg = QString("0x%1 == LoadSolutionFromFile()").arg(e.GetErrorCode(), 0, 16);
		myInfo << strReMsg;
		return;
	}

    strReMsg = "LoadSolutionFromFile success.";
    myInfo << strReMsg;
}

void CMainWindow::clickRenderBind()
{
	QString strReMsg = "";
	QString strResult = "";

	if (NULL == m_pVmSol)
	{
		return;
	}
	try
	{
		m_bRenderFlag = true;

		if (NULL == pModuleImageSourceTool) return;
		ImageSourceResults* pResult = pModuleImageSourceTool->GetResult();
		if (NULL == pResult) return;

		qlonglong pData = (qlonglong)&(pResult->GetImageData());
		m_pRender->dynamicCall("SetImageSourceData(qlonglong)", pData);

		qlonglong pDataCircle = (qlonglong)&(stCirGloble);
		m_pRender->dynamicCall("SetCircle((qlonglong)", pDataCircle);
	}
	catch (CVmException e)
	{
		QString strReMsg = QString("0x%1 == GetResult()").arg(e.GetErrorCode(), 0, 16);
		myInfo << strReMsg;
	}
    catch (...)
    {
        QString strReMsg = "Interface Exception!";
        myInfo << strReMsg;
    }
}

void CMainWindow::clickExecuteOnce()
{
	QString strReMsg = "";
	try
	{
		if (NULL == m_pVmSol) return;
		m_pVmPrc = (IVmProcedure *)(*m_pVmSol)["calibration"];
		if (NULL == m_pVmPrc)
		{
			QMessageBox::warning(this, "Warning", "Procedure name doesn't exist!");
			return;
		}
		pModuleImageSourceTool = (ImageSourceModuleTool *)(*m_pVmSol)["calibration.Image Source1"];
		if (NULL == pModuleImageSourceTool) return;
		pModuleCircleFindTool = (IMVSCircleFindModuTool *)(*m_pVmSol)["calibration.圆查找1"];
		if (NULL == pModuleCircleFindTool) return;

		m_pVmSol->DisableModulesCallback();
		pModuleImageSourceTool->EnableResultCallback();
		pModuleCircleFindTool->EnableResultCallback();
		m_bGetCallbackFlag = false;
		m_pVmPrc->Run();
		//m_pVmSol->EnableModulesCallback();
		while (!m_bGetCallbackFlag)  { QThread::msleep(20);  }
		if (true == m_bRenderFlag)
		{
			if (NULL == pModuleImageSourceTool) return;
			ImageSourceResults* pResult = pModuleImageSourceTool->GetResult();
			if (NULL == pResult) return;

			qlonglong pData = (qlonglong)&(pResult->GetImageData());
			m_pRender->dynamicCall("SetImageSourceData(qlonglong)", pData);
			qlonglong pDataCircle = (qlonglong)&(stCirGloble);
			m_pRender->dynamicCall("SetCircle((qlonglong)", pDataCircle);
		}
	}
	catch (CVmException e)
	{
		QString strReMsg = QString("0x%1 == Run()").arg(e.GetErrorCode(), 0, 16);
		myInfo << strReMsg;
		return;
	}
    catch (...)
    {
        QString strReMsg = "Interface Exception!";
        myInfo << strReMsg;
    }

	strReMsg = "Run success.";
	myInfo << strReMsg;
}

void CMainWindow::clickRenderUnBind()
{
	QString strReMsg = "";
	try
	{
		m_pVmSol->DisableModulesCallback();
		m_bRenderFlag = false;
	}
	catch (CVmException e)
	{
		QString strReMsg = QString("0x%1 == GetResult()").arg(e.GetErrorCode(), 0, 16);
		myInfo << strReMsg;
	}
	strReMsg = "Remove shape success";
	myInfo << strReMsg;
}



void CMainWindow::clickImageResults()
{
	// TODO:  在此添加控件通知处理程序代码
	QString strReMsg = "";
	try
	{
		if (NULL == m_pVmSol) return;
		m_pVmPrc = (IVmProcedure *)(*m_pVmSol)["calibration"];
		if (NULL == m_pVmPrc)
		{
			QMessageBox::warning(this, "Warning", "Procedure name doesn't exist!");
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
				QMessageBox::warning(this, "Warning", "Failed to create image instance!");
				return;
			}
		}
		MVD_IMAGE_DATA_INFO stImageDataInfo;
		stImageDataInfo.stDataChannel[0].pData = (unsigned char*)mshowImage.ImageData;
		stImageDataInfo.stDataChannel[0].nRowStep = (unsigned int)mshowImage.Width;
		stImageDataInfo.stDataChannel[0].nLen = mshowImage.DataLen;
		stImageDataInfo.stDataChannel[0].nSize = mshowImage.DataLen;

		// QImage img(reinterpret_cast<const uchar*>(mshowImage.ImageData), mshowImage.Width, mshowImage.Height,mshowImage.Width, QImage::Format_Grayscale8);
		// QString outputFile = "output.png";
		// img.save(outputFile);

		m_pstInputImage->InitImage(mshowImage.Width, mshowImage.Height, MVD_PIXEL_FORMAT::MVD_PIXEL_MONO_08, stImageDataInfo);
		char*  pcFileName = "Proimage.jpg";
		m_pstInputImage->SaveImage(pcFileName);

		m_pVmSol->DisableModulesCallback();
	}
	catch (CVmException e)
	{
		QString strReMsg = QString("0x%1 == Getprocedureresult()").arg(e.GetErrorCode(), 0, 16);
		myInfo << strReMsg;
	}
}

void CMainWindow::clickCallBackImageResults()
{
}

void CMainWindow::clickProcessResults()
{
}