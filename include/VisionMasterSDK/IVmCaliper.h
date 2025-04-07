/***************************************************************************************************
 * File：IVmCaliper.h
 * Note：CH: 卡尺工具模块接口声明 | En: Interface for the Caliper tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CALIPER_H_
#define _IVM_CALIPER_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSCaliperModu
    {        /*************************** Params Class Start ***************************/
        // CH: 边缘模式 | EN: Edge Mode
        typedef enum _EdgeModeEnum
        {
            // CH: 单边缘 | EN: Single Edge
            EdgeMode_SINGLE_EDGE = 0x1,

            // CH: 边缘对 | EN: Edge Pair
            EdgeMode_EDGE_PAIR = 0x2,

        }EdgeModeEnum;

        // CH: 边缘0极性 | EN: Edge 0 polarity
        typedef enum _EdgePolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            EdgePolarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            EdgePolarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            EdgePolarity_Both = 0x3,

        }EdgePolarityEnum;

        // CH: 边缘1极性 | EN: Edge 1 polarity
        typedef enum _Edge1PolarityEnum
        {
            // CH: 从黑到白 | EN: Dark to Light
            Edge1Polarity_BlackToWhite = 0x1,

            // CH: 从白到黑 | EN: Light to Dark
            Edge1Polarity_WhiteToBlack = 0x2,

            // CH: 任意极性 | EN: Both
            Edge1Polarity_Both = 0x3,

        }Edge1PolarityEnum;

        // CH: 排序方式 | EN: Sort Type
        typedef enum _SortTypeEnum
        {
            // CH: 分数降序 | EN: Score Descend
            SortType_ScoreDescend = 0x0,

            // CH: 分数升序 | EN: Score Ascend
            SortType_ScoreAscend = 0x1,

            // CH: 方向正向 | EN: Orient Forward
            SortType_OrientForward = 0x2,

            // CH: 方向逆向 | EN: Orient Backward
            SortType_OrientBackward = 0x3,

        }SortTypeEnum;

        // CH: 曲线类型1 | EN: Scoring1 Function
        typedef enum _ContrastDropEnum
        {
            // CH: 递增 | EN: Ascending
            ContrastDrop_Rise = 0x0,

            // CH: 递减 | EN: Descending
            ContrastDrop_Drop = 0x1,

        }ContrastDropEnum;

        // CH: 曲线类型2 | EN: Scoring2 Function
        typedef enum _GrayscaleDropEnum
        {
            // CH: 递增 | EN: Ascending
            GrayscaleDrop_Rise = 0x0,

            // CH: 递减 | EN: Descending
            GrayscaleDrop_Drop = 0x1,

        }GrayscaleDropEnum;

        // CH: 曲线类型3 | EN: Scoring3 Function
        typedef enum _PositionDropEnum
        {
            // CH: 递增 | EN: Ascending
            PositionDrop_Rise = 0x0,

            // CH: 递减 | EN: Descending
            PositionDrop_Drop = 0x1,

        }PositionDropEnum;

        // CH: 曲线类型4 | EN: Scoring4 Function
        typedef enum _PositionNegDropEnum
        {
            // CH: 递增 | EN: Ascending
            PositionNegDrop_Rise = 0x0,

            // CH: 递减 | EN: Descending
            PositionNegDrop_Drop = 0x1,

        }PositionNegDropEnum;

        // CH: 曲线类型 | EN: Scoring Function
        typedef enum _PositionNormDropEnum
        {
            // CH: 递增 | EN: Ascending
            PositionNormDrop_Rise = 0x0,

            // CH: 递减 | EN: Descending
            PositionNormDrop_Drop = 0x1,

        }PositionNormDropEnum;

        // CH: 曲线类型 | EN: Scoring Function
        typedef enum _PositionNormNegDropEnum
        {
            // CH: 递增 | EN: Ascending
            PositionNormNegDrop_Rise = 0x0,

            // CH: 递减 | EN: Descending
            PositionNormNegDrop_Drop = 0x1,

        }PositionNormNegDropEnum;

        // CH: 曲线类型 | EN: Scoring Function
        typedef enum _SizeNormDropEnum
        {
            // CH: 递增 | EN: Ascending
            SizeNormDrop_Rise = 0x0,

            // CH: 递减 | EN: Descending
            SizeNormDrop_Drop = 0x1,

        }SizeNormDropEnum;

        // CH: 曲线类型 | EN: Scoring Function
        typedef enum _SizeDiffNormDropEnum
        {
            // CH: 递增 | EN: Ascending
            SizeDiffNormDrop_Rise = 0x0,

            // CH: 递减 | EN: Descending
            SizeDiffNormDrop_Drop = 0x1,

        }SizeDiffNormDropEnum;

        // CH: 左曲线类型 | EN: Left Scoring Function
        typedef enum _SizeDiffNormAsymDropEnum
        {
            // CH: 递增 | EN: Ascending
            SizeDiffNormAsymDrop_Rise = 0x0,

            // CH: 递减 | EN: Descending
            SizeDiffNormAsymDrop_Drop = 0x1,

        }SizeDiffNormAsymDropEnum;

        // CH: 右曲线类型 | EN: Right Scoring Function
        typedef enum _SizeDiffNormAsymDropHEnum
        {
            // CH: 递增 | EN: Ascending
            SizeDiffNormAsymDropH_Rise = 0x0,

            // CH: 递减 | EN: Descending
            SizeDiffNormAsymDropH_Drop = 0x1,

        }SizeDiffNormAsymDropHEnum;

        // CH: 投影方向 | EN: Projection Direction
        typedef enum _ProjectionTypeEnum
        {
            // CH: 从左到右 | EN: Left to Right
            ProjectionType_ProjectionToHeight = 0x0,

            // CH: 从上到下 | EN: Top to Bottom
            ProjectionType_ProjectionToWidth = 0x1,

        }ProjectionTypeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class CaliperRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the CaliperParams.  */
        class CaliperParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CaliperParams() {}
            virtual ~CaliperParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual CaliperRoiManager* GetModuRoiManager() = 0;

            // CH: 边缘模式 | EN: Edge Mode
            __declspec(property(put = SetEdgeMode, get = GetEdgeMode)) EdgeModeEnum EdgeMode;

            virtual EdgeModeEnum GetEdgeMode() = 0;

            virtual void SetEdgeMode(EdgeModeEnum value) = 0;

            // CH: 滤波尺寸 | EN: Filter Size
            __declspec(property(put = SetHalfKernelSize, get = GetHalfKernelSize)) int HalfKernelSize;

            virtual int GetHalfKernelSize() = 0;

            virtual void SetHalfKernelSize(int value) = 0;

            // CH: 边缘阈值 | EN: Edge Threshold
            __declspec(property(put = SetContrastTH, get = GetContrastTH)) int ContrastTH;

            virtual int GetContrastTH() = 0;

            virtual void SetContrastTH(int value) = 0;

            // CH: 边缘0极性 | EN: Edge 0 polarity
            __declspec(property(put = SetEdgePolarity, get = GetEdgePolarity)) EdgePolarityEnum EdgePolarity;

            virtual EdgePolarityEnum GetEdgePolarity() = 0;

            virtual void SetEdgePolarity(EdgePolarityEnum value) = 0;

            // CH: 边缘1极性 | EN: Edge 1 polarity
            __declspec(property(put = SetEdge1Polarity, get = GetEdge1Polarity)) Edge1PolarityEnum Edge1Polarity;

            virtual Edge1PolarityEnum GetEdge1Polarity() = 0;

            virtual void SetEdge1Polarity(Edge1PolarityEnum value) = 0;

            // CH: 边缘对宽度 | EN: EdgePairWidth
            __declspec(property(put = SetEdgePairWidth, get = GetEdgePairWidth)) int EdgePairWidth;

            virtual int GetEdgePairWidth() = 0;

            virtual void SetEdgePairWidth(int value) = 0;

            // CH: 最大结果数 | EN: Max Result Number
            __declspec(property(put = SetMaximum, get = GetMaximum)) int Maximum;

            virtual int GetMaximum() = 0;

            virtual void SetMaximum(int value) = 0;

            // CH: 排序方式 | EN: Sort Type
            __declspec(property(put = SetSortType, get = GetSortType)) SortTypeEnum SortType;

            virtual SortTypeEnum GetSortType() = 0;

            virtual void SetSortType(SortTypeEnum value) = 0;

            // CH: 对比度 | EN: HistContrast
            __declspec(property(put = SetContrastEnable, get = GetContrastEnable)) bool ContrastEnable;

            virtual bool GetContrastEnable() = 0;

            virtual void SetContrastEnable(bool value) = 0;

            // CH: 边缘对对比度 | EN: Edge Pair Contrast
            __declspec(property(put = SetContrastPairEnable, get = GetContrastPairEnable)) bool ContrastPairEnable;

            virtual bool GetContrastPairEnable() = 0;

            virtual void SetContrastPairEnable(bool value) = 0;

            // CH: 曲线类型1 | EN: Scoring1 Function
            __declspec(property(put = SetContrastDrop, get = GetContrastDrop)) ContrastDropEnum ContrastDrop;

            virtual ContrastDropEnum GetContrastDrop() = 0;

            virtual void SetContrastDrop(ContrastDropEnum value) = 0;

            // CH: 起点 | EN: Startpoint
            __declspec(property(put = SetContrastX0, get = GetContrastX0)) int ContrastX0;

            virtual int GetContrastX0() = 0;

            virtual void SetContrastX0(int value) = 0;

            // CH: X中点 | EN: Midpoint
            __declspec(property(put = SetContrastX1, get = GetContrastX1)) int ContrastX1;

            virtual int GetContrastX1() = 0;

            virtual void SetContrastX1(int value) = 0;

            // CH: 终点 | EN: Endpoint
            __declspec(property(put = SetContrastXC, get = GetContrastXC)) int ContrastXC;

            virtual int GetContrastXC() = 0;

            virtual void SetContrastXC(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetContrastY0, get = GetContrastY0)) int ContrastY0;

            virtual int GetContrastY0() = 0;

            virtual void SetContrastY0(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetContrastY1, get = GetContrastY1)) int ContrastY1;

            virtual int GetContrastY1() = 0;

            virtual void SetContrastY1(int value) = 0;

            // CH: 灰度 | EN: Grayscale
            __declspec(property(put = SetGrayscaleEnable, get = GetGrayscaleEnable)) bool GrayscaleEnable;

            virtual bool GetGrayscaleEnable() = 0;

            virtual void SetGrayscaleEnable(bool value) = 0;

            // CH: 曲线类型2 | EN: Scoring2 Function
            __declspec(property(put = SetGrayscaleDrop, get = GetGrayscaleDrop)) GrayscaleDropEnum GrayscaleDrop;

            virtual GrayscaleDropEnum GetGrayscaleDrop() = 0;

            virtual void SetGrayscaleDrop(GrayscaleDropEnum value) = 0;

            // CH: 起点 | EN: Startpoint
            __declspec(property(put = SetGrayscaleX0, get = GetGrayscaleX0)) int GrayscaleX0;

            virtual int GetGrayscaleX0() = 0;

            virtual void SetGrayscaleX0(int value) = 0;

            // CH: X中点 | EN: Midpoint
            __declspec(property(put = SetGrayscaleX1, get = GetGrayscaleX1)) int GrayscaleX1;

            virtual int GetGrayscaleX1() = 0;

            virtual void SetGrayscaleX1(int value) = 0;

            // CH: 终点 | EN: Endpoint
            __declspec(property(put = SetGrayscaleXC, get = GetGrayscaleXC)) int GrayscaleXC;

            virtual int GetGrayscaleXC() = 0;

            virtual void SetGrayscaleXC(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetGrayscaleY0, get = GetGrayscaleY0)) int GrayscaleY0;

            virtual int GetGrayscaleY0() = 0;

            virtual void SetGrayscaleY0(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetGrayscaleY1, get = GetGrayscaleY1)) int GrayscaleY1;

            virtual int GetGrayscaleY1() = 0;

            virtual void SetGrayscaleY1(int value) = 0;

            // CH: 位置 | EN: Position
            __declspec(property(put = SetPositionEnable, get = GetPositionEnable)) bool PositionEnable;

            virtual bool GetPositionEnable() = 0;

            virtual void SetPositionEnable(bool value) = 0;

            // CH: 曲线类型3 | EN: Scoring3 Function
            __declspec(property(put = SetPositionDrop, get = GetPositionDrop)) PositionDropEnum PositionDrop;

            virtual PositionDropEnum GetPositionDrop() = 0;

            virtual void SetPositionDrop(PositionDropEnum value) = 0;

            // CH: 起点 | EN: Startpoint
            __declspec(property(put = SetPositionX0, get = GetPositionX0)) int PositionX0;

            virtual int GetPositionX0() = 0;

            virtual void SetPositionX0(int value) = 0;

            // CH: X中点 | EN: Midpoint
            __declspec(property(put = SetPositionX1, get = GetPositionX1)) int PositionX1;

            virtual int GetPositionX1() = 0;

            virtual void SetPositionX1(int value) = 0;

            // CH: 终点 | EN: Endpoint
            __declspec(property(put = SetPositionXC, get = GetPositionXC)) int PositionXC;

            virtual int GetPositionXC() = 0;

            virtual void SetPositionXC(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetPositionY0, get = GetPositionY0)) int PositionY0;

            virtual int GetPositionY0() = 0;

            virtual void SetPositionY0(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetPositionY1, get = GetPositionY1)) int PositionY1;

            virtual int GetPositionY1() = 0;

            virtual void SetPositionY1(int value) = 0;

            // CH: 相对位置 | EN: Relative Position
            __declspec(property(put = SetPositionNegEnable, get = GetPositionNegEnable)) bool PositionNegEnable;

            virtual bool GetPositionNegEnable() = 0;

            virtual void SetPositionNegEnable(bool value) = 0;

            // CH: 曲线类型4 | EN: Scoring4 Function
            __declspec(property(put = SetPositionNegDrop, get = GetPositionNegDrop)) PositionNegDropEnum PositionNegDrop;

            virtual PositionNegDropEnum GetPositionNegDrop() = 0;

            virtual void SetPositionNegDrop(PositionNegDropEnum value) = 0;

            // CH: 起点 | EN: Startpoint
            __declspec(property(put = SetPositionNegX0, get = GetPositionNegX0)) int PositionNegX0;

            virtual int GetPositionNegX0() = 0;

            virtual void SetPositionNegX0(int value) = 0;

            // CH: X中点 | EN: Midpoint
            __declspec(property(put = SetPositionNegX1, get = GetPositionNegX1)) int PositionNegX1;

            virtual int GetPositionNegX1() = 0;

            virtual void SetPositionNegX1(int value) = 0;

            // CH: 终点 | EN: Endpoint
            __declspec(property(put = SetPositionNegXC, get = GetPositionNegXC)) int PositionNegXC;

            virtual int GetPositionNegXC() = 0;

            virtual void SetPositionNegXC(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetPositionNegY0, get = GetPositionNegY0)) int PositionNegY0;

            virtual int GetPositionNegY0() = 0;

            virtual void SetPositionNegY0(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetPositionNegY1, get = GetPositionNegY1)) int PositionNegY1;

            virtual int GetPositionNegY1() = 0;

            virtual void SetPositionNegY1(int value) = 0;

            // CH: 归一位置 | EN: Normalized Position
            __declspec(property(put = SetPositionNormEnable, get = GetPositionNormEnable)) bool PositionNormEnable;

            virtual bool GetPositionNormEnable() = 0;

            virtual void SetPositionNormEnable(bool value) = 0;

            // CH: 曲线类型 | EN: Scoring Function
            __declspec(property(put = SetPositionNormDrop, get = GetPositionNormDrop)) PositionNormDropEnum PositionNormDrop;

            virtual PositionNormDropEnum GetPositionNormDrop() = 0;

            virtual void SetPositionNormDrop(PositionNormDropEnum value) = 0;

            // CH: 起点 | EN: Startpoint
            __declspec(property(put = SetPositionNormX0, get = GetPositionNormX0)) int PositionNormX0;

            virtual int GetPositionNormX0() = 0;

            virtual void SetPositionNormX0(int value) = 0;

            // CH: X中点 | EN: Midpoint
            __declspec(property(put = SetPositionNormX1, get = GetPositionNormX1)) int PositionNormX1;

            virtual int GetPositionNormX1() = 0;

            virtual void SetPositionNormX1(int value) = 0;

            // CH: 终点 | EN: Endpoint
            __declspec(property(put = SetPositionNormXC, get = GetPositionNormXC)) int PositionNormXC;

            virtual int GetPositionNormXC() = 0;

            virtual void SetPositionNormXC(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetPositionNormY0, get = GetPositionNormY0)) int PositionNormY0;

            virtual int GetPositionNormY0() = 0;

            virtual void SetPositionNormY0(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetPositionNormY1, get = GetPositionNormY1)) int PositionNormY1;

            virtual int GetPositionNormY1() = 0;

            virtual void SetPositionNormY1(int value) = 0;

            // CH: 归一相对位置 | EN: Normalized Relative Pos.
            __declspec(property(put = SetPositionNormNegEnable, get = GetPositionNormNegEnable)) bool PositionNormNegEnable;

            virtual bool GetPositionNormNegEnable() = 0;

            virtual void SetPositionNormNegEnable(bool value) = 0;

            // CH: 曲线类型 | EN: Scoring Function
            __declspec(property(put = SetPositionNormNegDrop, get = GetPositionNormNegDrop)) PositionNormNegDropEnum PositionNormNegDrop;

            virtual PositionNormNegDropEnum GetPositionNormNegDrop() = 0;

            virtual void SetPositionNormNegDrop(PositionNormNegDropEnum value) = 0;

            // CH: 起点 | EN: Startpoint
            __declspec(property(put = SetPositionNormNegX0, get = GetPositionNormNegX0)) int PositionNormNegX0;

            virtual int GetPositionNormNegX0() = 0;

            virtual void SetPositionNormNegX0(int value) = 0;

            // CH: X中点 | EN: Midpoint
            __declspec(property(put = SetPositionNormNegX1, get = GetPositionNormNegX1)) int PositionNormNegX1;

            virtual int GetPositionNormNegX1() = 0;

            virtual void SetPositionNormNegX1(int value) = 0;

            // CH: 终点 | EN: Endpoint
            __declspec(property(put = SetPositionNormNegXC, get = GetPositionNormNegXC)) int PositionNormNegXC;

            virtual int GetPositionNormNegXC() = 0;

            virtual void SetPositionNormNegXC(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetPositionNormNegY0, get = GetPositionNormNegY0)) int PositionNormNegY0;

            virtual int GetPositionNormNegY0() = 0;

            virtual void SetPositionNormNegY0(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetPositionNormNegY1, get = GetPositionNormNegY1)) int PositionNormNegY1;

            virtual int GetPositionNormNegY1() = 0;

            virtual void SetPositionNormNegY1(int value) = 0;

            // CH: 间距 | EN: Interval
            __declspec(property(put = SetSizeNormEnable, get = GetSizeNormEnable)) bool SizeNormEnable;

            virtual bool GetSizeNormEnable() = 0;

            virtual void SetSizeNormEnable(bool value) = 0;

            // CH: 曲线类型 | EN: Scoring Function
            __declspec(property(put = SetSizeNormDrop, get = GetSizeNormDrop)) SizeNormDropEnum SizeNormDrop;

            virtual SizeNormDropEnum GetSizeNormDrop() = 0;

            virtual void SetSizeNormDrop(SizeNormDropEnum value) = 0;

            // CH: 起点 | EN: Startpoint
            __declspec(property(put = SetSizeNormX0, get = GetSizeNormX0)) int SizeNormX0;

            virtual int GetSizeNormX0() = 0;

            virtual void SetSizeNormX0(int value) = 0;

            // CH: X中点 | EN: Midpoint
            __declspec(property(put = SetSizeNormX1, get = GetSizeNormX1)) int SizeNormX1;

            virtual int GetSizeNormX1() = 0;

            virtual void SetSizeNormX1(int value) = 0;

            // CH: 终点 | EN: Endpoint
            __declspec(property(put = SetSizeNormXC, get = GetSizeNormXC)) int SizeNormXC;

            virtual int GetSizeNormXC() = 0;

            virtual void SetSizeNormXC(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetSizeNormY0, get = GetSizeNormY0)) int SizeNormY0;

            virtual int GetSizeNormY0() = 0;

            virtual void SetSizeNormY0(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetSizeNormY1, get = GetSizeNormY1)) int SizeNormY1;

            virtual int GetSizeNormY1() = 0;

            virtual void SetSizeNormY1(int value) = 0;

            // CH: 间距差 | EN: Interval Difference
            __declspec(property(put = SetSizeDiffNormEnable, get = GetSizeDiffNormEnable)) bool SizeDiffNormEnable;

            virtual bool GetSizeDiffNormEnable() = 0;

            virtual void SetSizeDiffNormEnable(bool value) = 0;

            // CH: 曲线类型 | EN: Scoring Function
            __declspec(property(put = SetSizeDiffNormDrop, get = GetSizeDiffNormDrop)) SizeDiffNormDropEnum SizeDiffNormDrop;

            virtual SizeDiffNormDropEnum GetSizeDiffNormDrop() = 0;

            virtual void SetSizeDiffNormDrop(SizeDiffNormDropEnum value) = 0;

            // CH: 起点 | EN: Startpoint
            __declspec(property(put = SetSizeDiffNormX0, get = GetSizeDiffNormX0)) int SizeDiffNormX0;

            virtual int GetSizeDiffNormX0() = 0;

            virtual void SetSizeDiffNormX0(int value) = 0;

            // CH: X中点 | EN: Midpoint
            __declspec(property(put = SetSizeDiffNormX1, get = GetSizeDiffNormX1)) int SizeDiffNormX1;

            virtual int GetSizeDiffNormX1() = 0;

            virtual void SetSizeDiffNormX1(int value) = 0;

            // CH: 终点 | EN: Endpoint
            __declspec(property(put = SetSizeDiffNormXC, get = GetSizeDiffNormXC)) int SizeDiffNormXC;

            virtual int GetSizeDiffNormXC() = 0;

            virtual void SetSizeDiffNormXC(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetSizeDiffNormY0, get = GetSizeDiffNormY0)) int SizeDiffNormY0;

            virtual int GetSizeDiffNormY0() = 0;

            virtual void SetSizeDiffNormY0(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetSizeDiffNormY1, get = GetSizeDiffNormY1)) int SizeDiffNormY1;

            virtual int GetSizeDiffNormY1() = 0;

            virtual void SetSizeDiffNormY1(int value) = 0;

            // CH: 相对间距差 | EN: Relative Interval Diff.
            __declspec(property(put = SetSizeDiffNormAsymEnable, get = GetSizeDiffNormAsymEnable)) bool SizeDiffNormAsymEnable;

            virtual bool GetSizeDiffNormAsymEnable() = 0;

            virtual void SetSizeDiffNormAsymEnable(bool value) = 0;

            // CH: 左曲线类型 | EN: Left Scoring Function
            __declspec(property(put = SetSizeDiffNormAsymDrop, get = GetSizeDiffNormAsymDrop)) SizeDiffNormAsymDropEnum SizeDiffNormAsymDrop;

            virtual SizeDiffNormAsymDropEnum GetSizeDiffNormAsymDrop() = 0;

            virtual void SetSizeDiffNormAsymDrop(SizeDiffNormAsymDropEnum value) = 0;

            // CH: 起点 | EN: Startpoint
            __declspec(property(put = SetSizeDiffNormAsymX0, get = GetSizeDiffNormAsymX0)) int SizeDiffNormAsymX0;

            virtual int GetSizeDiffNormAsymX0() = 0;

            virtual void SetSizeDiffNormAsymX0(int value) = 0;

            // CH: X中点 | EN: Midpoint
            __declspec(property(put = SetSizeDiffNormAsymX1, get = GetSizeDiffNormAsymX1)) int SizeDiffNormAsymX1;

            virtual int GetSizeDiffNormAsymX1() = 0;

            virtual void SetSizeDiffNormAsymX1(int value) = 0;

            // CH: 终点 | EN: Endpoint
            __declspec(property(put = SetSizeDiffNormAsymXC, get = GetSizeDiffNormAsymXC)) int SizeDiffNormAsymXC;

            virtual int GetSizeDiffNormAsymXC() = 0;

            virtual void SetSizeDiffNormAsymXC(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetSizeDiffNormAsymY0, get = GetSizeDiffNormAsymY0)) int SizeDiffNormAsymY0;

            virtual int GetSizeDiffNormAsymY0() = 0;

            virtual void SetSizeDiffNormAsymY0(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetSizeDiffNormAsymY1, get = GetSizeDiffNormAsymY1)) int SizeDiffNormAsymY1;

            virtual int GetSizeDiffNormAsymY1() = 0;

            virtual void SetSizeDiffNormAsymY1(int value) = 0;

            // CH: 右曲线类型 | EN: Right Scoring Function
            __declspec(property(put = SetSizeDiffNormAsymDropH, get = GetSizeDiffNormAsymDropH)) SizeDiffNormAsymDropHEnum SizeDiffNormAsymDropH;

            virtual SizeDiffNormAsymDropHEnum GetSizeDiffNormAsymDropH() = 0;

            virtual void SetSizeDiffNormAsymDropH(SizeDiffNormAsymDropHEnum value) = 0;

            // CH: 起点 | EN: Startpoint
            __declspec(property(put = SetSizeDiffNormAsymX0H, get = GetSizeDiffNormAsymX0H)) int SizeDiffNormAsymX0H;

            virtual int GetSizeDiffNormAsymX0H() = 0;

            virtual void SetSizeDiffNormAsymX0H(int value) = 0;

            // CH: X中点 | EN: Midpoint
            __declspec(property(put = SetSizeDiffNormAsymX1H, get = GetSizeDiffNormAsymX1H)) int SizeDiffNormAsymX1H;

            virtual int GetSizeDiffNormAsymX1H() = 0;

            virtual void SetSizeDiffNormAsymX1H(int value) = 0;

            // CH: 终点 | EN: Endpoint
            __declspec(property(put = SetSizeDiffNormAsymXCH, get = GetSizeDiffNormAsymXCH)) int SizeDiffNormAsymXCH;

            virtual int GetSizeDiffNormAsymXCH() = 0;

            virtual void SetSizeDiffNormAsymXCH(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetSizeDiffNormAsymY0H, get = GetSizeDiffNormAsymY0H)) int SizeDiffNormAsymY0H;

            virtual int GetSizeDiffNormAsymY0H() = 0;

            virtual void SetSizeDiffNormAsymY0H(int value) = 0;

            // CH: Y计分 | EN: Scoring
            __declspec(property(put = SetSizeDiffNormAsymY1H, get = GetSizeDiffNormAsymY1H)) int SizeDiffNormAsymY1H;

            virtual int GetSizeDiffNormAsymY1H() = 0;

            virtual void SetSizeDiffNormAsymY1H(int value) = 0;

            // CH: 投影方向 | EN: Projection Direction
            __declspec(property(put = SetProjectionType, get = GetProjectionType)) ProjectionTypeEnum ProjectionType;

            virtual ProjectionTypeEnum GetProjectionType() = 0;

            virtual void SetProjectionType(ProjectionTypeEnum value) = 0;

            // CH: 模糊边缘 | EN: Fuzzy Edge
            __declspec(property(put = SetFuzzyedgeFlag, get = GetFuzzyedgeFlag)) bool FuzzyedgeFlag;

            virtual bool GetFuzzyedgeFlag() = 0;

            virtual void SetFuzzyedgeFlag(bool value) = 0;

            // CH: 数量判断 | EN: Quantity Check
            __declspec(property(put = SetNumLimitEnable, get = GetNumLimitEnable)) bool NumLimitEnable;

            virtual bool GetNumLimitEnable() = 0;

            virtual void SetNumLimitEnable(bool value) = 0;

            // CH: 数量范围 | EN: Quantity Range
            __declspec(property(put = SetNumLimitLow, get = GetNumLimitLow)) int NumLimitLow;

            virtual int GetNumLimitLow() = 0;

            virtual void SetNumLimitLow(int value) = 0;

            // CH: 数量范围 | EN: Quantity Range
            __declspec(property(put = SetNumLimitHigh, get = GetNumLimitHigh)) int NumLimitHigh;

            virtual int GetNumLimitHigh() = 0;

            virtual void SetNumLimitHigh(int value) = 0;

            // CH: 宽度判断 | EN: Width Check
            __declspec(property(put = SetEdgeWidthLimitEnable, get = GetEdgeWidthLimitEnable)) bool EdgeWidthLimitEnable;

            virtual bool GetEdgeWidthLimitEnable() = 0;

            virtual void SetEdgeWidthLimitEnable(bool value) = 0;

            // CH: 宽度范围 | EN: Width Range
            __declspec(property(put = SetEdgeWidthLimitLow, get = GetEdgeWidthLimitLow)) double EdgeWidthLimitLow;

            virtual double GetEdgeWidthLimitLow() = 0;

            virtual void SetEdgeWidthLimitLow(double value) = 0;

            // CH: 宽度范围 | EN: Width Range
            __declspec(property(put = SetEdgeWidthLimitHigh, get = GetEdgeWidthLimitHigh)) double EdgeWidthLimitHigh;

            virtual double GetEdgeWidthLimitHigh() = 0;

            virtual void SetEdgeWidthLimitHigh(double value) = 0;

            // CH: 边缘点0X判断 | EN: Edge Point 0X Check
            __declspec(property(put = SetEdge0PointXLimitEnable, get = GetEdge0PointXLimitEnable)) bool Edge0PointXLimitEnable;

            virtual bool GetEdge0PointXLimitEnable() = 0;

            virtual void SetEdge0PointXLimitEnable(bool value) = 0;

            // CH: 边缘点0X范围 | EN: Edge Point 0X Range
            __declspec(property(put = SetEdge0PointXLimitLow, get = GetEdge0PointXLimitLow)) double Edge0PointXLimitLow;

            virtual double GetEdge0PointXLimitLow() = 0;

            virtual void SetEdge0PointXLimitLow(double value) = 0;

            // CH: 边缘点0X范围 | EN: Edge Point 0X Range
            __declspec(property(put = SetEdge0PointXLimitHigh, get = GetEdge0PointXLimitHigh)) double Edge0PointXLimitHigh;

            virtual double GetEdge0PointXLimitHigh() = 0;

            virtual void SetEdge0PointXLimitHigh(double value) = 0;

            // CH: 边缘点0Y判断 | EN: Edge Point 0Y Check
            __declspec(property(put = SetEdge0PointYLimitEnable, get = GetEdge0PointYLimitEnable)) bool Edge0PointYLimitEnable;

            virtual bool GetEdge0PointYLimitEnable() = 0;

            virtual void SetEdge0PointYLimitEnable(bool value) = 0;

            // CH: 边缘点0Y范围 | EN: Edge Point 0Y Range
            __declspec(property(put = SetEdge0PointYLimitLow, get = GetEdge0PointYLimitLow)) double Edge0PointYLimitLow;

            virtual double GetEdge0PointYLimitLow() = 0;

            virtual void SetEdge0PointYLimitLow(double value) = 0;

            // CH: 边缘点0Y范围 | EN: Edge Point 0Y Range
            __declspec(property(put = SetEdge0PointYLimitHigh, get = GetEdge0PointYLimitHigh)) double Edge0PointYLimitHigh;

            virtual double GetEdge0PointYLimitHigh() = 0;

            virtual void SetEdge0PointYLimitHigh(double value) = 0;

            // CH: 边缘点1X判断 | EN: Edge Point 1X Check
            __declspec(property(put = SetEdge1PointXLimitEnable, get = GetEdge1PointXLimitEnable)) bool Edge1PointXLimitEnable;

            virtual bool GetEdge1PointXLimitEnable() = 0;

            virtual void SetEdge1PointXLimitEnable(bool value) = 0;

            // CH: 边缘点1X范围 | EN: Edge Point 1X Range
            __declspec(property(put = SetEdge1PointXLimitLow, get = GetEdge1PointXLimitLow)) double Edge1PointXLimitLow;

            virtual double GetEdge1PointXLimitLow() = 0;

            virtual void SetEdge1PointXLimitLow(double value) = 0;

            // CH: 边缘点1X范围 | EN: Edge Point 1X Range
            __declspec(property(put = SetEdge1PointXLimitHigh, get = GetEdge1PointXLimitHigh)) double Edge1PointXLimitHigh;

            virtual double GetEdge1PointXLimitHigh() = 0;

            virtual void SetEdge1PointXLimitHigh(double value) = 0;

            // CH: 边缘点1Y判断 | EN: Edge Point 1Y Check
            __declspec(property(put = SetEdge1PointYLimitEnable, get = GetEdge1PointYLimitEnable)) bool Edge1PointYLimitEnable;

            virtual bool GetEdge1PointYLimitEnable() = 0;

            virtual void SetEdge1PointYLimitEnable(bool value) = 0;

            // CH: 边缘点1Y范围 | EN: Edge Point 1Y Range
            __declspec(property(put = SetEdge1PointYLimitLow, get = GetEdge1PointYLimitLow)) double Edge1PointYLimitLow;

            virtual double GetEdge1PointYLimitLow() = 0;

            virtual void SetEdge1PointYLimitLow(double value) = 0;

            // CH: 边缘点1Y范围 | EN: Edge Point 1Y Range
            __declspec(property(put = SetEdge1PointYLimitHigh, get = GetEdge1PointYLimitHigh)) double Edge1PointYLimitHigh;

            virtual double GetEdge1PointYLimitHigh() = 0;

            virtual void SetEdge1PointYLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /** @enum  MVD_EDGEPOINT_STATUS
        *  @brief Type of the polarity of the edge point
        */
        typedef _MVD_EDGE_POLARITY__ MVD_EDGE_POLARITY;
        
        /*  Note: Interface Classes for describing single edge Information.  */
        class ICaliperSingleEdgeInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit ICaliperSingleEdgeInfo() {}
            virtual ~ICaliperSingleEdgeInfo() {}

        public:
            ///< Properties
            /**
             * @par 说明
             * 边缘点坐标
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetEdgePoint() = 0;
            /**
             * @par 说明
             * 边线相对box中心线相对距离（可正可负）
             * @par 权限
             * 只读
             */
            virtual float GetBias() = 0;
            /**
             * @par 说明
             * 分数
             * @par 权限
             * 只读
             */
            virtual float GetScore() = 0;
            /**
             * @par 说明
             * 边缘极性
             * @par 权限
             * 只读
             */
            virtual MVD_EDGE_POLARITY GetPolarity() = 0;
        };

        class ICaliperEdge
        {
        protected:
            ///< Constructor and Destructor
            explicit ICaliperEdge() {}
            virtual ~ICaliperEdge() {}

        public:
            ///< Properties
            /**
             * @par 说明
             * 边缘点坐标
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetEdgePoint() = 0;
            /**
             * @par 说明
             * 
             * @par 权限
             * 只读
             */
            virtual float GetBias() = 0;
            /**
             * @par 说明
             * 边缘极性
             * @par 权限
             * 只读
             */
            virtual MVD_EDGE_POLARITY GetPolarity() = 0;
        };

        class ICaliperEdgePairInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit ICaliperEdgePairInfo() {}
            virtual ~ICaliperEdgePairInfo() {}

        public:
            ///< Properties
            /**
             * @par 说明
             * 边缘0信息
             * @par 权限
             * 只读
             */
            virtual ICaliperEdge* GetEdge0Info() = 0;
            /**
             * @par 说明
             * 边缘1信息
             * @par 权限
             * 只读
             */
            virtual ICaliperEdge* GetEdge1Info() = 0;
            /**
             * @par 说明
             * 距离
             * @par 权限
             * 只读
             */
            virtual float GetDistance() = 0;
            /**
             * @par 说明
             * 得分
             * @par 权限
             * 只读
             */
            virtual float GetScore() = 0;
        };

        /*  Note: Interface Classes for describing single edge find result Information.  */
        class ISingleEdgeFindResult
        {
        protected:
            ///< Constructor and Destructor
            explicit ISingleEdgeFindResult() {}
            virtual ~ISingleEdgeFindResult() {}

        public:
            ///< Properties
            /**
             * @par 说明
             * 边缘个数
             * @par 权限
             * 只读
             */
            virtual int GetEdgeNum() = 0;
            /**
             * @brief 获取结果中的单个边缘点信息
             * @param nPtIndex [out] 边缘点信息
             * @return 返回结果边缘点序
             * @par 注解
             * nPtIndex从0开始计数。
             */
            virtual ICaliperSingleEdgeInfo* GetSingleEdgeInfo( int nIndex ) = 0;
        };

        class IEdgePairFindResult
        {
        protected:
            ///< Constructor and Destructor
            explicit IEdgePairFindResult() {}
            virtual ~IEdgePairFindResult() {}

        public:
            ///< Properties
            /**
             * @par 说明
             * 边缘对个数
             * @par 权限
             * 只读
             */
            virtual int GetEdgePairNum() = 0;
            /**
             * @brief 获取结果中的边缘点信息
             * @param nIndex [out] 边缘点信息
             * @return 返回结果边缘点序
             * @par 注解
             * nIndex从0开始计数。
             */
            virtual ICaliperEdgePairInfo* GetEdgePairInfo( int nIndex ) = 0;
        };

        /*  Note: Interface Classes of the result of the CaliperResults.  */
        class CaliperResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CaliperResults() {}
            virtual ~CaliperResults() {}

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
            ///< Properties
            /**
             * @par 说明
             * 单边缘结果信息
             * @par 权限
             * 只读
             */
            virtual ISingleEdgeFindResult* GetSingleEdge() = 0;
            /**
             * @par 说明
             * 边缘对结果信息
             * @par 权限
             * 只读
             */
            virtual IEdgePairFindResult* GetEdgePair() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Caliper tool.  */
        class IMVSCaliperModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCaliperModuTool() {}
            virtual ~IMVSCaliperModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CaliperParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CaliperResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCaliperModuTool(IMVSCaliperModuTool&);
            IMVSCaliperModuTool& operator=(IMVSCaliperModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Caliper.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCaliperModu::IMVSCaliperModuTool * __stdcall GetCaliperToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CALIPER_H_
