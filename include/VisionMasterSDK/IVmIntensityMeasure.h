/***************************************************************************************************
 * File：IVmIntensityMeasure.h
 * Note：CH: 亮度测量模块接口声明 | En: Interface for the IntensityMeasure tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_INTENSITYMEASURE_H_
#define _IVM_INTENSITYMEASURE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSIntensityMeasureModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class IntensityMeasureRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the IntensityMeasureParams.  */
        class IntensityMeasureParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IntensityMeasureParams() {}
            virtual ~IntensityMeasureParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual IntensityMeasureRoiManager* GetModuRoiManager() = 0;

            // CH: 最大值判断 | EN: Max Value Check
            __declspec(property(put = SetMaxValueLimitEnable, get = GetMaxValueLimitEnable)) bool MaxValueLimitEnable;

            virtual bool GetMaxValueLimitEnable() = 0;

            virtual void SetMaxValueLimitEnable(bool value) = 0;

            // CH: 最大值范围 | EN: Max Value Range
            __declspec(property(put = SetMaxValueLimitLow, get = GetMaxValueLimitLow)) int MaxValueLimitLow;

            virtual int GetMaxValueLimitLow() = 0;

            virtual void SetMaxValueLimitLow(int value) = 0;

            // CH: 最大值范围 | EN: Max Value Range
            __declspec(property(put = SetMaxValueLimitHigh, get = GetMaxValueLimitHigh)) int MaxValueLimitHigh;

            virtual int GetMaxValueLimitHigh() = 0;

            virtual void SetMaxValueLimitHigh(int value) = 0;

            // CH: 最小值判断 | EN: Min Value Check
            __declspec(property(put = SetMinValueLimitEnable, get = GetMinValueLimitEnable)) bool MinValueLimitEnable;

            virtual bool GetMinValueLimitEnable() = 0;

            virtual void SetMinValueLimitEnable(bool value) = 0;

            // CH: 最小值范围 | EN: Min Value Range
            __declspec(property(put = SetMinValueLimitLow, get = GetMinValueLimitLow)) int MinValueLimitLow;

            virtual int GetMinValueLimitLow() = 0;

            virtual void SetMinValueLimitLow(int value) = 0;

            // CH: 最小值范围 | EN: Min Value Range
            __declspec(property(put = SetMinValueLimitHigh, get = GetMinValueLimitHigh)) int MinValueLimitHigh;

            virtual int GetMinValueLimitHigh() = 0;

            virtual void SetMinValueLimitHigh(int value) = 0;

            // CH: 均值判断 | EN: Mean Value Check
            __declspec(property(put = SetMeanLimitEnable, get = GetMeanLimitEnable)) bool MeanLimitEnable;

            virtual bool GetMeanLimitEnable() = 0;

            virtual void SetMeanLimitEnable(bool value) = 0;

            // CH: 均值范围 | EN: Mean Value Range
            __declspec(property(put = SetMeanLimitLow, get = GetMeanLimitLow)) double MeanLimitLow;

            virtual double GetMeanLimitLow() = 0;

            virtual void SetMeanLimitLow(double value) = 0;

            // CH: 均值范围 | EN: Mean Value Range
            __declspec(property(put = SetMeanLimitHigh, get = GetMeanLimitHigh)) double MeanLimitHigh;

            virtual double GetMeanLimitHigh() = 0;

            virtual void SetMeanLimitHigh(double value) = 0;

            // CH: 标准差判断 | EN: SD Check
            __declspec(property(put = SetStdLimitEnable, get = GetStdLimitEnable)) bool StdLimitEnable;

            virtual bool GetStdLimitEnable() = 0;

            virtual void SetStdLimitEnable(bool value) = 0;

            // CH: 标准差范围 | EN: SD Range
            __declspec(property(put = SetStdLimitLow, get = GetStdLimitLow)) double StdLimitLow;

            virtual double GetStdLimitLow() = 0;

            virtual void SetStdLimitLow(double value) = 0;

            // CH: 标准差范围 | EN: SD Range
            __declspec(property(put = SetStdLimitHigh, get = GetStdLimitHigh)) double StdLimitHigh;

            virtual double GetStdLimitHigh() = 0;

            virtual void SetStdLimitHigh(double value) = 0;

            // CH: 对比度判断 | EN: Contrast Judge
            __declspec(property(put = SetContrastLimitEnable, get = GetContrastLimitEnable)) bool ContrastLimitEnable;

            virtual bool GetContrastLimitEnable() = 0;

            virtual void SetContrastLimitEnable(bool value) = 0;

            // CH: 对比度范围 | EN: Contrast Range
            __declspec(property(put = SetContrastLimitLow, get = GetContrastLimitLow)) double ContrastLimitLow;

            virtual double GetContrastLimitLow() = 0;

            virtual void SetContrastLimitLow(double value) = 0;

            // CH: 对比度范围 | EN: Contrast Range
            __declspec(property(put = SetContrastLimitHigh, get = GetContrastLimitHigh)) double ContrastLimitHigh;

            virtual double GetContrastLimitHigh() = 0;

            virtual void SetContrastLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the IntensityMeasureResults.  */
        class IntensityMeasureResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IntensityMeasureResults() {}
            virtual ~IntensityMeasureResults() {}

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
             * ROI圆弧
             * @par 权限
             * 只读
             */
             virtual Annulus GetROIAnnulus() = 0;

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
             * 最小值
             * @par 权限
             * 只读
             */
            virtual int GetMinLum() = 0;
            /**
             * @par 说明
             * 最大值
             * @par 权限
             * 只读
             */
            virtual int GetMaxLum() = 0;
            /**
             * @par 说明
             * 均值
             * @par 权限
             * 只读
             */
            virtual float GetMeanLum() = 0;
            /**
             * @par 说明
             * 标准差
             * @par 权限
             * 只读
             */
            virtual float GetStdLum() = 0;
            /**
             * @par 说明
             * 对比度
             * @par 权限
             * 只读
             */
            virtual float GetHistContrast() = 0;
            /**
             * @par 说明
             * 直方图
             * @par 权限
             * 只读
             */
            virtual void GetLumHist(int nLumHist[256]) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the IntensityMeasure tool.  */
        class IMVSIntensityMeasureModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSIntensityMeasureModuTool() {}
            virtual ~IMVSIntensityMeasureModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual IntensityMeasureParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual IntensityMeasureResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSIntensityMeasureModuTool(IMVSIntensityMeasureModuTool&);
            IMVSIntensityMeasureModuTool& operator=(IMVSIntensityMeasureModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for IntensityMeasure.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSIntensityMeasureModu::IMVSIntensityMeasureModuTool * __stdcall GetIntensityMeasureToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_INTENSITYMEASURE_H_
