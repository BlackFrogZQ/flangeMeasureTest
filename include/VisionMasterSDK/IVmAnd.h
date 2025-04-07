/***************************************************************************************************
 * File：IVmAnd.h
 * Note：CH: 逻辑模块接口声明 | En: Interface for the And tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_AND_H_
#define _IVM_AND_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace AndModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 逻辑运算类型 | EN: Logical Operation Type
        typedef enum _LogicalModeEnum
        {
            // CH: 与 | EN: AND
            LogicalMode_And = 0x1,

            // CH: 或 | EN: OR
            LogicalMode_Or = 0x2,

            // CH: 非 | EN: NOT
            LogicalMode_Not = 0x5,

            // CH: 与非 | EN: NAND
            LogicalMode_AndNot = 0x3,

            // CH: 或非 | EN: NOR
            LogicalMode_OrNot = 0x4,

        }LogicalModeEnum;

        /*  Note: Interface Classes of the parameter of the AndParams.  */
        class AndParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit AndParams() {}
            virtual ~AndParams() {}

        public:

            // CH: 逻辑运算类型 | EN: Logical Operation Type
            __declspec(property(put = SetLogicalMode, get = GetLogicalMode)) LogicalModeEnum LogicalMode;

            virtual LogicalModeEnum GetLogicalMode() = 0;

            virtual void SetLogicalMode(LogicalModeEnum value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the AndResults.  */
        class AndResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit AndResults() {}
            virtual ~AndResults() {}

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
             * 运算结果（BOOL）
             * @par 权限
             * 只读
             */
            virtual int GetAndResult() = 0;

            /**
             * @par 说明
             * 运算结果（STRING）
             * @par 权限
             * 只读
             */
            virtual const char * GetStrAndResult() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the And tool.  */
        class AndModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit AndModuleTool() {}
            virtual ~AndModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual AndParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual AndResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            AndModuleTool(AndModuleTool&);
            AndModuleTool& operator=(AndModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for And.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::AndModule::AndModuleTool * __stdcall GetAndToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_AND_H_
