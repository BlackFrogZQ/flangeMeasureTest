/***************************************************************************************************
 *
 * 版权信息：版权所有 (c) 2020, 保留所有权利
 *
 * 文件名称： VmModuleResultBase.h
 * 摘    要: VM模块结果基础类声明
 *
 * 当前版本：4.3.0
 * 日    期：2020-10-29 19:24:30
 * 备    注：新建
 ****************************************************************************************************/
#ifndef CVMMODULERESULTBASE_H__ // 2020-10-29 19:24:30
#define CVMMODULERESULTBASE_H__

#pragma warning(disable:4819)
#include <iostream>
#include <memory>
#include "iMVS-6000PlatformSDKDefine.h"
typedef double MVB3D_RTMAT_F64[4][4];
namespace VisionMasterSDK
{
    const static unsigned int MAX_MODULE_PARAMNAME_LENGTH = 128;     // 模块结果名称最大长度
    const static unsigned int MAX_MODULE_RESVALUE_LENGTH  = 4096;    // 模块结果值最大长度
    const static unsigned int MAX_POLYGON_VERTEX_NUM = 32;           // 多边形最大点数
	const static unsigned int SINGLE_CVXHULL_NUM = 16;               // 2D单凸包点数，固定16
	const static unsigned int SINGLE_RECTCOR_NUM = 4;                // 2D单矩形顶点数，固定4

    // 整型点信息结构
    typedef struct _PointI {
        int   X;
        int   Y;
    } PointI;

    // 浮点型点信息结构
    typedef struct _PointF {
        float   X;
        float   Y;
    } PointF;

    // 位姿结构
    typedef struct _Posture {
        PointF stPoint;
        float  R;
    } Posture;

    // 图像像素格式
    typedef enum _MvdPixelFormat_
    {
		MVD_PIXEL_NULL = 0,
		//Mono8
		MVD_PIXEL_MONO_08 = IMVS_PF_IMG_FORMAT_MONO8,    //| 8b   |        D0           |         S0         |
		//RGB 3 RGBRGB...
		MVD_PIXEL_RGB_RGB24_C3 = IMVS_PF_IMG_FORMAT_RGB24,  //| 8b   |    RGB:D0           |  RGB:S0            |

		// 3D图像格式（算法需要的格式）
		/*	MVD3D_PIXEL_MONO_08 = 1,
			MVD3D_PIXEL_MONO_16 = 3,
			MVD3D_PIXEL_RGB24_C3 = 201,*/

		// VM渲染的图像格式
		MV3D_PIXEL_Gvsp_MONO_08  = 17301505,
		MV3D_PIXEL_Gvsp_MONO_16  = 17825976,
		MV3D_PIXEL_Gvsp_RGB24_C3 = 35127316,

    }MvdPixelFormat;

    // 图像基本信息结构
    typedef struct ImageBaseData__
    {
        void * ImageData;
        unsigned int DataLen;
        int Width;
        int Height;
        MvdPixelFormat Pixelformat;
    } ImageBaseData;

    // 矩形信息结构
    typedef struct RectI__
    {
        PointI RectPoint;
        int RectWidth;
        int RectHeight;
    } RectI;

    // 矩形信息结构
    typedef struct RectF__
    {
        PointF RectPoint;
        float RectWidth;
        float RectHeight;
    } RectF;

    // 矩形框信息结构
    typedef struct RectBox__
    {
        PointF CenterPoint;
        float BoxWidth;
        float BoxHeight;
        float Angle;
    } RectBox;

    // 直线信息结构
    typedef struct Line__
    {
        PointF StartPoint;
        PointF EndPoint;
        float Angle;
    } Line;

    // 不带角度的直线信息结构
    typedef struct Line_v2__
    {
        PointF StartPoint;
        PointF EndPoint;
    } Line_v2;

    // 圆信息结构
    typedef struct Circle__
    {
        PointF CenterPoint;
        float Radius;
    } Circle;

    // 圆环信息结构
    typedef struct Annulus__
    {
        PointF CenterPoint;
        float InnerRadius;
        float OuterRadius;
        float StartAngle;
        float AngleExtend;
    } Annulus;

