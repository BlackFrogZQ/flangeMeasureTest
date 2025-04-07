/***************************************************************************************************
 * File：IVmTranslationCalib.h
 * Note：CH: 平移旋转标定模块接口声明 | En: Interface for the TranslationCalib tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_TRANSLATIONCALIB_H_
#define _IVM_TRANSLATIONCALIB_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace TranslationCalibModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 标定类型 | EN: Calibration Type
        typedef enum _CalibTypeEnum
        {
            // CH: 平移标定 | EN: TransCalib
            CalibType_TransCalib = 0x0,

            // CH: 平移旋转标定 | EN: TransAndRotateCalib
            CalibType_TransAndRotateCalib = 0x1,

        }CalibTypeEnum;

        // CH: 标定点获取 | EN: Calib Points Acquisition
        typedef enum _CalibPointGetEnum
        {
            // CH: 触发获取 | EN: Trigger Acquisition
            CalibPointGet_TriggerAcquisition = 0x0,

            // CH: 手动输入 | EN: Manual Input
            CalibPointGet_ManualInput = 0x1,

        }CalibPointGetEnum;

        // CH: 相机模式 | EN: Camera Mode
        typedef enum _CameraModeEnum
        {
            // CH: 相机静止 | EN: Static Camera
            CameraMode_CameraStatic = 0x1,

            // CH: 相机运动 | EN: Dynamic Camera
            CameraMode_CameraMove = 0x3,

        }CameraModeEnum;

        // CH: 自由度 | EN: DOF
        typedef enum _HomoFreedomEnum
        {
            // CH: 缩放、旋转、纵横比、倾斜、平移及透射 | EN: Scale、Rotation、Aspect Ratio、Tilt、Translation and Transmission
            HomoFreedom_Perspective = 0x1,

            // CH: 缩放、旋转、纵横比、倾斜及平移 | EN: Scale、Rotation、Aspect Ratio、Tilt and Translation
            HomoFreedom_Affine = 0x2,

            // CH: 缩放、旋转及平移 | EN: Scale、Rotation and Translation
            HomoFreedom_Similarity = 0x3,

        }HomoFreedomEnum;

        /*  Note: Interface Classes of the parameter of the TranslationCalibParams.  */
        class TranslationCalibParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit TranslationCalibParams() {}
            virtual ~TranslationCalibParams() {}

        public:

            // CH: 图像点(仅当次执行起效) | EN: Image Point(Only valid for this execution)
            virtual void SetImagePoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 物理点(仅当次执行起效) | EN: Physical Point(Only valid for this execution)
            virtual void SetPhysicalPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 图像角度(仅当次执行起效) | EN: Image Rotate Angle(Only valid for this execution)
            virtual void SetImageRotateAngle(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 物理角度(仅当次执行起效) | EN: World Rotate Angle(Only valid for this execution)
            virtual void SetWorldRotateAngle(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 外部输入字符(仅当次执行起效) | EN: External Input Character(Only valid for this execution)
            virtual void SetTrigger(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // TeachFlag
            virtual void SetTeachFlag(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标定类型 | EN: Calibration Type
            __declspec(property(put = SetCalibType, get = GetCalibType)) CalibTypeEnum CalibType;

            virtual CalibTypeEnum GetCalibType() = 0;

            virtual void SetCalibType(CalibTypeEnum value) = 0;

            // CH: 标定点获取 | EN: Calib Points Acquisition
            __declspec(property(put = SetCalibPointGet, get = GetCalibPointGet)) CalibPointGetEnum CalibPointGet;

            virtual CalibPointGetEnum GetCalibPointGet() = 0;

            virtual void SetCalibPointGet(CalibPointGetEnum value) = 0;

            // CH: 相机模式 | EN: Camera Mode
            __declspec(property(put = SetCameraMode, get = GetCameraMode)) CameraModeEnum CameraMode;

            virtual CameraModeEnum GetCameraMode() = 0;

            virtual void SetCameraMode(CameraModeEnum value) = 0;

            // CH: 自由度 | EN: DOF
            __declspec(property(put = SetHomoFreedom, get = GetHomoFreedom)) HomoFreedomEnum HomoFreedom;

            virtual HomoFreedomEnum GetHomoFreedom() = 0;

            virtual void SetHomoFreedom(HomoFreedomEnum value) = 0;

            // CH: 平移次数 | EN: Translation Times
            __declspec(property(put = SetCalibPointTotalNum, get = GetCalibPointTotalNum)) int CalibPointTotalNum;

            virtual int GetCalibPointTotalNum() = 0;

            virtual void SetCalibPointTotalNum(int value) = 0;

            // CH: 旋转次数 | EN: Rotation Times
            __declspec(property(put = SetRotPointTotalNum, get = GetRotPointTotalNum)) int RotPointTotalNum;

            virtual int GetRotPointTotalNum() = 0;

            virtual void SetRotPointTotalNum(int value) = 0;

            // CH: 组合标定 | EN: UnionCalibEnable
            __declspec(property(put = SetUnionCalibEnable, get = GetUnionCalibEnable)) bool UnionCalibEnable;

            virtual bool GetUnionCalibEnable() = 0;

            virtual void SetUnionCalibEnable(bool value) = 0;

            // CH: 示教 | EN: Demonstration
            __declspec(property(put = SetTeachEnable, get = GetTeachEnable)) bool TeachEnable;

            virtual bool GetTeachEnable() = 0;

            virtual void SetTeachEnable(bool value) = 0;

            // CH: 更新文件 | EN: Update File
            __declspec(property(put = SetRefreshFileEnable, get = GetRefreshFileEnable)) bool RefreshFileEnable;

            virtual bool GetRefreshFileEnable() = 0;

            virtual void SetRefreshFileEnable(bool value) = 0;

            // CH: 标定文件路径 | EN: Set Calibration File Path
            __declspec(property(put = SetCalibPathName, get = GetCalibPathName)) const char* CalibPathName;

            virtual const char* GetCalibPathName() = 0;

            virtual void SetCalibPathName(const char* value) = 0;

            // CH: 清空标定点 | EN: Clear Point
            virtual int DoClearPoint() = 0;

            // CH: 生成标定文件 | EN: Create Calibration File
            virtual int DoSaveFile(IN const char * const strValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the TranslationCalibResults.  */
        class TranslationCalibResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit TranslationCalibResults() {}
            virtual ~TranslationCalibResults() {}

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
             * 标定状态
             * @par 权限
             * 只读
             */
             virtual int GetCalibStatus() = 0;

             /**
             * @par 说明
             * 坐标系左右手一致性
             * @par 权限
             * 只读
             */
             virtual int GetIsRightCoorA() = 0;

             /**
             * @par 说明
             * 当前标定点
             * @par 权限
             * 只读
             */
             virtual int GetCalibCurIndex() = 0;

             /**
             * @par 说明
             * 标定点总数
             * @par 权限
             * 只读
             */
             virtual int GetCalibTotalNum() = 0;

             /**
             * @par 说明
             * 标定图像点
             * @par 权限
             * 只读
             */
             virtual PointF GetCalibImagePoint(int nIndex) = 0;

             /**
             * @par 说明
             * 标定物理点
             * @par 权限
             * 只读
             */
             virtual PointF GetCalibPhysicalPoint(int nIndex) = 0;

             /**
             * @par 说明
             * 平移像素平均误差
             * @par 权限
             * 只读
             */
             virtual float GetTransError() = 0;

             /**
             * @par 说明
             * 旋转像素平均误差
             * @par 权限
             * 只读
             */
             virtual float GetRotError() = 0;

             /**
             * @par 说明
             * 旋转轴图像点
             * @par 权限
             * 只读
             */
             virtual PointF GetRotAxisPoint() = 0;

             /**
             * @par 说明
             * 旋转中心物理点
             * @par 权限
             * 只读
             */
             virtual PointF GetRotPhysicalPoint() = 0;

             /**
             * @par 说明
             * 角度旋转一致性
             * @par 权限
             * 只读
             */
             virtual int GetRotDirectionState() = 0;

             /**
             * @par 说明
             * 平移像素最大误差
             * @par 权限
             * 只读
             */
             virtual float GetTransEstMax() = 0;

             /**
             * @par 说明
             * 平移像素最大误差对应点数
             * @par 权限
             * 只读
             */
             virtual float GetTransErrMaxPtsNum() = 0;

             /**
             * @par 说明
             * 平移估计真实误差
             * @par 权限
             * 只读
             */
             virtual float GetTransWorldError() = 0;

             /**
             * @par 说明
             * 平移像素真实最大误差
             * @par 权限
             * 只读
             */
             virtual float GetTransErrWorldMax() = 0;

             /**
             * @par 说明
             * 旋转像素最大误差
             * @par 权限
             * 只读
             */
             virtual float GetRotErrMax() = 0;

             /**
             * @par 说明
             * 旋转像素最大误差对应点数
             * @par 权限
             * 只读
             */
             virtual int GetRotErrMaxPtsNum() = 0;

             /**
             * @par 说明
             * 旋转真实平均误差
             * @par 权限
             * 只读
             */
             virtual float GetRotWorldError() = 0;

             /**
             * @par 说明
             * 旋转真实最大误差
             * @par 权限
             * 只读
             */
             virtual float GetRotErrWorldMax() = 0;

             /**
             * @par 说明
             * 尺度
             * @par 权限
             * 只读
             */
             virtual float GetScale() = 0;

             /**
             * @par 说明
             * x偏移
             * @par 权限
             * 只读
             */
             virtual float GetDeltaX() = 0;

             /**
             * @par 说明
             * y偏移
             * @par 权限
             * 只读
             */
             virtual float GetDeltaY() = 0;

             /**
             * @par 说明
             * 旋转
             * @par 权限
             * 只读
             */
             virtual float GetRotate() = 0;

             /**
             * @par 说明
             * 倾斜量
             * @par 权限
             * 只读
             */
             virtual float GetTilt() = 0;

             /**
             * @par 说明
             *  Y方向和X方向的比例
             * @par 权限
             * 只读
             */
             virtual float GetDirectionRatio() = 0;

             /**
             * @par 说明
             * 像素精度
             * @par 权限
             * 只读
             */
             virtual float GetPixelPrecision() = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the TranslationCalib tool.  */
        class TranslationCalibModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit TranslationCalibModuTool() {}
            virtual ~TranslationCalibModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual TranslationCalibParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual TranslationCalibResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            TranslationCalibModuTool(TranslationCalibModuTool&);
            TranslationCalibModuTool& operator=(TranslationCalibModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for TranslationCalib.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::TranslationCalibModu::TranslationCalibModuTool * __stdcall GetTranslationCalibToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_TRANSLATIONCALIB_H_
