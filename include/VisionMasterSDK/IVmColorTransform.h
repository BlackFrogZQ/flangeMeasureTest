/***************************************************************************************************
 * File：IVmColorTransform.h
 * Note：CH: 颜色转换模块接口声明 | En: Interface for the ColorTransform tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_COLORTRANSFORM_H_
#define _IVM_COLORTRANSFORM_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSColorTransformModu
    {        /*************************** Params Class Start ***************************/
        // CH: 转换类型 | EN: Transfer Type
        typedef enum _ColorTransformTypeEnum
        {
            // CH: RGB转灰度 | EN: RGB to Grayscale
            ColorTransformType_RGB2GRAY = 0x1,

            // CH: RGB转HSV | EN: RGB to HSV
            ColorTransformType_RGB2HSV = 0x2,

            // CH: RGB转HSI | EN: RGB to HSI
            ColorTransformType_RGB2HSI = 0x3,

            // CH: RGB转YUV | EN: RGB to YUV
            ColorTransformType_RGB2YUV = 0x4,

        }ColorTransformTypeEnum;

        // CH: 显示通道 | EN: Displayed Channel
        typedef enum _ShowChannelEnum
        {
            // CH: 第一通道 | EN: 1st Channel
            ShowChannel_FirstChannel = 0x0,

            // CH: 第二通道 | EN: 2nd Channel
            ShowChannel_SecondChannel = 0x1,

            // CH: 第三通道 | EN: 3rd Channel
            ShowChannel_ThirdChannel = 0x2,

        }ShowChannelEnum;

        // CH: 转换比例 | EN: Transfer Ratio
        typedef enum _RGB2GrayTypeEnum
        {
            // CH: 通用转换比例 | EN: General Transfer Ratio
            RGB2GrayType_GeneralRatio = 0x1,

            // CH: 平均转换比例 | EN: Average Transfer Ratio
            RGB2GrayType_AverageRatio = 0x2,

            // CH: 通道最小值 | EN: Channel Min Value
            RGB2GrayType_ChannelMin = 0x3,

            // CH: 通道最大值 | EN: Channel Max Value
            RGB2GrayType_ChannelMax = 0x4,

            // CH: 自设转换比例 | EN: User-defined Transfer Ratio
            RGB2GrayType_UserRatio = 0x5,

            // CH: R通道 | EN: Channel R
            RGB2GrayType_RChannel = 0x6,

            // CH: B通道 | EN: Channel B
            RGB2GrayType_BChannel = 0x7,

            // CH: G通道 | EN: Channel G
            RGB2GrayType_GChannel = 0x8,

        }RGB2GrayTypeEnum;

        /*  Note: Interface Classes of the parameter of the ColorTransformParams.  */
        class ColorTransformParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ColorTransformParams() {}
            virtual ~ColorTransformParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 转换类型 | EN: Transfer Type
            __declspec(property(put = SetColorTransformType, get = GetColorTransformType)) ColorTransformTypeEnum ColorTransformType;

            virtual ColorTransformTypeEnum GetColorTransformType() = 0;

            virtual void SetColorTransformType(ColorTransformTypeEnum value) = 0;

            // CH: 显示通道 | EN: Displayed Channel
            __declspec(property(put = SetShowChannel, get = GetShowChannel)) ShowChannelEnum ShowChannel;

            virtual ShowChannelEnum GetShowChannel() = 0;

            virtual void SetShowChannel(ShowChannelEnum value) = 0;

            // CH: 转换比例 | EN: Transfer Ratio
            __declspec(property(put = SetRGB2GrayType, get = GetRGB2GrayType)) RGB2GrayTypeEnum RGB2GrayType;

            virtual RGB2GrayTypeEnum GetRGB2GrayType() = 0;

            virtual void SetRGB2GrayType(RGB2GrayTypeEnum value) = 0;

            // CH: R转换比例 | EN: R Transfer Ratio
            __declspec(property(put = SetRratio, get = GetRratio)) int Rratio;

            virtual int GetRratio() = 0;

            virtual void SetRratio(int value) = 0;

            // CH: G转换比例 | EN: G Transfer Ratio
            __declspec(property(put = SetGratio, get = GetGratio)) int Gratio;

            virtual int GetGratio() = 0;

            virtual void SetGratio(int value) = 0;

            // CH: B转换比例 | EN: B Transfer Ratio
            __declspec(property(put = SetBratio, get = GetBratio)) int Bratio;

            virtual int GetBratio() = 0;

            virtual void SetBratio(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ColorTransformResults.  */
        class ColorTransformResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ColorTransformResults() {}
            virtual ~ColorTransformResults() {}

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
             * 输出图像
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutputImage() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ColorTransform tool.  */
        class IMVSColorTransformModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSColorTransformModuTool() {}
            virtual ~IMVSColorTransformModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ColorTransformParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ColorTransformResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSColorTransformModuTool(IMVSColorTransformModuTool&);
            IMVSColorTransformModuTool& operator=(IMVSColorTransformModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ColorTransform.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSColorTransformModu::IMVSColorTransformModuTool * __stdcall GetColorTransformToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_COLORTRANSFORM_H_
