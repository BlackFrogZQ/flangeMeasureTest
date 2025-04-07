/***************************************************************************************************
 * File：IVmBoxOverlapCalculation.h
 * Note：CH: Box重叠率模块接口声明 | En: Interface for the BoxOverlapCalculation tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_BOXOVERLAPCALCULATION_H_
#define _IVM_BOXOVERLAPCALCULATION_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSBoxOverlapCalculationModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the BoxOverlapCalculationParams.  */
        class BoxOverlapCalculationParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BoxOverlapCalculationParams() {}
            virtual ~BoxOverlapCalculationParams() {}

        public:

            // CH: 区域1(仅当次执行起效) | EN: region1(Only valid for this execution)
            virtual void SetInputBOX1(RectBox* pInputValue, unsigned int nValueNum) = 0;

            // CH: 区域2(仅当次执行起效) | EN: region2(Only valid for this execution)
            virtual void SetInputBOX2(RectBox* pInputValue, unsigned int nValueNum) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the BoxOverlapCalculationResults.  */
        class BoxOverlapCalculationResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BoxOverlapCalculationResults() {}
            virtual ~BoxOverlapCalculationResults() {}

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
            * 输出重叠率
            * @par 权限
            * 只读
            */
            virtual float GetOverlap() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the BoxOverlapCalculation tool.  */
        class IMVSBoxOverlapCalculationModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSBoxOverlapCalculationModuTool() {}
            virtual ~IMVSBoxOverlapCalculationModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual BoxOverlapCalculationParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual BoxOverlapCalculationResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSBoxOverlapCalculationModuTool(IMVSBoxOverlapCalculationModuTool&);
            IMVSBoxOverlapCalculationModuTool& operator=(IMVSBoxOverlapCalculationModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for BoxOverlapCalculation.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSBoxOverlapCalculationModu::IMVSBoxOverlapCalculationModuTool * __stdcall GetBoxOverlapCalculationToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_BOXOVERLAPCALCULATION_H_
