/***************************************************************************************************
 * File：IVmMultiImageFusion.h
 * Note：CH: 多图融合模块接口声明 | En: Interface for the MultiImageFusion tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MULTIIMAGEFUSION_H_
#define _IVM_MULTIIMAGEFUSION_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMultiImageFusionModu
    {        /*************************** Params Class Start ***************************/
        // CH: 输出图像类型 | EN: Output Image Type
        typedef enum _ResultTypeEnum
        {
            // CH: 反射 | EN: Reflection
            ResultType_Albedo = 0x1,

            // CH: 阴影 | EN: Shadow
            ResultType_Shade = 0x2,

            // CH: 全部 | EN: All
            ResultType_All = 0x3,

        }ResultTypeEnum;

        // CH: 方向增强类型 | EN: Direction Enhancement Type
        typedef enum _DirEnhanceTypeEnum
        {
            // CH: 无 | EN: NoMirror
            DirEnhanceType_None = 0x0,

            // CH: X方向 | EN: X-direction
            DirEnhanceType_XDirection = 0x1,

            // CH: Y方向 | EN: Y-direction
            DirEnhanceType_YDirection = 0x2,

        }DirEnhanceTypeEnum;

        /*  Note: Interface Classes of the parameter of the MultiImageFusionParams.  */
        class MultiImageFusionParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MultiImageFusionParams() {}
            virtual ~MultiImageFusionParams() {}

        public:

            // CH: 图像数量(仅当次执行起效) | EN: Image Quantity(Only valid for this execution)
            virtual void SetImageCount(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入图像0(仅当次执行起效) | EN: InImage0(Only valid for this execution)
            virtual void SetInImage0(ImageBaseData* pInputValue) = 0;

            // CH: 分布角0(仅当次执行起效) | EN: Distribution0(Only valid for this execution)
            virtual void SetInImage0Distribution(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 照射角0(仅当次执行起效) | EN: Irradiation0(Only valid for this execution)
            virtual void SetInImage0Irradiation(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入图像1(仅当次执行起效) | EN: InImage1(Only valid for this execution)
            virtual void SetInImage1(ImageBaseData* pInputValue) = 0;

            // CH: 分布角1(仅当次执行起效) | EN: Distribution1(Only valid for this execution)
            virtual void SetInImage1Distribution(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 照射角1(仅当次执行起效) | EN: Irradiation1(Only valid for this execution)
            virtual void SetInImage1Irradiation(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入图像2(仅当次执行起效) | EN: InImage2(Only valid for this execution)
            virtual void SetInImage2(ImageBaseData* pInputValue) = 0;

            // CH: 分布角2(仅当次执行起效) | EN: Distribution2(Only valid for this execution)
            virtual void SetInImage2Distribution(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 照射角2(仅当次执行起效) | EN: Irradiation2(Only valid for this execution)
            virtual void SetInImage2Irradiation(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入图像3(仅当次执行起效) | EN: InImage3(Only valid for this execution)
            virtual void SetInImage3(ImageBaseData* pInputValue) = 0;

            // CH: 分布角3(仅当次执行起效) | EN: Distribution3(Only valid for this execution)
            virtual void SetInImage3Distribution(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 照射角3(仅当次执行起效) | EN: Irradiation3(Only valid for this execution)
            virtual void SetInImage3Irradiation(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入图像4(仅当次执行起效) | EN: InImage4(Only valid for this execution)
            virtual void SetInImage4(ImageBaseData* pInputValue) = 0;

            // CH: 分布角4(仅当次执行起效) | EN: Distribution4(Only valid for this execution)
            virtual void SetInImage4Distribution(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 照射角4(仅当次执行起效) | EN: Irradiation4(Only valid for this execution)
            virtual void SetInImage4Irradiation(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入图像5(仅当次执行起效) | EN: InImage5(Only valid for this execution)
            virtual void SetInImage5(ImageBaseData* pInputValue) = 0;

            // CH: 分布角5(仅当次执行起效) | EN: Distribution5(Only valid for this execution)
            virtual void SetInImage5Distribution(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 照射角5(仅当次执行起效) | EN: Irradiation5(Only valid for this execution)
            virtual void SetInImage5Irradiation(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入图像6(仅当次执行起效) | EN: InImage6(Only valid for this execution)
            virtual void SetInImage6(ImageBaseData* pInputValue) = 0;

            // CH: 分布角6(仅当次执行起效) | EN: Distribution6(Only valid for this execution)
            virtual void SetInImage6Distribution(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 照射角6(仅当次执行起效) | EN: Irradiation6(Only valid for this execution)
            virtual void SetInImage6Irradiation(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入图像7(仅当次执行起效) | EN: InImage7(Only valid for this execution)
            virtual void SetInImage7(ImageBaseData* pInputValue) = 0;

            // CH: 分布角7(仅当次执行起效) | EN: Distribution7(Only valid for this execution)
            virtual void SetInImage7Distribution(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 照射角7(仅当次执行起效) | EN: Irradiation7(Only valid for this execution)
            virtual void SetInImage7Irradiation(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输出图像类型 | EN: Output Image Type
            __declspec(property(put = SetResultType, get = GetResultType)) ResultTypeEnum ResultType;

            virtual ResultTypeEnum GetResultType() = 0;

            virtual void SetResultType(ResultTypeEnum value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetKernelSize, get = GetKernelSize)) int KernelSize;

            virtual int GetKernelSize() = 0;

            virtual void SetKernelSize(int value) = 0;

            // CH: 增强使能 | EN: Enhancement Enable
            __declspec(property(put = SetEnhanceEnable, get = GetEnhanceEnable)) bool EnhanceEnable;

            virtual bool GetEnhanceEnable() = 0;

            virtual void SetEnhanceEnable(bool value) = 0;

            // CH: 背景亮度 | EN: Background Brightness
            __declspec(property(put = SetBrightness, get = GetBrightness)) int Brightness;

            virtual int GetBrightness() = 0;

            virtual void SetBrightness(int value) = 0;

            // CH: 对比系数 | EN: Contrast Coefficient
            __declspec(property(put = SetContrastCoef, get = GetContrastCoef)) int ContrastCoef;

            virtual int GetContrastCoef() = 0;

            virtual void SetContrastCoef(int value) = 0;

            // CH: 方向增强类型 | EN: Direction Enhancement Type
            __declspec(property(put = SetDirEnhanceType, get = GetDirEnhanceType)) DirEnhanceTypeEnum DirEnhanceType;

            virtual DirEnhanceTypeEnum GetDirEnhanceType() = 0;

            virtual void SetDirEnhanceType(DirEnhanceTypeEnum value) = 0;

            // CH: 方向增强等级 | EN: Direction Enhancement Grade
            __declspec(property(put = SetDirEnhanceLevel, get = GetDirEnhanceLevel)) int DirEnhanceLevel;

            virtual int GetDirEnhanceLevel() = 0;

            virtual void SetDirEnhanceLevel(int value) = 0;

            // CH: 光晕去除等级 | EN: Halo Removal Grade
            __declspec(property(put = SetHalationRemoveLevel, get = GetHalationRemoveLevel)) int HalationRemoveLevel;

            virtual int GetHalationRemoveLevel() = 0;

            virtual void SetHalationRemoveLevel(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the MultiImageFusionResults.  */
        class MultiImageFusionResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MultiImageFusionResults() {}
            virtual ~MultiImageFusionResults() {}

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
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;
            /**
             * @brief 获取图像数
             * @return 图像数
             * @par 注解
             * 无
             */
            virtual int GetImageNum() = 0;
            /**
            * @par 说明
            * 图像宽度
            * @par 权限
            * 只读
            */
            virtual int GetImageWidth() = 0;
            /**
            * @par 说明
            * 图像高度
            * @par 权限
            * 只读
            */
            virtual int GetImageHeight() = 0;

            /**
             * @brief 获取反射图像
             * @return 反射图像
             * @par 注解
             * 无
             */
            virtual ImageBaseData GetAlbedoImageCom() = 0;

            /**
             * @brief 获取阴影图像
             * @return 阴影图像
             * @par 注解
             * 无
             */
            virtual ImageBaseData GetShadingImageCom() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the MultiImageFusion tool.  */
        class IMVSMultiImageFusionModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMultiImageFusionModuTool() {}
            virtual ~IMVSMultiImageFusionModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MultiImageFusionParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MultiImageFusionResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSMultiImageFusionModuTool(IMVSMultiImageFusionModuTool&);
            IMVSMultiImageFusionModuTool& operator=(IMVSMultiImageFusionModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MultiImageFusion.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMultiImageFusionModu::IMVSMultiImageFusionModuTool * __stdcall GetMultiImageFusionToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MULTIIMAGEFUSION_H_
