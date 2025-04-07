/***************************************************************************************************
 * File：IVmBoxMerge.h
 * Note：CH: Box融合模块接口声明 | En: Interface for the BoxMerge tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_BOXMERGE_H_
#define _IVM_BOXMERGE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSBoxMergeModu
    {
        /*************************** Params Class Start ***************************/
        // CH: Box融合类型 | EN: Box Merge Type
        typedef enum _BoxMergeTypeEnum
        {
            // CH: 无条件融合并按缺陷优先级输出标签 | EN: Merge Type Flaw Priority
            BoxMergeType_MergeTypeFlawPriority = 0x1,

            // CH: 按标签类别融合并输出标签 | EN: Merge Type Box Label
            BoxMergeType_MergeTypeBoxLabel = 0x2,

            // CH: 无条件融合并随机输出标签 | EN: Merge Type No Box Label
            BoxMergeType_MergeTypeNoBoxLabel = 0x3,

        }BoxMergeTypeEnum;

        // CH: 标签分割符 | EN: Split Char
        typedef enum _SplitCharEnum
        {
            // ,
            SplitChar_Dot = 0x1,

            // :
            SplitChar_Colon = 0x2,

            // ;
            SplitChar_Semicolon = 0x3,

            // _
            SplitChar_Underline = 0x4,

        }SplitCharEnum;

        // CH: 优先级排序 | EN: Priority Sort Type
        typedef enum _PrioritySortTypeEnum
        {
            // CH: 降序 | EN: Grade Down
            PrioritySortType_PrioritySortDescend = 0x1,

            // CH: 升序 | EN: Grade Up
            PrioritySortType_PrioritySortAscend = 0x2,

        }PrioritySortTypeEnum;

        /*  Note: Interface Classes of the parameter of the BoxMergeParams.  */
        class BoxMergeParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BoxMergeParams() {}
            virtual ~BoxMergeParams() {}

        public:

            // CH: 输入Box(仅当次执行起效) | EN: Input Box(Only valid for this execution)
            virtual void SetInputBOX(RectBox* pInputValue, unsigned int nValueNum) = 0;

            // CH: Box标签(仅当次执行起效,长度小于128，A-Z、a-z、0-9、'_'、'-') | EN: Box labels(Only valid for this execution,length is less than 128, A-Z、a-z、0-9、'_'、'-')
            virtual void SetBoxLabel(InputStringData* pInputValue, unsigned int nValueNum) = 0;

			// CH: 缺陷优先级(仅当次执行起效) | EN: FlawPriority(Only valid for this execution)
            virtual void SetFlawPriority(InputStringData* pInputValue, unsigned int nValueNum) = 0;

            // CH: 重叠率 | EN: OverlapRate
            __declspec(property(put = SetOverlapThresh, get = GetOverlapThresh)) int OverlapThresh;

            virtual int GetOverlapThresh() = 0;

            virtual void SetOverlapThresh(int value) = 0;

            // CH: Box融合类型 | EN: Box Merge Type
            __declspec(property(put = SetBoxMergeType, get = GetBoxMergeType)) BoxMergeTypeEnum BoxMergeType;

            virtual BoxMergeTypeEnum GetBoxMergeType() = 0;

            virtual void SetBoxMergeType(BoxMergeTypeEnum value) = 0;

            // CH: 标签分割符 | EN: Split Char
            __declspec(property(put = SetSplitChar, get = GetSplitChar)) SplitCharEnum SplitChar;

            virtual SplitCharEnum GetSplitChar() = 0;

            virtual void SetSplitChar(SplitCharEnum value) = 0;

            // CH: 优先级排序 | EN: Priority Sort Type
            __declspec(property(put = SetPrioritySortType, get = GetPrioritySortType)) PrioritySortTypeEnum PrioritySortType;

            virtual PrioritySortTypeEnum GetPrioritySortType() = 0;

            virtual void SetPrioritySortType(PrioritySortTypeEnum value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the BoxMergeResults.  */
        class BoxMergeResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit BoxMergeResults() {}
            virtual ~BoxMergeResults() {}

        public:
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;

            /**
            * @brief 根据索引获取输出Box的信息
            * @param nIndex            [IN]    Box索引，范围[0, NumOfOutputBoxes)
            * @param pcLabel        [OUT]    Box标签
            * @return 指定索引处Box的信息，出错时抛出异常
            * @par 注解
            * 无
            */
            virtual RectBox GetOutputBoxData(unsigned int nIndex) = 0;
            /**
            * @brief 根据索引获取标签
            * @param pcLabel        [IN] Box标签
            * @return 指定标签，出错时抛出异常
            * @par 注解
            * 无
            */
            virtual const char * GetOutputBoxByLabel(unsigned int nIndex) = 0;
            /**
            * @par 说明
            * 获取重合的box数量
            * @par 权限
            * 只读
            */
            virtual unsigned int GetBoxMergeNum() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the BoxMerge tool.  */
        class IMVSBoxMergeModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSBoxMergeModuTool() {}
            virtual ~IMVSBoxMergeModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual BoxMergeParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual BoxMergeResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSBoxMergeModuTool(IMVSBoxMergeModuTool&);
            IMVSBoxMergeModuTool& operator=(IMVSBoxMergeModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for BoxMerge.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSBoxMergeModu::IMVSBoxMergeModuTool * __stdcall GetBoxMergeToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_BOXMERGE_H_
