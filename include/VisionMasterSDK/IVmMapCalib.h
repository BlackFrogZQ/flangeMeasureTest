/***************************************************************************************************
 * File：IVmMapCalib.h
 * Note：CH: 映射标定模块接口声明 | En: Interface for the MapCalib tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MAPCALIB_H_
#define _IVM_MAPCALIB_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMapCalibModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 输入方式 | EN: Input Mode
        typedef enum _InputTypeEnum
        {
            // CH: 图像输入 | EN: Image Input
            InputType_InputImage = 0x1,

            // CH: 文件输入 | EN: File Input
            InputType_InputFile = 0x2,

        }InputTypeEnum;

        // CH: 标定板类型 | EN: Calibration Board Type
        typedef enum _CalibBoardTypeEnum
        {
            // CH: 海康标定板I型 | EN: Hikvision I Calibration Board
            CalibBoardType_TypeHKI = 0x7,

            // CH: 海康标定板II型 | EN: Hikvision II Calibration Board
            CalibBoardType_TypeHKII = 0x6,

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

        // CH: 权重函数 | EN: Weighting Function
        typedef enum _WeightFunEnum
        {
            // CH: 最小二乘 | EN: Least Squares
            WeightFun_LeastSqure = 0x1,

            // CH: Huber | EN: Huber
            WeightFun_Huber = 0x2,

            // CH: Tukey | EN: Tukey
            WeightFun_Tukey = 0x3,

        }WeightFunEnum;

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

        // CH: 中值滤波状态 | EN: Median Filtering State
        typedef enum _FilterStatus2Enum
        {
            // CH: 执行滤波 | EN: Execution Filtering
            FilterStatus2_FilterStateTure = 0x1,

            // CH: 无滤波 | EN: No Filter
            FilterStatus2_FilterStateFalse = 0x2,

        }FilterStatus2Enum;

        // CH: 亚像素窗口 | EN: Sub-pixel window
        typedef enum _SubpixelWinAuto2Enum
        {
            // CH: 自适应 | EN: Self-Adaption
            SubpixelWinAuto2_SubpixelWinSizeAuto = 0x1,

            // CH: 设置值 | EN: Set
            SubpixelWinAuto2_SubpixelWinSizeUser = 0x2,

        }SubpixelWinAuto2Enum;

        /*  Note: Interface Classes of the parameter of the MapCalibParams.  */
        class MapCalibParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MapCalibParams() {}
            virtual ~MapCalibParams() {}

        public:

            // CH: 输入图像1(仅当次执行起效) | EN: InputImage1(Only valid for this execution)
            virtual void SetInputImage1(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像2(仅当次执行起效) | EN: InputImage2(Only valid for this execution)
            virtual void SetInputImage2(ImageBaseData* pInputValue) = 0;

            // CH: 刷新信号(仅当次执行起效) | EN: Refresh Signal(Only valid for this execution)
            virtual void SetRefreshSignal(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 物理点(仅当次执行起效) | EN: Physical Point(Only valid for this execution)
            virtual void SetPhysicalPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 物理角度(仅当次执行起效) | EN: World Rotate Angle(Only valid for this execution)
            virtual void SetWorldRotateAngle(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 外部输入字符(仅当次执行起效) | EN: External Input Character(Only valid for this execution)
            virtual void SetTrigger(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // TeachFlagInput
            virtual void SetTeachFlagInput(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入方式 | EN: Input Mode
            __declspec(property(put = SetInputType, get = GetInputType)) InputTypeEnum InputType;

            virtual InputTypeEnum GetInputType() = 0;

            virtual void SetInputType(InputTypeEnum value) = 0;

            // CH: 示教 | EN: Demonstration
            __declspec(property(put = SetTeachEnable, get = GetTeachEnable)) bool TeachEnable;

            virtual bool GetTeachEnable() = 0;

            virtual void SetTeachEnable(bool value) = 0;

            // CH: 外部触发字符 | EN: External Triggered Character
            __declspec(property(put = SetTeachFlag, get = GetTeachFlag)) const char* TeachFlag;

            virtual const char* GetTeachFlag() = 0;

            virtual void SetTeachFlag(const char* value) = 0;

            // CH: 标定文件1 | EN: Calibration File1
            __declspec(property(put = SetCalibPath0, get = GetCalibPath0)) const char* CalibPath0;

            virtual const char* GetCalibPath0() = 0;

            virtual void SetCalibPath0(const char* value) = 0;

            // CH: 标定文件2 | EN: Calibration File2
            __declspec(property(put = SetCalibPath1, get = GetCalibPath1)) const char* CalibPath1;

            virtual const char* GetCalibPath1() = 0;

            virtual void SetCalibPath1(const char* value) = 0;

            // CH: 标定文件路径 | EN: Set Calibration File Path
            __declspec(property(put = SetCalibPathName, get = GetCalibPathName)) const char* CalibPathName;

            virtual const char* GetCalibPathName() = 0;

            virtual void SetCalibPathName(const char* value) = 0;

            // CH: 更新文件 | EN: Update File
            __declspec(property(put = SetRefreshFileEnable, get = GetRefreshFileEnable)) bool RefreshFileEnable;

            virtual bool GetRefreshFileEnable() = 0;

            virtual void SetRefreshFileEnable(bool value) = 0;

            // CH: 标定板类型 | EN: Calibration Board Type
            __declspec(property(put = SetCalibBoardType, get = GetCalibBoardType)) CalibBoardTypeEnum CalibBoardType;

            virtual CalibBoardTypeEnum GetCalibBoardType() = 0;

            virtual void SetCalibBoardType(CalibBoardTypeEnum value) = 0;

            // CH: 自由度 | EN: DOF
            __declspec(property(put = SetHomoFreedom, get = GetHomoFreedom)) HomoFreedomEnum HomoFreedom;

            virtual HomoFreedomEnum GetHomoFreedom() = 0;

            virtual void SetHomoFreedom(HomoFreedomEnum value) = 0;

            // CH: 权重函数 | EN: Weighting Function
            __declspec(property(put = SetWeightFun, get = GetWeightFun)) WeightFunEnum WeightFun;

            virtual WeightFunEnum GetWeightFun() = 0;

            virtual void SetWeightFun(WeightFunEnum value) = 0;

            // CH: 权重系数 | EN: Weighting Coefficient
            __declspec(property(put = SetWeightFactor, get = GetWeightFactor)) int WeightFactor;

            virtual int GetWeightFactor() = 0;

            virtual void SetWeightFactor(int value) = 0;

            // CH: 灰度对比度 | EN: Grayscale Contrast
            __declspec(property(put = SetGrayContrast, get = GetGrayContrast)) int GrayContrast;

            virtual int GetGrayContrast() = 0;

            virtual void SetGrayContrast(int value) = 0;

            // CH: 中值滤波状态 | EN: Median Filtering State
            __declspec(property(put = SetFilterStatus, get = GetFilterStatus)) FilterStatusEnum FilterStatus;

            virtual FilterStatusEnum GetFilterStatus() = 0;

            virtual void SetFilterStatus(FilterStatusEnum value) = 0;

            // CH: 亚像素窗口 | EN: Sub-pixel window
            __declspec(property(put = SetSubpixelWinAuto, get = GetSubpixelWinAuto)) SubpixelWinAutoEnum SubpixelWinAuto;

            virtual SubpixelWinAutoEnum GetSubpixelWinAuto() = 0;

            virtual void SetSubpixelWinAuto(SubpixelWinAutoEnum value) = 0;

            // CH: 设置窗口大小 | EN: Set window size
            __declspec(property(put = SetSubPixelWindowSize, get = GetSubPixelWindowSize)) int SubPixelWindowSize;

            virtual int GetSubPixelWindowSize() = 0;

            virtual void SetSubPixelWindowSize(int value) = 0;

            // CH: 灰度对比度 | EN: Grayscale Contrast
            __declspec(property(put = SetGrayContrast2, get = GetGrayContrast2)) int GrayContrast2;

            virtual int GetGrayContrast2() = 0;

            virtual void SetGrayContrast2(int value) = 0;

            // CH: 中值滤波状态 | EN: Median Filtering State
            __declspec(property(put = SetFilterStatus2, get = GetFilterStatus2)) FilterStatus2Enum FilterStatus2;

            virtual FilterStatus2Enum GetFilterStatus2() = 0;

            virtual void SetFilterStatus2(FilterStatus2Enum value) = 0;

            // CH: 亚像素窗口 | EN: Sub-pixel window
            __declspec(property(put = SetSubpixelWinAuto2, get = GetSubpixelWinAuto2)) SubpixelWinAuto2Enum SubpixelWinAuto2;

            virtual SubpixelWinAuto2Enum GetSubpixelWinAuto2() = 0;

            virtual void SetSubpixelWinAuto2(SubpixelWinAuto2Enum value) = 0;

            // CH: 设置窗口大小 | EN: Set window size
            __declspec(property(put = SetSubPixelWindowSize2, get = GetSubPixelWindowSize2)) int SubPixelWindowSize2;

            virtual int GetSubPixelWindowSize2() = 0;

            virtual void SetSubPixelWindowSize2(int value) = 0;

            // CH: 生成标定文件 | EN: Create Calibration File
            virtual int DoSaveFile(IN const char * const strValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        class ICalibPointsInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit ICalibPointsInfo() {}
            virtual ~ICalibPointsInfo() {}

        public:
            ///< Property
            /**
             * @par 说明
             * 总角点数量
             * @par 权限
             * 读写
             */
            virtual int GetPointNum() = 0;

            /**
             * @par 说明
             * 角点图像坐标集合
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F* GetImageCoordinates() = 0;
        };

        class ITwoImageMapCalibExtraInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit ITwoImageMapCalibExtraInfo() {}
            virtual ~ITwoImageMapCalibExtraInfo() {}

        public:
            ///< Property
            /**
             * @par 说明
             * 图像的标定状态
             * @par 权限
             * 只读
             */
            virtual int GetSourceImageCalibStatus() = 0;

            /**
             * @par 说明
             * 图像的标定状态
             * @par 权限
             * 只读
             */
            virtual int GetTargetImageCalibStatus() = 0;

            /**
             * @par 说明
             * 图像的单像素精度
             * @par 权限
             * 只读
             */
            virtual float GetSourceImageScale() = 0;

            /**
             * @par 说明
             * 图像的单像素精度
             * @par 权限
             * 只读
             */
            virtual float GetTargetImageScale() = 0;

            /**
             * @par 说明
             * 映射误差
             * @par 权限
             * 只读
             */
            virtual float GetMapError() = 0;

            /**
             * @par 说明
             * 当前图像的角点集
             * @par 权限
             * 只读
             */
            virtual ICalibPointsInfo* GetSourceImagePoints() = 0;

            /**
             * @par 说明
             * 目标图像的角点集
             * @par 权限
             * 只读
             */
            virtual ICalibPointsInfo* GetTargetImagePoints() = 0;

            /**
             * @par 说明
             * 当前图像角点映射到目标图像内的角点集
             * @par 权限
             * 只读
             */
            virtual ICalibPointsInfo* GetProjectionPoints() = 0;
        };

        /*  Note: Interface Classes of the result of the MapCalibResults.  */
        class MapCalibResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MapCalibResults() {}
            virtual ~MapCalibResults() {}

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
             * 标定状态
             * @par 权限
             * 只读
             */
             virtual int GetCalibStatus() = 0;
            /**
             * @par 说明
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI(int nIndex) = 0;
            ///< Property
            /**
             * @par 说明
             * x方向比例
             * @par 权限
             * 只读
             */
            virtual float GetXRatio() = 0;

            /**
             * @par 说明
             * y方向比例
             * @par 权限
             * 只读
             */
            virtual float GetYRatio() = 0;

            /**
             * @par 说明
             * 两张图像映射标定模式下的额外输出信息
             * @par 权限
             * 只读
             */
            virtual ITwoImageMapCalibExtraInfo* GetTwoImageModeExtraInfo() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the MapCalib tool.  */
        class IMVSMapCalibModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMapCalibModuTool() {}
            virtual ~IMVSMapCalibModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MapCalibParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MapCalibResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSMapCalibModuTool(IMVSMapCalibModuTool&);
            IMVSMapCalibModuTool& operator=(IMVSMapCalibModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MapCalib.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMapCalibModu::IMVSMapCalibModuTool * __stdcall GetMapCalibToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MAPCALIB_H_
