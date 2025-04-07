/***************************************************************************************************
 * File：IVmSendDatas.h
 * Note：CH: 发送数据模块接口声明 | En: Interface for the SendDatas tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_SENDDATAS_H_
#define _IVM_SENDDATAS_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace SendDatasModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the SendDatasParams.  */
        class SendDatasParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SendDatasParams() {}
            virtual ~SendDatasParams() {}

        public:

            // CH: 输入图像1(仅当次执行起效) | EN: InputImage1(Only valid for this execution)
            virtual void SetInputImage1(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像2(仅当次执行起效) | EN: InputImage2(Only valid for this execution)
            virtual void SetInputImage2(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像3(仅当次执行起效) | EN: InputImage3(Only valid for this execution)
            virtual void SetInputImage3(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像4(仅当次执行起效) | EN: InputImage4(Only valid for this execution)
            virtual void SetInputImage4(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像5(仅当次执行起效) | EN: InputImage5(Only valid for this execution)
            virtual void SetInputImage5(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像6(仅当次执行起效) | EN: InputImage6(Only valid for this execution)
            virtual void SetInputImage6(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像7(仅当次执行起效) | EN: InputImage7(Only valid for this execution)
            virtual void SetInputImage7(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像8(仅当次执行起效) | EN: InputImage8(Only valid for this execution)
            virtual void SetInputImage8(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像9(仅当次执行起效) | EN: InputImage9(Only valid for this execution)
            virtual void SetInputImage9(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像10(仅当次执行起效) | EN: InputImage10(Only valid for this execution)
            virtual void SetInputImage10(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像11(仅当次执行起效) | EN: InputImage11(Only valid for this execution)
            virtual void SetInputImage11(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像12(仅当次执行起效) | EN: InputImage12(Only valid for this execution)
            virtual void SetInputImage12(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像13(仅当次执行起效) | EN: InputImage13(Only valid for this execution)
            virtual void SetInputImage13(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像14(仅当次执行起效) | EN: InputImage14(Only valid for this execution)
            virtual void SetInputImage14(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像15(仅当次执行起效) | EN: InputImage15(Only valid for this execution)
            virtual void SetInputImage15(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像16(仅当次执行起效) | EN: InputImage16(Only valid for this execution)
            virtual void SetInputImage16(ImageBaseData* pInputValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the SendDatasResults.  */
        class SendDatasResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SendDatasResults() {}
            virtual ~SendDatasResults() {}

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
             * 发送数据
             * @par 权限
             * 只读
             */
            virtual const char * GetSendData() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the SendDatas tool.  */
        class SendDatasModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SendDatasModuleTool() {}
            virtual ~SendDatasModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual SendDatasParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual SendDatasResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            SendDatasModuleTool(SendDatasModuleTool&);
            SendDatasModuleTool& operator=(SendDatasModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for SendDatas.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::SendDatasModule::SendDatasModuleTool * __stdcall GetSendDatasToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_SENDDATAS_H_
