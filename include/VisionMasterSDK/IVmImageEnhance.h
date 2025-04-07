/***************************************************************************************************
 * File：IVmImageEnhance.h
 * Note：CH: 图像增强模块接口声明 | En: Interface for the ImageEnhance tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGEENHANCE_H_
#define _IVM_IMAGEENHANCE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageEnhanceModu
    {        /*************************** Params Class Start ***************************/
        // CH: 图像增强类型 | EN: Image Enhancement Type
        typedef enum _EnhanceTypeEnum
        {
            // CH: 锐化 | EN: Sharpness
            EnhanceType_Sharpen = 0x1,

            // CH: 对比度 | EN: HistContrast
            EnhanceType_Contrast = 0x2,

            // CH: Gamma | EN: Gamma
            EnhanceType_Gamma = 0x3,

            // CH: 亮度校正 | EN: Brightness
            EnhanceType_BrightAdhust = 0x4,

        }EnhanceTypeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ImageEnhanceRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ImageEnhanceParams.  */
        class ImageEnhanceParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageEnhanceParams() {}
            virtual ~ImageEnhanceParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ImageEnhanceRoiManager* GetModuRoiManager() = 0;

            // CH: 图像增强类型 | EN: Image Enhancement Type
            __declspec(property(put = SetEnhanceType, get = GetEnhanceType)) EnhanceTypeEnum EnhanceType;

            virtual EnhanceTypeEnum GetEnhanceType() = 0;

            virtual void SetEnhanceType(EnhanceTypeEnum value) = 0;

            // CH: 锐化强度 | EN: Sharpen Intensity
            __declspec(property(put = SetSharpenStrength, get = GetSharpenStrength)) int SharpenStrength;

            virtual int GetSharpenStrength() = 0;

            virtual void SetSharpenStrength(int value) = 0;

            // CH: 锐化核大小 | EN: Kernel Size
            __declspec(property(put = SetSharpenKernelSize, get = GetSharpenKernelSize)) int SharpenKernelSize;

            virtual int GetSharpenKernelSize() = 0;

            virtual void SetSharpenKernelSize(int value) = 0;

            // CH: 对比度系数 | EN: Contrast Coefficient
            __declspec(property(put = SetContrastFactor, get = GetContrastFactor)) int ContrastFactor;

            virtual int GetContrastFactor() = 0;

            virtual void SetContrastFactor(int value) = 0;

            // CH: Gamma | EN: Gamma
            __declspec(property(put = SetGammaVal, get = GetGammaVal)) double GammaVal;

            virtual double GetGammaVal() = 0;

            virtual void SetGammaVal(double value) = 0;

            // CH: 增益 | EN: Gain
            __declspec(property(put = SetBrightGain, get = GetBrightGain)) int BrightGain;

            virtual int GetBrightGain() = 0;

            virtual void SetBrightGain(int value) = 0;

            // CH: 亮度校正补偿 | EN: Compensation
            __declspec(property(put = SetBrightOffset, get = GetBrightOffset)) int BrightOffset;

            virtual int GetBrightOffset() = 0;

            virtual void SetBrightOffset(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageEnhanceResults.  */
        class ImageEnhanceResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageEnhanceResults() {}
            virtual ~ImageEnhanceResults() {}

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
        /*  Note: Note: This is the class for the ImageEnhance tool.  */
        class IMVSImageEnhanceModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageEnhanceModuTool() {}
            virtual ~IMVSImageEnhanceModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageEnhanceParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageEnhanceResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageEnhanceModuTool(IMVSImageEnhanceModuTool&);
            IMVSImageEnhanceModuTool& operator=(IMVSImageEnhanceModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageEnhance.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageEnhanceModu::IMVSImageEnhanceModuTool * __stdcall GetImageEnhanceToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGEENHANCE_H_
