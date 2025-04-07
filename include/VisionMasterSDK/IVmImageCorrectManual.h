/***************************************************************************************************
 * File：IVmImageCorrectManual.h
 * Note：CH: 图像矫正模块接口声明 | En: Interface for the ImageCorrectManual tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGECORRECTMANUAL_H_
#define _IVM_IMAGECORRECTMANUAL_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageCorrectManualModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the ImageCorrectManualParams.  */
        class ImageCorrectManualParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageCorrectManualParams() {}
            virtual ~ImageCorrectManualParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 曲张量 | EN: Expansion Amount
            __declspec(property(put = SetWarpPara, get = GetWarpPara)) int WarpPara;

            virtual int GetWarpPara() = 0;

            virtual void SetWarpPara(int value) = 0;

            // CH: 缩放量 | EN: Scaling Amount
            __declspec(property(put = SetZoomPara, get = GetZoomPara)) int ZoomPara;

            virtual int GetZoomPara() = 0;

            virtual void SetZoomPara(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageCorrectManualResults.  */
        class ImageCorrectManualResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageCorrectManualResults() {}
            virtual ~ImageCorrectManualResults() {}

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
        /*  Note: Note: This is the class for the ImageCorrectManual tool.  */
        class IMVSImageCorrectManualModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageCorrectManualModuTool() {}
            virtual ~IMVSImageCorrectManualModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageCorrectManualParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageCorrectManualResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageCorrectManualModuTool(IMVSImageCorrectManualModuTool&);
            IMVSImageCorrectManualModuTool& operator=(IMVSImageCorrectManualModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageCorrectManual.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageCorrectManualModu::IMVSImageCorrectManualModuTool * __stdcall GetImageCorrectManualToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGECORRECTMANUAL_H_
