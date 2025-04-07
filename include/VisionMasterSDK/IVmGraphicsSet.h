/***************************************************************************************************
 * File：IVmGraphicsSet.h
 * Note：CH: 图形收集模块接口声明 | En: Interface for the GraphicsSet tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_GRAPHICSSET_H_
#define _IVM_GRAPHICSSET_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"
#include "IVmDynamicIoDefine.h"

namespace VisionMasterSDK
{
    namespace GraphicsSetModule
    {
        ///< 文本信息
        typedef struct TextInfo_
        {
            PointF stPosition;                         // CH: 文本位置 | EN: Text Position
            char strValue[MAX_MODULE_RESVALUE_LENGTH]; // CH: 字符串数据 | EN: String
            char strReserved[32];                      // CH: 保留字段 | EN: Reserved
        } TextInfo;

        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the GraphicsSetParams.  */
        class GraphicsSetParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GraphicsSetParams() {}
            virtual ~GraphicsSetParams() {}

        public:

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the GraphicsSetResults.  */
        class GraphicsSetResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GraphicsSetResults() {}
            virtual ~GraphicsSetResults() {}

        public:
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;

            /**
            * @brief 获取点输出
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual IoPointArray GetOutputPointArray(IN const char * const strParamName) = 0;
            /**
            * @brief 获取直线输出
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual IoLineArray GetOutputLineArray(IN const char * const strParamName) = 0;
            /**
            * @brief 获取矩形输出
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual IoRectBoxArray GetOutputBoxArray(IN const char * const strParamName) = 0;
            /**
            * @brief 获取圆输出
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual IoAnnulusArray GetOutputAnnulusArray(IN const char * const strParamName) = 0;
            /**
            * @brief 获取文本输出
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual StringDataArray GetOutputString(IN const char * const strParamName) = 0;

            /**
            * @brief 获取输出状态
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual IntDataArray GetOutputInt(IN const char * const strParamName) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the GraphicsSet tool.  */
        class GraphicsSetModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GraphicsSetModuleTool() {}
            virtual ~GraphicsSetModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual GraphicsSetParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual GraphicsSetResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            GraphicsSetModuleTool(GraphicsSetModuleTool&);
            GraphicsSetModuleTool& operator=(GraphicsSetModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for GraphicsSet.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::GraphicsSetModule::GraphicsSetModuleTool * __stdcall GetGraphicsSetToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_GRAPHICSSET_H_
