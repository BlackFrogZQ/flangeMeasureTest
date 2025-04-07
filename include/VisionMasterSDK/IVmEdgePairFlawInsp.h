/***************************************************************************************************
 * File：IVmEdgePairFlawInsp.h
 * Note：CH: 边缘对模型缺陷检测模块接口声明 | En: Interface for the EdgePairFlawInsp tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_EDGEPAIRFLAWINSP_H_
#define _IVM_EDGEPAIRFLAWINSP_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSEdgePairFlawInspModu
    {
        /* @enum  MVD_EDGE_PAIR_FLAW_TYPE
         *  @brief Type of the flaw of the edge pair insp
         */
        typedef _MVD_EDGEINSP_EDGE_PAIR_FLAW_TYPE__ MVD_EDGE_PAIR_FLAW_TYPE;
        /*************************** Params Class Start ***************************/
        // CH: 边缘查找类型 | EN: Edge Search Type
        typedef enum _EdgePairFindModeEnum
        {
            // CH: 最宽边缘对 | EN: Widest edge pair
            EdgePairFindMode_Widest = 0x1,

            // CH: 最接近边缘对 | EN: Nearest edge pair
            EdgePairFindMode_Nearest = 0x2,

            // CH: 最强最接近边缘对 | EN: Strongest & Nearest Edge Pair
            EdgePairFindMode_StrongestNearest = 0x3,

        }EdgePairFindModeEnum;

        // CH: 边缘0极性 | EN: Edge 0 polarity
        typedef enum _EdgePairEdge0PolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgePairEdge0Polarity_B2W = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgePairEdge0Polarity_W2B = 0x2,

            // CH: 任意极性 | EN: Both
            EdgePairEdge0Polarity_All = 0x3,

        }EdgePairEdge0PolarityEnum;

        // CH: 边缘1极性 | EN: Edge 1 polarity
        typedef enum _EdgePairEdge1PolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgePairEdge1Polarity_B2W = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgePairEdge1Polarity_W2B = 0x2,

            // CH: 任意极性 | EN: Both
            EdgePairEdge1Polarity_All = 0x3,

        }EdgePairEdge1PolarityEnum;

        /*  Note: Interface Classes of the parameter of the EdgePairFlawInspParams.  */
        class EdgePairFlawInspParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgePairFlawInspParams() {}
            virtual ~EdgePairFlawInspParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 边缘查找类型 | EN: Edge Search Type
            __declspec(property(put = SetEdgePairFindMode, get = GetEdgePairFindMode)) EdgePairFindModeEnum EdgePairFindMode;

            virtual EdgePairFindModeEnum GetEdgePairFindMode() = 0;

            virtual void SetEdgePairFindMode(EdgePairFindModeEnum value) = 0;

            // CH: 卡尺高度 | EN: CaliperHeight
            __declspec(property(put = SetCaliperHeight, get = GetCaliperHeight)) int CaliperHeight;

            virtual int GetCaliperHeight() = 0;

            virtual void SetCaliperHeight(int value) = 0;

            // CH: 卡尺宽度 | EN: CaliperWidth
            __declspec(property(put = SetCaliperWidth, get = GetCaliperWidth)) int CaliperWidth;

            virtual int GetCaliperWidth() = 0;

            virtual void SetCaliperWidth(int value) = 0;

            // CH: 理想宽度 | EN: Ideal Width
            __declspec(property(put = SetEdgePairIdealWidth, get = GetEdgePairIdealWidth)) int EdgePairIdealWidth;

            virtual int GetEdgePairIdealWidth() = 0;

            virtual void SetEdgePairIdealWidth(int value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeStrength, get = GetEdgeStrength)) int EdgeStrength;

            virtual int GetEdgeStrength() = 0;

            virtual void SetEdgeStrength(int value) = 0;

            // CH: 边缘0极性 | EN: Edge 0 polarity
            __declspec(property(put = SetEdgePairEdge0Polarity, get = GetEdgePairEdge0Polarity)) EdgePairEdge0PolarityEnum EdgePairEdge0Polarity;

            virtual EdgePairEdge0PolarityEnum GetEdgePairEdge0Polarity() = 0;

            virtual void SetEdgePairEdge0Polarity(EdgePairEdge0PolarityEnum value) = 0;

            // CH: 边缘1极性 | EN: Edge 1 polarity
            __declspec(property(put = SetEdgePairEdge1Polarity, get = GetEdgePairEdge1Polarity)) EdgePairEdge1PolarityEnum EdgePairEdge1Polarity;

            virtual EdgePairEdge1PolarityEnum GetEdgePairEdge1Polarity() = 0;

            virtual void SetEdgePairEdge1Polarity(EdgePairEdge1PolarityEnum value) = 0;

            // CH: 中心点使能 | EN: Midpoint Enable
            __declspec(property(put = SetMidPointEnable, get = GetMidPointEnable)) bool MidPointEnable;

            virtual bool GetMidPointEnable() = 0;

            virtual void SetMidPointEnable(bool value) = 0;

            // CH: 缺陷长度阈值 | EN: Defect Length Threshold
            __declspec(property(put = SetLenThresh, get = GetLenThresh)) int LenThresh;

            virtual int GetLenThresh() = 0;

            virtual void SetLenThresh(int value) = 0;

            // CH: 宽度缺陷使能 | EN: Width Defect Enable
            __declspec(property(put = SetWidthEnable, get = GetWidthEnable)) bool WidthEnable;

            virtual bool GetWidthEnable() = 0;

            virtual void SetWidthEnable(bool value) = 0;

            // CH: 宽度合格比例 | EN: Width Eligibility Ratio
            __declspec(property(put = SetWidthLowOffset, get = GetWidthLowOffset)) int WidthLowOffset;

            virtual int GetWidthLowOffset() = 0;

            virtual void SetWidthLowOffset(int value) = 0;

            // CH: 宽度合格比例 | EN: Width Eligibility Ratio
            __declspec(property(put = SetWidthHighOffset, get = GetWidthHighOffset)) int WidthHighOffset;

            virtual int GetWidthHighOffset() = 0;

            virtual void SetWidthHighOffset(int value) = 0;

            // CH: 位置缺陷使能 | EN: Location Defect Enable
            __declspec(property(put = SetOffsetEnable, get = GetOffsetEnable)) bool OffsetEnable;

            virtual bool GetOffsetEnable() = 0;

            virtual void SetOffsetEnable(bool value) = 0;

            // CH: 位置偏移阈值 | EN: Location Deviation Threshold
            __declspec(property(put = SetOffsetThresh, get = GetOffsetThresh)) int OffsetThresh;

            virtual int GetOffsetThresh() = 0;

            virtual void SetOffsetThresh(int value) = 0;

            // CH: 断裂缺陷使能 | EN: Fracture Defect Enable
            __declspec(property(put = SetCrackEnable, get = GetCrackEnable)) bool CrackEnable;

            virtual bool GetCrackEnable() = 0;

            virtual void SetCrackEnable(bool value) = 0;

            // CH: 阶梯缺陷使能 | EN: Enable Hierarchical Defect
            __declspec(property(put = SetGradEnable, get = GetGradEnable)) bool GradEnable;

            virtual bool GetGradEnable() = 0;

            virtual void SetGradEnable(bool value) = 0;

            // CH: 阶梯偏离高度 | EN: Hierarchy Deviation Height
            __declspec(property(put = SetGradThresh, get = GetGradThresh)) int GradThresh;

            virtual int GetGradThresh() = 0;

            virtual void SetGradThresh(int value) = 0;

            // CH: 最小阶梯长度 | EN: Min. Hierarchy Length
            __declspec(property(put = SetGradLen, get = GetGradLen)) int GradLen;

            virtual int GetGradLen() = 0;

            virtual void SetGradLen(int value) = 0;

            // CH: 气泡缺陷检测 | EN: Bubble Defect Detect
            __declspec(property(put = SetBubbleEnable, get = GetBubbleEnable)) bool BubbleEnable;

            virtual bool GetBubbleEnable() = 0;

            virtual void SetBubbleEnable(bool value) = 0;

            // CH: 灰度合格阈值 | EN: Grayscale acceptance threshold
            __declspec(property(put = SetBubbleLowOffset, get = GetBubbleLowOffset)) int BubbleLowOffset;

            virtual int GetBubbleLowOffset() = 0;

            virtual void SetBubbleLowOffset(int value) = 0;

            // CH: 灰度合格阈值 | EN: Grayscale acceptance threshold
            __declspec(property(put = SetBubbleHighOffset, get = GetBubbleHighOffset)) int BubbleHighOffset;

            virtual int GetBubbleHighOffset() = 0;

            virtual void SetBubbleHighOffset(int value) = 0;

            // CH: 灰度突变阈值 | EN: Grayscale change threshold
            __declspec(property(put = SetBubbleChangeThresh, get = GetBubbleChangeThresh)) int BubbleChangeThresh;

            virtual int GetBubbleChangeThresh() = 0;

            virtual void SetBubbleChangeThresh(int value) = 0;

            // CH: 气泡缺陷长度 | EN: Bubble defect length
            __declspec(property(put = SetBubbleLen, get = GetBubbleLen)) int BubbleLen;

            virtual int GetBubbleLen() = 0;

            virtual void SetBubbleLen(int value) = 0;

            // CH: 最大突变次数 | EN: Maximum number of mutations
            __declspec(property(put = SetBubbleGrayChangeNum, get = GetBubbleGrayChangeNum)) int BubbleGrayChangeNum;

            virtual int GetBubbleGrayChangeNum() = 0;

            virtual void SetBubbleGrayChangeNum(int value) = 0;

            // CH: 灰度辅助检测 | EN: Grayscale assisted detection
            __declspec(property(put = SetGrayTrackEnable, get = GetGrayTrackEnable)) bool GrayTrackEnable;

            virtual bool GetGrayTrackEnable() = 0;

            virtual void SetGrayTrackEnable(bool value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetHalfKernelSize, get = GetHalfKernelSize)) int HalfKernelSize;

            virtual int GetHalfKernelSize() = 0;

            virtual void SetHalfKernelSize(int value) = 0;

            // CH: 追踪容忍 | EN: Track Distol
            __declspec(property(put = SetGrayTrackDistol, get = GetGrayTrackDistol)) int GrayTrackDistol;

            virtual int GetGrayTrackDistol() = 0;

            virtual void SetGrayTrackDistol(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes for describing edge pair width info.  */
        class IEdgePairWidthInfo
        {
        protected:
            // Constructor and Destructor
            explicit IEdgePairWidthInfo() {}
            virtual ~IEdgePairWidthInfo() {}

        public:
            // Property
            /**
             * @par 说明
             * 最大宽度
             * @par 权限
             * 只读
             */
            virtual float GetMaxWidth() = 0;
            /**
             * @par 说明
             * 最小宽度
             * @par 权限
             * 只读
             */
            virtual float GetMinWidth() = 0;
            /**
             * @par 说明
             * 平均宽度
             * @par 权限
             * 只读
             */
            virtual float GetAverageWidth() = 0;
            /**
             * @par 说明
             * 边缘对的数量
             * @par 权限
             * 只读
             */
            virtual int GetNumOfEdgePair() = 0;
            /**
             * @brief 获取边缘对宽度信息
             * @param 无
             * @return 边缘对宽度信息数组的首地址,数组长度为NumOfEdgePair
             * @par 注解
             * 
             */
            virtual float* GetEdgePairWidthArray() = 0;
        };

        /*  Note: Interface Classes for describing single match info.  */
        class IEdgePairFlawInfo
        {
        protected:
            // Constructor and Destructor
            explicit IEdgePairFlawInfo() {}
            virtual ~IEdgePairFlawInfo() {}

        public:
            // Property
            /*  Note: Get the bounding rectangle of the flaw. */
            /**
             * @par 说明
             * 缺陷类型
             * @par 权限
             * 只读
             */
            virtual MVD_EDGE_PAIR_FLAW_TYPE GetFlawType() = 0;
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
        };

        /*  Note: Interface Classes of the result of the EdgePairFlawInspResults.  */
        class EdgePairFlawInspResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgePairFlawInspResults() {}
            virtual ~EdgePairFlawInspResults() {}

        public:
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
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
             * @param nFlawIndex [in] 缺陷的索引，[0, FlawNum)
             * @return 无，出错时抛出异常
             * @par 注解
             * 无
             */
            virtual IEdgePairFlawInfo* GetFlawInfo( int nFlawIndex ) = 0;
            /**
             * @brief 获取边缘对宽度信息
             * @return 无，出错时抛出异常
             * @par 注解
             * 
             */
            virtual IEdgePairWidthInfo* GetFlawWidthInfo() = 0;
            /**
             * @brief 获取边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePointNum() = 0;
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
             * @brief 根据索引查询边缘点1
             * @param nIndex   [IN]  边缘点1的索引，[0, EdgePointNum)
             * @param stPoint1 [OUT] 边缘点1
             * @param nStatus  [OUT] 边缘点1状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetEdge1Point(int nIndex, MVD_POINT_F &stPoint1, int &nStatus) = 0;
            /**
             * @brief 根据索引查询边缘中点
             * @param nIndex     [IN]  边缘中点的索引，[0, EdgePointNum)
             * @param stMidPoint [OUT] 边缘点中点
             * @param nStatus    [OUT] 边缘点中点状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetEdgeMiddlePoint(int nIndex, MVD_POINT_F &stMidPoint, int &nStatus) = 0;
            /**
             * @brief 获取卡尺数量
             * @return 卡尺数量
             * @par 注解
             * 无
             */
            virtual int GetCaliperNum() = 0;
            /**
             * @brief 获取卡尺中心点
             * @param nIndex [IN] 卡尺box的索引[0, CaliperNum)
             * @return 卡尺中心点
             * @par 注解
             * 
             */
            virtual MVD_POINT_F GetCaliperCenterPoint(int nIndex) = 0;
            /**
             * @brief 获取卡尺box
             * @param nIndex [IN] 卡尺box的索引[0, CaliperNum)
             * @return 
             * @par 注解
             * 
             */
            virtual RectBox GetCaliperBox(int nIndex) = 0;

            /**
             * @par 说明
             * 人工绘制每条轨迹的点个数 nTrajIndex [IN] 轨迹索引,[0, IdeaTrajNum)
             * @par 权限
             * 只读
             */
            virtual int GetTrajPtsNum(int nTrajIndex) = 0;

            /**
             * @par 说明
             * 获取特定卡尺 nTrajCaliperIndex [IN] 卡尺索引,[0, sum(TrajPtsNum))
             * @par 权限
             * 只读
             */
            virtual RectBox GetIdeaTrajCaliper(int nTrajCaliperIndex) = 0;

            /**
             * @brief 获取理想边缘点0信息
             * @param nIndex [IN] 边缘点索引,[0, EdgePointNum)
             * @return 边缘0的边缘点
             * @par 注解
             * 
             */
            virtual MVD_POINT_F GetIdeaEdge0Point(int nIndex) = 0;

            /**
             * @brief 获取理想边缘点1信息
             * @param nIndex [IN] 边缘点索引,[0, EdgePointNum)
             * @return 边缘1的边缘点
             * @par 注解
             * 
             */
            virtual MVD_POINT_F GetIdeaEdge1Point(int nIndex) = 0;

            /**
             * @brief 获取人工轨迹信息
             * @param nIndex [IN] 人工轨迹索引,[0, sum(TrajPtsNum))
             * @return 边缘1的边缘点
             * @par 注解
             * 
             */
            virtual MVD_POINT_F GetIdeaTraj(int nIndex) = 0;

            /**
             * @brief 根据索引获取优化轨迹的信息
             * @param nCalTrajIndex [in] 优化轨迹的索引，[0, sum(TrajPtsNum)), stCalTraj [out]优化轨迹信息，CalTrajFlag [out]优化轨迹状态
             * @return 返回索引处轨迹信息   当前仅支持一条即nPolygonIndex为0
             * @par 注解
             * 无
             */
            virtual void GetCalTraj(int nCalTrajIndex ,MVD_POINT_F &stCalTraj, int &CalTrajFlag) = 0;

            /**
             * @par 说明
             * 人工绘制轨迹条数
             * @par 权限
             * 只读
             */
            virtual int GetIdeaTrajNum() = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the EdgePairFlawInsp tool.  */
        class IMVSEdgePairFlawInspModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSEdgePairFlawInspModuTool() {}
            virtual ~IMVSEdgePairFlawInspModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual EdgePairFlawInspParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual EdgePairFlawInspResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

            /**
            * @brief 导入模型
            * @param 模型路径
            * @return 无，出错时抛出异常
            * @par 注解
            * 导入模型
            */
            virtual void ImportModelData(IN const char * const strPath) = 0;
        private:
            IMVSEdgePairFlawInspModuTool(IMVSEdgePairFlawInspModuTool&);
            IMVSEdgePairFlawInspModuTool& operator=(IMVSEdgePairFlawInspModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for EdgePairFlawInsp.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSEdgePairFlawInspModu::IMVSEdgePairFlawInspModuTool * __stdcall GetEdgePairFlawInspToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_EDGEPAIRFLAWINSP_H_
