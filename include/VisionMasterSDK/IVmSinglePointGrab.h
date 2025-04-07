/***************************************************************************************************
 * File：IVmSinglePointGrab.h
 * Note：CH: 单点抓取模块接口声明 | En: Interface for the SinglePointGrab tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_SINGLEPOINTGRAB_H_
#define _IVM_SINGLEPOINTGRAB_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace SinglePointGrabModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 标定类型 | EN: Calibration Type
        typedef enum _CalibTypeEnum
        {
            // CH: 平移标定 | EN: TransCalib
            CalibType_TransCalib = 0x0,

            // CH: 平移旋转标定 | EN: TransAndRotateCalib
            CalibType_TransAndRotateCalib = 0x1,

        }CalibTypeEnum;

        /*  Note: Interface Classes of the parameter of the SinglePointGrabParams.  */
        class SinglePointGrabParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SinglePointGrabParams() {}
            virtual ~SinglePointGrabParams() {}

        public:

            // CH: 像素点(仅当次执行起效) | EN: ImagePoint(Only valid for this execution)
            virtual void SetImagePoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 图像角度(仅当次执行起效) | EN: ImagePointA(Only valid for this execution)
            virtual void SetImagePointA(float* pInputValue, unsigned int nValueNum) = 0;

            // TeachPoint
            virtual void SetTeachPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // TeachPointA
            virtual void SetTeachPointA(float* pInputValue, unsigned int nValueNum) = 0;

            // TeachSnapPoint
            virtual void SetTeachSnapPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // TeachSnapPointA
            virtual void SetTeachSnapPointA(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标定矩阵(仅当次执行起效) | EN: Calibration Matrix(Only valid for this execution)
            virtual void SetCalibMatrix(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 刷新信号(仅当次执行起效) | EN: Refresh Signal(Only valid for this execution)
            virtual void SetRefreshSignal(int* pInputValue, unsigned int nValueNum) = 0;

            // SnapPointDeltaAngle
            virtual void SetSnapPointDeltaAngle(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 标定类型 | EN: Calibration Type
            __declspec(property(put = SetCalibType, get = GetCalibType)) CalibTypeEnum CalibType;

            virtual CalibTypeEnum GetCalibType() = 0;

            virtual void SetCalibType(CalibTypeEnum value) = 0;

            // CH: 旋转拍照使能 | EN: RunParam_SnapPointRotateEnable
            __declspec(property(put = SetSnapPointRotateEnable, get = GetSnapPointRotateEnable)) bool SnapPointRotateEnable;

            virtual bool GetSnapPointRotateEnable() = 0;

            virtual void SetSnapPointRotateEnable(bool value) = 0;

            // CH: 加载标定文件 | EN: Load Calibration File
            __declspec(property(put = SetFilePath, get = GetFilePath)) const char* FilePath;

            virtual const char* GetFilePath() = 0;

            virtual void SetFilePath(const char* value) = 0;

            // CH: 创建基准 | EN: Create Reference
            virtual int DoBasicInit() = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the SinglePointGrabResults.  */
        class SinglePointGrabResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SinglePointGrabResults() {}
            virtual ~SinglePointGrabResults() {}

        public:
             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;

             /**
             * @brief 获取基准点坐标
             * @return 返回基准点坐标
             */
             virtual PointF GetInitPoint() = 0;

             /**
             * @brief 获取基准点角度
             * @return 返回基准点角度
             */
             virtual float GetInitPointAngle() = 0;

             /**
             * @par 说明
             * 相对坐标X
             * @par 权限
             * 只读
             */
             virtual float GetOffsetX() = 0;

             /**
             * @par 说明
             * 相对坐标Y
             * @par 权限
             * 只读
             */
             virtual float GetOffsetY() = 0;

             /**
             * @par 说明
             * 相对坐标R
             * @par 权限
             * 只读
             */
             virtual float GetOffsetR() = 0;

             /**
             * @par 说明
             * 绝对坐标X
             * @par 权限
             * 只读
             */
             virtual float GetAbssetX() = 0;

             /**
             * @par 说明
             * 绝对坐标Y
             * @par 权限
             * 只读
             */
             virtual float GetAbssetY() = 0;

             /**
             * @par 说明
             * 绝对坐标R
             * @par 权限
             * 只读
             */
             virtual float GetAbssetR() = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the SinglePointGrab tool.  */
        class SinglePointGrabModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SinglePointGrabModuTool() {}
            virtual ~SinglePointGrabModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual SinglePointGrabParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual SinglePointGrabResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            SinglePointGrabModuTool(SinglePointGrabModuTool&);
            SinglePointGrabModuTool& operator=(SinglePointGrabModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for SinglePointGrab.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::SinglePointGrabModu::SinglePointGrabModuTool * __stdcall GetSinglePointGrabToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_SINGLEPOINTGRAB_H_
