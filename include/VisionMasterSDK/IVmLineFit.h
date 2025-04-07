/***************************************************************************************************
 * File：IVmLineFit.h
 * Note：CH: 直线拟合模块接口声明 | En: Interface for the LineFit tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_LINEFIT_H_
#define _IVM_LINEFIT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSLineFitModu
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

        /*  Note: Interface Classes of the parameter of the LineFitParams.  */
        class LineFitParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineFitParams() {}
            virtual ~LineFitParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 拟合点(仅当次执行起效) | EN: Fit Point(Only valid for this execution)
            virtual void SetFitPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

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
        /*  Note: Interface Classes of the result of the LineFitResults.  */
        class LineFitResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineFitResults() {}
            virtual ~LineFitResults() {}

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
             * 输出直线
             * @par 权限
             * 只读
             */
            virtual Line GetFitLine() = 0;
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
            * 拟合时使用点个数
            * @par 权限
            * 只读
            */
            virtual int GetFitPointNum() = 0;
            /**
             * @par 说明
             * 匹配点数
             * @par 权限
             * 只读
             */
            virtual int GetNumOfPointsUsed() = 0;
            /**
             * @par 说明
             * 获取指定索引处的输入点是否用于拟合;0:未使用 1:使用
             * @param nIndex [in] 输入点索引，[0,InputPointNum)
             * @par 权限
             * 只读
             */
            virtual int GetPointStatus(int nIndex) = 0;
            /**
             * @par 说明
             * 获取指定索引处的输入点的拟合距离
             * @param nIndex [in] 输入点索引，[0,InputPointNum)
             * @par 权限
             * 只读
             */
            virtual float GetPointFitDistance(int nIndex) = 0;
            /**
             * @par 说明
             * 输出拟合点
             * @param nIndex [in] 输入点索引，[0,InputPointNum)
             * @par 权限
             * 只读
             */
            virtual PointF GetOutputFittingPoint(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the LineFit tool.  */
        class IMVSLineFitModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSLineFitModuTool() {}
            virtual ~IMVSLineFitModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual LineFitParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual LineFitResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSLineFitModuTool(IMVSLineFitModuTool&);
            IMVSLineFitModuTool& operator=(IMVSLineFitModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for LineFit.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSLineFitModu::IMVSLineFitModuTool * __stdcall GetLineFitToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_LINEFIT_H_
