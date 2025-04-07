/***************************************************************************************************
 * File：IVmLineFindGroup.h
 * Note：CH: 直线查找组合模块接口声明 | En: Interface for the LineFindGroup tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_LINEFINDGROUP_H_
#define _IVM_LINEFINDGROUP_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSLineFindGroupModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 初始化类型 | EN: Init Type
        typedef enum _InitTypeEnum
        {
            // CH: 全局法 | EN: Global Optimum
            InitType_Global = 0x1,

            // CH: 局部最优 | EN: Local Optimum
            InitType_Exhaustion = 0x2,

        }InitTypeEnum;

        // CH: 权重函数 | EN: Weighting Function
        typedef enum _WeightFuncEnum
        {
            // CH: 最小二乘 | EN: Least Squares
            WeightFunc_LeastSquare = 0x1,

            // CH: Huber函数 | EN: Huber Function
            WeightFunc_Huber = 0x2,

            // CH: Tukey函数 | EN: Tukey Function
            WeightFunc_Tukey = 0x3,

        }WeightFuncEnum;

        /*  Note: Interface Classes of the parameter of the LineFindGroupParams.  */
        class LineFindGroupParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineFindGroupParams() {}
            virtual ~LineFindGroupParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 剔除点数 | EN: Reject Number
            __declspec(property(put = SetRejectNum, get = GetRejectNum)) int RejectNum;

            virtual int GetRejectNum() = 0;

            virtual void SetRejectNum(int value) = 0;

            // CH: 剔除距离 | EN: Distance to remove
            __declspec(property(put = SetRejectDist, get = GetRejectDist)) int RejectDist;

            virtual int GetRejectDist() = 0;

            virtual void SetRejectDist(int value) = 0;

            // CH: 初始化类型 | EN: Init Type
            __declspec(property(put = SetInitType, get = GetInitType)) InitTypeEnum InitType;

            virtual InitTypeEnum GetInitType() = 0;

            virtual void SetInitType(InitTypeEnum value) = 0;

            // CH: 权重函数 | EN: Weighting Function
            __declspec(property(put = SetWeightFunc, get = GetWeightFunc)) WeightFuncEnum WeightFunc;

            virtual WeightFuncEnum GetWeightFunc() = 0;

            virtual void SetWeightFunc(WeightFuncEnum value) = 0;

            // CH: 最大迭代次数 | EN: Max Iteration
            __declspec(property(put = SetMaxIters, get = GetMaxIters)) int MaxIters;

            virtual int GetMaxIters() = 0;

            virtual void SetMaxIters(int value) = 0;

            // CH: 匹配点数判断 | EN: Fit Points Check
            __declspec(property(put = SetNumLimitEnable, get = GetNumLimitEnable)) bool NumLimitEnable;

            virtual bool GetNumLimitEnable() = 0;

            virtual void SetNumLimitEnable(bool value) = 0;

            // CH: 拟合点数范围 | EN: Fit Points Range
            __declspec(property(put = SetNumLimitLow, get = GetNumLimitLow)) int NumLimitLow;

            virtual int GetNumLimitLow() = 0;

            virtual void SetNumLimitLow(int value) = 0;

            // CH: 拟合点数范围 | EN: Fit Points Range
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

            // CH: 拟合误差判断 | EN: Fit Error Check
            __declspec(property(put = SetScoreLimitEnable, get = GetScoreLimitEnable)) bool ScoreLimitEnable;

            virtual bool GetScoreLimitEnable() = 0;

            virtual void SetScoreLimitEnable(bool value) = 0;

            // CH: 拟合误差范围 | EN: Fit Error Range
            __declspec(property(put = SetScoreLimitLow, get = GetScoreLimitLow)) double ScoreLimitLow;

            virtual double GetScoreLimitLow() = 0;

            virtual void SetScoreLimitLow(double value) = 0;

            // CH: 拟合误差范围 | EN: Fit Error Range
            __declspec(property(put = SetScoreLimitHigh, get = GetScoreLimitHigh)) double ScoreLimitHigh;

            virtual double GetScoreLimitHigh() = 0;

            virtual void SetScoreLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the LineFindGroupResults.  */
        class LineFindGroupResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineFindGroupResults() {}
            virtual ~LineFindGroupResults() {}

        public:
             /**
             * @par 说明
             * 卡尺检测区
             * @par 权限
             * 只读
             */
             virtual RectBox GetDetectCaliperBox(int nIndex) = 0;
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
            /**
             * @par 说明
             * 输出直线
             * @par 权限
             * 只读
             */
            virtual Line GetOutputLine() = 0;

            /**
             * @par 说明
             * 输出拟合点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F * GetOutputFittingPoint() = 0;

            /**
             * @par 说明
             * 拟合误差
             * @par 权限
             * 只读
             */
            virtual float GetLineFitScore() = 0;

            /**
             * @par 说明
             * 拟合状态
             * @par 权限
             * 只读
             */
            virtual int GetLineFitStatus() = 0;

            /**
             * @par 说明
             * 拟合点数
             * @par 权限
             * 只读
             */
            virtual int GetFitPointNum() = 0;

            /**
             * @par 说明
             * 拟合距离
             * @par 权限
             * 只读
             */
            virtual float GetFitDist(int nIndex) = 0;

            /**
             * @par 说明
             * 匹配点
             * @par 权限
             * 只读
             */
            virtual int GetFitUsedPoint(int nIndex) = 0;

            /**
             * @par 说明
             * 匹配点数
             * @par 权限
             * 只读
             */
            virtual int GetFitUsedPointNum() = 0;

            /**
             * @par 说明
             * 最小外接矩形数量
             * @par 权限
             * 只读
             */
            virtual int GetMinBoudingRectNum() = 0;

            /**
             * @par 说明
             * 最小外接矩形
             * @par 权限
             * 只读
             */
            virtual RectBox GetMinBoudingRect(int nIndex) = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the LineFindGroup tool.  */
        class IMVSLineFindGroupModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSLineFindGroupModuTool() {}
            virtual ~IMVSLineFindGroupModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual LineFindGroupParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual LineFindGroupResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSLineFindGroupModuTool(IMVSLineFindGroupModuTool&);
            IMVSLineFindGroupModuTool& operator=(IMVSLineFindGroupModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for LineFindGroup.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSLineFindGroupModu::IMVSLineFindGroupModuTool * __stdcall GetLineFindGroupToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_LINEFINDGROUP_H_
