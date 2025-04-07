/***************************************************************************************************
 * File：IVmFrameMean.h
 * Note：CH: 帧平均模块接口声明 | En: Interface for the FrameMean tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_FRAMEMEAN_H_
#define _IVM_FRAMEMEAN_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSFrameMeanModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the FrameMeanParams.  */
        class FrameMeanParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit FrameMeanParams() {}
            virtual ~FrameMeanParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the FrameMeanResults.  */
        class FrameMeanResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit FrameMeanResults() {}
            virtual ~FrameMeanResults() {}

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
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;
            /**
             * @par 说明
             * 获取已统计图像数
             * @par 权限
             * 只读
             */
            virtual int GetImgCount() = 0;

            /**
             * @par 说明
             * 获取输出图像
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutputImage() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the FrameMean tool.  */
        class IMVSFrameMeanModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSFrameMeanModuTool() {}
            virtual ~IMVSFrameMeanModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual FrameMeanParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual FrameMeanResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSFrameMeanModuTool(IMVSFrameMeanModuTool&);
            IMVSFrameMeanModuTool& operator=(IMVSFrameMeanModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for FrameMean.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSFrameMeanModu::IMVSFrameMeanModuTool * __stdcall GetFrameMeanToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_FRAMEMEAN_H_
