/***************************************************************************************************
 * File：IVmImageCalib.h
 * Note：CH: 畸变标定模块接口声明 | En: Interface for the ImageCalib tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGECALIB_H_
#define _IVM_IMAGECALIB_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageCalibModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 畸变类型 | EN: Distortion Type
        typedef enum _CorrectModelEnum
        {
            // CH: 透视畸变 | EN: Perspective Distortion
            CorrectModel_CorrectModelLinear = 0x1,

            // CH: 径向畸变 | EN: Radial Distortion
            CorrectModel_CorrectModelRadial = 0x2,

            // CH: 径向透视畸变 | EN: Radial Perspective Distortion
            CorrectModel_CorrectModelPersRadial = 0x3,

        }CorrectModelEnum;

        // CH: 标定板类型 | EN: Calibration Board Type
        typedef enum _CalibBoardTypeEnum
        {
            // CH: 棋盘格标定板 | EN: Checkboard Calibration Board
            CalibBoardType_TypeChecker = 0x1,

            // CH: 圆标定板 | EN: Round Calibration Board
            CalibBoardType_TypeCircle = 0x2,

        }CalibBoardTypeEnum;

        // CH: 自由度 | EN: DOF
        typedef enum _HomoFreedomEnum
        {
            // CH: 缩放、旋转、纵横比、倾斜、平移及透射 | EN: Scale、Rotation、Aspect Ratio、Tilt、Translation and Transmission
            HomoFreedom_Perspective = 0x1,

            // CH: 缩放、旋转、纵横比、倾斜及平移 | EN: Scale、Rotation、Aspect Ratio、Tilt and Translation
            HomoFreedom_Affine = 0x2,

            // CH: 缩放、旋转及平移 | EN: Scale、Rotation and Translation
            HomoFreedom_Similarity = 0x3,

        }HomoFreedomEnum;

        // CH: 中值滤波状态 | EN: Median Filtering State
        typedef enum _FilterStatusEnum
        {
            // CH: 执行滤波 | EN: Execution Filtering
            FilterStatus_FilterStateTure = 0x1,

            // CH: 无滤波 | EN: No Filter
            FilterStatus_FilterStateFalse = 0x2,

        }FilterStatusEnum;

        // CH: 亚像素窗口 | EN: Sub-pixel window
        typedef enum _SubpixelWinAutoEnum
        {
            // CH: 自适应 | EN: Self-Adaption
            SubpixelWinAuto_SubpixelWinSizeAuto = 0x1,

            // CH: 设置值 | EN: Set
            SubpixelWinAuto_SubpixelWinSizeUser = 0x2,

        }SubpixelWinAutoEnum;

        // CH: 圆点类型 | EN: Dot Type
        typedef enum _CircleBoardCircleModeEnum
        {
            // CH: 白底黑圆 | EN: Black Dot with White Background
            CircleBoardCircleMode_CircleModeBlack = 0x1,

            // CH: 黑底白圆 | EN: White Dot with Black Background
            CircleBoardCircleMode_CircleModeWhite = 0x2,

        }CircleBoardCircleModeEnum;

        // CH: 权重函数 | EN: Weighting Function
        typedef enum _CalibBoardWeightFunEnum
        {
            // CH: 最小二乘 | EN: Least Squares
            CalibBoardWeightFun_LeastSqure = 0x1,

            // CH: Huber | EN: Huber
            CalibBoardWeightFun_Huber = 0x2,

            // CH: Tukey | EN: Tukey
            CalibBoardWeightFun_Tukey = 0x3,

        }CalibBoardWeightFunEnum;

        /*  Note: Interface Classes of the parameter of the ImageCalibParams.  */
        class ImageCalibParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageCalibParams() {}
            virtual ~ImageCalibParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 校正中心点(仅当次执行起效) | EN: CorrectCenterPoint(Only valid for this execution)
            virtual void SetCorrectCenterPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标定文件路径 | EN: Set Calibration File Path
            __declspec(property(put = SetCalibPathName, get = GetCalibPathName)) const char* CalibPathName;

            virtual const char* GetCalibPathName() = 0;

            virtual void SetCalibPathName(const char* value) = 0;

            // CH: 更新文件 | EN: Update File
            __declspec(property(put = SetRefreshFileEnable, get = GetRefreshFileEnable)) bool RefreshFileEnable;

            virtual bool GetRefreshFileEnable() = 0;

            virtual void SetRefreshFileEnable(bool value) = 0;

            // CH: 畸变类型 | EN: Distortion Type
            __declspec(property(put = SetCorrectModel, get = GetCorrectModel)) CorrectModelEnum CorrectModel;

            virtual CorrectModelEnum GetCorrectModel() = 0;

            virtual void SetCorrectModel(CorrectModelEnum value) = 0;

            // CH: 标定板类型 | EN: Calibration Board Type
            __declspec(property(put = SetCalibBoardType, get = GetCalibBoardType)) CalibBoardTypeEnum CalibBoardType;

            virtual CalibBoardTypeEnum GetCalibBoardType() = 0;

            virtual void SetCalibBoardType(CalibBoardTypeEnum value) = 0;

            // CH: 自由度 | EN: DOF
            __declspec(property(put = SetHomoFreedom, get = GetHomoFreedom)) HomoFreedomEnum HomoFreedom;

            virtual HomoFreedomEnum GetHomoFreedom() = 0;

            virtual void SetHomoFreedom(HomoFreedomEnum value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: 灰度对比度 | EN: Grayscale Contrast
            __declspec(property(put = SetGrayContrast, get = GetGrayContrast)) int GrayContrast;

            virtual int GetGrayContrast() = 0;

            virtual void SetGrayContrast(int value) = 0;

            // CH: 中值滤波状态 | EN: Median Filtering State
            __declspec(property(put = SetFilterStatus, get = GetFilterStatus)) FilterStatusEnum FilterStatus;

            virtual FilterStatusEnum GetFilterStatus() = 0;

            virtual void SetFilterStatus(FilterStatusEnum value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: 亚像素窗口 | EN: Sub-pixel window
            __declspec(property(put = SetSubpixelWinAuto, get = GetSubpixelWinAuto)) SubpixelWinAutoEnum SubpixelWinAuto;

            virtual SubpixelWinAutoEnum GetSubpixelWinAuto() = 0;

            virtual void SetSubpixelWinAuto(SubpixelWinAutoEnum value) = 0;

            // CH: 设置窗口大小 | EN: Set window size
            __declspec(property(put = SetSubPixelWindowSize, get = GetSubPixelWindowSize)) int SubPixelWindowSize;

            virtual int GetSubPixelWindowSize() = 0;

            virtual void SetSubPixelWindowSize(int value) = 0;

            // CH: 点圆度 | EN: Dot Circularity
            __declspec(property(put = SetCircularity, get = GetCircularity)) int Circularity;

            virtual int GetCircularity() = 0;

            virtual void SetCircularity(int value) = 0;

            // CH: 边缘提取阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeThreshLow, get = GetEdgeThreshLow)) int EdgeThreshLow;

            virtual int GetEdgeThreshLow() = 0;

            virtual void SetEdgeThreshLow(int value) = 0;

            // CH: 边缘提取阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeThreshHigh, get = GetEdgeThreshHigh)) int EdgeThreshHigh;

            virtual int GetEdgeThreshHigh() = 0;

            virtual void SetEdgeThreshHigh(int value) = 0;

            // CH: 圆点类型 | EN: Dot Type
            __declspec(property(put = SetCircleBoardCircleMode, get = GetCircleBoardCircleMode)) CircleBoardCircleModeEnum CircleBoardCircleMode;

            virtual CircleBoardCircleModeEnum GetCircleBoardCircleMode() = 0;

            virtual void SetCircleBoardCircleMode(CircleBoardCircleModeEnum value) = 0;

            // CH: 权重函数 | EN: Weighting Function
            __declspec(property(put = SetCalibBoardWeightFun, get = GetCalibBoardWeightFun)) CalibBoardWeightFunEnum CalibBoardWeightFun;

            virtual CalibBoardWeightFunEnum GetCalibBoardWeightFun() = 0;

            virtual void SetCalibBoardWeightFun(CalibBoardWeightFunEnum value) = 0;

            // CH: 权重系数 | EN: Weighting Coefficient
            __declspec(property(put = SetWeightFactor, get = GetWeightFactor)) int WeightFactor;

            virtual int GetWeightFactor() = 0;

            virtual void SetWeightFactor(int value) = 0;

            // CH: 距离阈值 | EN: Distance Threshold
            __declspec(property(put = SetDistThreshold, get = GetDistThreshold)) int DistThreshold;

            virtual int GetDistThreshold() = 0;

            virtual void SetDistThreshold(int value) = 0;

            // CH: 采样率 | EN: Sampling Rate
            __declspec(property(put = SetSampleRatio, get = GetSampleRatio)) int SampleRatio;

            virtual int GetSampleRatio() = 0;

            virtual void SetSampleRatio(int value) = 0;

            // CH: 生成标定文件 | EN: Create Calibration File
            virtual int DoSaveFile(IN const char * const strValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes for describing distort IImage locate process result information.  */
        class IImageCalibLocateInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IImageCalibLocateInfo() {}
            virtual ~IImageCalibLocateInfo() {}

        public:
            ///< Property
            /**
             * @par 说明
             * 标定点数量
             * @par 权限
             * 只读
             */
            virtual int GetCalibPointNum() = 0;
            ///< Method
            /**
             * @brief 获取标定点的图像坐标
             * @param nIndex [in] 查询点的索引值，从0开始编码
             * @return 点坐标
             * @par 注解
             * 无
             */
            virtual MVD_POINT_F GetCalibPointImageCoordinate(int nIndex) = 0;
        };

        /*  Note: Interface Classes for describing distort IImage homo process result information.  */
        class IImageCalibHomoEstInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IImageCalibHomoEstInfo() {}
            virtual ~IImageCalibHomoEstInfo() {}

        public:
            ///< Property
            /**
             * @par 说明
             * 估计误差
             * @par 权限
             * 只读
             */
            virtual float GetEstimationError() = 0;
        };

        /*  Note: Interface Classes of the result of the ImageCalibResults.  */
        class ImageCalibResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageCalibResults() {}
            virtual ~ImageCalibResults() {}

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
             * @brief 描述标定板位置信息
             * @param 无
             * @return 标定板位置信息
             * @par 注解
             * 无
             */
            virtual IImageCalibLocateInfo* GetLocateInfo() = 0;
            /**
             * @brief 标定板Homo估计信息
             * @param 无
             * @return Homo估计信息
             * @par 注解
             * 无
             */
            virtual IImageCalibHomoEstInfo* GetHomoEstInfo() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageCalib tool.  */
        class IMVSImageCalibModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageCalibModuTool() {}
            virtual ~IMVSImageCalibModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageCalibParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageCalibResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageCalibModuTool(IMVSImageCalibModuTool&);
            IMVSImageCalibModuTool& operator=(IMVSImageCalibModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageCalib.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageCalibModu::IMVSImageCalibModuTool * __stdcall GetImageCalibToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGECALIB_H_
