/***************************************************************************************************
 *
 * 版权信息：版权所有 (c) 2020, 保留所有权利
 *
 * 文件名称：iMVS-6000PlatformSDKDefine.h
 * 摘    要：二次开发SDK接口宏定义
 *
 * 作    者：视觉平台组
 * 日    期：2020-01-17 11:09:05
 * 备    注：新建

 * Copyright information: All Right Reserved.
 *
 * File name: iMVS-6000PlatformSDKDefine.h
 * Brief: VisionMaster SDK definition
 *
 * Author: VisionMaster Team
 * Date: 2020-01-17 11:09:05
 * Note: New
 ****************************************************************************************************/
#ifndef IMVS_6000_PLATFORMSDK_DEFINE_H__
#define IMVS_6000_PLATFORMSDK_DEFINE_H__

#pragma warning(disable:4819)
#include "ErrorCodeDefine.h"
#include "IVmExport.h"
using namespace VisionMasterSDK;

/*************************************************************************
 * 系统宏定义
 * System macro definition
 *************************************************************************/

// CH: 定义输入表示 | EN: Input definition
#ifndef IN
#define IN
#endif

// CH: 定义输出表示 | EN: Output definition
#ifndef OUT
#define OUT
#endif

// CH: 定义输入输出表示 | EN: Input and output definition
#ifndef INOUT
#define INOUT
#endif

// CH: 定义空指针 | EN: Empty pointer definition
#ifndef IMVS_NULL
#ifdef __cplusplus
#define IMVS_NULL    0
#else
#define IMVS_NULL    ((void *)0)
#endif
#endif

// CH: 模块名称宏定义 | EN: Module names' macro definition
#define MODU_NAME_LOCALIMAGEVIEW       "LocalImageView"            // CH: 本地图像模块 | EN: Local image module
#define MODU_NAME_CAMERAMODULE         "CameraModule"              // CH: 相机图像模块 | EN: Camera module
#define MODU_NAME_SAVEIMAGE            "SaveImage"                 // CH: 输出图像模块 | EN: Output image module
#define MODU_NAME_HPFEATUREMATCHMODU   "IMVSHPFeatureMatchModu"    // CH: 高精度特征匹配模块 | EN: Feature high-precising matching module
#define MODU_NAME_FASTFEATUREMATCHMODU "IMVSFastFeatureMatchModu"  // CH: 快速特征匹配模块 | EN: Feature fast matching module
#define MODU_NAME_CIRCLEFINDMODU       "IMVSCircleFindModu"        // CH: 圆查找模块 | EN: Circle search module
#define MODU_NAME_LINEFINDMODU         "IMVSLineFindModu"          // CH: 直线查找模块 | EN: Line search module
#define MODU_NAME_BLOBFINDMODU         "IMVSBlobFindModu"          // CH: Blob分析模块 | EN: BLOB (Binary Large Object) analysis module
#define MODU_NAME_CALIPERMODU          "IMVSCaliperModu"           // CH: 卡尺工具模块 | EN: Caliper tool module
#define MODU_NAME_CALIPEREDGEMODU      "IMVSCaliperEdgeModu"       // CH: 边缘查找模块 | EN: Edge search module
#define MODU_NAME_EDGEWIDTHFINDMODU    "IMVSEdgeWidthFindModu"     // CH: 间距检测模块 | EN: Interval detection module
#define MODU_NAME_FIXTUREMODU          "IMVSFixtureModu"           // CH: 位置修正模块 | EN: Position correction module
#define MODU_NAME_RECTFINDMODU         "IMVSRectFindModu"          // CH: 矩形检测模块 | EN: Rectangle detection module
#define MODU_NAME_PEAKFINDMODU         "IMVSPeakFindModu"          // CH: 顶点检测模块 | EN: Vertex detection module
#define MODU_NAME_CALIPERCORNERMODU    "IMVSCaliperCornerModu"     // CH: 边缘交点模块 | EN: Edge intersection search module
#define MODU_NAME_PAIRLINEMODU         "IMVSPairLineModu"          // CH: 平行线查找模块 | EN: Parallel line search module
#define MODU_NAME_L2CMEASUREMODU       "IMVSL2CMeasureModu"        // CH: 线圆测量模块 | EN: Line and circle distance measurement module
#define MODU_NAME_C2CMEASUREMODU       "IMVSC2CMeasureModu"        // CH: 圆圆测量模块 | EN: Circle and circle distance measurement module
#define MODU_NAME_P2CMEASUREMODU       "IMVSP2CMeasureModu"        // CH: 点圆测量模块 | EN: Point and circle distance measurement module
#define MODU_NAME_P2LMEASUREMODU       "IMVSP2LMeasureModu"        // CH: 点线测量模块 | EN: Point and line distance measurement module
#define MODU_NAME_L2LMEASUREMODU       "IMVSL2LMeasureModu"        // CH: 线线测量模块 | EN: Line and line distance measurement module
#define MODU_NAME_P2PMEASUREMODU       "IMVSP2PMeasureModu"        // CH: 点点测量模块 | EN: Point and point distance measurement module
#define MODU_NAME_CIRCLEFITMODU        "IMVSCircleFitModu"         // CH: 圆拟合模块 | EN: Circle fitting module
#define MODU_NAME_LINEFITMODU          "IMVSLineFitModu"           // CH: 直线拟合模块 | EN: Line fitting module
#define MODU_NAME_INTENSITYMEASUREMODU "IMVSIntensityMeasureModu"  // CH: 亮度测量模块 | EN: Brightness detection module
#define MODU_NAME_PIXELCOUNTMODU       "IMVSPixelCountModu"        // CH: 像素统计模块 | EN: Pixel statistics module
#define MODU_NAME_HISTTOOLMODU         "IMVSHistToolModu"          // CH: 直方图工具模块 | EN: Histogram tool module
#define MODU_NAME_GEOMETRYCREATE       "GeometryCreate"            // CH: 几何创建模块 | EN: Geometry creation module
#define MODU_NAME_2DBCRMODU            "IMVS2dBcrModu"             // CH: 二维码识别模块 | EN: QR code recognition module
#define MODU_NAME_BCRMODU              "IMVSBcrModu"               // CH: 条码识别模块 | EN: Bar code recognition module
#define MODU_NAME_OCRMODU              "IMVSOcrModu"               // CH: 字符识别模块 | EN: OCR (Optical Character Recognition) module
#define MODU_NAME_VERICODEMODU         "IMVSVericodeModu"          // CH: VeriCode模块 | EN: Verification code module
#define MODU_NAME_CALIBBOARDCALIBMODU  "IMVSCalibBoardCalibModu"   // CH: 标定板标定模块 | EN: Calibration module
#define MODU_NAME_NPOINTCALIBMODU      "IMVSNPointCalibModu"       // CH: N点标定模块 | EN: N-point calibration module
#define MODU_NAME_CALIBTRANSFORMMODU   "IMVSCalibTransformModu"    // CH: 标定转换模块 | EN: Calibration conversion module
#define MODU_NAME_SCALETRANSFORMMODU   "IMVSScaleTransformModu"    // CH: 单位转换模块 | EN: Unit conversion module
#define MODU_NAME_IMAGECORRECTCALIBMODU "IMVSImageCorrectCalibModu"// CH: 畸变校正模块 | EN: Distortion calibration module
#define MODU_NAME_IMAGEMORPHMODU       "IMVSImageMorphModu"        // CH: 形态学处理模块 | EN: Image morphological processing module
#define MODU_NAME_BINARYMODU           "IMVSBinaryModu"            // CH: 图像二值化模块 | EN: Image binarization module
#define MODU_NAME_IMAGEFILTERMODU      "IMVSImageFilterModu"       // CH: 图像滤波模块 | EN: Image filtering module
#define MODU_NAME_IMAGEENHANCEMODU     "IMVSImageEnhanceModu"      // CH: 图像增强模块 | EN: Image enhancement module
#define MODU_NAME_IMAGEMATHMODU        "IMVSImageMathModu"         // CH: 图像运算模块 | EN: Image arithmetic module
#define MODU_NAME_IMAGESHARPNESSMODU   "IMVSImageSharpnessModu"    // CH: 清晰度评估模块 | EN: Image resolution assessment module
#define MODU_NAME_IMAGEFIXTUREMODU     "IMVSImageFixtureModu"      // CH: 图像修正模块 | EN: Image correction module
#define MODU_NAME_SHADECORRECTMODU     "IMVSShadeCorrectModu"      // CH: 阴影校正模块 | EN: Shadow correction module
#define MODU_NAME_AFFINETRANSFORMMODU  "IMVSAffineTransformModu"   // CH: 仿射变换模块 | EN: Affine transformation module
#define MODU_NAME_POLARUNWARPMODU      "IMVSPolarUnwarpModu"       // CH: 圆环展开模块 | EN: Circular expansion module
#define MODU_NAME_COLOREXTRACTMODU     "IMVSColorExtractModu"      // CH: 颜色抽取模块 | EN: Color extraction module
#define MODU_NAME_COLORMEASUREMODU     "IMVSColorMeasureModu"      // CH: 颜色测量模块 | EN: Color detection module
#define MODU_NAME_COLORTRANSFORMMODU   "IMVSColorTransformModu"    // CH: 颜色转换模块 | EN: Color conversion module
#define MODU_NAME_IFMODULE             "IfModule"                  // CH: 条件检测模块 | EN: Condition detection module
#define MODU_NAME_BRANCHMODULE         "BranchModule_STD"          // CH: 分支模块 | EN: Branching module
#define MODU_NAME_ANDMODULE            "AndModule"                 // CH: 逻辑模块 | EN: Logic module
#define MODU_NAME_FORMATMODULE         "FormatModule"              // CH: 格式化模块 | EN: Formatting module
#define MODU_NAME_CALCULATORMODULE     "CalculatorModule"          // CH: 变量计算模块 | EN: Variable calculation module
#define MODU_NAME_STRINGCOMPAREMODULE  "StringCompareModule"       // CH: 字符比较模块 | EN: Character comparison module
#define MODU_NAME_SHELLMODULE          "ShellModule"               // CH: 脚本模块 | EN: Script module
#define MODU_NAME_POINTSETMODU         "PointSetMODU_STD"          // CH: 点集模块 | EN: Point set module

// CH: 深度学习模块 | EN: Deep learning modules
#define MODU_NAME_OCRDLMODU            "IMVSOcrDlModu"            // CH: 深度学习字符识别模块 （GPU版本） | EN: OCR (Optical Character Recognition) module (for deep learning), GPU version
#define MODU_NAME_CNNSEGMODU           "IMVSCnnFlawModu"          // CH: 深度学习图像分割模块 | EN: Image segmentation module (for deep learning)
#define MODU_NAME_CNNCHARDETECTMODU    "IMVSCnnCharDetectModu"    // CH: 深度学习字符定位模块 （GPU版本） | EN: Character location module (for deep learning), GPU version
#define MODU_NAME_CNNCLASSIFYMODU      "IMVSCnnClassifyModu"      // CH: 深度学习分类模块 （GPU版本） | EN: Deep learning classification module, GPU version
#define MODU_NAME_CNNDETECTMODU        "IMVSCnnDetectModu"        // CH: 深度学习目标检测模块 （GPU版本） | EN: Target detection module (for deep learning), GPU version
#define MODU_NAME_CNNTRAINTOOLMODU     "IMVSCnnTrainToolModu"     // CH: 深度学习训练工具模块 | EN: Training tool module

// CH: V3.1.0新增深度学习CPU版本模块 | EN: V3.1.0 new deep learning CPU version modules
#define MODU_NAME_CNNCHARDETECTMODUC   "IMVSCnnCharDetectModuC"   // CH: 深度学习字符定位模块 （CPU版本） | EN: Character location module (for deep learning), CPU version
#define MODU_NAME_CNNCLASSIFYMODUC     "IMVSCnnClassifyModuC"     // CH: 深度学习分类模块 （CPU版本） | EN: Deep learning classification module, CPU version
#define MODU_NAME_CNNDETECTMODUC       "IMVSCnnDetectModuC"       // CH: 深度学习目标检测模块 （CPU版本） | EN: Target detection module (for deep learning), CPU version

// CH: V3.0.0新增模块 | EN: V3.0.0 new modules
#define MODU_NAME_BRANCHSTRINGCPMOLD      "BranchStringCpm"              // CH: 分支字符模块 | EN: Branch character module
#define MODU_NAME_FRAMEMEANMODU           "IMVSFrameMeanModu"            // CH: 帧平均模块 | EN: Frame averaging module
#define MODU_NAME_IMAGECALIBMODU          "IMVSImageCalibModu"           // CH: 畸变标定模块 | EN: Distortion calibration module
#define MODU_NAME_IMAGECOMBINEPROCESSMODU "IMVSImageCombineProcessModu"  // CH: 图像组合模块 | EN: Image combination module
#define MODU_NAME_IMAGENORMLIZEMODU       "IMVSImageNormlizeModu"        // CH: 图像归一化模块 | EN: Image normalization module
#define MODU_NAME_MARKINSPMODU            "IMVSMarkInspModu"             // CH: 字符缺陷检测模块 | EN: Character defect detection module
#define MODU_NAME_REGIONCOPYMODU          "IMVSRegionCopyModu"           // CH: 拷贝填充模块 | EN: Area copying and filling module
#define MODU_NAME_READDATASMODULE         "ReadDatasModule"              // CH: 接收数据模块 | EN: Data receiving module
#define MODU_NAME_SAVETEXTMODULE          "SaveTextModule"               // CH: 文本保存模块 | EN: Text storage module
#define MODU_NAME_SENDDATASMODULE         "SendDatasModule"              // CH: 发送数据模块 | EN: Data sending module
#define MODU_NAME_TIMESTATISTICMODULE     "TimeStatisticModule"          // CH: 耗时统计模块 | EN: Time-consuming statistics module
#define MODU_NAME_CAMERAMAPMODU           "IMVSCameraMapModu"            // CH: 相机映射模块 | EN: Camera mapping module
#define MODU_NAME_SINGLEPOINTALIGNMODU    "IMVSSinglePointAlignModu"     // CH: 单点对位模块 | EN: Single point alignment module
#define MODU_NAME_MULTIPOINTALIGNMODU     "IMVSMultiPointAlignModu"      // CH: 点集对位模块 | EN: Point set alignment module
#define MODU_NAME_LINEALIGNMODU           "IMVSLineAlignModu"            // CH: 线对位模块 | EN: Line alignment module

// CH: V3.1.0新增模块 | EN: V3.1.0 new modules
#define MODU_NAME_CIRCLEEDGEINSPMODU     "IMVSCircleEdgeInspModu"        // CH: 圆弧边缘缺陷检测模块 | EN: Arc edge defect detection module
#define MODU_NAME_LINEEDGEINSPMODU       "IMVSLineEdgeInspModu"          // CH: 直线边缘缺陷检测模块 | EN: Line edge defect detection module
#define MODU_NAME_CIRCLEEDGEPAIRINSPMODU "IMVSCircleEdgePairInspModu"    // CH: 圆弧边缘对缺陷检测模块 | EN: Arc edge pair defect detection module
#define MODU_NAME_LINEEDGEPAIRINSPMODU   "IMVSLineEdgePairInspModu"      // CH: 直线边缘对缺陷检测模块 | EN: Line edge pair defect detection module
#define MODU_NAME_EDGEINSPGROUPMODU      "IMVSEdgeInspGroupModu"         // CH: 边缘组合缺陷检测模块 | EN: Edge combination defect detection module
#define MODU_NAME_EDGEPAIRINSPGROUPMODU  "IMVSEdgePairInspGroupModu"     // CH: 边缘对组合缺陷检测模块 | EN: Edge pair combination defect detection module
#define MODU_NAME_EDGEFLAWINSPMODU       "IMVSEdgeFlawInspModu"          // CH: 边缘模型缺陷检测模块 | EN: Edge model defect detection module
#define MODU_NAME_EDGEPAIRFLAWINSPMODU   "IMVSEdgePairFlawInspModu"      // CH: 边缘对模型缺陷检测模块 | EN: Edge pair model defect detection module
#define MODU_NAME_BRANCHSTRINGCPML       "BranchStringCpmL"              // CH: 分支字符模块（单进程） | EN: Character comparison module (for single process)

// CH: V3.2.0新增模块 | EN: V3.2.0 new modules
#define MODU_NAME_IMAGEBUFFERMODULE      "ImageBufferModule"             // CH: 缓存图像模块 | EN: Cache image module
#define MODU_NAME_GRAYMATCHMODU          "IMVSGrayMatchModu"             // CH: 灰度模型匹配模块 | EN: Grayscale model matching module
#define MODU_NAME_COLORRECOGNITIONMODU   "IMVSColorRecognitionModu"      // CH: 颜色识别模块 | EN: Color distinguish module
#define MODU_NAME_IMAGECORRECTMANUALMODU "IMVSImageCorrectManualModu"    // CH: 图像矫正模块 | EN: Image correction module
#define MODU_NAME_CAMERAIOMODULE         "CameraIOModule"                // CH: 相机IO通信模块 | EN: Camera IO communication module

// CH: V3.3.0新增模块 | EN: V3.3.0 new modules
#define MODU_NAME_IMAGESOURCEMODULE      "ImageSourceModule"             // CH: 图像源模块 | EN: Image source module
#define MODU_NAME_LIGHTMODULE            "LightModule"                   // CH: 光源模块 | EN: Light module
#define MODU_NAME_QUADRANGEFINDMODULE    "IMVSQuadrangleFindModu"        // CH: 四边形查找模块 | EN: Quadrangle find module
#define MODU_NAME_LINEFINDGROUPMODULE    "IMVSLineFindGroupModu"         // CH: 直线查找组合模块 | EN: Line find group module
#define MODU_NAME_MULTILINEFINDMODULE    "IMVSMultiLineFindModu"         // CH: 多直线查找模块 | EN: Multi-line find module
#define MODU_NAME_MAPCALIBMODULE         "IMVSMapCalibModu"              // CH: 映射标定模块 | EN: Mapping calibration module
#define MODU_NAME_NIMGCALIBMODULE        "IMVSNImageCalibModu"           // CH: N图像标定模块 | EN: N-Image calibration module
#define MODU_NAME_IMGSTITCHMODULE        "IMVSImgStitchCalibModu"        // CH: 图像拼接模块 | EN: Image stitching module
#define MODU_NAME_GEOMETRICTRANSFORMMODULE "IMVSGeometricTransformModu"  // CH: 几何变换模块 | EN: Geometric transform module
#define MODU_NAME_DATASETMODULE          "DataSetModule"                 // CH: 数据集合模块 | EN: Data set module
#define MODU_NAME_DATAASSEMBLEMODULE     "DataAssembleModule"            // CH: 协议组装模块 | EN: Protocol assemble module
#define MODU_NAME_DATAANALYSISMODULE     "DataAnalysisModule"            // CH: 协议解析模块 | EN: Protocol analysis module
#define MODU_NAME_CNNSINGLECHARDETECTMODU "IMVSCnnSingleCharDetectModu"  // CH: 深度学习单字符检测模块 （GPU版本） | EN: Single character detection module (for deep learning), GPU version
#define MODU_NAME_CNNSINGLECHARDETECTMODUC "IMVSCnnSingleCharDetectModuC"// CH: 深度学习单字符检测模块 （CPU版本） | EN: Single character detection module (for deep learning), CPU version
#define MODU_NAME_GROUPMODULE            "IMVSGroup"                     // CH: Group模块 | EN: Group module

// CH: V3.4.0新增模块 | EN: V3.4.0 new modules
#define MODU_NAME_MARKFINDMODULE         "IMVSMarkFindModu"              // CH: 图形定位模块 | EN: Graphic positioning module
#define MODU_NAME_BLOBFINDLABELSMODU     "IMVSBlobFindLabelsModu"        // CH: Blob标签分析模块 | EN: BLOB (Binary Large Object) labels analysis module
#define MODU_NAME_2DGRADEMODU            "IMVS2dGradeModu"               // CH: 二维码等级模块 | EN: QR code grade module
#define MODU_NAME_GLUEPATHCONDUCTMODU    "IMVSGluePathConductModu"       // CH: 胶路引导模块 | EN: Glue guide module
#define MODU_NAME_BRANCHENDMODU          "BranchEndModule"               // CH: 分支结束模块 | EN: Branch end module
#define MODU_NAME_COMMTRIGGERMODU        "CommTriggerModule"             // CH: 通信触发模块 | EN: Communication trigger module
#define MODU_NAME_OCRDLMODUC             "IMVSOcrDlModuC"                // CH: 深度学习字符识别模块 （CPU版本） | EN: OCR (Optical Character Recognition) module (for deep learning), CPU version
#define MODU_NAME_CNNCODERECGMODU        "IMVSCnnCodeRecgModu"           // CH: 深度学习读码模块 （GPU版本） | EN: Code recognition module (for deep learning), GPU version
#define MODU_NAME_CNNCODERECGMODUC       "IMVSCnnCodeRecgModuC"          // CH: 深度学习读码模块 （CPU版本） | EN: Code recognition module (for deep learning), CPU version
#define MODU_NAME_CNNRETRIEVALMODU       "IMVSCnnRetrievalModu"          // CH: 深度学习图像检索模块 （GPU版本） | EN: Image retrieval module (for deep learning), GPU version
#define MODU_NAME_CNNRETRIEVALMODUC      "IMVSCnnRetrievalModuC"         // CH: 深度学习图像检索模块 （CPU版本） | EN: Image retrieval module (for deep learning), CPU version

// CH: V4.0新增模块 | EN: V4.0 new modules
#define MODU_NAME_CNNSEGMODUC            "IMVSCnnFlawModuC"              // CH: 深度学习图像分割模块 （CPU版本） | EN: Image segmentation module (for deep learning), CPU version
#define MODU_NAME_INSPECTMODU            "IMVSInspectModu"               // CH: 缺陷对比模块 | EN: Inspect module
#define MODU_NAME_MULTIIMAGEFUSIONMODU   "IMVSMultiImageFusionModu"      // CH: 多图融合模块 | EN: Multi image fusion module
#define MODU_NAME_IMAGEAQUISITIONMODULE  "ImageAcquisitionModule"        // CH: 多图采集模块 | EN: Image acquisition module
#define MODU_NAME_CNNINSPECTMODU         "IMVSCnnInspectModu"            // CH: DL异常检测模块（GPU版本） | EN: Inspect module (for deep learning), GPU version
#define MODU_NAME_CNNINSPECTMODUC        "IMVSCnnInspectModuC"           // CH: DL异常检测模块（CPU版本） | EN: Inspect module (for deep learning), CPU version

// CH: V4.1新增模块 | EN: V4.1 new modules
#define MODU_NAME_ANGLEBISECTORFINDMODU  "IMVSAngleBisectorFindModu"     // CH: 角平分线查找模块 | EN: Angle bisector line find module
#define MODU_NAME_MEDIANLINEFINDMODU     "IMVSMedianLineFindModu"        // CH: 中线查找模块 | EN: Median line find module
#define MODU_NAME_PARALLELCALCULATEMODU  "IMVSParallelCalculateModu"     // CH: 平行线计算模块 | EN: Parallel line calculate module
#define MODU_NAME_VERTICALLINEFINDMODU   "IMVSVerticalLineFindModu"      // CH: 垂线查找模块 | EN: Vertical line find module
#define MODU_NAME_READCALIBFILEMODU      "ReadCalibFileModu"             // CH: 标定加载模块 | EN: Read calibration file module
#define MODU_NAME_ROTATECALCULATEMODU    "IMVSRotateCalculateModu"       // CH: 旋转计算模块 | EN: Rotate calculate module
#define MODU_NAME_CNNINSTANCESEGMENTMODU "IMVSCnnInstanceSegmentModu"    // CH: DL实例分割模块（GPU版本） | EN: Instance segment module (for deep learning), GPU version
#define MODU_NAME_CNNINSTANCESEGMENTMODUC "IMVSCnnInstanceSegmentModuC"  // CH: DL实例分割模块（CPU版本） | EN: Instance segment module (for deep learning), CPU version
#define MODU_NAME_MARKINSPMODUVA         "IMVSMarkInspModuVA"            // CH: 字符缺陷检测模块（V4.1版本） | EN: Character defect detection module, 4.1 version

// CH: V4.2新增模块 | EN: V4.2 new modules
#define MODU_NAME_COORDINATETRANSFORMMODU "CoordinateTransform"          // CH: 坐标转化模块 | EN: Coordinate Transform Module
#define MODU_NAME_ARRAY2DCORRECTMODU      "IMVS2dArrayCorrectModu"       // CH: 二维阵列模块 | EN: 2D Array Correct Module
#define MODU_NAME_BOXFILTERMODU           "IMVSBoxFilterModule"          // CH: Box过滤模块 | EN: Box Filter Module
#define MODU_NAME_BOXMERGEMODU            "IMVSBoxMergeModu"             // CH: Box融合模块 | EN: Box Merge Module
#define MODU_NAME_BOXOVERLAPCALCULATIONMODU  "IMVSBoxOverlapCalculationModu"    // CH: Box重叠率模块 | EN: Box Overlap Calculation Module
#define MODU_NAME_TARGETTRACKMODU         "IMVSTargetTrackModu"          // CH: 目标跟踪模块 | EN: Target Track Module
#define MODU_NAME_GRAPHICSSETMODU         "GraphicsSetModule"            // CH: 图形收集模块 | EN: Graphics Set Module
#define MODU_NAME_IMAGERESIZEMODU         "IMVSImageResizeModu"          // CH: 图像缩放模块 | EN: Image Resize Module
#define MODU_NAME_DIVIDEIMAGEMODU         "IMVSDivideImageModu"          // CH: 划片模块模块 | EN: Divide Image Module
#define MODU_NAME_MULTILABELFILTERMODU    "IMVSMultiLabelFilterModu"     // CH: 多标签筛选模块 | EN: MultiLabel Filter Module
#define MODU_NAME_EDGEPOSTRENDANALYMODU   "IMVSEdgePosTrendAnalyModu"    // CH: 边缘位置趋势分析模块 | EN: Edge position trend analy module
#define MODU_NAME_EDGEPAIRPOSTRENDANALYMODU  "IMVSEdgePairPosTrendAnalyModu"    // CH: 边缘对位置趋势分析模块 | EN: Edge pair position trend analy module
#define MODU_NAME_IFBRANCHMODU            "IfBranchModule"               // CH: 条件分支 | EN: Condition-Branch
#define MODU_NAME_TRIGGERMODU             "TriggerModule"                // CH: 触发模块 | EN: Trigger Module
#define MODU_NAME_CNNUNSUPERVISEDMODU     "IMVSCnnUnSupervisedModu"      // CH: DL无监督GPU | EN: DL UnSupervised GPU

// CH: V4.2维护新增模块 | EN: V4.2 Maintenance new modules
#define MODU_NAME_SURFACEDEFECTFILTERMODU  "IMVSSurfaceDefectFilterModu" // CH: 表面缺陷滤波 | EN: Surface Defect Filter
#define MODU_NAME_ROTATECALIBMODU         "RotateCalibModu"              // CH: 旋转标定 | EN: Rotate Calibration Module
#define MODU_NAME_SINGLEPOINTMAPALIGNMODU  "SinglePointMapAlignModu"     // CH: 单点映射对位 | EN: Single Point Map Align Module
#define MODU_NAME_SINGLEPOINTGRABMODU     "SinglePointGrabModu"          // CH: 单点抓取 | EN: Single Point Grab Module
#define MODU_NAME_SINGLEPOINTRECTIFYMODU  "SinglePointRectifyModu"       // CH: 单点纠偏 | EN: Single Point Rectify Module
#define MODU_NAME_TRANSLATIONCALIBMODU    "TranslationCalibModu"         // CH: 平移旋转标定 | EN: Translation Calibration Module
#define MODU_NAME_GRAYMATCHVAMODU         "IMVSGrayMatchModuVA"          // CH: 灰度匹配 | EN: Gray Model Match Module

// CH: V4.3新增模块 | EN: V4.3 new modules
#define MODU_NAME_CONTOURMATCHMODU  "IMVSContourMatchModu"               // CH: 轮廓匹配 | EN: IMVSContourMatchModu
#define MODU_NAME_INVERSEAFFINETRANSFORMMODU  "IMVSInverseAffineTransformModu"    // CH: 逆仿射变换 | EN: IMVSInverseAffineTransformModu
#define MODU_NAME_ELLIPSEFITMODU  "IMVSEllipseFitModu"                  // CH: 椭圆拟合 | EN: IMVSEllipseFitModu
#define MODU_NAME_ELLIPSEFINDMODU  "IMVSEllipseFindModu"                // CH: 椭圆查找 | EN: IMVSEllipseFindModu

