/***************************************************************************************************
 * File：IVmLineEdgePairInsp.h
 * Note：CH: 直线对缺陷检测模块接口声明 | En: Interface for the LineEdgePairInsp tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_LINEEDGEPAIRINSP_H_
#define _IVM_LINEEDGEPAIRINSP_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSLineEdgePairInspModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 边缘查找类型 | EN: Edge Search Type
        typedef enum _FindModeEnum
        {
            // CH: 最宽边缘对 | EN: Widest edge pair
            FindMode_Widest = 0x1,

            // CH: 最接近边缘对 | EN: Nearest edge pair
            FindMode_Nearest = 0x2,

            // CH: 最强最接近边缘对 | EN: Strongest & Nearest Edge Pair
            FindMode_StrongestNearest = 0x3,

        }FindModeEnum;

        // CH: 边缘0极性 | EN: Edge 0 polarity
        typedef enum _Edge0PolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            Edge0Polarity_B2W = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            Edge0Polarity_W2B = 0x2,

            // CH: 任意极性 | EN: Both
            Edge0Polarity_All = 0x3,

        }Edge0PolarityEnum;

        // CH: 边缘1极性 | EN: Edge 1 polarity
        typedef enum _Edge1PolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            Edge1Polarity_B2W = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            Edge1Polarity_W2B = 0x2,

            // CH: 任意极性 | EN: Both
            Edge1Polarity_All = 0x3,

        }Edge1PolarityEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class LineEdgePairInspRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the LineEdgePairInspParams.  */
        class LineEdgePairInspParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineEdgePairInspParams() {}
            virtual ~LineEdgePairInspParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入直线1(仅当次执行起效) | EN: InputLine1(Only valid for this execution)
            virtual void SetInputLine1(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入直线2(仅当次执行起效) | EN: InputLine2(Only valid for this execution)
            virtual void SetInputLine2(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标准输入 | EN: Standard Input
            __declspec(property(put = SetStandardInput, get = GetStandardInput)) bool StandardInput;

            virtual bool GetStandardInput() = 0;

            virtual void SetStandardInput(bool value) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual LineEdgePairInspRoiManager* GetModuRoiManager() = 0;

            // CH: 边缘查找类型 | EN: Edge Search Type
            __declspec(property(put = SetFindMode, get = GetFindMode)) FindModeEnum FindMode;

            virtual FindModeEnum GetFindMode() = 0;

            virtual void SetFindMode(FindModeEnum value) = 0;

            // CH: 边缘0极性 | EN: Edge 0 polarity
            __declspec(property(put = SetEdge0Polarity, get = GetEdge0Polarity)) Edge0PolarityEnum Edge0Polarity;

            virtual Edge0PolarityEnum GetEdge0Polarity() = 0;

            virtual void SetEdge0Polarity(Edge0PolarityEnum value) = 0;

            // CH: 边缘1极性 | EN: Edge 1 polarity
            __declspec(property(put = SetEdge1Polarity, get = GetEdge1Polarity)) Edge1PolarityEnum Edge1Polarity;

            virtual Edge1PolarityEnum GetEdge1Polarity() = 0;

            virtual void SetEdge1Polarity(Edge1PolarityEnum value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetHalfKernelSize, get = GetHalfKernelSize)) int HalfKernelSize;

            virtual int GetHalfKernelSize() = 0;

            virtual void SetHalfKernelSize(int value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeStrength, get = GetEdgeStrength)) int EdgeStrength;

            virtual int GetEdgeStrength() = 0;

            virtual void SetEdgeStrength(int value) = 0;

            // CH: 理想宽度 | EN: Ideal Width
            __declspec(property(put = SetIdeaWidth, get = GetIdeaWidth)) int IdeaWidth;

            virtual int GetIdeaWidth() = 0;

            virtual void SetIdeaWidth(int value) = 0;

            // CH: 卡尺高度 | EN: CaliperHeight
            __declspec(property(put = SetCaliperHeight, get = GetCaliperHeight)) int CaliperHeight;

            virtual int GetCaliperHeight() = 0;

            virtual void SetCaliperHeight(int value) = 0;

            // CH: 卡尺宽度 | EN: CaliperWidth
            __declspec(property(put = SetCaliperWidth, get = GetCaliperWidth)) int CaliperWidth;

            virtual int GetCaliperWidth() = 0;

            virtual void SetCaliperWidth(int value) = 0;

            // CH: 卡尺间距 | EN: Caliper Spacing
            __declspec(property(put = SetCaliperDistTraj, get = GetCaliperDistTraj)) int CaliperDistTraj;

            virtual int GetCaliperDistTraj() = 0;

            virtual void SetCaliperDistTraj(int value) = 0;

            // CH: 宽度合格范围 | EN: Width Eligibility Range
            __declspec(property(put = SetRoughMinDis, get = GetRoughMinDis)) int RoughMinDis;

            virtual int GetRoughMinDis() = 0;

            virtual void SetRoughMinDis(int value) = 0;

            // CH: 宽度合格范围 | EN: Width Eligibility Range
            __declspec(property(put = SetRoughMaxDis, get = GetRoughMaxDis)) int RoughMaxDis;

            virtual int GetRoughMaxDis() = 0;

            virtual void SetRoughMaxDis(int value) = 0;

            // CH: 缺陷尺寸使能 | EN: Defect Size Enable
            __declspec(property(put = SetSizeEnable, get = GetSizeEnable)) bool SizeEnable;

            virtual bool GetSizeEnable() = 0;

            virtual void SetSizeEnable(bool value) = 0;

            // CH: 缺陷尺寸阈值 | EN: Rough Min Size
            __declspec(property(put = SetRoughMinSize, get = GetRoughMinSize)) int RoughMinSize;

            virtual int GetRoughMinSize() = 0;

            virtual void SetRoughMinSize(int value) = 0;

            // CH: 缺陷面积使能 | EN: Defect Area Enable
            __declspec(property(put = SetAreaEnable, get = GetAreaEnable)) bool AreaEnable;

            virtual bool GetAreaEnable() = 0;

            virtual void SetAreaEnable(bool value) = 0;

            // CH: 缺陷面积阈值 | EN: Rough Min Area
            __declspec(property(put = SetRoughMinArea, get = GetRoughMinArea)) int RoughMinArea;

            virtual int GetRoughMinArea() = 0;

            virtual void SetRoughMinArea(int value) = 0;

            // CH: 卡尺数量 | EN: Caliper Number
            __declspec(property(put = SetLineCaliperNum, get = GetLineCaliperNum)) int LineCaliperNum;

            virtual int GetLineCaliperNum() = 0;

            virtual void SetLineCaliperNum(int value) = 0;

            // CH: 剔除点数 | EN: Reject Number
            __declspec(property(put = SetFitRejectNum, get = GetFitRejectNum)) int FitRejectNum;

            virtual int GetFitRejectNum() = 0;

            virtual void SetFitRejectNum(int value) = 0;

            // CH: 剔除阈值 | EN: Threshold to Remove
            __declspec(property(put = SetFitRejectDist, get = GetFitRejectDist)) int FitRejectDist;

            virtual int GetFitRejectDist() = 0;

            virtual void SetFitRejectDist(int value) = 0;

            // CH: 容忍角度 | EN: Angle Tolerance
            __declspec(property(put = SetAngleTol, get = GetAngleTol)) int AngleTol;

            virtual int GetAngleTol() = 0;

            virtual void SetAngleTol(int value) = 0;

            // CH: 追踪容忍度 | EN: Track Tolerance
            __declspec(property(put = SetTrackDistTol, get = GetTrackDistTol)) int TrackDistTol;

            virtual int GetTrackDistTol() = 0;

            virtual void SetTrackDistTol(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /* @enum  MVD_EDGEINSP_FLAW_DEFECT_TYPE
         *  @brief 边缘对缺陷类型
         */
        typedef _MVD_EDGEINSP_FLAW_DEFECT_TYPE__ MVD_EDGEINSP_FLAW_DEFECT_TYPE;
        
        /*  Note: 直线对缺陷检测缺陷信息类.  */
        class ILineEdgePairFlawInfo
        {
        protected:
            // 构造与析构函数
            explicit ILineEdgePairFlawInfo() {}
            virtual ~ILineEdgePairFlawInfo() {}

        public:
            /**
             * @par 说明
             * 缺陷包围框
             * @par 权限
             * 只读
             */
            virtual RectBox GetFlawBox() = 0;
            /**
             * @par 说明
             * 缺陷长度
             * @par 权限
             * 只读
             */
            virtual float GetFlawLength() = 0;
            /**
             * @par 说明
             * 缺陷面积
             * @par 权限
             * 只读
             */
            virtual float GetFlawArea() = 0;
            /**
             * @par 说明
             * 缺陷所在的卡尺的起始索引
             * @par 权限
             * 只读
             */
            virtual int GetCaliperStartIndex() = 0;
            /**
             * @par 说明
             * 缺陷所在的卡尺的结束索引
             * @par 权限
             * 只读
             */
            virtual int GetCaliperEndIndex() = 0;
            /**
             * @par 说明
             * 缺陷类型
             * @par 权限
             * 只读
             */
            virtual MVD_EDGEINSP_FLAW_DEFECT_TYPE GetFlawType() = 0;
        };

        /*  Note: Interface Classes of the result of the LineEdgePairInspResults.  */
        class LineEdgePairInspResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineEdgePairInspResults() {}
            virtual ~LineEdgePairInspResults() {}

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
             * 缺陷数量
             * @par 权限
             * 只读
             */
            virtual int GetFlawNum() = 0;
            /**
             * @brief 根据索引获取缺陷的信息
             * @param nIndex [in] 缺陷的索引,[0, FlawNum)
             * @return 单缺陷信息
             * @par 注解
             * 无
             */
            virtual ILineEdgePairFlawInfo* GetFlawInfo(int nIndex) = 0;
            /**
             * @brief 获取边缘0点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdge0PointNum() = 0;
            /**
             * @brief 根据索引查询边缘点0
             * @param nIndex   [IN]  边缘点0的索引，[0, EdgePointNum)
             * @param stPoint0 [OUT] 边缘点0
             * @param nStatus  [OUT] 边缘点0状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetEdge0Point(int nIndex, MVD_POINT_F &stPoint0, int &nStatus) = 0;
            /**
             * @brief 获取边缘1点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdge1PointNum() = 0;
            /**
             * @brief 根据索引查询边缘点1
             * @param nIndex   [IN]  边缘点1的索引，[0, EdgePointNum)
             * @param stPoint1 [OUT] 边缘点1
             * @param nStatus  [OUT] 边缘点1状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetEdge1Point(int nIndex, MVD_POINT_F &stPoint1, int &nStatus) = 0;
            /**
             * @brief 获取卡尺数量
             * @return 卡尺数量
             * @par 注解
             * 无
             */
            virtual int GetCaliperNum() = 0;
            /**
             * @brief 获取卡尺点信息  个数为当前卡尺个数
             * @param nIndex   [IN]   卡尺点序号，[0, CaliperNum)
             * @param stPoint  [OUT]  卡尺点
             * @param nStatus  [OUT]  卡尺点状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetCaliperIdeaPoint(int nIndex, MVD_POINT_F &stPoint, int &nStatus) = 0;
            /**
             * @par 说明
             * 最小宽度
             * @par 权限
             * 只读
             */
            /*  Note: Get the min width the defect.*/
            virtual float GetMinWidth() = 0;
            /**
             * @par 说明
             * 最大宽度
             * @par 权限
             * 只读
             */
            /*  Note: Get the max width the defect.*/
            virtual float GetMaxWidth() = 0;
            /**
             * @par 说明
             * 平均宽度
             * @par 权限
             * 只读
             */
            /*  Note: Get the average width the defect.*/
            virtual float GetAverageWidth() = 0;
            /**
             * @par 说明
             * 近似面积
             * @par 权限
             * 只读
             */
            /*  Note: Get the approximate width the defect.*/
            virtual float GetApproximateArea() = 0;
            /**
            * @par 说明
            * 最小边缘点0
            * @par 权限
            * 只读
            */
            virtual PointF GetMinEdgePoint0() = 0;
            /**
            * @par 说明
            * 最小边缘点0极性
            * @par 权限
            * 只读
            */
            virtual int GetMinEdgePolarity0() = 0;
            /**
            * @par 说明
            * 最小边缘点1
            * @par 权限
            * 只读
            */
            virtual PointF GetMinEdgePoint1() = 0;
            /**
            * @par 说明
            * 最小边缘点1极性
            * @par 权限
            * 只读
            */
            virtual int GetMinEdgePolarity1() = 0;
            /**
            * @par 说明
            * 最小边缘分数
            * @par 权限
            * 只读
            */
            virtual float GetMinEdgeScore() = 0;
            /**
            * @par 说明
            * 最小边缘距离
            * @par 权限
            * 只读
            */
            virtual float GetMinEdgeDistance() = 0;
            /**
            * @par 说明
            * 最小边缘状态
            * @par 权限
            * 只读
            */
            virtual int GetMinEdgeStatus() = 0;
            /**
            * @par 说明
            * 最大边缘点0
            * @par 权限
            * 只读
            */
            virtual PointF GetMaxEdgePoint0() = 0;
            /**
            * @par 说明
            * 最大边缘点0极性
            * @par 权限
            * 只读
            */
            virtual int GetMaxEdgePolarity0() = 0;
            /**
            * @par 说明
            * 最大边缘点1
            * @par 权限
            * 只读
            */
            virtual PointF GetMaxEdgePoint1() = 0;
            /**
            * @par 说明
            * 最大边缘点1极性
            * @par 权限
            * 只读
            */
            virtual int GetMaxEdgePolarity1() = 0;
            /**
            * @par 说明
            * 最大边缘分数
            * @par 权限
            * 只读
            */
            virtual float GetMaxEdgeScore() = 0;
            /**
            * @par 说明
            * 最大边缘距离
            * @par 权限
            * 只读
            */
            virtual float GetMaxEdgeDistance() = 0;
            /**
            * @par 说明
            * 最大边缘状态
            * @par 权限
            * 只读
            */
            virtual int GetMaxEdgeStatus() = 0;
            /**
             * @brief 获取内部拟合直线个数
             * @return 直线个数
             * @par 注解
             * 无
             */
            virtual int GetLineNum() = 0;
            /**
             * @brief 根据索引获取内部拟合直线
             * @param nIndex [in] 直线索引,[0, LineNum)
             * @return 内部拟合输出的直线
             * @par 注解
             * 
             */
            virtual Line GetInnerFitLine(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the LineEdgePairInsp tool.  */
        class IMVSLineEdgePairInspModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSLineEdgePairInspModuTool() {}
            virtual ~IMVSLineEdgePairInspModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual LineEdgePairInspParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual LineEdgePairInspResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSLineEdgePairInspModuTool(IMVSLineEdgePairInspModuTool&);
            IMVSLineEdgePairInspModuTool& operator=(IMVSLineEdgePairInspModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for LineEdgePairInsp.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSLineEdgePairInspModu::IMVSLineEdgePairInspModuTool * __stdcall GetLineEdgePairInspToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_LINEEDGEPAIRINSP_H_
