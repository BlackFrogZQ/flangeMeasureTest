/***************************************************************************************************
 * File：IVmDataSet.h
 * Note：CH: 数据集合模块接口声明 | En: Interface for the DataSet tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_DATASET_H_
#define _IVM_DATASET_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace DataSetModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the DataSetParams.  */
        class DataSetParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DataSetParams() {}
            virtual ~DataSetParams() {}

        public:

            // CH: 清空信号(仅当次执行起效) | EN: Clear Signal(Only valid for this execution)
            virtual void SetClearSignal(int* pInputValue, unsigned int nValueNum) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the DataSetResults.  */
        class DataSetResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DataSetResults() {}
            virtual ~DataSetResults() {}

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
             * 结果数据
             * @par 权限
             * 只读
             */
            virtual OutputResultInfo * GetResult(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the DataSet tool.  */
        class DataSetModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DataSetModuleTool() {}
            virtual ~DataSetModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual DataSetParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual DataSetResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            DataSetModuleTool(DataSetModuleTool&);
            DataSetModuleTool& operator=(DataSetModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for DataSet.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::DataSetModule::DataSetModuleTool * __stdcall GetDataSetToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_DATASET_H_
