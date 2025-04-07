/***************************************************************************************************
 * File：IVmDynamicIoDefine.h
 * Note：Interface for the dynamic io.
 *
 * Version：4.3
 * Date：2021/11/14 11:04:12
 ***************************************************************************************************/
#ifndef _IVM_DYNAMIC_IODEFINE_H_
#define _IVM_DYNAMIC_IODEFINE_H_

#pragma warning(disable:4819)
//#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
namespace VisionMasterSDK
{
    //IO类型
    typedef enum VmIoType__ {
		IO_TYPE_NOTSUPPORT = 0,					// 不支持
		IO_TYPE_INT = 1,						// 整形
		IO_TYPE_FLOAT = 2,						// 浮点型
		IO_TYPE_STRING = 3,						// 字符串型
		IO_TYPE_IMAGE = 4,						// 图像
		IO_TYPE_POINTSET = 5,					// ** 目前不对外开放 **
		IO_TYPE_BYTE = 6,						// 二进制
		IO_TYPE_POINT_F = 7,					// 点
		IO_TYPE_POINT_I = 8,					// 点
		IO_TYPE_LINE = 9,						// 线
		IO_TYPE_CIRCLE = 10,					// 圆
		IO_TYPE_RECT_F = 11,					// 不带角度矩形
		IO_TYPE_RECT_I = 12,					// 不带角度矩形
		IO_TYPE_ROIBOX = 13,					// 带角度矩形
		IO_TYPE_FIXTURE = 14,					// 位置修正
		IO_TYPE_ANNULUS = 16,					// 圆环(ROIANNULUS)
		IO_TYPE_CONTOURPOINTS = 17,				// ** 目前不对外开放 **
		IO_TYPE_CLASSINFO = 18,					// 类别信息
		IO_TYPE_PIXELIMAGE = 19,				// 带有类别信息的图像
		IO_TYPE_POSTURE = 20,					// 位姿
		IO_TYPE_POLYGON = 21,					// 多边形
		IO_TYPE_ELLIPSE = 22,					// 椭圆
		IO_TYPE_3DPOINTCLOUDEX = 23,			// 3D点云拓展 
		IO_TYPE_3DMAT4F32 = 24,					// 3D矩阵4*4 F32
		IO_TYPE_3DPOINTF32 = 25,				// 3D点F32
		IO_TYPE_3DPOINTS32 = 26,				// 3D点S32（预留）
		IO_TYPE_3DPOINTF64 = 27,				// 3D点F32（预留）
		IO_TYPE_3DLINEF32 = 28,					// 3D线F32
		IO_TYPE_3DLINEF64 = 29,					// 3D线F64（预留）
		IO_TYPE_3DPLANEF32 = 30,				// 3D面F32
		IO_TYPE_3DPLANEF64 = 31,				// 3D面F64（预留）
		IO_TYPE_3DMAT3F32 = 32,					// 3D矩阵3*3 F32
		IO_TYPE_3DMAT3F64 = 33,					// 3D矩阵3*3 F64(预留)
		IO_TYPE_3DNORMAL4F32 = 34,				// 3D法向量
		IO_TYPE_3DROBOTVISION = 35,				// 3D机器人视觉参数
		IO_TYPE_3DRECTBOXF32 = 36,				// 3D矩形框
		IO_TYPE_3DPOSEF32 = 37,					// 3D位姿 F32
		IO_TYPE_3DPOSEF64 = 38,					// 3D位姿 F64
		IO_TYPE_3DMAT4F64 = 41,					// 3D矩阵4*4 F64
		IO_TYPE_3DIMAGE = 42,					// 3D图像
		IO_TYPE_DOUBLE = 43,					// 双精度浮点型
		IO_TYPE_2DCVXHULL = 44,					// 2D凸包
		IO_TYPE_2DRECTCOR = 45,					// 2D矩形顶点
		IO_TYPE_2DBOXLET = 46,					// 2D包围盒
		IO_TYPE_3DBBOX = 47,					// 3D包围盒角点
		IO_TYPE_3DNOANGLEBOX = 48,				// 3D无角度包围盒
		IO_TYPE_3DORIENTBOX = 49,				// 3D有角度包围盒
		IO_TYPE_3DRING = 50,					// 3D圆环
		IO_TYPE_3DGEOPARAM = 51,				// 3D几何参数
		IO_TYPE_3DTopPoint = 52,				// 3D实力分割顶点
		IO_TYPE_3DINSTANCEOBJINFO = 53,			// 3D实例分割信息
		IO_TYPE_3DCIRCLE = 54,					// 3D圆
		IO_TYPE_3DCYLINDRCIALSURFACE =55,		// 3D圆柱面
		IO_TYPE_3DCYLINDER =56,					// 3D圆柱体
		IO_TYPE_3DSPHERE = 57,					// 3D球
		IO_TYPE_3DCONVEXHuLLPOINT = 58,			// 3D凸包点
		IO_TYPE_3DCONVEXHULL = 59,				// 3D凸包
		IO_TYPE_3DRECTCONNERPNT = 60,			// 3D矩形角点
		IO_TYPE_3DINCIRCLE =61,					// 3D内切圆
		IO_TYPE_3DOUTCIRCLE =62,				// 3D外接圆
		IO_TYPE_3DPCDEXTINFO = 63,				// 3D点云拓展信息
        IO_TYPE_MAX								// 暂不支持
    }VmIoType;

