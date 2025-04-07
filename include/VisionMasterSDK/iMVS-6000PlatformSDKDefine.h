/***************************************************************************************************
 *
 * ��Ȩ��Ϣ����Ȩ���� (c) 2020, ��������Ȩ��
 *
 * �ļ����ƣ�iMVS-6000PlatformSDKDefine.h
 * ժ    Ҫ�����ο���SDK�ӿں궨��
 *
 * ��    �ߣ��Ӿ�ƽ̨��
 * ��    �ڣ�2020-01-17 11:09:05
 * ��    ע���½�

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
 * ϵͳ�궨��
 * System macro definition
 *************************************************************************/

// CH: ���������ʾ | EN: Input definition
#ifndef IN
#define IN
#endif

// CH: ���������ʾ | EN: Output definition
#ifndef OUT
#define OUT
#endif

// CH: �������������ʾ | EN: Input and output definition
#ifndef INOUT
#define INOUT
#endif

// CH: �����ָ�� | EN: Empty pointer definition
#ifndef IMVS_NULL
#ifdef __cplusplus
#define IMVS_NULL    0
#else
#define IMVS_NULL    ((void *)0)
#endif
#endif

// CH: ģ�����ƺ궨�� | EN: Module names' macro definition
#define MODU_NAME_LOCALIMAGEVIEW       "LocalImageView"            // CH: ����ͼ��ģ�� | EN: Local image module
#define MODU_NAME_CAMERAMODULE         "CameraModule"              // CH: ���ͼ��ģ�� | EN: Camera module
#define MODU_NAME_SAVEIMAGE            "SaveImage"                 // CH: ���ͼ��ģ�� | EN: Output image module
#define MODU_NAME_HPFEATUREMATCHMODU   "IMVSHPFeatureMatchModu"    // CH: �߾�������ƥ��ģ�� | EN: Feature high-precising matching module
#define MODU_NAME_FASTFEATUREMATCHMODU "IMVSFastFeatureMatchModu"  // CH: ��������ƥ��ģ�� | EN: Feature fast matching module
#define MODU_NAME_CIRCLEFINDMODU       "IMVSCircleFindModu"        // CH: Բ����ģ�� | EN: Circle search module
#define MODU_NAME_LINEFINDMODU         "IMVSLineFindModu"          // CH: ֱ�߲���ģ�� | EN: Line search module
#define MODU_NAME_BLOBFINDMODU         "IMVSBlobFindModu"          // CH: Blob����ģ�� | EN: BLOB (Binary Large Object) analysis module
#define MODU_NAME_CALIPERMODU          "IMVSCaliperModu"           // CH: ���߹���ģ�� | EN: Caliper tool module
#define MODU_NAME_CALIPEREDGEMODU      "IMVSCaliperEdgeModu"       // CH: ��Ե����ģ�� | EN: Edge search module
#define MODU_NAME_EDGEWIDTHFINDMODU    "IMVSEdgeWidthFindModu"     // CH: �����ģ�� | EN: Interval detection module
#define MODU_NAME_FIXTUREMODU          "IMVSFixtureModu"           // CH: λ������ģ�� | EN: Position correction module
#define MODU_NAME_RECTFINDMODU         "IMVSRectFindModu"          // CH: ���μ��ģ�� | EN: Rectangle detection module
#define MODU_NAME_PEAKFINDMODU         "IMVSPeakFindModu"          // CH: ������ģ�� | EN: Vertex detection module
#define MODU_NAME_CALIPERCORNERMODU    "IMVSCaliperCornerModu"     // CH: ��Ե����ģ�� | EN: Edge intersection search module
#define MODU_NAME_PAIRLINEMODU         "IMVSPairLineModu"          // CH: ƽ���߲���ģ�� | EN: Parallel line search module
#define MODU_NAME_L2CMEASUREMODU       "IMVSL2CMeasureModu"        // CH: ��Բ����ģ�� | EN: Line and circle distance measurement module
#define MODU_NAME_C2CMEASUREMODU       "IMVSC2CMeasureModu"        // CH: ԲԲ����ģ�� | EN: Circle and circle distance measurement module
#define MODU_NAME_P2CMEASUREMODU       "IMVSP2CMeasureModu"        // CH: ��Բ����ģ�� | EN: Point and circle distance measurement module
#define MODU_NAME_P2LMEASUREMODU       "IMVSP2LMeasureModu"        // CH: ���߲���ģ�� | EN: Point and line distance measurement module
#define MODU_NAME_L2LMEASUREMODU       "IMVSL2LMeasureModu"        // CH: ���߲���ģ�� | EN: Line and line distance measurement module
#define MODU_NAME_P2PMEASUREMODU       "IMVSP2PMeasureModu"        // CH: ������ģ�� | EN: Point and point distance measurement module
#define MODU_NAME_CIRCLEFITMODU        "IMVSCircleFitModu"         // CH: Բ���ģ�� | EN: Circle fitting module
#define MODU_NAME_LINEFITMODU          "IMVSLineFitModu"           // CH: ֱ�����ģ�� | EN: Line fitting module
#define MODU_NAME_INTENSITYMEASUREMODU "IMVSIntensityMeasureModu"  // CH: ���Ȳ���ģ�� | EN: Brightness detection module
#define MODU_NAME_PIXELCOUNTMODU       "IMVSPixelCountModu"        // CH: ����ͳ��ģ�� | EN: Pixel statistics module
#define MODU_NAME_HISTTOOLMODU         "IMVSHistToolModu"          // CH: ֱ��ͼ����ģ�� | EN: Histogram tool module
#define MODU_NAME_GEOMETRYCREATE       "GeometryCreate"            // CH: ���δ���ģ�� | EN: Geometry creation module
#define MODU_NAME_2DBCRMODU            "IMVS2dBcrModu"             // CH: ��ά��ʶ��ģ�� | EN: QR code recognition module
#define MODU_NAME_BCRMODU              "IMVSBcrModu"               // CH: ����ʶ��ģ�� | EN: Bar code recognition module
#define MODU_NAME_OCRMODU              "IMVSOcrModu"               // CH: �ַ�ʶ��ģ�� | EN: OCR (Optical Character Recognition) module
#define MODU_NAME_VERICODEMODU         "IMVSVericodeModu"          // CH: VeriCodeģ�� | EN: Verification code module
#define MODU_NAME_CALIBBOARDCALIBMODU  "IMVSCalibBoardCalibModu"   // CH: �궨��궨ģ�� | EN: Calibration module
#define MODU_NAME_NPOINTCALIBMODU      "IMVSNPointCalibModu"       // CH: N��궨ģ�� | EN: N-point calibration module
#define MODU_NAME_CALIBTRANSFORMMODU   "IMVSCalibTransformModu"    // CH: �궨ת��ģ�� | EN: Calibration conversion module
#define MODU_NAME_SCALETRANSFORMMODU   "IMVSScaleTransformModu"    // CH: ��λת��ģ�� | EN: Unit conversion module
#define MODU_NAME_IMAGECORRECTCALIBMODU "IMVSImageCorrectCalibModu"// CH: ����У��ģ�� | EN: Distortion calibration module
#define MODU_NAME_IMAGEMORPHMODU       "IMVSImageMorphModu"        // CH: ��̬ѧ����ģ�� | EN: Image morphological processing module
#define MODU_NAME_BINARYMODU           "IMVSBinaryModu"            // CH: ͼ���ֵ��ģ�� | EN: Image binarization module
#define MODU_NAME_IMAGEFILTERMODU      "IMVSImageFilterModu"       // CH: ͼ���˲�ģ�� | EN: Image filtering module
#define MODU_NAME_IMAGEENHANCEMODU     "IMVSImageEnhanceModu"      // CH: ͼ����ǿģ�� | EN: Image enhancement module
#define MODU_NAME_IMAGEMATHMODU        "IMVSImageMathModu"         // CH: ͼ������ģ�� | EN: Image arithmetic module
#define MODU_NAME_IMAGESHARPNESSMODU   "IMVSImageSharpnessModu"    // CH: ����������ģ�� | EN: Image resolution assessment module
#define MODU_NAME_IMAGEFIXTUREMODU     "IMVSImageFixtureModu"      // CH: ͼ������ģ�� | EN: Image correction module
#define MODU_NAME_SHADECORRECTMODU     "IMVSShadeCorrectModu"      // CH: ��ӰУ��ģ�� | EN: Shadow correction module
#define MODU_NAME_AFFINETRANSFORMMODU  "IMVSAffineTransformModu"   // CH: ����任ģ�� | EN: Affine transformation module
#define MODU_NAME_POLARUNWARPMODU      "IMVSPolarUnwarpModu"       // CH: Բ��չ��ģ�� | EN: Circular expansion module
#define MODU_NAME_COLOREXTRACTMODU     "IMVSColorExtractModu"      // CH: ��ɫ��ȡģ�� | EN: Color extraction module
#define MODU_NAME_COLORMEASUREMODU     "IMVSColorMeasureModu"      // CH: ��ɫ����ģ�� | EN: Color detection module
#define MODU_NAME_COLORTRANSFORMMODU   "IMVSColorTransformModu"    // CH: ��ɫת��ģ�� | EN: Color conversion module
#define MODU_NAME_IFMODULE             "IfModule"                  // CH: �������ģ�� | EN: Condition detection module
#define MODU_NAME_BRANCHMODULE         "BranchModule_STD"          // CH: ��֧ģ�� | EN: Branching module
#define MODU_NAME_ANDMODULE            "AndModule"                 // CH: �߼�ģ�� | EN: Logic module
#define MODU_NAME_FORMATMODULE         "FormatModule"              // CH: ��ʽ��ģ�� | EN: Formatting module
#define MODU_NAME_CALCULATORMODULE     "CalculatorModule"          // CH: ��������ģ�� | EN: Variable calculation module
#define MODU_NAME_STRINGCOMPAREMODULE  "StringCompareModule"       // CH: �ַ��Ƚ�ģ�� | EN: Character comparison module
#define MODU_NAME_SHELLMODULE          "ShellModule"               // CH: �ű�ģ�� | EN: Script module
#define MODU_NAME_POINTSETMODU         "PointSetMODU_STD"          // CH: �㼯ģ�� | EN: Point set module

// CH: ���ѧϰģ�� | EN: Deep learning modules
#define MODU_NAME_OCRDLMODU            "IMVSOcrDlModu"            // CH: ���ѧϰ�ַ�ʶ��ģ�� ��GPU�汾�� | EN: OCR (Optical Character Recognition) module (for deep learning), GPU version
#define MODU_NAME_CNNSEGMODU           "IMVSCnnFlawModu"          // CH: ���ѧϰͼ��ָ�ģ�� | EN: Image segmentation module (for deep learning)
#define MODU_NAME_CNNCHARDETECTMODU    "IMVSCnnCharDetectModu"    // CH: ���ѧϰ�ַ���λģ�� ��GPU�汾�� | EN: Character location module (for deep learning), GPU version
#define MODU_NAME_CNNCLASSIFYMODU      "IMVSCnnClassifyModu"      // CH: ���ѧϰ����ģ�� ��GPU�汾�� | EN: Deep learning classification module, GPU version
#define MODU_NAME_CNNDETECTMODU        "IMVSCnnDetectModu"        // CH: ���ѧϰĿ����ģ�� ��GPU�汾�� | EN: Target detection module (for deep learning), GPU version
#define MODU_NAME_CNNTRAINTOOLMODU     "IMVSCnnTrainToolModu"     // CH: ���ѧϰѵ������ģ�� | EN: Training tool module

// CH: V3.1.0�������ѧϰCPU�汾ģ�� | EN: V3.1.0 new deep learning CPU version modules
#define MODU_NAME_CNNCHARDETECTMODUC   "IMVSCnnCharDetectModuC"   // CH: ���ѧϰ�ַ���λģ�� ��CPU�汾�� | EN: Character location module (for deep learning), CPU version
#define MODU_NAME_CNNCLASSIFYMODUC     "IMVSCnnClassifyModuC"     // CH: ���ѧϰ����ģ�� ��CPU�汾�� | EN: Deep learning classification module, CPU version
#define MODU_NAME_CNNDETECTMODUC       "IMVSCnnDetectModuC"       // CH: ���ѧϰĿ����ģ�� ��CPU�汾�� | EN: Target detection module (for deep learning), CPU version

// CH: V3.0.0����ģ�� | EN: V3.0.0 new modules
#define MODU_NAME_BRANCHSTRINGCPMOLD      "BranchStringCpm"              // CH: ��֧�ַ�ģ�� | EN: Branch character module
#define MODU_NAME_FRAMEMEANMODU           "IMVSFrameMeanModu"            // CH: ֡ƽ��ģ�� | EN: Frame averaging module
#define MODU_NAME_IMAGECALIBMODU          "IMVSImageCalibModu"           // CH: ����궨ģ�� | EN: Distortion calibration module
#define MODU_NAME_IMAGECOMBINEPROCESSMODU "IMVSImageCombineProcessModu"  // CH: ͼ�����ģ�� | EN: Image combination module
#define MODU_NAME_IMAGENORMLIZEMODU       "IMVSImageNormlizeModu"        // CH: ͼ���һ��ģ�� | EN: Image normalization module
#define MODU_NAME_MARKINSPMODU            "IMVSMarkInspModu"             // CH: �ַ�ȱ�ݼ��ģ�� | EN: Character defect detection module
#define MODU_NAME_REGIONCOPYMODU          "IMVSRegionCopyModu"           // CH: �������ģ�� | EN: Area copying and filling module
#define MODU_NAME_READDATASMODULE         "ReadDatasModule"              // CH: ��������ģ�� | EN: Data receiving module
#define MODU_NAME_SAVETEXTMODULE          "SaveTextModule"               // CH: �ı�����ģ�� | EN: Text storage module
#define MODU_NAME_SENDDATASMODULE         "SendDatasModule"              // CH: ��������ģ�� | EN: Data sending module
#define MODU_NAME_TIMESTATISTICMODULE     "TimeStatisticModule"          // CH: ��ʱͳ��ģ�� | EN: Time-consuming statistics module
#define MODU_NAME_CAMERAMAPMODU           "IMVSCameraMapModu"            // CH: ���ӳ��ģ�� | EN: Camera mapping module
#define MODU_NAME_SINGLEPOINTALIGNMODU    "IMVSSinglePointAlignModu"     // CH: �����λģ�� | EN: Single point alignment module
#define MODU_NAME_MULTIPOINTALIGNMODU     "IMVSMultiPointAlignModu"      // CH: �㼯��λģ�� | EN: Point set alignment module
#define MODU_NAME_LINEALIGNMODU           "IMVSLineAlignModu"            // CH: �߶�λģ�� | EN: Line alignment module

// CH: V3.1.0����ģ�� | EN: V3.1.0 new modules
#define MODU_NAME_CIRCLEEDGEINSPMODU     "IMVSCircleEdgeInspModu"        // CH: Բ����Եȱ�ݼ��ģ�� | EN: Arc edge defect detection module
#define MODU_NAME_LINEEDGEINSPMODU       "IMVSLineEdgeInspModu"          // CH: ֱ�߱�Եȱ�ݼ��ģ�� | EN: Line edge defect detection module
#define MODU_NAME_CIRCLEEDGEPAIRINSPMODU "IMVSCircleEdgePairInspModu"    // CH: Բ����Ե��ȱ�ݼ��ģ�� | EN: Arc edge pair defect detection module
#define MODU_NAME_LINEEDGEPAIRINSPMODU   "IMVSLineEdgePairInspModu"      // CH: ֱ�߱�Ե��ȱ�ݼ��ģ�� | EN: Line edge pair defect detection module
#define MODU_NAME_EDGEINSPGROUPMODU      "IMVSEdgeInspGroupModu"         // CH: ��Ե���ȱ�ݼ��ģ�� | EN: Edge combination defect detection module
#define MODU_NAME_EDGEPAIRINSPGROUPMODU  "IMVSEdgePairInspGroupModu"     // CH: ��Ե�����ȱ�ݼ��ģ�� | EN: Edge pair combination defect detection module
#define MODU_NAME_EDGEFLAWINSPMODU       "IMVSEdgeFlawInspModu"          // CH: ��Եģ��ȱ�ݼ��ģ�� | EN: Edge model defect detection module
#define MODU_NAME_EDGEPAIRFLAWINSPMODU   "IMVSEdgePairFlawInspModu"      // CH: ��Ե��ģ��ȱ�ݼ��ģ�� | EN: Edge pair model defect detection module
#define MODU_NAME_BRANCHSTRINGCPML       "BranchStringCpmL"              // CH: ��֧�ַ�ģ�飨�����̣� | EN: Character comparison module (for single process)

// CH: V3.2.0����ģ�� | EN: V3.2.0 new modules
#define MODU_NAME_IMAGEBUFFERMODULE      "ImageBufferModule"             // CH: ����ͼ��ģ�� | EN: Cache image module
#define MODU_NAME_GRAYMATCHMODU          "IMVSGrayMatchModu"             // CH: �Ҷ�ģ��ƥ��ģ�� | EN: Grayscale model matching module
#define MODU_NAME_COLORRECOGNITIONMODU   "IMVSColorRecognitionModu"      // CH: ��ɫʶ��ģ�� | EN: Color distinguish module
#define MODU_NAME_IMAGECORRECTMANUALMODU "IMVSImageCorrectManualModu"    // CH: ͼ�����ģ�� | EN: Image correction module
#define MODU_NAME_CAMERAIOMODULE         "CameraIOModule"                // CH: ���IOͨ��ģ�� | EN: Camera IO communication module

// CH: V3.3.0����ģ�� | EN: V3.3.0 new modules
#define MODU_NAME_IMAGESOURCEMODULE      "ImageSourceModule"             // CH: ͼ��Դģ�� | EN: Image source module
#define MODU_NAME_LIGHTMODULE            "LightModule"                   // CH: ��Դģ�� | EN: Light module
#define MODU_NAME_QUADRANGEFINDMODULE    "IMVSQuadrangleFindModu"        // CH: �ı��β���ģ�� | EN: Quadrangle find module
#define MODU_NAME_LINEFINDGROUPMODULE    "IMVSLineFindGroupModu"         // CH: ֱ�߲������ģ�� | EN: Line find group module
#define MODU_NAME_MULTILINEFINDMODULE    "IMVSMultiLineFindModu"         // CH: ��ֱ�߲���ģ�� | EN: Multi-line find module
#define MODU_NAME_MAPCALIBMODULE         "IMVSMapCalibModu"              // CH: ӳ��궨ģ�� | EN: Mapping calibration module
#define MODU_NAME_NIMGCALIBMODULE        "IMVSNImageCalibModu"           // CH: Nͼ��궨ģ�� | EN: N-Image calibration module
#define MODU_NAME_IMGSTITCHMODULE        "IMVSImgStitchCalibModu"        // CH: ͼ��ƴ��ģ�� | EN: Image stitching module
#define MODU_NAME_GEOMETRICTRANSFORMMODULE "IMVSGeometricTransformModu"  // CH: ���α任ģ�� | EN: Geometric transform module
#define MODU_NAME_DATASETMODULE          "DataSetModule"                 // CH: ���ݼ���ģ�� | EN: Data set module
#define MODU_NAME_DATAASSEMBLEMODULE     "DataAssembleModule"            // CH: Э����װģ�� | EN: Protocol assemble module
#define MODU_NAME_DATAANALYSISMODULE     "DataAnalysisModule"            // CH: Э�����ģ�� | EN: Protocol analysis module
#define MODU_NAME_CNNSINGLECHARDETECTMODU "IMVSCnnSingleCharDetectModu"  // CH: ���ѧϰ���ַ����ģ�� ��GPU�汾�� | EN: Single character detection module (for deep learning), GPU version
#define MODU_NAME_CNNSINGLECHARDETECTMODUC "IMVSCnnSingleCharDetectModuC"// CH: ���ѧϰ���ַ����ģ�� ��CPU�汾�� | EN: Single character detection module (for deep learning), CPU version
#define MODU_NAME_GROUPMODULE            "IMVSGroup"                     // CH: Groupģ�� | EN: Group module

// CH: V3.4.0����ģ�� | EN: V3.4.0 new modules
#define MODU_NAME_MARKFINDMODULE         "IMVSMarkFindModu"              // CH: ͼ�ζ�λģ�� | EN: Graphic positioning module
#define MODU_NAME_BLOBFINDLABELSMODU     "IMVSBlobFindLabelsModu"        // CH: Blob��ǩ����ģ�� | EN: BLOB (Binary Large Object) labels analysis module
#define MODU_NAME_2DGRADEMODU            "IMVS2dGradeModu"               // CH: ��ά��ȼ�ģ�� | EN: QR code grade module
#define MODU_NAME_GLUEPATHCONDUCTMODU    "IMVSGluePathConductModu"       // CH: ��·����ģ�� | EN: Glue guide module
#define MODU_NAME_BRANCHENDMODU          "BranchEndModule"               // CH: ��֧����ģ�� | EN: Branch end module
#define MODU_NAME_COMMTRIGGERMODU        "CommTriggerModule"             // CH: ͨ�Ŵ���ģ�� | EN: Communication trigger module
#define MODU_NAME_OCRDLMODUC             "IMVSOcrDlModuC"                // CH: ���ѧϰ�ַ�ʶ��ģ�� ��CPU�汾�� | EN: OCR (Optical Character Recognition) module (for deep learning), CPU version
#define MODU_NAME_CNNCODERECGMODU        "IMVSCnnCodeRecgModu"           // CH: ���ѧϰ����ģ�� ��GPU�汾�� | EN: Code recognition module (for deep learning), GPU version
#define MODU_NAME_CNNCODERECGMODUC       "IMVSCnnCodeRecgModuC"          // CH: ���ѧϰ����ģ�� ��CPU�汾�� | EN: Code recognition module (for deep learning), CPU version
#define MODU_NAME_CNNRETRIEVALMODU       "IMVSCnnRetrievalModu"          // CH: ���ѧϰͼ�����ģ�� ��GPU�汾�� | EN: Image retrieval module (for deep learning), GPU version
#define MODU_NAME_CNNRETRIEVALMODUC      "IMVSCnnRetrievalModuC"         // CH: ���ѧϰͼ�����ģ�� ��CPU�汾�� | EN: Image retrieval module (for deep learning), CPU version

// CH: V4.0����ģ�� | EN: V4.0 new modules
#define MODU_NAME_CNNSEGMODUC            "IMVSCnnFlawModuC"              // CH: ���ѧϰͼ��ָ�ģ�� ��CPU�汾�� | EN: Image segmentation module (for deep learning), CPU version
#define MODU_NAME_INSPECTMODU            "IMVSInspectModu"               // CH: ȱ�ݶԱ�ģ�� | EN: Inspect module
#define MODU_NAME_MULTIIMAGEFUSIONMODU   "IMVSMultiImageFusionModu"      // CH: ��ͼ�ں�ģ�� | EN: Multi image fusion module
#define MODU_NAME_IMAGEAQUISITIONMODULE  "ImageAcquisitionModule"        // CH: ��ͼ�ɼ�ģ�� | EN: Image acquisition module
#define MODU_NAME_CNNINSPECTMODU         "IMVSCnnInspectModu"            // CH: DL�쳣���ģ�飨GPU�汾�� | EN: Inspect module (for deep learning), GPU version
#define MODU_NAME_CNNINSPECTMODUC        "IMVSCnnInspectModuC"           // CH: DL�쳣���ģ�飨CPU�汾�� | EN: Inspect module (for deep learning), CPU version

// CH: V4.1����ģ�� | EN: V4.1 new modules
#define MODU_NAME_ANGLEBISECTORFINDMODU  "IMVSAngleBisectorFindModu"     // CH: ��ƽ���߲���ģ�� | EN: Angle bisector line find module
#define MODU_NAME_MEDIANLINEFINDMODU     "IMVSMedianLineFindModu"        // CH: ���߲���ģ�� | EN: Median line find module
#define MODU_NAME_PARALLELCALCULATEMODU  "IMVSParallelCalculateModu"     // CH: ƽ���߼���ģ�� | EN: Parallel line calculate module
#define MODU_NAME_VERTICALLINEFINDMODU   "IMVSVerticalLineFindModu"      // CH: ���߲���ģ�� | EN: Vertical line find module
#define MODU_NAME_READCALIBFILEMODU      "ReadCalibFileModu"             // CH: �궨����ģ�� | EN: Read calibration file module
#define MODU_NAME_ROTATECALCULATEMODU    "IMVSRotateCalculateModu"       // CH: ��ת����ģ�� | EN: Rotate calculate module
#define MODU_NAME_CNNINSTANCESEGMENTMODU "IMVSCnnInstanceSegmentModu"    // CH: DLʵ���ָ�ģ�飨GPU�汾�� | EN: Instance segment module (for deep learning), GPU version
#define MODU_NAME_CNNINSTANCESEGMENTMODUC "IMVSCnnInstanceSegmentModuC"  // CH: DLʵ���ָ�ģ�飨CPU�汾�� | EN: Instance segment module (for deep learning), CPU version
#define MODU_NAME_MARKINSPMODUVA         "IMVSMarkInspModuVA"            // CH: �ַ�ȱ�ݼ��ģ�飨V4.1�汾�� | EN: Character defect detection module, 4.1 version

// CH: V4.2����ģ�� | EN: V4.2 new modules
#define MODU_NAME_COORDINATETRANSFORMMODU "CoordinateTransform"          // CH: ����ת��ģ�� | EN: Coordinate Transform Module
#define MODU_NAME_ARRAY2DCORRECTMODU      "IMVS2dArrayCorrectModu"       // CH: ��ά����ģ�� | EN: 2D Array Correct Module
#define MODU_NAME_BOXFILTERMODU           "IMVSBoxFilterModule"          // CH: Box����ģ�� | EN: Box Filter Module
#define MODU_NAME_BOXMERGEMODU            "IMVSBoxMergeModu"             // CH: Box�ں�ģ�� | EN: Box Merge Module
#define MODU_NAME_BOXOVERLAPCALCULATIONMODU  "IMVSBoxOverlapCalculationModu"    // CH: Box�ص���ģ�� | EN: Box Overlap Calculation Module
#define MODU_NAME_TARGETTRACKMODU         "IMVSTargetTrackModu"          // CH: Ŀ�����ģ�� | EN: Target Track Module
#define MODU_NAME_GRAPHICSSETMODU         "GraphicsSetModule"            // CH: ͼ���ռ�ģ�� | EN: Graphics Set Module
#define MODU_NAME_IMAGERESIZEMODU         "IMVSImageResizeModu"          // CH: ͼ������ģ�� | EN: Image Resize Module
#define MODU_NAME_DIVIDEIMAGEMODU         "IMVSDivideImageModu"          // CH: ��Ƭģ��ģ�� | EN: Divide Image Module
#define MODU_NAME_MULTILABELFILTERMODU    "IMVSMultiLabelFilterModu"     // CH: ���ǩɸѡģ�� | EN: MultiLabel Filter Module
#define MODU_NAME_EDGEPOSTRENDANALYMODU   "IMVSEdgePosTrendAnalyModu"    // CH: ��Եλ�����Ʒ���ģ�� | EN: Edge position trend analy module
#define MODU_NAME_EDGEPAIRPOSTRENDANALYMODU  "IMVSEdgePairPosTrendAnalyModu"    // CH: ��Ե��λ�����Ʒ���ģ�� | EN: Edge pair position trend analy module
#define MODU_NAME_IFBRANCHMODU            "IfBranchModule"               // CH: ������֧ | EN: Condition-Branch
#define MODU_NAME_TRIGGERMODU             "TriggerModule"                // CH: ����ģ�� | EN: Trigger Module
#define MODU_NAME_CNNUNSUPERVISEDMODU     "IMVSCnnUnSupervisedModu"      // CH: DL�޼ලGPU | EN: DL UnSupervised GPU

// CH: V4.2ά������ģ�� | EN: V4.2 Maintenance new modules
#define MODU_NAME_SURFACEDEFECTFILTERMODU  "IMVSSurfaceDefectFilterModu" // CH: ����ȱ���˲� | EN: Surface Defect Filter
#define MODU_NAME_ROTATECALIBMODU         "RotateCalibModu"              // CH: ��ת�궨 | EN: Rotate Calibration Module
#define MODU_NAME_SINGLEPOINTMAPALIGNMODU  "SinglePointMapAlignModu"     // CH: ����ӳ���λ | EN: Single Point Map Align Module
#define MODU_NAME_SINGLEPOINTGRABMODU     "SinglePointGrabModu"          // CH: ����ץȡ | EN: Single Point Grab Module
#define MODU_NAME_SINGLEPOINTRECTIFYMODU  "SinglePointRectifyModu"       // CH: �����ƫ | EN: Single Point Rectify Module
#define MODU_NAME_TRANSLATIONCALIBMODU    "TranslationCalibModu"         // CH: ƽ����ת�궨 | EN: Translation Calibration Module
#define MODU_NAME_GRAYMATCHVAMODU         "IMVSGrayMatchModuVA"          // CH: �Ҷ�ƥ�� | EN: Gray Model Match Module

