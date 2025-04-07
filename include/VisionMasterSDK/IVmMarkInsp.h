/***************************************************************************************************
 * File：IVmMarkInsp.h
 * Note：CH: 字符缺陷检测模块接口声明 | En: Interface for the MarkInsp tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MARKINSP_H_
#define _IVM_MARKINSP_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMarkInspModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 归一化类型 | EN: Normalization Type
        typedef enum _NormlizeTypeEnum
        {
            // CH: 不处理 | EN: Not Deal
            NormlizeType_Processless = 0x0,

            // CH: 直方图均衡化 | EN: Histogram Equalization
            NormlizeType_HistEqualize = 0x1,

            // CH: 直方图归一化 | EN: Histogram Normalization
            NormlizeType_HistNormalize = 0x2,

            // CH: 均值标准差归一化 | EN: Standard Deviation Normalization
            NormlizeType_StdDevNormalize = 0x3,

        }NormlizeTypeEnum;

        // CH: 统计训练方法 | EN: Statistical Training Type
        typedef enum _MarkModelTypeEnum
        {
            // CH: 均值标准差法 | EN: Mean Standard Deviation Type
            MarkModelType_MeanStdDev = 0x1,

            // CH: 相关法 | EN: Correlation Type
            MarkModelType_Correlation = 0x2,

        }MarkModelTypeEnum;

        // CH: 缺陷类型 | EN: DefectType
        typedef enum _FlawTypeEnum
        {
            // CH: 亮缺陷 | EN: Bright Defect
            FlawType_NonNormlize = 0x01,

            // CH: 暗缺陷 | EN: Dark Defect
            FlawType_HistEqual = 0x2,

            // CH: 亮暗缺陷 | EN: Bright and Dark Defect
            FlawType_HistMatch = 0x3,

        }FlawTypeEnum;

        // CH: 阈值类型 | EN: Threshold Type
        typedef enum _ExactThresholdFlagEnum
        {
            // CH: 自动阈值 | EN: Auto Threshold
            ExactThresholdFlag_AutoThreshold = 0x0,

            // CH: 模板阈值 | EN: Model Threshold
            ExactThresholdFlag_ModelThreshold = 0x1,

            // CH: 手动阈值 | EN: Manual Threshold
            ExactThresholdFlag_ManualThreshold = 0x2,

        }ExactThresholdFlagEnum;

        // CH: 匹配极性 | EN: Match Polarity
        typedef enum _MatchPolarityEnum
        {
            // CH: 不考虑极性 | EN: Ignored
            MatchPolarity_No = 0x0,

            // CH: 考虑极性 | EN: Considered
            MatchPolarity_Yes = 0x1,

        }MatchPolarityEnum;

        // CH: 阈值类型 | EN: Threshold Type
        typedef enum _MatchThresholdFlagEnum
        {
            // CH: 自动阈值 | EN: Auto Threshold
            MatchThresholdFlag_AutoThreshold = 0x0,

            // CH: 模板阈值 | EN: Model Threshold
            MatchThresholdFlag_ModelThreshold = 0x1,

            // CH: 手动阈值 | EN: Manual Threshold
            MatchThresholdFlag_ManualThreshold = 0x2,

        }MatchThresholdFlagEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class MarkInspRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the MarkInspParams.  */
        class MarkInspParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MarkInspParams() {}
            virtual ~MarkInspParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual MarkInspRoiManager* GetModuRoiManager() = 0;

            // CH: 归一化类型 | EN: Normalization Type
            __declspec(property(put = SetNormlizeType, get = GetNormlizeType)) NormlizeTypeEnum NormlizeType;

            virtual NormlizeTypeEnum GetNormlizeType() = 0;

            virtual void SetNormlizeType(NormlizeTypeEnum value) = 0;

            // CH: 直方图比例 | EN: Histogram Ratio
            __declspec(property(put = SetNormLeftPercent, get = GetNormLeftPercent)) double NormLeftPercent;

            virtual double GetNormLeftPercent() = 0;

            virtual void SetNormLeftPercent(double value) = 0;

            // CH: 直方图比例 | EN: Histogram Ratio
            __declspec(property(put = SetNormRightPercent, get = GetNormRightPercent)) double NormRightPercent;

            virtual double GetNormRightPercent() = 0;

            virtual void SetNormRightPercent(double value) = 0;

            // CH: 统计训练方法 | EN: Statistical Training Type
            __declspec(property(put = SetMarkModelType, get = GetMarkModelType)) MarkModelTypeEnum MarkModelType;

            virtual MarkModelTypeEnum GetMarkModelType() = 0;

            virtual void SetMarkModelType(MarkModelTypeEnum value) = 0;

            // CH: 相关分数阈值 | EN: Correlation Score Threshold
            __declspec(property(put = SetCorreScore, get = GetCorreScore)) int CorreScore;

            virtual int GetCorreScore() = 0;

            virtual void SetCorreScore(int value) = 0;

            // CH: 高度方向区块 | EN: Blocks in Height
            __declspec(property(put = SetBlockNumX, get = GetBlockNumX)) int BlockNumX;

            virtual int GetBlockNumX() = 0;

            virtual void SetBlockNumX(int value) = 0;

            // CH: 宽度方向区块 | EN: Blocks in Width
            __declspec(property(put = SetBlockNumY, get = GetBlockNumY)) int BlockNumY;

            virtual int GetBlockNumY() = 0;

            virtual void SetBlockNumY(int value) = 0;

            // CH: 高阈值比例 | EN: High Threshold Ratio
            __declspec(property(put = SetHighScale, get = GetHighScale)) double HighScale;

            virtual double GetHighScale() = 0;

            virtual void SetHighScale(double value) = 0;

            // CH: 高阈值容忍 | EN: High Threshold Tolerance
            __declspec(property(put = SetHighOffset, get = GetHighOffset)) double HighOffset;

            virtual double GetHighOffset() = 0;

            virtual void SetHighOffset(double value) = 0;

            // CH: 低阈值比例 | EN: Low Threshold Ratio
            __declspec(property(put = SetLowScale, get = GetLowScale)) double LowScale;

            virtual double GetLowScale() = 0;

            virtual void SetLowScale(double value) = 0;

            // CH: 低阈值容忍 | EN: Low Threshold Tolerance
            __declspec(property(put = SetLowOffset, get = GetLowOffset)) double LowOffset;

            virtual double GetLowOffset() = 0;

            virtual void SetLowOffset(double value) = 0;

            // CH: 缺陷类型 | EN: DefectType
            __declspec(property(put = SetFlawType, get = GetFlawType)) FlawTypeEnum FlawType;

            virtual FlawTypeEnum GetFlawType() = 0;

            virtual void SetFlawType(FlawTypeEnum value) = 0;

            // CH: 容忍度开关 | EN: Tolerance Flag
            __declspec(property(put = SetToleranceFlag, get = GetToleranceFlag)) bool ToleranceFlag;

            virtual bool GetToleranceFlag() = 0;

            virtual void SetToleranceFlag(bool value) = 0;

            // CH: 容忍度数值 | EN: Tolerance Value
            __declspec(property(put = SetToleranceValue, get = GetToleranceValue)) int ToleranceValue;

            virtual int GetToleranceValue() = 0;

            virtual void SetToleranceValue(int value) = 0;

            // CH: 面积大小阈值 | EN: Area Threshold
            __declspec(property(put = SetAreaThresh, get = GetAreaThresh)) int AreaThresh;

            virtual int GetAreaThresh() = 0;

            virtual void SetAreaThresh(int value) = 0;

            // CH: 最小匹配分数 | EN: Min Match Score
            __declspec(property(put = SetMatchMarkMinScore, get = GetMatchMarkMinScore)) double MatchMarkMinScore;

            virtual double GetMatchMarkMinScore() = 0;

            virtual void SetMatchMarkMinScore(double value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetMatchMarkAngleStart, get = GetMatchMarkAngleStart)) int MatchMarkAngleStart;

            virtual int GetMatchMarkAngleStart() = 0;

            virtual void SetMatchMarkAngleStart(int value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetMatchMarkAngleEnd, get = GetMatchMarkAngleEnd)) int MatchMarkAngleEnd;

            virtual int GetMatchMarkAngleEnd() = 0;

            virtual void SetMatchMarkAngleEnd(int value) = 0;

            // CH: 阈值类型 | EN: Threshold Type
            __declspec(property(put = SetExactThresholdFlag, get = GetExactThresholdFlag)) ExactThresholdFlagEnum ExactThresholdFlag;

            virtual ExactThresholdFlagEnum GetExactThresholdFlag() = 0;

            virtual void SetExactThresholdFlag(ExactThresholdFlagEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetExactThreshold, get = GetExactThreshold)) int ExactThreshold;

            virtual int GetExactThreshold() = 0;

            virtual void SetExactThreshold(int value) = 0;

            // CH: 速度使能 | EN: Speed Enable
            __declspec(property(put = SetMatchMarkRoughFlag, get = GetMatchMarkRoughFlag)) bool MatchMarkRoughFlag;

            virtual bool GetMatchMarkRoughFlag() = 0;

            virtual void SetMatchMarkRoughFlag(bool value) = 0;

            // CH: 速度阈值 | EN: Speed Threshold
            __declspec(property(put = SetMatchMarkRoughThresh, get = GetMatchMarkRoughThresh)) double MatchMarkRoughThresh;

            virtual double GetMatchMarkRoughThresh() = 0;

            virtual void SetMatchMarkRoughThresh(double value) = 0;

            // CH: 位置纠正 | EN: Correct Flag
            __declspec(property(put = SetMatchCorrectFlag, get = GetMatchCorrectFlag)) bool MatchCorrectFlag;

            virtual bool GetMatchCorrectFlag() = 0;

            virtual void SetMatchCorrectFlag(bool value) = 0;

            // CH: 宽度方向容忍 | EN: Width Tolerance
            __declspec(property(put = SetMatchToleranceX, get = GetMatchToleranceX)) int MatchToleranceX;

            virtual int GetMatchToleranceX() = 0;

            virtual void SetMatchToleranceX(int value) = 0;

            // CH: 高度方向容忍 | EN: Height Tolerance
            __declspec(property(put = SetMatchToleranceY, get = GetMatchToleranceY)) int MatchToleranceY;

            virtual int GetMatchToleranceY() = 0;

            virtual void SetMatchToleranceY(int value) = 0;

            // CH: 最小匹配分数 | EN: Min Match Score
            __declspec(property(put = SetMatchMinScore, get = GetMatchMinScore)) double MatchMinScore;

            virtual double GetMatchMinScore() = 0;

            virtual void SetMatchMinScore(double value) = 0;

            // CH: 匹配极性 | EN: Match Polarity
            __declspec(property(put = SetMatchPolarity, get = GetMatchPolarity)) MatchPolarityEnum MatchPolarity;

            virtual MatchPolarityEnum GetMatchPolarity() = 0;

            virtual void SetMatchPolarity(MatchPolarityEnum value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetMatchAngleStart, get = GetMatchAngleStart)) int MatchAngleStart;

            virtual int GetMatchAngleStart() = 0;

            virtual void SetMatchAngleStart(int value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetMatchAngleEnd, get = GetMatchAngleEnd)) int MatchAngleEnd;

            virtual int GetMatchAngleEnd() = 0;

            virtual void SetMatchAngleEnd(int value) = 0;

            // CH: 尺度范围 | EN: Scale Range
            __declspec(property(put = SetMatchScaleStart, get = GetMatchScaleStart)) double MatchScaleStart;

            virtual double GetMatchScaleStart() = 0;

            virtual void SetMatchScaleStart(double value) = 0;

            // CH: 尺度范围 | EN: Scale Range
            __declspec(property(put = SetMatchScaleEnd, get = GetMatchScaleEnd)) double MatchScaleEnd;

            virtual double GetMatchScaleEnd() = 0;

            virtual void SetMatchScaleEnd(double value) = 0;

            // CH: 阈值类型 | EN: Threshold Type
            __declspec(property(put = SetMatchThresholdFlag, get = GetMatchThresholdFlag)) MatchThresholdFlagEnum MatchThresholdFlag;

            virtual MatchThresholdFlagEnum GetMatchThresholdFlag() = 0;

            virtual void SetMatchThresholdFlag(MatchThresholdFlagEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetMatchThreshold, get = GetMatchThreshold)) int MatchThreshold;

            virtual int GetMatchThreshold() = 0;

            virtual void SetMatchThreshold(int value) = 0;

            // CH: 速度使能 | EN: Speed Enable
            __declspec(property(put = SetMatchRoughFlag, get = GetMatchRoughFlag)) bool MatchRoughFlag;

            virtual bool GetMatchRoughFlag() = 0;

            virtual void SetMatchRoughFlag(bool value) = 0;

            // CH: 速度阈值 | EN: Speed Threshold
            __declspec(property(put = SetMatchRoughThresh, get = GetMatchRoughThresh)) double MatchRoughThresh;

            virtual double GetMatchRoughThresh() = 0;

            virtual void SetMatchRoughThresh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        // 字符缺陷检测方法
        typedef _MVD_MKINSP_METHOD_TYPE__ MVD_MKINSP_METHOD_TYPE;
        
        /*  Note: Interface Classes of the result of the MarkInspResults.  */
        class MarkInspResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MarkInspResults() {}
            virtual ~MarkInspResults() {}

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
        /*  Note: Note: This is the class for the MarkInsp tool.  */
        class IMVSMarkInspModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMarkInspModuTool() {}
            virtual ~IMVSMarkInspModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MarkInspParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MarkInspResults* GetResult() = 0;

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
            IMVSMarkInspModuTool(IMVSMarkInspModuTool&);
            IMVSMarkInspModuTool& operator=(IMVSMarkInspModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MarkInsp.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMarkInspModu::IMVSMarkInspModuTool * __stdcall GetMarkInspToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MARKINSP_H_
