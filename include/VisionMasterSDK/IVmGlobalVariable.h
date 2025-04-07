/***************************************************************************************************
* File：IVmGlobalVariable.h
* Note：CH: 全局变量模块接口声明 | En: Interface for the GlobalVariable tool.
*
* Version：4.3
* Date: 2021-01-13 14:43:42
***************************************************************************************************/
#ifndef _IVM_GLOBALVARIABLE_H_
#define _IVM_GLOBALVARIABLE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"

#define    MAX_VAR_NUM    2048        //全局变量最大数量
#define    COMM_NAME_MAX_LENGTH    256    

namespace VisionMasterSDK
{
    namespace GlobalVariableModule
    {
        // CH: 全局变量信息单个结构体 | EN: Global module single variable information structure
        typedef struct GlobalVarInfo_
        {
            bool bCommEnable;                               //CH: 通信初始化 标志位 | communicate initial
            char strValueType[8];                           //CH: 变量类型 string, int, float | variable type
            unsigned int  nDataLen;                         //CH: 变量长度 | variable length
            char *pDataValue;                               //CH: 变量值 |  variable value
            char strValueName[COMM_NAME_MAX_LENGTH];        //CH: 变量名称 |  variable name
            char strRemark[COMM_NAME_MAX_LENGTH];           //CH: 变量注释信息 |  variable remark info
            int nReserved[4];
        }GlobalVarInfo;

        // CH: 全局变量模块信息列表结构 | EN: Global module variable information list structure
        typedef struct GlobalVarInfoList_
        {
            int nCount;
            GlobalVarInfo stGlobalValue[MAX_VAR_NUM];
            int nReserved[4];
        }GlobalVarInfoList;

        /*  Note: Note: This is the class for the GlobalVariable tool.  */
        class GlobalVariableModuleTool
        {
        protected:
            ///< Constructor and Destructor
            explicit GlobalVariableModuleTool() {}
            virtual ~GlobalVariableModuleTool() {}

        public:
            /**
             * @par 说明
             * 设置全局变量
             * @par 注解
             * 设置对应全局变量值
             */
            virtual void SetGlobalVar(IN const char * const strParam, IN const char * const strVal) = 0;

            /**
             * @par 说明
             * 获取全局变量
             * @par 注解
             * 获取对应全局变量值
             */
            virtual void GetGlobalVar(IN const char * const strParam, OUT char strVal[8192]) = 0;

            /**
            * @par 说明
            * 获取全局变量列表信息
            * @par 注解
            * 获取对应全局变量值
            */
            virtual GlobalVarInfoList* GetAllGlobalVar(void) = 0;

        private:
            GlobalVariableModuleTool(GlobalVariableModuleTool&);
            GlobalVariableModuleTool& operator=(GlobalVariableModuleTool&);
        };
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

    /*  Note: Get tool instance for GlobalVariable.  */
    IMVS_6000_PLATFORMSDK_API VisionMasterSDK::GlobalVariableModule::GlobalVariableModuleTool * __stdcall GetGlobalVariableToolInstance(void);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_GLOBALVARIABLE_H_