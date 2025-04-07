/***************************************************************************************************
 * File：IVmScaleTransform.h
 * Note：CH: 单位转换模块接口声明 | En: Interface for the ScaleTransform tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_SCALETRANSFORM_H_
#define _IVM_SCALETRANSFORM_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSScaleTransformModu
    {        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the ScaleTransformParams.  */
        class ScaleTransformParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ScaleTransformParams() {}
            virtual ~ScaleTransformParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 像素间距(仅当次执行起效) | EN: ImageDist(Only valid for this execution)
            virtual void SetImageDist(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 刷新信号(仅当次执行起效) | EN: Refresh Signal(Only valid for this execution)
            virtual void SetRefreshSignal(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 像素当量修正系数(仅当次执行起效) | EN: Pixel Equivalent Correct Info(Only valid for this execution)
            virtual void SetPixelEquivalentCorrectInfo(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 加载标定文件 | EN: Load Calibration File
            __declspec(property(put = SetLoadCalibPath, get = GetLoadCalibPath)) const char* LoadCalibPath;

            virtual const char* GetLoadCalibPath() = 0;

            virtual void SetLoadCalibPath(const char* value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ScaleTransformResults.  */
        class ScaleTransformResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ScaleTransformResults() {}
            virtual ~ScaleTransformResults() {}

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
             * 单像素精度
             * @par 权限
             * 读写
             */
            virtual float GetPixelScale() = 0;

            /**
             * @par 说明
             * 转换结果
             * @par 权限
             * 读写
             */
            virtual float GetPhyDist() = 0;

            /**
             * @par 说明
             * 像素距离
             * @par 权限
             * 读写
             */
            virtual float GetPixDist() = 0;

            /**
             * @par 说明
             * 平移X
             * @par 权限
             * 读写
             */
            virtual float GetTranslateX() = 0;

            /**
             * @par 说明
             * 平移Y
             * @par 权限
             * 读写
             */
            virtual float GetTranslateY() = 0;

            /**
             * @par 说明
             * 旋转
             * @par 权限
             * 读写
             */
            virtual float GetRotate() = 0;

            /**
             * @par 说明
             * 尺度
             * @par 权限
             * 读写
             */
            virtual float GetScale() = 0;

            /**
             * @par 说明
             * 斜切
             * @par 权限
             * 读写
             */
            virtual float GetSkew() = 0;

            /**
             * @par 说明
             * 宽高比
             * @par 权限
             * 读写
             */
            virtual float GetAspect() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ScaleTransform tool.  */
        class IMVSScaleTransformModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSScaleTransformModuTool() {}
            virtual ~IMVSScaleTransformModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ScaleTransformParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ScaleTransformResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSScaleTransformModuTool(IMVSScaleTransformModuTool&);
            IMVSScaleTransformModuTool& operator=(IMVSScaleTransformModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ScaleTransform.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSScaleTransformModu::IMVSScaleTransformModuTool * __stdcall GetScaleTransformToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_SCALETRANSFORM_H_
