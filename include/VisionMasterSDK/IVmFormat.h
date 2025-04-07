/***************************************************************************************************
 * File：IVmFormat.h
 * Note：CH: 格式化模块接口声明 | En: Interface for the Format tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_FORMAT_H_
#define _IVM_FORMAT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace FormatModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the FormatParams.  */
        class FormatParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit FormatParams() {}
            virtual ~FormatParams() {}

        public:

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the FormatResults.  */
        class FormatResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit FormatResults() {}
            virtual ~FormatResults() {}

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
             * 获取格式化结果
             * @par 权限
             * 只读
             */
            /* Gets information of the FormatOut. */
            virtual const char * GetFormatOut() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Format tool.  */
        class FormatModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit FormatModuleTool() {}
            virtual ~FormatModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual FormatParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual FormatResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            FormatModuleTool(FormatModuleTool&);
            FormatModuleTool& operator=(FormatModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Format.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::FormatModule::FormatModuleTool * __stdcall GetFormatToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_FORMAT_H_
