/***************************************************************************************************
 * File：IVmCnnRegisterClassify.h
 * Note：CH: 注册分类G模块接口声明 | En: Interface for the CnnRegisterClassify tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CNNREGISTERCLASSIFY_H_
#define _IVM_CNNREGISTERCLASSIFY_H_

#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCnnRegisterClassifyModu
    {
        /*************************** Params Class Start ***************************/
		/*  Note: Interface Classes of the RoiManager.  */
		class CnnRegisterClassifyRoiManager
		{
		public:

			// CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
			virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

		};

		/*  Note: Interface Classes of the parameter of the CnnRegisterClassifyParams.  */
        class CnnRegisterClassifyParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnRegisterClassifyParams() {}
            virtual ~CnnRegisterClassifyParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

			// CH: ROI管理器 | EN: ROI Manager
			virtual CnnRegisterClassifyRoiManager* GetModuRoiManager() = 0;

			// CH: Gallery路径 | EN: Gallery Path
			__declspec(property(put = SetLoadGalleryFilePath, get = GetLoadGalleryFilePath)) const char* LoadGalleryFilePath;

			virtual const char* GetLoadGalleryFilePath() = 0;

			virtual void SetLoadGalleryFilePath(const char* value) = 0;

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
        /*  Note: Interface Classes of the result of the CnnRegisterClassifyResults.  */
        class CnnRegisterClassifyResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnRegisterClassifyResults() {}
            virtual ~CnnRegisterClassifyResults() {}

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
			 * 类别个数
			 * @par 权限
			 * 只读
			 */
			 virtual int GetClassNum() = 0;

			 /**
			 * @par 说明
			 * 相似度
			 * @par 权限
			 * 只读
			 */
			 virtual float GetSimilarity(int nIndex) = 0;

			 /**
			 * @par 说明
			 * 图像索引
			 * @par 权限
			 * 只读
			 */
			 virtual int GetImageIndex(int nIndex) = 0;

			 /**
			 * @par 说明
			 * 类别名称
			 * @par 权限
			 * 只读
			 */
			 virtual string GetClassName(int nIndex) = 0;

			 /**
			 * @par 说明
			 * 缩略图_0
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetSampleImage_0() = 0;

			 /**
			 * @par 说明
			 * 缩略图_1
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetSampleImage_1() = 0;

			 /**
			 * @par 说明
			 * 缩略图_2
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetSampleImage_2() = 0;

			 /**
			 * @par 说明
			 * 缩略图_3
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetSampleImage_3() = 0;

			 /**
			 * @par 说明
			 * 缩略图_4
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetSampleImage_4() = 0;

			 /**
			 * @par 说明
			 * 缩略图_5
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetSampleImage_5() = 0;

			 /**
			 * @par 说明
			 * 缩略图_6
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetSampleImage_6() = 0;

			 /**
			 * @par 说明
			 * 缩略图_7
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetSampleImage_7() = 0;

			 /**
			 * @par 说明
			 * 缩略图_8
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetSampleImage_8() = 0;

			 /**
			 * @par 说明
			 * 缩略图_9
			 * @par 权限
			 * 只读
			 */
			 virtual ImageBaseData GetSampleImage_9() = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CnnRegisterClassify tool.  */
        class IMVSCnnRegisterClassifyModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCnnRegisterClassifyModuTool() {}
            virtual ~IMVSCnnRegisterClassifyModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CnnRegisterClassifyParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CnnRegisterClassifyResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCnnRegisterClassifyModuTool(IMVSCnnRegisterClassifyModuTool&);
            IMVSCnnRegisterClassifyModuTool& operator=(IMVSCnnRegisterClassifyModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CnnRegisterClassify.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCnnRegisterClassifyModu::IMVSCnnRegisterClassifyModuTool * __stdcall GetCnnRegisterClassifyToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CNNREGISTERCLASSIFY_H_
