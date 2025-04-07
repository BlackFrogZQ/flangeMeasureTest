/***************************************************************************************************
* File:  MVD_AlgoParamDefine.h
* Note:  Algorithm-dependent common data struct definition in namespace VisionDesigner.
*
* Version:  V3.2.0.3
****************************************************************************************************/

#ifndef _MVD_ALGO_PARAM_DEFINE_H__
#define _MVD_ALGO_PARAM_DEFINE_H__

#include "MVD_ShapeParamDefine.h"

namespace VisionDesigner
{
    /************************************************************************/
    /*                               标定类                                */
    /************************************************************************/
    /** @struct _MVD_CALIBBOARD_TYPE__
     *  @brief  Calibboard type - enum type
     */
    enum _MVD_CALIBBOARD_TYPE__
    {
        MVD_CALIBBOARD_CHECKER = 1, // Checker Board
        MVD_CALIBBOARD_CIRCLE = 2, // Circle Board
        MVD_CALIBBOARD_HKA_SPARSE_I = 7,   // 海康I型标定板
        MVD_CALIBBOARD_HKA_DENSE_II = 6,   // 海康II型标定板
        MVD_CALIBBOARD_HKA_DENSE_II_V2     = 8, // 海康II型扩展型标定板(稠密型)
        MVD_CALIBBOARD_HKA_SPARSE_I_V2     = 9, // 海康I型扩展型标定板(稀疏型)
        MVD_CALIBBOARD_RSCODE_SIGN_FOUR = 3, // 海康I型标定板(V3.3后定义更新为MVD_CALIBBOARD_TYPE_HKA_SPARSE_I)
        MVD_CALIBBOARD_RSCODE_SIGN = 4 // 海康II型标定板(V3.3后定义更新为MVD_CALIBBOARD_TYPE_HKA_DENSE_II)
    };

    /** @struct _MVD_CALIBBOARD_IMAGE_TYPE__
     *  @brief  Calibboard image type - enum type
     */
    enum _MVD_CALIBBOARD_IMAGE_TYPE__
    {
        MVD_CALIBBOARD_OFFSET_IMAGE = 1, // 平移图像
        MVD_CALIBBOARD_ROTATE_IMAGE = 2 // 旋转图像
    };

    /** @struct _MVD_CALIBBOARD_COORDINATE_MODE__
     *  @brief  Calibboard coordinate mode - enum type
     */
    enum _MVD_CALIBBOARD_COORDINATE_MODE__
    {
        MVD_COORD_MODE_LEFT_HANDED = 1, // Left-handed coordinate system
        MVD_COORD_MODE_RIGHT_HANDED = 2 // Right-handed coordinate system
    };

    /** @enum _MVD_CAMERA_MODE__
     *  @brief  camera mode - enum type
     */
    enum _MVD_CAMERA_MODE__
    {
        MVD_CAMERA_MODE_STATIC_UP = 1,
        MVD_CAMERA_MODE_STATIC_DOWN = 2,
        MVD_CAMERA_MODE_MOVE = 3
    };

    /** @enum _MVD_MAP_CALIB_MODE__
    *  @brief  map calib mode - enum type
    */
    enum _MVD_MAP_CALIB_MODE__
    {
        MVD_MAP_CALIB_MODE_TWO_IMAGE = 1,
        MVD_MAP_CALIB_MODE_TWO_FILE = 2,
    };
    /** @enum _MVD_CALIB_MOVE_TYPE__
    *  @brief  map calib mode - enum type
    */
    enum _MVD_CALIB_MOVE_TYPE__
    {
        MVD_MAP_CALIB_MOVE_TYPE_OFFSET = 1,
        MVD_MAP_CALIB_MOVE_TYPE_ROTATE = 2,
    };
    /************************************************************************/
    /*                               拼接类                                */
    /************************************************************************/
    /** @struct _MVD_STITCH_CHECKERBOARD_SUBPIXEL_WIN_AUTO_TYPE_
    *  @brief  subpixel window auto type - enum type
    */
    enum _MVD_STITCH_CHECKERBOARD_SUBPIXEL_WIN_AUTO_TYPE__
    {
        MVD_STITCH_CHECKERBOARD_SUBP_WIN_AUTO = 1, // 自适应
        MVD_STITCH_CHECKERBOARD_SUBP_WIN_MANUAL = 2 // 设置值
    };

    /** @struct _MVD_STITCH_PATTERN_CREATE_PARAM__
    *  @brief  Pattern create param - struct type
    */
    struct _MVD_STITCH_PATTERN_CREATE_PARAM__
    {
        bool bFilterFlag; // 中值滤波标记，默认值true
        _MVD_STITCH_CHECKERBOARD_SUBPIXEL_WIN_AUTO_TYPE__ enSubPixelWinMode; // 亚像素窗口模式,默认值1
        int nSubPixelWinSize; // 亚像素窗口大小[3,100], 默认值7
        int nGrayContrast; // 灰度对比度[1,255], 默认值15
        int nReserved[8]; // 保留字节
    };

