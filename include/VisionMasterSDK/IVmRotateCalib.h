/***************************************************************************************************
 * File：IVmRotateCalib.h
 * Note：CH: 旋转标定模块接口声明 | En: Interface for the RotateCalib tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_ROTATECALIB_H_
#define _IVM_ROTATECALIB_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace RotateCalibModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the RotateCalibParams.  */
        class RotateCalibParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit RotateCalibParams() {}
            virtual ~RotateCalibParams() {}

        public:

            // CH: 图像点(仅当次执行起效) | EN: Image Point(Only valid for this execution)
            virtual void SetImagePoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 物理角度(仅当次执行起效) | EN: World Rotate Angle(Only valid for this execution)
            virtual void SetWorldRotateAngle(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 旋转次数(仅当次执行起效) | EN: Rotation Times(Only valid for this execution)
            virtual void SetRotNum(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 刷新信号(仅当次执行起效) | EN: Refresh Signal(Only valid for this execution)
            virtual void SetRefreshSignal(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 反向纠正 | EN: RevOutputFlag
            __declspec(property(put = SetRevOutputFlag, get = GetRevOutputFlag)) bool RevOutputFlag;

            virtual bool GetRevOutputFlag() = 0;

            virtual void SetRevOutputFlag(bool value) = 0;

            // CH: 加载标定文件 | EN: Load Calibration File
            __declspec(property(put = SetFilePath, get = GetFilePath)) const char* FilePath;

            virtual const char* GetFilePath() = 0;

            virtual void SetFilePath(const char* value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the RotateCalibResults.  */
        class RotateCalibResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit RotateCalibResults() {}
            virtual ~RotateCalibResults() {}

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
             * 剩余标定次数
             * @par 权限
             * 只读
             */
             virtual int GetRemainCount() = 0;

             /**
             * @par 说明
             * 旋转轴图像点
             * @par 权限
             * 只读
             */
             virtual PointF GetRotAxisPoint() = 0;

             /**
             * @par 说明
             * 旋转中心物理点
             * @par 权限
             * 只读
             */
             virtual PointF GetRotPhysicalPoint() = 0;

             /**
             * @par 说明
             * 旋转像素平均误差
             * @par 权限
             * 只读
             */
             virtual float GetRotError() = 0;

             /**
             * @par 说明
             * 旋转真实平均误差
             * @par 权限
             * 只读
             */
             virtual float GetRotWorldError() = 0;

        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the RotateCalib tool.  */
        class RotateCalibModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit RotateCalibModuTool() {}
            virtual ~RotateCalibModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual RotateCalibParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual RotateCalibResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            RotateCalibModuTool(RotateCalibModuTool&);
            RotateCalibModuTool& operator=(RotateCalibModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for RotateCalib.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::RotateCalibModu::RotateCalibModuTool * __stdcall GetRotateCalibToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_ROTATECALIB_H_
