/***************************************************************************************************
 * File：IVmOcr.h
 * Note：CH: 字符识别模块接口声明 | En: Interface for the Ocr tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_OCR_H_
#define _IVM_OCR_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSOcrModu
    {        /*************************** Params Class Start ***************************/
        // CH: 字符极性 | EN: Character Polarity
        typedef enum _PolarityEnum
        {
            // CH: 白底黑字 | EN: Dark On Light
            Polarity_DarkOnBright = 0x1,

            // CH: 黑底白字 | EN: Light On Dark
            Polarity_BrightOnDark = 0x2,

        }PolarityEnum;

        // CH: 宽度类型 | EN: Width Type
        typedef enum _WidthTypeEnum
        {
            // CH: 可变类型 | EN: Changable Type
            WidthType_Changable = 0x0,

            // CH: 等宽类型 | EN: Aequilatus Type
            WidthType_Aequilatus = 0x1,

        }WidthTypeEnum;

        // CH: 忽略边框 | EN: Ignore Borders
        typedef enum _IgnoreBorderFragmentEnableEnum
        {
            // CH: 否 | EN: No
            IgnoreBorderFragmentEnable_Tab_No = 0x0,

            // CH: 是 | EN: Yes
            IgnoreBorderFragmentEnable_Tab_Yes = 0x1,

        }IgnoreBorderFragmentEnableEnum;

        // CH: 分类方法 | EN: Classification Method
        typedef enum _ClassMethodEnum
        {
            // CH: 距离最近 | EN: Nearest Distance
            ClassMethod_NearestDistance = 0x1,

            // CH: 权重最高 | EN: Weight Highest
            ClassMethod_WeightHighest = 0x2,

            // CH: 频率最高 | EN: Rate Fastest
            ClassMethod_RateFastest = 0x3,

        }ClassMethodEnum;

        // CH: 字宽滤波使能 | EN: Stroke Width Filter
        typedef enum _StrokeFilterEnableEnum
        {
            // CH: 不使能 | EN: Disabled
            StrokeFilterEnable_No = 0x0,

            // CH: 使能 | EN: Enabled
            StrokeFilterEnable_Yes = 0x1,

        }StrokeFilterEnableEnum;

        // CH: 相似度类型 | EN: Similarity Type
        typedef enum _SimilarFunEnum
        {
            // CH: 欧式距离 | EN: Euclidean Distance
            SimilarFun_Euclid = 0x1,

            // CH: 余弦距离 | EN: Cosine Distance
            SimilarFun_Cosine = 0x2,

        }SimilarFunEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class OcrRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the OcrParams.  */
        class OcrParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit OcrParams() {}
            virtual ~OcrParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual OcrRoiManager* GetModuRoiManager() = 0;

            // CH: 启用字符过滤 | EN: Character Filtration Enable
            __declspec(property(put = SetFontFilterEnable, get = GetFontFilterEnable)) bool FontFilterEnable;

            virtual bool GetFontFilterEnable() = 0;

            virtual void SetFontFilterEnable(bool value) = 0;

            // CH: 识别字符个数 | EN: Identify Character Quantity
            __declspec(property(put = SetFontFilterNum, get = GetFontFilterNum)) int FontFilterNum;

            virtual int GetFontFilterNum() = 0;

            virtual void SetFontFilterNum(int value) = 0;

            // CH: 字符过滤信息 | EN: Character Filtration Info.
            // // OCR字符过滤协议：(0:全部, 1:数字, 2:英文, 3:大写字母, 4:小写字母, 5:特殊字符, 6:自定义字符串(协议格式6:32位16进制串), 7:空格)
            __declspec(property(put = SetFontFilterInfo, get = GetFontFilterInfo)) const char* FontFilterInfo;

            virtual const char* GetFontFilterInfo() = 0;

            virtual void SetFontFilterInfo(const char* value) = 0;

            // CH: 字符极性 | EN: Character Polarity
            __declspec(property(put = SetPolarity, get = GetPolarity)) PolarityEnum Polarity;

            virtual PolarityEnum GetPolarity() = 0;

            virtual void SetPolarity(PolarityEnum value) = 0;

            // CH: 字符宽度范围 | EN: Character Width Range
            __declspec(property(put = SetMinCharWidth, get = GetMinCharWidth)) int MinCharWidth;

            virtual int GetMinCharWidth() = 0;

            virtual void SetMinCharWidth(int value) = 0;

            // CH: 字符宽度范围 | EN: Character Width Range
            __declspec(property(put = SetMaxCharWidth, get = GetMaxCharWidth)) int MaxCharWidth;

            virtual int GetMaxCharWidth() = 0;

            virtual void SetMaxCharWidth(int value) = 0;

            // CH: 宽度类型 | EN: Width Type
            __declspec(property(put = SetWidthType, get = GetWidthType)) WidthTypeEnum WidthType;

            virtual WidthTypeEnum GetWidthType() = 0;

            virtual void SetWidthType(WidthTypeEnum value) = 0;

            // CH: 字符高度范围 | EN: Character Height Range
            __declspec(property(put = SetMinCharHeight, get = GetMinCharHeight)) int MinCharHeight;

            virtual int GetMinCharHeight() = 0;

            virtual void SetMinCharHeight(int value) = 0;

            // CH: 字符高度范围 | EN: Character Height Range
            __declspec(property(put = SetMaxCharHeight, get = GetMaxCharHeight)) int MaxCharHeight;

            virtual int GetMaxCharHeight() = 0;

            virtual void SetMaxCharHeight(int value) = 0;

            // CH: 二值化系数 | EN: Binary Ratio
            __declspec(property(put = SetBinaryCoef, get = GetBinaryCoef)) int BinaryCoef;

            virtual int GetBinaryCoef() = 0;

            virtual void SetBinaryCoef(int value) = 0;

            // CH: 片段面积范围 | EN: Area of fragment area
            __declspec(property(put = SetMinCharArea, get = GetMinCharArea)) int MinCharArea;

            virtual int GetMinCharArea() = 0;

            virtual void SetMinCharArea(int value) = 0;

            // CH: 片段面积范围 | EN: Area of fragment area
            __declspec(property(put = SetMaxCharArea, get = GetMaxCharArea)) int MaxCharArea;

            virtual int GetMaxCharArea() = 0;

            virtual void SetMaxCharArea(int value) = 0;

            // CH: 合格阈值 | EN: Accept Threshold
            __declspec(property(put = SetAcceptThreshold, get = GetAcceptThreshold)) int AcceptThreshold;

            virtual int GetAcceptThreshold() = 0;

            virtual void SetAcceptThreshold(int value) = 0;

            // CH: 距离阈值 | EN: Distance Threshold
            __declspec(property(put = SetMainLineDistThresh, get = GetMainLineDistThresh)) int MainLineDistThresh;

            virtual int GetMainLineDistThresh() = 0;

            virtual void SetMainLineDistThresh(int value) = 0;

            // CH: 忽略边框 | EN: Ignore Borders
            __declspec(property(put = SetIgnoreBorderFragmentEnable, get = GetIgnoreBorderFragmentEnable)) IgnoreBorderFragmentEnableEnum IgnoreBorderFragmentEnable;

            virtual IgnoreBorderFragmentEnableEnum GetIgnoreBorderFragmentEnable() = 0;

            virtual void SetIgnoreBorderFragmentEnable(IgnoreBorderFragmentEnableEnum value) = 0;

            // CH: 主方向范围 | EN: Main Direction Range
            __declspec(property(put = SetOrientHalfRange, get = GetOrientHalfRange)) int OrientHalfRange;

            virtual int GetOrientHalfRange() = 0;

            virtual void SetOrientHalfRange(int value) = 0;

            // CH: 倾斜角范围 | EN: Tilt Range
            __declspec(property(put = SetSlantHalfRange, get = GetSlantHalfRange)) int SlantHalfRange;

            virtual int GetSlantHalfRange() = 0;

            virtual void SetSlantHalfRange(int value) = 0;

            // CH: 字符最小间隙 | EN: Min Char Gap
            __declspec(property(put = SetMinInterCharGap, get = GetMinInterCharGap)) int MinInterCharGap;

            virtual int GetMinInterCharGap() = 0;

            virtual void SetMinInterCharGap(int value) = 0;

            // CH: 行间最小间隙 | EN: Min Text Gap
            __declspec(property(put = SetMinInterTextGap, get = GetMinInterTextGap)) int MinInterTextGap;

            virtual int GetMinInterTextGap() = 0;

            virtual void SetMinInterTextGap(int value) = 0;

            // CH: 最大宽高比 | EN: Max Aspect Ratio
            __declspec(property(put = SetMaxLengthWidthRatio, get = GetMaxLengthWidthRatio)) int MaxLengthWidthRatio;

            virtual int GetMaxLengthWidthRatio() = 0;

            virtual void SetMaxLengthWidthRatio(int value) = 0;

            // CH: 分类方法 | EN: Classification Method
            __declspec(property(put = SetClassMethod, get = GetClassMethod)) ClassMethodEnum ClassMethod;

            virtual ClassMethodEnum GetClassMethod() = 0;

            virtual void SetClassMethod(ClassMethodEnum value) = 0;

            // CH: 字宽滤波使能 | EN: Stroke Width Filter
            __declspec(property(put = SetStrokeFilterEnable, get = GetStrokeFilterEnable)) StrokeFilterEnableEnum StrokeFilterEnable;

            virtual StrokeFilterEnableEnum GetStrokeFilterEnable() = 0;

            virtual void SetStrokeFilterEnable(StrokeFilterEnableEnum value) = 0;

            // CH: 笔画宽度范围 | EN: Stroke Width Range
            __declspec(property(put = SetMinStrokeWidth, get = GetMinStrokeWidth)) int MinStrokeWidth;

            virtual int GetMinStrokeWidth() = 0;

            virtual void SetMinStrokeWidth(int value) = 0;

            // CH: 笔画宽度范围 | EN: Stroke Width Range
            __declspec(property(put = SetMaxStrokeWidth, get = GetMaxStrokeWidth)) int MaxStrokeWidth;

            virtual int GetMaxStrokeWidth() = 0;

            virtual void SetMaxStrokeWidth(int value) = 0;

            // CH: 相似度类型 | EN: Similarity Type
            __declspec(property(put = SetSimilarFun, get = GetSimilarFun)) SimilarFunEnum SimilarFun;

            virtual SimilarFunEnum GetSimilarFun() = 0;

            virtual void SetSimilarFun(SimilarFunEnum value) = 0;

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
        // 字符识别信息
        class IOCRPredictInfo
        {
        protected:
            // 构造函数和析构函数
            explicit IOCRPredictInfo() {}
            virtual ~IOCRPredictInfo() {}

        public:
            /**
             * @par 说明
             * 位置信息
             * @par 权限
             * 只读
             */
            virtual RectBox GetBox() = 0;
            /**
             * @par 说明
             * 倾斜角度
             * @par 权限
             * 只读
             */
            virtual float GetSkewAngle() = 0;
            /**
             * @par 说明
             * 字符标签信息
             * @par 权限
             * 只读
             */
            virtual char GetLabel() = 0;
            /**
             * @par 说明
             * 备选字符标签信息
             * @par 权限
             * 只读
             */
            virtual char GetAlternativeLabel() = 0;
            /**
             * @par 说明
             * 字符标签得分
             * @par 权限
             * 只读
             */
            virtual float GetLabelScore() = 0;
            /**
             * @par 说明
             * 备选字符标签得分
             * @par 权限
             * 只读
             */
            virtual float GetAlternativeLabelScore() = 0;
            /**
             * @par 说明
             * 置信度
             * @par 权限
             * 只读
             */
            virtual float GetConfidence() = 0;
        };

        /*  Note: Interface Classes of the result of the OcrResults.  */
        class OcrResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit OcrResults() {}
            virtual ~OcrResults() {}

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
             * @brief 获取字符数量
             * @param 无
             * @return 字符数量
             * @par 注解
             * 无
             */
            virtual int GetCharacterNum() = 0;

            /**
             * @brief 获取识别的字符信息
             * @param nIndex [in] 拟查询的字符索引，从0开始计数
             * @return 字符信息
             * @par 注解
             * 出错时抛出异常
             */
            virtual IOCRPredictInfo* GetPredictInfo(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Ocr tool.  */
        class IMVSOcrModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSOcrModuTool() {}
            virtual ~IMVSOcrModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual OcrParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual OcrResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

            /**
            * @brief 导入模型
            * @param 模型路径
            * @return 无，出错时抛出异常
            * @par 注解
            * 导入模型
            */
            virtual void ImportModelData(IN const char * const strPath) = 0;

        private:
            IMVSOcrModuTool(IMVSOcrModuTool&);
            IMVSOcrModuTool& operator=(IMVSOcrModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Ocr.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSOcrModu::IMVSOcrModuTool * __stdcall GetOcrToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_OCR_H_
