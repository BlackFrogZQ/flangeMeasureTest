/***************************************************************************************************
 * File：IVmP2PMeasure.h
 * Note：CH: 点点测量模块接口声明 | En: Interface for the P2PMeasure tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_P2PMEASURE_H_
#define _IVM_P2PMEASURE_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSP2PMeasureModu
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

        /*  Note: Interface Classes of the parameter of the P2PMeasureParams.  */
        class P2PMeasureParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit P2PMeasureParams() {}
            virtual ~P2PMeasureParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入点1(仅当次执行起效) | EN: Input Point1(Only valid for this execution)
            virtual void SetInputPoint1(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入点2(仅当次执行起效) | EN: Input Point2(Only valid for this execution)
            virtual void SetInputPoint2(PointF* pInputValue, unsigned int nValueNum) = 0;

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

            // CH: 距离判断 | EN: Distance Check
            __declspec(property(put = SetDistLimitEnable, get = GetDistLimitEnable)) bool DistLimitEnable;

            virtual bool GetDistLimitEnable() = 0;

            virtual void SetDistLimitEnable(bool value) = 0;

            // CH: 距离范围 | EN: Distance Range
            __declspec(property(put = SetDistLimitLow, get = GetDistLimitLow)) double DistLimitLow;

            virtual double GetDistLimitLow() = 0;

            virtual void SetDistLimitLow(double value) = 0;

            // CH: 距离范围 | EN: Distance Range
            __declspec(property(put = SetDistLimitHigh, get = GetDistLimitHigh)) double DistLimitHigh;

            virtual double GetDistLimitHigh() = 0;

            virtual void SetDistLimitHigh(double value) = 0;

            // CH: 中点X判断 | EN: Midpoint X Check
            __declspec(property(put = SetMidXLimitEnable, get = GetMidXLimitEnable)) bool MidXLimitEnable;

            virtual bool GetMidXLimitEnable() = 0;

            virtual void SetMidXLimitEnable(bool value) = 0;

            // CH: 中点X范围 | EN: Midpoint X Range
            __declspec(property(put = SetMidXLimitLow, get = GetMidXLimitLow)) double MidXLimitLow;

            virtual double GetMidXLimitLow() = 0;

            virtual void SetMidXLimitLow(double value) = 0;

            // CH: 中点X范围 | EN: Midpoint X Range
            __declspec(property(put = SetMidXLimitHigh, get = GetMidXLimitHigh)) double MidXLimitHigh;

            virtual double GetMidXLimitHigh() = 0;

            virtual void SetMidXLimitHigh(double value) = 0;

            // CH: 中点Y判断 | EN: Midpoint Y Check
            __declspec(property(put = SetMidYLimitEnable, get = GetMidYLimitEnable)) bool MidYLimitEnable;

            virtual bool GetMidYLimitEnable() = 0;

            virtual void SetMidYLimitEnable(bool value) = 0;

            // CH: 中点Y范围 | EN: Midpoint Y Range
            __declspec(property(put = SetMidYLimitLow, get = GetMidYLimitLow)) double MidYLimitLow;

            virtual double GetMidYLimitLow() = 0;

            virtual void SetMidYLimitLow(double value) = 0;

            // CH: 中点Y范围 | EN: Midpoint Y Range
            __declspec(property(put = SetMidYLimitHigh, get = GetMidYLimitHigh)) double MidYLimitHigh;

            virtual double GetMidYLimitHigh() = 0;

            virtual void SetMidYLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the P2PMeasureResults.  */
        class P2PMeasureResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit P2PMeasureResults() {}
            virtual ~P2PMeasureResults() {}

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
             * 点点测量的中点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetMidPoint() = 0;
            /**
             * @par 说明
             * 点点连线与水平X轴之间的角度
             * @par 权限
             * 只读
             */
            virtual float GetAngle() = 0;
            /**
             * @par 说明
             * 点点之间的距离
             * @par 权限
             * 只读
             */
            virtual float GetDist() = 0;
            /**
             * @par 说明
             * 测量点
             * @par 权限
             * nIndex [IN] 范围(0,1)
             * 可读
             */
            virtual PointF GetMeasurePoint(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the P2PMeasure tool.  */
        class IMVSP2PMeasureModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSP2PMeasureModuTool() {}
            virtual ~IMVSP2PMeasureModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual P2PMeasureParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual P2PMeasureResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSP2PMeasureModuTool(IMVSP2PMeasureModuTool&);
            IMVSP2PMeasureModuTool& operator=(IMVSP2PMeasureModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for P2PMeasure.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSP2PMeasureModu::IMVSP2PMeasureModuTool * __stdcall GetP2PMeasureToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_P2PMEASURE_H_
