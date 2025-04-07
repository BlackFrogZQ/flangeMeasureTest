/***************************************************************************************************
 * File：IVmShell.h
 * Note：CH: 脚本模块接口声明 | En: Interface for the Shell tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_SHELL_H_
#define _IVM_SHELL_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"
#include "IVmDynamicIoDefine.h"

namespace VisionMasterSDK
{
    namespace ShellModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the ShellParams.  */
        class ShellParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ShellParams() {}
            virtual ~ShellParams() {}

        public:
            /** 
            *  @brief  设置动态输入图像数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoImage结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputImageV2(const char * const strParamName, const IoImage * const pstImageData) = 0;
            /** 
            *  @brief  设置Int数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  int型指针数组
            *  @param  数组长度
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputInt(const char * const strParamName, const int * const anIntVal, const int nValNum) = 0;
            /**
            *  @brief  设置Float数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  Float型指针数组
            *  @param  数组长度
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputFloat(const char * const strParamName, const float * const anFloatVal, const int nValNum) = 0;
            /** 
            *  @brief  设置String数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  InputStringData结构体指针数组
            *  @param  数组长度
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputString(const char * const strParamName, const InputStringData * const astStrData, const int nValNum) = 0;
            /** 
            *  @brief  设置二进制数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  BytesData结构体指针
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputBytes(const char * const strParamName, const BytesData * const pBytes) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ShellResults.  */
        class ShellResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ShellResults() {}
            virtual ~ShellResults() {}

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
             * 获取结果显示
             * @par 权限
             * 只读
             */
            virtual const char * GetResultShow() = 0;

            /**
             * @par 说明(V4.2废弃)
             * 结果数量
             * @par 权限
             * 只读
             */
            virtual int GetResultNum() = 0;

            /**
             * @par 说明(V4.2废弃)
             * 结果数据
             * @par 权限
             * 只读
             */
            virtual ShellOutputResultInfo * GetResult(int nIndex) = 0;


            /**
            * @brief 获取整型输出
            * @param 参数名称
            * @return IntDataArray型数据，出错时抛出异常
            * @par 注解
            */
            virtual IntDataArray GetOutputInt(IN const char * const strParamName) = 0;

            /**
            * @brief 获取浮点型输出
            * @param 参数名称
            * @return FloatDataArray型数据，出错时抛出异常
            * @par 注解
            */
            virtual FloatDataArray GetOutputFloat(IN const char * const strParamName) = 0;

            /**
            * @brief 获取字符串型输出
            * @param 参数名称
            * @return StringDataArray型数据，出错时抛出异常
            * @par 注解
            */
            virtual StringDataArray GetOutputString(IN const char * const strParamName) = 0;

            /**
            * @brief 获取二进制数据型输出
            * @param 参数名称
            * @return ByteArrayData型数据，出错时抛出异常
            * @par 注解
            */
            virtual ByteArrayData GetOutputByteArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取图像结果（单个图像）
            * @param 参数名称
            * @return IoImage型数据，出错时抛出异常
            * @par 注解
            */
            virtual IoImage GetOutputImage(IN const char * const strParamName) = 0;


        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Shell tool.  */
        class ShellModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ShellModuleTool() {}
            virtual ~ShellModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ShellParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ShellResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            ShellModuleTool(ShellModuleTool&);
            ShellModuleTool& operator=(ShellModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Shell.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::ShellModule::ShellModuleTool * __stdcall GetShellToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_SHELL_H_