    // 多边形信息结构
    typedef struct Polygon__
    {
        unsigned int VertexNum;
        PointF VertexPoints[MAX_POLYGON_VERTEX_NUM];
    } Polygon;

    // 缺陷修正信息结构
    typedef struct DefectFixture__
    {
        float MinWidth;
        float MaxWidth;
        float AverageWidth;
        float ApproximateArea;
    } DefectFixture;

    typedef struct MatchPoint__
    {
        float MatchOutlineX; // CH: 匹配轮廓点X | EN : Matching contour point X
        float MatchOutlineY; // CH: 匹配轮廓点Y | EN: Matching contour point Y
        float MatchOutlineScore; // CH: 匹配轮廓点分数 | EN: Matching contour point score
        int MatchOutlineIndex; // CH: 匹配轮廓点序号 | EN: Matching contour point No.
    } MatchPoint;

    // 类别信息数据
    typedef struct ClassInfo__
    {
        char Name[MAX_MODULE_PARAMNAME_LENGTH];
        int GrayValue;
    } ClassInfo;

    typedef struct  PixelImage__
    {
        ImageBaseData stIamge;
        int nClassNum;
        ClassInfo*  pInfo;
    } PixelImage;

    //修正数据
    typedef struct Fixture__
    {
        PointF stInitPoint;
        float  fInitAngle;
        float  fInitScaleX;
        float  fInitScaleY;
        PointF stRunPoint;
        float  fRunAngle;
        float  fRunScaleX;
        float  fRunScaleY;
    } Fixture;

    //轮廓点数据
    typedef struct MatchOutline__
    {
        int MatchPointNum; // 匹配点数量
        MatchPoint * MatchOutlinePoints; // 匹配点
    } MatchOutline;

    // 二进制数据
    typedef struct BaseDataInfo__
    {
        char            * pData;           // CH: 数据 | EN: Image data
        size_t            nLen;            // CH: 数据长度 | EN: Image data len
        unsigned int      nReserved[4];    // CH: 保留字段 | EN: Reserved
    } BaseDataInfo;

    // 字符串结果信息结构
    typedef struct StringValueInfo__
    {
        char            strValue[MAX_MODULE_RESVALUE_LENGTH];    // CH: 字符串数据 | EN: String data
        unsigned int    nReserved[4];                            // CH: 保留字段 | EN: Reserved
    } StringValueInfo;

    // 输出模块结果信息结构
    typedef struct OutputResultInfo__
    {
        char            strParamName[MAX_MODULE_PARAMNAME_LENGTH];    // CH: 结果名称 | EN: Result name
        int             nParamType;           // CH: 结果类型:1整型 2浮点型 3字符串型 | EN: Result type: 1-integer, 2-float, 3-string
        int             nValueNum;            // CH: 模块值个数 | EN: Number of module values
        int *           pIntValue;            // CH: 整型数据 | EN: Integer data
        float *         pFloatValue;          // CH: 浮点型数据 | EN: Float data
        StringValueInfo * pstStringValue;     // CH: 字符串型数据 | EN: String data
    } OutputResultInfo;

    // 脚本模块输出模块结果信息结构
    typedef struct ShellOutputResultInfo__
    {
        char            strParamName[MAX_MODULE_PARAMNAME_LENGTH];    // CH: 结果名称 | EN: Result name
        int             nParamType;           // CH: 结果类型:1整型 2浮点型 3字符串型 4图像型 6二进制数据型 | EN: Result type: 1-integer, 2-float, 3-string, 4-image, 6-byte
        int             nValueNum;            // CH: 模块值个数 | EN: Number of module values
        int *           pIntValue;            // CH: 整型数据 | EN: Integer data
        float *         pFloatValue;          // CH: 浮点型数据 | EN: Float data
        StringValueInfo * pstStringValue;     // CH: 字符串型数据 | EN: String data
        BaseDataInfo    * pstImgValue;        // CH: 图像型数据 | EN: Image data
        BaseDataInfo    * pstByteValue;       // CH: 二进制数据 | EN: Byte data
    } ShellOutputResultInfo;

