/***************************************************************************************************
 * File：IVmColorExtract.h
 * Note：CH: 颜色抽取模块接口声明 | En: Interface for the ColorExtract tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_COLOREXTRACT_H_
#define _IVM_COLOREXTRACT_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSColorExtractModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the RoiManager.  */
        class ColorExtractRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ColorExtractParams.  */
        class ColorExtractParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ColorExtractParams() {}
            virtual ~ColorExtractParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ColorExtractRoiManager* GetModuRoiManager() = 0;

            // CH: 颜色面积判断 | EN: Color Total Area Check
            __declspec(property(put = SetAreaLimitEnable, get = GetAreaLimitEnable)) bool AreaLimitEnable;

            virtual bool GetAreaLimitEnable() = 0;

            virtual void SetAreaLimitEnable(bool value) = 0;

            // CH: 面积范围 | EN: Area Range
            __declspec(property(put = SetAreaLimitLow, get = GetAreaLimitLow)) double AreaLimitLow;

            virtual double GetAreaLimitLow() = 0;

            virtual void SetAreaLimitLow(double value) = 0;

            // CH: 面积范围 | EN: Area Range
            __declspec(property(put = SetAreaLimitHigh, get = GetAreaLimitHigh)) double AreaLimitHigh;

            virtual double GetAreaLimitHigh() = 0;

            virtual void SetAreaLimitHigh(double value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ColorExtractResults.  */
        class ColorExtractResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ColorExtractResults() {}
            virtual ~ColorExtractResults() {}

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
             * ROI圆弧
             * @par 权限
             * 只读
             */
             virtual Annulus GetROIAnnulus() = 0;
            /**
             * @par 说明
             * 输出图像
             * @par 权限
             * 只读
             */
            virtual ImageBaseData GetOutputImage() = 0;
            /**
             * @par 说明
             * 总面积
             * @par 权限
             * 只读
             */
            virtual float GetTotalArea() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ColorExtract tool.  */
        class IMVSColorExtractModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSColorExtractModuTool() {}
            virtual ~IMVSColorExtractModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ColorExtractParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ColorExtractResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSColorExtractModuTool(IMVSColorExtractModuTool&);
            IMVSColorExtractModuTool& operator=(IMVSColorExtractModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ColorExtract.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSColorExtractModu::IMVSColorExtractModuTool * __stdcall GetColorExtractToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_COLOREXTRACT_H_
