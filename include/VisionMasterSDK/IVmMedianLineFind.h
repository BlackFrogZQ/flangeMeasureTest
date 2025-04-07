/***************************************************************************************************
 * File：IVmMedianLineFind.h
 * Note：CH: 中线查找模块接口声明 | En: Interface for the MedianLineFind tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_MEDIANLINEFIND_H_
#define _IVM_MEDIANLINEFIND_H_

#include "MVD_ShapeParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSMedianLineFindModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the MedianLineFindParams.  */
        class MedianLineFindParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MedianLineFindParams() {}
            virtual ~MedianLineFindParams() {}

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
        /*  Note: Interface Classes of the result of the MedianLineFindResults.  */
        class MedianLineFindResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit MedianLineFindResults() {}
            virtual ~MedianLineFindResults() {}

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
             * 中线
             * @par 权限
             * 只读
             */
             virtual Line GetMedianLine() = 0;
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
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the MedianLineFind tool.  */
        class IMVSMedianLineFindModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSMedianLineFindModuTool() {}
            virtual ~IMVSMedianLineFindModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual MedianLineFindParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual MedianLineFindResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSMedianLineFindModuTool(IMVSMedianLineFindModuTool&);
            IMVSMedianLineFindModuTool& operator=(IMVSMedianLineFindModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for MedianLineFind.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSMedianLineFindModu::IMVSMedianLineFindModuTool * __stdcall GetMedianLineFindToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_MEDIANLINEFIND_H_
