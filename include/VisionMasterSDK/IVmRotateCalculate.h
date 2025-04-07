/***************************************************************************************************
 * File：IVmRotateCalculate.h
 * Note：CH: 旋转计算模块接口声明 | En: Interface for the RotateCalculate tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_ROTATECALCULATE_H_
#define _IVM_ROTATECALCULATE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSRotateCalculateModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the RotateCalculateParams.  */
        class RotateCalculateParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit RotateCalculateParams() {}
            virtual ~RotateCalculateParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入点(仅当次执行起效) | EN: Input Point(Only valid for this execution)
            virtual void SetInputPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入直线(仅当次执行起效) | EN: Input Line(Only valid for this execution)
            virtual void SetInputLine(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 旋转中心(仅当次执行起效) | EN: Rotate Center(Only valid for this execution)
            virtual void SetRotateCenter(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 角度(仅当次执行起效) | EN: Angle(Only valid for this execution)
            virtual void SetAngle(float* pInputValue, unsigned int nValueNum) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the RotateCalculateResults.  */
        class RotateCalculateResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit RotateCalculateResults() {}
            virtual ~RotateCalculateResults() {}

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
             * 旋转中心点
             * @par 权限
             * 只读
             */
             virtual PointF GetInOutRotateCenterPt() = 0;
            /**
             * @par 说明
             * 点数量
             * @par 权限
             * 只读
             */
             virtual int GetPointNum() = 0;
            /**
             * @par 说明
             * 输入输出点
             * @par nIndex [IN] 索引
             * @par 权限
             * 只读
             */
             virtual PointF GetInputOutPoint(IN int nIndex) = 0;
            /**
             * @par 说明
             * 输出点
             * @par nIndex [IN] 索引
             * @par 权限
             * 只读
             */
             virtual PointF GetOutPoint(IN int nIndex) = 0;
            /**
             * @par 说明
             * 输入输出线
             * @par 权限
             * 只读
             */
             virtual Line GetInputOutLine() = 0;
            /**
             * @par 说明
             * 输出线
             * @par 权限
             * 只读
             */
             virtual Line GetOutLine() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the RotateCalculate tool.  */
        class IMVSRotateCalculateModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSRotateCalculateModuTool() {}
            virtual ~IMVSRotateCalculateModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual RotateCalculateParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual RotateCalculateResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSRotateCalculateModuTool(IMVSRotateCalculateModuTool&);
            IMVSRotateCalculateModuTool& operator=(IMVSRotateCalculateModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for RotateCalculate.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSRotateCalculateModu::IMVSRotateCalculateModuTool * __stdcall GetRotateCalculateToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_ROTATECALCULATE_H_
