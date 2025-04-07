/***************************************************************************************************
 * File：IVmLight.h
 * Note：CH: 光源模块接口声明 | En: Interface for the Light tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_LIGHT_H_
#define _IVM_LIGHT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace LightModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 输出类型 | EN: Output Type
        typedef enum _OutputTypeEnum
        {
            // CH: OK时输出 | EN: Output when OK
            OutputType_OK = 1,

            // CH: NG时输出 | EN: Output when NG
            OutputType_NG = 2,

        }OutputTypeEnum;

        // CH: 光源状态1 | EN: Channel 1 Light State
        typedef enum _Channel1LightStateEnum
        {
            // CH: 触发后亮（常灭） | EN: LightStateOn
            Channel1LightState_LightStateOn = 1,

            // CH: 触发后灭（常亮） | EN: LightStateOff
            Channel1LightState_LightStateOff = 2,

        }Channel1LightStateEnum;

        // CH: 光源状态1 | EN: Channel 1 Light State
        typedef enum _Channel1LightStateVBEnum
        {
            // CH: 常亮 | EN: LightStateOn
            Channel1LightStateVB_LightStateOn = 1,

            // CH: 常灭 | EN: LightStateOff
            Channel1LightStateVB_LightStateOff = 2,

        }Channel1LightStateVBEnum;

        // CH: 通道1沿定义 | EN: Channel 1 EdgeType
        typedef enum _Channel1EdgeTypeEnum
        {
            // CH: 上升沿 | EN: EdgeTypeRising
            Channel1EdgeType_EdgeTypeRising = 1,

            // CH: 下降沿 | EN: EdgeTypeFalling
            Channel1EdgeType_EdgeTypeFalling = 2,

        }Channel1EdgeTypeEnum;

        // CH: 光源状态2 | EN: Channel 2 Light State
        typedef enum _Channel2LightStateEnum
        {
            // CH: 触发后亮（常灭） | EN: LightStateOn
            Channel2LightState_LightStateOn = 1,

            // CH: 触发后灭（常亮） | EN: LightStateOff
            Channel2LightState_LightStateOff = 2,

        }Channel2LightStateEnum;

        // CH: 光源状态2 | EN: Channel 2 Light State
        typedef enum _Channel2LightStateVBEnum
        {
            // CH: 常亮 | EN: LightStateOn
            Channel2LightStateVB_LightStateOn = 1,

            // CH: 常灭 | EN: LightStateOff
            Channel2LightStateVB_LightStateOff = 2,

        }Channel2LightStateVBEnum;

        // CH: 通道2沿定义 | EN: Channel 2 Edge Type
        typedef enum _Channel2EdgeTypeEnum
        {
            // CH: 上升沿 | EN: EdgeTypeRising
            Channel2EdgeType_EdgeTypeRising = 1,

            // CH: 下降沿 | EN: EdgeTypeFalling
            Channel2EdgeType_EdgeTypeFalling = 2,

        }Channel2EdgeTypeEnum;

        // CH: 光源状态3 | EN: Channel 3 Light State
        typedef enum _Channel3LightStateEnum
        {
            // CH: 触发后亮（常灭） | EN: LightStateOn
            Channel3LightState_LightStateOn = 1,

            // CH: 触发后灭（常亮） | EN: LightStateOff
            Channel3LightState_LightStateOff = 2,

        }Channel3LightStateEnum;

        // CH: 通道3沿定义 | EN: Channel 3 EdgeType
        typedef enum _Channel3EdgeTypeEnum
        {
            // CH: 上升沿 | EN: EdgeTypeRising
            Channel3EdgeType_EdgeTypeRising = 1,

            // CH: 下降沿 | EN: EdgeTypeFalling
            Channel3EdgeType_EdgeTypeFalling = 2,

        }Channel3EdgeTypeEnum;

        // CH: 光源状态4 | EN: Channel 4 Light State
        typedef enum _Channel4LightStateEnum
        {
            // CH: 触发后亮（常灭） | EN: LightStateOn
            Channel4LightState_LightStateOn = 1,

            // CH: 触发后灭（常亮） | EN: LightStateOff
            Channel4LightState_LightStateOff = 2,

        }Channel4LightStateEnum;


        // CH: 通道4沿定义 | EN: Channel 4 EdgeType
        typedef enum _Channel4EdgeTypeEnum
        {
            // CH: 上升沿 | EN: EdgeTypeRising
            Channel4EdgeType_EdgeTypeRising = 1,

            // CH: 下降沿 | EN: EdgeTypeFalling
            Channel4EdgeType_EdgeTypeFalling = 2,

        }Channel4EdgeTypeEnum;

        /*  Note: Interface Classes of the parameter of the LightParams.  */
        class LightParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LightParams() {}
            virtual ~LightParams() {}

        public:

            // CH: 通道1亮度(仅当次执行起效) | EN: Channel 1 Brightness(Only valid for this execution)
            virtual void SetInputChannel1Brightness(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 通道2亮度(仅当次执行起效) | EN: Channel 2 Brightness(Only valid for this execution)
            virtual void SetInputChannel2Brightness(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 通道3亮度(仅当次执行起效) | EN: Channel 3 Brightness(Only valid for this execution)
            virtual void SetInputChannel3Brightness(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 通道4亮度(仅当次执行起效) | EN: Channel 4 Brightness(Only valid for this execution)
            virtual void SetInputChannel4Brightness(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入字符(仅当次执行起效) | EN: InputString(Only valid for this execution)
            virtual void SetInputString(InputStringData* pInputValue, unsigned int nValueNum) = 0;
            // CH: 输出类型 | EN: Output Type
            __declspec(property(put = SetOutputType, get = GetOutputType)) OutputTypeEnum OutputType;

            virtual OutputTypeEnum GetOutputType() = 0;

            virtual void SetOutputType(OutputTypeEnum value) = 0;

            // CH: 触发时间(ms) | EN: Trigger Time(ms)
            __declspec(property(put = SetTriggerTime, get = GetTriggerTime)) int TriggerTime;

            virtual int GetTriggerTime() = 0;

            virtual void SetTriggerTime(int value) = 0;

            // CH: 通道1使能 | EN: Channel 1 Enable
            __declspec(property(put = SetChannel1Enable, get = GetChannel1Enable)) bool Channel1Enable;

            virtual bool GetChannel1Enable() = 0;

            virtual void SetChannel1Enable(bool value) = 0;

            // CH: 通道1亮度 | EN: Channel 1 Brightness
            __declspec(property(put = SetChannel1Brightness, get = GetChannel1Brightness)) int Channel1Brightness;

            virtual int GetChannel1Brightness() = 0;

            virtual void SetChannel1Brightness(int value) = 0;

            // CH: 光源状态1 | EN: Channel 1 Light State
            __declspec(property(put = SetChannel1LightState, get = GetChannel1LightState)) Channel1LightStateEnum Channel1LightState;

            virtual Channel1LightStateEnum GetChannel1LightState() = 0;

            virtual void SetChannel1LightState(Channel1LightStateEnum value) = 0;

            // CH: 光源状态1 | EN: Channel 1 Light State
            __declspec(property(put = SetChannel1LightStateVB, get = GetChannel1LightStateVB)) Channel1LightStateVBEnum Channel1LightStateVB;

            virtual Channel1LightStateVBEnum GetChannel1LightStateVB() = 0;

            virtual void SetChannel1LightStateVB(Channel1LightStateVBEnum value) = 0;

            // CH: 通道1沿定义 | EN: Channel 1 EdgeType
            __declspec(property(put = SetChannel1EdgeType, get = GetChannel1EdgeType)) Channel1EdgeTypeEnum Channel1EdgeType;

            virtual Channel1EdgeTypeEnum GetChannel1EdgeType() = 0;

            virtual void SetChannel1EdgeType(Channel1EdgeTypeEnum value) = 0;

            // CH: 持续时间(ms) | EN: Duration(ms)
            __declspec(property(put = SetChannel1DurationTime, get = GetChannel1DurationTime)) int Channel1DurationTime;

            virtual int GetChannel1DurationTime() = 0;

            virtual void SetChannel1DurationTime(int value) = 0;

            // CH: 通道2使能 | EN: Channel 2 Enable
            __declspec(property(put = SetChannel2Enable, get = GetChannel2Enable)) bool Channel2Enable;

            virtual bool GetChannel2Enable() = 0;

            virtual void SetChannel2Enable(bool value) = 0;

            // CH: 通道2亮度 | EN: Channel 2 Brightness
            __declspec(property(put = SetChannel2Brightness, get = GetChannel2Brightness)) int Channel2Brightness;

            virtual int GetChannel2Brightness() = 0;

            virtual void SetChannel2Brightness(int value) = 0;

            // CH: 光源状态2 | EN: Channel 2 Light State
            __declspec(property(put = SetChannel2LightState, get = GetChannel2LightState)) Channel2LightStateEnum Channel2LightState;

            virtual Channel2LightStateEnum GetChannel2LightState() = 0;

            virtual void SetChannel2LightState(Channel2LightStateEnum value) = 0;

            // CH: 光源状态2 | EN: Channel 2 Light State
            __declspec(property(put = SetChannel2LightStateVB, get = GetChannel2LightStateVB)) Channel2LightStateVBEnum Channel2LightStateVB;

            virtual Channel2LightStateVBEnum GetChannel2LightStateVB() = 0;

            virtual void SetChannel2LightStateVB(Channel2LightStateVBEnum value) = 0;

            // CH: 通道2沿定义 | EN: Channel 2 Edge Type
            __declspec(property(put = SetChannel2EdgeType, get = GetChannel2EdgeType)) Channel2EdgeTypeEnum Channel2EdgeType;

            virtual Channel2EdgeTypeEnum GetChannel2EdgeType() = 0;

            virtual void SetChannel2EdgeType(Channel2EdgeTypeEnum value) = 0;

            // CH: 持续时间(ms) | EN: Duration(ms)
            __declspec(property(put = SetChannel2DurationTime, get = GetChannel2DurationTime)) int Channel2DurationTime;

            virtual int GetChannel2DurationTime() = 0;

            virtual void SetChannel2DurationTime(int value) = 0;

            // CH: 通道3使能 | EN: Channel 3 Enable
            __declspec(property(put = SetChannel3Enable, get = GetChannel3Enable)) bool Channel3Enable;

            virtual bool GetChannel3Enable() = 0;

            virtual void SetChannel3Enable(bool value) = 0;

            // CH: 通道3亮度 | EN: Channel 3 Brightness
            __declspec(property(put = SetChannel3Brightness, get = GetChannel3Brightness)) int Channel3Brightness;

            virtual int GetChannel3Brightness() = 0;

            virtual void SetChannel3Brightness(int value) = 0;

            // CH: 光源状态3 | EN: Channel 3 Light State
            __declspec(property(put = SetChannel3LightState, get = GetChannel3LightState)) Channel3LightStateEnum Channel3LightState;

            virtual Channel3LightStateEnum GetChannel3LightState() = 0;

            virtual void SetChannel3LightState(Channel3LightStateEnum value) = 0;

            // CH: 通道3沿定义 | EN: Channel 3 EdgeType
            __declspec(property(put = SetChannel3EdgeType, get = GetChannel3EdgeType)) Channel3EdgeTypeEnum Channel3EdgeType;

            virtual Channel3EdgeTypeEnum GetChannel3EdgeType() = 0;

            virtual void SetChannel3EdgeType(Channel3EdgeTypeEnum value) = 0;

            // CH: 持续时间(ms) | EN: Duration(ms)
            __declspec(property(put = SetChannel3DurationTime, get = GetChannel3DurationTime)) int Channel3DurationTime;

            virtual int GetChannel3DurationTime() = 0;

            virtual void SetChannel3DurationTime(int value) = 0;

            // CH: 通道4使能 | EN: Channel 4 Enable
            __declspec(property(put = SetChannel4Enable, get = GetChannel4Enable)) bool Channel4Enable;

            virtual bool GetChannel4Enable() = 0;

            virtual void SetChannel4Enable(bool value) = 0;

            // CH: 通道4亮度 | EN: Channel 4 Brightness
            __declspec(property(put = SetChannel4Brightness, get = GetChannel4Brightness)) int Channel4Brightness;

            virtual int GetChannel4Brightness() = 0;

            virtual void SetChannel4Brightness(int value) = 0;

            // CH: 光源状态4 | EN: Channel 4 Light State
            __declspec(property(put = SetChannel4LightState, get = GetChannel4LightState)) Channel4LightStateEnum Channel4LightState;

            virtual Channel4LightStateEnum GetChannel4LightState() = 0;

            virtual void SetChannel4LightState(Channel4LightStateEnum value) = 0;

            // CH: 通道4沿定义 | EN: Channel 4 EdgeType
            __declspec(property(put = SetChannel4EdgeType, get = GetChannel4EdgeType)) Channel4EdgeTypeEnum Channel4EdgeType;

            virtual Channel4EdgeTypeEnum GetChannel4EdgeType() = 0;

            virtual void SetChannel4EdgeType(Channel4EdgeTypeEnum value) = 0;

            // CH: 持续时间(ms) | EN: Duration(ms)
            __declspec(property(put = SetChannel4DurationTime, get = GetChannel4DurationTime)) int Channel4DurationTime;

            virtual int GetChannel4DurationTime() = 0;

            virtual void SetChannel4DurationTime(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        // CH: 光源通道信息结构 | EN: Structure about information of light channel
        typedef struct LightChannelInfo__
        {
            int    iEnable;                                          // CH: 使能 | EN: Enable
            int    iBrightness;                                      // CH: 亮度 | EN: Brightness
            int    iLightState;                                      // CH: 光源状态 | EN: Light state
            int    iEdgeType;                                        // CH: 沿定义 | EN: Edge type
            int    iDurationTime;                                    // CH: 持续时间 | EN: Duration time
        } LightChannelInfo;
        /*  Note: Interface Classes of the result of the LightResults.  */
        class LightResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LightResults() {}
            virtual ~LightResults() {}

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
             * 通道1信息
             * @par 权限
             * 只读
             */
             virtual LightChannelInfo GetChannel1Info() = 0;

             /**
             * @par 说明
             * 通道2信息
             * @par 权限
             * 只读
             */
             virtual LightChannelInfo GetChannel2Info() = 0;

             /**
             * @par 说明
             * 通道3信息
             * @par 权限
             * 只读
             */
             virtual LightChannelInfo GetChannel3Info() = 0;

             /**
             * @par 说明
             * 通道4信息
             * @par 权限
             * 只读
             */
             virtual LightChannelInfo GetChannel4Info() = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Light tool.  */
        class LightModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LightModuleTool() {}
            virtual ~LightModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual LightParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual LightResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            LightModuleTool(LightModuleTool&);
            LightModuleTool& operator=(LightModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Light.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::LightModule::LightModuleTool * __stdcall GetLightToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_LIGHT_H_