    /************************************************************************/
    /*                               定位类                                */
    /************************************************************************/
    /** @enum  _MVD_EDGEPOINT_STATUS__
     *  @brief Find status of the edge point
     */
    enum _MVD_EDGEPOINT_STATUS__
    {
        MVD_EDGEPOINT_STATUS_USED = 0x0001,    // Successfully found and used, default value
        MVD_EDGEPOINT_STATUS_NO_USED = 0x0002,    // Successfully found but not used
        MVD_EDGEPOINT_STATUS_NO_FIND = 0x0003     // Fail to find
    };

    /** @enum  _MVD_EDGE_POLARITY__
     *  @brief Type of the polarity of the edge point
     */
    enum _MVD_EDGE_POLARITY__
    {
        MVD_EDGE_POLARITY_DARK_TO_BRIGHT = 0x0001,    // From black to white, default value
        MVD_EDGE_POLARITY_BRIGHT_TO_DARK = 0x0002,    // From white to black
        MVD_EDGE_POLARITY_BOTH = 0x0003     // both
    };

    /** @enum  _MVD_EDGE_POLARITY_EX__
    *  @brief Type of the polarity of the edge point
    */
    enum _MVD_EDGE_POLARITY_EX__
    {
        MVD_EDGE_POLARITY_DARK_TO_BRIGHT_EX = 0x0001,    // 由黑到白
        MVD_EDGE_POLARITY_BRIGHT_TO_DARK_EX = 0x0002,    // 由白到黑
        MVD_EDGE_POLARITY_MIXED_EX = 0x0003,     // 由黑到白 & 由白到黑(同一条线段中点集有两种极性点)
        MVD_EDGE_POLARITY_EITHER_EX = 0x0004     // 由黑到白 | 由白到黑(同一条线段中点集有一种极性点)
    };

    /** @enum  _MVD_POSITION__
     *  @brief 方位
     */
    enum _MVD_POSITION__
    {
        MVD_POSITION_TOP = 0x0001,    // Top
        MVD_POSITION_RIGHT = 0x0002,    // Right
        MVD_POSITION_BOTTOM = 0x0003,    // Bottom
        MVD_POSITION_LEFT = 0x0004,    // Left
    };

    /** @enum  MVD_CALIPERTOOL_EDGEMODE
     *  @brief Type of the edge mode for the caliper
     */
    typedef enum _MVD_CALIPERTOOL_EDGEMODE__
    {
        MVD_CALIPERTOOL_EDGEMODE_SINGLE_EDGE = 0x0001,    // Caliper Tool Work mode : SingleEdge, default value
        MVD_CALIPERTOOL_EDGEMODE_EDGE_PAIR = 0x0002,    // Caliper Tool Work mode : EdgePair
    };

    /** @struct _MVD_FIDUCIAL_POINT_F__
    *  @brief  fiducial pose point Info - float type
    */
    struct _MVD_FIDUCIAL_POINT_F__
    {
        MVD_POINT_F stPosition;
        float fAngle;
        float fScaleX;
        float fScaleY;

        int nReserved[6];
    };

    /** @struct _MVD_POSFIX_MODE__
     *  @brief  Position Fix Mode - enum type
     */
    enum _MVD_POSFIX_MODE__
    {
        MVD_POSFIX_MODE_NONE = 0x0001,  // Do not make position fixture
        MVD_POSFIX_MODE_HORI = 0x0002,  // Position fixture horizontally
        MVD_POSFIX_MODE_VERT = 0x0003,  // Position fixture vertically
        MVD_POSFIX_MODE_HV = 0x0004,  // Position fixture both horizontally and vertically
        MVD_POSFIX_MODE_HVA = 0x0005,  // Angle fixture both horizontally and vertically
        MVD_POSFIX_MODE_HVAS = 0x0006,  // Angle fixture both horizontally and vertically, support scale
    };

    /** @struct _MVD_POSFIX_MODE__
    *  @brief  Position Fix Mode - enum type
    */
    enum _MVD_MARKFIND_ROI_TYPE__
    {
        MVD_MARK_TYPE_CROSS = 0x0000,  // 空心十字
        MVD_MARK_TYPE_RECT = 0x0001,  // 空心矩形
    };

    /** @struct _MVD_MARK_WEIGHT_TYPE__
    *  @brief  Weight Mode - enum type
    */
    enum _MVD_MARKFIND_WEIGHT_TYPE__
    {
        MVD_MARK_WEIGHT_TYPE_IMPORTANT = 0x0000,  // 重要
        MVD_MARK_WEIGHT_TYPE_COMMON = 0x0001,  // 一般
        MVD_MARK_WEIGHT_TYPE_WEAK = 0x0002,  // 弱
    };

