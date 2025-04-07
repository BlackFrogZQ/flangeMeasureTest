/***************************************************************************************************
 * File：IVmProcedure.h
 * Note：Interface for the procedure tool.
 *
 * Version：4.3
 * Date：2020-11
 ***************************************************************************************************/
#ifndef _IVM_PROCEDURE_H_
#define _IVM_PROCEDURE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmToolBase.h"
#include "IVmDynamicIoDefine.h"

namespace VisionMasterSDK
{
    namespace VmProcedure
    {
        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the IMVSProcedureResults.  */
        class IMVSProcedureResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSProcedureResults() {}
            virtual ~IMVSProcedureResults() {}

        public:

            /**
            * @brief 获取整型输入
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual IntDataArray GetOutputInt(IN const char * const strParamName) = 0;

            /**
            * @brief 获取浮点型输入
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual FloatDataArray GetOutputFloat(IN const char * const strParamName) = 0;

			/**
			* @brief 获取双精度浮点型输入
			* @param 参数名称
			* @return 无，出错时抛出异常
			* @par 注解
			*/
			virtual DoubleDataArray GetOutputDouble(IN const char * const strParamName) = 0;

            /**
            * @brief 获取字符串型输入
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual StringDataArray GetOutputString(IN const char * const strParamName) = 0;

            /**
            * @brief 获取二进制数据型输入
            * @param 参数名称
            * @return 二进制数据
            * @par 注解
            */
            virtual ByteArrayData GetOutputByteArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取图像结果（整个图像）
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoImage GetOutputImageV2(IN const char * const strParamName) = 0;

            /**
            * @brief 获取点输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoPointArray GetOutputPointArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取直线输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoLineArray GetOutputLineArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取圆输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoCircleArray GetOutputCircleArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取椭圆输出数组
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual IoEllipseArray GetOutputEllipseArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取带角度矩形输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoRectBoxArray GetOutputBoxArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取无角度矩形(浮点型)输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoRectFArray GetOutputRectArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取位置修正输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoFixtureArray GetOutputFixtureArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取圆环输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoAnnulusArray GetOutputAnnulusArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取类别信息输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoClassInfoArray GetOutputClassInfoArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取带类别信息的图(界面可根据类别信息将灰度图显示成彩图)
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoPixelImage GetOutputPixelImage(IN const char * const strParamName) = 0;

            /**
            * @brief 获取位姿数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoPostureArray GetOutputPostureArray(IN const char * const strParamName) = 0;
            /**
            * @brief 获取多边形输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoPolygonArray GetOutputPolygonArray(IN const char * const strParamName) = 0;

            /**
            * @brief 所有所有输出名称信息（CONTOURPOINTS、POINTSET、小写的image,这三种类型不支持）
            * @param
            * @return
            * @par 注解
            */
            virtual IoNameInfoArray GetAllOutputNameInfo() = 0;

            /**
            * @brief 根据名称信息获取输出对象基类指针
            * @param
            * @return
            * @par 注解
            */
            virtual VmIoBase* GetOutputObject(IN const IoNameInfo& stNameInfo) = 0;

