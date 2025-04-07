/***************************************************************************************************
 * File：IVmTimeStatistic.h
 * Note：CH: 耗时统计模块接口声明 | En: Interface for the TimeStatistic tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_TIMESTATISTIC_H_
#define _IVM_TIMESTATISTIC_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace TimeStatisticModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the TimeStatisticParams.  */
        class TimeStatisticParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit TimeStatisticParams() {}
            virtual ~TimeStatisticParams() {}

        public:

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the TimeStatisticResults.  */
        class TimeStatisticResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit TimeStatisticResults() {}
            virtual ~TimeStatisticResults() {}

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
             * 获取Time
             * @par 权限
             * 只读
             */
            virtual float GetTime() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the TimeStatistic tool.  */
        class TimeStatisticModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit TimeStatisticModuleTool() {}
            virtual ~TimeStatisticModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual TimeStatisticParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual TimeStatisticResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            TimeStatisticModuleTool(TimeStatisticModuleTool&);
            TimeStatisticModuleTool& operator=(TimeStatisticModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for TimeStatistic.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::TimeStatisticModule::TimeStatisticModuleTool * __stdcall GetTimeStatisticToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_TIMESTATISTIC_H_