    /** @struct _MVD_MARK_PAT_TYPE__
    *  @brief  Pat type - enum type
    */
    enum _MVD_MARKFIND_PAT_TYPE__
    {
        MVD_MARK_PAT_TYPE_FAST = 0x0000,  // 快速特征匹配
        MVD_MARK_PAT_TYPE_HP = 0x0001,    // 高精度特征匹配
    };

        /** @struct _MVD_PATMATCH_OPTIMIZE_FLAG_TYPE__
    *  @brief  Pat type - enum type
    */
    enum _MVD_PATMATCH_OPTIMIZE_FLAG_TYPE__
    {
        MVD_PATMATCH_OPTIMIZE_NONE = 0,     //导出默认模板
        MVD_PATMATCH_OPTIMIZE_IMG  = 1,     //导出模板不含原图
    };

    /** @struct _MVD_BOXROIFIND_PROC_TYPE__
    *  @brief  Process Type - enum type
    */
    enum _MVD_BOXROIFIND_PROC_TYPE__
    {
        MVD_BOXROI_PROC_TYPE_LINE = 0x0000,           // 检测直线
        MVD_BOXROI_PROC_TYPE_DISTANCE = 0x0001,       // 检测两条直线的距离
    };


    /************************************************************************/
    /*                               测量类                                */
    /************************************************************************/
    /** @enum  _MVD_MEASURE_C2C_TYPES__
     *  @brief Positional relationship between circle and circle
     */
    enum _MVD_MEASURE_C2C_TYPES__
    {
        MVD_MEASURE_C2C_UNDEFINED = 0x00000000,     // Undefined
        MVD_MEASURE_C2C_CONTAIN = 0x00000001,     // Contain
        MVD_MEASURE_C2C_INSCRIBE = 0x00000002,     // Inscribe
        MVD_MEASURE_C2C_INTERSECT = 0x00000003,     // Intersect
        MVD_MEASURE_C2C_EXCIRCLE = 0x00000004,     // External cutting
        MVD_MEASURE_C2C_DEVIATION = 0x00000005,     // Deviation
    };

	enum _MVD_NORMALIZE_ANGLE_TYPE_
	{
		MVD_NORMALIZE_ANGLE_TYPE_90 = 0x00000000,     // 归一化角度范围【-90，90】
		MVD_NORMALIZE_ANGLE_TYPE_180 = 0x00000001,     // 归一化角度范围【-180，180】
	};



    /************************************************************************/
    /*                             预处理类                             */
    /************************************************************************/
    /** @enum _MVD_IMGFIX_MODE__
     *  @brief  Image Fix Mode
     */
    enum _MVD_IMGFIX_MODE__
    {
        MVD_IMGFIX_MODE_NONE = 0x0001,  // Do not make fixture
        MVD_IMGFIX_MODE_HORI = 0x0002,  // Fixture horizontally
        MVD_IMGFIX_MODE_VERT = 0x0003,  // Fixture vertically
        MVD_IMGFIX_MODE_HV = 0x0004,  // Fixture both horizontally and vertically
        MVD_IMGFIX_MODE_HVA = 0x0005,  // Angle fixture both horizontally and vertically
        MVD_IMGFIX_MODE_HVAS = 0x0006,  // Angle fixture both horizontally and vertically, support scale
    };

    /** @struct _MVD_PREPRO_FIDUCIAL_POINT_F__
     *  @brief  fiducial pose point Info - float type
     */
    struct _MVD_PREPRO_FIDUCIAL_POINT_F__
    {
        MVD_POINT_F stBasisPoint;
        float fBasisAngle;
        float fScaleX;
        float fScaleY;

        int nReserved[6];
    };

    /** @struct _MVD_PREPRO_FRAME_MEAN_PROC_MODE
    *  @brief  Steps to create a frame average model 
    */
    enum _MVD_PREPRO_FRAME_MEAN_PROC_MODE
    {
        MVD_FRAME_MEAN_TRAIN_STEP = 1,   // 叠加
        MVD_FRAME_MEAN_CALCU_STEP = 2,   // 跳过
        MVD_FRAME_MEAN_ABORT_STEP = 3    // 重置
    };

    /** @struct _MVD_PREPRO_FLAW_PRIORITY_SORT_TYPE__
     *  @brief  flaw priority sort type - enum type
     */
	enum _MVD_PREPRO_FLAW_PRIORITY_SORT_TYPE__
	{
		MVD_PREPRO_FLAW_PRIORITY_SORT_TYPE_DESCEND = 1,  // 降序,优先级从高到低
		MVD_PREPRO_FLAW_PRIORITY_SORT_TYPE_AESCEND = 2,  // 升序，优先级从低到高
	};

