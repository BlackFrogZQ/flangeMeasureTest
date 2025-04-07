/***************************************************************************************************
 * File：IVmCnnClassify.h
 * Note：CH: 深度学习分类模块接口声明 | En: Interface for the CnnClassify tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CNNCLASSIFY_H_
#define _IVM_CNNCLASSIFY_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCnnClassifyModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class CnnClassifyRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the CnnClassifyParams.  */
        class CnnClassifyParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnClassifyParams() {}
            virtual ~CnnClassifyParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual CnnClassifyRoiManager* GetModuRoiManager() = 0;

            // CH: 模型文件路径 | EN: Model File Path
            __declspec(property(put = SetLoadModelPath, get = GetLoadModelPath)) const char* LoadModelPath;

            virtual const char* GetLoadModelPath() = 0;

            virtual void SetLoadModelPath(const char* value) = 0;

            // CH: 方案存模型 | EN: Save Model Data
            __declspec(property(put = SetSaveModelDataEnable, get = GetSaveModelDataEnable)) bool SaveModelDataEnable;

            virtual bool GetSaveModelDataEnable() = 0;

            virtual void SetSaveModelDataEnable(bool value) = 0;

            // CH: 获取模型ROI使能 | EN: GetRoiFromModel Enable
            __declspec(property(put = SetRoiFromModelEnable, get = GetRoiFromModelEnable)) bool RoiFromModelEnable;

            virtual bool GetRoiFromModelEnable() = 0;

            virtual void SetRoiFromModelEnable(bool value) = 0;

            // CH: 前K个类别 | EN: First K Categories
            __declspec(property(put = SetTopClassK, get = GetTopClassK)) int TopClassK;

            virtual int GetTopClassK() = 0;

            virtual void SetTopClassK(int value) = 0;

            // CH: 个数判断 | EN: Number Check
            __declspec(property(put = SetNumLimitEnable, get = GetNumLimitEnable)) bool NumLimitEnable;

            virtual bool GetNumLimitEnable() = 0;

            virtual void SetNumLimitEnable(bool value) = 0;

            // CH: 个数范围 | EN: Number Range
            __declspec(property(put = SetNumLimitLow, get = GetNumLimitLow)) int NumLimitLow;

            virtual int GetNumLimitLow() = 0;

            virtual void SetNumLimitLow(int value) = 0;

            // CH: 个数范围 | EN: Number Range
            __declspec(property(put = SetNumLimitHigh, get = GetNumLimitHigh)) int NumLimitHigh;

            virtual int GetNumLimitHigh() = 0;

            virtual void SetNumLimitHigh(int value) = 0;

            // CH: 概率判断 | EN: Probability Check
            __declspec(property(put = SetProbLimitEnable, get = GetProbLimitEnable)) bool ProbLimitEnable;

            virtual bool GetProbLimitEnable() = 0;

            virtual void SetProbLimitEnable(bool value) = 0;

            // CH: 概率范围 | EN: Probability Range
            __declspec(property(put = SetProbLimitLow, get = GetProbLimitLow)) double ProbLimitLow;

            virtual double GetProbLimitLow() = 0;

            virtual void SetProbLimitLow(double value) = 0;

            // CH: 概率范围 | EN: Probability Range
            __declspec(property(put = SetProbLimitHigh, get = GetProbLimitHigh)) double ProbLimitHigh;

            virtual double GetProbLimitHigh() = 0;

            virtual void SetProbLimitHigh(double value) = 0;

            // CH: 类别号判断 | EN: Category No. Check
            __declspec(property(put = SetLabelLimitEnable, get = GetLabelLimitEnable)) bool LabelLimitEnable;

            virtual bool GetLabelLimitEnable() = 0;

            virtual void SetLabelLimitEnable(bool value) = 0;

            // CH: 类别号范围 | EN: No. Range
            __declspec(property(put = SetLabelLimitLow, get = GetLabelLimitLow)) int LabelLimitLow;

            virtual int GetLabelLimitLow() = 0;

            virtual void SetLabelLimitLow(int value) = 0;

            // CH: 类别号范围 | EN: No. Range
            __declspec(property(put = SetLabelLimitHigh, get = GetLabelLimitHigh)) int LabelLimitHigh;

            virtual int GetLabelLimitHigh() = 0;

            virtual void SetLabelLimitHigh(int value) = 0;

            // CH: 类别名称判断 | EN: Category Name Check
            __declspec(property(put = SetCategoryNameLimitEnable, get = GetCategoryNameLimitEnable)) bool CategoryNameLimitEnable;

            virtual bool GetCategoryNameLimitEnable() = 0;

            virtual void SetCategoryNameLimitEnable(bool value) = 0;

            // CH: 类别名称 | EN: ClassName
            __declspec(property(put = SetCategoryNameLimit, get = GetCategoryNameLimit)) const char* CategoryNameLimit;

            virtual const char* GetCategoryNameLimit() = 0;

            virtual void SetCategoryNameLimit(const char* value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        class ICNNClassifyPredInfo
        {
        protected:
            ///< Constructor and Destructor
            //构造函数和析构函数
            explicit ICNNClassifyPredInfo() {}
            virtual ~ICNNClassifyPredInfo() {}

        public:
            /**
             * @par 说明
             * 标签值，例如0，1，2......
             * @par 权限
             * 只读
             */
            virtual int GetLabelValue() = 0;
            /**
             * @par 说明
             * 标签概率值
             * @par 权限
             * 只读
             */
            virtual float GetLabelProbability() = 0;
            /**
             * @par 说明
             * 标签名称，例如狗，猫，鸟......
             * @par 权限
             * 只读
             */
            virtual void GetLabelName(char pcLabelName[128]) = 0;
        };

        /*  Note: Interface Classes of the result of the CnnClassifyResults.  */
        class CnnClassifyResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnClassifyResults() {}
            virtual ~CnnClassifyResults() {}

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
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;
            /**
             * @par 说明
             * 给定索引的预测信息
             * @par 权限
             * 只读
             */
            virtual ICNNClassifyPredInfo* GetPredInfo(int nPredIndex) = 0;
            /**
             * @par 说明
             * 预测信息的数量
             * @par 权限
             * 只读
             */
            virtual int GetPredNum() = 0;
            /**
             * @par 说明
             * 预测信息的置信度
             * @par 权限
             * 只读
             */
            virtual float GetPredConfidence() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CnnClassify tool.  */
        class IMVSCnnClassifyModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCnnClassifyModuTool() {}
            virtual ~IMVSCnnClassifyModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CnnClassifyParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CnnClassifyResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCnnClassifyModuTool(IMVSCnnClassifyModuTool&);
            IMVSCnnClassifyModuTool& operator=(IMVSCnnClassifyModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CnnClassify.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCnnClassifyModu::IMVSCnnClassifyModuTool * __stdcall GetCnnClassifyToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CNNCLASSIFY_H_
