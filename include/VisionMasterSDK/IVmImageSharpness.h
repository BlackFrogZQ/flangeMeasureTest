/***************************************************************************************************
 * File：IVmImageSharpness.h
 * Note：CH: 清晰度评估模块接口声明 | En: Interface for the ImageSharpness tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGESHARPNESS_H_
#define _IVM_IMAGESHARPNESS_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageSharpnessModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 评价模式 | EN: Assess Mode
        typedef enum _SharpnessModeEnum
        {
            // CH: 自相关 | EN: Autocorrelation
            SharpnessMode_AutoCoreeMode = 0x1,

            // CH: 梯度平方 | EN: Gradient Square
            SharpnessMode_SquaredGrad = 0x2,

        }SharpnessModeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ImageSharpnessRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ImageSharpnessParams.  */
        class ImageSharpnessParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageSharpnessParams() {}
            virtual ~ImageSharpnessParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ImageSharpnessRoiManager* GetModuRoiManager() = 0;

            // CH: 评价模式 | EN: Assess Mode
            __declspec(property(put = SetSharpnessMode, get = GetSharpnessMode)) SharpnessModeEnum SharpnessMode;

            virtual SharpnessModeEnum GetSharpnessMode() = 0;

            virtual void SetSharpnessMode(SharpnessModeEnum value) = 0;

            // CH: 噪声等级 | EN: Noise Level
            __declspec(property(put = SetNoiseLevel, get = GetNoiseLevel)) int NoiseLevel;

            virtual int GetNoiseLevel() = 0;

            virtual void SetNoiseLevel(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageSharpnessResults.  */
        class ImageSharpnessResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageSharpnessResults() {}
            virtual ~ImageSharpnessResults() {}

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
             * 图像清晰度分数 
             * @par 权限
             * 只读
             */
            virtual float GetSharpness() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageSharpness tool.  */
        class IMVSImageSharpnessModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageSharpnessModuTool() {}
            virtual ~IMVSImageSharpnessModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageSharpnessParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageSharpnessResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageSharpnessModuTool(IMVSImageSharpnessModuTool&);
            IMVSImageSharpnessModuTool& operator=(IMVSImageSharpnessModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageSharpness.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageSharpnessModu::IMVSImageSharpnessModuTool * __stdcall GetImageSharpnessToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGESHARPNESS_H_
