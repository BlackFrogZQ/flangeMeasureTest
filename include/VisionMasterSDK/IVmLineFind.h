/***************************************************************************************************
 * File：IVmLineFind.h
 * Note：CH: 直线查找模块接口声明 | En: Interface for the LineFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_LINEFIND_H_
#define _IVM_LINEFIND_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSLineFindModu
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

            // CH: 接近中线 | EN: Close To Mid
            FindMode_Mid = 0x4,

        }FindModeEnum;

        // CH: 边缘极性 | EN: EdgePolarity
        typedef enum _EdgePolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgePolarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgePolarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            EdgePolarity_Both = 0x3,

        }EdgePolarityEnum;

        // CH: 初始拟合 | EN: Initial Fit
        typedef enum _InitTypeEnum
        {
            // CH: 全局 | EN: Global
            InitType_ALS = 0x1,

            // CH: 局部 | EN: Partial
            InitType_LLS = 0x2,

        }InitTypeEnum;

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
        class LineFindRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the LineFindParams.  */
        class LineFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineFindParams() {}
            virtual ~LineFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual LineFindRoiManager* GetModuRoiManager() = 0;

            // CH: 边缘类型 | EN: Edge Type
            __declspec(property(put = SetFindMode, get = GetFindMode)) FindModeEnum FindMode;

            virtual FindModeEnum GetFindMode() = 0;

            virtual void SetFindMode(FindModeEnum value) = 0;

            // CH: 边缘极性 | EN: EdgePolarity
            __declspec(property(put = SetEdgePolarity, get = GetEdgePolarity)) EdgePolarityEnum EdgePolarity;

            virtual EdgePolarityEnum GetEdgePolarity() = 0;

            virtual void SetEdgePolarity(EdgePolarityEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeStrength, get = GetEdgeStrength)) int EdgeStrength;

            virtual int GetEdgeStrength() = 0;

            virtual void SetEdgeStrength(int value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetKernelSize, get = GetKernelSize)) int KernelSize;

            virtual int GetKernelSize() = 0;

            virtual void SetKernelSize(int value) = 0;

            // CH: 卡尺数量 | EN: Caliper Number
            __declspec(property(put = SetRayNum, get = GetRayNum)) int RayNum;

            virtual int GetRayNum() = 0;

            virtual void SetRayNum(int value) = 0;

            // CH: 直线查找反向 | EN: RevertFindOrient
            __declspec(property(put = SetRevertFindOrient, get = GetRevertFindOrient)) bool RevertFindOrient;

            virtual bool GetRevertFindOrient() = 0;

            virtual void SetRevertFindOrient(bool value) = 0;

            // CH: 角度归一化 | EN: AngleNormalization
            __declspec(property(put = SetAngleNormalization, get = GetAngleNormalization)) bool AngleNormalization;

            virtual bool GetAngleNormalization() = 0;

            virtual void SetAngleNormalization(bool value) = 0;

            // CH: 剔除点数 | EN: Reject Number
            __declspec(property(put = SetRejectNum, get = GetRejectNum)) int RejectNum;

            virtual int GetRejectNum() = 0;

            virtual void SetRejectNum(int value) = 0;

            // CH: 剔除距离 | EN: Distance to remove
            __declspec(property(put = SetRejectDist, get = GetRejectDist)) int RejectDist;

            virtual int GetRejectDist() = 0;

            virtual void SetRejectDist(int value) = 0;

            // CH: 投影宽度 | EN: Projection Width
            __declspec(property(put = SetRegionWidth, get = GetRegionWidth)) int RegionWidth;

            virtual int GetRegionWidth() = 0;

            virtual void SetRegionWidth(int value) = 0;

            // CH: 初始拟合 | EN: Initial Fit
            __declspec(property(put = SetInitType, get = GetInitType)) InitTypeEnum InitType;

            virtual InitTypeEnum GetInitType() = 0;

            virtual void SetInitType(InitTypeEnum value) = 0;

            // CH: 拟合方式 | EN: Fit Mode
            __declspec(property(put = SetFitFun, get = GetFitFun)) FitFunEnum FitFun;

            virtual FitFunEnum GetFitFun() = 0;

            virtual void SetFitFun(FitFunEnum value) = 0;

            // CH: 匹配点数判断 | EN: Fit Points Check
            __declspec(property(put = SetFitPointsLimitEnable, get = GetFitPointsLimitEnable)) bool FitPointsLimitEnable;

            virtual bool GetFitPointsLimitEnable() = 0;

            virtual void SetFitPointsLimitEnable(bool value) = 0;

            // CH: 拟合点数范围 | EN: Fit Points Range
            __declspec(property(put = SetFitPointsLimitLow, get = GetFitPointsLimitLow)) int FitPointsLimitLow;

            virtual int GetFitPointsLimitLow() = 0;

            virtual void SetFitPointsLimitLow(int value) = 0;

            // CH: 拟合点数范围 | EN: Fit Points Range
            __declspec(property(put = SetFitPointsLimitHigh, get = GetFitPointsLimitHigh)) int FitPointsLimitHigh;

            virtual int GetFitPointsLimitHigh() = 0;

            virtual void SetFitPointsLimitHigh(int value) = 0;

            // CH: 角度判断 | EN: Angle Check
            __declspec(property(put = SetAngleLimitEnable, get = GetAngleLimitEnable)) bool AngleLimitEnable;

            virtual bool GetAngleLimitEnable() = 0;

            virtual void SetAngleLimitEnable(bool value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngleLimitLow, get = GetAngleLimitLow)) double AngleLimitLow;

            virtual double GetAngleLimitLow() = 0;

            virtual void SetAngleLimitLow(double value) = 0;

            // CH: 角度范围 | EN: Angle Range
            __declspec(property(put = SetAngleLimitHigh, get = GetAngleLimitHigh)) double AngleLimitHigh;

            virtual double GetAngleLimitHigh() = 0;

            virtual void SetAngleLimitHigh(double value) = 0;

            // CH: 拟合误差判断 | EN: Fit Error Check
            __declspec(property(put = SetScoreLimitEnable, get = GetScoreLimitEnable)) bool ScoreLimitEnable;

            virtual bool GetScoreLimitEnable() = 0;

            virtual void SetScoreLimitEnable(bool value) = 0;

            // CH: 拟合误差范围 | EN: Fit Error Range
            __declspec(property(put = SetScoreLimitLow, get = GetScoreLimitLow)) double ScoreLimitLow;

            virtual double GetScoreLimitLow() = 0;

            virtual void SetScoreLimitLow(double value) = 0;

            // CH: 拟合误差范围 | EN: Fit Error Range
            __declspec(property(put = SetScoreLimitHigh, get = GetScoreLimitHigh)) double ScoreLimitHigh;

            virtual double GetScoreLimitHigh() = 0;

            virtual void SetScoreLimitHigh(double value) = 0;

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
        class ILineFindEdgePointInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit ILineFindEdgePointInfo() {}
            virtual ~ILineFindEdgePointInfo() {}

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

        /*  Note: Interface Classes of the result of the LineFindResults.  */
        class LineFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineFindResults() {}
            virtual ~LineFindResults() {}

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
             * 卡尺检测区
             * @par 权限
             * 只读
             */
             virtual RectBox GetDetectCaliperBox(int nIndex) = 0;
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
             * 直线起点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetLineStartPoint() = 0;
            /**
             * @par 说明
             * 直线终点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetLineEndPoint() = 0;
            /**
            * @par 说明
            * 直线中点
            * @par 权限
            * 只读
            */
            virtual MVD_POINT_F GetMidpoint() = 0;
            /**
             * @par 说明
             * 直线角度
             * @par 权限
             * 只读
             */
            virtual float GetLineAngle() = 0;
            /**
             * @par 说明
             * 拟合误差
             * @par 权限
             * 只读
             */
            virtual float GetLineStraightness() = 0;
            /**
             * @par 说明
             * 0:查找失败；1:查找成功
             * @par 权限
             * 只读
             * @return 查找状态
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
             * @brief 获取结果边缘点序
             * @param nPtIndex [out] 边缘点序
             * @return 返回结果边缘点序
             * @par 注解
             * nPtIndex从0开始计数。
             */
            virtual ILineFindEdgePointInfo* GetEdgePointInfo(int nPtIndex) = 0;
            /**
             * @par 说明
             * 卡尺数
             * @par 权限
             * 只读
             */
            virtual int GetCaliperNum() = 0;
            /**
             * @brief 获取结果中的单个卡尺位置
             * @param nCaliperIndex [in] 卡尺索引
             * @return 返回卡尺信息
             * @par 注解
             * nPtIndex从0开始计数。
             */
            virtual RectBox GetCaliperBox(int nCaliperIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the LineFind tool.  */
        class IMVSLineFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSLineFindModuTool() {}
            virtual ~IMVSLineFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual LineFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual LineFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSLineFindModuTool(IMVSLineFindModuTool&);
            IMVSLineFindModuTool& operator=(IMVSLineFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for LineFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSLineFindModu::IMVSLineFindModuTool * __stdcall GetLineFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_LINEFIND_H_
