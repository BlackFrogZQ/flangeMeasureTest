/***************************************************************************************************
 * File：IVmMultiPointAlign.h
 * Note：CH: 点集对位模块接口声明 | En: Interface for the MultiPointAlign tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MULTIPOINTALIGN_H_
#define _IVM_MULTIPOINTALIGN_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMultiPointAlignModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the MultiPointAlignParams.  */
        class MultiPointAlignParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MultiPointAlignParams() {}
            virtual ~MultiPointAlignParams() {}

        public:

            // CH: 目标点输入1(仅当次执行起效) | EN: TargetPointInput1(Only valid for this execution)
            virtual void SetTargetPointInput1(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入1(仅当次执行起效) | EN: ObjectPointInput1(Only valid for this execution)
            virtual void SetObjectPointInput1(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入2(仅当次执行起效) | EN: TargetPointInput2(Only valid for this execution)
            virtual void SetTargetPointInput2(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入2(仅当次执行起效) | EN: ObjectPointInput2(Only valid for this execution)
            virtual void SetObjectPointInput2(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入3(仅当次执行起效) | EN: TargetPointInput3(Only valid for this execution)
            virtual void SetTargetPointInput3(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入3(仅当次执行起效) | EN: ObjectPointInput3(Only valid for this execution)
            virtual void SetObjectPointInput3(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入4(仅当次执行起效) | EN: TargetPointInput4(Only valid for this execution)
            virtual void SetTargetPointInput4(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入4(仅当次执行起效) | EN: ObjectPointInput4(Only valid for this execution)
            virtual void SetObjectPointInput4(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入5(仅当次执行起效) | EN: TargetPointInput5(Only valid for this execution)
            virtual void SetTargetPointInput5(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入5(仅当次执行起效) | EN: ObjectPointInput5(Only valid for this execution)
            virtual void SetObjectPointInput5(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入6(仅当次执行起效) | EN: TargetPointInput6(Only valid for this execution)
            virtual void SetTargetPointInput6(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入6(仅当次执行起效) | EN: ObjectPointInput6(Only valid for this execution)
            virtual void SetObjectPointInput6(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入7(仅当次执行起效) | EN: TargetPointInput7(Only valid for this execution)
            virtual void SetTargetPointInput7(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入7(仅当次执行起效) | EN: ObjectPointInput7(Only valid for this execution)
            virtual void SetObjectPointInput7(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标点输入8(仅当次执行起效) | EN: TargetPointInput8(Only valid for this execution)
            virtual void SetTargetPointInput8(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入8(仅当次执行起效) | EN: ObjectPointInput8(Only valid for this execution)
            virtual void SetObjectPointInput8(PointF* pInputValue, unsigned int nValueNum) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the MultiPointAlignResults.  */
        class MultiPointAlignResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MultiPointAlignResults() {}
            virtual ~MultiPointAlignResults() {}

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
             * theta方向偏移
             * @par 权限
             * 只读
             */
            virtual float GetDeltaTheta() = 0;
            /**
             * @par 说明
             * x方向偏移
             * @par 权限
             * 只读
             */
            virtual float GetDeltaX() = 0;
            /**
             * @par 说明
             * y方向偏移
             * @par 权限
             * 只读
             */
            virtual float GetDeltaY() = 0;
            /**
             * @par 说明
             * 对位误差
             * @par 权限
             * 只读
             */
            virtual float GetAlignError() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the MultiPointAlign tool.  */
        class IMVSMultiPointAlignModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMultiPointAlignModuTool() {}
            virtual ~IMVSMultiPointAlignModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MultiPointAlignParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MultiPointAlignResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSMultiPointAlignModuTool(IMVSMultiPointAlignModuTool&);
            IMVSMultiPointAlignModuTool& operator=(IMVSMultiPointAlignModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MultiPointAlign.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMultiPointAlignModu::IMVSMultiPointAlignModuTool * __stdcall GetMultiPointAlignToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MULTIPOINTALIGN_H_
