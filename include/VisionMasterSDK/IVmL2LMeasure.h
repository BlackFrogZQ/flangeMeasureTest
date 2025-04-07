/***************************************************************************************************
 * File：IVmL2LMeasure.h
 * Note：CH: 线线测量模块接口声明 | En: Interface for the L2LMeasure tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_L2LMEASURE_H_
#define _IVM_L2LMEASURE_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSL2LMeasureModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 边缘类型1 | EN: Edge Type1
        typedef enum _FindMode1Enum
        {
            // CH: 最强 | EN: Strongest Edge
            FindMode1_Best = 0x1,

            // CH: 第一条 | EN: First Edge
            FindMode1_First = 0x2,

            // CH: 最后一条 | EN: Last Edge
            FindMode1_Last = 0x3,

            // CH: 接近中线 | EN: Close To Mid
            FindMode1_Mid = 0x4,

        }FindMode1Enum;

        // CH: 边缘极性1 | EN: Edge Polarity1
        typedef enum _EdgePolarity1Enum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgePolarity1_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgePolarity1_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            EdgePolarity1_Both = 0x3,

        }EdgePolarity1Enum;

        // CH: 初始拟合1 | EN: Initial Fit1
        typedef enum _InitType1Enum
        {
            // CH: 全局 | EN: Global
            InitType1_ALS = 0x1,

            // CH: 局部 | EN: Partial
            InitType1_LLS = 0x2,

        }InitType1Enum;

        // CH: 拟合方式1 | EN: Fit Mode1
        typedef enum _FitFun1Enum
        {
            // CH: 最小二乘 | EN: Least Squares
            FitFun1_LS = 0x1,

            // CH: huber | EN: huber
            FitFun1_Huber = 0x2,

            // CH: tukey | EN: tukey
            FitFun1_Tukey = 0x3,

        }FitFun1Enum;

        // CH: 边缘类型2 | EN: Edge Type2
        typedef enum _FindMode2Enum
        {
            // CH: 最强 | EN: Strongest Edge
            FindMode2_Best = 0x1,

            // CH: 第一条 | EN: First Edge
            FindMode2_First = 0x2,

            // CH: 最后一条 | EN: Last Edge
            FindMode2_Last = 0x3,

            // CH: 接近中线 | EN: Close To Mid
            FindMode2_Mid = 0x4,

        }FindMode2Enum;

        // CH: 边缘极性2 | EN: Edge Polarity2
        typedef enum _EdgePolarity2Enum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgePolarity2_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgePolarity2_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            EdgePolarity2_Both = 0x3,

        }EdgePolarity2Enum;

        // CH: 初始拟合2 | EN: Initial Fit2
        typedef enum _InitType2Enum
        {
            // CH: 全局 | EN: Global
            InitType2_ALS = 0x1,

            // CH: 局部 | EN: Partial
            InitType2_LLS = 0x2,

        }InitType2Enum;

        // CH: 拟合方式2 | EN: Fit Mode2
        typedef enum _FitFun2Enum
        {
            // CH: 最小二乘 | EN: Least Squares
            FitFun2_LS = 0x1,

            // CH: huber | EN: huber
            FitFun2_Huber = 0x2,

            // CH: tukey | EN: tukey
            FitFun2_Tukey = 0x3,

        }FitFun2Enum;

        // CH: 输出角度范围 | EN: RunParam_OutputAngleRange
        typedef enum _OutputAngleRangeEnum
        {
            // CH: -90°-90° | EN: RunParam_RangeSegment
            OutputAngleRange_RangeSegment = 0x0,

            // CH: -180°-180° | EN: RunParam_RangeLinear
            OutputAngleRange_RangeLinear = 0x1,

        }OutputAngleRangeEnum;

        /*  Note: Interface Classes of the parameter of the L2LMeasureParams.  */
        class L2LMeasureParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit L2LMeasureParams() {}
            virtual ~L2LMeasureParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入直线1(仅当次执行起效) | EN: Input Line 1(Only valid for this execution)
            virtual void SetInputLine1(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入直线2(仅当次执行起效) | EN: Input Line 2(Only valid for this execution)
            virtual void SetInputLine2(Line* pInputValue, unsigned int nValueNum) = 0;
            // CH: 边缘类型1 | EN: Edge Type1
            __declspec(property(put = SetFindMode1, get = GetFindMode1)) FindMode1Enum FindMode1;

            virtual FindMode1Enum GetFindMode1() = 0;

            virtual void SetFindMode1(FindMode1Enum value) = 0;

            // CH: 边缘极性1 | EN: Edge Polarity1
            __declspec(property(put = SetEdgePolarity1, get = GetEdgePolarity1)) EdgePolarity1Enum EdgePolarity1;

            virtual EdgePolarity1Enum GetEdgePolarity1() = 0;

            virtual void SetEdgePolarity1(EdgePolarity1Enum value) = 0;

            // CH: 边缘阈值1 | EN: Contrast Threshold1
            __declspec(property(put = SetEdgeThreshold1, get = GetEdgeThreshold1)) int EdgeThreshold1;

            virtual int GetEdgeThreshold1() = 0;

            virtual void SetEdgeThreshold1(int value) = 0;

            // CH: 滤波尺寸1 | EN: Filter Size1
            __declspec(property(put = SetKernelSize1, get = GetKernelSize1)) int KernelSize1;

            virtual int GetKernelSize1() = 0;

            virtual void SetKernelSize1(int value) = 0;

            // CH: 剔除点数1 | EN: Reject Number1
            __declspec(property(put = SetRejectNum1, get = GetRejectNum1)) int RejectNum1;

            virtual int GetRejectNum1() = 0;

            virtual void SetRejectNum1(int value) = 0;

            // CH: 剔除距离1 | EN: Distance to remove1
            __declspec(property(put = SetRejectDist1, get = GetRejectDist1)) int RejectDist1;

            virtual int GetRejectDist1() = 0;

            virtual void SetRejectDist1(int value) = 0;

            // CH: 初始拟合1 | EN: Initial Fit1
            __declspec(property(put = SetInitType1, get = GetInitType1)) InitType1Enum InitType1;

            virtual InitType1Enum GetInitType1() = 0;

            virtual void SetInitType1(InitType1Enum value) = 0;

            // CH: 拟合方式1 | EN: Fit Mode1
            __declspec(property(put = SetFitFun1, get = GetFitFun1)) FitFun1Enum FitFun1;

            virtual FitFun1Enum GetFitFun1() = 0;

            virtual void SetFitFun1(FitFun1Enum value) = 0;

            // CH: 边缘类型2 | EN: Edge Type2
            __declspec(property(put = SetFindMode2, get = GetFindMode2)) FindMode2Enum FindMode2;

            virtual FindMode2Enum GetFindMode2() = 0;

            virtual void SetFindMode2(FindMode2Enum value) = 0;

            // CH: 边缘极性2 | EN: Edge Polarity2
            __declspec(property(put = SetEdgePolarity2, get = GetEdgePolarity2)) EdgePolarity2Enum EdgePolarity2;

            virtual EdgePolarity2Enum GetEdgePolarity2() = 0;

            virtual void SetEdgePolarity2(EdgePolarity2Enum value) = 0;

            // CH: 边缘阈值2 | EN: Contrast Threshold2
            __declspec(property(put = SetEdgeThreshold2, get = GetEdgeThreshold2)) int EdgeThreshold2;

            virtual int GetEdgeThreshold2() = 0;

            virtual void SetEdgeThreshold2(int value) = 0;

            // CH: 滤波尺寸2 | EN: Filter Size2
            __declspec(property(put = SetKernelSize2, get = GetKernelSize2)) int KernelSize2;

            virtual int GetKernelSize2() = 0;

            virtual void SetKernelSize2(int value) = 0;

            // CH: 剔除点数2 | EN: Reject Number2
            __declspec(property(put = SetRejectNum2, get = GetRejectNum2)) int RejectNum2;

            virtual int GetRejectNum2() = 0;

            virtual void SetRejectNum2(int value) = 0;

            // CH: 剔除距离2 | EN: Distance to remove2
            __declspec(property(put = SetRejectDist2, get = GetRejectDist2)) int RejectDist2;

            virtual int GetRejectDist2() = 0;

            virtual void SetRejectDist2(int value) = 0;

            // CH: 初始拟合2 | EN: Initial Fit2
            __declspec(property(put = SetInitType2, get = GetInitType2)) InitType2Enum InitType2;

            virtual InitType2Enum GetInitType2() = 0;

            virtual void SetInitType2(InitType2Enum value) = 0;

            // CH: 拟合方式2 | EN: Fit Mode2
            __declspec(property(put = SetFitFun2, get = GetFitFun2)) FitFun2Enum FitFun2;

            virtual FitFun2Enum GetFitFun2() = 0;

            virtual void SetFitFun2(FitFun2Enum value) = 0;

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

            // CH: 交点X判断 | EN: Intersection X Check
            __declspec(property(put = SetInterXLimitEnable, get = GetInterXLimitEnable)) bool InterXLimitEnable;

            virtual bool GetInterXLimitEnable() = 0;

            virtual void SetInterXLimitEnable(bool value) = 0;

            // CH: 交点X范围 | EN: Intersection X Range
            __declspec(property(put = SetInterXLimitLow, get = GetInterXLimitLow)) double InterXLimitLow;

            virtual double GetInterXLimitLow() = 0;

            virtual void SetInterXLimitLow(double value) = 0;

            // CH: 交点X范围 | EN: Intersection X Range
            __declspec(property(put = SetInterXLimitHigh, get = GetInterXLimitHigh)) double InterXLimitHigh;

            virtual double GetInterXLimitHigh() = 0;

            virtual void SetInterXLimitHigh(double value) = 0;

            // CH: 交点Y判断 | EN: Intersection Y Check
            __declspec(property(put = SetInterYLimitEnable, get = GetInterYLimitEnable)) bool InterYLimitEnable;

            virtual bool GetInterYLimitEnable() = 0;

            virtual void SetInterYLimitEnable(bool value) = 0;

            // CH: 交点Y范围 | EN: Intersection Y Range
            __declspec(property(put = SetInterYLimitLow, get = GetInterYLimitLow)) double InterYLimitLow;

            virtual double GetInterYLimitLow() = 0;

            virtual void SetInterYLimitLow(double value) = 0;

            // CH: 交点Y范围 | EN: Intersection Y Range
            __declspec(property(put = SetInterYLimitHigh, get = GetInterYLimitHigh)) double InterYLimitHigh;

            virtual double GetInterYLimitHigh() = 0;

            virtual void SetInterYLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the L2LMeasureResults.  */
        class L2LMeasureResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit L2LMeasureResults() {}
            virtual ~L2LMeasureResults() {}

        public:
             /**
             * @par 说明
             * 卡尺检测区1
             * nIndex [IN] 范围(0,5)
             * @par 权限
             * 只读
             */
             virtual RectBox GetDetectCaliperBox1(int nIndex) = 0;
             /**
             * @par 说明
             * 卡尺检测区2
             * nIndex [IN] 范围(0,5)
             * @par 权限
             * 只读
             */
             virtual RectBox GetDetectCaliperBox2(int nIndex) = 0;
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
            /**
             * @par 说明
             * 交点
             * @par 权限
             * 可读
             */
            virtual MVD_POINT_F GetInterPoint() = 0;
            /**
             * @par 说明
             * 夹角
             * @par 权限
             * 可读
             */
            virtual float GetAngle() = 0;
            /**
             * @par 说明
             * 绝对距离
             * @par 权限
             * 可读
             */
            virtual float GetVerticalAbsDist() = 0;
            /**
             * @par 说明
             * 测量直线
             * @par 权限
             * nIndex [IN] 范围(0,1)
             * 可读
             */
            virtual Line GetMeasureLine(int nIndex) = 0;
            /**
             * @par 说明
             * 角度标识点
             * @par 权限
             * nIndex [IN] 范围(0,4)
             * 可读
             */
            virtual PointF GetShowAnglePoint(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the L2LMeasure tool.  */
        class IMVSL2LMeasureModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSL2LMeasureModuTool() {}
            virtual ~IMVSL2LMeasureModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual L2LMeasureParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual L2LMeasureResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSL2LMeasureModuTool(IMVSL2LMeasureModuTool&);
            IMVSL2LMeasureModuTool& operator=(IMVSL2LMeasureModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for L2LMeasure.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSL2LMeasureModu::IMVSL2LMeasureModuTool * __stdcall GetL2LMeasureToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_L2LMEASURE_H_
