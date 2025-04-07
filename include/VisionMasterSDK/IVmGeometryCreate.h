/***************************************************************************************************
 * File：IVmGeometryCreate.h
 * Note：CH: 几何创建模块接口声明 | En: Interface for the GeometryCreate tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_GEOMETRYCREATE_H_
#define _IVM_GEOMETRYCREATE_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace GeometryCreate
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the GeometryCreateParams.  */
        class GeometryCreateParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GeometryCreateParams() {}
            virtual ~GeometryCreateParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入点(仅当次执行起效) | EN: Input Point(Only valid for this execution)
            virtual void SetInputPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入直线(仅当次执行起效) | EN: Input Line(Only valid for this execution)
            virtual void SetInputLine(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入圆(仅当次执行起效) | EN: Input Circle(Only valid for this execution)
            virtual void SetInputCircle(Annulus* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入Box(仅当次执行起效) | EN: Input Box (Only valid for this execution)
            virtual void SetInputBox(RectBox* pInputValue, unsigned int nValueNum) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the GeometryCreateResults.  */
        class GeometryCreateResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GeometryCreateResults() {}
            virtual ~GeometryCreateResults() {}

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
             * 输出点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetOutputPoint() = 0;

            /**
             * @par 说明
             * 输出直线
             * @par 权限
             * 只读
             */
            virtual Line GetOutputLine() = 0;

            /**
            * @par 说明
            * 输出直线角度
            * @par 权限
            * 只读
            */
            virtual float GetOutputLineAngle() = 0;

            /**
             * @par 说明
             * 输出圆
             * @par 权限
             * 只读
             */
            virtual Circle GetOutputCircle() = 0;

            /**
             * @par 说明
             * 点个数
             * @par 权限
             * 只读
             */
             virtual int GetOutputPointNum() = 0;

            /**
             * @par 说明
             * 输出点
             * @param nIndex [in] 输入点索引，[0,OutputPointNum)
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetOutputPointAt(int nIndex = 0) = 0;

            /**
             * @par 说明
             * 点个数
             * @par 权限
             * 只读
             */
            virtual int GetLineNum() = 0;

            /**
             * @par 说明
             * 输出直线
             * @param nIndex [in] 输入点索引，[0,LineNum)
             * @par 权限
             * 只读
             */
            virtual Line GetOutputLineAt(int nIndex = 0) = 0;

            /**
            * @par 说明
            * 输出直线角度
            * @param nIndex [in] 输入点索引，[0,LineNum)
            * @par 权限
            * 只读
            */
            virtual float GetOutputLineAngleAt(int nIndex = 0) = 0;

            /**
             * @par 说明
             * 圆个数
             * @par 权限
             * 只读
             */
            virtual int GetCircleNum() = 0;

            /**
             * @par 说明
             * 输出圆
             * @param nIndex [in] 输入点索引，[0,CircleNum)
             * @par 权限
             * 只读
             */
            virtual Annulus GetOutputCircleAt(int nIndex = 0) = 0;

            /**
             * @par 说明
             * 矩形个数
             * @par 权限
             * 只读
             */
            virtual int GetBoxNum() = 0;

            /**
             * @par 说明
             * 输出矩形
             * @par 权限
             * @param nIndex [in] 输入点索引，[0,BoxNum)
             * 只读
             */
            virtual RectBox GetOutputResultBoxAt(int nIndex = 0) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the GeometryCreate tool.  */
        class GeometryCreateTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit GeometryCreateTool() {}
            virtual ~GeometryCreateTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual GeometryCreateParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual GeometryCreateResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            GeometryCreateTool(GeometryCreateTool&);
            GeometryCreateTool& operator=(GeometryCreateTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for GeometryCreate.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::GeometryCreate::GeometryCreateTool * __stdcall GetGeometryCreateToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_GEOMETRYCREATE_H_
