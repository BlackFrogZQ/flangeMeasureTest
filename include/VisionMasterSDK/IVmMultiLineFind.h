/***************************************************************************************************
 * File：IVmMultiLineFind.h
 * Note：CH: 多直线查找模块接口声明 | En: Interface for the MultiLineFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MULTILINEFIND_H_
#define _IVM_MULTILINEFIND_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMultiLineFindModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 直线边缘极性 | EN: Line Edge Polarity
        typedef enum _EdgePolarityEnum
        {
            // CH: 由黑到白 | EN: Dark To Bright
            EdgePolarity_DarkToBright = 1,

            // CH: 由白到黑 | EN: Bright To Dark
            EdgePolarity_BrightToDark = 2,

            // CH: 任意(同一条线段中点集有两种极性点) | EN: Any (There are 2 polarity points in midpoint sets of the same line segment.)
            EdgePolarity_Mixed = 3,

            // CH: 黑到白或白到黑(同一条线段中点集有一种极性点) | EN: From black to white or from white to black (There are 1 polarity point in midpoint sets of the same line segment.)
            EdgePolarity_Either = 4,

        }EdgePolarityEnum;

        // CH: 拟合方式 | EN: Fit Mode
        typedef enum _LineFitFunEnum
        {
            // CH: 最小二乘 | EN: Least Squares
            LineFitFun_LS = 0x1,

            // CH: huber | EN: huber
            LineFitFun_Huber = 0x2,

            // CH: tukey | EN: tukey
            LineFitFun_Tukey = 0x3,

        }LineFitFunEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class MultiLineFindRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the MultiLineFindParams.  */
        class MultiLineFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MultiLineFindParams() {}
            virtual ~MultiLineFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual MultiLineFindRoiManager* GetModuRoiManager() = 0;

            // CH: 滤波核半宽 | EN: Filter Kernel Half-Width
            __declspec(property(put = SetGradientFieldSize, get = GetGradientFieldSize)) int GradientFieldSize;

            virtual int GetGradientFieldSize() = 0;

            virtual void SetGradientFieldSize(int value) = 0;

            // CH: 投影长度 | EN: Projection Length
            __declspec(property(put = SetProjectionLength, get = GetProjectionLength)) int ProjectionLength;

            virtual int GetProjectionLength() = 0;

            virtual void SetProjectionLength(int value) = 0;

            // CH: 绝对边缘阈值 | EN: Absolute Edge Threshold
            __declspec(property(put = SetEdgeThreshold, get = GetEdgeThreshold)) int EdgeThreshold;

            virtual int GetEdgeThreshold() = 0;

            virtual void SetEdgeThreshold(int value) = 0;

            // CH: 相对边缘阈值 | EN: Relative Edge Threshold
            __declspec(property(put = SetNormalContrast, get = GetNormalContrast)) int NormalContrast;

            virtual int GetNormalContrast() = 0;

            virtual void SetNormalContrast(int value) = 0;

            // CH: 直线边缘极性 | EN: Line Edge Polarity
            __declspec(property(put = SetEdgePolarity, get = GetEdgePolarity)) EdgePolarityEnum EdgePolarity;

            virtual EdgePolarityEnum GetEdgePolarity() = 0;

            virtual void SetEdgePolarity(EdgePolarityEnum value) = 0;

            // CH: 边缘角度容忍 | EN: Edge Angle Tolerance
            __declspec(property(put = SetEdgeAngleTolerance, get = GetEdgeAngleTolerance)) int EdgeAngleTolerance;

            virtual int GetEdgeAngleTolerance() = 0;

            virtual void SetEdgeAngleTolerance(int value) = 0;

            // CH: 边缘距离容忍 | EN: Edge Dist Tolerance
            __declspec(property(put = SetEdgeDistTolerance, get = GetEdgeDistTolerance)) int EdgeDistTolerance;

            virtual int GetEdgeDistTolerance() = 0;

            virtual void SetEdgeDistTolerance(int value) = 0;

            // CH: 多线最大条数 | EN: Line Max Num
            __declspec(property(put = SetLineMaxNum, get = GetLineMaxNum)) int LineMaxNum;

            virtual int GetLineMaxNum() = 0;

            virtual void SetLineMaxNum(int value) = 0;

            // CH: 覆盖率阈值 | EN: Line Coverage
            __declspec(property(put = SetLineCoverage, get = GetLineCoverage)) int LineCoverage;

            virtual int GetLineCoverage() = 0;

            virtual void SetLineCoverage(int value) = 0;

            // CH: 旋转角度容忍 | EN: Line Rotation Tolerance
            __declspec(property(put = SetLineRotationTolerance, get = GetLineRotationTolerance)) int LineRotationTolerance;

            virtual int GetLineRotationTolerance() = 0;

            virtual void SetLineRotationTolerance(int value) = 0;

            // CH: 拟合方式 | EN: Fit Mode
            __declspec(property(put = SetLineFitFun, get = GetLineFitFun)) LineFitFunEnum LineFitFun;

            virtual LineFitFunEnum GetLineFitFun() = 0;

            virtual void SetLineFitFun(LineFitFunEnum value) = 0;

            // CH: 边缘点数判断 | EN: Edge Points Num Check
            __declspec(property(put = SetEdgePointsNumLimitEnable, get = GetEdgePointsNumLimitEnable)) bool EdgePointsNumLimitEnable;

            virtual bool GetEdgePointsNumLimitEnable() = 0;

            virtual void SetEdgePointsNumLimitEnable(bool value) = 0;

            // CH: 边缘点数范围 | EN: Edge Points Num Range
            __declspec(property(put = SetEdgePointsNumLimitLow, get = GetEdgePointsNumLimitLow)) int EdgePointsNumLimitLow;

            virtual int GetEdgePointsNumLimitLow() = 0;

            virtual void SetEdgePointsNumLimitLow(int value) = 0;

            // CH: 边缘点数范围 | EN: Edge Points Num Range
            __declspec(property(put = SetEdgePointsNumLimitHigh, get = GetEdgePointsNumLimitHigh)) int EdgePointsNumLimitHigh;

            virtual int GetEdgePointsNumLimitHigh() = 0;

            virtual void SetEdgePointsNumLimitHigh(int value) = 0;

            // CH: 直线数量判断 | EN: Line Num Check
            __declspec(property(put = SetLineNumLimitEnable, get = GetLineNumLimitEnable)) bool LineNumLimitEnable;

            virtual bool GetLineNumLimitEnable() = 0;

            virtual void SetLineNumLimitEnable(bool value) = 0;

            // CH: 直线数量范围 | EN: Line Num Range
            __declspec(property(put = SetLineNumLimitLow, get = GetLineNumLimitLow)) int LineNumLimitLow;

            virtual int GetLineNumLimitLow() = 0;

            virtual void SetLineNumLimitLow(int value) = 0;

            // CH: 直线数量范围 | EN: Line Num Range
            __declspec(property(put = SetLineNumLimitHigh, get = GetLineNumLimitHigh)) int LineNumLimitHigh;

            virtual int GetLineNumLimitHigh() = 0;

            virtual void SetLineNumLimitHigh(int value) = 0;

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
        class IMultiLineFindEdgePointInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IMultiLineFindEdgePointInfo() {}
            virtual ~IMultiLineFindEdgePointInfo() {}

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
            * 边缘点极性
            * @par 权限
            * 只读
            */
            virtual MVD_EDGE_POLARITY GetPolarity() = 0;
            /**
            * @par 说明
            * 梯度幅值
            * @par 权限
            * 只读
            */
            virtual float GetMagnitude() = 0;
            /**
            * @par 说明
            * 梯度方向
            * @par 权限
            * 只读
            */
            virtual float GetOrientation() = 0;
            /**
            * @par 说明
            * 边缘点距离
            * @par 权限
            * 只读
            */
            virtual float GetDistance() = 0;
            /**
            * @par 说明
            * 边缘点状态(枚举值1-边缘点已使用，对应界面状态1；枚举值3-边缘点未使用，对应界面状态0)
            * @par 权限
            * 只读
            */
            virtual MVD_EDGEPOINT_STATUS GetStatus() = 0;
            /**
             * @par 说明
             * 投影区域索引
             * @par 权限
             * 只读
             */
            virtual int GetCaliperIndex() = 0;
            /**
            * @par 说明
            * 所属线段索引
            * @par 权限
            * 只读
            */
            virtual int GetLineIndex() = 0;
        };

        /*  Note: Interface Classes for describing a line Information.  */
        class IMultiLineFindLineInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IMultiLineFindLineInfo() {}
            virtual ~IMultiLineFindLineInfo() {}

        public:
            /**
            * @par 说明
            * 当前直线段
            * @par 权限
            * 只读
            */
            virtual Line GetLine() = 0;
            /**
            * @par 说明
            * 当前直线段拟合误差
            * @par 权限
            * 只读
            */
            virtual float GetFitError() = 0;
            /**
            * @par 说明
            * 当前直线段对比度强度
            * @par 权限
            * 只读
            */
            virtual float GetIntensity() = 0;
            /**
            * @par 说明
            * 覆盖率分数
            * @par 权限
            * 只读
            */
            virtual float GetCoverageScore() = 0;
            /**
            * @par 说明
            * 在群点数量
            * @par 权限
            * 只读
            */
            virtual int GetInliersNum() = 0;
            /**
            * @par 说明
            * 线段索引
            * @par 权限
            * 只读
            */
            virtual int GetLineIndex() = 0;
        };

        /*  Note: Interface Classes of the result of the MultiLineFindResults.  */
        class MultiLineFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MultiLineFindResults() {}
            virtual ~MultiLineFindResults() {}

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
             * 检测状态
             * @par 权限
             * 只读
             */
            virtual int GetStatus() = 0;
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
            virtual IMultiLineFindEdgePointInfo* GetEdgePointInfo(int nPtIndex) = 0;
            /**
             * @par 说明
             * 直线段总数
             * @par 权限
             * 只读
             */
            virtual int GetLineNum() = 0;
            /**
             * @brief 获取结果中的直线段信息
             * @param nLineIndex [in] 直线段索引
             * @return 返回结果边缘点序
             * @par 注解
             * nPtIndex从0开始计数。
             */
            /* Gets information of the line with an index value of 'nLineIndex'.
            The range of index value can be queried from GetLineNum function. */
            virtual IMultiLineFindLineInfo* GetLineInfo(int nLineIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the MultiLineFind tool.  */
        class IMVSMultiLineFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMultiLineFindModuTool() {}
            virtual ~IMVSMultiLineFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MultiLineFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MultiLineFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSMultiLineFindModuTool(IMVSMultiLineFindModuTool&);
            IMVSMultiLineFindModuTool& operator=(IMVSMultiLineFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MultiLineFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMultiLineFindModu::IMVSMultiLineFindModuTool * __stdcall GetMultiLineFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MULTILINEFIND_H_
