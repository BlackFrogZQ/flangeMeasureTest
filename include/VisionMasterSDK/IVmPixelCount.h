/***************************************************************************************************
 * File：IVmPixelCount.h
 * Note：CH: 像素统计模块接口声明 | En: Interface for the PixelCount tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_PIXELCOUNT_H_
#define _IVM_PIXELCOUNT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSPixelCountModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class PixelCountRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the PixelCountParams.  */
        class PixelCountParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit PixelCountParams() {}
            virtual ~PixelCountParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual PixelCountRoiManager* GetModuRoiManager() = 0;

            // CH: 低阈值 | EN: Low Threshold
            __declspec(property(put = SetLowThresh, get = GetLowThresh)) int LowThresh;

            virtual int GetLowThresh() = 0;

            virtual void SetLowThresh(int value) = 0;

            // CH: 高阈值 | EN: High Threshold
            __declspec(property(put = SetHighThresh, get = GetHighThresh)) int HighThresh;

            virtual int GetHighThresh() = 0;

            virtual void SetHighThresh(int value) = 0;

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

            // CH: 比率范围 | EN: Ratio Range
            __declspec(property(put = SetRatioLimitLow, get = GetRatioLimitLow)) double RatioLimitLow;

            virtual double GetRatioLimitLow() = 0;

            virtual void SetRatioLimitLow(double value) = 0;

            // CH: 比率范围 | EN: Ratio Range
            __declspec(property(put = SetRatioLimitHigh, get = GetRatioLimitHigh)) double RatioLimitHigh;

            virtual double GetRatioLimitHigh() = 0;

            virtual void SetRatioLimitHigh(double value) = 0;

            // CH: 输出图像 | EN: Output Image
            __declspec(property(put = SetBinaryEnable, get = GetBinaryEnable)) bool BinaryEnable;

            virtual bool GetBinaryEnable() = 0;

            virtual void SetBinaryEnable(bool value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the PixelCountResults.  */
        class PixelCountResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit PixelCountResults() {}
            virtual ~PixelCountResults() {}

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
             * 输出图像
             * @par 权限
             * 只读
             */
             virtual ImageBaseData GetOutputImage() = 0;

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
             * 像素个数
             * @par 权限
             * 读写
             */
            virtual int GetPixelCount() = 0;
            /**
             * @par 说明
             * 比率
             * @par 权限
             * 读写
             */
            virtual float GetRatio() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the PixelCount tool.  */
        class IMVSPixelCountModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSPixelCountModuTool() {}
            virtual ~IMVSPixelCountModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual PixelCountParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual PixelCountResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSPixelCountModuTool(IMVSPixelCountModuTool&);
            IMVSPixelCountModuTool& operator=(IMVSPixelCountModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for PixelCount.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSPixelCountModu::IMVSPixelCountModuTool * __stdcall GetPixelCountToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_PIXELCOUNT_H_
