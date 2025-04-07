/***************************************************************************************************
 * File：IVmDataAssemble.h
 * Note：CH: 协议组装模块接口声明 | En: Interface for the DataAssemble tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_DATAASSEMBLE_H_
#define _IVM_DATAASSEMBLE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace DataAssembleModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 方式选择 | EN: Handler Mode
        typedef enum _AssembleTypeEnum
        {
            // CH: 文本组装 | EN: Text
            AssembleType_TxtAssemble = 0x0,

            // CH: 脚本组装 | EN: Script
            AssembleType_ScriptAssemble = 0x1,

        }AssembleTypeEnum;

        /*  Note: Interface Classes of the parameter of the DataAssembleParams.  */
        class DataAssembleParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DataAssembleParams() {}
            virtual ~DataAssembleParams() {}

        public:

            // CH: 方式选择 | EN: Handler Mode
            __declspec(property(put = SetAssembleType, get = GetAssembleType)) AssembleTypeEnum AssembleType;

            virtual AssembleTypeEnum GetAssembleType() = 0;

            virtual void SetAssembleType(AssembleTypeEnum value) = 0;

            // CH: 分隔符 | EN: Split Symbol
            __declspec(property(put = SetSeparator, get = GetSeparator)) const char* Separator;

            virtual const char* GetSeparator() = 0;

            virtual void SetSeparator(const char* value) = 0;

            // CH: 路径选择 | EN: Select Path
            __declspec(property(put = SetPyScriptPath, get = GetPyScriptPath)) const char* PyScriptPath;

            virtual const char* GetPyScriptPath() = 0;

            virtual void SetPyScriptPath(const char* value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the DataAssembleResults.  */
        class DataAssembleResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DataAssembleResults() {}
            virtual ~DataAssembleResults() {}

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
             * 获取组装结果
             * @par 权限
             * 只读
             */
            /* Gets information of the AssembleResult. */
            virtual const char * GetAssembleResult() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the DataAssemble tool.  */
        class DataAssembleModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DataAssembleModuleTool() {}
            virtual ~DataAssembleModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual DataAssembleParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual DataAssembleResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            DataAssembleModuleTool(DataAssembleModuleTool&);
            DataAssembleModuleTool& operator=(DataAssembleModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for DataAssemble.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::DataAssembleModule::DataAssembleModuleTool * __stdcall GetDataAssembleToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_DATAASSEMBLE_H_
