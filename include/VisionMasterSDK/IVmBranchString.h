/***************************************************************************************************
 * File：IVmBranchString.h
 * Note：CH: 分支字符模块接口声明 | En: Interface for the BranchString tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_BRANCHSTRING_H_
#define _IVM_BRANCHSTRING_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

#define MAX_BRANCH_VAR_NUM  32
#define MAX_BRANCH_PARAM_LEN  128
namespace VisionMasterSDK
{
    namespace BranchStringCpmL
    {
        /*************************** Params Class Start ***************************/

        /*  Note: Interface Classes of the parameter of the branch string Item.  */
        class BranchStringItemParam
        {
            protected:
            ///< Constructor and Destructor
            explicit BranchStringItemParam() {}
            virtual ~BranchStringItemParam() {}

        public:

            // CH: 分支id value | EN: branch id Value
            __declspec(property(get = GetBranchID)) int BranchID;

            virtual int GetBranchID() = 0;

            // CH: 分支输入字符  | EN: InputValue Value
            __declspec(property(put = SetInputValue, get = GetInputValue)) const char* InputValue;

            virtual const char* GetInputValue() = 0;

            virtual void SetInputValue(const char* value) = 0;

            // CH: 调试模式  | EN: debug Value
            __declspec(property(put = SetIsDebugMode, get = GetIsDebugMode)) bool IsDebugMode;

            virtual bool GetIsDebugMode() = 0;

            virtual void SetIsDebugMode(bool value) = 0;
        };

        // CH: 分支字符信息结构体 | EN: branch information list structure
        typedef struct _BranchStringItemlist
        {
            unsigned int nNum;                                                     // CH: 元素数量 | EN: branch item Number
            BranchStringItemParam *astBranchStringItemInfo[MAX_BRANCH_VAR_NUM];    // CH: 元素信息 | EN: branch item Info
            unsigned int nReserved[4];                                             // CH: 保留字段 | EN: Reserved

        }BranchStringItemList;

        /*  Note: Interface Classes of the parameter of the BranchStringParams.  */
        class BranchStringParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BranchStringParams() {}
            virtual ~BranchStringParams() {}

        public:

            // CH: 输入文本(仅当次执行起效) | EN: Input Text(Only valid for this execution)
            virtual void SetStringA(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // CH: 获取分支字符项 | EN: Get Branch String Item Param
            // CH: 参数名称为界面id名 如"2" | EN: Parameters branch id such as "2"
            virtual BranchStringItemParam * GetBranchStrItemParam(int branchID) = 0;

			// CH: 获取所有分支字符项 | EN: Get all branch string item
            virtual BranchStringItemList*  GetBranchStrItemParamList() = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the BranchStringResults.  */
        class BranchStringResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BranchStringResults() {}
            virtual ~BranchStringResults() {}

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
             * 获取分支路线
             * @par 权限
             * 只读
             */
            /* Gets information of the BranchMatch. */
            virtual const char * GetBranchMatch() = 0;

            /**
             * @par 说明
             * 获取分支条件字符
             * @par 权限
             * 只读
             */
            /* Gets information of the StringMatch. */
            virtual const char * GetStringMatch() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the BranchString tool.  */
        class BranchStringCpmLTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BranchStringCpmLTool() {}
            virtual ~BranchStringCpmLTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual BranchStringParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual BranchStringResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            BranchStringCpmLTool(BranchStringCpmLTool&);
            BranchStringCpmLTool& operator=(BranchStringCpmLTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for BranchString.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::BranchStringCpmL::BranchStringCpmLTool * __stdcall GetBranchStringToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_BRANCHSTRING_H_
