/***************************************************************************************************
 * File：IVmMarkFind.h
 * Note：CH: 图形定位模块接口声明 | En: Interface for the MarkFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MARKFIND_H_
#define _IVM_MARKFIND_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMarkFindModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 匹配极性 | EN: Match Polarity
        typedef enum _PolarityEnum
        {
            // CH: 不考虑极性 | EN: Ignored
            Polarity_No = 0x0,

            // CH: 考虑极性 | EN: Considered
            Polarity_Yes = 0x1,

        }PolarityEnum;

        // CH: 定位类型 | EN: Mark LocationType
        typedef enum _MarkLocationTypeEnum
        {
            // CH: 直接映射 | EN: Direct Mapping
            MarkLocationType_No = 0x0,

            // CH: 二次修正 | EN: Second Correction
            MarkLocationType_Yes = 0x1,

        }MarkLocationTypeEnum;

        // CH: 排序类型 | EN: Sort
        typedef enum _SortTypeEnum
        {
            // CH: 按分数降序排序 | EN: Score: High to Low
            SortType_Score = 0x2,

            // CH: 按角度降序排序 | EN: Angle: Big to Small
            SortType_Angle = 0x3,

            // CH: 按X由小到大排序 | EN: X: Small to Big
            SortType_X = 0x4,

            // CH: 按Y由小到大排序 | EN: Y: Small to Big
            SortType_Y = 0x5,

            // CH: X由小到大，Y由小到大 | EN: X: Small to Big, Y: Small to Big
            SortType_XY = 0x6,

            // CH: Y由小到大，X由小到大 | EN: Y: Small to Big, X: Small to Big
            SortType_YX = 0x7,

        }SortTypeEnum;

        // CH: 阈值类型 | EN: Threshold Type
        typedef enum _MatchThresholdFlagEnum
        {
            // CH: 自动阈值 | EN: Auto Threshold
            MatchThresholdFlag_Auto = 0x0,

            // CH: 模板阈值 | EN: Model Threshold
            MatchThresholdFlag_Model = 0x1,

            // CH: 手动阈值 | EN: Manual Threshold
            MatchThresholdFlag_Manual = 0x2,

        }MatchThresholdFlagEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class MarkFindRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the MarkFindParams.  */
        class MarkFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MarkFindParams() {}
            virtual ~MarkFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual MarkFindRoiManager* GetModuRoiManager() = 0;

            // CH: 最小匹配分数 | EN: Min Match Score
            __declspec(property(put = SetMinScore, get = GetMinScore)) double MinScore;

            virtual double GetMinScore() = 0;

            virtual void SetMinScore(double value) = 0;

            // CH: 最大匹配个数 | EN: Max Number to find
            __declspec(property(put = SetMaxMatchNum, get = GetMaxMatchNum)) int MaxMatchNum;

            virtual int GetMaxMatchNum() = 0;

            virtual void SetMaxMatchNum(int value) = 0;

            // CH: 匹配极性 | EN: Match Polarity
            __declspec(property(put = SetPolarity, get = GetPolarity)) PolarityEnum Polarity;

            virtual PolarityEnum GetPolarity() = 0;

            virtual void SetPolarity(PolarityEnum value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngleStart, get = GetAngleStart)) int AngleStart;

            virtual int GetAngleStart() = 0;

            virtual void SetAngleStart(int value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngleEnd, get = GetAngleEnd)) int AngleEnd;

            virtual int GetAngleEnd() = 0;

            virtual void SetAngleEnd(int value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: 尺度范围 | EN: Scale Range
            __declspec(property(put = SetScaleStart, get = GetScaleStart)) double ScaleStart;

            virtual double GetScaleStart() = 0;

            virtual void SetScaleStart(double value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: 尺度范围 | EN: Scale Range
            __declspec(property(put = SetScaleEnd, get = GetScaleEnd)) double ScaleEnd;

            virtual double GetScaleEnd() = 0;

            virtual void SetScaleEnd(double value) = 0;

            // CH: 定位类型 | EN: Mark LocationType
            __declspec(property(put = SetMarkLocationType, get = GetMarkLocationType)) MarkLocationTypeEnum MarkLocationType;

            virtual MarkLocationTypeEnum GetMarkLocationType() = 0;

            virtual void SetMarkLocationType(MarkLocationTypeEnum value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: X尺度范围 | EN: X Scale Range
            __declspec(property(put = SetScaleXStart, get = GetScaleXStart)) double ScaleXStart;

            virtual double GetScaleXStart() = 0;

            virtual void SetScaleXStart(double value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: X尺度范围 | EN: X Scale Range
            __declspec(property(put = SetScaleXEnd, get = GetScaleXEnd)) double ScaleXEnd;

            virtual double GetScaleXEnd() = 0;

            virtual void SetScaleXEnd(double value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: Y尺度范围 | EN: Y Scale Range
            __declspec(property(put = SetScaleYStart, get = GetScaleYStart)) double ScaleYStart;

            virtual double GetScaleYStart() = 0;

            virtual void SetScaleYStart(double value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: Y尺度范围 | EN: Y Scale Range
            __declspec(property(put = SetScaleYEnd, get = GetScaleYEnd)) double ScaleYEnd;

            virtual double GetScaleYEnd() = 0;

            virtual void SetScaleYEnd(double value) = 0;

            // CH: 最大重叠率 | EN: Overlap Threshold
            __declspec(property(put = SetMaxOverlap, get = GetMaxOverlap)) int MaxOverlap;

            virtual int GetMaxOverlap() = 0;

            virtual void SetMaxOverlap(int value) = 0;

            // CH: 排序类型 | EN: Sort
            __declspec(property(put = SetSortType, get = GetSortType)) SortTypeEnum SortType;

            virtual SortTypeEnum GetSortType() = 0;

            virtual void SetSortType(SortTypeEnum value) = 0;

            // CH: 阈值类型 | EN: Threshold Type
            __declspec(property(put = SetMatchThresholdFlag, get = GetMatchThresholdFlag)) MatchThresholdFlagEnum MatchThresholdFlag;

            virtual MatchThresholdFlagEnum GetMatchThresholdFlag() = 0;

            virtual void SetMatchThresholdFlag(MatchThresholdFlagEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetMatchThresholdHigh, get = GetMatchThresholdHigh)) int MatchThresholdHigh;

            virtual int GetMatchThresholdHigh() = 0;

            virtual void SetMatchThresholdHigh(int value) = 0;

            // CH: 是否考虑噪点 | EN: Noise Considered
            __declspec(property(put = SetSpotterFlag, get = GetSpotterFlag)) bool SpotterFlag;

            virtual bool GetSpotterFlag() = 0;

            virtual void SetSpotterFlag(bool value) = 0;

            // CH: 延拓阈值 | EN: Extension Threshold
            __declspec(property(put = SetMatchExtentRate, get = GetMatchExtentRate)) int MatchExtentRate;

            virtual int GetMatchExtentRate() = 0;

            virtual void SetMatchExtentRate(int value) = 0;

            // CH: 超时控制 | EN: Overtime Control
            __declspec(property(put = SetTimeOut, get = GetTimeOut)) int TimeOut;

            virtual int GetTimeOut() = 0;

            virtual void SetTimeOut(int value) = 0;

            // CH: 轮廓使能 | EN: Contour Enabled
            __declspec(property(put = SetOutLineEnable, get = GetOutLineEnable)) bool OutLineEnable;

            virtual bool GetOutLineEnable() = 0;

            virtual void SetOutLineEnable(bool value) = 0;

            // CH: 数量判断 | EN: Quantity Check
            __declspec(property(put = SetNumLimitEnable, get = GetNumLimitEnable)) bool NumLimitEnable;

            virtual bool GetNumLimitEnable() = 0;

            virtual void SetNumLimitEnable(bool value) = 0;

            // CH: 数量范围 | EN: Quantity Range
            __declspec(property(put = SetNumLimitLow, get = GetNumLimitLow)) int NumLimitLow;

            virtual int GetNumLimitLow() = 0;

            virtual void SetNumLimitLow(int value) = 0;

            // CH: 数量范围 | EN: Quantity Range
            __declspec(property(put = SetNumLimitHigh, get = GetNumLimitHigh)) int NumLimitHigh;

            virtual int GetNumLimitHigh() = 0;

            virtual void SetNumLimitHigh(int value) = 0;

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

            // CH: 弃用 | EN: Obsolete
            // CH: X尺度判断 | EN: X Scale Check
            __declspec(property(put = SetScaleXLimitEnable, get = GetScaleXLimitEnable)) bool ScaleXLimitEnable;

            virtual bool GetScaleXLimitEnable() = 0;

            virtual void SetScaleXLimitEnable(bool value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: X尺度范围 | EN: X Scale Range
            __declspec(property(put = SetScaleXLimitLow, get = GetScaleXLimitLow)) double ScaleXLimitLow;

            virtual double GetScaleXLimitLow() = 0;

            virtual void SetScaleXLimitLow(double value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: X尺度范围 | EN: X Scale Range
            __declspec(property(put = SetScaleXLimitHigh, get = GetScaleXLimitHigh)) double ScaleXLimitHigh;

            virtual double GetScaleXLimitHigh() = 0;

            virtual void SetScaleXLimitHigh(double value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: Y尺度判断 | EN: Y Scale Check
            __declspec(property(put = SetScaleYLimitEnable, get = GetScaleYLimitEnable)) bool ScaleYLimitEnable;

            virtual bool GetScaleYLimitEnable() = 0;

            virtual void SetScaleYLimitEnable(bool value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: Y尺度范围 | EN: Y Scale Range
            __declspec(property(put = SetScaleYLimitLow, get = GetScaleYLimitLow)) double ScaleYLimitLow;

            virtual double GetScaleYLimitLow() = 0;

            virtual void SetScaleYLimitLow(double value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: Y尺度范围 | EN: Y Scale Range
            __declspec(property(put = SetScaleYLimitHigh, get = GetScaleYLimitHigh)) double ScaleYLimitHigh;

            virtual double GetScaleYLimitHigh() = 0;

            virtual void SetScaleYLimitHigh(double value) = 0;

            // CH: 分数判断 | EN: Score Check
            __declspec(property(put = SetScoreLimitEnable, get = GetScoreLimitEnable)) bool ScoreLimitEnable;

            virtual bool GetScoreLimitEnable() = 0;

            virtual void SetScoreLimitEnable(bool value) = 0;

            // CH: 分数范围 | EN: Score Range
            __declspec(property(put = SetScoreLimitLow, get = GetScoreLimitLow)) double ScoreLimitLow;

            virtual double GetScoreLimitLow() = 0;

            virtual void SetScoreLimitLow(double value) = 0;

            // CH: 分数范围 | EN: Score Range
            __declspec(property(put = SetScoreLimitHigh, get = GetScoreLimitHigh)) double ScoreLimitHigh;

            virtual double GetScoreLimitHigh() = 0;

            virtual void SetScoreLimitHigh(double value) = 0;

            // CH: 匹配点X判断 | EN: Match Point X Check
            __declspec(property(put = SetMatchPointXLimitEnable, get = GetMatchPointXLimitEnable)) bool MatchPointXLimitEnable;

            virtual bool GetMatchPointXLimitEnable() = 0;

            virtual void SetMatchPointXLimitEnable(bool value) = 0;

            // CH: 匹配点X范围 | EN: Match Point X Range
            __declspec(property(put = SetMatchPointXLimitLow, get = GetMatchPointXLimitLow)) double MatchPointXLimitLow;

            virtual double GetMatchPointXLimitLow() = 0;

            virtual void SetMatchPointXLimitLow(double value) = 0;

            // CH: 匹配点X范围 | EN: Match Point X Range
            __declspec(property(put = SetMatchPointXLimitHigh, get = GetMatchPointXLimitHigh)) double MatchPointXLimitHigh;

            virtual double GetMatchPointXLimitHigh() = 0;

            virtual void SetMatchPointXLimitHigh(double value) = 0;

            // CH: 匹配点Y判断 | EN: Match Point Y Check
            __declspec(property(put = SetMatchPointYLimitEnable, get = GetMatchPointYLimitEnable)) bool MatchPointYLimitEnable;

            virtual bool GetMatchPointYLimitEnable() = 0;

            virtual void SetMatchPointYLimitEnable(bool value) = 0;

            // CH: 匹配点Y范围 | EN: Match Point Y Range
            __declspec(property(put = SetMatchPointYLimitLow, get = GetMatchPointYLimitLow)) double MatchPointYLimitLow;

            virtual double GetMatchPointYLimitLow() = 0;

            virtual void SetMatchPointYLimitLow(double value) = 0;

            // CH: 匹配点Y范围 | EN: Match Point Y Range
            __declspec(property(put = SetMatchPointYLimitHigh, get = GetMatchPointYLimitHigh)) double MatchPointYLimitHigh;

            virtual double GetMatchPointYLimitHigh() = 0;

            virtual void SetMatchPointYLimitHigh(double value) = 0;

            // CH: 中心点X判断 | EN: Central Point X Check
            __declspec(property(put = SetBoxPointXLimitEnable, get = GetBoxPointXLimitEnable)) bool BoxPointXLimitEnable;

            virtual bool GetBoxPointXLimitEnable() = 0;

            virtual void SetBoxPointXLimitEnable(bool value) = 0;

            // CH: 中心点X范围 | EN: Central Point X Range
            __declspec(property(put = SetBoxPointXLimitLow, get = GetBoxPointXLimitLow)) double BoxPointXLimitLow;

            virtual double GetBoxPointXLimitLow() = 0;

            virtual void SetBoxPointXLimitLow(double value) = 0;

            // CH: 中心点X范围 | EN: Central Point X Range
            __declspec(property(put = SetBoxPointXLimitHigh, get = GetBoxPointXLimitHigh)) double BoxPointXLimitHigh;

            virtual double GetBoxPointXLimitHigh() = 0;

            virtual void SetBoxPointXLimitHigh(double value) = 0;

            // CH: 中心点Y判断 | EN: Central Point Y Check
            __declspec(property(put = SetBoxPointYLimitEnable, get = GetBoxPointYLimitEnable)) bool BoxPointYLimitEnable;

            virtual bool GetBoxPointYLimitEnable() = 0;

            virtual void SetBoxPointYLimitEnable(bool value) = 0;

            // CH: 中心点Y范围 | EN: Central Point Y Range
            __declspec(property(put = SetBoxPointYLimitLow, get = GetBoxPointYLimitLow)) double BoxPointYLimitLow;

            virtual double GetBoxPointYLimitLow() = 0;

            virtual void SetBoxPointYLimitLow(double value) = 0;

            // CH: 中心点Y范围 | EN: Central Point Y Range
            __declspec(property(put = SetBoxPointYLimitHigh, get = GetBoxPointYLimitHigh)) double BoxPointYLimitHigh;

            virtual double GetBoxPointYLimitHigh() = 0;

            virtual void SetBoxPointYLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the MarkFindResults.  */
        class MarkFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MarkFindResults() {}
            virtual ~MarkFindResults() {}

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
             * 匹配状态
             * @par 权限
             * 只读
             */
            virtual int GetMatchStatus(int nIndex) = 0;            

            /**
             * @par 说明
             * 匹配个数
             * @par 权限
             * 只读
             */
            virtual int GetMatchNum() = 0;

            /**
             * @par 说明
             * 匹配框
             * @par 权限
             * 只读
             */
            virtual RectBox GetMatchRect(int nIndex) = 0;

            /**
             * @par 说明
             * 匹配点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetMatchPoint(int nIndex) = 0;

            /**
             * @par 说明
             * 直线数量
             * @par 权限
             * 只读
             */
            virtual int GetLineNum() = 0;

            /**
             * @par 说明
             * 直线状态
             * @par 权限
             * 只读
             */
            virtual int GetLineStatus(int nIndex) = 0;

            /**
             * @par 说明
             * 输出直线
             * @par 权限
             * 只读
             */
            virtual Line GetOutputLine(int nIndex) = 0;

            /**
             * @par 说明
             * 尺度X
             * @par 权限
             * 只读
             */
            virtual float GetMatchScaleX(int nIndex) = 0;

            /**
             * @par 说明
             * 尺度Y
             * @par 权限
             * 只读
             */
            virtual float GetMatchScaleY(int nIndex) = 0;

            /**
             * @par 说明
             * 分数
             * @par 权限
             * 只读
             */
            virtual float GetMatchScore(int nIndex) = 0;

            /**
             * @par 说明
             * 匹配轮廓信息
             * @par 权限
             * 只读
             */
            virtual MatchOutline GetMatchOutline() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the MarkFind tool.  */
        class IMVSMarkFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMarkFindModuTool() {}
            virtual ~IMVSMarkFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MarkFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MarkFindResults* GetResult() = 0;

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
            IMVSMarkFindModuTool(IMVSMarkFindModuTool&);
            IMVSMarkFindModuTool& operator=(IMVSMarkFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MarkFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMarkFindModu::IMVSMarkFindModuTool * __stdcall GetMarkFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MARKFIND_H_
