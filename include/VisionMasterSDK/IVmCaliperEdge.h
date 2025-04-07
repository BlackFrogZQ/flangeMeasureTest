/***************************************************************************************************
 * File：IVmCaliperEdge.h
 * Note：CH: 边缘查找模块接口声明 | En: Interface for the CaliperEdge tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CALIPEREDGE_H_
#define _IVM_CALIPEREDGE_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCaliperEdgeModu
    {
        /*************************** Params Class Start ***************************/
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

        // CH: 边缘选择方式 | EN: Edge Choose Mode
        typedef enum _FindModeEnum
        {
            // CH: 按强度 | EN: By Strength
            FindMode_Best = 0x1,

            // CH: 从前往后 | EN: Front to Back
            FindMode_First = 0x2,

            // CH: 从后往前 | EN: Back to Front
            FindMode_Last = 0x3,

            // CH: 所有 | EN: All
            FindMode_All = 0x4,

        }FindModeEnum;

        // CH: 排序方式 | EN: Sort Type
        typedef enum _SortTypeEnum
        {
            // CH: 分数降序 | EN: Score Descend
            SortType_ScoreDescend = 0x0,

            // CH: 分数升序 | EN: Score Ascend
            SortType_ScoreAscend = 0x1,

            // CH: 方向正向 | EN: Orient Forward
            SortType_OrientForward = 0x2,

            // CH: 方向逆向 | EN: Orient Backward
            SortType_OrientBackward = 0x3,

        }SortTypeEnum;

        // CH: 查找方向 | EN: Search Direction
        typedef enum _FindOrientEnum
        {
            // CH: 从上到下 | EN: Top to Bottom
            FindOrient_UpToDown = 0x1,

            // CH: 从左到右 | EN: Left to Right
            FindOrient_LeftToRight = 0x2,

        }FindOrientEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class CaliperEdgeRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the CaliperEdgeParams.  */
        class CaliperEdgeParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CaliperEdgeParams() {}
            virtual ~CaliperEdgeParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual CaliperEdgeRoiManager* GetModuRoiManager() = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetHalfKernelSize, get = GetHalfKernelSize)) int HalfKernelSize;

            virtual int GetHalfKernelSize() = 0;

            virtual void SetHalfKernelSize(int value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetContrastTH, get = GetContrastTH)) int ContrastTH;

            virtual int GetContrastTH() = 0;

            virtual void SetContrastTH(int value) = 0;

            // CH: 边缘极性 | EN: EdgePolarity
            __declspec(property(put = SetEdgePolarity, get = GetEdgePolarity)) EdgePolarityEnum EdgePolarity;

            virtual EdgePolarityEnum GetEdgePolarity() = 0;

            virtual void SetEdgePolarity(EdgePolarityEnum value) = 0;

            // CH: 边缘选择方式 | EN: Edge Choose Mode
            __declspec(property(put = SetFindMode, get = GetFindMode)) FindModeEnum FindMode;

            virtual FindModeEnum GetFindMode() = 0;

            virtual void SetFindMode(FindModeEnum value) = 0;

            // CH: 最大结果数 | EN: Max Result Number
            __declspec(property(put = SetMaximum, get = GetMaximum)) int Maximum;

            virtual int GetMaximum() = 0;

            virtual void SetMaximum(int value) = 0;

            // CH: 排序方式 | EN: Sort Type
            __declspec(property(put = SetSortType, get = GetSortType)) SortTypeEnum SortType;

            virtual SortTypeEnum GetSortType() = 0;

            virtual void SetSortType(SortTypeEnum value) = 0;

            // CH: 查找方向 | EN: Search Direction
            __declspec(property(put = SetFindOrient, get = GetFindOrient)) FindOrientEnum FindOrient;

            virtual FindOrientEnum GetFindOrient() = 0;

            virtual void SetFindOrient(FindOrientEnum value) = 0;

            // CH: 最小边缘分数 | EN: Min Edge Score
            __declspec(property(put = SetMinScore, get = GetMinScore)) double MinScore;

            virtual double GetMinScore() = 0;

            virtual void SetMinScore(double value) = 0;

            // CH: 数量判断 | EN: Quantity Check
            __declspec(property(put = SetNumLimitEnable, get = GetNumLimitEnable)) bool NumLimitEnable;

            virtual bool GetNumLimitEnable() = 0;

            virtual void SetNumLimitEnable(bool value) = 0;

            // CH: 数量判断 | EN: Quantity Check
            __declspec(property(put = SetNumLimitLow, get = GetNumLimitLow)) int NumLimitLow;

            virtual int GetNumLimitLow() = 0;

            virtual void SetNumLimitLow(int value) = 0;

            // CH: 数量判断 | EN: Quantity Check
            __declspec(property(put = SetNumLimitHigh, get = GetNumLimitHigh)) int NumLimitHigh;

            virtual int GetNumLimitHigh() = 0;

            virtual void SetNumLimitHigh(int value) = 0;

            // CH: 边缘点X判断 | EN: Edge Point X Check
            __declspec(property(put = SetEdgePointXLimitEnable, get = GetEdgePointXLimitEnable)) bool EdgePointXLimitEnable;

            virtual bool GetEdgePointXLimitEnable() = 0;

            virtual void SetEdgePointXLimitEnable(bool value) = 0;

            // CH: 边缘点X判断 | EN: Edge Point X Check
            __declspec(property(put = SetEdgePointXLimitLow, get = GetEdgePointXLimitLow)) double EdgePointXLimitLow;

            virtual double GetEdgePointXLimitLow() = 0;

            virtual void SetEdgePointXLimitLow(double value) = 0;

            // CH: 边缘点X判断 | EN: Edge Point X Check
            __declspec(property(put = SetEdgePointXLimitHigh, get = GetEdgePointXLimitHigh)) double EdgePointXLimitHigh;

            virtual double GetEdgePointXLimitHigh() = 0;

            virtual void SetEdgePointXLimitHigh(double value) = 0;

            // CH: 边缘点Y判断 | EN: Edge Point Y Check
            __declspec(property(put = SetEdgePointYLimitEnable, get = GetEdgePointYLimitEnable)) bool EdgePointYLimitEnable;

            virtual bool GetEdgePointYLimitEnable() = 0;

            virtual void SetEdgePointYLimitEnable(bool value) = 0;

            // CH: 边缘点Y判断 | EN: Edge Point Y Check
            __declspec(property(put = SetEdgePointYLimitLow, get = GetEdgePointYLimitLow)) double EdgePointYLimitLow;

            virtual double GetEdgePointYLimitLow() = 0;

            virtual void SetEdgePointYLimitLow(double value) = 0;

            // CH: 边缘点Y判断 | EN: Edge Point Y Check
            __declspec(property(put = SetEdgePointYLimitHigh, get = GetEdgePointYLimitHigh)) double EdgePointYLimitHigh;

            virtual double GetEdgePointYLimitHigh() = 0;

            virtual void SetEdgePointYLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /** @enum  MVD_EDGEPOINT_STATUS
         *  @brief Type of the polarity of the edge point
         */
        typedef _MVD_EDGE_POLARITY__ MVD_EDGE_POLARITY;

        /*  Note: Interface Classes for describing single edge Information.  */
        class IEdgeFindSingleEdgeInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IEdgeFindSingleEdgeInfo() {}
            virtual ~IEdgeFindSingleEdgeInfo() {}

        public:
            /**
             * @par 说明
             * 边缘点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetEdgePoint() = 0;
            /**
             * @par 说明
             * 边缘点偏移量
             * @par 权限
             * 只读
             */
            virtual float GetBias() = 0;
            /**
             * @par 说明
             * 边缘点得分
             * @par 权限
             * 只读
             */
            virtual float GetScore() = 0;
            /**
             * @par 说明
             * 边缘极性
             * @par 权限
             * 只读
             */
            virtual MVD_EDGE_POLARITY GetPolarity() = 0;
            /**
             * @par 说明
             * 直线
             * @par 权限
             * 只读
             */
            virtual Line GetLineInfo() = 0;
        };

        /*  Note: Interface Classes of the result of the CaliperEdgeResults.  */
        class CaliperEdgeResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CaliperEdgeResults() {}
            virtual ~CaliperEdgeResults() {}

        public:
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
             * 边缘信息
             * @par 权限
             * 只读
             */
            virtual int GetEdgeNum() = 0;
            /**
             * @par 说明
             * 边缘点数
             * @par 权限
             * 只读
             */
            virtual IEdgeFindSingleEdgeInfo* GetSingleEdgeInfo( int nIndex ) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CaliperEdge tool.  */
        class IMVSCaliperEdgeModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCaliperEdgeModuTool() {}
            virtual ~IMVSCaliperEdgeModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CaliperEdgeParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CaliperEdgeResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCaliperEdgeModuTool(IMVSCaliperEdgeModuTool&);
            IMVSCaliperEdgeModuTool& operator=(IMVSCaliperEdgeModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CaliperEdge.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCaliperEdgeModu::IMVSCaliperEdgeModuTool * __stdcall GetCaliperEdgeToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CALIPEREDGE_H_