    // 变量计算模块输出模块结果信息结构
    typedef struct CalOutputResultInfo__
    {
        char            strParamName[MAX_MODULE_PARAMNAME_LENGTH];    // CH: 结果名称 | EN: Result name
        int             nParamType;           // CH: 结果类型:1整型 2浮点型 3字符串型 | EN: Result type: 1-integer, 2-float, 3-string
        int             nValueNum;            // CH: 模块值个数 | EN: Number of module values
        int *           pIntValue;            // CH: 整型数据 | EN: Integer data
        float *         pFloatValue;          // CH: 浮点型数据 | EN: Float data
    } CalOutputResultInfo;

    // 整型数据
    typedef struct IntResultInfo__
    {
        int   nValueStatus;    // 单个输出参数的状态 1成功，其他值失败
        int   nValueNum;       // 模块值个数
        int * pIntValue;       // 整型数据
    }IntResultInfo;

    // 浮点型数据
    typedef struct FloatResultInfo__
    {
        int   nValueStatus;    // 单个输出参数的状态 1成功，其他值失败
        int   nValueNum;       // 模块值个数
        float * pFloatValue;   // 浮点型数据
    }FloatResultInfo;

    // 浮点型数据
    typedef struct StringResultInfo__
    {
        int   nValueStatus;    // 单个输出参数的状态 1成功，其他值失败
        int   nValueNum;       // 模块值个数
        StringValueInfo * pstStringValue; // 字符串型数据
    }StringResultInfo;

    // 图像像素数据
    typedef struct ImageResultInfo__
    {
        int   nValueStatus;    // 单个输出参数的状态 1成功，其他值失败
        int   nValueNum;       // 模块值个数
        BaseDataInfo * pstImageValue; // 图像像素数据
    } ImageResultInfo;

    // 点集型数据
    typedef struct PointsetResultInfo__
    {
        int   nValueStatus;    // 单个输出参数的状态 1成功，其他值失败
        int   nValueNum;       // 模块值个数
        BaseDataInfo * pstPointsetValue; // 点集型数据
    } PointsetResultInfo;

	// 椭圆信息结构
	typedef struct Ellipse__
	{
		PointF CenterPoint;	// 圆心点
		float MajorRadius;	// 长半轴
		float MinorRadius;	// 短半轴
		float Angle;	    // 角度
	} Ellipse;

	// 3D图像基本信息结构
	typedef struct Image3DBaseData__
	{
		int			  cam_type;
		float         x_scale;            
		float         y_scale;
		float         z_scale;
		int			  x_offset;           
		int           y_offset;           
		int           z_offset;  
		ImageBaseData stIntensity;
		ImageBaseData stRange;
		ImageBaseData stRgb;
		double		  depth_to_rgb[4][4];
		double		  rgb_cam_mat[3][3];
		double		  rgb_dis_coeffs[5];
		double		  depth_dis_coeffs[5];
	} Image3DBaseData;

	// 3D点信息结构  float类型
	typedef struct Point3DF32__
	{
		float    fX;
		float    fY;
		float    fZ;
	}Point3DF32;

	// 3D点信息结构  int类型
	typedef struct Point3DS32__
	{
		int    nX;
		int    nY;
		int    nZ;
	}Point3DS32;

	// 3D点信息结构  Double类型
	typedef struct Point3DF64__
	{
		double    dX;
		double    dY;
		double    dZ;
	}Point3DF64;

	// 3D线信息结构 float类型（两个点）
	typedef struct SegmentLine3DF32__
	{
		Point3DF32	stStartPoint;
		Point3DF32	stEndPoint;
	}SegmentLine3DF32;

	// 3D线 double类型（两个点）
	typedef struct SegmentLine3DF64__
	{
		Point3DF64	stStartPoint;
		Point3DF64	stEndPoint;
	}SegmentLine3DF64;

	// 3D面信息结构 Float类型
	typedef struct PlaneCoe3DF32_
	{
		float a;
		float b;
		float c;
		float d;
	}PlaneCoe3DF32;

	// 3D面信息结构 Double类型
	typedef struct PlaneCoe3DF64_
	{
		double a;
		double b;
		double c;
		double d;
	}PlaneCoe3DF64;

