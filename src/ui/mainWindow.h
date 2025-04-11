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

using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;
using namespace VisionMasterSDK::VmProcedure;
using namespace VisionMasterSDK::ImageSourceModule;
using namespace VisionMasterSDK::IMVSCircleFindModu;
using namespace VisionDesigner;

class QTextBrowser;
class QAxWidget;
class CMainWindowMenuBar;

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
    ImageSourceModuleTool * pModuleImageSourceTool;
    IMVSCircleFindModuTool * pModuleCircleFindTool;

    ImageBaseData mshowImageGloble;
    CircleEx stCirGloble;

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