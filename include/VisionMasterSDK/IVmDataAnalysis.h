/***************************************************************************************************
 * File：IVmDataAnalysis.h
 * Note：CH: 协议解析模块接口声明 | En: Interface for the DataAnalysis tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_DATAANALYSIS_H_
#define _IVM_DATAANALYSIS_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace DataAnalysisModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 方式选择 | EN: Handler Mode
        typedef enum _AnalysisTypeEnum
        {
            // CH: 文本解析 | EN: Text
            AnalysisType_TxtAnalytic = 0x0,

            // CH: 脚本解析 | EN: Script
            AnalysisType_ScriptAnalytic = 0x1,

            // CH: 字节解析 | EN: Byte
            AnalysisType_ByteAnalytic = 0x2,

        }AnalysisTypeEnum;

        /*  Note: Interface Classes of the parameter of the DataAnalysisParams.  */
        class DataAnalysisParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DataAnalysisParams() {}
            virtual ~DataAnalysisParams() {}

        public:

            // CH: 解析数据(仅当次执行起效) | EN: Analysis Data(Only valid for this execution)
            virtual void SetAnalysis(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // CH: 方式选择 | EN: Handler Mode
            __declspec(property(put = SetAnalysisType, get = GetAnalysisType)) AnalysisTypeEnum AnalysisType;

            virtual AnalysisTypeEnum GetAnalysisType() = 0;

            virtual void SetAnalysisType(AnalysisTypeEnum value) = 0;

            // CH: 分隔符 | EN: Split Symbol
            __declspec(property(put = SetSeparator, get = GetSeparator)) const char* Separator;

            virtual const char* GetSeparator() = 0;

            virtual void SetSeparator(const char* value) = 0;

            // CH: 路径选择 | EN: Select Path
            __declspec(property(put = SetPyScriptPath, get = GetPyScriptPath)) const char* PyScriptPath;

            virtual const char* GetPyScriptPath() = 0;

            virtual void SetPyScriptPath(const char* value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the DataAnalysisResults.  */
        class DataAnalysisResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DataAnalysisResults() {}
            virtual ~DataAnalysisResults() {}

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
        /*  Note: Note: This is the class for the DataAnalysis tool.  */
        class DataAnalysisModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit DataAnalysisModuleTool() {}
            virtual ~DataAnalysisModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual DataAnalysisParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual DataAnalysisResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            DataAnalysisModuleTool(DataAnalysisModuleTool&);
            DataAnalysisModuleTool& operator=(DataAnalysisModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for DataAnalysis.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::DataAnalysisModule::DataAnalysisModuleTool * __stdcall GetDataAnalysisToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_DATAANALYSIS_H_