    //IO基类
    typedef struct VmIoBase__
    {
        VmIoType eType;//io类型
        virtual ~VmIoBase__(){}
        virtual void DeleteMemory(){}

    }VmIoBase;
    
    ///< 字符串
    typedef struct StringData_ 
    {
        char strValue[MAX_MODULE_RESVALUE_LENGTH]; // CH: 字符串数据 | EN: String
        char strReserved[32];                      // CH: 保留字段 | EN: Reserved
    } StringData;

    

    ///< 整型数组
    typedef struct IntDataArray_ : VmIoBase
    {
        int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
        int *  pIntVal;                 // CH: 整型数据 | EN: Int data
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IntDataArray_()
        {
            eType = IO_TYPE_INT;
            nValueNum = 0;
            pIntVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {//不需要实现
        }
    } IntDataArray;

    ///< 浮点型数组
    typedef struct FloatDataArray_ : VmIoBase
    {
        int     nValueNum;               // CH: 浮点型数据数量 | EN: Number of int value
        float * pFloatVal;               // CH: 浮点型数据 | EN: Int data
        int     nReserved[4];            // CH: 保留字段 | EN: Reserved

        FloatDataArray_()
        {
            eType = IO_TYPE_FLOAT;
            nValueNum = 0;
            pFloatVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {//不需要实现
        }
    } FloatDataArray;


	///< 双精度浮点型数组
	typedef struct DoubleDataArray_ : VmIoBase
	{
		int     nValueNum;               // CH: Double数据数量 | EN: Number of double value
		double *pDoubleVal;              // CH: Double数据 | EN: double data
		int     nReserved[4];            // CH: 保留字段 | EN: Reserved

		DoubleDataArray_()
		{
			eType = IO_TYPE_DOUBLE;
			nValueNum = 0;
			pDoubleVal = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{//不需要实现
		}
	}DoubleDataArray;

    ///< 字符串型数组
    typedef struct StringDataArray_ : VmIoBase
    {
        int     nValueNum;               // CH: 字符串型数据数量 | EN: Number of int value
        StringData * astStringVal;       // CH: 字符串型数据 | EN: Int data
        int     nReserved[4];            // CH: 保留字段 | EN: Reserved

        StringDataArray_()
        {
            eType = IO_TYPE_STRING;
            nValueNum = 0;
            astStringVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
            if (NULL != astStringVal)
            {
                delete [] astStringVal;
                astStringVal = NULL;
            }
        }
    } StringDataArray;

    ///< 二进制数据
    typedef struct ByteArrayData_ : VmIoBase
    {
        size_t    nDataLen;               // CH: 数据长度 | EN: Data length
        char *    pData;                  // CH: 数据 | EN: Data
        int       nReserved[4];           // CH: 保留字段 | EN: Reserved

        ByteArrayData_()
        {
            eType = IO_TYPE_BYTE;
            nDataLen = 0;
            pData = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {//不需要实现
        }
    } ByteArrayData;

    ///< 图像类型
    typedef struct IoImage__ : VmIoBase
    {
		int nDataEmpty;                // CH: 数据是否获取 0 没有数据  1 有数据 | EN: DataReceived 
        ImageBaseData stImage;           // CH: 
        int     nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoImage__()
        {
			nDataEmpty = 0; //初始没有数据，有数据之后需置为1
            eType = IO_TYPE_IMAGE;
            memset(&stImage, 0, sizeof(stImage));
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {//不需要实现

        }
        
    } IoImage;

    //点结果数组
    typedef struct IoPointArray__ : VmIoBase
    {
        int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
        PointF *  pPointVal;                 // CH: 点指针 | EN:
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoPointArray__()
        {
            eType = IO_TYPE_POINT_F;
            nValueNum = 0;
            pPointVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
            if (NULL != pPointVal)
            {
                delete[] pPointVal;
            }
        }
    }IoPointArray;

    //直线结果数组
    typedef struct IoLineArray__ : VmIoBase
    {
        int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
        Line_v2 *  pLineVal;                 // CH: 
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoLineArray__()
        {
            eType = IO_TYPE_LINE;
            nValueNum = 0;
            pLineVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
            if (NULL != pLineVal)
            {
                delete[] pLineVal;
            }
        }
    }IoLineArray;

    //圆结果数组
    typedef struct IoCircleArray__ : VmIoBase
    {
        int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
        Circle *  pCircleVal;                 // CH: 
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoCircleArray__()
        {
            eType = IO_TYPE_LINE;
            nValueNum = 0;
            pCircleVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
            if (NULL != pCircleVal)
            {
                delete[] pCircleVal;
            }
        }
    }IoCircleArray;

	//椭圆结果数组
	typedef struct IoEllipseArray__ : VmIoBase
	{
		int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
		Ellipse *  pEllipseVal;                 // CH: 
		int    nReserved[4];            // CH: 保留字段 | EN: Reserved

		IoEllipseArray__()
		{
			eType = IO_TYPE_ELLIPSE;
			nValueNum = 0;
			pEllipseVal = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pEllipseVal)
			{
				delete[] pEllipseVal;
			}
		}
	}IoEllipseArray;

    //带角度矩形结果数组
    typedef struct IoRectBoxArray__ : VmIoBase
    {
        int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
        RectBox *  pBoxVal;                 // CH: 带角度矩形 | EN:
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoRectBoxArray__()
        {
            eType = IO_TYPE_ROIBOX;
            nValueNum = 0;
            pBoxVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
            if (NULL != pBoxVal)
            {
                delete[] pBoxVal;
            }
            pBoxVal = NULL;
        }
    }IoRectBoxArray;

    //无角度矩形结果数组
    typedef struct IoRectFArray__ : VmIoBase
    {
        int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
        RectF *  pRectVal;                 // CH: 
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoRectFArray__()
        {
            eType = IO_TYPE_RECT_F;
            nValueNum = 0;
            pRectVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
            if (NULL != pRectVal)
            {
                delete[] pRectVal;
            }
        }
    }IoRectFArray;

    //位置修正结果数组
    typedef struct IoFixtureArray__ : VmIoBase
    {
        int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
        Fixture *  pFixtureVal;                 // CH: 
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoFixtureArray__()
        {
            eType = IO_TYPE_FIXTURE;
            nValueNum = 0;
            pFixtureVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
            if (NULL != pFixtureVal)
            {
                delete[] pFixtureVal;
            }
        }
    }IoFixtureArray;


    //圆环结果数组
    typedef struct IoAnnulusArray__ : VmIoBase
    {
        int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
        Annulus *  pAnnulusVal;                 // CH: 
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoAnnulusArray__()
        {
            eType = IO_TYPE_ANNULUS;
            nValueNum = 0;
            pAnnulusVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
            if (NULL != pAnnulusVal)
            {
                delete[] pAnnulusVal;
            }
        }
    }IoAnnulusArray;

    //类别信息结果数组
    typedef struct IoClassInfoArray__ : VmIoBase
    {
        int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
        ClassInfo *  pClassInfoVal;                 // CH: 
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoClassInfoArray__()
        {
            eType = IO_TYPE_CLASSINFO;
            nValueNum = 0;
            pClassInfoVal = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
            if (NULL != pClassInfoVal)
            {
                delete[] pClassInfoVal;
            }
        }
    }IoClassInfoArray;


    //带类别信息图像数组
    typedef struct IoPixelImage__ : VmIoBase
    {
		int nDataEmpty;                // CH: 数据是否获取 0 没有数据  1 有数据 | EN: DataReceived 
        PixelImage  stImageWithClass;  // CH: 
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoPixelImage__()
        {
			nDataEmpty = 0;    //初始没有数据，有数据之后需置为1
            eType = IO_TYPE_PIXELIMAGE;
            memset(&stImageWithClass, 0, sizeof(stImageWithClass));
			stImageWithClass.pInfo = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
			if (NULL != stImageWithClass.pInfo)
			{
				delete[] stImageWithClass.pInfo;
			}
        }
    }IoPixelImage;

    //位姿数组
    typedef struct IoPostureArray__ : VmIoBase
    {
        int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
        Posture *  pPosture;                 // CH: 
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoPostureArray__()
        {
            eType = IO_TYPE_POSTURE;
            nValueNum = 0;
            pPosture = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

        virtual void DeleteMemory()
        {
            if (NULL != pPosture)
            {
                delete[] pPosture;
            }
        }
    }IoPostureArray;

	//多边形数组
	typedef struct IoPolygonArray__ : VmIoBase
	{
		int    nValueNum;               // CH: 整型数据数量 | EN: Number of int value
		Polygon *  pPolygon;                 // CH: 
		int    nReserved[4];            // CH: 保留字段 | EN: Reserved

		IoPolygonArray__()
		{
            eType = IO_TYPE_POLYGON;
			nValueNum = 0;
			pPolygon = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pPolygon)
			{
				delete[] pPolygon;
			}
		}
	}IoPolygonArray;

    //IO名称和类型
    typedef struct IoNameInfo__
    {
        char strIoName[MAX_MODULE_PARAMNAME_LENGTH];  //IO名称
        VmIoType nType;                               //IO类型
        char reserve[8];

        IoNameInfo__()
        {
            memset(&strIoName, 0, sizeof(strIoName));
            nType = IO_TYPE_NOTSUPPORT;
            memset(reserve, 0, sizeof(reserve));
        }

    }IoNameInfo;

    //
    typedef struct IoNameInfoArr__
    {
        int nNameNum;    // CH: 数量 | EN: Number
        IoNameInfo*  pstIo;// CH: 
        int    nReserved[4];            // CH: 保留字段 | EN: Reserved

        IoNameInfoArr__()
        {
            nNameNum = 0;
            pstIo = NULL;
            memset(nReserved, 0, sizeof(nReserved));
        }

    }IoNameInfoArray;



	///< 3D图像
	typedef struct Io3DImage__ : VmIoBase
	{
		int nDataEmpty;                // CH: 数据是否获取 0 没有数据  1 有数据 | EN: DataReceived 
		Image3DBaseData stImage3D;           // CH: 
		int     nReserved[4];            // CH: 保留字段 | EN: Reserved

		Io3DImage__()
		{
			nDataEmpty = 0; //初始没有数据，有数据之后需置为1
			eType = IO_TYPE_IMAGE;
			memset(&stImage3D, 0, sizeof(stImage3D));
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{//不需要实现

		}

	} Io3DImage;


	///3D点云
	typedef struct Io3DPointCloudF32Array__ :VmIoBase
	{
		int    nValueNum;							 // CH: 点云数据数量 | EN: Number of int value
		PointCloudExt3DF32Data *pstPcd3DData;        // CH: 点云数据
		int     nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DPointCloudF32Array__()
		{
			nValueNum = 0;	
			eType = IO_TYPE_3DPOINTCLOUDEX;
			pstPcd3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstPcd3DData)
			{
				delete[] pstPcd3DData;
				pstPcd3DData = NULL;
			}	
		}
	}Io3DPointCloudF32Array;

	///3D矩阵F32（3*3）
	typedef struct Io3RMatrix3F32Array__ :VmIoBase
	{
		int			nValueNum;							 // CH: 矩阵数据数量 | EN: Number of int value
		RMAT3DF32	*pMatrix3DData;						 // CH: 矩阵数据
		int			nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3RMatrix3F32Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DMAT4F32;
			pMatrix3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pMatrix3DData)
			{
				delete[] pMatrix3DData;
				pMatrix3DData = NULL;
			}
		}
	}Io3DMatrix3F32Array;

	///3D矩阵F64（3*3）
	typedef struct Io3DMatrix3F64Array__ :VmIoBase
	{
		int			nValueNum;							 // CH: 矩阵数据数量 | EN: Number of int value
		RMAT3DF64	*pMatrix3DData;						 // CH: 矩阵数据
		int			nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DMatrix3F64Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DMAT3F64;
			pMatrix3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pMatrix3DData)
			{
				delete[] pMatrix3DData;
				pMatrix3DData = NULL;
			}

		}
	}Io3DMatrix3F64Array;