// CH: V4.3维护新增模块 | EN: V4.3 Maintenance new modules
#define MODU_NAME_MACHINELEARNINGCLASSIFIERMODU  "IMVSMachineLearningClassifierModu"    // CH: ML分类 | EN: Machine Learning Classifier
#define MODU_NAME_CNNREGISTERCLASSIFYMODU  "IMVSCnnRegisterClassifyModu"    // CH: 注册分类G | EN: Register Classify GPU
#define MODU_NAME_CNNREGISTERCLASSIFYMODUC  "IMVSCnnRegisterClassifyModuC"    // CH: 注册分类C | EN: Register Classify CPU
#define MODU_NAME_CNNFASTFLAWMODU  "IMVSCnnFastFlawModu"    // CH: DL快速图像分割 | EN: IMVSCnnFastFlawModu
#define MODU_NAME_MATRIXCIRCLEFINDMODU  "IMVSMatrixCircleFindModu"    // CH: 阵列圆查找 | EN: Matrix Circle Find
#define MODU_NAME_PIXELCOUNTVAMODU  "IMVSPixelCountModuVA"    // CH: 像素统计 | EN: Pixel Count

/*************************************************************************
 * 常见宏定义
 * Common macro definitions
 *************************************************************************/
const static unsigned int IMVS_PF_MAX_MODULE_NAME_LENGTH         = 64;         // CH: 模块名称最大长度 | EN: Maximum length of module name
const static unsigned int IMVS_PF_MAX_MODULE_DISPLAY_NAME_LENGTH = 256;        // CH: 模块显示名称最大长度 | EN: Maximum length of module display name
const static unsigned int IMVS_PF_MAX_MODULE_NUM                 = 1040;       // CH: 最大模块个数 | EN: Maximum number of modules
const static unsigned int IMVS_PF_MAX_MODULE_PARAM_NUM           = 128;        // CH: 最大模块参数个数 | EN: Maximum number of module parameters
const static unsigned int IMVS_PF_STATUS_FILTER_RECEIVE          = 1;          // CH: 过滤状态: 接收信息 | EN: Filtering status: receiving information
const static unsigned int IMVS_PF_STATUS_FILTER_NOT_RECEIVE      = 0;          // CH: 过滤状态: 不接收信息 | EN: Filtering status: not receiving information
const static unsigned int IMVS_PF_MAX_DATATYPE_NUM               = 32;         // CH: 数据类型最大个数 | EN: Maximum number of data types
const static unsigned int IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH    = 128;        // CH: 模块结果名称最大长度 | EN: Maximum length of module result name
const static unsigned int IMVS_PF_MAX_MODULE_RESVALUE_LENGTH     = 4096;       // CH: 模块结果值最大长度 | EN: Maximum length of module result value
const static unsigned int IMVS_PF_MAX_MODULE_PARAMVALUE_LENGTH   = 512;        // CH: 模块参数值最大长度 | EN: Maximum length of module parameter value
const static unsigned int IMVS_PF_INPUT_NO_PASSWORD              = 0;          // CH: 无密码状态输入值 | EN: Input value in the status without password
const static unsigned int IMVS_PF_DEFAULT_WAITTIME               = 10000;      // CH: 默认等待时间 | EN: Default waiting time
const static unsigned int IMVS_PF_MAX_IMPORT_NUM                 = 16;         // CH: 最大导入数据文件数量 | EN: Maximum number of imported data files
const static unsigned int IMVS_PF_STATUS_HAS_PASSWORD            = 1;          // CH: 方案文件有密码 | EN: Solution file with password
const static unsigned int IMVS_PF_STATUS_HAS_NO_PASSWORD         = 0;          // CH: 方案文件无密码 | EN: Solution file without password
const static unsigned int IMVS_PF_STATUS_PLATFORM_SHOW           = 1;          // CH: 平台界面显示状态 | EN: Status of showing platform interface
const static unsigned int IMVS_PF_STATUS_PLATFORM_HIDE           = 0;          // CH: 平台界面隐藏状态 | EN: Status of hiding platform interface
const static unsigned int IMVS_PF_MAX_PATH_LENGTH                = 260;        // CH: 路径最大长度值 | EN: Maximum length of path
const static unsigned int IMVS_PF_PASSWORD_LENGTH                = 32;         // CH: 密码长度值 | EN: Maximum length of password
const static unsigned int IMVS_PF_VERSION_LENGTH                 = 32;         // CH: 版本信息长度值 | EN: Maximum length of version information
const static unsigned int IMVS_PF_MAX_PROCESS_NAME_LENGTH        = 64;         // CH: 流程名称最大长度 | EN: Maximum length of process name
const static unsigned int IMVS_PF_MAX_PROCESS_NUM                = 1000;       // CH: 最大流程个数 | EN: Maximum number of processes
const static unsigned int IMVS_PF_CHAR_RES_SIZE                  = 2;          // CH: 字符识别结果大小 | EN: Character recognition result size
const static unsigned int IMVS_PF_IMG_FORMAT_MONO8               = 0x01080001; // CH: 像素格式 MONO8 | EN: MONO8 pixel format
const static unsigned int IMVS_PF_IMG_FORMAT_RGB24               = 0x02180014; // CH: 像素格式 RGB24 | EN: RGB24 pixel format
const static unsigned int IMVS_PF_IMG_FORMAT_MONO16				 = 0x011000B8; // CH: 像素格式 MONO16| EN: MONO16 pixel format
const static unsigned int IMVS_PF_STATUS_PROCESS_SHIELD          = 1;          // CH: 流程禁用状态 | EN: Process disabled status
const static unsigned int IMVS_PF_STATUS_PROCESS_ENABLE          = 0;          // CH: 流程启用状态 | EN: Process enable status
const static unsigned int IMVS_PF_ALL_MODULE_CTRL_CALLBACK       = 30000;      // CH: 所有模块结果回调控制模块ID | EN: All module results callback control module ID
const static unsigned int IMVS_PF_IMAGE_BUFFER_NUM               = 5;          // CH: 缓存图像模块缓存图像数量 | EN: Number of cached images
const static unsigned int IMVS_PF_CAMPICINFO_LIST_NUM            = 256;        // CH: 相机图像信息列表数目 | EN: Number of camera information lists
const static unsigned int IMVS_PF_MAX_ATTACH_FRONTWND_NUM        = 16;         // CH: 最大嵌入前端运行界面数目 | EN: Maximum number of attached front-end running windows
const static unsigned int IMVS_PF_MODULE_GLOBAL_VAR              = 13000;      // CH: 全局变量模块ID | EN: Module ID of global variable
const static unsigned int IMVS_PF_STATUS_CALLBACK_START          = 1;          // CH: 开启回调状态 | EN: Turn on callback status
const static unsigned int IMVS_PF_STATUS_CALLBACK_STOP           = 0;          // CH: 停止回调状态 | EN: Turn off callback status
const static unsigned int IMVS_PF_MAX_FLAW_SCORE_IMAGE_NUM       = 8;          // CH: 最大缺陷概率图个数 | EN: Maximum number of defect probability images
const static unsigned int IMVS_PF_REENTRANT_MAX_CMD_LEN          = 16;         // CH: 可重入最大触发字符串长度 | EN: Maximum length of command string in reentrant
const static unsigned int IMVS_PF_CAMERA_MAX_SN_LEN              = 64;         // CH: 相机最大序列号长度 | EN: Maximum length of camera sn
const static unsigned int IMVS_PF_CAMERA_MAX_NAME_LEN            = 64;         // CH: 相机最大名称长度 | EN: Maximum length of camera name
const static unsigned int IMVS_PF_CAMERA_MAX_NUM                 = 256;        // CH: 相机最大数量 | EN: Maximum length of camera number

// CH: 模块结果类型宏定义 | EN: Module results type macro definition
const static unsigned int IMVS_PF_MODURES_TYPE_INT              = 1;          // CH: 整型数据 | EN: Integer data
const static unsigned int IMVS_PF_MODURES_TYPE_FLOAT            = 2;          // CH: 浮点型数据 | EN: Float data
const static unsigned int IMVS_PF_MODURES_TYPE_STRING           = 3;          // CH: 字符串型数据 | EN: String data
const static unsigned int IMVS_PF_MODURES_TYPE_IMAGE            = 4;          // CH: 图像型数据 | EN: Image data
const static unsigned int IMVS_PF_MODURES_TYPE_CHUNK            = 5;          // CH: 大数据类型数据 | EN: Data used for big data
const static unsigned int IMVS_PF_MODURES_TYPE_BYTEDATA         = 6;          // CH: 二进制数据类型数据 | EN: Binary data
const static unsigned int IMVS_PF_MODURES_TYPE_DOUBLE			= 7;          // CH: 浮点型数据 | EN: Double data

// CH: 导入数据类型 | EN: Import data types
const static unsigned int IMVS_PF_IMPORT_TYPE_TEMP              = 1;          // CH: 模板数据类型 | EN: Template data type
const static unsigned int IMVS_PF_IMPORT_TYPE_FONT              = 2;          // CH: 字库数据类型 | EN: Font library data type
const static unsigned int IMVS_PF_IMPORT_TYPE_CALIB             = 3;          // CH: 标定文件数据类型 | EN: Calibration file data type
const static unsigned int IMVS_PF_IMPORT_TYPE_DLN               = 4;          // CH: 深度学习模型文件数据类型 | EN: Font library of deep learning data type
const static unsigned int IMVS_PF_IMPORT_TYPE_IMAGE             = 5;          // CH: 图像数据类型 | EN: Image data type
const static unsigned int IMVS_PF_IMPORT_TYPE_MARKINSP          = 6;          // CH: 字符模板类型 | EN: Character template type
const static unsigned int IMVS_PF_IMPORT_TYPE_EDGEFLAW          = 7;          // CH: 边缘缺陷模板类型 | EN: Edge defect template type
const static unsigned int IMVS_PF_IMPORT_TYPE_COLORRECOGNITION   = 8;          // CH: 颜色识别模板类型 | EN: Color recognition template type
const static unsigned int IMVS_PF_IMPORT_TYPE_MARKFIND          = 9;          // CH: 图形定位模板类型 | EN: Mark find template type
const static unsigned int IMVS_PF_IMPORT_TYPE_GLUEPATHCONDUCT    = 10;          // CH: 路径提取模板类型 | EN: Glue path conduct template type
const static unsigned int IMVS_PF_IMPORT_TYPE_IMGSTITCHCALIB     = 11;          // CH: 图像拼接模板类型 | EN: Image stitch calib template type
const static unsigned int IMVS_PF_IMPORT_TYPE_INSPECT           = 12;          // CH: 缺陷对比模板类型 | EN: Inspect template type

/*************************************************************************
 * 枚举定义：回调函数中的输出算法平台信息类型
 * Enumeration definition: the type of output information in the callback function
 *************************************************************************/
typedef enum IMVS_CTRLC_OUTPUT_PlATFORM_INFO_TYPE__
{
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_MODULE_RESULT      = 0,    // CH: 模块输出结果信息 | EN: Module result
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_START_CONTINUOUSLY = 1,    // CH: 单个流程连续执行开始信息 | EN: Information of starting continuous execution of single process
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_STOP               = 2,    // CH: 单个流程停止执行状态信息 | EN: Information of stopping single process execution
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_WORK_STATE         = 3,    // CH: 流程工作状态信息 | EN: Process status information
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_HB_MODU            = 4,    // CH: 模块心跳异常信息（多进程版本） | EN: Module heartbeat exception information, multi-process version
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_HB_SERVER          = 5,    // CH: 服务心跳异常信息 | EN: Server heartbeat exception information
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_HB_CLIENT          = 6,    // CH: 平台界面心跳异常 | EN: Information of platform interface heartbeat exception
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_DONGLE             = 7,    // CH: 加密狗异常信息 | EN: Dongle status information
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_SOLUTION_LOAD_INTERFACE_FILE = 8,    // CH: 方案加载界面文件信息 | EN: The file information of solution loading interface
    IMVS_ENUM_CTRLC_OUTPUT_PlATFORM_INFO_SOLUTION_SAVE_END  = 9,    // CH: 保存结束状态信息 | EN: Status of ending solution saving
    IMVS_ENUM_CTRLC_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_END  = 10,   // CH: 加载结束状态信息 | EN: Status of ending solution loading
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_HB_SP_PROXY        = 11,   // CH: 模块进程心跳异常信息（单进程版本） | EN: Module proxy heartbeat exception information, single-process version
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_GLOBALSCRIPT_CRASH = 12,   // CH: 全局脚本异常信息 | EN: Global script exception information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_LOAD_MODULE_WARN   = 13,   // CH: 方案加载时模块错误警告信息 | EN: Load module error warning information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_EXPORT_PROCESS_END = 14,   // CH: 导出流程结束信息 | EN: Export process end information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_IMPORT_PROCESS_END = 15,   // CH: 导入流程结束信息 | EN: Import process end information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_PROCEDURE_UNREGISTER = 16, // CH: 流程解注册信息 | EN: Process deregister information
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_CAMERA_COLLECT     = 17,   // CH: 相机取图结束信息 | EN: Camera collect end information
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_COMMUNICATION_CONNECT = 18,  // CH: 通信连接信息 | EN: Communication connect information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_CAMERA_COLLECT_START  = 19,  // CH: 相机取图开始信息 | EN: Camera collect start information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_CAMERA_CONNECT_STATUS = 20,  // CH: 相机连接状态信息   | EN: Camera connect status information

} IMVS_CTRLC_OUTPUT_PlATFORM_INFO_TYPE;

/*************************************************************************
 * 结构体定义
 * Structure definition
 *************************************************************************/
// CH: 输出算法平台信息结构 | EN: Algorithm platform information structure
typedef struct IMVS_PF_OUTPUT_PLATFORM_INFO__
{
    unsigned int  nInfoType;                                // CH: 回调信息类型 | EN: Callback information type
    unsigned int  nDataSize;                                // CH: 回调数据分配内存 | EN: Size of memory allocated for saving callback data
    unsigned int  nDataLen;                                 // CH: 回调数据实际长度 | EN: Actual size of callback data
    void *        pData;                                    // CH: 回调数据 | EN: Callback data details
    unsigned int  nReserved[4];                             // CH: 保留字段 | EN: Reserved
} IMVS_PF_OUTPUT_PLATFORM_INFO;

// CH: 模块结果信息结构 | EN: Module results information structure
typedef struct IMVS_PF_MODULE_STRING_VALUE__
{
    char            strValue[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: 字符串数据 | EN: String data
    unsigned int    nReserved[4];    // CH: 保留字段 | EN: Reserved
} IMVS_PF_MODULE_STRING_VALUE;       // CH: 字符串数据类型 | EN: String data structure

typedef struct IMVS_PF_MODULE_IMAGE_VALUE_
{
    char *          pData;               // CH: 实际数据 | EN: Actual data
    unsigned int    nLen;                // CH: 实际数据长度 | EN: Actual data size
    char            strReserved[260];    // CH: 保留字段 | EN: Reserved
    unsigned int    nReserved[4];        // CH: 保留字段 | EN: Reserved
} IMVS_PF_MODULE_IMAGE_VALUE;            // CH: 图像数据类型 | EN: Image data structure

typedef struct IMVS_PF_MODULE_CHUNK_VALUE__
{
    char *          pData;               // CH: 实际数据 | EN: Actual data
    unsigned int    nLen;                // CH: 实际数据长度 | EN: Actual data size
    char            strReserved[260];    // CH: 保留字段 | EN: Reserved
    unsigned int    nReserved[4];        // CH: 保留字段 | EN: Reserved
} IMVS_PF_MODULE_CHUNK_VALUE;            // CH: 大数据类型 | EN: Big data structure

typedef struct IMVS_PF_MODULE_BYTEDATA_VALUE_
{
	char *          pData;               // CH: 实际数据 | EN: Actual data
	unsigned int    nLen;                // CH: 实际数据长度 | EN: Actual data size
	unsigned int    nReserved[4];        // CH: 保留字段 | EN: Reserved
} IMVS_PF_MODULE_BYTEDATA_VALUE;

typedef struct IMVS_PF_MODULE_RESULT_INFO__
{
    int             nValueStatus;                                         // CH: 单个输出参数的状态 1成功，其他值失败 | EN: Status of a single module, 1-succeeded, other values-error codes
    char            strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH];    // CH: 模块结果名称 | EN: Module result name
    int             nParamType;                                           // CH: 模块结果类型:1整型 2浮点型 3字符串型 4表示图像 5表示大数据 | EN: Module result type: 1-integer, 2-float, 3-string, 4-image, 5-big data
    int             nValueNum;                                            // CH: 模块值个数 | EN: Number of module values
    int *           pIntValue;                                            // CH: 整型数据 | EN: Integer data
    float *         pFloatValue;                                          // CH: 浮点型数据 | EN: Float data
	double *        pDoubleValue;                                         // CH: 浮点型数据 | EN: Double data
    IMVS_PF_MODULE_STRING_VALUE * pstStringValue;                         // CH: 字符串型数据 | EN: String data
    IMVS_PF_MODULE_IMAGE_VALUE  * pstImageValue;                          // CH: 图像数据 | EN: Image data
    IMVS_PF_MODULE_CHUNK_VALUE  * pstChunkValue;                          // CH: 大数据 | EN: Big data
	IMVS_PF_MODULE_BYTEDATA_VALUE * pstByteValue;                         // CH: 二进制数据 | EN: Binary data
    unsigned int    nReserved[4];                                         // CH: 保留字段 | EN: Reserved
} IMVS_PF_MODULE_RESULT_INFO;                                             // CH: 模块结果信息 | EN: Module result details

