/***************************************************************************************************
 * File：IVmCoordinateTransform.h
 * Note：CH: 坐标转化模块接口声明 | En: Interface for the CoordinateTransform tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_COORDINATETRANSFORM_H_
#define _IVM_COORDINATETRANSFORM_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace CoordinateTransform
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the CoordinateTransformParams.  */
        class CoordinateTransformParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CoordinateTransformParams() {}
            virtual ~CoordinateTransformParams() {}

        public:

            // CH: 划片中心点(仅当次执行起效) | EN: Dicing Center Point(Only valid for this execution)
            virtual void SetDicingPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 划片宽(仅当次执行起效) | EN: Dicing Width(Only valid for this execution)
            virtual void SetDicingImageWidth(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 划片高(仅当次执行起效) | EN: Dicing Height(Only valid for this execution)
            virtual void SetDicingImageHeight(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入点(仅当次执行起效) | EN: Input Point(Only valid for this execution)
            virtual void SetSrcInputPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 坐标转换使能 | EN: Coordinate Conversion
            __declspec(property(put = SetCorrectEnable, get = GetCorrectEnable)) bool CorrectEnable;

            virtual bool GetCorrectEnable() = 0;

            virtual void SetCorrectEnable(bool value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the CoordinateTransformResults.  */
        class CoordinateTransformResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CoordinateTransformResults() {}
            virtual ~CoordinateTransformResults() {}

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
            * 输出点数量
            * @par 权限
            * 只读
            */
            virtual int GetDstPointNum() = 0;
            /**
            * @par 说明
            * 输出点
            * @par 权限
            * 只读
            */
            virtual PointF GetDstPointAt(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CoordinateTransform tool.  */
        class CoordinateTransformTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CoordinateTransformTool() {}
            virtual ~CoordinateTransformTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CoordinateTransformParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CoordinateTransformResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            CoordinateTransformTool(CoordinateTransformTool&);
            CoordinateTransformTool& operator=(CoordinateTransformTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CoordinateTransform.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::CoordinateTransform::CoordinateTransformTool * __stdcall GetCoordinateTransformToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_COORDINATETRANSFORM_H_
