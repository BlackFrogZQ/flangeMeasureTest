/***************************************************************************************************
 * File：IVmFastFeatureMatch.h
 * Note：CH: 快速特征匹配模块接口声明 | En: Interface for the FastFeatureMatch tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_FASTFEATUREMATCH_H_
#define _IVM_FASTFEATUREMATCH_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSFastFeatureMatchModu
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
        class FastFeatureMatchRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the FastFeatureMatchParams.  */
        class FastFeatureMatchParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit FastFeatureMatchParams() {}
            virtual ~FastFeatureMatchParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual FastFeatureMatchRoiManager* GetModuRoiManager() = 0;

            // CH: 全部搜索模式 | EN: Search All Mode
            __declspec(property(put = SetUseMatchAllMode, get = GetUseMatchAllMode)) bool UseMatchAllMode;

            virtual bool GetUseMatchAllMode() = 0;

            virtual void SetUseMatchAllMode(bool value) = 0;

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

            // CH: 尺度范围 | EN: Scale Range
            __declspec(property(put = SetScaleStart, get = GetScaleStart)) double ScaleStart;

            virtual double GetScaleStart() = 0;

            virtual void SetScaleStart(double value) = 0;

            // CH: 尺度范围 | EN: Scale Range
            __declspec(property(put = SetScaleEnd, get = GetScaleEnd)) double ScaleEnd;

            virtual double GetScaleEnd() = 0;

            virtual void SetScaleEnd(double value) = 0;

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

            // CH: 匹配个数为0 | EN: Match Num Is Zero
            __declspec(property(put = SetOKWhenNumIsZero, get = GetOKWhenNumIsZero)) bool OKWhenNumIsZero;

            virtual bool GetOKWhenNumIsZero() = 0;

            virtual void SetOKWhenNumIsZero(bool value) = 0;

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

            // CH: 尺度判断 | EN: Scale Check
            __declspec(property(put = SetScaleLimitEnable, get = GetScaleLimitEnable)) bool ScaleLimitEnable;

            virtual bool GetScaleLimitEnable() = 0;

            virtual void SetScaleLimitEnable(bool value) = 0;

            // CH: 尺度范围 | EN: Scale Range
            __declspec(property(put = SetScaleLimitLow, get = GetScaleLimitLow)) double ScaleLimitLow;

            virtual double GetScaleLimitLow() = 0;

            virtual void SetScaleLimitLow(double value) = 0;

            // CH: 尺度范围 | EN: Scale Range
            __declspec(property(put = SetScaleLimitHigh, get = GetScaleLimitHigh)) double ScaleLimitHigh;

            virtual double GetScaleLimitHigh() = 0;

            virtual void SetScaleLimitHigh(double value) = 0;

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
        /*  Note: Interface Classes for describing edge points Information.  */
        class IPatMatchEdgePoint
        {
        protected:
            ///< Constructor and Destructor
            explicit IPatMatchEdgePoint() {}
            virtual ~IPatMatchEdgePoint() {}

        public:
            /**
             * @par 说明
             * 边缘点位置
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetPosition() = 0;
            /**
             * @par 说明
             * 边缘点得分
             * @par 权限
             * 只读
             */
            virtual float GetScore() = 0;
            /**
             * @par 说明
             * 边缘点索引（权重）
             * @par 权限
             * 只读
             */
            virtual unsigned int GetIndex() = 0;
        };

        /*  Note: Interface Classes for describing outline information.  */
        class IPatMatchOutline
        {
        protected:
            ///< Constructor and Destructor
            explicit IPatMatchOutline() {}
            virtual ~IPatMatchOutline() {}

        public:
            /**
             * @par 说明
             * 边缘点数
             * @par 权限
             * 只读
             */
            virtual int GetPointNum() = 0;
            /**
             * @brief 获取单个轮廓点信息
             * @param nPtIndex [in] 点索引，从0开始计数
             * @return 无，出错时抛出异常
             * @par 注解
             * 无
             */
            virtual IPatMatchEdgePoint* GetEdgePoint( unsigned int nPtIndex ) = 0;
        };

        /*  Note: Interface Classes for describing single match info.  */
        class IFastFeatureMatchInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IFastFeatureMatchInfo() {}
            virtual ~IFastFeatureMatchInfo() {}

        public:
            /**
             * @par 说明
             * 匹配框的位置
             * @par 权限
             * 只读
             */
            virtual RectBox GetMatchBox() = 0;
            /**
             * @par 说明
             * 匹配点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetMatchPoint() = 0;
            /**
             * @par 说明
             * 尺度
             * @par 权限
             * 只读
             */
            virtual float GetScale() = 0;
            /**
             * @par 说明
             * X方向尺度
             * @par 权限
             * 只读
             */
            virtual float GetScaleX() = 0;
            /**
             * @par 说明
             * Y方向尺度
             * @par 权限
             * 只读
             */
            virtual float GetScaleY() = 0;
            /**
             * @par 说明
             * 匹配得分
             * @par 权限
             * 只读
             */
            virtual float GetScore() = 0;
            /**
             * @par 说明
             * 匹配模板编号
             * @par 权限
             * 只读
             */
            virtual int GetMatchModelIndex() = 0;
            /**
             * @par 说明
             * 匹配模板名称
             * @par 权限
             * 只读
             */
            virtual const char * GetMatchModelName() = 0;
        };

        /*  Note: Interface Classes of the result of the FastFeatureMatchResults.  */
        class FastFeatureMatchResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit FastFeatureMatchResults() {}
            virtual ~FastFeatureMatchResults() {}

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
             * 匹配个数
             * @par 权限
             * 只读
             */
            virtual int GetMatchNum() = 0;
            /**
             * @brief 获取匹配信息
             * @param nMatchIndex [in] 匹配信息链表索引，从0开始计
             * @return 返回匹配信
             * @par 注解
             * 无
             */
            virtual IFastFeatureMatchInfo* GetMatchInfo( int nMatchIndex ) = 0;
            /**
             * @brief 获取匹配轮廓
             * @return 轮廓信息
             * @par 注解
             * a).出错时抛出异常
             * b).匹配基本参数设置启用轮廓，方可获取。
             */
            virtual IPatMatchOutline* GetOutline() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the FastFeatureMatch tool.  */
        class IMVSFastFeatureMatchModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSFastFeatureMatchModuTool() {}
            virtual ~IMVSFastFeatureMatchModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual FastFeatureMatchParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual FastFeatureMatchResults* GetResult() = 0;

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
			* @param strPaths   [IN]  模型路径
            * @param nNum   [IN]  模型数量
			* @return 无，出错时抛出异常
			*/
            virtual void ImportModelData(IN ModuleImportData * strPaths, IN const int nNum) = 0;

        private:
            IMVSFastFeatureMatchModuTool(IMVSFastFeatureMatchModuTool&);
            IMVSFastFeatureMatchModuTool& operator=(IMVSFastFeatureMatchModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for FastFeatureMatch.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSFastFeatureMatchModu::IMVSFastFeatureMatchModuTool * __stdcall GetFastFeatureMatchToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_FASTFEATUREMATCH_H_
