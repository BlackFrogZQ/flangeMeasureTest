/***************************************************************************************************
 * File：IVmArray2dCorrect.h
 * Note：CH: 二维阵列模块接口声明 | En: Interface for the Array2dCorrect tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_ARRAY2DCORRECT_H_
#define _IVM_ARRAY2DCORRECT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVS2dArrayCorrectModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the Array2dCorrectParams.  */
        class Array2dCorrectParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit Array2dCorrectParams() {}
            virtual ~Array2dCorrectParams() {}

        public:

            // CH: 区域(仅当次执行起效) | EN: Region(Only valid for this execution)
            virtual void SetInputBox(RectBox* pInputValue, unsigned int nValueNum) = 0;

            // CH: 阵列行数 | EN: Array Rows
            __declspec(property(put = SetArrayRowsNum, get = GetArrayRowsNum)) int ArrayRowsNum;

            virtual int GetArrayRowsNum() = 0;

            virtual void SetArrayRowsNum(int value) = 0;

            // CH: 阵列列数 | EN: Array Columns
            __declspec(property(put = SetArrayColsNum, get = GetArrayColsNum)) int ArrayColsNum;

            virtual int GetArrayColsNum() = 0;

            virtual void SetArrayColsNum(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the Array2dCorrectResults.  */
        class Array2dCorrectResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit Array2dCorrectResults() {}
            virtual ~Array2dCorrectResults() {}

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
            * 获取修正后的Box数量
            * @par 权限
            * 只读
            */
            virtual unsigned int GetNumOfArrayBoxes() = 0;
            /**
            * @par 说明
            * 获取最小包围行的Box数量
            * @par 权限
            * 只读
            */
            virtual unsigned int GetNumOfRowBoxes() = 0;
            /**
            * @brief 根据索引获取修正后的Box信息
            * @param nIndex [IN] 修正后的Box索引，范围[0, NumOfArrayBoxes)
            * @return 指定索引处Box的信息，出错时抛出异常
            * @par 注解
            */
            virtual RectBox GetArrayBoxAt(unsigned int nIndex) = 0;
            /**
            * @brief 根据索引获取最小包围行的Box信息
            * @param nIndex [IN] 最小包围行的Box索引，范围[0, NumOfRowBox)
            * @return 指定索引处Box的信息，出错时抛出异常
            * @par 注解
            */
            virtual RectBox GetRowBoxAt(unsigned int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the Array2dCorrect tool.  */
        class IMVS2dArrayCorrectModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVS2dArrayCorrectModuTool() {}
            virtual ~IMVS2dArrayCorrectModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual Array2dCorrectParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual Array2dCorrectResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVS2dArrayCorrectModuTool(IMVS2dArrayCorrectModuTool&);
            IMVS2dArrayCorrectModuTool& operator=(IMVS2dArrayCorrectModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for Array2dCorrect.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVS2dArrayCorrectModu::IMVS2dArrayCorrectModuTool * __stdcall GetArray2dCorrectToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_ARRAY2DCORRECT_H_