    /** @struct _MVD_PREPRO_BOX_MERGE_TYPE__
     *  @brief  box merge type - enum type
     */
	enum _MVD_PREPRO_BOX_MERGE_TYPE__
	{
		MVD_PREPRO_BOX_MERGE_TYPE_FLAW_PRIORITY = 1,  // 按缺陷优先级融合（需输入box_label及flaw_priority）
		MVD_PREPRO_BOX_MERGE_TYPE_BOX_LABEL     = 2,  // 按缺陷类别融合（需输入box_label，不需要输入flaw_priority）
		MVD_PREPRO_BOX_MERGE_TYPE_NO_BOX_LABEL  = 3,  // 无缺陷类别融合（不需要输入box_label及flaw_priority）
	};

    /************************************************************************/
    /*                              识别类                             */
    /************************************************************************/
    /** @enum _MVD_1DCODE_TYPE__
     *  @brief  1D Code Type - enum type
     */
    enum _MVD_1DCODE_TYPE__
    {
        MVD_1DCODE_NONE = 0, // unsupport
        MVD_1DCODE_EAN8 = 1, // EAN8 Code
        MVD_1DCODE_UPCE = 2, // UPCE Code
        MVD_1DCODE_UPCA = 3, // UPCA Code
        MVD_1DCODE_EAN13 = 4, // EAN13 Code
        MVD_1DCODE_ISBN13 = 5, // ISBN13 Code
        MVD_1DCODE_CODABAR = 6, // codabar Code
        MVD_1DCODE_ITF25 = 7, // itf 25 Code
        MVD_1DCODE_39 = 8, // Code 39
        MVD_1DCODE_93 = 9, // Code 93
        MVD_1DCODE_128 = 10, // Code 128
    };

    /** @enum _MVD_TDCODE_TYPE__
     *  @brief  2DCode Type - enum type
     */
    enum _MVD_TDCODE_TYPE__
    {
        MVD_2DCODE_NONE = 0, // 无可识别条码
        MVD_2DCODE_DM = 1, // DM码
        MVD_2DCODE_QR = 2, // QR码
    };

    /** @enum _MVD_SYMBOL_VERIFY_STANDARD__
    *  @brief  Grade Standard
    */
    enum _MVD_SYMBOL_VERIFY_STANDARD__
    {
        MVD_SYMBOL_VERIFY_ISO_STANDARD_15415 = 1,         // iso 15415标准
        MVD_SYMBOL_VERIFY_ISO_STANDARD_29158 = 2,          // iso 29158标准
        MVD_SYMBOL_VERIFY_ISO_STANDARD_15416 = 3,         // iso 15416标准
    };

    /** @enum _MVD_SYMBOL_VERIFY_LABEL__
    *  @brief  Verify label
    */
    enum _MVD_SYMBOL_VERIFY_LABEL__
    {
        MVD_SYMBOL_VERIFY_LABEL_STANDARD = 1,         // 码评级完全按照iso标准
        MVD_SYMBOL_VERIFY_LABEL_CUSTOM = 2,         // 部分指标采用定制
    };

    enum _MVD_SYMBOL_VERIFY_PROCESS_TYPE__
    {
        MVD_SYMBOL_VERIFY_PROCESS_TYPE_I = 1,   // 只支持DM码,效果较优
        MVD_SYMBOL_VERIFY_PROCESS_TYPE_II = 2,   // 支持DM码和QR码
    };

    /** @enum  _MVDOCR_FILTER_TYPE__
     *  @brief 字符过滤类型
     */
    typedef enum _MVDOCR_FILTER_TYPE__
    {
        MVDOCR_FILTER_NO = 0,    // 不过滤
        MVDOCR_FILTER_NUMBERONLY = 1,    // 只允许数字
        MVDOCR_FILTER_UPPERLOWERCASEBOTH = 2,    // 只允许字母
        MVDOCR_FILTER_UPPERCASEONLY = 3,    // 只允许大写字母
        MVDOCR_FILTER_LOWERCASEONLY = 4,    // 只允许小写字母
        MVDOCR_FILTER_SPECIALONLY = 5,    // 只允许特殊字符
        MVDOCR_FILTER_SPACE = 6,    // 只允许空格,CNNOCR只要过滤类型设为空格，识别结果强制转为空格，传统OCR如果识别结果不为空格，则返回问号
        MVDOCR_FILTER_CUSTOM = 7     // 自定义过滤字符
    };

    /** @enum  _MVDOCR_FILTER__
     *  @brief 字符过滤器
     */
    struct _MVDOCR_FILTER__
    {
        _MVDOCR_FILTER_TYPE__ enFilterType;                // 字符过滤类型
        char               pFilterValue[128];           // 与过滤类型有关，默认为空；e.g.自定义模式下需指定过滤字符串
        int                nReserved[7];                // 保留字节
    };