	///// 3D法向量信息结构
	//typedef struct Normal3DF32__
	//{
	//	float  x; // x分量
	//	float  y; // y分量
	//	float  z; // z分量
	//	float  c; // 曲率
	//}Normal3DF32;

	//// 3DRGBA信息结构
	//typedef struct Rgba3DF32__
	//{
	//	unsigned char b; // Blue channel
	//	unsigned char g; // Green channel
	//	unsigned char r; // Red channel
	//	unsigned char a; // Alpha channel
	//}Rgba3DF32;

	// 3D向量(F32)
	typedef struct _VEC3_3DF32
	{
		float  x; // x分量
		float  y; // y分量
		float  z; // z分量
	}VEC3_3DF32;

	// 点颜色信息
	typedef struct _PointRgb3D
	{
		unsigned char r; // Red channel
		unsigned char g; // Green channel
		unsigned char b; // Blue channel
	}PointRgb3D;

	// 无角度包围盒信息结构
	typedef struct AxisBox3DF32_
	{
		float   min_x;
		float   min_y;
		float   min_z;
		float   max_x;
		float   max_y;
		float   max_z;
	}AxisBox3DF32;

	typedef Point3DF32  BOX3DCorF32[8];
	typedef float  RMAT3DF32[3][3];
	typedef double RMAT3DF64[3][3];
	typedef float  RTMAT3DF32[4][4];
	typedef double RTMAT3DF64[4][4];

	// 3D点云拓展信息结构
	typedef struct PCD3DExtInfoF32__
	{
		int                     coor_type;                          // 坐标系类型
		// 尺寸
		int                     flag_size;                          // 尺寸标记
		float					length;								// 长度
		float                   width;								// 宽度
		int                     flag_height;                        // 高度标记
		float                   height;                             // 高度
		// 面积
		int                     flag_area;                          // 面积标记
		float                   area;                               // 点云面积
		// 密度
		int                     flag_density;                       // 密度标记
		float                   density;                            // 点云密度
		// 体积
		int                     flag_volume;                        // 体积标记
		float                   volume;                             // 体积
		// 中心点
		int                     flag_center;                        // 中心点标记
		Point3DF32				center;                             // 中心点
		// 凸包
		int                     flag_cvx;                           // 凸包标记
		Point3DF32				cvx_hull[16];						 // 凸包点
		int                     cvx_pnt_num;						// 凸包点数
		// 外接矩
		int                     flag_rect;                          // 外接矩标记
		Point3DF32				rect_pt[4];							// 外接矩角点
		int                     flag_rect_rat;                      // 矩形度标记
		float                   rect_rat;							// 矩形度
		// 平面方程
		int                     flag_plane;                         // 平面标记
		PlaneCoe3DF32           plane_coe;							// 平面方程
		// 法向量
		int                     flag_normal;                        // 法向量标记
		VEC3_3DF32              pcd_normal;                         // 法向量
		// 坐标范围
		int                     flag_range;                         // 坐标范围标记
		AxisBox3DF32			range;                              // 坐标范围
		// 包围盒
		int                     flag_bbox;                          // 包围盒标记
		BOX3DCorF32				bbox;                               // 包围盒角点
		// 内切圆
		int                     flag_incircle;                      // 内切圆标记
		Point3DF32		        incircle_center;                    // 内切圆心
		float                   long_axis;                          // 内切圆长轴
		float                   short_axis;                         // 内切圆短轴
		// 外接圆
		int                     flag_outcircle;                     // 外接圆标记
		Point3DF32				outcircle_center;                   // 外接圆心
		float                   outcircle_radius;                   // 外接圆半径
		// 位姿
		int                     flag_pose;                          // 位姿标记
		RTMAT3DF32				pose;                               // 位姿
		// 类别
		int                     flag_class;                         // 类别标记
		int                     class_type;                         // 类别
		// 量纲
		int                     flag_dimension;                     // 量纲标记
		float                   dimension_scale;                    // 缩放系数（输出结果除以该系数后可还原回原结果）

		int                     reserved[16];						// 保留字节
	}PCD3DExtInfoF32;

