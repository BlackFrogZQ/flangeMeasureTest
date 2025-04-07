/***************************************************************************************************
 * File：IVmPolarUnwarp.h
 * Note：CH: 圆环展开模块接口声明 | En: Interface for the PolarUnwarp tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_POLARUNWARP_H_
#define _IVM_POLARUNWARP_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSPolarUnwarpModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 角度方向 | EN: Angle Direction
        typedef enum _AngleDirTypeEnum
        {
            // CH: 逆时针 | EN: Anticlockwise
            AngleDirType_AntiClockWise = 0x1,

            // CH: 顺时针 | EN: Clockwise
            AngleDirType_ClockWise = 0x2,

        }AngleDirTypeEnum;

        // CH: 半径方向 | EN: Radius Orientation
        typedef enum _RadiusDirTypeEnum
        {
            // CH: 从内往外 | EN: Outward
            RadiusDirType_InnerToOuter = 0x1,

            // CH: 从外往内 | EN: Inward
            RadiusDirType_OuterToInner = 0x2,

        }RadiusDirTypeEnum;

        // CH: 插值方法 | EN: Interpolation Mode
        typedef enum _InterpolationEnum
        {
            // CH: 最近邻 | EN: NN
            Interpolation_Neareast = 0x1,

            // CH: 双线性 | EN: Bilinear
            Interpolation_Bilinear = 0x2,

        }InterpolationEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class PolarUnwarpRoiManager
        {
        public:

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the PolarUnwarpParams.  */
        class PolarUnwarpParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit PolarUnwarpParams() {}
            virtual ~PolarUnwarpParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual PolarUnwarpRoiManager* GetModuRoiManager() = 0;

            // CH: 角度方向 | EN: Angle Direction
            __declspec(property(put = SetAngleDirType, get = GetAngleDirType)) AngleDirTypeEnum AngleDirType;

            virtual AngleDirTypeEnum GetAngleDirType() = 0;

            virtual void SetAngleDirType(AngleDirTypeEnum value) = 0;

            // CH: 半径方向 | EN: Radius Orientation
            __declspec(property(put = SetRadiusDirType, get = GetRadiusDirType)) RadiusDirTypeEnum RadiusDirType;

            virtual RadiusDirTypeEnum GetRadiusDirType() = 0;

            virtual void SetRadiusDirType(RadiusDirTypeEnum value) = 0;

            // CH: 插值方法 | EN: Interpolation Mode
            __declspec(property(put = SetInterpolation, get = GetInterpolation)) InterpolationEnum Interpolation;

            virtual InterpolationEnum GetInterpolation() = 0;

            virtual void SetInterpolation(InterpolationEnum value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the PolarUnwarpResults.  */
        class PolarUnwarpResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit PolarUnwarpResults() {}
            virtual ~PolarUnwarpResults() {}

        public:
             /**
             * @par 说明
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;

             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
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
        /*  Note: Note: This is the class for the PolarUnwarp tool.  */
        class IMVSPolarUnwarpModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSPolarUnwarpModuTool() {}
            virtual ~IMVSPolarUnwarpModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual PolarUnwarpParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual PolarUnwarpResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSPolarUnwarpModuTool(IMVSPolarUnwarpModuTool&);
            IMVSPolarUnwarpModuTool& operator=(IMVSPolarUnwarpModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for PolarUnwarp.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSPolarUnwarpModu::IMVSPolarUnwarpModuTool * __stdcall GetPolarUnwarpToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_POLARUNWARP_H_