    /** @enum  _MVDGEOFIND_CALIPER_ROI_MODE__
    *  @brief 圆查找/直线查找输入中的卡尺区域输入模式
    */
    typedef enum _MVDGEOFIND_RUNNING_MODE__
    {
        MVDGEOFIND_RUNNING_MODE_CALCULATE_AND_FIND = 0x0000, //计算ROI相关并执行查找 0
        MVDGEOFIND_RUNNING_MODE_ONLY_CALCULATE     = 0x0001, //仅计算ROI相关输出 1
        MVDGEOFIND_RUNNING_MODE_ONLY_FIND          = 0x0002  //仅执行查找(输出中ROI相关已知)2

    };

    /************************************************************************/
    /*                            缺陷检测类                            */
    /************************************************************************/
    /** @enum  _MVD_EDGEINSP_EDGE_FLAW_TYPE__
     *  @brief Type of the flaw of the edge inspection
     */
    enum _MVD_EDGEINSP_SINGLE_EDGE_FLAW_TYPE__
    {
        MVD_EDGEINSP_SINGLE_FLAW_TYPE_EDGE_OFFSET = 0x0006, // 边缘位置偏移
        MVD_EDGEINSP_SINGLE_FLAW_TYPE_EDGE_ROUGH = 0x0007, // 边缘凸起或凹坑缺陷
        MVD_EDGEINSP_SINGLE_FLAW_TYPE_EDGE_CRACK = 0x0008, // 边缘断裂缺陷
        MVD_EDGEINSP_SINGLE_FLAW_TYPE_EDGE_GRAD = 0x0009, // 边缘阶梯差缺陷
    };

    /** @enum  _MVD_EDGEINSP_EDGE_FLAW_TYPE__
     *  @brief Type of the flaw of the edge inspection
     */
    enum _MVD_EDGEINSP_EDGE_PAIR_FLAW_TYPE__
    {
        MVD_EDGEINSP_FLAW_TYPE_EDGE_WIDTH = 0x0001, // 边缘对宽度缺陷
        MVD_EDGEINSP_FLAW_TYPE_EDGE_OFFSET = 0x0002, // 边缘对位置偏移
        MVD_EDGEINSP_FLAW_TYPE_EDGE_ROUGH = 0x0003, // 边缘对阶梯缺陷
        MVD_EDGEINSP_FLAW_TYPE_EDGE_CRACK = 0x0004, // 边缘对断裂缺陷
        MVD_EDGEINSP_FLAW_TYPE_EDGE_BUBBLE = 0x000A, // 边缘对气泡缺陷
    };

     /** @enum  _MVD_EDGEINSP_FLAW_DEFECT_TYPE__
     *  @brief Type of the flaw
     */
    enum _MVD_EDGEINSP_FLAW_DEFECT_TYPE__
    {
        MVD_EDGEINSP_FLAW_DEFECT_TYPE_NONE = 0, // 非缺陷
        MVD_EDGEINSP_FLAW_DEFECT_TYPE_FLAW = 1, // 缺陷
		MVD_EDGEINSP_FLAW_DEFECT_TYPE_GAP  = 2, // 断裂

		MVD_EDGEINSP_FLAW_DEFECT_TYPE_FLAW_LEFT  = 3,  // 左缺陷
		MVD_EDGEINSP_FLAW_DEFECT_TYPE_FLAW_RIGHT = 4,  // 右缺陷
		MVD_EDGEINSP_FLAW_DEFECT_TYPE_GAP_LEFT   = 5,  // 左断裂
		MVD_EDGEINSP_FLAW_DEFECT_TYPE_GAP_RIGHT  = 6,  // 右断裂
    };

    /** @enum  _MVD_MKINSP_METHOD_TYPE__
     *  @brief Character inspection method
     */
    enum _MVD_MKINSP_METHOD_TYPE__
    {
        MVD_MKINSP_COAR_CORRE = 1, // 相关法
        MVD_MKINSP_FINE_MEAN_STD = 2, // 均值标准差
    };

    /** @enum  _MVD_BEAD_GUIDE_RUNNING_MODE__
     *  @brief bead guide running mode
     */
    enum _MVD_BEAD_GUIDE_RUNNING_MODE__
    {
        MVD_BEAD_GUIDE_FIX_POINT = 0, // 按胶路固定点
        MVD_BEAD_GUIDE_FIND_EDGE = 1, // 固定胶路查找边缘
    };

    /** @enum  _MVD_EDGEINSP_PATTERN_TRAIN_MODE__
    *  @brief pattern train mode
    */
    enum _MVD_EDGEINSP_PATTERN_TRAIN_MODE__
    {
        MVD_EDGEINSP_PATTERN_TRAIN_I = 1, // 模型创建失败时，不输出临时结果，像边缘点、卡尺等
        MVD_EDGEINSP_PATTERN_TRAIN_II = 2, // 模型创建失败时，输出临时结果，像边缘点、卡尺等
    };

