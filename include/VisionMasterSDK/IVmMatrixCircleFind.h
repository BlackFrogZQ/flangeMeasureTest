/***************************************************************************************************
 * File：IVmMatrixCircleFind.h
 * Note：CH: 阵列圆查找模块接口声明 | En: Interface for the MatrixCircleFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MATRIXCIRCLEFIND_H_
#define _IVM_MATRIXCIRCLEFIND_H_

#include "MVD_AlgoParamDefine.h"
using namespace VisionDesigner;

#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMatrixCircleFindModu
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

        /*  Note: Interface Classes of the parameter of the MatrixCircleFindParams.  */
        class MatrixCircleFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MatrixCircleFindParams() {}
            virtual ~MatrixCircleFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

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

            // CH: 卡尺宽度 | EN: Caliper Width
            __declspec(property(put = SetRadWidth, get = GetRadWidth)) double RadWidth;

            virtual double GetRadWidth() = 0;

            virtual void SetRadWidth(double value) = 0;

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

            // CH: 输出轮廓点 | EN: RunParam_OutputCoutourPoint
            __declspec(property(put = SetOutputCoutourPoint, get = GetOutputCoutourPoint)) bool OutputCoutourPoint;

            virtual bool GetOutputCoutourPoint() = 0;

            virtual void SetOutputCoutourPoint(bool value) = 0;

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

            // CH: 圆个数判断 | EN: Find Circle Num Check
            __declspec(property(put = SetOutputCircleNumEnable, get = GetOutputCircleNumEnable)) bool OutputCircleNumEnable;

            virtual bool GetOutputCircleNumEnable() = 0;

            virtual void SetOutputCircleNumEnable(bool value) = 0;

            // CH: 圆个数判断 | EN: Find Circle Num Check
            __declspec(property(put = SetOutputCircleNumLimitLow, get = GetOutputCircleNumLimitLow)) int OutputCircleNumLimitLow;

            virtual int GetOutputCircleNumLimitLow() = 0;

            virtual void SetOutputCircleNumLimitLow(int value) = 0;

            // CH: 圆个数判断 | EN: Find Circle Num Check
            __declspec(property(put = SetOutputCircleNumLimitHigh, get = GetOutputCircleNumLimitHigh)) int OutputCircleNumLimitHigh;

            virtual int GetOutputCircleNumLimitHigh() = 0;

            virtual void SetOutputCircleNumLimitHigh(int value) = 0;

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
        class IMatrixCircleFindEdgePointInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IMatrixCircleFindEdgePointInfo() {}
            virtual ~IMatrixCircleFindEdgePointInfo() {}

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

        /*  Note: Interface Classes for describing edge points Information.  */
        class IMatrixCircleFindResultInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IMatrixCircleFindResultInfo() {}
            virtual ~IMatrixCircleFindResultInfo() {}

        public:
            /**
            * @par 说明
            * 0:查找圆失败；1:查找圆成功并输出
            * @par 权限
            * 只读
            * @return 查找状态
            */
            virtual int GetOutputCircleAnnulusStatus() = 0;
            /**
            * @brief 获取输出圆环
            * @param 无
            * @return 返回输出圆环
            * @par 注解
            */
            virtual Annulus GetOutputCircleAnnulus() = 0;
            /**
            * @par 说明
            * 拟合圆率
            * @par 权限
            * 只读
            */
            virtual float GetCircleness() = 0;
            /**
            * @par 说明
            * 卡尺数
            * @par 权限
            * 只读
            */
            virtual int GetCaliperNum() = 0;
            /**
            * @brief 获取结果中的单个卡尺位置
            * @param nCaliperIndex [in] 卡尺索引，范围[0,CaliperNum)
            * @return 返回卡尺信息
            * @par 注解
            */
            virtual RectBox GetCaliperBox(int nCaliperIndex) = 0;
            /**
            * @brief 获取结果中的单个卡尺检测区位置
            * @param nCaliperIndex [in] 卡尺索引，范围[0,卡尺个数)
            * @return 返回卡尺检测区信息
            * @par 注解
            */
            virtual RectBox GetDetectCaliperBox(int nDetectCaliperIndex) = 0;
        };
        
        
        /*  Note: Interface Classes of the result of the MatrixCircleFindResults.  */
        class MatrixCircleFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MatrixCircleFindResults() {}
            virtual ~MatrixCircleFindResults() {}

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
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI(int nIndex) = 0;

             /**
             * @par 说明
             * ROI圆弧
             * @par 权限
             * 只读
             */
             virtual Annulus GetROIAnnulus(int nIndex) = 0;

             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;

             /**
             * @par 说明
             * 边缘点点数
             * @par 权限
             * 只读
             */
             virtual int GetPointNum(int nIndex) = 0;
             /**
             * @brief 获取结果中的单个边缘点信息
             * @param nIndex [in] 边缘点信息
             * @return 返回结果边缘点序
             * @par 注解
             * nPtIndex从0开始计数。
             */
             /* Gets information of the point with an index value of 'nPtIndex'. The range of index value can be queried from GetPointNum function. */
             virtual IMatrixCircleFindEdgePointInfo* GetEdgePointInfo(int nPtIndex) = 0;

             /**
             * @par 说明
             * 输出圆环个数
             * @par 权限
             * 只读
             */
             virtual int GetMatrixCircleFindNum() = 0;

             /**
             * @brief 获取结果中的单个输出圆环信息
             * @param nPtIndex [in] 边缘点信息
             * @return 返回单个输出圆环信息
             * @par 注解
             * nPtIndex从0开始计数。
             */
             virtual IMatrixCircleFindResultInfo* GetMatrixCircleFindInfo(int nPtIndex) = 0;
             
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the MatrixCircleFind tool.  */
        class IMVSMatrixCircleFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMatrixCircleFindModuTool() {}
            virtual ~IMVSMatrixCircleFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MatrixCircleFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MatrixCircleFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSMatrixCircleFindModuTool(IMVSMatrixCircleFindModuTool&);
            IMVSMatrixCircleFindModuTool& operator=(IMVSMatrixCircleFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MatrixCircleFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMatrixCircleFindModu::IMVSMatrixCircleFindModuTool * __stdcall GetMatrixCircleFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MATRIXCIRCLEFIND_H_
