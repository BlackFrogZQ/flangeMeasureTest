/***************************************************************************************************
 * File：IVmSinglePointAlign.h
 * Note：CH: 单点对位模块接口声明 | En: Interface for the SinglePointAlign tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_SINGLEPOINTALIGN_H_
#define _IVM_SINGLEPOINTALIGN_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSSinglePointAlignModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the SinglePointAlignParams.  */
        class SinglePointAlignParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SinglePointAlignParams() {}
            virtual ~SinglePointAlignParams() {}

        public:

            // CH: 目标点输入(仅当次执行起效) | EN: TargetPointInput(Only valid for this execution)
            virtual void SetTargetPointInput(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标角度(仅当次执行起效) | EN: TargetAngle(Only valid for this execution)
            virtual void SetTargetAngle(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象点输入(仅当次执行起效) | EN: ObjectPointInput(Only valid for this execution)
            virtual void SetObjectPointInput(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 对象角度(仅当次执行起效) | EN: ObjectAngle(Only valid for this execution)
            virtual void SetObjectAngle(float* pInputValue, unsigned int nValueNum) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the SinglePointAlignResults.  */
        class SinglePointAlignResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SinglePointAlignResults() {}
            virtual ~SinglePointAlignResults() {}

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
             * 单点对位误差
             * @par 权限
             * 只读
             */
            virtual float GetAlignError() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the SinglePointAlign tool.  */
        class IMVSSinglePointAlignModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSSinglePointAlignModuTool() {}
            virtual ~IMVSSinglePointAlignModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual SinglePointAlignParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual SinglePointAlignResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSSinglePointAlignModuTool(IMVSSinglePointAlignModuTool&);
            IMVSSinglePointAlignModuTool& operator=(IMVSSinglePointAlignModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for SinglePointAlign.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSSinglePointAlignModu::IMVSSinglePointAlignModuTool * __stdcall GetSinglePointAlignToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_SINGLEPOINTALIGN_H_
