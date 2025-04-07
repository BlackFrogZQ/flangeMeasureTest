/***************************************************************************************************
 * File：IVmCircleFind.h
 * Note：CH: 圆查找模块接口声明 | En: Interface for the CircleFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CIRCLEFIND_H_
#define _IVM_CIRCLEFIND_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCircleFindModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 边缘类型 | EN: Edge Type
        typedef enum _FindModeEnum
        {
            // CH: 最强 | EN: Strongest Edge
            FindMode_Best = 0x1,

            // CH: 最后一条 | EN: Last Edge
            FindMode_Largest = 0x2,

            // CH: 第一条 | EN: First Edge
            FindMode_SMALLEST = 0x3,

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
        class CircleFindRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the CircleFindParams.  */
        class CircleFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CircleFindParams() {}
            virtual ~CircleFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual CircleFindRoiManager* GetModuRoiManager() = 0;

            // CH: 扇环半径 | EN: Sector Radius
            __declspec(property(put = SetMinRadius, get = GetMinRadius)) int MinRadius;

            virtual int GetMinRadius() = 0;

            virtual void SetMinRadius(int value) = 0;

            // CH: 扇环半径 | EN: Sector Radius
            __declspec(property(put = SetMaxRadius, get = GetMaxRadius)) int MaxRadius;

            virtual int GetMaxRadius() = 0;

            virtual void SetMaxRadius(int value) = 0;

            // CH: 边缘类型 | EN: Edge Type
            __declspec(property(put = SetFindMode, get = GetFindMode)) FindModeEnum FindMode;

            virtual FindModeEnum GetFindMode() = 0;

            virtual void SetFindMode(FindModeEnum value) = 0;

            // CH: 边缘极性 | EN: EdgePolarity
            __declspec(property(put = SetEdgePolarity, get = GetEdgePolarity)) EdgePolarityEnum EdgePolarity;

            virtual EdgePolarityEnum GetEdgePolarity() = 0;

            virtual void SetEdgePolarity(EdgePolarityEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeThresh, get = GetEdgeThresh)) int EdgeThresh;

            virtual int GetEdgeThresh() = 0;

            virtual void SetEdgeThresh(int value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetEdgeWidth, get = GetEdgeWidth)) int EdgeWidth;

            virtual int GetEdgeWidth() = 0;

            virtual void SetEdgeWidth(int value) = 0;

            // CH: 卡尺数量 | EN: Caliper Number
            __declspec(property(put = SetRadNum, get = GetRadNum)) int RadNum;

            virtual int GetRadNum() = 0;

            virtual void SetRadNum(int value) = 0;

            // CH: 剔除点数 | EN: Reject Number
            __declspec(property(put = SetRejectNum, get = GetRejectNum)) int RejectNum;

            virtual int GetRejectNum() = 0;

            virtual void SetRejectNum(int value) = 0;

            // CH: 初定位 | EN: Init Locating
            __declspec(property(put = SetCoarseDetectFlag, get = GetCoarseDetectFlag)) bool CoarseDetectFlag;

            virtual bool GetCoarseDetectFlag() = 0;

            virtual void SetCoarseDetectFlag(bool value) = 0;

            // CH: 下采样系数 | EN: Subsampling Coefficient
            __declspec(property(put = SetCCDSampleScale, get = GetCCDSampleScale)) int CCDSampleScale;

            virtual int GetCCDSampleScale() = 0;

            virtual void SetCCDSampleScale(int value) = 0;

            // CH: 圆定位敏感度 | EN: Locating Sensitivity
            __declspec(property(put = SetCCDCircleThresh, get = GetCCDCircleThresh)) int CCDCircleThresh;

            virtual int GetCCDCircleThresh() = 0;

            virtual void SetCCDCircleThresh(int value) = 0;

            // CH: 剔除距离 | EN: Distance to remove
            __declspec(property(put = SetRejectDist, get = GetRejectDist)) int RejectDist;

            virtual int GetRejectDist() = 0;

            virtual void SetRejectDist(int value) = 0;

            // CH: 投影宽度 | EN: Projection Width
            __declspec(property(put = SetProLength, get = GetProLength)) int ProLength;

            virtual int GetProLength() = 0;

            virtual void SetProLength(int value) = 0;

            // CH: 初始拟合 | EN: Initial Fit
            __declspec(property(put = SetInitType, get = GetInitType)) InitTypeEnum InitType;

            virtual InitTypeEnum GetInitType() = 0;

            virtual void SetInitType(InitTypeEnum value) = 0;

            // CH: 拟合方式 | EN: Fit Mode
            __declspec(property(put = SetFitFun, get = GetFitFun)) FitFunEnum FitFun;

            virtual FitFunEnum GetFitFun() = 0;

            virtual void SetFitFun(FitFunEnum value) = 0;

            // CH: 半径判断 | EN: Radius Check
            __declspec(property(put = SetRadiusLimitEnable, get = GetRadiusLimitEnable)) bool RadiusLimitEnable;

            virtual bool GetRadiusLimitEnable() = 0;

            virtual void SetRadiusLimitEnable(bool value) = 0;

            // CH: 半径判断 | EN: Radius Check
            __declspec(property(put = SetRadiusLimitLow, get = GetRadiusLimitLow)) double RadiusLimitLow;

            virtual double GetRadiusLimitLow() = 0;

            virtual void SetRadiusLimitLow(double value) = 0;

            // CH: 半径判断 | EN: Radius Check
            __declspec(property(put = SetRadiusLimitHigh, get = GetRadiusLimitHigh)) double RadiusLimitHigh;

            virtual double GetRadiusLimitHigh() = 0;

            virtual void SetRadiusLimitHigh(double value) = 0;

            // CH: 中心X判断 | EN: Center X Check
            __declspec(property(put = SetCenterXLimitEnable, get = GetCenterXLimitEnable)) bool CenterXLimitEnable;

            virtual bool GetCenterXLimitEnable() = 0;

            virtual void SetCenterXLimitEnable(bool value) = 0;

            // CH: 中心X判断 | EN: Center X Check
            __declspec(property(put = SetCenterXLimitLow, get = GetCenterXLimitLow)) double CenterXLimitLow;

            virtual double GetCenterXLimitLow() = 0;

            virtual void SetCenterXLimitLow(double value) = 0;

            // CH: 中心X判断 | EN: Center X Check
            __declspec(property(put = SetCenterXLimitHigh, get = GetCenterXLimitHigh)) double CenterXLimitHigh;

            virtual double GetCenterXLimitHigh() = 0;

            virtual void SetCenterXLimitHigh(double value) = 0;

            // CH: 中心Y判断 | EN: Center Y Check
            __declspec(property(put = SetCenterYLimitEnable, get = GetCenterYLimitEnable)) bool CenterYLimitEnable;

            virtual bool GetCenterYLimitEnable() = 0;

            virtual void SetCenterYLimitEnable(bool value) = 0;

            // CH: 中心Y范围 | EN: Center Y Range
            __declspec(property(put = SetCenterYLimitLow, get = GetCenterYLimitLow)) double CenterYLimitLow;

            virtual double GetCenterYLimitLow() = 0;

            virtual void SetCenterYLimitLow(double value) = 0;

            // CH: 中心Y范围 | EN: Center Y Range
            __declspec(property(put = SetCenterYLimitHigh, get = GetCenterYLimitHigh)) double CenterYLimitHigh;

            virtual double GetCenterYLimitHigh() = 0;

            virtual void SetCenterYLimitHigh(double value) = 0;

            // CH: 拟合误差判断 | EN: Fit Error Check
            __declspec(property(put = SetFitErrorLimitEnable, get = GetFitErrorLimitEnable)) bool FitErrorLimitEnable;

            virtual bool GetFitErrorLimitEnable() = 0;

            virtual void SetFitErrorLimitEnable(bool value) = 0;

            // CH: 拟合误差范围 | EN: Fit Error Range
            __declspec(property(put = SetFitErrorLimitLow, get = GetFitErrorLimitLow)) double FitErrorLimitLow;

            virtual double GetFitErrorLimitLow() = 0;

            virtual void SetFitErrorLimitLow(double value) = 0;

            // CH: 拟合误差范围 | EN: Fit Error Range
            __declspec(property(put = SetFitErrorLimitHigh, get = GetFitErrorLimitHigh)) double FitErrorLimitHigh;

            virtual double GetFitErrorLimitHigh() = 0;

            virtual void SetFitErrorLimitHigh(double value) = 0;

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

        /*  Note: Interface Classes for describing edge points Information.  */
        class ICircleFindEdgePointInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit ICircleFindEdgePointInfo() {}
            virtual ~ICircleFindEdgePointInfo() {}

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

        /*  Note: Interface Classes of the result of the IMVSCircleFindModuTool.  */
        class CircleFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CircleFindResults() {}
            virtual ~CircleFindResults() {}

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
             * ROI圆弧
             * @par 权限
             * 只读
             */
             virtual Annulus GetROIAnnulus() = 0;
            /**
             * @par 说明
             * 0:查找圆失败；1:查找圆成功并输出
             * @par 权限
             * 只读
             * @return 查找状态
             */
            virtual int GetStatus() = 0;
            /**
             * @par 说明
             * 拟合圆心
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetCircleCenter() = 0;
            /**
             * @par 说明
             * 拟合圆半径
             * @par 权限
             * 只读
             */
            virtual float GetCircleRadius() = 0;
            /**
             * @par 说明
             * 拟合误差
             * @par 权限
             * 只读
             */
            virtual float GetCircleness() = 0;
            /**
             * @par 说明
             * 边缘点点数
             * @par 权限
             * 只读
             */
            virtual int GetPointNum() = 0;
            /**
             * @brief 获取结果中的单个边缘点信息
             * @param nPtIndex [out] 边缘点信息
             * @return 返回结果边缘点序
             * @par 注解
             * nPtIndex从0开始计数。
             */
            /* Gets information of the point with an index value of 'nPtIndex'. The range of index value can be queried from GetPointNum function. */
            virtual ICircleFindEdgePointInfo* GetEdgePointInfo(int nPtIndex) = 0;
            /**
             * @brief 获取拟合圆弧
             * @param 无
             * @return 返回拟合圆弧的位置
             * @par 注解
             */
            virtual Annulus GetFitArc() = 0;
            /**
            * @brief 获取输出圆环
            * @param 无
            * @return 返回输出圆环
            * @par 注解
            */
            virtual Annulus GetOutputCircleAnnulus() = 0;
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
        /*  Note: Note: This is the class for the CircleFind tool.  */
        class IMVSCircleFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCircleFindModuTool() {}
            virtual ~IMVSCircleFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CircleFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CircleFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCircleFindModuTool(IMVSCircleFindModuTool&);
            IMVSCircleFindModuTool& operator=(IMVSCircleFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CircleFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCircleFindModu::IMVSCircleFindModuTool * __stdcall GetCircleFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CIRCLEFIND_H_
