#pragma once
#include "IVmSolution.h"
#include "IVmProcedure.h"
#include "IVmCircleFind.h"
#include "IVmImageSource.h"
#include "IVmExport.h"
#include "VMException.h"
#include "VmControlBaseInfo.h"
#include "MVDImageCpp.h"
#include <QWidget>

class QTextBrowser;
class QAxWidget;
class CMainWindowMenuBar;
// namespace VisionMasterSDK
// {
//     namespace VmSolution
//     {
//         class IVmSolution;
//     }
//     namespace VmProcedure
//     {
//         class IVmProcedure;
//     }
// }

using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;
using namespace VisionMasterSDK::VmProcedure;
using namespace VisionMasterSDK::IMVSCircleFindModu;
using namespace VisionMasterSDK::ImageSourceModule;
using namespace VisionDesigner;

class CMainWindow: public QWidget
{
    Q_OBJECT
public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

	void printMsg(QString p_msg);
    void loadSolution(QString strSolPath, QString strPassword);
    int CallBackModuResFunc(IN OutputPlatformInfo * const pstOutputPlatformInfo, bool bTime);
    void clickRenderBind();

protected:
	void init();

public slots:
    void slotsException(int code, QString source, QString desc, QString help);

public:
    ImageSourceModuleTool * pModuleImageSourceTool;// = (ImageSourceModuleTool *)(*m_pVmSol)["Flow1.Image Source1"];
    IMVSCircleFindModuTool * pModuleCircleFindTool;// = (IMVSCircleFindModuTool *)(*m_pVmSol)["Flow1.Circle Search1"];

    CircleEx stCirGloble;
    ImageBaseData mshowImageGloble;

    bool m_bRenderFlag;
    bool m_bGetCallbackFlag;

private:
	QTextBrowser* m_pOutMsg;
    QWidget* m_pControl;
    CMainWindowMenuBar *m_pMenuBar;

    IVmSolution* m_pVmSol;
    IVmProcedure * m_pVmPrc;
    QAxWidget *m_pSolution;
    QAxWidget *m_pRender;
};

CMainWindow* mainWindow();