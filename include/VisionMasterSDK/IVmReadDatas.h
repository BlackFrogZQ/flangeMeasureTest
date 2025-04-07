/***************************************************************************************************
 * File：IVmReadDatas.h
 * Note：CH: 接收数据模块接口声明 | En: Interface for the ReadDatas tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_READDATAS_H_
#define _IVM_READDATAS_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"
#include "IVmDynamicIoDefine.h"

namespace VisionMasterSDK
{
    namespace ReadDatasModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the ReadDatasParams.  */
        class ReadDatasParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ReadDatasParams() {}
            virtual ~ReadDatasParams() {}

        public:

            // CH: 获取行数 | EN: Row Number Acquisition
            __declspec(property(put = SetRowNum, get = GetRowNum)) int RowNum;

            virtual int GetRowNum() = 0;

            virtual void SetRowNum(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ReadDatasResults.  */
        class ReadDatasResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ReadDatasResults() {}
            virtual ~ReadDatasResults() {}

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
             * 结果数量
             * @par 权限
             * 只读
             */
            virtual int GetResultNum() = 0;

            /**
             * @par 说明
             * 结果数据，推荐使用动态接口（GetOutputInt、GetOutputFloat、GetOutputString、GetOutputByteArray、GetOutputImage）获取参数输出
             * @par 权限
             * 只读
             */
            virtual OutputResultInfo * GetResult(int nIndex) = 0;

			/**
			* @brief 根据模块输出参数名称，获取对应整型数据
			* @param 参数名称
			* @return IntDataArray型数据，出错时抛出异常
			* @par 注解
			*/
			virtual IntDataArray GetOutputInt(IN const char * const strParamName) = 0;

			/**
			* @brief 根据模块输出参数名称，获取对应浮点型数据
			* @param 参数名称
			* @return FloatDataArray型数据，出错时抛出异常
			* @par 注解
			*/
			virtual FloatDataArray GetOutputFloat(IN const char * const strParamName) = 0;

			/**
			* @brief 根据模块输出参数名称，获取对应字符串型数据
			* @param 参数名称
			* @return StringDataArray型数据，出错时抛出异常
			* @par 注解
			*/
			virtual StringDataArray GetOutputString(IN const char * const strParamName) = 0;

			/**
			* @brief 根据模块输出参数名称，获取对应二进制数据型数据
			* @param 参数名称
			* @return ByteArrayData型数据，出错时抛出异常
			* @par 注解
			*/
			virtual ByteArrayData GetOutputByteArray(IN const char * const strParamName) = 0;

			/**
			* @brief 根据模块输出参数名称，获取对应图像结果（单个图像）
			* @param 参数名称
			* @return IoImage型数据，出错时抛出异常
			* @par 注解
			*/
			virtual IoImage GetOutputImage(IN const char * const strParamName) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ReadDatas tool.  */
        class ReadDatasModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ReadDatasModuleTool() {}
            virtual ~ReadDatasModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ReadDatasParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ReadDatasResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            ReadDatasModuleTool(ReadDatasModuleTool&);
            ReadDatasModuleTool& operator=(ReadDatasModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ReadDatas.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::ReadDatasModule::ReadDatasModuleTool * __stdcall GetReadDatasToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_READDATAS_H_