			/**
			* @brief 获取3D图像结果（整个图像）
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DImage GetOutput3DImage(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D点云结果
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DPointCloudF32Array GetOutput3DPointCloudArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D 3*3矩阵  float类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DMatrix3F32Array GetOutput3DMatrix3F32Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D 3*3矩阵  double类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DMatrix3F64Array GetOutput3DMatrix3F64Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D 4*4矩阵	float类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DMatrix4F32Array GetOutput3DMatrix4F32Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D 4*4矩阵	double类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DMatrix4F64Array GetOutput3DMatrix4F64Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D点	float类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DPointF32Array GetOutput3DPointF32Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D点	int类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DPointS32Array GetOutput3DPointS32Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D点  double类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DPointF64Array GetOutput3DPointF64Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D线（两个点）  float类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DSegmentLineF32Array GetOutput3DSegmentLineF32Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D线（两个点）  double类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DSegmentLineF64Array GetOutput3DSegmentLineF64Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D面  float类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DPlaneCoeF32Array GetOutput3DPlaneCoeF32Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D面  double类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DPlaneCoeF64Array GetOutput3DPlaneCoeF64Array(IN const char * const strParamName) = 0;
			
			/**
			* @brief 获取3D法向量  float类型 
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DNormalF32Array GetOutput3DNormalF32Array(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D机器人视觉参数  
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DRobotVision GetOutput3DRobotVision(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D矩形框 Float类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DRectBoxF32Array GetOutput3DRectBoxF32(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D位姿信息 Double类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DPoseInfoF64Array GetOutput3DPoseInfoF64(IN const char * const strParamName) = 0;

			/**
			* @brief 获取2D凸包 Io2DCvxHullArray类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io2DCvxHullArray GetOutput2DCvxHullArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取2D矩形顶点 Io2DRectCorArray类型
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io2DRectCorArray GetOutput2DRectCorArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取2D包围盒
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io2DBoxLetArray GetOutput2DBoxLetArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D包围盒角点
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DBBoxArray GetOutput3DBBoxArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D无角度包围盒
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DNoAngleBoxArray GetOutput3DNoAngleBoxArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D有角度包围盒
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DOrinetBoxArray GetOutput3DOrientBoxArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D圆环
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DRingArray GetOutput3DRingArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D几何参数
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DGeoParamArray GetOutput3DGeoParamArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D实例分割信息顶点
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DTopPointArray GetOutput3DInstanceObjTopPntArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D实例分割信息
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DInstanceObjInfoArray GetOutput3DInstanceObjInfoArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D圆
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DCircleArray GetOutput3DCircleArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D圆柱面
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DCylinderSurfaceArray GetOutput3DCylinderSurfaceArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D圆柱
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DCylinderArray GetOutput3DCylinderArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D球
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DSphereArray GetOutput3DSphereArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D凸包点
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DConvexHullPointArray GetOutput3DConvexHullPointArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D凸包
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DConvexHullArray GetOutput3DConvexHullArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D矩形角点
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DRectCornerPointArray GetOutput3DRectCornerPntArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D内切圆
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DInCircleArray GetOutput3DInCircleArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取3D外接圆
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DOutCircleArray GetOutput3DOutCircleArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取点云拓展信息
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual Io3DPCDExtInfoArray GetOutput3DPCDExtInfoArray(IN const char * const strParamName) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the IMVSProcedureParams.  */
        class IMVSProcedureParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSProcedureParams() {}
            virtual ~IMVSProcedureParams() {}

        public:

            /**   
            *  @brief  设置动态输入图像数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoImage结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputImageV2(const char * const strParamName, const IoImage * const pstImageData) = 0;

            /** 
            *  @brief  设置动态输入矩形框数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoRectBoxArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputBox(const char * const strParamName, const IoRectBoxArray * const pstBox) = 0;

            /** 
            *  @brief  设置动态输入圆环ROI数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoAnnulusArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputAnnulus(const char * const strParamName, const IoAnnulusArray * const pstAnnulus) = 0;

            /** 
            *  @brief  设置动态输入圆形数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoCircleArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputCircle(const char * const strParamName, const IoCircleArray * const pstCircle) = 0;

			/**
			*  @brief  设置动态输入椭圆形数据(仅当次执行起效)
			*  @param  参数名称
			*  @param  IoEllipseArray结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInputEllipse(const char * const strParamName, const IoEllipseArray * const pstEllipse) = 0;

            /** 
            *  @brief  设置动态输入线型数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoLineArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputLine(const char * const strParamName, const IoLineArray * const pstLine) = 0;

            /** 
            *  @brief  设置动态输入点型数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoPointArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputPoint(const char * const strParamName, const IoPointArray * const pstPointF) = 0;

            /** 
            *  @brief  设置动态输入位置修正数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoFixtureArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputFixture(const char * const strParamName, const IoFixtureArray * const pstFixture) = 0;

            /** 
            *  @brief  设置动态输入矩形数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoRectFArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputRect(const char * const strParamName, const IoRectFArray * const pstRectF) = 0;

            /** 
            *  @brief  设置动态输入类别信息数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoClassInfoArray结构体指针数组
            *  @return 无
            *  @par 注解
            */
            virtual void SetInputClassInfo(const char * const strParamName, const IoClassInfoArray * const pstClassInfo) = 0;

