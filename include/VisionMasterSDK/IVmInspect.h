/***************************************************************************************************
 * File：IVmInspect.h
 * Note：CH: 异常检测模块接口声明 | En: Interface for the Anomaly Detection tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_INSPECT_H_
#define _IVM_INSPECT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSInspectModu
    {
        /*************************** Params Class Start ***************************/
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

        /*  Note: Interface Classes of the parameter of the InspectParams.  */
        class InspectParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit InspectParams() {}
            virtual ~InspectParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 分数阈值 | EN: Score Threshold
            __declspec(property(put = SetInspectScore, get = GetInspectScore)) double InspectScore;

            virtual double GetInspectScore() = 0;

            virtual void SetInspectScore(double value) = 0;

            // CH: 下采样率 | EN: Down Sample Rate
            __declspec(property(put = SetDownSampleRate, get = GetDownSampleRate)) int DownSampleRate;

            virtual int GetDownSampleRate() = 0;

            virtual void SetDownSampleRate(int value) = 0;

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

            // CH: 阈值类型 | EN: Threshold Type
            __declspec(property(put = SetMatchThresholdFlag, get = GetMatchThresholdFlag)) MatchThresholdFlagEnum MatchThresholdFlag;

            virtual MatchThresholdFlagEnum GetMatchThresholdFlag() = 0;

            virtual void SetMatchThresholdFlag(MatchThresholdFlagEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetMatchThreshold, get = GetMatchThreshold)) int MatchThreshold;

            virtual int GetMatchThreshold() = 0;

            virtual void SetMatchThreshold(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the InspectResults.  */
        class InspectResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit InspectResults() {}
            virtual ~InspectResults() {}

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
             * 标签
             * @par 权限
             * 只读
             */
            virtual const char * GetInspectLabel() = 0;

            /**
             * @par 说明
             * 分数
             * @par 权限
             * 只读
             */
            virtual float GetInspectScore() = 0;

            /**
             * @par 说明
             * 对比状态
             * @par 权限
             * 只读
             */
            virtual int GetInspectStatus() = 0;

            /**
             * @par 说明
             * Roi数量
             * @par 权限
             * 只读
             */
            virtual int GetInspRoiNum() = 0;

            /**
             * @par 说明
             * 匹配框
             * @par 权限
             * 只读
             */
            virtual RectBox GetMatchRect() = 0;

            /**
             * @par 说明
             * 匹配状态
             * @par 权限
             * 只读
             */
            virtual int GetMatchStatus() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Anomaly Detection tool.  */
        class IMVSInspectModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSInspectModuTool() {}
            virtual ~IMVSInspectModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual InspectParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual InspectResults* GetResult() = 0;

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
            IMVSInspectModuTool(IMVSInspectModuTool&);
            IMVSInspectModuTool& operator=(IMVSInspectModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Inspect.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSInspectModu::IMVSInspectModuTool * __stdcall GetInspectToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_INSPECT_H_
