/***************************************************************************************************
 * File：IVmOcrDl.h
 * Note：CH: DL字符识别模块接口声明 | En: Interface for the OcrDl tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_OCRDL_H_
#define _IVM_OCRDL_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

#ifndef MVBOCRDL_MAX_TEXT_LEN
#define MVBOCRDL_MAX_TEXT_LEN (51)
#endif

#ifndef MVD_OCRDL_MAX_CHAR_NUM
#define MVD_OCRDL_MAX_CHAR_NUM (50)
#endif

namespace VisionMasterSDK
{
    namespace IMVSOcrDlModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class OcrDlRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the OcrDlParams.  */
        class OcrDlParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit OcrDlParams() {}
            virtual ~OcrDlParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual OcrDlRoiManager* GetModuRoiManager() = 0;

            // CH: 模型文件路径 | EN: Model File Path
            __declspec(property(put = SetLoadModelPath, get = GetLoadModelPath)) const char* LoadModelPath;

            virtual const char* GetLoadModelPath() = 0;

            virtual void SetLoadModelPath(const char* value) = 0;

            // CH: 方案存模型 | EN: Save Model Data
            __declspec(property(put = SetSaveModelDataEnable, get = GetSaveModelDataEnable)) bool SaveModelDataEnable;

            virtual bool GetSaveModelDataEnable() = 0;

            virtual void SetSaveModelDataEnable(bool value) = 0;

            // CH: 启用字符过滤 | EN: Character Filtration Enable
            __declspec(property(put = SetFontFilterEnable, get = GetFontFilterEnable)) bool FontFilterEnable;

            virtual bool GetFontFilterEnable() = 0;

            virtual void SetFontFilterEnable(bool value) = 0;

            // CH: 识别字符个数 | EN: Identify Character Quantity
            __declspec(property(put = SetFontFilterNum, get = GetFontFilterNum)) int FontFilterNum;

            virtual int GetFontFilterNum() = 0;

            virtual void SetFontFilterNum(int value) = 0;

            // CH: 字符过滤信息 | EN: Character Filtration Info.
            // OCR字符过滤协议：(0:全部, 1:数字, 2:英文, 3:大写字母, 4:小写字母, 5:特殊字符, 6:自定义字符串(协议格式6:32位16进制串), 7:空格)
            __declspec(property(put = SetFontFilterInfo, get = GetFontFilterInfo)) const char* FontFilterInfo;

            virtual const char* GetFontFilterInfo() = 0;

            virtual void SetFontFilterInfo(const char* value) = 0;

            // CH: 最小置信度 | EN: Min Confidence
            __declspec(property(put = SetMinConfidence, get = GetMinConfidence)) double MinConfidence;

            virtual double GetMinConfidence() = 0;

            virtual void SetMinConfidence(double value) = 0;

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

            // CH: 字符验证 | EN: Character Verification
            __declspec(property(put = SetVerifyEnable, get = GetVerifyEnable)) bool VerifyEnable;

            virtual bool GetVerifyEnable() = 0;

            virtual void SetVerifyEnable(bool value) = 0;

            // CH: 数字集 | EN: Number Set
            __declspec(property(put = SetNumVerifyEnable, get = GetNumVerifyEnable)) bool NumVerifyEnable;

            virtual bool GetNumVerifyEnable() = 0;

            virtual void SetNumVerifyEnable(bool value) = 0;

            // CH: 小写字母集 | EN: Lowercase Set
            __declspec(property(put = SetSmallAlphabetVerify, get = GetSmallAlphabetVerify)) bool SmallAlphabetVerify;

            virtual bool GetSmallAlphabetVerify() = 0;

            virtual void SetSmallAlphabetVerify(bool value) = 0;

            // CH: 大写字母集 | EN: Uppercase Set
            __declspec(property(put = SetBigAlphabetVerify, get = GetBigAlphabetVerify)) bool BigAlphabetVerify;

            virtual bool GetBigAlphabetVerify() = 0;

            virtual void SetBigAlphabetVerify(bool value) = 0;

            // CH: 特殊字符集 | EN: Special Character Set
            __declspec(property(put = SetSpecialCharVerify, get = GetSpecialCharVerify)) bool SpecialCharVerify;

            virtual bool GetSpecialCharVerify() = 0;

            virtual void SetSpecialCharVerify(bool value) = 0;

            // CH: 用户字符验证 | EN: UDC Verification
            __declspec(property(put = SetUserStringVerify, get = GetUserStringVerify)) bool UserStringVerify;

            virtual bool GetUserStringVerify() = 0;

            virtual void SetUserStringVerify(bool value) = 0;

            // CH: 用户字符 | EN: UDC
            __declspec(property(put = SetUserString, get = GetUserString)) const char* UserString;

            virtual const char* GetUserString() = 0;

            virtual void SetUserString(const char* value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        class ICNNOCRStringInfo
        {
        protected:
            explicit ICNNOCRStringInfo(){};
            virtual ~ICNNOCRStringInfo(){};
        public:
            /**
             * @par 说明
             * 单个字符串的有效长度
             * @par 权限
             * 只读
             */
            virtual int GetInfoLen() = 0;
            /**
             * @par 说明
             * 获取单个字符串内容
             * @par 权限
             * 只读
             */
            virtual void GetInfo(char pcCharInfo[MVBOCRDL_MAX_TEXT_LEN]) = 0;
            /**
             * @par 说明
             * 获取字符串中单个字符的置信度
             * @par 权限
             * 只读
             */
            virtual void GetConfidence(float pfConfidence[MVD_OCRDL_MAX_CHAR_NUM]) = 0;
        };

        /*  Note: Interface Classes of the result of the OcrDlResults.  */
        class OcrDlResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit OcrDlResults() {}
            virtual ~OcrDlResults() {}

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
            virtual RectBox GetROI(int nIndex) = 0;
            /**
             * @par 说明
             * 检测区域状态
             * @par 权限
             * 只读
             */
            virtual int GetROIStatus(int nIndex) = 0;
            /**
             * @par 说明
             * 识别字符串的总数量
             * @par 权限
             * 只读
             */
            virtual int GetPredictNum() = 0;
            /**
             * @par 说明
             * 通过索引获取单个字符串信息
             * @par 权限
             * 只读
             */
            virtual ICNNOCRStringInfo* GetPredictInfo(int nPredictIndex) = 0;
			/**
             * @par 说明
             * 获取模型标识
             * @par 权限
             * 只读
             */
            virtual const char * GetModelFlag() = 0;
            /**
             * @par 说明
             * 获取top 1预测信息的总体置信度
             * @par 权限
             * 只读
             */
            virtual float GetTotalConfidence() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the OcrDl tool.  */
        class IMVSOcrDlModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSOcrDlModuTool() {}
            virtual ~IMVSOcrDlModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual OcrDlParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual OcrDlResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSOcrDlModuTool(IMVSOcrDlModuTool&);
            IMVSOcrDlModuTool& operator=(IMVSOcrDlModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for OcrDl.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSOcrDlModu::IMVSOcrDlModuTool * __stdcall GetOcrDlToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_OCRDL_H_
