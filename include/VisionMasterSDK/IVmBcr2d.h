/***************************************************************************************************
 * File：IVmBcr2d.h
 * Note：CH: 二维码识别模块接口声明 | En: Interface for the Bcr2d tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_BCR2D_H_
#define _IVM_BCR2D_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVS2dBcrModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 极性 | EN: Polarity
        typedef enum _PolarityEnum
        {
            // CH: 白底黑码 | EN: Dark On White
            Polarity_dark = 0x0,

            // CH: 黑底白码 | EN: White On Dark
            Polarity_bright = 0x1,

            // CH: 任意 | EN: Any
            Polarity_both = 0x2,

        }PolarityEnum;

        // CH: 边缘类型 | EN: Edge Type
        typedef enum _EdgeTypeEnum
        {
            // CH: 连续型 | EN: Continuous
            EdgeType_continuous = 0x0,

            // CH: 离散型 | EN: Discrete
            EdgeType_discrete = 0x1,

            // CH: 兼容模式 | EN: Compatibility
            EdgeType_allmode = 0x2,

        }EdgeTypeEnum;

        // CH: 镜像模式 | EN: Mirror Mode
        typedef enum _MirrorEnum
        {
            // CH: 非镜像 | EN: Non-Mirrored
            Mirror_Off = 0x0,

            // CH: 镜像 | EN: Mirrored
            Mirror_On = 0x1,

            // CH: 任意 | EN: Any
            Mirror_Both = 0x2,

        }MirrorEnum;

        // CH: QR畸变 | EN: QR Distortion
        typedef enum _DistortionFlagEnum
        {
            // CH: 非畸变 | EN: No Distortion
            DistortionFlag_Off = 0x0,

            // CH: 畸变 | EN: Distortion
            DistortionFlag_On = 0x1,

        }DistortionFlagEnum;

        // CH: 应用模式 | EN: Application Mode
        typedef enum _AppModeEnum
        {
            // CH: 普通模式 | EN: Normal Mode
            AppMode_Normal = 0x0,

            // CH: 专家模式 | EN: Expert Mode
            AppMode_ProMode = 0x1,

            // CH: 极速模式 | EN: Fast Mode
            AppMode_FastMode = 0x2,

        }AppModeEnum;

        // CH: DM码类型 | EN: DM Type
        typedef enum _RectangleEnum
        {
            // CH: 正方形 | EN: Square
            Rectangle_Square = 0x0,

            // CH: 长方形 | EN: Rectangle
            Rectangle_Rectangle = 0x1,

            // CH: 兼容模式 | EN: Compatibility
            Rectangle_AllMode = 0x2,

        }RectangleEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class Bcr2dRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the Bcr2dParams.  */
        class Bcr2dParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit Bcr2dParams() {}
            virtual ~Bcr2dParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual Bcr2dRoiManager* GetModuRoiManager() = 0;

            // CH: QR码 | EN: QR Code
            __declspec(property(put = SetQRCode, get = GetQRCode)) bool QRCode;

            virtual bool GetQRCode() = 0;

            virtual void SetQRCode(bool value) = 0;

            // CH: DataMatrix码 | EN: DM Code
            __declspec(property(put = SetDMCode, get = GetDMCode)) bool DMCode;

            virtual bool GetDMCode() = 0;

            virtual void SetDMCode(bool value) = 0;

            // CH: 二维码个数 | EN: 2D Code Number
            __declspec(property(put = SetLocCodeNum, get = GetLocCodeNum)) int LocCodeNum;

            virtual int GetLocCodeNum() = 0;

            virtual void SetLocCodeNum(int value) = 0;

            // CH: 极性 | EN: Polarity
            __declspec(property(put = SetPolarity, get = GetPolarity)) PolarityEnum Polarity;

            virtual PolarityEnum GetPolarity() = 0;

            virtual void SetPolarity(PolarityEnum value) = 0;

            // CH: 边缘类型 | EN: Edge Type
            __declspec(property(put = SetEdgeType, get = GetEdgeType)) EdgeTypeEnum EdgeType;

            virtual EdgeTypeEnum GetEdgeType() = 0;

            virtual void SetEdgeType(EdgeTypeEnum value) = 0;

            // CH: 降采样倍数 | EN: Subsampling Ratio
            __declspec(property(put = SetSampleLevel, get = GetSampleLevel)) int SampleLevel;

            virtual int GetSampleLevel() = 0;

            virtual void SetSampleLevel(int value) = 0;

            // CH: 码宽范围 | EN: Code Width Range
            __declspec(property(put = SetMinBarSize, get = GetMinBarSize)) int MinBarSize;

            virtual int GetMinBarSize() = 0;

            virtual void SetMinBarSize(int value) = 0;

            // CH: 码宽范围 | EN: Code Width Range
            __declspec(property(put = SetMaxBarSize, get = GetMaxBarSize)) int MaxBarSize;

            virtual int GetMaxBarSize() = 0;

            virtual void SetMaxBarSize(int value) = 0;

            // CH: 镜像模式 | EN: Mirror Mode
            __declspec(property(put = SetMirror, get = GetMirror)) MirrorEnum Mirror;

            virtual MirrorEnum GetMirror() = 0;

            virtual void SetMirror(MirrorEnum value) = 0;

            // CH: QR畸变 | EN: QR Distortion
            __declspec(property(put = SetDistortionFlag, get = GetDistortionFlag)) DistortionFlagEnum DistortionFlag;

            virtual DistortionFlagEnum GetDistortionFlag() = 0;

            virtual void SetDistortionFlag(DistortionFlagEnum value) = 0;

            // CH: 超时退出时间 | EN: Timeout-Period to Exit
            __declspec(property(put = SetWaitingTime, get = GetWaitingTime)) int WaitingTime;

            virtual int GetWaitingTime() = 0;

            virtual void SetWaitingTime(int value) = 0;

            // CH: 应用模式 | EN: Application Mode
            __declspec(property(put = SetAppMode, get = GetAppMode)) AppModeEnum AppMode;

            virtual AppModeEnum GetAppMode() = 0;

            virtual void SetAppMode(AppModeEnum value) = 0;

            // CH: DM码类型 | EN: DM Type
            __declspec(property(put = SetRectangle, get = GetRectangle)) RectangleEnum Rectangle;

            virtual RectangleEnum GetRectangle() = 0;

            virtual void SetRectangle(RectangleEnum value) = 0;

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
        /** @enum MVD_2DCODE_TYPE
         *  @brief 二维码类型
         */
        typedef enum _MVD_2DCODE_TYPE__
        {
            MVD_2DCODE_TYPE_NONE = 0, // 无可识别条码
            MVD_2DCODE_TYPE_DM = 101, // DM码
            MVD_2DCODE_TYPE_QR = 102, // QR码
        }MVD_2DCODE_TYPE;

        /*  Note: 二维码识别码信息描述类. */
        class I2DCodeInfo
        {
        protected:
            ///< 构造与析构函数
            explicit I2DCodeInfo() {}
            virtual ~I2DCodeInfo() {}

        public:
            /**
             * @par 说明
             * 二维码位置坐标
             * @par 权限
             * 只读
             */
            virtual RectBox GetPosition() = 0;
            /**
             * @par 说明
             * 二维码内容
             * @par 权限
             * 只读
             */
            virtual const char* GetContent() = 0;
            /**
             * @par 说明
             * 二维码类型
             * @par 权限
             * 只读
             */
            virtual MVD_2DCODE_TYPE GetType() = 0;
            /**
             * @par 说明
             * 二维码角度
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

        /*  Note: Interface Classes of the result of the Bcr2dResults.  */
        class Bcr2dResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit Bcr2dResults() {}
            virtual ~Bcr2dResults() {}

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
             * 二维码个数
             * @par 权限
             * 只读
             */
            virtual int GetCodeNum() = 0;
            /**
             * @brief 获取二维码信息
             * @param nIndex [in] 二维码信息索引
             * @return 返回二维码信息
             * @par 注解
             * nIndex从0开始计数。
             */
            virtual I2DCodeInfo* GetCodeInfo(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Bcr2d tool.  */
        class IMVS2dBcrModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVS2dBcrModuTool() {}
            virtual ~IMVS2dBcrModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual Bcr2dParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual Bcr2dResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVS2dBcrModuTool(IMVS2dBcrModuTool&);
            IMVS2dBcrModuTool& operator=(IMVS2dBcrModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Bcr2d.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVS2dBcrModu::IMVS2dBcrModuTool * __stdcall GetBcr2dToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_BCR2D_H_
