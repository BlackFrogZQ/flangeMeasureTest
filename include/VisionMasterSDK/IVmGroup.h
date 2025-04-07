/***************************************************************************************************
 * File：IVmGroup.h
 * Note：Interface for the group tool.
 *
 * Version：4.3
 * Date：2021/1/12 11:04:12
 ***************************************************************************************************/
#ifndef _IVM_GROUP_H_
#define _IVM_GROUP_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"
#include "IVmDynamicIoDefine.h"

namespace VisionMasterSDK
{
    namespace IMVSGroup
    {
        /*************************** Params Class Start ***************************/
        // CH: 数据类型 | EN: Data Type
        typedef enum _DataTypeEnum
        {
            // CH: int | EN: int
            DataType_Int = 0x1,

            // CH: float | EN: float
            DataType_Float = 0x2,

            // CH: string | EN: string
            DataType_String = 0x3,

        }DataTypeEnum;

        // CH: 比较运算 | EN: Compare Operate
        typedef enum _CmpTypeEnum
        {
            // %>%
            CmpType_GT = 0x1,

            // %<%
            CmpType_LT = 0x2,

            // %=%
            CmpType_EQ = 0x3,

            // %!=%
            CmpType_NE = 0x4,

            // %>=%
            CmpType_GE = 0x5,

            // %<=%
            CmpType_LE = 0x6,

        }CmpTypeEnum;

        /*  Note: Interface Classes of the parameter of the IMVSGroupParams.  */
        class IMVSGroupParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSGroupParams() {}
            virtual ~IMVSGroupParams() {}

        public:

            // CH: 循环使能 | EN: Loop Enable
            __declspec(property(put = SetEnableLoop, get = GetEnableLoop)) bool EnableLoop;

            virtual bool GetEnableLoop() = 0;

            virtual void SetEnableLoop(bool value) = 0;

            // CH: 循环间隔(ms) | EN: Cycle Time(ms)
            __declspec(property(put = SetLoopTimeGap, get = GetLoopTimeGap)) int LoopTimeGap;

            virtual int GetLoopTimeGap() = 0;

            virtual void SetLoopTimeGap(int value) = 0;

            // CH: 中断循环 | EN: Break Loop
            __declspec(property(put = SetEnableBreak, get = GetEnableBreak)) bool EnableBreak;

            virtual bool GetEnableBreak() = 0;

            virtual void SetEnableBreak(bool value) = 0;

            // CH: 数据类型 | EN: Data Type
            __declspec(property(put = SetDataType, get = GetDataType)) DataTypeEnum DataType;

            virtual DataTypeEnum GetDataType() = 0;

            virtual void SetDataType(DataTypeEnum value) = 0;

            // CH: 比较运算 | EN: Compare Operate
            __declspec(property(put = SetCmpType, get = GetCmpType)) CmpTypeEnum CmpType;

            virtual CmpTypeEnum GetCmpType() = 0;

            virtual void SetCmpType(CmpTypeEnum value) = 0;

            /**
            *  @brief  设置Int数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  int型指针数组
            *  @param  数组长度
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputInt(const char * const strParamName, const int * const anIntVal, const int nValNum) = 0;
            /**
            *  @brief  设置Float数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  Float型指针数组
            *  @param  数组长度
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputFloat(const char * const strParamName, const float * const anFloatVal, const int nValNum) = 0;
            /**
            *  @brief  设置String数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  InputStringData结构体指针数组
            *  @param  数组长度
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputString(const char * const strParamName, const InputStringData * const astStrData, const int nValNum) = 0;
            /** 
            *  @brief  设置动态输入图像数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoImage结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputImageV2(const char * const strParamName, const IoImage * const pstImageData) = 0;

            /** 
            *  @brief  设置动态输入矩形框数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoRectBoxArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputBox(const char * const strParamName, const IoRectBoxArray * const pstBox) = 0;

            /** 
            *  @brief  设置动态输入圆环ROI数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoAnnulusArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputAnnulus(const char * const strParamName, const IoAnnulusArray * const pstAnnulus) = 0;

            /** 
            *  @brief  设置动态输入圆形数据(仅当次执行起效)(弃用)
            *  @param  参数名称
            *  @param  IoCircleArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputCircle(const char * const strParamName, const IoCircleArray * const pstCircle) = 0;

			/**
			*  @brief  设置动态输入椭圆形数据(仅当次执行起效)
			*  @param  参数名称
			*  @param  IoEllipseArray结构体指针数组
			*  @return 无
			*  @par    注解
			*/
			virtual void SetInputEllipse(const char * const strParamName, const IoEllipseArray * const pstEllipse) = 0;

