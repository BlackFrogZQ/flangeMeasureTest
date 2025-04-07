/***************************************************************************************************
 * File：IVmCnnFlaw.h
 * Note：CH: DL图像分割模块接口声明 | En: Interface for the CnnFlaw tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_CNNFLAW_H_
#define _IVM_CNNFLAW_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

#ifndef MVD_CNNSEGMENT_LABEL_NAME_MAX_LEN
#define MVD_CNNSEGMENT_LABEL_NAME_MAX_LEN (128)
#endif

#ifndef MVD_CNNSEGMENT_SCORE_HIST_BIN_NUM
#define MVD_CNNSEGMENT_SCORE_HIST_BIN_NUM (256)
#endif

namespace VisionMasterSDK
{
    namespace IMVSCnnFlawModu
    {        /*************************** Params Class Start ***************************/
        // CH: 运行模式 | EN: Operating Mode
        typedef enum _AlgRunModeEnum
        {
            // CH: 高性能模式 | EN: High Performance Mode
            AlgRunMode_HpMode = 0x0,

            // CH: 极速模式 | EN: Fast Mode
            AlgRunMode_FastMode = 0x1,

        }AlgRunModeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class CnnFlawRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the CnnFlawParams.  */
        class CnnFlawParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnFlawParams() {}
            virtual ~CnnFlawParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual CnnFlawRoiManager* GetModuRoiManager() = 0;

            // CH: 模型文件路径 | EN: Model File Path
            __declspec(property(put = SetLoadModelPath, get = GetLoadModelPath)) const char* LoadModelPath;

            virtual const char* GetLoadModelPath() = 0;

            virtual void SetLoadModelPath(const char* value) = 0;

            // CH: 方案存模型 | EN: Save Model Data
            __declspec(property(put = SetSaveModelDataEnable, get = GetSaveModelDataEnable)) bool SaveModelDataEnable;

            virtual bool GetSaveModelDataEnable() = 0;

            virtual void SetSaveModelDataEnable(bool value) = 0;

            // CH: 获取模型ROI使能 | EN: GetRoiFromModel Enable
            __declspec(property(put = SetRoiFromModelEnable, get = GetRoiFromModelEnable)) bool RoiFromModelEnable;

            virtual bool GetRoiFromModelEnable() = 0;

            virtual void SetRoiFromModelEnable(bool value) = 0;

            // CH: 按ROI裁图 | EN: Cut Via Roi
            __declspec(property(put = SetCutViaROIEnable, get = GetCutViaROIEnable)) bool CutViaROIEnable;

            virtual bool GetCutViaROIEnable() = 0;

            virtual void SetCutViaROIEnable(bool value) = 0;

            // CH: 采样系数 | EN: Sampling Coefficient
            __declspec(property(put = SetSampleInterval, get = GetSampleInterval)) int SampleInterval;

            virtual int GetSampleInterval() = 0;

            virtual void SetSampleInterval(int value) = 0;

            // CH: 运行模式 | EN: Operating Mode
            __declspec(property(put = SetAlgRunMode, get = GetAlgRunMode)) AlgRunModeEnum AlgRunMode;

            virtual AlgRunModeEnum GetAlgRunMode() = 0;

            virtual void SetAlgRunMode(AlgRunModeEnum value) = 0;

            // CH: 最小分数 | EN: Minimum Score
            __declspec(property(put = SetMinScore, get = GetMinScore)) int MinScore;

            virtual int GetMinScore() = 0;

            virtual void SetMinScore(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the CnnFlawResults.  */
        class CnnFlawResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit CnnFlawResults() {}
            virtual ~CnnFlawResults() {}

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
            * 获取类别数
            * @par 权限
            * 只读
            */
            virtual int GetClassNum() = 0;
            /**
            * @par 说明
            * 获取单类别标签名称
            * @par 权限
            * 只读
            */
            virtual void GetLabelName(IN int nIndex, OUT char szLabelName[MVD_CNNSEGMENT_LABEL_NAME_MAX_LEN]) = 0;
            /**
            * @par 说明
            * 获取灰度值数量
            * @par 权限
            * 只读
            */
            virtual int GetGrayValueNum() = 0;
            /**
            * @par 说明
            * 获取灰度值数量
            * @par 权限
            * 只读
            */
            virtual int GetGrayValue(int nIndex) = 0;
            /**
            * @par 说明
            * 获取最小分数
            * @par 权限
            * 只读
            */
            virtual int GetMinScore() = 0;
            /**
            * @par 说明
            * 获取图像分割类别图，像素值代表其所属的类别，背景的像素值为0
            * @par 权限
            * 只读
            */
            virtual ImageBaseData GetClassMap() = 0;
            /**
            * @par 说明
            * 显示概率图
            * @par 权限
            * 只读
            */
            virtual ImageBaseData GetScoreMap() = 0;
            /**
            * @par 说明
            * 获取概率直方图，用于调整阈值, 采用相对值(归一化)
            * @par 权限
            * 只读
            */
            virtual void GetScoreHist(unsigned int pnScoreHist[MVD_CNNSEGMENT_SCORE_HIST_BIN_NUM]) = 0;
            /**
            * @par 说明
            * 获取输出类别的缺陷概率图数量，需要在运行参数界面添加输出类别，没有添加时该数量为0，最大数量为8
            * @par 权限
            * 只读
            */
            virtual int GetOutputScoreImageNum() = 0;
            /**
            * @brief 说明
            * @param  按索引查询输出类别的缺陷概率图
            * @return 缺陷概率图
            * @par 注解
            * 无
            */
            virtual ImageBaseData QueryOutputScoreImageInfo(int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the CnnFlaw tool.  */
        class IMVSCnnFlawModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSCnnFlawModuTool() {}
            virtual ~IMVSCnnFlawModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual CnnFlawParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual CnnFlawResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSCnnFlawModuTool(IMVSCnnFlawModuTool&);
            IMVSCnnFlawModuTool& operator=(IMVSCnnFlawModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for CnnFlaw.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSCnnFlawModu::IMVSCnnFlawModuTool * __stdcall GetCnnFlawToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_CNNFLAW_H_
