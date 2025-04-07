/***************************************************************************************************
 * File：IVmCalibTransform.h
 * Note：CH: 标定转换模块接口声明 | En: Interface for the CalibTransform tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CALIBTRANSFORM_H_
#define _IVM_CALIBTRANSFORM_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCalibTransformModu
    {        /*************************** Params Class Start ***************************/
        // CH: 坐标类型 | EN: Coord Type
        typedef enum _CoordTypeEnum
        {
            // CH: 图像坐标 | EN: Image Coord
            CoordType_ImageCoord = 0x0,

            // CH: 物理坐标 | EN: Physical Coord
            CoordType_PhysicalCoord = 0x1,

        }CoordTypeEnum;

        /*  Note: Interface Classes of the parameter of the CalibTransformParams.  */
        class CalibTransformParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CalibTransformParams() {}
            virtual ~CalibTransformParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入点(仅当次执行起效) | EN: Input Point(Only valid for this execution)
            virtual void SetInputPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 图像角度(仅当次执行起效) | EN: ImagePointA(Only valid for this execution)
            virtual void SetImagePointA(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 刷新信号(仅当次执行起效) | EN: Refresh Signal(Only valid for this execution)
            virtual void SetRefreshSignal(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标定矩阵(仅当次执行起效) | EN: Calibration Matrix(Only valid for this execution)
            virtual void SetCalibMatrix(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: (预留)标定位位姿点(仅当次执行起效) | EN: (Reserve)Input Calib Pose Point(Only valid for this execution)
            virtual void SetInputCalibPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: (预留)标定位位姿关节0角度(仅当次执行起效) | EN: (Reserve)Input Calib Pose Joint0 Angle(Only valid for this execution)
            virtual void SetCalibPoseJoint0A(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: (预留)标定位位姿关节1角度(仅当次执行起效) | EN: (Reserve)Input Calib Pose Joint1 Angle(Only valid for this execution)
            virtual void SetCalibPoseJoint1A(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: (预留)运行位位姿点(仅当次执行起效) | EN: (Reserve)Input Run Pose Point(Only valid for this execution)
            virtual void SetInputRunPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: (预留)运行位位姿关节0角度(仅当次执行起效) | EN: (Reserve)Input Run Pose Joint0 Angle(Only valid for this execution)
            virtual void SetRunPoseJoint0A(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: (预留)运行位位姿关节1角度(仅当次执行起效) | EN: (Reserve)Input Run Pose Joint1 Angle(Only valid for this execution)
            virtual void SetRunPoseJoint1A(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 坐标类型 | EN: Coord Type
            __declspec(property(put = SetCoordType, get = GetCoordType)) CoordTypeEnum CoordType;

            virtual CoordTypeEnum GetCoordType() = 0;

            virtual void SetCoordType(CoordTypeEnum value) = 0;

            // CH: 加载标定文件 | EN: Load Calibration File
            __declspec(property(put = SetLoadCalibPath, get = GetLoadCalibPath)) const char* LoadCalibPath;

            virtual const char* GetLoadCalibPath() = 0;

            virtual void SetLoadCalibPath(const char* value) = 0;

            // CH: (预留)位姿输入使能 | EN: (Reserve)Pose Input Enable
            __declspec(property(put = SetPoseInfoEnable, get = GetPoseInfoEnable)) bool PoseInfoEnable;

            virtual bool GetPoseInfoEnable() = 0;

            virtual void SetPoseInfoEnable(bool value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the CalibTransformResults.  */
        class CalibTransformResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CalibTransformResults() {}
            virtual ~CalibTransformResults() {}

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
             * 尺度
             * @par 权限
             * 只读
             */
            virtual float GetScale() = 0;
            /**
             * @par 说明
             * 输出角度
             * @param nIndex [IN] 结果数量索引
             * @par 权限
             * 读写
             */
            ///< Property
            virtual float GetAngle(int nIndex) = 0;
            /**
             * @par 说明
             * 输出坐标
             * @param nIndex [IN] 结果数量索引
             * @par 权限
             * 只读
             */
            /*  Note: Mechanical Coordinate of a point. */
            virtual MVD_POINT_F GetCoordinate(int nIndex) = 0;
            /**
             * @par 说明
             * 单像素精度
             * @par 权限
             * 只读
             */
             virtual float GetPixelScale() = 0;
             /**
              * @par 说明
              * 平移X
              * @par 权限
              * 只读
              */
             virtual float GetTranslateX() = 0;
             /**
              * @par 说明
              * 平移Y
              * @par 权限
              * 只读
              */
             virtual float GetTranslateY() = 0;
             /**
              * @par 说明
              * 旋转
              * @par 权限
              * 只读
              */
             virtual float GetRotate() = 0;
             /**
              * @par 说明
              * 斜切
              * @par 权限
              * 只读
              */
             virtual float GetSkew() = 0;
             /**
              * @par 说明
              * 宽高比
              * @par 权限
              * 只读
              */
             virtual float GetAspect() = 0;
             /**
             * @par 说明
             * 输出标定位姿坐标(预留)
             * @param nIndex [IN] 结果数量索引
             * @par 权限
             * 只读
             */
             /*  Note: Mechanical Coordinate of a point. */
             virtual MVD_POINT_F GetCalibPosePoint(int nIndex) = 0;
             /**
             * @par 说明
             * 标定位姿关节0角度(预留)
             * @par 权限
             * 只读
             */
			 virtual float GetCalibPoseJoint0A(int nIndex) = 0;
             /**
             * @par 说明
             * 标定位姿关节1角度(预留)
             * @par 权限
             * 只读
             */
			 virtual float GetCalibPoseJoint1A(int nIndex) = 0;
             /**
             * @par 说明
             * 输出运行位姿坐标(预留)
             * @param nIndex [IN] 结果数量索引
             * @par 权限
             * 只读
             */
             /*  Note: Mechanical Coordinate of a point. */
             virtual MVD_POINT_F GetRunPosePoint(int nIndex) = 0;
             /**
             * @par 说明
             * 运行位姿关节0角度(预留)
             * @par 权限
             * 只读
             */
			 virtual float GetRunPoseJoint0A(int nIndex) = 0;
             /**
             * @par 说明
             * 运行位姿关节1角度(预留)
             * @par 权限
             * 只读
             */
			 virtual float GetRunPoseJoint1A(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CalibTransform tool.  */
        class IMVSCalibTransformModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCalibTransformModuTool() {}
            virtual ~IMVSCalibTransformModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CalibTransformParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CalibTransformResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCalibTransformModuTool(IMVSCalibTransformModuTool&);
            IMVSCalibTransformModuTool& operator=(IMVSCalibTransformModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CalibTransform.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCalibTransformModu::IMVSCalibTransformModuTool * __stdcall GetCalibTransformToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CALIBTRANSFORM_H_
