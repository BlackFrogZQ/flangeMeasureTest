/***************************************************************************************************
 * File：IVmBoxFilter.h
 * Note：CH: Box过滤模块接口声明 | En: Interface for the BoxFilter tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_BOXFILTER_H_
#define _IVM_BOXFILTER_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSBoxFilterModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the BoxFilterParams.  */
        class BoxFilterParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BoxFilterParams() {}
            virtual ~BoxFilterParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 区域(仅当次执行起效) | EN: Region(Only valid for this execution)
            virtual void SetInputRegion(RectBox* pInputValue, unsigned int nValueNum) = 0;

            // CH: 最小重叠率 | EN: MinOverlap
            __declspec(property(put = SetMinOverlap, get = GetMinOverlap)) double MinOverlap;

            virtual double GetMinOverlap() = 0;

            virtual void SetMinOverlap(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the BoxFilterResults.  */
        class BoxFilterResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BoxFilterResults() {}
            virtual ~BoxFilterResults() {}

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
            * 获取过滤后保留的Box数量
            * @par 权限
            * 只读
            */
            virtual unsigned int GetNumOfOutputBoxes() = 0;
            /**
            * @brief 根据索引获取输出Box的信息
            * @param nIndex [IN] Box索引，范围[0, NumOfOutputBoxes)
            * @return 指定索引处Box的信息，出错时抛出异常
            * @par 注解
            */
            virtual RectBox GetOutputBox(unsigned int nIndex) = 0;
            /**
            * @brief 根据索引获取输出Box的编号
            * @param nIndex [IN] Box索引，范围[0, NumOfOutputBoxes)
            * @return 指定索引处Box的编号，出错时抛出异常
            * @par 如0,2为保留第1和第3个输入的box
            */
            virtual unsigned int GetIndexOfOutputBox(unsigned int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the BoxFilter tool.  */
        class IMVSBoxFilterModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSBoxFilterModuleTool() {}
            virtual ~IMVSBoxFilterModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual BoxFilterParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual BoxFilterResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSBoxFilterModuleTool(IMVSBoxFilterModuleTool&);
            IMVSBoxFilterModuleTool& operator=(IMVSBoxFilterModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for BoxFilter.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSBoxFilterModule::IMVSBoxFilterModuleTool * __stdcall GetBoxFilterToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_BOXFILTER_H_
