/***************************************************************************************************
 * File：IVmCalculator.h
 * Note：CH: 变量计算模块接口声明 | En: Interface for the Calculator tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CALCULATOR_H_
#define _IVM_CALCULATOR_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace CalculatorModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the CalculatorParams.  */
        class CalculatorParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CalculatorParams() {}
            virtual ~CalculatorParams() {}

        public:

            // CH: 重置 | EN: Reset
            virtual int DoResetValue() = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the CalculatorResults.  */
        class CalculatorResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CalculatorResults() {}
            virtual ~CalculatorResults() {}

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
             * 获取结果显示
             * @par 权限
             * 只读
             */
            /* Gets information of the ResultShow. */
            virtual const char * GetResultShow() = 0;
            /**
             * @par 说明
             * 结果数量
             * @par 权限
             * 只读
             */
            virtual int GetResultNum() = 0;
            /**
             * @par 说明
             * 获取结果显示
             * @par 权限
             * 只读
             */
            virtual CalOutputResultInfo * GetResult(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Calculator tool.  */
        class CalculatorModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CalculatorModuleTool() {}
            virtual ~CalculatorModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CalculatorParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CalculatorResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            CalculatorModuleTool(CalculatorModuleTool&);
            CalculatorModuleTool& operator=(CalculatorModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Calculator.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::CalculatorModule::CalculatorModuleTool * __stdcall GetCalculatorToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CALCULATOR_H_
