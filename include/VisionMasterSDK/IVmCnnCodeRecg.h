/***************************************************************************************************
 * File：IVmCnnCodeRecg.h
 * Note：CH: DL读码模块接口声明 | En: Interface for the CnnCodeRecg tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CNNCODERECG_H_
#define _IVM_CNNCODERECG_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCnnCodeRecgModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 极性 | EN: Polarity
        typedef enum _CodePolarityEnum
        {
            // CH: 白底黑码 | EN: Dark On White
            CodePolarity_dark = 0x0,

            // CH: 黑底白码 | EN: White On Dark
            CodePolarity_bright = 0x1,

            // CH: 任意 | EN: Any
            CodePolarity_both = 0x2,

        }CodePolarityEnum;

        // CH: 边缘类型 | EN: Edge Type
        typedef enum _DiscreteFlagEnum
        {
            // CH: 连续型 | EN: Continuous
            DiscreteFlag_continuous = 0x0,

            // CH: 离散型 | EN: Discrete
            DiscreteFlag_discrete = 0x1,

            // CH: 兼容模式 | EN: Compatibility
            DiscreteFlag_allmode = 0x2,

        }DiscreteFlagEnum;

        // CH: 镜像模式 | EN: Mirror Mode
        typedef enum _MirrorModeEnum
        {
            // CH: 非镜像 | EN: Non-Mirrored
            MirrorMode_Off = 0x0,

            // CH: 镜像 | EN: Mirrored
            MirrorMode_On = 0x1,

            // CH: 任意 | EN: Any
            MirrorMode_Both = 0x2,

        }MirrorModeEnum;

        // CH: QR畸变 | EN: QR Distortion
        typedef enum _DistortionFlagEnum
        {
            // CH: 非畸变 | EN: No Distortion
            DistortionFlag_Off = 0x0,

            // CH: 畸变 | EN: Distortion
            DistortionFlag_On = 0x1,

        }DistortionFlagEnum;

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

        // CH: ISO标准 | EN: ISO Standard
        typedef enum _StandardTypeEnum
        {
            // CH: ISO15415 | EN: ISO15415
            StandardType_ISO15415 = 0x1,

            // CH: ISO29158 | EN: ISO29158
            StandardType_ISO29158 = 0x2,

        }StandardTypeEnum;

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

        // CH: 评级处理类型 | EN: Classification Type
        typedef enum _ClassificationTypeEnum
        {
            // CH: 处理类型1 | EN: process type 1
            ClassificationType_process_type_one = 0x1,

            // CH: 处理类型2 | EN: process type 2
            ClassificationType_process_type_two = 0x2,

        }ClassificationTypeEnum;

        // CH: 评级模式 | EN: Verify Mode Type
        typedef enum _VerifyLabelTypeEnum
        {
            // CH: ISO模式 | EN: ISO Mode
            VerifyLabelType_ISO_Mode = 0x1,

            // CH: HIK模式 | EN: HIK Mode
            VerifyLabelType_HIK_Mode = 0x2,

        }VerifyLabelTypeEnum;

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
        typedef enum _EdgeFeatureEnum
        {
            // CH: 连续型 | EN: Continuous
            EdgeFeature_continuous = 0x0,

            // CH: 离散型 | EN: Discrete
            EdgeFeature_discrete = 0x1,

        }EdgeFeatureEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class CnnCodeRecgRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the CnnCodeRecgParams.  */
        class CnnCodeRecgParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnCodeRecgParams() {}
            virtual ~CnnCodeRecgParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual CnnCodeRecgRoiManager* GetModuRoiManager() = 0;

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

            // CH: EAN8码 | EN: EAN8
            __declspec(property(put = SetEAN8, get = GetEAN8)) bool EAN8;

            virtual bool GetEAN8() = 0;

            virtual void SetEAN8(bool value) = 0;

            // CH: EAN13码 | EN: EAN13
            __declspec(property(put = SetEAN13, get = GetEAN13)) bool EAN13;

            virtual bool GetEAN13() = 0;

            virtual void SetEAN13(bool value) = 0;

            // CH: UPCA码 | EN: UPCA
            __declspec(property(put = SetUPCA, get = GetUPCA)) bool UPCA;

            virtual bool GetUPCA() = 0;

            virtual void SetUPCA(bool value) = 0;

            // CH: UPCE码 | EN: UPCE
            __declspec(property(put = SetUPCE, get = GetUPCE)) bool UPCE;

            virtual bool GetUPCE() = 0;

            virtual void SetUPCE(bool value) = 0;

            // CH: 交替25码 | EN: ITF25
            __declspec(property(put = SetITF25, get = GetITF25)) bool ITF25;

            virtual bool GetITF25() = 0;

            virtual void SetITF25(bool value) = 0;

            // CH: CODE93码 | EN: CODE 93
            __declspec(property(put = SetCODE93, get = GetCODE93)) bool CODE93;

            virtual bool GetCODE93() = 0;

            virtual void SetCODE93(bool value) = 0;

            // CH: MATRIX25码 | EN: MATRIX25
            __declspec(property(put = SetMATRIX25, get = GetMATRIX25)) bool MATRIX25;

            virtual bool GetMATRIX25() = 0;

            virtual void SetMATRIX25(bool value) = 0;

            // CH: MSI码 | EN: MSI
            __declspec(property(put = SetMSI, get = GetMSI)) bool MSI;

            virtual bool GetMSI() = 0;

            virtual void SetMSI(bool value) = 0;

            // CH: CNPOST码 | EN: CHINAPOST
            __declspec(property(put = SetCHINAPOST, get = GetCHINAPOST)) bool CHINAPOST;

            virtual bool GetCHINAPOST() = 0;

            virtual void SetCHINAPOST(bool value) = 0;

            // CH: CODE11码 | EN: CODE11
            __declspec(property(put = SetCODE11, get = GetCODE11)) bool CODE11;

            virtual bool GetCODE11() = 0;

            virtual void SetCODE11(bool value) = 0;

            // CH: IND25码 | EN: INDUSTRIAL25
            __declspec(property(put = SetINDUSTRIAL25, get = GetINDUSTRIAL25)) bool INDUSTRIAL25;

            virtual bool GetINDUSTRIAL25() = 0;

            virtual void SetINDUSTRIAL25(bool value) = 0;

            // CH: ITF14码 | EN: ITF14
            __declspec(property(put = SetITF14, get = GetITF14)) bool ITF14;

            virtual bool GetITF14() = 0;

            virtual void SetITF14(bool value) = 0;

            // CH: 条码个数 | EN: Bar Code Number
            __declspec(property(put = SetBarCodeNum, get = GetBarCodeNum)) int BarCodeNum;

            virtual int GetBarCodeNum() = 0;

            virtual void SetBarCodeNum(int value) = 0;

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

            // CH: 弃用,无功能 | EN: Obsolete,ineffectual
            // CH: 极性 | EN: Polarity
            __declspec(property(put = SetCodePolarity, get = GetCodePolarity)) CodePolarityEnum CodePolarity;

            virtual CodePolarityEnum GetCodePolarity() = 0;

            virtual void SetCodePolarity(CodePolarityEnum value) = 0;

            // CH: 弃用,无功能 | EN: Obsolete,ineffectual
            // CH: 边缘类型 | EN: Edge Type
            __declspec(property(put = SetDiscreteFlag, get = GetDiscreteFlag)) DiscreteFlagEnum DiscreteFlag;

            virtual DiscreteFlagEnum GetDiscreteFlag() = 0;

            virtual void SetDiscreteFlag(DiscreteFlagEnum value) = 0;

            // CH: 弃用,无功能 | EN: Obsolete,ineffectual
            // CH: 降采样倍数 | EN: Subsampling Ratio
            __declspec(property(put = SetSampleLevel, get = GetSampleLevel)) int SampleLevel;

            virtual int GetSampleLevel() = 0;

            virtual void SetSampleLevel(int value) = 0;

            // CH: 弃用,无功能 | EN: Obsolete,ineffectual
            // CH: 镜像模式 | EN: Mirror Mode
            __declspec(property(put = SetMirrorMode, get = GetMirrorMode)) MirrorModeEnum MirrorMode;

            virtual MirrorModeEnum GetMirrorMode() = 0;

            virtual void SetMirrorMode(MirrorModeEnum value) = 0;

            // CH: 弃用,无功能 | EN: Obsolete,ineffectual
            // CH: QR畸变 | EN: QR Distortion
            __declspec(property(put = SetDistortionFlag, get = GetDistortionFlag)) DistortionFlagEnum DistortionFlag;

            virtual DistortionFlagEnum GetDistortionFlag() = 0;

            virtual void SetDistortionFlag(DistortionFlagEnum value) = 0;

            // CH: 弃用,无功能 | EN: Obsolete,ineffectual
            // CH: DM码类型 | EN: DM Type
            __declspec(property(put = SetRectangle, get = GetRectangle)) RectangleEnum Rectangle;

            virtual RectangleEnum GetRectangle() = 0;

            virtual void SetRectangle(RectangleEnum value) = 0;

            // CH: 超时退出时间 | EN: Timeout-Period to Exit
            __declspec(property(put = SetWaitingTime, get = GetWaitingTime)) int WaitingTime;

            virtual int GetWaitingTime() = 0;

            virtual void SetWaitingTime(int value) = 0;

            // CH: 高性能模式 | EN: High Performance Mode
            __declspec(property(put = SetPerfMode, get = GetPerfMode)) bool PerfMode;

            virtual bool GetPerfMode() = 0;

            virtual void SetPerfMode(bool value) = 0;

            // CH: 码行列号 | EN: Arrange Flag
            __declspec(property(put = SetArrangeFlag, get = GetArrangeFlag)) bool ArrangeFlag;

            virtual bool GetArrangeFlag() = 0;

            virtual void SetArrangeFlag(bool value) = 0;

            // CH: 行数量 | EN: Row Num
            __declspec(property(put = SetArrangeRowNum, get = GetArrangeRowNum)) int ArrangeRowNum;

            virtual int GetArrangeRowNum() = 0;

            virtual void SetArrangeRowNum(int value) = 0;

            // CH: 列数量 | EN: Column Num
            __declspec(property(put = SetArrangeColumnNum, get = GetArrangeColumnNum)) int ArrangeColumnNum;

            virtual int GetArrangeColumnNum() = 0;

            virtual void SetArrangeColumnNum(int value) = 0;

            // CH: 码等级 | EN: Code Grade
            __declspec(property(put = SetGradeFlag, get = GetGradeFlag)) bool GradeFlag;

            virtual bool GetGradeFlag() = 0;

            virtual void SetGradeFlag(bool value) = 0;

            // CH: ISO标准 | EN: ISO Standard
            __declspec(property(put = SetStandardType, get = GetStandardType)) StandardTypeEnum StandardType;

            virtual StandardTypeEnum GetStandardType() = 0;

            virtual void SetStandardType(StandardTypeEnum value) = 0;

            // CH: 镜像模式 | EN: Mirror Mode
            __declspec(property(put = SetMirror, get = GetMirror)) MirrorEnum Mirror;

            virtual MirrorEnum GetMirror() = 0;

            virtual void SetMirror(MirrorEnum value) = 0;

            // CH: 评级处理类型 | EN: Classification Type
            __declspec(property(put = SetClassificationType, get = GetClassificationType)) ClassificationTypeEnum ClassificationType;

            virtual ClassificationTypeEnum GetClassificationType() = 0;

            virtual void SetClassificationType(ClassificationTypeEnum value) = 0;

            // CH: 孔径尺寸 | EN: Aperture Size
            __declspec(property(put = SetAperture, get = GetAperture)) int Aperture;

            virtual int GetAperture() = 0;

            virtual void SetAperture(int value) = 0;

            // CH: 标准孔径 | EN: Standard Aperture
            __declspec(property(put = SetStdAperture, get = GetStdAperture)) double StdAperture;

            virtual double GetStdAperture() = 0;

            virtual void SetStdAperture(double value) = 0;

            // CH: 成像放大率 | EN: System magnification
            __declspec(property(put = SetSystemMag, get = GetSystemMag)) double SystemMag;

            virtual double GetSystemMag() = 0;

            virtual void SetSystemMag(double value) = 0;

            // CH: 评级模式 | EN: Verify Mode Type
            __declspec(property(put = SetVerifyLabelType, get = GetVerifyLabelType)) VerifyLabelTypeEnum VerifyLabelType;

            virtual VerifyLabelTypeEnum GetVerifyLabelType() = 0;

            virtual void SetVerifyLabelType(VerifyLabelTypeEnum value) = 0;

            // CH: 极性 | EN: Polarity
            __declspec(property(put = SetPolarity, get = GetPolarity)) PolarityEnum Polarity;

            virtual PolarityEnum GetPolarity() = 0;

            virtual void SetPolarity(PolarityEnum value) = 0;

            // CH: 二维码行数 | EN: 2D Code Row
            __declspec(property(put = SetSymbolRows, get = GetSymbolRows)) int SymbolRows;

            virtual int GetSymbolRows() = 0;

            virtual void SetSymbolRows(int value) = 0;

            // CH: 二维码列数 | EN: 2D Code Column
            __declspec(property(put = SetSymbolCols, get = GetSymbolCols)) int SymbolCols;

            virtual int GetSymbolCols() = 0;

            virtual void SetSymbolCols(int value) = 0;

            // CH: 边缘类型 | EN: Edge Type
            __declspec(property(put = SetEdgeFeature, get = GetEdgeFeature)) EdgeFeatureEnum EdgeFeature;

            virtual EdgeFeatureEnum GetEdgeFeature() = 0;

            virtual void SetEdgeFeature(EdgeFeatureEnum value) = 0;

            // CH: 译码评分 | EN: Decoding Score
            __declspec(property(put = SetDecodeFlag, get = GetDecodeFlag)) bool DecodeFlag;

            virtual bool GetDecodeFlag() = 0;

            virtual void SetDecodeFlag(bool value) = 0;

            // CH: 边缘确定度 | EN: Edge Certainty
            __declspec(property(put = SetEdgeDeterminationFlag, get = GetEdgeDeterminationFlag)) bool EdgeDeterminationFlag;

            virtual bool GetEdgeDeterminationFlag() = 0;

            virtual void SetEdgeDeterminationFlag(bool value) = 0;

            // CH: 符号对比度 | EN: SymbolContrast
            __declspec(property(put = SetSymbolContrastFlag, get = GetSymbolContrastFlag)) bool SymbolContrastFlag;

            virtual bool GetSymbolContrastFlag() = 0;

            virtual void SetSymbolContrastFlag(bool value) = 0;

            // CH: 最小反射率 | EN: Minimum Edge Contrast
            __declspec(property(put = SetMinReflectanceFlag, get = GetMinReflectanceFlag)) bool MinReflectanceFlag;

            virtual bool GetMinReflectanceFlag() = 0;

            virtual void SetMinReflectanceFlag(bool value) = 0;

            // CH: 边缘对比度 | EN: Edge Contrast
            __declspec(property(put = SetMinEdgeContrastFlag, get = GetMinEdgeContrastFlag)) bool MinEdgeContrastFlag;

            virtual bool GetMinEdgeContrastFlag() = 0;

            virtual void SetMinEdgeContrastFlag(bool value) = 0;

            // CH: 模块均匀性 | EN: Modulation
            __declspec(property(put = SetModulationFlag, get = GetModulationFlag)) bool ModulationFlag;

            virtual bool GetModulationFlag() = 0;

            virtual void SetModulationFlag(bool value) = 0;

            // CH: 可译码性 | EN: Decodability
            __declspec(property(put = SetDecodabilityFlag, get = GetDecodabilityFlag)) bool DecodabilityFlag;

            virtual bool GetDecodabilityFlag() = 0;

            virtual void SetDecodabilityFlag(bool value) = 0;

            // CH: 缺陷度 | EN: Defects
            __declspec(property(put = SetDefectsFlag, get = GetDefectsFlag)) bool DefectsFlag;

            virtual bool GetDefectsFlag() = 0;

            virtual void SetDefectsFlag(bool value) = 0;

            // CH: 静区 | EN: Quiet Zone
            __declspec(property(put = SetQuietZoneFlag, get = GetQuietZoneFlag)) bool QuietZoneFlag;

            virtual bool GetQuietZoneFlag() = 0;

            virtual void SetQuietZoneFlag(bool value) = 0;

            // CH: 可译码性A | EN: Decodability A
            __declspec(property(put = SetDecodabilityThrA, get = GetDecodabilityThrA)) int DecodabilityThrA;

            virtual int GetDecodabilityThrA() = 0;

            virtual void SetDecodabilityThrA(int value) = 0;

            // CH: 可译码性B | EN: Decodability B
            __declspec(property(put = SetDecodabilityThrB, get = GetDecodabilityThrB)) int DecodabilityThrB;

            virtual int GetDecodabilityThrB() = 0;

            virtual void SetDecodabilityThrB(int value) = 0;

            // CH: 可译码性C | EN: Decodability C
            __declspec(property(put = SetDecodabilityThrC, get = GetDecodabilityThrC)) int DecodabilityThrC;

            virtual int GetDecodabilityThrC() = 0;

            virtual void SetDecodabilityThrC(int value) = 0;

            // CH: 可译码性D | EN: Decodability D
            __declspec(property(put = SetDecodabilityThrD, get = GetDecodabilityThrD)) int DecodabilityThrD;

            virtual int GetDecodabilityThrD() = 0;

            virtual void SetDecodabilityThrD(int value) = 0;

            // CH: 缺陷度A | EN: Defect Degree A
            __declspec(property(put = SetDefectsThrA, get = GetDefectsThrA)) int DefectsThrA;

            virtual int GetDefectsThrA() = 0;

            virtual void SetDefectsThrA(int value) = 0;

            // CH: 缺陷度B | EN: Defect Degree B
            __declspec(property(put = SetDefectsThrB, get = GetDefectsThrB)) int DefectsThrB;

            virtual int GetDefectsThrB() = 0;

            virtual void SetDefectsThrB(int value) = 0;

            // CH: 缺陷度C | EN: Defect Degree C
            __declspec(property(put = SetDefectsThrC, get = GetDefectsThrC)) int DefectsThrC;

            virtual int GetDefectsThrC() = 0;

            virtual void SetDefectsThrC(int value) = 0;

            // CH: 缺陷度D | EN: Defect Degree D
            __declspec(property(put = SetDefectsThrD, get = GetDefectsThrD)) int DefectsThrD;

            virtual int GetDefectsThrD() = 0;

            virtual void SetDefectsThrD(int value) = 0;

            // CH: 最小反射率A | EN: Minimum Reflectivity A
            __declspec(property(put = SetMinReflectanceThrA, get = GetMinReflectanceThrA)) int MinReflectanceThrA;

            virtual int GetMinReflectanceThrA() = 0;

            virtual void SetMinReflectanceThrA(int value) = 0;

            // CH: 边缘对比度A | EN: Edge Contrast A
            __declspec(property(put = SetMinEdgeContrastThrA, get = GetMinEdgeContrastThrA)) int MinEdgeContrastThrA;

            virtual int GetMinEdgeContrastThrA() = 0;

            virtual void SetMinEdgeContrastThrA(int value) = 0;

            // CH: 模块均匀性A | EN: Module Uniformity A
            __declspec(property(put = SetModulationThrA, get = GetModulationThrA)) int ModulationThrA;

            virtual int GetModulationThrA() = 0;

            virtual void SetModulationThrA(int value) = 0;

            // CH: 模块均匀性B | EN: Module Uniformity B
            __declspec(property(put = SetModulationThrB, get = GetModulationThrB)) int ModulationThrB;

            virtual int GetModulationThrB() = 0;

            virtual void SetModulationThrB(int value) = 0;

            // CH: 模块均匀性C | EN: Module Uniformity C
            __declspec(property(put = SetModulationThrC, get = GetModulationThrC)) int ModulationThrC;

            virtual int GetModulationThrC() = 0;

            virtual void SetModulationThrC(int value) = 0;

            // CH: 模块均匀性D | EN: Module Uniformity D
            __declspec(property(put = SetModulationThrD, get = GetModulationThrD)) int ModulationThrD;

            virtual int GetModulationThrD() = 0;

            virtual void SetModulationThrD(int value) = 0;

            // CH: 对比度A | EN: Contrast A
            __declspec(property(put = SetSymbolContrastThrA, get = GetSymbolContrastThrA)) int SymbolContrastThrA;

            virtual int GetSymbolContrastThrA() = 0;

            virtual void SetSymbolContrastThrA(int value) = 0;

            // CH: 对比度B | EN: Contrast B
            __declspec(property(put = SetSymbolContrastThrB, get = GetSymbolContrastThrB)) int SymbolContrastThrB;

            virtual int GetSymbolContrastThrB() = 0;

            virtual void SetSymbolContrastThrB(int value) = 0;

            // CH: 对比度C | EN: Contrast C
            __declspec(property(put = SetSymbolContrastThrC, get = GetSymbolContrastThrC)) int SymbolContrastThrC;

            virtual int GetSymbolContrastThrC() = 0;

            virtual void SetSymbolContrastThrC(int value) = 0;

            // CH: 对比度D | EN: Contrast D
            __declspec(property(put = SetSymbolContrastThrD, get = GetSymbolContrastThrD)) int SymbolContrastThrD;

            virtual int GetSymbolContrastThrD() = 0;

            virtual void SetSymbolContrastThrD(int value) = 0;

            // CH: 孔径设置 | EN: Aperture Settings
            __declspec(property(put = SetApertureEnable, get = GetApertureEnable)) bool ApertureEnable;

            virtual bool GetApertureEnable() = 0;

            virtual void SetApertureEnable(bool value) = 0;

            // CH: 孔径尺寸 | EN: Aperture Size
            __declspec(property(put = SetApertureIn, get = GetApertureIn)) int ApertureIn;

            virtual int GetApertureIn() = 0;

            virtual void SetApertureIn(int value) = 0;

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
        /*  Note: 码信息描述类. */
        class ICodeInfo
        {
        protected:
            ///< 构造与析构函数
            explicit ICodeInfo() {}
            virtual ~ICodeInfo() {}

        public:
            /**
             * @par 说明
             * 码状态
             * @par 权限
             * 只读
             */
            virtual int GetCodeStatus() = 0;
            /**
            * @par 说明
            * 码角点信息
            * @par 权限
            * 只读
            */
            /*  Note: 码的角点信息,分别为:左上角、右上角、左下角、右下角顶点坐标. */
            virtual PointF GetCornerPoint(int nIndex) = 0;
            /**
            * @par 说明
            * 码的矩形框
            * @par 权限
            * 只读
            */
            virtual RectBox GetRect() = 0;
            /**
             * @par 说明
             * 码内容
             * @par 权限
             * 只读
             */
            virtual const char* GetContent() = 0;
            /**
             * @par 说明
             * 码类型
             * @par 权限
             * 只读
             */
            virtual int GetType() = 0;
            /**
             * @par 说明
             * 码角度
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
            /**
            * @par 说明
            * 码行号
            * @par 权限
            * 只读
            */
            virtual int GetCodeRowNum() = 0;
            /**
            * @par 说明
            * 码列号
            * @par 权限
            * 只读
            */
            virtual int GetCodeColumnNum() = 0;
        };

        /*  Note: 码等级信息描述类. */
        class ICodeGradeInfo
        {
        protected:
            ///< 构造与析构函数
            explicit ICodeGradeInfo() {}
            virtual ~ICodeGradeInfo() {}

        public:
             /**
             * @par 说明
             * 总质量等级
             * @par 权限
             * 只读
             */
             virtual int GetOverQuality() = 0;
             /**
             * @par 说明
             * 译码评分
             * @par 权限
             * 只读
             */
             virtual int GetDecode() = 0;
             /**
             * @par 说明
             * 符号对比度
             * @par 权限
             * 只读
             */
             virtual int GetSymbolContrast() = 0;
             /**
             * @par 说明
             * 模块均匀性
             * @par 权限
             * 只读
             */
             virtual int GetModulation() = 0;
             /**
             * @par 说明
             * 符号对比度分数
             * @par 权限
             * 只读
             */
             virtual float GetScScore() = 0;
             /**
             * @par 说明
             * 模块均匀性分数
             * @par 权限
             * 只读
             */
             virtual float GetModScore() = 0;
             /**
             * @par 说明
             * 固定程度
             * @par 权限
             * 只读
             */
             virtual int GetFixedPatternDamage() = 0;
             /**
             * @par 说明
             * 轴向不均匀性
             * @par 权限
             * 只读
             */
             virtual int GetAxial() = 0;
             /**
             * @par 说明
             * 网格不均匀性
             * @par 权限
             * 只读
             */
             virtual int GetGrid() = 0;
             /**
             * @par 说明
             * 未使用纠错
             * @par 权限
             * 只读
             */
             virtual int GetUnusedErrorCorrection() = 0;
             /**
             * @par 说明
             * 水平打印伸缩
             * @par 权限
             * 只读
             */
             virtual int GetPrintGrowthHor() = 0;
             /**
             * @par 说明
             * 垂直打印伸缩
             * @par 权限
             * 只读
             */
             virtual int GetPrintGrowthVer() = 0;
             /**
             * @par 说明
             * 反射率余量
             * @par 权限
             * 只读
             */
             virtual int GetRmGrade() = 0;
             /**
             * @par 说明
             * 固定程度分数
             * @par 权限
             * 只读
             */
             virtual float GetFpdScore() = 0;
             /**
             * @par 说明
             * 码轴规整性分数
             * @par 权限
             * 只读
             */
             virtual float GetAnScore() = 0;
             /**
             * @par 说明
             * 网格均匀性分数
             * @par 权限
             * 只读
             */
             virtual float GetGnScore() = 0;
             /**
             * @par 说明
             * 未使用纠错分数
             * @par 权限
             * 只读
             */
             virtual float GetUecScore() = 0;
             /**
             * @par 说明
             * 水平打印伸缩分数
             * @par 权限
             * 只读
             */
             virtual float GetPghScore() = 0;
             /**
             * @par 说明
             * 垂直打印伸缩分数
             * @par 权限
             * 只读
             */
             virtual float GetPgvScore() = 0;
             /**
             * @par 说明
             * 反射率余量分数
             * @par 权限
             * 只读
             */
             virtual float GetRmScore() = 0;
             /**
             * @par 说明
             * 边缘确定度
             * @par 权限
             * 只读
             */
             virtual int GetEdgeDetermination() = 0;
             /**
             * @par 说明
             * 最小反射率
             * @par 权限
             * 只读
             */
             virtual int GetMinReflectance() = 0;
             /**
             * @par 说明
             * 最小边缘对比度
             * @par 权限
             * 只读
             */
             virtual int GetMinEdgeContrast() = 0;
             /**
             * @par 说明
             * 可译码性
             * @par 权限
             * 只读
             */
             virtual int GetDecodability() = 0;
             /**
             * @par 说明
             * 缺陷度
             * @par 权限
             * 只读
             */
             virtual int GetDefects() = 0;
             /**
             * @par 说明
             * 静区
             * @par 权限
             * 只读
             */
             virtual int GetQuietZone() = 0;
             /**
             * @par 说明
             * 边缘确定度分数
             * @par 权限
             * 只读
             */
             virtual float GetEdgeScore() = 0;
             /**
             * @par 说明
             * 最小反射率分数
             * @par 权限
             * 只读
             */
             virtual float GetMinrScore() = 0;
             /**
             * @par 说明
             * 最小边缘对比度分数
             * @par 权限
             * 只读
             */
             virtual float GetMineScore() = 0;
             /**
             * @par 说明
             * 可译码性分数
             * @par 权限
             * 只读
             */
             virtual float GetDcdScore() = 0;
             /**
             * @par 说明
             * 缺陷分数
             * @par 权限
             * 只读
             */
             virtual float GetDefScore() = 0;
             /**
             * @par 说明
             * 静区分数
             * @par 权限
             * 只读
             */
             virtual float GetQzScore() = 0;

        };

        /*  Note: Interface Classes of the result of the CnnCodeRecgResults.  */
        class CnnCodeRecgResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnCodeRecgResults() {}
            virtual ~CnnCodeRecgResults() {}

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
             * 码个数
             * @par 权限
             * 只读
             */
            virtual int GetCodeNum() = 0;

            /**
             * @brief 获取码信息
             * @param nIndex [in] 码信息索引
             * @return 返回码信息
             * @par 注解
             * nIndex从0开始计数。
             */
            virtual ICodeInfo* GetCodeInfo(int nIndex) = 0;

            /**
             * @par 说明
             * 码等级数量
             * @par 权限
             * 只读
             */
            virtual int GetCodeGradeNum() = 0;

            /**
             * @brief 获取码等级信息
             * @param nIndex [in] 码等级信息索引
             * @return 返回码等级信息
             * @par 注解
             * nIndex从0开始计数。
             */
            virtual ICodeGradeInfo* GetCodeGradeInfo(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CnnCodeRecg tool.  */
        class IMVSCnnCodeRecgModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCnnCodeRecgModuTool() {}
            virtual ~IMVSCnnCodeRecgModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CnnCodeRecgParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CnnCodeRecgResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCnnCodeRecgModuTool(IMVSCnnCodeRecgModuTool&);
            IMVSCnnCodeRecgModuTool& operator=(IMVSCnnCodeRecgModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CnnCodeRecg.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCnnCodeRecgModu::IMVSCnnCodeRecgModuTool * __stdcall GetCnnCodeRecgToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CNNCODERECG_H_
