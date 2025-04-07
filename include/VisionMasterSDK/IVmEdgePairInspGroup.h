/***************************************************************************************************
 * File：IVmEdgePairInspGroup.h
 * Note：CH: 边缘对组合缺陷检测模块接口声明 | En: Interface for the EdgePairInspGroup tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_EDGEPAIRINSPGROUP_H_
#define _IVM_EDGEPAIRINSPGROUP_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSEdgePairInspGroupModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the EdgePairInspGroupParams.  */
        class EdgePairInspGroupParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgePairInspGroupParams() {}
            virtual ~EdgePairInspGroupParams() {}

        public:
            // CH: 中心点使能 | EN: Midpoint Enable
            __declspec(property(put = SetMidPointEnable, get = GetMidPointEnable)) bool MidPointEnable;

            virtual bool GetMidPointEnable() = 0;

            virtual void SetMidPointEnable(bool value) = 0;

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /* @enum  MVD_EDGEINSP_FLAW_DEFECT_TYPE
         *  @brief 边缘对组合缺陷类型
         */
        typedef _MVD_EDGEINSP_FLAW_DEFECT_TYPE__ MVD_EDGEINSP_FLAW_DEFECT_TYPE;
        
        /*  Note: 边缘对组合缺陷检测缺陷信息类.  */
        class IEdgePairFlawGroupInfo
        {
        protected:
            // 构造与析构函数
            explicit IEdgePairFlawGroupInfo() {}
            virtual ~IEdgePairFlawGroupInfo() {}

        public:
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
             * 缺陷面积
             * @par 权限
             * 只读
             */
            virtual float GetFlawArea() = 0;
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
            /**
             * @par 说明
             * 缺陷类型
             * @par 权限
             * 只读
             */
            virtual MVD_EDGEINSP_FLAW_DEFECT_TYPE GetFlawType() = 0;
        };
        
        /*  Note: Interface Classes of the result of the EdgePairInspGroupResults.  */
        class EdgePairInspGroupResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgePairInspGroupResults() {}
            virtual ~EdgePairInspGroupResults() {}

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
             * 缺陷数量
             * @par 权限
             * 只读
             */
            virtual int GetFlawNum() = 0;
            /**
             * @brief 根据索引获取缺陷的信息
             * @param nIndex [in] 缺陷的索引,[0, FlawNum)
             * @return 单缺陷信息
             * @par 注解
             * 无
             */
            virtual IEdgePairFlawGroupInfo* GetFlawInfo(int nIndex) = 0;
            /**
             * @brief 获取边缘0点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdge0PointNum() = 0;
            /**
             * @brief 根据索引查询边缘点0
             * @param nIndex  [IN]  边缘点0的索引，[0, EdgePointNum)
             * @param stPoint0 [OUT] 边缘点0
             * @param nStatus [OUT] 边缘点0状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetEdge0Point(int nIndex, MVD_POINT_F &stPoint0, int &nStatus) = 0;
            /**
             * @brief 获取边缘1点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdge1PointNum() = 0;
            /**
             * @brief 根据索引查询边缘点1
             * @param nIndex  [IN]  边缘点1的索引，[0, EdgePointNum)
             * @param stPoint1 [OUT] 边缘点1
             * @param nStatus [OUT] 边缘点1状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetEdge1Point(int nIndex, MVD_POINT_F &stPoint1, int &nStatus) = 0;
			/**
             * @brief 获取中点的数量
             * @return 中点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgeMidPointNum() = 0;
            /**
             * @brief 根据索引查询边缘中点
             * @param nIndex     [IN]  边缘中点的索引，[0, EdgeMidPointNum)
             * @param stMidPoint [OUT] 边缘点中点
             * @param nStatus    [OUT] 边缘点中点状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetEdgeMiddlePoint(int nIndex, MVD_POINT_F &stMidPoint, int &nStatus) = 0;
            /**
             * @brief 获取卡尺数量
             * @return 卡尺数量
             * @par 注解
             * 无
             */
            virtual int GetCaliperNum() = 0;
            /**
             * @brief 获取卡尺点信息  个数为当前卡尺个数
             * @param nIndex   [IN]   卡尺点序号，[0, CaliperNum)
             * @param stPoint  [OUT]  卡尺点
             * @param nStatus  [OUT]  卡尺点状态,状态1为正常，0为缺陷
             * @par 权限
             * 只读
             */
            virtual void GetCaliperIdeaPoint(int nIndex, MVD_POINT_F &stPoint, int &nStatus) = 0;
            /**
             * @par 说明
             * 最小宽度
             * @par 权限
             * 只读
             */
            /*  Note: Get the min width the defect.*/
            virtual float GetMinWidth() = 0;
            /**
             * @par 说明
             * 最大宽度
             * @par 权限
             * 只读
             */
            /*  Note: Get the max width the defect.*/
            virtual float GetMaxWidth() = 0;
            /**
             * @par 说明
             * 平均宽度
             * @par 权限
             * 只读
             */
            /*  Note: Get the average width the defect.*/
            virtual float GetAverageWidth() = 0;
            /**
             * @par 说明
             * 近似面积
             * @par 权限
             * 只读
             */
            /*  Note: Get the approximate width the defect.*/
            virtual float GetApproximateArea() = 0;
            /**
             * @brief 获取内部拟合直线个数
             * @return 直线个数
             * @par 注解
             * 无
             */
            virtual int GetLineNum() = 0;
            /**
             * @brief 根据索引获取内部拟合直线
             * @param nIndex [in] 直线索引,[0, LineNum)
             * @return 内部拟合输出的直线
             * @par 注解
             * 
             */
            virtual Line GetInnerFitLine(int nIndex) = 0;
            /**
             * @par 说明
             * 获取拟合圆弧信息 圆弧等价于内外径相等的扇环 nArcIndex：圆弧序号
             * @par 权限
             * 只读
             */
            /*  Note: Get the information of fitting arc.*/
            virtual Circle GetArc(int nArcIndex) = 0;
            /**
             * @par 说明
             * 获取拟合圆弧数目
             * @par 权限
             * 只读
             */
            /*  Note: Get the number  of the fit arc.*/
            virtual int GetArcNum() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the EdgePairInspGroup tool.  */
        class IMVSEdgePairInspGroupModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSEdgePairInspGroupModuTool() {}
            virtual ~IMVSEdgePairInspGroupModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual EdgePairInspGroupParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual EdgePairInspGroupResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSEdgePairInspGroupModuTool(IMVSEdgePairInspGroupModuTool&);
            IMVSEdgePairInspGroupModuTool& operator=(IMVSEdgePairInspGroupModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for EdgePairInspGroup.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSEdgePairInspGroupModu::IMVSEdgePairInspGroupModuTool * __stdcall GetEdgePairInspGroupToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_EDGEPAIRINSPGROUP_H_