            /** 
            *  @brief  设置动态输入像素图像数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoPixelImage结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputPixelImage(const char * const strParamName, const IoPixelImage * const pstPixelImage) = 0;
            /** 
            *  @brief  设置动态输入多边形数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoPolygonArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputPolygon(const char * const strParamName, const IoPolygonArray * const pstPolygon) = 0;
            /** 
            *  @brief  设置动态输入位姿数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoPostureArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputPosture(const char * const strParamName, const IoPostureArray * const pstPosture) = 0;
			/**
			*  @brief  获取所有输入名称信息
			*  @param  无
			*  @return 无
			*  @par    注解
			*/
			virtual IoNameInfoArray GetAllInputNameInfo() = 0;

			/**
			*  @brief  设置动态输入3D图像(仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DImage结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DImage(const char * const strParamName, const Io3DImage * const pstImageData) = 0;

			/**
			*  @brief  设置动态输入3D点数据 float类型(仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DPointF32Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DPointF32(const char * const strParamName, const Io3DPointF32Array * const pstPointData) = 0;

			/**
			*  @brief  设置动态输入3D点数据 int类型(仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DPointS32Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DPointS32(const char * const strParamName, const Io3DPointS32Array * const pstPointData) = 0;

			/**
			*  @brief  设置动态输入3D点数据 double类型(仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DPointF64Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DPointF64(const char * const strParamName, const Io3DPointF64Array * const pstPointData) = 0;

			/**
			*  @brief  设置动态输入3D法向量 
			*  @param  参数名称
			*  @param  Io3DNormalF32Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DNormalF32(const char * const strParamName, const Io3DNormalF32Array * const pstNormalData) = 0;

			/**
			*  @brief  设置动态输入3D线数据 float类型(仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DSegmentLineF32Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DSegmentLineF32(const char * const strParamName, const Io3DSegmentLineF32Array * const pstLineData) = 0;

			/**
			*  @brief  设置动态输入3D面数据 float类型(仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DPlaneCoeF32Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DPlaneCoeF32(const char * const strParamName, const Io3DPlaneCoeF32Array * const pstPlaneData) = 0;

			/**
			*  @brief  设置动态输入3D 3*3矩阵数据 float类型(仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DRMatrixF32Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DMatrix3F32(const char * const strParamName, const Io3DMatrix3F32Array * const pstMatrixData) = 0;

			/**
			*  @brief  设置动态输入3D 3*3矩阵数据 double类型(仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DMatrix3F64Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DMatrix3F64(const char * const strParamName, const Io3DMatrix3F64Array * const pstMatrixData) = 0;

			/**
			*  @brief  设置动态输入3D 4*4矩阵数据 float类型(仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DRTMatrixF32Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DMatrix4F32(const char * const strParamName, const Io3DMatrix4F32Array * const pstMatrixData) = 0;

			/**
			*  @brief  设置动态输入3D 4*4矩阵数据 double类型(仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DMatrix4F64Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DMatrix4F64(const char * const strParamName, const Io3DMatrix4F64Array * const pstMatrixData) = 0;

			/**
			*  @brief  设置动态输入机器人视觉参数 (仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DQuatPoseF32Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DRobotVision(const char * const strParamName, const Io3DRobotVision * const pstRobotVision) = 0;

			/**
			*  @brief  设置动态输入位姿信息 (仅当次执行起效)
			*  @param  参数名称
			*  @param  Io3DPoseInfoF64Array结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInput3DPoseInfoF64(const char * const strParamName, const Io3DPoseInfoF64Array * const pstPoseInfo) = 0;

			/**
			* @brief 设置2D凸包
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput2DCvxHullArray(IN const char * const strParamName, Io2DCvxHullArray* const pstCvxHullArray) = 0;

			/**
			* @brief 设置2D矩形顶点
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput2DRectCorArray(IN const char * const strParamName, Io2DRectCorArray* const pstRectCorArray) = 0;

			/**
			* @brief 设置2D包围盒
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput2DBoxLetArray(IN const char * const strParamName, Io2DBoxLetArray* const pstBboxArray) = 0;

			/**
			* @brief 设置3D包围盒角点
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DBBoxArray(IN const char * const strParamName, Io3DBBoxArray* const pstBBoxArray) = 0;

			/**
			* @brief 设置3D无角度包围盒
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DNoAngleBoxArray(IN const char * const strParamName, Io3DNoAngleBoxArray* const pstBoxArray) = 0;

			/**
			* @brief 设置3D有角度包围盒
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DOrientBoxArray(IN const char * const strParamName, Io3DOrinetBoxArray* const pstBoxArray) = 0;

			/**
			* @brief 设置3D圆
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DCircleArray(IN const char * const strParamName, Io3DCircleArray* const pstCircleArray) = 0;

			/**
			* @brief 设置3D圆环
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DRingArray(IN const char * const strParamName, Io3DRingArray* const pstRingArray) = 0;

			/**
			* @brief 设置3D圆柱面
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DCylinderSurfaceArray(IN const char * const strParamName, Io3DCylinderSurfaceArray* const pstCylinderSurfaceArray) = 0;

			/**
			* @brief 设置3D圆柱体
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DCylinderArray(IN const char * const strParamName, Io3DCylinderArray* const pstCylinderArray) = 0;

			/**
			* @brief 设置3D球体
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DSphereArray(IN const char * const strParamName, Io3DSphereArray* const pstSphereArray) = 0;

			/**
			* @brief 设置3D内切圆
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DInCircleArray(IN const char * const strParamName, Io3DInCircleArray* const pstInCircleArray) = 0;

			/**
			* @brief 设置3D外切圆
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DOutCircleArray(IN const char * const strParamName, Io3DOutCircleArray* const pstInCircleArray) = 0;

			/**
			* @brief 设置3D外接矩形角点
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DRectCornerPntArray(IN const char * const strParamName, Io3DRectCornerPointArray* const pstInRectCornerPointArray) = 0;

			/**
			* @brief 设置3D凸包点
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DConvexHullPointArray(IN const char * const strParamName, Io3DConvexHullPointArray* const pstInConvexHullPointArray) = 0;

			/**
			* @brief 设置3D凸包
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DConvexHullArray(IN const char * const strParamName, Io3DConvexHullArray* const pstInConvexHullArray) = 0;

			/**
			* @brief 设置3D实例分割信息顶点
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DInstanceObjTopPntArray(IN const char * const strParamName, Io3DTopPointArray* const pstInTopPointArray) = 0;

			/**
			* @brief 设置3D实例分割信息
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DInstanceObjInfoArray(IN const char * const strParamName, Io3DInstanceObjInfoArray* const pstInstanceObjInfoArray) = 0;

			/**
			* @brief 设置3D几何参数
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DGeoParamArray(IN const char * const strParamName, Io3DGeoParamArray* const pstGeoParamArray) = 0;

			/**
			* @brief 设置3D点云拓展信息
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DPCDExtInfoArray(IN const char * const strParamName, Io3DPCDExtInfoArray* const pstPCDExtInfoArray) = 0;

			/**
			* @brief 设置3D点云
			* @param 参数名称
			* @return
			* @par 注解
			* 目前点云个数只支持一个，不支持多个
			*/
			virtual void SetInput3DPointCloudArray(IN const char * const strParamName, Io3DPointCloudF32Array* const pstPCDArray) = 0;

