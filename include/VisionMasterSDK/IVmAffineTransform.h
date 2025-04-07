/***************************************************************************************************
 * File：IVmAffineTransform.h
 * Note：CH: 仿射变换模块接口声明 | En: Interface for the AffineTransform tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_AFFINETRANSFORM_H_
#define _IVM_AFFINETRANSFORM_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSAffineTransformModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 仿射变换类型 | EN: Transformation Type
        typedef enum _TransformationTypeEnum
        {
            // CH: 裁剪缩放 | EN: Crop Zoom
            TransformationType_CropZoom = 0x1,

            // CH: 镜像 | EN: Mirrored
            TransformationType_Mirror = 0x2,

            // CH: 平移 | EN: Translation
            TransformationType_Translation = 0x3,

        }TransformationTypeEnum;

        // CH: 插值方法 | EN: Interpolation Mode
        typedef enum _InterpolationEnum
        {
            // CH: 最近邻 | EN: NN
            Interpolation_Neareast = 0x1,

            // CH: 双线性 | EN: Bilinear
            Interpolation_Bilinear = 0x2,

        }InterpolationEnum;

        // CH: 填充方式 | EN: Fill Mode
        typedef enum _ExtensionTypeEnum
        {
            // CH: 常数 | EN: Constant
            ExtensionType_Constant = 0x1,

            // CH: 邻近复制 | EN: Copy Nearby
            ExtensionType_Copy = 0x2,

        }ExtensionTypeEnum;

        // CH: 镜像方向 | EN: Mirror Orientation
        typedef enum _MirrorOrientationEnum
        {
            // CH: 水平 | EN: Horizontal
            MirrorOrientation_Horizontal = 0x1,

            // CH: 垂直 | EN: Vertical
            MirrorOrientation_Vertical = 0x2,

            // CH: 水平垂直 | EN: HoriAndVert
            MirrorOrientation_HoriAndVert = 0x3,

        }MirrorOrientationEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class AffineTransformRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the AffineTransformParams.  */
        class AffineTransformParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit AffineTransformParams() {}
            virtual ~AffineTransformParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual AffineTransformRoiManager* GetModuRoiManager() = 0;

            // CH: 仿射变换类型 | EN: Transformation Type
            __declspec(property(put = SetTransformationType, get = GetTransformationType)) TransformationTypeEnum TransformationType;

            virtual TransformationTypeEnum GetTransformationType() = 0;

            virtual void SetTransformationType(TransformationTypeEnum value) = 0;

            // CH: 尺度 | EN: Scale
            __declspec(property(put = SetScale, get = GetScale)) double Scale;

            virtual double GetScale() = 0;

            virtual void SetScale(double value) = 0;

            // CH: 宽高比 | EN: Aspect
            __declspec(property(put = SetAspect, get = GetAspect)) double Aspect;

            virtual double GetAspect() = 0;

            virtual void SetAspect(double value) = 0;

            // CH: 插值方法 | EN: Interpolation Mode
            __declspec(property(put = SetInterpolation, get = GetInterpolation)) InterpolationEnum Interpolation;

            virtual InterpolationEnum GetInterpolation() = 0;

            virtual void SetInterpolation(InterpolationEnum value) = 0;

            // CH: 填充方式 | EN: Fill Mode
            __declspec(property(put = SetExtensionType, get = GetExtensionType)) ExtensionTypeEnum ExtensionType;

            virtual ExtensionTypeEnum GetExtensionType() = 0;

            virtual void SetExtensionType(ExtensionTypeEnum value) = 0;

            // CH: 填充值 | EN: Fill Value
            __declspec(property(put = SetExtensionValue, get = GetExtensionValue)) int ExtensionValue;

            virtual int GetExtensionValue() = 0;

            virtual void SetExtensionValue(int value) = 0;

            // CH: 镜像方向 | EN: Mirror Orientation
            __declspec(property(put = SetMirrorOrientation, get = GetMirrorOrientation)) MirrorOrientationEnum MirrorOrientation;

            virtual MirrorOrientationEnum GetMirrorOrientation() = 0;

            virtual void SetMirrorOrientation(MirrorOrientationEnum value) = 0;

            // CH: 旋转角度 | EN: Rotation Angle
            __declspec(property(put = SetRotateAngle, get = GetRotateAngle)) double RotateAngle;

            virtual double GetRotateAngle() = 0;

            virtual void SetRotateAngle(double value) = 0;

            // CH: X移动距离 | EN: Moving distance in X
            __declspec(property(put = SetMoveXValue, get = GetMoveXValue)) int MoveXValue;

            virtual int GetMoveXValue() = 0;

            virtual void SetMoveXValue(int value) = 0;

            // CH: Y移动距离 | EN: Moving distance in Y
            __declspec(property(put = SetMoveYValue, get = GetMoveYValue)) int MoveYValue;

            virtual int GetMoveYValue() = 0;

            virtual void SetMoveYValue(int value) = 0;

            // CH: 锁定输出尺寸 | EN: Lock Output Size
            __declspec(property(put = SetLockOutputImageSize, get = GetLockOutputImageSize)) bool LockOutputImageSize;

            virtual bool GetLockOutputImageSize() = 0;

            virtual void SetLockOutputImageSize(bool value) = 0;

            // CH: 宽度 | EN: Width
            __declspec(property(put = SetWidthValue, get = GetWidthValue)) int WidthValue;

            virtual int GetWidthValue() = 0;

            virtual void SetWidthValue(int value) = 0;

            // CH: 高度 | EN: MergeBoxHeight
            __declspec(property(put = SetHeightValue, get = GetHeightValue)) int HeightValue;

            virtual int GetHeightValue() = 0;

            virtual void SetHeightValue(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the AffineTransformResults.  */
        class AffineTransformResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit AffineTransformResults() {}
            virtual ~AffineTransformResults() {}

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
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;
            /**
             * @brief 获取仿射变换后的图片
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 无
             */
            virtual ImageBaseData GetOutputImage() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the AffineTransform tool.  */
        class IMVSAffineTransformModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSAffineTransformModuTool() {}
            virtual ~IMVSAffineTransformModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual AffineTransformParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual AffineTransformResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSAffineTransformModuTool(IMVSAffineTransformModuTool&);
            IMVSAffineTransformModuTool& operator=(IMVSAffineTransformModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for AffineTransform.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSAffineTransformModu::IMVSAffineTransformModuTool * __stdcall GetAffineTransformToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_AFFINETRANSFORM_H_
