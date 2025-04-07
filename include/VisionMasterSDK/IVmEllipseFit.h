/***************************************************************************************************
 * File：IVmEllipseFit.h
 * Note：CH: 椭圆拟合模块接口声明 | En: Interface for the EllipseFit tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_ELLIPSEFIT_H_
#define _IVM_ELLIPSEFIT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSEllipseFitModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the EllipseFitParams.  */
        class EllipseFitParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EllipseFitParams() {}
            virtual ~EllipseFitParams() {}

        public:

            // CH: 输入拟合点(仅当次执行起效) | EN: InputFittingPoint(Only valid for this execution)
            virtual void SetInputFittingPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 误差容忍度 | EN: ErrorTolerance
            __declspec(property(put = SetErrorTolerance, get = GetErrorTolerance)) int ErrorTolerance;

            virtual int GetErrorTolerance() = 0;

            virtual void SetErrorTolerance(int value) = 0;

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
        /*  Note: Interface Classes of the result of the EllipseFitResults.  */
        class EllipseFitResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EllipseFitResults() {}
            virtual ~EllipseFitResults() {}

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
			 * 输出椭圆
			 * @par 权限
			 * 只读
			 */
			 virtual Ellipse GetFitEllipse() = 0;
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
			 * 拟合点
			 * @param nIndex [in] 输入点索引，[0,InputPointNum)
			 * @par 权限
			 * 只读
			 */
			 virtual PointF GetOutputFittingPoint(int nIndex) = 0;
			 /**
			 * @par 说明
			 * 拟合点数
			 * @par 权限
			 * 只读
			 */
			 virtual int GetFitPointNum() = 0;
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
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the EllipseFit tool.  */
        class IMVSEllipseFitModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSEllipseFitModuTool() {}
            virtual ~IMVSEllipseFitModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual EllipseFitParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual EllipseFitResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSEllipseFitModuTool(IMVSEllipseFitModuTool&);
            IMVSEllipseFitModuTool& operator=(IMVSEllipseFitModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for EllipseFit.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSEllipseFitModu::IMVSEllipseFitModuTool * __stdcall GetEllipseFitToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_ELLIPSEFIT_H_
