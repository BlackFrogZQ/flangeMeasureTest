/***************************************************************************************************
 * File：IVmImageResize.h
 * Note：CH: 图像缩放模块接口声明 | En: Interface for the ImageResize tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGERESIZE_H_
#define _IVM_IMAGERESIZE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageResizeModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 插值类型 | EN: Inter_Mode
        typedef enum _InterTypeEnum
        {
            // CH: 最近邻 | EN: NN
            InterType_Neareast = 0x1,

            // CH: 双线性 | EN: Bilinear
            InterType_Bilinear = 0x2,

            // CH: 双三次 | EN: RunParam_Cubic
            InterType_Cubic = 0x4,

        }InterTypeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ImageResizeRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效, 仅支持0°矩形) | EN: Rectangle ROI(Only valid for this execution, Support only 0°Rectangle)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ImageResizeParams.  */
        class ImageResizeParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageResizeParams() {}
            virtual ~ImageResizeParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ImageResizeRoiManager* GetModuRoiManager() = 0;

            // CH: 输出图像宽度 | EN: OutImageWidth
            __declspec(property(put = SetWidthValue, get = GetWidthValue)) int WidthValue;

            virtual int GetWidthValue() = 0;

            virtual void SetWidthValue(int value) = 0;

            // CH: 输出图像高度 | EN: OutImageHeight
            __declspec(property(put = SetHeightValue, get = GetHeightValue)) int HeightValue;

            virtual int GetHeightValue() = 0;

            virtual void SetHeightValue(int value) = 0;

            // CH: 插值类型 | EN: Inter_Mode
            __declspec(property(put = SetInterType, get = GetInterType)) InterTypeEnum InterType;

            virtual InterTypeEnum GetInterType() = 0;

            virtual void SetInterType(InterTypeEnum value) = 0;

            // CH: 抗混叠 | EN: RunParam_AntiAliasing
            __declspec(property(put = SetAntiAliasing, get = GetAntiAliasing)) bool AntiAliasing;

            virtual bool GetAntiAliasing() = 0;

            virtual void SetAntiAliasing(bool value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageResizeResults.  */
        class ImageResizeResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageResizeResults() {}
            virtual ~ImageResizeResults() {}

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
            /**
            * @par 说明
            * 检测区域
            * @par 权限
            * 只读
            */
            virtual RectBox GetROI() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageResize tool.  */
        class IMVSImageResizeModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageResizeModuTool() {}
            virtual ~IMVSImageResizeModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageResizeParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageResizeResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageResizeModuTool(IMVSImageResizeModuTool&);
            IMVSImageResizeModuTool& operator=(IMVSImageResizeModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageResize.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageResizeModu::IMVSImageResizeModuTool * __stdcall GetImageResizeToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGERESIZE_H_
