/***************************************************************************************************
 * File：IVmEdgeFlawInsp.h
 * Note：CH: 边缘模型缺陷检测模块接口声明 | En: Interface for the EdgeFlawInsp tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_EDGEFLAWINSP_H_
#define _IVM_EDGEFLAWINSP_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSEdgeFlawInspModu
    {
        /* @enum  MVD_SINGLE_EDGE_FLAW_TYPE
         *  @brief Type of the flaw of the edge inspection
         */
        typedef _MVD_EDGEINSP_SINGLE_EDGE_FLAW_TYPE__ MVD_SINGLE_EDGE_FLAW_TYPE;

        /*************************** Params Class Start ***************************/
        // CH: 边缘类型 | EN: Edge Type
        typedef enum _EdgePointFindModeEnum
        {
            // CH: 最强 | EN: Strongest Edge
            EdgePointFindMode_Best = 0x1,

            // CH: 第一条 | EN: First Edge
            EdgePointFindMode_First = 0x2,

            // CH: 最后一条 | EN: Last Edge
            EdgePointFindMode_Last = 0x3,

        }EdgePointFindModeEnum;

        // CH: 边缘极性 | EN: EdgePolarity
        typedef enum _EdgePointPolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgePointPolarity_B2W = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgePointPolarity_W2B = 0x2,

            // CH: 任意极性 | EN: Both
            EdgePointPolarity_All = 0x3,

        }EdgePointPolarityEnum;

        /*  Note: Interface Classes of the parameter of the EdgeFlawInspParams.  */
        class EdgeFlawInspParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgeFlawInspParams() {}
            virtual ~EdgeFlawInspParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 边缘类型 | EN: Edge Type
            __declspec(property(put = SetEdgePointFindMode, get = GetEdgePointFindMode)) EdgePointFindModeEnum EdgePointFindMode;

            virtual EdgePointFindModeEnum GetEdgePointFindMode() = 0;

            virtual void SetEdgePointFindMode(EdgePointFindModeEnum value) = 0;

            // CH: 边缘极性 | EN: EdgePolarity
            __declspec(property(put = SetEdgePointPolarity, get = GetEdgePointPolarity)) EdgePointPolarityEnum EdgePointPolarity;

            virtual EdgePointPolarityEnum GetEdgePointPolarity() = 0;

            virtual void SetEdgePointPolarity(EdgePointPolarityEnum value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetEdgeStrength, get = GetEdgeStrength)) int EdgeStrength;

            virtual int GetEdgeStrength() = 0;

            virtual void SetEdgeStrength(int value) = 0;

            // CH: 卡尺高度 | EN: CaliperHeight
            __declspec(property(put = SetCaliperHeight, get = GetCaliperHeight)) int CaliperHeight;

            virtual int GetCaliperHeight() = 0;

            virtual void SetCaliperHeight(int value) = 0;

            // CH: 卡尺宽度 | EN: CaliperWidth
            __declspec(property(put = SetCaliperWidth, get = GetCaliperWidth)) int CaliperWidth;

            virtual int GetCaliperWidth() = 0;

            virtual void SetCaliperWidth(int value) = 0;

            // CH: 缺陷长度阈值 | EN: Defect Length Threshold
            __declspec(property(put = SetLenThresh, get = GetLenThresh)) int LenThresh;

            virtual int GetLenThresh() = 0;

            virtual void SetLenThresh(int value) = 0;

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
        /*  Note: Interface classes for describing each edge flaw information.  */
        class IEdgeFlawInfo
        {
        protected:
            // Constructor and Destructor
            explicit IEdgeFlawInfo() {}
            virtual ~IEdgeFlawInfo() {}

        public:
            // Property
            /*  Note: Get the bounding rectangle of the flaw. */
            /**
             * @par 说明
             * 缺陷类型
             * @par 权限
             * 只读
             */
            virtual MVD_SINGLE_EDGE_FLAW_TYPE GetFlawType() = 0;
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

        /*  Note: Interface Classes of the result of the EdgeFlawInspResults.  */
        class EdgeFlawInspResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgeFlawInspResults() {}
            virtual ~EdgeFlawInspResults() {}

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
            virtual int GetEdgeFlawNum() = 0;
            /**
             * @brief 根据索引获取缺陷的信息
             * @param nIndex [in] 缺陷的索引,[0, FlawNum)
             * @return 单缺陷信息
             * @par 注解
             * 无
             */
            virtual IEdgeFlawInfo* GetEdgeFlawInfo(int nIndex) = 0;
            /**
             * @brief 获取边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePointNum() = 0;
            /**
            * @brief 根据索引查询边缘点
            * @param nIndex  [IN]  边缘点的索引，[0, EdgePointNum)
            * @param stPoint [OUT] 边缘点
            * @param nStatus [OUT] 边缘点状态,状态1为正常，0为缺陷
            * @par 权限
            * 只读
            */
            virtual void GetEdgePoint(int nIndex, MVD_POINT_F &stPoint, int &nStatus) = 0;
            /**
             * @brief 获取卡尺数量
             * @return 卡尺数量
             * @par 注解
             * 无
             */
            virtual int GetCaliperNum() = 0;
            /**
             * @brief 根据索引获取卡尺信息
             * @param nIndex [in] 卡尺索引,[0, Caliper)
             * @return 单卡尺信息
             * @par 注解
             * 
             */
            virtual RectBox GetCaliperBox(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the EdgeFlawInsp tool.  */
        class IMVSEdgeFlawInspModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSEdgeFlawInspModuTool() {}
            virtual ~IMVSEdgeFlawInspModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual EdgeFlawInspParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual EdgeFlawInspResults* GetResult() = 0;

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
            IMVSEdgeFlawInspModuTool(IMVSEdgeFlawInspModuTool&);
            IMVSEdgeFlawInspModuTool& operator=(IMVSEdgeFlawInspModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for EdgeFlawInsp.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSEdgeFlawInspModu::IMVSEdgeFlawInspModuTool * __stdcall GetEdgeFlawInspToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_EDGEFLAWINSP_H_
