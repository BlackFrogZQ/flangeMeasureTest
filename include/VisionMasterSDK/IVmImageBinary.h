/***************************************************************************************************
 * File：IVmImageBinary.h
 * Note：CH: 图像二值化模块接口声明 | En: Interface for the ImageBinary tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGEBINARY_H_
#define _IVM_IMAGEBINARY_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSBinaryModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 二值化类型 | EN: Binarization Type
        typedef enum _BinaryTypeEnum
        {
            // CH: 硬阈值二值化 | EN: Hard Threshold Binarization
            BinaryType_HardThreshold = 0x1,

            // CH: 均值二值化 | EN: Mean Binarization
            BinaryType_MeanThreshold = 0x2,

            // CH: 高斯二值化 | EN: Gaussian Binarization
            BinaryType_GaussianThreshold = 0x3,

            // CH: Sauvola二值化 | EN: Sauvola Binarization
            BinaryType_Sauvola = 0x7,

            // CH: 自动 | EN: Auto
            BinaryType_OTSU = 0x4,

        }BinaryTypeEnum;

        // CH: 比较类型 | EN: Comparison Type
        typedef enum _CompareTypeEnum
        {
            // CH: 大于等于 | EN: Greater Than or Equal to
            CompareType_GreaterEq = 0x0,

            // CH: 小于等于 | EN: Less Than or Equal to
            CompareType_LessEq = 0x1,

            // CH: 等于 | EN: Equal to
            CompareType_Equal = 0x2,

            // CH: 不等于 | EN: Not Equal to
            CompareType_NotEqual = 0x3,

        }CompareTypeEnum;

        // CH: 分割类型 | EN: Segment Type
        typedef enum _SauvolaSegTypeEnum
        {
            // CH: 暗于背景 | EN: Darker Than Background
            SauvolaSegType_Dark = 0x0,

            // CH: 亮于背景 | EN: Brighter Than Bachground
            SauvolaSegType_Bright = 0x1,

        }SauvolaSegTypeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ImageBinaryRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
			virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

			// CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
			virtual void SetRoisRectangle(RectBox* pRoiValue, unsigned int nValueNum) = 0;

			// CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
			virtual void SetRoisAnnulus(Annulus* pRoiValue, unsigned int nValueNum) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ImageBinaryParams.  */
        class ImageBinaryParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageBinaryParams() {}
            virtual ~ImageBinaryParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ImageBinaryRoiManager* GetModuRoiManager() = 0;

            // CH: 二值化类型 | EN: Binarization Type
            __declspec(property(put = SetBinaryType, get = GetBinaryType)) BinaryTypeEnum BinaryType;

            virtual BinaryTypeEnum GetBinaryType() = 0;

            virtual void SetBinaryType(BinaryTypeEnum value) = 0;

            // CH: 低阈值 | EN: Low Threshold
            __declspec(property(put = SetLowThreshold, get = GetLowThreshold)) int LowThreshold;

            virtual int GetLowThreshold() = 0;

            virtual void SetLowThreshold(int value) = 0;

            // CH: 高阈值 | EN: High Threshold
            __declspec(property(put = SetHighThreshold, get = GetHighThreshold)) int HighThreshold;

            virtual int GetHighThreshold() = 0;

            virtual void SetHighThreshold(int value) = 0;

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

            // CH: 高斯标准差 | EN: Gaussian Standard Deviation
            __declspec(property(put = SetGaussSigma, get = GetGaussSigma)) double GaussSigma;

            virtual double GetGaussSigma() = 0;

            virtual void SetGaussSigma(double value) = 0;

            // CH: 比较类型 | EN: Comparison Type
            __declspec(property(put = SetCompareType, get = GetCompareType)) CompareTypeEnum CompareType;

            virtual CompareTypeEnum GetCompareType() = 0;

            virtual void SetCompareType(CompareTypeEnum value) = 0;

            // CH: 阈值偏移量 | EN: Threshold Offset
            __declspec(property(put = SetThresholdOffset, get = GetThresholdOffset)) int ThresholdOffset;

            virtual int GetThresholdOffset() = 0;

            virtual void SetThresholdOffset(int value) = 0;

            // CH: 校正系数(精度为0.001) | EN: Adjust Coefficient(Precision is 0.001)
			__declspec(property(put = SetSauvolaAdjustCoef, get = GetSauvolaAdjustCoef)) double SauvolaAdjustCoef;

			virtual double GetSauvolaAdjustCoef() = 0;

			virtual void SetSauvolaAdjustCoef(double value) = 0;

            // CH: 动态范围(精度为0.1) | EN: Range(Precision is 0.1)
			__declspec(property(put = SetSauvolaRange, get = GetSauvolaRange)) double SauvolaRange;

			virtual double GetSauvolaRange() = 0;

			virtual void SetSauvolaRange(double value) = 0;

            // CH: 分割类型 | EN: Segment Type
            __declspec(property(put = SetSauvolaSegType, get = GetSauvolaSegType)) SauvolaSegTypeEnum SauvolaSegType;

            virtual SauvolaSegTypeEnum GetSauvolaSegType() = 0;

            virtual void SetSauvolaSegType(SauvolaSegTypeEnum value) = 0;

            // CH: 滤波核宽度 | EN: Filter Kernel Width
            __declspec(property(put = SetSauvolaWinWidth, get = GetSauvolaWinWidth)) int SauvolaWinWidth;

            virtual int GetSauvolaWinWidth() = 0;

            virtual void SetSauvolaWinWidth(int value) = 0;

            // CH: 滤波核高度 | EN: Filter Kernel Height
            __declspec(property(put = SetSauvolaWinHeight, get = GetSauvolaWinHeight)) int SauvolaWinHeight;

            virtual int GetSauvolaWinHeight() = 0;

            virtual void SetSauvolaWinHeight(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageBinaryResults.  */
        class ImageBinaryResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageBinaryResults() {}
            virtual ~ImageBinaryResults() {}

        public:
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
             * 输出掩膜
             * @par 权限
             * 只读
             */
             virtual ImageBaseData GetOutputMask() = 0;

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
			 * 检测区域
			 * @par 权限
			 * 只读
			 */
			 virtual RectBox GetROI(int nIndex) = 0;
			 /**
			 * @par 说明
			 * ROI圆弧
			 * @par 权限
			 * 只读
			 */
			 virtual Annulus GetROIAnnulus(int nIndex) = 0;
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
        /*  Note: Note: This is the class for the ImageBinary tool.  */
        class IMVSBinaryModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSBinaryModuTool() {}
            virtual ~IMVSBinaryModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageBinaryParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageBinaryResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSBinaryModuTool(IMVSBinaryModuTool&);
            IMVSBinaryModuTool& operator=(IMVSBinaryModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageBinary.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSBinaryModu::IMVSBinaryModuTool * __stdcall GetImageBinaryToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGEBINARY_H_
