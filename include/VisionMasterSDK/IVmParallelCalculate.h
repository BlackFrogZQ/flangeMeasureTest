/***************************************************************************************************
 * File：IVmParallelCalculate.h
 * Note：CH: 平行线计算模块接口声明 | En: Interface for the ParallelCalculate tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_PARALLELCALCULATE_H_
#define _IVM_PARALLELCALCULATE_H_

#include "MVD_ShapeParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSParallelCalculateModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 方式选择 | EN: Handler Mode
        typedef enum _WayToChooseEnum
        {
            // CH: 过直线外一点 | EN: A point outside the line
            WayToChoose_PointLine = 0x0,

            // CH: 与直线相距一定距离 | EN: A distance from the line
            WayToChoose_DistanceLine = 0x1,

        }WayToChooseEnum;

        /*  Note: Interface Classes of the parameter of the ParallelCalculateParams.  */
        class ParallelCalculateParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ParallelCalculateParams() {}
            virtual ~ParallelCalculateParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入点(仅当次执行起效) | EN: Input Point(Only valid for this execution)
            virtual void SetInputPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入直线(仅当次执行起效) | EN: Input Line(Only valid for this execution)
            virtual void SetInputLine(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 方式选择 | EN: Handler Mode
            __declspec(property(put = SetWayToChoose, get = GetWayToChoose)) WayToChooseEnum WayToChoose;

            virtual WayToChooseEnum GetWayToChoose() = 0;

            virtual void SetWayToChoose(WayToChooseEnum value) = 0;

            // CH: 间距 | EN: Interval
            __declspec(property(put = SetLineLength, get = GetLineLength)) double LineLength;

            virtual double GetLineLength() = 0;

            virtual void SetLineLength(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ParallelCalculateResults.  */
        class ParallelCalculateResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ParallelCalculateResults() {}
            virtual ~ParallelCalculateResults() {}

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
             * 测量点
             * @par 权限
             * 只读
             */
             virtual MVD_POINT_F GetMeasurePoint() = 0;
            /**
             * @par 说明
             * 测量直线
             * @par 权限
             * 只读
             */
             virtual Line GetMeasureLine() = 0;
            /**
             * @par 说明
             * 平行线
             * @par 权限
             * 只读
             */
             virtual Line GetParallelLine() = 0;
            /**
             * @par 说明
             * 平行线1
             * @par 权限
             * 只读
             */
             virtual Line GetParallelLine1() = 0;
            /**
             * @par 说明
             * 平行线2
             * @par 权限
             * 只读
             */
             virtual Line GetParallelLine2() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ParallelCalculate tool.  */
        class IMVSParallelCalculateModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSParallelCalculateModuTool() {}
            virtual ~IMVSParallelCalculateModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ParallelCalculateParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ParallelCalculateResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSParallelCalculateModuTool(IMVSParallelCalculateModuTool&);
            IMVSParallelCalculateModuTool& operator=(IMVSParallelCalculateModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ParallelCalculate.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSParallelCalculateModu::IMVSParallelCalculateModuTool * __stdcall GetParallelCalculateToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_PARALLELCALCULATE_H_
