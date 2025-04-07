/***************************************************************************************************
 * File：IVmNImageCalib.h
 * Note：CH: N图像标定模块接口声明 | En: Interface for the NImageCalib tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_NIMAGECALIB_H_
#define _IVM_NIMAGECALIB_H_

#include "MVD_AlgoParamDefine.h"

using namespace VisionDesigner;

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSNImageCalibModu
    {
        /*************************** Params Class Start ***************************/
        // CH: 移动优先 | EN: Movement First
        typedef enum _MoveFirstTypeEnum
        {
            // CH: X优先 | EN: X First
            MoveFirstType_XFirst = 0x1,

            // CH: Y优先 | EN: Y First
            MoveFirstType_YFirst = 0x2,

        }MoveFirstTypeEnum;

        // CH: 标定板类型 | EN: Calibration Board Type
        typedef enum _CalibBoardTypeEnum
        {
            // CH: 海康标定板I型 | EN: Hikvision I Calibration Board
            CalibBoardType_TypeHKI = 0x7,

            // CH: 海康标定板II型 | EN: Hikvision II Calibration Board
            CalibBoardType_TypeHKII = 0x6,

        }CalibBoardTypeEnum;

        // CH: 中值滤波状态 | EN: Median Filtering State
        typedef enum _FilterStatusEnum
        {
            // CH: 执行滤波 | EN: Execution Filtering
            FilterStatus_FilterStateTure = 0x1,

            // CH: 无滤波 | EN: No Filter
            FilterStatus_FilterStateFalse = 0x2,

        }FilterStatusEnum;

        // CH: 亚像素窗口 | EN: Sub-pixel window
        typedef enum _SubpixelWinAutoEnum
        {
            // CH: 自适应 | EN: Self-Adaption
            SubpixelWinAuto_SubpixelWinSizeAuto = 0x1,

            // CH: 设置值 | EN: Set
            SubpixelWinAuto_SubpixelWinSizeUser = 0x2,

        }SubpixelWinAutoEnum;

        /*  Note: Interface Classes of the parameter of the NImageCalibParams.  */
        class NImageCalibParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit NImageCalibParams() {}
            virtual ~NImageCalibParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: 图像点(仅当次执行起效) | EN: Image Point(Only valid for this execution)
            virtual void SetImagePoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 物理点(仅当次执行起效) | EN: Physical Point(Only valid for this execution)
            virtual void SetPhysicalPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 外部输入字符(仅当次执行起效) | EN: External Input Character(Only valid for this execution)
            virtual void SetPhyPoint(PointF* pInputValue, unsigned int nValueNum) = 0;

            // CH: 旋转角度(仅当次执行起效) | EN: Rotation Angle(Only valid for this execution)
            virtual void SetRotateAngle(float* pInputValue, unsigned int nValueNum) = 0;

            // CH: 平移次数 | EN: Translation Times
            __declspec(property(put = SetCalibPointTotalNum, get = GetCalibPointTotalNum)) int CalibPointTotalNum;

            virtual int GetCalibPointTotalNum() = 0;

            virtual void SetCalibPointTotalNum(int value) = 0;

            // CH: 旋转次数 | EN: Rotation Times
            __declspec(property(put = SetRotPointTotalNum, get = GetRotPointTotalNum)) int RotPointTotalNum;

            virtual int GetRotPointTotalNum() = 0;

            virtual void SetRotPointTotalNum(int value) = 0;

            // CH: 基准点X | EN: InitPointX
            __declspec(property(put = SetBasePointX, get = GetBasePointX)) double BasePointX;

            virtual double GetBasePointX() = 0;

            virtual void SetBasePointX(double value) = 0;

            // CH: 基准点Y | EN: InitPointY
            __declspec(property(put = SetBasePointY, get = GetBasePointY)) double BasePointY;

            virtual double GetBasePointY() = 0;

            virtual void SetBasePointY(double value) = 0;

            // CH: 偏移X | EN: Offset X
            __declspec(property(put = SetMoveAlignX, get = GetMoveAlignX)) double MoveAlignX;

            virtual double GetMoveAlignX() = 0;

            virtual void SetMoveAlignX(double value) = 0;

            // CH: 偏移Y | EN: Offset Y
            __declspec(property(put = SetMoveAlignY, get = GetMoveAlignY)) double MoveAlignY;

            virtual double GetMoveAlignY() = 0;

            virtual void SetMoveAlignY(double value) = 0;

            // CH: 移动优先 | EN: Movement First
            __declspec(property(put = SetMoveFirstType, get = GetMoveFirstType)) MoveFirstTypeEnum MoveFirstType;

            virtual MoveFirstTypeEnum GetMoveFirstType() = 0;

            virtual void SetMoveFirstType(MoveFirstTypeEnum value) = 0;

            // CH: 换向移动次数 | EN: Commutation Number
            __declspec(property(put = SetChangeDirectionMoveTime, get = GetChangeDirectionMoveTime)) int ChangeDirectionMoveTime;

            virtual int GetChangeDirectionMoveTime() = 0;

            virtual void SetChangeDirectionMoveTime(int value) = 0;

            // CH: 基准角度 | EN: InitAngle
            __declspec(property(put = SetBaseAngle, get = GetBaseAngle)) double BaseAngle;

            virtual double GetBaseAngle() = 0;

            virtual void SetBaseAngle(double value) = 0;

            // CH: 角度偏移 | EN: Angle Offset
            __declspec(property(put = SetMoveAngle, get = GetMoveAngle)) double MoveAngle;

            virtual double GetMoveAngle() = 0;

            virtual void SetMoveAngle(double value) = 0;

            // CH: 矩阵修正 | EN: Homo Fix
            __declspec(property(put = SetHomoFixEnable, get = GetHomoFixEnable)) bool HomoFixEnable;

            virtual bool GetHomoFixEnable() = 0;

            virtual void SetHomoFixEnable(bool value) = 0;

            // CH: 更新文件 | EN: Update File
            __declspec(property(put = SetRefreshFileEnable, get = GetRefreshFileEnable)) bool RefreshFileEnable;

            virtual bool GetRefreshFileEnable() = 0;

            virtual void SetRefreshFileEnable(bool value) = 0;

            // CH: 标定文件路径 | EN: Set Calibration File Path
            __declspec(property(put = SetCalibPathName, get = GetCalibPathName)) const char* CalibPathName;

            virtual const char* GetCalibPathName() = 0;

            virtual void SetCalibPathName(const char* value) = 0;

            // CH: 相机移动 | EN: Camera Movement
            __declspec(property(put = SetCareraMove, get = GetCareraMove)) bool CareraMove;

            virtual bool GetCareraMove() = 0;

            virtual void SetCareraMove(bool value) = 0;

            // CH: 标定板类型 | EN: Calibration Board Type
            __declspec(property(put = SetCalibBoardType, get = GetCalibBoardType)) CalibBoardTypeEnum CalibBoardType;

            virtual CalibBoardTypeEnum GetCalibBoardType() = 0;

            virtual void SetCalibBoardType(CalibBoardTypeEnum value) = 0;

            // CH: 弃用 | EN: Obsolete
            // CH: 灰度对比度 | EN: Grayscale Contrast
            __declspec(property(put = SetGrayContrast, get = GetGrayContrast)) int GrayContrast;

            virtual int GetGrayContrast() = 0;

            virtual void SetGrayContrast(int value) = 0;

            // CH: 中值滤波状态 | EN: Median Filtering State
            __declspec(property(put = SetFilterStatus, get = GetFilterStatus)) FilterStatusEnum FilterStatus;

            virtual FilterStatusEnum GetFilterStatus() = 0;

            virtual void SetFilterStatus(FilterStatusEnum value) = 0;

            // CH: 亚像素窗口 | EN: Sub-pixel window
            __declspec(property(put = SetSubpixelWinAuto, get = GetSubpixelWinAuto)) SubpixelWinAutoEnum SubpixelWinAuto;

            virtual SubpixelWinAutoEnum GetSubpixelWinAuto() = 0;

            virtual void SetSubpixelWinAuto(SubpixelWinAutoEnum value) = 0;

            // CH: 设置窗口大小 | EN: Set window size
            __declspec(property(put = SetSubPixelWindowSize, get = GetSubPixelWindowSize)) int SubPixelWindowSize;

            virtual int GetSubPixelWindowSize() = 0;

            virtual void SetSubPixelWindowSize(int value) = 0;

            // CH: 生成标定文件 | EN: Create Calibration File
            virtual int DoSaveFile(IN const char * const strValue) = 0;

            // CH: 清除图像 | EN: Clear Image
            virtual int DoClearImage() = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        class INImageCalibMechanismTransErrorInfo
        {
        protected:
            ///< Constructor and Destructor
            explicit INImageCalibMechanismTransErrorInfo() {}
            virtual ~INImageCalibMechanismTransErrorInfo() {}
        public:
            /**
             * @par 说明
             * 平移过程中图像移动量与机构移动量之间的偏差
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetTransPoint() = 0;
            /**
             * @par 说明
             * 平移过程中的图像尺度变化
             * @par 权限
             * 只读
             */
            virtual float GetScale() = 0;
            /**
             * @par 说明
             * 平移过程中的图像之间旋转变化量
             * @par 权限
             * 只读
             */
            virtual float GetRotate() = 0;
            
            /**
             * @par 说明
             * 平移估计时的像素误差
             * @par 权限
             * 只读
             */
            virtual float GetTransError() = 0;
            /**
             * @par 说明
             * 平移估计时的真实误差，单位mm
             * @par 权限
             * 只读
             */
            virtual float GetTransWorldError() = 0;
            /**
             * @par 说明
             * 旋转估计像素误差
             * @par 权限
             * 只读
             */
            virtual float GetRotError() = 0;
            /**
             * @par 说明
             * 旋转估计真实误差，单位mm
             * @par 权限
             * 只读
             */
            virtual float GetRotWorldError() = 0;
            /**
             * @par 说明
             * 机构旋转运动误差,是输入的旋转角度与计算的机构旋转角度之差
             * @par 权限
             * 只读
             */
            virtual float GetRotAngleError() = 0;
        };

        /*  Note: Interface Classes of the result of the NImageCalibResults.  */
        class NImageCalibResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit NImageCalibResults() {}
            virtual ~NImageCalibResults() {}

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
             * 每张图像的标定状态
             * @par 权限
             * 只读
             */
            virtual int GetCalibStatus(int nImageIndex) = 0;
            /**
             * @par 说明
             * 轴心在旋转图像中的图像坐标
             * @par 权限
             * 只读
             */
            virtual MVD_POINT_F GetRotImageCenter() = 0;
            /**
             * @par 说明
             * 机构平移运动误差
             * @par 权限
             * 只读
             */
            virtual INImageCalibMechanismTransErrorInfo* GetTransMotionErrorInfo() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the NImageCalib tool.  */
        class IMVSNImageCalibModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSNImageCalibModuTool() {}
            virtual ~IMVSNImageCalibModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual NImageCalibParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual NImageCalibResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

        private:
            IMVSNImageCalibModuTool(IMVSNImageCalibModuTool&);
            IMVSNImageCalibModuTool& operator=(IMVSNImageCalibModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for NImageCalib.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSNImageCalibModu::IMVSNImageCalibModuTool * __stdcall GetNImageCalibToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_NIMAGECALIB_H_
