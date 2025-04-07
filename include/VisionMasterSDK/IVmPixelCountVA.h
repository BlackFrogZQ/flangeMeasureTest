/***************************************************************************************************
 * File：IVmPixelCountVA.h
 * Note：CH: 像素统计模块接口声明 | En: Interface for the PixelCountVA tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_PIXELCOUNTVA_H_
#define _IVM_PIXELCOUNTVA_H_

#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSPixelCountModuVA
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class PixelCountVARoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ThresholdRangeItemParam.  */
        class ThresholdRangeItemParam
        {
        protected:
            ///< Constructor and Destructor
            explicit ThresholdRangeItemParam() {}
            virtual ~ThresholdRangeItemParam() {}

        public:

            // CH: 最大值 | EN: Max Value
            __declspec(property(put = SetMaxValue, get = GetMaxValue)) int MaxValue;

            virtual int GetMaxValue() = 0;

            virtual void SetMaxValue(int value) = 0;

            // CH: 最小值 | EN: Min Value
            __declspec(property(put = SetMinValue, get = GetMinValue)) int MinValue;

            virtual int GetMinValue() = 0;

            virtual void SetMinValue(int value) = 0;
        };

        /*  Note: Interface Classes of the parameter of the PixelCountVAParams.  */
        class PixelCountVAParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit PixelCountVAParams() {}
            virtual ~PixelCountVAParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual PixelCountVARoiManager* GetModuRoiManager() = 0;

            // CH: 数量判断 | EN: Quantity Check
            __declspec(property(put = SetCountLimitEnable, get = GetCountLimitEnable)) bool CountLimitEnable;

            virtual bool GetCountLimitEnable() = 0;

            virtual void SetCountLimitEnable(bool value) = 0;

            // CH: 数量范围 | EN: Quantity Range
            __declspec(property(put = SetCountLimitLow, get = GetCountLimitLow)) int CountLimitLow;

            virtual int GetCountLimitLow() = 0;

            virtual void SetCountLimitLow(int value) = 0;

            // CH: 数量范围 | EN: Quantity Range
            __declspec(property(put = SetCountLimitHigh, get = GetCountLimitHigh)) int CountLimitHigh;

            virtual int GetCountLimitHigh() = 0;

            virtual void SetCountLimitHigh(int value) = 0;

            // CH: 比率判断 | EN: Ratio Check
            __declspec(property(put = SetRatioLimitEnable, get = GetRatioLimitEnable)) bool RatioLimitEnable;

            virtual bool GetRatioLimitEnable() = 0;

            virtual void SetRatioLimitEnable(bool value) = 0;

            // RunParam_Ratio Range
            __declspec(property(put = SetRatioLimitLow, get = GetRatioLimitLow)) double RatioLimitLow;

            virtual double GetRatioLimitLow() = 0;

            virtual void SetRatioLimitLow(double value) = 0;

            // RunParam_Ratio Range
            __declspec(property(put = SetRatioLimitHigh, get = GetRatioLimitHigh)) double RatioLimitHigh;

            virtual double GetRatioLimitHigh() = 0;

            virtual void SetRatioLimitHigh(double value) = 0;

            // CH: CH: 根据索引名称获取阈值范围动态参数项(最大值/最小值等)(单例模式) | EN: Get Threshold Range Dynamic Parameter Items By Index Name(Max Value/Min Value)(Singleton Pattern)
            // CH: 参数名称为阈值范围下的序号, 如"0" | EN: Parameters Name Is The Sequence Number Under The Threshold Range, Such As "0"
            virtual ThresholdRangeItemParam * GetThresholdRangeItemParam(const char * const strName) = 0;
        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the PixelCountVAResults.  */
        class PixelCountVAResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit PixelCountVAResults() {}
            virtual ~PixelCountVAResults() {}

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
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;

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
			 * 像素数量
			 * @par 权限
			 * 只读
			 */
			 virtual int GetCount(int nIndex) = 0;

			 /**
			 * @par 说明
			 * 比率
			 * @par 权限
			 * 只读
			 */
			 virtual float GetRatio(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the PixelCountVA tool.  */
        class IMVSPixelCountModuVATool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSPixelCountModuVATool() {}
            virtual ~IMVSPixelCountModuVATool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual PixelCountVAParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual PixelCountVAResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSPixelCountModuVATool(IMVSPixelCountModuVATool&);
            IMVSPixelCountModuVATool& operator=(IMVSPixelCountModuVATool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for PixelCountVA.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSPixelCountModuVA::IMVSPixelCountModuVATool * __stdcall GetPixelCountVAToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_PIXELCOUNTVA_H_
