/***************************************************************************************************
 * File：IVmImageCombineProcess.h
 * Note：CH: 图像组合模块接口声明 | En: Interface for the ImageCombineProcess tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGECOMBINEPROCESS_H_
#define _IVM_IMAGECOMBINEPROCESS_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageCombineProcessModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class ImageCombineProcessRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ImageCombineProcessParams.  */
        class ImageCombineProcessParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageCombineProcessParams() {}
            virtual ~ImageCombineProcessParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ImageCombineProcessRoiManager* GetModuRoiManager() = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageCombineProcessResults.  */
        class ImageCombineProcessResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageCombineProcessResults() {}
            virtual ~ImageCombineProcessResults() {}

        public:
             /**
             * @par 说明
             * 输出掩膜
             * @par 权限
             * 只读
             */
             virtual ImageBaseData GetOutputMask() = 0;

             /**
             * @par 说明
             * 屏蔽区多边形点集
             * @par 权限
             * 只读
             */
             virtual PointF GetBlindPolygonPoints(int nIndex) = 0;

             /**
             * @par 说明
             * 屏蔽区多边形点数
             * @par 权限
             * 只读
             */
             virtual int GetBlindPolygonPointNum(int nIndex) = 0;

             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
             /**
             * @par 说明
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;
             /**
             * @par 说明
             * ROI圆弧
             * @par 权限
             * 只读
             */
             virtual Annulus GetROIAnnulus() = 0;
            /**
             * @par 说明
             * 输出图像
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutputImage() = 0;

            /**
             * @par 说明
             * 中间图像
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetPImage() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageCombineProcess tool.  */
        class IMVSImageCombineProcessModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageCombineProcessModuTool() {}
            virtual ~IMVSImageCombineProcessModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageCombineProcessParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageCombineProcessResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageCombineProcessModuTool(IMVSImageCombineProcessModuTool&);
            IMVSImageCombineProcessModuTool& operator=(IMVSImageCombineProcessModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageCombineProcess.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageCombineProcessModu::IMVSImageCombineProcessModuTool * __stdcall GetImageCombineProcessToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGECOMBINEPROCESS_H_
