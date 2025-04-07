/***************************************************************************************************
 * File：IVmIfBranch.h
 * Note：CH: 条件分支模块接口声明 | En: Interface for the IfBranch tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IFBRANCH_H_
#define _IVM_IFBRANCH_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IfBranchModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 分支结果输出判断 
        typedef enum _BranchStateEnum
        {
            // CH: OK输出
            BranchState_OK = 0x1,

            // CH: NG输出 
            BranchState_NG = 0x2,

        }BranchStateEnum;

        /*  Note: Interface Classes of the parameter of the IfBranchParams.  */
        class IfBranchParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IfBranchParams() {}
            virtual ~IfBranchParams() {}

        public:
            //设置整型条件项的最小值
            virtual void SetIntMinValue(const char * const strName, int nMin) = 0;
            //获取整型条件项的最小值
            virtual int GetIntMinValue(const char * const strName) = 0;

            //设置浮点条件项的最小值
            virtual void SetFloatMinValue(const char * const strName, double dMin) = 0;
            //获取浮点条件项的最小值
            virtual double GetFloatMinValue(const char * const strName) = 0;


            //设置整型条件项的最大值
            virtual void SetIntMaxValue(const char * const strName, int nMax) = 0;
            //获取整型条件项的最大值
            virtual int GetIntMaxValue(const char * const strName) = 0;

            //设置浮点条件项的最大值
            virtual void SetFloatMaxValue(const char * const strName, double dMax) = 0;
            //获取浮点条件项的最大值
            virtual double GetFloatMaxValue(const char * const strName) = 0;


            //设置条件项的判断条件
            virtual void SetStateValue(const char * const strName, BranchStateEnum eState) = 0;
            //获取条件项的判断条件
            virtual BranchStateEnum GetStateValue(const char * const strName) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the IfBranchResults.  */
        class IfBranchResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IfBranchResults() {}
            virtual ~IfBranchResults() {}

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
             * 分支路线
             * @par 权限
             * 只读
             */
             virtual const char * GetBranchMatch() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the IfBranch tool.  */
        class IfBranchModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IfBranchModuleTool() {}
            virtual ~IfBranchModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual IfBranchParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual IfBranchResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IfBranchModuleTool(IfBranchModuleTool&);
            IfBranchModuleTool& operator=(IfBranchModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for IfBranch.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IfBranchModule::IfBranchModuleTool * __stdcall GetIfBranchToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IFBRANCH_H_