	// 3D点云信息结构
	typedef struct PointCloudExt3DF32Data__
	{
		int                     capacity;        // 容量
		int                     pnt_num;         // 点数
		int                     normal_num;      // 法向量点数
		int                     colors_num;      // rgb点数
		Point3DF32				*points;         // 3D点集数据
		VEC3_3DF32				*normals;        // 法向量+曲率
		PointRgb3D				*colors;         // rgb数据
		PCD3DExtInfoF32			ext_info;        // 拓展信息
	}PointCloudExt3DF32Data;

	// 3D相机内参信息结构
	typedef struct CamInstrinc3D_
	{
		double          fx;                   // 相机的fx
		double          fy;                   // 相机的fy
		double          cx;                   // 相机的cx
		double          cy;                   // 相机的cy
		double          distort[5];           // 相机畸变系数
		int				flag_distort;         // 畸变系数使能
	}CamInstrinc3D;

	//尺寸(整型)
	typedef struct ImageSize_
	{
		int  width;     // 宽度
		int  height;    // 高度
	}ImageSize;

	// 物体尺寸范围
	typedef struct ObjectSizeRange3D_
	{
		float                    min_length;     // 长度最小值
		float                    max_length;     // 长度最大值
		float                    min_width;      // 宽度最小值
		float                    max_width;      // 宽度最大值
		float                    min_height;     // 高度最小值
		float                    max_height;     // 高度最大值
	}ObjectSizeRange3D;

	// 物体尺寸范围
#define  OBJ_SIZE_NUM_MAX      (50)           // 物体尺寸最大数量
	typedef struct ObjectSizeList3D_
	{
		float     length[OBJ_SIZE_NUM_MAX];     // 长度
		float     width[OBJ_SIZE_NUM_MAX];      // 宽度
		float     height[OBJ_SIZE_NUM_MAX];     // 高度
		float     tolerance;                    // 尺寸容忍度
		float     list_num;                     // 列表数量
	}ObjectSizeList3D;

	// 3D机器人视觉参数信息结构 
	typedef struct RobotVision3D_
	{
		int				   flag_camera_calib;
		CamInstrinc3D      rgb_instrinc;         // RGB相机内参
		CamInstrinc3D      depth_instrinc;       // 深度相机内参
		ImageSize          rgb_img_size;         // RGB相机分辨率
		ImageSize          depth_img_size;       // 深度相机分辨率
		RTMAT3DF64         rgb_to_depth;         // RGB相机到深度相机的变换
		RTMAT3DF64         depth_to_rgb;         // 深度相机到RGB相机的变换

		int					flag_multi_camera_calib;	// 多相机标定标记(HKA_FALSE or HKA_TRUE)
		RTMAT3DF64			rgb_to_major_rgb;		// 当前RGB相机到主RGB相机的变换
		RTMAT3DF64			depth_to_major_depth;	// 当前深度相机到主深度相机的变换

		int                flag_robot_calib;     // 手眼标定标记(HKA_FALSE or HKA_TRUE)
		int                robot_hec_type;       // 手眼标定类型(MVB3D_ROBOT_HEC_TYPE)
		RTMAT3DF64         tool_to_rgb;          // 机器人法兰到RGB相机的变换(EIH)
		RTMAT3DF64         robot_to_rgb;         // 机器人到RGB相机的变换(ETH)
		RTMAT3DF64         rgb_to_robot;         // RGB相机到机器人的变换
		RTMAT3DF64         robot_to_depth;       // 机器人到深度相机的变换
		RTMAT3DF64         depth_to_robot;       // 深度相机到机器人的变换
		RTMAT3DF64         tool_to_robot;        // 机器人法兰位姿(EIH时使用)

		int                flag_work_plane;      // 工作台/基准面标记(HKA_FALSE or HKA_TRUE)
		RTMAT3DF64         work_to_rgb;          // 工作台到RGB相机变换
		RTMAT3DF64         rgb_to_work;          // RGB相机到工作台变换
		RTMAT3DF64         work_to_depth;        // 工作台到深度相机变换
		RTMAT3DF64         depth_to_work;        // 深度相机到工作台变换
		RTMAT3DF64         work_to_robot;        // 工作台到机器人变换
		RTMAT3DF64         robot_to_work;        // 机器人到工作台变换

	}RobotVision3D;

