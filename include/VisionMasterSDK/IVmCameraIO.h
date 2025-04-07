/***************************************************************************************************
 * File：IVmCameraIO.h
 * Note：CH: 相机IO通信模块接口声明 | En: Interface for the CameraIO tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CAMERAIO_H_
#define _IVM_CAMERAIO_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace CameraIOModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 相机类型 | EN: Camera Type
        typedef enum _CameraTypeEnum
        {
            // CH: 普通相机 | EN: CommonCamera
            CameraType_CommonCamera = 0x1,

            // CH: 智能相机 | EN: SmartCamera
            CameraType_SmartCamera = 2,

            // CH: 线阵相机 | EN: Dalsa Camera
            CameraType_DalsaCamera = 3,

        }CameraTypeEnum;

        // CH: 有效电平 | EN: Active Level
        typedef enum _IOEnableElectricalLevelEnum
        {
            // CH: 高电平有效 | EN: Active High
            IOEnableElectricalLevel_High = 0x1,

            // CH: 低电平有效 | EN: Active Low
            IOEnableElectricalLevel_Low = 2,

        }IOEnableElectricalLevelEnum;

        // CH: 输出类型 | EN: Output Type
        typedef enum _IOOutTypeEnum
        {
            // CH: OK时输出 | EN: Output when OK
            IOOutType_Ok = 0x1,

            // CH: NG时输出 | EN: Output when NG
            IOOutType_Ng = 2,

        }IOOutTypeEnum;

        /*  Note: Interface Classes of the parameter of the CameraIOParams.  */
        class CameraIOParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CameraIOParams() {}
            virtual ~CameraIOParams() {}

        public:

            // CH: 相机类型 | EN: Camera Type
            __declspec(property(put = SetCameraType, get = GetCameraType)) CameraTypeEnum CameraType;

            virtual CameraTypeEnum GetCameraType() = 0;

            virtual void SetCameraType(CameraTypeEnum value) = 0;

            // CH: 持续时间使能 | EN: DurationTimeEnable
            __declspec(property(put = SetDurationTimeEnable, get = GetDurationTimeEnable)) bool DurationTimeEnable;

            virtual bool GetDurationTimeEnable() = 0;

            virtual void SetDurationTimeEnable(bool value) = 0;

            // CH: 持续时间 | EN: Duration
            __declspec(property(put = SetIODurationTime, get = GetIODurationTime)) int IODurationTime;

            virtual int GetIODurationTime() = 0;

            virtual void SetIODurationTime(int value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: 有效电平 | EN: Active Level
            __declspec(property(put = SetIOEnableElectricalLevel, get = GetIOEnableElectricalLevel)) IOEnableElectricalLevelEnum IOEnableElectricalLevel;

            virtual IOEnableElectricalLevelEnum GetIOEnableElectricalLevel() = 0;

            virtual void SetIOEnableElectricalLevel(IOEnableElectricalLevelEnum value) = 0;

            // CH: 输出类型 | EN: Output Type
            __declspec(property(put = SetIOOutType, get = GetIOOutType)) IOOutTypeEnum IOOutType;

            virtual IOOutTypeEnum GetIOOutType() = 0;

            virtual void SetIOOutType(IOOutTypeEnum value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the CameraIOResults.  */
        class CameraIOResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CameraIOResults() {}
            virtual ~CameraIOResults() {}

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
             * 通信结果
             * @par 权限
             * 只读
             */
            virtual const char * GetStrResult() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CameraIO tool.  */
        class CameraIOModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CameraIOModuleTool() {}
            virtual ~CameraIOModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CameraIOParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CameraIOResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            CameraIOModuleTool(CameraIOModuleTool&);
            CameraIOModuleTool& operator=(CameraIOModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CameraIO.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::CameraIOModule::CameraIOModuleTool * __stdcall GetCameraIOToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CAMERAIO_H_
