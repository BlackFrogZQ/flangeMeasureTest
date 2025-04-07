/***************************************************************************************************
 * File：IVmSurfaceDefectFilter.h
 * Note：CH: 表面缺陷滤波模块接口声明 | En: Interface for the SurfaceDefectFilter tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_SURFACEDEFECTFILTER_H_
#define _IVM_SURFACEDEFECTFILTER_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSSurfaceDefectFilterModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class SurfaceDefectFilterRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the SurfaceDefectFilterParams.  */
        class SurfaceDefectFilterParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SurfaceDefectFilterParams() {}
            virtual ~SurfaceDefectFilterParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual SurfaceDefectFilterRoiManager* GetModuRoiManager() = 0;

            // CH: 滤波核宽度 | EN: Filter Kernel Width
            __declspec(property(put = SetKerWidth, get = GetKerWidth)) int KerWidth;

            virtual int GetKerWidth() = 0;

            virtual void SetKerWidth(int value) = 0;

            // CH: 滤波核高度 | EN: Filter Kernel Height
            __declspec(property(put = SetKerHeight, get = GetKerHeight)) int KerHeight;

            virtual int GetKerHeight() = 0;

            virtual void SetKerHeight(int value) = 0;

            // CH: 核的数量 | EN: Ker Num
            __declspec(property(put = SetKerNum, get = GetKerNum)) int KerNum;

            virtual int GetKerNum() = 0;

            virtual void SetKerNum(int value) = 0;

            // CH: 标准差 | EN: LumStd
            __declspec(property(put = SetSigma, get = GetSigma)) int Sigma;

            virtual int GetSigma() = 0;

            virtual void SetSigma(int value) = 0;

            // CH: 偏移 | EN: Offset
            __declspec(property(put = SetOffset, get = GetOffset)) int Offset;

            virtual int GetOffset() = 0;

            virtual void SetOffset(int value) = 0;

            // CH: 0度权重 | EN: 0 Angle Weight
            __declspec(property(put = SetWeight0, get = GetWeight0)) double Weight0;

            virtual double GetWeight0() = 0;

            virtual void SetWeight0(double value) = 0;

            // CH: 30度权重 | EN: 30 Angle Weight
            __declspec(property(put = SetWeight1, get = GetWeight1)) double Weight1;

            virtual double GetWeight1() = 0;

            virtual void SetWeight1(double value) = 0;

            // CH: 60度权重 | EN: 60 Angle Weight
            __declspec(property(put = SetWeight2, get = GetWeight2)) double Weight2;

            virtual double GetWeight2() = 0;

            virtual void SetWeight2(double value) = 0;

            // CH: 90度权重 | EN: 90 Angle Weight
            __declspec(property(put = SetWeight3, get = GetWeight3)) double Weight3;

            virtual double GetWeight3() = 0;

            virtual void SetWeight3(double value) = 0;

            // CH: 120度权重 | EN: 120 Angle Weight
            __declspec(property(put = SetWeight4, get = GetWeight4)) double Weight4;

            virtual double GetWeight4() = 0;

            virtual void SetWeight4(double value) = 0;

            // CH: 150度权重 | EN: 150 Angle Weight
            __declspec(property(put = SetWeight5, get = GetWeight5)) double Weight5;

            virtual double GetWeight5() = 0;

            virtual void SetWeight5(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the SurfaceDefectFilterResults.  */
        class SurfaceDefectFilterResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SurfaceDefectFilterResults() {}
            virtual ~SurfaceDefectFilterResults() {}

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
             * 输出图像
             * @par 权限
             * 只读
             */
             virtual ImageBaseData GetOutputImage() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the SurfaceDefectFilter tool.  */
        class IMVSSurfaceDefectFilterModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSSurfaceDefectFilterModuTool() {}
            virtual ~IMVSSurfaceDefectFilterModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual SurfaceDefectFilterParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual SurfaceDefectFilterResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSSurfaceDefectFilterModuTool(IMVSSurfaceDefectFilterModuTool&);
            IMVSSurfaceDefectFilterModuTool& operator=(IMVSSurfaceDefectFilterModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for SurfaceDefectFilter.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSSurfaceDefectFilterModu::IMVSSurfaceDefectFilterModuTool * __stdcall GetSurfaceDefectFilterToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_SURFACEDEFECTFILTER_H_
