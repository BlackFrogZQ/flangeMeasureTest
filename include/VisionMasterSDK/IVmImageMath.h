/***************************************************************************************************
 * File：IVmImageMath.h
 * Note：CH: 图像运算模块接口声明 | En: Interface for the ImageMath tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGEMATH_H_
#define _IVM_IMAGEMATH_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImageMathModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 运算类型 | EN: Calc Type
        typedef enum _ArithmeticTypeEnum
        {
            // CH: 图像加 | EN: Addition
            ArithmeticType_Add = 0x1,

            // CH: 图像减 | EN: Substraction
            ArithmeticType_Sub = 0x2,

            // CH: 图像绝对差 | EN: Absolute Difference
            ArithmeticType_AbsDiff = 0x3,

            // CH: 两者最大值 | EN: Max Value
            ArithmeticType_Max = 0x4,

            // CH: 两者最小值 | EN: Min Value
            ArithmeticType_Min = 0x5,

            // CH: 两者均值 | EN: Mean Value
            ArithmeticType_Average = 0x6,

            // CH: 图像与 | EN: AND
            ArithmeticType_And = 0x7,

            // CH: 图像或 | EN: OR
            ArithmeticType_Or = 0x8,

            // CH: 图像异或 | EN: XOR
            ArithmeticType_Xor = 0x9,

            // CH: k1*I1+k2*I2+C | EN: RunParam_(k1*I1+k2*I2+c)
            ArithmeticType_BiImgLinear = 0xA,

            // CH: k1*I1+C | EN: RunParam_(k1*I1+c)
            ArithmeticType_SingleImgLinear = 0xB,

            // CH: I1+C | EN: RunParam_I1+C
            ArithmeticType_ADDC = 0xC,

            // CH: I1-C | EN: RunParam_I1-C
            ArithmeticType_SUBC = 0xD,

            // CH: C-I1 | EN: RunParam_C-I1
            ArithmeticType_CSUB = 0xE,

            // CH: 两幅图像乘 | EN: RunParam_Image1_multiply_Image2
            ArithmeticType_MUL = 0xF,

            // CH: 两幅图像除 | EN: RunParam_Image1_divide_Image2
            ArithmeticType_DIV = 0x10,

            // CH: I1/C | EN: RunParam_I1/C
            ArithmeticType_DIVC = 0x11,

            // CH: C/I1 | EN: RunParam_C/I1
            ArithmeticType_CDIV = 0x12,

            // CH: I1&&C | EN: RunParam_Image1 and C
            ArithmeticType_ANDC = 0x13,

            // CH: I1||C | EN: RunParam_Image1 or C
            ArithmeticType_ORC = 0x14,

            // CH: I1^C | EN: RunParam_Image1 XOR C
            ArithmeticType_XORC = 0x15,

            // CH: 图像和常数最大值 | EN: RunParam_Image and constant maxima
            ArithmeticType_MAXC = 0x16,

            // CH: 图像和常数最小值 | EN: RunParam_Image and constant minima
            ArithmeticType_MINC = 0x17,

            // CH: 图像和常数均值 | EN: RunParam_Image and constant mean
            ArithmeticType_AVGC = 0x18,

            // CH: |I1-C| | EN: RunParam_Image1 subtract C absolute
            ArithmeticType_ABS_DIFFC = 0x19,

            // CH: 两幅图像与非 | EN: RunParam_Two images and non
            ArithmeticType_ANDNOT = 0x1A,

            // CH: 两幅图像或非 | EN: RunParam_Two images or not
            ArithmeticType_ORNOT = 0x1B,

            // CH: !(I1&&C) | EN: RunParam_not Image1 and C
            ArithmeticType_ANDNOTC = 0x1C,

            // CH: !(I1||C) | EN: RunParam_not Image1 or C
            ArithmeticType_ORNOTC = 0x1D,

            // CH: (I1-(I2 + C))>=0?255:0 | EN: RunParam_SUB_GREATER_EQ_BIN
            ArithmeticType_SUB_GREATER_EQ_BIN = 0x1E,

            // CH: (I1-(I2 + C))>=0?0:255 | EN: RunParam_SUB_LESS_EQ_BIN
            ArithmeticType_SUB_LESS_EQ_BIN = 0x1F,

        }ArithmeticTypeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ImageMathRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ImageMathParams.  */
        class ImageMathParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageMathParams() {}
            virtual ~ImageMathParams() {}

        public:

            // CH: 输入图像1(仅当次执行起效) | EN: InputImage1(Only valid for this execution)
            virtual void SetInputImage1(ImageBaseData* pInputValue) = 0;

            // CH: 输入图像2(仅当次执行起效) | EN: InputImage2(Only valid for this execution)
            virtual void SetInputImage2(ImageBaseData* pInputValue) = 0;

            // CH: 图像权重1 | EN: Image K1
            __declspec(property(put = SetImageWeight1, get = GetImageWeight1)) double ImageWeight1;

            virtual double GetImageWeight1() = 0;

            virtual void SetImageWeight1(double value) = 0;

            // CH: 图像补偿1 | EN: Image Offset 1
            __declspec(property(put = SetImageOffset1, get = GetImageOffset1)) double ImageOffset1;

            virtual double GetImageOffset1() = 0;

            virtual void SetImageOffset1(double value) = 0;

            // CH: 图像权重2 | EN: Image K2
            __declspec(property(put = SetImageWeight2, get = GetImageWeight2)) double ImageWeight2;

            virtual double GetImageWeight2() = 0;

            virtual void SetImageWeight2(double value) = 0;

            // CH: 图像补偿2 | EN: Image Offset 2
            __declspec(property(put = SetImageOffset2, get = GetImageOffset2)) double ImageOffset2;

            virtual double GetImageOffset2() = 0;

            virtual void SetImageOffset2(double value) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ImageMathRoiManager* GetModuRoiManager() = 0;

            // CH: 运算类型 | EN: Calc Type
            __declspec(property(put = SetArithmeticType, get = GetArithmeticType)) ArithmeticTypeEnum ArithmeticType;

            virtual ArithmeticTypeEnum GetArithmeticType() = 0;

            virtual void SetArithmeticType(ArithmeticTypeEnum value) = 0;

            // CH: 运算权重1 | EN: ImageK 1
            __declspec(property(put = SetImageK1, get = GetImageK1)) double ImageK1;

            virtual double GetImageK1() = 0;

            virtual void SetImageK1(double value) = 0;

            // CH: 运算权重2 | EN: ImageK 2
            __declspec(property(put = SetImageK2, get = GetImageK2)) double ImageK2;

            virtual double GetImageK2() = 0;

            virtual void SetImageK2(double value) = 0;

            // CH: 运算补偿 | EN: Image Offset
            __declspec(property(put = SetImageC, get = GetImageC)) double ImageC;

            virtual double GetImageC() = 0;

            virtual void SetImageC(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageMathResults.  */
        class ImageMathResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageMathResults() {}
            virtual ~ImageMathResults() {}

        public:
             /**
             * @par 说明
             * ROI圆弧
             * @par 权限
             * 只读
             */
             virtual Annulus GetROIAnnulus() = 0;

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
        /*  Note: Note: This is the class for the ImageMath tool.  */
        class IMVSImageMathModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImageMathModuTool() {}
            virtual ~IMVSImageMathModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageMathParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageMathResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSImageMathModuTool(IMVSImageMathModuTool&);
            IMVSImageMathModuTool& operator=(IMVSImageMathModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageMath.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImageMathModu::IMVSImageMathModuTool * __stdcall GetImageMathToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGEMATH_H_
