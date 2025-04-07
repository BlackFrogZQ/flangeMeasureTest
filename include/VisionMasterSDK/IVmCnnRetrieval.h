/***************************************************************************************************
 * File：IVmCnnRetrieval.h
 * Note：CH: DL图像检索模块接口声明 | En: Interface for the CnnRetrieval tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CNNRETRIEVAL_H_
#define _IVM_CNNRETRIEVAL_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

#ifndef MVD_CNN_RETRIEVAL_LABEL_NAME_LEN_MAX
#define MVD_CNN_RETRIEVAL_LABEL_NAME_LEN_MAX    (1024)
#endif

namespace VisionMasterSDK
{
    namespace IMVSCnnRetrievalModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the CnnRetrievalParams.  */
        class CnnRetrievalParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnRetrievalParams() {}
            virtual ~CnnRetrievalParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 模型文件路径 | EN: Model File Path
            __declspec(property(put = SetLoadModelPath, get = GetLoadModelPath)) const char* LoadModelPath;

            virtual const char* GetLoadModelPath() = 0;

            virtual void SetLoadModelPath(const char* value) = 0;

            // CH: Gallery路径 | EN: Gallery Path
            __declspec(property(put = SetLoadGalleryFilePath, get = GetLoadGalleryFilePath)) const char* LoadGalleryFilePath;

            virtual const char* GetLoadGalleryFilePath() = 0;

            virtual void SetLoadGalleryFilePath(const char* value) = 0;

            // CH: 方案存模型 | EN: Save Model Data
            __declspec(property(put = SetSaveModelDataEnable, get = GetSaveModelDataEnable)) bool SaveModelDataEnable;

            virtual bool GetSaveModelDataEnable() = 0;

            virtual void SetSaveModelDataEnable(bool value) = 0;

            // CH: 前K个类别 | EN: First K Categories
            __declspec(property(put = SetTopClsK, get = GetTopClsK)) int TopClsK;

            virtual int GetTopClsK() = 0;

            virtual void SetTopClsK(int value) = 0;

            // CH: 最小相似度 | EN: Min Similarity
            __declspec(property(put = SetMinSimilarity, get = GetMinSimilarity)) double MinSimilarity;

            virtual double GetMinSimilarity() = 0;

            virtual void SetMinSimilarity(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: 图像检索匹配信息类.*/
        class ICNNRetrievalMatchInfo
        {
        protected:
            explicit ICNNRetrievalMatchInfo(){};
            virtual ~ICNNRetrievalMatchInfo(){};

        public:
            /**
             * @par 说明
             * 获取检索出的样本相似度
             * @par 权限
             * 只读
             */
            virtual float GetSimilarity() = 0;
            /**
             * @par 说明
             * 获取检索出的样本索引号
             * @par 权限
             * 只读
             */
            virtual int GetSampleIndex() = 0;
            /**
             * @par 说明
             * 获取检索出的样本对应的标签名称
             * @par 权限
             * 只读
             */
            virtual void GetLabelName(char pcLabelName[MVD_CNN_RETRIEVAL_LABEL_NAME_LEN_MAX]) = 0;
        };

        /*  Note: Interface Classes of the result of the CnnRetrievalResults.  */
        class CnnRetrievalResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnRetrievalResults() {}
            virtual ~CnnRetrievalResults() {}

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
             * 检索信息的数量
             * @par 权限
             * 只读
             */
            virtual int GetTopNum() = 0;
            /**
             * @par 说明
             * 根据给定的索引获取检索信息
             * @par 权限
             * 只读
             */
            virtual ICNNRetrievalMatchInfo* GetMatchInfo(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CnnRetrieval tool.  */
        class IMVSCnnRetrievalModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCnnRetrievalModuTool() {}
            virtual ~IMVSCnnRetrievalModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CnnRetrievalParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CnnRetrievalResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCnnRetrievalModuTool(IMVSCnnRetrievalModuTool&);
            IMVSCnnRetrievalModuTool& operator=(IMVSCnnRetrievalModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CnnRetrieval.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCnnRetrievalModu::IMVSCnnRetrievalModuTool * __stdcall GetCnnRetrievalToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CNNRETRIEVAL_H_