	// 3D矩形框
	typedef struct RectBox3DF32_
	{
		Point3DF32		cam_cor_3d[4];       // 角点空间坐标
		Point3DF32		cam_cor_cen;         // 角点空间中心
		PointI			img_cor_2d[4];       // 角点图像坐标
		PointF			img_cor_cen;         // 角点图像中心
		int				is_depth_edge[4];    // 是否为深度边缘

		int				flag_dir;            // 主方向标记
		VEC3_3DF32		major_dir_3d;        // 3D主方向
		float			major_dir_2d[2];     // 2D主方向

		int				flag_score;          // 得分标记
		float           rect_score;          // 矩形得分

		int				flag_inseg;          // 实例分割标记
		int				is_rect_find;        // 矩形查找标记
		int				inseg_idx;           // 隶属实例分割ID

		int            flag_class;          // 类别标记
		int            class_type;          // 所属类别	
	}RectBox3DF32;

	// 位姿空间变换
	typedef struct Trans3DF64_
	{
		double	dTx;
		double	dTy;
		double	dTz;
		double	dRx;
		double	dRy;
		double	dRz;
	}Trans3DF64;

	// 欧拉位姿
	typedef struct PoseEular3DF64_
	{
		Trans3DF64		stEular;		// 欧拉(角度制)/旋转向量位姿
		int				nRotType;		// 输出旋转类型
	}PoseEular3DF64;

	// 四元数位姿
	typedef struct QuatPose3DF64_
	{
		double		dQuatRotate[4];		// 旋转四元数		
		double		dTx;				// 平移x
		double		dTy;				// 平移y
		double		dTz;				// 平移z
	}QuatPose3DF64;

	// 位姿基元
	typedef union PoseLet3DF64_
	{
		PoseEular3DF64		stEular;	// 欧拉/旋转向量位姿
		QuatPose3DF64		stQuat;		// 四元数
		RTMAT3DF64			dTransMat;	// 变换矩阵
	}PoseLet3DF64;

	// 3D位姿参数
	typedef struct PoseInfo3DF64_
	{
		PoseLet3DF64	stPoseLet;		// 位姿基元
		int				nType;			// 位姿类型
		int				nCoorType;		// 坐标系类型
	}PoseInfo3DF64;

	// 点云-2D包围盒-2D凸包
	typedef struct CvxHull2D__
	{
		int nValidNum; //凸包的有效数量
		PointF stPoints[SINGLE_CVXHULL_NUM]; //所有凸包点
	} CvxHull2D;

	// 点云-2D包围盒-2D矩形顶点
	typedef struct RectCor2D__
	{
		int nValidNum; //顶点的有效数量
		PointF stPoints[SINGLE_RECTCOR_NUM]; //所有顶点
	} RectCor2D;

	// 2D包围盒类型
	typedef enum _BoxLet2DType_
	{
		BOX2D_LET_TYPE_MIN = 1,
		BOX2D_LET_TYPE_CVX_HULL = 1, // 2D凸包
		BOX2D_LET_TYPE_RECT_COR = 2, // 2D矩形顶点
		BOX2D_LET_TYPE_AXIS_RECT = 3, // 2D无角度矩形
		BOX2D_LET_TYPE_ANGLE_RECT = 4, // 2D有角度矩形
		BOX2D_LET_TYPE_MAX = 4,
	}BoxLet2DType;

	// 点云-2D包围盒
	typedef struct BoxLet2D__
	{
		CvxHull2D stCvxHull; //2D凸包
		RectCor2D stRectCor; //2D矩形顶点
		RectF     stRect;    // 2D无角度矩形
		RectBox   stBox;     // 2D有角度矩形(角度为弧度)
		int nType;           //包围盒类型 1-凸包 2-矩形顶点 3-无角度矩形 4-有角度矩形
	} BoxLet2D;

	// 点云拓展信息-3D包围盒角点
	typedef struct BBox3D__
	{
		BOX3DCorF32				bbox;                               // 包围盒角点
	} BBox3D;


