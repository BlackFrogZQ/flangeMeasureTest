#pragma once
#include "../IProcessToolFun.h"
#include "hikrobotEngineDef.h"
#include "IVmSolution.h"
#include "IVmProcedure.h"
#include "IVmImageSource.h"
#include "IVmCircleFind.h"
#include "IVmExport.h"
#include "VMException.h"
#include "VmControlBaseInfo.h"
#include "MVDImageCpp.h"
#include <QWidget>

using namespace VisionDesigner;
using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;
using namespace VisionMasterSDK::VmProcedure;
using namespace VisionMasterSDK::ImageSourceModule;
using namespace VisionMasterSDK::IMVSCircleFindModu;

class QAxWidget;

namespace TIGER_ProcessTool
{
    class CHikrobotEngine : public IProcessToolFun, public QWidget
    {
    public:
        CHikrobotEngine(QWidget *parent = nullptr);
        ~CHikrobotEngine();

        virtual void init() override;

        static int __stdcall CallBackModuRes(OUT OutputPlatformInfo * const pstOutputPlatformInfo, IN void * const pUser);
        int CallBackModuResFunc(IN OutputPlatformInfo * const pstOutputPlatformInfo, bool bTime);
        void loadSolution(QString strSolPath, QString strPassword);
        void executeOnce();
        void getimagesourceresult();

    public:
        ImageSourceModuleTool * pModuleImageSourceTool;
        IMVSCircleFindModuTool * pModuleCircleFindTool;

        ImageBaseData mshowImageGloble;
        CircleEx stCirGloble;

        bool m_bRenderFlag;
        bool m_bGetCallbackFlag;

    public slots:
        void slotsException(int code, QString source, QString desc, QString help);

    public:
        struct CAxWidget
        {
            CCOMObject pCOMObject;
            QString enName;
            QString cnName;
            QString CLSID;
            bool isExist;
            QAxWidget *pAxWidget;
        };
        QVector<CAxWidget> m_pAxWidgets;

    private:
        IVmSolution* m_pVmSol;
        IVmProcedure * m_pVmPrc;
        IMvdImage* m_pstInputImage;
    };
};