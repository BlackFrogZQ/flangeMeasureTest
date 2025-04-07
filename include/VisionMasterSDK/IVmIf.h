/***************************************************************************************************
 * File：IVmIf.h
 * Note：CH: 条件检测模块接口声明 | En: Interface for the If tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IF_H_
#define _IVM_IF_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include <map>
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IfModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 逻辑处理模式 | EN: Logic Processing Mode
        typedef enum _LogicalModeEnum
        {
            // CH: 全部 | EN: All
            LogicalMode_And = 0x1,

            // CH: 任意 | EN: Any
            LogicalMode_Or = 0x2,

        }LogicalModeEnum;

        /*  Note: Interface Classes of the parameter of the Condition Item.  */
        class IfItemParam
        {
        protected:
            ///< Constructor and Destructor
            explicit IfItemParam() {}
            virtual ~IfItemParam() {}

        public:

            // CH: 最大值 | EN: Max Value
            __declspec(property(put = SetMaxValue, get = GetMaxValue)) double MaxValue;

            virtual double GetMaxValue() = 0;

            virtual void SetMaxValue(double value) = 0;

            // CH: 最小值 | EN: Min Value
            __declspec(property(put = SetMinValue, get = GetMinValue)) double MinValue;

            virtual double GetMinValue() = 0;

            virtual void SetMinValue(double value) = 0;
        };

        /*  Note: Interface Classes of the parameter of the IfParams.  */
        class IfParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IfParams() {}
            virtual ~IfParams() {}

        public:

            // CH: 逻辑处理模式 | EN: Logic Processing Mode
            __declspec(property(put = SetLogicalMode, get = GetLogicalMode)) LogicalModeEnum LogicalMode;

            virtual LogicalModeEnum GetLogicalMode() = 0;

            virtual void SetLogicalMode(LogicalModeEnum value) = 0;

            // CH: 获取条件项参数(最大值/最小值等)(单例模式) | EN: Get Condition Item Param(Max Value/Min Value)(Singleton Pattern)
            // CH: 参数名称为界面变量名 如"int0" | EN: Parameters Name such as "int0"
            virtual IfItemParam * GetIfItemParam(const char * const strName) = 0;

            // CH: 弃用 | EN : Obsolete
            // CH: 获取动态参数项(单例模式) | EN: Get Dynamic Parameters Item(Singleton Pattern)
            // CH: 参数名称为"界面变量名_参数用途" 如"int0_Max" | EN: Parameters Name such as "int0_Max"
            virtual ParamItem * GetDynamicParam(const char * const strName) = 0;
        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the IfResults.  */
        class IfResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IfResults() {}
            virtual ~IfResults() {}

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
             * 获取字符串结果
             * @par 权限
             * 只读
             */
            virtual const char * GetStrResult() = 0;
            /**
             * @par 说明
             * 获取整型结果
             * @par 权限
             * 只读
             */
            virtual int GetNIfResult() = 0;
            /**
             * @par 说明
             * 获取条件项结果个数
             * @par 权限
             * 只读
             */
            virtual int GetItemResultNum() = 0;
            /**
             * @par 说明
             * 获取条件项结果
             * @par nIndex [IN] 索引
             * @par 权限
             * 只读
             */
            virtual const char * GetIfItemResult(int nIndex) = 0;
            /**
             * @par 说明
             * 获取条件项状态
             * @par nIndex [IN] 索引
             * @par 权限
             * 只读
             */
            virtual int GetIfItemStatus(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the If tool.  */
        class IfModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IfModuleTool() {}
            virtual ~IfModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual IfParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual IfResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IfModuleTool(IfModuleTool&);
            IfModuleTool& operator=(IfModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for If.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IfModule::IfModuleTool * __stdcall GetIfToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IF_H_
