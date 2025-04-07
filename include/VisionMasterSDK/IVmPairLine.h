/***************************************************************************************************
 * File：IVmPairLine.h
 * Note：CH: 平行线查找模块接口声明 | En: Interface for the PairLine tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_PAIRLINE_H_
#define _IVM_PAIRLINE_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSPairLineModu
    {        /*************************** Params Class Start ***************************/
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

        // CH: 边缘0极性 | EN: Edge 0 polarity
        typedef enum _Edge0PolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            Edge0Polarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            Edge0Polarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            Edge0Polarity_Both = 0x3,

        }Edge0PolarityEnum;

        // CH: 边缘1极性 | EN: Edge 1 polarity
        typedef enum _Edge1PolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            Edge1Polarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            Edge1Polarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            Edge1Polarity_Both = 0x3,

        }Edge1PolarityEnum;

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
        class PairLineRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the PairLineParams.  */
        class PairLineParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit PairLineParams() {}
            virtual ~PairLineParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual PairLineRoiManager* GetModuRoiManager() = 0;

            // CH: 边缘对类型 | EN: Edge Pair Type
            __declspec(property(put = SetEdgeType, get = GetEdgeType)) EdgeTypeEnum EdgeType;

            virtual EdgeTypeEnum GetEdgeType() = 0;

            virtual void SetEdgeType(EdgeTypeEnum value) = 0;

            // CH: 边缘0极性 | EN: Edge 0 polarity
            __declspec(property(put = SetEdge0Polarity, get = GetEdge0Polarity)) Edge0PolarityEnum Edge0Polarity;

            virtual Edge0PolarityEnum GetEdge0Polarity() = 0;

            virtual void SetEdge0Polarity(Edge0PolarityEnum value) = 0;

            // CH: 边缘1极性 | EN: Edge 1 polarity
            __declspec(property(put = SetEdge1Polarity, get = GetEdge1Polarity)) Edge1PolarityEnum Edge1Polarity;

            virtual Edge1PolarityEnum GetEdge1Polarity() = 0;

            virtual void SetEdge1Polarity(Edge1PolarityEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeStrength, get = GetEdgeStrength)) int EdgeStrength;

            virtual int GetEdgeStrength() = 0;

            virtual void SetEdgeStrength(int value) = 0;

            // CH: 卡尺数量 | EN: Caliper Number
            __declspec(property(put = SetCaliperNum, get = GetCaliperNum)) int CaliperNum;

            virtual int GetCaliperNum() = 0;

            virtual void SetCaliperNum(int value) = 0;

            // CH: 理想间距 | EN: Ideal Distance
            __declspec(property(put = SetIdeaWidth, get = GetIdeaWidth)) int IdeaWidth;

            virtual int GetIdeaWidth() = 0;

            virtual void SetIdeaWidth(int value) = 0;

            // CH: 最大角度差 | EN: Max. Angle Difference
            __declspec(property(put = SetAngleTol, get = GetAngleTol)) int AngleTol;

            virtual int GetAngleTol() = 0;

            virtual void SetAngleTol(int value) = 0;

            // CH: 剔除点数 | EN: Reject Number
            __declspec(property(put = SetRejectNum, get = GetRejectNum)) int RejectNum;

            virtual int GetRejectNum() = 0;

            virtual void SetRejectNum(int value) = 0;

            // CH: 剔除距离 | EN: Distance to remove
            __declspec(property(put = SetRejectDist, get = GetRejectDist)) int RejectDist;

            virtual int GetRejectDist() = 0;

            virtual void SetRejectDist(int value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetKernelSize, get = GetKernelSize)) int KernelSize;

            virtual int GetKernelSize() = 0;

            virtual void SetKernelSize(int value) = 0;

            // CH: 投影宽度 | EN: Projection Width
            __declspec(property(put = SetProjectLen, get = GetProjectLen)) int ProjectLen;

            virtual int GetProjectLen() = 0;

            virtual void SetProjectLen(int value) = 0;

            // CH: 初始拟合 | EN: Initial Fit
            __declspec(property(put = SetFitInitType, get = GetFitInitType)) FitInitTypeEnum FitInitType;

            virtual FitInitTypeEnum GetFitInitType() = 0;

            virtual void SetFitInitType(FitInitTypeEnum value) = 0;

            // CH: 拟合方式 | EN: Fit Mode
            __declspec(property(put = SetFitFun, get = GetFitFun)) FitFunEnum FitFun;

            virtual FitFunEnum GetFitFun() = 0;

            virtual void SetFitFun(FitFunEnum value) = 0;

            // CH: 线对宽度 | EN: Line Pair Width
            __declspec(property(put = SetLineWidthLimitEnable, get = GetLineWidthLimitEnable)) bool LineWidthLimitEnable;

            virtual bool GetLineWidthLimitEnable() = 0;

            virtual void SetLineWidthLimitEnable(bool value) = 0;

            // CH: 宽度范围 | EN: Width Range
            __declspec(property(put = SetLineWidthLimitLow, get = GetLineWidthLimitLow)) double LineWidthLimitLow;

            virtual double GetLineWidthLimitLow() = 0;

            virtual void SetLineWidthLimitLow(double value) = 0;

            // CH: 宽度范围 | EN: Width Range
            __declspec(property(put = SetLineWidthLimitHigh, get = GetLineWidthLimitHigh)) double LineWidthLimitHigh;

            virtual double GetLineWidthLimitHigh() = 0;

            virtual void SetLineWidthLimitHigh(double value) = 0;

            // CH: 直线0角度 | EN: Line0Angle
            __declspec(property(put = SetAngle0LimitEnable, get = GetAngle0LimitEnable)) bool Angle0LimitEnable;

            virtual bool GetAngle0LimitEnable() = 0;

            virtual void SetAngle0LimitEnable(bool value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngle0LimitLow, get = GetAngle0LimitLow)) double Angle0LimitLow;

            virtual double GetAngle0LimitLow() = 0;

            virtual void SetAngle0LimitLow(double value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngle0LimitHigh, get = GetAngle0LimitHigh)) double Angle0LimitHigh;

            virtual double GetAngle0LimitHigh() = 0;

            virtual void SetAngle0LimitHigh(double value) = 0;

            // CH: 直线1角度 | EN: Line1Angle
            __declspec(property(put = SetAngle1LimitEnable, get = GetAngle1LimitEnable)) bool Angle1LimitEnable;

            virtual bool GetAngle1LimitEnable() = 0;

            virtual void SetAngle1LimitEnable(bool value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngle1LimitLow, get = GetAngle1LimitLow)) double Angle1LimitLow;

            virtual double GetAngle1LimitLow() = 0;

            virtual void SetAngle1LimitLow(double value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngle1LimitHigh, get = GetAngle1LimitHigh)) double Angle1LimitHigh;

            virtual double GetAngle1LimitHigh() = 0;

            virtual void SetAngle1LimitHigh(double value) = 0;

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
        class IPairLineFindEdgePointInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IPairLineFindEdgePointInfo() {}
            virtual ~IPairLineFindEdgePointInfo() {}

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

        /*  Note: Interface Classes of the result of the PairLineResults.  */
        class PairLineResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit PairLineResults() {}
            virtual ~PairLineResults() {}

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
              * 边缘直线0
              * @par 权限
              * 只读
              */
            virtual Line GetLine0Info() = 0;
            /**
             * @par 说明
             * 边缘直线1
             * @par 权限
             * 只读
             */
            virtual Line GetLine1Info() = 0;
            /**
             * @par 说明
             * 边缘中线
             * @par 权限
             * 只读
             */
            virtual Line GetLineMidInfo() = 0;
            /**
             * @par 说明
             * 检测状态
             * @par 权限
             * 只读
             */
            virtual int GetStatus() = 0;
            /**
             * @par 说明
             * 获取间距
             * @par 权限
             * 只读
             */
            virtual float GetLineWidth() = 0;
            /**
             * @par 说明
             * 获取边缘点数量
             * @par 权限
             * 只读
             */
            /* Gets the total number of edge points in the current result.*/
            virtual int GetEdgePointNum() = 0;
            /**
             * @par 说明
             * 获取边缘0的点信息
             * @param nPtIndex [in] 点的索引值，从0开始计数
             * @par 权限
             * 只读
             */
            /* Gets information of the point with an index value of 'nPtIndex'.
            The range of index value can be queried from GetEdgePointCount function. */
            virtual IPairLineFindEdgePointInfo* GetEdge0PointInfo(int nPtIndex) = 0;
            /**
             * @par 说明
             * 获取边缘1的点信息
             * @param nPtIndex [in] 点的索引值，从0开始计数
             * @par 权限
             * 只读
             */
            virtual IPairLineFindEdgePointInfo* GetEdge1PointInfo(int nPtIndex) = 0;
            /**
             * @par 说明
             * 获取中间点的信息
             * @param nPtIndex [in] 点的索引值，从0开始计数
             * @par 权限
             * 只读
             */
            virtual IPairLineFindEdgePointInfo* GetEdgeMidPointInfo(int nPtIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the PairLine tool.  */
        class IMVSPairLineModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSPairLineModuTool() {}
            virtual ~IMVSPairLineModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual PairLineParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual PairLineResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSPairLineModuTool(IMVSPairLineModuTool&);
            IMVSPairLineModuTool& operator=(IMVSPairLineModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for PairLine.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSPairLineModu::IMVSPairLineModuTool * __stdcall GetPairLineToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_PAIRLINE_H_