typedef struct IMVS_PF_MODULE_RESULT_INFO_LIST__
{
    // CH: 模块结果基本信息 | EN: Module results basic information
    unsigned int    nStatus;                // CH: 整个模块的状态 1成功，其他值，异常 | EN: Module status, 1-succeeded, other values-error code
	unsigned int    nErrorCode;             // CH: 模块异常时底层返回的错误码 | EN: Error code returned when the module is abnormal
    unsigned int    nProcessID;             // CH: 流程ID | EN: Process ID
    unsigned int    nModuleID;              // CH: 模块ID | EN: Module ID
    float           fModuleTime;            // CH: 模块时间，从输入数据全部到达开始计算，从将所有数据发送出去结束计算 | EN: Module time
    float           fAlgorithmTime;         // CH: 算法时间 | EN: Algorithm time
    unsigned int    nInCycle;               // CH: 是否为循环内模块 | EN: Whether it is the module in the loop
    char *          pstrModuleName;         // CH: 模块名称 | EN: Module name
    char *          pstrDisplayName;        // CH: 模块显示名称 | EN: Displayed module name
    char *          pReserved[8];           // CH: 保留字段 | EN: Reserved
    char            strReserved[60];        // CH: 保留字段 | EN: Reserved
    unsigned int    nReserved1[2];           // CH: 保留字段 | EN: Reserved
    unsigned int    nExecuteCount;          // CH: 执行次数 | EN: Execute Count
    unsigned int    nReserved2[1];           // CH: 保留字段 | EN: Reserved

    // CH: 模块结果具体数据 | EN: Module results data
    int             nResultNum;                   // CH: 模块结果数量 | EN: Number of module results
    IMVS_PF_MODULE_RESULT_INFO * pModuResInfo;    // CH: 模块结果 | EN: Module result details

    char            strReCommand[IMVS_PF_REENTRANT_MAX_CMD_LEN];  // CH: 可重入触发字符串 | EN: Command string in reentrant
    unsigned int    nReservedEx[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_MODULE_RESULT_INFO_LIST;

// CH: 加密狗状态信息结构 | EN: Dongle status information structure
typedef struct IMVS_PF_DONGLE_INFO__
{
    unsigned int    nDongleStatus;  // CH: 加密狗状态 | EN: Dongle status
    unsigned int    nReserved[4];   // CH: 保留字段 | EN: Reserved
} IMVS_PF_DONGLE_INFO;

// CH: 流程状态信息结构 | EN: Process status information structure
typedef struct IMVS_PF_MODULE_WORK_STAUS__
{
	unsigned int    nProcessID;     // CH: 流程ID | EN: Process ID
	unsigned int    nWorkStatus;    // CH: 0是空闲，1是忙碌 | EN: Work status, 0-idle, 1-busy
    unsigned int    nIsTimeValid;   // CH: 流程时间有效性 | EN: Is process time valid
    float           fProcessTime;   // CH: 流程时间 | EN : Process Time
    unsigned int    nExecuteCount;  // CH: 执行次数 | EN: Execute Count
    char            strReCommand[IMVS_PF_REENTRANT_MAX_CMD_LEN];  // CH: 可重入触发字符串 | EN: Command string in reentrant
	unsigned int    nReserved[4];   // CH: 保留字段 | EN: Reserved
} IMVS_PF_MODULE_WORK_STAUS;

// CH: 方案加载界面文件信息结构 | EN: Structure about solution loading interface information
typedef struct IMVS_PF_SOLUTION_LOAD_INTERFACE_FILE_INFO__
{
    unsigned char * pData;          // CH: 文件信息数据 | EN: File data
    unsigned int    nDataLen;       // CH: 文件信息长度 | EN: File data length
    unsigned int    nReserved[4];   // CH: 保留字段 | EN: Reserved
} IMVS_PF_SOLUTION_LOAD_INTERFACE_FILE_INFO;

// CH: 连续执行开始状态信息结构 | EN: Structure about information of starting continuous execution of single process
typedef struct IMVS_PF_STATUS_START_CONTINUOUSLY_INFO__
{
    unsigned int    nStatus;       // CH: 状态值 | EN: Status value
    unsigned int    nProcessID;    // CH: 流程ID | EN: Process ID
    unsigned int    nReserved[3];  // CH: 保留字段 | EN: Reserved
} IMVS_PF_STATUS_START_CONTINUOUSLY_INFO;

// CH: 停止执行状态信息结构 | EN: Structure about information of stopping single process execution
typedef struct IMVS_PF_STATUS_STOP_INFO__
{
    unsigned int    nStatus;       // CH: 状态值 | EN: Status value
    unsigned int    nProcessID;    // CH: 流程ID | EN: Process ID
	unsigned int    nStopAction;   // CH: 流程停止的原因 (0:无效; 1:正常停止; 2:流程NG; 3:模块请求停止流程) | EN: Reason for process stop (0: invalid; 1: normal stop; 2: process NG; 3: Module request to stop process)
    unsigned int    nReserved[2];  // CH: 保留字段 | EN: Reserved
} IMVS_PF_STATUS_STOP_INFO;

// CH: 模块心跳异常信息结构 | EN: Heartbeat exception information structure of module
typedef struct IMVS_PF_EXCEPTION_HB_MODULE_INFO__
{
    unsigned int    nModuleID;                                              // CH: 模块ID | EN: Module ID
    unsigned int    nProcessID;                                             // CH: 流程ID | EN: Process ID
    char            strModuleName[IMVS_PF_MAX_MODULE_NAME_LENGTH];          // CH: 模块名称 | EN: Module name
	char            strDisPlayName[IMVS_PF_MAX_MODULE_DISPLAY_NAME_LENGTH]; // CH: 模块显示名称 | EN: Displayed module name
    unsigned int    nReserved[4];                                           // CH: 保留字段 | EN: Reserved
} IMVS_PF_EXCEPTION_HB_MODULE_INFO;

// CH: 服务心跳异常信息结构 | EN: Structure about abnormal service heartbeat information
typedef struct IMVS_PF_EXCEPTION_HB_SERVER_INFO__
{
    unsigned int    nServerStatus;    // CH: Server状态: 0表示正常，其他表示错误码 | EN: Server status: 0-normal, other value- error codes
    unsigned int    nReserved[4];     // CH: 保留字段 | EN: Reserved
} IMVS_PF_EXCEPTION_HB_SERVER_INFO;

// CH: 平台界面心跳异常信息结构 | EN: Structure about information of abnormal platform interface heartbeat
typedef struct IMVS_PF_EXCEPTION_HB_CLIENT_INFO__
{
    unsigned int    nClientStatus;  // CH: Client状态: 0表示正常，其他表示错误码 | EN: Client status: 0-normal, other value-error code
    unsigned int    nReserved[4];   // CH: 保留字段 | EN: Reserved
} IMVS_PF_EXCEPTION_HB_CLIENT_INFO;

// CH: 保存结束状态信息结构 | EN: Status information structure of ending saving solution
typedef struct IMVS_PF_SOLUTION_SAVE_END_INFO__
{
    unsigned int    nClientType;  // CH: 客户端类型 | EN: Client type
    unsigned int    nStatus;      // CH: 保存结束状态 | EN: Status information
	char            strSolPath[IMVS_PF_MAX_PATH_LENGTH]; // CH: 方案路径 | EN: Solution path
    unsigned int    nReserved[4]; // CH: 保留字段 | EN: Reserved
} IMVS_PF_SOLUTION_SAVE_END_INFO;

// CH: 加载结束状态信息结构 | EN: Status information structure of ending solution loading
typedef struct IMVS_PF_SOLUTION_LOAD_END_INFO__
{
    unsigned int    nClientType;  // CH: 客户端类型 | EN: Client type
    unsigned int    nStatus;      // CH: 加载结束状态 | EN: Status information
	char            strSolPath[IMVS_PF_MAX_PATH_LENGTH]; // CH: 方案路径 | EN: Solution path
    unsigned int    nReserved[4]; // CH: 保留字段 | EN: Reserved
} IMVS_PF_SOLUTION_LOAD_END_INFO;

// CH: 模块进程心跳异常信息结构 | EN: Heartbeat exception information structure of module proxy
typedef struct IMVS_PF_EXCEPTION_HB_SP_PROXY_INFO__
{
	unsigned int    nSolStatu;               // CH: 方案是否存在状态 0：方案不存在，1：方案存在 | EN: Solution exists status, 0:solution not exist, 1: solution exist
	unsigned int    nReserved[4];            // CH: 保留字段 | EN: Reserved
} IMVS_PF_EXCEPTION_HB_SP_PROXY_INFO;

// CH: 全局脚本模块异常信息结构 | EN: Exception information structure of global script module
typedef struct IMVS_PF_GLOBALSCRIPT_CRASH_INFO__
{
	unsigned int    nStatus;                 // CH: 全局脚本崩溃状态 | EN: Global script crash status
	unsigned int    nReserved[4];            // CH: 保留字段 | EN: Reserved
} IMVS_PF_GLOBALSCRIPT_CRASH_INFO;

// CH: 加载方案上报错误信息结构 | EN: Load module error warning information structure
typedef struct IMVS_PF_LOAD_MODULE_ERROR_INFO__
{
	unsigned int nModuleID;                                     // CH: 模块ID | EN: Module ID
	char         strModuleName[IMVS_PF_MAX_MODULE_NAME_LENGTH]; // CH: 模块名称 | EN: Module name
	int          nErrorCode;                                    // CH: 错误码 | EN: Error code
} IMVS_PF_LOAD_MODULE_ERROR_INFO;

// CH: 加载方案上报错误信息列表结构 | EN: Load module error warning information list structure
typedef struct IMVS_PF_LOAD_MODULE_ERROR_INFO_LIST__
{
	unsigned int nClientType;                   // CH: 客户端类型 | EN: Client type
	unsigned int nModuleNum;                    // CH: 上报错误信息模块数量 | EN: Module number
	IMVS_PF_LOAD_MODULE_ERROR_INFO astLoadModuErrInfo[IMVS_PF_MAX_MODULE_NUM]; // CH: 加载方案上报错误信息 | EN: Load module error warning information
	unsigned int nReserved[4];                  // CH: 保留字段 | EN: Reserved
} IMVS_PF_LOAD_MODULE_ERROR_INFO_LIST;

// CH: 导出流程结束状态信息结构 | EN: Status information structure of ending process exporting
typedef struct IMVS_PF_EXPORT_PROCESS_END_INFO__
{
	unsigned int    nProcessId;                             // CH: 流程ID | EN: Process id
	char            strProcPath[IMVS_PF_MAX_PATH_LENGTH];   // CH: 流程文件路径 | EN: The path of process file
	int             nErrorCode;                             // CH: 错误码 | EN: Error code
	unsigned int    nReserved[4];                           // CH: 保留字段 | EN: Reserved
} IMVS_PF_EXPORT_PROCESS_END_INFO;

// CH: 导入流程结束状态信息结构 | EN: Status information structure of ending process importing
typedef struct IMVS_PF_IMPORT_PROCESS_END_INFO__
{
	unsigned int    nProcessId;                                   // CH: 流程ID | EN: Process id
	char            strProcName[IMVS_PF_MAX_PROCESS_NAME_LENGTH]; // CH: 流程名称 | EN: Process name
	int             nErrorCode;                                   // CH: 错误码 | EN: Error code
	unsigned int    nReserved[4];                                 // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMPORT_PROCESS_END_INFO;

// CH: 流程解注册信息 | EN: Process deregister information
typedef struct IMVS_PF_PROCEDURE_UNREGISTER_INFO__
{
	unsigned int    nClientType;                                  // CH: 客户端类型 | EN: Client type
	unsigned int    nProcessID;                                   // CH: 删除流程ID | EN: The id of deleted process
	int             nErrorCode;                                   // CH: 删除流程状态 | EN: The error code of deleted process
	char            strProcessName[IMVS_PF_MAX_PROCESS_NAME_LENGTH]; // CH: 流程名称 | EN: Process name
	unsigned int    nReserved[4];                                 // CH: 保留字段 | EN: Reserved
} IMVS_PF_PROCEDURE_UNREGISTER_INFO;

// CH: 单个模块信息结构 | EN: Module information structure
typedef struct IMVS_PF_MODULE_INFO__
{
    unsigned int    nModuleID;                                              // CH: 模块ID | EN: Module ID
    unsigned int    nProcessID;                                             // CH: 流程ID | EN: Process ID
	char            strDisplayName[IMVS_PF_MAX_MODULE_DISPLAY_NAME_LENGTH]; // CH: 界面显示名称 | EN: Displayed module name
    char            strModuleName[IMVS_PF_MAX_MODULE_NAME_LENGTH];          // CH: 模块名称 | EN: Module name
    unsigned int    nReserved[128];                                         // CH: 保留字段 | EN: Reserved
} IMVS_PF_MODULE_INFO;

// CH: 模块信息列表结构 | EN: Module information list structure
typedef struct IMVS_PF_MODULE_INFO_LIST__
{
    unsigned int           nNum;                                     // CH: 模块个数 | EN: Number of modules in list
    IMVS_PF_MODULE_INFO    astModuleInfo[IMVS_PF_MAX_MODULE_NUM];    // CH: 模块信息列表 | EN: Information details of a module
    unsigned int           nReserved[4];                             // CH: 保留字段 | EN: Reserved
} IMVS_PF_MODULE_INFO_LIST;

// CH: 模块参数信息结构 | EN: Module parameter structure
typedef struct IMVS_PF_MODULE_PARAM__
{
    char            strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH];      // CH: 参数名称 | EN: Parameter name
    char            strParamValue[IMVS_PF_MAX_MODULE_PARAMVALUE_LENGTH];    // CH: 参数值 | EN: Parameter value
    unsigned int    nReserved[16];                                          // CH: 保留字段 | EN: Reserved
}IMVS_PF_MODULE_PARAM;

// CH: 模块参数列表信息结构 | EN: Module parameter list structure
typedef struct IMVS_PF_MODULE_PARAM_LIST__
{
    unsigned int          nParamNum;                                          // CH: 参数个数 | EN: The number of parameters in the list
    IMVS_PF_MODULE_PARAM  stModuleParamList[IMVS_PF_MAX_MODULE_PARAM_NUM];    // CH: 模块参数 | EN: Module parameters in list
    unsigned int          nReserved[4];                                       // CH: 保留字段 | EN: Reserved
}IMVS_PF_MODULE_PARAM_LIST;

// CH: 模块过滤信息结构 | EN: Module filtering information structure
typedef struct IMVS_PF_FILTER_MODULE__
{
    unsigned int    nModuleID;       // CH: 模块ID | EN: Module ID
    unsigned int    nReserved[4];    // CH: 保留字段 | EN: Reserved
}IMVS_PF_FILTER_MODULE;

// CH: 数据类型过滤信息结构 | EN: Structure about information of data type filtering
typedef struct IMVS_PF_FILTER_DATATYPE__
{
    unsigned int    nDataType;           // CH: 数据类型 | EN: Data type
    unsigned int    nReserved[4];        // CH: 保留字段 | EN: Reserved
}IMVS_PF_FILTER_DATATYPE;

// CH: 过滤条件信息结构 | EN: Filter condition information structure
typedef struct IMVS_PF_FILTER_CONDITION_LIST__
{
    unsigned int               nModuNum;                                   // CH: 模块过滤信息数量 | EN: The number of module filtering information
    unsigned int               nDataTypeNum;                               // CH: 数据类型过滤信息数量 | EN: The number of data type filtering information
    unsigned int               nModuStatus;                                // CH: 模块过滤状态 | EN: Module filtering status
    unsigned int               nDataTypeStatus;                            // CH: 数据类型过滤状态 | EN: Data type filtering status
    IMVS_PF_FILTER_MODULE      stFilterModule[IMVS_PF_MAX_MODULE_NUM];     // CH: 模块过滤信息 | EN: Module filtering information
    IMVS_PF_FILTER_DATATYPE    stFilterDataType[IMVS_PF_MAX_DATATYPE_NUM]; // CH: 数据类型过滤信息 | EN: Information of data type filtering
    unsigned int               nReserved[4];                               // CH: 保留字段 | EN: Reserved
}IMVS_PF_FILTER_CONDITION_LIST;

// CH: 保存平台方案输入参数信息结构 | EN: Structure about inputted parameters information when saving platform solution
typedef struct IMVS_PF_SAVE_SOLUTION_INPUT__
{
    char                strPath[IMVS_PF_MAX_PATH_LENGTH];    // CH: 保存方案绝对路径 | EN: Solution files saving path
    char                strPassWord[IMVS_PF_PASSWORD_LENGTH];// CH: 保存方案密码 | EN: Password of the saved solution file
    unsigned char *     pAdditionData;                       // CH: 保存方案附加自定义数据 | EN: Custom data while saving the solution file
    unsigned int        nDataLen;                            // CH: 保存方案附加自定义数据长度 | EN: Custom data length while saving the solution file
    unsigned int        nReserved[4];                        // CH: 保留字段 | EN: Reserved
}IMVS_PF_SAVE_SOLUTION_INPUT;

// CH: 向模块导入数据输入参数信息结构 | EN: Module input parameter structure
typedef struct IMVS_PF_IMPORT_MODULE_DATA__
{
    char *             pData;                             // CH: 导入文件绝对路径或数据 | EN: The imported file's path or data
    unsigned int       nDataLen;                          // CH: 导入文件绝对路径或数据长度 | EN: Length of the imported file's path
    unsigned int       nReserved[4];                      // CH: 保留字段 | EN: Reserved
}IMVS_PF_IMPORT_MODULE_DATA;

typedef struct IMVS_PF_IMPORT_MODULE_DATA_INPUT__
{
    unsigned int                  nModuleID;                                   // CH: 模块ID | EN: Module ID
    unsigned int                  nDataType;                                   // CH: 导入数据类型 (1: 模板数据类型, 2:字库数据类型, 3:标定文件数据类型, 4:深度学习模型文件数据类型, 5:图像数据类型, 6:字符模板类型, 7:边缘缺陷模板类型; 8:颜色识别模板类型) | EN: Data type, including template, font library, calibration file, font library of deep learning, image, character defect template, edge defect template, color recognition template
    unsigned int                  nDataNum;                                    // CH: 导入数据个数 | EN: The number of data
    IMVS_PF_IMPORT_MODULE_DATA    stImportModuData[IMVS_PF_MAX_IMPORT_NUM];    // CH: 导入数据 | EN: Imported data
	unsigned int                  nRecvTimeout;                                // CH: 接收超时 | EN: Receive timeout
    unsigned int                  nReserved[3];                                // CH: 保留字段 | EN: Reserved
}IMVS_PF_IMPORT_MODULE_DATA_INPUT;

// CH: 方案版本信息结构 | EN: Solution version information structure
typedef struct IMVS_PF_SOLUTION_VERSION_INFO__
{
    char    strSolutionInfo[IMVS_PF_VERSION_LENGTH];     // CH: 方案版本信息 | EN: Solution version information
    char    strReserved[32];                             // CH: 保留字段 | EN: Reserved
} IMVS_PF_SOLUTION_VERSION_INFO;

// CH: 流程信息结构 | EN: Process information structure
typedef struct IMVS_PF_PROCESS_INFO__
{
    unsigned int nProcessID;                                        // CH: 流程ID | EN: Process ID
    char         strProcessName[IMVS_PF_MAX_PROCESS_NAME_LENGTH];   // CH: 流程名称 | EN: Process name
    unsigned int nReserved[4];                                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_PROCESS_INFO;

// CH: 流程信息列表结构 | EN: Process information list structure
typedef struct IMVS_PF_PROCESS_INFO_LIST__
{
    unsigned int         nNum;                                       // CH: 流程个数 | EN: The number of processes in the list
    IMVS_PF_PROCESS_INFO astProcessInfo[IMVS_PF_MAX_PROCESS_NUM];    // CH: 流程信息列表 | EN: Process information
    unsigned int         nReserved[4];                               // CH: 保留字段 | EN: Reserved
} IMVS_PF_PROCESS_INFO_LIST;

// CH: 相机图像信息结构 | EN: Camera image information structure
typedef struct IMVS_PF_CAMERA_PIC_INFO__
{
	int  nCameraId;                               // CH: 相机模块ID | EN: Camera module id
	char szLocalPicPath[IMVS_PF_MAX_PATH_LENGTH]; // CH: 本地图片绝对路径 | EN: Local picture absolute path
}IMVS_PF_CAMERA_PIC_INFO;

// CH: 相机图像信息列表结构 | EN: Camera image information list structure
typedef struct IMVS_PF_CAMERA_PIC_INFO_LIST__
{
	int nNum;                                                              // CH: 列表实际大小 | EN: The size of the list
	IMVS_PF_CAMERA_PIC_INFO stCamPicInfoList[IMVS_PF_CAMPICINFO_LIST_NUM]; // CH: 相机图像信息列表 | EN: Camera image information list
	int                     nTimeout;                                      // CH: 接口超时 | EN: Interface timeout
	unsigned int            nReserved[4];                                  // CH: 保留字段 | EN: Reserved
} IMVS_PF_CAMERA_PIC_INFO_LIST;

// CH: 嵌入前端运行界面窗体句柄信息结构 | EN: The handle information of third-party interfaces/windows
typedef struct IMVS_PF_FRONTEDWND_HANDLE_INFO__
{
	int          nIndex;               // CH: 子窗体序号 | EN: The index of son window
	void *       pFrontHandle;         // CH: 父窗体句柄 | EN: The handle of third-party interfaces/windows
} IMVS_PF_FRONTEDWND_HANDLE_INFO;

// CH: 嵌入前端运行界面父窗体句柄列表结构 | EN: The handle list structure of third-party interfaces/windows
typedef struct IMVS_PF_FRONTEDWND_HANDLE_LIST__
{
	int          nNum;                                                  // CH: 目标父窗体数量 | EN: Number of target parent forms
	IMVS_PF_FRONTEDWND_HANDLE_INFO stFrontHandleArray[IMVS_PF_MAX_ATTACH_FRONTWND_NUM];    // CH: 前端运行界面句柄列表 | EN: The handle list of third-party interfaces/windows
	int          nSleepTime;                                            // CH: 嵌入前延时 | EN: Sleep time before attaching
	unsigned int nReserved[4];                                          // CH: 保留字段 | EN: Reserved
} IMVS_PF_FRONTEDWND_HANDLE_LIST;

// CH: 输入图像数据信息结构 | EN: Input image data information structure
typedef struct IMVS_PF_IMAGE_DATA_INFO__
{
	char * pImgData;       // CH: 图像数据 | EN: Image data
	int    iImgDataLen;    // CH: 图像数据长度 | EN: Image data length
	int    iWidth;         // CH: 图像宽度 | EN: Image width
	int    iHeight;        // CH: 图像高度 | EN: Image height
	int    iImgFormat;     // CH: 图像像素格式（1：Mono8 2：RGB） | EN: Image pixel format (1:Mono8 2:RGB)
} IMVS_PF_IMAGE_DATA_INFO;

// CH: 用户输入图像信息结构 | EN: User input image information structure
typedef struct IMVS_PF_INPUT_IMAGE_INFO__
{
	unsigned int nModuleID;                                       // CH: 模块ID | EN: Module ID
	int          nDataType;                                       // CH: 图像数据类型(0:二进制数据, 1:路径) | EN: Image pixel format(0:Binary data, 1:Path)
	char         strImagePath[IMVS_PF_MAX_PATH_LENGTH];           // CH: 图像文件绝对路径 | EN: Image file absolute path
	IMVS_PF_IMAGE_DATA_INFO stImageDataInfo;                      // CH: 图像数据 | EN: Image data
    int          nIsP2PSend;                                      // CH: 是否点对点发送数据(0:NO, 1:YES) | EN: Is send data point to ponint 
    int          nIsWaitCopy;                                     // CH: 是否等待图像拷贝完成(0:NO, 1:YES) | EN: Is wait copy image 
	unsigned int nReserved[2];                                    // CH: 保留字段 | EN: Reserved
} IMVS_PF_INPUT_IMAGE_INFO;

// CH: 设置通信模块二进制数据信息结构 | EN: Communication module binary data settings information structure
typedef struct IMVS_PF_COMM_BINARY_DATA_INFO__
{
	int           nDeviceId;                                       // CH: 设备序号 | EN: The device serial number
	int           nDataType;                                       // CH：数据类型（1:字符串 2:整型 3:浮点 4:二进制数据） | EN: Data type (1: string 2: int 3: float 4: Byte)
	int           nAddressId;                                      // CH: 地址ID | EN: The address id
	char *        pData;                                           // CH: 二进制数据 | EN: The binary data
	unsigned int  nDataLenth;                                      // CH: 二进制数据长度 | EN: The length of binary data
} IMVS_PF_COMM_BINARY_DATA_INFO;

// CH: 设置普通模块二进制数据信息结构 | EN: Normal module binary data settings information structure
typedef struct IMVS_PF_NORMAL_BINARY_DATA_INFO__
{
	unsigned int nModuleID;                                         // CH: 模块ID | EN: Module ID
	char         strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH]; // CH: 参数名称 | EN: Parameter name
	char *       pData;                                             // CH: 二进制数据 | EN: The binary data
	unsigned int nDataLenth;                                        // CH: 二进制数据长度 | EN: The length of binary data
} IMVS_PF_NORMAL_BINARY_DATA_INFO;

// CH: 设置二进制数据信息结构 | EN: Binary data settings information structure
typedef struct IMVS_PF_SET_BINARY_DATA_INFO__
{
	unsigned int nModuleType;                                     // CH: 模块类型(0: 普通模块, 1: 通信模块) | EN: Module ID(0: Normal module, 1: Communication module)
	unsigned int nRecvWaitTime;                                   // CH: 接收超时（单位：ms） | EN: Receive time-out (in ms)
	IMVS_PF_COMM_BINARY_DATA_INFO   stCommBinaryData;             // CH: 通信模块二进制数据 | EN: The binary data of communication modules 
	IMVS_PF_NORMAL_BINARY_DATA_INFO stNormalBinaryData;           // CH: 普通模块二进制数据 | EN: The binary data of normal modules 
	unsigned int nReserved[4];                                    // CH: 保留字段 | EN: Reserved
} IMVS_PF_SET_BINARY_DATA_INFO;

// CH: 获取二进制数据长度信息结构 | EN: Binary data length getting information structure
typedef struct IMVS_PF_GET_BINARY_DATA_LEN_INFO__
{
	unsigned int nModuleID;                                         // [IN] CH: 模块ID | EN: Module ID
	char         strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH]; // [IN] CH: 参数名称 | EN: Parameter name
	unsigned int nRecvWaitTime;                                     // [IN] CH: 接收超时（单位：ms） | EN: Receive time-out (in ms)
	unsigned int nDataLength;                                       // [OUT] CH: 二进制数据长度 | EN: The length of the binary data
	unsigned int nReserved[4];                                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_GET_BINARY_DATA_LEN_INFO;

// CH: 获取二进制数据信息结构 | EN: Binary data getting information structure
typedef struct IMVS_PF_GET_BINARY_DATA_INFO__
{
	unsigned int nModuleID;                                         // [IN] CH: 模块ID | EN: Module ID
	char         strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH]; // [IN] CH: 参数名称 | EN: Parameter name
	unsigned int nRecvWaitTime;                                     // [IN] CH: 接收超时（单位：ms） | EN: Receive time-out (in ms)
	unsigned int nMallocSize;                                       // [IN] CH: 分配空间 | EN: The allocated space
	char *       pBinaryData;                                       // [OUT] CH: 二进制数据 | EN: Binary data
	unsigned int nDataLen;                                          // [OUT] CH: 二进制数据长度 | EN: The length of the binary data
	unsigned int nReserved[4];                                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_GET_BINARY_DATA_INFO;

// CH: 导入流程信息结构 | EN: Import process information structure
typedef struct IMVS_PF_IMPORT_PROCESS_INFO__
{
	unsigned int nProcessID;                                   // CH: 流程ID | EN: Process ID
	char         strProcName[IMVS_PF_MAX_PROCESS_NAME_LENGTH]; // CH: 流程名称 | EN: Process name
	unsigned int nReserved[4];                                 // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMPORT_PROCESS_INFO;

// CH: 相机取图信息结构 | EN: Camera collect information structure
typedef struct IMVS_PF_CAMERA_COLLECT_INFO__
{
    unsigned int nCameraID;                                    // CH: 相机ID | EN: Camera ID
    unsigned int nFrameNum;                                    // CH: 图像帧号 | EN: Frame number
    char strCameraSN[IMVS_PF_CAMERA_MAX_SN_LEN];               // CH: 相机SN | EN: Camera SN
	unsigned int nCollectStatus;							   // CH: 取图状态 | EN: Collect Status
    unsigned int nReserved[3];                                 // CH: 保留字段 | EN: Reserved
} IMVS_PF_CAMERA_COLLECT_INFO;

// CH: 相机连接状态信息结构 | EN: Camera connect status information structure
typedef struct IMVS_PF_CAMERA_CONNECT_STATUS_INFO__
{
	unsigned int nCameraID;                                    // CH: 相机ID | EN: Camera ID
	unsigned int nConnectStatus;                               // CH: 连接状态 | EN: Connect Status
	char strCameraSN[IMVS_PF_CAMERA_MAX_SN_LEN];               // CH: 相机SN | EN: Camera SN
	unsigned int nReserved[4];                                 // CH: 保留字段 | EN: Reserved
} IMVS_PF_CAMERA_CONNECT_STATUS_INFO;

// CH: 单个相机信息结构 | EN: Camera information structure
typedef struct IMVS_PF_CAMERA_INFO__
{
    char strCameraName[IMVS_PF_CAMERA_MAX_NAME_LEN];           // CH: 相机名称 | EN: Camera Name
    char strCameraSN[IMVS_PF_CAMERA_MAX_SN_LEN];               // CH: 相机SN | EN: Camera SN
    unsigned int nReserved[4];                                 // CH: 保留字段 | EN: Reserved
} IMVS_PF_CAMERA_INFO;

// CH: 相机信息列表结构 | EN: Camera information list structure
typedef struct IMVS_PF_CAMERA_INFO_LIST__
{
    unsigned int nNum;                                          // CH: 相机数量 | EN: Camera Number
    IMVS_PF_CAMERA_INFO astCameraInfo[IMVS_PF_CAMERA_MAX_NUM];  // CH: 相机信息 | EN: Camera Info
    unsigned int nReserved[4];                                  // CH: 保留字段 | EN: Reserved
} IMVS_PF_CAMERA_INFO_LIST;

// CH: 通信连接信息结构 | EN: Communication connect information structure
typedef struct IMVS_PF_COMMUNICATION_CONNECT_INFO__
{
    unsigned int nDeviceStatus;                                // CH: 设备状态 | EN: Device Status
    unsigned int nDeviceID;                                    // CH: 设备ID | EN: Device ID
    unsigned int nReserved[4];                                 // CH: 保留字段 | EN: Reserved
}IMVS_PF_COMMUNICATION_CONNECT_INFO;

/*************************************************************************
 * 模块结果结构体定义
 * Module results structure definition
 *************************************************************************/
// CH: 图像数据信息结构 | EN: Image information structure
typedef struct IMVS_PF_IMAGE_INFO__
{
    char * pImgData;       // CH: 图像数据 | EN: Image data
    int    iImgDataLen;    // CH: 图像数据长度 | EN: Image data length
    int    iWidth;         // CH: 图像宽度 | EN: Image width
    int    iHeight;        // CH: 图像高度 | EN: Image height
    int    iImgFormat;     // CH: 图像像素格式 | EN: Image pixel format
    int    iReserved[4];   // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGE_INFO;

// CH: 图像源模块数据信息结构 | EN: Image source module data structure
typedef struct IMVS_PF_IMAGESOURCEMODULE_INFO__
{
	int                nFrameNum;       // CH: 帧号 | EN: Frame number
	int                nLostFrameCount; // CH: 丢帧数 | EN: Number of frames lost
	int                nLostPacketCount;// CH: 丢包数 | EN: Number of bags lost
	int                nGetCamfailCount;// CH: 获取相机失败次数 | EN: Count of failed camera acquisitions
    IMVS_PF_IMAGE_INFO stImgInfo;       // CH: 图像数据 | EN: Image data
	IMVS_PF_IMAGE_INFO stMono8ImgInfo;  // CH: mono8图像数据 | Mono8 Image data
	char               strCurImagePath[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 当前本地图像路径 | EN: Current image path
    int                iReserved[4];    // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGESOURCEMODULE_INFO;

// CH: 输出图像模块数据信息结构 | EN: Structure about information of output image module
typedef struct IMVS_PF_SAVEIMAGE_MODU_INFO__
{
    int    iModuStatu;     // CH: 模块状态 | EN: Module status
	char   strImgSavePath[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 图像存储路径 | EN: Image storage path
	char   strImgName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];     // CH: 图像名称 | EN: Image name
	char   strRenderImgSavePath[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 渲染图像存储路径 | EN: Render Image storage path
	char   strRenderImageName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 渲染图像名称 | EN: Render Image name
	IMVS_PF_IMAGE_INFO stOutImgInfo; // CH: 输出图像数据 | EN: Output image data
	int    iReserved[4];   // CH: 保留字段 | EN: Reserved
} IMVS_PF_SAVEIMAGE_MODU_INFO;

// CH: 浮点型二维点信息结构 | EN: Structure about information of floating-point 2D point
typedef struct IMVS_PF_2DPOINT_F__
{
    float    fPtX;         // CH: 点X坐标 | EN: X coordinate
    float    fPtY;         // CH: 点Y坐标 | EN: Y coordinate
} IMVS_PF_2DPOINT_F;

// CH: 整型二维点信息结构 | EN: Structure about information of integer 2D point
typedef struct IMVS_PF_2DPOINT_I__
{
    int    iPtX;         // CH: 点X坐标 | EN: X coordinate
    int    iPtY;         // CH: 点Y坐标 | EN: Y coordinate
} IMVS_PF_2DPOINT_I;

// CH: 区域信息结构 | EN: Region information structure
typedef struct IMVS_PF_REGION__
{
    float    fWidth;              // CH: 区域宽度 | EN: Region width
    float    fHeight;             // CH: 区域高度 | EN: Region height
    float    fAngle;              // CH: 区域角度 | EN: Region angle
    IMVS_PF_2DPOINT_F stCenterPt; // CH: 区域中心点 | EN: Coordinates of regional center point
} IMVS_PF_REGION;

// CH: 特征匹配边缘点 | EN: Structure about feature matching edge point
typedef struct IMVS_PATMATCH_POINT_INFO__
{
    float fMatchOutlineX;        // CH: 匹配轮廓点X | EN: Matching contour point X
    float fMatchOutlineY;        // CH: 匹配轮廓点Y | EN: Matching contour point Y
    float fMatchOutlineScore;    // CH: 匹配轮廓点分数 | EN: Matching contour point score
    int   iMatchOutlineIndex;    // CH: 匹配轮廓点序号 | EN: Matching contour point No.
}IMVS_PATMATCH_POINT_INFO;

// CH: 匹配轮廓信息结构 | EN: Matching contour information structure
typedef struct IMVS_PF_MATCH_INFO__
{
    int   iPtNum;                             // CH: 匹配轮廓点个数 | EN: The number of matching contour points
    IMVS_PATMATCH_POINT_INFO * pstPatMatchPt; // CH: 匹配特征点 | EN: Matching feature points
} IMVS_PF_MATCH_INFO;

// CH: 匹配点信息结构 | EN: Matching point information structure
typedef struct IMVS_PF_MATCH_PT_INFO__
{
    float    fScore;              // CH: 匹配点分数 | EN: Matched point score
    float    fScale;              // CH: 匹配点尺度 | EN: Matched point scale
    IMVS_PF_2DPOINT_F stMatchPt;  // CH: 匹配点 | EN: Matching point
} IMVS_PF_MATCH_PT_INFO;

// CH: 特征匹配基本信息结构 | EN: Structure about feature matching information
typedef struct IMVS_PF_MATCH_BASE_INFO__
{
    int    iMatchTempNum;               // CH: 匹配模板编号 | EN: Matching template No.
    int    iMatchStatu;                 // CH: 匹配状态 | EN: Matching status
    IMVS_PF_REGION stMatchBox;          // CH: 匹配框 | EN: Matching box
    IMVS_PF_MATCH_PT_INFO stMatchPt;    // CH: 匹配点 | EN: Matching point
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
}IMVS_PF_MATCH_BASE_INFO;

// CH: 快速特征匹配模块信息结构 | EN: Structure about information of feature fast matching module
typedef struct IMVS_PF_FASTFEATUREMATCH_MODU_INFO__
{
    int    iModuStatu;                  // CH: 模块状态 | EN: Module status
    IMVS_PF_MATCH_INFO stMatchConInfo;  // CH: 匹配轮廓信息 | EN: Matching contour information
    int    iMatchNum;                   // CH: 匹配个数 | EN: The number of matched modules
    IMVS_PF_MATCH_BASE_INFO * pstMatchBaseInfo; // CH: 特征匹配基本信息 | EN: Basic information of feature fast matching
	IMVS_PF_REGION stDetectRegion;      // CH: 捡测区域 | EN: Detection region
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_FASTFEATUREMATCH_MODU_INFO;

// CH: 高精度匹配点信息结构 | EN: Structure about information of high precision matching point
typedef struct IMVS_PF_HPMATCH_PT_INFO__
{
    float    fScore;              // CH: 匹配点分数 | EN: Matching point score
    float    fScale;              // CH: 匹配点尺度 | EN: Matching point scale
    float    fScaleX;             // CH: 尺度X | EN: Scale X
    float    fScaleY;             // CH: 尺度Y | EN: Scale Y
    IMVS_PF_2DPOINT_F stMatchPt;  // CH: 匹配点 | EN: Matching point
} IMVS_PF_HPMATCH_PT_INFO;

// CH: 高精度特征匹配基本信息结构 | EN: Structure about basic information of feature high-precision matching
typedef struct IMVS_PF_HPMATCH_BASE_INFO__
{
    int    iMatchTempNum;               // CH: 匹配模板编号 | EN: Matching template No.
    int    iMatchStatu;                 // CH: 匹配状态 | EN: Matching status
    IMVS_PF_REGION stMatchBox;          // CH: 匹配框 | EN: Matching box
    IMVS_PF_HPMATCH_PT_INFO stMatchPt;  // CH: 匹配点 | EN: Matching point
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
}IMVS_PF_HPMATCH_BASE_INFO;

// CH: 高精度特征匹配模块信息结构 | EN: Structure about information of feature high-precision matching
typedef struct IMVS_PF_HPFEATUREMATCH_MODU_INFO__
{
    int    iModuStatu;                  // CH: 模块状态 | EN: Module status
    IMVS_PF_MATCH_INFO stMatchConInfo;  // CH: 匹配轮廓信息 | EN: Matching contour information
    int    iMatchNum;                   // CH: 匹配个数 | EN: The number of matched items
    IMVS_PF_HPMATCH_BASE_INFO * pstMatchBaseInfo; // CH: 高精度特征匹配基本信息 | EN: Basic information of feature high-precision matching
	IMVS_PF_REGION stDetectRegion;      // CH: 捡测区域 | EN: Detection region
	int    iMatchOutlineNum;            // CH: 
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_HPFEATUREMATCH_MODU_INFO;

// CH: 轮廓点信息结构 | EN: Contour point information structure
typedef struct IMVS_PF_CONTOUR_PT__
{
    int  iStatus;                  // CH: 轮廓点状态 | EN: Contour point status
    IMVS_PF_2DPOINT_F stCirPt;     // CH: 轮廓点 | EN: Contour point
} IMVS_PF_CONTOUR_PT;

// CH: 轮廓点集信息结构 | EN: Contour point set information structure
typedef struct IMVS_PF_OUTLINE_PT__
{
    int    iPtNum;                      // CH: 轮廓点数 | EN: The number of contour points
    IMVS_PF_CONTOUR_PT * pstContourPt;  // CH: 轮廓点 | EN: Contour point information
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_OUTLINE_PT;

// CH: 输出圆弧信息结构 | EN: Output arc information structure
typedef struct IMVS_PF_ANNULUS_CIRCLE_INFO__
{
	float  fOutputAnnulusCenterX;       // CH: 输出圆中心X | EN: Output circle center point X
	float  fOutputAnnulusCenterY;       // CH: 输出圆中心Y | EN: Output circle center point Y
	float  fOutputAnnulusInnerRadius;   // CH: 输出圆内径 | EN: Output circle inner radius
	float  fOutputAnnulusOuterRadius;   // CH: 输出圆外径 | EN: Output circle outer radius
	float  fOutputAnnulusStartAngle;    // CH: 输出圆起始角度 | EN: Output circle start angle
	float  fOutputAnnulusAngleExtend;   // CH: 输出圆展开角度 | EN: Output circle expand angle
} IMVS_PF_ANNULUS_CIRCLE_INFO;

// CH: 圆查找模块信息结构 | EN: Structure about information of circle search module
typedef struct IMVS_PF_CIRCLEFIND_MODU_INFO__
{
    int    iModuStatu;                  // CH: 模块状态 | EN: Module status
    float  fRadius;                     // CH: 圆半径 | EN: Circle radius
    float  fFitDiff;                    // CH: 拟合误差 | EN: Fitting error
    IMVS_PF_2DPOINT_F  stCirPt;         // CH: 圆心点 | EN: Center point
    IMVS_PF_OUTLINE_PT stOutlinePts;    // CH: 圆轮廓点 | EN: Points on the circumstance
    IMVS_PF_REGION     stDetectRegion;  // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stAnnulusCirInfo; // CH: 圆弧信息 | EN: Output arc information
	int    iCaliperBoxNum;              // CH: 卡尺框数量 | EN: Number of caliper boxes
	IMVS_PF_REGION *   pstCaliperBox;   // CH: 卡尺框 | EN: Caliper boxes
	int    iCaliperDetectNum;           // CH: 卡尺框检测区数量 | EN: Number of caliper detection areas
	IMVS_PF_REGION *   pstCaliperDetectRegion; // CH: 卡尺框检测区 | EN: Caliper detection areas
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiAnnulusCirInfo; // CH: ROI圆弧信息 | EN: ROI arc information
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_CIRCLEFIND_MODU_INFO;

// CH: 直线查找模块信息结构 | EN: Structure about information of line search module
typedef struct IMVS_PF_LINEFIND_MODU_INFO__
{
    int    iModuStatu;                  // CH: 模块状态 | EN: Module status
    float  fAngle;                      // CH: 直线角度 | EN: Linear tilt angle
    float  fFitDiff;                    // CH: 拟合误差 | EN: Coordinates of the line's start point
    IMVS_PF_2DPOINT_F    stStartPt;     // CH: 直线起点 | EN: Coordinates of the line's start point
    IMVS_PF_2DPOINT_F    stEndPt;       // CH: 直线终点 | EN: Coordinates of the line's end point
    IMVS_PF_OUTLINE_PT stOutlinePts;    // CH: 直线轮廓点 | EN: Information of the point on the line
    IMVS_PF_REGION     stDetectRegion;  // CH: 检测区域 | EN: Detected region
	int    iCaliperBoxNum;              // CH: 卡尺框数量 | EN: Number of caliper boxes
	IMVS_PF_REGION *   pstCaliperBox;   // CH: 卡尺框 | EN: Caliper boxes
	int    iCaliperDetectNum;           // CH: 卡尺框检测区数量 | EN: Number of caliper detection areas
	IMVS_PF_REGION *   pstCaliperDetectRegion; // CH: 卡尺框检测区 | EN: Caliper detection areas
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_LINEFIND_MODU_INFO;

// CH: 连通域信息结构 | EN: Connected domain information structure
typedef struct IMVS_PF_CONNECT_DOMAINS_INFO__
{
	float fBlobAngle;                   // CH: 主轴角度 | EN: Spindle angle
    float fPeriMeter;                   // CH: 连通域周长 | EN: Connected domain circumstance
    float fLongAxis;                    // CH: 长轴 | EN: Long axis
    float fShortAxis;                   // CH: 短轴 | EN: Short axis
	float fAxisRatio;                   // CH: 轴比 | EN: Axis ratio
    float fCircularity;                 // CH: 圆形度 | EN: Circularity
    float fSquareness;                  // CH: 矩形度 | EN: Squareness
    float fScore;                       // CH: 分数 | EN: Score
    float fWidth;                       // CH: 最小外接矩形宽度 | EN: Width of the smallest external rectangle
    float fHeight;                      // CH: 最小外接矩形高度 | EN: Height of the smallest external rectangle
    float fAngle;                       // CH: 最小外接矩形角度 | EN: Angle of the smallest external rectangle
    IMVS_PF_2DPOINT_F stCentroidPt;     // CH: 最小外接矩形中心点 | EN: Center point of the smallest external rectangle
} IMVS_PF_CONNECT_DOMAINS_INFO;

// CH: Blob轮廓点信息结构 | EN: Blob contour point information
typedef struct IMVS_PF_BLOBOUTLINE_PT__
{
    int  iPtNum;                          // CH: 轮廓点数 | EN: The number of blob contour points
    IMVS_PATMATCH_POINT_INFO * pstBlobPt; // CH: 轮廓点 | EN: Blob contour point
} IMVS_PF_BLOBOUTLINE_PT;

// CH: 单个Blob基本信息结构 | EN: Single blob information structure
typedef struct IMVS_PF_SINGLEBLOB_INFO__
{
    int    iMonoStatu;                        // CH: 单体状态 | EN: Monomer status
    float  fArea;                             // CH: 面积 | EN: Area of the blob
	IMVS_PF_2DPOINT_F    stCentroidPt;        // CH: 质心点 | EN: Centroid point coordinates
    IMVS_PF_CONNECT_DOMAINS_INFO stConnectDomain; // CH: 连通域信息 | EN: Connected domain information
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
}IMVS_PF_SINGLEBLOB_INFO;

// CH: BLOB分析模块信息结构 | EN: Blob analysis information structure
typedef struct IMVS_PF_BLOBFIND_MODU_INFO__
{
    int    iModuStatu;                        // CH: 模块状态 | EN: Module status
	float  fTotalArea;                        // CH: 总面积 | EN: Total area of the blob
	int    iDetectNum;                        // CH: 检测区域个数 | EN: Number of detected region
    IMVS_PF_REGION *  pstDetectRegion;        // CH: 检测区域 | EN: Detected region
    IMVS_PF_BLOBOUTLINE_PT  stBlobOutlinePt;  // CH: Blob轮廓信息 | EN: Blob contour information
    IMVS_PF_IMAGE_INFO stBinaImage;           // CH: 二值化图像 | EN: Blob image
    IMVS_PF_IMAGE_INFO stBlobImage;           // CH: Blob图像 | EN: The number of blobs
    int    iBlobNum;                          // CH: BLOB个数 | EN: Single blob information
    IMVS_PF_SINGLEBLOB_INFO * pstSingleBlobInfo; // CH: BLOB信息 | EN: Blob information
	int    iAnnulusNum;                       // CH: ROI圆弧个数 | EN: Number of ROI arcs
	IMVS_PF_ANNULUS_CIRCLE_INFO * pstAnnulusCirInfo; // CH: ROI圆弧信息 | EN: ROI arc information
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_BLOBFIND_MODU_INFO;

// CH: 边缘信息结构 | EN: Edge information structure
typedef struct IMVS_PF_EDGE_INFO__
{
    int    iEdgePloraty;                     // CH: 边缘极性 | EN: Edge polarity
    float  fEdgePos;                         // CH: 边缘位置 | EN: The position of the edge
    IMVS_PF_2DPOINT_F stEdgePt;              // CH: 边缘点 | EN: Edge point
} IMVS_PF_EDGE_INFO;

// CH: 直线信息结构 | EN: Line information structure
typedef struct IMVS_PF_LINE_INFO__
{
    float fAngle;                           // CH: 直线角度 | EN: Linear tilt angle
    IMVS_PF_2DPOINT_F stStartPt;            // CH: 直线起点 | EN: Line's start point
    IMVS_PF_2DPOINT_F stEndPt;              // CH: 直线终点 | EN: Line's end point
} IMVS_PF_LINE_INFO;

// CH: 卡尺边缘信息结构 | EN: Caliper edge information
typedef struct IMVS_PF_CALIPER_INFO__
{
    int    iEdgeStatu;                        // CH: 边缘状态 | EN: Edge status
    float  fScore;                            // CH: 分数 | EN: Score
    float  fEdgePairWidth;                    // CH: 测量宽度 | EN: Width between the two lines
    IMVS_PF_EDGE_INFO stEdgeInfo0;            // CH: 边缘0信息 | EN: Information of points on line 0
    IMVS_PF_EDGE_INFO stEdgeInfo1;            // CH: 边缘1信息 | EN: Information of points on line 1
    IMVS_PF_LINE_INFO stEdgeLine0;            // CH: 边缘0直线 | EN: Line 0 information
    IMVS_PF_LINE_INFO stEdgeLine1;            // CH: 边缘1直线 | EN: Line 1 information
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
}IMVS_PF_CALIPER_INFO;

// CH: 卡尺工具模块信息结构 | EN: Caliper module information structure
typedef struct IMVS_PF_CALIPER_MODU_INFO__
{
    int    iModuStatu;                        // CH: 模块状态 | EN: Module status
    IMVS_PF_REGION         stDetectRegion;    // CH: 检测区域 | EN: Detected region
    int    iEdgeNum;                          // CH: 边缘个数 | EN: The number of caliper edges
    IMVS_PF_CALIPER_INFO * pstCalipInfo;      // CH: 卡尺边缘 | EN: Caliper edge
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_CALIPER_MODU_INFO;

// CH: 边缘结果信息结构 | EN: Caliper edge result details structure
typedef struct IMVS_PF_CALIPER_EDGE_INFO__
{
    int    iEdgeStatu;                        // CH: 边缘状态 | EN: Edge status
    float  fScore;                            // CH: 分数 | EN: Score
    int    iEdgePloraty;                      // CH: 边缘极性 | EN: Edge polarity
    float  fEdgePos;                          // CH: 边缘位置 | EN: Edge position
    IMVS_PF_2DPOINT_F stEdgePt;               // CH: 边缘点 | EN: Coordinates of the point one edge line
    IMVS_PF_LINE_INFO stEdgeLine;             // CH: 边缘直线 | EN: Edge line information
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_CALIPER_EDGE_INFO;

// CH: 边缘查找模块信息结构 | EN: Structure about information of edge search module
typedef struct IMVS_PF_CALIPEREDGE_MODU_INFO__
{
    int    iModuStatu;                        // CH: 模块状态 | EN: Module status
    IMVS_PF_REGION stDetectRegion;            // CH: 检测区域 | EN: Detected region
    int    iEdgeNum;                          // CH: 边缘个数 | EN: The number of edges
    IMVS_PF_CALIPER_EDGE_INFO * pstCalipEdge; // CH: 边缘信息 | EN: Caliper edge information
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_CALIPEREDGE_MODU_INFO;

// CH: 间距结果信息结构 | EN: Result details of the distance between two edges
typedef struct IMVS_PF_EDGE_WIDTH_RES_INFO__
{
    int    iEdgeStatu;                        // CH: 边缘状态 | EN: Edge status
    float  fEdgeDis;                          // CH: 边缘间距 | EN: The distance between the two edges
    float  fScore;                            // CH: 分数 | EN: Score
    int    iEdgePloraty0;                     // CH: 边缘0极性 | EN: Edge 0 polarity
    float  fEdgePos0;                         // CH: 边缘0位置 | EN: Edge 0 position
    int    iEdgePloraty1;                     // CH: 边缘1极性 | EN: Edge 1 polarity
    float  fEdgePos1;                         // CH: 边缘1位置 | EN: Edge 1 position
    IMVS_PF_2DPOINT_F stEdgePt0;              // CH: 边缘点0 | EN: Points on line 0
    IMVS_PF_2DPOINT_F stEdgePt1;              // CH: 边缘点1 | EN: Points on line 1
    IMVS_PF_LINE_INFO stEdgeLine0;            // CH: 边缘直线0 | EN: Line 0 information
    IMVS_PF_LINE_INFO stEdgeLine1;            // CH: 边缘直线1 | EN: Line 1 information
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
}IMVS_PF_EDGE_WIDTH_RES_INFO;

// CH: 间距检测模块信息结构 | EN: Structure about information of interval detection module
typedef struct IMVS_PF_EDGEWIDTHFIND_MODU_INFO__
{
    int    iModuStatu;                        // CH: 模块状态 | EN: Module status
    IMVS_PF_REGION    stDetectRegion;         // CH: 检测区域 | EN: Detected region
    int    iEdgeNum;                          // CH: 边缘个数 | EN: The number of edges
    IMVS_PF_EDGE_WIDTH_RES_INFO * pstEdgeWidthResInfo; // CH: 间距结果信息结构 | EN: Details of the distance between edges
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_EDGEWIDTHFIND_MODU_INFO;

// CH: 位置修正模块信息结构 | EN: Structure about information of position correction module
typedef struct IMVS_PF_FIXTURE_MODU_INFO__
{
	int    iModuStatu;                        // CH: 模块状态 | EN: Module status
    float  fBaseAngle;                        // CH: 基准角度 | EN: Based angle
    float  fOperateAngle;                     // CH: 运行角度 | EN: Operating angle
    IMVS_PF_2DPOINT_F stBasePt;               // CH: 基准点 | EN: Datum point coordinates
    IMVS_PF_2DPOINT_F stOperatePt;            // CH: 运行点 | EN: Operating point coordinates
	float  fBaseScaleX;                       // CH: 基准尺度X | EN: Datum scale X
	float  fBaseScaleY;                       // CH: 基准尺度Y | EN: Datum scale Y
	float  fRunScaleX;                        // CH: 运行尺度X | EN: Run scale X
	float  fRunScaleY;                        // CH: 运行尺度Y | EN: Run scale Y
	int  iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_FIXTURE_MODU_INFO;

// CH: 矩形框信息结构 | EN: Rectangle information structure
typedef struct IMVS_PF_RECT_INFO__
{
    float    fWidth;                  // CH: 矩形宽度 | EN: Rectangle width
    float    fHeight;                 // CH: 矩形高度 | EN: Rectangle height
    float    fAngle;                  // CH: 矩形角度 | EN: Tilt angle of the rectangle
    IMVS_PF_2DPOINT_F stCentPt;       // CH: 中心点 | EN: The center point of the rectangle
} IMVS_PF_RECT_INFO;

// CH: 矩形检测模块 | EN: Structure about information of rectangle detection module
typedef struct IMVS_PF_RECTFIND_MODU_INFO__
{
    int    iModuStatu;                        // CH: 模块状态 | EN: Module status
    int    iDetectStatu;                      // CH: 检测状态 | EN: Detection status
    IMVS_PF_RECT_INFO  stRect;                // CH: 矩形 | EN: Detected rectangle information
    IMVS_PF_OUTLINE_PT stOutlinePt;           // CH: 轮廓点 | EN: Contour point information
    IMVS_PF_REGION     stDetectRegion;        // CH: 检测区域 | EN: Detcted region
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_RECTFIND_MODU_INFO;

// CH: 顶点信息 | EN: Vertex information structure
typedef struct IMVS_PF_PEAK_INFO__
{
    float  fPeakScore;                        // CH: 顶点分数 | EN: Vertex score
    int    iPeakPloraty;                      // CH: 顶点极性 | EN: Vertex polarity
    float  fPeakDist;                         // CH: 顶点距离 | EN: Distance between two vertex
    int    iPeakStatu;                        // CH: 顶点状态 | EN: Vertex status
    IMVS_PF_2DPOINT_F stPeakPt;               // CH: 顶点 | EN: Vertex coordinates
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_PEAK_INFO;

// CH: 边缘信息 | EN: Edge information structure
typedef struct IMVS_PF_PEAKEDGE_INFO__
{
    int    iEdgeStatu;                        // CH: 边缘状态 | EN: Edge status
    float  fEdgeScore;                        // CH: 边缘分数 | EN: Edge score
    int    iEdgePloraty;                      // CH: 边缘极性 | EN: Edge polarity
    float  fEdgePos;                          // CH: 边缘位置 | EN: The position of the edge
    IMVS_PF_2DPOINT_F stEdgePt;               // CH: 边缘点 | EN: Edge point information
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_PEAKEDGE_INFO;

// CH: 顶点检测模块 | EN: Structure about information of vertex detection module
typedef struct IMVS_PF_PEAKFIND_MODU_INFO__
{
    int    iModuStatu;                        // CH: 模块状态 | EN: Module status
    IMVS_PF_PEAK_INFO     stPeakInfo;         // CH: 顶点信息 | EN: Vertex information
    IMVS_PF_REGION        stDetectRegion;     // CH: 检测区域 | EN: Detected region
    int    iEdgeNum;                          // CH: 边缘个数 | EN: The number of edges
    IMVS_PF_PEAKEDGE_INFO * pstEdgeInfo;      // CH: 边缘信息 | EN: Edge information
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_PEAKFIND_MODU_INFO;

// CH: 边缘交点查找模块 | EN: Structure about information of border intersection search module
typedef struct IMVS_PF_CALIPCORNER_MODU_INFO__
{
    int    iModuStatu;                        // CH: 模块状态 | EN: Module status
    float  fCornerAngle;                      // CH: 边缘交点角度 | EN: Angle between line 1 and line 0
    IMVS_PF_2DPOINT_F  stCornerPt;            // CH: 边缘交点 | EN: Intersection coordinates of the two lines
    IMVS_PF_LINE_INFO  stCalipLine0;          // CH: 边缘直线0 | EN: Line 0 information
    IMVS_PF_LINE_INFO  stCalipLine1;          // CH: 边缘直线1 | EN: Line 1 information
    IMVS_PF_OUTLINE_PT stOutLine0;            // CH: 直线0轮廓点 | EN: Information about points on the line 0
    IMVS_PF_OUTLINE_PT stOutLine1;            // CH: 直线1轮廓点 | EN: Information about points on the line 1
    IMVS_PF_REGION     stDetectRegion1;       // CH: 检测区域1 | EN: Information of the detected region 1
    IMVS_PF_REGION     stDetectRegion2;       // CH: 检测区域2 | EN: Information of the detected region 2
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_CALIPERCORNER_MODU_INFO;

// CH: 平行线查找模块 | EN: Structure about information of parallel line search module
typedef struct IMVS_PF_PAIRLINE_MODU_INFO__
{
    int    iModuStatu;                        // CH: 模块状态 | EN: Module status
    int    iDetectStatu;                      // CH: 检测状态 | EN: Detection status
    float  fLineWidth;                        // CH: 直线宽度 | EN: Width of the line
    IMVS_PF_LINE_INFO  stCalipLine0;          // CH: 边缘直线0 | EN: Information of line 0
    IMVS_PF_LINE_INFO  stCalipLine1;          // CH: 边缘直线1 | EN: Information of line 1
	IMVS_PF_LINE_INFO  stMidLine;             // CH: 边缘中线 | EN: Information of the two lines' midline
    IMVS_PF_OUTLINE_PT stOutLine0;            // CH: 直线0轮廓点 | EN: Coordinates of points on line 0
    IMVS_PF_OUTLINE_PT stOutLine1;            // CH: 直线1轮廓点 | EN: Coordinates of points on line 1
	IMVS_PF_OUTLINE_PT stMidOutLine;          // CH: 中线轮廓点 | EN: Coordinates of points on the midline of the two lines
    IMVS_PF_REGION     stDetectRegion;        // CH: 检测区域 | EN: Detected region
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_PAIRLINE_MODU_INFO;

// CH: 线圆测量模块信息结构 | EN: Structure about information of line and circle distance measurement module
typedef struct IMVS_PF_L2CMEASURE_MODU_INFO__
{
    int    iModuStatu;                    // CH: 模块状态 | EN: Module status
    float  fAngle;                        // CH: 角度 | EN: Angle between the vertical line (which connects the point and the line segment) and the X-coordinate (positive direction)
    float  fDist;                         // CH: 距离 | EN: Vertical distance between the circle's center and the line
    float  fRadius;                       // CH: 测量圆半径 | EN: Radius of the measured circle
    IMVS_PF_2DPOINT_F stCentPt;           // CH: 测量圆心点 | EN: Center point of the measured circle
    IMVS_PF_2DPOINT_F stMeasuStartPt;     // CH: 测量直线起点 | EN: The start point of the measured line
    IMVS_PF_2DPOINT_F stMeasuEndPt;       // CH: 测量直线终点 | EN: The end point of the measured line
	float             fLineAngle;         // CH: 测量直线角度 | EN: The angle of measured line
    IMVS_PF_2DPOINT_F stIntersecPt1;      // CH: 交点1 | EN: Interaction 1 information
    IMVS_PF_2DPOINT_F stIntersecPt2;      // CH: 交点2 | EN: Interaction 2 information
    IMVS_PF_2DPOINT_F stFootPt;           // CH: 垂足点 | EN: Foot point
	int nCaliperBox1Num;                  // CH: 卡尺检测区1数量 | EN: Number of caliper detection region 1
	IMVS_PF_REGION *  pstDetectRegion1;   // CH: 卡尺检测区1 | EN: Detected region 1
	int nCaliperBox2Num;                  // CH: 卡尺检测区2数量 | EN: Number of caliper detection region 2
	IMVS_PF_REGION *  pstDetectRegion2;   // CH: 卡尺检测区2 | EN: Detected region 2
    int    iReserved[4];                  // CH: 保留字段 | EN: Reserved
} IMVS_PF_L2CMEASURE_MODU_INFO;

// CH: 圆圆测量模块信息结构 | EN: Structure about information of circle and circle distance measurement module
typedef struct IMVS_PF_C2CMEASURE_MODU_INFO__
{
    int    iModuStatu;                    // CH: 模块状态 | EN: Module status
    float  fAngle;                        // CH: 角度 | EN: The angle between the connecting line of center points and X-coordinate (positive direction)
    float  fDist;                         // CH: 距离 | EN: Center distance
    char   strPosRela[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 位置关系 | EN: Position relationship of the two circles
    float  fRadius1;                      // CH: 测量圆1半径 | EN: Circle 1's radius
    float  fRadius2;                      // CH: 测量圆2半径 | EN: Circle 2's radius
    IMVS_PF_2DPOINT_F stCentPt1;          // CH: 测量圆1圆心点 | EN: Coordinates of the circle 1's center point
    IMVS_PF_2DPOINT_F stCentPt2;          // CH: 测量圆2圆心点 | EN: Coordinates of the circle 2's center point
    IMVS_PF_2DPOINT_F stIntersecPt1;      // CH: 交点1 | EN: Coordinates of intersection point 1
    IMVS_PF_2DPOINT_F stIntersecPt2;      // CH: 交点2 | EN: Coordinates of intersection point 2
	int nCaliperBox1Num;                // CH: 卡尺检测区1数量 | EN: Number of caliper detection region 1
	IMVS_PF_REGION *  pstDetectRegion1; // CH: 卡尺检测区1 | EN: Detected region 1
	int nCaliperBox2Num;                // CH: 卡尺检测区2数量 | EN: Number of caliper detection region 2
	IMVS_PF_REGION *  pstDetectRegion2; // CH: 卡尺检测区2 | EN: Detected region 2
    int    iReserved[4];                  // CH: 保留字段 | EN: Reserved
} IMVS_PF_C2CMEASURE_MODU_INFO;

// CH: 点圆测量模块信息结构 | EN: Structure about information of point and circle distance measurement module
typedef struct IMVS_PF_P2CMEASURE_MODU_INFO__
{
    int    iModuStatu;                    // CH: 模块状态 | EN: Module status
    float  fAngle;                        // CH: 角度 | EN: The angle between the line ( which connects the point and the center point) and X-coordinate (positive direction)
    float  fCenterDist;                   // CH: 中心距离 | EN: Distance between the point and the center point
    float  fNearestDist;                  // CH: 最近距离 | EN: The shortest distance between the point and the circle
    float  fFarDist;                      // CH: 最远距离 | EN: The fastest distance between the point and the circle
    float  fRadius;                       // CH: 测量圆半径 | EN: Radius of the circle
    IMVS_PF_2DPOINT_F stCentPt;           // CH: 测量圆心点 | EN: Center point coordinates
    IMVS_PF_2DPOINT_F stMeasuPt;          // CH: 测量点 | EN: Point coordinates
    int    iReserved[4];                  // CH: 保留字段 | EN: Reserved
} IMVS_PF_P2CMEASURE_MODU_INFO;

// CH: 点线测量模块信息结构 | EN: Structure about information of point and line distance measurement module
typedef struct IMVS_PF_P2LMEASURE_MODU_INFO__
{
    int    iModuStatu;                    // CH: 模块状态 | EN: Module status
    float  fVertDist;                     // CH: 垂直距离 | EN: The vertical distance between the point and the segment
    float  fNearestDist;                  // CH: 最近距离 | EN: The shortest distance between the point and the segment
    float  fFarDist;                      // CH: 最远距离 | EN: The farthest distance between the point and the segment
    float  fAngle;                        // CH: 角度 | EN: Angle between the vertical line (between the point and the segment) and X-coordinate (positive direction)
    IMVS_PF_2DPOINT_F stBasePt;           // CH: 垂足点 | EN: Foot point coordinates
    IMVS_PF_2DPOINT_F stMeasuPt;          // CH: 测量点 | EN: Measured point coordinates
    IMVS_PF_2DPOINT_F stStartPt;          // CH: 测量直线起点 | EN: Coordinates of the line segment's start point
    IMVS_PF_2DPOINT_F stEndPt;            // CH: 测量直线终点 | EN: Coordinates of the line segment's end point
	float  fLineAngle;                    // CH: 测量直线角度 | EN: Angle of the line
    int    iReserved[4];                  // CH: 保留字段 | EN: Reserved
} IMVS_PF_P2LMEASURE_MODU_INFO;

// CH: 线线测量模块信息结构 | EN: Structure about information of line and line distance measurement module
typedef struct IMVS_PF_L2LMEASURE_MODU_INFO__
{
    int    iModuStatu;                  // CH: 模块状态 | EN: Module status
    float  fDist;                       // CH: 距离 | EN: Distance of lines
    float  fAbsDist;                    // CH: 绝对距离 | EN: Absolute distance of the lines
    float  fAngle;                      // CH: 夹角 | EN: Included angle between the two lines
    IMVS_PF_2DPOINT_F stIntersecPt;     // CH: 交点 | EN: Interaction point of the lines
    IMVS_PF_2DPOINT_F stStartPt1;       // CH: 测量直线1起点 | EN: Start point coordinates of line 1
    IMVS_PF_2DPOINT_F stEndPt1;         // CH: 测量直线1终点 | EN: End point coordinates of line 1
	float  fLine1Angle;                 // CH: 测量直线1角度 | EN: angle of line1
	float  fLine2Angle;                 // CH: 测量直线2角度 | EN: angle of line2
    IMVS_PF_2DPOINT_F stStartPt2;       // CH: 测量直线2起点 | EN: Start point coordinates of line 2
    IMVS_PF_2DPOINT_F stEndPt2;         // CH: 测量直线2终点 | EN: End point coordinates of line 2
	IMVS_PF_2DPOINT_F stShowAnglePt1;   // CH: 角度标识点1 | EN: Angle identification point 1
	IMVS_PF_2DPOINT_F stShowAnglePt2;   // CH: 角度标识点2 | EN: Angle identification point 2
	IMVS_PF_2DPOINT_F stShowAnglePt3;   // CH: 角度标识点3 | EN: Angle identification point 3
	IMVS_PF_2DPOINT_F stShowAnglePt4;   // CH: 角度标识点4 | EN: Angle identification point 4
	IMVS_PF_2DPOINT_F stShowAnglePt5;   // CH: 角度标识点5 | EN: Angle identification point 5
	int nCaliperBox1Num;                // CH: 卡尺检测区1数量 | EN: Number of caliper detection region 1
	IMVS_PF_REGION *  pstDetectRegion1; // CH: 卡尺检测区1 | EN: Detected region 1
	int nCaliperBox2Num;                // CH: 卡尺检测区2数量 | EN: Number of caliper detection region 2
	IMVS_PF_REGION *  pstDetectRegion2; // CH: 卡尺检测区2 | EN: Detected region 2
	int  iReserved[4];                  // CH: 保留字段 | EN: Reserved
} IMVS_PF_L2LMEASURE_MODU_INFO;

// CH: 点点测量模块信息结构 | EN: Structure about information of point to point distance measurement module
typedef struct IMVS_PF_P2PMEASURE_MODU_INFO__
{
    int    iModuStatu;                // CH: 模块状态 | EN: Module status
    float  fDist;                     // CH: 距离 | EN: The distance between the two points
    float  fAngle;                    // CH: 角度 | EN: Angle between the two points' connection line and the X-coordinate (positive direction)
    IMVS_PF_2DPOINT_F stMidPt;        // CH: 中点 | EN: The midpoint of the two points
    IMVS_PF_2DPOINT_F stMeasuPt1;     // CH: 测量点1 | EN: Coordinates of the measured point 1
    IMVS_PF_2DPOINT_F stMeasuPt2;     // CH: 测量点2 | EN: Coordinates of the measured point 2
    int    iReserved[4];              // CH: 保留字段 | EN: Reserved
} IMVS_PF_P2PMEASURE_MODU_INFO;

// CH: 拟合结果信息结构 | EN: Fitting results details structure
typedef struct IMVS_PF_FIT_RES_INFO__
{
    int    iMatchPt;                  // CH: 匹配点 | EN: Matching point
    float  fFitDist;                  // CH: 拟合距离 | EN: Fitting distance
    IMVS_PF_2DPOINT_F stFitPt;        // CH: 拟合点 | EN: Fitting point Coordinates
    int    iReserved[4];              // CH: 保留字段 | EN: Reserved
} IMVS_PF_FIT_RES_INFO;

// CH: 圆拟合模块信息结构 | EN: Structure about information of circle fitting module
typedef struct IMVS_PF_CIRCLEFIT_MODU_INFO__
{
    int    iModuStatu;                // CH: 模块状态 | EN: Module status
    int    iMatchNum;                 // CH: 匹配点数 | EN: The number of matched points
    int    iFitStatus;                // CH: 拟合状态 | EN: Fitting status
    float  fFitError;                 // CH: 拟合误差 | EN: Fitting error
    float  fRadius;                   // CH: 圆半径 | EN: Radius of the circle
    IMVS_PF_2DPOINT_F stCentPt;       // CH: 圆心点 | EN: Center point coordinates
    int    iFitPtNum;                 // CH: 拟合点数 | EN: The number of fitting points
    IMVS_PF_FIT_RES_INFO * pstCirfitResInfo; // CH: 圆拟合结果 | EN: Circle fitting result
    int    iReserved[4];              // CH: 保留字段 | EN: Reserved
} IMVS_PF_CIRCLEFIT_MODU_INFO;

// CH: 直线拟合模块信息结构 | EN: Structure about information of line fitting module
typedef struct IMVS_PF_LINEFIT_MODU_INFO__
{
    int    iModuStatu;                // CH: 模块状态 | EN: Module status
    int    iMatchNum;                 // CH: 匹配点数 | EN: The number of the points that meet requirements
    int    iFitStatus;                // CH: 拟合状态 | EN: Fitting status
    float  fFitError;                 // CH: 拟合误差 | EN: Fitting errors
    IMVS_PF_LINE_INFO stOutLine;      // CH: 输出直线 | EN: Information of the output line
    int    iFitPtNum;                 // CH: 拟合点数 | EN: Total number of the fitting points
    IMVS_PF_FIT_RES_INFO * pstLinefitResInfo; // CH: 线拟合结果 | EN: Curve fitting result
    int    iReserved[4];              // CH: 保留字段 | EN: Reserved
} IMVS_PF_LINEFIT_MODU_INFO;

// CH: 亮度测量模块信息结构 | EN: Structure about information of brightness detection module
typedef struct IMVS_PF_INTENSITYMEASURE_MODU_INFO__
{
    int    iModuStatu;               // CH: 模块状态 | EN: Module status
    int    iMinVal;                  // CH: 最小值 | EN: The minimum value
    int    iMaxVal;                  // CH: 最大值 | EN: The maximum value
    float  fAveVal;                  // CH: 均值 | EN: Average value
    float  fStdDevia;                // CH: 标准差 | EN: Standard deviation
	float  fHistContrast;            // CH: 对比度 | EN: Contrast
    int    iHist[256];               // CH: 直方图 | EN: Histogram
    IMVS_PF_REGION stDetectRegion;   // CH: 检测区域 | EN: Detected region
    int    iReserved[4];             // CH: 保留字段 | EN: Reserved
} IMVS_PF_INTENSITYMEASURE_MODU_INFO;

// CH: 像素统计模块信息结构 | EN: Structure about information of pixel statistics module
typedef struct IMVS_PF_PIXELCOUNT_MODU_INFO__
{
    int    iModuStatu;               // CH: 模块状态 | EN: Module status
    int    iPixelNum;                // CH: 像素数量 | EN: The number of pixels
    float  fRatio;                   // CH: 比率 | EN: Ratio
    IMVS_PF_REGION stDetectRegion;   // CH: 检测区域 | EN: Detected region
    int    iReserved[4];             // CH: 保留字段 | EN: Reserved
} IMVS_PF_PIXELCOUNT_MODU_INFO;

// CH: 直方图信息 | EN: Histogram information structure
typedef struct IMVS_PF_HIST_INFO__
{
    int    iPixelNum;                // CH: 像素数量 | EN: The number of pixels
    int    iMinVal;                  // CH: 最小值 | EN: The minimum value
    int    iMaxVal;                  // CH: 最大值 | EN: The maximum value
    int    iMidVal;                  // CH: 中值 | EN: Medium value
    int    iPeakVal;                 // CH: 峰值 | EN: Peak value
    float  fMeanVal;                 // CH: 均值 | EN: Average value
    float  fStdDev;                  // CH: 标准差 | EN: Standard deviation
	float  fHistContrast;            // CH: 对比度 | EN: Contrast
    int    iHist[256];               // CH: 直方图 | EN: Histogram
    int    iCumHist[256];            // CH: 累积直方图 | EN: Cumulative histogram
    int    iReserved[4];             // CH: 保留字段 | EN: Reserved
} IMVS_PF_HIST_INFO;

// CH: 直方图工具信息结构 | EN: Structure about information of histogram tool module
typedef struct IMVS_PF_HISTTOOL_MODU_INFO__
{
    int    iModuStatu;                   // CH: 模块状态 | EN: Module status
    IMVS_PF_HIST_INFO stHistInfo;        // CH: 直方图信息 | EN: Histogram information
    IMVS_PF_REGION    stDetectRegion;    // CH: 检测区域 | EN: Detected region
    int    iReserved[4];                 // CH: 保留字段 | EN: Reserved
} IMVS_PF_HISTTOOL_MODU_INFO;

// CH: 几何创建模块 | EN: Structure about information of geometry creation module
typedef struct IMVS_PF_GEOMETRYCREATE_MODU_INFO__
{
    int               iModuStatu;        // CH: 模块状态 | EN: Module status
    IMVS_PF_2DPOINT_F stOutPt;           // CH: 输出点 | EN: Outputted point coordinates
    IMVS_PF_LINE_INFO stOutLine;         // CH: 输出线 | EN: Outputted line information
    float             fRadius;           // CH: 圆半径 | EN: Radius
    IMVS_PF_2DPOINT_F stCirPt;           // CH: 圆心点 | EN: Center point coordinates
	char strModuResult[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];  // CH: 模块结果 | EN: Module result
    int               iReserved[4];      // CH: 保留字段 | EN: Reserved
} IMVS_PF_GEOMETRYCREATE_MODU_INFO;

// CH: 二维码结果信息结构 | EN: QR code result details structure
typedef struct IMVS_PF_2DCR_RES_INFO__
{
    int    iCodeStatu;               // CH: 码状态 | EN: QR code status
	float  fPPM;                     // CH: PPM | EN: PPM
    char   strCodeInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 编码信息 | EN: Encoding information
	int    iEstVersion;              // CH: 评估版本 | EN: Evaluation version
	int    iCodeType;                // CH: 码类型 | EN: Code type
	int    iColorFlag;               // CH: 极性标志 | EN: Polarity flag
	int    iNerrors;                 // CH: 错误码字数 | EN: Number of error code words
	int    iNumtemp;                 // CH: 已纠错字数 | EN: Number of corrected words
	float  fCodePosAngle;            // CH: 码角度 | EN: Code angle
    IMVS_PF_RECT_INFO stRect;        // CH: 矩形框 | EN: Information of the QR code rectangle
	IMVS_PF_2DPOINT_I stCodePos0;    // CH: 码角点0 | EN: Code corner point 0
	IMVS_PF_2DPOINT_I stCodePos1;    // CH: 码角点1 | EN: Code corner point 1
	IMVS_PF_2DPOINT_I stCodePos2;    // CH: 码角点2 | EN: Code corner point 2
	IMVS_PF_2DPOINT_I stCodePos3;    // CH: 码角点3 | EN: Code corner point 3
    int    iReserved[4];             // CH: 保留字段 | EN: Reserved
}IMVS_PF_2DCR_RES_INFO;

// CH: 二维码识别模块信息结构 | EN: Structure about information of QR code recognition module
typedef struct IMVS_PF_2DBCR_MODU_INFO__
{
    int    iModuStatu;               // CH: 模块状态 | EN: Module status
    IMVS_PF_REGION stDetectRegion;   // CH: 检测区域 | EN: Detected region
    int    iCodeNum;                 // CH: 码个数 | EN: The number of QR codes
    IMVS_PF_2DCR_RES_INFO * pst2DCRInfo; // CH: 二维码结果信息 | EN: QR code information
    int    iReserved[4];             // CH: 保留字段 | EN: Reserved
} IMVS_PF_2DBCR_MODU_INFO;

// CH: 条码结果信息结构 | EN: Bar code result structure
typedef struct IMVS_PF_BCR_RES_INFO__
{
    int    iCodeStatu;               // CH: 码状态 | EN: Barcode status
    int    iCodeType;                // CH: 码类型 | EN: Barcode type
    float  fCodeAngle;               // CH: 条码角度 | EN: Angle of the barcode
	float  fPPM;                     // CH: PPM | EN: PPM
    char   strCodeInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 编码信息 | EN: Encoding information
    IMVS_PF_RECT_INFO stRectInfo;    // CH: 矩形框信息 | EN: Bar code rectangle information
    int    iReserved[4];             // CH: 保留字段 | EN: Reserved
}IMVS_PF_BCR_RES_INFO;

// CH: 条码识别模块信息结构 | EN: Structure about information of bar code recognition module
typedef struct IMVS_PF_BCR_MODU_INFO__
{
    int    iModuStatu;               // CH: 模块状态 | EN: Module status
    IMVS_PF_REGION stDetectRegion;   // CH: 检测区域 | EN: Detected region
    int    iCodeNum;                 // CH: 码个数 | EN: The number of barcodes
    IMVS_PF_BCR_RES_INFO * pstBCRInfo; // CH: 条码结果信息 | EN: Bar code information
    int    iReserved[4];             // CH: 保留字段 | EN: Reserved
} IMVS_PF_BCR_MODU_INFO;

// CH: 整型矩形框信息结构 | EN: Structure about information of integer rectangle
typedef struct IMVS_PF_RECT_INFO_I__
{
    int    iWidth;                  // CH: 矩形宽度 | EN: Rectangle width
    int    iHeight;                 // CH: 矩形高度 | EN: Rectangle height
    float  fAngle;                  // CH: 矩形角度 | EN: Tilt angle of the rectangle
    IMVS_PF_2DPOINT_I stCentPt;     // CH: 中心点 | EN: Coordinates of the rectangle's center point
} IMVS_PF_RECT_INFO_I;

// CH: 浮点型矩形框信息结构 | EN: Structure of floating-point rectangle information
typedef struct IMVS_PF_RECT_INFO_F__
{
	float  fWidth;                  // CH: 矩形宽度 | EN: Rectangle width
	float  fHeight;                 // CH: 矩形高度 | EN: Rectangle Height
	float  fAngle;                  // CH: 矩形角度 | EN: Rectangle angle
	IMVS_PF_2DPOINT_F stCentPt;     // CH: 中心点 | EN: Coordinates of the rectangle's center point
} IMVS_PF_RECT_INFO_F;

// CH: 字符识别结果信息结构 | EN: Structure about information of character recognition module
typedef struct IMVS_PF_CHARRECON_RES_INFO__
{
	float fCharScore;                     // CH: 分数 | EN: Score
	float fConfidence;                    // CH: 置信度 | EN: Confidence
	float fCharBoxSkew;                   // CH: 字符矩形倾斜度 | EN: The skew of character rectangle
	float fChar0Score;                    // CH: 第1置信度字符分数 | EN: Score of character 0
	float fChar1Score;                    // CH: 第2置信度字符分数 | EN: Score of character 1
	char  chChar0[IMVS_PF_CHAR_RES_SIZE]; // CH: 第1置信度字符 | EN: Character 0
	char  chChar1[IMVS_PF_CHAR_RES_SIZE]; // CH: 第2置信度字符 | EN: Character 1
	IMVS_PF_RECT_INFO_F stCharRect;       // CH: 字符矩形 | EN: Character rectangle
} IMVS_PF_CHARRECON_RES_INFO;

// CH: 单个字符识别结果信息结构 | EN: Structure about information of Single character recognition result
typedef struct IMVS_PF_OCR_RES_INFO__
{
	char   strTextInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];       // CH: 第一置信度字符信息 | EN: First confidence text information
	char   strSecondTextInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 第二置信度字符信息 | EN: Second confidence text information
	IMVS_PF_REGION stDetectRegion;                                // CH: 检测区域 | EN: Detected region
	int    iCharNum;                                              // CH: 字符个数 | EN: Number of characters
	IMVS_PF_CHARRECON_RES_INFO * pstCharResInfo;                  // CH: 字符结果信息 | EN: Characters result information
} IMVS_PF_OCR_RES_INFO;

// CH: 字符识别模块信息结构 | EN: Structure about information of character recognition module
typedef struct IMVS_PF_OCR_MODU_INFO__
{
    int    iModuStatu;                    // CH: 模块状态 | EN: Module status
	int    iRecogResultNum;               // CH: 识别结果数量 | EN: Number of results
	IMVS_PF_OCR_RES_INFO * pstOCRResInfo; // CH: 字符识别结果 | EN: Character recognition results
    int    iReserved[4];                  // CH: 保留字段 | EN: Reserved
} IMVS_PF_OCR_MODU_INFO;

// CH: VeriCode码结果信息结构 | EN: Verification code result structure
typedef struct IMVS_PF_VERICODE_RES_INFO__
{
    char   strCodeInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 编码信息 | EN: Encoding information
    IMVS_PF_RECT_INFO_F stVeriCodeRect;    // CH: 矩形框 | EN: Information of the verification code's rectangle
    int    iReserved[4];                   // CH: 保留字段 | EN: Reserved
} IMVS_PF_VERICODE_RES_INFO;

// CH: VeriCode码模块信息结构 | EN: Structure about information of verification code module
typedef struct IMVS_PF_VERICODE_MODU_INFO__
{
    int    iModuStatu;                     // CH: 模块状态 | EN: Module status
    IMVS_PF_REGION      stDetectRegion;    // CH: 检测区域 | EN: Detected region
    int    iCodeNum;                       // CH: 码个数 | EN: The number of verification codes
    IMVS_PF_VERICODE_RES_INFO * pstVeriCodeRes; // CH: VeriCode码结果信息 | EN: Verification code information
    int    iReserved[4];                   // CH: 保留字段 | EN: Reserved
} IMVS_PF_VERICODE_MODU_INFO;

// CH: 标定板标定模块信息结构 | EN: Calibration module information structure
typedef struct IMVS_PF_CALIBBOARDCALIB_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    int    iCalibStatus;               // CH: 标定状态 | EN: Calibration status
    float  fCalibErr;                  // CH: 标定误差 | EN: Calibration error
    float  fPixAccuracy;               // CH: 像素精度 | EN: Pixel accuracy
    IMVS_PF_2DPOINT_F stCalibOriPt;    // CH: 标定原点 | EN: Calibration origin coordinates
	IMVS_PF_2DPOINT_F stCalibOriVecXPt;// CH: 坐标X向量 | EN: Vector X coordinates
	IMVS_PF_2DPOINT_F stCalibOriVecYPt;// CH: 坐标Y向量 | EN: Vector Y coordinates
    float  fPanX;                      // CH: 平移X | EN: The distance to translate to X-coordinate
    float  fPanY;                      // CH: 平移Y | EN: The distance to translate to Y-coordinate
    float  fRota;                      // CH: 旋转 | EN: Rotation angle
    float  fScale;                     // CH: 尺度 | EN: Scale
    float  fObliq;                     // CH: 斜切 | EN: Slope
    float  fWHRatio;                   // CH: 宽高比 | EN: Aspect ratio
    int    iCalibPtNum;                // CH: 标定点数 | EN: The number of calibration points
    IMVS_PF_2DPOINT_F * pstCalibPt;    // CH: 标定点 | EN: Calibration point coordinates
	IMVS_PF_REGION      stDetectRegion;// CH: 检测区域 | EN: Detected region
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_CALIBBOARDCALIB_MODU_INFO;

// CH: N点标定模块信息结构 | EN: Structure about information of N-Point calibration module
typedef struct IMVS_PF_ALIGNCALIB_MODU_INFO__
{
	int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    int    iCalibStatus;               // CH: 标定状态 | EN: Calibration status
	int    iCalibErrStatus;            // CH: 评估标定状态 | EN: Calibration Error Status
    float  fTransErr;                  // CH: 标定平移误差 | EN: Calibration translation error
    float  fRotatErr;                  // CH: 标定旋转误差 | EN: Calibration rotation error
    float  fPixAccuracy;               // CH: 像素精度 | EN: Pixel accuracy
	float  fPanX;                      // CH: 平移X | EN: The distance to translate to X-coordinate
	float  fPanY;                      // CH: 平移Y | EN: The distance to translate to Y-coordinate
	float  fRota;                      // CH: 旋转 | EN: Rotation angle
	float  fScale;                     // CH: 尺度 | EN: Scale
	float  fObliq;                     // CH: 斜切 | EN: Slope
	float  fWHRatio;                   // CH: 宽高比 | EN: Aspect ratio
    int    iCalibIndex;                // CH: 当前标定点 | EN: The current calibration point index
    int    iCalibTotalNum;             // CH: 标定点总数 | EN: The total number of the calibration points
	IMVS_PF_2DPOINT_F * pstImagePt;    // CH: 标定像素点 | EN: Pixel point coordinates
    IMVS_PF_2DPOINT_F * pstWorldPt;    // CH: 标定物理点 | EN: Physical point coordinates
	IMVS_PF_2DPOINT_F   stRotCenterImgPt; // CH: 旋转轴图像点 | EN: Rotating axis image points
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_ALIGNCALIB_MODU_INFO;

// CH: 标定物理信息结构 | EN: Structure of calibration world information
typedef struct IMVS_PF_CALIB_WORLD_INFO__
{
	float  fWorldAngle;                // CH: 标定物理角度 | EN: Calibration world angle
	IMVS_PF_2DPOINT_F stOutWorldPt;    // CH: 输出点 | EN: Outputted point coordinates
} IMVS_PF_CALIB_WORLD_INFO;

// CH: 标定转换模块信息结构 | EN: Structure about information of calibration conversion module
typedef struct IMVS_PF_CALIBTRANSFORM_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    float  fSinPixAccuracy;            // CH: 单像素精度 | EN: Single pixel accuracy
	float  fPanX;                      // CH: 平移X | EN: The distance to translate to X-coordinate
	float  fPanY;                      // CH: 平移Y | EN: The distance to translate to Y-coordinate
	float  fRota;                      // CH: 旋转 | EN: Rotation angle
	float  fScale;                     // CH: 尺度 | EN: Scale
	float  fObliq;                     // CH: 斜切 | EN: Slope
	float  fWHRatio;                   // CH: 宽高比 | EN: Aspect ratio
    int    iTransformNum;              // CH: 转换点数 | EN: The number of the converted points
	IMVS_PF_CALIB_WORLD_INFO * pstOutWorldInfo; // CH: 标定物理信息 | EN: Calibration world information
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_CALIBTRANSFORM_MODU_INFO;

// CH: 单位转换模块信息结构 | EN: Structure about information of unit conversion module
typedef struct IMVS_PF_SCALETRANSFORM_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    float  fPixAccuracy;               // CH: 单像素精度 | EN: Single pixel accuracy
    float  fTransformRes;              // CH: 转换结果 | EN: Conversion result
	float  fPixDist;                   // CH: 像素距离 | EN: Pixel distance
	float  fPanX;                      // CH: 平移X | EN: The distance to translate to X-coordinate
	float  fPanY;                      // CH: 平移Y | EN: The distance to translate to Y-coordinate
	float  fRota;                      // CH: 旋转 | EN: Rotation angle
	float  fScale;                     // CH: 尺度 | EN: Scale
	float  fObliq;                     // CH: 斜切 | EN: Slope
	float  fWHRatio;                   // CH: 宽高比 | EN: Aspect ratio
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_SCALETRANSFORM_MODU_INFO;

// CH: 畸变校正模块信息结构 | EN: Structure about information of distortion correction module
typedef struct IMVS_PF_IMAGECORRECT_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stCorrectImg;   // CH: 输出图像 | EN: Corrected image information
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGECORRECT_MODU_INFO;

// CH: 形态学处理模块信息结构 | EN: Structure about information of morphology processing module
typedef struct IMVS_PF_IMAGEMORPH_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stMorphOutImg;  // CH: 输出图像 | EN: Outputted image information
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGEMORPH_MODU_INFO;

// CH: 图像二值化模块信息结构 | EN: Image binarization module information structure
typedef struct IMVS_PF_BINARY_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stBinOutImg;    // CH: 输出图像 | EN: Binarization image information
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_BINARY_MODU_INFO;

// CH: 图像滤波模块信息结构 | EN: Image filtering module information structure
typedef struct IMVS_PF_IMAGEFILTER_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stFilterOutImg; // CH: 输出图像 | EN: IOutputted image information
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGEFILTER_MODU_INFO;

// CH: 图像增强模块信息结构 | EN: Structure about information of image enhancement module
typedef struct IMVS_PF_IMAGEENHANCE_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stEnhanceOutImg;// CH: 输出图像 | EN: Enhanced image information
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGEENHANCE_MODU_INFO;

// CH: 图像运算模块信息结构 | EN: Structure about information of image arithmetics module
typedef struct IMVS_PF_IMAGEMATH_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stMathOutImg;   // CH: 输出图像 | EN: Outputted image information
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGEMATH_MODU_INFO;

// CH: 清晰度评估模块信息结构 | EN: Structure about information of resolution accessment module
typedef struct IMVS_PF_IMAGESHARPNESS_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    float  fSharpness;                 // CH: 清晰度 | EN: Image sharpness
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGESHARPNESS_MODU_INFO;

// CH: 图像修正模块信息结构 | EN: Structure about information of image correction module
typedef struct IMVS_PF_IMAGEFIXTURE_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stFixOutImg;    // CH: 输出图像 | EN: Outputted image information
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGEFIXTURE_MODU_INFO;

// CH: 阴影校正模块信息结构 | EN: Structure about information of shadow correction module
typedef struct IMVS_PF_SHADECORRECT_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stShadeImg;     // CH: 输出图像 | EN: Outputted image information
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_SHADECORRECT_MODU_INFO;

// CH: 仿射变换模块信息结构 | EN: Structure about information of affine transformation module
typedef struct IMVS_PF_AFFINETRANSFORM_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stAffineImg;    // CH: 输出图像 | EN: Transformed image information
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_AFFINETRANSFORM_MODU_INFO;

// CH: 圆环区域信息结构 | EN: Ring information structure
typedef struct IMVS_PF_POLARREGION__
{
	float    fInnerRadius;            // CH: 检测区域内径 | EN: Internal diameter
	float    fOuterRadius;            // CH: 检测区域外径 | EN: External diameter
	float    fAngleSpan;              // CH: 检测区域角度范围 | EN: Angle range
	float    fStartAngle;             // CH: 检测区域起始角度 | EN: Start angle
	IMVS_PF_2DPOINT_F stCenterPt;     // CH: 检测区域中心点 | EN: Coordinates of the ring's center point
} IMVS_PF_POLARREGION;

// CH: 圆环展开模块信息结构 | EN: Structure about information of ring expandsion module
typedef struct IMVS_PF_POLARUNWARP_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO  stPolarImg;    // CH: 输出图像 | EN: Outputted image information
	IMVS_PF_POLARREGION stDetectRegion;// CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_POLARUNWARP_MODU_INFO;

// CH: 颜色抽取模块信息结构 | EN: Structure about information of color extraction module
typedef struct IMVS_PF_COLOREXTRACT_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
	float  fTotalArea;                 // CH: 总面积   | EN: Total Area
    IMVS_PF_IMAGE_INFO stExtractImg;   // CH: 输出图像 | EN: Outputted image information
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_COLOREXTRACT_MODU_INFO;

// CH: 通道信息结构 | EN: Channel information structure
typedef struct IMVS_PF_CHANNEL_INFO__
{
    int   iMin;                         // CH: 通道最小值 | EN: Channel minimum value
    int   iMax;                         // CH: 通道最大值 | EN: Channel maximum value
    float fAve;                         // CH: 通道均值 | EN: Channel mean value
    float fStdDev;                      // CH: 通道标准差 | EN: Channel standard deviation
    int   iHist[256];                   // CH: 通道直方图 | EN: Channel histogram
    int   iReserved[4];                 // CH: 保留字段 | EN: Reserved
}IMVS_PF_CHANNEL_INFO;

// CH: 颜色测量模块信息结构 | EN: Structure about information of color measurement module
typedef struct IMVS_PF_COLORMEASURE_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_CHANNEL_INFO stChannel1;   // CH: 通道1信息 | EN: Channel 1 information
    IMVS_PF_CHANNEL_INFO stChannel2;   // CH: 通道2信息 | EN: Channel 2 information
    IMVS_PF_CHANNEL_INFO stChannel3;   // CH: 通道3信息 | EN: Channel 3 information
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_COLORMEASURE_MODU_INFO;

// CH: 颜色转换模块信息结构 | EN: Structure about information of color conversion module
typedef struct IMVS_PF_COLORTRANSFORM_MODU_INFO__
{
    int    iModuStatu;                        // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stColorTransOutImg;    // CH: 输出图像 | EN: Converted image information
    int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_COLORTRANSFORM_MODU_INFO;

// CH: 条件检测模块信息结构 | EN: Structure about information of condition detection module
typedef struct IMVS_PF_IF_MODU_INFO__
{
    int    iModuStatu;                          // CH: 模块状态 | EN: Module status
    int    iIfRes;                              // CH: Int型结果 | EN: Integer result
    char   strIfRes[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 字符串型结果 | EN: String type result
    int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_IF_MODU_INFO;

// CH: 分支模块信息结构 | EN: Branching module information structure
typedef struct IMVS_PF_BRANCH_MODU_INFO__
{
	int    iModuStatu;                          // CH: 模块状态 | EN: Module status
    int    iTransMark;                          // CH: 传输标志 | EN: Transformation mark
	int    iOutputForEnd;                       // CH: 分支结束输出标志 | EN: Branch end output flag
	char   strBranchMatch[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 匹配分支 | EN: Matched module ID
    int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_BRANCH_MODU_INFO;

// CH: 逻辑模块信息结构 | EN: Logic module information structure
typedef struct IMVS_PF_AND_MODU_INFO__
{
    int    iModuStatu;                          // CH: 模块状态 | EN: Module status
    int    iBoolAndRes;                         // CH: 与结果BOOL | EN: Result of BOOL AND
    char   strBoolAndRes[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 与结果STRING | EN: Result of STRING AND
    int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_AND_MODU_INFO;

// CH: 格式化模块信息结构 | EN: Formatting module information structure
typedef struct IMVS_PF_FORMAT_MODU_INFO__
{
    int    iStatus;                             // CH: 状态 | EN: Module status
    char   strFormatOut[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 格式化输出 | EN: Formatted output
    int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_FORMAT_MODU_INFO;

// CH: 变量计算输出结果信息结构 | EN: Structure about information of calculation module output result
typedef struct IMVS_PF_CALCULATOR_RESULT_INFO__
{
	char            strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH];    // CH: 结果名称 | EN: Result name
	int             nParamType;                                           // CH: 结果类型:1整型 2浮点型 | EN: Result type: 1-integer, 2-float
	int             nIntValue;                                            // CH: 整型数据 | EN: Integer data
	float           fFloatValue;                                          // CH: 浮点型数据 | EN: Float data
} IMVS_PF_CALCULATOR_RESULT_INFO;

// CH: 变量计算模块信息结构 | EN: Variable calculation module information structure
typedef struct IMVS_PF_CALCULATOR_MODU_INFO__
{
    int    iStatus;                             // CH: 状态 | EN: Calculation status
    char   strCalculateOut[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 计算器输出 | EN: Calculation result
	int    nOutResNum;                          // CH: 结果个数 | EN: Number of output result
	IMVS_PF_CALCULATOR_RESULT_INFO * pstCalResInfo; // CH: 输出结果 | EN: Output result
	int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_CALCULATOR_MODU_INFO;

// CH: 字符比较模块信息结构 | EN: Structure about information of character comparison module
typedef struct IMVS_PF_STRINGCOMPARE_MODU_INFO__
{
    int    iModuStatu;                          // CH: 模块状态 | EN: Module status
    int    iIndex;                              // CH: 字符索引 | EN: String index
    char   strStringMatch[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 比较字符 | EN: Inputted string
    int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_STRINGCOMPARE_MODU_INFO;

// CH: 输出模块结果信息结构 | EN: Structure about information of output module result
typedef struct IMVS_PF_OUTPUT_RESULT_INFO__
{
	char            strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH];    // CH: 结果名称 | EN: Result name
	int             nParamType;                                           // CH: 结果类型:1整型 2浮点型 3字符串型 | EN: Result type: 1-integer, 2-float, 3-string
	int             nValueNum;                                            // CH: 模块值个数 | EN: Number of module values
	int *           pIntValue;                                            // CH: 整型数据 | EN: Integer data
	float *         pFloatValue;                                          // CH: 浮点型数据 | EN: Float data
	IMVS_PF_MODULE_STRING_VALUE * pstStringValue;                         // CH: 字符串型数据 | EN: String data
} IMVS_PF_OUTPUT_RESULT_INFO;

// CH: 脚本模块信息结构 | EN: Script module information structure
typedef struct IMVS_PF_SHELL_MODU_INFO__
{
    int    iModuStatu;                          // CH: 模块状态 | EN: Module status
    char   strResInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 结果显示 | EN: Results
	int    nResultNum;                          // CH: 结果数量 | EN: Number of results
	IMVS_PF_OUTPUT_RESULT_INFO * pstOutResInfo; // CH: 脚本模块结果 | EN: Script module result
    int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_SHELL_MODU_INFO;

// CH: 点集模块信息结构 | EN: Structure about information of point set module
typedef struct IMVS_PF_POINTSET_MODU_INFO__
{
    int    iModuStatu;                          // CH: 模块状态 | EN: Module status
    int    iPtNum;                              // CH: 点个数 | EN: The number of points
    IMVS_PF_2DPOINT_F * pstPointSetPt;          // CH: 点集 | EN: Point set information
    int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_POINTSET_MODU_INFO;

// CH: 分支字符比较模块信息结构 | EN: Structure about information of string comparison module
typedef struct IMVS_PF_BRANCHSTRINGCPM_MODU_INFO__
{
    int    iModuStatu;                          // CH: 模块状态 | EN: Module status
	int    iOutputForEnd;                       // CH: 分支结束输出标志 | EN: Branch end output flag
    char   strBranchMatch[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 匹配分支 | EN: Matched module ID
    char   strStringMatch[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 匹配字符 | EN: Received string information
    int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_BRANCHSTRINGCPM_MODU_INFO;

// CH: 帧平均模块信息结构 | EN: Structure about information of frame averaging module
typedef struct IMVS_PF_FRAMEMEAN_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    int    iImgNum;                    // CH: 已统计图像数 | EN: The number of the counted images
    IMVS_PF_IMAGE_INFO stFrameMeanImg; // CH: 帧平均图像 | EN: Frame averaging image
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_FRAMEMEAN_MODU_INFO;

// CH: 图像组合模块信息结构 | EN: Structure about information of image combination module
typedef struct IMVS_PF_IMAGECOMBINEPROCESS_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stOutputImg;    // CH: 输出图像 | EN: Composite image information
    IMVS_PF_IMAGE_INFO stMidImg;       // CH: 中间图像 | EN: Middle image information
    IMVS_PF_REGION stDetectRegion;     // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGECOMBINEPROCESS_MODU_INFO;

// CH: 字符缺陷信息结构 | EN: Structure about information of character defect
typedef struct IMVS_PF_MARK_DEFECT_INFO__
{
	int    iMarkStatu;                 // CH: 字符状态 | EN: Whether the character is defective
	IMVS_PF_REGION stMarkBox;          // CH: 字符框 | EN: Character box
} IMVS_PF_MARK_DEFECT_INFO;

// CH: 字符缺陷检测模块信息结构 | EN: Structure about information of character bug detection module
typedef struct IMVS_PF_MARKINSP_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
	int    iMatchStatus;               // CH: 匹配状态 | EN: Match status
    int    iMarkBoxNum;                // CH: 字符框个数 | EN: The number of character boxes
	IMVS_PF_MARK_DEFECT_INFO * pstMarkDefectInfo; // CH: 字符缺陷信息 | EN: Character defect information
    IMVS_PF_REGION   stDetectRegion;   // CH: 检测区域 | EN: Detected region
    int    iDefectNum;                 // CH: 缺陷个数 | EN: The number of defects
    IMVS_PF_REGION * pstDefectBox;     // CH: 缺陷框 | EN: Defective box information
	IMVS_PF_REGION   pstMatchRect;     // CH: 匹配狂 | EN: Match rect information
    IMVS_PF_IMAGE_INFO stDefBinaryImg; // CH: 缺陷二值图像 | EN: Binary image information
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_MARKINSP_MODU_INFO;

// CH: 拷贝填充模块信息结构 | EN: Structure about information of copy and filling module
typedef struct IMVS_PF_REGIONCOPY_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stOutputImg;    // CH: 输出图像 | EN: Outputted image information
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
	int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_REGIONCOPY_MODU_INFO;

// CH: 畸变标定模块信息结构 | EN: Structure about information of distortion calibration module
typedef struct IMVS_PF_IMAGECALIB_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    int    iCalibStatu;                // CH: 标定状态 | EN: Calibration status
    float  fCalibError;                // CH: 标定误差 | EN: Calibration errors
	float  fEstError;                  // CH: 估计误差 | EN: Estimation error
    IMVS_PF_IMAGE_INFO stOutputImg;    // CH: 输出图像 | EN: Outputted image information
    int    iCalibNum;                  // CH: 标定点数 | EN: The number of calibration points
    IMVS_PF_2DPOINT_F * pstCalibPoint; // CH: 标定点 | EN: Calibration point coordinates
	IMVS_PF_REGION   stDetectRegion;   // CH: 检测区域 | EN: Detected region
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGECALIB_MODU_INFO;

// CH: 图像归一化模块信息结构 | EN: Structure about information of image normalization module
typedef struct IMVS_PF_IMAGENORMLIZE_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    IMVS_PF_IMAGE_INFO stOutputImg;    // CH: 输出图像 | EN: Outputted image information
    IMVS_PF_REGION   stDetectRegion;   // CH: 检测区域 | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROI圆弧 | EN: ROI Arc
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGENORMLIZE_MODU_INFO;

// CH: 耗时统计模块信息结构 | EN: Structure about information of time-consuming statistics module
typedef struct IMVS_PF_TIMESTATISTIC_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    float  fTimeConsume;               // CH: 耗时 | EN: Time consumed
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_TIMESTATISTIC_MODU_INFO;

// CH: 文本保存模块信息结构 | EN: Structure about information of text storage module
typedef struct IMVS_PF_SAVETEXT_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
	char   strSavePath[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 保存路径 | EN: Save path
	char   strFileName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 文件名称 | EN: File name
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_SAVETEXT_MODU_INFO;

// CH: 接收数据模块信息结构 | EN: Structure about information of data receiving module
typedef struct IMVS_PF_READDATAS_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
	int    nResultNum;                 // CH: 结果数量 | EN: Number of results
	IMVS_PF_OUTPUT_RESULT_INFO * pstOutResInfo; // CH: 接收数据模块结果 | EN: Script module result
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_READDATAS_MODU_INFO;

// CH: 发送数据模块信息结构 | EN: Structure about information of data sending module 
typedef struct IMVS_PF_SENDDATAS_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    char   strSendDatas[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 发送数据 | EN: Data sent via the module
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_SENDDATAS_MODU_INFO;

// CH: 相机映射模块信息结构 | EN: Structure about information of camera mapping module
typedef struct IMVS_PF_CAMERAMAP_MODU_INFO__
{
    float  fScaleX;                 // CH: x方向比例 | EN: Scale in X direction
    float  fScaleY;                 // CH: y方向比例 | EN: Scale in Y direction
    int    iCalibStatus;            // CH: 标定状态 | EN: Calibration status
	float  fPanX;                   // CH: 平移X | EN: The distance to translate to X-coordinate
	float  fPanY;                   // CH: 平移Y | EN: The distance to translate to Y-coordinate
	float  fRota;                   // CH: 旋转 | EN: Rotation angle
	float  fScale;                  // CH: 尺度 | EN: Scale
	float  fObliq;                  // CH: 斜切 | EN: Slope
	float  fWHRatio;                // CH: 宽高比 | EN: Aspect ratio
    int    iReserved[4];            // CH: 保留字段 | EN: Reserved
} IMVS_PF_CAMERAMAP_MODU_INFO;

// CH: 单点对位模块信息结构 | EN: Structure about information of single point alignment module
typedef struct IMVS_PF_SINGLEPOINTALIGN_MODU_INFO__
{
    int    iModuStatu;              // CH: 模块状态 | EN: Module status
    float  fDeltaX;                 // CH: x偏移 | EN: X-offset
    float  fDeltaY;                 // CH: y偏移 | EN: Y-offset
    float  fDeltaTheta;             // CH: theta偏移 | EN: Theta-offset
    int    iReserved[4];            // CH: 保留字段 | EN: Reserved
} IMVS_PF_SINGLEPOINTALIGN_MODU_INFO;

// CH: 点集对位模块信息结构 | EN: Structure about information of point set alignment module
typedef struct IMVS_PF_MULTIPOINTALIGN_MODU_INFO__
{
    int    iModuStatu;              // CH: 对位状态 | EN: Module status
    float  fDeltaX;                 // CH: x偏移 | EN: X-offset
    float  fDeltaY;                 // CH: y偏移 | EN: Y-offset
    float  fDeltaTheta;             // CH: theta偏移 | EN: Theta-offset
    int    iReserved[4];            // CH: 保留字段 | EN: Reserved
} IMVS_PF_MULTIPOINTALIGN_MODU_INFO;

// CH: 线对位模块信息结构 | EN: Structure about information of line alignment module
typedef struct IMVS_PF_LINEALIGN_MODU_INFO__
{
    int    iModuStatu;              // CH: 对位状态 | EN: Module status
    float  fDeltaX;                 // CH: x偏移 | EN: X-offset
    float  fDeltaY;                 // CH: y偏移 | EN: Y-offset
    float  fDeltaTheta;             // CH: theta偏移 | EN: Theta-offset
    int    iReserved[4];            // CH: 保留字段 | EN: Reserved
} IMVS_PF_LINEALIGN_MODU_INFO;

// CH: 检测区域信息结构 | EN: Detected region information structure
typedef struct IMVS_PF_OCRDLDETECT_REGION__
{
	int   iOptimalCharNum;              // CH: 最优字符个数 | EN: Optimal number of characters
	float fOptimalTextConf;             // CH: 最优字符串置信度 | EN: Optimal string confidence level
	char  strOptimalText[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 最佳字符串信息 | EN: Optimal string information
    int   iRegionStatus;                // CH: 检测区域状态 | EN: Detected region status
    IMVS_PF_REGION stDetectRegion;      // CH: 检测区域 | EN: Detected region information
} IMVS_PF_OCRDLDETECT_REGION;

// CH: 深度学习字符识别结果信息结构 | EN: Structure about information of DL character recognition result
typedef struct IMVS_PF_OCRDL_RESULT_INFO__
{
	int    iCharNum;              // CH: 字符个数 | EN: The number of characters
	float  fTextConf;             // CH: 字符串置信度 | EN: String confidence level
	char   strChConfidence[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 字符置信度 | EN: Character confidence level
	char   strRoiSeq[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];       // CH: 检测序号 | EN: Detection serial number
	char   strFontInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];     // CH: 字符串信息 | EN: String information
} IMVS_PF_OCRDL_RESULT_INFO;

// CH: 深度学习字符识别模块信息结构 | EN: Structure about information of DL character recognition module
typedef struct IMVS_PF_OCRDL_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
    int    iOcrDLResNum;               // CH: 字符识别结果个数 | EN: The number of characters
    int    iDetectNum;                 // CH: 捡测区域个数 | EN: The number of detected regions
	IMVS_PF_OCRDL_RESULT_INFO *  pstOcrDLResInfo;  // CH: 字符识别结果信息 | EN: DL character recognition result information
	IMVS_PF_OCRDLDETECT_REGION * pstDetectRegion;  // CH: 检测区域 | EN: Detected region
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_OCRDL_MODU_INFO;

// CH: 深度学习类别信息结构 | EN: Structure about information of DL class
typedef struct IMVS_PF_CNNFLAW_CLASS_INFO__
{
	int    iGrayValue;                 // CH: 灰度值 | EN: Grayscale value
	char   strClassName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 类别名称 | EN: Class name
} IMVS_PF_CNNFLAW_CLASS_INFO;

// CH: 深度学习图像分割模块信息结构 | EN: Structure about information of DL image segmentation module
typedef struct IMVS_PF_CNNFLAW_MODU_INFO__
{
    int    iModuStatu;                 // CH: 模块状态 | EN: Module status
	int    iMinScore;                  // CH: 最小分数 | EN: Minimum score
	int    iProbHist[256];             // CH: 概率直方图 | EN: Probability histogram
	int    iClassNum;                  // CH: 类别数量 | EN: Number of class
	IMVS_PF_CNNFLAW_CLASS_INFO * pstClassInfo; // CH: 类别信息 | EN: Class information
	IMVS_PF_IMAGE_INFO stScoreImg;     // CH: 概率图 | EN: Probability image
	IMVS_PF_IMAGE_INFO stClassImg;     // CH: 类别图 | EN: Class image
	int    iFlawImgNum;                // CH: 缺陷概率图个数 | EN: Number of defect probability images
	IMVS_PF_IMAGE_INFO stFlawScoreImg[IMVS_PF_MAX_FLAW_SCORE_IMAGE_NUM]; // CH: 缺陷概率图 | EN: Defect probability images
    IMVS_PF_REGION     stDetectRegion; // CH: 检测区域 | EN: Detected region information
    int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_CNNFLAW_MODU_INFO;

// CH: 字符定位目标信息结构 | EN: Structure of character locating result details
typedef struct IMVS_PF_CHARTARGET_INFO__
{
    float fTarConfidence;              // CH: 目标置信度 | EN: Confidence level of the character locating result
    int   iTarStatus;                  // CH: 目标状态 | EN: Whether the locating result meets requirements: 1-yes, other-no
    IMVS_PF_RECT_INFO_F stTargetRect;  // CH: 目标信息矩形 | EN: Rectangle box information
} IMVS_PF_CHARTARGET_INFO;

// CH: 深度学习字符定位模块信息结构 | EN: Structure about information of DL character locating module
typedef struct IMVS_PF_CNNCHARDETECT_MODU_INFO__
{
    int    iModuStatu;                  // CH: 模块状态 | EN: Module status
    int    iTargetNum;                  // CH: 目标个数 | EN: The number of located characters
    IMVS_PF_CHARTARGET_INFO * pstTargetInfo; // CH: 目标信息结构 | EN: Details of the character locating result
    IMVS_PF_REGION      stDetectRegion; // CH: 检测区域 | EN: Detected region
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_CNNCHARDETECT_MODU_INFO;

// CH: 类别信息结构 | EN: Category information structure
typedef struct IMVS_PF_CLASS_INFO__
{
    int   iCateLabels;    // CH: 类别标签 | EN: Category label
    float fProbability;   // CH: 类别概率 | EN: Category probability
	char  strClassName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: 类别名称 | EN: Category name
} IMVS_PF_CLASS_INFO;

// CH: 深度学习分类模块信息结构 | EN: Structure about information of DL classification module
typedef struct IMVS_PF_CNNCLASSIFY_MODU_INFO__
{
    int    iModuStatu;                  // CH: 模块状态 | EN: Module status
    int    iClassNum;                   // CH: 类别个数 | EN: The number of categories
	float  fConfidence;                 // CH: 置信度 | EN: Confidence
    IMVS_PF_CLASS_INFO * pstClassInfo;  // CH: 类别信息 | EN: Category information
    IMVS_PF_REGION       stDetectRegion;// CH: 检测区域 | EN: Detected region
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_CNNCLASSIFY_MODU_INFO;

// CH: 目标信息结构 | EN: Target information structure
typedef struct IMVS_PF_TARGET_INFO__
{
    int   iTarCategory;                // CH: 目标类别 | EN: Target category
    float fTarConfidence;              // CH: 目标置信度 | EN: Target confidence level
    int   iTarStatus;                  // CH: 目标状态 | EN: Target status
	float fObjRadius;                  // CH: 目标半径 | EN: Target radius
	char  strClassName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: 类别名称 | EN: Class name
    IMVS_PF_RECT_INFO_F stTargetRect;  // CH: 目标信息矩形 | EN: Rectangle box information
} IMVS_PF_TARGET_INFO;

// CH: 深度学习目标检测模块信息结构 | EN: Structure about information of DL target detection module
typedef struct IMVS_PF_CNNDETECT_MODU_INFO__
{
    int    iModuStatu;                  // CH: 模块状态 | EN: Module status
    int    iTargetNum;                  // CH: 目标个数 | EN: The number of targets
    IMVS_PF_TARGET_INFO * pstTargetInfo;// CH: 目标信息结构 | EN: Target information structure
    IMVS_PF_REGION      stDetectRegion; // CH: 检测区域 | EN: Detected region
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_CNNDETECT_MODU_INFO;

// CH: 单字符定位目标信息结构 | EN: Structure of single character locating result details
typedef struct IMVS_PF_SINGLECHARTARGET_INFO__
{
	float fTarConfidence;              // CH: 目标置信度 | EN: Confidence level of the character locating result
	int   iMarkStatus;                 // CH: 字符状态 | EN: Character status
	char  strSingleCharInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: 单字符信息 | EN: Single character information
	IMVS_PF_RECT_INFO_F stTargetRect;  // CH: 目标信息矩形 | EN: Rectangle box information
} IMVS_PF_SINGLECHARTARGET_INFO;

// CH: 文本信息结构 | EN: Structure of text information
typedef struct IMVS_PF_TEXT_INFO__
{
	int   iTarStatus;                  // CH: 目标状态 | EN: Target status
	IMVS_PF_RECT_INFO_F stTextBox;     // CH: 文本框信息 | EN: Text box information
} IMVS_PF_TEXT_INFO;

// CH: 字符信息结构 | EN: Character information structure
typedef struct IMVS_PF_CHARACTER_INFO__
{
	int   iCharNum;                // CH: 字符个数 | EN: Number of characters
	float fTextConf;               // CH: 字符串置信度 | EN: String confidence level
	char  strRoiSeq[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];  // CH: 检测序号 | EN: Detection serial number
	char  strText[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: 字符信息 | EN: Character information
} IMVS_PF_CHARACTER_INFO;

// CH: 深度学习单字符检测模块信息结构 | EN: Structure about information of DL single character detection module
typedef struct IMVS_PF_CNNSINGLECHARDETECT_MODU_INFO__
{
	int    iModuStatu;                  // CH: 模块状态 | EN: Module status
	int    iTextNum;                    // CH: 文本信息个数 | EN: The number of text information
	int    iTargetNum;                  // CH: 目标个数 | EN: The number of located characters
	int    iCharInfoNum;                // CH: 字符信息数量 | EN: Number of character information
	IMVS_PF_TEXT_INFO * pstTextInfo;    // CH: 文本信息 | EN: Text information
	IMVS_PF_SINGLECHARTARGET_INFO * pstTargetInfo; // CH: 目标信息结构 | EN: Details of the character locating result
	IMVS_PF_CHARACTER_INFO        * pstCharInfo;   // CH: 字符信息结构 | EN: Character information structure
	IMVS_PF_REGION      stDetectRegion; // CH: 检测区域 | EN: Detected region
	int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_CNNSINGLECHARDETECT_MODU_INFO;

// CH: 深度学习训练工具模块信息结构 | EN: Structure about information of DL training tool module
typedef struct IMVS_PF_CNNTRAINTOOL_MODU_INFO__
{
    int    iModuStatu;                  // CH: 模块状态 | EN: Module status
    int    iTrainProgress;              // CH: 训练进度 | EN: Training progress
    float  fTrainErr;                   // CH: 训练误差 | EN: Training error
    int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_CNNTRAINTOOL_MODU_INFO;

// CH: 缺陷框信息结构 | EN: Structure about information of defect box
typedef struct IMVS_PF_FLAWRECT_INFO__
{
	int    iCaliperStart;               // CH: 卡尺起始值 | EN: Caliper start value
	int    iCaliperEnd;                 // CH: 卡尺终止值 | EN: Caliper end value
	int    iDefectType;                 // CH: 缺陷类型 | EN: Type of defect
	float  fDefectSize;                 // CH: 缺陷尺寸 | EN: Size of defect
	float  fDefectArea;                 // CH: 缺陷面积 | EN: Area of defect
	IMVS_PF_RECT_INFO_F stFlawRect;     // CH: 缺陷框 | EN: Defect box
} IMVS_PF_FLAWRECT_INFO;

// CH: 边缘点信息结构 | EN: Structure about information of edge point
typedef struct IMVS_PF_EDGEPOINT_INFO__
{
	int    iEdgePtStatu;                // CH: 边缘点状态 | EN: Edge point status
	IMVS_PF_2DPOINT_F stEdgePoint;      // CH: 边缘点 | EN: Edge point
} IMVS_PF_EDGEPOINT_INFO;

// CH: 卡尺信息结构 | EN: Structure about information of caliper
typedef struct IMVS_PF_CALIPPOINT_INFO__
{
	int    iCalipPtStatu;               // CH: 卡尺状态 | EN: Caliper status
	IMVS_PF_2DPOINT_F stCalipPoint;     // CH: 卡尺信息 | EN: Caliper information
} IMVS_PF_CALIPPOINT_INFO;

// CH: 缺陷综合信息结构 | EN: Structure about defect comprehensive information
typedef struct IMVS_PF_DEFECT_COMPRE_INFO__
{
	float    fMinWidth;                   // CH: 最小宽度 | EN: Minimum width
	float    fMaxWidth;                   // CH: 最大宽度 | EN: Maximum width
	float    fAverageWidth;               // CH: 平均宽度 | EN: Average width
	float    fApproximateArea;            // CH: 近似面积 | EN: Approximate area
} IMVS_PF_DEFECT_COMPRE_INFO;

// CH: 圆弧边缘缺陷模块信息结构 | EN: Structure about information of arc edge defect module
typedef struct IMVS_PF_CIRCLEEDGEINSP_MODU_INFO__
{
	int    iModuStatu;                            // CH: 模块状态 | EN: Module status
	int    iFlawNum;                              // CH: 缺陷个数 | EN: Number of defects
	int    iEdgePointNum;                         // CH: 边缘点个数 | EN: Number of edge points
	int    iCalipIdeaPointNum;                    // CH: 卡尺数量 | EN: Number of caliper
	float  fStandardRadius;                       // CH: 输出标准圆半径 | EN: Radius of output standard circle
	IMVS_PF_2DPOINT_F       stStandardCirPt;      // CH: 输出标准圆心点 | EN: Center point of output standard circle
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo;    // CH: 缺陷框信息 | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePtInfo;      // CH: 边缘点信息 | EN: Edge point information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;     // CH: 卡尺信息 | EN: Caliper information
	IMVS_PF_ANNULUS_CIRCLE_INFO stAnnulusCirInfo; // CH: 输出圆信息 | EN: Output circle information
	IMVS_PF_REGION              stDetectRegion;   // CH: 检测区域 | EN: Detected region
	int    iReserved[4];                          // CH: 保留字段 | EN: Reserved
} IMVS_PF_CIRCLEEDGEINSP_MODU_INFO;

// CH: 直线边缘缺陷模块信息结构 | EN: Structure about information of straight-line edge defect module
typedef struct IMVS_PF_LINEEDGEINSP_MODU_INFO__
{
	int    iModuStatu;                         // CH: 模块状态 | EN: Module status
	int    iFlawNum;                           // CH: 缺陷个数 | EN: Number of defects
	int    iEdgePointNum;                      // CH: 边缘点个数 | EN: Number of edge points
	int    iCalipIdeaPointNum;                 // CH: 卡尺数量 | EN: Number of caliper
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo; // CH: 缺陷框信息 | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePtInfo;   // CH: 边缘点信息 | EN: Edge point information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;  // CH: 卡尺信息 | EN: Caliper information
	IMVS_PF_LINE_INFO         stStandardLine;  // CH: 输出标准直线 | EN: Output standard line
	IMVS_PF_REGION            stDetectRegion;  // CH: 检测区域 | EN: Detected region
	int    iReserved[4];                       // CH: 保留字段 | EN: Reserved
} IMVS_PF_LINEEDGEINSP_MODU_INFO;

// CH: 圆弧对缺陷模块信息结构 | EN: Structure about information of arc pair edge defect module
typedef struct IMVS_PF_CIRCLEEDGEPAIRINSP_MODU_INFO__
{
	int    iModuStatu;                            // CH: 模块状态 | EN: Module status
	int    iFlawNum;                              // CH: 缺陷个数 | EN: Number of defects
	int    iEdge0PointNum;                        // CH: 边缘点0个数 | EN: Number of edge 0 points
	int    iEdge1PointNum;                        // CH: 边缘点1个数 | EN: Number of edge 1 points
	int    iCalipIdeaPointNum;                    // CH: 卡尺数量 | EN: Number of caliper
	float  fStandardRadius0;                      // CH: 输出标准圆半径0 | EN: Radius of output standard circle 0
	float  fStandardRadius1;                      // CH: 输出标准圆半径1 | EN: Radius of output standard circle 1
	IMVS_PF_2DPOINT_F       stStandardCirPt0;     // CH: 输出标准圆心点0 | EN: Center point of output standard circle 0
	IMVS_PF_2DPOINT_F       stStandardCirPt1;     // CH: 输出标准圆心点1 | EN: Center point of output standard circle 1
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo;    // CH: 缺陷框信息 | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt0Info;     // CH: 边缘点0信息 | EN: Edge point 0 information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt1Info;     // CH: 边缘点1信息 | EN: Edge point 1 information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;     // CH: 卡尺信息 | EN: Caliper information
	IMVS_PF_ANNULUS_CIRCLE_INFO stAnnulusCirInfo; // CH: 输出圆信息 | EN: Output circle information
	IMVS_PF_REGION              stDetectRegion;   // CH: 检测区域 | EN: Detected region
	IMVS_PF_DEFECT_COMPRE_INFO  stDefectCompreInfo; // CH: 缺陷综合信息 | EN: Defect comprehensive information
	int    iReserved[4];                          // CH: 保留字段 | EN: Reserved
} IMVS_PF_CIRCLEEDGEPAIRINSP_MODU_INFO;

// CH: 直线对缺陷模块信息结构 | EN: Structure about information of straight-line pair edge defect module
typedef struct IMVS_PF_LINEEDGEPAIRINSP_MODU_INFO__
{
	int    iModuStatu;                         // CH: 模块状态 | EN: Module status
	int    iFlawNum;                           // CH: 缺陷个数 | EN: Number of defects
	int    iEdge0PointNum;                     // CH: 边缘点0个数 | EN: Number of edge 0 points
	int    iEdge1PointNum;                     // CH: 边缘点1个数 | EN: Number of edge 1 points
	int    iCalipIdeaPointNum;                 // CH: 卡尺数量 | EN: Number of caliper
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo; // CH: 缺陷框信息 | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt0Info;  // CH: 边缘点0信息 | EN: Edge point 0 information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt1Info;  // CH: 边缘点1信息 | EN: Edge point 1 information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;  // CH: 卡尺信息 | EN: Caliper information
	IMVS_PF_LINE_INFO         stStandardLine0; // CH: 输出标准直线0 | EN: Output standard line 0
	IMVS_PF_LINE_INFO         stStandardLine1; // CH: 输出标准直线1 | EN: Output standard line 1
	IMVS_PF_REGION            stDetectRegion;  // CH: 检测区域 | EN: Detected region
	IMVS_PF_DEFECT_COMPRE_INFO stDefectCompreInfo; // CH: 缺陷综合信息 | EN: Defect comprehensive information
	int    iReserved[4];                       // CH: 保留字段 | EN: Reserved
} IMVS_PF_LINEEDGEPAIRINSP_MODU_INFO;

// CH: 标准输出圆输出直线组合信息结构 | EN: Structure about information of standard output circle and line
typedef struct IMVS_PF_STANDARD_LINEANDCIR_INFO__
{
	int     iCircleNum;                       // CH: 输出标准圆数量 | EN: Number of output standard circle
	int     iLineNum;                         // CH: 输出标准直线数量 | EN: Number of output standard line
	float * pfStandardCirRadius;              // CH: 输出标准圆半径 | EN: Output standard circle radius
	IMVS_PF_2DPOINT_F * pstStandardCirPt;     // CH: 输出标准圆心点 | EN: Output standard center point
	IMVS_PF_LINE_INFO * pstStandardLine;      // CH: 输出标准直线 | EN: Output standard line
} IMVS_PF_STANDARD_LINEANDCIR_INFO;

// CH: 边缘缺陷组合模块信息结构 | EN: Structure about information of edge defect combination
typedef struct IMVS_PF_EDGEINSPGROUP_MODU_INFO__
{
	int    iModuStatu;                         // CH: 模块状态 | EN: Module status
	int    iFlawNum;                           // CH: 缺陷个数 | EN: Number of defects
	int    iEdgePointNum;                      // CH: 边缘点个数 | EN: Number of edge points
	int    iCalipIdeaPointNum;                 // CH: 卡尺数量 | EN: Number of caliper
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo; // CH: 缺陷框信息 | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePtInfo;   // CH: 边缘点信息 | EN: Edge point information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;  // CH: 卡尺信息 | EN: Caliper information
	IMVS_PF_STANDARD_LINEANDCIR_INFO stStandardLineAndCirInfo;    // CH: 输出标准直线以及标准圆信息 | EN: Standard output circle and line information
	int    iReserved[4];                       // CH: 保留字段 | EN: Reserved
} IMVS_PF_EDGEINSPGROUP_MODU_INFO;

// CH: 边缘对缺陷组合模块信息结构 | EN: Structure about information of edge pair defect combination
typedef struct IMVS_PF_EDGEPAIRINSPGROUP_MODU_INFO__
{
	int    iModuStatu;                         // CH: 模块状态 | EN: Module status
	int    iFlawNum;                           // CH: 缺陷个数 | EN: Number of defects
	int    iEdge0PointNum;                     // CH: 边缘点0个数 | EN: Number of edge 0 points
	int    iEdge1PointNum;                     // CH: 边缘点1个数 | EN: Number of edge 1 points
	int    iCalipIdeaPointNum;                 // CH: 卡尺数量 | EN: Number of caliper
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo; // CH: 缺陷框信息 | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt0Info;  // CH: 边缘点0信息 | EN: Edge point 0 information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt1Info;  // CH: 边缘点1信息 | EN: Edge point 1 information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;  // CH: 卡尺信息 | EN: Caliper information
	IMVS_PF_STANDARD_LINEANDCIR_INFO stStandardLineAndCirInfo;    // CH: 输出标准直线以及标准圆信息 | EN: Standard output circle and line information
	IMVS_PF_DEFECT_COMPRE_INFO stDefectCompreInfo; // CH: 缺陷综合信息 | EN: Defect comprehensive information
	int    iReserved[4];                       // CH: 保留字段 | EN: Reserved
} IMVS_PF_EDGEPAIRINSPGROUP_MODU_INFO;

// CH: 模型缺陷框信息结构 | EN: Structure about information of model defect box
typedef struct IMVS_PF_MODEL_FLAWRECT_INFO__
{
	int    iCaliperStart;               // CH: 缺陷卡尺起始索引 | EN: Defect caliper start index
	int    iCaliperEnd;                 // CH: 缺陷卡尺终止索引 | EN: Defect caliper end index
	int    iDefectType;                 // CH: 缺陷类型 | EN: Type of defect
	float  fDefectSize;                 // CH: 缺陷尺寸 | EN: Size of defect
	float  fDefectArea;                 // CH: 缺陷面积 | EN: Area of defect
	float  fFlawLen;                    // CH: 缺陷长度 | EN: Length of defect
	IMVS_PF_RECT_INFO_F stFlawRect;     // CH: 缺陷框 | EN: Defect box
} IMVS_PF_MODEL_FLAWRECT_INFO;

// CH: 边缘模型卡尺信息结构 | EN: Structure about information of edge model caliper
typedef struct IMVS_PF_EDGEFLAW_CALIPER_INFO__
{
	IMVS_PF_2DPOINT_F   stCalipPoint;   // CH: 理想卡尺点 | EN: Ideal caliper point
	IMVS_PF_RECT_INFO_F stCaliperRect;  // CH: 卡尺框 | EN: Caliper box
} IMVS_PF_EDGEFLAW_CALIPER_INFO;

// CH: 边缘模型缺陷模块信息结构 | EN: Structure about information of edge model defect module
typedef struct IMVS_PF_EDGEFLAWINSP_MODU_INFO__
{
	int    iModuStatu;                             // CH: 模块状态 | EN: Module status
	int    iFlawNum;                               // CH: 缺陷个数 | EN: Number of defects
	int    iEdgePointNum;                          // CH: 边缘点个数 | EN: Number of edge points
	int    iCalipIdeaPointNum;                     // CH: 卡尺数量 | EN: Number of caliper
	IMVS_PF_MODEL_FLAWRECT_INFO * pstFlawRectInfo; // CH: 缺陷框信息 | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePtInfo;       // CH: 边缘点信息 | EN: Edge point information
	IMVS_PF_EDGEFLAW_CALIPER_INFO * pstCaliperInfo;// CH: 卡尺信息 | EN: Caliper information
	int    iReserved[4];                           // CH: 保留字段 | EN: Reserved
} IMVS_PF_EDGEFLAWINSP_MODU_INFO;

// CH: 边缘对模型卡尺信息结构 | EN: Structure about information of edge pair model caliper
typedef struct IMVS_PF_EDGEFLAW_PAIR_CALIPER_INFO__
{
	IMVS_PF_2DPOINT_F   stIdeaEdgePoint0;    // CH: 理想边缘点0 | EN: Ideal edge point 0
	IMVS_PF_2DPOINT_F   stIdeaEdgePoint1;    // CH: 理想边缘点1 | EN: Ideal edge point 1
	IMVS_PF_RECT_INFO_F stCaliperRect;       // CH: 卡尺框 | EN: Caliper box
} IMVS_PF_EDGEFLAW_PAIR_CALIPER_INFO;

// CH: 边缘对模型轨迹信息结构 | EN: Structure about information of edge pair model trajectory
typedef struct IMVS_PF_TRAJECTORY_INFO__
{
	int                 iCalTrajFlag;         // CH: 优化轨迹状态 | EN: Optimize track status
	IMVS_PF_2DPOINT_F   stIdeaTrajPoint;      // CH: 理想轨迹点 | EN: Ideal track point
	IMVS_PF_2DPOINT_F   stCalTrajPoint;       // CH: 优化轨迹点 | EN: Optimize track points
	IMVS_PF_RECT_INFO_F stIdeaTrajCaliper;    // CH: 理想轨迹卡尺框 | EN: Ideal track caliper box
} IMVS_PF_TRAJECTORY_INFO;

// CH: 边缘对模型缺陷模块信息结构 | EN: Structure about information of edge pair model defect module
typedef struct IMVS_PF_EDGEPAIRFLAWINSP_MODU_INFO__
{
	int    iModuStatu;                             // CH: 模块状态 | EN: Module status
	float  fMaxWidth;                              // CH: 最大宽度 | EN: Maximum width
	float  fMinWidth;                              // CH: 最小宽度 | EN: Minimum width
	float  fAvgWidth;                              // CH: 平均宽度 | EN: Average width
	int    iPairNum;                               // CH: 边缘对数量 | EN: Number of edge pairs
	int    iFlawNum;                               // CH: 缺陷个数 | EN: Number of defects
	int    iEdgePointNum;                          // CH: 边缘点个数 | EN: Number of edge points
	int    iCalipIdeaPointNum;                     // CH: 卡尺数量 | EN: Number of caliper
	int    iTrajectNum;                            // CH: 轨迹信息数量 | EN: Number of trajectory information
	float * pfEdgePairWidth;                       // CH: 边缘对宽度 | EN: Edge pair width
	IMVS_PF_MODEL_FLAWRECT_INFO * pstFlawRectInfo; // CH: 缺陷框信息 | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt0Info;      // CH: 边缘点0信息 | EN: Edge point 0 information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt1Info;      // CH: 边缘点1信息 | EN: Edge point 1 information
	IMVS_PF_EDGEFLAW_PAIR_CALIPER_INFO * pstCaliperInfo; // CH: 卡尺信息 | EN: Caliper information
	IMVS_PF_TRAJECTORY_INFO * pstTrajectInfo;      // CH: 轨迹信息 | EN: Trajectory information
	int    iReserved[4];                           // CH: 保留字段 | EN: Reserved
} IMVS_PF_EDGEPAIRFLAWINSP_MODU_INFO;

// CH: 缓存图像数据信息结构 | EN: Structure about information of cache images
typedef struct IMVS_PF_IMAGEBUFFERMODULE_INFO__
{
	int                iModuStatu;     // CH: 模块状态 | EN: Module status
	int                nImgNum;        // CH: 缓存图像数量 | EN: Number of cached images
	IMVS_PF_IMAGE_INFO stOutImgInfo[IMVS_PF_IMAGE_BUFFER_NUM];   // CH: 输出图像数据 | EN: Output images information
	int                iReserved[4];   // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGEBUFFERMODULE_INFO;

// CH: 灰度模型匹配基本信息结构 | EN: Structure about basic information of grayscale model matching
typedef struct IMVS_PF_GMATCH_BASE_INFO__
{
	int    iMatchTempNum;               // CH: 匹配模板编号 | EN: Number of match template
	int    iMatchStatu;                 // CH: 匹配状态 | EN: Match status
	char   strMatchModelName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 匹配模板名称 | EN： Name of match model
	IMVS_PF_REGION stMatchBox;          // CH: 匹配框 | EN: Match box
	IMVS_PF_MATCH_PT_INFO stMatchPt;    // CH: 匹配点 | EN: Match point
	IMVS_PF_REGION stDetectRegion;      // CH: 捡测区域 | EN: Detected region
	int    iReserved[4];                // CH: 保留字段 | EN: Reserved
}IMVS_PF_GMATCH_BASE_INFO;

// CH: 灰度模型匹配模块信息结构 | EN: Structure about information of grayscale model matching
typedef struct IMVS_PF_GRAYMATCH_MODU_INFO__
{
	int    iModuStatu;                  // CH: 模块状态 | EN: Module status
	int    iMatchNum;                   // CH: 匹配个数 | EN: Number of matches
	IMVS_PF_GMATCH_BASE_INFO * pstMatchBaseInfo; // CH: 特征匹配基本信息 | EN: basic information of grayscale model matching
	int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_GRAYMATCH_MODU_INFO;

// CH: 颜色识别模型样本信息结构 | EN: Structure about information of color recognition model sample
typedef struct IMVS_PF_COLORMODELSAMPLE_DATA_INFO__
{
	int     nNum;                       // CH: 模型或样本数量 | EN: Number of model or sample
	float * fData;                      // CH: 模型或样本数据 | EN: Data of model or sample
} IMVS_PF_COLORMODELSAMPLE_DATA_INFO;

// CH: 颜色识别结果信息结构 | EN: Structure about information of color recognition
typedef struct IMVS_PF_COLORRECOGNITION_RES_INFO__
{
	float   fColorScore;                                             // CH: 颜色识别分数 | EN: Color recognition score
	char    strColorTypeName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: 颜色识别类型名称 | EN: Type name of color recognition
} IMVS_PF_COLORRECOGNITION_RES_INFO;

// CH: 颜色识别模块信息结构 | EN: Structure about information of color recognition module
typedef struct IMVS_PF_COLORRECOGNITION_MODU_INFO__
{
	int    iModuStatu;                                         // CH: 模块状态 | EN: Module status
	float  fConfidence;                                        // CH: 置信度 | EN: Confidence
	float  fTopScore;                                          // CH: 最佳分数 | EN: Top score
	char   strTopTypeName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 最佳匹配名称 | EN: Top type name
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stModelHData;           // CH: 模型H通道数据 | EN: Model H channel data
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stModelSData;           // CH: 模型S通道数据 | EN: Model S channel data
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stModelIData;           // CH: 模型I通道数据 | EN: Model I channel data
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stSampleHData;          // CH: 样本H通道数据 | EN: Sample H channel data
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stSampleSData;          // CH: 样本S通道数据 | EN: Sample S channel data
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stSampleIData;          // CH: 样本I通道数据 | EN: Sample I channel data
	int    nColorDistResNum;                                   // CH: 颜色识别结果数量 | EN: Number of color recognition results
	IMVS_PF_COLORRECOGNITION_RES_INFO * pstColorDistResInfo;   // CH: 颜色识别结果 | EN: Color recognition results
	IMVS_PF_REGION stDetectRegion;                             // CH: 检测区域 | EN: Detected region
	int    iReserved[4];                                       // CH: 保留字段 | EN: Reserved
} IMVS_PF_COLORRECOGNITION_MODU_INFO;

// CH: 图像矫正模块信息结构 | EN: Structure about information of image correction
typedef struct IMVS_PF_IMAGECORRECTMANUAL_MODU_INFO__
{
	int    iModuStatu;                 // CH: 模块状态 | EN: Module status
	IMVS_PF_IMAGE_INFO stCorrectImg;   // CH: 输出图像 | EN: Output image
	int    iReserved[4];               // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMAGECORRECTMANUAL_MODU_INFO;

// CH: 相机IO通信模块信息结构 | EN: Structure about information of camera IO communication module
typedef struct IMVS_PF_CAMERAIOMODULE_INFO__
{
	int    iModuStatu;                                       // CH: 模块状态 | EN: Module status
	char   strResult[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: 结果字符串 | EN: Result string
	int    iReserved[4];                                     // CH: 保留字段 | EN: Reserved
} IMVS_PF_CAMERAIOMODULE_INFO;

// CH: 光源通道信息结构 | EN: Structure about information of light channel
typedef struct IMVS_PF_LIGHTCHANNEL_INFO__
{
	int    iEnable;                                          // CH: 使能 | EN: Enable
	int    iBrightness;                                      // CH: 亮度 | EN: Brightness
	int    iLightState;                                      // CH: 光源状态 | EN: Light state
	int    iEdgeType;                                        // CH: 沿定义 | EN: Edge type
	int    iDurationTime;                                    // CH: 持续时间 | EN: Duration time
} IMVS_PF_LIGHTCHANNEL_INFO;

// CH: 光源模块信息结构 | EN: Structure about information of light module
typedef struct IMVS_PF_LIGHTMODULE_INFO__
{
	int    iModuStatu;                                       // CH: 模块状态 | EN: Module status
	IMVS_PF_LIGHTCHANNEL_INFO stLightChannel1Info;           // CH: 通道1信息 | EN: Channel 1 information
	IMVS_PF_LIGHTCHANNEL_INFO stLightChannel2Info;           // CH: 通道2信息 | EN: Channel 2 information
	IMVS_PF_LIGHTCHANNEL_INFO stLightChannel3Info;           // CH: 通道3信息 | EN: Channel 3 information
	IMVS_PF_LIGHTCHANNEL_INFO stLightChannel4Info;           // CH: 通道4信息 | EN: Channel 4 information
	int    iReserved[4];                                     // CH: 保留字段 | EN: Reserved
} IMVS_PF_LIGHTMODULE_INFO;

// CH: 四边形查找模块信息结构 | EN: Structure about information of quadrangle find module
typedef struct IMVS_PF_QUADRANGEFIND_MODU_INFO__
{
	int    iModuStatu;                            // CH: 模块状态 | EN: Module status
	float  fFitDiff0;                             // CH: 边缘直线0拟合误差 | EN: The fit error of edge line 0
	float  fFitDiff1;                             // CH: 边缘直线1拟合误差 | EN: The fit error of edge line 1
	float  fFitDiff2;                             // CH: 边缘直线2拟合误差 | EN: The fit error of edge line 2
	float  fFitDiff3;                             // CH: 边缘直线3拟合误差 | EN: The fit error of edge line 3
	float  fAngle0;                               // CH: 夹角0 | EN: Angle 0
	float  fAngle1;                               // CH: 夹角1 | EN: Angle 1
	float  fAngle2;                               // CH: 夹角2 | EN: Angle 2
	float  fAngle3;                               // CH: 夹角3 | EN: Angle 3
	IMVS_PF_LINE_INFO stEdgeLine0;                // CH: 边缘直线0 | EN: Edge line 0
	IMVS_PF_LINE_INFO stEdgeLine1;                // CH: 边缘直线1 | EN: Edge line 1
	IMVS_PF_LINE_INFO stEdgeLine2;                // CH: 边缘直线2 | EN: Edge line 2
	IMVS_PF_LINE_INFO stEdgeLine3;                // CH: 边缘直线3 | EN: Edge line 3
	IMVS_PF_OUTLINE_PT stOutlinePts0;             // CH: 直线0轮廓点 | EN: The contour point of line 0
	IMVS_PF_OUTLINE_PT stOutlinePts1;             // CH: 直线1轮廓点 | EN: The contour point of line 1
	IMVS_PF_OUTLINE_PT stOutlinePts2;             // CH: 直线2轮廓点 | EN: The contour point of line 2
	IMVS_PF_OUTLINE_PT stOutlinePts3;             // CH: 直线3轮廓点 | EN: The contour point of line 3
	IMVS_PF_LINE_INFO  stDiagonalLine0;           // CH: 对角线0 | EN: Diagonal 0
	IMVS_PF_LINE_INFO  stDiagonalLine1;           // CH: 对角线1 | EN: Diagonal 1
	IMVS_PF_LINE_INFO  stMedianLine0;             // CH: 中线0 | EN: Midline 0
	IMVS_PF_LINE_INFO  stMedianLine1;             // CH: 中线1 | EN: Midline 1
	IMVS_PF_LINE_INFO  stAngleBisector0;          // CH: 四边形对边角平分线0 | EN: Diagonal split line 0
	IMVS_PF_LINE_INFO  stAngleBisector1;          // CH: 四边形对边角平分线1 | EN: Diagonal split line 1
	IMVS_PF_2DPOINT_F stVertexPoint0;             // CH: 顶点0 | EN: Vertex 0
	IMVS_PF_2DPOINT_F stVertexPoint1;             // CH: 顶点1 | EN: Vertex 1
	IMVS_PF_2DPOINT_F stVertexPoint2;             // CH: 顶点2 | EN: Vertex 2
	IMVS_PF_2DPOINT_F stVertexPoint3;             // CH: 顶点3 | EN: Vertex 3
	IMVS_PF_2DPOINT_F stDiagIntersectionPt;       // CH: 对角线交点 | EN: Diagonal intersection
	IMVS_PF_2DPOINT_F stMedianIntersectionPt;     // CH: 中点线交点 | EN: Midline intersection
	IMVS_PF_2DPOINT_F stCentralPoint;             // CH: 中心点 | EN: Center point
	IMVS_PF_2DPOINT_F stAngleBisectorIntersPoint; // CH: 对边角平分线交点 | EN: Diagonal split point
	IMVS_PF_REGION stDetectRegion0;               // CH: 检测区域0 | EN: ROI0
	IMVS_PF_REGION stDetectRegion1;               // CH: 检测区域1 | EN: ROI1
	IMVS_PF_REGION stDetectRegion2;               // CH: 检测区域2 | EN: ROI2
	IMVS_PF_REGION stDetectRegion3;               // CH: 检测区域3 | EN: ROI3
	int    iReserved[4];                          // CH: 保留字段 | EN: Reserved
} IMVS_PF_QUADRANGEFIND_MODU_INFO;

// CH: 直线查找组合模块 | EN: Structure about information of line find group module
typedef struct IMVS_PF_LINEFINDGROUP_MODU_INFO__
{
	int    iModuStatu;                        // CH: 模块状态 | EN: Module status
	int    iFitStatus;                        // CH: 拟合状态 | EN: Fit status
	float  fFitScore;                         // CH: 拟合误差 | EN: Fit score
	IMVS_PF_LINE_INFO stOutLine;              // CH: 输出直线 | EN: Output line
	int    iMatchNum;                         // CH: 匹配点数 | EN: Match number
	int    iFitPtNum;                         // CH: 拟合点数 | EN: Fit point number
	IMVS_PF_FIT_RES_INFO * pstLinefitResInfo; // CH: 线拟合结果 | EN: Line fit result
	int    iMinCirNum;                        // CH: 最小外接矩形数量 | EN: Number of minimum circumscribed rectangle
	IMVS_PF_RECT_INFO * pstMinCirRect;        // CH: 最小外接矩形 | EN: Minimum circumscribed rectangle
	int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_LINEFINDGROUP_MODU_INFO;

// CH: 多直线输出结果信息 | EN: Structure about information of multi-line output result
typedef struct IMVS_PF_MULTILINE_INFO__
{
	float fLineFitError;                      // CH: 线拟合误差 | EN: Line fit error
	float fLineIntensity;                     // CH: 线对比度强度 | EN: Line intensity
	float fCoverageScore;                     // CH: 覆盖率分数 | EN: Coverage score
	int   iInliersNum;                        // CH: 在群点数量 | EN: Group point number
	int   iLineIndex;                         // CH: 线段索引 | EN: Line index
	IMVS_PF_LINE_INFO stOutputLine;           // CH: 输出直线 | EN: Output line
} IMVS_PF_MULTILINE_INFO;

// CH: 边缘点信息 | EN: Structure about information of multi-line edge points
typedef struct IMVS_PF_MULTILINEEDGE_INFO__
{
	int   iEdgePolarity;                     // CH: 边缘极性 | EN: Edge polarity
	float fEdgeMagnitude;                    // CH: 梯度幅值 | EN: Edge magnitude
	float fEdgeOrientation;                  // CH: 梯度方向 | EN: Edge orientation
	float fEdgeDist;                         // CH: 边缘距离 | EN: Edge distance
	int   iEdgeStatus;                       // CH: 边缘状态 | EN: Edge status
	int   iEdgeCaliperIndex;                 // CH: 投影区域索引 | EN: The index of edge caliper
	int   iEdgeLineIndex;                    // CH: 所属线段索引 | EN: The index of edge line
	IMVS_PF_2DPOINT_F stContourPt;           // CH: 轮廓点 | EN: Contour point
} IMVS_PF_MULTILINEEDGE_INFO;

// CH: 多直线查找模块 | EN: Structure about information of multi-line find module
typedef struct IMVS_PF_MULTILINEFIND_MODU_INFO__
{
	int    iModuStatu;                        // CH: 模块状态 | EN: Module status
	int    iLineNum;                          // CH: 直线数量 | EN: The number of lines
	IMVS_PF_MULTILINE_INFO * pstOutLineInfo;  // CH: 输出直线 | EN: Output lines
	int    iEdgePointNum;                     // CH: 边缘点数量 | EN: The number of edge points
	IMVS_PF_MULTILINEEDGE_INFO * pstEdgeInfo; // CH: 边缘点信息 | EN: Multi-line edge information
	IMVS_PF_REGION stDetectRegion;            // CH: 检测区域 | EN: Detected region
	int    iCaliperDetectNum;                 // CH: 卡尺框检测区数量 | EN: Number of caliper detection areas
	IMVS_PF_REGION *   pstCaliperDetectRegion; // CH: 卡尺框检测区 | EN: Caliper detection areas
	int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_MULTILINEFIND_MODU_INFO;

// CH: 映射标定模块 | EN: Structure about information of mapping calibration module
typedef struct IMVS_PF_TWOIMGCALIB_MODU_INFO__
{
	int    iModuStatu;                       // CH: 模块状态 | EN: Module status
	float  fKx;                              // CH: 输出X方向比例 | EN: kx
	float  fKy;                              // CH: 输出Y方向比例 | EN: ky
	float  fMapError;                        // CH: 映射误差 | EN: Map error
	int    iImgCalibStatus1;                 // CH: 图像1标定状态 | EN: Image 1 calibration status
	int    iImgCalibStatus2;                 // CH: 图像2标定状态 | EN: Image 2 calibration status
	float  fPixelScale1;                     // CH: 单像素精度1 | EN: Single-pixel accuracy 1
	float  fPixelScale2;                     // CH: 单像素精度2 | EN: Single-pixel accuracy 2
	int    iCurCornersPointNum;              // CH: 当前角点数量 | EN: Number of current corner points
	int    iObjCornersPointNum;              // CH: 目标角点数量 | EN: Number of target corner points
	int    iProCornersPointNum;              // CH: 映射角点数量 | EN: Number of map corner points
	IMVS_PF_2DPOINT_F * pstCornersCurPoints; // CH: 当前角点 | EN: Current corner points
	IMVS_PF_2DPOINT_F * pstCornersObjPoints; // CH: 目标角点 | EN: Target corner points
	IMVS_PF_2DPOINT_F * pstCornersProPoints; // CH: 映射角点 | EN: Map corner points	
	IMVS_PF_REGION      stDetectRegion1;     // CH: 检测区域1 | EN: Detected region1
	IMVS_PF_REGION      stDetectRegion2;     // CH: 检测区域2 | EN: Detected region2
	int    iReserved[4];                     // CH: 保留字段 | EN: Reserved
} IMVS_PF_TWOIMGCALIB_MODU_INFO;

// CH: N图像标定模块 | EN: Structure about information of N-Image calibration module
typedef struct IMVS_PF_NIMAGECALIB_MODU_INFO__
{
	int    iModuStatu;                       // CH: 模块状态 | EN: Module status
	int    iCalibStatus;                     // CH: 标定状态 | EN: Calibration status
	int    iCalibErrStatus;                  // CH: 评估标定误差状态 | EN:Calibration Error Status
	int    iRotDirectState;                  // CH: 旋转方向 | EN: Rotate Direction
	int    iCornerPairsNum;                  // CH: 位置信息数量 | EN: Number of Corner Pairs Info
	int    iTransErrMaxPtsNum;               // CH: 像素最大误差对应点数 | EN: Number of Trans Error Max Points
	int    iRotErrMaxPtsNum;                 // CH: 像素最大误差对应点数 | EN: Number of Rotate Error Max Points
	int    iTransMotionErrPicIndex;          // CH: 最大误差所在图片索引 | EN: Index of the picture which has the max error
	int    iRotMotionErrPicIndex;            // CH: 最大误差所在图片索引 | EN: Index of the picture which has the max error
	int    iCurNum;                          // CH: 当前数量 | EN: Current number
	int    iTotalNum;                        // CH: 总数量 | EN: Total number
	float  fTransError;                      // CH: 平移估计像素误差 | EN: Translation estimation pixel error
	float  fTransWorldError;                 // CH: 平移真实像素误差 | EN: Translation world pixel error
	float  fRotError;                        // CH: 旋转估计像素误差 | EN: Rotation estimation pixel error
	float  fRotWorldError;                   // CH: 旋转真实像素误差 | EN: Rotation world pixel error
	float  fRotateAngleError;                // CH: 旋转角度误差 | EN: Rotate angle error
	float  fTransEstMax;                     // CH: 像素最大误差 | EN: Trans Max Error
	float  fTransErrWorldMax;                // CH: 真实最大误差 | EN: Trans World Max Error
	float  fRotErrMax;                       // CH: 像素最大误差 | EN: Rotate Max Error
	float  fRotErrWorldMax;                  // CH: 真实最大误差 | EN: Rotate World Max Error
	float  fTransMotionErrAvgTrans;          // CH: 平移过程中图像移动量与机够移动量之间的偏差(距离误差) | EN: Trans Motion Error Average Trans
	float  fTransMotionErrAvgScale;          // CH: 平移过程中的图像尺度变化 | EN: Trans Motion Error Average Scale
	float  fTransMotionErrAvgRotate;         // CH: 平移过程中的图像之间旋转变化量 | EN: Trans Motion Error Average Rotation
	float  fTransMotionErrMaxTrans;          // CH: 平移过程中图像移动量与机够移动量之间的偏差(距离误差) | EN: Trans Motion Error Max Trans
	float  fTransMotionErrMaxScale;          // CH: 平移过程中的图像尺度变化 | EN: Trans Motion Error Max Scale
	float  fTransMotionErrMaxRotate;         // CH: 平移过程中的图像之间旋转变化量 | EN: Trans Motion Error Max Rotation
	float  fRotMotionErrAvg;                 // CH: 平均误差 | EN: Rotate Motion Average Error
	float  fRotMotionErrMax;                 // CH: 最大误差 | EN: Rotate Motion Max Error
	float  fMoveDirec;                       // CH: y方向和x方向移动比 | EN: Move Ratio of Y Direction and X Direction
	IMVS_PF_2DPOINT_F stDirXVectorPoint;     // CH: 机构坐标系x方向向量 | EN: X Vector of coordinate system
	IMVS_PF_2DPOINT_F stDirYVectorPoint;     // CH: 机构坐标系y方向向量 | EN: Y Vector of coordinate system
	IMVS_PF_2DPOINT_F stRotateCenterPoint;   // CH: 旋转中心坐标 | EN: Rotate center point coordinate
	IMVS_PF_2DPOINT_F stTransDirectError;    // CH: 平移方向误差 | EN: Rotate direction error
	IMVS_PF_2DPOINT_F * pOutImagePoint;      // CH: 轨迹点 | EN: Points of corner pairs
	IMVS_PF_REGION stDetectRegion;           // CH: 检测区域 | EN: Detected region
	int    iReserved[4];                     // CH: 保留字段 | EN: Reserved
} IMVS_PF_NIMAGECALIB_MODU_INFO;

// CH: 图像拼接模块 | EN: Structure about information of image stitching module
typedef struct IMVS_PF_IMGSTITCH_MODU_INFO__
{
	int    iModuStatu;                       // CH: 模块状态 | EN: Module status
	int    iCurNum;                          // CH: 当前数量 | EN: Current number
	int    iTotalNum;                        // CH: 总数量 | EN: Total number
	IMVS_PF_RECT_INFO * pstMinCirRect;       // CH: 最小外接矩形 | EN: Minimum circumscribed rectangle
	IMVS_PF_IMAGE_INFO stBinaryImgInfo;      // CH: 二值化图像数据 | EN: Binary image data
	int    iReserved[4];                     // CH: 保留字段 | EN: Reserved
} IMVS_PF_IMGSTITCH_MODU_INFO;

// CH: 几何变换模块 | EN: Structure about information of geometric transform module
typedef struct IMVS_PF_GEOMETRICTRANSFORM_MODU_INFO__
{
	int    iModuStatu;                       // CH: 模块状态 | EN: Module status
	IMVS_PF_IMAGE_INFO stOutputImgInfo;      // CH: 输出图像数据 | EN: Output image data
	int    iReserved[4];                     // CH: 保留字段 | EN: Reserved
} IMVS_PF_GEOMETRICTRANSFORM_MODU_INFO;

// CH: 数据集合模块信息结构 | EN: Structure about information of data set module
typedef struct IMVS_PF_DATASET_MODU_INFO__
{
	int    iModuStatu;                          // CH: 模块状态 | EN: Module status
	int    nResultNum;                          // CH: 结果数量 | EN: Number of results
	IMVS_PF_OUTPUT_RESULT_INFO * pstOutResInfo; // CH: 数据集合结果 | EN: Data set module result
	int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_DATASET_MODU_INFO;

// CH: 协议组装模块信息结构 | EN: Structure about information of protocol assemble module
typedef struct IMVS_PF_PROTOCOL_ASSEMBLE_MODU_INFO__
{
	int    iModuStatu;                       // CH: 模块状态 | EN: Module status
	char   strAssembleResult[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 组装结果 | EN: Assemble result
	char   strBinaryResult[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];   // CH: 二进制数据 | EN: Binary result
	int    iReserved[4];                     // CH: 保留字段 | EN: Reserved
} IMVS_PF_PROTOCOL_ASSEMBLE_MODU_INFO;

// CH: 协议解析模块信息结构 | EN: Structure about information of protocol analysis module
typedef struct IMVS_PF_PROTOCOL_ANALYSIS_MODU_INFO__
{
	int    iModuStatu;                          // CH: 模块状态 | EN: Module status
	int    nResultNum;                          // CH: 结果数量 | EN: Number of results
	IMVS_PF_OUTPUT_RESULT_INFO * pstOutResInfo; // CH: 协议解析结果 | EN: Protocol analysis result
	int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_PROTOCOL_ANALYSIS_MODU_INFO;

// CH: Group结果信息结构 | EN: Structure about information of group module result
typedef struct IMVS_PF_GROUP_RESULT_INFO__
{
	char            strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH];    // CH: 结果名称 | EN: Result name
	int             nParamType;                                           // CH: 结果类型:1整型 2浮点型 3字符串型 | EN: Result type: 1-integer, 2-float, 3-string
	int             nValueNum;                                            // CH: 模块值个数 | EN: Number of module values
	int *           pIntValue;                                            // CH: 整型数据 | EN: Integer data
	float *         pFloatValue;                                          // CH: 浮点型数据 | EN: Float data
	IMVS_PF_MODULE_STRING_VALUE * pstStringValue;                         // CH: 字符串型数据 | EN: String data
	IMVS_PF_MODULE_IMAGE_VALUE *  pstImageValue;                          // CH: 图像类型数据 | EN: Image data
	IMVS_PF_MODULE_CHUNK_VALUE *  pstChunkValue;                          // CH: 大数据 | EN: Big data
} IMVS_PF_GROUP_RESULT_INFO;

// CH: Group模块信息结构 | EN: Structure about information of group module
typedef struct IMVS_PF_GROUP_MODU_INFO__
{
	int    iModuStatu;                          // CH: 模块状态 | EN: Module status
	int    nResultNum;                          // CH: 结果数量 | EN: Number of results
	IMVS_PF_GROUP_RESULT_INFO * pstGroupResInfo;// CH: Group模块结果 | EN: Group module result
	int    iReserved[4];                        // CH: 保留字段 | EN: Reserved
} IMVS_PF_GROUP_MODU_INFO;

// CH: 图形定位匹配点信息结构 | EN: Structure about information of graphic positioning matching point
typedef struct IMVS_PF_MARKMATCH_PT_INFO__
{
	float    fScore;              // CH: 匹配点分数 | EN: Matching point score
	float    fScaleX;             // CH: 尺度X | EN: Scale X
	float    fScaleY;             // CH: 尺度Y | EN: Scale Y
	IMVS_PF_2DPOINT_F stMatchPt;  // CH: 匹配点 | EN: Matching point
} IMVS_PF_MARKMATCH_PT_INFO;

// CH: 图形定位基本信息结构 | EN: Structure about basic information of graphic positioning
typedef struct IMVS_PF_MARKMATCH_BASE_INFO__
{
	int    iMatchStatu;                  // CH: 匹配状态 | EN: Matching status
	IMVS_PF_REGION stMatchBox;           // CH: 匹配框 | EN: Matching box
	IMVS_PF_MARKMATCH_PT_INFO stMatchPt; // CH: 匹配点 | EN: Matching point
	int    iReserved[4];                 // CH: 保留字段 | EN: Reserved
}IMVS_PF_MARKMATCH_BASE_INFO;

// CH: 输出直线信息结构 | EN: Structure about basic information of output line
typedef struct IMVS_PF_FIND_LINE_INFO__
{
	int    iLineStatus;                  // CH: 匹配状态 | EN: Matching status
	IMVS_PF_LINE_INFO stFindLineInfo;    // CH: 输出直线信息 | EN: Output line information
}IMVS_PF_FIND_LINE_INFO;

// CH: 图形定位模块信息结构 | EN: Structure about information of graphic positioning module
typedef struct IMVS_PF_MARKFIND_MODU_INFO__
{
	int    iModuStatu;                  // CH: 模块状态 | EN: Module status
	IMVS_PF_MATCH_INFO stMatchConInfo;  // CH: 匹配轮廓信息 | EN: Matching contour information
	int    iMatchNum;                   // CH: 匹配个数 | EN: The number of matched items
	IMVS_PF_MARKMATCH_BASE_INFO * pstMatchBaseInfo; // CH: 图形定位匹配基本信息 | EN: Basic information of graphic positioning 
	IMVS_PF_FIND_LINE_INFO stFindLine0; // CH: 输出直线0 | EN: Output line 0
	IMVS_PF_FIND_LINE_INFO stFindLine1; // CH: 输出直线1 | EN: Output line 1
	IMVS_PF_FIND_LINE_INFO stFindLine2; // CH: 输出直线2 | EN: Output line 2
	IMVS_PF_FIND_LINE_INFO stFindLine3; // CH: 输出直线3 | EN: Output line 3
	IMVS_PF_REGION stDetectRegion;      // CH: 捡测区域 | EN: Detection region
	int    iReserved[4];                // CH: 保留字段 | EN: Reserved
} IMVS_PF_MARKFIND_MODU_INFO;

// CH: 单个Blob标签基本信息结构 | EN: Single blob label information structure
typedef struct IMVS_PF_SINGLEBLOBLABEL_INFO__
{
	int    iMonoStatu;                        // CH: 单体状态 | EN: Monomer status
	float  fArea;                             // CH: 面积 | EN: Area of the blob
	IMVS_PF_2DPOINT_F    stCentroidPt;        // CH: 质心点 | EN: Centroid point coordinates
	IMVS_PF_CONNECT_DOMAINS_INFO stConnectDomain; // CH: 连通域信息 | EN: Connected domain information
	int    iLabelValue;                       // CH: 标签值 | EN: Label value
	char   strCateLabel[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 类别标签 | EN: Category label
	int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
}IMVS_PF_SINGLEBLOBLABEL_INFO;

// CH: Blob标签分析模块信息结构 | EN: BLOB(Binary Large Object) labels analysis module information structure
typedef struct IMVS_PF_BLOBFINDLABELS_MODU_INFO__
{
	int    iModuStatu;                        // CH: 模块状态 | EN: Module status
	float  fTotalArea;                        // CH: 总面积 | EN: Total area of the blob
	int    iDetectNum;                        // CH: 检测区域个数 | EN: Number of detected region
	IMVS_PF_REGION *  pstDetectRegion;        // CH: 检测区域 | EN: Detected region
	IMVS_PF_BLOBOUTLINE_PT  stBlobOutlinePt;  // CH: Blob轮廓信息 | EN: Blob contour information
	IMVS_PF_IMAGE_INFO stBinaImage;           // CH: 二值化图像 | EN: Binary image
	IMVS_PF_IMAGE_INFO stBlobImage;           // CH: Blob图像 | EN: Blob image
	int    iBlobNum;                          // CH: BLOB个数 | EN: The number of blobs
	IMVS_PF_SINGLEBLOBLABEL_INFO * pstSingleBlobInfo; // CH: BLOB信息 | EN: Blob information
	int    iAnnulusNum;                       // CH: ROI圆弧个数 | EN: Number of ROI arcs
	IMVS_PF_ANNULUS_CIRCLE_INFO * pstAnnulusCirInfo; // CH: ROI圆弧信息 | EN: ROI arc information
	int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_BLOBFINDLABELS_MODU_INFO;

// CH: 胶点信息结构 | EN: Structure about information of glue points
typedef struct IMVS_PF_GLUEPOINT_INFO__
{
	int    iGluePtStatus;               // CH: 胶点状态 | EN: Glue point status
	IMVS_PF_2DPOINT_F stCalipPoint;     // CH: 胶点 | EN: Dots
} IMVS_PF_GLUEPOINT_INFO;

// CH: 路径提取模块信息结构 | EN: Structure about information of glue path extraction module
typedef struct IMVS_PF_GLUEPATHCONDUCT_MODU_INFO__
{
	int    iModuStatu;                        // CH: 模块状态 | EN: Module status
	int    iGluePointNum;                     // CH: 胶点个数 | EN: The number of dots
	IMVS_PF_GLUEPOINT_INFO * pstGluePoints;   // CH: 胶点信息 | EN: Dots information
	int    iReserved[4];                      // CH: 保留字段 | EN: Reserved
} IMVS_PF_GLUEPATHCONDUCT_MODU_INFO;

// CH: 深度学习读码结果信息结构 | EN: Deep learning code recognition details structure
typedef struct IMVS_PF_CNNCODERECG_RES_INFO__
{
	int    iCodeStatu;               // CH: 码状态 | EN: Code status
	float  fPPM;                     // CH: PPM | EN: PPM
	char   strCodeInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 编码信息 | EN: Encoding information
	int    iEstVersion;              // CH: 评估版本 | EN: Evaluation version
	int    iCodeType;                // CH: 码类型 | EN: Code type
	float  fCodePosAngle;            // CH: 码角度 | EN: Code angle
	IMVS_PF_RECT_INFO stRect;        // CH: 矩形框 | EN: Information of the code rectangle
	IMVS_PF_2DPOINT_I stCodePos0;    // CH: 码角点0 | EN: Code corner point 0
	IMVS_PF_2DPOINT_I stCodePos1;    // CH: 码角点1 | EN: Code corner point 1
	IMVS_PF_2DPOINT_I stCodePos2;    // CH: 码角点2 | EN: Code corner point 2
	IMVS_PF_2DPOINT_I stCodePos3;    // CH: 码角点3 | EN: Code corner point 3
	int    iReserved[4];             // CH: 保留字段 | EN: Reserved
}IMVS_PF_CNNCODERECG_RES_INFO;

// CH: 码等级结果信息 | EN: information of code grade module
typedef struct IMVS_PF_CNNCODEGRADE_RES_INFO__
{
	int iSymbolContrast;            // CH: 符号对比度 | EN: Symbolic contrast
	int iAxial;                     // CH: 轴向不均匀性 | EN: Axial unevenness
	int iGrid;                      // CH: 网格不均匀性 | EN: Mesh unevenness
	int iModulation;                // CH: 模块均匀性 | EN: Module uniformity
	int iFixedPatternDamage;        // CH: 固定程度 | EN: The degree of fixation
	int iUnusedErrorCorrection;     // CH: 未使用纠错 | EN: Error correction is not used
	int iPrintGrowthHor;            // CH: 水平打印伸缩 | EN: Horizontal print scaling
	int iPrintGrowthVer;            // CH: 垂直打印伸缩 | EN: Vertical print scaling
	int iRmGrade;                   // CH: 反射率余量 | EN: Reflectivity balance
	int iDecode;                    // CH: 译码评分 | EN: Decoding score
	int iOverQuality;               // CH: 总质量等级 | EN: Total quality grade
	int iEdgeDetermination;
	int iMinReflectance;
	int iMinEdgeContrast;
	int iDecodability;
	int iDefects;
	int iQuietZone;
	float fScScore;                 // CH: 符号对比度分数 | EN: Score of symbolic contrast
	float fAnScore;                 // CH: 码轴规整性分数 | EN: Score of code shaft regulation
	float fGnScore;                 // CH: 网格均匀性分数 | EN: Score of mesh unevenness
	float fModScore;                // CH: 模块均匀性分数 | EN: Score of module uniformity
	float fFpdScore;                // CH: 固定程度分数 | EN: Score of fixation degree
	float fUecScore;                // CH: 未使用纠错分数 | EN: Score of unused error correction
	float fPghScore;                // CH: 水平打印伸缩分数 | EN: Score of horizontal print scaling
	float fPgvScore;                // CH: 垂直打印伸缩分数 | EN: Score of vertical print scaling
	float fRmScore;                 // CH: 反射率余量分数 | EN: Score of reflectivity balance
	float fEdgeScore;
	float fMinrScore;
	float fMineScore;
	float fDcdScore;
	float fDefScore;
	float fQzScore;
} IMVS_PF_CNNCODEGRADE_RES_INFO;

// CH: 深度学习读码模块信息结构 | EN: Structure about information of deep learning code recognition module
typedef struct IMVS_PF_CNNCODERECG_MODU_INFO__
{
	int    iModuStatu;               // CH: 模块状态 | EN: Module status
	IMVS_PF_REGION stDetectRegion;   // CH: 检测区域 | EN: Detected region
	int    iCodeNum;                 // CH: 码个数 | EN: The number of codes
	IMVS_PF_CNNCODERECG_RES_INFO * pstCNNCRInfo; // CH: 码结果信息 | EN: Code information
	int    iGradeNum;                // CH: 码等级数量 | EN: Number of code levels
	IMVS_PF_CNNCODEGRADE_RES_INFO * pstCNNGradeResInfo; // CH: 码等级信息 | EN: Code level information
	int    iReserved[4];             // CH: 保留字段 | EN: Reserved
} IMVS_PF_CNNCODERECG_MODU_INFO;

// CH: 深度学习图像检索结果信息结构 | EN: Deep learning image retrieval results structure
typedef struct IMVS_PF_CNNRETRIEVAL_RES_INFO__
{
	int    iImageIndex;               // CH: 图像索引号 | EN: Image index number
	float  fSimilarity;               // CH: 相似度 | EN: Similarity
	char   strClassLabel[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 类别标签 | EN: Category label
}IMVS_PF_CNNRETRIEVAL_RES_INFO;

// CH: 深度学习图像检索模块信息结构 | EN: Structure about information of deep learning image retrieval module
typedef struct IMVS_PF_CNNRETRIEVAL_MODU_INFO__
{
	int    iModuStatu;               // CH: 模块状态 | EN: Module status
	int    iClassNum;                // CH: 类别数量 | EN: The number of class
	IMVS_PF_REGION stDetectRegion;   // CH: 检测区域 | EN: Detected region
	int    iTopNum;                  // CH: 结果数量 | EN: The number of results
	IMVS_PF_CNNRETRIEVAL_RES_INFO * pstCNNRetrievalInfo; // CH: 图像检索结果信息 | EN: Image retrieval results information
	int    iReserved[4];             // CH: 保留字段 | EN: Reserved
} IMVS_PF_CNNRETRIEVAL_MODU_INFO;

// CH: 二维码等级结果信息 | EN: information of QR code grade module
typedef struct IMVS_PF_2DGRADE_RES_INFO__
{
	int iSymbolContrast;            // CH: 符号对比度 | EN: Symbolic contrast
	int iAxial;                     // CH: 轴向不均匀性 | EN: Axial unevenness
	int iGrid;                      // CH: 网格不均匀性 | EN: Mesh unevenness
	int iModulation;                // CH: 模块均匀性 | EN: Module uniformity
	int iFixedPatternDamage;        // CH: 固定程度 | EN: The degree of fixation
	int iUnusedErrorCorrection;     // CH: 未使用纠错 | EN: Error correction is not used
	int iPrintGrowthHor;            // CH: 水平打印伸缩 | EN: Horizontal print scaling
	int iPrintGrowthVer;            // CH: 垂直打印伸缩 | EN: Vertical print scaling
	int iRmGrade;                   // CH: 反射率余量 | EN: Reflectivity balance
	int iDecode;                    // CH: 译码评分 | EN: Decoding score
	int iOverQuality;               // CH: 总质量等级 | EN: Total quality grade
	float fScScore;                 // CH: 符号对比度分数 | EN: Score of symbolic contrast
	float fAnScore;                 // CH: 码轴规整性分数 | EN: Score of code shaft regulation
	float fGnScore;                 // CH: 网格均匀性分数 | EN: Score of mesh unevenness
	float fModScore;                // CH: 模块均匀性分数 | EN: Score of module uniformity
	float fFpdScore;                // CH: 固定程度分数 | EN: Score of fixation degree
	float fUecScore;                // CH: 未使用纠错分数 | EN: Score of unused error correction
	float fPghScore;                // CH: 水平打印伸缩分数 | EN: Score of horizontal print scaling
	float fPgvScore;                // CH: 垂直打印伸缩分数 | EN: Score of vertical print scaling
	float fRmScore;                 // CH: 反射率余量分数 | EN: Score of reflectivity balance
	char strCodeInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: 编码信息 | EN: Encoding information
	IMVS_PF_REGION stDetectRegion;  // CH: 检测区域 | EN: Detected region
} IMVS_PF_2DGRADE_RES_INFO;

// CH: 二维码等级模块信息结构 | EN: Structure about information of QR code grade module
typedef struct IMVS_PF_2DGRADE_MODU_INFO__
{
	int    iModuStatu;               // CH: 模块状态 | EN: Module status
	int    iCodeNum;                 // CH: 二维码数量 | EN: The number of codes
	IMVS_PF_2DGRADE_RES_INFO * pst2DGradeResult;    // CH: 二维码等级结果信息 | EN: QR code level result information
	int    iReserved[4];             // CH: 保留字段 | EN: Reserved
} IMVS_PF_2DGRADE_MODU_INFO;

// CH: 缺陷对比模块信息结构 | EN: Structure about information of inspect module
typedef struct IMVS_PF_INSPECT_MODU_INFO__
{
	int iModuStatus;              // CH: 模块状态 | EN: Module status
	int * iInspectStatus;           // CH: 缺陷状态 | EN: Inspect status
	int iDetectRoiNum;            // CH: 检测ROI个数 | EN: The number of detect area
	int iMatchStatus;             // CH: 匹配状态 | EN: Match Status
	float * fInspectScore;          // CH: 缺陷分数 | EN: Inspect Score
	IMVS_PF_REGION * stMatchBox;    // CH: 匹配框 | EN: Matching box
	IMVS_PF_REGION * stDetectBox;    // CH: 检测区 | EN: Detect box
	int    iReserved[4];             // CH: 保留字段 | EN: Reserved
}IMVS_PF_INSPECT_MODU_INFO;

typedef struct IMVS_PF_MULTIFUSION_MODU_INFO__
{
	int iModuStatus;                      // CH: 模块状态 | EN: Module status
	int iImageNum;                        // CH: 图片个数 | EN: Image Number
	int iImageWidth;                      // CH: 图像宽度 | EN: Image Width
	int iImageHeight;                     // CH: 图像高度 | EN: Image Height
	IMVS_PF_IMAGE_INFO stAlbedoImage;     // CH: 反射图像 | EN: Albedo Image
	IMVS_PF_IMAGE_INFO stShadingImage;    // CH: 阴影图像 | EN: Shading Image
	IMVS_PF_REGION stDetectBox;           // CH: 检测区 | EN: Detect box
	int    iReserved[4];                  // CH: 保留字段 | EN: Reserved
}IMVS_PF_MULTIFUSION_MODU_INFO;

typedef struct IMVS_PF_IMAGEAQUISITION_MODU_INFO__
{
	int iImageCount;                      // CH: 图像个数 | EN: Image Count
	IMVS_PF_IMAGE_INFO stImage0;          // CH: 图像0信息 | EN：Information of Image0
	float fImage0Distribution;            // CH: 图像0分布角 | EN：Distribution of Image0
	float fImage0Irradiation;             // CH: 图像0照射角 | EN: Irradiation of Image0
	IMVS_PF_IMAGE_INFO stImage1;          // CH: 图像1信息 | EN：Information of Image1
	float fImage1Distribution;            // CH: 图像1分布角 | EN：Distribution of Image1
	float fImage1Irradiation;             // CH: 图像1照射角 | EN: Irradiation of Image1
	IMVS_PF_IMAGE_INFO stImage2;          // CH: 图像2信息 | EN：Information of Image2
	float fImage2Distribution;            // CH: 图像2分布角 | EN：Distribution of Image2
	float fImage2Irradiation;             // CH: 图像2照射角 | EN: Irradiation of Image2
	IMVS_PF_IMAGE_INFO stImage3;          // CH: 图像3信息 | EN：Information of Image3
	float fImage3Distribution;            // CH: 图像3分布角 | EN：Distribution of Image3
	float fImage3Irradiation;             // CH: 图像3照射角 | EN: Irradiation of Image3
	IMVS_PF_IMAGE_INFO stImage4;          // CH: 图像4信息 | EN：Information of Image4
	float fImage4Distribution;            // CH: 图像4分布角 | EN：Distribution of Image4
	float fImage4Irradiation;             // CH: 图像4照射角 | EN: Irradiation of Image4
	IMVS_PF_IMAGE_INFO stImage5;          // CH: 图像5信息 | EN：Information of Image5
	float fImage5Distribution;            // CH: 图像5分布角 | EN：Distribution of Image5
	float fImage5Irradiation;             // CH: 图像5照射角 | EN: Irradiation of Image5
	IMVS_PF_IMAGE_INFO stImage6;          // CH: 图像6信息 | EN：Information of Image6
	float fImage6Distribution;            // CH: 图像6分布角 | EN：Distribution of Image6
	float fImage6Irradiation;             // CH: 图像6照射角 | EN: Irradiation of Image6
	IMVS_PF_IMAGE_INFO stImage7;          // CH: 图像7信息 | EN：Information of Image7
	float fImage7Distribution;            // CH: 图像7分布角 | EN：Distribution of Image7
	float fImage7Irradiation;             // CH: 图像7照射角 | EN: Irradiation of Image7
	int iFrameNum;                        // CH: 帧号 | EN: Frame Number
	int iLostFrameCount;                  // CH: 丢帧数 | EN: Number of lost frames
	int iLostPacketCount;                 // CH: 丢包数 | EN: Number of lost packet
	int iGetCameraFailCount;              // CH: 相机获取失败次数 | EN: Number of get camera fail
	int    iReserved[4];                  // CH: 保留字段 | EN: Reserved
}IMVS_PF_IMAGEAQUISITION_MODU_INFO;

typedef struct IMVS_PF_CNNINSPECT_MODU_INFO__
{
	int iModuStatus;                      // CH: 模块状态 | EN: Module status
	IMVS_PF_IMAGE_INFO stResidualImage;   // CH: 图像信息 | EN：Information of Image
	IMVS_PF_REGION stDetectBox;           // CH: 检测区 | EN: Detect box
	int    iReserved[4];                  // CH: 保留字段 | EN: Reserved
}IMVS_PF_CNNINSPECT_MODU_INFO;

// CH: 模块结构体数据信息结构 | EN: Structure about information of module results
typedef struct IMVS_PF_MODU_RES_INFO__
{
	unsigned int    nStatus;                                                // CH: 整个模块的状态 1成功，其他值，异常 | EN: 1-succeeded, other values-error code
	unsigned int    nErrorCode;                                             // CH: 模块异常时底层返回的错误码 | EN: Error code returned when the module is abnormal
    unsigned int    nProcessID;                                             // CH: 流程ID | EN: Process ID
    unsigned int    nModuleID;                                              // CH: 模块ID | EN: Module ID
    float           fModuleTime;                                            // CH: 模块时间, 从输入数据全部到达开始计算，从将所有数据发送出去结束计算 | EN: Module time
    float           fAlgorithmTime;                                         // CH: 算法时间 | EN: Algorithm time
    unsigned int    nInCycle;                                               // CH: 是否为循环内模块 | EN: Whether it is the module in the loop
	char            strDisplayName[IMVS_PF_MAX_MODULE_DISPLAY_NAME_LENGTH]; // CH: 界面显示名称 | EN: Displayed module name
    char            strModuleName[IMVS_PF_MAX_MODULE_NAME_LENGTH];          // CH: 模块名称 | EN: Module name
    void *          pData;                                                  // CH: 模块结果数据 | EN: Module result details
    unsigned int    nLen;                                                   // CH: 模块结果数据长度 | EN: Length of module result data
    char *          pReserved[8];                                           // CH: 保留字段 | EN: Reserved
    unsigned int    nReserved[31];                                          // CH: 保留字段 | EN: Reserved
} IMVS_PF_MODU_RES_INFO;

#define g_strTcpPortConfig "TcpPortConfig.cfg"


#endif // IMVS_6000_PLATFORMSDK_DEFINE_H__
