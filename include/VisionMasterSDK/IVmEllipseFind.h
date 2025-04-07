/***************************************************************************************************
 * File：IVmEllipseFind.h
 * Note：CH: 椭圆查找模块接口声明 | En: Interface for the EllipseFind tool.
 *
 * Version：4.3
 * Date: 2022-10-08 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_ELLIPSEFIND_H_
#define _IVM_ELLIPSEFIND_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSEllipseFindModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 边缘类型 | EN: Edge Type
        typedef enum _EllipseFindModeEnum
        {
            // CH: 最强 | EN: Strongest Edge
            EllipseFindMode_Best = 0x1,

            // CH: 最后一条 | EN: Last Edge
            EllipseFindMode_Largest = 0x2,

            // CH: 第一条 | EN: First Edge
            EllipseFindMode_SMALLEST = 0x3,

        }EllipseFindModeEnum;

        // CH: 边缘极性 | EN: EdgePolarity
        typedef enum _EdgePolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgePolarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgePolarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            EdgePolarity_Both = 0x3,

        }EdgePolarityEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class EllipseFindRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the EllipseFindParams.  */
        class EllipseFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EllipseFindParams() {}
            virtual ~EllipseFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual EllipseFindRoiManager* GetModuRoiManager() = 0;

            // CH: 缩放范围 | EN: Zoom Range
            __declspec(property(put = SetScaleInside, get = GetScaleInside)) double ScaleInside;

            virtual double GetScaleInside() = 0;

            virtual void SetScaleInside(double value) = 0;

            // CH: 缩放范围 | EN: Zoom Range
            __declspec(property(put = SetScaleOutside, get = GetScaleOutside)) double ScaleOutside;

            virtual double GetScaleOutside() = 0;

            virtual void SetScaleOutside(double value) = 0;

            // CH: 边缘类型 | EN: Edge Type
            __declspec(property(put = SetEllipseFindMode, get = GetEllipseFindMode)) EllipseFindModeEnum EllipseFindMode;

            virtual EllipseFindModeEnum GetEllipseFindMode() = 0;

            virtual void SetEllipseFindMode(EllipseFindModeEnum value) = 0;

            // CH: 边缘极性 | EN: EdgePolarity
            __declspec(property(put = SetEdgePolarity, get = GetEdgePolarity)) EdgePolarityEnum EdgePolarity;

            virtual EdgePolarityEnum GetEdgePolarity() = 0;

            virtual void SetEdgePolarity(EdgePolarityEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeThresh, get = GetEdgeThresh)) int EdgeThresh;

            virtual int GetEdgeThresh() = 0;

            virtual void SetEdgeThresh(int value) = 0;

            // CH: 卡尺数量 | EN: Caliper Number
            __declspec(property(put = SetRaysNum, get = GetRaysNum)) int RaysNum;

            virtual int GetRaysNum() = 0;

            virtual void SetRaysNum(int value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetEdgeWidth, get = GetEdgeWidth)) int EdgeWidth;

            virtual int GetEdgeWidth() = 0;

            virtual void SetEdgeWidth(int value) = 0;

            // CH: 投影宽度 | EN: Projection Width
            __declspec(property(put = SetRegionWidth, get = GetRegionWidth)) int RegionWidth;

            virtual int GetRegionWidth() = 0;

            virtual void SetRegionWidth(int value) = 0;

            // CH: 误差容忍度 | EN: ErrorTolerance
            __declspec(property(put = SetFitErrorTolerance, get = GetFitErrorTolerance)) int FitErrorTolerance;

            virtual int GetFitErrorTolerance() = 0;

            virtual void SetFitErrorTolerance(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the EllipseFindResults.  */
        class EllipseFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EllipseFindResults() {}
            virtual ~EllipseFindResults() {}

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
             * 椭圆轮廓点
             * @par 权限
             * 只读
             */
			 virtual PointF GetEllipseCoutourPoint(int nIndex) = 0;
			 /**
			 * @par 说明
			 * 轮廓点状态
			 * @par 权限
			 * 只读
			 */
			 virtual int GetEdgePointStatus(int nIndex) = 0;
             /**
             * @par 说明
             * 边缘点个数
             * @par 权限
             * 只读
             */
             virtual int GetEdgePointNum() = 0;
			 /**
			 * @par 说明
			 * 输出椭圆
			 * @par 权限
			 * 只读
			 */
			 virtual Ellipse GetOutputEllipse() = 0;
			 /**
			 * @par 说明
			 * 椭圆环
			 * @par 权限
			 * 只读
			 */
			 virtual Ellipse GetOutputEllipseRing(int nIndex) = 0;
			 /**
			 * @par 说明
			 * 椭圆环数量
			 * @par 权限
			 * 只读
			 */
			 virtual int GetOutputEllipseRingNum() = 0;
		};
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the EllipseFind tool.  */
        class IMVSEllipseFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSEllipseFindModuTool() {}
            virtual ~IMVSEllipseFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual EllipseFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual EllipseFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSEllipseFindModuTool(IMVSEllipseFindModuTool&);
            IMVSEllipseFindModuTool& operator=(IMVSEllipseFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for EllipseFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSEllipseFindModu::IMVSEllipseFindModuTool * __stdcall GetEllipseFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_ELLIPSEFIND_H_
