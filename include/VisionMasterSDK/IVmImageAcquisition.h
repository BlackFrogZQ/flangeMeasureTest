/***************************************************************************************************
 * File：IVmImageAcquisition.h
 * Note：CH: 多图采集模块接口声明 | En: Interface for the ImageAcquisition tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGEACQUISITION_H_
#define _IVM_IMAGEACQUISITION_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace ImageAcquisitionModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 图像源 | EN: ImageSource
        typedef enum _ImageSourceTypeEnum
        {
            // CH: 本地图像 | EN: Local Image
            ImageSourceType_LocalImage = 0x1,

            // CH: 相机 | EN: Camera
            ImageSourceType_Camera = 0x2,

        }ImageSourceTypeEnum;

        /*  Note: Interface Classes of the parameter of the ImageAcquisitionParams.  */
        class ImageAcquisitionParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageAcquisitionParams() {}
            virtual ~ImageAcquisitionParams() {}

        public:

            // CH: 图像源 | EN: ImageSource
            __declspec(property(put = SetImageSourceType, get = GetImageSourceType)) ImageSourceTypeEnum ImageSourceType;

            virtual ImageSourceTypeEnum GetImageSourceType() = 0;

            virtual void SetImageSourceType(ImageSourceTypeEnum value) = 0;

            // CH: 取图间隔 | EN: Acquisition Rate
            __declspec(property(put = SetInterval, get = GetInterval)) int Interval;

            virtual int GetInterval() = 0;

            virtual void SetInterval(int value) = 0;

            // CH: 取图数量 | EN: Image Count
            __declspec(property(put = SetImageCount, get = GetImageCount)) int ImageCount;

            virtual int GetImageCount() = 0;

            virtual void SetImageCount(int value) = 0;

            // CH: 图像路径 | EN: Image Path
            __declspec(property(put = SetImageDir, get = GetImageDir)) const char* ImageDir;

            virtual const char* GetImageDir() = 0;

            virtual void SetImageDir(const char* value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageAcquisitionResults.  */
        class ImageAcquisitionResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageAcquisitionResults() {}
            virtual ~ImageAcquisitionResults() {}

        public:
            /**
             * @par 说明
             * 帧号
             * @par 权限
             * 读写
             */
            virtual int GetFrameNum() = 0;

            /**
             * @par 说明
             * 丢帧数
             * @par 权限
             * 读写
             */
            virtual int GetLostFrameCount() = 0;

            /**
             * @par 说明
             * 丢包数
             * @par 权限
             * 读写
             */
            virtual int GetLostPacketCount() = 0;

            /**
             * @par 说明
             * 相机获取失败次数
             * @par 权限
             * 读写
             */
            virtual int GetCameraFailCount() = 0;

            /**
             * @par 说明
             * 获取图像数量
             * @par 权限
             * 读写
             */
            virtual int GetImageCount() = 0;

            /**
             * @par 说明
             * 获取分布角
             * @par 权限
             * 读写
             */
            virtual float GetDistributionAngle(int nIndex) = 0;

            /**
             * @par 说明
             * 获取照射角
             * @par 权限
             * 读写
             */
            virtual float GetIrradiationAngle(int nIndex) = 0;

            /**
             * @par 说明
             * 获取输出图像
             * @par 权限
             * 读写
             */
            virtual ImageBaseData GetOutputImage(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageAcquisition tool.  */
        class ImageAcquisitionModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageAcquisitionModuleTool() {}
            virtual ~ImageAcquisitionModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageAcquisitionParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageAcquisitionResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            ImageAcquisitionModuleTool(ImageAcquisitionModuleTool&);
            ImageAcquisitionModuleTool& operator=(ImageAcquisitionModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageAcquisition.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::ImageAcquisitionModule::ImageAcquisitionModuleTool * __stdcall GetImageAcquisitionToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGEACQUISITION_H_
