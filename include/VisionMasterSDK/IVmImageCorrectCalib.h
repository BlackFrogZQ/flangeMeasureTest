/***************************************************************************************************
 * File：IVmImageCorrectCalib.h
 * Note：CH: 畸变校正模块接口声明 | En: Interface for the ImageCorrectCalib tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGECORRECTCALIB_H_
#define _IVM_IMAGECORRECTCALIB_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageCorrectCalibModu
    {        /*************************** Params Class Start ***************************/
        // CH: 校正模式 | EN: Correction Mode
        typedef enum _CorrectModelEnum
        {
            // CH: 透视畸变校正 | EN: Perspective Distortion Correction
            CorrectModel_CorrectModelLinear = 0x1,

            // CH: 径向畸变校正 | EN: Radial Distortion Correction
            CorrectModel_CorrectModelRadial = 0x2,

            // CH: 径向透视畸变校正 | EN: Radial Perspective Distortion Correction
            CorrectModel_CorrectModelPersRadial = 0x3,

        }CorrectModelEnum;

        /*  Note: Interface Classes of the parameter of the ImageCorrectCalibParams.  */
        class ImageCorrectCalibParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageCorrectCalibParams() {}
            virtual ~ImageCorrectCalibParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 刷新信号(仅当次执行起效) | EN: Refresh Signal(Only valid for this execution)
            virtual void SetRefreshSignal(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标定文件路径 | EN: Set Calibration File Path
            __declspec(property(put = SetCalibPath, get = GetCalibPath)) const char* CalibPath;

            virtual const char* GetCalibPath() = 0;

            virtual void SetCalibPath(const char* value) = 0;

            // CH: 校正模式 | EN: Correction Mode
            __declspec(property(put = SetCorrectModel, get = GetCorrectModel)) CorrectModelEnum CorrectModel;

            virtual CorrectModelEnum GetCorrectModel() = 0;

            virtual void SetCorrectModel(CorrectModelEnum value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageCorrectCalibResults.  */
        class ImageCorrectCalibResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageCorrectCalibResults() {}
            virtual ~ImageCorrectCalibResults() {}

        public:
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
            /**
             * @brief 获取畸变矫正图像
             * @param 无
             * @return 畸变矫正图像
             * @par 注解
             * 无
             */
            virtual ImageBaseData GetOutputImage() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageCorrectCalib tool.  */
        class IMVSImageCorrectCalibModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageCorrectCalibModuTool() {}
            virtual ~IMVSImageCorrectCalibModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageCorrectCalibParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageCorrectCalibResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageCorrectCalibModuTool(IMVSImageCorrectCalibModuTool&);
            IMVSImageCorrectCalibModuTool& operator=(IMVSImageCorrectCalibModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageCorrectCalib.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageCorrectCalibModu::IMVSImageCorrectCalibModuTool * __stdcall GetImageCorrectCalibToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGECORRECTCALIB_H_
