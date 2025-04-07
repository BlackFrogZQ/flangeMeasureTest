/***************************************************************************************************
 * File：IVmCnnUnSupervised.h
 * Note：CH: DL无监督GPU模块接口声明 | En: Interface for the CnnUnSupervised tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CNNUNSUPERVISED_H_
#define _IVM_CNNUNSUPERVISED_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCnnUnSupervisedModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the CnnUnSupervisedParams.  */
        class CnnUnSupervisedParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnUnSupervisedParams() {}
            virtual ~CnnUnSupervisedParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 模型文件路径 | EN: Model File Path
            __declspec(property(put = SetLoadModelPath, get = GetLoadModelPath)) const char* LoadModelPath;

            virtual const char* GetLoadModelPath() = 0;

            virtual void SetLoadModelPath(const char* value) = 0;

            // CH: 方案存模型 | EN: Save Model Data
            __declspec(property(put = SetSaveModelDataEnable, get = GetSaveModelDataEnable)) bool SaveModelDataEnable;

            virtual bool GetSaveModelDataEnable() = 0;

            virtual void SetSaveModelDataEnable(bool value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the CnnUnSupervisedResults.  */
        class CnnUnSupervisedResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnUnSupervisedResults() {}
            virtual ~CnnUnSupervisedResults() {}

        public:
             /**
             * @par 说明
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;

             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;

             /**
             * @par 说明
             * 概率图
             * @par 权限
             * 只读
             */
             virtual ImageBaseData GetProbabilityImageData() = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CnnUnSupervised tool.  */
        class IMVSCnnUnSupervisedModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCnnUnSupervisedModuTool() {}
            virtual ~IMVSCnnUnSupervisedModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CnnUnSupervisedParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CnnUnSupervisedResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCnnUnSupervisedModuTool(IMVSCnnUnSupervisedModuTool&);
            IMVSCnnUnSupervisedModuTool& operator=(IMVSCnnUnSupervisedModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CnnUnSupervised.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCnnUnSupervisedModu::IMVSCnnUnSupervisedModuTool * __stdcall GetCnnUnSupervisedToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CNNUNSUPERVISED_H_
