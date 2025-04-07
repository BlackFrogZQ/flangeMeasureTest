/***************************************************************************************************
 * File：IVmCaliperCorner.h
 * Note：CH: 边缘交点模块接口声明 | En: Interface for the CaliperCorner tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CALIPERCORNER_H_
#define _IVM_CALIPERCORNER_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCaliperCornerModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 边缘1类型 | EN: Edge 1 Type
        typedef enum _Edge0TypeEnum
        {
            // CH: 最强 | EN: Strongest Edge
            Edge0Type_Best = 0x1,

            // CH: 第一条 | EN: First Edge
            Edge0Type_First = 0x2,

            // CH: 最后一条 | EN: Last Edge
            Edge0Type_Last = 0x3,

        }Edge0TypeEnum;

        // CH: 边缘1极性 | EN: Edge 1 polarity
        typedef enum _Edge0PolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            Edge0Polarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            Edge0Polarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            Edge0Polarity_Both = 0x3,

        }Edge0PolarityEnum;

        // CH: 边缘2类型 | EN: Edge 2 Type
        typedef enum _Edge1TypeEnum
        {
            // CH: 最强 | EN: Strongest Edge
            Edge1Type_Best = 0x1,

            // CH: 第一条 | EN: First Edge
            Edge1Type_First = 0x2,

            // CH: 最后一条 | EN: Last Edge
            Edge1Type_Last = 0x3,

        }Edge1TypeEnum;

        // CH: 边缘2极性 | EN: Edge 2 Polarity
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
        class CaliperCornerRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox* pRoiValue, unsigned int nValueNum) = 0;

        };

        /*  Note: Interface Classes of the parameter of the CaliperCornerParams.  */
        class CaliperCornerParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CaliperCornerParams() {}
            virtual ~CaliperCornerParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual CaliperCornerRoiManager* GetModuRoiManager() = 0;

            // CH: 边缘1类型 | EN: Edge 1 Type
            __declspec(property(put = SetEdge0Type, get = GetEdge0Type)) Edge0TypeEnum Edge0Type;

            virtual Edge0TypeEnum GetEdge0Type() = 0;

            virtual void SetEdge0Type(Edge0TypeEnum value) = 0;

            // CH: 边缘1极性 | EN: Edge 1 polarity
            __declspec(property(put = SetEdge0Polarity, get = GetEdge0Polarity)) Edge0PolarityEnum Edge0Polarity;

            virtual Edge0PolarityEnum GetEdge0Polarity() = 0;

            virtual void SetEdge0Polarity(Edge0PolarityEnum value) = 0;

            // CH: 边缘2类型 | EN: Edge 2 Type
            __declspec(property(put = SetEdge1Type, get = GetEdge1Type)) Edge1TypeEnum Edge1Type;

            virtual Edge1TypeEnum GetEdge1Type() = 0;

            virtual void SetEdge1Type(Edge1TypeEnum value) = 0;

            // CH: 边缘2极性 | EN: Edge 2 Polarity
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

            // CH: 交点X判断 | EN: Intersection X Check
            __declspec(property(put = SetCornerPointXLimitEnable, get = GetCornerPointXLimitEnable)) bool CornerPointXLimitEnable;

            virtual bool GetCornerPointXLimitEnable() = 0;

            virtual void SetCornerPointXLimitEnable(bool value) = 0;

            // CH: 交点X范围 | EN: Intersection X Range
            __declspec(property(put = SetCornerPointXLimitLow, get = GetCornerPointXLimitLow)) double CornerPointXLimitLow;

            virtual double GetCornerPointXLimitLow() = 0;

            virtual void SetCornerPointXLimitLow(double value) = 0;

            // CH: 交点X范围 | EN: Intersection X Range
            __declspec(property(put = SetCornerPointXLimitHigh, get = GetCornerPointXLimitHigh)) double CornerPointXLimitHigh;

            virtual double GetCornerPointXLimitHigh() = 0;

            virtual void SetCornerPointXLimitHigh(double value) = 0;

            // CH: 交点Y判断 | EN: Intersection Y Check
            __declspec(property(put = SetCornerPointYLimitEnable, get = GetCornerPointYLimitEnable)) bool CornerPointYLimitEnable;

            virtual bool GetCornerPointYLimitEnable() = 0;

            virtual void SetCornerPointYLimitEnable(bool value) = 0;

            // CH: 交点Y范围 | EN: Intersection Y Range
            __declspec(property(put = SetCornerPointYLimitLow, get = GetCornerPointYLimitLow)) double CornerPointYLimitLow;

            virtual double GetCornerPointYLimitLow() = 0;

            virtual void SetCornerPointYLimitLow(double value) = 0;

            // CH: 交点Y范围 | EN: Intersection Y Range
            __declspec(property(put = SetCornerPointYLimitHigh, get = GetCornerPointYLimitHigh)) double CornerPointYLimitHigh;

            virtual double GetCornerPointYLimitHigh() = 0;

            virtual void SetCornerPointYLimitHigh(double value) = 0;

            // CH: 交点角度判断 | EN: Intersection Angle Check
            __declspec(property(put = SetCornerAngleLimitEnable, get = GetCornerAngleLimitEnable)) bool CornerAngleLimitEnable;

            virtual bool GetCornerAngleLimitEnable() = 0;

            virtual void SetCornerAngleLimitEnable(bool value) = 0;

            // CH: 交点角度范围 | EN: Intersection Angle Range
            __declspec(property(put = SetCornerAngleLimitLow, get = GetCornerAngleLimitLow)) double CornerAngleLimitLow;

            virtual double GetCornerAngleLimitLow() = 0;

            virtual void SetCornerAngleLimitLow(double value) = 0;

            // CH: 交点角度范围 | EN: Intersection Angle Range
            __declspec(property(put = SetCornerAngleLimitHigh, get = GetCornerAngleLimitHigh)) double CornerAngleLimitHigh;

            virtual double GetCornerAngleLimitHigh() = 0;

            virtual void SetCornerAngleLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /** @enum  MVD_EDGEPOINT_STATUS
         *  @brief 边缘点状态
         */
        typedef _MVD_EDGEPOINT_STATUS__ MVD_EDGEPOINT_STATUS;

        /** @enum  MVD_EDGE_POLARITY
         *  @brief 边缘极性
         */
        typedef _MVD_EDGE_POLARITY__ MVD_EDGE_POLARITY;

        /*  Note: 边缘点信息描述类.  */
        class ICornerFindEdgePointInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit ICornerFindEdgePointInfo() {}
            virtual ~ICornerFindEdgePointInfo() {}

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

        /*  Note: 查找结果中边缘线信息.  */
        class ICornerFindLineInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit ICornerFindLineInfo() {}
            virtual ~ICornerFindLineInfo() {}

        public:
            /**
             * @par 说明
             * 直线位置
             * @par 权限
             * 只读
             */
            virtual Line GetLine() = 0;
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
            virtual ICornerFindEdgePointInfo* GetEdgePointInfo(int nPtIndex) = 0;
        };

        /*  Note: Interface Classes of the result of the CaliperCornerResults.  */
        class CaliperCornerResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CaliperCornerResults() {}
            virtual ~CaliperCornerResults() {}

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
             * 检测区域1
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI1() = 0;
             /**
             * @par 说明
             * 检测区域2
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI2() = 0;
            /**
             * @par 说明
             * 检测状态,1:有效、其他：无效
             * @par 权限
             * 只读
             */
            virtual int GetStatus() = 0;
            /**
             * @par 说明
             * 交叉点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetIntersectionPoint() = 0;
            /**
             * @par 说明
             * 交叉角度
             * @par 权限
             * 只读
             */
            virtual float GetIntersectionAngle() = 0;
            /**
             * @par 说明
             * 直线0信息
             * @par 权限
             * 只读
             */
            virtual ICornerFindLineInfo* GetLine0Info() = 0;
            /**
             * @par 说明
             * 直线1信息
             * @par 权限
             * 只读
             */
            virtual ICornerFindLineInfo* GetLine1Info() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CaliperCorner tool.  */
        class IMVSCaliperCornerModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCaliperCornerModuTool() {}
            virtual ~IMVSCaliperCornerModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CaliperCornerParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CaliperCornerResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCaliperCornerModuTool(IMVSCaliperCornerModuTool&);
            IMVSCaliperCornerModuTool& operator=(IMVSCaliperCornerModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CaliperCorner.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCaliperCornerModu::IMVSCaliperCornerModuTool * __stdcall GetCaliperCornerToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CALIPERCORNER_H_
