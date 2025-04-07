/***************************************************************************************************
 * File：IVmImageBuffer.h
 * Note：CH: 缓存图像模块接口声明 | En: Interface for the ImageBuffer tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMAGEBUFFER_H_
#define _IVM_IMAGEBUFFER_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace ImageBufferModule
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the ImageBufferParams.  */
        class ImageBufferParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageBufferParams() {}
            virtual ~ImageBufferParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 刷新标志(仅当次执行起效) | EN: Refresh Flag(Only valid for this execution)
            virtual void SetRefreshFlag(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 缓存数量(仅当次执行起效) | EN: Cache Quantity(Only valid for this execution)
            virtual void SetBufferCount(int* pInputValue, unsigned int nValueNum) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImageBufferResults.  */
        class ImageBufferResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageBufferResults() {}
            virtual ~ImageBufferResults() {}

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
             * 输出图像0
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage0() = 0;

            /**
             * @par 说明
             * 输出图像1
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage1() = 0;

            /**
             * @par 说明
             * 输出图像2
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage2() = 0;

            /**
             * @par 说明
             * 输出图像3
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage3() = 0;

            /**
             * @par 说明
             * 输出图像4
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage4() = 0;

            /**
             * @par 说明
             * 输出图像5
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage5() = 0;

            /**
             * @par 说明
             * 输出图像6
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage6() = 0;

            /**
             * @par 说明
             * 输出图像7
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage7() = 0;

            /**
             * @par 说明
             * 输出图像8
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage8() = 0;

            /**
             * @par 说明
             * 输出图像9
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage9() = 0;

            /**
             * @par 说明
             * 输出图像10
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage10() = 0;

            /**
             * @par 说明
             * 输出图像11
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage11() = 0;

            /**
             * @par 说明
             * 输出图像12
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage12() = 0;

            /**
             * @par 说明
             * 输出图像13
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage13() = 0;

            /**
             * @par 说明
             * 输出图像14
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutImage14() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImageBuffer tool.  */
        class ImageBufferModuleTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImageBufferModuleTool() {}
            virtual ~ImageBufferModuleTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImageBufferParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImageBufferResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            ImageBufferModuleTool(ImageBufferModuleTool&);
            ImageBufferModuleTool& operator=(ImageBufferModuleTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImageBuffer.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::ImageBufferModule::ImageBufferModuleTool * __stdcall GetImageBufferToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMAGEBUFFER_H_
