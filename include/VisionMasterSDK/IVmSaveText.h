/***************************************************************************************************
 * File：IVmSaveText.h
 * Note：CH: 文本保存模块接口声明 | En: Interface for the SaveText tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_SAVETEXT_H_
#define _IVM_SAVETEXT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace SaveTextModule
    {
        /*************************** Params Class Start ***************************/
        // CH: 数据源 | EN: Data Source
        typedef enum _OutputTypeEnum
        {
            // CH: TXT | EN: TXT
            OutputType_TXT = 0x0,

            // CH: CSV | EN: CSV
            OutputType_CSV = 0x1,

        }OutputTypeEnum;

        // CH: 保存条件 | EN: Save Condition
        typedef enum _SaveConditionEnum
        {
            // CH: 全部保存 | EN: Save All
            SaveCondition_ALL = 0x0,

            // CH: OK时保存 | EN: Save OK
            SaveCondition_OK = 0x1,

            // CH: NG时保存 | EN: Save NG
            SaveCondition_NG = 0x2,

            // CH: 不保存 | EN: Not Save
            SaveCondition_NONE = 0x3,

        }SaveConditionEnum;

        // CH: 存储方式 | EN: Save Mode
        typedef enum _SaveTypeEnum
        {
            // CH: 覆盖存储 | EN: Overwrite
            SaveType_OverWrite = 0x0,

            // CH: 停止存储 | EN: Stop Saving
            SaveType_NoSave = 0x1,

        }SaveTypeEnum;

        // CH: 文件命名 | EN: File Naming
        typedef enum _NameTypeEnum
        {
            // CH: 序号 | EN: Number
            NameType_Index = 0x0,

            // CH: 时间 | EN: Time
            NameType_Time = 0x1,

            // CH: 无 | EN: None
            NameType_None = 0x2,

        }NameTypeEnum;

        /*  Note: Interface Classes of the parameter of the SaveTextParams.  */
        class SaveTextParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SaveTextParams() {}
            virtual ~SaveTextParams() {}

        public:

            // CH: 数据源 | EN: Data Source
            __declspec(property(put = SetOutputType, get = GetOutputType)) OutputTypeEnum OutputType;

            virtual OutputTypeEnum GetOutputType() = 0;

            virtual void SetOutputType(OutputTypeEnum value) = 0;

            // CH: 保存列名 | EN: Save column name
            __declspec(property(put = SetSaveColumnNames, get = GetSaveColumnNames)) bool SaveColumnNames;

            virtual bool GetSaveColumnNames() = 0;

            virtual void SetSaveColumnNames(bool value) = 0;

            // CH: 触发保存 | EN: Save Trigger
            __declspec(property(put = SetSaveTrigger, get = GetSaveTrigger)) bool SaveTrigger;

            virtual bool GetSaveTrigger() = 0;

            virtual void SetSaveTrigger(bool value) = 0;

            // CH: 保存条件 | EN: Save Condition
            __declspec(property(put = SetSaveCondition, get = GetSaveCondition)) SaveConditionEnum SaveCondition;

            virtual SaveConditionEnum GetSaveCondition() = 0;

            virtual void SetSaveCondition(SaveConditionEnum value) = 0;

            // CH: 保存路径 | EN: SavePath
            __declspec(property(put = SetPath, get = GetPath)) const char* Path;

            virtual const char* GetPath() = 0;

            virtual void SetPath(const char* value) = 0;

            // CH: 文件保存数量 | EN: File Save Number
            __declspec(property(put = SetFileCount, get = GetFileCount)) int FileCount;

            virtual int GetFileCount() = 0;

            virtual void SetFileCount(int value) = 0;

            // CH: 文件容量(K) | EN: Document Size(K)
            __declspec(property(put = SetFileLen, get = GetFileLen)) int FileLen;

            virtual int GetFileLen() = 0;

            virtual void SetFileLen(int value) = 0;

            // CH: 存储方式 | EN: Save Mode
            __declspec(property(put = SetSaveType, get = GetSaveType)) SaveTypeEnum SaveType;

            virtual SaveTypeEnum GetSaveType() = 0;

            virtual void SetSaveType(SaveTypeEnum value) = 0;

            // CH: 时间戳设置 | EN: Timestamp Setting
            __declspec(property(put = SetTimeStamp, get = GetTimeStamp)) const char* TimeStamp;

            virtual const char* GetTimeStamp() = 0;

            virtual void SetTimeStamp(const char* value) = 0;

            // CH: 生成日期目录 | EN: Generate Directory By Date
            __declspec(property(put = SetSaveByDateTrigger, get = GetSaveByDateTrigger)) bool SaveByDateTrigger;

            virtual bool GetSaveByDateTrigger() = 0;

            virtual void SetSaveByDateTrigger(bool value) = 0;

            // CH: 文件保存天数 | EN: File Retention Days
            __declspec(property(put = SetMaxDayCount, get = GetMaxDayCount)) int MaxDayCount;

            virtual int GetMaxDayCount() = 0;

            virtual void SetMaxDayCount(int value) = 0;

            // CH: 文件命名 | EN: File Naming
            __declspec(property(put = SetNameType, get = GetNameType)) NameTypeEnum NameType;

            virtual NameTypeEnum GetNameType() = 0;

            virtual void SetNameType(NameTypeEnum value) = 0;

            // CH: 实时存储 | EN: Real Time Save
            __declspec(property(put = SetRealTimeSave, get = GetRealTimeSave)) bool RealTimeSave;

            virtual bool GetRealTimeSave() = 0;

            virtual void SetRealTimeSave(bool value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the SaveTextResults.  */
        class SaveTextResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SaveTextResults() {}
            virtual ~SaveTextResults() {}

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
             * 获取保存路径
             * @par 权限
             * 只读
             */
            virtual const char * GetSavePath() = 0;

            /**
             * @par 说明
             * 获取文件名称
             * @par 权限
             * 只读
             */
            virtual const char * GetFileName() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the SaveText tool.  */
        class SaveTextModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SaveTextModuleTool() {}
            virtual ~SaveTextModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual SaveTextParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual SaveTextResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            SaveTextModuleTool(SaveTextModuleTool&);
            SaveTextModuleTool& operator=(SaveTextModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for SaveText.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::SaveTextModule::SaveTextModuleTool * __stdcall GetSaveTextToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_SAVETEXT_H_
