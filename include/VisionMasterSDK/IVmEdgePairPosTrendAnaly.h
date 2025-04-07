/***************************************************************************************************
 * File：IVmEdgePairPosTrendAnaly.h
 * Note：CH: 边缘对位置趋势分析模块接口声明 | En: Interface for the EdgePairPosTrendAnaly tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_EDGEPAIRPOSTRENDANALY_H_
#define _IVM_EDGEPAIRPOSTRENDANALY_H_
#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;
#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSEdgePairPosTrendAnalyModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 边缘类型 | EN: Edge Type
        typedef enum _FindModeEnum
        {
            // CH: 最宽边缘对 | EN: Widest edge pair
            FindMode_WidestEdgePair = 0x1,

            // CH: 最窄边缘对 | EN: Narrowest edge pair
            FindMode_NarrowestEdgePair = 0x2,

            // CH: 最强边缘对 | EN: Strongest edge pair
            FindMode_StrongestEdgePair = 0x3,

            // CH: 最弱边缘对 | EN: Weakest edge pair
            FindMode_WeakestEdgePair = 0x4,

            // CH: 第一个边缘对 | EN: First edge pair
            FindMode_FirstEdgePair = 0x5,

            // CH: 最后一个边缘对 | EN: Last edge pair
            FindMode_LastEdgePair = 0x6,

            // CH: 最接近边缘对 | EN: Nearest edge pair
            FindMode_NearestEdgePair = 0x7,

            // CH: 最不接近边缘对 | EN: Farthest edge pair
            FindMode_FarthestEdgePair = 0x8,

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

        // CH: 边缘查找方向 | EN: Edge Search Direction
        typedef enum _DetechOrientEnum
        {
            // CH: 从上到下 | EN: Top to Bottom
            DetechOrient_T2B = 0x1,

            // CH: 从左到右 | EN: Left to Right
            DetechOrient_L2R = 0x2,

        }DetechOrientEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class EdgePairPosTrendAnalyRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the EdgePairPosTrendAnalyParams.  */
        class EdgePairPosTrendAnalyParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgePairPosTrendAnalyParams() {}
            virtual ~EdgePairPosTrendAnalyParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual EdgePairPosTrendAnalyRoiManager* GetModuRoiManager() = 0;

            // CH: 边缘类型 | EN: Edge Type
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

            // CH: 中心点使能 | EN: Midpoint Enable
            __declspec(property(put = SetMidPointEnable, get = GetMidPointEnable)) bool MidPointEnable;

            virtual bool GetMidPointEnable() = 0;

            virtual void SetMidPointEnable(bool value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetHalfKernelSize, get = GetHalfKernelSize)) int HalfKernelSize;

            virtual int GetHalfKernelSize() = 0;

            virtual void SetHalfKernelSize(int value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeStrength, get = GetEdgeStrength)) int EdgeStrength;

            virtual int GetEdgeStrength() = 0;

            virtual void SetEdgeStrength(int value) = 0;

            // CH: 理想边缘宽度 | EN: Idea edge width
            __declspec(property(put = SetIdeaWid, get = GetIdeaWid)) int IdeaWid;

            virtual int GetIdeaWid() = 0;

            virtual void SetIdeaWid(int value) = 0;

            // CH: 卡尺数量 | EN: Caliper Number
            __declspec(property(put = SetCaliperCount, get = GetCaliperCount)) int CaliperCount;

            virtual int GetCaliperCount() = 0;

            virtual void SetCaliperCount(int value) = 0;

            // CH: 边缘查找方向 | EN: Edge Search Direction
            __declspec(property(put = SetDetechOrient, get = GetDetechOrient)) DetechOrientEnum DetechOrient;

            virtual DetechOrientEnum GetDetechOrient() = 0;

            virtual void SetDetechOrient(DetechOrientEnum value) = 0;

            // CH: 卡尺宽度 | EN: CaliperWidth
            __declspec(property(put = SetProjectionLength, get = GetProjectionLength)) int ProjectionLength;

            virtual int GetProjectionLength() = 0;

            virtual void SetProjectionLength(int value) = 0;

            // CH: 距离低阈值 | EN: Distance Lower Threshold
            __declspec(property(put = SetDistLow, get = GetDistLow)) int DistLow;

            virtual int GetDistLow() = 0;

            virtual void SetDistLow(int value) = 0;

            // CH: 高阈值使能 | EN: High Threshold Enable
            __declspec(property(put = SetDistHighIsAutoEnable, get = GetDistHighIsAutoEnable)) bool DistHighIsAutoEnable;

            virtual bool GetDistHighIsAutoEnable() = 0;

            virtual void SetDistHighIsAutoEnable(bool value) = 0;

            // CH: 距离高阈值 | EN: Distance High Threshold
            __declspec(property(put = SetDistHigh, get = GetDistHigh)) int DistHigh;

            virtual int GetDistHigh() = 0;

            virtual void SetDistHigh(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the EdgePairPosTrendAnalyResults.  */
        class EdgePairPosTrendAnalyResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgePairPosTrendAnalyResults() {}
            virtual ~EdgePairPosTrendAnalyResults() {}

        public:
            /**
            * @brief 获取模块状态
            * @param 无
            * @return 模块状态
            * @par 权限
            * 只读
            */
            virtual int GetModuStatus() = 0;

            /*  Note:[趋势信息].  */
            /**
            * @brief 获取边缘对提取总数
            * @param 无
            * @return 边缘对提取总数
            * @par 注解
            * 无
            */
            virtual int GetEdgePairCount() = 0;
            /**
            * @brief 获取边缘对最小距离
            * @param 无
            * @return 边缘对最小距离
            * @par 注解
            * 无
            */
            virtual float GetEdgePairMinDistance() = 0;
            /**
            * @brief 获取边缘对最大距离
            * @param 无
            * @return 边缘对最大距离
            * @par 注解
            * 无
            */
            virtual float GetEdgePairMaxDistance() = 0;
            /**
            * @brief 获取边缘对平均距离
            * @param 无
            * @return 边缘对平均距离
            * @par 注解
            * 无
            */
            virtual float GetEdgePairAverageDistance() = 0;
            /**
            * @brief 获取目标边缘对总数
            * @param 无
            * @return 目标边缘对总数
            * @par 注解
            * 无
            */
            virtual int GetSelEdgePairCount() = 0;
            /**
            * @brief 获取目标边缘对最小距离
            * @param 无
            * @return 目标边缘对最小距离
            * @par 注解
            * 无
            */
            virtual float GetSelEdgePairMinDistance() = 0;
            /**
            * @brief 获取目标边缘对最大距离
            * @param 无
            * @return 目标边缘对最大距离
            * @par 注解
            * 无
            */
            virtual float GetSelEdgePairMaxDistance() = 0;
            /**
            * @brief 获取目标边缘对平均距离
            * @param 无
            * @return 目标边缘对平均距离
            * @par 注解
            * 无
            */
            virtual float GetSelEdgePairAverageDistance() = 0;
            /**
            * @brief 获取卡尺数量
            * @param 无
            * @return 卡尺数量
            * @par 注解
            * 无
            */
            virtual int GetCaliperCount() = 0;
            /**
            * @brief 获取边缘对最小距离拟合直线点0
            * @param 无
            * @return 边缘对最小距离拟合直线点0
            * @par 注解
            * 无
            */
            virtual PointF GetMinDistPoint0() = 0;
            /**
            * @brief 获取边缘对最小距离拟合直线点1
            * @param 无
            * @return 边缘对最小距离拟合直线点1
            * @par 注解
            * 无
            */
            virtual PointF GetMinDistPoint1() = 0;
            /**
            * @brief 获取边缘对最大距离拟合直线点0
            * @param 无
            * @return 边缘对最大距离拟合直线点0
            * @par 注解
            * 无
            */
            virtual PointF GetMaxDistPoint0() = 0;
            /**
            * @brief 获取边缘对最大距离拟合直线点1
            * @param 无
            * @return 边缘对最大距离拟合直线点1
            * @par 注解
            * 无
            */
            virtual PointF GetMaxDistPoint1() = 0;

            /*  Note:[边缘对信息].  */
            /**
            * @brief 获取边缘对个数
            * @param 无
            * @return 边缘对个数
            * @par 注解
            * 无
            */
            virtual int GetEdgePairPointCount() = 0;
            /**
            * @brief 获取边缘点0
            * @param nIndex [in] 边缘对的索引,[0, 边缘对个数)
            * @return 边缘点0
            * @par 注解
            * 无
            */
            virtual PointF GetEdgePoint0(int nIndex) = 0;
            /**
            * @brief 获取边缘点1
            * @param nIndex [in] 边缘对的索引,[0, 边缘对个数)
            * @return 边缘点1
            * @par 注解
            * 无
            */
            virtual PointF GetEdgePoint1(int nIndex) = 0;
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
            * @brief 获取边缘得分
            * @param nIndex [in] 边缘对的索引,[0, 边缘对个数)
            * @return 边缘得分
            * @par 注解
            * 无
            */
            virtual float GetScore(int nIndex) = 0;
            /**
            * @brief 获取边缘0极性
            * @param nIndex [in] 边缘对的索引,[0, 边缘对个数)
            * @return 边缘0极性
            * @par 注解
            * 无
            */
            virtual int GetPolarity0(int nIndex) = 0;
            /**
            * @brief 获取边缘1极性
            * @param nIndex [in] 边缘对的索引,[0, 边缘对个数)
            * @return 边缘1极性
            * @par 注解
            * 无
            */
            virtual int GetPolarity1(int nIndex) = 0;
            /**
            * @brief 获取边缘距离
            * @param nIndex [in] 边缘对的索引,[0, 边缘对个数)
            * @return 边缘距离
            * @par 注解
            * 无
            */
            virtual float GetDist(int nIndex) = 0;
            /**
            * @brief 获取边缘点查找状态，1为正常，其他为异常。
            * @param nIndex [in] 边缘对的索引,[0, 边缘对个数)
            * @return 边缘点查找状态
            * @par 注解
            * 无
            */
            virtual int GetStatus(int nIndex) = 0;
            /**
            * @brief 获取ROI区域
            * @param 无
            * @return ROI区域信息
            * @par 权限
            * 只读
            */
            virtual RectBox GetROI() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the EdgePairPosTrendAnaly tool.  */
        class IMVSEdgePairPosTrendAnalyModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSEdgePairPosTrendAnalyModuTool() {}
            virtual ~IMVSEdgePairPosTrendAnalyModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual EdgePairPosTrendAnalyParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual EdgePairPosTrendAnalyResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSEdgePairPosTrendAnalyModuTool(IMVSEdgePairPosTrendAnalyModuTool&);
            IMVSEdgePairPosTrendAnalyModuTool& operator=(IMVSEdgePairPosTrendAnalyModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for EdgePairPosTrendAnaly.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSEdgePairPosTrendAnalyModu::IMVSEdgePairPosTrendAnalyModuTool * __stdcall GetEdgePairPosTrendAnalyToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_EDGEPAIRPOSTRENDANALY_H_
