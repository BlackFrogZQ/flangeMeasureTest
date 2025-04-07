/***************************************************************************************************
 * File：IVmImageFilter.h
 * Note：CH: 图像滤波模块接口声明 | En: Interface for the ImageFilter tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGEFILTER_H_
#define _IVM_IMAGEFILTER_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageFilterModu
    {        /*************************** Params Class Start ***************************/
        // CH: 图像滤波类型 | EN: Filter Type
        typedef enum _FilterTypeEnum
        {
            // CH: 高斯 | EN: Gaussian Filter
            FilterType_Gaussian = 0x1,

            // CH: 中值 | EN: LumMedian
            FilterType_Median = 0x2,

            // CH: 均值 | EN: LumMean
            FilterType_Mean = 0x3,

            // CH: 取反 | EN: Inverse Filter
            FilterType_Invert = 0x4,

            // CH: 边缘提取 | EN: Edge Extraction
            FilterType_Edge = 0x5,

        }FilterTypeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ImageFilterRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ImageFilterParams.  */
        class ImageFilterParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageFilterParams() {}
            virtual ~ImageFilterParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ImageFilterRoiManager* GetModuRoiManager() = 0;

            // CH: 图像滤波类型 | EN: Filter Type
            __declspec(property(put = SetFilterType, get = GetFilterType)) FilterTypeEnum FilterType;

            virtual FilterTypeEnum GetFilterType() = 0;

            virtual void SetFilterType(FilterTypeEnum value) = 0;

            // CH: 滤波核宽度 | EN: Filter Kernel Width
            __declspec(property(put = SetKernelWidth, get = GetKernelWidth)) int KernelWidth;

            virtual int GetKernelWidth() = 0;

            virtual void SetKernelWidth(int value) = 0;

            // CH: 滤波核高度 | EN: Filter Kernel Height
            __declspec(property(put = SetKernelHeight, get = GetKernelHeight)) int KernelHeight;

            virtual int GetKernelHeight() = 0;

            virtual void SetKernelHeight(int value) = 0;

            // CH: 高斯滤波核 | EN: Gaussian Filter Kernel
            __declspec(property(put = SetGaussKernelSize, get = GetGaussKernelSize)) int GaussKernelSize;

            virtual int GetGaussKernelSize() = 0;

            virtual void SetGaussKernelSize(int value) = 0;

            // CH: 边缘阈值范围 | EN: Edge Threshold Range
            __declspec(property(put = SetEdegLowThreshold, get = GetEdegLowThreshold)) int EdegLowThreshold;

            virtual int GetEdegLowThreshold() = 0;

            virtual void SetEdegLowThreshold(int value) = 0;

            // CH: 边缘阈值范围 | EN: Edge Threshold Range
            __declspec(property(put = SetEdegHighThreshold, get = GetEdegHighThreshold)) int EdegHighThreshold;

            virtual int GetEdegHighThreshold() = 0;

            virtual void SetEdegHighThreshold(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageFilterResults.  */
        class ImageFilterResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageFilterResults() {}
            virtual ~ImageFilterResults() {}

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
             * ROI圆弧
             * @par 权限
             * 只读
             */
             virtual Annulus GetROIAnnulus() = 0;
            /**
             * @par 说明
             * 输出图像
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutputImage() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageFilter tool.  */
        class IMVSImageFilterModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageFilterModuTool() {}
            virtual ~IMVSImageFilterModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageFilterParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageFilterResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageFilterModuTool(IMVSImageFilterModuTool&);
            IMVSImageFilterModuTool& operator=(IMVSImageFilterModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageFilter.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageFilterModu::IMVSImageFilterModuTool * __stdcall GetImageFilterToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGEFILTER_H_