			/**
			* @brief 设置3D矩形框
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual void SetInput3DRectBoxArray(IN const char * const strParamName, Io3DRectBoxF32Array* const pstRectBoxArray) = 0;
        };
        /*************************** Params Class End ***************************/

        /*************************** Tool Class Start ***************************/
        class IVmProcedureEvent
        {
        public:
            /**
            * @brief 流程开始执行状态回调
            * @param pstWorkStatus [IN] 流程状态
            * @param pUser [IN] 用户指针
            * @par 注解
            */
            virtual void OnWorkBeginStatusCallBack(IN const IMVS_PF_MODULE_WORK_STAUS * const pstWorkStatus, IN void * const pUser) = 0;

            /**
            * @brief 流程结束执行状态回调
            * @param pstWorkStatus [IN] 流程状态
            * @param pUser [IN] 用户指针
            * @par 注解
            */
            virtual void OnWorkEndStatusCallBack(IN const IMVS_PF_MODULE_WORK_STAUS * const pstWorkStatus, IN void * const pUser) = 0;
        };

        class IVmProcedure : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IVmProcedure() {}
            virtual ~IVmProcedure() {}

        public:
            /**
            * @brief 执行一次
            * @param 触发字符串
            * @param 是否等待执行结束
            * @return 无，出错时抛出异常
            * @par 注解
            * 流程执行一次
            */
            virtual void Run(IN const char * const strCmd = NULL, IN bool bIsWait = true) = 0;

