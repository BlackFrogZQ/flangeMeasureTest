/***************************************************************************************************
 * File：IVmGluePathConduct.h
 * Note：CH: 路径提取模块接口声明 | En: Interface for the GluePathConduct tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_GLUEPATHCONDUCT_H_
#define _IVM_GLUEPATHCONDUCT_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSGluePathConductModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 提取方式 | EN: Extraction Method
        typedef enum _ModPointModeEnum
        {
            // CH: 等间隔取点 | EN: Take points at equal intervals
            ModPointMode_Best = 0x0,

            // CH: 查找边缘点 | EN: Find edge points
            ModPointMode_First = 0x1,

        }ModPointModeEnum;

        /*  Note: Interface Classes of the parameter of the GluePathConductParams.  */
        class GluePathConductParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GluePathConductParams() {}
            virtual ~GluePathConductParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 提取方式 | EN: Extraction Method
            __declspec(property(put = SetModPointMode, get = GetModPointMode)) ModPointModeEnum ModPointMode;

            virtual ModPointModeEnum GetModPointMode() = 0;

            virtual void SetModPointMode(ModPointModeEnum value) = 0;

            // CH: 输出圆弧信息 | EN: Output Arc Params
            __declspec(property(put = SetArcParamEnable, get = GetArcParamEnable)) bool ArcParamEnable;

            virtual bool GetArcParamEnable() = 0;

            virtual void SetArcParamEnable(bool value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /** @enum  MVD_EDGEPOINT_STATUS
        *  @brief Type of the polarity of the edge point
        */
        typedef _MVD_EDGE_POLARITY__ MVD_EDGE_POLARITY;

        /** @enum  MVD_EDGEPOINT_STATUS
        *  @brief Find status of the edge point
        */
        typedef _MVD_EDGEPOINT_STATUS__ MVD_EDGEPOINT_STATUS;
        
        class IBeadGuideEdgePointInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit IBeadGuideEdgePointInfo() {}
            virtual ~IBeadGuideEdgePointInfo() {}

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

        /*  Note: Interface Classes of the result of the GluePathConductResults.  */
        class GluePathConductResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GluePathConductResults() {}
            virtual ~GluePathConductResults() {}

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
             * @brief 获取边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePointNum() = 0;
            /**
             * @brief 根据索引获取边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePointInfo(int nIndex) = 0;
            /**
             * @brief 根据索引获取边缘点类型
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 边缘点类型
             * @par 注解
             * 无
             */
            virtual int GetGluePointTypes(int nIndex) = 0;
            /**
             * @brief 获取路径1边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePoint1Num() = 0;
            /**
             * @brief 根据索引获取路径1边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePoint1Info(int nIndex) = 0;
            /**
             * @brief 获取路径2边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePoint2Num() = 0;
            /**
             * @brief 根据索引获取路径2边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePoint2Info(int nIndex) = 0;
            /**
             * @brief 获取路径3边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePoint3Num() = 0;
            /**
             * @brief 根据索引获取路径3边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePoint3Info(int nIndex) = 0;
            /**
             * @brief 获取路径4边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePoint4Num() = 0;
            /**
             * @brief 根据索引路径4获取边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePoint4Info(int nIndex) = 0;
            /**
             * @brief 获取路径5边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePoint5Num() = 0;
            /**
             * @brief 根据索引获取路径5边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePoint5Info(int nIndex) = 0;
            /**
             * @brief 获取路径6边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePoint6Num() = 0;
            /**
             * @brief 根据索引获取路径6边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePoint6Info(int nIndex) = 0;
            /**
             * @brief 获取路径7边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePoint7Num() = 0;
            /**
             * @brief 根据索引获取路径7边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePoint7Info(int nIndex) = 0;
            /**
             * @brief 获取路径8边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePoint8Num() = 0;
            /**
             * @brief 根据索引获取路径8边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePoint8Info(int nIndex) = 0;
            /**
             * @brief 获取路径9边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePoint9Num() = 0;
            /**
             * @brief 根据索引获取路径9边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePoint9Info(int nIndex) = 0;
            /**
             * @brief 获取路径10边缘点的数量
             * @return 边缘点个数
             * @par 注解
             * 无
             */
            virtual int GetEdgePoint10Num() = 0;
            /**
             * @brief 根据索引获取路径10边缘点的信息
             * @param nIndex [in] 边缘点的索引,[0, EdgePointNum)
             * @return 单边缘点信息
             * @par 注解
             * 无
             */
            virtual IBeadGuideEdgePointInfo* GetEdgePoint10Info(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the GluePathConduct tool.  */
        class IMVSGluePathConductModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSGluePathConductModuTool() {}
            virtual ~IMVSGluePathConductModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual GluePathConductParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual GluePathConductResults* GetResult() = 0;

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
            IMVSGluePathConductModuTool(IMVSGluePathConductModuTool&);
            IMVSGluePathConductModuTool& operator=(IMVSGluePathConductModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for GluePathConduct.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSGluePathConductModu::IMVSGluePathConductModuTool * __stdcall GetGluePathConductToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_GLUEPATHCONDUCT_H_