    /************************************************************************/
    /*                            颜色处理类                            */
    /************************************************************************/
    /** @enum  _MVD_COLOR_SPACE_TYPE__
    *  @brief Color space type
    */
    enum _MVD_COLOR_SPACE_TYPE__
    {
        MVD_COLOR_SPACE_RGB = 1,   // RGB颜色空间
        MVD_COLOR_SPACE_HSV = 2,   // HSV颜色空间
        MVD_COLOR_SPACE_HSI = 3,   // HSI颜色空间
        MVD_COLOR_SPACE_YUV = 4    // YUV颜色空间(颜色抽取不支持)
    };

    /** @enum  _MVD_COLOR_EXTRACT_SINGLE_RANGE__
    *  @brief Color extract range param
    */
    struct _MVD_COLOR_EXTRACT_SINGLE_RANGE__
    {
        int nC1LowTolerance;        // 第一通道(R or H)的低容忍值
        int nC1HighTolerance;       // 第一通道(R or H)的高容忍值
        int nC2LowTolerance;        // 第二通道(G or S)的低容忍值
        int nC2HighTolerance;       // 第二通道(G or S)的高容忍值
        int nC3LowTolerance;        // 第三通道(B or V)的低容忍值
        int nC3HighTolerance;       // 第三通道(B or V)的高容忍值
        bool bReverseEnable;        // 反转使能   true表示反转，false表示不反转
        _MVD_COLOR_SPACE_TYPE__ enColorSpace;            // 颜色空间  //每个范围均可单独设置颜色空间
        int nReserved[8]; // 保留字节
    };


	/************************************************************************/
    /*                         串、片、栅定位、焊带偏移                          */
    /************************************************************************/
    /** @enum  _MVD_LINE_F__
     *  @brief 线
     */
    struct _MVD_LINE_F__
    {
        MVD_POINT_F  stStartPoint;
        MVD_POINT_F  stEndPoint;
        float fAngle; 
    };

    /** @struct MVD_BOX_F
    *  @brief  BOX description - float type
    */
    typedef struct _MVD_BOX_F_
    {
        float fCenterX;     //the center x of the rectangle
        float fCenterY;     //the center y of the rectangle
        float fWidth;       //the width of the rectangle
        float fHeight;      //the height of the rectangle
        float fAngle;       //the angle of the rectangle
    }MVD_BOX_F;


	/************************************************************************/
	/*								目标跟踪类			                     */
	/************************************************************************/
	/** @struct _MVD_TRACK_COUNT_DIRECTION__
	*  @brief  目标跟踪计数方向
	*/
	typedef enum _MVD_TRACK_COUNT_DIRECTION__
	{
		MVD_TRACK_COUNT_DIR_Y           = 0,  // 沿图像竖直方向跟踪计数，默认值
		MVD_TRACK_COUNT_DIR_X           = 1,  // 沿图像水平方向跟踪计数
	};

	/** @struct _MVD_TRACK_COUNT_LINE__
	*  @brief  目标跟踪计数线
	*/
	typedef struct _MVD_TRACK_COUNT_LINE__
	{
		_MVD_TRACK_COUNT_DIRECTION__    stCountDir;   // 计数线的方向，详见_MVD_TRACK_COUNT_DIRECTION__
		float							fLinePos;     // 计数线的位置
		int								nReserved[32]; // 保留字节
	};



	/************************************************************************/
	/*                            版本信息获取类                            */
	/************************************************************************/
	/** @enum  _MVD_SDK_TYPE__
	*  @brief sdk type
	*/
    enum _MVD_SDK_TYPE__
    {
		MVD_SDK_TYPE_MIN = 0,        ///SDK类型最小值

		MVD_All2DVersion =0,         /// 所有类别

		MVD_CameraMap = 1,           /// 相机映射
		MVD_ImageFixture = 2,        /// 图像修正
		MVD_LineAlign = 3,           /// 线对位
		MVD_PointSetAlign = 4,       /// 点集对位
		MVD_PositionFix = 5,         /// 位置修正
		MVD_SinglePointAlign = 6,    /// 单点对位

		MVD_CalibBoardCalib = 10,    /// 标定板标定
		MVD_CalibTrans = 11,         /// 标定转换
		MVD_ImageCalib = 12,         /// 畸变标定
		MVD_ImageCorrectCalib = 13,  /// 畸变矫正
		MVD_MapCalib = 14,           /// 映射标定
		MVD_MatrixFix = 15,          /// 矩阵修正
		MVD_MatrixToParam = 16,      /// 矩阵转参数
		MVD_NImageCalib = 17,        /// N图标定
		MVD_NPointCalib = 18,        /// N点标定

