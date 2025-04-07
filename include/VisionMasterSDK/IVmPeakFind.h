/***************************************************************************************************
 * File：IVmPeakFind.h
 * Note：CH: 顶点检测模块接口声明 | En: Interface for the PeakFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_PEAKFIND_H_
#define _IVM_PEAKFIND_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSPeakFindModu
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

        /*  Note: Interface Classes of the RoiManager.  */
        class PeakFindRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the PeakFindParams.  */
        class PeakFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit PeakFindParams() {}
            virtual ~PeakFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual PeakFindRoiManager* GetModuRoiManager() = 0;

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

            // CH: 扫描宽度 | EN: Scan Width
            __declspec(property(put = SetScanWidth, get = GetScanWidth)) int ScanWidth;

            virtual int GetScanWidth() = 0;

            virtual void SetScanWidth(int value) = 0;

            // CH: 数量判断 | EN: Quantity Check
            __declspec(property(put = SetNumLimitEnable, get = GetNumLimitEnable)) bool NumLimitEnable;

            virtual bool GetNumLimitEnable() = 0;

            virtual void SetNumLimitEnable(bool value) = 0;

            // CH: 数量范围 | EN: Quantity Range
            __declspec(property(put = SetNumLimitLow, get = GetNumLimitLow)) int NumLimitLow;

            virtual int GetNumLimitLow() = 0;

            virtual void SetNumLimitLow(int value) = 0;

            // CH: 数量范围 | EN: Quantity Range
            __declspec(property(put = SetNumLimitHigh, get = GetNumLimitHigh)) int NumLimitHigh;

            virtual int GetNumLimitHigh() = 0;

            virtual void SetNumLimitHigh(int value) = 0;

            // CH: 边缘点X判断 | EN: Edge Point X Check
            __declspec(property(put = SetEdgePointXLimitEnable, get = GetEdgePointXLimitEnable)) bool EdgePointXLimitEnable;

            virtual bool GetEdgePointXLimitEnable() = 0;

            virtual void SetEdgePointXLimitEnable(bool value) = 0;

            // CH: 边缘点X范围 | EN: Edge Point X Range
            __declspec(property(put = SetEdgePointXLimitLow, get = GetEdgePointXLimitLow)) double EdgePointXLimitLow;

            virtual double GetEdgePointXLimitLow() = 0;

            virtual void SetEdgePointXLimitLow(double value) = 0;

            // CH: 边缘点X范围 | EN: Edge Point X Range
            __declspec(property(put = SetEdgePointXLimitHigh, get = GetEdgePointXLimitHigh)) double EdgePointXLimitHigh;

            virtual double GetEdgePointXLimitHigh() = 0;

            virtual void SetEdgePointXLimitHigh(double value) = 0;

            // CH: 边缘点Y判断 | EN: Edge Point Y Check
            __declspec(property(put = SetEdgePointYLimitEnable, get = GetEdgePointYLimitEnable)) bool EdgePointYLimitEnable;

            virtual bool GetEdgePointYLimitEnable() = 0;

            virtual void SetEdgePointYLimitEnable(bool value) = 0;

            // CH: 边缘点Y范围 | EN: Edge Point Y Range
            __declspec(property(put = SetEdgePointYLimitLow, get = GetEdgePointYLimitLow)) double EdgePointYLimitLow;

            virtual double GetEdgePointYLimitLow() = 0;

            virtual void SetEdgePointYLimitLow(double value) = 0;

            // CH: 边缘点Y范围 | EN: Edge Point Y Range
            __declspec(property(put = SetEdgePointYLimitHigh, get = GetEdgePointYLimitHigh)) double EdgePointYLimitHigh;

            virtual double GetEdgePointYLimitHigh() = 0;

            virtual void SetEdgePointYLimitHigh(double value) = 0;

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
        class IPeakFindEdgePointInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IPeakFindEdgePointInfo() {}
            virtual ~IPeakFindEdgePointInfo() {}

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
             * 边缘点得分
             * @par 权限
             * 只读
             */
            virtual float GetScore() = 0;
            /**
             * @par 说明
             * 边缘点距离
             * @par 权限
             * 只读
             */
            virtual float GetDistance() = 0;
            /**
             * @par 说明
             * 边缘点极性
             * @par 权限
             * 只读
             */
            virtual MVD_EDGE_POLARITY GetPolarity() = 0;
            /**
             * @par 说明
             * 边缘点状态
             * @par 权限
             * 只读
             */
            virtual MVD_EDGEPOINT_STATUS GetStatus() = 0;
        };

        /*  Note: Interface Classes of the result of the PeakFindResults.  */
        class PeakFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit PeakFindResults() {}
            virtual ~PeakFindResults() {}

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
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;
            /**
             * @par 说明
             * 顶点信息
             * @par 权限
             * 只读
             */
            virtual IPeakFindEdgePointInfo* GetPeakPointInfo() = 0;
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
            virtual IPeakFindEdgePointInfo* GetEdgePointInfo(int nPtIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the PeakFind tool.  */
        class IMVSPeakFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSPeakFindModuTool() {}
            virtual ~IMVSPeakFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual PeakFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual PeakFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSPeakFindModuTool(IMVSPeakFindModuTool&);
            IMVSPeakFindModuTool& operator=(IMVSPeakFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for PeakFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSPeakFindModu::IMVSPeakFindModuTool * __stdcall GetPeakFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_PEAKFIND_H_
