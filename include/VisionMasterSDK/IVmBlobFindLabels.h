/***************************************************************************************************
 * File：IVmBlobFindLabels.h
 * Note：CH: BLOB标签分析模块接口声明 | En: Interface for the BlobFindLabels tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_BLOBFINDLABELS_H_
#define _IVM_BLOBFINDLABELS_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSBlobFindLabelsModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 排序特征 | EN: Ranking
        typedef enum _SortFeatureEnum
        {
            // CH: 面积 | EN: Area
            SortFeature_SortFeatureArea = 0x1,

            // CH: 周长 | EN: Perimeter
            SortFeature_SortFeaturePerimeter = 0x2,

            // CH: 圆形度 | EN: CircleScore
            SortFeature_SortFeatureCircularity = 0x3,

            // CH: 矩形度 | EN: RectScore
            SortFeature_SortFeatureRect = 0x4,

            // CH: 连通域中心x | EN: Connectivity center X
            SortFeature_SortFeatureCentroidX = 0x5,

            // CH: 连通域中心y | EN: Connectivity center Y
            SortFeature_SortFeatureCentroidY = 0x6,

            // CH: box角度 | EN: box angle
            SortFeature_SortFeatureBoxAngle = 0x7,

            // CH: box宽 | EN: box width
            SortFeature_SortFeatureBoxWidth = 0x8,

            // CH: box高 | EN: box height
            SortFeature_SortFeatureBoxHeight = 0x9,

            // CH: 矩形左上顶点x | EN: Rectangle left upper x
            SortFeature_SortFeatureRectX = 0xA,

            // CH: 矩形左上顶点y | EN: Rectangle left upper y
            SortFeature_SortFeatureRectY = 0xB,

            // CH: 二阶中心距主轴角度 | EN: Two step spindle angle
            SortFeature_SortFeatureAxisAngle = 0xC,

            // CH: 轴比(box短轴/box长轴) | EN: MinAxis / LongAxis
            SortFeature_SortFeatureAxisRatio = 0xD,

        }SortFeatureEnum;

        // CH: 排序方式 | EN: Sort Type
        typedef enum _SortModeEnum
        {
            // CH: 升序 | EN: Grade Up
            SortMode_SortModeAscend = 0x1,

            // CH: 降序 | EN: Grade Down
            SortMode_SortModeDecend = 0x2,

            // CH: 不排序 | EN: Donot Grade
            SortMode_SortModeNotSort = 0x3,

        }SortModeEnum;

        // CH: 连通性 | EN: Connectivity 
        typedef enum _ConnectivityEnum
        {
            // CH: 8连通 | EN: 8-connected
            Connectivity_Connected_8 = 0x8,

            // CH: 4连通 | EN: 4-connected
            Connectivity_Connected_4 = 0x4,

        }ConnectivityEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class BlobFindLabelsRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox* pRoiValue, unsigned int nValueNum) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus* pRoiValue, unsigned int nValueNum) = 0;

            // CH: 掩膜图像(仅当次执行起效) | EN: Mask Image(Only valid for this execution)
            virtual void SetMaskImage(ImageBaseData stMaskImage) = 0;

        };

        /*  Note: Interface Classes of the parameter of the AreaThresholdItemParam.  */
        class AreaThresholdItemParam
        {
        protected:
            ///< Constructor and Destructor
            explicit AreaThresholdItemParam() {}
            virtual ~AreaThresholdItemParam() {}

        public:

            // CH: 灰度值 | EN: Gray Value
            __declspec(property(put = SetGrayValue, get = GetGrayValue)) int GrayValue;

            virtual int GetGrayValue() = 0;

            virtual void SetGrayValue(int value) = 0;

            // CH: 面积范围最大值 | EN: Area Range Max Value
            __declspec(property(put = SetZreaMaxValue, get = GetZreaMaxValue)) int ZreaMaxValue;

            virtual int GetZreaMaxValue() = 0;

            virtual void SetZreaMaxValue(int value) = 0;

            // CH: 面积范围最小值 | EN: Area Range Min Value
            __declspec(property(put = SetZreaMinValue, get = GetZreaMinValue)) int ZreaMinValue;

            virtual int GetZreaMinValue() = 0;

            virtual void SetZreaMinValue(int value) = 0;

            // CH: 反选 | EN: Inverse
            __declspec(property(put = SetInverseValue, get = GetInverseValue)) bool InverseValue;

            virtual bool GetInverseValue() = 0;

            virtual void SetInverseValue(bool value) = 0;
        };

        /*  Note: Interface Classes of the parameter of the BlobFindLabelsParams.  */
        class BlobFindLabelsParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BlobFindLabelsParams() {}
            virtual ~BlobFindLabelsParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 类别名称(仅当次执行起效) | EN: ClassName(Only valid for this execution)
            virtual void SetClassName(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // CH: 灰度值(仅当次执行起效) | EN: Gray value(Only valid for this execution)
            virtual void SetGrayValue(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual BlobFindLabelsRoiManager* GetModuRoiManager() = 0;

            // CH: 查找个数 | EN: Number to Find
            __declspec(property(put = SetFindNum, get = GetFindNum)) int FindNum;

            virtual int GetFindNum() = 0;

            virtual void SetFindNum(int value) = 0;

            // CH: 面积使能 | EN: Area Enable
            __declspec(property(put = SetSelectByArea, get = GetSelectByArea)) bool SelectByArea;

            virtual bool GetSelectByArea() = 0;

            virtual void SetSelectByArea(bool value) = 0;

            // CH: 面积范围 | EN: Area Range
            __declspec(property(put = SetMinArea, get = GetMinArea)) int MinArea;

            virtual int GetMinArea() = 0;

            virtual void SetMinArea(int value) = 0;

            // CH: 面积范围 | EN: Area Range
            __declspec(property(put = SetMaxArea, get = GetMaxArea)) int MaxArea;

            virtual int GetMaxArea() = 0;

            virtual void SetMaxArea(int value) = 0;

            // CH: 轮廓输出使能 | EN: Enable Contour Output
            __declspec(property(put = SetBolbOutLineEnable, get = GetBolbOutLineEnable)) bool BolbOutLineEnable;

            virtual bool GetBolbOutLineEnable() = 0;

            virtual void SetBolbOutLineEnable(bool value) = 0;

            // CH: Blob图像输出 | EN: Blob Image Output
            __declspec(property(put = SetBolbImageEnable, get = GetBolbImageEnable)) bool BolbImageEnable;

            virtual bool GetBolbImageEnable() = 0;

            virtual void SetBolbImageEnable(bool value) = 0;

            // CH: 周长使能 | EN: Perimeter Enable
            __declspec(property(put = SetSelectByPerimeter, get = GetSelectByPerimeter)) bool SelectByPerimeter;

            virtual bool GetSelectByPerimeter() = 0;

            virtual void SetSelectByPerimeter(bool value) = 0;

            // CH: 周长范围 | EN: Perimeter Range
            __declspec(property(put = SetMinPerimeter, get = GetMinPerimeter)) int MinPerimeter;

            virtual int GetMinPerimeter() = 0;

            virtual void SetMinPerimeter(int value) = 0;

            // CH: 周长范围 | EN: Perimeter Range
            __declspec(property(put = SetMaxPerimeter, get = GetMaxPerimeter)) int MaxPerimeter;

            virtual int GetMaxPerimeter() = 0;

            virtual void SetMaxPerimeter(int value) = 0;

            // CH: 短轴使能 | EN: Minor Axis Enable
            __declspec(property(put = SetSelectByShortAxis, get = GetSelectByShortAxis)) bool SelectByShortAxis;

            virtual bool GetSelectByShortAxis() = 0;

            virtual void SetSelectByShortAxis(bool value) = 0;

            // CH: 短轴范围 | EN: Minor Axis Range
            __declspec(property(put = SetMinShortAxis, get = GetMinShortAxis)) int MinShortAxis;

            virtual int GetMinShortAxis() = 0;

            virtual void SetMinShortAxis(int value) = 0;

            // CH: 短轴范围 | EN: Minor Axis Range
            __declspec(property(put = SetMaxShortAxis, get = GetMaxShortAxis)) int MaxShortAxis;

            virtual int GetMaxShortAxis() = 0;

            virtual void SetMaxShortAxis(int value) = 0;

            // CH: 长轴使能 | EN: Major Axis Enable
            __declspec(property(put = SetSelectByLongAxis, get = GetSelectByLongAxis)) bool SelectByLongAxis;

            virtual bool GetSelectByLongAxis() = 0;

            virtual void SetSelectByLongAxis(bool value) = 0;

            // CH: 长轴范围 | EN: Major Axis Range
            __declspec(property(put = SetMinLongAxis, get = GetMinLongAxis)) int MinLongAxis;

            virtual int GetMinLongAxis() = 0;

            virtual void SetMinLongAxis(int value) = 0;

            // CH: 长轴范围 | EN: Major Axis Range
            __declspec(property(put = SetMaxLongAxis, get = GetMaxLongAxis)) int MaxLongAxis;

            virtual int GetMaxLongAxis() = 0;

            virtual void SetMaxLongAxis(int value) = 0;

            // CH: 圆形度使能 | EN: Circularity Enable
            __declspec(property(put = SetSelectByCircularuty, get = GetSelectByCircularuty)) bool SelectByCircularuty;

            virtual bool GetSelectByCircularuty() = 0;

            virtual void SetSelectByCircularuty(bool value) = 0;

            // CH: 圆形度范围 | EN: Circularity Range
            __declspec(property(put = SetMinCircularity, get = GetMinCircularity)) double MinCircularity;

            virtual double GetMinCircularity() = 0;

            virtual void SetMinCircularity(double value) = 0;

            // CH: 圆形度范围 | EN: Circularity Range
            __declspec(property(put = SetMaxCircularity, get = GetMaxCircularity)) double MaxCircularity;

            virtual double GetMaxCircularity() = 0;

            virtual void SetMaxCircularity(double value) = 0;

            // CH: 矩形度使能 | EN: Rectangularity Enable
            __declspec(property(put = SetSelectByRectangularity, get = GetSelectByRectangularity)) bool SelectByRectangularity;

            virtual bool GetSelectByRectangularity() = 0;

            virtual void SetSelectByRectangularity(bool value) = 0;

            // CH: 矩形度范围 | EN: Rectangularity Range
            __declspec(property(put = SetMinRectangularity, get = GetMinRectangularity)) double MinRectangularity;

            virtual double GetMinRectangularity() = 0;

            virtual void SetMinRectangularity(double value) = 0;

            // CH: 矩形度范围 | EN: Rectangularity Range
            __declspec(property(put = SetMaxRectangularity, get = GetMaxRectangularity)) double MaxRectangularity;

            virtual double GetMaxRectangularity() = 0;

            virtual void SetMaxRectangularity(double value) = 0;

            // CH: 质心偏移使能 | EN: Barycenter Offset Enable
            __declspec(property(put = SetSelectByCentraBias, get = GetSelectByCentraBias)) bool SelectByCentraBias;

            virtual bool GetSelectByCentraBias() = 0;

            virtual void SetSelectByCentraBias(bool value) = 0;

            // CH: 质心偏移范围 | EN: Barycenter Offset Range
            __declspec(property(put = SetMinCenterBias, get = GetMinCenterBias)) double MinCenterBias;

            virtual double GetMinCenterBias() = 0;

            virtual void SetMinCenterBias(double value) = 0;

            // CH: 质心偏移范围 | EN: Barycenter Offset Range
            __declspec(property(put = SetMaxCenterBias, get = GetMaxCenterBias)) double MaxCenterBias;

            virtual double GetMaxCenterBias() = 0;

            virtual void SetMaxCenterBias(double value) = 0;

            // CH: 轴比范围 | EN: Axial Ratio
            __declspec(property(put = SetAxisRatioEnable, get = GetAxisRatioEnable)) bool AxisRatioEnable;

            virtual bool GetAxisRatioEnable() = 0;

            virtual void SetAxisRatioEnable(bool value) = 0;

            // CH: 轴比范围 | EN: Axial Ratio
            __declspec(property(put = SetMinAxisRatio, get = GetMinAxisRatio)) double MinAxisRatio;

            virtual double GetMinAxisRatio() = 0;

            virtual void SetMinAxisRatio(double value) = 0;

            // CH: 轴比范围 | EN: Axial Ratio
            __declspec(property(put = SetMaxAxisRatio, get = GetMaxAxisRatio)) double MaxAxisRatio;

            virtual double GetMaxAxisRatio() = 0;

            virtual void SetMaxAxisRatio(double value) = 0;

            // CH: 排序特征 | EN: Ranking
            __declspec(property(put = SetSortFeature, get = GetSortFeature)) SortFeatureEnum SortFeature;

            virtual SortFeatureEnum GetSortFeature() = 0;

            virtual void SetSortFeature(SortFeatureEnum value) = 0;

            // CH: 排序方式 | EN: Sort Type
            __declspec(property(put = SetSortMode, get = GetSortMode)) SortModeEnum SortMode;

            virtual SortModeEnum GetSortMode() = 0;

            virtual void SetSortMode(SortModeEnum value) = 0;

            // CH: 连通性 | EN: Connectivity 
            __declspec(property(put = SetConnectivity, get = GetConnectivity)) ConnectivityEnum Connectivity;

            virtual ConnectivityEnum GetConnectivity() = 0;

            virtual void SetConnectivity(ConnectivityEnum value) = 0;

            // CH: 最小重叠率 | EN: MinOverlap
            __declspec(property(put = SetOverlapRatio, get = GetOverlapRatio)) int OverlapRatio;

            virtual int GetOverlapRatio() = 0;

            virtual void SetOverlapRatio(int value) = 0;
			
			// CH: 像素超界使能 | EN: RunParam_MaxOutPixelNumEnable
            __declspec(property(put = SetMaxOutPixelNumEnable, get = GetMaxOutPixelNumEnable)) bool MaxOutPixelNumEnable;

            virtual bool GetMaxOutPixelNumEnable() = 0;

            virtual void SetMaxOutPixelNumEnable(bool value) = 0;

            // CH: 最大超界像素 | EN: MaxOutPixelNum
            __declspec(property(put = SetMaxOutPixelNum, get = GetMaxOutPixelNum)) int MaxOutPixelNum;

            virtual int GetMaxOutPixelNum() = 0;

            virtual void SetMaxOutPixelNum(int value) = 0;

            // CH: 启用标签级面积筛选 | EN: Enable label-level area filtering
            __declspec(property(put = SetLabelWiseAreaSelectEnable, get = GetLabelWiseAreaSelectEnable)) bool LabelWiseAreaSelectEnable;

            virtual bool GetLabelWiseAreaSelectEnable() = 0;

            virtual void SetLabelWiseAreaSelectEnable(bool value) = 0;

            // CH: Blob个数判断 | EN: Blob Number Check
            __declspec(property(put = SetBlobNumLimitEnable, get = GetBlobNumLimitEnable)) bool BlobNumLimitEnable;

            virtual bool GetBlobNumLimitEnable() = 0;

            virtual void SetBlobNumLimitEnable(bool value) = 0;

            // CH: Blob个数范围 | EN: Blob Number Range
            __declspec(property(put = SetBlobNumLimitLow, get = GetBlobNumLimitLow)) int BlobNumLimitLow;

            virtual int GetBlobNumLimitLow() = 0;

            virtual void SetBlobNumLimitLow(int value) = 0;

            // CH: Blob个数范围 | EN: Blob Number Range
            __declspec(property(put = SetBlobNumLimitHigh, get = GetBlobNumLimitHigh)) int BlobNumLimitHigh;

            virtual int GetBlobNumLimitHigh() = 0;

            virtual void SetBlobNumLimitHigh(int value) = 0;

            // CH: Blob面积判断 | EN: Blob Area Check
            __declspec(property(put = SetBlobAreaLimitEnable, get = GetBlobAreaLimitEnable)) bool BlobAreaLimitEnable;

            virtual bool GetBlobAreaLimitEnable() = 0;

            virtual void SetBlobAreaLimitEnable(bool value) = 0;

            // CH: Blob面积范围 | EN: Blob Area Range
            __declspec(property(put = SetBlobAreaLimitLow, get = GetBlobAreaLimitLow)) double BlobAreaLimitLow;

            virtual double GetBlobAreaLimitLow() = 0;

            virtual void SetBlobAreaLimitLow(double value) = 0;

            // CH: Blob面积范围 | EN: Blob Area Range
            __declspec(property(put = SetBlobAreaLimitHigh, get = GetBlobAreaLimitHigh)) double BlobAreaLimitHigh;

            virtual double GetBlobAreaLimitHigh() = 0;

            virtual void SetBlobAreaLimitHigh(double value) = 0;

            // CH: Blob总面积 | EN: Blob Total Area Check
            __declspec(property(put = SetBlobTotalAreaLimitEnable, get = GetBlobTotalAreaLimitEnable)) bool BlobTotalAreaLimitEnable;

            virtual bool GetBlobTotalAreaLimitEnable() = 0;

            virtual void SetBlobTotalAreaLimitEnable(bool value) = 0;

            // CH: 总面积范围 | EN: Blob Total Area Range
            __declspec(property(put = SetBlobTotalAreaLimitLow, get = GetBlobTotalAreaLimitLow)) double BlobTotalAreaLimitLow;

            virtual double GetBlobTotalAreaLimitLow() = 0;

            virtual void SetBlobTotalAreaLimitLow(double value) = 0;

            // CH: 总面积范围 | EN: Blob Total Area Range
            __declspec(property(put = SetBlobTotalAreaLimitHigh, get = GetBlobTotalAreaLimitHigh)) double BlobTotalAreaLimitHigh;

            virtual double GetBlobTotalAreaLimitHigh() = 0;

            virtual void SetBlobTotalAreaLimitHigh(double value) = 0;

            // CH: 质心X判断 | EN: Barycenter X Check
            __declspec(property(put = SetCentroidXLimitEnable, get = GetCentroidXLimitEnable)) bool CentroidXLimitEnable;

            virtual bool GetCentroidXLimitEnable() = 0;

            virtual void SetCentroidXLimitEnable(bool value) = 0;

            // CH: 质心X范围 | EN: Barycenter X Range
            __declspec(property(put = SetCentroidXLimitLow, get = GetCentroidXLimitLow)) double CentroidXLimitLow;

            virtual double GetCentroidXLimitLow() = 0;

            virtual void SetCentroidXLimitLow(double value) = 0;

            // CH: 质心X范围 | EN: Barycenter X Range
            __declspec(property(put = SetCentroidXLimitHigh, get = GetCentroidXLimitHigh)) double CentroidXLimitHigh;

            virtual double GetCentroidXLimitHigh() = 0;

            virtual void SetCentroidXLimitHigh(double value) = 0;

            // CH: 质心Y判断 | EN: Barycenter Y Check
            __declspec(property(put = SetCentroidYLimitEnable, get = GetCentroidYLimitEnable)) bool CentroidYLimitEnable;

            virtual bool GetCentroidYLimitEnable() = 0;

            virtual void SetCentroidYLimitEnable(bool value) = 0;

            // CH: 质心Y范围 | EN: Barycenter Y Range
            __declspec(property(put = SetCentroidYLimitLow, get = GetCentroidYLimitLow)) double CentroidYLimitLow;

            virtual double GetCentroidYLimitLow() = 0;

            virtual void SetCentroidYLimitLow(double value) = 0;

            // CH: 质心Y范围 | EN: Barycenter Y Range
            __declspec(property(put = SetCentroidYLimitHigh, get = GetCentroidYLimitHigh)) double CentroidYLimitHigh;

            virtual double GetCentroidYLimitHigh() = 0;

            virtual void SetCentroidYLimitHigh(double value) = 0;

            // CH: Box角度判断 | EN: BoxAngle Check
            __declspec(property(put = SetAngleLimitEnable, get = GetAngleLimitEnable)) bool AngleLimitEnable;

            virtual bool GetAngleLimitEnable() = 0;

            virtual void SetAngleLimitEnable(bool value) = 0;

            // CH: Box角度范围 | EN: BoxAngle Range
            __declspec(property(put = SetAngleLimitLow, get = GetAngleLimitLow)) double AngleLimitLow;

            virtual double GetAngleLimitLow() = 0;

            virtual void SetAngleLimitLow(double value) = 0;

            // CH: Box角度范围 | EN: BoxAngle Range
            __declspec(property(put = SetAngleLimitHigh, get = GetAngleLimitHigh)) double AngleLimitHigh;

            virtual double GetAngleLimitHigh() = 0;

            virtual void SetAngleLimitHigh(double value) = 0;

            // CH: 中心X判断 | EN: Center X Check
            __declspec(property(put = SetCenterXLimitEnable, get = GetCenterXLimitEnable)) bool CenterXLimitEnable;

            virtual bool GetCenterXLimitEnable() = 0;

            virtual void SetCenterXLimitEnable(bool value) = 0;

            // CH: 中心X范围 | EN: Center X Range
            __declspec(property(put = SetCenterXLimitLow, get = GetCenterXLimitLow)) double CenterXLimitLow;

            virtual double GetCenterXLimitLow() = 0;

            virtual void SetCenterXLimitLow(double value) = 0;

            // CH: 中心X范围 | EN: Center X Range
            __declspec(property(put = SetCenterXLimitHigh, get = GetCenterXLimitHigh)) double CenterXLimitHigh;

            virtual double GetCenterXLimitHigh() = 0;

            virtual void SetCenterXLimitHigh(double value) = 0;

            // CH: 中心Y判断 | EN: Center Y Check
            __declspec(property(put = SetCenterYLimitEnable, get = GetCenterYLimitEnable)) bool CenterYLimitEnable;

            virtual bool GetCenterYLimitEnable() = 0;

            virtual void SetCenterYLimitEnable(bool value) = 0;

            // CH: 中心Y范围 | EN: Center Y Range
            __declspec(property(put = SetCenterYLimitLow, get = GetCenterYLimitLow)) double CenterYLimitLow;

            virtual double GetCenterYLimitLow() = 0;

            virtual void SetCenterYLimitLow(double value) = 0;

            // CH: 中心Y范围 | EN: Center Y Range
            __declspec(property(put = SetCenterYLimitHigh, get = GetCenterYLimitHigh)) double CenterYLimitHigh;

            virtual double GetCenterYLimitHigh() = 0;

            virtual void SetCenterYLimitHigh(double value) = 0;

            // CH: Box高度判断 | EN: Box Height Check
            __declspec(property(put = SetBoxHeightLimitEnable, get = GetBoxHeightLimitEnable)) bool BoxHeightLimitEnable;

            virtual bool GetBoxHeightLimitEnable() = 0;

            virtual void SetBoxHeightLimitEnable(bool value) = 0;

            // CH: Box高度范围 | EN: Box Height Range
            __declspec(property(put = SetBoxHeightLimitLow, get = GetBoxHeightLimitLow)) double BoxHeightLimitLow;

            virtual double GetBoxHeightLimitLow() = 0;

            virtual void SetBoxHeightLimitLow(double value) = 0;

            // CH: Box高度范围 | EN: Box Height Range
            __declspec(property(put = SetBoxHeightLimitHigh, get = GetBoxHeightLimitHigh)) double BoxHeightLimitHigh;

            virtual double GetBoxHeightLimitHigh() = 0;

            virtual void SetBoxHeightLimitHigh(double value) = 0;

            // CH: Box宽度判断 | EN: Box Width Check
            __declspec(property(put = SetBoxWidthLimitEnable, get = GetBoxWidthLimitEnable)) bool BoxWidthLimitEnable;

            virtual bool GetBoxWidthLimitEnable() = 0;

            virtual void SetBoxWidthLimitEnable(bool value) = 0;

            // CH: Box宽度范围 | EN: Box Width Range
            __declspec(property(put = SetBoxWidthLimitLow, get = GetBoxWidthLimitLow)) double BoxWidthLimitLow;

            virtual double GetBoxWidthLimitLow() = 0;

            virtual void SetBoxWidthLimitLow(double value) = 0;

            // CH: Box宽度范围 | EN: Box Width Range
            __declspec(property(put = SetBoxWidthLimitHigh, get = GetBoxWidthLimitHigh)) double BoxWidthLimitHigh;

            virtual double GetBoxWidthLimitHigh() = 0;

            virtual void SetBoxWidthLimitHigh(double value) = 0;

            // CH: 周长判断 | EN: Perimeter Check
            __declspec(property(put = SetPerimeterLimitEnable, get = GetPerimeterLimitEnable)) bool PerimeterLimitEnable;

            virtual bool GetPerimeterLimitEnable() = 0;

            virtual void SetPerimeterLimitEnable(bool value) = 0;

            // CH: 周长范围 | EN: Perimeter Range
            __declspec(property(put = SetPerimeterLimitLow, get = GetPerimeterLimitLow)) double PerimeterLimitLow;

            virtual double GetPerimeterLimitLow() = 0;

            virtual void SetPerimeterLimitLow(double value) = 0;

            // CH: 周长范围 | EN: Perimeter Range
            __declspec(property(put = SetPerimeterLimitHigh, get = GetPerimeterLimitHigh)) double PerimeterLimitHigh;

            virtual double GetPerimeterLimitHigh() = 0;

            virtual void SetPerimeterLimitHigh(double value) = 0;

            // CH: 长轴判断 | EN: Major Axis Check
            __declspec(property(put = SetLongAxisLimitEnable, get = GetLongAxisLimitEnable)) bool LongAxisLimitEnable;

            virtual bool GetLongAxisLimitEnable() = 0;

            virtual void SetLongAxisLimitEnable(bool value) = 0;

            // CH: 长轴范围 | EN: Major Axis Range
            __declspec(property(put = SetLongAxisLimitLow, get = GetLongAxisLimitLow)) double LongAxisLimitLow;

            virtual double GetLongAxisLimitLow() = 0;

            virtual void SetLongAxisLimitLow(double value) = 0;

            // CH: 长轴范围 | EN: Major Axis Range
            __declspec(property(put = SetLongAxisLimitHigh, get = GetLongAxisLimitHigh)) double LongAxisLimitHigh;

            virtual double GetLongAxisLimitHigh() = 0;

            virtual void SetLongAxisLimitHigh(double value) = 0;

            // CH: 短轴判断 | EN: Minor Axis Check
            __declspec(property(put = SetShortAxisLimitEnable, get = GetShortAxisLimitEnable)) bool ShortAxisLimitEnable;

            virtual bool GetShortAxisLimitEnable() = 0;

            virtual void SetShortAxisLimitEnable(bool value) = 0;

            // CH: 短轴范围 | EN: Minor Axis Range
            __declspec(property(put = SetShortAxisLimitLow, get = GetShortAxisLimitLow)) double ShortAxisLimitLow;

            virtual double GetShortAxisLimitLow() = 0;

            virtual void SetShortAxisLimitLow(double value) = 0;

            // CH: 短轴范围 | EN: Minor Axis Range
            __declspec(property(put = SetShortAxisLimitHigh, get = GetShortAxisLimitHigh)) double ShortAxisLimitHigh;

            virtual double GetShortAxisLimitHigh() = 0;

            virtual void SetShortAxisLimitHigh(double value) = 0;

            // CH: 圆形度判断 | EN: Circularity Check
            __declspec(property(put = SetCircularityLimitEnable, get = GetCircularityLimitEnable)) bool CircularityLimitEnable;

            virtual bool GetCircularityLimitEnable() = 0;

            virtual void SetCircularityLimitEnable(bool value) = 0;

            // CH: 圆形度范围 | EN: Circularity Range
            __declspec(property(put = SetCircularityLimitLow, get = GetCircularityLimitLow)) double CircularityLimitLow;

            virtual double GetCircularityLimitLow() = 0;

            virtual void SetCircularityLimitLow(double value) = 0;

            // CH: 圆形度范围 | EN: Circularity Range
            __declspec(property(put = SetCircularityLimitHigh, get = GetCircularityLimitHigh)) double CircularityLimitHigh;

            virtual double GetCircularityLimitHigh() = 0;

            virtual void SetCircularityLimitHigh(double value) = 0;

            // CH: 矩形度判断 | EN: Rectangularity Check
            __declspec(property(put = SetRectangularityLimitEnable, get = GetRectangularityLimitEnable)) bool RectangularityLimitEnable;

            virtual bool GetRectangularityLimitEnable() = 0;

            virtual void SetRectangularityLimitEnable(bool value) = 0;

            // CH: 矩形度范围 | EN: Rectangularity Range
            __declspec(property(put = SetRectangularityLimitLow, get = GetRectangularityLimitLow)) double RectangularityLimitLow;

            virtual double GetRectangularityLimitLow() = 0;

            virtual void SetRectangularityLimitLow(double value) = 0;

            // CH: 矩形度范围 | EN: Rectangularity Range
            __declspec(property(put = SetRectangularityLimitHigh, get = GetRectangularityLimitHigh)) double RectangularityLimitHigh;

            virtual double GetRectangularityLimitHigh() = 0;

            virtual void SetRectangularityLimitHigh(double value) = 0;

            // CH: CH: 根据索引名称获取面积阈值动态参数项(灰度值/最大值/最小值/反选等)(单例模式) | EN:Get Area Threshold Dynamic Parameter Items According To Index Name(Gray Value/Max Value/Min Value/Inverse)(Singleton Pattern)
            // CH: 参数名称即序号, 如"1" | EN: Parameters Name Is The Sequence Number, Such As "1"
            virtual AreaThresholdItemParam* GetAreaThresholdItemParam(const char * const strName) = 0;
        };

        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Blob信息描述类.  */
        class IBlobInfo
        {
        protected:
            ///< 构造与析构
            explicit IBlobInfo() {}
            virtual ~IBlobInfo() {}

        public:
            //// Properties
            /**
             * @par 说明
             * 周长
             * @par 权限
             * 只读
             *
             */
            virtual float GetPerimeter() = 0;
            /**
             * @par 说明
             * 圆形度
             * @par 权限
             * 只读
             *
             */
            virtual float GetCircularity() = 0;
            /**
             * @par 说明
             * 最小外接矩形短轴
             * @par 权限
             * 只读
             *
             */
            virtual float GetShortAxis() = 0;
            /**
             * @par 说明
             * 最小外接矩形长轴
             * @par 权限
             * 只读
             *
             */
            virtual float GetLongAxis() = 0;
            /**
             * @par 说明
             * 轴比（短轴/长轴）
             * @par 权限
             * 只读
             *
             */
            virtual float GetAxisRatio() = 0;
            /**
             * @par 说明
             * 角度
             * @par 权限
             * 只读
             *
             */
            virtual float GetAngle() = 0;
            /**
             * @par 说明
             * 矩形度
             * @par 权限
             * 只读
             *
             */
            virtual float GetRectangularity() = 0;
            /**
             * @par 说明
             * Blob得分
             * @par 权限
             * 只读
             *
             */
            virtual float GetScore() = 0;
            /**
             * @par 说明
             * 最小面积外接矩形
             * @par 权限
             * 只读
             *
             */
            virtual RectBox GetBoxInfo() = 0;
            /**
             * @par 说明
             * 连通域中心（质心）
             * @par 权限
             * 只读
             *
             */
            virtual MVD_POINT_F GetCenteroid() = 0;
            /**
             * @par 说明
             * 面积
             * @par 权限
             * 只读
             *
             */
            virtual float GetAreaF() = 0;
            /**
             * @par 说明
             * 标签值，即当前blob的灰度值
             * @par 权限
             * 只读
             *
             */
            virtual int GetLabelID() = 0;
            /**
            * @par 说明
            * 类别标签，即当前blob的灰度值对应标签
            * @par 权限
            * 只读
            *
            */
            virtual const char * GetClassLabel() = 0;
        };

        /*  Note: Interface Classes of the result of the BlobFindLabelsResults.  */
        class BlobFindLabelsResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BlobFindLabelsResults() {}
            virtual ~BlobFindLabelsResults() {}

        public:
             /**
             * @par 说明
             * 输出掩膜
             * @par 权限
             * 只读
             */
             virtual ImageBaseData GetOutputMask() = 0;

             /**
             * @par 说明
             * 屏蔽区多边形点集
             * @par 权限
             * 只读
             */
             virtual PointF GetBlindPolygonPoints(int nIndex) = 0;

             /**
             * @par 说明
             * 屏蔽区多边形点数
             * @par 权限
             * 只读
             */
             virtual int GetBlindPolygonPointNum(int nIndex) = 0;

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
             * ROI圆弧
             * @par 权限
             * 只读
             */
             virtual Annulus GetROIAnnulus(int nIndex) = 0;
            ///< Properties
            /**
             * @par 说明
             * Blob数量
             * @par 权限
             * 只读
             *
             */
            /* Gets the total number of edge points in the current result.*/
            virtual int GetBlobNum() = 0;
            /**
             * @par 说明
             * 获取Blob分析的结果信息
             * @par 权限
             * 只读
             *
             */
            /* Gets information of the blob with an index value of 'nBlobIndex'.
            The range of index value can be queried from GetBlobCount function. */
            virtual IBlobInfo* GetBlobInfo(int nBlobIndex) = 0;
            /**
             * @par 说明
             * 二值化图像
             * @par 权限
             * 只读
             *
             */
            /* One of the results binary image Input image binarization result */
            virtual ImageBaseData GetBinaryImage() = 0;
            /**
             * @par 说明
             * 获取Blob图像
             * @par 权限
             * 只读
             *
             */
            /* The other binary image Target connected domain drawing result */
            virtual ImageBaseData GetBlobImage() = 0;
            /**
             * @par 说明
             * Blob总面积
             * @par 权限
             * 只读
             *
             */
            virtual float GetTotalArea() = 0;
            /**
             * @par 说明
             * 轮廓点数量
             * @par 权限
             * 只读
             *
             */
            virtual int GetContourPointNum() = 0;
            /**
             * @par 说明
             * 轮廓点
             * @par 权限
             * 只读
             *
             */
            virtual MVD_POINT_S* GetContourPoints() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the BlobFindLabels tool.  */
        class IMVSBlobFindLabelsModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSBlobFindLabelsModuTool() {}
            virtual ~IMVSBlobFindLabelsModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual BlobFindLabelsParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual BlobFindLabelsResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSBlobFindLabelsModuTool(IMVSBlobFindLabelsModuTool&);
            IMVSBlobFindLabelsModuTool& operator=(IMVSBlobFindLabelsModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for BlobFindLabels.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSBlobFindLabelsModu::IMVSBlobFindLabelsModuTool * __stdcall GetBlobFindLabelsToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_BLOBFINDLABELS_H_
