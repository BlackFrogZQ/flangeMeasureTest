/***************************************************************************************************
 * File：IVmImageMorph.h
 * Note：CH: 形态学处理模块接口声明 | En: Interface for the ImageMorph tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGEMORPH_H_
#define _IVM_IMAGEMORPH_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageMorphModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 形态学类型 | EN: Morphology Type
        typedef enum _MorphTypeEnum
        {
            // CH: 膨胀 | EN: Dilation
            MorphType_Dilate = 0x1,

            // CH: 腐蚀 | EN: Erosion
            MorphType_Erode = 0x2,

            // CH: 开 | EN: Opening
            MorphType_Open = 0x3,

            // CH: 闭 | EN: Closing
            MorphType_Close = 0x4,

        }MorphTypeEnum;

        // CH: 形态学形状 | EN: Structuring Element
        typedef enum _MorphShapeEnum
        {
            // CH: 矩形 | EN: Box
            MorphShape_Rectange = 0x0,

            // CH: 椭圆 | EN: Ellipse
            MorphShape_Ellipse = 0x1,

            // CH: 十字 | EN: Cross
            MorphShape_Crosss = 0x2,

        }MorphShapeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ImageMorphRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ImageMorphParams.  */
        class ImageMorphParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageMorphParams() {}
            virtual ~ImageMorphParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ImageMorphRoiManager* GetModuRoiManager() = 0;

            // CH: 形态学类型 | EN: Morphology Type
            __declspec(property(put = SetMorphType, get = GetMorphType)) MorphTypeEnum MorphType;

            virtual MorphTypeEnum GetMorphType() = 0;

            virtual void SetMorphType(MorphTypeEnum value) = 0;

            // CH: 形态学形状 | EN: Structuring Element
            __declspec(property(put = SetMorphShape, get = GetMorphShape)) MorphShapeEnum MorphShape;

            virtual MorphShapeEnum GetMorphShape() = 0;

            virtual void SetMorphShape(MorphShapeEnum value) = 0;

            // CH: 迭代次数 | EN: Iteration Times
            __declspec(property(put = SetMorphIterNum, get = GetMorphIterNum)) int MorphIterNum;

            virtual int GetMorphIterNum() = 0;

            virtual void SetMorphIterNum(int value) = 0;

            // CH: 核宽度 | EN: Element Width
            __declspec(property(put = SetKernelWidth, get = GetKernelWidth)) int KernelWidth;

            virtual int GetKernelWidth() = 0;

            virtual void SetKernelWidth(int value) = 0;

            // CH: 核高度 | EN: Element Height
            __declspec(property(put = SetKernelHeight, get = GetKernelHeight)) int KernelHeight;

            virtual int GetKernelHeight() = 0;

            virtual void SetKernelHeight(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageMorphResults.  */
        class ImageMorphResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageMorphResults() {}
            virtual ~ImageMorphResults() {}

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
        /*  Note: Note: This is the class for the ImageMorph tool.  */
        class IMVSImageMorphModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageMorphModuTool() {}
            virtual ~IMVSImageMorphModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageMorphParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageMorphResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageMorphModuTool(IMVSImageMorphModuTool&);
            IMVSImageMorphModuTool& operator=(IMVSImageMorphModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageMorph.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageMorphModu::IMVSImageMorphModuTool * __stdcall GetImageMorphToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGEMORPH_H_
