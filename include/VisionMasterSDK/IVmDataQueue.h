/***************************************************************************************************
 * File：IVmDataQueue.h
 * Note：CH: 数据队列模块接口声明 | En: Interface for the DataQueue tool.
 *
* Version：4.3
* Date: 2021-01-13 14:43:42
***************************************************************************************************/
#ifndef _IVM_DATAQUEUE_H_
#define _IVM_DATAQUEUE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"

namespace VisionMasterSDK
{
    namespace DataQueueModule
    {
        // 整型数据信息结构
        typedef struct _IntValue {
            int   nIndex;
            int   nNum;
            int   nValue[256];
        } IntValue;

        // 浮点型数据信息结构
        typedef struct _FloatValue {
            int   nIndex;
            int   nNum;
            float fValue[256];
        } FloatValue;

        // 字符串型数据信息结构
        typedef struct _StringInfo {
            char  strValue[4096];
        } StringInfo;

        typedef struct _StringValue {
            int   nIndex;
            int   nNum;
            StringInfo astValue[256];
        } StringValue;

        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the DataQueueParams.  */
        class DataQueueParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DataQueueParams() {}
            virtual ~DataQueueParams() {}

        public:

            // CH : 异步触发 | EN : Asynchronous Trigger
            __declspec(property(put = SetAsynchronousTrigger, get = GetAsynchronousTrigger)) bool AsynchronousTrigger;

            virtual bool GetAsynchronousTrigger() = 0;

            virtual void SetAsynchronousTrigger(bool value) = 0;

            // CH: 清空 | EN: Clear
            virtual int DoClearData() = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the DataQueue tool.  */
        class DataQueueModuleTool
        {
        protected:
            ///< Constructor and Destructor
            explicit DataQueueModuleTool() {}
            virtual ~DataQueueModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual DataQueueParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 设置整型数据
             * @par 注解
             * 设置整型数据
             */
            virtual void SetIntData(IN const IntValue * const pstIntVal) = 0;

            /**
             * @par 说明
             * 设置浮点型数据
             * @par 注解
             * 设置浮点型数据
             */
            virtual void SetFloatData(IN const FloatValue * const pstFloatVal) = 0;

            /**
             * @par 说明
             * 设置字符串型数据
             * @par 注解
             * 设置字符串型数据
             */
            virtual void SetStringData(IN const StringValue * const pstStringVal) = 0;

            /**
             * @par 说明
             * 获取整型数据
             * @par 注解
             * 获取指定索引的整型数据
             */
            virtual IntValue GetIntData(IN const int nIndex) = 0;

            /**
             * @par 说明
             * 获取浮点型数据
             * @par 注解
             * 获取指定索引的浮点型数据
             */
            virtual FloatValue GetFloatData(IN const int nIndex) = 0;

            /**
             * @par 说明
             * 获取字符串型数据
             * @par 注解
             * 获取指定索引的字符串型数据
             */
            virtual StringValue * GetStringData(IN const int nIndex) = 0;

        private:
            DataQueueModuleTool(DataQueueModuleTool&);
            DataQueueModuleTool& operator=(DataQueueModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for DataQueue.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::DataQueueModule::DataQueueModuleTool * __stdcall GetDataQueueToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_DATAQUEUE_H_
