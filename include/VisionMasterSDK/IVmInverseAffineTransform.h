/***************************************************************************************************
 * File：IVmInverseAffineTransform.h
 * Note：CH: 逆仿射变换模块接口声明 | En: Interface for the InverseAffineTransform tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_INVERSEAFFINETRANSFORM_H_
#define _IVM_INVERSEAFFINETRANSFORM_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSInverseAffineTransformModu
    {
        /*************************** Params Class Start ***************************/

        /*  Note: Interface Classes of the RoiManager.  */
        class InverseAffineTransformRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the InverseAffineTransformParams.  */
        class InverseAffineTransformParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit InverseAffineTransformParams() {}
            virtual ~InverseAffineTransformParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像2(仅当次执行起效) | EN: InputImageBack(Only valid for this execution)
			virtual void SetInputImageBack(ImageBaseData* pInputValue) = 0;

			// CH: ROI管理器 | EN: ROI Manager
			virtual InverseAffineTransformRoiManager* GetModuRoiManager() = 0;

            // imagewidth
            virtual void SetImagewidth(float* pInputValue, unsigned int nValueNum) = 0;

            // imageheight
            virtual void SetImageheight(float* pInputValue, unsigned int nValueNum) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the InverseAffineTransformResults.  */
        class InverseAffineTransformResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit InverseAffineTransformResults() {}
            virtual ~InverseAffineTransformResults() {}

        public:
             /**
             * @par 说明
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;

             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;

			 /**
			 * @par 说明
			 * 获取输出图像
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetOutputImage() = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the InverseAffineTransform tool.  */
        class IMVSInverseAffineTransformModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSInverseAffineTransformModuTool() {}
            virtual ~IMVSInverseAffineTransformModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual InverseAffineTransformParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual InverseAffineTransformResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSInverseAffineTransformModuTool(IMVSInverseAffineTransformModuTool&);
            IMVSInverseAffineTransformModuTool& operator=(IMVSInverseAffineTransformModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for InverseAffineTransform.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSInverseAffineTransformModu::IMVSInverseAffineTransformModuTool * __stdcall GetInverseAffineTransformToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_INVERSEAFFINETRANSFORM_H_
