/***************************************************************************************************
 * File：IVmBcr.h
 * Note：CH: 条码识别模块接口声明 | En: Interface for the Bcr tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_BCR_H_
#define _IVM_BCR_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSBcrModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class BcrRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the BcrParams.  */
        class BcrParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BcrParams() {}
            virtual ~BcrParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual BcrRoiManager* GetModuRoiManager() = 0;

            // CH: CODE39码 | EN: CODE 39
            __declspec(property(put = SetCODE39, get = GetCODE39)) bool CODE39;

            virtual bool GetCODE39() = 0;

            virtual void SetCODE39(bool value) = 0;

            // CH: CODE128码 | EN: CODE 128
            __declspec(property(put = SetCODE128, get = GetCODE128)) bool CODE128;

            virtual bool GetCODE128() = 0;

            virtual void SetCODE128(bool value) = 0;

            // CH: 库得巴码 | EN: Codabar
            __declspec(property(put = SetCODABAR, get = GetCODABAR)) bool CODABAR;

            virtual bool GetCODABAR() = 0;

            virtual void SetCODABAR(bool value) = 0;

            // CH: EAN码 | EN: EAN
            __declspec(property(put = SetEAN, get = GetEAN)) bool EAN;

            virtual bool GetEAN() = 0;

            virtual void SetEAN(bool value) = 0;

            // CH: 交替25码 | EN: ITF25
            __declspec(property(put = SetITF25, get = GetITF25)) bool ITF25;

            virtual bool GetITF25() = 0;

            virtual void SetITF25(bool value) = 0;

            // CH: CODE93码 | EN: CODE 93
            __declspec(property(put = SetCODE93, get = GetCODE93)) bool CODE93;

            virtual bool GetCODE93() = 0;

            virtual void SetCODE93(bool value) = 0;

            // CH: 条码个数 | EN: Bar Code Number
            __declspec(property(put = SetBarNum, get = GetBarNum)) int BarNum;

            virtual int GetBarNum() = 0;

            virtual void SetBarNum(int value) = 0;

            // CH: 降采样系数 | EN: Decimation Coefficient
            __declspec(property(put = SetPreSampleLevel, get = GetPreSampleLevel)) int PreSampleLevel;

            virtual int GetPreSampleLevel() = 0;

            virtual void SetPreSampleLevel(int value) = 0;

            // CH: 检测窗口大小 | EN: Detection Window Size
            __declspec(property(put = SetLocWinSize, get = GetLocWinSize)) int LocWinSize;

            virtual int GetLocWinSize() = 0;

            virtual void SetLocWinSize(int value) = 0;

            // CH: 静区宽度 | EN: Quiet Zone Width
            __declspec(property(put = SetSegQuietW, get = GetSegQuietW)) int SegQuietW;

            virtual int GetSegQuietW() = 0;

            virtual void SetSegQuietW(int value) = 0;

            // CH: 去伪过滤尺寸 | EN: DfkSize
            __declspec(property(put = SetDfkMinSize, get = GetDfkMinSize)) int DfkMinSize;

            virtual int GetDfkMinSize() = 0;

            virtual void SetDfkMinSize(int value) = 0;

            // CH: 去伪过滤尺寸 | EN: DfkSize
            __declspec(property(put = SetDfkMaxSize, get = GetDfkMaxSize)) int DfkMaxSize;

            virtual int GetDfkMaxSize() = 0;

            virtual void SetDfkMaxSize(int value) = 0;

            // CH: 超时退出时间 | EN: Timeout-Period to Exit
            __declspec(property(put = SetWaitingTime, get = GetWaitingTime)) int WaitingTime;

            virtual int GetWaitingTime() = 0;

            virtual void SetWaitingTime(int value) = 0;

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
        /** @enum MVD_1DCODE_TYPE
        *  @brief  1D Code Type - enum type
        */
        typedef _MVD_1DCODE_TYPE__ MVD_1DCODE_TYPE;

        /*  Note: Interface Classes for describing 1D Code detail information.  */
        class I1DCodeInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit I1DCodeInfo() {}
            virtual ~I1DCodeInfo() {}

        public:
            /**
            * @par 说明
            * 条码的位置,[0,3600],顺时针
            * @par 权限
            * 只读
            */
            virtual RectBox GetPosition(void) = 0;
            /**
             * @par 说明
             * 条码内容
             * @par 权限
             * 只读
             */
            virtual const char* GetContent() = 0;
            /**
             * @par 说明
             * 条码类型
             * @par 权限
             * 只读
             */
            virtual MVD_1DCODE_TYPE GetType() = 0;
            /**
             * @par 说明
             * 条码角度
             * @par 权限
             * 只读
             */
            virtual float GetAngle() = 0;
            /**
            * @par 说明
            * 估计ppm
            * @par 权限
            * 只读
            */
            virtual float GetEstppm() = 0;
        };

        /*  Note: Interface Classes of the result of the BcrResults.  */
        class BcrResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BcrResults() {}
            virtual ~BcrResults() {}

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
             * 条码个数
             * @par 权限
             * 只读
             */
            virtual int GetCodeNum() = 0;
            /**
             * @par 说明
             * 条码区域个数(当前版本尚未支持,输出为0)
             * @par 权限
             * 只读
             */
            virtual int GetRegionNum() = 0;
            /**
             * @brief 获取条码信息
             * @param nIndex [in] 条码信息索引
             * @return 返回条码信息
             * @par 注解
             * nIndex从0开始计数。
             */
            virtual I1DCodeInfo* GetCodeInfo(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Bcr tool.  */
        class IMVSBcrModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSBcrModuTool() {}
            virtual ~IMVSBcrModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual BcrParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual BcrResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSBcrModuTool(IMVSBcrModuTool&);
            IMVSBcrModuTool& operator=(IMVSBcrModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Bcr.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSBcrModu::IMVSBcrModuTool * __stdcall GetBcrToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_BCR_H_