            /** 
            *  @brief  设置动态输入线型数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoLineArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputLine(const char * const strParamName, const IoLineArray * const pstLine) = 0;

            /** 
            *  @brief  设置动态输入点型数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoPointArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputPoint(const char * const strParamName, const IoPointArray * const pstPointF) = 0;

            /**
            *  @brief  设置动态输入位置修正数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoFixtureArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputFixture(const char * const strParamName, const IoFixtureArray * const pstFixture) = 0;

            /** 
            *  @brief  设置动态输入矩形数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoRectFArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputRect(const char * const strParamName, const IoRectFArray * const pstRectF) = 0;

            /** 
            *  @brief  设置动态输入类别信息数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoClassInfoArray结构体指针数组
            *  @return 无
            *  @par 注解
            */
            virtual void SetInputClassInfo(const char * const strParamName, const IoClassInfoArray * const pstClassInfo) = 0;

            /** 
            *  @brief  设置动态输入像素图像数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoPixelImage结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputPixelImage(const char * const strParamName, const IoPixelImage * const pstPixelImage) = 0;
            /** 
            *  @brief  设置动态输入多边形数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoPolygonArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputPolygon(const char * const strParamName, const IoPolygonArray * const pstPolygon) = 0;
            /** 
            *  @brief  设置动态输入位姿数据(仅当次执行起效)
            *  @param  参数名称
            *  @param  IoPostureArray结构体指针数组
            *  @return 无
            *  @par    注解
            */
            virtual void SetInputPosture(const char * const strParamName, const IoPostureArray * const pstPosture) = 0;
			/**
			*  @brief  获取所有输入名称信息
			*  @param  无
			*  @return 无
			*  @par    注解
			*/
			virtual IoNameInfoArray GetAllInputNameInfo() = 0;
        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        /*  Note: Interface Classes of the result of the IMVSGroupResults.  */
        class IMVSGroupResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSGroupResults() {}
            virtual ~IMVSGroupResults() {}

        public:
            /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
            virtual int GetModuStatus() = 0;

            /**
            * @brief 获取整型输出
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual IntDataArray GetOutputInt(IN const char * const strParamName) = 0;

            /**
            * @brief 获取浮点型输出
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual FloatDataArray GetOutputFloat(IN const char * const strParamName) = 0;

            /**
            * @brief 获取字符串型输出
            * @param 参数名称
            * @return 无，出错时抛出异常
            * @par 注解
            */
            virtual StringDataArray GetOutputString(IN const char * const strParamName) = 0;

            /**
            * @brief 获取图像像素数据输出,弃用,推荐(GetOutputImageV2(IN const char * const strParamName))
            * @param 参数名称
            * @return 图像像素数据
            * @par 注解
            */
            virtual BaseDataInfo GetOutputImage(IN const char * const strParamName) = 0;

            /**
            * @brief 获取点集型输出
            * @param 参数名称
            * @return 点集
            * @par 注解
            */
            virtual MatchOutline GetOutputPointset(IN const char * const strParamName) = 0;

            /**
            * @brief 获取二进制数据型输出
            * @param 参数名称
            * @return 二进制数据
            * @par 注解
            */
            virtual ByteArrayData GetOutputByteArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取图像结果（整个图像）
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoImage GetOutputImageV2(IN const char * const strParamName) = 0;

            /**
            * @brief 获取点输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoPointArray GetOutputPointArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取直线输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoLineArray GetOutputLineArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取圆输出数组(弃用)
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoCircleArray GetOutputCircleArray(IN const char * const strParamName) = 0;

			/**
			* @brief 获取椭圆输出数组
			* @param 参数名称
			* @return
			* @par 注解
			*/
			virtual IoEllipseArray GetOutputEllipseArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取带角度矩形输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoRectBoxArray GetOutputBoxArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取无角度矩形(浮点型)输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoRectFArray GetOutputRectArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取位置修正输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoFixtureArray GetOutputFixtureArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取圆环输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoAnnulusArray GetOutputAnnulusArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取类别信息输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoClassInfoArray GetOutputClassInfoArray(IN const char * const strParamName) = 0;

