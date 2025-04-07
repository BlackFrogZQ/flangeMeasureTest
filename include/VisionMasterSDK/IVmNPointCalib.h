/***************************************************************************************************
 * File：IVmNPointCalib.h
 * Note：CH: N点标定模块接口声明 | En: Interface for the NPointCalib tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_NPOINTCALIB_H_
#define _IVM_NPOINTCALIB_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSNPointCalibModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 标定点获取 | EN: Calib Points Acquisition
        typedef enum _CalibPointGetEnum
        {
            // CH: 触发获取 | EN: Trigger Acquisition
            CalibPointGet_TriggerAcquisition = 0x0,

            // CH: 手动输入 | EN: Manual Input
            CalibPointGet_ManualInput = 0x1,

        }CalibPointGetEnum;

        // CH: 移动优先 | EN: Movement First
        typedef enum _MoveFirstTypeEnum
        {
            // CH: X优先 | EN: X First
            MoveFirstType_XFirst = 0x1,

            // CH: Y优先 | EN: Y First
            MoveFirstType_YFirst = 0x2,

        }MoveFirstTypeEnum;

        // CH: 相机模式 | EN: Camera Mode
        typedef enum _CameraModeEnum
        {
            // CH: 相机静止上相机位 | EN: Camera Stationary Up
            CameraMode_CameraStaticUp = 0x1,

            // CH: 相机静止下相机位 | EN: Camera Stationary Down
            CameraMode_CameraStaticDown = 0x2,

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

        // CH: 权重函数 | EN: Weighting Function
        typedef enum _WeightFunEnum
        {
            // CH: 最小二乘 | EN: Least Squares
            WeightFun_LeastSqure = 0x1,

            // CH: Huber | EN: Huber
            WeightFun_Huber = 0x2,

            // CH: Tukey | EN: Tukey
            WeightFun_Tukey = 0x3,

            // CH: 弃用 | EN: Obsolete
            // CH: Ransac | EN: Ransac
            WeightFun_Ransac = 0x4,

        }WeightFunEnum;

        /*  Note: Interface Classes of the parameter of the NPointCalibParams.  */
        class NPointCalibParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit NPointCalibParams() {}
            virtual ~NPointCalibParams() {}

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

            // TeachFlagInput
            virtual void SetTeachFlagInput(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标定点获取 | EN: Calib Points Acquisition
            __declspec(property(put = SetCalibPointGet, get = GetCalibPointGet)) CalibPointGetEnum CalibPointGet;

            virtual CalibPointGetEnum GetCalibPointGet() = 0;

            virtual void SetCalibPointGet(CalibPointGetEnum value) = 0;

            // CH: 平移次数 | EN: Translation Times
            __declspec(property(put = SetCalibPointTotalNum, get = GetCalibPointTotalNum)) int CalibPointTotalNum;

            virtual int GetCalibPointTotalNum() = 0;

            virtual void SetCalibPointTotalNum(int value) = 0;

            // CH: 旋转次数 | EN: Rotation Times
            __declspec(property(put = SetRotPointTotalNum, get = GetRotPointTotalNum)) int RotPointTotalNum;

            virtual int GetRotPointTotalNum() = 0;

            virtual void SetRotPointTotalNum(int value) = 0;

            // CH: 示教 | EN: Demonstration
            __declspec(property(put = SetTeachEnable, get = GetTeachEnable)) bool TeachEnable;

            virtual bool GetTeachEnable() = 0;

            virtual void SetTeachEnable(bool value) = 0;

            // CH: 外部触发字符 | EN: External Triggered Character
            __declspec(property(put = SetTeachFlag, get = GetTeachFlag)) const char* TeachFlag;

            virtual const char* GetTeachFlag() = 0;

            virtual void SetTeachFlag(const char* value) = 0;

            // CH: 基准点X | EN: InitPointX
            __declspec(property(put = SetBasePointX, get = GetBasePointX)) double BasePointX;

            virtual double GetBasePointX() = 0;

            virtual void SetBasePointX(double value) = 0;

            // CH: 基准点Y | EN: InitPointY
            __declspec(property(put = SetBasePointY, get = GetBasePointY)) double BasePointY;

            virtual double GetBasePointY() = 0;

            virtual void SetBasePointY(double value) = 0;

            // CH: 偏移X | EN: Offset X
            __declspec(property(put = SetMoveAlignX, get = GetMoveAlignX)) double MoveAlignX;

            virtual double GetMoveAlignX() = 0;

            virtual void SetMoveAlignX(double value) = 0;

            // CH: 偏移Y | EN: Offset Y
            __declspec(property(put = SetMoveAlignY, get = GetMoveAlignY)) double MoveAlignY;

            virtual double GetMoveAlignY() = 0;

            virtual void SetMoveAlignY(double value) = 0;

            // CH: 移动优先 | EN: Movement First
            __declspec(property(put = SetMoveFirstType, get = GetMoveFirstType)) MoveFirstTypeEnum MoveFirstType;

            virtual MoveFirstTypeEnum GetMoveFirstType() = 0;

            virtual void SetMoveFirstType(MoveFirstTypeEnum value) = 0;

            // CH: 换向移动次数 | EN: Commutation Number
            __declspec(property(put = SetChangeDirectionMoveTime, get = GetChangeDirectionMoveTime)) int ChangeDirectionMoveTime;

            virtual int GetChangeDirectionMoveTime() = 0;

            virtual void SetChangeDirectionMoveTime(int value) = 0;

            // CH: 基准角度 | EN: InitAngle
            __declspec(property(put = SetBaseAngle, get = GetBaseAngle)) double BaseAngle;

            virtual double GetBaseAngle() = 0;

            virtual void SetBaseAngle(double value) = 0;

            // CH: 角度偏移 | EN: Angle Offset
            __declspec(property(put = SetMoveAngle, get = GetMoveAngle)) double MoveAngle;

            virtual double GetMoveAngle() = 0;

            virtual void SetMoveAngle(double value) = 0;

            // CH: 使用相对坐标 | EN: Use Relative Coordinates
            __declspec(property(put = SetUseRelativeCoordinates, get = GetUseRelativeCoordinates)) bool UseRelativeCoordinates;

            virtual bool GetUseRelativeCoordinates() = 0;

            virtual void SetUseRelativeCoordinates(bool value) = 0;

            // CH: 标定原点 | EN: Calibration Origin
            __declspec(property(put = SetCalibOrigin, get = GetCalibOrigin)) int CalibOrigin;

            virtual int GetCalibOrigin() = 0;

            virtual void SetCalibOrigin(int value) = 0;

            // CH: 更新文件 | EN: Update File
            __declspec(property(put = SetRefreshFileEnable, get = GetRefreshFileEnable)) bool RefreshFileEnable;

            virtual bool GetRefreshFileEnable() = 0;

            virtual void SetRefreshFileEnable(bool value) = 0;

            // CH: 标定文件路径 | EN: Set Calibration File Path
            __declspec(property(put = SetCalibPathName, get = GetCalibPathName)) const char* CalibPathName;

            virtual const char* GetCalibPathName() = 0;

            virtual void SetCalibPathName(const char* value) = 0;

            // CH: 相机模式 | EN: Camera Mode
            __declspec(property(put = SetCameraMode, get = GetCameraMode)) CameraModeEnum CameraMode;

            virtual CameraModeEnum GetCameraMode() = 0;

            virtual void SetCameraMode(CameraModeEnum value) = 0;

            // CH: 自由度 | EN: DOF
            __declspec(property(put = SetHomoFreedom, get = GetHomoFreedom)) HomoFreedomEnum HomoFreedom;

            virtual HomoFreedomEnum GetHomoFreedom() = 0;

            virtual void SetHomoFreedom(HomoFreedomEnum value) = 0;

            // CH: 权重函数 | EN: Weighting Function
            __declspec(property(put = SetWeightFun, get = GetWeightFun)) WeightFunEnum WeightFun;

            virtual WeightFunEnum GetWeightFun() = 0;

            virtual void SetWeightFun(WeightFunEnum value) = 0;

            // CH: 权重系数 | EN: Weighting Coefficient
            __declspec(property(put = SetWeightFactor, get = GetWeightFactor)) int WeightFactor;

            virtual int GetWeightFactor() = 0;

            virtual void SetWeightFactor(int value) = 0;

            // CH: 距离阈值 | EN: Distance Threshold
            __declspec(property(put = SetDistThreshold, get = GetDistThreshold)) int DistThreshold;

            virtual int GetDistThreshold() = 0;

            virtual void SetDistThreshold(int value) = 0;

            // CH: 采样率 | EN: Sampling Rate
            __declspec(property(put = SetSampleRatio, get = GetSampleRatio)) int SampleRatio;

            virtual int GetSampleRatio() = 0;

            virtual void SetSampleRatio(int value) = 0;

            // CH: 清空标定点 | EN: Clear Point
            virtual int DoClearPoint() = 0;

            // CH: 生成标定文件 | EN: Create Calibration File
            virtual int DoSaveFile(IN const char * const strValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes for describing offset point calib process result information.  */
        class IOffsetPointCalibInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IOffsetPointCalibInfo() {}
            virtual ~IOffsetPointCalibInfo() {}

        public:
            /**
             * @par 说明
             * HOMO估计状态
             * @par 权限
             * 读写
             */
            virtual int GetHomoEstStatus() = 0;
            /**
             * @par 说明
             * 平移误差
             * @par 权限
             * 读写
             */
            virtual float GetOffsetError() = 0;
            /**
             * @par 说明
             * HOMO矩阵(预留)
             * @par 权限
             * 读写
             */
            virtual void GetHomoMatrix(float homoMatrix[9]) = 0;
        };

        /*  Note: Interface Classes for describing platform calib process result information.  */
        class IPlatformCalibInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IPlatformCalibInfo() {}
            virtual ~IPlatformCalibInfo() {}

        public:
            /**
             * @par 说明
             * N点标定中平移估计误差
             * @par 权限
             * 读写
             */
            virtual float GetOffsetError() = 0;
            /**
             * @par 说明
             * N点标定中旋转估计误差
             * @par 权限
             * 读写
             */
            virtual float GetRotateError() = 0;
            /**
             * @par 说明
             * 旋转中心图像坐标
             * @par 权限
             * 读写
             */
            virtual MVD_POINT_F GetRotCenterImageCoord() = 0;
            /**
             * @par 说明
             * 旋转中心物理坐标
             * @par 权限
             * 读写
             */
            virtual MVD_POINT_F GetRotCenterWorldCoord() = 0;
        };

        /*  Note: Interface Classes for describing parse homo matrix process result information.  */
        class ICalibMatrixToParamInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit ICalibMatrixToParamInfo() {}
            virtual ~ICalibMatrixToParamInfo() {}

        public:
            /**
             * @par 说明
             * 尺度
             * @par 权限
             * 读写
             */
            virtual float GetScale() = 0;
            /**
             * @par 说明
             * X偏移
             * @par 权限
             * 读写
             */
            virtual float GetOffsetX() = 0;
            /**
             * @par 说明
             * Y偏移
             * @par 权限
             * 读写
             */
            virtual float GetOffsetY() = 0;
            /**
             * @par 说明
             * 旋转角度
             * @par 权限
             * 读写
             */
            virtual float GetRotate() = 0;
            /**
             * @par 说明
             * Y方向和X方向的比例
             * @par 权限
             * 读写
             */
            virtual float GetAspect() = 0;
            /**
             * @par 说明
             * 倾斜量
             * @par 权限
             * 读写
             */
            virtual float GetSkew() = 0;
            /**
             * @par 说明
             * 像素精度
             * @par 权限
             * 读写
             */
            virtual float GetPixelPrecision() = 0;
        };

        /*  Note: Interface Classes of the result of the NPointCalibResults.  */
        class NPointCalibResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit NPointCalibResults() {}
            virtual ~NPointCalibResults() {}

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
             * 获取N点标定的结果，若旋转点个数不为0，结果为空。
             * @par 权限
             * 只读
             */
            /*  Note: offset calib result.
                if the count of rotate point is not zero, this result is NULL.  */
            virtual IOffsetPointCalibInfo* GetOffsetPointCalibInfo() = 0;
            /**
             * @par 说明
             * 获取N点标定的结果，若旋转点个数为0，结果为空。
             * @par 权限
             * 只读
             */
            virtual IPlatformCalibInfo* GetPlatformCalibInfo() = 0;
            /**
             * @par 说明
             * N点标定homo矩阵转参数
             * @par 权限
             * 只读
             */
            virtual ICalibMatrixToParamInfo* GetCalibMatrixToParamInfo() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the NPointCalib tool.  */
        class IMVSNPointCalibModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSNPointCalibModuTool() {}
            virtual ~IMVSNPointCalibModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual NPointCalibParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual NPointCalibResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSNPointCalibModuTool(IMVSNPointCalibModuTool&);
            IMVSNPointCalibModuTool& operator=(IMVSNPointCalibModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for NPointCalib.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSNPointCalibModu::IMVSNPointCalibModuTool * __stdcall GetNPointCalibToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_NPOINTCALIB_H_