	///3D矩阵F32（4*4）
	typedef struct Io3DMatrix4F32Array__ :VmIoBase
	{
		int			nValueNum;							 // CH: 矩阵数据数量 | EN: Number of int value
		RTMAT3DF32	*pMatrix3DData;						 // CH: 矩阵数据
		int			nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DMatrix4F32Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DMAT4F32;
			pMatrix3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pMatrix3DData)
			{
				delete[] pMatrix3DData;
				pMatrix3DData = NULL;
			}

		}
	}Io3DMatrix4F32Array;


	///3D矩阵F64（4*4）
	typedef struct Io3DMatrix4F64Array__ :VmIoBase
	{
		int			nValueNum;							 // CH: 矩阵数据数量 | EN: Number of int value
		RTMAT3DF64	*pMatrix3DData;						 // CH: 矩阵数据
		int			nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DMatrix4F64Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DMAT4F64;
			pMatrix3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pMatrix3DData)
			{
				delete[] pMatrix3DData;
				pMatrix3DData = NULL;
			}
		}
	}Io3DMatrix4F64Array;


	///3D点 F32
	typedef struct Io3DPointF32Array__ :VmIoBase
	{
		int			nValueNum;							 // CH: 点数据数量 | EN: Number of int value
		Point3DF32	*pPoint3DData;						 // CH: 点数据
		int			nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DPointF32Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DPOINTF32;
			pPoint3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pPoint3DData)
			{
				delete[] pPoint3DData;
				pPoint3DData = NULL;
			}

		}
	}Io3DPointF32Array;

	///3D点 S32
	typedef struct Io3DPointS32Array__ :VmIoBase
	{
		int			nValueNum;							 // CH: 点数据数量 | EN: Number of int value
		Point3DS32	*pPoint3DData;						 // CH: 点数据
		int			nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DPointS32Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DPOINTS32;
			pPoint3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pPoint3DData)
			{
				delete[] pPoint3DData;
				pPoint3DData = NULL;
			}
		}
	}Io3DPointS32Array;

	///3D点 F64
	typedef struct Io3DPointF64Array__ :VmIoBase
	{
		int			nValueNum;							 // CH: 点数据数量 | EN: Number of int value
		Point3DF64	*pPoint3DData;						 // CH: 点数据
		int			nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DPointF64Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DPOINTF64;
			pPoint3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pPoint3DData)
			{
				delete[] pPoint3DData;
				pPoint3DData = NULL;
			}
		}
	}Io3DPointF64Array;

	//3D线 F32
	typedef struct Io3DSegmentLineF32Array__ :VmIoBase
	{
		int					nValueNum;							 // CH: 点数据数量 | EN: Number of int value
		SegmentLine3DF32	*pLine3DData;						 // CH: 点数据
		int					nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DSegmentLineF32Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DLINEF32;
			pLine3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pLine3DData)
			{
				delete[] pLine3DData;
				pLine3DData = NULL;
			}
		}
	}Io3DSegmentLineF32Array;

	//3D线 F64
	typedef struct Io3DSegmentLineF64Array__ :VmIoBase
	{
		int					nValueNum;							 // CH: 线数据数量 | EN: Number of int value
		SegmentLine3DF64	*pLine3DData;						 // CH: 线数据
		int					nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DSegmentLineF64Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DLINEF64;
			pLine3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pLine3DData)
			{
				delete[] pLine3DData;
				pLine3DData = NULL;
			}
		}
	}Io3DSegmentLineF64Array;

	// 3D面 F32
	typedef struct Io3DPlaneCoeF32Array__ :VmIoBase
	{
		int					nValueNum;							 // CH: 面数据数量 | EN: Number of int value
		PlaneCoe3DF32		*pPlane3DData;						 // CH: 面数据
		int					nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DPlaneCoeF32Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DPLANEF32;
			pPlane3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pPlane3DData)
			{
				delete[] pPlane3DData;
				pPlane3DData = NULL;
			}
		}
	}Io3DPlaneCoeF32Array;

	// 3D面 F64
	typedef struct Io3DPlaneCoeF64Array__ :VmIoBase
	{
		int					nValueNum;							 // CH: 面数据数量 | EN: Number of int value
		PlaneCoe3DF64		*pPlane3DData;						 // CH: 面数据
		int					nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DPlaneCoeF64Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DPLANEF64;
			pPlane3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pPlane3DData)
			{
				delete[] pPlane3DData;
				pPlane3DData = NULL;
			}
		}
	}Io3DPlaneCoeF64Array;

	// 3D法向量 F32
	typedef struct Io3DNormalF32Array__ :VmIoBase
	{
		int					nValueNum;							 // CH: 法向量数据数量 | EN: Number of int value
		VEC3_3DF32			*pNormal3DData;						 // CH: 法向量数据
		int					nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DNormalF32Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DNORMAL4F32;
			pNormal3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pNormal3DData)
			{
				delete[] pNormal3DData;
				pNormal3DData = NULL;
			}
		}
	}Io3DNormalF32Array;

	// 3D机器人视觉参数
	typedef struct Io3DRobotVision__ :VmIoBase
	{
		int					nValueNum;							 // CH: 机器人视觉参数数据数量(目前只有一个) | EN: Number of int value
		RobotVision3D		stRobotVison3DData;					 // CH: 机器人视觉参数数据
		int					nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DRobotVision__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DROBOTVISION;
			memset(&stRobotVison3DData, 0, sizeof(stRobotVison3DData));
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{//不需要实现

		}
	}Io3DRobotVision;

	// 3D矩形框觉参数
	typedef struct Io3DRectBoxF32Array__ :VmIoBase
	{
		int					nValueNum;							 // CH: 3D矩形框数据数量 | EN: Number of int value
		RectBox3DF32		*pstRectBox3DData;					 // CH: 3D矩形框数据
		int					nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DRectBoxF32Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DRECTBOXF32;
			pstRectBox3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstRectBox3DData)
			{
				delete[] pstRectBox3DData;
				pstRectBox3DData = NULL;
			}
		}
	}Io3DRectBoxF32Array;

	// 3D位姿信息
	typedef struct Io3DPoseInfoF64Array__ :VmIoBase
	{
		int					nValueNum;							 // CH: 3D位姿信息数据数量 | EN: Number of int value
		PoseInfo3DF64		*pstPose3DData;						 // CH: 3D位姿信息数据
		int					nReserved[4];						 // CH: 保留字段 | EN: Reserved

		Io3DPoseInfoF64Array__()
		{
			nValueNum = 0;
			eType = IO_TYPE_3DPOSEF64;
			pstPose3DData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstPose3DData)
			{
				delete[] pstPose3DData;
				pstPose3DData = NULL;
			}
		}
	}Io3DPoseInfoF64Array;

	//点云-2D包围盒-2D凸包
	typedef struct Io2DCvxHullArray__ : VmIoBase
	{
		int    nValueNum;               // CH: 凸包数 | EN: Number of int value
		CvxHull2D* pCvxHullVal;         // CH: 凸包数据 | EN: 
		int    nReserved[4];            // CH: 保留字段 | EN: Reserved
		
		Io2DCvxHullArray__()
		{
			eType = IO_TYPE_2DCVXHULL;
			nValueNum = 0;
			pCvxHullVal = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pCvxHullVal)
			{
				delete[] pCvxHullVal;
			}
		}
	}Io2DCvxHullArray;

	//点云-2D包围盒-2D矩形顶点
	typedef struct Io2DRectCorArray__ : VmIoBase
	{
		int    nValueNum;               // CH: 矩形数 | EN: Number of int value
		RectCor2D* pRectCor;            // CH: 矩形顶点数据 | EN: 
		int    nReserved[4];            // CH: 保留字段 | EN: Reserved

		Io2DRectCorArray__()
		{
			eType = IO_TYPE_2DRECTCOR;
			nValueNum = 0;
			pRectCor = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pRectCor)
			{
				delete[] pRectCor;
			}
		}
	}Io2DRectCorArray;


	// 2D包围盒
	typedef struct Io2DBoxLetArray__ : VmIoBase
	{
		int    nValueNum;               // CH: 包围盒数 | EN: Number of int value
		BoxLet2D* pBoxLet;                // CH: 包围盒数据 | EN: 
		int    nReserved[4];            // CH: 保留字段 | EN: Reserved

		Io2DBoxLetArray__()
		{
			eType = IO_TYPE_2DBOXLET;
			nValueNum = 0;
			pBoxLet = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pBoxLet)
			{
				delete[] pBoxLet;
			}
		}
	}Io2DBoxLetArray;


	// 3D包围盒角点
	typedef struct Io3DBBoxArray__ : VmIoBase
	{
		int		nValueNum;               // CH: 3D包围盒角点个数 | EN: Number of int Io3DBBoxArray
		BBox3D* pBBox;					 // CH: 3D包围盒角点数据 | EN: 
		int		nReserved[4];            // CH: 保留字段 | EN: Reserved

		Io3DBBoxArray__()
		{
			eType = IO_TYPE_3DBBOX;
			nValueNum = 0;
			pBBox = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pBBox)
			{
				delete[] pBBox;
			}
		}
	}Io3DBBoxArray;


	// 3D无角度包围盒
	typedef struct Io3DNoAngleBoxArray__ : VmIoBase
	{
		int				nValueNum;               // CH: 3D无角度包围盒个数 | EN: Number of int Io3DBoxArray
		NoAngleBox3D*  pBox;					 // CH: 3D无角度包围盒数据 | EN: 
		int			  nReserved[4];              // CH: 保留字段 | EN: Reserved

		Io3DNoAngleBoxArray__()
		{
			eType = IO_TYPE_3DNOANGLEBOX;
			nValueNum = 0;
			pBox = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pBox)
			{
				delete[] pBox;
			}
		}
	}Io3DNoAngleBoxArray;

	// 3D有角度包围盒
	typedef struct Io3DOrinetBoxArray__ : VmIoBase
	{
		int			   nValueNum;               // CH: 3D无角度包围盒个数 | EN: Number of int Io3DBoxArray
		OrientBox3D*   pBox;					 // CH: 3D无角度包围盒数据 | EN: 
		int			  nReserved[4];              // CH: 保留字段 | EN: Reserved

		Io3DOrinetBoxArray__()
		{
			eType = IO_TYPE_3DORIENTBOX;
			nValueNum = 0;
			pBox = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pBox)
			{
				delete[] pBox;
			}
		}
	}Io3DOrinetBoxArray;


	// 3D圆环
	typedef struct Io3DRingArray__ : VmIoBase
	{
		int			   nValueNum;               // CH: 3D圆环个数 | EN: Number of Io3DRingArray
		Ring3D*		   pstRing;					// CH: 3D圆环数据 | EN: 
		int			  nReserved[4];             // CH: 保留字段 | EN: Reserved

		Io3DRingArray__()
		{
			eType = IO_TYPE_3DRING;
			nValueNum = 0;
			pstRing = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstRing)
			{
				delete[] pstRing;
			}
		}
	}Io3DRingArray;

	// 3D几何参数
	typedef struct Io3DGeoParamArray__ : VmIoBase
	{
		int			   nValueNum;               // CH: 3D几何参数个数 | EN: Number of Io3DGeoParamArray
		GeoParameter3D* pstGeoParam;			// CH: 3D几何参数数据 | EN: 
		int			  nReserved[4];             // CH: 保留字段 | EN: Reserved

		Io3DGeoParamArray__()
		{
			eType = IO_TYPE_3DGEOPARAM;
			nValueNum = 0;
			pstGeoParam = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstGeoParam)
			{
				delete[] pstGeoParam;
			}
		}
	}Io3DGeoParamArray;


	// 3D实例分割信息 -顶点
	typedef struct Io3DTopPointArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D顶点个数 | EN: Number of Io3DTopPointArray
		TopPoint3D*			pstTopPoint;				// CH: 3D顶点数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DTopPointArray__()
		{
			eType = IO_TYPE_3DINSTANCEOBJINFO;
			nValueNum = 0;
			pstTopPoint = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstTopPoint)
			{
				delete[] pstTopPoint;
			}
		}
	}Io3DTopPointArray;

	// 3D实例分割信息
	typedef struct Io3DInstanceObjInfoArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D实例分割信息个数 | EN: Number of Io3DInstanceObjInfoArray
		InstanceObjInfo3D*	pstInstanceObj;				// CH: 3D实例分割信息数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DInstanceObjInfoArray__()
		{
			eType = IO_TYPE_3DINSTANCEOBJINFO;
			nValueNum = 0;
			pstInstanceObj = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstInstanceObj)
			{
				delete[] pstInstanceObj;
			}
		}
	}Io3DInstanceObjInfoArray;


	// 3D圆
	typedef struct Io3DCircleArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D圆个数 | EN: Number of 3D Cirlce
		Circle3D*			pstCircle;					// CH: 3D圆数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DCircleArray__()
		{
			eType = IO_TYPE_3DCIRCLE;
			nValueNum = 0;
			pstCircle = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstCircle)
			{
				delete[] pstCircle;
			}
		}
	}Io3DCircleArray;

	// 3D圆柱面
	typedef struct Io3DCylinderSurfaceArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D圆柱面个数 | EN: Number of 3D CylindricalSurface
		CylindricalSurface3D* pstCylinderSurface;		// CH: 3D圆柱面数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DCylinderSurfaceArray__()
		{
			eType = IO_TYPE_3DCYLINDRCIALSURFACE;
			nValueNum = 0;
			pstCylinderSurface = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstCylinderSurface)
			{
				delete[] pstCylinderSurface;
			}
		}
	}Io3DCylinderSurfaceArray;

	// 3D圆柱
	typedef struct Io3DCylinderArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D圆柱个数 | EN: Number of 3D Cylinder
		Cylinder3D*			pstCylinder;				// CH: 3D圆柱数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DCylinderArray__()
		{
			eType = IO_TYPE_3DCYLINDER;
			nValueNum = 0;
			pstCylinder = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstCylinder)
			{
				delete[] pstCylinder;
			}
		}
	}Io3DCylinderArray;

	// 3D球
	typedef struct Io3DSphereArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D球个数 | EN: Number of 3D sphere
		Sphere3D*			pstSphere;					// CH: 3D球数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DSphereArray__()
		{
			eType = IO_TYPE_3DSPHERE;
			nValueNum = 0;
			pstSphere = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstSphere)
			{
				delete[] pstSphere;
			}
		}
	}Io3DSphereArray;


	// 3D凸包点
	typedef struct Io3DConvexHullPointArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D凸包点个数 | EN: Number of 3D Convex hull point num
		CvxHullPnt3D*		pstPoint;					// CH: 3D凸包点数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DConvexHullPointArray__()
		{
			eType = IO_TYPE_3DCONVEXHuLLPOINT;
			nValueNum = 0;
			pstPoint = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pstPoint)
			{
				delete[] pstPoint;
			}
		}
	}Io3DConvexHullPointArray;


	// 3D凸包
	typedef struct Io3DConvexHullArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D凸包个数 | EN: Number of 3D Convex hull
		CvxHull3D*			pst3DCvxhull;				// CH: 3D凸包数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DConvexHullArray__()
		{
			eType = IO_TYPE_3DCONVEXHULL;
			nValueNum = 0;
			pst3DCvxhull = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pst3DCvxhull)
			{
				delete[] pst3DCvxhull;
			}
		}
	}Io3DConvexHullArray;


	// 3D矩形角点
	typedef struct Io3DRectCornerPointArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D矩形角点个数 | EN: Number of 3D rect corner point num
		RectCornerPnt3D*	pst3DRectCornerPntData;		// CH: 3D矩形角点数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DRectCornerPointArray__()
		{
			eType = IO_TYPE_3DRECTCONNERPNT;
			nValueNum = 0;
			pst3DRectCornerPntData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pst3DRectCornerPntData)
			{
				delete[] pst3DRectCornerPntData;
			}
		}
	}Io3DRectCornerPointArray;

	// 3D内切圆
	typedef struct Io3DInCircleArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D内切圆个数 | EN: Number of inscribed Circle 3D in num
		InCircle3D*			pst3DInCircleData;			// CH: 3D内切圆数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DInCircleArray__()
		{
			eType = IO_TYPE_3DINCIRCLE;
			nValueNum = 0;
			pst3DInCircleData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pst3DInCircleData)
			{
				delete[] pst3DInCircleData;
			}
		}
	}Io3DInCircleArray;

	// 3D外接圆
	typedef struct Io3DOutCircleArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D外接圆个数 | EN: Number of inscribed Circle 3D in num
		OutCircle3D*		pst3DOutCircleData;			// CH: 3D外接圆数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DOutCircleArray__()
		{
			eType = IO_TYPE_3DOUTCIRCLE;
			nValueNum = 0;
			pst3DOutCircleData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pst3DOutCircleData)
			{
				delete[] pst3DOutCircleData;
			}
		}
	}Io3DOutCircleArray;


	// 3D点云拓展信息
	typedef struct Io3DPCDExtInfoArray__ : VmIoBase
	{
		int					nValueNum;					// CH: 3D拓展信息个数 | EN: Number of inscribed Circle 3D in num
		PCDExtInfoData3D*	pst3DPCDExtInfoData;		// CH: 3D拓展信息数据 | EN: 
		int					nReserved[4];				// CH: 保留字段 | EN: Reserved

		Io3DPCDExtInfoArray__()
		{
			eType = IO_TYPE_3DPCDEXTINFO;
			nValueNum = 0;
			pst3DPCDExtInfoData = NULL;
			memset(nReserved, 0, sizeof(nReserved));
		}

		virtual void DeleteMemory()
		{
			if (NULL != pst3DPCDExtInfoData)
			{
				delete[] pst3DPCDExtInfoData;
			}
		}
	}Io3DPCDExtInfoArray;
}


#endif    ///< _IVM_GROUP_H_
