/***************************************************************************************************
* File：IVmGlobalCamera.h
* Note：CH: 全局相机模块接口声明 | En: Interface for the GlobalCameraModule tool.
*
* Version：4.3
* Date: 2021-01-13 14:43:42
***************************************************************************************************/
#ifndef _IVM_GLOBALCAMERA_H_
#define _IVM_GLOBALCAMERA_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"

namespace VisionMasterSDK
{
    namespace GlobalCameraModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 选择器 | EN: Selector
        typedef enum _GammaSelectorEnum
        {
            // USER
            GammaSelector_USER = 1,

            // SRGB
            GammaSelector_SRGB = 2,

        }GammaSelectorEnum;

        // CH: 电平类型 | EN: ElectricalLevel Type
        typedef enum _ElectricalLevelEnum
        {
            // CH: 高电平有效 | EN: Active High
            High = 1,

            // CH: 低电平有效 | EN: Active Low
            Low = 2,

        }ElectricalLevelEnum;

        typedef enum _CameraMoldEnum
        {
            /// <summary>
            /// CH: 普通相机 | EN: Common Camera
            /// </summary>
            CommonCamera = 0x1,

            /// <summary>
            /// CH: 智能相机 | EN: Smart Camera
            /// </summary>
            SmartCamera = 0x2,

            /// <summary>
            /// CH: 线阵相机 | EN: Dalsa Camera
            /// </summary>
            DalsaCamera = 0x3,

        }CameraMoldEnum;
        /*  Note: Interface Classes of the parameter of the GlobalCameraParams.  */
        class GlobalCameraParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GlobalCameraParams() {}
            virtual ~GlobalCameraParams() {}

        public:

            // CH: 图像宽度 | EN: Image Width
            __declspec(property(put = SetWidth, get = GetWidth)) int Width;

            virtual int GetWidth() = 0;

            virtual void SetWidth(int value) = 0;

            // CH: 图像高度 | EN: Image Height
            __declspec(property(put = SetHeight, get = GetHeight)) int Height;

            virtual int GetHeight() = 0;

            virtual void SetHeight(int value) = 0;

            // CH: 曝光时间 | EN: Exposure Time
            __declspec(property(put = SetExposureTime, get = GetExposureTime)) double ExposureTime;

            virtual double GetExposureTime() = 0;

            virtual void SetExposureTime(double value) = 0;

            // CH: 像素格式 | EN: Pixel Format
            __declspec(property(put = SetPixelFormat, get = GetPixelFormat)) int PixelFormat;

            virtual int GetPixelFormat() = 0;

            virtual void SetPixelFormat(int value) = 0;

            // CH: 触发源 | EN: Trigger Source
            __declspec(property(put = SetTriggerSource, get = GetTriggerSource)) int TriggerSource;

            virtual int GetTriggerSource() = 0;

            virtual void SetTriggerSource(int value) = 0;

            // CH: 触发延迟(us) | EN: Trigger Delay(us)
            __declspec(property(put = SetTriggerDelay, get = GetTriggerDelay)) double TriggerDelay;

            virtual double GetTriggerDelay() = 0;

            virtual void SetTriggerDelay(double value) = 0;

            // CH: 增益(dB) | EN: Gain(dB)
            __declspec(property(put = SetGain, get = GetGain)) double Gain;

            virtual double GetGain() = 0;

            virtual void SetGain(double value) = 0;

            // CH: Gamma使能 | EN: Gamma Enable
            __declspec(property(put = SetGammaEnable, get = GetGammaEnable)) bool GammaEnable;

            virtual bool GetGammaEnable() = 0;

            virtual void SetGammaEnable(bool value) = 0;

            // CH: 选择器 | EN: Selector
            __declspec(property(put = SetGammaSelector, get = GetGammaSelector)) GammaSelectorEnum GammaSelector;

            virtual GammaSelectorEnum GetGammaSelector() = 0;

            virtual void SetGammaSelector(GammaSelectorEnum value) = 0;

            // CH: 相机类型 | EN: Camera Type
            __declspec(property(put = SetCameraMold, get = GetCameraMold)) CameraMoldEnum CameraMold;

            virtual CameraMoldEnum GetCameraMold() = 0;

            virtual void SetCameraMold(CameraMoldEnum value) = 0;

            // CH: 电平类型 | EN: ElectricalLevel Type
            __declspec(property(put = SetElectricalLevel, get = GetElectricalLevel)) ElectricalLevelEnum ElectricalLevel;

            virtual ElectricalLevelEnum GetElectricalLevel() = 0;

            virtual void SetElectricalLevel(ElectricalLevelEnum value) = 0;

            /**
            * @brief 获取相机信息列表
            * @param 空
            * @return 相机信息列表
            * @par 注解
            */
            virtual CameraInfoList * GetCameraInfoList(void) = 0;

            /**
            * @brief 获取选择相机SN
            * @return 选择相机SN
            * @par 注解
            */
            virtual const char * GetChosenCameraSN() = 0;

            /**
            * @brief 设置选择相机SN
            * @param 选择相机SN
            * @return
            * @par 注解
            */
            virtual void SetChosenCameraSN(const char * value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the GlobalCameraResults.  */
        class GlobalCameraResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GlobalCameraResults() {}
            virtual ~GlobalCameraResults() {}

        public:

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the GlobalCameraModule tool.  */
        class GlobalCameraModuleTool
        {
        protected:
            ///< Constructor and Destructor
            explicit GlobalCameraModuleTool() {}
            virtual ~GlobalCameraModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual GlobalCameraParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual GlobalCameraResults* GetResult() = 0;

            /**
             * @par 说明
             * 判断相机是否处于连接状态
             * @par 权限
             * 只读
             */
            virtual bool bIsCameraConnect(void) = 0;

            /**
            * @par 说明
            * 保存参数到用户集1
            */
            virtual void SaveParamToUser1(void) = 0;

            /**
             * @par 说明
             * 获取出图触发流程使能状态
             */
            virtual bool GetTriggerProcessEnable() = 0;

            /**
             * @par 说明
             * 设置出图是否触发流程运行，true表示触发流程，false表示不触发流程
             */
            virtual void SetTriggerProcessEnable(bool value) = 0;

        private:
            GlobalCameraModuleTool(GlobalCameraModuleTool&);
            GlobalCameraModuleTool& operator=(GlobalCameraModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

    /*  Note: Get tool instance for GlobalCameraModule.  */
    IMVS_6000_PLATFORMSDK_API VisionMasterSDK::GlobalCameraModule::GlobalCameraModuleTool * __stdcall GetGlobalCameraToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_GLOBALCAMERA_H_
