/***************************************************************************************************
 * File：IVmStringCompare.h
 * Note：CH: 字符比较模块接口声明 | En: Interface for the StringCompare tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_STRINGCOMPARE_H_
#define _IVM_STRINGCOMPARE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace StringCompareModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the StringCompareParams.  */
        class StringCompareParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit StringCompareParams() {}
            virtual ~StringCompareParams() {}

        public:

            // CH: 输入文本(仅当次执行起效) | EN: Input Text(Only valid for this execution)
            virtual void SetStringA(InputStringData* pInputValue, unsigned int nValueNum) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the StringCompareResults.  */
        class StringCompareResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit StringCompareResults() {}
            virtual ~StringCompareResults() {}

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
             * 获取分支条件字符
             * @par 权限
             * 只读
             */
            virtual const char * GetStringMatch() = 0;

            /**
             * @par 说明
             * 获取Index
             * @par 权限
             * 只读
             */
            virtual int GetIndex() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the StringCompare tool.  */
        class StringCompareModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit StringCompareModuleTool() {}
            virtual ~StringCompareModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual StringCompareParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual StringCompareResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            StringCompareModuleTool(StringCompareModuleTool&);
            StringCompareModuleTool& operator=(StringCompareModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for StringCompare.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::StringCompareModule::StringCompareModuleTool * __stdcall GetStringCompareToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_STRINGCOMPARE_H_
