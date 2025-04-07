/***************************************************************************************************
 * File：IVmEdgeInspGroup.h
 * Note：CH: 边缘组合缺陷检测模块接口声明 | En: Interface for the EdgeInspGroup tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_EDGEINSPGROUP_H_
#define _IVM_EDGEINSPGROUP_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSEdgeInspGroupModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the EdgeInspGroupParams.  */
        class EdgeInspGroupParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgeInspGroupParams() {}
            virtual ~EdgeInspGroupParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /* @enum  MVD_EDGEINSP_FLAW_DEFECT_TYPE
         *  @brief 边缘缺陷类型
         */
        typedef _MVD_EDGEINSP_FLAW_DEFECT_TYPE__ MVD_EDGEINSP_FLAW_DEFECT_TYPE;
        
        /*  Note: 边缘组合缺陷检测缺陷信息类.  */
        class IEdgeFlawGroupInfo
        {
        protected:
            // 构造与析构函数
            explicit IEdgeFlawGroupInfo() {}
            virtual ~IEdgeFlawGroupInfo() {}

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

        /*  Note: Interface Classes of the result of the EdgeInspGroupResults.  */
        class EdgeInspGroupResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit EdgeInspGroupResults() {}
            virtual ~EdgeInspGroupResults() {}

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
            virtual int GetFlawNum() = 0;
            /**
             * @brief 根据索引获取缺陷的信息
             * @param nIndex [in] 缺陷的索引,[0, FlawNum)
             * @return 单缺陷信息
             * @par 注解
             * 无
             */
            virtual IEdgeFlawGroupInfo* GetFlawInfo(int nIndex) = 0;
            /**
             * @brief 获取边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePointNum() = 0;
            /**
             * @brief 根据索引查询边缘点
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点
             * @par 注解
             * 
             */
            virtual MVD_POINT_F GetEdgePoint(int nIndex) = 0;
            /**
             * @brief 根据索引查询边缘点状态，0表示为正常状态 1表示为缺陷状态
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点
             * @par 注解
             * 
             */
            virtual int GetEdgePointStatus(int nIndex) = 0;
            /**
             * @brief 获取卡尺数量
             * @return 卡尺数量
             * @par 注解
             * 无
             */
            virtual int GetCaliperNum() = 0;
            /**
             * @brief 根据索引获取卡尺信息（预留）
             * @param nIndex [in] 卡尺索引,[0, CaliperNum)
             * @return 单卡尺信息
             * @par 注解
             * 
             */
            virtual RectBox GetCaliperBox(int nIndex) = 0;
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
             * @brief 获取内部拟合直线个数
             * @return 直线个数
             * @par 注解
             * 无
             */
            virtual int GetLineNum() = 0;
            /**
             * @brief 根据索引获取内部拟合直线
             * @param nIndex [in] 直线索引,[0, LineNum)
             * @return 内部拟合输出直线
             * @par 注解
             * 
             */
            virtual Line GetInnerFitLine(int nIndex) = 0;
            /**
             * @brief 获取内部拟合圆个数
             * @return 拟合圆个数
             * @par 注解
             * 无
             */
            virtual int GetArcNum() = 0;
            /**
             * @par 说明
             * 获取拟合圆弧信息 圆弧等价于内外径相等的扇环  边检测为1条
             * @par 权限
             * 只读
             */
            /*  Note: Get the information of fitting arc.*/
            virtual Circle GetArc(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the EdgeInspGroup tool.  */
        class IMVSEdgeInspGroupModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSEdgeInspGroupModuTool() {}
            virtual ~IMVSEdgeInspGroupModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual EdgeInspGroupParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual EdgeInspGroupResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSEdgeInspGroupModuTool(IMVSEdgeInspGroupModuTool&);
            IMVSEdgeInspGroupModuTool& operator=(IMVSEdgeInspGroupModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for EdgeInspGroup.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSEdgeInspGroupModu::IMVSEdgeInspGroupModuTool * __stdcall GetEdgeInspGroupToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_EDGEINSPGROUP_H_
