/***************************************************************************************************
 * File：IVmMultiLabelFilter.h
 * Note：CH: 多标签筛选模块接口声明 | En: Interface for the MultiLabelFilter tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MULTILABELFILTER_H_
#define _IVM_MULTILABELFILTER_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMultiLabelFilterModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the MultiLabelFilterParams.  */
        class MultiLabelFilterParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MultiLabelFilterParams() {}
            virtual ~MultiLabelFilterParams() {}

        public:

            // CH: 类别编号(仅当次执行起效) | EN: ClassIndex(Only valid for this execution)
            virtual void SetClassIndex(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 类别个数(仅当次执行起效) | EN: ClassNum(Only valid for this execution)
            virtual void SetClassNum(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the MultiLabelFilterResults.  */
        class MultiLabelFilterResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MultiLabelFilterResults() {}
            virtual ~MultiLabelFilterResults() {}

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
            * 输出图像
            * @par 权限
            * 只读
            */
            virtual ImageBaseData GetOutputImage() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the MultiLabelFilter tool.  */
        class IMVSMultiLabelFilterModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMultiLabelFilterModuTool() {}
            virtual ~IMVSMultiLabelFilterModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MultiLabelFilterParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MultiLabelFilterResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSMultiLabelFilterModuTool(IMVSMultiLabelFilterModuTool&);
            IMVSMultiLabelFilterModuTool& operator=(IMVSMultiLabelFilterModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MultiLabelFilter.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMultiLabelFilterModu::IMVSMultiLabelFilterModuTool * __stdcall GetMultiLabelFilterToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MULTILABELFILTER_H_