            /**
            * @brief 执行一次
            * @param 触发字符串
            * @param 当前执行次数
            * @param 是否等待执行结束
            * @return 无，出错时抛出异常
            * @par 注解
            * 流程执行一次
            */
            virtual void Run(OUT unsigned int * const pnRunCount, IN const char * const strCmd = NULL, IN bool bIsWait = true) = 0;

            /**
            * @brief 执行一次点对点模式
            * @param 超时时间
            * @return 无，出错时抛出异常
            * @par 注解
            * 流程执行一次
            */
            virtual void RunP2P(IN unsigned int nTimeout) = 0;

            /**
            * @brief 连续运行
            * @param 无
            * @return 无，出错时抛出异常
            * @par 注解
            * 流程连续运行
            */
            virtual void Runing(void) = 0;

            /**
            * @brief 停止连续运行
            * @param 等待超时 （单位：秒）
            * @return 无，出错时抛出异常
            * @par 注解
            * 流程停止连续运行
            */
            virtual void StopRun(IN const unsigned int nWaitTime = 3) = 0;

            /**
            * @brief 设置连续运行时间间隔
            * @param 时间间隔 （单位：ms）
            * @return 无，出错时抛出异常
            * @par 注解
            * 设置流程连续运行时间间隔
            */
            virtual void SetRunInterval(IN const unsigned int nMilliSecond) = 0;

            /**
            * @brief 禁用流程
            * @param 无
            * @return 无
            * @par 注解
            */
            virtual void DisableProcedure(void) = 0;

            /**
            * @brief 启用流程
            * @param 无
            * @return 无
            * @par 注解
            */
            virtual void EnableProcedure(void) = 0;

            /**
            * @brief 流程是否禁用
            * @param 无
            * @return 流程禁用返回true，未禁用返回false
            * @par 注解
            */
            virtual bool IsProcedureDisable(void) = 0;

            /**
            * @brief 保存流程至文件
            * @param 流程路径
            * @param 流程文件密码（预留）
            * @return 无，出错时抛出异常
            * @par 注解
            * 弃用,推荐(SaveAsProcedure(const char * const strPrcPath, const char * const strPassword)
            */
            virtual void ExportProcess(IN const char * const strPrcPath, IN const char * const strPassword = NULL) = 0;

            /**
            * @brief 保存流程至文件
            * @param 流程路径
            * @param 流程文件密码（预留）
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual void SaveAsProcedure(IN const char * const strPrcPath, IN const char * const strPassword = NULL) = 0;

            /**
            * @brief 获取所有模块信息列表
            * @param 空
            * @return 所有模块信息列表
            * @par 注解
            */
            virtual ModuleInfoList * GetAllModuleList(void) = 0;

            /**
            * @brief 获取流程第一层级模块列表（不包含Group内部模块）
            * @param 空
            * @return 流程第一层级模块列表
            * @par 注解
            */
            virtual ModuleInfoList * GetProcedureModuleList(void) = 0;

            /**
            * @brief 设置流程运行策略接口
            * @param pstRunPolicyInfo [IN] 流程运行策略信息
            * @return 空
            * @par 注解
            */
            virtual void SetProcedureRunPolicy(IN const ProcedureRunPolicy * const pstRunPolicyInfo) = 0;

