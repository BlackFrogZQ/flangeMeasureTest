/***************************************************************************************************
 * File：IVmImageSource.h
 * Note：CH: 图像源模块接口声明 | En: Interface for the ImageSource tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGESOURCE_H_
#define _IVM_IMAGESOURCE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace ImageSourceModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 图像源 | EN: ImageSource
        typedef enum _ImageSourceTypeEnum
        {
            // CH: 本地图像 | EN: Local Image
            ImageSourceType_LocalImage = 0x1,

            // CH: 相机 | EN: Camera
            ImageSourceType_Camera = 0x2,

            // CH: SDK | EN: SDK
            ImageSourceType_SDK = 0x3,

        }ImageSourceTypeEnum;

        // CH: 像素格式 | EN: Pixel Format
        typedef enum _PixelFormatEnum
        {
            // CH: MONO8 | EN: MONO8
            PixelFormat_MONO8 = 0x1,

            // CH: RGB24 | EN: RGB24
            PixelFormat_RGB24 = 0x2,

        }PixelFormatEnum;

        /*  Note: Interface Classes of the parameter of the ImageSourceParams.  */
        class ImageSourceParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageSourceParams() {}
            virtual ~ImageSourceParams() {}

        public:

            // CH: 触发字符(仅当次执行起效) | EN: String(Only valid for this execution)
            virtual void SetTriggerString(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // CH: 过滤字符(仅当次执行起效) | EN: TriggerFilter(Only valid for this execution)
            virtual void SetTriggerFilter(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // CH: 曝光时间(仅当次执行起效) | EN: ExposureTimeInput(Only valid for this execution)
            virtual void SetExposureTimeInput(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 增益时间(仅当次执行起效) | EN: GainInput(Only valid for this execution)
            virtual void SetGainInput(float* pInputValue, unsigned int nValueNum) = 0;

			// CH: 触发清空变量(仅当次执行起效)   | EN: Clear Trigger Value(Only valid for this execution)
            virtual void SetClearTriggerValue(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 图像源 | EN: ImageSource
            __declspec(property(put = SetImageSourceType, get = GetImageSourceType)) ImageSourceTypeEnum ImageSourceType;

            virtual ImageSourceTypeEnum GetImageSourceType() = 0;

            virtual void SetImageSourceType(ImageSourceTypeEnum value) = 0;

            // CH: 像素格式 | EN: Pixel Format
            __declspec(property(put = SetPixelFormat, get = GetPixelFormat)) PixelFormatEnum PixelFormat;

            virtual PixelFormatEnum GetPixelFormat() = 0;

            virtual void SetPixelFormat(PixelFormatEnum value) = 0;

            // CH: 取图间隔 | EN: Acquisition Rate
            __declspec(property(put = SetInterval, get = GetInterval)) int Interval;

            virtual int GetInterval() = 0;

            virtual void SetInterval(int value) = 0;

            // CH: 方案存图 | EN: Save Image
            __declspec(property(put = SetSolSaveImageData, get = GetSolSaveImageData)) bool SolSaveImageData;

            virtual bool GetSolSaveImageData() = 0;

            virtual void SetSolSaveImageData(bool value) = 0;

            // CH: 显示图像名称 | EN: Show Image Name
            __declspec(property(put = SetShowImageName, get = GetShowImageName)) bool ShowImageName;

            virtual bool GetShowImageName() = 0;

            virtual void SetShowImageName(bool value) = 0;

            // CH: SN初始值 | EN: Initial SN
            __declspec(property(put = SetInitialSN, get = GetInitialSN)) int InitialSN;

            virtual int GetInitialSN() = 0;

            virtual void SetInitialSN(int value) = 0;

            // CH: 图片缓存 | EN: PathCache
            __declspec(property(put = SetPathCache, get = GetPathCache)) int PathCache;

            virtual int GetPathCache() = 0;

            virtual void SetPathCache(int value) = 0;

            // CH: 输出Mono8 | EN: Output Mono8
            __declspec(property(put = SetOutMono8, get = GetOutMono8)) bool OutMono8;

            virtual bool GetOutMono8() = 0;

            virtual void SetOutMono8(bool value) = 0;

            // CH: 拼接使能 | EN: Stitch Enable
            __declspec(property(put = SetStitchEnable, get = GetStitchEnable)) bool StitchEnable;

            virtual bool GetStitchEnable() = 0;

            virtual void SetStitchEnable(bool value) = 0;

            // CH: 起始高度 | EN: Start Height
            __declspec(property(put = SetStitchStartHeight, get = GetStitchStartHeight)) int StitchStartHeight;

            virtual int GetStitchStartHeight() = 0;

            virtual void SetStitchStartHeight(int value) = 0;

            // CH: 拼接高度 | EN: Stitch Height
            __declspec(property(put = SetStitchHeight, get = GetStitchHeight)) int StitchHeight;

            virtual int GetStitchHeight() = 0;

            virtual void SetStitchHeight(int value) = 0;

            // CH: 触发清空 | EN: Trigger Clear
            __declspec(property(put = SetClearTrigger, get = GetClearTrigger)) bool ClearTrigger;

            virtual bool GetClearTrigger() = 0;

            virtual void SetClearTrigger(bool value) = 0;

            // CH: 自动切换 | EN: Auto Switch
            __declspec(property(put = SetAutoPlay, get = GetAutoPlay)) bool AutoPlay;

            virtual bool GetAutoPlay() = 0;

            virtual void SetAutoPlay(bool value) = 0;

            // CH: 最后一张停止 | EN: The last one stops
            __declspec(property(put = SetAutoStop, get = GetAutoStop)) bool AutoStop;

            virtual bool GetAutoStop() = 0;

            virtual void SetAutoStop(bool value) = 0;

            // CH: 字符触发过滤 | EN: Character Trigger Filter
            __declspec(property(put = SetTriggerStringEnable, get = GetTriggerStringEnable)) bool TriggerStringEnable;

            virtual bool GetTriggerStringEnable() = 0;

            virtual void SetTriggerStringEnable(bool value) = 0;

            /**
            * @brief 通过相机名称设置相机ID
            * @param 相机名称
            * @return 无，出错时抛出异常
            * @par 注解
            * 设置相机ID
            */
            virtual void SetCameraName(IN char* strCameraName) = 0;

            /**
            * @brief 获取绑定相机名称
            * @param 相机名称
            * @return 无，出错时抛出异常
            * @par 注解
            * 获取相机名称
            */
            virtual void GetCameraName(OUT char* strCameraName) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageSourceResults.  */
        class ImageSourceResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageSourceResults() {}
            virtual ~ImageSourceResults() {}

        public:
            /**
             * @par 说明
             * 图像数据
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetImageData() = 0;
            /**
             * @par 说明
             * Mono8图像数据
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetImageDataMono8() = 0;
            /**
             * @par 说明
             * 帧号
             * @par 权限
             * 只读
             */
            virtual int GetFrameNum() = 0;
            /**
             * @par 说明
             * 丢帧数
             * @par 权限
             * 只读
             */
            virtual int GetLostFrameCount() = 0;
            /**
             * @par 说明
             * 丢包数
             * @par 权限
             * 只读
             */
            virtual int GetLostPacketCount() = 0;
            /**
             * @par 说明
             * 获取相机失败次数
             * @par 权限
             * 只读
             */
            virtual int GetCameraFailCount() = 0;
            /**
             * @par 说明
             * 当前本地图像路径
             * @par 权限
             * 只读
             */
            virtual const char * GetCurImagePath() = 0;
            /**
             * @par 说明
             * 当前本地图像名称
             * @par 权限
             * 只读
             */
            virtual const char * GetCurImageName() = 0;
            /**
            * @par 说明
            * 获取SNCode
            * @par 权限
            * 只读
            */
            virtual int GetSNCode() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageSource tool.  */
        class ImageSourceModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageSourceModuleTool() {}
            virtual ~ImageSourceModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageSourceParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageSourceResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

            /**
             * @brief 设置图像路径
             * @param 图像路径
             * @return 无，出错时抛出异常
             * @par 注解
             * 设置图像路径（图像源需选择SDK模式）
             */
            virtual void SetImagePath(IN const char * const strPath) = 0;

            /**
             * @brief 设置图像数据
             * @param 图像数据
             * @param 是否等待图像拷贝完成,如不等待,则在当次执行期间,避免释放该图像数据
             * @return 无，出错时抛出异常
             * @par 注解
             * 设置图像数据（图像源需选择SDK模式）(仅当次执行起效)
             */
            virtual void SetImageData(IN const ImageBaseData * const pstImgData, IN bool bIsWaitCopy = true) = 0;

            /**
            * @brief 点对点设置图像数据
            * @param 图像数据
            * @param 是否等待图像拷贝完成,如不等待,则在当次执行期间,避免释放该图像数据
            * @return 无，出错时抛出异常
            * @par 注解
            * 设置图像数据（图像源需选择SDK模式）(仅当次执行起效)
            */
            virtual void SetImageDataP2P(IN const ImageBaseData * const pstImgData, IN bool bIsWaitCopy = true) = 0;

            /**
            * @brief 通过路径添加图像
            * @param 图像路径
            * @return 无，出错时抛出异常
            * @par 注解
            * 通过路径添加图像
            */
            virtual void AddInputImageByPath(IN const char * const strPath) = 0;

            /**
            * @brief 通过路径删除图像
            * @param 图像路径
            * @return 无，出错时抛出异常
            * @par 注解
            * 通过路径删除图像
            */
            virtual void DeleteInputImageByPath(IN const char * const strPath) = 0;

            /**
            * @brief 清空所有输入图像
            * @param 无
            * @return 无，出错时抛出异常
            * @par 注解
            * 清空所有输入图像
            */
            virtual void ClearAllInputImage() = 0;

            

        private:
            ImageSourceModuleTool(ImageSourceModuleTool&);
            ImageSourceModuleTool& operator=(ImageSourceModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageSource.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::ImageSourceModule::ImageSourceModuleTool * __stdcall GetImageSourceToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGESOURCE_H_
