/***************************************************************************************************
 * File：IVmVerticalLineFind.h
 * Note：CH: 垂线查找模块接口声明 | En: Interface for the VerticalLineFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_VERTICALLINEFIND_H_
#define _IVM_VERTICALLINEFIND_H_

#include "MVD_ShapeParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSVerticalLineFindModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 垂线类型 | EN: VerticalLine Type
        typedef enum _TypeEnum
        {
            // CH: 过点垂线 | EN: Point Perpendicular
            VerticalLinePoint = 0x0,

            // CH: 中垂线 | EN: Perpendicular Bisector
            VerticalLineMedian = 0x1,

        }TypeEnum;

        /*  Note: Interface Classes of the parameter of the VerticalLineFindParams.  */
        class VerticalLineFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit VerticalLineFindParams() {}
            virtual ~VerticalLineFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入点(仅当次执行起效) | EN: Input Point(Only valid for this execution)
            virtual void SetInputPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入直线(仅当次执行起效) | EN: Input Line(Only valid for this execution)
            virtual void SetInputLine(Line* pInputValue, unsigned int nValueNum) = 0;

            //CH: 垂线类型 | EN: VerticalLine Type
            __declspec(property(put = SetType, get = GetType)) TypeEnum Type;

            virtual TypeEnum GetType() = 0;

            virtual void SetType(TypeEnum value) = 0;
        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the VerticalLineFindResults.  */
        class VerticalLineFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit VerticalLineFindResults() {}
            virtual ~VerticalLineFindResults() {}

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
             * 测量点
             * @par 权限
             * 只读
             */
             virtual MVD_POINT_F GetMeasurePoint() = 0;
            /**
             * @par 说明
             * 测量直线
             * @par 权限
             * 只读
             */
             virtual Line GetMeasureLine() = 0;
            /**
             * @par 说明
             * 输出直线角度
             * @par 权限
             * 只读
             */
             virtual float GetOutputLineAngle() = 0;
            /**
             * @par 说明
             * 垂足点
             * @par 权限
             * 只读
             */
             virtual MVD_POINT_F GetFootPoint() = 0;
            /**
             * @par 说明
             * 垂线
             * @par 权限
             * 只读
             */
             virtual Line GetVerticalLine() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the VerticalLineFind tool.  */
        class IMVSVerticalLineFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSVerticalLineFindModuTool() {}
            virtual ~IMVSVerticalLineFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual VerticalLineFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual VerticalLineFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSVerticalLineFindModuTool(IMVSVerticalLineFindModuTool&);
            IMVSVerticalLineFindModuTool& operator=(IMVSVerticalLineFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for VerticalLineFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSVerticalLineFindModu::IMVSVerticalLineFindModuTool * __stdcall GetVerticalLineFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_VERTICALLINEFIND_H_
