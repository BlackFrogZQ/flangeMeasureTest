#pragma once
#include "../IProcessToolFun.h"
#include "IVmSolution.h"
#include "IVmProcedure.h"
#include "IVmImageSource.h"
#include "IVmCircleFind.h"
#include "IVmExport.h"
#include "VMException.h"
#include "VmControlBaseInfo.h"
#include "MVDImageCpp.h"

using namespace VisionDesigner;
using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;
using namespace VisionMasterSDK::VmProcedure;
using namespace VisionMasterSDK::ImageSourceModule;
using namespace VisionMasterSDK::IMVSCircleFindModu;

class QAxWidget;

namespace TIGER_ProcessTool
{
    class CHikrobotEngine : IProcessToolFun
    {
    public:
        CHikrobotEngine();
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

    protected:
        struct CAxWidget
        {
            QString name;
            bool isAdd;
            QAxWidget *pAxWidget;
        };

    private:
        IVmSolution* m_pVmSol;
        IVmProcedure * m_pVmPrc;
        QVector<CAxWidget> m_pAxWidgets;

        IMvdImage* m_pstInputImage;
    };
};