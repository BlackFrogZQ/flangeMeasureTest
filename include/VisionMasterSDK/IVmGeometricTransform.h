/***************************************************************************************************
 * File：IVmGeometricTransform.h
 * Note：CH: 几何变换模块接口声明 | En: Interface for the GeometricTransform tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_GEOMETRICTRANSFORM_H_
#define _IVM_GEOMETRICTRANSFORM_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSGeometricTransformModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 镜像方向 | EN: Mirror Orientation
        typedef enum _MirrorOrientationEnum
        {
            // CH: 无 | EN: NoMirror
            MirrorOrientation_NoMirror = 0x0,

            // CH: 水平 | EN: Horizontal
            MirrorOrientation_Horizontal = 0x1,

            // CH: 垂直 | EN: Vertical
            MirrorOrientation_Vertical = 0x2,

            // CH: 水平垂直 | EN: HoriAndVert
            MirrorOrientation_HoriAndVert = 0x3,

        }MirrorOrientationEnum;

        // CH: 旋转角度 | EN: Rotation Angle
        typedef enum _RotateAngleEnum
        {
            // CH: 0 | EN: 0
            RotateAngle_ZeroQuarter = 0x0,

            // CH: 90 | EN: 90
            RotateAngle_OneQuarter = 0x1,

            // CH: 180 | EN: 180
            RotateAngle_TwoQuarter = 0x2,

            // CH: 270 | EN: 270
            RotateAngle_ThreeQuarter = 0x3,

        }RotateAngleEnum;

        /*  Note: Interface Classes of the parameter of the GeometricTransformParams.  */
        class GeometricTransformParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GeometricTransformParams() {}
            virtual ~GeometricTransformParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 镜像方向 | EN: Mirror Orientation
            __declspec(property(put = SetMirrorOrientation, get = GetMirrorOrientation)) MirrorOrientationEnum MirrorOrientation;

            virtual MirrorOrientationEnum GetMirrorOrientation() = 0;

            virtual void SetMirrorOrientation(MirrorOrientationEnum value) = 0;

            // CH: 旋转角度 | EN: Rotation Angle
            __declspec(property(put = SetRotateAngle, get = GetRotateAngle)) RotateAngleEnum RotateAngle;

            virtual RotateAngleEnum GetRotateAngle() = 0;

            virtual void SetRotateAngle(RotateAngleEnum value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the GeometricTransformResults.  */
        class GeometricTransformResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GeometricTransformResults() {}
            virtual ~GeometricTransformResults() {}

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
             * 获取输出图像
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutputImage() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the GeometricTransform tool.  */
        class IMVSGeometricTransformModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSGeometricTransformModuTool() {}
            virtual ~IMVSGeometricTransformModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual GeometricTransformParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual GeometricTransformResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSGeometricTransformModuTool(IMVSGeometricTransformModuTool&);
            IMVSGeometricTransformModuTool& operator=(IMVSGeometricTransformModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for GeometricTransform.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSGeometricTransformModu::IMVSGeometricTransformModuTool * __stdcall GetGeometricTransformToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_GEOMETRICTRANSFORM_H_