	// 点云拓展信息-3D无角度包围盒
	typedef struct NoAngleBox3D__
	{
		AxisBox3DF32				box;                           // 无角度包围盒
	}NoAngleBox3D;


	// 3D包围盒基元-3D有角度包围盒
	typedef struct OrientBox3D__
	{
		Point3DF32		  stCenetrPnt;// 中心点
		float             width;      // 宽度(X轴)
		float             length;     // 长度(Y轴)
		float             height;     // 高度(Z轴)
		float             x_angle;    // 绕x轴旋转的角度
		float             y_angle;    // 绕y轴旋转的角度
		float             z_angle;    // 绕z轴旋转的角度
	}OrientBox3D;


	// 3D几何基元-3D圆环
	typedef struct Ring3D__
	{
		Point3DF32		  stCenetrPnt;		   // 中心点
		float             InsideDiameter;      // 宽度(直径mm)
		float             OutSideDiameter;     // 长度(直径mm)
		float             height;			   // 高度(mm)
		float             x_angle;			   // 绕x轴旋转的角度
		float             y_angle;			   // 绕y轴旋转的角度
		float             z_angle;			   // 绕z轴旋转的角度
	}Ring3D;

	// 3D几何基元
	typedef struct GeoLet3D__
	{
		Point3DF32		  stPoint;			   // 点
		VEC3_3DF32		  stNormal;			   // 法向量
		PlaneCoe3DF32	  stPlane;			   // 平面方程
		OrientBox3D       stBox3d;			   // 3dbox
		Ring3D			  stRing3d;			   // 3d圆环
		SegmentLine3DF32  stLine3d;			   // 3d直线
	}GeoLet3D;

	// 3D几何参数
	typedef struct GeoParameter3D__
	{
		GeoLet3D		  stGeoLet;			   // 几何基元
		int				  nType;			   // 几何类型
		int				  nCoorType;		   // 坐标系类型
	}GeoParameter3D;

	// 3D实例分割信息-顶点
	typedef struct TopPoint3D__
	{
		PointI			  stPoint[16];		    // 顶点
	}TopPoint3D;

	// 3D实例分割信息
	typedef struct InstanceObjInfo3D__
	{
		int				  nClassLabel;          // 类别值
		int               nVertexNum;           // 顶点数
		TopPoint3D		  stTopPoint;
	}InstanceObjInfo3D;

	// 3D圆
	typedef struct Circle3D__
	{
		Point3DF32		  stCenter;				// 圆心坐标
		VEC3_3DF32		  stNormVec;			// 所在平面的法向
		float			  fRadius;				// 半径
	}Circle3D;

	// 3D圆柱面
	typedef struct CylindricalSurface3D__
	{
		Point3DF32		  stAxisPoint;			// 中轴上一点
		VEC3_3DF32		  stAxisDirection;		// 中轴方向
		float			  fRadius;				// 半径
	}CylindricalSurface3D;

	// 3D圆柱体
	typedef struct Cylinder3D__
	{
		CylindricalSurface3D	stCylinder;		// 圆柱方程
		float					fLength;		// 半径
	}Cylinder3D;

	// 3D球
	typedef struct Sphere3D__
	{
		Point3DF32				stCenterPnt;	// 球心坐标
		float					fRadius;		// 半径
	}Sphere3D;

	// 3D凸包点
	typedef struct CvxHullPnt3D__
	{
		Point3DF32				stCvxHullPnt[16];	// 凸包点
	}CvxHullPnt3D;

	// 3D凸包
	typedef struct CvxHull3D__
	{
		CvxHullPnt3D				stCvxHullPnt;	// 凸包点
		int							nPntNum;		// 凸包点数
	}CvxHull3D;

	// 外接矩形角点
	typedef struct RectCornerPnt3D__
	{
		Point3DF32				stCornerPnt[4];		// 角点
	}RectCornerPnt3D;

	// 3D内切圆
	typedef struct InCircle3D__
	{
		Point3DF32				stCenterPnt;		// 内切圆心
		float					fLongAxis;			// 内切圆长轴
		float					fShortAxis;			// 内切圆短轴
	}InCircle3D;