// CH: V4.3����ģ�� | EN: V4.3 new modules
#define MODU_NAME_CONTOURMATCHMODU  "IMVSContourMatchModu"               // CH: ����ƥ�� | EN: IMVSContourMatchModu
#define MODU_NAME_INVERSEAFFINETRANSFORMMODU  "IMVSInverseAffineTransformModu"    // CH: �����任 | EN: IMVSInverseAffineTransformModu
#define MODU_NAME_ELLIPSEFITMODU  "IMVSEllipseFitModu"                  // CH: ��Բ��� | EN: IMVSEllipseFitModu
#define MODU_NAME_ELLIPSEFINDMODU  "IMVSEllipseFindModu"                // CH: ��Բ���� | EN: IMVSEllipseFindModu

// CH: V4.3ά������ģ�� | EN: V4.3 Maintenance new modules
#define MODU_NAME_MACHINELEARNINGCLASSIFIERMODU  "IMVSMachineLearningClassifierModu"    // CH: ML���� | EN: Machine Learning Classifier
#define MODU_NAME_CNNREGISTERCLASSIFYMODU  "IMVSCnnRegisterClassifyModu"    // CH: ע�����G | EN: Register Classify GPU
#define MODU_NAME_CNNREGISTERCLASSIFYMODUC  "IMVSCnnRegisterClassifyModuC"    // CH: ע�����C | EN: Register Classify CPU
#define MODU_NAME_CNNFASTFLAWMODU  "IMVSCnnFastFlawModu"    // CH: DL����ͼ��ָ� | EN: IMVSCnnFastFlawModu
#define MODU_NAME_MATRIXCIRCLEFINDMODU  "IMVSMatrixCircleFindModu"    // CH: ����Բ���� | EN: Matrix Circle Find
#define MODU_NAME_PIXELCOUNTVAMODU  "IMVSPixelCountModuVA"    // CH: ����ͳ�� | EN: Pixel Count

/*************************************************************************
 * �����궨��
 * Common macro definitions
 *************************************************************************/
const static unsigned int IMVS_PF_MAX_MODULE_NAME_LENGTH         = 64;         // CH: ģ��������󳤶� | EN: Maximum length of module name
const static unsigned int IMVS_PF_MAX_MODULE_DISPLAY_NAME_LENGTH = 256;        // CH: ģ����ʾ������󳤶� | EN: Maximum length of module display name
const static unsigned int IMVS_PF_MAX_MODULE_NUM                 = 1040;       // CH: ���ģ����� | EN: Maximum number of modules
const static unsigned int IMVS_PF_MAX_MODULE_PARAM_NUM           = 128;        // CH: ���ģ��������� | EN: Maximum number of module parameters
const static unsigned int IMVS_PF_STATUS_FILTER_RECEIVE          = 1;          // CH: ����״̬: ������Ϣ | EN: Filtering status: receiving information
const static unsigned int IMVS_PF_STATUS_FILTER_NOT_RECEIVE      = 0;          // CH: ����״̬: ��������Ϣ | EN: Filtering status: not receiving information
const static unsigned int IMVS_PF_MAX_DATATYPE_NUM               = 32;         // CH: �������������� | EN: Maximum number of data types
const static unsigned int IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH    = 128;        // CH: ģ����������󳤶� | EN: Maximum length of module result name
const static unsigned int IMVS_PF_MAX_MODULE_RESVALUE_LENGTH     = 4096;       // CH: ģ����ֵ��󳤶� | EN: Maximum length of module result value
const static unsigned int IMVS_PF_MAX_MODULE_PARAMVALUE_LENGTH   = 512;        // CH: ģ�����ֵ��󳤶� | EN: Maximum length of module parameter value
const static unsigned int IMVS_PF_INPUT_NO_PASSWORD              = 0;          // CH: ������״̬����ֵ | EN: Input value in the status without password
const static unsigned int IMVS_PF_DEFAULT_WAITTIME               = 10000;      // CH: Ĭ�ϵȴ�ʱ�� | EN: Default waiting time
const static unsigned int IMVS_PF_MAX_IMPORT_NUM                 = 16;         // CH: ����������ļ����� | EN: Maximum number of imported data files
const static unsigned int IMVS_PF_STATUS_HAS_PASSWORD            = 1;          // CH: �����ļ������� | EN: Solution file with password
const static unsigned int IMVS_PF_STATUS_HAS_NO_PASSWORD         = 0;          // CH: �����ļ������� | EN: Solution file without password
const static unsigned int IMVS_PF_STATUS_PLATFORM_SHOW           = 1;          // CH: ƽ̨������ʾ״̬ | EN: Status of showing platform interface
const static unsigned int IMVS_PF_STATUS_PLATFORM_HIDE           = 0;          // CH: ƽ̨��������״̬ | EN: Status of hiding platform interface
const static unsigned int IMVS_PF_MAX_PATH_LENGTH                = 260;        // CH: ·����󳤶�ֵ | EN: Maximum length of path
const static unsigned int IMVS_PF_PASSWORD_LENGTH                = 32;         // CH: ���볤��ֵ | EN: Maximum length of password
const static unsigned int IMVS_PF_VERSION_LENGTH                 = 32;         // CH: �汾��Ϣ����ֵ | EN: Maximum length of version information
const static unsigned int IMVS_PF_MAX_PROCESS_NAME_LENGTH        = 64;         // CH: ����������󳤶� | EN: Maximum length of process name
const static unsigned int IMVS_PF_MAX_PROCESS_NUM                = 1000;       // CH: ������̸��� | EN: Maximum number of processes
const static unsigned int IMVS_PF_CHAR_RES_SIZE                  = 2;          // CH: �ַ�ʶ������С | EN: Character recognition result size
const static unsigned int IMVS_PF_IMG_FORMAT_MONO8               = 0x01080001; // CH: ���ظ�ʽ MONO8 | EN: MONO8 pixel format
const static unsigned int IMVS_PF_IMG_FORMAT_RGB24               = 0x02180014; // CH: ���ظ�ʽ RGB24 | EN: RGB24 pixel format
const static unsigned int IMVS_PF_IMG_FORMAT_MONO16				 = 0x011000B8; // CH: ���ظ�ʽ MONO16| EN: MONO16 pixel format
const static unsigned int IMVS_PF_STATUS_PROCESS_SHIELD          = 1;          // CH: ���̽���״̬ | EN: Process disabled status
const static unsigned int IMVS_PF_STATUS_PROCESS_ENABLE          = 0;          // CH: ��������״̬ | EN: Process enable status
const static unsigned int IMVS_PF_ALL_MODULE_CTRL_CALLBACK       = 30000;      // CH: ����ģ�����ص�����ģ��ID | EN: All module results callback control module ID
const static unsigned int IMVS_PF_IMAGE_BUFFER_NUM               = 5;          // CH: ����ͼ��ģ�黺��ͼ������ | EN: Number of cached images
const static unsigned int IMVS_PF_CAMPICINFO_LIST_NUM            = 256;        // CH: ���ͼ����Ϣ�б���Ŀ | EN: Number of camera information lists
const static unsigned int IMVS_PF_MAX_ATTACH_FRONTWND_NUM        = 16;         // CH: ���Ƕ��ǰ�����н�����Ŀ | EN: Maximum number of attached front-end running windows
const static unsigned int IMVS_PF_MODULE_GLOBAL_VAR              = 13000;      // CH: ȫ�ֱ���ģ��ID | EN: Module ID of global variable
const static unsigned int IMVS_PF_STATUS_CALLBACK_START          = 1;          // CH: �����ص�״̬ | EN: Turn on callback status
const static unsigned int IMVS_PF_STATUS_CALLBACK_STOP           = 0;          // CH: ֹͣ�ص�״̬ | EN: Turn off callback status
const static unsigned int IMVS_PF_MAX_FLAW_SCORE_IMAGE_NUM       = 8;          // CH: ���ȱ�ݸ���ͼ���� | EN: Maximum number of defect probability images
const static unsigned int IMVS_PF_REENTRANT_MAX_CMD_LEN          = 16;         // CH: ��������󴥷��ַ������� | EN: Maximum length of command string in reentrant
const static unsigned int IMVS_PF_CAMERA_MAX_SN_LEN              = 64;         // CH: ���������кų��� | EN: Maximum length of camera sn
const static unsigned int IMVS_PF_CAMERA_MAX_NAME_LEN            = 64;         // CH: ���������Ƴ��� | EN: Maximum length of camera name
const static unsigned int IMVS_PF_CAMERA_MAX_NUM                 = 256;        // CH: ���������� | EN: Maximum length of camera number

// CH: ģ�������ͺ궨�� | EN: Module results type macro definition
const static unsigned int IMVS_PF_MODURES_TYPE_INT              = 1;          // CH: �������� | EN: Integer data
const static unsigned int IMVS_PF_MODURES_TYPE_FLOAT            = 2;          // CH: ���������� | EN: Float data
const static unsigned int IMVS_PF_MODURES_TYPE_STRING           = 3;          // CH: �ַ��������� | EN: String data
const static unsigned int IMVS_PF_MODURES_TYPE_IMAGE            = 4;          // CH: ͼ�������� | EN: Image data
const static unsigned int IMVS_PF_MODURES_TYPE_CHUNK            = 5;          // CH: �������������� | EN: Data used for big data
const static unsigned int IMVS_PF_MODURES_TYPE_BYTEDATA         = 6;          // CH: ������������������ | EN: Binary data
const static unsigned int IMVS_PF_MODURES_TYPE_DOUBLE			= 7;          // CH: ���������� | EN: Double data

// CH: ������������ | EN: Import data types
const static unsigned int IMVS_PF_IMPORT_TYPE_TEMP              = 1;          // CH: ģ���������� | EN: Template data type
const static unsigned int IMVS_PF_IMPORT_TYPE_FONT              = 2;          // CH: �ֿ��������� | EN: Font library data type
const static unsigned int IMVS_PF_IMPORT_TYPE_CALIB             = 3;          // CH: �궨�ļ��������� | EN: Calibration file data type
const static unsigned int IMVS_PF_IMPORT_TYPE_DLN               = 4;          // CH: ���ѧϰģ���ļ��������� | EN: Font library of deep learning data type
const static unsigned int IMVS_PF_IMPORT_TYPE_IMAGE             = 5;          // CH: ͼ���������� | EN: Image data type
const static unsigned int IMVS_PF_IMPORT_TYPE_MARKINSP          = 6;          // CH: �ַ�ģ������ | EN: Character template type
const static unsigned int IMVS_PF_IMPORT_TYPE_EDGEFLAW          = 7;          // CH: ��Եȱ��ģ������ | EN: Edge defect template type
const static unsigned int IMVS_PF_IMPORT_TYPE_COLORRECOGNITION   = 8;          // CH: ��ɫʶ��ģ������ | EN: Color recognition template type
const static unsigned int IMVS_PF_IMPORT_TYPE_MARKFIND          = 9;          // CH: ͼ�ζ�λģ������ | EN: Mark find template type
const static unsigned int IMVS_PF_IMPORT_TYPE_GLUEPATHCONDUCT    = 10;          // CH: ·����ȡģ������ | EN: Glue path conduct template type
const static unsigned int IMVS_PF_IMPORT_TYPE_IMGSTITCHCALIB     = 11;          // CH: ͼ��ƴ��ģ������ | EN: Image stitch calib template type
const static unsigned int IMVS_PF_IMPORT_TYPE_INSPECT           = 12;          // CH: ȱ�ݶԱ�ģ������ | EN: Inspect template type

/*************************************************************************
 * ö�ٶ��壺�ص������е�����㷨ƽ̨��Ϣ����
 * Enumeration definition: the type of output information in the callback function
 *************************************************************************/
typedef enum IMVS_CTRLC_OUTPUT_PlATFORM_INFO_TYPE__
{
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_MODULE_RESULT      = 0,    // CH: ģ����������Ϣ | EN: Module result
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_START_CONTINUOUSLY = 1,    // CH: ������������ִ�п�ʼ��Ϣ | EN: Information of starting continuous execution of single process
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_STOP               = 2,    // CH: ��������ִֹͣ��״̬��Ϣ | EN: Information of stopping single process execution
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_WORK_STATE         = 3,    // CH: ���̹���״̬��Ϣ | EN: Process status information
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_HB_MODU            = 4,    // CH: ģ�������쳣��Ϣ������̰汾�� | EN: Module heartbeat exception information, multi-process version
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_HB_SERVER          = 5,    // CH: ���������쳣��Ϣ | EN: Server heartbeat exception information
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_HB_CLIENT          = 6,    // CH: ƽ̨���������쳣 | EN: Information of platform interface heartbeat exception
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_DONGLE             = 7,    // CH: ���ܹ��쳣��Ϣ | EN: Dongle status information
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_SOLUTION_LOAD_INTERFACE_FILE = 8,    // CH: �������ؽ����ļ���Ϣ | EN: The file information of solution loading interface
    IMVS_ENUM_CTRLC_OUTPUT_PlATFORM_INFO_SOLUTION_SAVE_END  = 9,    // CH: �������״̬��Ϣ | EN: Status of ending solution saving
    IMVS_ENUM_CTRLC_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_END  = 10,   // CH: ���ؽ���״̬��Ϣ | EN: Status of ending solution loading
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_HB_SP_PROXY        = 11,   // CH: ģ����������쳣��Ϣ�������̰汾�� | EN: Module proxy heartbeat exception information, single-process version
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_GLOBALSCRIPT_CRASH = 12,   // CH: ȫ�ֽű��쳣��Ϣ | EN: Global script exception information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_LOAD_MODULE_WARN   = 13,   // CH: ��������ʱģ����󾯸���Ϣ | EN: Load module error warning information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_EXPORT_PROCESS_END = 14,   // CH: �������̽�����Ϣ | EN: Export process end information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_IMPORT_PROCESS_END = 15,   // CH: �������̽�����Ϣ | EN: Import process end information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_PROCEDURE_UNREGISTER = 16, // CH: ���̽�ע����Ϣ | EN: Process deregister information
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_CAMERA_COLLECT     = 17,   // CH: ���ȡͼ������Ϣ | EN: Camera collect end information
    IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_COMMUNICATION_CONNECT = 18,  // CH: ͨ��������Ϣ | EN: Communication connect information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_CAMERA_COLLECT_START  = 19,  // CH: ���ȡͼ��ʼ��Ϣ | EN: Camera collect start information
	IMVS_ENUM_CTRLC_OUTPUT_PLATFORM_INFO_CAMERA_CONNECT_STATUS = 20,  // CH: �������״̬��Ϣ   | EN: Camera connect status information

} IMVS_CTRLC_OUTPUT_PlATFORM_INFO_TYPE;

/*************************************************************************
 * �ṹ�嶨��
 * Structure definition
 *************************************************************************/
