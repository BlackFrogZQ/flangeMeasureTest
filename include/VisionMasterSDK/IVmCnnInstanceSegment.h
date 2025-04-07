/***************************************************************************************************
 * File：IVmCnnInstanceSegment.h
 * Note：CH: DL实例分割模块接口声明 | En: Interface for the CnnInstanceSegment tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CNNINSTANCESEGMENT_H_
#define _IVM_CNNINSTANCESEGMENT_H_

#include "MVD_ShapeParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

#ifndef MVD_CNN_INSTANCE_SEGMENT_LABEL_NAME_MAX_LEN
#define MVD_CNN_INSTANCE_SEGMENT_LABEL_NAME_MAX_LEN (128)
#endif

namespace VisionMasterSDK
{
    namespace IMVSCnnInstanceSegmentModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class CnnInstanceSegmentRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the CnnInstanceSegmentParams.  */
        class CnnInstanceSegmentParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnInstanceSegmentParams() {}
            virtual ~CnnInstanceSegmentParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual CnnInstanceSegmentRoiManager* GetModuRoiManager() = 0;

            // CH: 模型文件路径 | EN: Model File Path
            __declspec(property(put = SetLoadModelPath, get = GetLoadModelPath)) const char* LoadModelPath;

            virtual const char* GetLoadModelPath() = 0;

            virtual void SetLoadModelPath(const char* value) = 0;

            // CH: 方案存模型 | EN: Save Model Data
            __declspec(property(put = SetSaveModelDataEnable, get = GetSaveModelDataEnable)) bool SaveModelDataEnable;

            virtual bool GetSaveModelDataEnable() = 0;

            virtual void SetSaveModelDataEnable(bool value) = 0;

            // CH: 最大查找个数 | EN: Max Number to Find
            __declspec(property(put = SetMaxObjNum, get = GetMaxObjNum)) int MaxObjNum;

            virtual int GetMaxObjNum() = 0;

            virtual void SetMaxObjNum(int value) = 0;

            // CH: 目标框置信度 | EN: Target Confidence
            __declspec(property(put = SetMinScore, get = GetMinScore)) double MinScore;

            virtual double GetMinScore() = 0;

            virtual void SetMinScore(double value) = 0;

            // CH: 目标框重叠率 | EN: Target Overlap
            __declspec(property(put = SetMaxOverlap, get = GetMaxOverlap)) double MaxOverlap;

            virtual double GetMaxOverlap() = 0;

            virtual void SetMaxOverlap(double value) = 0;

            // CH: 掩膜置信度 | EN: Mask Confidence
            __declspec(property(put = SetMaskThresh, get = GetMaskThresh)) double MaskThresh;

            virtual double GetMaskThresh() = 0;

            virtual void SetMaskThresh(double value) = 0;

            // CH: 掩膜重叠率 | EN: Mask Overlap Threshold
            __declspec(property(put = SetMaskOverlap, get = GetMaskOverlap)) double MaskOverlap;

            virtual double GetMaskOverlap() = 0;

            virtual void SetMaskOverlap(double value) = 0;

            // CH: 边缘筛选使能 | EN: Edge Filter Enable
            __declspec(property(put = SetOutFilterEnable, get = GetOutFilterEnable)) bool OutFilterEnable;

            virtual bool GetOutFilterEnable() = 0;

            virtual void SetOutFilterEnable(bool value) = 0;

            // CH: 最小边缘分数 | EN: Min Edge Score
            __declspec(property(put = SetOutFilterScore, get = GetOutFilterScore)) double OutFilterScore;

            virtual double GetOutFilterScore() = 0;

            virtual void SetOutFilterScore(double value) = 0;

            // CH: 渲染输出图像 | EN: Render Mask Image
            __declspec(property(put = SetRenderMaskEnable, get = GetRenderMaskEnable)) bool RenderMaskEnable;

            virtual bool GetRenderMaskEnable() = 0;

            virtual void SetRenderMaskEnable(bool value) = 0;

            // CH: 不同类别过滤 | EN: Filter of Different Categories
            __declspec(property(put = SetDiffClassNMSEnable, get = GetDiffClassNMSEnable)) bool DiffClassNMSEnable;

            virtual bool GetDiffClassNMSEnable() = 0;

            virtual void SetDiffClassNMSEnable(bool value) = 0;

            // CH: 个数判断 | EN: Number Check
            __declspec(property(put = SetNumLimitEnable, get = GetNumLimitEnable)) bool NumLimitEnable;

            virtual bool GetNumLimitEnable() = 0;

            virtual void SetNumLimitEnable(bool value) = 0;

            // CH: 个数范围 | EN: Number Range
            __declspec(property(put = SetNumLimitLow, get = GetNumLimitLow)) int NumLimitLow;

            virtual int GetNumLimitLow() = 0;

            virtual void SetNumLimitLow(int value) = 0;

            // CH: 个数范围 | EN: Number Range
            __declspec(property(put = SetNumLimitHigh, get = GetNumLimitHigh)) int NumLimitHigh;

            virtual int GetNumLimitHigh() = 0;

            virtual void SetNumLimitHigh(int value) = 0;

            // CH: 置信度判断 | EN: Confidence Check
            __declspec(property(put = SetScoreLimitEnable, get = GetScoreLimitEnable)) bool ScoreLimitEnable;

            virtual bool GetScoreLimitEnable() = 0;

            virtual void SetScoreLimitEnable(bool value) = 0;

            // CH: 置信度范围 | EN: Confidence Range
            __declspec(property(put = SetScoreLimitLow, get = GetScoreLimitLow)) double ScoreLimitLow;

            virtual double GetScoreLimitLow() = 0;

            virtual void SetScoreLimitLow(double value) = 0;

            // CH: 置信度范围 | EN: Confidence Range
            __declspec(property(put = SetScoreLimitHigh, get = GetScoreLimitHigh)) double ScoreLimitHigh;

            virtual double GetScoreLimitHigh() = 0;

            virtual void SetScoreLimitHigh(double value) = 0;

            // CH: 类别号判断 | EN: Category No. Check
            __declspec(property(put = SetClassLimitEnable, get = GetClassLimitEnable)) bool ClassLimitEnable;

            virtual bool GetClassLimitEnable() = 0;

            virtual void SetClassLimitEnable(bool value) = 0;

            // CH: 类别号范围 | EN: No. Range
            __declspec(property(put = SetClassLimitLow, get = GetClassLimitLow)) int ClassLimitLow;

            virtual int GetClassLimitLow() = 0;

            virtual void SetClassLimitLow(int value) = 0;

            // CH: 类别号范围 | EN: No. Range
            __declspec(property(put = SetClassLimitHigh, get = GetClassLimitHigh)) int ClassLimitHigh;

            virtual int GetClassLimitHigh() = 0;

            virtual void SetClassLimitHigh(int value) = 0;

            // CH: 类别名称判断 | EN: Category Name Check
            __declspec(property(put = SetCategoryNameLimitEnable, get = GetCategoryNameLimitEnable)) bool CategoryNameLimitEnable;

            virtual bool GetCategoryNameLimitEnable() = 0;

            virtual void SetCategoryNameLimitEnable(bool value) = 0;

            // CH: 类别名称 | EN: ClassName
            __declspec(property(put = SetCategoryNameLimit, get = GetCategoryNameLimit)) const char* CategoryNameLimit;

            virtual const char* GetCategoryNameLimit() = 0;

            virtual void SetCategoryNameLimit(const char* value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        class ICNNInstanceSegmentInfo
        {
        protected:
            explicit ICNNInstanceSegmentInfo(){};
            virtual ~ICNNInstanceSegmentInfo(){};

        public:
            /**
            * @par 说明
            * 目标像素值
            * @par 权限
            * 只读
            */
            virtual int GetObjPixel() = 0;
            /**
            * @par 说明
            * 目标面积
            * @par 权限
            * 只读
            */
            virtual int GetObjArea() = 0;
            /**
             * @par 说明
             * 目标状态
             * @par 权限
             * 只读
             */
            virtual int GetObjStatus() = 0;
            /**
             * @par 说明
             * 分割出的目标标签值
             * @par 权限
             * 只读
             */
            virtual int GetLabel() = 0;
            /**
             * @par 说明
             * 分割出的目标置信度
             * @par 权限
             * 只读
             */
            virtual float GetConfidence() = 0;
            /**
             * @par 说明
             * 分割出的目标框属性
             * @par 权限
             * 只读
             */
            virtual RectBox GetSegmentBox() = 0;
            /**
             * @par 说明
             * 分割出的目标标签名称
             * @par 权限
             * 只读
             */
            virtual void GetLabelName(char pcLabelName[MVD_CNN_INSTANCE_SEGMENT_LABEL_NAME_MAX_LEN]) = 0;
            /**
             * @par 说明
             * 获取边缘点个数
             * @par 权限
             * 只读
             */
            virtual int GetEdgePointNum() = 0;
        };

        /*  Note: Interface Classes of the result of the CnnInstanceSegmentResults.  */
        class CnnInstanceSegmentResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnInstanceSegmentResults() {}
            virtual ~CnnInstanceSegmentResults() {}

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
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;
            /**
             * @par 说明
             * 实例分割图，像素值表明其所属的目标
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetSegmentMap() = 0;
            /**
            * @par 说明
            * 实例分割渲染图, 需开启渲染输出图像, 像素值表明其所属的目标,
            * @par 权限
            * 只读
            */
            virtual ImageBaseData GetSegmentRenderImage() = 0;
            /**
             * @par 说明
             * 分割信息的数量
             * @par 权限
             * 只读
             */
            virtual int GetSegmentNum() = 0;
            /**
             * @par 说明
             * 根据给定的索引获取分割信息
             * @par 权限
             * 只读
             */
            virtual ICNNInstanceSegmentInfo* GetSegmentInfo(int nIndex) = 0;
            /**
             * @par 说明
             * 多边形轮廓点数量
             * @par 权限
             * 只读
             */
            virtual int GetPolyonPointNum() = 0;
            /**
             * @par 说明
             * 多边形轮廓点
             * nIndex [IN] 索引
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetPolyonPoint(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CnnInstanceSegment tool.  */
        class IMVSCnnInstanceSegmentModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCnnInstanceSegmentModuTool() {}
            virtual ~IMVSCnnInstanceSegmentModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CnnInstanceSegmentParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CnnInstanceSegmentResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCnnInstanceSegmentModuTool(IMVSCnnInstanceSegmentModuTool&);
            IMVSCnnInstanceSegmentModuTool& operator=(IMVSCnnInstanceSegmentModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CnnInstanceSegment.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCnnInstanceSegmentModu::IMVSCnnInstanceSegmentModuTool * __stdcall GetCnnInstanceSegmentToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CNNINSTANCESEGMENT_H_
