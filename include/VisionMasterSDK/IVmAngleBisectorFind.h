/***************************************************************************************************
 * File：IVmAngleBisectorFind.h
 * Note：CH: 角平分线查找模块接口声明 | En: Interface for the AngleBisectorFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_ANGLEBISECTORFIND_H_
#define _IVM_ANGLEBISECTORFIND_H_

#include "MVD_ShapeParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSAngleBisectorFindModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the AngleBisectorFindParams.  */
        class AngleBisectorFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit AngleBisectorFindParams() {}
            virtual ~AngleBisectorFindParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 输入直线1(仅当次执行起效) | EN: Input Line 1(Only valid for this execution)
            virtual void SetInputLine1(Line* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入直线2(仅当次执行起效) | EN: Input Line 2(Only valid for this execution)
            virtual void SetInputLine2(Line* pInputValue, unsigned int nValueNum) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the AngleBisectorFindResults.  */
        class AngleBisectorFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit AngleBisectorFindResults() {}
            virtual ~AngleBisectorFindResults() {}

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
             * 测量直线1
             * @par 权限
             * 只读
             */
             virtual Line GetMeasureLine1() = 0;
            /**
             * @par 说明
             * 测量直线2
             * @par 权限
             * 只读
             */
             virtual Line GetMeasureLine2() = 0;
            /**
             * @par 说明
             * 交点
             * @par 权限
             * 只读
             */
             virtual MVD_POINT_F GetIntersectionPt() = 0;
            /**
             * @par 说明
             * 角平分线
             * @par 权限
             * 只读
             */
             virtual Line GetAngleBisectorLine() = 0;
            /**
             * @par 说明
             * 角度标识点
             * @par nIndex [IN] 索引，范围:[0, 4]
             * @par 权限
             * 只读
             */
             virtual MVD_POINT_F GetAngleBisectorLine(IN int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the AngleBisectorFind tool.  */
        class IMVSAngleBisectorFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSAngleBisectorFindModuTool() {}
            virtual ~IMVSAngleBisectorFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual AngleBisectorFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual AngleBisectorFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSAngleBisectorFindModuTool(IMVSAngleBisectorFindModuTool&);
            IMVSAngleBisectorFindModuTool& operator=(IMVSAngleBisectorFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for AngleBisectorFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSAngleBisectorFindModu::IMVSAngleBisectorFindModuTool * __stdcall GetAngleBisectorFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_ANGLEBISECTORFIND_H_
