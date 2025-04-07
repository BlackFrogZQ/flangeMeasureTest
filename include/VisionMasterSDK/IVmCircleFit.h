/***************************************************************************************************
 * File：IVmCircleFit.h
 * Note：CH: 圆拟合模块接口声明 | En: Interface for the CircleFit tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CIRCLEFIT_H_
#define _IVM_CIRCLEFIT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCircleFitModu
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

        /*  Note: Interface Classes of the parameter of the CircleFitParams.  */
        class CircleFitParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CircleFitParams() {}
            virtual ~CircleFitParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入拟合点(仅当次执行起效) | EN: InputFittingPoint(Only valid for this execution)
            virtual void SetInputFittingPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

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

            // CH: 半径判断 | EN: Radius Check
            __declspec(property(put = SetRadiusLimitEnable, get = GetRadiusLimitEnable)) bool RadiusLimitEnable;

            virtual bool GetRadiusLimitEnable() = 0;

            virtual void SetRadiusLimitEnable(bool value) = 0;

            // CH: 半径范围 | EN: Radius Range
            __declspec(property(put = SetRadiusLimitLow, get = GetRadiusLimitLow)) double RadiusLimitLow;

            virtual double GetRadiusLimitLow() = 0;

            virtual void SetRadiusLimitLow(double value) = 0;

            // CH: 半径范围 | EN: Radius Range
            __declspec(property(put = SetRadiusLimitHigh, get = GetRadiusLimitHigh)) double RadiusLimitHigh;

            virtual double GetRadiusLimitHigh() = 0;

            virtual void SetRadiusLimitHigh(double value) = 0;

            // CH: 中心X判断 | EN: Center X Check
            __declspec(property(put = SetCenterXLimitEnable, get = GetCenterXLimitEnable)) bool CenterXLimitEnable;

            virtual bool GetCenterXLimitEnable() = 0;

            virtual void SetCenterXLimitEnable(bool value) = 0;

            // CH: 中心X范围 | EN: Center X Range
            __declspec(property(put = SetCenterXLimitLow, get = GetCenterXLimitLow)) double CenterXLimitLow;

            virtual double GetCenterXLimitLow() = 0;

            virtual void SetCenterXLimitLow(double value) = 0;

            // CH: 中心X范围 | EN: Center X Range
            __declspec(property(put = SetCenterXLimitHigh, get = GetCenterXLimitHigh)) double CenterXLimitHigh;

            virtual double GetCenterXLimitHigh() = 0;

            virtual void SetCenterXLimitHigh(double value) = 0;

            // CH: 中心Y判断 | EN: Center Y Check
            __declspec(property(put = SetCenterYLimitEnable, get = GetCenterYLimitEnable)) bool CenterYLimitEnable;

            virtual bool GetCenterYLimitEnable() = 0;

            virtual void SetCenterYLimitEnable(bool value) = 0;

            // CH: 中心Y范围 | EN: Center Y Range
            __declspec(property(put = SetCenterYLimitLow, get = GetCenterYLimitLow)) double CenterYLimitLow;

            virtual double GetCenterYLimitLow() = 0;

            virtual void SetCenterYLimitLow(double value) = 0;

            // CH: 中心Y范围 | EN: Center Y Range
            __declspec(property(put = SetCenterYLimitHigh, get = GetCenterYLimitHigh)) double CenterYLimitHigh;

            virtual double GetCenterYLimitHigh() = 0;

            virtual void SetCenterYLimitHigh(double value) = 0;

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
        /*  Note: Interface Classes of the result of the CircleFitResults.  */
        class CircleFitResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CircleFitResults() {}
            virtual ~CircleFitResults() {}

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
             * 输出圆
             * @par 权限
             * 只读
             */
            virtual Circle GetFitCircle() = 0;
            /**
            * @par 说明
            * 输出圆环
            * @par 权限
            * 只读
            */
            virtual Annulus GetFitCircleAnnulus() = 0;
            /**
             * @par 说明
             * 拟合误差
             * @par 权限
             * 只读
             */
            virtual float GetFitError() = 0;
            /**
             * @par 说明
             * 拟合状态
             * @par 权限
             * 只读
             */
            virtual int GetFitStatus() = 0;
            /**
             * @par 说明
             * 匹配点数
             * @par 权限
             * 只读
             */
            virtual int GetNumOfPointsUsed() = 0;
            /**
             * @par 说明
             * 拟合点
             * @param nIndex [in] 输入点索引，[0,InputPointNum)
             * @par 权限
             * 只读
             */
            virtual PointF GetOutputFittingPoint(int nIndex) = 0;
            /**
             * @par 说明
             * 获取指定索引处的输入点的拟合距离
             * @param nIndex [in] 输入点索引，[0,InputPointNum)
             * @par 权限
             * 只读
             */
            virtual float GetFitDist(int nIndex) = 0;
            /**
             * @par 说明
             * 获取指定索引处的匹配点
             * @param nIndex [in] 输入点索引，[0,InputPointNum)
             * @par 权限
             * 只读
             */
            virtual int GetFitUsedPoint(int nIndex) = 0;
            /**
             * @par 说明
             * 拟合点数
             * @par 权限
             * 只读
             */
            virtual int GetFitPointNum() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CircleFit tool.  */
        class IMVSCircleFitModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCircleFitModuTool() {}
            virtual ~IMVSCircleFitModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CircleFitParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CircleFitResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCircleFitModuTool(IMVSCircleFitModuTool&);
            IMVSCircleFitModuTool& operator=(IMVSCircleFitModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CircleFit.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCircleFitModu::IMVSCircleFitModuTool * __stdcall GetCircleFitToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CIRCLEFIT_H_