// CH: ����㷨ƽ̨��Ϣ�ṹ | EN: Algorithm platform information structure
typedef struct IMVS_PF_OUTPUT_PLATFORM_INFO__
{
    unsigned int  nInfoType;                                // CH: �ص���Ϣ���� | EN: Callback information type
    unsigned int  nDataSize;                                // CH: �ص����ݷ����ڴ� | EN: Size of memory allocated for saving callback data
    unsigned int  nDataLen;                                 // CH: �ص�����ʵ�ʳ��� | EN: Actual size of callback data
    void *        pData;                                    // CH: �ص����� | EN: Callback data details
    unsigned int  nReserved[4];                             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_OUTPUT_PLATFORM_INFO;

// CH: ģ������Ϣ�ṹ | EN: Module results information structure
typedef struct IMVS_PF_MODULE_STRING_VALUE__
{
    char            strValue[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: �ַ������� | EN: String data
    unsigned int    nReserved[4];    // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MODULE_STRING_VALUE;       // CH: �ַ����������� | EN: String data structure

typedef struct IMVS_PF_MODULE_IMAGE_VALUE_
{
    char *          pData;               // CH: ʵ������ | EN: Actual data
    unsigned int    nLen;                // CH: ʵ�����ݳ��� | EN: Actual data size
    char            strReserved[260];    // CH: �����ֶ� | EN: Reserved
    unsigned int    nReserved[4];        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MODULE_IMAGE_VALUE;            // CH: ͼ���������� | EN: Image data structure

typedef struct IMVS_PF_MODULE_CHUNK_VALUE__
{
    char *          pData;               // CH: ʵ������ | EN: Actual data
    unsigned int    nLen;                // CH: ʵ�����ݳ��� | EN: Actual data size
    char            strReserved[260];    // CH: �����ֶ� | EN: Reserved
    unsigned int    nReserved[4];        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MODULE_CHUNK_VALUE;            // CH: ���������� | EN: Big data structure

typedef struct IMVS_PF_MODULE_BYTEDATA_VALUE_
{
	char *          pData;               // CH: ʵ������ | EN: Actual data
	unsigned int    nLen;                // CH: ʵ�����ݳ��� | EN: Actual data size
	unsigned int    nReserved[4];        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MODULE_BYTEDATA_VALUE;

typedef struct IMVS_PF_MODULE_RESULT_INFO__
{
    int             nValueStatus;                                         // CH: �������������״̬ 1�ɹ�������ֵʧ�� | EN: Status of a single module, 1-succeeded, other values-error codes
    char            strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH];    // CH: ģ�������� | EN: Module result name
    int             nParamType;                                           // CH: ģ��������:1���� 2������ 3�ַ����� 4��ʾͼ�� 5��ʾ������ | EN: Module result type: 1-integer, 2-float, 3-string, 4-image, 5-big data
    int             nValueNum;                                            // CH: ģ��ֵ���� | EN: Number of module values
    int *           pIntValue;                                            // CH: �������� | EN: Integer data
    float *         pFloatValue;                                          // CH: ���������� | EN: Float data
	double *        pDoubleValue;                                         // CH: ���������� | EN: Double data
    IMVS_PF_MODULE_STRING_VALUE * pstStringValue;                         // CH: �ַ��������� | EN: String data
    IMVS_PF_MODULE_IMAGE_VALUE  * pstImageValue;                          // CH: ͼ������ | EN: Image data
    IMVS_PF_MODULE_CHUNK_VALUE  * pstChunkValue;                          // CH: ������ | EN: Big data
	IMVS_PF_MODULE_BYTEDATA_VALUE * pstByteValue;                         // CH: ���������� | EN: Binary data
    unsigned int    nReserved[4];                                         // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MODULE_RESULT_INFO;                                             // CH: ģ������Ϣ | EN: Module result details

typedef struct IMVS_PF_MODULE_RESULT_INFO_LIST__
{
    // CH: ģ����������Ϣ | EN: Module results basic information
    unsigned int    nStatus;                // CH: ����ģ���״̬ 1�ɹ�������ֵ���쳣 | EN: Module status, 1-succeeded, other values-error code
	unsigned int    nErrorCode;             // CH: ģ���쳣ʱ�ײ㷵�صĴ����� | EN: Error code returned when the module is abnormal
    unsigned int    nProcessID;             // CH: ����ID | EN: Process ID
    unsigned int    nModuleID;              // CH: ģ��ID | EN: Module ID
    float           fModuleTime;            // CH: ģ��ʱ�䣬����������ȫ�����￪ʼ���㣬�ӽ��������ݷ��ͳ�ȥ�������� | EN: Module time
    float           fAlgorithmTime;         // CH: �㷨ʱ�� | EN: Algorithm time
    unsigned int    nInCycle;               // CH: �Ƿ�Ϊѭ����ģ�� | EN: Whether it is the module in the loop
    char *          pstrModuleName;         // CH: ģ������ | EN: Module name
    char *          pstrDisplayName;        // CH: ģ����ʾ���� | EN: Displayed module name
    char *          pReserved[8];           // CH: �����ֶ� | EN: Reserved
    char            strReserved[60];        // CH: �����ֶ� | EN: Reserved
    unsigned int    nReserved1[2];           // CH: �����ֶ� | EN: Reserved
    unsigned int    nExecuteCount;          // CH: ִ�д��� | EN: Execute Count
    unsigned int    nReserved2[1];           // CH: �����ֶ� | EN: Reserved

    // CH: ģ������������ | EN: Module results data
    int             nResultNum;                   // CH: ģ�������� | EN: Number of module results
    IMVS_PF_MODULE_RESULT_INFO * pModuResInfo;    // CH: ģ���� | EN: Module result details

    char            strReCommand[IMVS_PF_REENTRANT_MAX_CMD_LEN];  // CH: �����봥���ַ��� | EN: Command string in reentrant
    unsigned int    nReservedEx[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MODULE_RESULT_INFO_LIST;

// CH: ���ܹ�״̬��Ϣ�ṹ | EN: Dongle status information structure
typedef struct IMVS_PF_DONGLE_INFO__
{
    unsigned int    nDongleStatus;  // CH: ���ܹ�״̬ | EN: Dongle status
    unsigned int    nReserved[4];   // CH: �����ֶ� | EN: Reserved
} IMVS_PF_DONGLE_INFO;

// CH: ����״̬��Ϣ�ṹ | EN: Process status information structure
typedef struct IMVS_PF_MODULE_WORK_STAUS__
{
	unsigned int    nProcessID;     // CH: ����ID | EN: Process ID
	unsigned int    nWorkStatus;    // CH: 0�ǿ��У�1��æµ | EN: Work status, 0-idle, 1-busy
    unsigned int    nIsTimeValid;   // CH: ����ʱ����Ч�� | EN: Is process time valid
    float           fProcessTime;   // CH: ����ʱ�� | EN : Process Time
    unsigned int    nExecuteCount;  // CH: ִ�д��� | EN: Execute Count
    char            strReCommand[IMVS_PF_REENTRANT_MAX_CMD_LEN];  // CH: �����봥���ַ��� | EN: Command string in reentrant
	unsigned int    nReserved[4];   // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MODULE_WORK_STAUS;

// CH: �������ؽ����ļ���Ϣ�ṹ | EN: Structure about solution loading interface information
typedef struct IMVS_PF_SOLUTION_LOAD_INTERFACE_FILE_INFO__
{
    unsigned char * pData;          // CH: �ļ���Ϣ���� | EN: File data
    unsigned int    nDataLen;       // CH: �ļ���Ϣ���� | EN: File data length
    unsigned int    nReserved[4];   // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SOLUTION_LOAD_INTERFACE_FILE_INFO;

// CH: ����ִ�п�ʼ״̬��Ϣ�ṹ | EN: Structure about information of starting continuous execution of single process
typedef struct IMVS_PF_STATUS_START_CONTINUOUSLY_INFO__
{
    unsigned int    nStatus;       // CH: ״ֵ̬ | EN: Status value
    unsigned int    nProcessID;    // CH: ����ID | EN: Process ID
    unsigned int    nReserved[3];  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_STATUS_START_CONTINUOUSLY_INFO;

// CH: ִֹͣ��״̬��Ϣ�ṹ | EN: Structure about information of stopping single process execution
typedef struct IMVS_PF_STATUS_STOP_INFO__
{
    unsigned int    nStatus;       // CH: ״ֵ̬ | EN: Status value
    unsigned int    nProcessID;    // CH: ����ID | EN: Process ID
	unsigned int    nStopAction;   // CH: ����ֹͣ��ԭ�� (0:��Ч; 1:����ֹͣ; 2:����NG; 3:ģ������ֹͣ����) | EN: Reason for process stop (0: invalid; 1: normal stop; 2: process NG; 3: Module request to stop process)
    unsigned int    nReserved[2];  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_STATUS_STOP_INFO;

// CH: ģ�������쳣��Ϣ�ṹ | EN: Heartbeat exception information structure of module
typedef struct IMVS_PF_EXCEPTION_HB_MODULE_INFO__
{
    unsigned int    nModuleID;                                              // CH: ģ��ID | EN: Module ID
    unsigned int    nProcessID;                                             // CH: ����ID | EN: Process ID
    char            strModuleName[IMVS_PF_MAX_MODULE_NAME_LENGTH];          // CH: ģ������ | EN: Module name
	char            strDisPlayName[IMVS_PF_MAX_MODULE_DISPLAY_NAME_LENGTH]; // CH: ģ����ʾ���� | EN: Displayed module name
    unsigned int    nReserved[4];                                           // CH: �����ֶ� | EN: Reserved
} IMVS_PF_EXCEPTION_HB_MODULE_INFO;

// CH: ���������쳣��Ϣ�ṹ | EN: Structure about abnormal service heartbeat information
typedef struct IMVS_PF_EXCEPTION_HB_SERVER_INFO__
{
    unsigned int    nServerStatus;    // CH: Server״̬: 0��ʾ������������ʾ������ | EN: Server status: 0-normal, other value- error codes
    unsigned int    nReserved[4];     // CH: �����ֶ� | EN: Reserved
} IMVS_PF_EXCEPTION_HB_SERVER_INFO;

// CH: ƽ̨���������쳣��Ϣ�ṹ | EN: Structure about information of abnormal platform interface heartbeat
typedef struct IMVS_PF_EXCEPTION_HB_CLIENT_INFO__
{
    unsigned int    nClientStatus;  // CH: Client״̬: 0��ʾ������������ʾ������ | EN: Client status: 0-normal, other value-error code
    unsigned int    nReserved[4];   // CH: �����ֶ� | EN: Reserved
} IMVS_PF_EXCEPTION_HB_CLIENT_INFO;

// CH: �������״̬��Ϣ�ṹ | EN: Status information structure of ending saving solution
typedef struct IMVS_PF_SOLUTION_SAVE_END_INFO__
{
    unsigned int    nClientType;  // CH: �ͻ������� | EN: Client type
    unsigned int    nStatus;      // CH: �������״̬ | EN: Status information
	char            strSolPath[IMVS_PF_MAX_PATH_LENGTH]; // CH: ����·�� | EN: Solution path
    unsigned int    nReserved[4]; // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SOLUTION_SAVE_END_INFO;

// CH: ���ؽ���״̬��Ϣ�ṹ | EN: Status information structure of ending solution loading
typedef struct IMVS_PF_SOLUTION_LOAD_END_INFO__
{
    unsigned int    nClientType;  // CH: �ͻ������� | EN: Client type
    unsigned int    nStatus;      // CH: ���ؽ���״̬ | EN: Status information
	char            strSolPath[IMVS_PF_MAX_PATH_LENGTH]; // CH: ����·�� | EN: Solution path
    unsigned int    nReserved[4]; // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SOLUTION_LOAD_END_INFO;

// CH: ģ����������쳣��Ϣ�ṹ | EN: Heartbeat exception information structure of module proxy
typedef struct IMVS_PF_EXCEPTION_HB_SP_PROXY_INFO__
{
	unsigned int    nSolStatu;               // CH: �����Ƿ����״̬ 0�����������ڣ�1���������� | EN: Solution exists status, 0:solution not exist, 1: solution exist
	unsigned int    nReserved[4];            // CH: �����ֶ� | EN: Reserved
} IMVS_PF_EXCEPTION_HB_SP_PROXY_INFO;

// CH: ȫ�ֽű�ģ���쳣��Ϣ�ṹ | EN: Exception information structure of global script module
typedef struct IMVS_PF_GLOBALSCRIPT_CRASH_INFO__
{
	unsigned int    nStatus;                 // CH: ȫ�ֽű�����״̬ | EN: Global script crash status
	unsigned int    nReserved[4];            // CH: �����ֶ� | EN: Reserved
} IMVS_PF_GLOBALSCRIPT_CRASH_INFO;

// CH: ���ط����ϱ�������Ϣ�ṹ | EN: Load module error warning information structure
typedef struct IMVS_PF_LOAD_MODULE_ERROR_INFO__
{
	unsigned int nModuleID;                                     // CH: ģ��ID | EN: Module ID
	char         strModuleName[IMVS_PF_MAX_MODULE_NAME_LENGTH]; // CH: ģ������ | EN: Module name
	int          nErrorCode;                                    // CH: ������ | EN: Error code
} IMVS_PF_LOAD_MODULE_ERROR_INFO;

// CH: ���ط����ϱ�������Ϣ�б�ṹ | EN: Load module error warning information list structure
typedef struct IMVS_PF_LOAD_MODULE_ERROR_INFO_LIST__
{
	unsigned int nClientType;                   // CH: �ͻ������� | EN: Client type
	unsigned int nModuleNum;                    // CH: �ϱ�������Ϣģ������ | EN: Module number
	IMVS_PF_LOAD_MODULE_ERROR_INFO astLoadModuErrInfo[IMVS_PF_MAX_MODULE_NUM]; // CH: ���ط����ϱ�������Ϣ | EN: Load module error warning information
	unsigned int nReserved[4];                  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_LOAD_MODULE_ERROR_INFO_LIST;

// CH: �������̽���״̬��Ϣ�ṹ | EN: Status information structure of ending process exporting
typedef struct IMVS_PF_EXPORT_PROCESS_END_INFO__
{
	unsigned int    nProcessId;                             // CH: ����ID | EN: Process id
	char            strProcPath[IMVS_PF_MAX_PATH_LENGTH];   // CH: �����ļ�·�� | EN: The path of process file
	int             nErrorCode;                             // CH: ������ | EN: Error code
	unsigned int    nReserved[4];                           // CH: �����ֶ� | EN: Reserved
} IMVS_PF_EXPORT_PROCESS_END_INFO;

// CH: �������̽���״̬��Ϣ�ṹ | EN: Status information structure of ending process importing
typedef struct IMVS_PF_IMPORT_PROCESS_END_INFO__
{
	unsigned int    nProcessId;                                   // CH: ����ID | EN: Process id
	char            strProcName[IMVS_PF_MAX_PROCESS_NAME_LENGTH]; // CH: �������� | EN: Process name
	int             nErrorCode;                                   // CH: ������ | EN: Error code
	unsigned int    nReserved[4];                                 // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMPORT_PROCESS_END_INFO;

// CH: ���̽�ע����Ϣ | EN: Process deregister information
typedef struct IMVS_PF_PROCEDURE_UNREGISTER_INFO__
{
	unsigned int    nClientType;                                  // CH: �ͻ������� | EN: Client type
	unsigned int    nProcessID;                                   // CH: ɾ������ID | EN: The id of deleted process
	int             nErrorCode;                                   // CH: ɾ������״̬ | EN: The error code of deleted process
	char            strProcessName[IMVS_PF_MAX_PROCESS_NAME_LENGTH]; // CH: �������� | EN: Process name
	unsigned int    nReserved[4];                                 // CH: �����ֶ� | EN: Reserved
} IMVS_PF_PROCEDURE_UNREGISTER_INFO;

// CH: ����ģ����Ϣ�ṹ | EN: Module information structure
typedef struct IMVS_PF_MODULE_INFO__
{
    unsigned int    nModuleID;                                              // CH: ģ��ID | EN: Module ID
    unsigned int    nProcessID;                                             // CH: ����ID | EN: Process ID
	char            strDisplayName[IMVS_PF_MAX_MODULE_DISPLAY_NAME_LENGTH]; // CH: ������ʾ���� | EN: Displayed module name
    char            strModuleName[IMVS_PF_MAX_MODULE_NAME_LENGTH];          // CH: ģ������ | EN: Module name
    unsigned int    nReserved[128];                                         // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MODULE_INFO;

// CH: ģ����Ϣ�б�ṹ | EN: Module information list structure
typedef struct IMVS_PF_MODULE_INFO_LIST__
{
    unsigned int           nNum;                                     // CH: ģ����� | EN: Number of modules in list
    IMVS_PF_MODULE_INFO    astModuleInfo[IMVS_PF_MAX_MODULE_NUM];    // CH: ģ����Ϣ�б� | EN: Information details of a module
    unsigned int           nReserved[4];                             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MODULE_INFO_LIST;

// CH: ģ�������Ϣ�ṹ | EN: Module parameter structure
typedef struct IMVS_PF_MODULE_PARAM__
{
    char            strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH];      // CH: �������� | EN: Parameter name
    char            strParamValue[IMVS_PF_MAX_MODULE_PARAMVALUE_LENGTH];    // CH: ����ֵ | EN: Parameter value
    unsigned int    nReserved[16];                                          // CH: �����ֶ� | EN: Reserved
}IMVS_PF_MODULE_PARAM;

// CH: ģ������б���Ϣ�ṹ | EN: Module parameter list structure
typedef struct IMVS_PF_MODULE_PARAM_LIST__
{
    unsigned int          nParamNum;                                          // CH: �������� | EN: The number of parameters in the list
    IMVS_PF_MODULE_PARAM  stModuleParamList[IMVS_PF_MAX_MODULE_PARAM_NUM];    // CH: ģ����� | EN: Module parameters in list
    unsigned int          nReserved[4];                                       // CH: �����ֶ� | EN: Reserved
}IMVS_PF_MODULE_PARAM_LIST;

// CH: ģ�������Ϣ�ṹ | EN: Module filtering information structure
typedef struct IMVS_PF_FILTER_MODULE__
{
    unsigned int    nModuleID;       // CH: ģ��ID | EN: Module ID
    unsigned int    nReserved[4];    // CH: �����ֶ� | EN: Reserved
}IMVS_PF_FILTER_MODULE;

// CH: �������͹�����Ϣ�ṹ | EN: Structure about information of data type filtering
typedef struct IMVS_PF_FILTER_DATATYPE__
{
    unsigned int    nDataType;           // CH: �������� | EN: Data type
    unsigned int    nReserved[4];        // CH: �����ֶ� | EN: Reserved
}IMVS_PF_FILTER_DATATYPE;

// CH: ����������Ϣ�ṹ | EN: Filter condition information structure
typedef struct IMVS_PF_FILTER_CONDITION_LIST__
{
    unsigned int               nModuNum;                                   // CH: ģ�������Ϣ���� | EN: The number of module filtering information
    unsigned int               nDataTypeNum;                               // CH: �������͹�����Ϣ���� | EN: The number of data type filtering information
    unsigned int               nModuStatus;                                // CH: ģ�����״̬ | EN: Module filtering status
    unsigned int               nDataTypeStatus;                            // CH: �������͹���״̬ | EN: Data type filtering status
    IMVS_PF_FILTER_MODULE      stFilterModule[IMVS_PF_MAX_MODULE_NUM];     // CH: ģ�������Ϣ | EN: Module filtering information
    IMVS_PF_FILTER_DATATYPE    stFilterDataType[IMVS_PF_MAX_DATATYPE_NUM]; // CH: �������͹�����Ϣ | EN: Information of data type filtering
    unsigned int               nReserved[4];                               // CH: �����ֶ� | EN: Reserved
}IMVS_PF_FILTER_CONDITION_LIST;

// CH: ����ƽ̨�������������Ϣ�ṹ | EN: Structure about inputted parameters information when saving platform solution
typedef struct IMVS_PF_SAVE_SOLUTION_INPUT__
{
    char                strPath[IMVS_PF_MAX_PATH_LENGTH];    // CH: ���淽������·�� | EN: Solution files saving path
    char                strPassWord[IMVS_PF_PASSWORD_LENGTH];// CH: ���淽������ | EN: Password of the saved solution file
    unsigned char *     pAdditionData;                       // CH: ���淽�������Զ������� | EN: Custom data while saving the solution file
    unsigned int        nDataLen;                            // CH: ���淽�������Զ������ݳ��� | EN: Custom data length while saving the solution file
    unsigned int        nReserved[4];                        // CH: �����ֶ� | EN: Reserved
}IMVS_PF_SAVE_SOLUTION_INPUT;

// CH: ��ģ�鵼���������������Ϣ�ṹ | EN: Module input parameter structure
typedef struct IMVS_PF_IMPORT_MODULE_DATA__
{
    char *             pData;                             // CH: �����ļ�����·�������� | EN: The imported file's path or data
    unsigned int       nDataLen;                          // CH: �����ļ�����·�������ݳ��� | EN: Length of the imported file's path
    unsigned int       nReserved[4];                      // CH: �����ֶ� | EN: Reserved
}IMVS_PF_IMPORT_MODULE_DATA;

typedef struct IMVS_PF_IMPORT_MODULE_DATA_INPUT__
{
    unsigned int                  nModuleID;                                   // CH: ģ��ID | EN: Module ID
    unsigned int                  nDataType;                                   // CH: ������������ (1: ģ����������, 2:�ֿ���������, 3:�궨�ļ���������, 4:���ѧϰģ���ļ���������, 5:ͼ����������, 6:�ַ�ģ������, 7:��Եȱ��ģ������; 8:��ɫʶ��ģ������) | EN: Data type, including template, font library, calibration file, font library of deep learning, image, character defect template, edge defect template, color recognition template
    unsigned int                  nDataNum;                                    // CH: �������ݸ��� | EN: The number of data
    IMVS_PF_IMPORT_MODULE_DATA    stImportModuData[IMVS_PF_MAX_IMPORT_NUM];    // CH: �������� | EN: Imported data
	unsigned int                  nRecvTimeout;                                // CH: ���ճ�ʱ | EN: Receive timeout
    unsigned int                  nReserved[3];                                // CH: �����ֶ� | EN: Reserved
}IMVS_PF_IMPORT_MODULE_DATA_INPUT;

// CH: �����汾��Ϣ�ṹ | EN: Solution version information structure
typedef struct IMVS_PF_SOLUTION_VERSION_INFO__
{
    char    strSolutionInfo[IMVS_PF_VERSION_LENGTH];     // CH: �����汾��Ϣ | EN: Solution version information
    char    strReserved[32];                             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SOLUTION_VERSION_INFO;

// CH: ������Ϣ�ṹ | EN: Process information structure
typedef struct IMVS_PF_PROCESS_INFO__
{
    unsigned int nProcessID;                                        // CH: ����ID | EN: Process ID
    char         strProcessName[IMVS_PF_MAX_PROCESS_NAME_LENGTH];   // CH: �������� | EN: Process name
    unsigned int nReserved[4];                                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_PROCESS_INFO;

// CH: ������Ϣ�б�ṹ | EN: Process information list structure
typedef struct IMVS_PF_PROCESS_INFO_LIST__
{
    unsigned int         nNum;                                       // CH: ���̸��� | EN: The number of processes in the list
    IMVS_PF_PROCESS_INFO astProcessInfo[IMVS_PF_MAX_PROCESS_NUM];    // CH: ������Ϣ�б� | EN: Process information
    unsigned int         nReserved[4];                               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_PROCESS_INFO_LIST;

// CH: ���ͼ����Ϣ�ṹ | EN: Camera image information structure
typedef struct IMVS_PF_CAMERA_PIC_INFO__
{
	int  nCameraId;                               // CH: ���ģ��ID | EN: Camera module id
	char szLocalPicPath[IMVS_PF_MAX_PATH_LENGTH]; // CH: ����ͼƬ����·�� | EN: Local picture absolute path
}IMVS_PF_CAMERA_PIC_INFO;

// CH: ���ͼ����Ϣ�б�ṹ | EN: Camera image information list structure
typedef struct IMVS_PF_CAMERA_PIC_INFO_LIST__
{
	int nNum;                                                              // CH: �б�ʵ�ʴ�С | EN: The size of the list
	IMVS_PF_CAMERA_PIC_INFO stCamPicInfoList[IMVS_PF_CAMPICINFO_LIST_NUM]; // CH: ���ͼ����Ϣ�б� | EN: Camera image information list
	int                     nTimeout;                                      // CH: �ӿڳ�ʱ | EN: Interface timeout
	unsigned int            nReserved[4];                                  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CAMERA_PIC_INFO_LIST;

// CH: Ƕ��ǰ�����н��洰������Ϣ�ṹ | EN: The handle information of third-party interfaces/windows
typedef struct IMVS_PF_FRONTEDWND_HANDLE_INFO__
{
	int          nIndex;               // CH: �Ӵ������ | EN: The index of son window
	void *       pFrontHandle;         // CH: �������� | EN: The handle of third-party interfaces/windows
} IMVS_PF_FRONTEDWND_HANDLE_INFO;

// CH: Ƕ��ǰ�����н��游�������б�ṹ | EN: The handle list structure of third-party interfaces/windows
typedef struct IMVS_PF_FRONTEDWND_HANDLE_LIST__
{
	int          nNum;                                                  // CH: Ŀ�길�������� | EN: Number of target parent forms
	IMVS_PF_FRONTEDWND_HANDLE_INFO stFrontHandleArray[IMVS_PF_MAX_ATTACH_FRONTWND_NUM];    // CH: ǰ�����н������б� | EN: The handle list of third-party interfaces/windows
	int          nSleepTime;                                            // CH: Ƕ��ǰ��ʱ | EN: Sleep time before attaching
	unsigned int nReserved[4];                                          // CH: �����ֶ� | EN: Reserved
} IMVS_PF_FRONTEDWND_HANDLE_LIST;

// CH: ����ͼ��������Ϣ�ṹ | EN: Input image data information structure
typedef struct IMVS_PF_IMAGE_DATA_INFO__
{
	char * pImgData;       // CH: ͼ������ | EN: Image data
	int    iImgDataLen;    // CH: ͼ�����ݳ��� | EN: Image data length
	int    iWidth;         // CH: ͼ���� | EN: Image width
	int    iHeight;        // CH: ͼ��߶� | EN: Image height
	int    iImgFormat;     // CH: ͼ�����ظ�ʽ��1��Mono8 2��RGB�� | EN: Image pixel format (1:Mono8 2:RGB)
} IMVS_PF_IMAGE_DATA_INFO;

// CH: �û�����ͼ����Ϣ�ṹ | EN: User input image information structure
typedef struct IMVS_PF_INPUT_IMAGE_INFO__
{
	unsigned int nModuleID;                                       // CH: ģ��ID | EN: Module ID
	int          nDataType;                                       // CH: ͼ����������(0:����������, 1:·��) | EN: Image pixel format(0:Binary data, 1:Path)
	char         strImagePath[IMVS_PF_MAX_PATH_LENGTH];           // CH: ͼ���ļ�����·�� | EN: Image file absolute path
	IMVS_PF_IMAGE_DATA_INFO stImageDataInfo;                      // CH: ͼ������ | EN: Image data
    int          nIsP2PSend;                                      // CH: �Ƿ��Ե㷢������(0:NO, 1:YES) | EN: Is send data point to ponint 
    int          nIsWaitCopy;                                     // CH: �Ƿ�ȴ�ͼ�񿽱����(0:NO, 1:YES) | EN: Is wait copy image 
	unsigned int nReserved[2];                                    // CH: �����ֶ� | EN: Reserved
} IMVS_PF_INPUT_IMAGE_INFO;

// CH: ����ͨ��ģ�������������Ϣ�ṹ | EN: Communication module binary data settings information structure
typedef struct IMVS_PF_COMM_BINARY_DATA_INFO__
{
	int           nDeviceId;                                       // CH: �豸��� | EN: The device serial number
	int           nDataType;                                       // CH���������ͣ�1:�ַ��� 2:���� 3:���� 4:���������ݣ� | EN: Data type (1: string 2: int 3: float 4: Byte)
	int           nAddressId;                                      // CH: ��ַID | EN: The address id
	char *        pData;                                           // CH: ���������� | EN: The binary data
	unsigned int  nDataLenth;                                      // CH: ���������ݳ��� | EN: The length of binary data
} IMVS_PF_COMM_BINARY_DATA_INFO;

// CH: ������ͨģ�������������Ϣ�ṹ | EN: Normal module binary data settings information structure
typedef struct IMVS_PF_NORMAL_BINARY_DATA_INFO__
{
	unsigned int nModuleID;                                         // CH: ģ��ID | EN: Module ID
	char         strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH]; // CH: �������� | EN: Parameter name
	char *       pData;                                             // CH: ���������� | EN: The binary data
	unsigned int nDataLenth;                                        // CH: ���������ݳ��� | EN: The length of binary data
} IMVS_PF_NORMAL_BINARY_DATA_INFO;

// CH: ���ö�����������Ϣ�ṹ | EN: Binary data settings information structure
typedef struct IMVS_PF_SET_BINARY_DATA_INFO__
{
	unsigned int nModuleType;                                     // CH: ģ������(0: ��ͨģ��, 1: ͨ��ģ��) | EN: Module ID(0: Normal module, 1: Communication module)
	unsigned int nRecvWaitTime;                                   // CH: ���ճ�ʱ����λ��ms�� | EN: Receive time-out (in ms)
	IMVS_PF_COMM_BINARY_DATA_INFO   stCommBinaryData;             // CH: ͨ��ģ����������� | EN: The binary data of communication modules 
	IMVS_PF_NORMAL_BINARY_DATA_INFO stNormalBinaryData;           // CH: ��ͨģ����������� | EN: The binary data of normal modules 
	unsigned int nReserved[4];                                    // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SET_BINARY_DATA_INFO;

// CH: ��ȡ���������ݳ�����Ϣ�ṹ | EN: Binary data length getting information structure
typedef struct IMVS_PF_GET_BINARY_DATA_LEN_INFO__
{
	unsigned int nModuleID;                                         // [IN] CH: ģ��ID | EN: Module ID
	char         strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH]; // [IN] CH: �������� | EN: Parameter name
	unsigned int nRecvWaitTime;                                     // [IN] CH: ���ճ�ʱ����λ��ms�� | EN: Receive time-out (in ms)
	unsigned int nDataLength;                                       // [OUT] CH: ���������ݳ��� | EN: The length of the binary data
	unsigned int nReserved[4];                                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_GET_BINARY_DATA_LEN_INFO;

// CH: ��ȡ������������Ϣ�ṹ | EN: Binary data getting information structure
typedef struct IMVS_PF_GET_BINARY_DATA_INFO__
{
	unsigned int nModuleID;                                         // [IN] CH: ģ��ID | EN: Module ID
	char         strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH]; // [IN] CH: �������� | EN: Parameter name
	unsigned int nRecvWaitTime;                                     // [IN] CH: ���ճ�ʱ����λ��ms�� | EN: Receive time-out (in ms)
	unsigned int nMallocSize;                                       // [IN] CH: ����ռ� | EN: The allocated space
	char *       pBinaryData;                                       // [OUT] CH: ���������� | EN: Binary data
	unsigned int nDataLen;                                          // [OUT] CH: ���������ݳ��� | EN: The length of the binary data
	unsigned int nReserved[4];                                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_GET_BINARY_DATA_INFO;

// CH: ����������Ϣ�ṹ | EN: Import process information structure
typedef struct IMVS_PF_IMPORT_PROCESS_INFO__
{
	unsigned int nProcessID;                                   // CH: ����ID | EN: Process ID
	char         strProcName[IMVS_PF_MAX_PROCESS_NAME_LENGTH]; // CH: �������� | EN: Process name
	unsigned int nReserved[4];                                 // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMPORT_PROCESS_INFO;

// CH: ���ȡͼ��Ϣ�ṹ | EN: Camera collect information structure
typedef struct IMVS_PF_CAMERA_COLLECT_INFO__
{
    unsigned int nCameraID;                                    // CH: ���ID | EN: Camera ID
    unsigned int nFrameNum;                                    // CH: ͼ��֡�� | EN: Frame number
    char strCameraSN[IMVS_PF_CAMERA_MAX_SN_LEN];               // CH: ���SN | EN: Camera SN
	unsigned int nCollectStatus;							   // CH: ȡͼ״̬ | EN: Collect Status
    unsigned int nReserved[3];                                 // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CAMERA_COLLECT_INFO;

// CH: �������״̬��Ϣ�ṹ | EN: Camera connect status information structure
typedef struct IMVS_PF_CAMERA_CONNECT_STATUS_INFO__
{
	unsigned int nCameraID;                                    // CH: ���ID | EN: Camera ID
	unsigned int nConnectStatus;                               // CH: ����״̬ | EN: Connect Status
	char strCameraSN[IMVS_PF_CAMERA_MAX_SN_LEN];               // CH: ���SN | EN: Camera SN
	unsigned int nReserved[4];                                 // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CAMERA_CONNECT_STATUS_INFO;

// CH: ���������Ϣ�ṹ | EN: Camera information structure
typedef struct IMVS_PF_CAMERA_INFO__
{
    char strCameraName[IMVS_PF_CAMERA_MAX_NAME_LEN];           // CH: ������� | EN: Camera Name
    char strCameraSN[IMVS_PF_CAMERA_MAX_SN_LEN];               // CH: ���SN | EN: Camera SN
    unsigned int nReserved[4];                                 // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CAMERA_INFO;

// CH: �����Ϣ�б�ṹ | EN: Camera information list structure
typedef struct IMVS_PF_CAMERA_INFO_LIST__
{
    unsigned int nNum;                                          // CH: ������� | EN: Camera Number
    IMVS_PF_CAMERA_INFO astCameraInfo[IMVS_PF_CAMERA_MAX_NUM];  // CH: �����Ϣ | EN: Camera Info
    unsigned int nReserved[4];                                  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CAMERA_INFO_LIST;

// CH: ͨ��������Ϣ�ṹ | EN: Communication connect information structure
typedef struct IMVS_PF_COMMUNICATION_CONNECT_INFO__
{
    unsigned int nDeviceStatus;                                // CH: �豸״̬ | EN: Device Status
    unsigned int nDeviceID;                                    // CH: �豸ID | EN: Device ID
    unsigned int nReserved[4];                                 // CH: �����ֶ� | EN: Reserved
}IMVS_PF_COMMUNICATION_CONNECT_INFO;

/*************************************************************************
 * ģ�����ṹ�嶨��
 * Module results structure definition
 *************************************************************************/
// CH: ͼ��������Ϣ�ṹ | EN: Image information structure
typedef struct IMVS_PF_IMAGE_INFO__
{
    char * pImgData;       // CH: ͼ������ | EN: Image data
    int    iImgDataLen;    // CH: ͼ�����ݳ��� | EN: Image data length
    int    iWidth;         // CH: ͼ���� | EN: Image width
    int    iHeight;        // CH: ͼ��߶� | EN: Image height
    int    iImgFormat;     // CH: ͼ�����ظ�ʽ | EN: Image pixel format
    int    iReserved[4];   // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGE_INFO;

// CH: ͼ��Դģ��������Ϣ�ṹ | EN: Image source module data structure
typedef struct IMVS_PF_IMAGESOURCEMODULE_INFO__
{
	int                nFrameNum;       // CH: ֡�� | EN: Frame number
	int                nLostFrameCount; // CH: ��֡�� | EN: Number of frames lost
	int                nLostPacketCount;// CH: ������ | EN: Number of bags lost
	int                nGetCamfailCount;// CH: ��ȡ���ʧ�ܴ��� | EN: Count of failed camera acquisitions
    IMVS_PF_IMAGE_INFO stImgInfo;       // CH: ͼ������ | EN: Image data
	IMVS_PF_IMAGE_INFO stMono8ImgInfo;  // CH: mono8ͼ������ | Mono8 Image data
	char               strCurImagePath[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ��ǰ����ͼ��·�� | EN: Current image path
    int                iReserved[4];    // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGESOURCEMODULE_INFO;

// CH: ���ͼ��ģ��������Ϣ�ṹ | EN: Structure about information of output image module
typedef struct IMVS_PF_SAVEIMAGE_MODU_INFO__
{
    int    iModuStatu;     // CH: ģ��״̬ | EN: Module status
	char   strImgSavePath[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ͼ��洢·�� | EN: Image storage path
	char   strImgName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];     // CH: ͼ������ | EN: Image name
	char   strRenderImgSavePath[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ��Ⱦͼ��洢·�� | EN: Render Image storage path
	char   strRenderImageName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ��Ⱦͼ������ | EN: Render Image name
	IMVS_PF_IMAGE_INFO stOutImgInfo; // CH: ���ͼ������ | EN: Output image data
	int    iReserved[4];   // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SAVEIMAGE_MODU_INFO;

// CH: �����Ͷ�ά����Ϣ�ṹ | EN: Structure about information of floating-point 2D point
typedef struct IMVS_PF_2DPOINT_F__
{
    float    fPtX;         // CH: ��X���� | EN: X coordinate
    float    fPtY;         // CH: ��Y���� | EN: Y coordinate
} IMVS_PF_2DPOINT_F;

// CH: ���Ͷ�ά����Ϣ�ṹ | EN: Structure about information of integer 2D point
typedef struct IMVS_PF_2DPOINT_I__
{
    int    iPtX;         // CH: ��X���� | EN: X coordinate
    int    iPtY;         // CH: ��Y���� | EN: Y coordinate
} IMVS_PF_2DPOINT_I;

// CH: ������Ϣ�ṹ | EN: Region information structure
typedef struct IMVS_PF_REGION__
{
    float    fWidth;              // CH: ������ | EN: Region width
    float    fHeight;             // CH: ����߶� | EN: Region height
    float    fAngle;              // CH: ����Ƕ� | EN: Region angle
    IMVS_PF_2DPOINT_F stCenterPt; // CH: �������ĵ� | EN: Coordinates of regional center point
} IMVS_PF_REGION;

// CH: ����ƥ���Ե�� | EN: Structure about feature matching edge point
typedef struct IMVS_PATMATCH_POINT_INFO__
{
    float fMatchOutlineX;        // CH: ƥ��������X | EN: Matching contour point X
    float fMatchOutlineY;        // CH: ƥ��������Y | EN: Matching contour point Y
    float fMatchOutlineScore;    // CH: ƥ����������� | EN: Matching contour point score
    int   iMatchOutlineIndex;    // CH: ƥ����������� | EN: Matching contour point No.
}IMVS_PATMATCH_POINT_INFO;

// CH: ƥ��������Ϣ�ṹ | EN: Matching contour information structure
typedef struct IMVS_PF_MATCH_INFO__
{
    int   iPtNum;                             // CH: ƥ����������� | EN: The number of matching contour points
    IMVS_PATMATCH_POINT_INFO * pstPatMatchPt; // CH: ƥ�������� | EN: Matching feature points
} IMVS_PF_MATCH_INFO;

// CH: ƥ�����Ϣ�ṹ | EN: Matching point information structure
typedef struct IMVS_PF_MATCH_PT_INFO__
{
    float    fScore;              // CH: ƥ������ | EN: Matched point score
    float    fScale;              // CH: ƥ���߶� | EN: Matched point scale
    IMVS_PF_2DPOINT_F stMatchPt;  // CH: ƥ��� | EN: Matching point
} IMVS_PF_MATCH_PT_INFO;

// CH: ����ƥ�������Ϣ�ṹ | EN: Structure about feature matching information
typedef struct IMVS_PF_MATCH_BASE_INFO__
{
    int    iMatchTempNum;               // CH: ƥ��ģ���� | EN: Matching template No.
    int    iMatchStatu;                 // CH: ƥ��״̬ | EN: Matching status
    IMVS_PF_REGION stMatchBox;          // CH: ƥ��� | EN: Matching box
    IMVS_PF_MATCH_PT_INFO stMatchPt;    // CH: ƥ��� | EN: Matching point
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
}IMVS_PF_MATCH_BASE_INFO;

// CH: ��������ƥ��ģ����Ϣ�ṹ | EN: Structure about information of feature fast matching module
typedef struct IMVS_PF_FASTFEATUREMATCH_MODU_INFO__
{
    int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
    IMVS_PF_MATCH_INFO stMatchConInfo;  // CH: ƥ��������Ϣ | EN: Matching contour information
    int    iMatchNum;                   // CH: ƥ����� | EN: The number of matched modules
    IMVS_PF_MATCH_BASE_INFO * pstMatchBaseInfo; // CH: ����ƥ�������Ϣ | EN: Basic information of feature fast matching
	IMVS_PF_REGION stDetectRegion;      // CH: ������� | EN: Detection region
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_FASTFEATUREMATCH_MODU_INFO;

// CH: �߾���ƥ�����Ϣ�ṹ | EN: Structure about information of high precision matching point
typedef struct IMVS_PF_HPMATCH_PT_INFO__
{
    float    fScore;              // CH: ƥ������ | EN: Matching point score
    float    fScale;              // CH: ƥ���߶� | EN: Matching point scale
    float    fScaleX;             // CH: �߶�X | EN: Scale X
    float    fScaleY;             // CH: �߶�Y | EN: Scale Y
    IMVS_PF_2DPOINT_F stMatchPt;  // CH: ƥ��� | EN: Matching point
} IMVS_PF_HPMATCH_PT_INFO;

// CH: �߾�������ƥ�������Ϣ�ṹ | EN: Structure about basic information of feature high-precision matching
typedef struct IMVS_PF_HPMATCH_BASE_INFO__
{
    int    iMatchTempNum;               // CH: ƥ��ģ���� | EN: Matching template No.
    int    iMatchStatu;                 // CH: ƥ��״̬ | EN: Matching status
    IMVS_PF_REGION stMatchBox;          // CH: ƥ��� | EN: Matching box
    IMVS_PF_HPMATCH_PT_INFO stMatchPt;  // CH: ƥ��� | EN: Matching point
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
}IMVS_PF_HPMATCH_BASE_INFO;

// CH: �߾�������ƥ��ģ����Ϣ�ṹ | EN: Structure about information of feature high-precision matching
typedef struct IMVS_PF_HPFEATUREMATCH_MODU_INFO__
{
    int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
    IMVS_PF_MATCH_INFO stMatchConInfo;  // CH: ƥ��������Ϣ | EN: Matching contour information
    int    iMatchNum;                   // CH: ƥ����� | EN: The number of matched items
    IMVS_PF_HPMATCH_BASE_INFO * pstMatchBaseInfo; // CH: �߾�������ƥ�������Ϣ | EN: Basic information of feature high-precision matching
	IMVS_PF_REGION stDetectRegion;      // CH: ������� | EN: Detection region
	int    iMatchOutlineNum;            // CH: 
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_HPFEATUREMATCH_MODU_INFO;

// CH: ��������Ϣ�ṹ | EN: Contour point information structure
typedef struct IMVS_PF_CONTOUR_PT__
{
    int  iStatus;                  // CH: ������״̬ | EN: Contour point status
    IMVS_PF_2DPOINT_F stCirPt;     // CH: ������ | EN: Contour point
} IMVS_PF_CONTOUR_PT;

// CH: �����㼯��Ϣ�ṹ | EN: Contour point set information structure
typedef struct IMVS_PF_OUTLINE_PT__
{
    int    iPtNum;                      // CH: �������� | EN: The number of contour points
    IMVS_PF_CONTOUR_PT * pstContourPt;  // CH: ������ | EN: Contour point information
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_OUTLINE_PT;

// CH: ���Բ����Ϣ�ṹ | EN: Output arc information structure
typedef struct IMVS_PF_ANNULUS_CIRCLE_INFO__
{
	float  fOutputAnnulusCenterX;       // CH: ���Բ����X | EN: Output circle center point X
	float  fOutputAnnulusCenterY;       // CH: ���Բ����Y | EN: Output circle center point Y
	float  fOutputAnnulusInnerRadius;   // CH: ���Բ�ھ� | EN: Output circle inner radius
	float  fOutputAnnulusOuterRadius;   // CH: ���Բ�⾶ | EN: Output circle outer radius
	float  fOutputAnnulusStartAngle;    // CH: ���Բ��ʼ�Ƕ� | EN: Output circle start angle
	float  fOutputAnnulusAngleExtend;   // CH: ���Բչ���Ƕ� | EN: Output circle expand angle
} IMVS_PF_ANNULUS_CIRCLE_INFO;

// CH: Բ����ģ����Ϣ�ṹ | EN: Structure about information of circle search module
typedef struct IMVS_PF_CIRCLEFIND_MODU_INFO__
{
    int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
    float  fRadius;                     // CH: Բ�뾶 | EN: Circle radius
    float  fFitDiff;                    // CH: ������ | EN: Fitting error
    IMVS_PF_2DPOINT_F  stCirPt;         // CH: Բ�ĵ� | EN: Center point
    IMVS_PF_OUTLINE_PT stOutlinePts;    // CH: Բ������ | EN: Points on the circumstance
    IMVS_PF_REGION     stDetectRegion;  // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stAnnulusCirInfo; // CH: Բ����Ϣ | EN: Output arc information
	int    iCaliperBoxNum;              // CH: ���߿����� | EN: Number of caliper boxes
	IMVS_PF_REGION *   pstCaliperBox;   // CH: ���߿� | EN: Caliper boxes
	int    iCaliperDetectNum;           // CH: ���߿��������� | EN: Number of caliper detection areas
	IMVS_PF_REGION *   pstCaliperDetectRegion; // CH: ���߿����� | EN: Caliper detection areas
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiAnnulusCirInfo; // CH: ROIԲ����Ϣ | EN: ROI arc information
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CIRCLEFIND_MODU_INFO;

// CH: ֱ�߲���ģ����Ϣ�ṹ | EN: Structure about information of line search module
typedef struct IMVS_PF_LINEFIND_MODU_INFO__
{
    int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
    float  fAngle;                      // CH: ֱ�߽Ƕ� | EN: Linear tilt angle
    float  fFitDiff;                    // CH: ������ | EN: Coordinates of the line's start point
    IMVS_PF_2DPOINT_F    stStartPt;     // CH: ֱ����� | EN: Coordinates of the line's start point
    IMVS_PF_2DPOINT_F    stEndPt;       // CH: ֱ���յ� | EN: Coordinates of the line's end point
    IMVS_PF_OUTLINE_PT stOutlinePts;    // CH: ֱ�������� | EN: Information of the point on the line
    IMVS_PF_REGION     stDetectRegion;  // CH: ������� | EN: Detected region
	int    iCaliperBoxNum;              // CH: ���߿����� | EN: Number of caliper boxes
	IMVS_PF_REGION *   pstCaliperBox;   // CH: ���߿� | EN: Caliper boxes
	int    iCaliperDetectNum;           // CH: ���߿��������� | EN: Number of caliper detection areas
	IMVS_PF_REGION *   pstCaliperDetectRegion; // CH: ���߿����� | EN: Caliper detection areas
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_LINEFIND_MODU_INFO;

// CH: ��ͨ����Ϣ�ṹ | EN: Connected domain information structure
typedef struct IMVS_PF_CONNECT_DOMAINS_INFO__
{
	float fBlobAngle;                   // CH: ����Ƕ� | EN: Spindle angle
    float fPeriMeter;                   // CH: ��ͨ���ܳ� | EN: Connected domain circumstance
    float fLongAxis;                    // CH: ���� | EN: Long axis
    float fShortAxis;                   // CH: ���� | EN: Short axis
	float fAxisRatio;                   // CH: ��� | EN: Axis ratio
    float fCircularity;                 // CH: Բ�ζ� | EN: Circularity
    float fSquareness;                  // CH: ���ζ� | EN: Squareness
    float fScore;                       // CH: ���� | EN: Score
    float fWidth;                       // CH: ��С��Ӿ��ο�� | EN: Width of the smallest external rectangle
    float fHeight;                      // CH: ��С��Ӿ��θ߶� | EN: Height of the smallest external rectangle
    float fAngle;                       // CH: ��С��Ӿ��νǶ� | EN: Angle of the smallest external rectangle
    IMVS_PF_2DPOINT_F stCentroidPt;     // CH: ��С��Ӿ������ĵ� | EN: Center point of the smallest external rectangle
} IMVS_PF_CONNECT_DOMAINS_INFO;

// CH: Blob��������Ϣ�ṹ | EN: Blob contour point information
typedef struct IMVS_PF_BLOBOUTLINE_PT__
{
    int  iPtNum;                          // CH: �������� | EN: The number of blob contour points
    IMVS_PATMATCH_POINT_INFO * pstBlobPt; // CH: ������ | EN: Blob contour point
} IMVS_PF_BLOBOUTLINE_PT;

// CH: ����Blob������Ϣ�ṹ | EN: Single blob information structure
typedef struct IMVS_PF_SINGLEBLOB_INFO__
{
    int    iMonoStatu;                        // CH: ����״̬ | EN: Monomer status
    float  fArea;                             // CH: ��� | EN: Area of the blob
	IMVS_PF_2DPOINT_F    stCentroidPt;        // CH: ���ĵ� | EN: Centroid point coordinates
    IMVS_PF_CONNECT_DOMAINS_INFO stConnectDomain; // CH: ��ͨ����Ϣ | EN: Connected domain information
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
}IMVS_PF_SINGLEBLOB_INFO;

// CH: BLOB����ģ����Ϣ�ṹ | EN: Blob analysis information structure
typedef struct IMVS_PF_BLOBFIND_MODU_INFO__
{
    int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
	float  fTotalArea;                        // CH: ����� | EN: Total area of the blob
	int    iDetectNum;                        // CH: ���������� | EN: Number of detected region
    IMVS_PF_REGION *  pstDetectRegion;        // CH: ������� | EN: Detected region
    IMVS_PF_BLOBOUTLINE_PT  stBlobOutlinePt;  // CH: Blob������Ϣ | EN: Blob contour information
    IMVS_PF_IMAGE_INFO stBinaImage;           // CH: ��ֵ��ͼ�� | EN: Blob image
    IMVS_PF_IMAGE_INFO stBlobImage;           // CH: Blobͼ�� | EN: The number of blobs
    int    iBlobNum;                          // CH: BLOB���� | EN: Single blob information
    IMVS_PF_SINGLEBLOB_INFO * pstSingleBlobInfo; // CH: BLOB��Ϣ | EN: Blob information
	int    iAnnulusNum;                       // CH: ROIԲ������ | EN: Number of ROI arcs
	IMVS_PF_ANNULUS_CIRCLE_INFO * pstAnnulusCirInfo; // CH: ROIԲ����Ϣ | EN: ROI arc information
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_BLOBFIND_MODU_INFO;

// CH: ��Ե��Ϣ�ṹ | EN: Edge information structure
typedef struct IMVS_PF_EDGE_INFO__
{
    int    iEdgePloraty;                     // CH: ��Ե���� | EN: Edge polarity
    float  fEdgePos;                         // CH: ��Եλ�� | EN: The position of the edge
    IMVS_PF_2DPOINT_F stEdgePt;              // CH: ��Ե�� | EN: Edge point
} IMVS_PF_EDGE_INFO;

// CH: ֱ����Ϣ�ṹ | EN: Line information structure
typedef struct IMVS_PF_LINE_INFO__
{
    float fAngle;                           // CH: ֱ�߽Ƕ� | EN: Linear tilt angle
    IMVS_PF_2DPOINT_F stStartPt;            // CH: ֱ����� | EN: Line's start point
    IMVS_PF_2DPOINT_F stEndPt;              // CH: ֱ���յ� | EN: Line's end point
} IMVS_PF_LINE_INFO;

// CH: ���߱�Ե��Ϣ�ṹ | EN: Caliper edge information
typedef struct IMVS_PF_CALIPER_INFO__
{
    int    iEdgeStatu;                        // CH: ��Ե״̬ | EN: Edge status
    float  fScore;                            // CH: ���� | EN: Score
    float  fEdgePairWidth;                    // CH: ������� | EN: Width between the two lines
    IMVS_PF_EDGE_INFO stEdgeInfo0;            // CH: ��Ե0��Ϣ | EN: Information of points on line 0
    IMVS_PF_EDGE_INFO stEdgeInfo1;            // CH: ��Ե1��Ϣ | EN: Information of points on line 1
    IMVS_PF_LINE_INFO stEdgeLine0;            // CH: ��Ե0ֱ�� | EN: Line 0 information
    IMVS_PF_LINE_INFO stEdgeLine1;            // CH: ��Ե1ֱ�� | EN: Line 1 information
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
}IMVS_PF_CALIPER_INFO;

// CH: ���߹���ģ����Ϣ�ṹ | EN: Caliper module information structure
typedef struct IMVS_PF_CALIPER_MODU_INFO__
{
    int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
    IMVS_PF_REGION         stDetectRegion;    // CH: ������� | EN: Detected region
    int    iEdgeNum;                          // CH: ��Ե���� | EN: The number of caliper edges
    IMVS_PF_CALIPER_INFO * pstCalipInfo;      // CH: ���߱�Ե | EN: Caliper edge
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CALIPER_MODU_INFO;

// CH: ��Ե�����Ϣ�ṹ | EN: Caliper edge result details structure
typedef struct IMVS_PF_CALIPER_EDGE_INFO__
{
    int    iEdgeStatu;                        // CH: ��Ե״̬ | EN: Edge status
    float  fScore;                            // CH: ���� | EN: Score
    int    iEdgePloraty;                      // CH: ��Ե���� | EN: Edge polarity
    float  fEdgePos;                          // CH: ��Եλ�� | EN: Edge position
    IMVS_PF_2DPOINT_F stEdgePt;               // CH: ��Ե�� | EN: Coordinates of the point one edge line
    IMVS_PF_LINE_INFO stEdgeLine;             // CH: ��Եֱ�� | EN: Edge line information
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CALIPER_EDGE_INFO;

// CH: ��Ե����ģ����Ϣ�ṹ | EN: Structure about information of edge search module
typedef struct IMVS_PF_CALIPEREDGE_MODU_INFO__
{
    int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
    IMVS_PF_REGION stDetectRegion;            // CH: ������� | EN: Detected region
    int    iEdgeNum;                          // CH: ��Ե���� | EN: The number of edges
    IMVS_PF_CALIPER_EDGE_INFO * pstCalipEdge; // CH: ��Ե��Ϣ | EN: Caliper edge information
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CALIPEREDGE_MODU_INFO;

// CH: �������Ϣ�ṹ | EN: Result details of the distance between two edges
typedef struct IMVS_PF_EDGE_WIDTH_RES_INFO__
{
    int    iEdgeStatu;                        // CH: ��Ե״̬ | EN: Edge status
    float  fEdgeDis;                          // CH: ��Ե��� | EN: The distance between the two edges
    float  fScore;                            // CH: ���� | EN: Score
    int    iEdgePloraty0;                     // CH: ��Ե0���� | EN: Edge 0 polarity
    float  fEdgePos0;                         // CH: ��Ե0λ�� | EN: Edge 0 position
    int    iEdgePloraty1;                     // CH: ��Ե1���� | EN: Edge 1 polarity
    float  fEdgePos1;                         // CH: ��Ե1λ�� | EN: Edge 1 position
    IMVS_PF_2DPOINT_F stEdgePt0;              // CH: ��Ե��0 | EN: Points on line 0
    IMVS_PF_2DPOINT_F stEdgePt1;              // CH: ��Ե��1 | EN: Points on line 1
    IMVS_PF_LINE_INFO stEdgeLine0;            // CH: ��Եֱ��0 | EN: Line 0 information
    IMVS_PF_LINE_INFO stEdgeLine1;            // CH: ��Եֱ��1 | EN: Line 1 information
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
}IMVS_PF_EDGE_WIDTH_RES_INFO;

// CH: �����ģ����Ϣ�ṹ | EN: Structure about information of interval detection module
typedef struct IMVS_PF_EDGEWIDTHFIND_MODU_INFO__
{
    int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
    IMVS_PF_REGION    stDetectRegion;         // CH: ������� | EN: Detected region
    int    iEdgeNum;                          // CH: ��Ե���� | EN: The number of edges
    IMVS_PF_EDGE_WIDTH_RES_INFO * pstEdgeWidthResInfo; // CH: �������Ϣ�ṹ | EN: Details of the distance between edges
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_EDGEWIDTHFIND_MODU_INFO;

// CH: λ������ģ����Ϣ�ṹ | EN: Structure about information of position correction module
typedef struct IMVS_PF_FIXTURE_MODU_INFO__
{
	int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
    float  fBaseAngle;                        // CH: ��׼�Ƕ� | EN: Based angle
    float  fOperateAngle;                     // CH: ���нǶ� | EN: Operating angle
    IMVS_PF_2DPOINT_F stBasePt;               // CH: ��׼�� | EN: Datum point coordinates
    IMVS_PF_2DPOINT_F stOperatePt;            // CH: ���е� | EN: Operating point coordinates
	float  fBaseScaleX;                       // CH: ��׼�߶�X | EN: Datum scale X
	float  fBaseScaleY;                       // CH: ��׼�߶�Y | EN: Datum scale Y
	float  fRunScaleX;                        // CH: ���г߶�X | EN: Run scale X
	float  fRunScaleY;                        // CH: ���г߶�Y | EN: Run scale Y
	int  iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_FIXTURE_MODU_INFO;

// CH: ���ο���Ϣ�ṹ | EN: Rectangle information structure
typedef struct IMVS_PF_RECT_INFO__
{
    float    fWidth;                  // CH: ���ο�� | EN: Rectangle width
    float    fHeight;                 // CH: ���θ߶� | EN: Rectangle height
    float    fAngle;                  // CH: ���νǶ� | EN: Tilt angle of the rectangle
    IMVS_PF_2DPOINT_F stCentPt;       // CH: ���ĵ� | EN: The center point of the rectangle
} IMVS_PF_RECT_INFO;

// CH: ���μ��ģ�� | EN: Structure about information of rectangle detection module
typedef struct IMVS_PF_RECTFIND_MODU_INFO__
{
    int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
    int    iDetectStatu;                      // CH: ���״̬ | EN: Detection status
    IMVS_PF_RECT_INFO  stRect;                // CH: ���� | EN: Detected rectangle information
    IMVS_PF_OUTLINE_PT stOutlinePt;           // CH: ������ | EN: Contour point information
    IMVS_PF_REGION     stDetectRegion;        // CH: ������� | EN: Detcted region
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_RECTFIND_MODU_INFO;

// CH: ������Ϣ | EN: Vertex information structure
typedef struct IMVS_PF_PEAK_INFO__
{
    float  fPeakScore;                        // CH: ������� | EN: Vertex score
    int    iPeakPloraty;                      // CH: ���㼫�� | EN: Vertex polarity
    float  fPeakDist;                         // CH: ������� | EN: Distance between two vertex
    int    iPeakStatu;                        // CH: ����״̬ | EN: Vertex status
    IMVS_PF_2DPOINT_F stPeakPt;               // CH: ���� | EN: Vertex coordinates
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_PEAK_INFO;

// CH: ��Ե��Ϣ | EN: Edge information structure
typedef struct IMVS_PF_PEAKEDGE_INFO__
{
    int    iEdgeStatu;                        // CH: ��Ե״̬ | EN: Edge status
    float  fEdgeScore;                        // CH: ��Ե���� | EN: Edge score
    int    iEdgePloraty;                      // CH: ��Ե���� | EN: Edge polarity
    float  fEdgePos;                          // CH: ��Եλ�� | EN: The position of the edge
    IMVS_PF_2DPOINT_F stEdgePt;               // CH: ��Ե�� | EN: Edge point information
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_PEAKEDGE_INFO;

// CH: ������ģ�� | EN: Structure about information of vertex detection module
typedef struct IMVS_PF_PEAKFIND_MODU_INFO__
{
    int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
    IMVS_PF_PEAK_INFO     stPeakInfo;         // CH: ������Ϣ | EN: Vertex information
    IMVS_PF_REGION        stDetectRegion;     // CH: ������� | EN: Detected region
    int    iEdgeNum;                          // CH: ��Ե���� | EN: The number of edges
    IMVS_PF_PEAKEDGE_INFO * pstEdgeInfo;      // CH: ��Ե��Ϣ | EN: Edge information
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_PEAKFIND_MODU_INFO;

// CH: ��Ե�������ģ�� | EN: Structure about information of border intersection search module
typedef struct IMVS_PF_CALIPCORNER_MODU_INFO__
{
    int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
    float  fCornerAngle;                      // CH: ��Ե����Ƕ� | EN: Angle between line 1 and line 0
    IMVS_PF_2DPOINT_F  stCornerPt;            // CH: ��Ե���� | EN: Intersection coordinates of the two lines
    IMVS_PF_LINE_INFO  stCalipLine0;          // CH: ��Եֱ��0 | EN: Line 0 information
    IMVS_PF_LINE_INFO  stCalipLine1;          // CH: ��Եֱ��1 | EN: Line 1 information
    IMVS_PF_OUTLINE_PT stOutLine0;            // CH: ֱ��0������ | EN: Information about points on the line 0
    IMVS_PF_OUTLINE_PT stOutLine1;            // CH: ֱ��1������ | EN: Information about points on the line 1
    IMVS_PF_REGION     stDetectRegion1;       // CH: �������1 | EN: Information of the detected region 1
    IMVS_PF_REGION     stDetectRegion2;       // CH: �������2 | EN: Information of the detected region 2
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CALIPERCORNER_MODU_INFO;

// CH: ƽ���߲���ģ�� | EN: Structure about information of parallel line search module
typedef struct IMVS_PF_PAIRLINE_MODU_INFO__
{
    int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
    int    iDetectStatu;                      // CH: ���״̬ | EN: Detection status
    float  fLineWidth;                        // CH: ֱ�߿�� | EN: Width of the line
    IMVS_PF_LINE_INFO  stCalipLine0;          // CH: ��Եֱ��0 | EN: Information of line 0
    IMVS_PF_LINE_INFO  stCalipLine1;          // CH: ��Եֱ��1 | EN: Information of line 1
	IMVS_PF_LINE_INFO  stMidLine;             // CH: ��Ե���� | EN: Information of the two lines' midline
    IMVS_PF_OUTLINE_PT stOutLine0;            // CH: ֱ��0������ | EN: Coordinates of points on line 0
    IMVS_PF_OUTLINE_PT stOutLine1;            // CH: ֱ��1������ | EN: Coordinates of points on line 1
	IMVS_PF_OUTLINE_PT stMidOutLine;          // CH: ���������� | EN: Coordinates of points on the midline of the two lines
    IMVS_PF_REGION     stDetectRegion;        // CH: ������� | EN: Detected region
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_PAIRLINE_MODU_INFO;

// CH: ��Բ����ģ����Ϣ�ṹ | EN: Structure about information of line and circle distance measurement module
typedef struct IMVS_PF_L2CMEASURE_MODU_INFO__
{
    int    iModuStatu;                    // CH: ģ��״̬ | EN: Module status
    float  fAngle;                        // CH: �Ƕ� | EN: Angle between the vertical line (which connects the point and the line segment) and the X-coordinate (positive direction)
    float  fDist;                         // CH: ���� | EN: Vertical distance between the circle's center and the line
    float  fRadius;                       // CH: ����Բ�뾶 | EN: Radius of the measured circle
    IMVS_PF_2DPOINT_F stCentPt;           // CH: ����Բ�ĵ� | EN: Center point of the measured circle
    IMVS_PF_2DPOINT_F stMeasuStartPt;     // CH: ����ֱ����� | EN: The start point of the measured line
    IMVS_PF_2DPOINT_F stMeasuEndPt;       // CH: ����ֱ���յ� | EN: The end point of the measured line
	float             fLineAngle;         // CH: ����ֱ�߽Ƕ� | EN: The angle of measured line
    IMVS_PF_2DPOINT_F stIntersecPt1;      // CH: ����1 | EN: Interaction 1 information
    IMVS_PF_2DPOINT_F stIntersecPt2;      // CH: ����2 | EN: Interaction 2 information
    IMVS_PF_2DPOINT_F stFootPt;           // CH: ����� | EN: Foot point
	int nCaliperBox1Num;                  // CH: ���߼����1���� | EN: Number of caliper detection region 1
	IMVS_PF_REGION *  pstDetectRegion1;   // CH: ���߼����1 | EN: Detected region 1
	int nCaliperBox2Num;                  // CH: ���߼����2���� | EN: Number of caliper detection region 2
	IMVS_PF_REGION *  pstDetectRegion2;   // CH: ���߼����2 | EN: Detected region 2
    int    iReserved[4];                  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_L2CMEASURE_MODU_INFO;

// CH: ԲԲ����ģ����Ϣ�ṹ | EN: Structure about information of circle and circle distance measurement module
typedef struct IMVS_PF_C2CMEASURE_MODU_INFO__
{
    int    iModuStatu;                    // CH: ģ��״̬ | EN: Module status
    float  fAngle;                        // CH: �Ƕ� | EN: The angle between the connecting line of center points and X-coordinate (positive direction)
    float  fDist;                         // CH: ���� | EN: Center distance
    char   strPosRela[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: λ�ù�ϵ | EN: Position relationship of the two circles
    float  fRadius1;                      // CH: ����Բ1�뾶 | EN: Circle 1's radius
    float  fRadius2;                      // CH: ����Բ2�뾶 | EN: Circle 2's radius
    IMVS_PF_2DPOINT_F stCentPt1;          // CH: ����Բ1Բ�ĵ� | EN: Coordinates of the circle 1's center point
    IMVS_PF_2DPOINT_F stCentPt2;          // CH: ����Բ2Բ�ĵ� | EN: Coordinates of the circle 2's center point
    IMVS_PF_2DPOINT_F stIntersecPt1;      // CH: ����1 | EN: Coordinates of intersection point 1
    IMVS_PF_2DPOINT_F stIntersecPt2;      // CH: ����2 | EN: Coordinates of intersection point 2
	int nCaliperBox1Num;                // CH: ���߼����1���� | EN: Number of caliper detection region 1
	IMVS_PF_REGION *  pstDetectRegion1; // CH: ���߼����1 | EN: Detected region 1
	int nCaliperBox2Num;                // CH: ���߼����2���� | EN: Number of caliper detection region 2
	IMVS_PF_REGION *  pstDetectRegion2; // CH: ���߼����2 | EN: Detected region 2
    int    iReserved[4];                  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_C2CMEASURE_MODU_INFO;

// CH: ��Բ����ģ����Ϣ�ṹ | EN: Structure about information of point and circle distance measurement module
typedef struct IMVS_PF_P2CMEASURE_MODU_INFO__
{
    int    iModuStatu;                    // CH: ģ��״̬ | EN: Module status
    float  fAngle;                        // CH: �Ƕ� | EN: The angle between the line ( which connects the point and the center point) and X-coordinate (positive direction)
    float  fCenterDist;                   // CH: ���ľ��� | EN: Distance between the point and the center point
    float  fNearestDist;                  // CH: ������� | EN: The shortest distance between the point and the circle
    float  fFarDist;                      // CH: ��Զ���� | EN: The fastest distance between the point and the circle
    float  fRadius;                       // CH: ����Բ�뾶 | EN: Radius of the circle
    IMVS_PF_2DPOINT_F stCentPt;           // CH: ����Բ�ĵ� | EN: Center point coordinates
    IMVS_PF_2DPOINT_F stMeasuPt;          // CH: ������ | EN: Point coordinates
    int    iReserved[4];                  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_P2CMEASURE_MODU_INFO;

// CH: ���߲���ģ����Ϣ�ṹ | EN: Structure about information of point and line distance measurement module
typedef struct IMVS_PF_P2LMEASURE_MODU_INFO__
{
    int    iModuStatu;                    // CH: ģ��״̬ | EN: Module status
    float  fVertDist;                     // CH: ��ֱ���� | EN: The vertical distance between the point and the segment
    float  fNearestDist;                  // CH: ������� | EN: The shortest distance between the point and the segment
    float  fFarDist;                      // CH: ��Զ���� | EN: The farthest distance between the point and the segment
    float  fAngle;                        // CH: �Ƕ� | EN: Angle between the vertical line (between the point and the segment) and X-coordinate (positive direction)
    IMVS_PF_2DPOINT_F stBasePt;           // CH: ����� | EN: Foot point coordinates
    IMVS_PF_2DPOINT_F stMeasuPt;          // CH: ������ | EN: Measured point coordinates
    IMVS_PF_2DPOINT_F stStartPt;          // CH: ����ֱ����� | EN: Coordinates of the line segment's start point
    IMVS_PF_2DPOINT_F stEndPt;            // CH: ����ֱ���յ� | EN: Coordinates of the line segment's end point
	float  fLineAngle;                    // CH: ����ֱ�߽Ƕ� | EN: Angle of the line
    int    iReserved[4];                  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_P2LMEASURE_MODU_INFO;

// CH: ���߲���ģ����Ϣ�ṹ | EN: Structure about information of line and line distance measurement module
typedef struct IMVS_PF_L2LMEASURE_MODU_INFO__
{
    int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
    float  fDist;                       // CH: ���� | EN: Distance of lines
    float  fAbsDist;                    // CH: ���Ծ��� | EN: Absolute distance of the lines
    float  fAngle;                      // CH: �н� | EN: Included angle between the two lines
    IMVS_PF_2DPOINT_F stIntersecPt;     // CH: ���� | EN: Interaction point of the lines
    IMVS_PF_2DPOINT_F stStartPt1;       // CH: ����ֱ��1��� | EN: Start point coordinates of line 1
    IMVS_PF_2DPOINT_F stEndPt1;         // CH: ����ֱ��1�յ� | EN: End point coordinates of line 1
	float  fLine1Angle;                 // CH: ����ֱ��1�Ƕ� | EN: angle of line1
	float  fLine2Angle;                 // CH: ����ֱ��2�Ƕ� | EN: angle of line2
    IMVS_PF_2DPOINT_F stStartPt2;       // CH: ����ֱ��2��� | EN: Start point coordinates of line 2
    IMVS_PF_2DPOINT_F stEndPt2;         // CH: ����ֱ��2�յ� | EN: End point coordinates of line 2
	IMVS_PF_2DPOINT_F stShowAnglePt1;   // CH: �Ƕȱ�ʶ��1 | EN: Angle identification point 1
	IMVS_PF_2DPOINT_F stShowAnglePt2;   // CH: �Ƕȱ�ʶ��2 | EN: Angle identification point 2
	IMVS_PF_2DPOINT_F stShowAnglePt3;   // CH: �Ƕȱ�ʶ��3 | EN: Angle identification point 3
	IMVS_PF_2DPOINT_F stShowAnglePt4;   // CH: �Ƕȱ�ʶ��4 | EN: Angle identification point 4
	IMVS_PF_2DPOINT_F stShowAnglePt5;   // CH: �Ƕȱ�ʶ��5 | EN: Angle identification point 5
	int nCaliperBox1Num;                // CH: ���߼����1���� | EN: Number of caliper detection region 1
	IMVS_PF_REGION *  pstDetectRegion1; // CH: ���߼����1 | EN: Detected region 1
	int nCaliperBox2Num;                // CH: ���߼����2���� | EN: Number of caliper detection region 2
	IMVS_PF_REGION *  pstDetectRegion2; // CH: ���߼����2 | EN: Detected region 2
	int  iReserved[4];                  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_L2LMEASURE_MODU_INFO;

// CH: ������ģ����Ϣ�ṹ | EN: Structure about information of point to point distance measurement module
typedef struct IMVS_PF_P2PMEASURE_MODU_INFO__
{
    int    iModuStatu;                // CH: ģ��״̬ | EN: Module status
    float  fDist;                     // CH: ���� | EN: The distance between the two points
    float  fAngle;                    // CH: �Ƕ� | EN: Angle between the two points' connection line and the X-coordinate (positive direction)
    IMVS_PF_2DPOINT_F stMidPt;        // CH: �е� | EN: The midpoint of the two points
    IMVS_PF_2DPOINT_F stMeasuPt1;     // CH: ������1 | EN: Coordinates of the measured point 1
    IMVS_PF_2DPOINT_F stMeasuPt2;     // CH: ������2 | EN: Coordinates of the measured point 2
    int    iReserved[4];              // CH: �����ֶ� | EN: Reserved
} IMVS_PF_P2PMEASURE_MODU_INFO;

// CH: ��Ͻ����Ϣ�ṹ | EN: Fitting results details structure
typedef struct IMVS_PF_FIT_RES_INFO__
{
    int    iMatchPt;                  // CH: ƥ��� | EN: Matching point
    float  fFitDist;                  // CH: ��Ͼ��� | EN: Fitting distance
    IMVS_PF_2DPOINT_F stFitPt;        // CH: ��ϵ� | EN: Fitting point Coordinates
    int    iReserved[4];              // CH: �����ֶ� | EN: Reserved
} IMVS_PF_FIT_RES_INFO;

// CH: Բ���ģ����Ϣ�ṹ | EN: Structure about information of circle fitting module
typedef struct IMVS_PF_CIRCLEFIT_MODU_INFO__
{
    int    iModuStatu;                // CH: ģ��״̬ | EN: Module status
    int    iMatchNum;                 // CH: ƥ����� | EN: The number of matched points
    int    iFitStatus;                // CH: ���״̬ | EN: Fitting status
    float  fFitError;                 // CH: ������ | EN: Fitting error
    float  fRadius;                   // CH: Բ�뾶 | EN: Radius of the circle
    IMVS_PF_2DPOINT_F stCentPt;       // CH: Բ�ĵ� | EN: Center point coordinates
    int    iFitPtNum;                 // CH: ��ϵ��� | EN: The number of fitting points
    IMVS_PF_FIT_RES_INFO * pstCirfitResInfo; // CH: Բ��Ͻ�� | EN: Circle fitting result
    int    iReserved[4];              // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CIRCLEFIT_MODU_INFO;

// CH: ֱ�����ģ����Ϣ�ṹ | EN: Structure about information of line fitting module
typedef struct IMVS_PF_LINEFIT_MODU_INFO__
{
    int    iModuStatu;                // CH: ģ��״̬ | EN: Module status
    int    iMatchNum;                 // CH: ƥ����� | EN: The number of the points that meet requirements
    int    iFitStatus;                // CH: ���״̬ | EN: Fitting status
    float  fFitError;                 // CH: ������ | EN: Fitting errors
    IMVS_PF_LINE_INFO stOutLine;      // CH: ���ֱ�� | EN: Information of the output line
    int    iFitPtNum;                 // CH: ��ϵ��� | EN: Total number of the fitting points
    IMVS_PF_FIT_RES_INFO * pstLinefitResInfo; // CH: ����Ͻ�� | EN: Curve fitting result
    int    iReserved[4];              // CH: �����ֶ� | EN: Reserved
} IMVS_PF_LINEFIT_MODU_INFO;

// CH: ���Ȳ���ģ����Ϣ�ṹ | EN: Structure about information of brightness detection module
typedef struct IMVS_PF_INTENSITYMEASURE_MODU_INFO__
{
    int    iModuStatu;               // CH: ģ��״̬ | EN: Module status
    int    iMinVal;                  // CH: ��Сֵ | EN: The minimum value
    int    iMaxVal;                  // CH: ���ֵ | EN: The maximum value
    float  fAveVal;                  // CH: ��ֵ | EN: Average value
    float  fStdDevia;                // CH: ��׼�� | EN: Standard deviation
	float  fHistContrast;            // CH: �Աȶ� | EN: Contrast
    int    iHist[256];               // CH: ֱ��ͼ | EN: Histogram
    IMVS_PF_REGION stDetectRegion;   // CH: ������� | EN: Detected region
    int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_INTENSITYMEASURE_MODU_INFO;

// CH: ����ͳ��ģ����Ϣ�ṹ | EN: Structure about information of pixel statistics module
typedef struct IMVS_PF_PIXELCOUNT_MODU_INFO__
{
    int    iModuStatu;               // CH: ģ��״̬ | EN: Module status
    int    iPixelNum;                // CH: �������� | EN: The number of pixels
    float  fRatio;                   // CH: ���� | EN: Ratio
    IMVS_PF_REGION stDetectRegion;   // CH: ������� | EN: Detected region
    int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_PIXELCOUNT_MODU_INFO;

// CH: ֱ��ͼ��Ϣ | EN: Histogram information structure
typedef struct IMVS_PF_HIST_INFO__
{
    int    iPixelNum;                // CH: �������� | EN: The number of pixels
    int    iMinVal;                  // CH: ��Сֵ | EN: The minimum value
    int    iMaxVal;                  // CH: ���ֵ | EN: The maximum value
    int    iMidVal;                  // CH: ��ֵ | EN: Medium value
    int    iPeakVal;                 // CH: ��ֵ | EN: Peak value
    float  fMeanVal;                 // CH: ��ֵ | EN: Average value
    float  fStdDev;                  // CH: ��׼�� | EN: Standard deviation
	float  fHistContrast;            // CH: �Աȶ� | EN: Contrast
    int    iHist[256];               // CH: ֱ��ͼ | EN: Histogram
    int    iCumHist[256];            // CH: �ۻ�ֱ��ͼ | EN: Cumulative histogram
    int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_HIST_INFO;

// CH: ֱ��ͼ������Ϣ�ṹ | EN: Structure about information of histogram tool module
typedef struct IMVS_PF_HISTTOOL_MODU_INFO__
{
    int    iModuStatu;                   // CH: ģ��״̬ | EN: Module status
    IMVS_PF_HIST_INFO stHistInfo;        // CH: ֱ��ͼ��Ϣ | EN: Histogram information
    IMVS_PF_REGION    stDetectRegion;    // CH: ������� | EN: Detected region
    int    iReserved[4];                 // CH: �����ֶ� | EN: Reserved
} IMVS_PF_HISTTOOL_MODU_INFO;

// CH: ���δ���ģ�� | EN: Structure about information of geometry creation module
typedef struct IMVS_PF_GEOMETRYCREATE_MODU_INFO__
{
    int               iModuStatu;        // CH: ģ��״̬ | EN: Module status
    IMVS_PF_2DPOINT_F stOutPt;           // CH: ����� | EN: Outputted point coordinates
    IMVS_PF_LINE_INFO stOutLine;         // CH: ����� | EN: Outputted line information
    float             fRadius;           // CH: Բ�뾶 | EN: Radius
    IMVS_PF_2DPOINT_F stCirPt;           // CH: Բ�ĵ� | EN: Center point coordinates
	char strModuResult[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];  // CH: ģ���� | EN: Module result
    int               iReserved[4];      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_GEOMETRYCREATE_MODU_INFO;

// CH: ��ά������Ϣ�ṹ | EN: QR code result details structure
typedef struct IMVS_PF_2DCR_RES_INFO__
{
    int    iCodeStatu;               // CH: ��״̬ | EN: QR code status
	float  fPPM;                     // CH: PPM | EN: PPM
    char   strCodeInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ������Ϣ | EN: Encoding information
	int    iEstVersion;              // CH: �����汾 | EN: Evaluation version
	int    iCodeType;                // CH: ������ | EN: Code type
	int    iColorFlag;               // CH: ���Ա�־ | EN: Polarity flag
	int    iNerrors;                 // CH: ���������� | EN: Number of error code words
	int    iNumtemp;                 // CH: �Ѿ������� | EN: Number of corrected words
	float  fCodePosAngle;            // CH: ��Ƕ� | EN: Code angle
    IMVS_PF_RECT_INFO stRect;        // CH: ���ο� | EN: Information of the QR code rectangle
	IMVS_PF_2DPOINT_I stCodePos0;    // CH: ��ǵ�0 | EN: Code corner point 0
	IMVS_PF_2DPOINT_I stCodePos1;    // CH: ��ǵ�1 | EN: Code corner point 1
	IMVS_PF_2DPOINT_I stCodePos2;    // CH: ��ǵ�2 | EN: Code corner point 2
	IMVS_PF_2DPOINT_I stCodePos3;    // CH: ��ǵ�3 | EN: Code corner point 3
    int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
}IMVS_PF_2DCR_RES_INFO;

// CH: ��ά��ʶ��ģ����Ϣ�ṹ | EN: Structure about information of QR code recognition module
typedef struct IMVS_PF_2DBCR_MODU_INFO__
{
    int    iModuStatu;               // CH: ģ��״̬ | EN: Module status
    IMVS_PF_REGION stDetectRegion;   // CH: ������� | EN: Detected region
    int    iCodeNum;                 // CH: ����� | EN: The number of QR codes
    IMVS_PF_2DCR_RES_INFO * pst2DCRInfo; // CH: ��ά������Ϣ | EN: QR code information
    int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_2DBCR_MODU_INFO;

// CH: ��������Ϣ�ṹ | EN: Bar code result structure
typedef struct IMVS_PF_BCR_RES_INFO__
{
    int    iCodeStatu;               // CH: ��״̬ | EN: Barcode status
    int    iCodeType;                // CH: ������ | EN: Barcode type
    float  fCodeAngle;               // CH: ����Ƕ� | EN: Angle of the barcode
	float  fPPM;                     // CH: PPM | EN: PPM
    char   strCodeInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ������Ϣ | EN: Encoding information
    IMVS_PF_RECT_INFO stRectInfo;    // CH: ���ο���Ϣ | EN: Bar code rectangle information
    int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
}IMVS_PF_BCR_RES_INFO;

// CH: ����ʶ��ģ����Ϣ�ṹ | EN: Structure about information of bar code recognition module
typedef struct IMVS_PF_BCR_MODU_INFO__
{
    int    iModuStatu;               // CH: ģ��״̬ | EN: Module status
    IMVS_PF_REGION stDetectRegion;   // CH: ������� | EN: Detected region
    int    iCodeNum;                 // CH: ����� | EN: The number of barcodes
    IMVS_PF_BCR_RES_INFO * pstBCRInfo; // CH: ��������Ϣ | EN: Bar code information
    int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_BCR_MODU_INFO;

// CH: ���;��ο���Ϣ�ṹ | EN: Structure about information of integer rectangle
typedef struct IMVS_PF_RECT_INFO_I__
{
    int    iWidth;                  // CH: ���ο�� | EN: Rectangle width
    int    iHeight;                 // CH: ���θ߶� | EN: Rectangle height
    float  fAngle;                  // CH: ���νǶ� | EN: Tilt angle of the rectangle
    IMVS_PF_2DPOINT_I stCentPt;     // CH: ���ĵ� | EN: Coordinates of the rectangle's center point
} IMVS_PF_RECT_INFO_I;

// CH: �����;��ο���Ϣ�ṹ | EN: Structure of floating-point rectangle information
typedef struct IMVS_PF_RECT_INFO_F__
{
	float  fWidth;                  // CH: ���ο�� | EN: Rectangle width
	float  fHeight;                 // CH: ���θ߶� | EN: Rectangle Height
	float  fAngle;                  // CH: ���νǶ� | EN: Rectangle angle
	IMVS_PF_2DPOINT_F stCentPt;     // CH: ���ĵ� | EN: Coordinates of the rectangle's center point
} IMVS_PF_RECT_INFO_F;

// CH: �ַ�ʶ������Ϣ�ṹ | EN: Structure about information of character recognition module
typedef struct IMVS_PF_CHARRECON_RES_INFO__
{
	float fCharScore;                     // CH: ���� | EN: Score
	float fConfidence;                    // CH: ���Ŷ� | EN: Confidence
	float fCharBoxSkew;                   // CH: �ַ�������б�� | EN: The skew of character rectangle
	float fChar0Score;                    // CH: ��1���Ŷ��ַ����� | EN: Score of character 0
	float fChar1Score;                    // CH: ��2���Ŷ��ַ����� | EN: Score of character 1
	char  chChar0[IMVS_PF_CHAR_RES_SIZE]; // CH: ��1���Ŷ��ַ� | EN: Character 0
	char  chChar1[IMVS_PF_CHAR_RES_SIZE]; // CH: ��2���Ŷ��ַ� | EN: Character 1
	IMVS_PF_RECT_INFO_F stCharRect;       // CH: �ַ����� | EN: Character rectangle
} IMVS_PF_CHARRECON_RES_INFO;

// CH: �����ַ�ʶ������Ϣ�ṹ | EN: Structure about information of Single character recognition result
typedef struct IMVS_PF_OCR_RES_INFO__
{
	char   strTextInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];       // CH: ��һ���Ŷ��ַ���Ϣ | EN: First confidence text information
	char   strSecondTextInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: �ڶ����Ŷ��ַ���Ϣ | EN: Second confidence text information
	IMVS_PF_REGION stDetectRegion;                                // CH: ������� | EN: Detected region
	int    iCharNum;                                              // CH: �ַ����� | EN: Number of characters
	IMVS_PF_CHARRECON_RES_INFO * pstCharResInfo;                  // CH: �ַ������Ϣ | EN: Characters result information
} IMVS_PF_OCR_RES_INFO;

// CH: �ַ�ʶ��ģ����Ϣ�ṹ | EN: Structure about information of character recognition module
typedef struct IMVS_PF_OCR_MODU_INFO__
{
    int    iModuStatu;                    // CH: ģ��״̬ | EN: Module status
	int    iRecogResultNum;               // CH: ʶ�������� | EN: Number of results
	IMVS_PF_OCR_RES_INFO * pstOCRResInfo; // CH: �ַ�ʶ���� | EN: Character recognition results
    int    iReserved[4];                  // CH: �����ֶ� | EN: Reserved
} IMVS_PF_OCR_MODU_INFO;

// CH: VeriCode������Ϣ�ṹ | EN: Verification code result structure
typedef struct IMVS_PF_VERICODE_RES_INFO__
{
    char   strCodeInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ������Ϣ | EN: Encoding information
    IMVS_PF_RECT_INFO_F stVeriCodeRect;    // CH: ���ο� | EN: Information of the verification code's rectangle
    int    iReserved[4];                   // CH: �����ֶ� | EN: Reserved
} IMVS_PF_VERICODE_RES_INFO;

// CH: VeriCode��ģ����Ϣ�ṹ | EN: Structure about information of verification code module
typedef struct IMVS_PF_VERICODE_MODU_INFO__
{
    int    iModuStatu;                     // CH: ģ��״̬ | EN: Module status
    IMVS_PF_REGION      stDetectRegion;    // CH: ������� | EN: Detected region
    int    iCodeNum;                       // CH: ����� | EN: The number of verification codes
    IMVS_PF_VERICODE_RES_INFO * pstVeriCodeRes; // CH: VeriCode������Ϣ | EN: Verification code information
    int    iReserved[4];                   // CH: �����ֶ� | EN: Reserved
} IMVS_PF_VERICODE_MODU_INFO;

// CH: �궨��궨ģ����Ϣ�ṹ | EN: Calibration module information structure
typedef struct IMVS_PF_CALIBBOARDCALIB_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    int    iCalibStatus;               // CH: �궨״̬ | EN: Calibration status
    float  fCalibErr;                  // CH: �궨��� | EN: Calibration error
    float  fPixAccuracy;               // CH: ���ؾ��� | EN: Pixel accuracy
    IMVS_PF_2DPOINT_F stCalibOriPt;    // CH: �궨ԭ�� | EN: Calibration origin coordinates
	IMVS_PF_2DPOINT_F stCalibOriVecXPt;// CH: ����X���� | EN: Vector X coordinates
	IMVS_PF_2DPOINT_F stCalibOriVecYPt;// CH: ����Y���� | EN: Vector Y coordinates
    float  fPanX;                      // CH: ƽ��X | EN: The distance to translate to X-coordinate
    float  fPanY;                      // CH: ƽ��Y | EN: The distance to translate to Y-coordinate
    float  fRota;                      // CH: ��ת | EN: Rotation angle
    float  fScale;                     // CH: �߶� | EN: Scale
    float  fObliq;                     // CH: б�� | EN: Slope
    float  fWHRatio;                   // CH: ��߱� | EN: Aspect ratio
    int    iCalibPtNum;                // CH: �궨���� | EN: The number of calibration points
    IMVS_PF_2DPOINT_F * pstCalibPt;    // CH: �궨�� | EN: Calibration point coordinates
	IMVS_PF_REGION      stDetectRegion;// CH: ������� | EN: Detected region
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CALIBBOARDCALIB_MODU_INFO;

// CH: N��궨ģ����Ϣ�ṹ | EN: Structure about information of N-Point calibration module
typedef struct IMVS_PF_ALIGNCALIB_MODU_INFO__
{
	int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    int    iCalibStatus;               // CH: �궨״̬ | EN: Calibration status
	int    iCalibErrStatus;            // CH: �����궨״̬ | EN: Calibration Error Status
    float  fTransErr;                  // CH: �궨ƽ����� | EN: Calibration translation error
    float  fRotatErr;                  // CH: �궨��ת��� | EN: Calibration rotation error
    float  fPixAccuracy;               // CH: ���ؾ��� | EN: Pixel accuracy
	float  fPanX;                      // CH: ƽ��X | EN: The distance to translate to X-coordinate
	float  fPanY;                      // CH: ƽ��Y | EN: The distance to translate to Y-coordinate
	float  fRota;                      // CH: ��ת | EN: Rotation angle
	float  fScale;                     // CH: �߶� | EN: Scale
	float  fObliq;                     // CH: б�� | EN: Slope
	float  fWHRatio;                   // CH: ��߱� | EN: Aspect ratio
    int    iCalibIndex;                // CH: ��ǰ�궨�� | EN: The current calibration point index
    int    iCalibTotalNum;             // CH: �궨������ | EN: The total number of the calibration points
	IMVS_PF_2DPOINT_F * pstImagePt;    // CH: �궨���ص� | EN: Pixel point coordinates
    IMVS_PF_2DPOINT_F * pstWorldPt;    // CH: �궨����� | EN: Physical point coordinates
	IMVS_PF_2DPOINT_F   stRotCenterImgPt; // CH: ��ת��ͼ��� | EN: Rotating axis image points
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_ALIGNCALIB_MODU_INFO;

// CH: �궨������Ϣ�ṹ | EN: Structure of calibration world information
typedef struct IMVS_PF_CALIB_WORLD_INFO__
{
	float  fWorldAngle;                // CH: �궨����Ƕ� | EN: Calibration world angle
	IMVS_PF_2DPOINT_F stOutWorldPt;    // CH: ����� | EN: Outputted point coordinates
} IMVS_PF_CALIB_WORLD_INFO;

// CH: �궨ת��ģ����Ϣ�ṹ | EN: Structure about information of calibration conversion module
typedef struct IMVS_PF_CALIBTRANSFORM_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    float  fSinPixAccuracy;            // CH: �����ؾ��� | EN: Single pixel accuracy
	float  fPanX;                      // CH: ƽ��X | EN: The distance to translate to X-coordinate
	float  fPanY;                      // CH: ƽ��Y | EN: The distance to translate to Y-coordinate
	float  fRota;                      // CH: ��ת | EN: Rotation angle
	float  fScale;                     // CH: �߶� | EN: Scale
	float  fObliq;                     // CH: б�� | EN: Slope
	float  fWHRatio;                   // CH: ��߱� | EN: Aspect ratio
    int    iTransformNum;              // CH: ת������ | EN: The number of the converted points
	IMVS_PF_CALIB_WORLD_INFO * pstOutWorldInfo; // CH: �궨������Ϣ | EN: Calibration world information
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CALIBTRANSFORM_MODU_INFO;

// CH: ��λת��ģ����Ϣ�ṹ | EN: Structure about information of unit conversion module
typedef struct IMVS_PF_SCALETRANSFORM_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    float  fPixAccuracy;               // CH: �����ؾ��� | EN: Single pixel accuracy
    float  fTransformRes;              // CH: ת����� | EN: Conversion result
	float  fPixDist;                   // CH: ���ؾ��� | EN: Pixel distance
	float  fPanX;                      // CH: ƽ��X | EN: The distance to translate to X-coordinate
	float  fPanY;                      // CH: ƽ��Y | EN: The distance to translate to Y-coordinate
	float  fRota;                      // CH: ��ת | EN: Rotation angle
	float  fScale;                     // CH: �߶� | EN: Scale
	float  fObliq;                     // CH: б�� | EN: Slope
	float  fWHRatio;                   // CH: ��߱� | EN: Aspect ratio
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SCALETRANSFORM_MODU_INFO;

// CH: ����У��ģ����Ϣ�ṹ | EN: Structure about information of distortion correction module
typedef struct IMVS_PF_IMAGECORRECT_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stCorrectImg;   // CH: ���ͼ�� | EN: Corrected image information
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGECORRECT_MODU_INFO;

// CH: ��̬ѧ����ģ����Ϣ�ṹ | EN: Structure about information of morphology processing module
typedef struct IMVS_PF_IMAGEMORPH_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stMorphOutImg;  // CH: ���ͼ�� | EN: Outputted image information
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGEMORPH_MODU_INFO;

// CH: ͼ���ֵ��ģ����Ϣ�ṹ | EN: Image binarization module information structure
typedef struct IMVS_PF_BINARY_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stBinOutImg;    // CH: ���ͼ�� | EN: Binarization image information
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_BINARY_MODU_INFO;

// CH: ͼ���˲�ģ����Ϣ�ṹ | EN: Image filtering module information structure
typedef struct IMVS_PF_IMAGEFILTER_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stFilterOutImg; // CH: ���ͼ�� | EN: IOutputted image information
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGEFILTER_MODU_INFO;

// CH: ͼ����ǿģ����Ϣ�ṹ | EN: Structure about information of image enhancement module
typedef struct IMVS_PF_IMAGEENHANCE_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stEnhanceOutImg;// CH: ���ͼ�� | EN: Enhanced image information
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGEENHANCE_MODU_INFO;

// CH: ͼ������ģ����Ϣ�ṹ | EN: Structure about information of image arithmetics module
typedef struct IMVS_PF_IMAGEMATH_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stMathOutImg;   // CH: ���ͼ�� | EN: Outputted image information
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGEMATH_MODU_INFO;

// CH: ����������ģ����Ϣ�ṹ | EN: Structure about information of resolution accessment module
typedef struct IMVS_PF_IMAGESHARPNESS_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    float  fSharpness;                 // CH: ������ | EN: Image sharpness
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGESHARPNESS_MODU_INFO;

// CH: ͼ������ģ����Ϣ�ṹ | EN: Structure about information of image correction module
typedef struct IMVS_PF_IMAGEFIXTURE_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stFixOutImg;    // CH: ���ͼ�� | EN: Outputted image information
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGEFIXTURE_MODU_INFO;

// CH: ��ӰУ��ģ����Ϣ�ṹ | EN: Structure about information of shadow correction module
typedef struct IMVS_PF_SHADECORRECT_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stShadeImg;     // CH: ���ͼ�� | EN: Outputted image information
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SHADECORRECT_MODU_INFO;

// CH: ����任ģ����Ϣ�ṹ | EN: Structure about information of affine transformation module
typedef struct IMVS_PF_AFFINETRANSFORM_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stAffineImg;    // CH: ���ͼ�� | EN: Transformed image information
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_AFFINETRANSFORM_MODU_INFO;

// CH: Բ��������Ϣ�ṹ | EN: Ring information structure
typedef struct IMVS_PF_POLARREGION__
{
	float    fInnerRadius;            // CH: ��������ھ� | EN: Internal diameter
	float    fOuterRadius;            // CH: ��������⾶ | EN: External diameter
	float    fAngleSpan;              // CH: �������Ƕȷ�Χ | EN: Angle range
	float    fStartAngle;             // CH: ���������ʼ�Ƕ� | EN: Start angle
	IMVS_PF_2DPOINT_F stCenterPt;     // CH: ����������ĵ� | EN: Coordinates of the ring's center point
} IMVS_PF_POLARREGION;

// CH: Բ��չ��ģ����Ϣ�ṹ | EN: Structure about information of ring expandsion module
typedef struct IMVS_PF_POLARUNWARP_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO  stPolarImg;    // CH: ���ͼ�� | EN: Outputted image information
	IMVS_PF_POLARREGION stDetectRegion;// CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_POLARUNWARP_MODU_INFO;

// CH: ��ɫ��ȡģ����Ϣ�ṹ | EN: Structure about information of color extraction module
typedef struct IMVS_PF_COLOREXTRACT_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
	float  fTotalArea;                 // CH: �����   | EN: Total Area
    IMVS_PF_IMAGE_INFO stExtractImg;   // CH: ���ͼ�� | EN: Outputted image information
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_COLOREXTRACT_MODU_INFO;

// CH: ͨ����Ϣ�ṹ | EN: Channel information structure
typedef struct IMVS_PF_CHANNEL_INFO__
{
    int   iMin;                         // CH: ͨ����Сֵ | EN: Channel minimum value
    int   iMax;                         // CH: ͨ�����ֵ | EN: Channel maximum value
    float fAve;                         // CH: ͨ����ֵ | EN: Channel mean value
    float fStdDev;                      // CH: ͨ����׼�� | EN: Channel standard deviation
    int   iHist[256];                   // CH: ͨ��ֱ��ͼ | EN: Channel histogram
    int   iReserved[4];                 // CH: �����ֶ� | EN: Reserved
}IMVS_PF_CHANNEL_INFO;

// CH: ��ɫ����ģ����Ϣ�ṹ | EN: Structure about information of color measurement module
typedef struct IMVS_PF_COLORMEASURE_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_CHANNEL_INFO stChannel1;   // CH: ͨ��1��Ϣ | EN: Channel 1 information
    IMVS_PF_CHANNEL_INFO stChannel2;   // CH: ͨ��2��Ϣ | EN: Channel 2 information
    IMVS_PF_CHANNEL_INFO stChannel3;   // CH: ͨ��3��Ϣ | EN: Channel 3 information
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_COLORMEASURE_MODU_INFO;

// CH: ��ɫת��ģ����Ϣ�ṹ | EN: Structure about information of color conversion module
typedef struct IMVS_PF_COLORTRANSFORM_MODU_INFO__
{
    int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stColorTransOutImg;    // CH: ���ͼ�� | EN: Converted image information
    int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_COLORTRANSFORM_MODU_INFO;

// CH: �������ģ����Ϣ�ṹ | EN: Structure about information of condition detection module
typedef struct IMVS_PF_IF_MODU_INFO__
{
    int    iModuStatu;                          // CH: ģ��״̬ | EN: Module status
    int    iIfRes;                              // CH: Int�ͽ�� | EN: Integer result
    char   strIfRes[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: �ַ����ͽ�� | EN: String type result
    int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IF_MODU_INFO;

// CH: ��֧ģ����Ϣ�ṹ | EN: Branching module information structure
typedef struct IMVS_PF_BRANCH_MODU_INFO__
{
	int    iModuStatu;                          // CH: ģ��״̬ | EN: Module status
    int    iTransMark;                          // CH: �����־ | EN: Transformation mark
	int    iOutputForEnd;                       // CH: ��֧���������־ | EN: Branch end output flag
	char   strBranchMatch[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ƥ���֧ | EN: Matched module ID
    int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_BRANCH_MODU_INFO;

// CH: �߼�ģ����Ϣ�ṹ | EN: Logic module information structure
typedef struct IMVS_PF_AND_MODU_INFO__
{
    int    iModuStatu;                          // CH: ģ��״̬ | EN: Module status
    int    iBoolAndRes;                         // CH: ����BOOL | EN: Result of BOOL AND
    char   strBoolAndRes[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ����STRING | EN: Result of STRING AND
    int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_AND_MODU_INFO;

// CH: ��ʽ��ģ����Ϣ�ṹ | EN: Formatting module information structure
typedef struct IMVS_PF_FORMAT_MODU_INFO__
{
    int    iStatus;                             // CH: ״̬ | EN: Module status
    char   strFormatOut[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ��ʽ����� | EN: Formatted output
    int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_FORMAT_MODU_INFO;

// CH: ����������������Ϣ�ṹ | EN: Structure about information of calculation module output result
typedef struct IMVS_PF_CALCULATOR_RESULT_INFO__
{
	char            strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH];    // CH: ������� | EN: Result name
	int             nParamType;                                           // CH: �������:1���� 2������ | EN: Result type: 1-integer, 2-float
	int             nIntValue;                                            // CH: �������� | EN: Integer data
	float           fFloatValue;                                          // CH: ���������� | EN: Float data
} IMVS_PF_CALCULATOR_RESULT_INFO;

// CH: ��������ģ����Ϣ�ṹ | EN: Variable calculation module information structure
typedef struct IMVS_PF_CALCULATOR_MODU_INFO__
{
    int    iStatus;                             // CH: ״̬ | EN: Calculation status
    char   strCalculateOut[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ��������� | EN: Calculation result
	int    nOutResNum;                          // CH: ������� | EN: Number of output result
	IMVS_PF_CALCULATOR_RESULT_INFO * pstCalResInfo; // CH: ������ | EN: Output result
	int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CALCULATOR_MODU_INFO;

// CH: �ַ��Ƚ�ģ����Ϣ�ṹ | EN: Structure about information of character comparison module
typedef struct IMVS_PF_STRINGCOMPARE_MODU_INFO__
{
    int    iModuStatu;                          // CH: ģ��״̬ | EN: Module status
    int    iIndex;                              // CH: �ַ����� | EN: String index
    char   strStringMatch[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: �Ƚ��ַ� | EN: Inputted string
    int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_STRINGCOMPARE_MODU_INFO;

// CH: ���ģ������Ϣ�ṹ | EN: Structure about information of output module result
typedef struct IMVS_PF_OUTPUT_RESULT_INFO__
{
	char            strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH];    // CH: ������� | EN: Result name
	int             nParamType;                                           // CH: �������:1���� 2������ 3�ַ����� | EN: Result type: 1-integer, 2-float, 3-string
	int             nValueNum;                                            // CH: ģ��ֵ���� | EN: Number of module values
	int *           pIntValue;                                            // CH: �������� | EN: Integer data
	float *         pFloatValue;                                          // CH: ���������� | EN: Float data
	IMVS_PF_MODULE_STRING_VALUE * pstStringValue;                         // CH: �ַ��������� | EN: String data
} IMVS_PF_OUTPUT_RESULT_INFO;

// CH: �ű�ģ����Ϣ�ṹ | EN: Script module information structure
typedef struct IMVS_PF_SHELL_MODU_INFO__
{
    int    iModuStatu;                          // CH: ģ��״̬ | EN: Module status
    char   strResInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: �����ʾ | EN: Results
	int    nResultNum;                          // CH: ������� | EN: Number of results
	IMVS_PF_OUTPUT_RESULT_INFO * pstOutResInfo; // CH: �ű�ģ���� | EN: Script module result
    int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SHELL_MODU_INFO;

// CH: �㼯ģ����Ϣ�ṹ | EN: Structure about information of point set module
typedef struct IMVS_PF_POINTSET_MODU_INFO__
{
    int    iModuStatu;                          // CH: ģ��״̬ | EN: Module status
    int    iPtNum;                              // CH: ����� | EN: The number of points
    IMVS_PF_2DPOINT_F * pstPointSetPt;          // CH: �㼯 | EN: Point set information
    int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_POINTSET_MODU_INFO;

// CH: ��֧�ַ��Ƚ�ģ����Ϣ�ṹ | EN: Structure about information of string comparison module
typedef struct IMVS_PF_BRANCHSTRINGCPM_MODU_INFO__
{
    int    iModuStatu;                          // CH: ģ��״̬ | EN: Module status
	int    iOutputForEnd;                       // CH: ��֧���������־ | EN: Branch end output flag
    char   strBranchMatch[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ƥ���֧ | EN: Matched module ID
    char   strStringMatch[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ƥ���ַ� | EN: Received string information
    int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_BRANCHSTRINGCPM_MODU_INFO;

// CH: ֡ƽ��ģ����Ϣ�ṹ | EN: Structure about information of frame averaging module
typedef struct IMVS_PF_FRAMEMEAN_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    int    iImgNum;                    // CH: ��ͳ��ͼ���� | EN: The number of the counted images
    IMVS_PF_IMAGE_INFO stFrameMeanImg; // CH: ֡ƽ��ͼ�� | EN: Frame averaging image
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_FRAMEMEAN_MODU_INFO;

// CH: ͼ�����ģ����Ϣ�ṹ | EN: Structure about information of image combination module
typedef struct IMVS_PF_IMAGECOMBINEPROCESS_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stOutputImg;    // CH: ���ͼ�� | EN: Composite image information
    IMVS_PF_IMAGE_INFO stMidImg;       // CH: �м�ͼ�� | EN: Middle image information
    IMVS_PF_REGION stDetectRegion;     // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGECOMBINEPROCESS_MODU_INFO;

// CH: �ַ�ȱ����Ϣ�ṹ | EN: Structure about information of character defect
typedef struct IMVS_PF_MARK_DEFECT_INFO__
{
	int    iMarkStatu;                 // CH: �ַ�״̬ | EN: Whether the character is defective
	IMVS_PF_REGION stMarkBox;          // CH: �ַ��� | EN: Character box
} IMVS_PF_MARK_DEFECT_INFO;

// CH: �ַ�ȱ�ݼ��ģ����Ϣ�ṹ | EN: Structure about information of character bug detection module
typedef struct IMVS_PF_MARKINSP_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
	int    iMatchStatus;               // CH: ƥ��״̬ | EN: Match status
    int    iMarkBoxNum;                // CH: �ַ������ | EN: The number of character boxes
	IMVS_PF_MARK_DEFECT_INFO * pstMarkDefectInfo; // CH: �ַ�ȱ����Ϣ | EN: Character defect information
    IMVS_PF_REGION   stDetectRegion;   // CH: ������� | EN: Detected region
    int    iDefectNum;                 // CH: ȱ�ݸ��� | EN: The number of defects
    IMVS_PF_REGION * pstDefectBox;     // CH: ȱ�ݿ� | EN: Defective box information
	IMVS_PF_REGION   pstMatchRect;     // CH: ƥ��� | EN: Match rect information
    IMVS_PF_IMAGE_INFO stDefBinaryImg; // CH: ȱ�ݶ�ֵͼ�� | EN: Binary image information
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MARKINSP_MODU_INFO;

// CH: �������ģ����Ϣ�ṹ | EN: Structure about information of copy and filling module
typedef struct IMVS_PF_REGIONCOPY_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stOutputImg;    // CH: ���ͼ�� | EN: Outputted image information
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
	int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_REGIONCOPY_MODU_INFO;

// CH: ����궨ģ����Ϣ�ṹ | EN: Structure about information of distortion calibration module
typedef struct IMVS_PF_IMAGECALIB_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    int    iCalibStatu;                // CH: �궨״̬ | EN: Calibration status
    float  fCalibError;                // CH: �궨��� | EN: Calibration errors
	float  fEstError;                  // CH: ������� | EN: Estimation error
    IMVS_PF_IMAGE_INFO stOutputImg;    // CH: ���ͼ�� | EN: Outputted image information
    int    iCalibNum;                  // CH: �궨���� | EN: The number of calibration points
    IMVS_PF_2DPOINT_F * pstCalibPoint; // CH: �궨�� | EN: Calibration point coordinates
	IMVS_PF_REGION   stDetectRegion;   // CH: ������� | EN: Detected region
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGECALIB_MODU_INFO;

// CH: ͼ���һ��ģ����Ϣ�ṹ | EN: Structure about information of image normalization module
typedef struct IMVS_PF_IMAGENORMLIZE_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    IMVS_PF_IMAGE_INFO stOutputImg;    // CH: ���ͼ�� | EN: Outputted image information
    IMVS_PF_REGION   stDetectRegion;   // CH: ������� | EN: Detected region
	IMVS_PF_ANNULUS_CIRCLE_INFO stRoiArcInfo; // CH: ROIԲ�� | EN: ROI Arc
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGENORMLIZE_MODU_INFO;

// CH: ��ʱͳ��ģ����Ϣ�ṹ | EN: Structure about information of time-consuming statistics module
typedef struct IMVS_PF_TIMESTATISTIC_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    float  fTimeConsume;               // CH: ��ʱ | EN: Time consumed
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_TIMESTATISTIC_MODU_INFO;

// CH: �ı�����ģ����Ϣ�ṹ | EN: Structure about information of text storage module
typedef struct IMVS_PF_SAVETEXT_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
	char   strSavePath[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ����·�� | EN: Save path
	char   strFileName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: �ļ����� | EN: File name
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SAVETEXT_MODU_INFO;

// CH: ��������ģ����Ϣ�ṹ | EN: Structure about information of data receiving module
typedef struct IMVS_PF_READDATAS_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
	int    nResultNum;                 // CH: ������� | EN: Number of results
	IMVS_PF_OUTPUT_RESULT_INFO * pstOutResInfo; // CH: ��������ģ���� | EN: Script module result
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_READDATAS_MODU_INFO;

// CH: ��������ģ����Ϣ�ṹ | EN: Structure about information of data sending module 
typedef struct IMVS_PF_SENDDATAS_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    char   strSendDatas[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: �������� | EN: Data sent via the module
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SENDDATAS_MODU_INFO;

// CH: ���ӳ��ģ����Ϣ�ṹ | EN: Structure about information of camera mapping module
typedef struct IMVS_PF_CAMERAMAP_MODU_INFO__
{
    float  fScaleX;                 // CH: x������� | EN: Scale in X direction
    float  fScaleY;                 // CH: y������� | EN: Scale in Y direction
    int    iCalibStatus;            // CH: �궨״̬ | EN: Calibration status
	float  fPanX;                   // CH: ƽ��X | EN: The distance to translate to X-coordinate
	float  fPanY;                   // CH: ƽ��Y | EN: The distance to translate to Y-coordinate
	float  fRota;                   // CH: ��ת | EN: Rotation angle
	float  fScale;                  // CH: �߶� | EN: Scale
	float  fObliq;                  // CH: б�� | EN: Slope
	float  fWHRatio;                // CH: ��߱� | EN: Aspect ratio
    int    iReserved[4];            // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CAMERAMAP_MODU_INFO;

// CH: �����λģ����Ϣ�ṹ | EN: Structure about information of single point alignment module
typedef struct IMVS_PF_SINGLEPOINTALIGN_MODU_INFO__
{
    int    iModuStatu;              // CH: ģ��״̬ | EN: Module status
    float  fDeltaX;                 // CH: xƫ�� | EN: X-offset
    float  fDeltaY;                 // CH: yƫ�� | EN: Y-offset
    float  fDeltaTheta;             // CH: thetaƫ�� | EN: Theta-offset
    int    iReserved[4];            // CH: �����ֶ� | EN: Reserved
} IMVS_PF_SINGLEPOINTALIGN_MODU_INFO;

// CH: �㼯��λģ����Ϣ�ṹ | EN: Structure about information of point set alignment module
typedef struct IMVS_PF_MULTIPOINTALIGN_MODU_INFO__
{
    int    iModuStatu;              // CH: ��λ״̬ | EN: Module status
    float  fDeltaX;                 // CH: xƫ�� | EN: X-offset
    float  fDeltaY;                 // CH: yƫ�� | EN: Y-offset
    float  fDeltaTheta;             // CH: thetaƫ�� | EN: Theta-offset
    int    iReserved[4];            // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MULTIPOINTALIGN_MODU_INFO;

// CH: �߶�λģ����Ϣ�ṹ | EN: Structure about information of line alignment module
typedef struct IMVS_PF_LINEALIGN_MODU_INFO__
{
    int    iModuStatu;              // CH: ��λ״̬ | EN: Module status
    float  fDeltaX;                 // CH: xƫ�� | EN: X-offset
    float  fDeltaY;                 // CH: yƫ�� | EN: Y-offset
    float  fDeltaTheta;             // CH: thetaƫ�� | EN: Theta-offset
    int    iReserved[4];            // CH: �����ֶ� | EN: Reserved
} IMVS_PF_LINEALIGN_MODU_INFO;

// CH: ���������Ϣ�ṹ | EN: Detected region information structure
typedef struct IMVS_PF_OCRDLDETECT_REGION__
{
	int   iOptimalCharNum;              // CH: �����ַ����� | EN: Optimal number of characters
	float fOptimalTextConf;             // CH: �����ַ������Ŷ� | EN: Optimal string confidence level
	char  strOptimalText[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ����ַ�����Ϣ | EN: Optimal string information
    int   iRegionStatus;                // CH: �������״̬ | EN: Detected region status
    IMVS_PF_REGION stDetectRegion;      // CH: ������� | EN: Detected region information
} IMVS_PF_OCRDLDETECT_REGION;

// CH: ���ѧϰ�ַ�ʶ������Ϣ�ṹ | EN: Structure about information of DL character recognition result
typedef struct IMVS_PF_OCRDL_RESULT_INFO__
{
	int    iCharNum;              // CH: �ַ����� | EN: The number of characters
	float  fTextConf;             // CH: �ַ������Ŷ� | EN: String confidence level
	char   strChConfidence[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: �ַ����Ŷ� | EN: Character confidence level
	char   strRoiSeq[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];       // CH: ������ | EN: Detection serial number
	char   strFontInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];     // CH: �ַ�����Ϣ | EN: String information
} IMVS_PF_OCRDL_RESULT_INFO;

// CH: ���ѧϰ�ַ�ʶ��ģ����Ϣ�ṹ | EN: Structure about information of DL character recognition module
typedef struct IMVS_PF_OCRDL_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
    int    iOcrDLResNum;               // CH: �ַ�ʶ�������� | EN: The number of characters
    int    iDetectNum;                 // CH: ���������� | EN: The number of detected regions
	IMVS_PF_OCRDL_RESULT_INFO *  pstOcrDLResInfo;  // CH: �ַ�ʶ������Ϣ | EN: DL character recognition result information
	IMVS_PF_OCRDLDETECT_REGION * pstDetectRegion;  // CH: ������� | EN: Detected region
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_OCRDL_MODU_INFO;

// CH: ���ѧϰ�����Ϣ�ṹ | EN: Structure about information of DL class
typedef struct IMVS_PF_CNNFLAW_CLASS_INFO__
{
	int    iGrayValue;                 // CH: �Ҷ�ֵ | EN: Grayscale value
	char   strClassName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ������� | EN: Class name
} IMVS_PF_CNNFLAW_CLASS_INFO;

// CH: ���ѧϰͼ��ָ�ģ����Ϣ�ṹ | EN: Structure about information of DL image segmentation module
typedef struct IMVS_PF_CNNFLAW_MODU_INFO__
{
    int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
	int    iMinScore;                  // CH: ��С���� | EN: Minimum score
	int    iProbHist[256];             // CH: ����ֱ��ͼ | EN: Probability histogram
	int    iClassNum;                  // CH: ������� | EN: Number of class
	IMVS_PF_CNNFLAW_CLASS_INFO * pstClassInfo; // CH: �����Ϣ | EN: Class information
	IMVS_PF_IMAGE_INFO stScoreImg;     // CH: ����ͼ | EN: Probability image
	IMVS_PF_IMAGE_INFO stClassImg;     // CH: ���ͼ | EN: Class image
	int    iFlawImgNum;                // CH: ȱ�ݸ���ͼ���� | EN: Number of defect probability images
	IMVS_PF_IMAGE_INFO stFlawScoreImg[IMVS_PF_MAX_FLAW_SCORE_IMAGE_NUM]; // CH: ȱ�ݸ���ͼ | EN: Defect probability images
    IMVS_PF_REGION     stDetectRegion; // CH: ������� | EN: Detected region information
    int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CNNFLAW_MODU_INFO;

// CH: �ַ���λĿ����Ϣ�ṹ | EN: Structure of character locating result details
typedef struct IMVS_PF_CHARTARGET_INFO__
{
    float fTarConfidence;              // CH: Ŀ�����Ŷ� | EN: Confidence level of the character locating result
    int   iTarStatus;                  // CH: Ŀ��״̬ | EN: Whether the locating result meets requirements: 1-yes, other-no
    IMVS_PF_RECT_INFO_F stTargetRect;  // CH: Ŀ����Ϣ���� | EN: Rectangle box information
} IMVS_PF_CHARTARGET_INFO;

// CH: ���ѧϰ�ַ���λģ����Ϣ�ṹ | EN: Structure about information of DL character locating module
typedef struct IMVS_PF_CNNCHARDETECT_MODU_INFO__
{
    int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
    int    iTargetNum;                  // CH: Ŀ����� | EN: The number of located characters
    IMVS_PF_CHARTARGET_INFO * pstTargetInfo; // CH: Ŀ����Ϣ�ṹ | EN: Details of the character locating result
    IMVS_PF_REGION      stDetectRegion; // CH: ������� | EN: Detected region
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CNNCHARDETECT_MODU_INFO;

// CH: �����Ϣ�ṹ | EN: Category information structure
typedef struct IMVS_PF_CLASS_INFO__
{
    int   iCateLabels;    // CH: ����ǩ | EN: Category label
    float fProbability;   // CH: ������ | EN: Category probability
	char  strClassName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: ������� | EN: Category name
} IMVS_PF_CLASS_INFO;

// CH: ���ѧϰ����ģ����Ϣ�ṹ | EN: Structure about information of DL classification module
typedef struct IMVS_PF_CNNCLASSIFY_MODU_INFO__
{
    int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
    int    iClassNum;                   // CH: ������ | EN: The number of categories
	float  fConfidence;                 // CH: ���Ŷ� | EN: Confidence
    IMVS_PF_CLASS_INFO * pstClassInfo;  // CH: �����Ϣ | EN: Category information
    IMVS_PF_REGION       stDetectRegion;// CH: ������� | EN: Detected region
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CNNCLASSIFY_MODU_INFO;

// CH: Ŀ����Ϣ�ṹ | EN: Target information structure
typedef struct IMVS_PF_TARGET_INFO__
{
    int   iTarCategory;                // CH: Ŀ����� | EN: Target category
    float fTarConfidence;              // CH: Ŀ�����Ŷ� | EN: Target confidence level
    int   iTarStatus;                  // CH: Ŀ��״̬ | EN: Target status
	float fObjRadius;                  // CH: Ŀ��뾶 | EN: Target radius
	char  strClassName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: ������� | EN: Class name
    IMVS_PF_RECT_INFO_F stTargetRect;  // CH: Ŀ����Ϣ���� | EN: Rectangle box information
} IMVS_PF_TARGET_INFO;

// CH: ���ѧϰĿ����ģ����Ϣ�ṹ | EN: Structure about information of DL target detection module
typedef struct IMVS_PF_CNNDETECT_MODU_INFO__
{
    int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
    int    iTargetNum;                  // CH: Ŀ����� | EN: The number of targets
    IMVS_PF_TARGET_INFO * pstTargetInfo;// CH: Ŀ����Ϣ�ṹ | EN: Target information structure
    IMVS_PF_REGION      stDetectRegion; // CH: ������� | EN: Detected region
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CNNDETECT_MODU_INFO;

// CH: ���ַ���λĿ����Ϣ�ṹ | EN: Structure of single character locating result details
typedef struct IMVS_PF_SINGLECHARTARGET_INFO__
{
	float fTarConfidence;              // CH: Ŀ�����Ŷ� | EN: Confidence level of the character locating result
	int   iMarkStatus;                 // CH: �ַ�״̬ | EN: Character status
	char  strSingleCharInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: ���ַ���Ϣ | EN: Single character information
	IMVS_PF_RECT_INFO_F stTargetRect;  // CH: Ŀ����Ϣ���� | EN: Rectangle box information
} IMVS_PF_SINGLECHARTARGET_INFO;

// CH: �ı���Ϣ�ṹ | EN: Structure of text information
typedef struct IMVS_PF_TEXT_INFO__
{
	int   iTarStatus;                  // CH: Ŀ��״̬ | EN: Target status
	IMVS_PF_RECT_INFO_F stTextBox;     // CH: �ı�����Ϣ | EN: Text box information
} IMVS_PF_TEXT_INFO;

// CH: �ַ���Ϣ�ṹ | EN: Character information structure
typedef struct IMVS_PF_CHARACTER_INFO__
{
	int   iCharNum;                // CH: �ַ����� | EN: Number of characters
	float fTextConf;               // CH: �ַ������Ŷ� | EN: String confidence level
	char  strRoiSeq[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];  // CH: ������ | EN: Detection serial number
	char  strText[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: �ַ���Ϣ | EN: Character information
} IMVS_PF_CHARACTER_INFO;

// CH: ���ѧϰ���ַ����ģ����Ϣ�ṹ | EN: Structure about information of DL single character detection module
typedef struct IMVS_PF_CNNSINGLECHARDETECT_MODU_INFO__
{
	int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
	int    iTextNum;                    // CH: �ı���Ϣ���� | EN: The number of text information
	int    iTargetNum;                  // CH: Ŀ����� | EN: The number of located characters
	int    iCharInfoNum;                // CH: �ַ���Ϣ���� | EN: Number of character information
	IMVS_PF_TEXT_INFO * pstTextInfo;    // CH: �ı���Ϣ | EN: Text information
	IMVS_PF_SINGLECHARTARGET_INFO * pstTargetInfo; // CH: Ŀ����Ϣ�ṹ | EN: Details of the character locating result
	IMVS_PF_CHARACTER_INFO        * pstCharInfo;   // CH: �ַ���Ϣ�ṹ | EN: Character information structure
	IMVS_PF_REGION      stDetectRegion; // CH: ������� | EN: Detected region
	int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CNNSINGLECHARDETECT_MODU_INFO;

// CH: ���ѧϰѵ������ģ����Ϣ�ṹ | EN: Structure about information of DL training tool module
typedef struct IMVS_PF_CNNTRAINTOOL_MODU_INFO__
{
    int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
    int    iTrainProgress;              // CH: ѵ������ | EN: Training progress
    float  fTrainErr;                   // CH: ѵ����� | EN: Training error
    int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CNNTRAINTOOL_MODU_INFO;

// CH: ȱ�ݿ���Ϣ�ṹ | EN: Structure about information of defect box
typedef struct IMVS_PF_FLAWRECT_INFO__
{
	int    iCaliperStart;               // CH: ������ʼֵ | EN: Caliper start value
	int    iCaliperEnd;                 // CH: ������ֵֹ | EN: Caliper end value
	int    iDefectType;                 // CH: ȱ������ | EN: Type of defect
	float  fDefectSize;                 // CH: ȱ�ݳߴ� | EN: Size of defect
	float  fDefectArea;                 // CH: ȱ����� | EN: Area of defect
	IMVS_PF_RECT_INFO_F stFlawRect;     // CH: ȱ�ݿ� | EN: Defect box
} IMVS_PF_FLAWRECT_INFO;

// CH: ��Ե����Ϣ�ṹ | EN: Structure about information of edge point
typedef struct IMVS_PF_EDGEPOINT_INFO__
{
	int    iEdgePtStatu;                // CH: ��Ե��״̬ | EN: Edge point status
	IMVS_PF_2DPOINT_F stEdgePoint;      // CH: ��Ե�� | EN: Edge point
} IMVS_PF_EDGEPOINT_INFO;

// CH: ������Ϣ�ṹ | EN: Structure about information of caliper
typedef struct IMVS_PF_CALIPPOINT_INFO__
{
	int    iCalipPtStatu;               // CH: ����״̬ | EN: Caliper status
	IMVS_PF_2DPOINT_F stCalipPoint;     // CH: ������Ϣ | EN: Caliper information
} IMVS_PF_CALIPPOINT_INFO;

// CH: ȱ���ۺ���Ϣ�ṹ | EN: Structure about defect comprehensive information
typedef struct IMVS_PF_DEFECT_COMPRE_INFO__
{
	float    fMinWidth;                   // CH: ��С��� | EN: Minimum width
	float    fMaxWidth;                   // CH: ����� | EN: Maximum width
	float    fAverageWidth;               // CH: ƽ����� | EN: Average width
	float    fApproximateArea;            // CH: ������� | EN: Approximate area
} IMVS_PF_DEFECT_COMPRE_INFO;

// CH: Բ����Եȱ��ģ����Ϣ�ṹ | EN: Structure about information of arc edge defect module
typedef struct IMVS_PF_CIRCLEEDGEINSP_MODU_INFO__
{
	int    iModuStatu;                            // CH: ģ��״̬ | EN: Module status
	int    iFlawNum;                              // CH: ȱ�ݸ��� | EN: Number of defects
	int    iEdgePointNum;                         // CH: ��Ե����� | EN: Number of edge points
	int    iCalipIdeaPointNum;                    // CH: �������� | EN: Number of caliper
	float  fStandardRadius;                       // CH: �����׼Բ�뾶 | EN: Radius of output standard circle
	IMVS_PF_2DPOINT_F       stStandardCirPt;      // CH: �����׼Բ�ĵ� | EN: Center point of output standard circle
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo;    // CH: ȱ�ݿ���Ϣ | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePtInfo;      // CH: ��Ե����Ϣ | EN: Edge point information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;     // CH: ������Ϣ | EN: Caliper information
	IMVS_PF_ANNULUS_CIRCLE_INFO stAnnulusCirInfo; // CH: ���Բ��Ϣ | EN: Output circle information
	IMVS_PF_REGION              stDetectRegion;   // CH: ������� | EN: Detected region
	int    iReserved[4];                          // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CIRCLEEDGEINSP_MODU_INFO;

// CH: ֱ�߱�Եȱ��ģ����Ϣ�ṹ | EN: Structure about information of straight-line edge defect module
typedef struct IMVS_PF_LINEEDGEINSP_MODU_INFO__
{
	int    iModuStatu;                         // CH: ģ��״̬ | EN: Module status
	int    iFlawNum;                           // CH: ȱ�ݸ��� | EN: Number of defects
	int    iEdgePointNum;                      // CH: ��Ե����� | EN: Number of edge points
	int    iCalipIdeaPointNum;                 // CH: �������� | EN: Number of caliper
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo; // CH: ȱ�ݿ���Ϣ | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePtInfo;   // CH: ��Ե����Ϣ | EN: Edge point information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;  // CH: ������Ϣ | EN: Caliper information
	IMVS_PF_LINE_INFO         stStandardLine;  // CH: �����׼ֱ�� | EN: Output standard line
	IMVS_PF_REGION            stDetectRegion;  // CH: ������� | EN: Detected region
	int    iReserved[4];                       // CH: �����ֶ� | EN: Reserved
} IMVS_PF_LINEEDGEINSP_MODU_INFO;

// CH: Բ����ȱ��ģ����Ϣ�ṹ | EN: Structure about information of arc pair edge defect module
typedef struct IMVS_PF_CIRCLEEDGEPAIRINSP_MODU_INFO__
{
	int    iModuStatu;                            // CH: ģ��״̬ | EN: Module status
	int    iFlawNum;                              // CH: ȱ�ݸ��� | EN: Number of defects
	int    iEdge0PointNum;                        // CH: ��Ե��0���� | EN: Number of edge 0 points
	int    iEdge1PointNum;                        // CH: ��Ե��1���� | EN: Number of edge 1 points
	int    iCalipIdeaPointNum;                    // CH: �������� | EN: Number of caliper
	float  fStandardRadius0;                      // CH: �����׼Բ�뾶0 | EN: Radius of output standard circle 0
	float  fStandardRadius1;                      // CH: �����׼Բ�뾶1 | EN: Radius of output standard circle 1
	IMVS_PF_2DPOINT_F       stStandardCirPt0;     // CH: �����׼Բ�ĵ�0 | EN: Center point of output standard circle 0
	IMVS_PF_2DPOINT_F       stStandardCirPt1;     // CH: �����׼Բ�ĵ�1 | EN: Center point of output standard circle 1
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo;    // CH: ȱ�ݿ���Ϣ | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt0Info;     // CH: ��Ե��0��Ϣ | EN: Edge point 0 information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt1Info;     // CH: ��Ե��1��Ϣ | EN: Edge point 1 information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;     // CH: ������Ϣ | EN: Caliper information
	IMVS_PF_ANNULUS_CIRCLE_INFO stAnnulusCirInfo; // CH: ���Բ��Ϣ | EN: Output circle information
	IMVS_PF_REGION              stDetectRegion;   // CH: ������� | EN: Detected region
	IMVS_PF_DEFECT_COMPRE_INFO  stDefectCompreInfo; // CH: ȱ���ۺ���Ϣ | EN: Defect comprehensive information
	int    iReserved[4];                          // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CIRCLEEDGEPAIRINSP_MODU_INFO;

// CH: ֱ�߶�ȱ��ģ����Ϣ�ṹ | EN: Structure about information of straight-line pair edge defect module
typedef struct IMVS_PF_LINEEDGEPAIRINSP_MODU_INFO__
{
	int    iModuStatu;                         // CH: ģ��״̬ | EN: Module status
	int    iFlawNum;                           // CH: ȱ�ݸ��� | EN: Number of defects
	int    iEdge0PointNum;                     // CH: ��Ե��0���� | EN: Number of edge 0 points
	int    iEdge1PointNum;                     // CH: ��Ե��1���� | EN: Number of edge 1 points
	int    iCalipIdeaPointNum;                 // CH: �������� | EN: Number of caliper
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo; // CH: ȱ�ݿ���Ϣ | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt0Info;  // CH: ��Ե��0��Ϣ | EN: Edge point 0 information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt1Info;  // CH: ��Ե��1��Ϣ | EN: Edge point 1 information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;  // CH: ������Ϣ | EN: Caliper information
	IMVS_PF_LINE_INFO         stStandardLine0; // CH: �����׼ֱ��0 | EN: Output standard line 0
	IMVS_PF_LINE_INFO         stStandardLine1; // CH: �����׼ֱ��1 | EN: Output standard line 1
	IMVS_PF_REGION            stDetectRegion;  // CH: ������� | EN: Detected region
	IMVS_PF_DEFECT_COMPRE_INFO stDefectCompreInfo; // CH: ȱ���ۺ���Ϣ | EN: Defect comprehensive information
	int    iReserved[4];                       // CH: �����ֶ� | EN: Reserved
} IMVS_PF_LINEEDGEPAIRINSP_MODU_INFO;

// CH: ��׼���Բ���ֱ�������Ϣ�ṹ | EN: Structure about information of standard output circle and line
typedef struct IMVS_PF_STANDARD_LINEANDCIR_INFO__
{
	int     iCircleNum;                       // CH: �����׼Բ���� | EN: Number of output standard circle
	int     iLineNum;                         // CH: �����׼ֱ������ | EN: Number of output standard line
	float * pfStandardCirRadius;              // CH: �����׼Բ�뾶 | EN: Output standard circle radius
	IMVS_PF_2DPOINT_F * pstStandardCirPt;     // CH: �����׼Բ�ĵ� | EN: Output standard center point
	IMVS_PF_LINE_INFO * pstStandardLine;      // CH: �����׼ֱ�� | EN: Output standard line
} IMVS_PF_STANDARD_LINEANDCIR_INFO;

// CH: ��Եȱ�����ģ����Ϣ�ṹ | EN: Structure about information of edge defect combination
typedef struct IMVS_PF_EDGEINSPGROUP_MODU_INFO__
{
	int    iModuStatu;                         // CH: ģ��״̬ | EN: Module status
	int    iFlawNum;                           // CH: ȱ�ݸ��� | EN: Number of defects
	int    iEdgePointNum;                      // CH: ��Ե����� | EN: Number of edge points
	int    iCalipIdeaPointNum;                 // CH: �������� | EN: Number of caliper
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo; // CH: ȱ�ݿ���Ϣ | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePtInfo;   // CH: ��Ե����Ϣ | EN: Edge point information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;  // CH: ������Ϣ | EN: Caliper information
	IMVS_PF_STANDARD_LINEANDCIR_INFO stStandardLineAndCirInfo;    // CH: �����׼ֱ���Լ���׼Բ��Ϣ | EN: Standard output circle and line information
	int    iReserved[4];                       // CH: �����ֶ� | EN: Reserved
} IMVS_PF_EDGEINSPGROUP_MODU_INFO;

// CH: ��Ե��ȱ�����ģ����Ϣ�ṹ | EN: Structure about information of edge pair defect combination
typedef struct IMVS_PF_EDGEPAIRINSPGROUP_MODU_INFO__
{
	int    iModuStatu;                         // CH: ģ��״̬ | EN: Module status
	int    iFlawNum;                           // CH: ȱ�ݸ��� | EN: Number of defects
	int    iEdge0PointNum;                     // CH: ��Ե��0���� | EN: Number of edge 0 points
	int    iEdge1PointNum;                     // CH: ��Ե��1���� | EN: Number of edge 1 points
	int    iCalipIdeaPointNum;                 // CH: �������� | EN: Number of caliper
	IMVS_PF_FLAWRECT_INFO   * pstFlawRectInfo; // CH: ȱ�ݿ���Ϣ | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt0Info;  // CH: ��Ե��0��Ϣ | EN: Edge point 0 information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt1Info;  // CH: ��Ե��1��Ϣ | EN: Edge point 1 information
	IMVS_PF_CALIPPOINT_INFO * pstCalipPtInfo;  // CH: ������Ϣ | EN: Caliper information
	IMVS_PF_STANDARD_LINEANDCIR_INFO stStandardLineAndCirInfo;    // CH: �����׼ֱ���Լ���׼Բ��Ϣ | EN: Standard output circle and line information
	IMVS_PF_DEFECT_COMPRE_INFO stDefectCompreInfo; // CH: ȱ���ۺ���Ϣ | EN: Defect comprehensive information
	int    iReserved[4];                       // CH: �����ֶ� | EN: Reserved
} IMVS_PF_EDGEPAIRINSPGROUP_MODU_INFO;

// CH: ģ��ȱ�ݿ���Ϣ�ṹ | EN: Structure about information of model defect box
typedef struct IMVS_PF_MODEL_FLAWRECT_INFO__
{
	int    iCaliperStart;               // CH: ȱ�ݿ�����ʼ���� | EN: Defect caliper start index
	int    iCaliperEnd;                 // CH: ȱ�ݿ�����ֹ���� | EN: Defect caliper end index
	int    iDefectType;                 // CH: ȱ������ | EN: Type of defect
	float  fDefectSize;                 // CH: ȱ�ݳߴ� | EN: Size of defect
	float  fDefectArea;                 // CH: ȱ����� | EN: Area of defect
	float  fFlawLen;                    // CH: ȱ�ݳ��� | EN: Length of defect
	IMVS_PF_RECT_INFO_F stFlawRect;     // CH: ȱ�ݿ� | EN: Defect box
} IMVS_PF_MODEL_FLAWRECT_INFO;

// CH: ��Եģ�Ϳ�����Ϣ�ṹ | EN: Structure about information of edge model caliper
typedef struct IMVS_PF_EDGEFLAW_CALIPER_INFO__
{
	IMVS_PF_2DPOINT_F   stCalipPoint;   // CH: ���뿨�ߵ� | EN: Ideal caliper point
	IMVS_PF_RECT_INFO_F stCaliperRect;  // CH: ���߿� | EN: Caliper box
} IMVS_PF_EDGEFLAW_CALIPER_INFO;

// CH: ��Եģ��ȱ��ģ����Ϣ�ṹ | EN: Structure about information of edge model defect module
typedef struct IMVS_PF_EDGEFLAWINSP_MODU_INFO__
{
	int    iModuStatu;                             // CH: ģ��״̬ | EN: Module status
	int    iFlawNum;                               // CH: ȱ�ݸ��� | EN: Number of defects
	int    iEdgePointNum;                          // CH: ��Ե����� | EN: Number of edge points
	int    iCalipIdeaPointNum;                     // CH: �������� | EN: Number of caliper
	IMVS_PF_MODEL_FLAWRECT_INFO * pstFlawRectInfo; // CH: ȱ�ݿ���Ϣ | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePtInfo;       // CH: ��Ե����Ϣ | EN: Edge point information
	IMVS_PF_EDGEFLAW_CALIPER_INFO * pstCaliperInfo;// CH: ������Ϣ | EN: Caliper information
	int    iReserved[4];                           // CH: �����ֶ� | EN: Reserved
} IMVS_PF_EDGEFLAWINSP_MODU_INFO;

// CH: ��Ե��ģ�Ϳ�����Ϣ�ṹ | EN: Structure about information of edge pair model caliper
typedef struct IMVS_PF_EDGEFLAW_PAIR_CALIPER_INFO__
{
	IMVS_PF_2DPOINT_F   stIdeaEdgePoint0;    // CH: �����Ե��0 | EN: Ideal edge point 0
	IMVS_PF_2DPOINT_F   stIdeaEdgePoint1;    // CH: �����Ե��1 | EN: Ideal edge point 1
	IMVS_PF_RECT_INFO_F stCaliperRect;       // CH: ���߿� | EN: Caliper box
} IMVS_PF_EDGEFLAW_PAIR_CALIPER_INFO;

// CH: ��Ե��ģ�͹켣��Ϣ�ṹ | EN: Structure about information of edge pair model trajectory
typedef struct IMVS_PF_TRAJECTORY_INFO__
{
	int                 iCalTrajFlag;         // CH: �Ż��켣״̬ | EN: Optimize track status
	IMVS_PF_2DPOINT_F   stIdeaTrajPoint;      // CH: ����켣�� | EN: Ideal track point
	IMVS_PF_2DPOINT_F   stCalTrajPoint;       // CH: �Ż��켣�� | EN: Optimize track points
	IMVS_PF_RECT_INFO_F stIdeaTrajCaliper;    // CH: ����켣���߿� | EN: Ideal track caliper box
} IMVS_PF_TRAJECTORY_INFO;

// CH: ��Ե��ģ��ȱ��ģ����Ϣ�ṹ | EN: Structure about information of edge pair model defect module
typedef struct IMVS_PF_EDGEPAIRFLAWINSP_MODU_INFO__
{
	int    iModuStatu;                             // CH: ģ��״̬ | EN: Module status
	float  fMaxWidth;                              // CH: ����� | EN: Maximum width
	float  fMinWidth;                              // CH: ��С��� | EN: Minimum width
	float  fAvgWidth;                              // CH: ƽ����� | EN: Average width
	int    iPairNum;                               // CH: ��Ե������ | EN: Number of edge pairs
	int    iFlawNum;                               // CH: ȱ�ݸ��� | EN: Number of defects
	int    iEdgePointNum;                          // CH: ��Ե����� | EN: Number of edge points
	int    iCalipIdeaPointNum;                     // CH: �������� | EN: Number of caliper
	int    iTrajectNum;                            // CH: �켣��Ϣ���� | EN: Number of trajectory information
	float * pfEdgePairWidth;                       // CH: ��Ե�Կ�� | EN: Edge pair width
	IMVS_PF_MODEL_FLAWRECT_INFO * pstFlawRectInfo; // CH: ȱ�ݿ���Ϣ | EN: Defect box information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt0Info;      // CH: ��Ե��0��Ϣ | EN: Edge point 0 information
	IMVS_PF_EDGEPOINT_INFO  * pstEdgePt1Info;      // CH: ��Ե��1��Ϣ | EN: Edge point 1 information
	IMVS_PF_EDGEFLAW_PAIR_CALIPER_INFO * pstCaliperInfo; // CH: ������Ϣ | EN: Caliper information
	IMVS_PF_TRAJECTORY_INFO * pstTrajectInfo;      // CH: �켣��Ϣ | EN: Trajectory information
	int    iReserved[4];                           // CH: �����ֶ� | EN: Reserved
} IMVS_PF_EDGEPAIRFLAWINSP_MODU_INFO;

// CH: ����ͼ��������Ϣ�ṹ | EN: Structure about information of cache images
typedef struct IMVS_PF_IMAGEBUFFERMODULE_INFO__
{
	int                iModuStatu;     // CH: ģ��״̬ | EN: Module status
	int                nImgNum;        // CH: ����ͼ������ | EN: Number of cached images
	IMVS_PF_IMAGE_INFO stOutImgInfo[IMVS_PF_IMAGE_BUFFER_NUM];   // CH: ���ͼ������ | EN: Output images information
	int                iReserved[4];   // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGEBUFFERMODULE_INFO;

// CH: �Ҷ�ģ��ƥ�������Ϣ�ṹ | EN: Structure about basic information of grayscale model matching
typedef struct IMVS_PF_GMATCH_BASE_INFO__
{
	int    iMatchTempNum;               // CH: ƥ��ģ���� | EN: Number of match template
	int    iMatchStatu;                 // CH: ƥ��״̬ | EN: Match status
	char   strMatchModelName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ƥ��ģ������ | EN�� Name of match model
	IMVS_PF_REGION stMatchBox;          // CH: ƥ��� | EN: Match box
	IMVS_PF_MATCH_PT_INFO stMatchPt;    // CH: ƥ��� | EN: Match point
	IMVS_PF_REGION stDetectRegion;      // CH: ������� | EN: Detected region
	int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
}IMVS_PF_GMATCH_BASE_INFO;

// CH: �Ҷ�ģ��ƥ��ģ����Ϣ�ṹ | EN: Structure about information of grayscale model matching
typedef struct IMVS_PF_GRAYMATCH_MODU_INFO__
{
	int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
	int    iMatchNum;                   // CH: ƥ����� | EN: Number of matches
	IMVS_PF_GMATCH_BASE_INFO * pstMatchBaseInfo; // CH: ����ƥ�������Ϣ | EN: basic information of grayscale model matching
	int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_GRAYMATCH_MODU_INFO;

// CH: ��ɫʶ��ģ��������Ϣ�ṹ | EN: Structure about information of color recognition model sample
typedef struct IMVS_PF_COLORMODELSAMPLE_DATA_INFO__
{
	int     nNum;                       // CH: ģ�ͻ��������� | EN: Number of model or sample
	float * fData;                      // CH: ģ�ͻ��������� | EN: Data of model or sample
} IMVS_PF_COLORMODELSAMPLE_DATA_INFO;

// CH: ��ɫʶ������Ϣ�ṹ | EN: Structure about information of color recognition
typedef struct IMVS_PF_COLORRECOGNITION_RES_INFO__
{
	float   fColorScore;                                             // CH: ��ɫʶ����� | EN: Color recognition score
	char    strColorTypeName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: ��ɫʶ���������� | EN: Type name of color recognition
} IMVS_PF_COLORRECOGNITION_RES_INFO;

// CH: ��ɫʶ��ģ����Ϣ�ṹ | EN: Structure about information of color recognition module
typedef struct IMVS_PF_COLORRECOGNITION_MODU_INFO__
{
	int    iModuStatu;                                         // CH: ģ��״̬ | EN: Module status
	float  fConfidence;                                        // CH: ���Ŷ� | EN: Confidence
	float  fTopScore;                                          // CH: ��ѷ��� | EN: Top score
	char   strTopTypeName[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ���ƥ������ | EN: Top type name
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stModelHData;           // CH: ģ��Hͨ������ | EN: Model H channel data
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stModelSData;           // CH: ģ��Sͨ������ | EN: Model S channel data
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stModelIData;           // CH: ģ��Iͨ������ | EN: Model I channel data
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stSampleHData;          // CH: ����Hͨ������ | EN: Sample H channel data
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stSampleSData;          // CH: ����Sͨ������ | EN: Sample S channel data
	IMVS_PF_COLORMODELSAMPLE_DATA_INFO stSampleIData;          // CH: ����Iͨ������ | EN: Sample I channel data
	int    nColorDistResNum;                                   // CH: ��ɫʶ�������� | EN: Number of color recognition results
	IMVS_PF_COLORRECOGNITION_RES_INFO * pstColorDistResInfo;   // CH: ��ɫʶ���� | EN: Color recognition results
	IMVS_PF_REGION stDetectRegion;                             // CH: ������� | EN: Detected region
	int    iReserved[4];                                       // CH: �����ֶ� | EN: Reserved
} IMVS_PF_COLORRECOGNITION_MODU_INFO;

// CH: ͼ�����ģ����Ϣ�ṹ | EN: Structure about information of image correction
typedef struct IMVS_PF_IMAGECORRECTMANUAL_MODU_INFO__
{
	int    iModuStatu;                 // CH: ģ��״̬ | EN: Module status
	IMVS_PF_IMAGE_INFO stCorrectImg;   // CH: ���ͼ�� | EN: Output image
	int    iReserved[4];               // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMAGECORRECTMANUAL_MODU_INFO;

// CH: ���IOͨ��ģ����Ϣ�ṹ | EN: Structure about information of camera IO communication module
typedef struct IMVS_PF_CAMERAIOMODULE_INFO__
{
	int    iModuStatu;                                       // CH: ģ��״̬ | EN: Module status
	char   strResult[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];    // CH: ����ַ��� | EN: Result string
	int    iReserved[4];                                     // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CAMERAIOMODULE_INFO;

// CH: ��Դͨ����Ϣ�ṹ | EN: Structure about information of light channel
typedef struct IMVS_PF_LIGHTCHANNEL_INFO__
{
	int    iEnable;                                          // CH: ʹ�� | EN: Enable
	int    iBrightness;                                      // CH: ���� | EN: Brightness
	int    iLightState;                                      // CH: ��Դ״̬ | EN: Light state
	int    iEdgeType;                                        // CH: �ض��� | EN: Edge type
	int    iDurationTime;                                    // CH: ����ʱ�� | EN: Duration time
} IMVS_PF_LIGHTCHANNEL_INFO;

// CH: ��Դģ����Ϣ�ṹ | EN: Structure about information of light module
typedef struct IMVS_PF_LIGHTMODULE_INFO__
{
	int    iModuStatu;                                       // CH: ģ��״̬ | EN: Module status
	IMVS_PF_LIGHTCHANNEL_INFO stLightChannel1Info;           // CH: ͨ��1��Ϣ | EN: Channel 1 information
	IMVS_PF_LIGHTCHANNEL_INFO stLightChannel2Info;           // CH: ͨ��2��Ϣ | EN: Channel 2 information
	IMVS_PF_LIGHTCHANNEL_INFO stLightChannel3Info;           // CH: ͨ��3��Ϣ | EN: Channel 3 information
	IMVS_PF_LIGHTCHANNEL_INFO stLightChannel4Info;           // CH: ͨ��4��Ϣ | EN: Channel 4 information
	int    iReserved[4];                                     // CH: �����ֶ� | EN: Reserved
} IMVS_PF_LIGHTMODULE_INFO;

// CH: �ı��β���ģ����Ϣ�ṹ | EN: Structure about information of quadrangle find module
typedef struct IMVS_PF_QUADRANGEFIND_MODU_INFO__
{
	int    iModuStatu;                            // CH: ģ��״̬ | EN: Module status
	float  fFitDiff0;                             // CH: ��Եֱ��0������ | EN: The fit error of edge line 0
	float  fFitDiff1;                             // CH: ��Եֱ��1������ | EN: The fit error of edge line 1
	float  fFitDiff2;                             // CH: ��Եֱ��2������ | EN: The fit error of edge line 2
	float  fFitDiff3;                             // CH: ��Եֱ��3������ | EN: The fit error of edge line 3
	float  fAngle0;                               // CH: �н�0 | EN: Angle 0
	float  fAngle1;                               // CH: �н�1 | EN: Angle 1
	float  fAngle2;                               // CH: �н�2 | EN: Angle 2
	float  fAngle3;                               // CH: �н�3 | EN: Angle 3
	IMVS_PF_LINE_INFO stEdgeLine0;                // CH: ��Եֱ��0 | EN: Edge line 0
	IMVS_PF_LINE_INFO stEdgeLine1;                // CH: ��Եֱ��1 | EN: Edge line 1
	IMVS_PF_LINE_INFO stEdgeLine2;                // CH: ��Եֱ��2 | EN: Edge line 2
	IMVS_PF_LINE_INFO stEdgeLine3;                // CH: ��Եֱ��3 | EN: Edge line 3
	IMVS_PF_OUTLINE_PT stOutlinePts0;             // CH: ֱ��0������ | EN: The contour point of line 0
	IMVS_PF_OUTLINE_PT stOutlinePts1;             // CH: ֱ��1������ | EN: The contour point of line 1
	IMVS_PF_OUTLINE_PT stOutlinePts2;             // CH: ֱ��2������ | EN: The contour point of line 2
	IMVS_PF_OUTLINE_PT stOutlinePts3;             // CH: ֱ��3������ | EN: The contour point of line 3
	IMVS_PF_LINE_INFO  stDiagonalLine0;           // CH: �Խ���0 | EN: Diagonal 0
	IMVS_PF_LINE_INFO  stDiagonalLine1;           // CH: �Խ���1 | EN: Diagonal 1
	IMVS_PF_LINE_INFO  stMedianLine0;             // CH: ����0 | EN: Midline 0
	IMVS_PF_LINE_INFO  stMedianLine1;             // CH: ����1 | EN: Midline 1
	IMVS_PF_LINE_INFO  stAngleBisector0;          // CH: �ı��ζԱ߽�ƽ����0 | EN: Diagonal split line 0
	IMVS_PF_LINE_INFO  stAngleBisector1;          // CH: �ı��ζԱ߽�ƽ����1 | EN: Diagonal split line 1
	IMVS_PF_2DPOINT_F stVertexPoint0;             // CH: ����0 | EN: Vertex 0
	IMVS_PF_2DPOINT_F stVertexPoint1;             // CH: ����1 | EN: Vertex 1
	IMVS_PF_2DPOINT_F stVertexPoint2;             // CH: ����2 | EN: Vertex 2
	IMVS_PF_2DPOINT_F stVertexPoint3;             // CH: ����3 | EN: Vertex 3
	IMVS_PF_2DPOINT_F stDiagIntersectionPt;       // CH: �Խ��߽��� | EN: Diagonal intersection
	IMVS_PF_2DPOINT_F stMedianIntersectionPt;     // CH: �е��߽��� | EN: Midline intersection
	IMVS_PF_2DPOINT_F stCentralPoint;             // CH: ���ĵ� | EN: Center point
	IMVS_PF_2DPOINT_F stAngleBisectorIntersPoint; // CH: �Ա߽�ƽ���߽��� | EN: Diagonal split point
	IMVS_PF_REGION stDetectRegion0;               // CH: �������0 | EN: ROI0
	IMVS_PF_REGION stDetectRegion1;               // CH: �������1 | EN: ROI1
	IMVS_PF_REGION stDetectRegion2;               // CH: �������2 | EN: ROI2
	IMVS_PF_REGION stDetectRegion3;               // CH: �������3 | EN: ROI3
	int    iReserved[4];                          // CH: �����ֶ� | EN: Reserved
} IMVS_PF_QUADRANGEFIND_MODU_INFO;

// CH: ֱ�߲������ģ�� | EN: Structure about information of line find group module
typedef struct IMVS_PF_LINEFINDGROUP_MODU_INFO__
{
	int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
	int    iFitStatus;                        // CH: ���״̬ | EN: Fit status
	float  fFitScore;                         // CH: ������ | EN: Fit score
	IMVS_PF_LINE_INFO stOutLine;              // CH: ���ֱ�� | EN: Output line
	int    iMatchNum;                         // CH: ƥ����� | EN: Match number
	int    iFitPtNum;                         // CH: ��ϵ��� | EN: Fit point number
	IMVS_PF_FIT_RES_INFO * pstLinefitResInfo; // CH: ����Ͻ�� | EN: Line fit result
	int    iMinCirNum;                        // CH: ��С��Ӿ������� | EN: Number of minimum circumscribed rectangle
	IMVS_PF_RECT_INFO * pstMinCirRect;        // CH: ��С��Ӿ��� | EN: Minimum circumscribed rectangle
	int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_LINEFINDGROUP_MODU_INFO;

// CH: ��ֱ����������Ϣ | EN: Structure about information of multi-line output result
typedef struct IMVS_PF_MULTILINE_INFO__
{
	float fLineFitError;                      // CH: �������� | EN: Line fit error
	float fLineIntensity;                     // CH: �߶Աȶ�ǿ�� | EN: Line intensity
	float fCoverageScore;                     // CH: �����ʷ��� | EN: Coverage score
	int   iInliersNum;                        // CH: ��Ⱥ������ | EN: Group point number
	int   iLineIndex;                         // CH: �߶����� | EN: Line index
	IMVS_PF_LINE_INFO stOutputLine;           // CH: ���ֱ�� | EN: Output line
} IMVS_PF_MULTILINE_INFO;

// CH: ��Ե����Ϣ | EN: Structure about information of multi-line edge points
typedef struct IMVS_PF_MULTILINEEDGE_INFO__
{
	int   iEdgePolarity;                     // CH: ��Ե���� | EN: Edge polarity
	float fEdgeMagnitude;                    // CH: �ݶȷ�ֵ | EN: Edge magnitude
	float fEdgeOrientation;                  // CH: �ݶȷ��� | EN: Edge orientation
	float fEdgeDist;                         // CH: ��Ե���� | EN: Edge distance
	int   iEdgeStatus;                       // CH: ��Ե״̬ | EN: Edge status
	int   iEdgeCaliperIndex;                 // CH: ͶӰ�������� | EN: The index of edge caliper
	int   iEdgeLineIndex;                    // CH: �����߶����� | EN: The index of edge line
	IMVS_PF_2DPOINT_F stContourPt;           // CH: ������ | EN: Contour point
} IMVS_PF_MULTILINEEDGE_INFO;

// CH: ��ֱ�߲���ģ�� | EN: Structure about information of multi-line find module
typedef struct IMVS_PF_MULTILINEFIND_MODU_INFO__
{
	int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
	int    iLineNum;                          // CH: ֱ������ | EN: The number of lines
	IMVS_PF_MULTILINE_INFO * pstOutLineInfo;  // CH: ���ֱ�� | EN: Output lines
	int    iEdgePointNum;                     // CH: ��Ե������ | EN: The number of edge points
	IMVS_PF_MULTILINEEDGE_INFO * pstEdgeInfo; // CH: ��Ե����Ϣ | EN: Multi-line edge information
	IMVS_PF_REGION stDetectRegion;            // CH: ������� | EN: Detected region
	int    iCaliperDetectNum;                 // CH: ���߿��������� | EN: Number of caliper detection areas
	IMVS_PF_REGION *   pstCaliperDetectRegion; // CH: ���߿����� | EN: Caliper detection areas
	int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MULTILINEFIND_MODU_INFO;

// CH: ӳ��궨ģ�� | EN: Structure about information of mapping calibration module
typedef struct IMVS_PF_TWOIMGCALIB_MODU_INFO__
{
	int    iModuStatu;                       // CH: ģ��״̬ | EN: Module status
	float  fKx;                              // CH: ���X������� | EN: kx
	float  fKy;                              // CH: ���Y������� | EN: ky
	float  fMapError;                        // CH: ӳ����� | EN: Map error
	int    iImgCalibStatus1;                 // CH: ͼ��1�궨״̬ | EN: Image 1 calibration status
	int    iImgCalibStatus2;                 // CH: ͼ��2�궨״̬ | EN: Image 2 calibration status
	float  fPixelScale1;                     // CH: �����ؾ���1 | EN: Single-pixel accuracy 1
	float  fPixelScale2;                     // CH: �����ؾ���2 | EN: Single-pixel accuracy 2
	int    iCurCornersPointNum;              // CH: ��ǰ�ǵ����� | EN: Number of current corner points
	int    iObjCornersPointNum;              // CH: Ŀ��ǵ����� | EN: Number of target corner points
	int    iProCornersPointNum;              // CH: ӳ��ǵ����� | EN: Number of map corner points
	IMVS_PF_2DPOINT_F * pstCornersCurPoints; // CH: ��ǰ�ǵ� | EN: Current corner points
	IMVS_PF_2DPOINT_F * pstCornersObjPoints; // CH: Ŀ��ǵ� | EN: Target corner points
	IMVS_PF_2DPOINT_F * pstCornersProPoints; // CH: ӳ��ǵ� | EN: Map corner points	
	IMVS_PF_REGION      stDetectRegion1;     // CH: �������1 | EN: Detected region1
	IMVS_PF_REGION      stDetectRegion2;     // CH: �������2 | EN: Detected region2
	int    iReserved[4];                     // CH: �����ֶ� | EN: Reserved
} IMVS_PF_TWOIMGCALIB_MODU_INFO;

// CH: Nͼ��궨ģ�� | EN: Structure about information of N-Image calibration module
typedef struct IMVS_PF_NIMAGECALIB_MODU_INFO__
{
	int    iModuStatu;                       // CH: ģ��״̬ | EN: Module status
	int    iCalibStatus;                     // CH: �궨״̬ | EN: Calibration status
	int    iCalibErrStatus;                  // CH: �����궨���״̬ | EN:Calibration Error Status
	int    iRotDirectState;                  // CH: ��ת���� | EN: Rotate Direction
	int    iCornerPairsNum;                  // CH: λ����Ϣ���� | EN: Number of Corner Pairs Info
	int    iTransErrMaxPtsNum;               // CH: �����������Ӧ���� | EN: Number of Trans Error Max Points
	int    iRotErrMaxPtsNum;                 // CH: �����������Ӧ���� | EN: Number of Rotate Error Max Points
	int    iTransMotionErrPicIndex;          // CH: ����������ͼƬ���� | EN: Index of the picture which has the max error
	int    iRotMotionErrPicIndex;            // CH: ����������ͼƬ���� | EN: Index of the picture which has the max error
	int    iCurNum;                          // CH: ��ǰ���� | EN: Current number
	int    iTotalNum;                        // CH: ������ | EN: Total number
	float  fTransError;                      // CH: ƽ�ƹ���������� | EN: Translation estimation pixel error
	float  fTransWorldError;                 // CH: ƽ����ʵ������� | EN: Translation world pixel error
	float  fRotError;                        // CH: ��ת����������� | EN: Rotation estimation pixel error
	float  fRotWorldError;                   // CH: ��ת��ʵ������� | EN: Rotation world pixel error
	float  fRotateAngleError;                // CH: ��ת�Ƕ���� | EN: Rotate angle error
	float  fTransEstMax;                     // CH: ���������� | EN: Trans Max Error
	float  fTransErrWorldMax;                // CH: ��ʵ������ | EN: Trans World Max Error
	float  fRotErrMax;                       // CH: ���������� | EN: Rotate Max Error
	float  fRotErrWorldMax;                  // CH: ��ʵ������ | EN: Rotate World Max Error
	float  fTransMotionErrAvgTrans;          // CH: ƽ�ƹ�����ͼ���ƶ���������ƶ���֮���ƫ��(�������) | EN: Trans Motion Error Average Trans
	float  fTransMotionErrAvgScale;          // CH: ƽ�ƹ����е�ͼ��߶ȱ仯 | EN: Trans Motion Error Average Scale
	float  fTransMotionErrAvgRotate;         // CH: ƽ�ƹ����е�ͼ��֮����ת�仯�� | EN: Trans Motion Error Average Rotation
	float  fTransMotionErrMaxTrans;          // CH: ƽ�ƹ�����ͼ���ƶ���������ƶ���֮���ƫ��(�������) | EN: Trans Motion Error Max Trans
	float  fTransMotionErrMaxScale;          // CH: ƽ�ƹ����е�ͼ��߶ȱ仯 | EN: Trans Motion Error Max Scale
	float  fTransMotionErrMaxRotate;         // CH: ƽ�ƹ����е�ͼ��֮����ת�仯�� | EN: Trans Motion Error Max Rotation
	float  fRotMotionErrAvg;                 // CH: ƽ����� | EN: Rotate Motion Average Error
	float  fRotMotionErrMax;                 // CH: ������ | EN: Rotate Motion Max Error
	float  fMoveDirec;                       // CH: y�����x�����ƶ��� | EN: Move Ratio of Y Direction and X Direction
	IMVS_PF_2DPOINT_F stDirXVectorPoint;     // CH: ��������ϵx�������� | EN: X Vector of coordinate system
	IMVS_PF_2DPOINT_F stDirYVectorPoint;     // CH: ��������ϵy�������� | EN: Y Vector of coordinate system
	IMVS_PF_2DPOINT_F stRotateCenterPoint;   // CH: ��ת�������� | EN: Rotate center point coordinate
	IMVS_PF_2DPOINT_F stTransDirectError;    // CH: ƽ�Ʒ������ | EN: Rotate direction error
	IMVS_PF_2DPOINT_F * pOutImagePoint;      // CH: �켣�� | EN: Points of corner pairs
	IMVS_PF_REGION stDetectRegion;           // CH: ������� | EN: Detected region
	int    iReserved[4];                     // CH: �����ֶ� | EN: Reserved
} IMVS_PF_NIMAGECALIB_MODU_INFO;

// CH: ͼ��ƴ��ģ�� | EN: Structure about information of image stitching module
typedef struct IMVS_PF_IMGSTITCH_MODU_INFO__
{
	int    iModuStatu;                       // CH: ģ��״̬ | EN: Module status
	int    iCurNum;                          // CH: ��ǰ���� | EN: Current number
	int    iTotalNum;                        // CH: ������ | EN: Total number
	IMVS_PF_RECT_INFO * pstMinCirRect;       // CH: ��С��Ӿ��� | EN: Minimum circumscribed rectangle
	IMVS_PF_IMAGE_INFO stBinaryImgInfo;      // CH: ��ֵ��ͼ������ | EN: Binary image data
	int    iReserved[4];                     // CH: �����ֶ� | EN: Reserved
} IMVS_PF_IMGSTITCH_MODU_INFO;

// CH: ���α任ģ�� | EN: Structure about information of geometric transform module
typedef struct IMVS_PF_GEOMETRICTRANSFORM_MODU_INFO__
{
	int    iModuStatu;                       // CH: ģ��״̬ | EN: Module status
	IMVS_PF_IMAGE_INFO stOutputImgInfo;      // CH: ���ͼ������ | EN: Output image data
	int    iReserved[4];                     // CH: �����ֶ� | EN: Reserved
} IMVS_PF_GEOMETRICTRANSFORM_MODU_INFO;

// CH: ���ݼ���ģ����Ϣ�ṹ | EN: Structure about information of data set module
typedef struct IMVS_PF_DATASET_MODU_INFO__
{
	int    iModuStatu;                          // CH: ģ��״̬ | EN: Module status
	int    nResultNum;                          // CH: ������� | EN: Number of results
	IMVS_PF_OUTPUT_RESULT_INFO * pstOutResInfo; // CH: ���ݼ��Ͻ�� | EN: Data set module result
	int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_DATASET_MODU_INFO;

// CH: Э����װģ����Ϣ�ṹ | EN: Structure about information of protocol assemble module
typedef struct IMVS_PF_PROTOCOL_ASSEMBLE_MODU_INFO__
{
	int    iModuStatu;                       // CH: ģ��״̬ | EN: Module status
	char   strAssembleResult[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ��װ��� | EN: Assemble result
	char   strBinaryResult[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH];   // CH: ���������� | EN: Binary result
	int    iReserved[4];                     // CH: �����ֶ� | EN: Reserved
} IMVS_PF_PROTOCOL_ASSEMBLE_MODU_INFO;

// CH: Э�����ģ����Ϣ�ṹ | EN: Structure about information of protocol analysis module
typedef struct IMVS_PF_PROTOCOL_ANALYSIS_MODU_INFO__
{
	int    iModuStatu;                          // CH: ģ��״̬ | EN: Module status
	int    nResultNum;                          // CH: ������� | EN: Number of results
	IMVS_PF_OUTPUT_RESULT_INFO * pstOutResInfo; // CH: Э�������� | EN: Protocol analysis result
	int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_PROTOCOL_ANALYSIS_MODU_INFO;

// CH: Group�����Ϣ�ṹ | EN: Structure about information of group module result
typedef struct IMVS_PF_GROUP_RESULT_INFO__
{
	char            strParamName[IMVS_PF_MAX_MODULE_PARAMNAME_LENGTH];    // CH: ������� | EN: Result name
	int             nParamType;                                           // CH: �������:1���� 2������ 3�ַ����� | EN: Result type: 1-integer, 2-float, 3-string
	int             nValueNum;                                            // CH: ģ��ֵ���� | EN: Number of module values
	int *           pIntValue;                                            // CH: �������� | EN: Integer data
	float *         pFloatValue;                                          // CH: ���������� | EN: Float data
	IMVS_PF_MODULE_STRING_VALUE * pstStringValue;                         // CH: �ַ��������� | EN: String data
	IMVS_PF_MODULE_IMAGE_VALUE *  pstImageValue;                          // CH: ͼ���������� | EN: Image data
	IMVS_PF_MODULE_CHUNK_VALUE *  pstChunkValue;                          // CH: ������ | EN: Big data
} IMVS_PF_GROUP_RESULT_INFO;

// CH: Groupģ����Ϣ�ṹ | EN: Structure about information of group module
typedef struct IMVS_PF_GROUP_MODU_INFO__
{
	int    iModuStatu;                          // CH: ģ��״̬ | EN: Module status
	int    nResultNum;                          // CH: ������� | EN: Number of results
	IMVS_PF_GROUP_RESULT_INFO * pstGroupResInfo;// CH: Groupģ���� | EN: Group module result
	int    iReserved[4];                        // CH: �����ֶ� | EN: Reserved
} IMVS_PF_GROUP_MODU_INFO;

// CH: ͼ�ζ�λƥ�����Ϣ�ṹ | EN: Structure about information of graphic positioning matching point
typedef struct IMVS_PF_MARKMATCH_PT_INFO__
{
	float    fScore;              // CH: ƥ������ | EN: Matching point score
	float    fScaleX;             // CH: �߶�X | EN: Scale X
	float    fScaleY;             // CH: �߶�Y | EN: Scale Y
	IMVS_PF_2DPOINT_F stMatchPt;  // CH: ƥ��� | EN: Matching point
} IMVS_PF_MARKMATCH_PT_INFO;

// CH: ͼ�ζ�λ������Ϣ�ṹ | EN: Structure about basic information of graphic positioning
typedef struct IMVS_PF_MARKMATCH_BASE_INFO__
{
	int    iMatchStatu;                  // CH: ƥ��״̬ | EN: Matching status
	IMVS_PF_REGION stMatchBox;           // CH: ƥ��� | EN: Matching box
	IMVS_PF_MARKMATCH_PT_INFO stMatchPt; // CH: ƥ��� | EN: Matching point
	int    iReserved[4];                 // CH: �����ֶ� | EN: Reserved
}IMVS_PF_MARKMATCH_BASE_INFO;

// CH: ���ֱ����Ϣ�ṹ | EN: Structure about basic information of output line
typedef struct IMVS_PF_FIND_LINE_INFO__
{
	int    iLineStatus;                  // CH: ƥ��״̬ | EN: Matching status
	IMVS_PF_LINE_INFO stFindLineInfo;    // CH: ���ֱ����Ϣ | EN: Output line information
}IMVS_PF_FIND_LINE_INFO;

// CH: ͼ�ζ�λģ����Ϣ�ṹ | EN: Structure about information of graphic positioning module
typedef struct IMVS_PF_MARKFIND_MODU_INFO__
{
	int    iModuStatu;                  // CH: ģ��״̬ | EN: Module status
	IMVS_PF_MATCH_INFO stMatchConInfo;  // CH: ƥ��������Ϣ | EN: Matching contour information
	int    iMatchNum;                   // CH: ƥ����� | EN: The number of matched items
	IMVS_PF_MARKMATCH_BASE_INFO * pstMatchBaseInfo; // CH: ͼ�ζ�λƥ�������Ϣ | EN: Basic information of graphic positioning 
	IMVS_PF_FIND_LINE_INFO stFindLine0; // CH: ���ֱ��0 | EN: Output line 0
	IMVS_PF_FIND_LINE_INFO stFindLine1; // CH: ���ֱ��1 | EN: Output line 1
	IMVS_PF_FIND_LINE_INFO stFindLine2; // CH: ���ֱ��2 | EN: Output line 2
	IMVS_PF_FIND_LINE_INFO stFindLine3; // CH: ���ֱ��3 | EN: Output line 3
	IMVS_PF_REGION stDetectRegion;      // CH: ������� | EN: Detection region
	int    iReserved[4];                // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MARKFIND_MODU_INFO;

// CH: ����Blob��ǩ������Ϣ�ṹ | EN: Single blob label information structure
typedef struct IMVS_PF_SINGLEBLOBLABEL_INFO__
{
	int    iMonoStatu;                        // CH: ����״̬ | EN: Monomer status
	float  fArea;                             // CH: ��� | EN: Area of the blob
	IMVS_PF_2DPOINT_F    stCentroidPt;        // CH: ���ĵ� | EN: Centroid point coordinates
	IMVS_PF_CONNECT_DOMAINS_INFO stConnectDomain; // CH: ��ͨ����Ϣ | EN: Connected domain information
	int    iLabelValue;                       // CH: ��ǩֵ | EN: Label value
	char   strCateLabel[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ����ǩ | EN: Category label
	int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
}IMVS_PF_SINGLEBLOBLABEL_INFO;

// CH: Blob��ǩ����ģ����Ϣ�ṹ | EN: BLOB(Binary Large Object) labels analysis module information structure
typedef struct IMVS_PF_BLOBFINDLABELS_MODU_INFO__
{
	int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
	float  fTotalArea;                        // CH: ����� | EN: Total area of the blob
	int    iDetectNum;                        // CH: ���������� | EN: Number of detected region
	IMVS_PF_REGION *  pstDetectRegion;        // CH: ������� | EN: Detected region
	IMVS_PF_BLOBOUTLINE_PT  stBlobOutlinePt;  // CH: Blob������Ϣ | EN: Blob contour information
	IMVS_PF_IMAGE_INFO stBinaImage;           // CH: ��ֵ��ͼ�� | EN: Binary image
	IMVS_PF_IMAGE_INFO stBlobImage;           // CH: Blobͼ�� | EN: Blob image
	int    iBlobNum;                          // CH: BLOB���� | EN: The number of blobs
	IMVS_PF_SINGLEBLOBLABEL_INFO * pstSingleBlobInfo; // CH: BLOB��Ϣ | EN: Blob information
	int    iAnnulusNum;                       // CH: ROIԲ������ | EN: Number of ROI arcs
	IMVS_PF_ANNULUS_CIRCLE_INFO * pstAnnulusCirInfo; // CH: ROIԲ����Ϣ | EN: ROI arc information
	int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_BLOBFINDLABELS_MODU_INFO;

// CH: ������Ϣ�ṹ | EN: Structure about information of glue points
typedef struct IMVS_PF_GLUEPOINT_INFO__
{
	int    iGluePtStatus;               // CH: ����״̬ | EN: Glue point status
	IMVS_PF_2DPOINT_F stCalipPoint;     // CH: ���� | EN: Dots
} IMVS_PF_GLUEPOINT_INFO;

// CH: ·����ȡģ����Ϣ�ṹ | EN: Structure about information of glue path extraction module
typedef struct IMVS_PF_GLUEPATHCONDUCT_MODU_INFO__
{
	int    iModuStatu;                        // CH: ģ��״̬ | EN: Module status
	int    iGluePointNum;                     // CH: ������� | EN: The number of dots
	IMVS_PF_GLUEPOINT_INFO * pstGluePoints;   // CH: ������Ϣ | EN: Dots information
	int    iReserved[4];                      // CH: �����ֶ� | EN: Reserved
} IMVS_PF_GLUEPATHCONDUCT_MODU_INFO;

// CH: ���ѧϰ��������Ϣ�ṹ | EN: Deep learning code recognition details structure
typedef struct IMVS_PF_CNNCODERECG_RES_INFO__
{
	int    iCodeStatu;               // CH: ��״̬ | EN: Code status
	float  fPPM;                     // CH: PPM | EN: PPM
	char   strCodeInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ������Ϣ | EN: Encoding information
	int    iEstVersion;              // CH: �����汾 | EN: Evaluation version
	int    iCodeType;                // CH: ������ | EN: Code type
	float  fCodePosAngle;            // CH: ��Ƕ� | EN: Code angle
	IMVS_PF_RECT_INFO stRect;        // CH: ���ο� | EN: Information of the code rectangle
	IMVS_PF_2DPOINT_I stCodePos0;    // CH: ��ǵ�0 | EN: Code corner point 0
	IMVS_PF_2DPOINT_I stCodePos1;    // CH: ��ǵ�1 | EN: Code corner point 1
	IMVS_PF_2DPOINT_I stCodePos2;    // CH: ��ǵ�2 | EN: Code corner point 2
	IMVS_PF_2DPOINT_I stCodePos3;    // CH: ��ǵ�3 | EN: Code corner point 3
	int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
}IMVS_PF_CNNCODERECG_RES_INFO;

// CH: ��ȼ������Ϣ | EN: information of code grade module
typedef struct IMVS_PF_CNNCODEGRADE_RES_INFO__
{
	int iSymbolContrast;            // CH: ���ŶԱȶ� | EN: Symbolic contrast
	int iAxial;                     // CH: ���򲻾����� | EN: Axial unevenness
	int iGrid;                      // CH: ���񲻾����� | EN: Mesh unevenness
	int iModulation;                // CH: ģ������� | EN: Module uniformity
	int iFixedPatternDamage;        // CH: �̶��̶� | EN: The degree of fixation
	int iUnusedErrorCorrection;     // CH: δʹ�þ��� | EN: Error correction is not used
	int iPrintGrowthHor;            // CH: ˮƽ��ӡ���� | EN: Horizontal print scaling
	int iPrintGrowthVer;            // CH: ��ֱ��ӡ���� | EN: Vertical print scaling
	int iRmGrade;                   // CH: ���������� | EN: Reflectivity balance
	int iDecode;                    // CH: �������� | EN: Decoding score
	int iOverQuality;               // CH: �������ȼ� | EN: Total quality grade
	int iEdgeDetermination;
	int iMinReflectance;
	int iMinEdgeContrast;
	int iDecodability;
	int iDefects;
	int iQuietZone;
	float fScScore;                 // CH: ���ŶԱȶȷ��� | EN: Score of symbolic contrast
	float fAnScore;                 // CH: ��������Է��� | EN: Score of code shaft regulation
	float fGnScore;                 // CH: ��������Է��� | EN: Score of mesh unevenness
	float fModScore;                // CH: ģ������Է��� | EN: Score of module uniformity
	float fFpdScore;                // CH: �̶��̶ȷ��� | EN: Score of fixation degree
	float fUecScore;                // CH: δʹ�þ������ | EN: Score of unused error correction
	float fPghScore;                // CH: ˮƽ��ӡ�������� | EN: Score of horizontal print scaling
	float fPgvScore;                // CH: ��ֱ��ӡ�������� | EN: Score of vertical print scaling
	float fRmScore;                 // CH: �������������� | EN: Score of reflectivity balance
	float fEdgeScore;
	float fMinrScore;
	float fMineScore;
	float fDcdScore;
	float fDefScore;
	float fQzScore;
} IMVS_PF_CNNCODEGRADE_RES_INFO;

// CH: ���ѧϰ����ģ����Ϣ�ṹ | EN: Structure about information of deep learning code recognition module
typedef struct IMVS_PF_CNNCODERECG_MODU_INFO__
{
	int    iModuStatu;               // CH: ģ��״̬ | EN: Module status
	IMVS_PF_REGION stDetectRegion;   // CH: ������� | EN: Detected region
	int    iCodeNum;                 // CH: ����� | EN: The number of codes
	IMVS_PF_CNNCODERECG_RES_INFO * pstCNNCRInfo; // CH: ������Ϣ | EN: Code information
	int    iGradeNum;                // CH: ��ȼ����� | EN: Number of code levels
	IMVS_PF_CNNCODEGRADE_RES_INFO * pstCNNGradeResInfo; // CH: ��ȼ���Ϣ | EN: Code level information
	int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CNNCODERECG_MODU_INFO;

// CH: ���ѧϰͼ����������Ϣ�ṹ | EN: Deep learning image retrieval results structure
typedef struct IMVS_PF_CNNRETRIEVAL_RES_INFO__
{
	int    iImageIndex;               // CH: ͼ�������� | EN: Image index number
	float  fSimilarity;               // CH: ���ƶ� | EN: Similarity
	char   strClassLabel[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ����ǩ | EN: Category label
}IMVS_PF_CNNRETRIEVAL_RES_INFO;

// CH: ���ѧϰͼ�����ģ����Ϣ�ṹ | EN: Structure about information of deep learning image retrieval module
typedef struct IMVS_PF_CNNRETRIEVAL_MODU_INFO__
{
	int    iModuStatu;               // CH: ģ��״̬ | EN: Module status
	int    iClassNum;                // CH: ������� | EN: The number of class
	IMVS_PF_REGION stDetectRegion;   // CH: ������� | EN: Detected region
	int    iTopNum;                  // CH: ������� | EN: The number of results
	IMVS_PF_CNNRETRIEVAL_RES_INFO * pstCNNRetrievalInfo; // CH: ͼ����������Ϣ | EN: Image retrieval results information
	int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_CNNRETRIEVAL_MODU_INFO;

// CH: ��ά��ȼ������Ϣ | EN: information of QR code grade module
typedef struct IMVS_PF_2DGRADE_RES_INFO__
{
	int iSymbolContrast;            // CH: ���ŶԱȶ� | EN: Symbolic contrast
	int iAxial;                     // CH: ���򲻾����� | EN: Axial unevenness
	int iGrid;                      // CH: ���񲻾����� | EN: Mesh unevenness
	int iModulation;                // CH: ģ������� | EN: Module uniformity
	int iFixedPatternDamage;        // CH: �̶��̶� | EN: The degree of fixation
	int iUnusedErrorCorrection;     // CH: δʹ�þ��� | EN: Error correction is not used
	int iPrintGrowthHor;            // CH: ˮƽ��ӡ���� | EN: Horizontal print scaling
	int iPrintGrowthVer;            // CH: ��ֱ��ӡ���� | EN: Vertical print scaling
	int iRmGrade;                   // CH: ���������� | EN: Reflectivity balance
	int iDecode;                    // CH: �������� | EN: Decoding score
	int iOverQuality;               // CH: �������ȼ� | EN: Total quality grade
	float fScScore;                 // CH: ���ŶԱȶȷ��� | EN: Score of symbolic contrast
	float fAnScore;                 // CH: ��������Է��� | EN: Score of code shaft regulation
	float fGnScore;                 // CH: ��������Է��� | EN: Score of mesh unevenness
	float fModScore;                // CH: ģ������Է��� | EN: Score of module uniformity
	float fFpdScore;                // CH: �̶��̶ȷ��� | EN: Score of fixation degree
	float fUecScore;                // CH: δʹ�þ������ | EN: Score of unused error correction
	float fPghScore;                // CH: ˮƽ��ӡ�������� | EN: Score of horizontal print scaling
	float fPgvScore;                // CH: ��ֱ��ӡ�������� | EN: Score of vertical print scaling
	float fRmScore;                 // CH: �������������� | EN: Score of reflectivity balance
	char strCodeInfo[IMVS_PF_MAX_MODULE_RESVALUE_LENGTH]; // CH: ������Ϣ | EN: Encoding information
	IMVS_PF_REGION stDetectRegion;  // CH: ������� | EN: Detected region
} IMVS_PF_2DGRADE_RES_INFO;

// CH: ��ά��ȼ�ģ����Ϣ�ṹ | EN: Structure about information of QR code grade module
typedef struct IMVS_PF_2DGRADE_MODU_INFO__
{
	int    iModuStatu;               // CH: ģ��״̬ | EN: Module status
	int    iCodeNum;                 // CH: ��ά������ | EN: The number of codes
	IMVS_PF_2DGRADE_RES_INFO * pst2DGradeResult;    // CH: ��ά��ȼ������Ϣ | EN: QR code level result information
	int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
} IMVS_PF_2DGRADE_MODU_INFO;

// CH: ȱ�ݶԱ�ģ����Ϣ�ṹ | EN: Structure about information of inspect module
typedef struct IMVS_PF_INSPECT_MODU_INFO__
{
	int iModuStatus;              // CH: ģ��״̬ | EN: Module status
	int * iInspectStatus;           // CH: ȱ��״̬ | EN: Inspect status
	int iDetectRoiNum;            // CH: ���ROI���� | EN: The number of detect area
	int iMatchStatus;             // CH: ƥ��״̬ | EN: Match Status
	float * fInspectScore;          // CH: ȱ�ݷ��� | EN: Inspect Score
	IMVS_PF_REGION * stMatchBox;    // CH: ƥ��� | EN: Matching box
	IMVS_PF_REGION * stDetectBox;    // CH: ����� | EN: Detect box
	int    iReserved[4];             // CH: �����ֶ� | EN: Reserved
}IMVS_PF_INSPECT_MODU_INFO;

typedef struct IMVS_PF_MULTIFUSION_MODU_INFO__
{
	int iModuStatus;                      // CH: ģ��״̬ | EN: Module status
	int iImageNum;                        // CH: ͼƬ���� | EN: Image Number
	int iImageWidth;                      // CH: ͼ���� | EN: Image Width
	int iImageHeight;                     // CH: ͼ��߶� | EN: Image Height
	IMVS_PF_IMAGE_INFO stAlbedoImage;     // CH: ����ͼ�� | EN: Albedo Image
	IMVS_PF_IMAGE_INFO stShadingImage;    // CH: ��Ӱͼ�� | EN: Shading Image
	IMVS_PF_REGION stDetectBox;           // CH: ����� | EN: Detect box
	int    iReserved[4];                  // CH: �����ֶ� | EN: Reserved
}IMVS_PF_MULTIFUSION_MODU_INFO;

typedef struct IMVS_PF_IMAGEAQUISITION_MODU_INFO__
{
	int iImageCount;                      // CH: ͼ����� | EN: Image Count
	IMVS_PF_IMAGE_INFO stImage0;          // CH: ͼ��0��Ϣ | EN��Information of Image0
	float fImage0Distribution;            // CH: ͼ��0�ֲ��� | EN��Distribution of Image0
	float fImage0Irradiation;             // CH: ͼ��0����� | EN: Irradiation of Image0
	IMVS_PF_IMAGE_INFO stImage1;          // CH: ͼ��1��Ϣ | EN��Information of Image1
	float fImage1Distribution;            // CH: ͼ��1�ֲ��� | EN��Distribution of Image1
	float fImage1Irradiation;             // CH: ͼ��1����� | EN: Irradiation of Image1
	IMVS_PF_IMAGE_INFO stImage2;          // CH: ͼ��2��Ϣ | EN��Information of Image2
	float fImage2Distribution;            // CH: ͼ��2�ֲ��� | EN��Distribution of Image2
	float fImage2Irradiation;             // CH: ͼ��2����� | EN: Irradiation of Image2
	IMVS_PF_IMAGE_INFO stImage3;          // CH: ͼ��3��Ϣ | EN��Information of Image3
	float fImage3Distribution;            // CH: ͼ��3�ֲ��� | EN��Distribution of Image3
	float fImage3Irradiation;             // CH: ͼ��3����� | EN: Irradiation of Image3
	IMVS_PF_IMAGE_INFO stImage4;          // CH: ͼ��4��Ϣ | EN��Information of Image4
	float fImage4Distribution;            // CH: ͼ��4�ֲ��� | EN��Distribution of Image4
	float fImage4Irradiation;             // CH: ͼ��4����� | EN: Irradiation of Image4
	IMVS_PF_IMAGE_INFO stImage5;          // CH: ͼ��5��Ϣ | EN��Information of Image5
	float fImage5Distribution;            // CH: ͼ��5�ֲ��� | EN��Distribution of Image5
	float fImage5Irradiation;             // CH: ͼ��5����� | EN: Irradiation of Image5
	IMVS_PF_IMAGE_INFO stImage6;          // CH: ͼ��6��Ϣ | EN��Information of Image6
	float fImage6Distribution;            // CH: ͼ��6�ֲ��� | EN��Distribution of Image6
	float fImage6Irradiation;             // CH: ͼ��6����� | EN: Irradiation of Image6
	IMVS_PF_IMAGE_INFO stImage7;          // CH: ͼ��7��Ϣ | EN��Information of Image7
	float fImage7Distribution;            // CH: ͼ��7�ֲ��� | EN��Distribution of Image7
	float fImage7Irradiation;             // CH: ͼ��7����� | EN: Irradiation of Image7
	int iFrameNum;                        // CH: ֡�� | EN: Frame Number
	int iLostFrameCount;                  // CH: ��֡�� | EN: Number of lost frames
	int iLostPacketCount;                 // CH: ������ | EN: Number of lost packet
	int iGetCameraFailCount;              // CH: �����ȡʧ�ܴ��� | EN: Number of get camera fail
	int    iReserved[4];                  // CH: �����ֶ� | EN: Reserved
}IMVS_PF_IMAGEAQUISITION_MODU_INFO;

typedef struct IMVS_PF_CNNINSPECT_MODU_INFO__
{
	int iModuStatus;                      // CH: ģ��״̬ | EN: Module status
	IMVS_PF_IMAGE_INFO stResidualImage;   // CH: ͼ����Ϣ | EN��Information of Image
	IMVS_PF_REGION stDetectBox;           // CH: ����� | EN: Detect box
	int    iReserved[4];                  // CH: �����ֶ� | EN: Reserved
}IMVS_PF_CNNINSPECT_MODU_INFO;

// CH: ģ��ṹ��������Ϣ�ṹ | EN: Structure about information of module results
typedef struct IMVS_PF_MODU_RES_INFO__
{
	unsigned int    nStatus;                                                // CH: ����ģ���״̬ 1�ɹ�������ֵ���쳣 | EN: 1-succeeded, other values-error code
	unsigned int    nErrorCode;                                             // CH: ģ���쳣ʱ�ײ㷵�صĴ����� | EN: Error code returned when the module is abnormal
    unsigned int    nProcessID;                                             // CH: ����ID | EN: Process ID
    unsigned int    nModuleID;                                              // CH: ģ��ID | EN: Module ID
    float           fModuleTime;                                            // CH: ģ��ʱ��, ����������ȫ�����￪ʼ���㣬�ӽ��������ݷ��ͳ�ȥ�������� | EN: Module time
    float           fAlgorithmTime;                                         // CH: �㷨ʱ�� | EN: Algorithm time
    unsigned int    nInCycle;                                               // CH: �Ƿ�Ϊѭ����ģ�� | EN: Whether it is the module in the loop
	char            strDisplayName[IMVS_PF_MAX_MODULE_DISPLAY_NAME_LENGTH]; // CH: ������ʾ���� | EN: Displayed module name
    char            strModuleName[IMVS_PF_MAX_MODULE_NAME_LENGTH];          // CH: ģ������ | EN: Module name
    void *          pData;                                                  // CH: ģ�������� | EN: Module result details
    unsigned int    nLen;                                                   // CH: ģ�������ݳ��� | EN: Length of module result data
    char *          pReserved[8];                                           // CH: �����ֶ� | EN: Reserved
    unsigned int    nReserved[31];                                          // CH: �����ֶ� | EN: Reserved
} IMVS_PF_MODU_RES_INFO;

#define g_strTcpPortConfig "TcpPortConfig.cfg"


#endif // IMVS_6000_PLATFORMSDK_DEFINE_H__
