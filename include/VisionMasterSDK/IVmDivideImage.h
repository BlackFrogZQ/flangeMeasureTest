/***************************************************************************************************
 * File：IVmDivideImage.h
 * Note：CH: 划片拆分模块模块接口声明 | En: Interface for the DivideImage tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_DIVIDEIMAGE_H_
#define _IVM_DIVIDEIMAGE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSDivideImageModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class DivideImageRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the DivideImageParams.  */
        class DivideImageParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DivideImageParams() {}
            virtual ~DivideImageParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual DivideImageRoiManager* GetModuRoiManager() = 0;

            // CH: X方向划片数 | EN: Number of divisions in X direction
            __declspec(property(put = SetNumX, get = GetNumX)) int NumX;

            virtual int GetNumX() = 0;

            virtual void SetNumX(int value) = 0;

            // CH: Y方向划片数 | EN: Number of divisions in Y direction
            __declspec(property(put = SetNumY, get = GetNumY)) int NumY;

            virtual int GetNumY() = 0;

            virtual void SetNumY(int value) = 0;

            // CH: X方向重叠率 | EN: X-direction overlap rate
            __declspec(property(put = SetOverlaprateX, get = GetOverlaprateX)) int OverlaprateX;

            virtual int GetOverlaprateX() = 0;

            virtual void SetOverlaprateX(int value) = 0;

            // CH: Y方向重叠率 | EN: Y-direction overlap rate
            __declspec(property(put = SetOverlaprateY, get = GetOverlaprateY)) int OverlaprateY;

            virtual int GetOverlaprateY() = 0;

            virtual void SetOverlaprateY(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the DivideImageResults.  */
        class DivideImageResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DivideImageResults() {}
            virtual ~DivideImageResults() {}

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
            * 划片个数
            * @par 权限
            * 只读
            */
            virtual int GetDivideCount() = 0;
            /**
            * @par 说明
            * 检测区域
            * @par 权限
            * 只读
            */
            virtual RectBox GetROI() = 0;
            /**
            * @par 说明
            * 划片BOX
            * @par 权限
            * 只读
            */
            virtual RectBox GetDivideRectAt(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the DivideImage tool.  */
        class IMVSDivideImageModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSDivideImageModuTool() {}
            virtual ~IMVSDivideImageModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual DivideImageParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual DivideImageResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSDivideImageModuTool(IMVSDivideImageModuTool&);
            IMVSDivideImageModuTool& operator=(IMVSDivideImageModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for DivideImage.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSDivideImageModu::IMVSDivideImageModuTool * __stdcall GetDivideImageToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_DIVIDEIMAGE_H_
