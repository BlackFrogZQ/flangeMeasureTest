/***************************************************************************************************
 * File：IVmEdgeWidthFind.h
 * Note：CH: 间距检测模块接口声明 | En: Interface for the EdgeWidthFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_EDGEWIDTHFIND_H_
#define _IVM_EDGEWIDTHFIND_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSEdgeWidthFindModu
    {
        /*************************** Params Class Start ***************************/
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

        // CH: 边缘对类型 | EN: Edge Pair Type
        typedef enum _FindModeEnum
        {
            // CH: 最宽 | EN: Widest Rect
            FindMode_Widest = 0x1,

            // CH: 最窄 | EN: Narrowest Rect
            FindMode_Narrowest = 0x2,

            // CH: 最强 | EN: Strongest Edge
            FindMode_Strongest = 0x3,

            // CH: 最弱 | EN: Min Contrast
            FindMode_Worst = 0x4,

            // CH: 第一对 | EN: The First Pair
            FindMode_First = 0x5,

            // CH: 最后一对 | EN: The Last Pair
            FindMode_Last = 0x6,

            // CH: 最接近 | EN: Best Rectangularity
            FindMode_Nearest = 0x7,

            // CH: 最不接近 | EN: Worst Rectangularity
            FindMode_Farthest = 0x8,

            // CH: 全部 | EN: All
            FindMode_All = 0x9,

        }FindModeEnum;

        // CH: 排序方式 | EN: Sort Type
        typedef enum _SortTypeEnum
        {
            // CH: 分数降序 | EN: Score Descend
            SortType_ScoreDescend = 0x0,

            // CH: 分数升序 | EN: Score Ascend
            SortType_ScoreAscend = 0x1,

            // CH: 方向正向 | EN: Orient Forward
            SortType_OrientForward = 0x2,

            // CH: 方向逆向 | EN: Orient Backward
            SortType_OrientBackward = 0x3,

        }SortTypeEnum;

        // CH: 查找方向 | EN: Search Direction
        typedef enum _FindOrientEnum
        {
            // CH: 从上到下 | EN: Top to Bottom
            FindOrient_UpToDown = 0x1,

            // CH: 从左到右 | EN: Left to Right
            FindOrient_LeftToRight = 0x2,

        }FindOrientEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class EdgeWidthFindRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the EdgeWidthFindParams.  */
        class EdgeWidthFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgeWidthFindParams() {}
            virtual ~EdgeWidthFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual EdgeWidthFindRoiManager* GetModuRoiManager() = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetHalfKernelSize, get = GetHalfKernelSize)) int HalfKernelSize;

            virtual int GetHalfKernelSize() = 0;

            virtual void SetHalfKernelSize(int value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetContrastTH, get = GetContrastTH)) int ContrastTH;

            virtual int GetContrastTH() = 0;

            virtual void SetContrastTH(int value) = 0;

            // CH: 边缘0极性 | EN: Edge 0 polarity
            __declspec(property(put = SetEdge0Polarity, get = GetEdge0Polarity)) Edge0PolarityEnum Edge0Polarity;

            virtual Edge0PolarityEnum GetEdge0Polarity() = 0;

            virtual void SetEdge0Polarity(Edge0PolarityEnum value) = 0;

            // CH: 边缘1极性 | EN: Edge 1 polarity
            __declspec(property(put = SetEdge1Polarity, get = GetEdge1Polarity)) Edge1PolarityEnum Edge1Polarity;

            virtual Edge1PolarityEnum GetEdge1Polarity() = 0;

            virtual void SetEdge1Polarity(Edge1PolarityEnum value) = 0;

            // CH: 边缘对类型 | EN: Edge Pair Type
            __declspec(property(put = SetFindMode, get = GetFindMode)) FindModeEnum FindMode;

            virtual FindModeEnum GetFindMode() = 0;

            virtual void SetFindMode(FindModeEnum value) = 0;

            // CH: 最大结果数 | EN: Max Result Number
            __declspec(property(put = SetMaximum, get = GetMaximum)) int Maximum;

            virtual int GetMaximum() = 0;

            virtual void SetMaximum(int value) = 0;

            // CH: 理想间距 | EN: Ideal Distance
            __declspec(property(put = SetIdeaWidth, get = GetIdeaWidth)) int IdeaWidth;

            virtual int GetIdeaWidth() = 0;

            virtual void SetIdeaWidth(int value) = 0;

            // CH: 排序方式 | EN: Sort Type
            __declspec(property(put = SetSortType, get = GetSortType)) SortTypeEnum SortType;

            virtual SortTypeEnum GetSortType() = 0;

            virtual void SetSortType(SortTypeEnum value) = 0;

            // CH: 查找方向 | EN: Search Direction
            __declspec(property(put = SetFindOrient, get = GetFindOrient)) FindOrientEnum FindOrient;

            virtual FindOrientEnum GetFindOrient() = 0;

            virtual void SetFindOrient(FindOrientEnum value) = 0;

            // CH: 最小边缘分数 | EN: Min Edge Score
            __declspec(property(put = SetMinScore, get = GetMinScore)) double MinScore;

            virtual double GetMinScore() = 0;

            virtual void SetMinScore(double value) = 0;

            // CH: 数量判断 | EN: Quantity Check
            __declspec(property(put = SetNumLimitEnable, get = GetNumLimitEnable)) bool NumLimitEnable;

            virtual bool GetNumLimitEnable() = 0;

            virtual void SetNumLimitEnable(bool value) = 0;

            // CH: 数量判断 | EN: Quantity Check
            __declspec(property(put = SetNumLimitLow, get = GetNumLimitLow)) int NumLimitLow;

            virtual int GetNumLimitLow() = 0;

            virtual void SetNumLimitLow(int value) = 0;

            // CH: 数量判断 | EN: Quantity Check
            __declspec(property(put = SetNumLimitHigh, get = GetNumLimitHigh)) int NumLimitHigh;

            virtual int GetNumLimitHigh() = 0;

            virtual void SetNumLimitHigh(int value) = 0;

            // CH: 宽度判断 | EN: Width Check
            __declspec(property(put = SetEdgeWidthLimitEnable, get = GetEdgeWidthLimitEnable)) bool EdgeWidthLimitEnable;

            virtual bool GetEdgeWidthLimitEnable() = 0;

            virtual void SetEdgeWidthLimitEnable(bool value) = 0;

            // CH: 宽度判断 | EN: Width Check
            __declspec(property(put = SetEdgeWidthLimitLow, get = GetEdgeWidthLimitLow)) double EdgeWidthLimitLow;

            virtual double GetEdgeWidthLimitLow() = 0;

            virtual void SetEdgeWidthLimitLow(double value) = 0;

            // CH: 宽度判断 | EN: Width Check
            __declspec(property(put = SetEdgeWidthLimitHigh, get = GetEdgeWidthLimitHigh)) double EdgeWidthLimitHigh;

            virtual double GetEdgeWidthLimitHigh() = 0;

            virtual void SetEdgeWidthLimitHigh(double value) = 0;

            // CH: 边缘点0X判断 | EN: Edge Point 0X Check
            __declspec(property(put = SetEdge0PointXLimitEnable, get = GetEdge0PointXLimitEnable)) bool Edge0PointXLimitEnable;

            virtual bool GetEdge0PointXLimitEnable() = 0;

            virtual void SetEdge0PointXLimitEnable(bool value) = 0;

            // CH: 边缘点0X范围 | EN: Edge Point 0X Range
            __declspec(property(put = SetEdge0PointXLimitLow, get = GetEdge0PointXLimitLow)) double Edge0PointXLimitLow;

            virtual double GetEdge0PointXLimitLow() = 0;

            virtual void SetEdge0PointXLimitLow(double value) = 0;

            // CH: 边缘点0X范围 | EN: Edge Point 0X Range
            __declspec(property(put = SetEdge0PointXLimitHigh, get = GetEdge0PointXLimitHigh)) double Edge0PointXLimitHigh;

            virtual double GetEdge0PointXLimitHigh() = 0;

            virtual void SetEdge0PointXLimitHigh(double value) = 0;

            // CH: 边缘点0Y判断 | EN: Edge Point 0Y Check
            __declspec(property(put = SetEdge0PointYLimitEnable, get = GetEdge0PointYLimitEnable)) bool Edge0PointYLimitEnable;

            virtual bool GetEdge0PointYLimitEnable() = 0;

            virtual void SetEdge0PointYLimitEnable(bool value) = 0;

            // CH: 边缘点0Y范围 | EN: Edge Point 0Y Range
            __declspec(property(put = SetEdge0PointYLimitLow, get = GetEdge0PointYLimitLow)) double Edge0PointYLimitLow;

            virtual double GetEdge0PointYLimitLow() = 0;

            virtual void SetEdge0PointYLimitLow(double value) = 0;

            // CH: 边缘点0Y范围 | EN: Edge Point 0Y Range
            __declspec(property(put = SetEdge0PointYLimitHigh, get = GetEdge0PointYLimitHigh)) double Edge0PointYLimitHigh;

            virtual double GetEdge0PointYLimitHigh() = 0;

            virtual void SetEdge0PointYLimitHigh(double value) = 0;

            // CH: 边缘点1X判断 | EN: Edge Point 1X Check
            __declspec(property(put = SetEdge1PointXLimitEnable, get = GetEdge1PointXLimitEnable)) bool Edge1PointXLimitEnable;

            virtual bool GetEdge1PointXLimitEnable() = 0;

            virtual void SetEdge1PointXLimitEnable(bool value) = 0;

            // CH: 边缘点1X范围 | EN: Edge Point 1X Range
            __declspec(property(put = SetEdge1PointXLimitLow, get = GetEdge1PointXLimitLow)) double Edge1PointXLimitLow;

            virtual double GetEdge1PointXLimitLow() = 0;

            virtual void SetEdge1PointXLimitLow(double value) = 0;

            // CH: 边缘点1X范围 | EN: Edge Point 1X Range
            __declspec(property(put = SetEdge1PointXLimitHigh, get = GetEdge1PointXLimitHigh)) double Edge1PointXLimitHigh;

            virtual double GetEdge1PointXLimitHigh() = 0;

            virtual void SetEdge1PointXLimitHigh(double value) = 0;

            // CH: 边缘点1Y判断 | EN: Edge Point 1Y Check
            __declspec(property(put = SetEdge1PointYLimitEnable, get = GetEdge1PointYLimitEnable)) bool Edge1PointYLimitEnable;

            virtual bool GetEdge1PointYLimitEnable() = 0;

            virtual void SetEdge1PointYLimitEnable(bool value) = 0;

            // CH: 边缘点1Y范围 | EN: Edge Point 1Y Range
            __declspec(property(put = SetEdge1PointYLimitLow, get = GetEdge1PointYLimitLow)) double Edge1PointYLimitLow;

            virtual double GetEdge1PointYLimitLow() = 0;

            virtual void SetEdge1PointYLimitLow(double value) = 0;

            // CH: 边缘点1Y范围 | EN: Edge Point 1Y Range
            __declspec(property(put = SetEdge1PointYLimitHigh, get = GetEdge1PointYLimitHigh)) double Edge1PointYLimitHigh;

            virtual double GetEdge1PointYLimitHigh() = 0;

            virtual void SetEdge1PointYLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /** @enum  MVD_EDGEPOINT_STATUS
        *  @brief Type of the polarity of the edge point
        */
        typedef _MVD_EDGE_POLARITY__ MVD_EDGE_POLARITY;
        
        /*  Note: Interface Classes for describing single edge information.  */
        class IEdgeWidthSingleEdgeInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IEdgeWidthSingleEdgeInfo() {}
            virtual ~IEdgeWidthSingleEdgeInfo() {}

        public:
            ///< Properties
            /**
             * @par 说明
             * 边缘点信息
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetEdgePoint() = 0;
            /**
             * @par 说明
             * 边缘点偏移
             * @par 权限
             * 只读
             */
            virtual float GetBias() = 0;
            /**
             * @par 说明
             * 边缘极性
             * @par 权限
             * 只读
             */
            virtual MVD_EDGE_POLARITY GetPolarity() = 0;
        };

        /*  Note: Interface Classes for describing a pair of edges information.  */
        class IEdgeWidthEdgePairInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IEdgeWidthEdgePairInfo() {}
            virtual ~IEdgeWidthEdgePairInfo() {}

        public:
            /**
             * @par 说明
             * 边缘0的基本信息
             * @par 权限
             * 只读
             */
            virtual IEdgeWidthSingleEdgeInfo* GetEdge0Info() = 0;
            /**
             * @par 说明
             * 边缘1的基本信息
             * @par 权限
             * 只读
             */
            virtual IEdgeWidthSingleEdgeInfo* GetEdge1Info() = 0;
            /**
             * @par 说明
             * 边缘间距
             * @par 权限
             * 只读
             */
            virtual float GetDistance() = 0;
            /**
             * @par 说明
             * 分数
             * @par 权限
             * 只读
             */
            virtual float GetScore() = 0;
            /**
             * @par 说明
             * 直线0
             * @par 权限
             * 只读
             */
            virtual Line GetLine0() = 0;
            /**
             * @par 说明
             * 直线1
             * @par 权限
             * 只读
             */
            virtual Line GetLine1() = 0;
        };

        /*  Note: Interface Classes of the result of the EdgeWidthFindResults.  */
        class EdgeWidthFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgeWidthFindResults() {}
            virtual ~EdgeWidthFindResults() {}

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
             * @par 说明
             * 边缘信息
             * @par 权限
             * 只读
             */
            virtual IEdgeWidthEdgePairInfo* GetEdgePairInfo( int nPtIndex ) = 0;
            /**
             * @par 说明
             * 边缘点数量
             * @par 权限
             * 只读
             */
            virtual int GetEdgePairNum() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the EdgeWidthFind tool.  */
        class IMVSEdgeWidthFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSEdgeWidthFindModuTool() {}
            virtual ~IMVSEdgeWidthFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual EdgeWidthFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual EdgeWidthFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSEdgeWidthFindModuTool(IMVSEdgeWidthFindModuTool&);
            IMVSEdgeWidthFindModuTool& operator=(IMVSEdgeWidthFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for EdgeWidthFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSEdgeWidthFindModu::IMVSEdgeWidthFindModuTool * __stdcall GetEdgeWidthFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_EDGEWIDTHFIND_H_
