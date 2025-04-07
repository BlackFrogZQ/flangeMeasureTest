/***************************************************************************************************
 * File：IVmSinglePointMapAlign.h
 * Note：CH: 单点映射对位模块接口声明 | En: Interface for the SinglePointMapAlign tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_SINGLEPOINTMAPALIGN_H_
#define _IVM_SINGLEPOINTMAPALIGN_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace SinglePointMapAlignModu
    {
        /*************************** Params Class Start ***************************/
        /*  Note: Interface Classes of the parameter of the SinglePointMapAlignParams.  */
        class SinglePointMapAlignParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SinglePointMapAlignParams() {}
            virtual ~SinglePointMapAlignParams() {}

        public:

            // CH: 对象像素点(仅当次执行起效) | EN: ObjImagePoint(Only valid for this execution)
            virtual void SetObjImagePoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // ObjImagePointA
            virtual void SetObjImagePointA(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标像素点(仅当次执行起效) | EN: TarImagePoint(Only valid for this execution)
            virtual void SetTarImagePoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标像素直线起点(仅当次执行起效) | EN: TarImageLineS(Only valid for this execution)
            virtual void SetTarImageLineS(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 目标像素直线终点(仅当次执行起效) | EN: TarImageLineE(Only valid for this execution)
            virtual void SetTarImageLineE(PointF* pInputValue, unsigned int nValueNum) = 0;

            // TeachPoint
            virtual void SetTeachPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // TeachPointA
            virtual void SetTeachPointA(float* pInputValue, unsigned int nValueNum) = 0;

            // NPointCalibMatrix
            virtual void SetNPointCalibMatrix(float* pInputValue, unsigned int nValueNum) = 0;

            // MapCalibMatrix
            virtual void SetMapCalibMatrix(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 刷新信号(仅当次执行起效) | EN: Refresh Signal(Only valid for this execution)
            virtual void SetRefreshSignal(int* pInputValue, unsigned int nValueNum) = 0;

            // CH: N点标定文件 | EN: N Calibration File
            __declspec(property(put = SetFilePath, get = GetFilePath)) const char* FilePath;

            virtual const char* GetFilePath() = 0;

            virtual void SetFilePath(const char* value) = 0;

            // CH: 映射标定文件 | EN: Load MapCalibration File
            __declspec(property(put = SetFilePathMap, get = GetFilePathMap)) const char* FilePathMap;

            virtual const char* GetFilePathMap() = 0;

            virtual void SetFilePathMap(const char* value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the SinglePointMapAlignResults.  */
        class SinglePointMapAlignResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SinglePointMapAlignResults() {}
            virtual ~SinglePointMapAlignResults() {}

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
        /*  Note: Note: This is the class for the SinglePointMapAlign tool.  */
        class SinglePointMapAlignModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit SinglePointMapAlignModuTool() {}
            virtual ~SinglePointMapAlignModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual SinglePointMapAlignParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual SinglePointMapAlignResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            SinglePointMapAlignModuTool(SinglePointMapAlignModuTool&);
            SinglePointMapAlignModuTool& operator=(SinglePointMapAlignModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for SinglePointMapAlign.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::SinglePointMapAlignModu::SinglePointMapAlignModuTool * __stdcall GetSinglePointMapAlignToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_SINGLEPOINTMAPALIGN_H_
