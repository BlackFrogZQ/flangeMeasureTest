/***************************************************************************************************
 * File：IVmColorMeasure.h
 * Note：CH: 颜色测量模块接口声明 | En: Interface for the ColorMeasure tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_COLORMEASURE_H_
#define _IVM_COLORMEASURE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSColorMeasureModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 颜色空间 | EN: Color Space
        typedef enum _ColorSpaceEnum
        {
            // CH: RGB | EN: RGB
            ColorSpace_RGB = 0x1,

            // CH: HSV | EN: HSV
            ColorSpace_HSV = 0x2,

            // CH: HSI | EN: HSI
            ColorSpace_HSI = 0x3,

        }ColorSpaceEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ColorMeasureRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ColorMeasureParams.  */
        class ColorMeasureParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ColorMeasureParams() {}
            virtual ~ColorMeasureParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ColorMeasureRoiManager* GetModuRoiManager() = 0;

            // CH: 颜色空间 | EN: Color Space
            __declspec(property(put = SetColorSpace, get = GetColorSpace)) ColorSpaceEnum ColorSpace;

            virtual ColorSpaceEnum GetColorSpace() = 0;

            virtual void SetColorSpace(ColorSpaceEnum value) = 0;

            // CH: 通道1最大值 | EN: C1Max
            __declspec(property(put = SetC1MaxValueLimitEnable, get = GetC1MaxValueLimitEnable)) bool C1MaxValueLimitEnable;

            virtual bool GetC1MaxValueLimitEnable() = 0;

            virtual void SetC1MaxValueLimitEnable(bool value) = 0;

            // CH: 最大值范围 | EN: Max Value Range
            __declspec(property(put = SetC1MaxValueLimitLow, get = GetC1MaxValueLimitLow)) int C1MaxValueLimitLow;

            virtual int GetC1MaxValueLimitLow() = 0;

            virtual void SetC1MaxValueLimitLow(int value) = 0;

            // CH: 最大值范围 | EN: Max Value Range
            __declspec(property(put = SetC1MaxValueLimitHigh, get = GetC1MaxValueLimitHigh)) int C1MaxValueLimitHigh;

            virtual int GetC1MaxValueLimitHigh() = 0;

            virtual void SetC1MaxValueLimitHigh(int value) = 0;

            // CH: 通道1最小值 | EN: C1Min
            __declspec(property(put = SetC1MinValueLimitEnable, get = GetC1MinValueLimitEnable)) bool C1MinValueLimitEnable;

            virtual bool GetC1MinValueLimitEnable() = 0;

            virtual void SetC1MinValueLimitEnable(bool value) = 0;

            // CH: 最小值范围 | EN: Min Value Range
            __declspec(property(put = SetC1MinValueLimitLow, get = GetC1MinValueLimitLow)) int C1MinValueLimitLow;

            virtual int GetC1MinValueLimitLow() = 0;

            virtual void SetC1MinValueLimitLow(int value) = 0;

            // CH: 最小值范围 | EN: Min Value Range
            __declspec(property(put = SetC1MinValueLimitHigh, get = GetC1MinValueLimitHigh)) int C1MinValueLimitHigh;

            virtual int GetC1MinValueLimitHigh() = 0;

            virtual void SetC1MinValueLimitHigh(int value) = 0;

            // CH: 通道1均值 | EN: C1Mean
            __declspec(property(put = SetC1MeanLimitEnable, get = GetC1MeanLimitEnable)) bool C1MeanLimitEnable;

            virtual bool GetC1MeanLimitEnable() = 0;

            virtual void SetC1MeanLimitEnable(bool value) = 0;

            // CH: 均值范围 | EN: Mean Value Range
            __declspec(property(put = SetC1MeanLimitLow, get = GetC1MeanLimitLow)) double C1MeanLimitLow;

            virtual double GetC1MeanLimitLow() = 0;

            virtual void SetC1MeanLimitLow(double value) = 0;

            // CH: 均值范围 | EN: Mean Value Range
            __declspec(property(put = SetC1MeanLimitHigh, get = GetC1MeanLimitHigh)) double C1MeanLimitHigh;

            virtual double GetC1MeanLimitHigh() = 0;

            virtual void SetC1MeanLimitHigh(double value) = 0;

            // CH: 通道1标准差 | EN: C1Std
            __declspec(property(put = SetC1StdLimitEnable, get = GetC1StdLimitEnable)) bool C1StdLimitEnable;

            virtual bool GetC1StdLimitEnable() = 0;

            virtual void SetC1StdLimitEnable(bool value) = 0;

            // CH: 标准差范围 | EN: SD Range
            __declspec(property(put = SetC1StdLimitLow, get = GetC1StdLimitLow)) double C1StdLimitLow;

            virtual double GetC1StdLimitLow() = 0;

            virtual void SetC1StdLimitLow(double value) = 0;

            // CH: 标准差范围 | EN: SD Range
            __declspec(property(put = SetC1StdLimitHigh, get = GetC1StdLimitHigh)) double C1StdLimitHigh;

            virtual double GetC1StdLimitHigh() = 0;

            virtual void SetC1StdLimitHigh(double value) = 0;

            // CH: 通道2最大值 | EN: C2Max
            __declspec(property(put = SetC2MaxValueLimitEnable, get = GetC2MaxValueLimitEnable)) bool C2MaxValueLimitEnable;

            virtual bool GetC2MaxValueLimitEnable() = 0;

            virtual void SetC2MaxValueLimitEnable(bool value) = 0;

            // CH: 最大值范围 | EN: Max Value Range
            __declspec(property(put = SetC2MaxValueLimitLow, get = GetC2MaxValueLimitLow)) int C2MaxValueLimitLow;

            virtual int GetC2MaxValueLimitLow() = 0;

            virtual void SetC2MaxValueLimitLow(int value) = 0;

            // CH: 最大值范围 | EN: Max Value Range
            __declspec(property(put = SetC2MaxValueLimitHigh, get = GetC2MaxValueLimitHigh)) int C2MaxValueLimitHigh;

            virtual int GetC2MaxValueLimitHigh() = 0;

            virtual void SetC2MaxValueLimitHigh(int value) = 0;

            // CH: 通道2最小值 | EN: C2Min
            __declspec(property(put = SetC2MinValueLimitEnable, get = GetC2MinValueLimitEnable)) bool C2MinValueLimitEnable;

            virtual bool GetC2MinValueLimitEnable() = 0;

            virtual void SetC2MinValueLimitEnable(bool value) = 0;

            // CH: 最小值范围 | EN: Min Value Range
            __declspec(property(put = SetC2MinValueLimitLow, get = GetC2MinValueLimitLow)) int C2MinValueLimitLow;

            virtual int GetC2MinValueLimitLow() = 0;

            virtual void SetC2MinValueLimitLow(int value) = 0;

            // CH: 最小值范围 | EN: Min Value Range
            __declspec(property(put = SetC2MinValueLimitHigh, get = GetC2MinValueLimitHigh)) int C2MinValueLimitHigh;

            virtual int GetC2MinValueLimitHigh() = 0;

            virtual void SetC2MinValueLimitHigh(int value) = 0;

            // CH: 通道2均值 | EN: C2Mean
            __declspec(property(put = SetC2MeanLimitEnable, get = GetC2MeanLimitEnable)) bool C2MeanLimitEnable;

            virtual bool GetC2MeanLimitEnable() = 0;

            virtual void SetC2MeanLimitEnable(bool value) = 0;

            // CH: 均值范围 | EN: Mean Value Range
            __declspec(property(put = SetC2MeanLimitLow, get = GetC2MeanLimitLow)) double C2MeanLimitLow;

            virtual double GetC2MeanLimitLow() = 0;

            virtual void SetC2MeanLimitLow(double value) = 0;

            // CH: 均值范围 | EN: Mean Value Range
            __declspec(property(put = SetC2MeanLimitHigh, get = GetC2MeanLimitHigh)) double C2MeanLimitHigh;

            virtual double GetC2MeanLimitHigh() = 0;

            virtual void SetC2MeanLimitHigh(double value) = 0;

            // CH: 通道2标准差 | EN: C2Std
            __declspec(property(put = SetC2StdLimitEnable, get = GetC2StdLimitEnable)) bool C2StdLimitEnable;

            virtual bool GetC2StdLimitEnable() = 0;

            virtual void SetC2StdLimitEnable(bool value) = 0;

            // CH: 标准差范围 | EN: SD Range
            __declspec(property(put = SetC2StdLimitLow, get = GetC2StdLimitLow)) double C2StdLimitLow;

            virtual double GetC2StdLimitLow() = 0;

            virtual void SetC2StdLimitLow(double value) = 0;

            // CH: 标准差范围 | EN: SD Range
            __declspec(property(put = SetC2StdLimitHigh, get = GetC2StdLimitHigh)) double C2StdLimitHigh;

            virtual double GetC2StdLimitHigh() = 0;

            virtual void SetC2StdLimitHigh(double value) = 0;

            // CH: 通道3最大值 | EN: C3Max
            __declspec(property(put = SetC3MaxValueLimitEnable, get = GetC3MaxValueLimitEnable)) bool C3MaxValueLimitEnable;

            virtual bool GetC3MaxValueLimitEnable() = 0;

            virtual void SetC3MaxValueLimitEnable(bool value) = 0;

            // CH: 最大值范围 | EN: Max Value Range
            __declspec(property(put = SetC3MaxValueLimitLow, get = GetC3MaxValueLimitLow)) int C3MaxValueLimitLow;

            virtual int GetC3MaxValueLimitLow() = 0;

            virtual void SetC3MaxValueLimitLow(int value) = 0;

            // CH: 最大值范围 | EN: Max Value Range
            __declspec(property(put = SetC3MaxValueLimitHigh, get = GetC3MaxValueLimitHigh)) int C3MaxValueLimitHigh;

            virtual int GetC3MaxValueLimitHigh() = 0;

            virtual void SetC3MaxValueLimitHigh(int value) = 0;

            // CH: 通道3最小值 | EN: C3Min
            __declspec(property(put = SetC3MinValueLimitEnable, get = GetC3MinValueLimitEnable)) bool C3MinValueLimitEnable;

            virtual bool GetC3MinValueLimitEnable() = 0;

            virtual void SetC3MinValueLimitEnable(bool value) = 0;

            // CH: 最小值范围 | EN: Min Value Range
            __declspec(property(put = SetC3MinValueLimitLow, get = GetC3MinValueLimitLow)) int C3MinValueLimitLow;

            virtual int GetC3MinValueLimitLow() = 0;

            virtual void SetC3MinValueLimitLow(int value) = 0;

            // CH: 最小值范围 | EN: Min Value Range
            __declspec(property(put = SetC3MinValueLimitHigh, get = GetC3MinValueLimitHigh)) int C3MinValueLimitHigh;

            virtual int GetC3MinValueLimitHigh() = 0;

            virtual void SetC3MinValueLimitHigh(int value) = 0;

            // CH: 通道3均值 | EN: C3Mean
            __declspec(property(put = SetC3MeanLimitEnable, get = GetC3MeanLimitEnable)) bool C3MeanLimitEnable;

            virtual bool GetC3MeanLimitEnable() = 0;

            virtual void SetC3MeanLimitEnable(bool value) = 0;

            // CH: 均值范围 | EN: Mean Value Range
            __declspec(property(put = SetC3MeanLimitLow, get = GetC3MeanLimitLow)) double C3MeanLimitLow;

            virtual double GetC3MeanLimitLow() = 0;

            virtual void SetC3MeanLimitLow(double value) = 0;

            // CH: 均值范围 | EN: Mean Value Range
            __declspec(property(put = SetC3MeanLimitHigh, get = GetC3MeanLimitHigh)) double C3MeanLimitHigh;

            virtual double GetC3MeanLimitHigh() = 0;

            virtual void SetC3MeanLimitHigh(double value) = 0;

            // CH: 通道3标准差 | EN: C3Std
            __declspec(property(put = SetC3StdLimitEnable, get = GetC3StdLimitEnable)) bool C3StdLimitEnable;

            virtual bool GetC3StdLimitEnable() = 0;

            virtual void SetC3StdLimitEnable(bool value) = 0;

            // CH: 标准差范围 | EN: SD Range
            __declspec(property(put = SetC3StdLimitLow, get = GetC3StdLimitLow)) double C3StdLimitLow;

            virtual double GetC3StdLimitLow() = 0;

            virtual void SetC3StdLimitLow(double value) = 0;

            // CH: 标准差范围 | EN: SD Range
            __declspec(property(put = SetC3StdLimitHigh, get = GetC3StdLimitHigh)) double C3StdLimitHigh;

            virtual double GetC3StdLimitHigh() = 0;

            virtual void SetC3StdLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        // 直方图BIN数目上限
        const int MVD_COLOR_MAX_HIST_BIN_NUM = 256;
        
        /*  Note: 颜色测量直方图信息描述类.  */
        class IColorMeasureHistInfo
        {
        protected:
            ///< 构造与析构函数
            explicit IColorMeasureHistInfo() {}
            virtual ~IColorMeasureHistInfo() {}

        public:
           /**
            * @par 说明
            * 获取bin数目
            * @par 权限
            * 只读
            */
            virtual int GetBinNum() = 0;
            /**
             * @par 说明
             * 获取直方图数据
             * @par 权限
             * 只读
             */
            virtual void GetHistData(int pnHistData[MVD_COLOR_MAX_HIST_BIN_NUM]) = 0;
            /**
             * @par 说明
             * 获取最小值
             * @par 权限
             * 只读
             */
            virtual int GetMinVal() = 0;
            /**
             * @par 说明
             * 获取最大值
             * @par 权限
             * 只读
             */
            virtual int GetMaxVal() = 0;
            /**
             * @par 说明
             * 获取均值
             * @par 权限
             * 只读
             */
            virtual float GetMeanVal() = 0;
            /**
             * @par 说明
             * 获取标准差
             * @par 权限
             * 只读
             */
            virtual float GetStandardDeviation() = 0;
        };

        /*  Note: Interface Classes of the result of the ColorMeasureResults.  */
        class ColorMeasureResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ColorMeasureResults() {}
            virtual ~ColorMeasureResults() {}

        public:
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
             * 获取指定通道直方图信息
             * @param nIndex [in] 通道索引, 取值范围[0,2]
             * @par 权限
             * 只读
             */
            virtual IColorMeasureHistInfo* GetHistInfoAt(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ColorMeasure tool.  */
        class IMVSColorMeasureModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSColorMeasureModuTool() {}
            virtual ~IMVSColorMeasureModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ColorMeasureParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ColorMeasureResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSColorMeasureModuTool(IMVSColorMeasureModuTool&);
            IMVSColorMeasureModuTool& operator=(IMVSColorMeasureModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ColorMeasure.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSColorMeasureModu::IMVSColorMeasureModuTool * __stdcall GetColorMeasureToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_COLORMEASURE_H_
