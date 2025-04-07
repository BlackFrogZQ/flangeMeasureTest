/***************************************************************************************************
 * File：IVmRegionCopy.h
 * Note：CH: 拷贝填充模块接口声明 | En: Interface for the RegionCopy tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_REGIONCOPY_H_
#define _IVM_REGIONCOPY_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSRegionCopyModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 处理类型 | EN: Process Type
        typedef enum _RegionTypeEnum
        {
            // CH: 拷贝 | EN: Copy
            RegionType_Copy = 0x1,

            // CH: 填充 | EN: Fill
            RegionType_Fill = 0x2,

        }RegionTypeEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class RegionCopyRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

            // CH: 圆环ROI(仅当次执行起效) | EN: Annulus ROI(Only valid for this execution)
            virtual void SetRoiAnnulus(Annulus stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the RegionCopyParams.  */
        class RegionCopyParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit RegionCopyParams() {}
            virtual ~RegionCopyParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual RegionCopyRoiManager* GetModuRoiManager() = 0;

            // CH: 处理类型 | EN: Process Type
            __declspec(property(put = SetRegionType, get = GetRegionType)) RegionTypeEnum RegionType;

            virtual RegionTypeEnum GetRegionType() = 0;

            virtual void SetRegionType(RegionTypeEnum value) = 0;

            // CH: 区域内填充值 | EN: Inside Fill Value
            __declspec(property(put = SetFillVal, get = GetFillVal)) int FillVal;

            virtual int GetFillVal() = 0;

            virtual void SetFillVal(int value) = 0;

            // CH: 区域外填充值 | EN: Outside Fill Value
            __declspec(property(put = SetExtFillVal, get = GetExtFillVal)) int ExtFillVal;

            virtual int GetExtFillVal() = 0;

            virtual void SetExtFillVal(int value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the RegionCopyResults.  */
        class RegionCopyResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit RegionCopyResults() {}
            virtual ~RegionCopyResults() {}

        public:
             /**
             * @par 说明
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;

             /**
             * @par 说明
             * 输出掩膜
             * @par 权限
             * 只读
             */
             virtual ImageBaseData GetOutputMask() = 0;

             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
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
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the RegionCopy tool.  */
        class IMVSRegionCopyModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSRegionCopyModuTool() {}
            virtual ~IMVSRegionCopyModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual RegionCopyParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual RegionCopyResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSRegionCopyModuTool(IMVSRegionCopyModuTool&);
            IMVSRegionCopyModuTool& operator=(IMVSRegionCopyModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for RegionCopy.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSRegionCopyModu::IMVSRegionCopyModuTool * __stdcall GetRegionCopyToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_REGIONCOPY_H_
