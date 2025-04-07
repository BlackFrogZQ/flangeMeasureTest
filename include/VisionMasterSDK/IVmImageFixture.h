/***************************************************************************************************
 * File：IVmImageFixture.h
 * Note：CH: 图像修正模块接口声明 | En: Interface for the ImageFixture tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGEFIXTURE_H_
#define _IVM_IMAGEFIXTURE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageFixtureModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the ImageFixtureParams.  */
        class ImageFixtureParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageFixtureParams() {}
            virtual ~ImageFixtureParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 位置修正信息(仅当次执行起效) | EN: Position Correction Info(Only valid for this execution)
            virtual void SetPositionCorrectionInfo(Fixture* pInputValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageFixtureResults.  */
        class ImageFixtureResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageFixtureResults() {}
            virtual ~ImageFixtureResults() {}

        public:
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
            /**
             * @par 说明
             * 输出图像
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutputImage() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageFixture tool.  */
        class IMVSImageFixtureModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageFixtureModuTool() {}
            virtual ~IMVSImageFixtureModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageFixtureParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageFixtureResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageFixtureModuTool(IMVSImageFixtureModuTool&);
            IMVSImageFixtureModuTool& operator=(IMVSImageFixtureModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageFixture.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageFixtureModu::IMVSImageFixtureModuTool * __stdcall GetImageFixtureToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGEFIXTURE_H_
