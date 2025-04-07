/***************************************************************************************************
 * File：IVmMarkInspVA.h
 * Note：CH: 字符缺陷检测模块接口声明 | En: Interface for the MarkInspVA tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MARKINSPVA_H_
#define _IVM_MARKINSPVA_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMarkInspModuVA
    {
        /*************************** Params Class Start ***************************/
        // CH: 缺陷类型 | EN: DefectType
        typedef enum _FlawTypeEnum
        {
            // CH: 亮缺陷 | EN: Bright Defect
            FlawType_BrightDefect = 0x01,

            // CH: 暗缺陷 | EN: Dark Defect
            FlawType_DarkDefect = 0x2,

            // CH: 亮暗缺陷 | EN: Bright and Dark Defect
            FlawType_BothDefect = 0x3,

        }FlawTypeEnum;

        // CH: 阈值类型 | EN: Threshold Type
        typedef enum _ExactMatchMatchThresholdFlagEnum
        {
            // CH: 自动阈值 | EN: Auto Threshold
            ExactMatchMatchThresholdFlag_AutoThreshold = 0x0,

            // CH: 模板阈值 | EN: Model Threshold
            ExactMatchMatchThresholdFlag_ModelThreshold = 0x1,

            // CH: 手动阈值 | EN: Manual Threshold
            ExactMatchMatchThresholdFlag_ManualThreshold = 0x2,

        }ExactMatchMatchThresholdFlagEnum;

        // CH: 匹配极性 | EN: Match Polarity
        typedef enum _RoughMatchPolarityEnum
        {
            // CH: 不考虑极性 | EN: Ignored
            RoughMatchPolarity_No = 0x0,

            // CH: 考虑极性 | EN: Considered
            RoughMatchPolarity_Yes = 0x1,

        }RoughMatchPolarityEnum;

        // CH: 阈值类型 | EN: Threshold Type
        typedef enum _RoughMatchMatchThresholdFlagEnum
        {
            // CH: 自动阈值 | EN: Auto Threshold
            RoughMatchMatchThresholdFlag_AutoThreshold = 0x0,

            // CH: 模板阈值 | EN: Model Threshold
            RoughMatchMatchThresholdFlag_ModelThreshold = 0x1,

            // CH: 手动阈值 | EN: Manual Threshold
            RoughMatchMatchThresholdFlag_ManualThreshold = 0x2,

        }RoughMatchMatchThresholdFlagEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class MarkInspVARoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the MarkInspVAParams.  */
        class MarkInspVAParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MarkInspVAParams() {}
            virtual ~MarkInspVAParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 运行点(仅当次执行起效) | EN: Unfixtured Point(Only valid for this execution)
            virtual void SetInheritRunPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 运行角度(仅当次执行起效) | EN: Unfixtured Angle(Only valid for this execution)
            virtual void SetInheritRunAngle(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 运行尺度X(仅当次执行起效) | EN: FixtureRunScaleX(Only valid for this execution)
            virtual void SetInheritRunScaleX(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 运行尺度Y(仅当次执行起效) | EN: FixtureRunScaleY(Only valid for this execution)
            virtual void SetInheritRunScaleY(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual MarkInspVARoiManager* GetModuRoiManager() = 0;

            // CH: 缺陷类型 | EN: DefectType
            __declspec(property(put = SetFlawType, get = GetFlawType)) FlawTypeEnum FlawType;

            virtual FlawTypeEnum GetFlawType() = 0;

            virtual void SetFlawType(FlawTypeEnum value) = 0;

            // CH: 亮缺陷阈值 | EN: Bright Threshold
            __declspec(property(put = SetBrightThreshold, get = GetBrightThreshold)) int BrightThreshold;

            virtual int GetBrightThreshold() = 0;

            virtual void SetBrightThreshold(int value) = 0;

            // CH: 暗缺陷阈值 | EN: Dark Threshold
            __declspec(property(put = SetDarkThreshold, get = GetDarkThreshold)) int DarkThreshold;

            virtual int GetDarkThreshold() = 0;

            virtual void SetDarkThreshold(int value) = 0;

            // CH: 亮缺陷尺度 | EN: Bright Scale
            __declspec(property(put = SetBrightVarScale, get = GetBrightVarScale)) double BrightVarScale;

            virtual double GetBrightVarScale() = 0;

            virtual void SetBrightVarScale(double value) = 0;

            // CH: 暗缺陷尺度 | EN: Dark Scale
            __declspec(property(put = SetDarkVarScale, get = GetDarkVarScale)) double DarkVarScale;

            virtual double GetDarkVarScale() = 0;

            virtual void SetDarkVarScale(double value) = 0;

            // CH: 边缘容忍度 | EN: Edge Tolerance
            __declspec(property(put = SetEdgeTolerance, get = GetEdgeTolerance)) int EdgeTolerance;

            virtual int GetEdgeTolerance() = 0;

            virtual void SetEdgeTolerance(int value) = 0;

            // CH: 面积大小阈值 | EN: Area Threshold
            __declspec(property(put = SetBlobMinArea, get = GetBlobMinArea)) int BlobMinArea;

            virtual int GetBlobMinArea() = 0;

            virtual void SetBlobMinArea(int value) = 0;

            // CH: 最小匹配分数 | EN: Min Match Score
            __declspec(property(put = SetExactMatchMinScore, get = GetExactMatchMinScore)) double ExactMatchMinScore;

            virtual double GetExactMatchMinScore() = 0;

            virtual void SetExactMatchMinScore(double value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetExactMatchAngleStart, get = GetExactMatchAngleStart)) int ExactMatchAngleStart;

            virtual int GetExactMatchAngleStart() = 0;

            virtual void SetExactMatchAngleStart(int value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetExactMatchAngleEnd, get = GetExactMatchAngleEnd)) int ExactMatchAngleEnd;

            virtual int GetExactMatchAngleEnd() = 0;

            virtual void SetExactMatchAngleEnd(int value) = 0;

            // CH: X尺度范围 | EN: X Scale Range
            __declspec(property(put = SetExactMatchScaleXStart, get = GetExactMatchScaleXStart)) double ExactMatchScaleXStart;

            virtual double GetExactMatchScaleXStart() = 0;

            virtual void SetExactMatchScaleXStart(double value) = 0;

            // CH: X尺度范围 | EN: X Scale Range
            __declspec(property(put = SetExactMatchScaleXEnd, get = GetExactMatchScaleXEnd)) double ExactMatchScaleXEnd;

            virtual double GetExactMatchScaleXEnd() = 0;

            virtual void SetExactMatchScaleXEnd(double value) = 0;

            // CH: Y尺度范围 | EN: Y Scale Range
            __declspec(property(put = SetExactMatchScaleYStart, get = GetExactMatchScaleYStart)) double ExactMatchScaleYStart;

            virtual double GetExactMatchScaleYStart() = 0;

            virtual void SetExactMatchScaleYStart(double value) = 0;

            // CH: Y尺度范围 | EN: Y Scale Range
            __declspec(property(put = SetExactMatchScaleYEnd, get = GetExactMatchScaleYEnd)) double ExactMatchScaleYEnd;

            virtual double GetExactMatchScaleYEnd() = 0;

            virtual void SetExactMatchScaleYEnd(double value) = 0;

            // CH: 阈值类型 | EN: Threshold Type
            __declspec(property(put = SetExactMatchMatchThresholdFlag, get = GetExactMatchMatchThresholdFlag)) ExactMatchMatchThresholdFlagEnum ExactMatchMatchThresholdFlag;

            virtual ExactMatchMatchThresholdFlagEnum GetExactMatchMatchThresholdFlag() = 0;

            virtual void SetExactMatchMatchThresholdFlag(ExactMatchMatchThresholdFlagEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetExactMatchMatchThresholdHigh, get = GetExactMatchMatchThresholdHigh)) int ExactMatchMatchThresholdHigh;

            virtual int GetExactMatchMatchThresholdHigh() = 0;

            virtual void SetExactMatchMatchThresholdHigh(int value) = 0;

            // CH: 位置纠正 | EN: Correct Flag
            __declspec(property(put = SetExactMatchCorrectFlag, get = GetExactMatchCorrectFlag)) bool ExactMatchCorrectFlag;

            virtual bool GetExactMatchCorrectFlag() = 0;

            virtual void SetExactMatchCorrectFlag(bool value) = 0;

            // CH: 宽度方向容忍 | EN: Width Tolerance
            __declspec(property(put = SetExactMatchToleranceX, get = GetExactMatchToleranceX)) double ExactMatchToleranceX;

            virtual double GetExactMatchToleranceX() = 0;

            virtual void SetExactMatchToleranceX(double value) = 0;

            // CH: 高度方向容忍 | EN: Height Tolerance
            __declspec(property(put = SetExactMatchToleranceY, get = GetExactMatchToleranceY)) double ExactMatchToleranceY;

            virtual double GetExactMatchToleranceY() = 0;

            virtual void SetExactMatchToleranceY(double value) = 0;

            // CH: 最小匹配分数 | EN: Min Match Score
            __declspec(property(put = SetRoughMatchMinScore, get = GetRoughMatchMinScore)) double RoughMatchMinScore;

            virtual double GetRoughMatchMinScore() = 0;

            virtual void SetRoughMatchMinScore(double value) = 0;

            // CH: 匹配极性 | EN: Match Polarity
            __declspec(property(put = SetRoughMatchPolarity, get = GetRoughMatchPolarity)) RoughMatchPolarityEnum RoughMatchPolarity;

            virtual RoughMatchPolarityEnum GetRoughMatchPolarity() = 0;

            virtual void SetRoughMatchPolarity(RoughMatchPolarityEnum value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetRoughMatchAngleStart, get = GetRoughMatchAngleStart)) int RoughMatchAngleStart;

            virtual int GetRoughMatchAngleStart() = 0;

            virtual void SetRoughMatchAngleStart(int value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetRoughMatchAngleEnd, get = GetRoughMatchAngleEnd)) int RoughMatchAngleEnd;

            virtual int GetRoughMatchAngleEnd() = 0;

            virtual void SetRoughMatchAngleEnd(int value) = 0;

            // CH: X尺度范围 | EN: X Scale Range
            __declspec(property(put = SetRoughMatchScaleXStart, get = GetRoughMatchScaleXStart)) double RoughMatchScaleXStart;

            virtual double GetRoughMatchScaleXStart() = 0;

            virtual void SetRoughMatchScaleXStart(double value) = 0;

            // CH: X尺度范围 | EN: X Scale Range
            __declspec(property(put = SetRoughMatchScaleXEnd, get = GetRoughMatchScaleXEnd)) double RoughMatchScaleXEnd;

            virtual double GetRoughMatchScaleXEnd() = 0;

            virtual void SetRoughMatchScaleXEnd(double value) = 0;

            // CH: Y尺度范围 | EN: Y Scale Range
            __declspec(property(put = SetRoughMatchScaleYStart, get = GetRoughMatchScaleYStart)) double RoughMatchScaleYStart;

            virtual double GetRoughMatchScaleYStart() = 0;

            virtual void SetRoughMatchScaleYStart(double value) = 0;

            // CH: Y尺度范围 | EN: Y Scale Range
            __declspec(property(put = SetRoughMatchScaleYEnd, get = GetRoughMatchScaleYEnd)) double RoughMatchScaleYEnd;

            virtual double GetRoughMatchScaleYEnd() = 0;

            virtual void SetRoughMatchScaleYEnd(double value) = 0;

            // CH: 阈值类型 | EN: Threshold Type
            __declspec(property(put = SetRoughMatchMatchThresholdFlag, get = GetRoughMatchMatchThresholdFlag)) RoughMatchMatchThresholdFlagEnum RoughMatchMatchThresholdFlag;

            virtual RoughMatchMatchThresholdFlagEnum GetRoughMatchMatchThresholdFlag() = 0;

            virtual void SetRoughMatchMatchThresholdFlag(RoughMatchMatchThresholdFlagEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetRoughMatchMatchThresholdHigh, get = GetRoughMatchMatchThresholdHigh)) int RoughMatchMatchThresholdHigh;

            virtual int GetRoughMatchMatchThresholdHigh() = 0;

            virtual void SetRoughMatchMatchThresholdHigh(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        // 字符缺陷检测方法
        typedef _MVD_MKINSP_METHOD_TYPE__ MVD_MKINSP_METHOD_TYPE;
        
        /*  Note: Interface Classes of the result of the MarkInspVAResults.  */
        class MarkInspVAResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MarkInspVAResults() {}
            virtual ~MarkInspVAResults() {}

        public:
             /**
             * @par 说明
             * 输出掩膜
             * @par 权限
             * 只读
             */
             virtual ImageBaseData GetOutputMask() = 0;

             /**
             * @par 说明
             * 屏蔽区多边形点集
             * @par 权限
             * 只读
             */
             virtual PointF GetBlindPolygonPoints(int nIndex) = 0;

             /**
             * @par 说明
             * 屏蔽区多边形点数
             * @par 权限
             * 只读
             */
             virtual int GetBlindPolygonPointNum(int nIndex) = 0;

             /**
              * @par 说明
              * 模块状态
              * @par 权限
              * 只读
              */
             virtual int GetModuStatus() = 0;
             /**
              * @par 说明
              * 检测区域
              * @par 权限
              * 只读
              */
             virtual RectBox GetROI() = 0;
             /**
             * @par 说明
             * 匹配框
             * @par 权限
             * 只读
             */
             virtual RectBox GetMatchRect() = 0;
             /**
             * @brief 获取缺陷图像
             * 缺陷图像
             * @par 权限
             * 只读
             */
             virtual ImageBaseData GetMarkFlawImage() = 0;
             /**
              * @par 说明
              * 匹配状态
              * @par 权限
              * 只读
              */
             virtual int GetMatchStatus() = 0;
             /**
              * @par 说明
              * 字符状态
              * @param nIndex [in] 字符状态索引
              * @par 权限
              * 只读
              */
             virtual int GetMarkStatus(int nIndex) = 0;
            /**
             * @brief 获取字符缺陷框个数
             * @param 无
             * @return 返回缺陷框个数
             * @par 注解
             * 无
             */
            virtual int GetNumOfFlawBox() = 0;
            /**
             * @brief 获取缺陷框位置
             * @param nIndex [in] 缺陷框索引
             * @return 返回缺陷框位置
             * @par 注解
             * nIndex从0开始计数。
             */
            virtual RectBox GetFlawBox(int nIndex) = 0;
            /**
             * @brief 获取字符定位框个数
             * @param 无
             * @return 返回字符定位框个数
             * @par 注解
             * 无
             */
            virtual int GetNumOfLocateBox() = 0;
            /**
             * @brief 获取字符定位框位置
             * @param nIndex [in] 字符定位框索引
             * @return 返回字符定位框位置
             * @par 注解
             * nIndex从0开始计数。
             */
            virtual RectBox GetLocateBox(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the MarkInspVA tool.  */
        class IMVSMarkInspModuVATool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMarkInspModuVATool() {}
            virtual ~IMVSMarkInspModuVATool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MarkInspVAParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MarkInspVAResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

            /**
            * @brief 导入模型
            * @param 模型路径
            * @return 无，出错时抛出异常
            * @par 注解
            * 导入模型
            */
            virtual void ImportModelData(IN const char * const strPath) = 0;

        private:
            IMVSMarkInspModuVATool(IMVSMarkInspModuVATool&);
            IMVSMarkInspModuVATool& operator=(IMVSMarkInspModuVATool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MarkInspVA.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMarkInspModuVA::IMVSMarkInspModuVATool * __stdcall GetMarkInspVAToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MARKINSPVA_H_
