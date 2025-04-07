/***************************************************************************************************
 * File：IVmBranch.h
 * Note：CH: 分支模块模块接口声明 | En: Interface for the Branch tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_BRANCH_H_
#define _IVM_BRANCH_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace BranchModule_STD
    {
        /*************************** Params Class Start ***************************/
        // CH: 索引选择 | EN: Index Selection
        typedef enum _IndexUserSetEnum
        {
            // CH: 按值索引 | EN: Index by Value
            IndexUserSet_IndexByValue = 0,

            // CH: 按位索引 | EN: Index by Bit
            IndexUserSet_IndexByBit = 1,

        }IndexUserSetEnum;

        /*  Note: Interface Classes of the parameter of the BranchParams.  */
        class BranchParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BranchParams() {}
            virtual ~BranchParams() {}

        public:

            // CH: 结果标志(仅当次执行起效) | EN: inputint(Only valid for this execution)
            virtual void SetInputint(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 索引选择 | EN: Index Selection
            __declspec(property(put = SetIndexUserSet, get = GetIndexUserSet)) IndexUserSetEnum IndexUserSet;

            virtual IndexUserSetEnum GetIndexUserSet() = 0;

            virtual void SetIndexUserSet(IndexUserSetEnum value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the BranchResults.  */
        class BranchResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BranchResults() {}
            virtual ~BranchResults() {}

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
             * 获取传输标志
             * @par 权限
             * 只读
             */
            /* Gets information of the transport flag. */
            virtual int GetOutputInt() = 0;

            /**
             * @par 说明
             * 获取分支路线
             * @par 权限
             * 只读
             */
            /* Gets information of the BranchMatch. */
            virtual const char * GetBranchMatch() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Branch tool.  */
        class BranchModule_STDTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BranchModule_STDTool() {}
            virtual ~BranchModule_STDTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual BranchParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual BranchResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            BranchModule_STDTool(BranchModule_STDTool&);
            BranchModule_STDTool& operator=(BranchModule_STDTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Branch.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::BranchModule_STD::BranchModule_STDTool * __stdcall GetBranchToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_BRANCH_H_