            /**
            * @brief 注册流程回调事件对象
            * @param pProcedureEvent [IN] 事件对象指针
            * @param pUser           [IN] 用户指针，注册时传入，回调时返回
            * @remarks 回调处理函数为子线程，函数中如需操作界面，建议使用自定义消息异步(MFC)或信号槽(QT)
            */
            virtual void RegisterCallBackEvent(IN IVmProcedureEvent* pProcedureEvent, IN void * const pUser) = 0;

            /**
            * @brief 解注册流程回调事件对象
            * @par 注解
            */
            virtual void UnRegisterCallBackEvent() = 0;

            /**
            * @brief 获取结果输出配置(V4.2废弃)
            * @param 输出配置参数
            * @return 整型结果
            * @par 注解
            */
            virtual IntResultInfo * GetIntOutputResult(IN const char * const strParam) = 0;

            /**
            * @brief 获取结果输出配置(V4.2废弃)
            * @param 输出配置参数
            * @return 浮点型结果
            * @par 注解
            */
            virtual FloatResultInfo * GetFloatOutputResult(IN const char * const strParam) = 0;

            /**
            * @brief 获取结果输出配置(V4.2废弃)
            * @param 输出配置参数
            * @return 字符串型结果
            * @par 注解
            */
            virtual StringResultInfo * GetStringOutputResult(IN const char * const strParam) = 0;

            /**
            * @brief 获取结果输出配置(V4.2废弃)
            * @param 输出配置参数
            * @return 图像像素结果
            * @par 注解
            */
            virtual ImageResultInfo * GetImageOutputResult(IN const char * const strParam) = 0;

            /**
            * @brief 获取结果输出配置(V4.2废弃)
            * @param 输出配置参数
            * @return 点集型结果
            * @par 注解
            */
            virtual PointsetResultInfo * GetPointsetOutputResult(IN const char * const strParam) = 0;

            /**
            * @brief 获取流程名称(UTF8格式)(预留，内部使用)
            * @param void
            * @return 流程名称
            * @par 注解
            */
            virtual const char * GetName(void) = 0;

            /**
            * @brief 获取内部所需信息(预留)
            * @param void
            * @return 流程内部信息
            * @par 注解
            */
            virtual void * GetControlInfo(void) = 0;
            /**
            * @par 说明
            * 参数对象，失败返回NULL
            * @par 注解
            * 通过参数对象可设置获取模块参数
            */
            virtual IMVSProcedureParams* GetParamObj() = 0;

            /**
            * @par 说明
            * 查找结果，未执行或执行失败返回NULL
            * @par 权限
            * 只读
            */
            virtual IMVSProcedureResults* GetResult() = 0;

        public:
            /**
            * @brief 根据名称获取模块对象
            * @param 模块显示名称
            * @return 模块对象指针
            * @par 注解
            */
            virtual void * operator[] (IN const char * const strKey) = 0;
        };
        /*************************** Tool Class End ***************************/
    }
}

/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

    /*  Note: Create tool instance for procedure. 
        brief: EN: Password parameter is reserved. | CH: 密码参数预留，暂不支持 */
    /* CH: 弃用,推荐(LoadProcedure(const char * const strPrcPath, const char * const strPassword, bool bIsOverrideGlobal = true)) | EN: Obsolete,recommend(LoadProcedure(const char * const strPrcPath, const char * const strPassword, bool bIsOverrideGlobal = true)) */
	IMVS_6000_PLATFORMSDK_API VisionMasterSDK::VmProcedure::IVmProcedure * __stdcall ImportProcess(IN const char * const strPrcPath, IN const char * const strPassword = NULL);
    /*  Note: Create tool instance for procedure.
    brief: EN: Password parameter is reserved. | CH: 密码参数预留，暂不支持 */
	IMVS_6000_PLATFORMSDK_API VisionMasterSDK::VmProcedure::IVmProcedure * __stdcall LoadProcedure(IN const char * const strPrcPath, IN const char * const strPassword = NULL, IN bool bIsOverrideGlobal = true);
    /*  Note: Destroy tool instance for procedure.  */
    IMVS_6000_PLATFORMSDK_API void __stdcall DestroyProcedureInstance(IN VisionMasterSDK::VmProcedure::IVmProcedure* pToolInstance);

#ifdef __cplusplus
}
#endif 

#endif    ///< _IVM_PROCEDURE_H_