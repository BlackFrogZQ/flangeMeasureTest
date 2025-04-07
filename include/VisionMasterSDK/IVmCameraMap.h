/***************************************************************************************************
 * File：IVmCameraMap.h
 * Note：CH: 相机映射模块接口声明 | En: Interface for the CameraMap tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CAMERAMAP_H_
#define _IVM_CAMERAMAP_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCameraMapModu
    {
        /*************************** Params Class Start ***************************/
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

        }WeightFunEnum;

        /*  Note: Interface Classes of the parameter of the CameraMapParams.  */
        class CameraMapParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CameraMapParams() {}
            virtual ~CameraMapParams() {}

        public:

            // CH: 目标点输入1(仅当次执行起效) | EN: TargetPointInput1(Only valid for this execution)
            virtual void SetTargetPointInput1(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入1(仅当次执行起效) | EN: ObjectPointInput1(Only valid for this execution)
            virtual void SetObjectPointInput1(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入2(仅当次执行起效) | EN: TargetPointInput2(Only valid for this execution)
            virtual void SetTargetPointInput2(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入2(仅当次执行起效) | EN: ObjectPointInput2(Only valid for this execution)
            virtual void SetObjectPointInput2(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入3(仅当次执行起效) | EN: TargetPointInput3(Only valid for this execution)
            virtual void SetTargetPointInput3(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入3(仅当次执行起效) | EN: ObjectPointInput3(Only valid for this execution)
            virtual void SetObjectPointInput3(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入4(仅当次执行起效) | EN: TargetPointInput4(Only valid for this execution)
            virtual void SetTargetPointInput4(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入4(仅当次执行起效) | EN: ObjectPointInput4(Only valid for this execution)
            virtual void SetObjectPointInput4(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入5(仅当次执行起效) | EN: TargetPointInput5(Only valid for this execution)
            virtual void SetTargetPointInput5(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入5(仅当次执行起效) | EN: ObjectPointInput5(Only valid for this execution)
            virtual void SetObjectPointInput5(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入6(仅当次执行起效) | EN: TargetPointInput6(Only valid for this execution)
            virtual void SetTargetPointInput6(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入6(仅当次执行起效) | EN: ObjectPointInput6(Only valid for this execution)
            virtual void SetObjectPointInput6(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入7(仅当次执行起效) | EN: TargetPointInput7(Only valid for this execution)
            virtual void SetTargetPointInput7(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入7(仅当次执行起效) | EN: ObjectPointInput7(Only valid for this execution)
            virtual void SetObjectPointInput7(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入8(仅当次执行起效) | EN: TargetPointInput8(Only valid for this execution)
            virtual void SetTargetPointInput8(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入8(仅当次执行起效) | EN: ObjectPointInput8(Only valid for this execution)
            virtual void SetObjectPointInput8(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标定文件路径 | EN: Set Calibration File Path
            __declspec(property(put = SetCalibPathName, get = GetCalibPathName)) const char* CalibPathName;

            virtual const char* GetCalibPathName() = 0;

            virtual void SetCalibPathName(const char* value) = 0;

            // CH: 更新文件 | EN: Update File
            __declspec(property(put = SetRefreshFileEnable, get = GetRefreshFileEnable)) bool RefreshFileEnable;

            virtual bool GetRefreshFileEnable() = 0;

            virtual void SetRefreshFileEnable(bool value) = 0;

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

            // CH: 生成标定文件 | EN: Create Calibration File
            virtual int DoSaveFile(IN const char * const strValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the CameraMapResults.  */
        class CameraMapResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CameraMapResults() {}
            virtual ~CameraMapResults() {}

        public:
            ///< properties
            /**
             * @par 说明
             * X方向比例
             * @par 权限
             * 只读
             */
            /*  Note: ratioX of camera map. */
            virtual float GetRatioX() = 0;
            /**
             * @par 说明
             * Y方向比例
             * @par 权限
             * 只读
             */
            /*  Note: ratioY of camera map. */
            virtual float GetRatioY() = 0;
            /**
             * @par 说明
             * 相机对位的HOMO矩阵
             * @par 权限
             * 只读
             */
            /*  Note: homo matrix of camera map. */
            virtual void GetTargetMatrix(float arrMatrix[9]) = 0;
            /**
             * @par 说明
             * 标定状态
             * @par 权限
             * 只读
             */
            /*  Note: ratioY of camera map. */
            virtual int GetCalibStatus() = 0;
            /**
             * @par 说明
             * 平移X
             * @par 权限
             * 只读
             */
            /*  Note: ratioY of camera map. */
            virtual float GetTranslateX() = 0;
            /**
             * @par 说明
             * 平移Y
             * @par 权限
             * 只读
             */
            /*  Note: ratioY of camera map. */
            virtual float GetTranslateY() = 0;
            /**
             * @par 说明
             * 旋转
             * @par 权限
             * 只读
             */
            /*  Note: ratioY of camera map. */
            virtual float GetRotate() = 0;
            /**
             * @par 说明
             * 尺度
             * @par 权限
             * 只读
             */
            /*  Note: ratioY of camera map. */
            virtual float GetScale() = 0;
            /**
             * @par 说明
             * 斜切
             * @par 权限
             * 只读
             */
            /*  Note: ratioY of camera map. */
            virtual float GetSkew() = 0;
            /**
             * @par 说明
             * 宽高比
             * @par 权限
             * 只读
             */
            /*  Note: ratioY of camera map. */
            virtual float GetAspect() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CameraMap tool.  */
        class IMVSCameraMapModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCameraMapModuTool() {}
            virtual ~IMVSCameraMapModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CameraMapParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CameraMapResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCameraMapModuTool(IMVSCameraMapModuTool&);
            IMVSCameraMapModuTool& operator=(IMVSCameraMapModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CameraMap.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCameraMapModu::IMVSCameraMapModuTool * __stdcall GetCameraMapToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CAMERAMAP_H_
