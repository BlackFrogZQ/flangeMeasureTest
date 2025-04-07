/***************************************************************************************************
 * File：IVmCircleEdgeInsp.h
 * Note：CH: 圆弧边缘缺陷检测模块接口声明 | En: Interface for the CircleEdgeInsp tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CIRCLEEDGEINSP_H_
#define _IVM_CIRCLEEDGEINSP_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCircleEdgeInspModu
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
        class CircleEdgeInspRoiManager
        {
        public:

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the CircleEdgeInspParams.  */
        class CircleEdgeInspParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CircleEdgeInspParams() {}
            virtual ~CircleEdgeInspParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入圆弧(仅当次执行起效) | EN: InputAnnulus(Only valid for this execution)
            virtual void SetInputAnnulus(Annulus* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标准输入 | EN: Standard Input
            __declspec(property(put = SetStandardInput, get = GetStandardInput)) bool StandardInput;

            virtual bool GetStandardInput() = 0;

            virtual void SetStandardInput(bool value) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual CircleEdgeInspRoiManager* GetModuRoiManager() = 0;

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
            __declspec(property(put = SetCircleCaliperNum, get = GetCircleCaliperNum)) int CircleCaliperNum;

            virtual int GetCircleCaliperNum() = 0;

            virtual void SetCircleCaliperNum(int value) = 0;

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
        /** @enum  MVD_EDGEINSP_FLAW_DEFECT_TYPE
         *  @brief defect type of the Arc pair inspect
         */
        typedef _MVD_EDGEINSP_FLAW_DEFECT_TYPE__ MVD_EDGEINSP_FLAW_DEFECT_TYPE;
        
        class IArcFlawInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IArcFlawInfo(){}
            virtual ~IArcFlawInfo(){}

        public:
            /**
             * @par 说明
             * 缺陷类型
             * @par 权限
             * 只读
             */      
            /*  Note: Get the defect type of the Arc flaw inspect. */
            virtual MVD_EDGEINSP_FLAW_DEFECT_TYPE GetFlawType() = 0;

            /**
             * @par 说明
             * 缺陷包围框
             * @par 权限
             * 只读
             */
            /*  Note: Get the defect box of the Arc flaw inspect. */
            virtual RectBox GetFlawBox() = 0;

            /**
             * @par 说明
             * 缺陷长度
             * @par 权限
             * 只读
             */
            /*  Note: Get the defect length of the Arc flaw inspect. */
            virtual float GetFlawSize() = 0;

            /**
             * @par 说明
             * 缺陷面积
             * @par 权限
             * 只读
             */
            /*  Note: Get the defect area of the Arc flaw inspect. */
            virtual float GetFlawArea() = 0;

            /**
             * @par 说明
             * 缺陷所在的卡尺的起始索引
             * @par 权限
             * 只读
             */
            /*  Note: Get the start index of the Caliper. */
            virtual int GetCaliperStartIndex() = 0;

            /**
             * @par 说明
             * 缺陷所在的卡尺的结束索引
             * @par 权限
             * 只读
             */
            /*  Note: Get the end index of the Caliper. */
            virtual int GetCaliperEndIndex() = 0;
        };

        /*  Note: Interface Classes of the result of the CircleEdgeInspResults.  */
        class CircleEdgeInspResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CircleEdgeInspResults() {}
            virtual ~CircleEdgeInspResults() {}

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
             * ROI圆弧
             * @par 权限
             * 只读
             */
             virtual Annulus GetROIAnnulus() = 0;
            /**
             * @par 说明
             * 获取边缘点个数
             * @par 权限
             * 只读
             */
            /*  Note: Get the number  of the edge points.*/
            virtual int GetEdgePtsNum() = 0;

            /**
             * @brief 根据索引查询边缘点
             * @param nIndex  [IN]  边缘点的索引，[0, EdgePointNum)
             * @param stPoint [OUT] 边缘点
             * @param nStatus [OUT] 边缘点状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetEdgePoint(int nIndex, MVD_POINT_F &stPoint, int &nStatus) = 0;

            /**
             * @par 说明
             * 获取卡尺个数
             * @par 权限
             * 只读
             */
            /*  Note: Get the number of Caliper.*/
            virtual int GetIdealPointNum() = 0;

            /**
             * @brief 获取卡尺点信息，个数为当前卡尺个数
             * @param nIdealPtsIndex   [IN]   卡尺点序号，[0, CaliperNum)
             * @param stPoint          [OUT]  卡尺点
             * @param nStatus          [OUT]  卡尺点状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetIdealPoint(int nIdealPtsIndex, MVD_POINT_F &stPoint, int &nStatus) = 0;

            /**
             * @par 说明
             * 获取拟合圆弧信息 圆弧等价于内外径相等的扇环  边检测为1条
             * @par 权限
             * 只读
             */
            /*  Note: Get the information of fitting arc.*/
            virtual Circle GetArc() = 0;

            /**
             * @par 说明
             * 拟合圆弧数目
             * @par 权限
             * 只读
             */
            /*  Note: Get the number  of the fit arc.*/
            virtual int GetArcNum() = 0;

            /**
             * @par 说明
             * 获取缺陷信息
             * @par 权限
             * 只读
             */
            virtual IArcFlawInfo * GetFlawInfo(int nIndex) = 0;

            /**
             * @par 说明
             * 缺陷个数
             * @par 权限
             * 只读
             */
            /*  Note: Get the number  of the defect.*/
            virtual int GetFlawNum() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CircleEdgeInsp tool.  */
        class IMVSCircleEdgeInspModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCircleEdgeInspModuTool() {}
            virtual ~IMVSCircleEdgeInspModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CircleEdgeInspParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CircleEdgeInspResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCircleEdgeInspModuTool(IMVSCircleEdgeInspModuTool&);
            IMVSCircleEdgeInspModuTool& operator=(IMVSCircleEdgeInspModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CircleEdgeInsp.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCircleEdgeInspModu::IMVSCircleEdgeInspModuTool * __stdcall GetCircleEdgeInspToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CIRCLEEDGEINSP_H_
