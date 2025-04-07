/***************************************************************************************************
 * File：IVmP2CMeasure.h
 * Note：CH: 点圆测量模块接口声明 | En: Interface for the P2CMeasure tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_P2CMEASURE_H_
#define _IVM_P2CMEASURE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSP2CMeasureModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 输出角度范围 | EN: RunParam_OutputAngleRange
        typedef enum _OutputAngleRangeEnum
        {
            // CH: -90°-90° | EN: RunParam_RangeSegment
            OutputAngleRange_RangeSegment = 0x0,

            // CH: -180°-180° | EN: RunParam_RangeLinear
            OutputAngleRange_RangeLinear = 0x1,

        }OutputAngleRangeEnum;

        /*  Note: Interface Classes of the parameter of the P2CMeasureParams.  */
        class P2CMeasureParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit P2CMeasureParams() {}
            virtual ~P2CMeasureParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入点(仅当次执行起效) | EN: Input Point(Only valid for this execution)
            virtual void SetInputPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入圆(仅当次执行起效) | EN: InputCircleAnnulus(Only valid for this execution)
            virtual void SetInputCircleAnnulus(Annulus* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输出角度范围 | EN: RunParam_OutputAngleRange
            __declspec(property(put = SetOutputAngleRange, get = GetOutputAngleRange)) OutputAngleRangeEnum OutputAngleRange;

            virtual OutputAngleRangeEnum GetOutputAngleRange() = 0;

            virtual void SetOutputAngleRange(OutputAngleRangeEnum value) = 0;

            // CH: 角度判断 | EN: Angle Check
            __declspec(property(put = SetAngleLimitEnable, get = GetAngleLimitEnable)) bool AngleLimitEnable;

            virtual bool GetAngleLimitEnable() = 0;

            virtual void SetAngleLimitEnable(bool value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngleLimitLow, get = GetAngleLimitLow)) double AngleLimitLow;

            virtual double GetAngleLimitLow() = 0;

            virtual void SetAngleLimitLow(double value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngleLimitHigh, get = GetAngleLimitHigh)) double AngleLimitHigh;

            virtual double GetAngleLimitHigh() = 0;

            virtual void SetAngleLimitHigh(double value) = 0;

            // CH: 中心距离判断 | EN: Center Distance Check
            __declspec(property(put = SetDistCenterLimitEnable, get = GetDistCenterLimitEnable)) bool DistCenterLimitEnable;

            virtual bool GetDistCenterLimitEnable() = 0;

            virtual void SetDistCenterLimitEnable(bool value) = 0;

            // CH: 中心距离范围 | EN: Center Distance Range
            __declspec(property(put = SetDistCenterLimitLow, get = GetDistCenterLimitLow)) double DistCenterLimitLow;

            virtual double GetDistCenterLimitLow() = 0;

            virtual void SetDistCenterLimitLow(double value) = 0;

            // CH: 中心距离范围 | EN: Center Distance Range
            __declspec(property(put = SetDistCenterLimitHigh, get = GetDistCenterLimitHigh)) double DistCenterLimitHigh;

            virtual double GetDistCenterLimitHigh() = 0;

            virtual void SetDistCenterLimitHigh(double value) = 0;

            // CH: 最近距离判断 | EN: Closest Distance Check
            __declspec(property(put = SetDistClosestLimitEnable, get = GetDistClosestLimitEnable)) bool DistClosestLimitEnable;

            virtual bool GetDistClosestLimitEnable() = 0;

            virtual void SetDistClosestLimitEnable(bool value) = 0;

            // CH: 最近距离范围 | EN: Closest Distance Range
            __declspec(property(put = SetDistClosestLimitLow, get = GetDistClosestLimitLow)) double DistClosestLimitLow;

            virtual double GetDistClosestLimitLow() = 0;

            virtual void SetDistClosestLimitLow(double value) = 0;

            // CH: 最近距离范围 | EN: Closest Distance Range
            __declspec(property(put = SetDistClosestLimitHigh, get = GetDistClosestLimitHigh)) double DistClosestLimitHigh;

            virtual double GetDistClosestLimitHigh() = 0;

            virtual void SetDistClosestLimitHigh(double value) = 0;

            // CH: 最远距离判断 | EN: Furthest Distance Check
            __declspec(property(put = SetDistFarthestLimitEnable, get = GetDistFarthestLimitEnable)) bool DistFarthestLimitEnable;

            virtual bool GetDistFarthestLimitEnable() = 0;

            virtual void SetDistFarthestLimitEnable(bool value) = 0;

            // CH: 最远距离范围 | EN: Furthest Distance Range
            __declspec(property(put = SetDistFarthestLimitLow, get = GetDistFarthestLimitLow)) double DistFarthestLimitLow;

            virtual double GetDistFarthestLimitLow() = 0;

            virtual void SetDistFarthestLimitLow(double value) = 0;

            // CH: 最远距离范围 | EN: Furthest Distance Range
            __declspec(property(put = SetDistFarthestLimitHigh, get = GetDistFarthestLimitHigh)) double DistFarthestLimitHigh;

            virtual double GetDistFarthestLimitHigh() = 0;

            virtual void SetDistFarthestLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the P2CMeasureResults.  */
        class P2CMeasureResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit P2CMeasureResults() {}
            virtual ~P2CMeasureResults() {}

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
             * 点与圆心之间的角度
             * @par 权限
             * 只读
             */
            virtual float GetAngle() = 0;
            /**
             * @par 说明
             * 点到圆心的距离
             * @par 权限
             * 只读
             */
            virtual float GetCenterDist() = 0;
            /**
             * @par 说明
             * 点到圆上点的最近距离
             * @par 权限
             * 只读
             */
            virtual float GetCloestDist() = 0;
            /**
             * @par 说明
             * 点到圆上点的最远距离
             * @par 权限
             * 只读
             */
            virtual float GetFarthestDist() = 0;
            /**
             * @par 说明
             * 测量点
             * @par 权限
             * 可读
             */
            virtual PointF GetMeasurePoint() = 0;
            /**
             * @par 说明
             * 测量圆
             * @par 权限
             * 可读
             */
            virtual Circle GetMeasureCircle() = 0;
            /**
            * @par 说明
            * 测量圆环
            * @par 权限
            * 可读
            */
            virtual Annulus GetMeasureCircleAnnulus() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the P2CMeasure tool.  */
        class IMVSP2CMeasureModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSP2CMeasureModuTool() {}
            virtual ~IMVSP2CMeasureModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual P2CMeasureParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual P2CMeasureResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSP2CMeasureModuTool(IMVSP2CMeasureModuTool&);
            IMVSP2CMeasureModuTool& operator=(IMVSP2CMeasureModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for P2CMeasure.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSP2CMeasureModu::IMVSP2CMeasureModuTool * __stdcall GetP2CMeasureToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_P2CMEASURE_H_
