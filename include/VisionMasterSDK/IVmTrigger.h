/***************************************************************************************************
 * File：IVmTrigger.h
 * Note：CH: 触发模块模块接口声明 | En: Interface for the Trigger tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_TRIGGER_H_
#define _IVM_TRIGGER_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace TriggerModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the TriggerParams.  */
        class TriggerParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit TriggerParams() {}
            virtual ~TriggerParams() {}

        public:

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the TriggerResults.  */
        class TriggerResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit TriggerResults() {}
            virtual ~TriggerResults() {}

        public:
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Trigger tool.  */
        class TriggerModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit TriggerModuleTool() {}
            virtual ~TriggerModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual TriggerParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual TriggerResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            TriggerModuleTool(TriggerModuleTool&);
            TriggerModuleTool& operator=(TriggerModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Trigger.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::TriggerModule::TriggerModuleTool * __stdcall GetTriggerToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_TRIGGER_H_
