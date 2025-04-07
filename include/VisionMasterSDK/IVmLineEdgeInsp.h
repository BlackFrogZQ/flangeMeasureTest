/***************************************************************************************************
 * File：IVmLineEdgeInsp.h
 * Note：CH: 直线边缘缺陷检测模块接口声明 | En: Interface for the LineEdgeInsp tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_LINEEDGEINSP_H_
#define _IVM_LINEEDGEINSP_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSLineEdgeInspModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 边缘类型 | EN: Edge Type
        typedef enum _FindModeEnum
        {
            // CH: 最强 | EN: Strongest Edge
            FindMode_Best = 0x1,

            // CH: 第一条 | EN: First Edge
            FindMode_First = 0x2,

            // CH: 最后一条 | EN: Last Edge
            FindMode_Last = 0x3,

        }FindModeEnum;

        // CH: 边缘极性 | EN: EdgePolarity
        typedef enum _EdgePolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgePolarity_B2W = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgePolarity_W2B = 0x2,

            // CH: 任意极性 | EN: Both
            EdgePolarity_All = 0x3,

        }EdgePolarityEnum;

        // CH: 缺陷极性 | EN: Defect Polarity
        typedef enum _FlawPolarityEnableEnum
        {
            // CH: 轨迹两侧缺陷 | EN: Trajectory Both Defect
            FlawPolarityEnable_All = 0x0,

            // CH: 轨迹右侧缺陷 | EN: Trajectory Right Defect
            FlawPolarityEnable_RightBottom = 0x1,

            // CH: 轨迹左侧缺陷 | EN: Trajectory Left Defect
            FlawPolarityEnable_LeftTop = 0x2,

        }FlawPolarityEnableEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class LineEdgeInspRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the LineEdgeInspParams.  */
        class LineEdgeInspParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineEdgeInspParams() {}
            virtual ~LineEdgeInspParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入直线(仅当次执行起效) | EN: Input Line(Only valid for this execution)
            virtual void SetInputLine(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标准输入 | EN: Standard Input
            __declspec(property(put = SetStandardInput, get = GetStandardInput)) bool StandardInput;

            virtual bool GetStandardInput() = 0;

            virtual void SetStandardInput(bool value) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual LineEdgeInspRoiManager* GetModuRoiManager() = 0;

            // CH: 边缘类型 | EN: Edge Type
            __declspec(property(put = SetFindMode, get = GetFindMode)) FindModeEnum FindMode;

            virtual FindModeEnum GetFindMode() = 0;

            virtual void SetFindMode(FindModeEnum value) = 0;

            // CH: 边缘极性 | EN: EdgePolarity
            __declspec(property(put = SetEdgePolarity, get = GetEdgePolarity)) EdgePolarityEnum EdgePolarity;

            virtual EdgePolarityEnum GetEdgePolarity() = 0;

            virtual void SetEdgePolarity(EdgePolarityEnum value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetHalfKernelSize, get = GetHalfKernelSize)) int HalfKernelSize;

            virtual int GetHalfKernelSize() = 0;

            virtual void SetHalfKernelSize(int value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeStrength, get = GetEdgeStrength)) int EdgeStrength;

            virtual int GetEdgeStrength() = 0;

            virtual void SetEdgeStrength(int value) = 0;

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

            // CH: 缺陷极性 | EN: Defect Polarity
            __declspec(property(put = SetFlawPolarityEnable, get = GetFlawPolarityEnable)) FlawPolarityEnableEnum FlawPolarityEnable;

            virtual FlawPolarityEnableEnum GetFlawPolarityEnable() = 0;

            virtual void SetFlawPolarityEnable(FlawPolarityEnableEnum value) = 0;

            // CH: 缺陷距离阈值 | EN: Rough Min Distance
            __declspec(property(put = SetRoughMinDis, get = GetRoughMinDis)) int RoughMinDis;

            virtual int GetRoughMinDis() = 0;

            virtual void SetRoughMinDis(int value) = 0;

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

            // CH: 追踪容忍度 | EN: Track Tolerance
            __declspec(property(put = SetTrackDistTol, get = GetTrackDistTol)) int TrackDistTol;

            virtual int GetTrackDistTol() = 0;

            virtual void SetTrackDistTol(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /* @enum  MVD_EDGEINSP_FLAW_DEFECT_TYPE
         *  @brief 边缘缺陷类型
         */
        typedef _MVD_EDGEINSP_FLAW_DEFECT_TYPE__ MVD_EDGEINSP_FLAW_DEFECT_TYPE;
        
        /*  Note: 直线边缘缺陷检测缺陷信息类.  */
        class ILineEdgeFlawInfo
        {
        protected:
            // 构造与析构函数
            explicit ILineEdgeFlawInfo() {}
            virtual ~ILineEdgeFlawInfo() {}

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

        /*  Note: Interface Classes of the result of the LineEdgeInspResults.  */
        class LineEdgeInspResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineEdgeInspResults() {}
            virtual ~LineEdgeInspResults() {}

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
            // Property
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
            virtual ILineEdgeFlawInfo* GetFlawInfo(int nIndex) = 0;
            /**
             * @brief 获取边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePointNum() = 0;
            /**
             * @brief 根据索引查询边缘点
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点
             * @par 注解
             * 
             */
            virtual MVD_POINT_F GetEdgePoint(int nIndex) = 0;
            /**
             * @brief 根据索引查询边缘点状态，0表示为正常状态 1表示为缺陷状态
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点
             * @par 注解
             * 
             */
            virtual int GetEdgePointStatus(int nIndex) = 0;
            /**
            * @brief 根据索引获取卡尺信息
            * @param nIndex [in] 卡尺索引,[0, Caliper)
            * @return 单卡尺信息
            * @par 注解
            *
            */
            virtual RectBox GetCaliperBox(int nIndex) = 0;
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
             * @brief 获取内部拟合直线个数
             * @return 直线个数
             * @par 注解
             * 无
             */
            virtual int GetLineNum() = 0;
            /**
             * @brief 根据索引获取内部拟合直线
             * @param nIndex [in] 直线索引,[0, LineNum)
             * @return 内部拟合输出直线
             * @par 注解
             * 
             */
            virtual Line GetInnerFitLine(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the LineEdgeInsp tool.  */
        class IMVSLineEdgeInspModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSLineEdgeInspModuTool() {}
            virtual ~IMVSLineEdgeInspModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual LineEdgeInspParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual LineEdgeInspResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSLineEdgeInspModuTool(IMVSLineEdgeInspModuTool&);
            IMVSLineEdgeInspModuTool& operator=(IMVSLineEdgeInspModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for LineEdgeInsp.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSLineEdgeInspModu::IMVSLineEdgeInspModuTool * __stdcall GetLineEdgeInspToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_LINEEDGEINSP_H_
