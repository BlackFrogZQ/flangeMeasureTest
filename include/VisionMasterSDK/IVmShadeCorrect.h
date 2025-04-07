/***************************************************************************************************
 * File：IVmShadeCorrect.h
 * Note：CH: 阴影校正模块接口声明 | En: Interface for the ShadeCorrect tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_SHADECORRECT_H_
#define _IVM_SHADECORRECT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSShadeCorrectModu
    {        /*************************** Params Class Start ***************************/
        // CH: 方向 | EN: Direction
        typedef enum _DirectionEnum
        {
            // CH: X | EN: X
            Direction_X = 0x1,

            // CH: Y | EN: Y
            Direction_Y = 0x2,

            // CH: XY | EN: XY
            Direction_XY = 0x3,

        }DirectionEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ShadeCorrectRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ShadeCorrectParams.  */
        class ShadeCorrectParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ShadeCorrectParams() {}
            virtual ~ShadeCorrectParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ShadeCorrectRoiManager* GetModuRoiManager() = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetRatio, get = GetRatio)) int Ratio;

            virtual int GetRatio() = 0;

            virtual void SetRatio(int value) = 0;

            // CH: 增益 | EN: Gain
            __declspec(property(put = SetGain, get = GetGain)) int Gain;

            virtual int GetGain() = 0;

            virtual void SetGain(int value) = 0;

            // CH: 亮度校正补偿 | EN: Compensation
            __declspec(property(put = SetOffset, get = GetOffset)) int Offset;

            virtual int GetOffset() = 0;

            virtual void SetOffset(int value) = 0;

            // CH: 噪声 | EN: Noise
            __declspec(property(put = SetNoise, get = GetNoise)) int Noise;

            virtual int GetNoise() = 0;

            virtual void SetNoise(int value) = 0;

            // CH: 方向 | EN: Direction
            __declspec(property(put = SetDirection, get = GetDirection)) DirectionEnum Direction;

            virtual DirectionEnum GetDirection() = 0;

            virtual void SetDirection(DirectionEnum value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ShadeCorrectResults.  */
        class ShadeCorrectResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ShadeCorrectResults() {}
            virtual ~ShadeCorrectResults() {}

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
        /*  Note: Note: This is the class for the ShadeCorrect tool.  */
        class IMVSShadeCorrectModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSShadeCorrectModuTool() {}
            virtual ~IMVSShadeCorrectModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ShadeCorrectParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ShadeCorrectResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSShadeCorrectModuTool(IMVSShadeCorrectModuTool&);
            IMVSShadeCorrectModuTool& operator=(IMVSShadeCorrectModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ShadeCorrect.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSShadeCorrectModu::IMVSShadeCorrectModuTool * __stdcall GetShadeCorrectToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_SHADECORRECT_H_
