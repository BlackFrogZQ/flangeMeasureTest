/***************************************************************************************************
 * File：IVmMachineLearningClassifier.h
 * Note：CH: ML分类模块接口声明 | En: Interface for the MachineLearningClassifier tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MACHINELEARNINGCLASSIFIER_H_
#define _IVM_MACHINELEARNINGCLASSIFIER_H_

#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMachineLearningClassifierModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class MachineLearningClassifierRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the MachineLearningClassifierParams.  */
        class MachineLearningClassifierParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MachineLearningClassifierParams() {}
            virtual ~MachineLearningClassifierParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual MachineLearningClassifierRoiManager* GetModuRoiManager() = 0;

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
        /*  Note: Interface Classes of the result of the MachineLearningClassifierResults.  */
        class MachineLearningClassifierResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MachineLearningClassifierResults() {}
            virtual ~MachineLearningClassifierResults() {}

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
			 * 预测信息个数
			 * @par 权限
			 * 只读
			 */
			 virtual int GetPredictNum() = 0;

			 /**
			 * @par 说明
			 * 标签索引
			 * @par 权限
			 * 只读
			 */
			 virtual int GetLabelsIndex(int nIndex) = 0;

			 /**
			 * @par 说明
			 * 标签名
			 * @par 权限
			 * 只读
			 */
			 virtual string GetLabelName(int nIndex) = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the MachineLearningClassifier tool.  */
        class IMVSMachineLearningClassifierModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMachineLearningClassifierModuTool() {}
            virtual ~IMVSMachineLearningClassifierModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MachineLearningClassifierParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MachineLearningClassifierResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSMachineLearningClassifierModuTool(IMVSMachineLearningClassifierModuTool&);
            IMVSMachineLearningClassifierModuTool& operator=(IMVSMachineLearningClassifierModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MachineLearningClassifier.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMachineLearningClassifierModu::IMVSMachineLearningClassifierModuTool * __stdcall GetMachineLearningClassifierToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MACHINELEARNINGCLASSIFIER_H_