            /**
            * @brief 获取带类别信息的图(界面可根据类别信息将灰度图显示成彩图)
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoPixelImage GetOutputPixelImage(IN const char * const strParamName) = 0;

            /**
            * @brief 获取位姿数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoPostureArray GetOutputPostureArray(IN const char * const strParamName) = 0; 
            
            /**
            * @brief 获取多边形输出数组
            * @param 参数名称
            * @return
            * @par 注解
            */
            virtual IoPolygonArray GetOutputPolygonArray(IN const char * const strParamName) = 0;

            /**
            * @brief 所有所有输出名称信息（CONTOURPOINTS、POINTSET、小写的image,这三种类型不支持）
            * @param
            * @return
            * @par 注解
            */
            virtual IoNameInfoArray GetAllOutputNameInfo() = 0;

            /**
            * @brief 根据名称信息获取输出对象基类指针
            * @param 
            * @return
            * @par 注解
            */
            virtual VmIoBase* GetOutputObject(IN const IoNameInfo& stNameInfo) = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the IMVSGroup tool.  */
        class IMVSGroupTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSGroupTool() {}
            virtual ~IMVSGroupTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual IMVSGroupParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual IMVSGroupResults* GetResult() = 0;

            /**
             * @brief 保存Group至文件
             * @param 文件路径
             * @param 文件密码
             * @return 无，出错时抛出异常
             * @par 注解
             * 不支持导出方案中Group相关的连接订阅信息
             * 弃用,推荐(SaveAsGroup(const char * const strGroPath, const char * const strPassword)
             */
            virtual void ExportGroup(IN const char * const strGroPath, IN const char * const strPassword = NULL) = 0;

            /**
            * @brief 保存Group至文件
            * @param 文件路径
            * @param 文件密码
            * @return 无，出错时抛出异常
            * @par 注解
            * 不支持导出方案中Group相关的连接订阅信息
            */
            virtual void SaveAsGroup(IN const char * const strGroPath, IN const char * const strPassword = NULL) = 0;

            /**
             * @brief 自执行一次
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 自执行一次（只支持独立Group）
             */
            virtual void Run(void) = 0;

            /**
             * @brief 获取所有模块信息列表
             * @param 空
             * @return 所有模块信息列表
             * @par 注解
             */
            virtual GroupModuInfoList * GetAllModuleList(void) = 0;

            /**
             * @brief 禁用Group
             * @param 无
             * @return 无
             * @par 注解
             */
            virtual void DisableGroup(void) = 0;

            /**
             * @brief 启用Group
             * @param 无
             * @return 无
             * @par 注解
             */
            virtual void EnableGroup(void) = 0;

            /**
             * @brief 获取当前模块ID(预留，内部使用)
             * @param 无
             * @return 当前模块ID
             * @par 注解
             */
            virtual unsigned int GetCurrentModuId(void) = 0;

        public:
            /**
             * @brief 根据名称获取模块对象
             * @param 模块显示名称
             * @return 模块对象指针
             * @par 注解
             */
            virtual void * operator[] (IN const char * const strKey) = 0;
        };
        /*************************** Tool Class End ***************************/
    }
}

/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

    /*  Note: Load the independent Group.
        brief: EN: Password parameter is reserved. | CH: 密码参数预留，暂不支持 */
    /* CH: 弃用,推荐(LoadIndependentGroup(const char * const strGroPath, IN const char * const strPassword)) | EN: Obsolete,recommend(LoadIndependentGroup(const char * const strGroPath, IN const char * const strPassword)) */
    IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSGroup::IMVSGroupTool * __stdcall LoadGroup(IN const char * const strGroPath, IN const char * const strPassword = NULL);
    /*  Note: Load the independent Group.
    brief: EN: Password parameter is reserved. | CH: 密码参数预留，暂不支持
    remarks: CH: 该接口加载的Group对象无法配合控件使用，如需配合控件，建议使用独立Group控件接口CVmSingleModuleSetControlInterface::LoadIndependentGroup */
    IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSGroup::IMVSGroupTool * __stdcall LoadIndependentGroup(IN const char * const strGroPath, IN const char * const strPassword = NULL);
    /*  Note: Get the independent Group by control. */
    IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSGroup::IMVSGroupTool * __stdcall GetGroupByCtrl(IN void * pCtrlInfo);
    /*  Note: Destroy tool instance for group.  */
    IMVS_6000_PLATFORMSDK_API void __stdcall DestroyGroupInstance(IN VisionMasterSDK::IMVSGroup::IMVSGroupTool* pToolInstance);

#ifdef __cplusplus
}
#endif 

#endif    ///< _IVM_GROUP_H_
