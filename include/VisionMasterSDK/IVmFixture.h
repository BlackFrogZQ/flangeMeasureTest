/***************************************************************************************************
 * File：IVmFixture.h
 * Note：CH: 位置修正模块接口声明 | En: Interface for the Fixture tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_FIXTURE_H_
#define _IVM_FIXTURE_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSFixtureModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the FixtureParams.  */
        class FixtureParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit FixtureParams() {}
            virtual ~FixtureParams() {}

        public:

            // CH: 原点(仅当次执行起效) | EN: Origin(Only valid for this execution)
            virtual void SetOrigin(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 角度(仅当次执行起效) | EN: InAngle(Only valid for this execution)
            virtual void SetInAngle(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 尺度X(仅当次执行起效) | EN: MatchScaleX(Only valid for this execution)
            virtual void SetMatchScaleX(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 尺度Y(仅当次执行起效) | EN: MatchScaleY(Only valid for this execution)
            virtual void SetMatchScaleY(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 创建基准 | EN: Create Reference
            virtual int DoFixtureInit() = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the FixtureResults.  */
        class FixtureResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit FixtureResults() {}
            virtual ~FixtureResults() {}

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
             * 基准点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetFixturedPoint() = 0;

            /**
             * @par 说明
             * 基准角度
             * @par 权限
             * 只读
             */
            virtual float GetFixtureInitAngle() = 0;

            /**
             * @par 说明
             * 基准尺度X
             * @par 权限
             * 只读
             */
            virtual float GetFixtureInitScaleX() = 0;

            /**
             * @par 说明
             * 基准尺度Y
             * @par 权限
             * 只读
             */
            virtual float GetFixtureInitScaleY() = 0;

            /**
             * @par 说明
             * 运行点
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetFixtureRunPoint() = 0;

            /**
             * @par 说明
             * 运行角度
             * @par 权限
             * 只读
             */
            virtual float GetFixtureRunAngle() = 0;

            /**
             * @par 说明
             * 运行尺度X
             * @par 权限
             * 只读
             */
            virtual float GetFixtureRunScaleX() = 0;

            /**
             * @par 说明
             * 运行尺度Y
             * @par 权限
             * 只读
             */
            virtual float GetFixtureRunScaleY() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Fixture tool.  */
        class IMVSFixtureModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSFixtureModuTool() {}
            virtual ~IMVSFixtureModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual FixtureParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual FixtureResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSFixtureModuTool(IMVSFixtureModuTool&);
            IMVSFixtureModuTool& operator=(IMVSFixtureModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Fixture.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSFixtureModu::IMVSFixtureModuTool * __stdcall GetFixtureToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_FIXTURE_H_
