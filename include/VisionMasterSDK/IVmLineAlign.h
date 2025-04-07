/***************************************************************************************************
 * File：IVmLineAlign.h
 * Note：CH: 线对位模块接口声明 | En: Interface for the LineAlign tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_LINEALIGN_H_
#define _IVM_LINEALIGN_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSLineAlignModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 对位形状 | EN: Alignment Shape
        typedef enum _AlignModeEnum
        {
            // CH: 开 | EN: Opening
            AlignMode_Open = 0,

            // CH: 闭 | EN: Closing
            AlignMode_Close = 1,

        }AlignModeEnum;

        /*  Note: Interface Classes of the parameter of the LineAlignParams.  */
        class LineAlignParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineAlignParams() {}
            virtual ~LineAlignParams() {}

        public:

            // CH: 目标线输入1(仅当次执行起效) | EN: TargetLineInput1(Only valid for this execution)
            virtual void SetTargetLineInput1(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线角度1(仅当次执行起效) | EN: TargetLineAngle1(Only valid for this execution)
            virtual void SetTargetLineAngle1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线输入1(仅当次执行起效) | EN: ObjectLineInput1(Only valid for this execution)
            virtual void SetObjectLineInput1(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线角度1(仅当次执行起效) | EN: ObjectLineAngle1(Only valid for this execution)
            virtual void SetObjectLineAngle1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线输入2(仅当次执行起效) | EN: TargetLineInput2(Only valid for this execution)
            virtual void SetTargetLineInput2(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线角度2(仅当次执行起效) | EN: TargetLineAngle2(Only valid for this execution)
            virtual void SetTargetLineAngle2(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线输入2(仅当次执行起效) | EN: ObjectLineInput2(Only valid for this execution)
            virtual void SetObjectLineInput2(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线角度2(仅当次执行起效) | EN: ObjectLineAngle2(Only valid for this execution)
            virtual void SetObjectLineAngle2(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线输入3(仅当次执行起效) | EN: TargetLineInput3(Only valid for this execution)
            virtual void SetTargetLineInput3(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线角度3(仅当次执行起效) | EN: TargetLineAngle3(Only valid for this execution)
            virtual void SetTargetLineAngle3(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线输入3(仅当次执行起效) | EN: ObjectLineInput3(Only valid for this execution)
            virtual void SetObjectLineInput3(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线角度3(仅当次执行起效) | EN: ObjectLineAngle3(Only valid for this execution)
            virtual void SetObjectLineAngle3(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线输入4(仅当次执行起效) | EN: TargetLineInput4(Only valid for this execution)
            virtual void SetTargetLineInput4(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线角度4(仅当次执行起效) | EN: TargetLineAngle4(Only valid for this execution)
            virtual void SetTargetLineAngle4(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线输入4(仅当次执行起效) | EN: ObjectLineInput4(Only valid for this execution)
            virtual void SetObjectLineInput4(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线角度4(仅当次执行起效) | EN: ObjectLineAngle4(Only valid for this execution)
            virtual void SetObjectLineAngle4(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线输入5(仅当次执行起效) | EN: TargetLineInput5(Only valid for this execution)
            virtual void SetTargetLineInput5(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线角度5(仅当次执行起效) | EN: TargetLineAngle5(Only valid for this execution)
            virtual void SetTargetLineAngle5(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线输入5(仅当次执行起效) | EN: ObjectLineInput5(Only valid for this execution)
            virtual void SetObjectLineInput5(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线角度5(仅当次执行起效) | EN: ObjectLineAngle5(Only valid for this execution)
            virtual void SetObjectLineAngle5(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线输入6(仅当次执行起效) | EN: TargetLineInput6(Only valid for this execution)
            virtual void SetTargetLineInput6(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线角度6(仅当次执行起效) | EN: TargetLineAngle6(Only valid for this execution)
            virtual void SetTargetLineAngle6(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线输入6(仅当次执行起效) | EN: ObjectLineInput6(Only valid for this execution)
            virtual void SetObjectLineInput6(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线角度6(仅当次执行起效) | EN: ObjectLineAngle6(Only valid for this execution)
            virtual void SetObjectLineAngle6(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线输入7(仅当次执行起效) | EN: TargetLineInput7(Only valid for this execution)
            virtual void SetTargetLineInput7(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线角度7(仅当次执行起效) | EN: TargetLineAngle7(Only valid for this execution)
            virtual void SetTargetLineAngle7(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线输入7(仅当次执行起效) | EN: ObjectLineInput7(Only valid for this execution)
            virtual void SetObjectLineInput7(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线角度7(仅当次执行起效) | EN: ObjectLineAngle7(Only valid for this execution)
            virtual void SetObjectLineAngle7(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线输入8(仅当次执行起效) | EN: TargetLineInput8(Only valid for this execution)
            virtual void SetTargetLineInput8(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标线角度8(仅当次执行起效) | EN: TargetLineAngle8(Only valid for this execution)
            virtual void SetTargetLineAngle8(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线输入8(仅当次执行起效) | EN: ObjectLineInput8(Only valid for this execution)
            virtual void SetObjectLineInput8(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象线角度8(仅当次执行起效) | EN: ObjectLineAngle8(Only valid for this execution)
            virtual void SetObjectLineAngle8(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对位形状 | EN: Alignment Shape
            __declspec(property(put = SetAlignMode, get = GetAlignMode)) AlignModeEnum AlignMode;

            virtual AlignModeEnum GetAlignMode() = 0;

            virtual void SetAlignMode(AlignModeEnum value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the LineAlignResults.  */
        class LineAlignResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit LineAlignResults() {}
            virtual ~LineAlignResults() {}

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
             * x偏移
             * @par 权限
             * 只读
             */
            /*  Note: ratioX of camera map. */
            virtual float GetDeltaX() = 0;

            /**
             * @par 说明
             * y偏移
             * @par 权限
             * 只读
             */
            /*  Note: ratioX of camera map. */
            virtual float GetDeltaY() = 0;

            /**
             * @par 说明
             * theta偏移
             * @par 权限
             * 只读
             */
            /*  Note: ratioX of camera map. */
            virtual float GetDeltaTheta() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the LineAlign tool.  */
        class IMVSLineAlignModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSLineAlignModuTool() {}
            virtual ~IMVSLineAlignModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual LineAlignParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual LineAlignResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSLineAlignModuTool(IMVSLineAlignModuTool&);
            IMVSLineAlignModuTool& operator=(IMVSLineAlignModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for LineAlign.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSLineAlignModu::IMVSLineAlignModuTool * __stdcall GetLineAlignToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_LINEALIGN_H_