		MVD_ColorConvert = 30,       /// 颜色转换
		MVD_ColorExtract = 31,       /// 颜色抽取
		MVD_ColorMeasure = 32,       /// 颜色测量
		MVD_ColorRecognition = 33,   /// 颜色识别

		MVD_ArcFlawInspCpp = 40,       /// 圆弧缺陷检测
		MVD_ArcPairFlawInspCpp = 41,   /// 圆弧对缺陷检测
		MVD_BeadGuideCpp = 42,         /// 路径提取
		MVD_EdgeFlawInsp = 43,         /// 边缘缺陷检测
		MVD_EdgePairFlawInsp = 44,     /// 边缘对缺陷检测
		MVD_LineEdgeFlawInsp = 45,     /// 直线边缘检测
		MVD_LineEdgePairFlawInsp = 46, /// 直线对边缘检测

		MVD_BlobFind = 50,              /// Blob查找
		MVD_CaliperTool = 51,           /// 卡尺工具
		MVD_CircleFind = 52,            /// 圆查找
		MVD_CrossPointFind = 53,        /// 边缘交点检测
		MVD_EdgeFind = 54,              /// 边缘检测
		MVD_EdgeWidth = 55,             /// 间距检测
		MVD_LineFind = 56,              /// 线查找
		MVD_MultiCategoryBlobFind = 57, /// Blob标签分析
		MVD_MultiLineFind = 58,         /// 多直线查找
		MVD_PairLineFind = 59,          /// 平行线查找
		MVD_PeakFind = 60,              /// 顶点检测
		MVD_QuadrangleFindCpp = 61,     /// 四边形查找
		MVD_RectangleFind = 62,         /// 矩形检测
		MVD_BoxROIFind = 63,            /// 矩形ROI获取
		MVD_AnnROIFind = 64,            /// 圆环ROI获取
		MVD_NearestPointFind = 65,      /// 最近特征点获取
		MVD_RegionProjection = 66,      /// 区域投影
		MVD_EllipseFind = 67,           /// 椭圆查找
		MVD_PitchFind = 68,				/// 节距测量

		MVD_C2CMeasure = 70,            /// 圆圆测量
		MVD_CircleFit = 71,             /// 圆拟合
		MVD_HistTool = 72,              /// 直方图工具
		MVD_IntensityMeasure = 73,      /// 亮度测量
		MVD_L2CMeasure = 74,            /// 线圆测量
		MVD_L2LMeasure = 75,            /// 线线测量
		MVD_LineFit = 76,               /// 线拟合
		MVD_P2CMeasure = 77,            /// 点圆测量
		MVD_P2LMeasure = 78,            /// 点线测量
		MVD_P2PMeasure = 79,            /// 点点测量
		MVD_PixelCount = 80,            /// 像素统计
		MVD_EllipseFit = 81,            /// 椭圆拟合

		MVD_MKInsp = 90,                /// 字符缺陷检测

		MVD_AlmightyPatMatch = 100,     /// 全能特征匹配
		MVD_FastFeaturePatMatch = 101,  /// 快速特征匹配
		MVD_GrayPatMatchCpp = 102,      /// 灰度特征匹配
		MVD_HPFeaturePatMatch = 103,    /// 高精度特征匹配

		MVD_AffineTransPrepro = 110,		/// 仿射变换
		MVD_ArithmeticPrepro = 111,			/// 图像运算
		MVD_BinaryPrepro = 112,				/// 图像二值化
		MVD_EnhancePrepro = 113,			/// 图像增强
		MVD_FilterPrepro = 114,				/// 图像过滤
		MVD_FrameMeanPrepro = 115,			/// 帧平均
		MVD_MorphPrepro = 116,				/// 形态学处理
		MVD_NormalizePrepro = 117,			/// 图像归一化
		MVD_PolarWarpPrepro = 118,			/// 圆环展开
		MVD_RegionCopyPrepro = 119,			/// 拷贝填充
		MVD_ShadeCorrectPrepro = 120,		/// 阴影校正
		MVD_SharpnessPrepro = 121,			/// 清晰度评估
		MVD_WarpDistortPrepro = 122,		/// 图像矫正
		MVD_BoxOverlapPrepro = 123,			/// Box重叠率
		MVD_BoxMergePrepro = 124,			/// Box融合
		MVD_ImageResizePrepro = 125,		/// 图像缩放
		MVD_MultiLabelFilterPrepro = 126,	/// 多标签筛选
		MVD_BoxFilterPrepro = 127,			/// BOX过滤
		MVD_MirrorPrepro = 128,         /// 图像镜像

		MVD_Code1DReader = 130,				/// 一维码识别
		MVD_Code2DReader = 131,				/// 二维码识别
		MVD_CodeVerify = 132,				/// 码评级（嵌在码识别中）
		MVD_OCR = 133,						/// 字符识别

