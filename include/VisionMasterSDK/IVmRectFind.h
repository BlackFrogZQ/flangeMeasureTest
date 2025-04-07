/***************************************************************************************************
 * File：IVmRectFind.h
 * Note：CH: 矩形检测模块接口声明 | En: Interface for the RectFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_RECTFIND_H_
#define _IVM_RECTFIND_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSRectFindModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 边缘对类型 | EN: Edge Pair Type
        typedef enum _EdgeTypeEnum
        {
            // CH: 最宽 | EN: Widest Rect
            EdgeType_Widest = 0x1,

            // CH: 最窄 | EN: Narrowest Rect
            EdgeType_Narrowest = 0x2,

            // CH: 最强 | EN: Strongest Edge
            EdgeType_Strongest = 0x3,

            // CH: 最弱 | EN: Min Contrast
            EdgeType_Worst = 0x4,

            // CH: 第一对 | EN: The First Pair
            EdgeType_First = 0x5,

            // CH: 最后一对 | EN: The Last Pair
            EdgeType_Last = 0x6,

            // CH: 最接近 | EN: Best Rectangularity
            EdgeType_Nearest = 0x7,

            // CH: 最不接近 | EN: Worst Rectangularity
            EdgeType_Farthest = 0x8,

        }EdgeTypeEnum;

        // CH: 上边缘极性 | EN: Upper Edge Polarity
        typedef enum _EdgeUpPolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgeUpPolarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgeUpPolarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            EdgeUpPolarity_Both = 0x3,

        }EdgeUpPolarityEnum;

        // CH: 下边缘极性 | EN: Lower Edge Polarity
        typedef enum _EdgeDownPolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgeDownPolarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgeDownPolarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            EdgeDownPolarity_Both = 0x3,

        }EdgeDownPolarityEnum;

        // CH: 左边缘极性 | EN: Left Edge Polarity
        typedef enum _EdgeLeftPolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgeLeftPolarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgeLeftPolarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            EdgeLeftPolarity_Both = 0x3,

        }EdgeLeftPolarityEnum;

        // CH: 右边缘极性 | EN: Right Edge Polarity
        typedef enum _EdgeRightPolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgeRightPolarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgeRightPolarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            EdgeRightPolarity_Both = 0x3,

        }EdgeRightPolarityEnum;

        // CH: 初始拟合 | EN: Initial Fit
        typedef enum _FitInitTypeEnum
        {
            // CH: 全局 | EN: Global
            FitInitType_ALS = 0x1,

            // CH: 局部 | EN: Partial
            FitInitType_LLS = 0x2,

        }FitInitTypeEnum;

        // CH: 拟合方式 | EN: Fit Mode
        typedef enum _FitFunEnum
        {
            // CH: 最小二乘 | EN: Least Squares
            FitFun_LS = 0x1,

            // CH: huber | EN: huber
            FitFun_Huber = 0x2,

            // CH: tukey | EN: tukey
            FitFun_Tukey = 0x3,

        }FitFunEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class RectFindRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the RectFindParams.  */
        class RectFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit RectFindParams() {}
            virtual ~RectFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual RectFindRoiManager* GetModuRoiManager() = 0;

            // CH: 边缘对类型 | EN: Edge Pair Type
            __declspec(property(put = SetEdgeType, get = GetEdgeType)) EdgeTypeEnum EdgeType;

            virtual EdgeTypeEnum GetEdgeType() = 0;

            virtual void SetEdgeType(EdgeTypeEnum value) = 0;

            // CH: 上边缘极性 | EN: Upper Edge Polarity
            __declspec(property(put = SetEdgeUpPolarity, get = GetEdgeUpPolarity)) EdgeUpPolarityEnum EdgeUpPolarity;

            virtual EdgeUpPolarityEnum GetEdgeUpPolarity() = 0;

            virtual void SetEdgeUpPolarity(EdgeUpPolarityEnum value) = 0;

            // CH: 下边缘极性 | EN: Lower Edge Polarity
            __declspec(property(put = SetEdgeDownPolarity, get = GetEdgeDownPolarity)) EdgeDownPolarityEnum EdgeDownPolarity;

            virtual EdgeDownPolarityEnum GetEdgeDownPolarity() = 0;

            virtual void SetEdgeDownPolarity(EdgeDownPolarityEnum value) = 0;

            // CH: 左边缘极性 | EN: Left Edge Polarity
            __declspec(property(put = SetEdgeLeftPolarity, get = GetEdgeLeftPolarity)) EdgeLeftPolarityEnum EdgeLeftPolarity;

            virtual EdgeLeftPolarityEnum GetEdgeLeftPolarity() = 0;

            virtual void SetEdgeLeftPolarity(EdgeLeftPolarityEnum value) = 0;

            // CH: 右边缘极性 | EN: Right Edge Polarity
            __declspec(property(put = SetEdgeRightPolarity, get = GetEdgeRightPolarity)) EdgeRightPolarityEnum EdgeRightPolarity;

            virtual EdgeRightPolarityEnum GetEdgeRightPolarity() = 0;

            virtual void SetEdgeRightPolarity(EdgeRightPolarityEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeStrength, get = GetEdgeStrength)) int EdgeStrength;

            virtual int GetEdgeStrength() = 0;

            virtual void SetEdgeStrength(int value) = 0;

            // CH: 卡尺数量 | EN: Caliper Number
            __declspec(property(put = SetCaliperNum, get = GetCaliperNum)) int CaliperNum;

            virtual int GetCaliperNum() = 0;

            virtual void SetCaliperNum(int value) = 0;

            // CH: 理想宽度 | EN: Ideal Width
            __declspec(property(put = SetIdeaWidth, get = GetIdeaWidth)) int IdeaWidth;

            virtual int GetIdeaWidth() = 0;

            virtual void SetIdeaWidth(int value) = 0;

            // CH: 理想高度 | EN: Ideal Height
            __declspec(property(put = SetIdeaHeight, get = GetIdeaHeight)) int IdeaHeight;

            virtual int GetIdeaHeight() = 0;

            virtual void SetIdeaHeight(int value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetKernelSize, get = GetKernelSize)) int KernelSize;

            virtual int GetKernelSize() = 0;

            virtual void SetKernelSize(int value) = 0;

            // CH: 投影宽度 | EN: Projection Width
            __declspec(property(put = SetProjectLen, get = GetProjectLen)) int ProjectLen;

            virtual int GetProjectLen() = 0;

            virtual void SetProjectLen(int value) = 0;

            // CH: 剔除点数 | EN: Reject Number
            __declspec(property(put = SetRejectNum, get = GetRejectNum)) int RejectNum;

            virtual int GetRejectNum() = 0;

            virtual void SetRejectNum(int value) = 0;

            // CH: 剔除距离 | EN: Distance to remove
            __declspec(property(put = SetRejectDist, get = GetRejectDist)) int RejectDist;

            virtual int GetRejectDist() = 0;

            virtual void SetRejectDist(int value) = 0;

            // CH: 初始拟合 | EN: Initial Fit
            __declspec(property(put = SetFitInitType, get = GetFitInitType)) FitInitTypeEnum FitInitType;

            virtual FitInitTypeEnum GetFitInitType() = 0;

            virtual void SetFitInitType(FitInitTypeEnum value) = 0;

            // CH: 拟合方式 | EN: Fit Mode
            __declspec(property(put = SetFitFun, get = GetFitFun)) FitFunEnum FitFun;

            virtual FitFunEnum GetFitFun() = 0;

            virtual void SetFitFun(FitFunEnum value) = 0;

            // CH: 角度判断 | EN: Angle Check
            __declspec(property(put = SetAngleLimitEnable, get = GetAngleLimitEnable)) bool AngleLimitEnable;

            virtual bool GetAngleLimitEnable() = 0;

            virtual void SetAngleLimitEnable(bool value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngleLimitLow, get = GetAngleLimitLow)) double AngleLimitLow;

            virtual double GetAngleLimitLow() = 0;

            virtual void SetAngleLimitLow(double value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngleLimitHigh, get = GetAngleLimitHigh)) double AngleLimitHigh;

            virtual double GetAngleLimitHigh() = 0;

            virtual void SetAngleLimitHigh(double value) = 0;

            // CH: 中心X判断 | EN: Center X Check
            __declspec(property(put = SetCenterXLimitEnable, get = GetCenterXLimitEnable)) bool CenterXLimitEnable;

            virtual bool GetCenterXLimitEnable() = 0;

            virtual void SetCenterXLimitEnable(bool value) = 0;

            // CH: 中心X范围 | EN: Center X Range
            __declspec(property(put = SetCenterXLimitLow, get = GetCenterXLimitLow)) double CenterXLimitLow;

            virtual double GetCenterXLimitLow() = 0;

            virtual void SetCenterXLimitLow(double value) = 0;

            // CH: 中心X范围 | EN: Center X Range
            __declspec(property(put = SetCenterXLimitHigh, get = GetCenterXLimitHigh)) double CenterXLimitHigh;

            virtual double GetCenterXLimitHigh() = 0;

            virtual void SetCenterXLimitHigh(double value) = 0;

            // CH: 中心Y判断 | EN: Center Y Check
            __declspec(property(put = SetCenterYLimitEnable, get = GetCenterYLimitEnable)) bool CenterYLimitEnable;

            virtual bool GetCenterYLimitEnable() = 0;

            virtual void SetCenterYLimitEnable(bool value) = 0;

            // CH: 中心Y范围 | EN: Center Y Range
            __declspec(property(put = SetCenterYLimitLow, get = GetCenterYLimitLow)) double CenterYLimitLow;

            virtual double GetCenterYLimitLow() = 0;

            virtual void SetCenterYLimitLow(double value) = 0;

            // CH: 中心Y范围 | EN: Center Y Range
            __declspec(property(put = SetCenterYLimitHigh, get = GetCenterYLimitHigh)) double CenterYLimitHigh;

            virtual double GetCenterYLimitHigh() = 0;

            virtual void SetCenterYLimitHigh(double value) = 0;

            // CH: 高度判断 | EN: Height Check
            __declspec(property(put = SetRectHeightLimitEnable, get = GetRectHeightLimitEnable)) bool RectHeightLimitEnable;

            virtual bool GetRectHeightLimitEnable() = 0;

            virtual void SetRectHeightLimitEnable(bool value) = 0;

            // CH: 高度范围 | EN: Height Range
            __declspec(property(put = SetRectHeightLimitLow, get = GetRectHeightLimitLow)) double RectHeightLimitLow;

            virtual double GetRectHeightLimitLow() = 0;

            virtual void SetRectHeightLimitLow(double value) = 0;

            // CH: 高度范围 | EN: Height Range
            __declspec(property(put = SetRectHeightLimitHigh, get = GetRectHeightLimitHigh)) double RectHeightLimitHigh;

            virtual double GetRectHeightLimitHigh() = 0;

            virtual void SetRectHeightLimitHigh(double value) = 0;

            // CH: 宽度判断 | EN: Width Check
            __declspec(property(put = SetRectWidthLimitEnable, get = GetRectWidthLimitEnable)) bool RectWidthLimitEnable;

            virtual bool GetRectWidthLimitEnable() = 0;

            virtual void SetRectWidthLimitEnable(bool value) = 0;

            // CH: 宽度范围 | EN: Width Range
            __declspec(property(put = SetRectWidthLimitLow, get = GetRectWidthLimitLow)) double RectWidthLimitLow;

            virtual double GetRectWidthLimitLow() = 0;

            virtual void SetRectWidthLimitLow(double value) = 0;

            // CH: 宽度范围 | EN: Width Range
            __declspec(property(put = SetRectWidthLimitHigh, get = GetRectWidthLimitHigh)) double RectWidthLimitHigh;

            virtual double GetRectWidthLimitHigh() = 0;

            virtual void SetRectWidthLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /** @enum  MVD_EDGEPOINT_STATUS
        *  @brief Find status of the edge point
        */
        typedef _MVD_EDGEPOINT_STATUS__ MVD_EDGEPOINT_STATUS;

        /** @enum  MVD_EDGEPOINT_STATUS
        *  @brief Type of the polarity of the edge point
        */
        typedef _MVD_EDGE_POLARITY__ MVD_EDGE_POLARITY;
        
        /*  Note: Interface Classes for describing a edge point Information.  */
        class IRectFindEdgePointInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IRectFindEdgePointInfo() {}
            virtual ~IRectFindEdgePointInfo() {}

        public:
             /**
             * @par 说明
             * 边缘点坐标
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetEdgePoint() = 0;
            /**
             * @par 说明
             * 边缘点状态
             * @par 权限
             * 只读
             */
            virtual MVD_EDGEPOINT_STATUS GetStatus() = 0;
        };

        /*  Note: Interface Classes of the result of the RectFindResults.  */
        class RectFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit RectFindResults() {}
            virtual ~RectFindResults() {}

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
             * 检测状态
             * @par 权限
             * 只读
             */
            virtual int GetStatus() = 0;
            /**
             * @par 说明
             * 矩形检测框
             * @par 权限
             * 只读
             */
            virtual RectBox GetRectBox() = 0;
            /**
             * @par 说明
             * 边缘点点数
             * @par 权限
             * 只读
             */
            virtual int GetEdgePointNum() = 0;
            /**
             * @brief 获取结果中的边缘点信息
             * @param nPtIndex [in] 边缘点索引
             * @return 返回结果边缘点序
             * @par 注解
             * nPtIndex从0开始计数。
             */
            /* Gets information of the point with an index value of 'nPtIndex'.
            The range of index value can be queried from GetEdgePointNum function. */
            virtual IRectFindEdgePointInfo* GetEdgePointInfo(int nPtIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the RectFind tool.  */
        class IMVSRectFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSRectFindModuTool() {}
            virtual ~IMVSRectFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual RectFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual RectFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSRectFindModuTool(IMVSRectFindModuTool&);
            IMVSRectFindModuTool& operator=(IMVSRectFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for RectFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSRectFindModu::IMVSRectFindModuTool * __stdcall GetRectFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_RECTFIND_H_
