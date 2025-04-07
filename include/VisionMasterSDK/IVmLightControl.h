/***************************************************************************************************
* File：IVmLightControl.h
* Note：CH: 光源控制模块接口声明 | En: Interface for the LightControl tool.
*
* Version：4.3
* Date: 2021-01-13 14:43:42
***************************************************************************************************/
#ifndef _IVM_LIGHTCONTROL_H_
#define _IVM_LIGHTCONTROL_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"

namespace VisionMasterSDK
{
    namespace LightControlModule
    {
        // 设备类型
        typedef enum DeviceTypeEnum_
        {
            TYPE_NONE             =  0,
            TYPE_LIGHT_CONTROLLER =  1,
            TYPE_VB2200           =  2,
            TYPE_VC4000           =  3,
            TYPE_VC3000_LIGHT     =  4,
            TYPE_VC3000_IO        =  5,
            TYPE_VC3000_GPIO      =  6,
        }DeviceTypeEnum;

        // 沿定义,用户表示输入信号的触发
        typedef enum TriggerEdgeEnum_
        {
            MV_IO_EDGE_UNKNOW  = 0x00,
            MV_IO_EDGE_RISING  = 0x01,        // 上升沿
            MV_IO_EDGE_FALLING = 0x02,        // 下降沿
        } TriggerEdgeEnum;

        // 光源常亮常灭
        typedef enum LightStateEnum_
        {
            MV_IO_LIGHTSTATE_ON  = 0x0001,     // 触发后常亮
            MV_IO_LIGHTSTATE_OFF = 0x0002,     // 触发后常灭
        } LightStateEnum;

        // 光源控制信息结构
        typedef struct LightChannelInfo_
        {
            int  nChannelIndex;    // 通道序号
            bool bChannelEnable;   // 通道使能
            int  nLightBrightness; // 通道亮度
            int  nLightState;      // 光源状态常亮常灭 常灭1，常亮2
            int  nTriggerEdge;     // 沿定义 （硬触发）
            int  nDurationTime;    // 持续时间 （硬触发）
        } LightChannelInfo;

        typedef struct LightConfigInfo_
        {
            LightChannelInfo stChannel1; // 通道1
            LightChannelInfo stChannel2; // 通道2
            LightChannelInfo stChannel3; // 通道3
            LightChannelInfo stChannel4; // 通道4
        } LightConfigInfo;

        typedef struct GlobalLightParam_
        {
            int nDeviceIndex;  // 设备序号
            int nDeviceType;   // 设备类型 
            char strReserved[16]; // 保留字段
            int nTriggerTime;  // 触发时间
            LightConfigInfo stLightConfig; // 光源通道信息
            int nReserved[4];
        } GlobalLightParam;

        /*  Note: Note: This is the class for the LightControl tool.  */
        class LightControlModuleTool
        {
        protected:
            ///< Constructor and Destructor
            explicit LightControlModuleTool() {}
            virtual ~LightControlModuleTool() {}

        public:
            /**
             * @par 说明
             * 设置全局光源参数信息
             * @par 权限
             * 只读
             * 异步接口，部分异常设置不返回错误
             */
            virtual void SetGlobalLightParam(IN GlobalLightParam * const pstLightParam) = 0;

        private:
            LightControlModuleTool(LightControlModuleTool&);
            LightControlModuleTool& operator=(LightControlModuleTool&);
        };
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

    /*  Note: Get tool instance for LightControl.  */
    IMVS_6000_PLATFORMSDK_API VisionMasterSDK::LightControlModule::LightControlModuleTool * __stdcall GetLightControlToolInstance(void);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_LIGHTCONTROL_H_