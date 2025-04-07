/***************************************************************************************************
 * File：IVmImageNormlize.h
 * Note：CH: 图像归一化模块接口声明 | En: Interface for the ImageNormlize tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGENORMLIZE_H_
#define _IVM_IMAGENORMLIZE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageNormlizeModu
    {        /*************************** Params Class Start ***************************/
        // CH: 归一化类型 | EN: Normalization Type
        typedef enum _NormlizeTypeEnum
        {
            // CH: 直方图均衡化 | EN: Histogram Equalization
            NormlizeType_HistEqual = 0x1,

            // CH: 直方图归一化 | EN: Histogram Normalization
            NormlizeType_HistMatch = 0x2,

            // CH: 均值标准差归一化 | EN: Standard Deviation Normalization
            NormlizeType_MeanStd = 0x3,

        }NormlizeTypeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ImageNormlizeRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ImageNormlizeParams.  */
        class ImageNormlizeParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageNormlizeParams() {}
            virtual ~ImageNormlizeParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ImageNormlizeRoiManager* GetModuRoiManager() = 0;

            // CH: 归一化类型 | EN: Normalization Type
            __declspec(property(put = SetNormlizeType, get = GetNormlizeType)) NormlizeTypeEnum NormlizeType;

            virtual NormlizeTypeEnum GetNormlizeType() = 0;

            virtual void SetNormlizeType(NormlizeTypeEnum value) = 0;

            // CH: 均值 | EN: LumMean
            __declspec(property(put = SetMeanVal, get = GetMeanVal)) double MeanVal;

            virtual double GetMeanVal() = 0;

            virtual void SetMeanVal(double value) = 0;

            // CH: 标准差 | EN: LumStd
            __declspec(property(put = SetStdVal, get = GetStdVal)) double StdVal;

            virtual double GetStdVal() = 0;

            virtual void SetStdVal(double value) = 0;

            // CH: 直方图比例 | EN: Histogram Ratio
            __declspec(property(put = SetLeftClipPercent, get = GetLeftClipPercent)) double LeftClipPercent;

            virtual double GetLeftClipPercent() = 0;

            virtual void SetLeftClipPercent(double value) = 0;

            // CH: 直方图比例 | EN: Histogram Ratio
            __declspec(property(put = SetRightClipPercent, get = GetRightClipPercent)) double RightClipPercent;

            virtual double GetRightClipPercent() = 0;

            virtual void SetRightClipPercent(double value) = 0;

            // CH: 灰度值范围 | EN: Gray Value Range
            __declspec(property(put = SetDstLeftPos, get = GetDstLeftPos)) double DstLeftPos;

            virtual double GetDstLeftPos() = 0;

            virtual void SetDstLeftPos(double value) = 0;

            // CH: 灰度值范围 | EN: Gray Value Range
            __declspec(property(put = SetDstRightPos, get = GetDstRightPos)) double DstRightPos;

            virtual double GetDstRightPos() = 0;

            virtual void SetDstRightPos(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageNormlizeResults.  */
        class ImageNormlizeResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageNormlizeResults() {}
            virtual ~ImageNormlizeResults() {}

        public:
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
             * 输出掩膜
             * @par 权限
             * 只读
             */
             virtual ImageBaseData GetOutputMask() = 0;

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
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageNormlize tool.  */
        class IMVSImageNormlizeModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageNormlizeModuTool() {}
            virtual ~IMVSImageNormlizeModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageNormlizeParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageNormlizeResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageNormlizeModuTool(IMVSImageNormlizeModuTool&);
            IMVSImageNormlizeModuTool& operator=(IMVSImageNormlizeModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageNormlize.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageNormlizeModu::IMVSImageNormlizeModuTool * __stdcall GetImageNormlizeToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGENORMLIZE_H_