		MVD_ImageStitch = 140,				/// 图像拼接

		MVD_Track = 150, ///目标跟踪

		MVD_FlawDetect = 160, ///匹配滤波
		MVD_Classier = 161,   ///分类器

		MVD_CellSetLocation = 180, ///串定位
		MVD_CellLocation = 181,   ///栅定位
		MVD_GridLocation = 182,   ///片定位

		MVD_DefectInspect = 200, ///异常检测

		MVD_MultiImageFusion = 220, ///多图融合

		MVD_SDK_TYPE_MAX = 220				/// SDK类型最大值

    };


    /** @enum  _MVD_DL_SDK_TYPE__
     *  @brief Deep learning sdk type
    */
    enum _MVD_DL_SDK_TYPE__
    {
        MVD_DL_SDK_TYPE_MIN     = 0,           /// 深度SDK类型最小值

        MVD_DL_AllVersion       = 0,           /// 所有类别

        MVD_DL_CharDetect       = 1,           /// 字符定位
        MVD_DL_CharRecog        = 2,           /// 字符识别
        MVD_DL_SingleCharDetect = 3,           /// 单字符检测

        MVD_DL_Classify        = 10,           /// 图像分类

        MVD_DL_CodeReader      = 20,           /// 码识别
        MVD_DL_CodeVerify      = 21,           /// 码评级 嵌在码识别中

        MVD_DL_Detect          = 30,           /// 目标检测

		MVD_DL_Inspect         = 40,           /// 异常检测
		MVD_DL_UnSupervisedSegment = 41,       /// 无监督

        MVD_DL_InstanceSegment = 50,           /// 实例分割

        MVD_DL_OCR             = 60,           /// 深度OCR

        MVD_DL_Retrieval       = 70,           /// 图像检索

        MVD_DL_Segment         = 80,           /// 图像分割
        MVD_DL_SegmentV2       = 81,           /// 图像分割v2

        MVD_DL_SDK_TYPE_MAX    = 81,           /// 深度SDK类型最大值
    };
    /************************************************************************/
    /*                            深度算子类                            */
    /************************************************************************/
    /** @enum  _MVD_CNN_MODEL_TYPE__
    *  @brief cnn model type
    */
    enum _MVD_CNN_MODEL_TYPE__
    {
        MVD_CNN_MODEL_TYPE_CLASSIFY                = 0x0001, // 分类识别
        MVD_CNN_MODEL_TYPE_DETECT                  = 0x0002, // 目标检测
        //MVD_CNN_MODEL_TYPE_SEMANTIC_SEGMENTATION = 0x0003, // 语义分割（暂不支持）
		MVD_CNN_MODEL_TYPE_CHAR_DETECT             = 0x0004, // 文本定位
        MVD_CNN_MODEL_TYPE_CHAR_RECOG              = 0x0005, // 字符识别
        MVD_CNN_MODEL_TYPE_INSPECT                 = 0x0006, // 异常检测
        //MVD_CNN_MODEL_TYPE_IMAGE_DENOISE         = 0x0007, // 图像降噪（暂不支持）
        MVD_CNN_MODEL_TYPE_RETRIEVAL               = 0x0008, // 图像检索
        MVD_CNN_MODEL_TYPE_INSTANCE_SEGMENTATION   = 0x0009, // 实例分割
        //MVD_CNN_MODEL_TYPE_STEREO_MATCHING       = 0x000A, // 双目匹配（暂不支持）
        //MVD_CNN_MODEL_TYPE_OCR                   = 0x000B, // OCR（暂不支持）
        //MVD_CNN_MODEL_TYPE_SEGMENT               = 0x000C, // 图像分割（暂不支持）
		MVD_CNN_MODEL_TYPE_UASI                    = 0x000D, // 无监督
		MVD_CNN_MODEL_TYPE_SINGLE_CHAR_DETECT      = 0x000E, // 单字符检测
    };

	/** @enum  _MVD_CNN_UASI_MODEL_TYPE__
	*  @brief cnn uasi model type
	*/
	enum _MVD_CNN_UASI_MODEL_TYPE__
	{
		MVD_CNN_MODEL_TYPE_UASI_FAST = 0x0001,		// 
		MVD_CNN_MODEL_TYPE_UASI_HIGH_PRECISION = 0x0002,		// 
	};

	/** @enum  _MVD_CNN_CROP_TYPE__
	*  @brief ROI裁剪模式,
	*/
	typedef enum _MVD_CNN_CROP_TYPE__
	{
		MVD_CNN_ROI_TYPE_NORMAL = 0x00000001,		    ///> 不裁剪
		MVD_CNN_ROI_TYPE_CROP = 0x00000002				///> 裁剪，仅支持rect和box
	}MVD_CNN_CROP_TYPE;

}

#endif // _MVD_ALGO_PARAM_DEFINE_H__
