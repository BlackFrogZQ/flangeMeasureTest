/***************************************************************************************************
 * File：IVmEdgePosTrendAnaly.h
 * Note：CH: 边缘位置趋势分析模块接口声明 | En: Interface for the EdgePosTrendAnaly tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_EDGEPOSTRENDANALY_H_
#define _IVM_EDGEPOSTRENDANALY_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSEdgePosTrendAnalyModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 边缘类型 | EN: Edge Type
        typedef enum _FindModeEnum
        {
            // CH: 最强 | EN: Strongest Edge
            FindMode_Best = 0x1,

            // CH: 第一条边缘 | EN: Fisrt Edge
            FindMode_First = 0x2,

            // CH: 最后一条边缘 | EN: Last Edge
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

        // CH: 边缘查找方向 | EN: Edge Search Direction
        typedef enum _DetechOrientEnum
        {
            // CH: 从上到下 | EN: Top to Bottom
            DetechOrient_T2B = 0x1,

            // CH: 从左到右 | EN: Left to Right
            DetechOrient_L2R = 0x2,

        }DetechOrientEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class EdgePosTrendAnalyRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the EdgePosTrendAnalyParams.  */
        class EdgePosTrendAnalyParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgePosTrendAnalyParams() {}
            virtual ~EdgePosTrendAnalyParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual EdgePosTrendAnalyRoiManager* GetModuRoiManager() = 0;

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
        /*  Note: Interface Classes of the result of the EdgePosTrendAnalyResults.  */
        class EdgePosTrendAnalyResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgePosTrendAnalyResults() {}
            virtual ~EdgePosTrendAnalyResults() {}

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
            * @brief 获取边缘点提取总数
            * @param 无
            * @return 边缘点提取总数
            * @par 注解
            * 无
            */
            virtual int GetEdgePosCount() = 0;
            /**
            * @brief 获取边缘点最小距离
            * @param 无
            * @return 边缘点最小距离
            * @par 注解
            * 无
            */
            virtual float GetEdgePosMinDistance() = 0;
            /**
            * @brief 获取边缘点最大距离
            * @param 无
            * @return 边缘点最大距离
            * @par 注解
            * 无
            */
            virtual float GetEdgePosMaxDistance() = 0;
            /**
            * @brief 获取边缘点平均距离
            * @param 无
            * @return 边缘点平均距离
            * @par 注解
            * 无
            */
            virtual float GetEdgePosAverageDistance() = 0;
            /**
            * @brief 获取目标边缘点总数
            * @param 无
            * @return 目标边缘点总数
            * @par 注解
            * 无
            */
            virtual int GetSelEdgePosCount() = 0;
            /**
            * @brief 获取目标边缘点最小距离
            * @param 无
            * @return 目标边缘点最小距离
            * @par 注解
            * 无
            */
            virtual float GetSelEdgePosMinDistance() = 0;
            /**
            * @brief 获取目标边缘点最大距离
            * @param 无
            * @return 目标边缘点最大距离
            * @par 注解
            * 无
            */
            virtual float GetSelEdgePosMaxDistance() = 0;
            /**
            * @brief 获取目标边缘点平均距离
            * @param 无
            * @return 目标边缘点平均距离
            * @par 注解
            * 无
            */
            virtual float GetSelEdgePosAverageDistance() = 0;
            /**
            * @brief 获取卡尺数量
            * @param 无
            * @return 卡尺数量
            * @par 注解
            * 无
            */
            virtual int GetCaliperCount() = 0;
            /**
            * @brief 获取边缘点最小距离索引点
            * @param 无
            * @return 边缘点最小距离索引点
            * @par 注解
            * 无
            */
            virtual PointF GetMinDistPoint() = 0;
            /**
            * @brief 获取边缘点最大距离索引点
            * @param 无
            * @return 边缘点最大距离索引点
            * @par 注解
            * 无
            */
            virtual PointF GetMaxDistPoint() = 0;

            /*  Note:[边缘点信息].  */
            /**
            * @brief 获取边缘点个数
            * @param 无
            * @return 边缘点个数
            * @par 注解
            * 无
            */
            virtual int GetEdgePointCount() = 0;
            /**
            * @brief 获取边缘点
            * @param nIndex [in] 边缘点的索引,[0, 边缘点个数)
            * @return 边缘点
            * @par 注解
            * 无
            */
            virtual PointF GetEdgePoint(int nIndex) = 0;
            /**
            * @brief 获取边缘得分
            * @param nIndex [in] 边缘点的索引,[0, 边缘点个数)
            * @return 边缘得分
            * @par 注解
            * 无
            */
            virtual float GetScore(int nIndex) = 0;
            /**
            * @brief 获取边缘极性
            * @param nIndex [in] 边缘点的索引,[0, 边缘点个数)
            * @return 边缘极性
            * @par 注解
            * 无
            */
            virtual int GetPolarity(int nIndex) = 0;
            /**
            * @brief 获取边缘距离
            * @param nIndex [in] 边缘点的索引,[0, 边缘点个数)
            * @return 边缘距离
            * @par 注解
            * 无
            */
            virtual float GetDist(int nIndex) = 0;
            /**
            * @brief 获取边缘点查找状态，1为正常，其他为异常。
            * @param nIndex [in] 边缘点的索引,[0, 边缘点个数)
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
        /*  Note: Note: This is the class for the EdgePosTrendAnaly tool.  */
        class IMVSEdgePosTrendAnalyModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSEdgePosTrendAnalyModuTool() {}
            virtual ~IMVSEdgePosTrendAnalyModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual EdgePosTrendAnalyParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual EdgePosTrendAnalyResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSEdgePosTrendAnalyModuTool(IMVSEdgePosTrendAnalyModuTool&);
            IMVSEdgePosTrendAnalyModuTool& operator=(IMVSEdgePosTrendAnalyModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for EdgePosTrendAnaly.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSEdgePosTrendAnalyModu::IMVSEdgePosTrendAnalyModuTool * __stdcall GetEdgePosTrendAnalyToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_EDGEPOSTRENDANALY_H_