	// 3D外接圆
	typedef struct OutCircle3D__
	{
		Point3DF32				stCenterPnt;		// 外接圆心
		float					fRadius;			// 外接圆半径
	}OutCircle3D;

	// 3D点云拓展信息-基础信息
	typedef struct ExtInfoData3D__
	{
		int                     coor_type;                          // 坐标系类型
		// 尺寸
		int                     flag_size;                          // 尺寸标记
		float					length;								// 长度
		float                   width;								// 宽度
		int                     flag_height;                        // 高度标记
		float                   height;                             // 高度
		// 面积
		int                     flag_area;                          // 面积标记
		float                   area;                               // 点云面积
		// 密度
		int                     flag_density;                       // 密度标记
		float                   density;                            // 点云密度
		// 体积
		int                     flag_volume;                        // 体积标记
		float                   volume;                             // 体积
		// 中心点
	}ExtInfoData3D;

	// 3D拓展信息
	typedef struct PCDExtInfoData3D__
	{
		ExtInfoData3D			stExtInfoData;

		int                     nCenterFlag;                        // 中心点标记
		Point3DF32				stCenterPnt;                        // 中心点
		// 凸包
		int                     nCvxHullFlag;                       // 凸包标记
		CvxHull3D				stCvxHull;							// 凸包
		// 外接矩
		int                     nRectFlag;                          // 外接矩标记
		RectCornerPnt3D			stRectCorPnt;						// 外接矩角点
		int                     nRectRatFlag;                       // 矩形度标记
		float                   fRectRat;							// 矩形度

		// 平面方程
		int                     nPlaneFlag;                         // 平面标记
		PlaneCoe3DF32           stPlaneCoe;							// 平面方程

		// 法向量
		int                     nNoramlFlag;                        // 法向量标记
		VEC3_3DF32              stPcdNoraml;                        // 法向量

		// 坐标范围
		int                     nRangeFlag;                         // 坐标范围标记
		NoAngleBox3D			stRange;                            // 坐标范围
	
		// 包围盒
		int                     nBBoxFlag;                          // 包围盒标记
		BBox3D					stBBox;                             // 包围盒角点

		// 内切圆
		int                     nIncircleFlag;                      // 内切圆标记
		InCircle3D				stIncircle;							// 内切圆

		// 外接圆
		int                     nOutcircleFlag;                     // 外接圆标记
		OutCircle3D				stOutcircle;						// 外接圆

		// 位姿
		int                     flag_pose;                          // 位姿标记
		RTMAT3DF32				pose;                               // 位姿

		// 类别
		int                     flag_class;                         // 类别标记
		int                     class_type;                         // 类别
		// 量纲
		int                     flag_dimension;                     // 量纲标记
		float                   dimension_scale;                    // 缩放系数（输出结果除以该系数后可还原回原结果）

		int                     reserved[16];						// 保留字节
	}PCDExtInfoData3D;


    /** @class CModuleResultBase
     *  @brief 模块结果基类
     */
    class CModuleResultBase
    {
    public:

        /** @fn     explicit CModuleResultBase();
         *  @brief  构造函数,初始化成员变量
         *  @param  无
         *  @return 无
         */
        explicit CModuleResultBase();

        /** @fn     virtual ~CModuleResultBase();
         *  @brief  析构函数,销毁成员变量
         *  @param  无
         *  @return 无
         */
        virtual ~CModuleResultBase();

    public:
        /** @fn     GetThisClassName();
         *  @brief  用于在运行时获取对象的真实类名称（内部使用）
         *  @param  无
         *  @return 类名
         */
        virtual const char * GetThisClassName();

        /** @fn     GetErrorCode();
        *  @brief  错误码
        *  @param  无
        *  @return 类名
        */
        virtual unsigned int GetErrorCode();

    protected:
        unsigned int m_nErrorCode;
        IMVS_PF_MODULE_RESULT_INFO_LIST m_stModuResInfoList;
    };

    typedef std::shared_ptr<CModuleResultBase> CModuleResultBasePtr;
}

#endif // CVMOBJECTBASE_H__
