/***************************************************************************************************
 * File：IVmSaveImage.h
 * Note：CH: 输出图像模块接口声明 | En: Interface for the SaveImage tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_SAVEIMAGE_H_
#define _IVM_SAVEIMAGE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace SaveImage
    {
        /*************************** Params Class Start ***************************/
        // CH: 保存条件 | EN: Save Condition
        typedef enum _ImageSaveConditionEnum
        {
            // CH: 全部保存 | EN: Save All
            ImageSaveCondition_ALL = 0x0,

            // CH: OK时保存 | EN: Save OK
            ImageSaveCondition_OK = 0x1,

            // CH: NG时保存 | EN: Save NG
            ImageSaveCondition_NG = 0x2,

            // CH: 不保存 | EN: Not Save
            ImageSaveCondition_NONE = 0x3,

        }ImageSaveConditionEnum;

        // CH: 存储方式 | EN: Save Mode
        typedef enum _ImageSaveTypeEnum
        {
            // CH: 覆盖存储 | EN: Overwrite
            ImageSaveType_OverWrite = 0x0,

            // CH: 停止存储 | EN: Stop Saving
            ImageSaveType_NoSave = 0x1,

        }ImageSaveTypeEnum;

        // CH: 存储单位 | EN: Storage Unit
        typedef enum _DiskUnitEnum
        {
            // CH: MB | EN: MB
            DiskUnit_MByte = 0x0,

            // CH: GB | EN: GB
            DiskUnit_GByte = 0x1,

        }DiskUnitEnum;

        // CH: 保存格式 | EN: Picture Format
        typedef enum _ImageTypeEnum
        {
            // CH: BMP | EN: BMP
            ImageType_BMP = 0x0,

            // CH: JPEG | EN: JPEG
            ImageType_JPEG = 0x1,

        }ImageTypeEnum;

        // CH: 编码格式 | EN: Coding Format
        typedef enum _CodingFormatEnum
        {
            // CH: UTF8 | EN: UTF8
            CodingFormat_UTF8 = 0x0,

            // CH: UNICODE | EN: UNICODE
            CodingFormat_UNICODE = 0x1,

        }CodingFormatEnum;

        // CH: 像素格式 | EN: Pixel Format
        typedef enum _PixelFormatEnum
        {
            // CH: RGB24 | EN: RGB24
            PixelFormat_RGB24 = 0x0,

            // CH: MONO8 | EN: MONO8
            PixelFormat_MONO8 = 0x1,

        }PixelFormatEnum;

        // CH: 图形倍率类型 | EN: Graph Rate Type
        typedef enum _GraphRateTypeEnum
        {
            // CH: 原图尺寸 | EN: Match Image
            GraphRateType_MatchImage = 0x0,

            // CH: 界面尺寸 | EN: Match View
            GraphRateType_MatchView = 0x1,

            // CH: 自定义倍率 | EN: Custom Rate
            GraphRateType_CustomRate = 0x2,

        }GraphRateTypeEnum;

        // CH: 线型 | EN: LineType
        typedef enum _LineTypeEnum
        {
            // CH: 4连通线 | EN: 4-connected Line
            LineType_FourConnectedLine = 0x0,

            // CH: 8连通线 | EN: 8-connected Line
            LineType_EightConnectedLine = 0x1,

            // CH: 抗锯齿线 | EN: Antialiased Line
            LineType_AntialiasedLine = 0x2,

        }LineTypeEnum;

        /*  Note: Interface Classes of the parameter of the SaveImageParams.  */
        class SaveImageParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SaveImageParams() {}
            virtual ~SaveImageParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 存图使能 | EN: Save Image Enable
            __declspec(property(put = SetSaveImageEnable, get = GetSaveImageEnable)) bool SaveImageEnable;

            virtual bool GetSaveImageEnable() = 0;

            virtual void SetSaveImageEnable(bool value) = 0;

            // CH: 触发保存 | EN: Save Trigger
            __declspec(property(put = SetImageSaveTrigger, get = GetImageSaveTrigger)) bool ImageSaveTrigger;

            virtual bool GetImageSaveTrigger() = 0;

            virtual void SetImageSaveTrigger(bool value) = 0;

            // CH: 保存条件 | EN: Save Condition
            __declspec(property(put = SetImageSaveCondition, get = GetImageSaveCondition)) ImageSaveConditionEnum ImageSaveCondition;

            virtual ImageSaveConditionEnum GetImageSaveCondition() = 0;

            virtual void SetImageSaveCondition(ImageSaveConditionEnum value) = 0;

            // CH: 调试保存 | EN: Debug Save
            __declspec(property(put = SetDebugInfoSave, get = GetDebugInfoSave)) bool DebugInfoSave;

            virtual bool GetDebugInfoSave() = 0;

            virtual void SetDebugInfoSave(bool value) = 0;

            // CH: 生成目录 | EN: Generate Directory
            __declspec(property(put = SetGenerateDir, get = GetGenerateDir)) bool GenerateDir;

            virtual bool GetGenerateDir() = 0;

            virtual void SetGenerateDir(bool value) = 0;

            // CH: 同步存储 | EN: Synchronous Storage
            __declspec(property(put = SetSynchronousStorage, get = GetSynchronousStorage)) bool SynchronousStorage;

            virtual bool GetSynchronousStorage() = 0;

            virtual void SetSynchronousStorage(bool value) = 0;

            // CH: 存图间隔 | EN: Storage Interval
            __declspec(property(put = SetStorageInterval, get = GetStorageInterval)) int StorageInterval;

            virtual int GetStorageInterval() = 0;

            virtual void SetStorageInterval(int value) = 0;

            // CH: 保存渲染图 | EN: Save Render Image
            __declspec(property(put = SetRenderImgEnable, get = GetRenderImgEnable)) bool RenderImgEnable;

            virtual bool GetRenderImgEnable() = 0;

            virtual void SetRenderImgEnable(bool value) = 0;

            // CH: 渲染图路径 | EN: Render Image Path
            __declspec(property(put = SetRenderImgPath, get = GetRenderImgPath)) const char* RenderImgPath;

            virtual const char* GetRenderImgPath() = 0;

            virtual void SetRenderImgPath(const char* value) = 0;

            // CH: 渲染OK路径 | EN: Rendering OK Path
            __declspec(property(put = SetRenderOKPath, get = GetRenderOKPath)) const char* RenderOKPath;

            virtual const char* GetRenderOKPath() = 0;

            virtual void SetRenderOKPath(const char* value) = 0;

            // CH: 渲染NG路径 | EN: Rendering NG Path
            __declspec(property(put = SetRenderNGPath, get = GetRenderNGPath)) const char* RenderNGPath;

            virtual const char* GetRenderNGPath() = 0;

            virtual void SetRenderNGPath(const char* value) = 0;

            // CH: 渲染图缓存 | EN: Render Image Cache
            __declspec(property(put = SetRenderImgCache, get = GetRenderImgCache)) int RenderImgCache;

            virtual int GetRenderImgCache() = 0;

            virtual void SetRenderImgCache(int value) = 0;

            // CH: 保存原图 | EN: Save Original Image
            __declspec(property(put = SetOriginImgEnable, get = GetOriginImgEnable)) bool OriginImgEnable;

            virtual bool GetOriginImgEnable() = 0;

            virtual void SetOriginImgEnable(bool value) = 0;

            // CH: 原图路径 | EN: Original Image Path
            __declspec(property(put = SetOriginImgPath, get = GetOriginImgPath)) const char* OriginImgPath;

            virtual const char* GetOriginImgPath() = 0;

            virtual void SetOriginImgPath(const char* value) = 0;

            // CH: 原图OK路径 | EN: Originality OK Path
            __declspec(property(put = SetOriginOKPath, get = GetOriginOKPath)) const char* OriginOKPath;

            virtual const char* GetOriginOKPath() = 0;

            virtual void SetOriginOKPath(const char* value) = 0;

            // CH: 原图NG路径 | EN: Originality NG Path
            __declspec(property(put = SetOriginNGPath, get = GetOriginNGPath)) const char* OriginNGPath;

            virtual const char* GetOriginNGPath() = 0;

            virtual void SetOriginNGPath(const char* value) = 0;

            // CH: 原图缓存 | EN: Original Image Cache
            __declspec(property(put = SetOriginImgCache, get = GetOriginImgCache)) int OriginImgCache;

            virtual int GetOriginImgCache() = 0;

            virtual void SetOriginImgCache(int value) = 0;

            // CH: 存储方式 | EN: Save Mode
            __declspec(property(put = SetImageSaveType, get = GetImageSaveType)) ImageSaveTypeEnum ImageSaveType;

            virtual ImageSaveTypeEnum GetImageSaveType() = 0;

            virtual void SetImageSaveType(ImageSaveTypeEnum value) = 0;

            // CH: 磁盘剩余空间 | EN: Disk Freespace
            __declspec(property(put = SetDiskFreespace, get = GetDiskFreespace)) int DiskFreespace;

            virtual int GetDiskFreespace() = 0;

            virtual void SetDiskFreespace(int value) = 0;

            // CH: 存储单位 | EN: Storage Unit
            __declspec(property(put = SetDiskUnit, get = GetDiskUnit)) DiskUnitEnum DiskUnit;

            virtual DiskUnitEnum GetDiskUnit() = 0;

            virtual void SetDiskUnit(DiskUnitEnum value) = 0;

            // CH: 最大保存天数 | EN: Max Save Days
            __declspec(property(put = SetImageMemoryDay, get = GetImageMemoryDay)) int ImageMemoryDay;

            virtual int GetImageMemoryDay() = 0;

            virtual void SetImageMemoryDay(int value) = 0;

            // CH: 保存格式 | EN: Picture Format
            __declspec(property(put = SetImageType, get = GetImageType)) ImageTypeEnum ImageType;

            virtual ImageTypeEnum GetImageType() = 0;

            virtual void SetImageType(ImageTypeEnum value) = 0;

            // CH: 图片压缩质量 | EN: Compression Quality
            __declspec(property(put = SetImageCompressionRation, get = GetImageCompressionRation)) int ImageCompressionRation;

            virtual int GetImageCompressionRation() = 0;

            virtual void SetImageCompressionRation(int value) = 0;

            // CH: 启用FTP | EN: Enable FTP
            __declspec(property(put = SetFTPEnable, get = GetFTPEnable)) bool FTPEnable;

            virtual bool GetFTPEnable() = 0;

            virtual void SetFTPEnable(bool value) = 0;

            // CH: 连接 | EN: Connect
            __declspec(property(put = SetConnectEnable, get = GetConnectEnable)) bool ConnectEnable;

            virtual bool GetConnectEnable() = 0;

            virtual void SetConnectEnable(bool value) = 0;

            // CH: 服务器IP | EN: Server IP
            __declspec(property(put = SetServerIP, get = GetServerIP)) const char* ServerIP;

            virtual const char* GetServerIP() = 0;

            virtual void SetServerIP(const char* value) = 0;

            // CH: 服务器端口 | EN: Server Port
            __declspec(property(put = SetServerPort, get = GetServerPort)) int ServerPort;

            virtual int GetServerPort() = 0;

            virtual void SetServerPort(int value) = 0;

            // CH: 用户名 | EN: User Name
            __declspec(property(put = SetUserName, get = GetUserName)) const char* UserName;

            virtual const char* GetUserName() = 0;

            virtual void SetUserName(const char* value) = 0;

            // CH: 密码 | EN: Password
            __declspec(property(put = SetPassword, get = GetPassword)) const char* Password;

            virtual const char* GetPassword() = 0;

            virtual void SetPassword(const char* value) = 0;

            // CH: 编码格式 | EN: Coding Format
            __declspec(property(put = SetCodingFormat, get = GetCodingFormat)) CodingFormatEnum CodingFormat;

            virtual CodingFormatEnum GetCodingFormat() = 0;

            virtual void SetCodingFormat(CodingFormatEnum value) = 0;

            // CH: FTP路径 | EN: FTP Path
            __declspec(property(put = SetFTPPath, get = GetFTPPath)) const char* FTPPath;

            virtual const char* GetFTPPath() = 0;

            virtual void SetFTPPath(const char* value) = 0;

            // CH: 输出使能 | EN: Output Enable
            __declspec(property(put = SetOutputEnable, get = GetOutputEnable)) bool OutputEnable;

            virtual bool GetOutputEnable() = 0;

            virtual void SetOutputEnable(bool value) = 0;

            // CH: 像素格式 | EN: Pixel Format
            __declspec(property(put = SetPixelFormat, get = GetPixelFormat)) PixelFormatEnum PixelFormat;

            virtual PixelFormatEnum GetPixelFormat() = 0;

            virtual void SetPixelFormat(PixelFormatEnum value) = 0;

            // CH: 图形倍率类型 | EN: Graph Rate Type
            __declspec(property(put = SetGraphRateType, get = GetGraphRateType)) GraphRateTypeEnum GraphRateType;

            virtual GraphRateTypeEnum GetGraphRateType() = 0;

            virtual void SetGraphRateType(GraphRateTypeEnum value) = 0;

            // CH: 线宽倍率 | EN: Line Width Rate
            __declspec(property(put = SetLineWidthRate, get = GetLineWidthRate)) int LineWidthRate;

            virtual int GetLineWidthRate() = 0;

            virtual void SetLineWidthRate(int value) = 0;

            // CH: 字宽倍率 | EN: Font Size Rate
            __declspec(property(put = SetFontSizeRate, get = GetFontSizeRate)) int FontSizeRate;

            virtual int GetFontSizeRate() = 0;

            virtual void SetFontSizeRate(int value) = 0;

            // CH: 线型 | EN: LineType
            __declspec(property(put = SetLineType, get = GetLineType)) LineTypeEnum LineType;

            virtual LineTypeEnum GetLineType() = 0;

            virtual void SetLineType(LineTypeEnum value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the SaveImageResults.  */
        class SaveImageResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SaveImageResults() {}
            virtual ~SaveImageResults() {}

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
             * 原图像保存路径
             * @par 权限
             * 只读
             */
            virtual const char * GetOriginImageSavePath() = 0;

            /**
             * @par 说明
             * 原图像名称
             * @par 权限
             * 只读
             */
            virtual const char * GetOriginImageName() = 0;

            /**
             * @par 说明
             * 渲染图像路径
             * @par 权限
             * 只读
             */
            virtual const char * GetRenderImageSavePath() = 0;

            /**
             * @par 说明
             * 渲染图像名称
             * @par 权限
             * 只读
             */
            virtual const char * GetRenderImageName() = 0;

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
        /*  Note: Note: This is the class for the SaveImage tool.  */
        class SaveImageTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SaveImageTool() {}
            virtual ~SaveImageTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual SaveImageParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual SaveImageResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            SaveImageTool(SaveImageTool&);
            SaveImageTool& operator=(SaveImageTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for SaveImage.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::SaveImage::SaveImageTool * __stdcall GetSaveImageToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_SAVEIMAGE_H_
