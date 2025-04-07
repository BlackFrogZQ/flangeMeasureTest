/***************************************************************************************************
 * File：IVmReadCalibFile.h
 * Note：CH: 标定加载模块接口声明 | En: Interface for the ReadCalibFile tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_READCALIBFILE_H_
#define _IVM_READCALIBFILE_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace ReadCalibFileModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the ReadCalibFileParams.  */
        class ReadCalibFileParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ReadCalibFileParams() {}
            virtual ~ReadCalibFileParams() {}

        public:

            // CH: 刷新信号(仅当次执行起效) | EN: Refresh Signal(Only valid for this execution)
            virtual void SetRefreshSignal(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: 图像基准坐标X(仅当次执行起效) | EN: Image Reference Coordinate X(Only valid for this execution)
            virtual void SetSnapImagePointX1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 图像基准坐标Y(仅当次执行起效) | EN: Image Reference Coordinate Y(Only valid for this execution)
            virtual void SetSnapImagePointY1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 图像基准坐标R(仅当次执行起效) | EN: Image Reference Coordinate R(Only valid for this execution)
            virtual void SetSnapImageR1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 拍照基准坐标X(仅当次执行起效) | EN: Photograph Reference Coordinate X(Only valid for this execution)
            virtual void SetSnapWorldPointX1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 拍照基准坐标Y(仅当次执行起效) | EN: Photograph Reference Coordinate Y(Only valid for this execution)
            virtual void SetSnapWorldPointY1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 拍照基准坐标R(仅当次执行起效) | EN: Photograph Reference Coordinate R(Only valid for this execution)
            virtual void SetSnapWorldR1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 示教坐标X(仅当次执行起效) | EN: Demonstration Coordinate X(Only valid for this execution)
            virtual void SetTeachWorldPointX1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 示教坐标Y(仅当次执行起效) | EN: Demonstration Coordinate Y(Only valid for this execution)
            virtual void SetTeachWorldPointY1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 示教坐标R(仅当次执行起效) | EN: Demonstration Coordinate R(Only valid for this execution)
            virtual void SetTeachWorldR1(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 方案存矩阵 | EN: Save Calib Data
            __declspec(property(put = SetSaveCalibDataEnable, get = GetSaveCalibDataEnable)) bool SaveCalibDataEnable;

            virtual bool GetSaveCalibDataEnable() = 0;

            virtual void SetSaveCalibDataEnable(bool value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the ReadCalibFileResults.  */
        class ReadCalibFileResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ReadCalibFileResults() {}
            virtual ~ReadCalibFileResults() {}

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
             * 角度旋转一致性
             * @par 权限
             * 只读
             */
             virtual int GetRotDirectionState() = 0;

            /**
             * @par 说明
             * 坐标系左右手一致性
             * @par 权限
             * 只读
             */
             virtual int GetIsRightCoorA() = 0;

            /**
             * @par 说明
             * 旋转中心图像坐标
             * @par 权限
             * 只读
             */
             virtual Posture GetRotCenterImage() = 0;

            /**
             * @par 说明
             * 旋转中心物理坐标
             * @par 权限
             * 只读
             */
             virtual Posture GetRotCenterWorld() = 0;
             
            /**
             * @par 说明
             * 图像基准坐标
             * @par 权限
             * 只读
             */
             virtual Posture GetSnapImage() = 0;

            /**
             * @par 说明
             * 拍照基准坐标
             * @par 权限
             * 只读
             */
             virtual Posture GetSnapWorld() = 0;

            /**
             * @par 说明
             * 示教坐标
             * @par 权限
             * 只读
             */
             virtual Posture GetTeachWorld() = 0;

            /**
             * @par 说明
             * 目标拍照坐标
             * @par 权限
             * 只读
             */
             virtual Posture GetSnapWorldCur() = 0;

            /**
             * @par 说明
             * 对象拍照坐标
             * @par 权限
             * 只读
             */
             virtual Posture GetSnapWorldObj() = 0;

            /**
             * @par 说明
             * 获取标定矩阵个数
             * @par 权限
             * 只读
             */
             virtual int GetCalibMatrixNum() = 0;

            /**
             * @par 说明
             * 获取标定矩阵值
             * @par 权限
             * 只读
             */
             virtual float GetCalibMatrix(IN int nIndex) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ReadCalibFile tool.  */
        class ReadCalibFileModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ReadCalibFileModuTool() {}
            virtual ~ReadCalibFileModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ReadCalibFileParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ReadCalibFileResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            ReadCalibFileModuTool(ReadCalibFileModuTool&);
            ReadCalibFileModuTool& operator=(ReadCalibFileModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ReadCalibFile.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::ReadCalibFileModu::ReadCalibFileModuTool * __stdcall GetReadCalibFileToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_READCALIBFILE_H_
