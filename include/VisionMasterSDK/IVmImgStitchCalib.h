/***************************************************************************************************
 * File：IVmImgStitchCalib.h
 * Note：CH: 图像拼接模块接口声明 | En: Interface for the ImgStitchCalib tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_IMGSTITCHCALIB_H_
#define _IVM_IMGSTITCHCALIB_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSImgStitchCalibModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 输入方式 | EN: Input Mode
        typedef enum _InputTypeEnum
        {
            // CH: 单来源 | EN: Single
            InputType_SingleSource = 0x1,

            // CH: 多来源 | EN: Multiple
            InputType_MultipleSource = 0x2,

        }InputTypeEnum;

        // CH: 拼接类型 | EN: Stitch Type
        typedef enum _StitchTypeEnum
        {
            // CH: 模型拼接 | EN: Model Stitch
            StitchType_ModelStitch = 0x1,

            // CH: 硬拼接 | EN: Hard Stitch
            StitchType_HardStitch = 0x2,

        }StitchTypeEnum;

        // CH: 拼接方向 | EN: Stitch Direction
        typedef enum _StitchDirectionEnum
        {
            // CH: X方向 | EN: X-direction
            StitchDirection_XDirection = 0x1,

            // CH: Y方向 | EN: Y-direction
            StitchDirection_YDirection = 0x2,

        }StitchDirectionEnum;

        // CH: 融合模式 | EN: Stitch Merge Type
        typedef enum _MergeTypeEnum
        {
            // CH: 均值融合 | EN: MergeMean
            MergeType_MergeMean = 0x1,

            // CH: 最小值融合 | EN: MergeMin
            MergeType_MergeMin = 0x2,

            // CH: 最大值融合 | EN: MergeMax
            MergeType_MergeMax = 0x3,

            // CH: 接尾融合 | EN: MergeUncover
            MergeType_MergeUncover = 0x4,

        }MergeTypeEnum;

        /*  Note: Interface Classes of the parameter of the ImgStitchCalibParams.  */
        class ImgStitchCalibParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImgStitchCalibParams() {}
            virtual ~ImgStitchCalibParams() {}

        public:

            // CH: 输入图像0(仅当次执行起效) | EN: InputImage0(Only valid for this execution)
            virtual void SetInputImage0(ImageBaseData* pInputValue) = 0;

            // CH: 输入方式 | EN: Input Mode
            __declspec(property(put = SetInputType, get = GetInputType)) InputTypeEnum InputType;

            virtual InputTypeEnum GetInputType() = 0;

            virtual void SetInputType(InputTypeEnum value) = 0;

            // CH: 拼接类型 | EN: Stitch Type
            __declspec(property(put = SetStitchType, get = GetStitchType)) StitchTypeEnum StitchType;

            virtual StitchTypeEnum GetStitchType() = 0;

            virtual void SetStitchType(StitchTypeEnum value) = 0;

            // CH: 拼接数目 | EN: Stitch Number
            __declspec(property(put = SetImageNum, get = GetImageNum)) int ImageNum;

            virtual int GetImageNum() = 0;

            virtual void SetImageNum(int value) = 0;

            // CH: 拼接数目 | EN: Stitch Number
            __declspec(property(put = SetHardImageNum, get = GetHardImageNum)) int HardImageNum;

            virtual int GetHardImageNum() = 0;

            virtual void SetHardImageNum(int value) = 0;

            // CH: 拼接方式 | EN: Stitch Method
            __declspec(property(put = SetImageMatrix, get = GetImageMatrix)) const char* ImageMatrix;

            virtual const char* GetImageMatrix() = 0;

            virtual void SetImageMatrix(const char* value) = 0;

            // CH: 拼接方向 | EN: Stitch Direction
            __declspec(property(put = SetStitchDirection, get = GetStitchDirection)) StitchDirectionEnum StitchDirection;

            virtual StitchDirectionEnum GetStitchDirection() = 0;

            virtual void SetStitchDirection(StitchDirectionEnum value) = 0;

            // CH: 融合模式 | EN: Stitch Merge Type
            __declspec(property(put = SetMergeType, get = GetMergeType)) MergeTypeEnum MergeType;

            virtual MergeTypeEnum GetMergeType() = 0;

            virtual void SetMergeType(MergeTypeEnum value) = 0;

            // CH: 裁剪参数 | EN: CutRatio
            __declspec(property(put = SetCutRatio, get = GetCutRatio)) int CutRatio;

            virtual int GetCutRatio() = 0;

            virtual void SetCutRatio(int value) = 0;

            // CH: 自动清空 | EN: AutoClear
            __declspec(property(put = SetAutoClear, get = GetAutoClear)) bool AutoClear;

            virtual bool GetAutoClear() = 0;

            virtual void SetAutoClear(bool value) = 0;

            // CH: 自动填充 | EN: Auto Fill
            __declspec(property(put = SetAutoFill, get = GetAutoFill)) bool AutoFill;

            virtual bool GetAutoFill() = 0;

            virtual void SetAutoFill(bool value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ImgStitchCalibResults.  */
        class ImgStitchCalibResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ImgStitchCalibResults() {}
            virtual ~ImgStitchCalibResults() {}

        public:
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
            /**
             * @brief 获取拼接结果图像
             * @return 拼接结果图像
             * @par 注解
             * 无
             */
            virtual ImageBaseData GetStitchImage() = 0;
            /**
             * @par 说明
             * 当前图像数量
             * @par 权限
             * 只读
             */
            virtual int GetCurNum() = 0;
            /**
            * @par 说明
            * 图像总数量
            * @par 权限
            * 只读
            */
            virtual int GetTotalNum() = 0;
            /**
             * @brief 获取每张原图在拼接结果图中的位置信息
             * @param nIndex [in] 查询点的索引值，从0开始编码
             * @return 每张原图在拼接结果图中的位置信息
             * @par 注解
             * 无
             */
            virtual RectBox GetImagePosition(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ImgStitchCalib tool.  */
        class IMVSImgStitchCalibModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSImgStitchCalibModuTool() {}
            virtual ~IMVSImgStitchCalibModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ImgStitchCalibParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ImgStitchCalibResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;
            
            /**
            * @brief 导入模型
            * @param 模型路径
            * @return 无，出错时抛出异常
            * @par 注解
            * 导入模型
            */
            virtual void ImportModelData(IN const char * const strPath) = 0;

        private:
            IMVSImgStitchCalibModuTool(IMVSImgStitchCalibModuTool&);
            IMVSImgStitchCalibModuTool& operator=(IMVSImgStitchCalibModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ImgStitchCalib.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSImgStitchCalibModu::IMVSImgStitchCalibModuTool * __stdcall GetImgStitchCalibToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_IMGSTITCHCALIB_H_
