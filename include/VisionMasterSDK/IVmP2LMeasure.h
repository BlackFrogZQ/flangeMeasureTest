/***************************************************************************************************
 * File：IVmP2LMeasure.h
 * Note：CH: 点线测量模块接口声明 | En: Interface for the P2LMeasure tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_P2LMEASURE_H_
#define _IVM_P2LMEASURE_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSP2LMeasureModu
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

        /*  Note: Interface Classes of the parameter of the P2LMeasureParams.  */
        class P2LMeasureParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit P2LMeasureParams() {}
            virtual ~P2LMeasureParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入点(仅当次执行起效) | EN: Input Point(Only valid for this execution)
            virtual void SetInputPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入直线(仅当次执行起效) | EN: Input Line(Only valid for this execution)
            virtual void SetInputLine(Line* pInputValue, unsigned int nValueNum) = 0;

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

            // CH: 垂直距离判断 | EN: Vertical Distance Check
            __declspec(property(put = SetDistPerpendLimitEnable, get = GetDistPerpendLimitEnable)) bool DistPerpendLimitEnable;

            virtual bool GetDistPerpendLimitEnable() = 0;

            virtual void SetDistPerpendLimitEnable(bool value) = 0;

            // CH: 垂直距离范围 | EN: Vertical Distance Range
            __declspec(property(put = SetDistPerpendLimitLow, get = GetDistPerpendLimitLow)) double DistPerpendLimitLow;

            virtual double GetDistPerpendLimitLow() = 0;

            virtual void SetDistPerpendLimitLow(double value) = 0;

            // CH: 垂直距离范围 | EN: Vertical Distance Range
            __declspec(property(put = SetDistPerpendLimitHigh, get = GetDistPerpendLimitHigh)) double DistPerpendLimitHigh;

            virtual double GetDistPerpendLimitHigh() = 0;

            virtual void SetDistPerpendLimitHigh(double value) = 0;

            // CH: 垂点X判断 | EN: Foot Point X Check
            __declspec(property(put = SetProjXLimitEnable, get = GetProjXLimitEnable)) bool ProjXLimitEnable;

            virtual bool GetProjXLimitEnable() = 0;

            virtual void SetProjXLimitEnable(bool value) = 0;

            // CH: 垂点X范围 | EN: Foot Point X Range
            __declspec(property(put = SetProjXLimitLow, get = GetProjXLimitLow)) double ProjXLimitLow;

            virtual double GetProjXLimitLow() = 0;

            virtual void SetProjXLimitLow(double value) = 0;

            // CH: 垂点X范围 | EN: Foot Point X Range
            __declspec(property(put = SetProjXLimitHigh, get = GetProjXLimitHigh)) double ProjXLimitHigh;

            virtual double GetProjXLimitHigh() = 0;

            virtual void SetProjXLimitHigh(double value) = 0;

            // CH: 垂点Y判断 | EN: Foot Point Y Check
            __declspec(property(put = SetProjYLimitEnable, get = GetProjYLimitEnable)) bool ProjYLimitEnable;

            virtual bool GetProjYLimitEnable() = 0;

            virtual void SetProjYLimitEnable(bool value) = 0;

            // CH: 垂点Y范围 | EN: Foot Point Y Range
            __declspec(property(put = SetProjYLimitLow, get = GetProjYLimitLow)) double ProjYLimitLow;

            virtual double GetProjYLimitLow() = 0;

            virtual void SetProjYLimitLow(double value) = 0;

            // CH: 垂点Y范围 | EN: Foot Point Y Range
            __declspec(property(put = SetProjYLimitHigh, get = GetProjYLimitHigh)) double ProjYLimitHigh;

            virtual double GetProjYLimitHigh() = 0;

            virtual void SetProjYLimitHigh(double value) = 0;

            // CH: 最近距离判断 | EN: Closest Distance Check
            __declspec(property(put = SetDistMinLimitEnable, get = GetDistMinLimitEnable)) bool DistMinLimitEnable;

            virtual bool GetDistMinLimitEnable() = 0;

            virtual void SetDistMinLimitEnable(bool value) = 0;

            // CH: 最近距离范围 | EN: Closest Distance Range
            __declspec(property(put = SetDistMinLimitLow, get = GetDistMinLimitLow)) double DistMinLimitLow;

            virtual double GetDistMinLimitLow() = 0;

            virtual void SetDistMinLimitLow(double value) = 0;

            // CH: 最近距离范围 | EN: Closest Distance Range
            __declspec(property(put = SetDistMinLimitHigh, get = GetDistMinLimitHigh)) double DistMinLimitHigh;

            virtual double GetDistMinLimitHigh() = 0;

            virtual void SetDistMinLimitHigh(double value) = 0;

            // CH: 最远距离判断 | EN: Furthest Distance Check
            __declspec(property(put = SetDistMaxLimitEnable, get = GetDistMaxLimitEnable)) bool DistMaxLimitEnable;

            virtual bool GetDistMaxLimitEnable() = 0;

            virtual void SetDistMaxLimitEnable(bool value) = 0;

            // CH: 最远距离范围 | EN: Furthest Distance Range
            __declspec(property(put = SetDistMaxLimitLow, get = GetDistMaxLimitLow)) double DistMaxLimitLow;

            virtual double GetDistMaxLimitLow() = 0;

            virtual void SetDistMaxLimitLow(double value) = 0;

            // CH: 最远距离范围 | EN: Furthest Distance Range
            __declspec(property(put = SetDistMaxLimitHigh, get = GetDistMaxLimitHigh)) double DistMaxLimitHigh;

            virtual double GetDistMaxLimitHigh() = 0;

            virtual void SetDistMaxLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the P2LMeasureResults.  */
        class P2LMeasureResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit P2LMeasureResults() {}
            virtual ~P2LMeasureResults() {}

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
             * 垂足点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetProjectPoint() = 0;
            /**
             * @par 说明
             * 角度
             * @par 权限
             * 只读
             */
            virtual float GetAngle() = 0;
            /**
             * @par 说明
             * 垂足距离
             * @par 权限
             * 只读
             */
            virtual float GetVerticalDist() = 0;
            /**
             * @par 说明
             * 最近距离
             * @par 权限
             * 只读
             */
            virtual float GetCloestDist() = 0;
            /**
             * @par 说明
             * 最远距离
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
             * 测量直线
             * @par 权限
             * 可读
             */
            virtual Line GetMeasureLine() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the P2LMeasure tool.  */
        class IMVSP2LMeasureModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSP2LMeasureModuTool() {}
            virtual ~IMVSP2LMeasureModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual P2LMeasureParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual P2LMeasureResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSP2LMeasureModuTool(IMVSP2LMeasureModuTool&);
            IMVSP2LMeasureModuTool& operator=(IMVSP2LMeasureModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for P2LMeasure.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSP2LMeasureModu::IMVSP2LMeasureModuTool * __stdcall GetP2LMeasureToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_P2LMEASURE_H_
