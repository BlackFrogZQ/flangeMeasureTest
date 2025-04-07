/***************************************************************************************************
 *
 * 版权信息：版权所有 (c) 2020, 保留所有权利
 *
 * 文件名称：iMVS-6000PlatformSDKC.h
 * 摘    要：二次开发SDK C接口头文件
 *
 * 作    者：视觉平台组
 * 日    期：2020-01-17 11:09:05
 * 备    注：新建

 * Copyright information: All Right Reserved.
 *
 * File name: iMVS-6000PlatformSDKC.h
 * Brief: VisionMaster SDK definition
 *
 * Author: VisionMaster Team
 * Date: 2020-01-17 11:09:05
 * Note: New
 ****************************************************************************************************/
#ifndef IMVS_6000_PLATFORMSDKC_H__
#define IMVS_6000_PLATFORMSDKC_H__

#pragma warning(disable:4819)
#include "iMVS-6000PlatformSDKDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
 * 基础接口
 * Basic Related API
 ****************************************************************************/
/****************************************************************************
 *  @fn     IMVS_PF_GetErrorMsg
 *  @brief  将错误码转为英文错误信息
 *  @param  nErrorCode             [IN]       错误码
 *  @return 返回输入错误码对应的英文错误信息

 *  @fn     IMVS_PF_GetErrorMsg
 *  @brief  Get detailed error message according to the error code
 *  @param  nErrorCode             [IN]       Error code
 *  @return Return detailed error message corresponding to the inputted error code
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API const char * __stdcall IMVS_PF_GetErrorMsg(IN const unsigned int nErrorCode);

/****************************************************************************
 *  @fn     IMVS_PF_GetBuildVersion
 *  @brief  获取编译版本
 *  @param  无
 *  @return 返回当前编译版本信息字符串

 *  @fn     IMVS_PF_GetBuildVersion
 *  @brief  Get the SDK version number
 *  @param  void
 *  @return Return the SDK version number for success
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API const char * __stdcall IMVS_PF_GetBuildVersion(void);

/****************************************************************************
 *  @fn     IMVS_PF_CreateHandle
 *  @brief  创建句柄
 *  @param  handle                  [OUT]       要生成的句柄
 *  @param  strServerPath           [IN]        服务路径，用于非管理员权限
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_CreateHandle
 *  @brief  Create the handle
 *  @param  handle                  [OUT]       Handle
 *  @param  strServerPath           [IN]        Service path, used for non-administrator permissions
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_CreateHandle(OUT void ** const handle, IN const char * const strServerPath = 0);

/****************************************************************************
 *  @fn     IMVS_PF_DestroyHandle
 *  @brief  销毁句柄
 *  @param  handle                  [IN]       要销毁的句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_DestroyHandle
 *  @brief  Destroy the handle
 *  @param  handle                  [IN]       Handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_DestroyHandle(IN const void * const handle);

/****************************************************************************
 *  @fn     IMVS_PF_GetDongleAuthority
 *  @brief  获取加密狗权限信息
 *  @param  handle                  [IN]       操作句柄
 *  @return 成功,返回当前加密狗状态值;失败,返回错误码

 *  @fn     IMVS_PF_GetDongleAuthority
 *  @brief  Get the dongle authorization information
 *  @param  handle                  [IN]       Handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetDongleAuthority(IN const void * const handle);

/****************************************************************************
 * 展现接口
 * Display Related API
 ****************************************************************************/
/****************************************************************************
 *  @fn     IMVS_PF_StartVisionMaster
 *  @brief  打开算法平台界面程序（V4.0弃用）
 *  @param  handle                  [IN]       操作句柄
 *  @param  strPlatformPath         [IN]       算法平台可执行文件绝对路径
 *  @param  nWaitTime               [IN]       等待时间（单位：毫秒）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_StartVisionMaster
 *  @brief  Start VisionMaster program
 *  @param  handle                  [IN]       Handle
 *  @param  strPlatformPath         [IN]       The storage path of VisionMaster exe. file
 *  @param  nWaitTime               [IN]       Waiting time, unit: ms
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_StartVisionMaster(IN const void * const handle, IN const char * const strPlatformPath , IN const unsigned int nWaitTime);

/****************************************************************************
 *  @fn     IMVS_PF_StartVisionMaster_U
 *  @brief  打开算法平台界面程序（V4.0弃用）
 *  @param  handle                  [IN]       操作句柄
 *  @param  strPlatformPath         [IN]       算法平台可执行文件绝对路径（UTF8格式）
 *  @param  nWaitTime               [IN]       等待时间（单位：毫秒）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_StartVisionMaster_U
 *  @brief  Start VisionMaster program
 *  @param  handle                  [IN]       Handle
 *  @param  strPlatformPath         [IN]       The storage path of VisionMaster exe. file (UTF8 format)
 *  @param  nWaitTime               [IN]       Waiting time, unit: ms
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_StartVisionMaster_U(IN const void * const handle, IN const char * const strPlatformPath, IN const unsigned int nWaitTime);

/****************************************************************************
 *  @fn     IMVS_PF_CloseVisionMaster
 *  @brief  关闭算法平台界面程序（V4.0弃用）
 *  @param  handle                  [IN]       操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_CloseVisionMaster
 *  @brief  Close VisionMaster program
 *  @param  handle                  [IN]       Handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_CloseVisionMaster(IN const void * const handle);

/****************************************************************************
 *  @fn     IMVS_PF_ShowVisionMaster
 *  @brief  控制算法平台主界面的显示/隐藏（V4.0弃用）
 *  @param  handle                  [IN]       操作句柄
 *  @param  nShowType               [IN]       显示类型（0：隐藏；1：显示）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ShowVisionMaster
 *  @brief  Show/hide the VisionMaster program page
 *  @param  handle                  [IN]       Handle
 *  @param  nShowType               [IN]       Shown or hidden status (0: Hide；1: Show)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ShowVisionMaster(IN const void * const handle, IN const unsigned int nShowType);

/****************************************************************************
 *  @fn     IMVS_PF_ShowModuleInterface
 *  @brief  弹出指定模块的结果输出界面（V4.0修改为绑定参数配置控件）
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @return 控件输入信息

 *  @fn     IMVS_PF_ShowModuleInterface
 *  @brief  Show specified module interface
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API void * __stdcall IMVS_PF_ShowModuleInterface(IN const void * const handle, IN const unsigned int nModuleID);

/****************************************************************************
 *  @fn     IMVS_PF_GetVisionMasterShowStatus
 *  @brief  获取算法平台界面显示/隐藏状态（V4.0弃用）
 *  @param  handle                  [IN]       操作句柄
 *  @param  pnShowStatus            [OUT]      显示/隐藏状态（0：隐藏；1：显示）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetVisionMasterShowStatus
 *  @brief  Get the VisionMaster show/hide status
 *  @param  handle                  [IN]       Handle
 *  @param  pnShowStatus            [OUT]      Shown or hidden status (0: Hide；1: Show)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetVisionMasterShowStatus(IN const void * const handle, OUT unsigned int * const pnShowStatus);

#ifdef SDK_PLATFORM_WINDOWS
/****************************************************************************
 *  @fn     IMVS_PF_AttachFrontedWnd
 *  @brief  载入运行界面窗口到第三方界面（V4.0弃用）
 *  @param  handle                  [IN]       操作句柄
 *  @param  hParentWnd              [IN]       第三方界面句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_AttachFrontedWnd
 *  @brief  Load the front-end running window to third-party interface
 *  @param  handle                  [IN]       Handle
 *  @param  hParentWnd              [IN]       The handle of third-party interface/window
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_AttachFrontedWnd(IN const void * const handle, IN const void * const hParentWnd);

/****************************************************************************
 *  @fn     IMVS_PF_UnAttachFrontedWnd
 *  @brief  卸载第三方界面中的运行界面窗口（V4.0弃用）
 *  @param  handle                  [IN]       操作句柄
 *  @param  hParentWnd              [IN]       第三方界面句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_UnAttachFrontedWnd
 *  @brief  Unload the front-end running window from third-party interface
 *  @param  handle                  [IN]       Handle
 *  @param  hParentWnd              [IN]       The handle of third-party interface/window
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_UnAttachFrontedWnd(IN const void * const handle, IN const void * const hParentWnd);

/****************************************************************************
 *  @fn     IMVS_PF_AttachSonFrontedWnds
 *  @brief  载入多个运行子界面窗口到多个第三方界面（V4.0弃用）
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstParentWndHandle      [IN]       第三方界面句柄列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_AttachSonFrontedWnds
 *  @brief  Load multiple son front-end running windows to multiple third-party interfaces
 *  @param  handle                  [IN]       Handle
 *  @param  pstParentWndHandle      [IN]       The handle list of third-party interfaces/windows
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_AttachSonFrontedWnds(IN const void * const handle, IN const IMVS_PF_FRONTEDWND_HANDLE_LIST * const pstParentWndHandle);

/****************************************************************************
 *  @fn     IMVS_PF_UnAttachSonFrontedWnds
 *  @brief  卸载多个第三方界面中的运行子界面窗口（V4.0弃用）
 *  @param  handle                  [IN]       操作句柄
 *  @param  hParentWnd              [IN]       第三方界面句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_UnAttachSonFrontedWnds
 *  @brief  Unload multiple son front-end running windows from third-party interfaces
 *  @param  handle                  [IN]       Handle
 *  @param  hParentWnd              [IN]       The handle list of third-party interfaces/windows
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_UnAttachSonFrontedWnds(IN const void * const handle, IN const IMVS_PF_FRONTEDWND_HANDLE_LIST * const pstParentWndHandle);

/****************************************************************************
 *  @fn     IMVS_PF_ScreenFrontedWnd
 *  @brief  截取前端运行子界面图像（V4.0弃用）
 *  @param  handle                  [IN]       操作句柄
 *  @param  pParentWndHandle        [IN]       父窗体句柄
 *  @param  strPath                 [IN]       存储图像绝对路径
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ScreenFrontedWnd
 *  @brief  Intercepting the image of the son front-end running window
 *  @param  handle                  [IN]       Handle
 *  @param  pParentWndHandle        [IN]       The handle of parent window
 *  @param  strPath                 [IN]       The absolute path of the stored image
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ScreenFrontedWnd(IN const void * const handle, IN const void * const pParentWndHandle, IN const char * const strPath);
#endif

/****************************************************************************
 * 平台数据接口
 * Platform Data Related API
 ****************************************************************************/
/****************************************************************************
 *  @fn     IMVS_PF_SetParamValue
 *  @brief  设置模块参数值
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  strName                 [IN]       参数名
 *  @param  strValue                [IN]       参数值
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetParamValue
 *  @brief  Set values for parameters
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  strName                 [IN]       Parameter name
 *  @param  strValue                [IN]       Parameter value
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetParamValue(IN const void * const handle , IN const unsigned int nModuleID , IN const char * const strName , IN const char * const strValue);

/****************************************************************************
 *  @fn     IMVS_PF_SetParamValue_U
 *  @brief  设置模块参数值
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  strName                 [IN]       参数名
 *  @param  strValue                [IN]       参数值(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetParamValue_U
 *  @brief  Set values for parameters
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  strName                 [IN]       Parameter name
 *  @param  strValue                [IN]       Parameter value (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetParamValue_U(IN const void * const handle, IN const unsigned int nModuleID, IN const char * const strName, IN const char * const strValue);

/****************************************************************************
 *  @fn     IMVS_PF_SetParamValue_L
 *  @brief  设置模块参数值
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  strName                 [IN]       参数名
 *  @param  strValue                [IN]       参数值(判断上下限)
 *  @param  nDataType               [IN]       数据类型(1：整型；2：浮点型)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetParamValue_L
 *  @brief  Set values for parameters
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  strName                 [IN]       Parameter name
 *  @param  strValue                [IN]       Parameter value (Judge upper and lower limits)
 *  @param  nDataType               [IN]       Data type (1:int, 2:float)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetParamValue_L(IN const void * const handle, IN const unsigned int nModuleID, IN const char * const strName, IN const char * const strValue, IN unsigned int nDataType);

/****************************************************************************
 *  @fn     IMVS_PF_GetParamValue
 *  @brief  获取模块参数值
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  strName                 [IN]       参数名
 *  @param  nStrValueSize           [IN]       参数值的分配大小
 *  @param  strValue                [OUT]      参数值
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetParamValue
 *  @brief  Get values for parameters
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  strName                 [IN]       Parameter name
 *  @param  nStrValueSize           [IN]       Parameter value size
 *  @param  strValue                [OUT]      Parameter value
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetParamValue(IN const void * const handle , IN const unsigned int nModuleID , IN const char * const strName , IN const unsigned int nStrValueSize , OUT char * const strValue);

/****************************************************************************
 *  @fn     IMVS_PF_GetParamValue_U
 *  @brief  获取模块参数值
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  strName                 [IN]       参数名
 *  @param  nStrValueSize           [IN]       参数值的分配大小
 *  @param  strValue                [OUT]      参数值(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetParamValue_U
 *  @brief  Get values for parameters
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  strName                 [IN]       Parameter name
 *  @param  nStrValueSize           [IN]       Parameter value size
 *  @param  strValue                [OUT]      Parameter value (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetParamValue_U(IN const void * const handle, IN const unsigned int nModuleID, IN const char * const strName, IN const unsigned int nStrValueSize, OUT char * const strValue);

/****************************************************************************
 *  @fn     IMVS_PF_GetParamList
 *  @brief  获取模块参数列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pstModuleParamList      [OUT]      模块参数列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetParamList
 *  @brief  Get the parameters list of specified module
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  pstModuleParamList      [OUT]      Pointer to module parameters list
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetParamList(IN const void * const handle , IN const unsigned int nModuleID , OUT IMVS_PF_MODULE_PARAM_LIST * const pstModuleParamList);

/****************************************************************************
 *  @fn     IMVS_PF_GetParamList_U
 *  @brief  获取模块参数列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pstModuleParamList      [OUT]      模块参数列表(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetParamList_U
 *  @brief  Get the parameters list of specified module
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  pstModuleParamList      [OUT]      Pointer to module parameters list (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetParamList_U(IN const void * const handle, IN const unsigned int nModuleID, OUT IMVS_PF_MODULE_PARAM_LIST * const pstModuleParamList);

/****************************************************************************
 *  @fn     IMVS_PF_SetParamList
 *  @brief  设置模块参数列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pstModuleParamList      [IN]       模块参数列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetParamList
 *  @brief  Set values for multiple parameters of specified module in batch
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  pstModuleParamList      [IN]       Pointer to module parameters list
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetParamList(IN const void * const handle , IN const unsigned int nModuleID , IN const IMVS_PF_MODULE_PARAM_LIST * const pstModuleParamList);

/****************************************************************************
 *  @fn     IMVS_PF_SetParamList_U
 *  @brief  设置模块参数列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pstModuleParamList      [IN]       模块参数列表(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetParamList_U
 *  @brief  Set values for multiple parameters of specified module in batch
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  pstModuleParamList      [IN]       Pointer to module parameters list (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetParamList_U(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_PF_MODULE_PARAM_LIST * const pstModuleParamList);

/****************************************************************************
 *  @fn     IMVS_PF_SetParamList_L
 *  @brief  设置模块参数列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pstModuleParamList      [IN]       模块参数列表(判断上下限)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetParamList_L
 *  @brief  Set values for multiple parameters of specified module in batch
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  pstModuleParamList      [IN]       Pointer to module parameters list (Judge upper and lower limits)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetParamList_L(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_PF_MODULE_PARAM_LIST * const pstModuleParamList);

/****************************************************************************
 *  @fn     IMVS_PF_SaveSolution
 *  @brief  保存算法平台方案
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstSaveInput            [IN]       保存方案输入结构体指针
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SaveSolution
 *  @brief  Save the solution
 *  @param  handle                  [IN]       Handle
 *  @param  pstSaveInput            [IN]       Pointer to inputted parameters structure of saved solution
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SaveSolution(IN const void * const handle, IN const IMVS_PF_SAVE_SOLUTION_INPUT * const pstSaveInput);

/****************************************************************************
 *  @fn     IMVS_PF_SaveSolution_U
 *  @brief  保存算法平台方案
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstSaveInput            [IN]       保存方案输入结构体指针(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SaveSolution_U
 *  @brief  Save the solution
 *  @param  handle                  [IN]       Handle
 *  @param  pstSaveInput            [IN]       Pointer to inputted parameters structure of saved solution (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SaveSolution_U(IN const void * const handle, IN const IMVS_PF_SAVE_SOLUTION_INPUT * const pstSaveInput);

/****************************************************************************
 *  @fn     IMVS_PF_GetSaveProgress
 *  @brief  获取方案保存进度、保存结果(错误码)
 *  @param  handle                  [IN]       操作句柄
 *  @param  pnSaveprogress          [OUT]      方案保存进度
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetSaveProgress
 *  @brief  Get the solution saving progress
 *  @param  handle                  [IN]       Handle
 *  @param  pnSaveprogress          [OUT]      Solution saving progress, ranges from 0 to 100
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetSaveProgress(IN const void * const handle , OUT unsigned int * const pnSaveprogress);

/****************************************************************************
 *  @fn     IMVS_PF_SyncSaveSolution
 *  @brief  同步保存算法平台方案
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstSaveInput            [IN]       保存方案输入结构体指针
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SyncSaveSolution
 *  @brief  Save the solution synchronous
 *  @param  handle                  [IN]       Handle
 *  @param  pstSaveInput            [IN]       Pointer to inputted parameters structure of saved solution
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SyncSaveSolution(IN const void * const handle, IN const IMVS_PF_SAVE_SOLUTION_INPUT * const pstSaveInput);

/****************************************************************************
 *  @fn     IMVS_PF_LoadSolution
 *  @brief  加载已有的算法平台方案
 *  @param  handle                  [IN]       操作句柄
 *  @param  strPath                 [IN]       方案绝对路径
 *  @param  strPassWord             [IN]       方案密码，如无密码可将该参数置为NULL或空字符串
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_LoadSolution
 *  @brief  Load the existed solution
 *  @param  handle                  [IN]       Handle
 *  @param  strPath                 [IN]       The saving path of solution
 *  @param  strPassWord             [IN]       Solution password, if the solution is not encrypted, set this parameter to IMVS_PF_INPUT_NO_PASSWORD
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_LoadSolution(IN const void * const handle, IN const char * const strPath, IN const char * const strPassWord);

/****************************************************************************
 *  @fn     IMVS_PF_LoadSolution_U
 *  @brief  加载已有的算法平台方案
 *  @param  handle                  [IN]       操作句柄
 *  @param  strPath                 [IN]       方案绝对路径(UTF8)
 *  @param  strPassWord             [IN]       方案密码，如无密码可将该参数置为NULL或空字符串
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_LoadSolution_U
 *  @brief  Load the existed solution
 *  @param  handle                  [IN]       Handle
 *  @param  strPath                 [IN]       The saving path of solution (UTF8 format)
 *  @param  strPassWord             [IN]       Solution password, if the solution is not encrypted, set this parameter to IMVS_PF_INPUT_NO_PASSWORD (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_LoadSolution_U(IN const void * const handle, IN const char * const strPath, IN const char * const strPassWord);

/****************************************************************************
 *  @fn     IMVS_PF_GetLoadProgress
 *  @brief  获取方案加载进度、加载结果（错误码）
 *  @param  handle                  [IN]       操作句柄
 *  @param  pnLoadProgress          [OUT]      加载进度
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetLoadProgress
 *  @brief  Get the solution loading progress
 *  @param  handle                  [IN]       Handle
 *  @param  pnLoadProgress          [OUT]      Loading progress
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetLoadProgress(IN const void * const handle , OUT unsigned int * const pnLoadProgress);

/****************************************************************************
 *  @fn     IMVS_PF_SyncLoadSolution
 *  @brief  同步加载已有的算法平台方案
 *  @param  handle                  [IN]       操作句柄
 *  @param  strPath                 [IN]       方案绝对路径
 *  @param  strPassWord             [IN]       方案密码，如无密码可将该参数置为NULL或空字符串
 *  @param  bSilentExecute          [IN]       是否静默执行（true：执行；false：不执行）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SyncLoadSolution
 *  @brief  Load the existed solution synchronous
 *  @param  handle                  [IN]       Handle
 *  @param  strPath                 [IN]       The saving path of solution
 *  @param  strPassWord             [IN]       Solution password, if the solution is not encrypted, set this parameter to IMVS_PF_INPUT_NO_PASSWORD
 *  @param  bSilentExecute          [IN]       Whether to execute silently (true: execute, false: Do not execute)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SyncLoadSolution(IN const void * const handle, IN const char * const strPath, IN const char * const strPassWord, IN bool bSilentExecute);

/****************************************************************************
 *  @fn     IMVS_PF_CloseSolution
 *  @brief  关闭算法平台当前方案
 *  @param  handle                  [IN]       操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_CloseSolution
 *  @brief  Close the solution
 *  @param  handle                  [IN]       Handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_CloseSolution(IN const void * const handle);

/****************************************************************************
 *  @fn     IMVS_PF_CheckPassword
 *  @brief  判断方案文件是否有密码
 *  @param  handle                  [IN]       操作句柄
 *  @param  strPath                 [IN]       方案绝对路径
 *  @param  pnHasPwd                [OUT]      方案是否有密码
 *                                             无密码：IMVS_STATUS_NO_PASSWORD   (0)
 *                                             有密码：IMVS_STATUS_HAVE_PASSWORD (1)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_CheckPassword
 *  @brief  Check if the solution file is encrypted
 *  @param  handle                  [IN]       Handle
 *  @param  strPath                 [IN]       The saving path of solution
 *  @param  pnHasPwd                [OUT]      Whether there is a password for solution file
 *                                             No password: IMVS_STATUS_NO_PASSWORD   (0)
 *                                             Has password: IMVS_STATUS_HAVE_PASSWORD (1)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_CheckPassword(IN const void * const handle, IN const char * const strPath, OUT unsigned int* pnHasPwd);

/****************************************************************************
 *  @fn     IMVS_PF_CheckPassword_U
 *  @brief  判断方案文件是否有密码
 *  @param  handle                  [IN]       操作句柄
 *  @param  strPath                 [IN]       方案绝对路径(UTF8)
 *  @param  pnHasPwd                [OUT]      方案是否有密码
 *                                             无密码：IMVS_STATUS_NO_PASSWORD   (0)
 *                                             有密码：IMVS_STATUS_HAVE_PASSWORD (1)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_CheckPassword_U
 *  @brief  Check if the solution file is encrypted
 *  @param  handle                  [IN]       Handle
 *  @param  strPath                 [IN]       The saving path of solution (UTF8 format)
 *  @param  pnHasPwd                [OUT]      Whether there is a password for solution file
 *                                             No password: IMVS_STATUS_NO_PASSWORD   (0)
 *                                             Has password: IMVS_STATUS_HAVE_PASSWORD (1)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_CheckPassword_U(IN const void * const handle, IN const char * const strPath, OUT unsigned int* pnHasPwd);

/****************************************************************************
 *  @fn     IMVS_PF_GetAllModuleList
 *  @brief  获取当前所有模块列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstModuleInfoList       [OUT]      所有模块信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetAllModuleList
 *  @brief  Get the list of all modules
 *  @param  handle                  [IN]       Handle
 *  @param  pstModuleInfoList       [OUT]      List of all modules information
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetAllModuleList(IN const void * const handle , OUT IMVS_PF_MODULE_INFO_LIST * const pstModuleInfoList);

/****************************************************************************
 *  @fn     IMVS_PF_GetAllModuleList_U
 *  @brief  获取当前所有模块列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstModuleInfoList       [OUT]      所有模块信息列表(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetAllModuleList_U
 *  @brief  Get the list of all modules
 *  @param  handle                  [IN]       Handle
 *  @param  pstModuleInfoList       [OUT]      List of all modules information (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetAllModuleList_U(IN const void * const handle, OUT IMVS_PF_MODULE_INFO_LIST * const pstModuleInfoList);

/****************************************************************************
 *  @fn     IMVS_PF_RegisterResultCallBack
 *  @brief  通过回调的方式将算法平台底层运行时的数据反馈给用户
 *  @param  handle                  [IN]       操作句柄
 *  @param  cbOutputPlatformInfo    [IN]       回调函数
 *  @param  pUser                   [IN]       用户句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_RegisterResultCallBack
 *  @brief  Register callback function to return the underlying data of algorithm platform
 *  @param  handle                  [IN]       Handle
 *  @param  cbOutputPlatformInfo    [IN]       Callback function
 *  @param  pUser                   [IN]       User handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_RegisterResultCallBack(IN const void * const handle , IN int ( __stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo , IN void * const pUser) , IN void * const pUser);

/****************************************************************************
 *  @fn     IMVS_PF_RegisterResultCallBack_U
 *  @brief  通过回调的方式将算法平台底层运行时的数据反馈给用户(UTF8)
 *  @param  handle                  [IN]       操作句柄
 *  @param  cbOutputPlatformInfo    [IN]       回调函数
 *  @param  pUser                   [IN]       用户句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_RegisterResultCallBack_U
 *  @brief  Register callback function to return the underlying data of algorithm platform (UTF8 format)
 *  @param  handle                  [IN]       Handle
 *  @param  cbOutputPlatformInfo    [IN]       Callback function
 *  @param  pUser                   [IN]       User handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_RegisterResultCallBack_U(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/****************************************************************************
 *  @fn     IMVS_PF_RegisterResultCallBack_V30
 *  @brief  通过回调的方式将算法平台底层运行时的数据反馈给用户(模块结果以模块结构体方式回调)
 *  @param  handle                  [IN]       操作句柄
 *  @param  cbOutputPlatformInfo    [IN]       回调函数
 *  @param  pUser                   [IN]       用户句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_RegisterResultCallBack_V30
 *  @brief  Register callback function to return the underlying data of algorithm platform.
 *          The module output results are called back in structure format
 *  @param  handle                  [IN]       Handle
 *  @param  cbOutputPlatformInfo    [IN]       Callback function
 *  @param  pUser                   [IN]       User handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_RegisterResultCallBack_V30(IN const void * const handle , IN int ( __stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo , IN void * const pUser) , IN void * const pUser);

/****************************************************************************
 *  @fn     IMVS_PF_RegisterResultCallBack_V30_U
 *  @brief  通过回调的方式将算法平台底层运行时的数据反馈给用户(模块结果以模块结构体方式回调)(UTF8)
 *  @param  handle                  [IN]       操作句柄
 *  @param  cbOutputPlatformInfo    [IN]       回调函数
 *  @param  pUser                   [IN]       用户句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_RegisterResultCallBack_V30_U
 *  @brief  Register callback function to return the underlying data of algorithm platform.
 *          The module output results are called back in structure format (UTF8 format)
 *  @param  handle                  [IN]       Handle
 *  @param  cbOutputPlatformInfo    [IN]       Callback function
 *  @param  pUser                   [IN]       User handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_RegisterResultCallBack_V30_U(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/****************************************************************************
 *  @fn     IMVS_PF_RegisterResultCallBack_V32
 *  @brief  通过回调的方式将算法平台底层运行时的数据反馈给用户(模块结果只回调用户在界面上配置的感兴趣部分)
 *  @param  handle                  [IN]       操作句柄
 *  @param  cbOutputPlatformInfo    [IN]       回调函数
 *  @param  pUser                   [IN]       用户句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_RegisterResultCallBack_V32
 *  @brief  Register callback function to return the underlying data of algorithm platform.
 *          Module results call back only the parts of interest that users configure on the interface
 *  @param  handle                  [IN]       Handle
 *  @param  cbOutputPlatformInfo    [IN]       Callback function
 *  @param  pUser                   [IN]       User handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_RegisterResultCallBack_V32(IN const void * const handle , IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo , IN void * const pUser) , IN void * const pUser);

/****************************************************************************
 *  @fn     IMVS_PF_RegisterResultCallBack_V32_U
 *  @brief  通过回调的方式将算法平台底层运行时的数据反馈给用户(模块结果只回调用户在界面上配置的感兴趣部分)(UTF8)
 *  @param  handle                  [IN]       操作句柄
 *  @param  cbOutputPlatformInfo    [IN]       回调函数
 *  @param  pUser                   [IN]       用户句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_RegisterResultCallBack_V32_U
 *  @brief  Register callback function to return the underlying data of algorithm platform.
 *          Module results call back only the parts of interest that users configure on the interface (UTF8 format)
 *  @param  handle                  [IN]       Handle
 *  @param  cbOutputPlatformInfo    [IN]       Callback function
 *  @param  pUser                   [IN]       User handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_RegisterResultCallBack_V32_U(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/****************************************************************************
 *  @fn     IMVS_PF_FilterCallBackResult
 *  @brief  按过滤条件过滤回调内容
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstFilterCondition      [IN]       过滤条件信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_FilterCallBackResult
 *  @brief  Filter the called back contents according to module and data type
 *  @param  handle                  [IN]       Handle
 *  @param  pstFilterCondition      [IN]       Filter condition
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_FilterCallBackResult(IN const void * const handle , IN const IMVS_PF_FILTER_CONDITION_LIST * const pstFilterCondition);

/****************************************************************************
 *  @fn     IMVS_PF_ImportModuleData
 *  @brief  向指定的模块导入数据
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstImportData           [IN]       导入模块数据信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ImportModuleData
 *  @brief  Import data to specified module
 *  @param  handle                  [IN]       Handle
 *  @param  pstImportData           [IN]       The data to be imported
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ImportModuleData(IN const void * const handle , IN const IMVS_PF_IMPORT_MODULE_DATA_INPUT * const pstImportData);

/****************************************************************************
 *  @fn     IMVS_PF_ImportModuleData_U
 *  @brief  向指定的模块导入数据
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstImportData           [IN]       导入模块数据信息(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ImportModuleData_U
 *  @brief  Import data to specified module
 *  @param  handle                  [IN]       Handle
 *  @param  pstImportData           [IN]       The data to be imported (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ImportModuleData_U(IN const void * const handle, IN const IMVS_PF_IMPORT_MODULE_DATA_INPUT * const pstImportData);

/****************************************************************************
 *  @fn     IMVS_PF_CtrlCallBackModuResult
 *  @brief  模块开启/停止回调信息
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID (模块ID为IMVS_PF_ALL_MODULE_CTRL_CALLBACK时表示所有模块开启/停止回调信息)
 *  @param  nCallbackStatus         [IN]       回调状态（0：停止回调；1：开启回调）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_CtrlCallBackModuResult
 *  @brief  Start/Stop module callback information
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID (The module ID is IMVS_PF_ALL_MODULE_CTRL_CALLBACK indicates that all modules are starting/stopping callback information)
 *  @param  nCallbackStatus         [IN]       Callback status (0:off; 1:on)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_CtrlCallBackModuResult(IN const void * const handle, IN const unsigned int nModuleID, IN const unsigned int nCallbackStatus);

/****************************************************************************
 *  @fn     IMVS_PF_GetCallBackModuResStatus
 *  @brief  获取模块开启/停止回调信息
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pnCallbackStatus        [IN]       回调状态（0：停止回调；1：开启回调）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetCallBackModuResStatus
 *  @brief  Get module callback status
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  pnCallbackStatus        [IN]       Callback status (0:off; 1:on)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetCallBackModuResStatus(IN const void * const handle, IN const unsigned int nModuleID, OUT unsigned int* pnCallbackStatus);

/****************************************************************************
 *  @fn     IMVS_PF_GetSolutionVersion
 *  @brief  获取方案版本信息
 *  @param  handle                  [IN]       操作句柄
 *  @param  strPath                 [IN]       方案绝对路径
 *  @param  strPassWord             [IN]       密码
 *  @param  pstSolutionVersionInfo  [OUT]      方案信息结构体指针
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetSolutionVersion
 *  @brief  Get the version information of solution
 *  @param  handle                  [IN]       Handle
 *  @param  strPath                 [IN]       Solution absolute path
 *  @param  strPassWord             [IN]       Solution password
 *  @param  pstSolutionVersionInfo  [OUT]      Pointer to solution information
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetSolutionVersion(IN const void * const handle, IN const char * const strPath, IN const char * const strPassWord, OUT IMVS_PF_SOLUTION_VERSION_INFO * pstSolutionVersionInfo);

/****************************************************************************
 *  @fn     IMVS_PF_GetSolutionVersion_U
 *  @brief  获取方案版本信息
 *  @param  handle                  [IN]       操作句柄
 *  @param  strPath                 [IN]       方案绝对路径(UTF8)
 *  @param  strPassWord             [IN]       密码
 *  @param  pstSolutionVersionInfo  [OUT]      方案信息结构体指针
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetSolutionVersion_U
 *  @brief  Get the version information of solution
 *  @param  handle                  [IN]       Handle
 *  @param  strPath                 [IN]       Solution absolute path (UTF8 format)
 *  @param  strPassWord             [IN]       Solution password
 *  @param  pstSolutionVersionInfo  [OUT]      Pointer to solution information
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetSolutionVersion_U(IN const void * const handle, IN const char * const strPath, IN const char * const strPassWord, OUT IMVS_PF_SOLUTION_VERSION_INFO * pstSolutionVersionInfo);

/****************************************************************************
 *  @fn     IMVS_PF_GetAllProcessList
 *  @brief  获取当前所有流程列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstProcessInfoList      [OUT]      流程信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetAllProcessList
 *  @brief  Get the list of all processes
 *  @param  handle                  [IN]       Handle
 *  @param  pstProcessInfoList      [OUT]      List of all processes information
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetAllProcessList(IN const void * const handle , OUT IMVS_PF_PROCESS_INFO_LIST * const pstProcessInfoList);

/****************************************************************************
 *  @fn     IMVS_PF_GetAllProcessList_U
 *  @brief  获取当前所有流程列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstProcessInfoList      [OUT]      流程信息列表(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetAllProcessList_U
 *  @brief  Get the list of all processes
 *  @param  handle                  [IN]       Handle
 *  @param  pstProcessInfoList      [OUT]      List of all processes information (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetAllProcessList_U(IN const void * const handle, OUT IMVS_PF_PROCESS_INFO_LIST * const pstProcessInfoList);

/****************************************************************************
 *  @fn     IMVS_PF_GetModulesByProcessId
 *  @brief  获取特定流程当前所有模块列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @param  pstModuleInfoList       [OUT]      模块信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetModulesByProcessId
 *  @brief  Get all modules information list of specified process
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @param  pstModuleInfoList       [OUT]      All modules information list
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetModulesByProcessId(IN const void * const handle , IN const unsigned int nProcessID, OUT IMVS_PF_MODULE_INFO_LIST * const pstModuleInfoList);

/****************************************************************************
 *  @fn     IMVS_PF_GetModulesByProcessId_U
 *  @brief  获取特定流程当前所有模块列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @param  pstModuleInfoList       [OUT]      模块信息列表(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetModulesByProcessId_U
 *  @brief  Get all modules information list of specified process
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @param  pstModuleInfoList       [OUT]      All modules information list (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetModulesByProcessId_U(IN const void * const handle, IN const unsigned int nProcessID, OUT IMVS_PF_MODULE_INFO_LIST * const pstModuleInfoList);

/****************************************************************************
 *  @fn     IMVS_PF_GetSolutionPath
 *  @brief  获取方案路径
 *  @param  handle            [IN]       操作句柄
 *  @param  nPathSize         [IN]       路径缓存区大小
 *  @param  strSolPath        [OUT]      方案路径
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetSolutionPath
 *  @brief  Get the solution path
 *  @param  handle            [IN]       Handle
 *  @param  nPathSize         [IN]       Buffer size of solution path
 *  @param  strSolPath        [OUT]      Solution path
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetSolutionPath(IN const void * const handle, IN const unsigned int nPathSize, OUT char * const strSolPath);

/****************************************************************************
 *  @fn     IMVS_PF_GetSolutionPath_U
 *  @brief  获取方案路径
 *  @param  handle            [IN]       操作句柄
 *  @param  nPathSize         [IN]       路径缓存区大小
 *  @param  strSolPath        [OUT]      方案路径(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetSolutionPath_U
 *  @brief  Get the solution path
 *  @param  handle            [IN]       Handle
 *  @param  nPathSize         [IN]       Buffer size of solution path
 *  @param  strSolPath        [OUT]      Solution path (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetSolutionPath_U(IN const void * const handle, IN const unsigned int nPathSize, OUT char * const strSolPath);

/****************************************************************************
 *  @fn     IMVS_PF_SetImageData
 *  @brief  设置用户图像数据
 *  @param  handle            [IN]       操作句柄
 *  @param  pstInputImageInfo [IN]       用户图像数据
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetImageData
 *  @brief  Set user image data
 *  @param  handle            [IN]       Handle
 *  @param  pstInputImageInfo [IN]       User image data
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetImageData(IN const void * const handle, IN const IMVS_PF_INPUT_IMAGE_INFO * const pstInputImageInfo);

/****************************************************************************
*  @fn     IMVS_PF_SetImageBufferNodeNum
*  @brief  设置模块输出图像的缓存节点数量（该接口只能在流程运行之前调用，否则会出现异常）
*  @param  handle            [IN]       操作句柄
*  @param  nModuleId         [IN]       模块ID
*  @param  nBufferNodeNum    [IN]       缓存节点数量
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码

*  @fn     IMVS_PF_SetImageBufferNodeNum
*  @brief  Set image buffer node num(Use function before procedure run, otherwise cause exception)
*  @param  handle            [IN]       Handle
*  @param  nModuleId         [IN]       Module id
*  @param  nBufferNodeNum    [IN]       Buffer node num
*  @return Return IMVS_EC_OK for success, and return Error Code for failure
****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetImageBufferNodeNum(IN const void * const handle, IN const unsigned int nModuleId, IN const unsigned int nBufferNodeNum);

/****************************************************************************
 *  @fn     IMVS_PF_SetBinaryData
 *  @brief  设置二进制数据
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstBinaryDataInfo       [IN]       二进制数据信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetBinaryData
 *  @brief  Set the binary data
 *  @param  handle                  [IN]       Handle
 *  @param  pstBinaryDataInfo       [IN]       Binary data information
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetBinaryData(IN const void * const handle, IN const IMVS_PF_SET_BINARY_DATA_INFO * const pstBinaryDataInfo);

/****************************************************************************
 *  @fn     IMVS_PF_GetBinaryDataLength
 *  @brief  获取二进制数据长度
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstBinaryDataLenInfo    [INOUT]    二进制数据长度信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetBinaryDataLength
 *  @brief  Gets the binary data length
 *  @param  handle                  [IN]       Handle
 *  @param  pstBinaryDataLenInfo    [INOUT]    Binary data length information
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetBinaryDataLength(IN const void * const handle, INOUT IMVS_PF_GET_BINARY_DATA_LEN_INFO * const pstBinaryDataLenInfo);

/****************************************************************************
 *  @fn     IMVS_PF_GetBinaryData
 *  @brief  获取二进制数据
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstBinaryDataInfo       [IN]       二进制数据信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetBinaryData
 *  @brief  Gets the binary data
 *  @param  handle                  [IN]       Handle
 *  @param  pstBinaryDataInfo       [IN]       Binary data information
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetBinaryData(IN const void * const handle, INOUT IMVS_PF_GET_BINARY_DATA_INFO * const pstBinaryDataInfo);

/****************************************************************************
 *  @fn     IMVS_PF_ExportProcess
 *  @brief  导出流程
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  strExportPath     [IN]       导出路径（绝对路径）
 *  @param  strPassword       [IN]       文件密码(预留)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ExportProcess
 *  @brief  Export the process
 *  @param  handle            [IN]       Handle
 *  @param  nProcessID        [IN]       Process ID
 *  @param  strExportPath     [IN]       The path of the export process, absolute path
 *  @param  strPassword       [IN]       File password (reserved)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ExportProcess(IN const void * const handle, IN const unsigned int nProcessID, IN const char * const strExportPath, IN const char * const strPassword);

/****************************************************************************
 *  @fn     IMVS_PF_ImportProcess
 *  @brief  导入流程
 *  @param  handle            [IN]       操作句柄
 *  @param  strImportPath     [IN]       导入路径（绝对路径）
 *  @param  strPassword       [IN]       文件密码(预留)
 *  @param  bOverrideGlobal   [IN]       是否覆盖全局模块(false：忽略流程文件中的全局模块，true：覆盖相同全局模块数据)
 *  @param  nIdAllocateWay    [IN]       ID分配方式 (0：自动分配ID，1：按文件中的ID分配)
 *  @param  pstProcessInfo    [OUT]      输出流程信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ImportProcess
 *  @brief  Import the process
 *  @param  handle            [IN]       Handle
 *  @param  strImportPath     [IN]       The path of the import process, absolute path
 *  @param  strPassword       [IN]       File password (reserved)
 *  @param  bOverrideGlobal   [IN]       Whether to override the global module (false: Ignore the global module in the process file, true: Overwrite the same global module data)
 *  @param  nIdAllocateWay    [IN]       ID allocated way (0: Auto, 1: According to the file)
 *  @param  pstProcessInfo    [OUT]      Output process information
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ImportProcess(IN const void * const handle, IN const char * const strImportPath, IN const char * const strPassword, IN const bool bOverrideGlobal, IN const unsigned int nIdAllocateWay, OUT IMVS_PF_IMPORT_PROCESS_INFO * const pstProcessInfo);

/****************************************************************************
 *  @fn     IMVS_PF_DeleteOneProcess
 *  @brief  删除一个流程
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_DeleteOneProcess
 *  @brief  Delete one process
 *  @param  handle            [IN]       Handle
 *  @param  nProcessID        [IN]       Process id
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_DeleteOneProcess(IN const void * const handle, IN const unsigned int nProcessID);

/****************************************************************************
 *  @fn     IMVS_PF_GetModuleIDByFullName
 *  @brief  根据流程模块全名称获取模块ID
 *  @param  handle            [IN]       操作句柄
 *  @param  strFullName       [IN]       流程模块全名称（格式：流程名.Group模块名.模块名），如果为全局模块或流程，只填一级的名称；二次开发SDK导入Group，第一级名称填空字符串和“none”
 *  @param  bIsIndependentGro [IN]       是否独立Group内模块
 *  @param  pnModuleId        [OUT]      模块ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetModuleIDByFullName
 *  @brief  Get the module ID according to the full name of the solution
 *  @param  handle            [IN]       Handle
 *  @param  strFullName       [IN]       Full name of the process and module (Format: Process display name.Group display name.Module display name)
 *  @param  bIsIndependentGro [IN]       Whether the module in the independent Group
 *  @param  pnModuleId        [OUT]      Module id
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetModuleIDByFullName(IN const void * const handle, IN const char * const strFullName, IN const bool bIsIndependentGro, OUT unsigned int * const pnModuleId);

/****************************************************************************
 *  @fn     IMVS_PF_SetAllCameraCheckParam
 *  @brief  设置所有相机模块是否打开参数
 *  @param  handle                  [IN]       操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetAllCameraCheckParam
 *  @brief  Set all camera modules "CheckCameraOpened" parameter
 *  @param  handle                  [IN]       Handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetAllCameraCheckParam(IN const void * const handle);

/****************************************************************************
 *  @fn     IMVS_PF_GetCameraConnectStatus
 *  @brief  获取相机连接状态信息
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pnConnectStatus         [OUT]      连接状态 (1: 已连接, 0: 未连接)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetCameraConnectStatus
 *  @brief  Gets the camera connection status information
 *  @param  handle                  [IN]       Handle
 *  @param  nModuleID               [IN]       Module ID
 *  @param  pnConnectStatus         [OUT]      Connection status (1: Connected, 0: Not connected)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetCameraConnectStatus(IN const void * const handle, IN const unsigned int nModuleID, OUT int * const pnConnectStatus);

/****************************************************************************
 * 平台控制接口
 * Platform Control Related API
 ****************************************************************************/
/****************************************************************************
 *  @fn     IMVS_PF_ExecuteOnce
 *  @brief  算法平台单次执行
 *  @param  handle                  [IN]       操作句柄
 *  @param  strCommand              [IN]       命令字符串
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ExecuteOnce
 *  @brief  Execute the algorithm platform only once
 *  @param  handle                  [IN]       Handle
 *  @param  strCommand              [IN]       Triggering command string
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ExecuteOnce(IN const void * const handle , IN const char * const strCommand);

/****************************************************************************
 *  @fn     IMVS_PF_ExecuteOnce_U
 *  @brief  算法平台单次执行
 *  @param  handle                  [IN]       操作句柄
 *  @param  strCommand              [IN]       命令字符串(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ExecuteOnce_U
 *  @brief  Execute the algorithm platform only once
 *  @param  handle                  [IN]       Handle
 *  @param  strCommand              [IN]       Triggering command string (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ExecuteOnce_U(IN const void * const handle, IN const char * const strCommand);

/****************************************************************************
 *  @fn     IMVS_PF_ContinousExecute
 *  @brief  算法平台连续执行开始
 *  @param  handle                  [IN]       操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ContinousExecute
 *  @brief  Execute the algorithm platform continuously
 *  @param  handle                  [IN]       Handle
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ContinousExecute(IN const void * const handle);

/****************************************************************************
 *  @fn     IMVS_PF_StopExecute
 *  @brief  算法平台连续执行结束
 *  @param  handle                  [IN]       操作句柄
 *  @param  nWaitTime               [IN]       超时时间（单位：秒）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_StopExecute
 *  @brief  Stop continuous execution of algorithm platform
 *  @param  handle                  [IN]       Handle
 *  @param  nWaitTime               [IN]       Waiting time, unit:s
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_StopExecute(IN const void * const handle, IN const unsigned int nWaitTime);

/****************************************************************************
 *  @fn     IMVS_PF_SetContinousExecuteInterval
 *  @brief  设置连续执行两次运行之间时间间隔
 *  @param  handle                  [IN]       操作句柄
 *  @param  nMilliSecond            [IN]       两次运行之间时间间隔
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetContinousExecuteInterval
 *  @brief  Set the execution time interval of continuous execution
 *  @param  handle                  [IN]       Handle
 *  @param  nMilliSecond            [IN]       The execution time interval, unit: millisecond
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetContinousExecuteInterval(IN const void * const handle, IN const unsigned int nMilliSecond);

/****************************************************************************
 *  @fn     IMVS_PF_ExecuteOnce_V30
 *  @brief  算法平台特定流程运行一次
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @param  strCommand              [IN]       触发字符串
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ExecuteOnce_V30
 *  @brief  Execute the algorithm platform specified process only once
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @param  strCommand              [IN]       Triggering command string
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ExecuteOnce_V30(IN const void * const handle, IN const unsigned int nProcessID, IN const char * const strCommand, bool bIsP2P = false);

/****************************************************************************
 *  @fn     IMVS_PF_ExecuteOnce_V30_U
 *  @brief  算法平台特定流程运行一次
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @param  strCommand              [IN]       触发字符串(UTF8)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ExecuteOnce_V30_U
 *  @brief  Execute the algorithm platform specified process only once
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @param  strCommand              [IN]       Triggering command string (UTF8 format)
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ExecuteOnce_V30_U(IN const void * const handle, IN const unsigned int nProcessID, IN const char * const strCommand);

/****************************************************************************
 *  @fn     IMVS_PF_ExecuteOnceEX_V30
 *  @brief  算法平台特定流程运行一次（带执行次数）
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @param  strCommand              [IN]       触发字符串
 *  @param  pnExecuteCount          [OUT]      执行次数
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ExecuteOnceEX_V30
 *  @brief  Execute the algorithm platform specified process only once with execution times
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @param  strCommand              [IN]       Triggering command string
 *  @param  pnExecuteCount          [OUT]      Execution times
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ExecuteOnceEX_V30(IN const void * const handle, IN const unsigned int nProcessID, IN const char * const strCommand, OUT unsigned int * const pnExecuteCount);

/****************************************************************************
 *  @fn     IMVS_PF_ContinousExecute_V30
 *  @brief  算法平台特定流程连续执行开始
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_ContinousExecute_V30
 *  @brief  Execute the algorithm platform specified process continuously
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_ContinousExecute_V30(IN const void * const handle, IN const unsigned int nProcessID);

/****************************************************************************
 *  @fn     IMVS_PF_StopExecute_V30
 *  @brief  算法平台特定流程停止执行
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @param  nWaitTime               [IN]       等待时间（单位：秒）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_StopExecute_V30
 *  @brief  Stop executing the specified process of algorithm platform
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @param  nWaitTime               [IN]       Waiting time, unit: second
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_StopExecute_V30(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nWaitTime);

/****************************************************************************
 *  @fn     IMVS_PF_SetContinousExecuteInterval_V30
 *  @brief  设置特定流程连续执行两次运行之间时间间隔
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @param  nMilliSecond            [IN]       时间间隔
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_SetContinousExecuteInterval_V30
 *  @brief  Set the execution time interval of specified process continuous execution
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @param  nMilliSecond            [IN]       The execution time interval, unit: millisecond
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetContinousExecuteInterval_V30(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nMilliSecond);

/****************************************************************************
 *  @fn     IMVS_PF_CtrlShieldProcess
 *  @brief  设置特定流程禁用/启用状态
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @param  nShieldStatus           [IN]       流程禁用/启用状态（1：禁用；0：启用）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_CtrlShieldProcess
 *  @brief  Set the disable/enable status of specified process
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @param  nShieldStatus           [IN]       disable/enable status, disable:1, enable:0
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_CtrlShieldProcess(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nShieldStatus);

/****************************************************************************
 *  @fn     IMVS_PF_GetProcedureShieldStatus
 *  @brief  获取特定流程禁用/启用状态
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @param  pnShieldStatus          [OUT]      流程禁用/启用状态（1：禁用；0：启用）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetProcedureShieldStatus
 *  @brief  Get the disable/enable status of specified process
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @param  pnShieldStatus          [OUT]      disable/enable status, disable:1, enable:0
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetProcedureShieldStatus(IN const void * const handle, IN const unsigned int nProcessID, OUT unsigned int * const pnShieldStatus);

/****************************************************************************
 *  @fn     IMVS_PF_MakeModulesPrepared
 *  @brief  模块资源预分配
 *  @param  handle            [IN]       操作句柄
 *  @param  pstCamPicInfoList [IN]       相机图像模块信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_MakeModulesPrepared
 *  @brief  Make module resource prepared
 *  @param  handle            [IN]       Handle
 *  @param  pstCamPicInfoList [IN]       Camera module picture information
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_MakeModulesPrepared(IN const void * const handle, IN const IMVS_PF_CAMERA_PIC_INFO_LIST * const pstCamPicInfoList);

/****************************************************************************
 *  @fn     IMVS_PF_GetProcessWorkStatus
 *  @brief  获取流程状态信息
 *  @param  handle                  [IN]       操作句柄
 *  @param  nProcessID              [IN]       流程ID
 *  @param  pnWorkStatus            [OUT]      当前流程运行状态 (1: 忙碌, 0: 空闲, -1: 停止)，与E0000300有区别
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码

 *  @fn     IMVS_PF_GetProcessWorkStatus
 *  @brief  Get process status information
 *  @param  handle                  [IN]       Handle
 *  @param  nProcessID              [IN]       Process ID
 *  @param  pnWorkStatus            [OUT]      The current process running state (1: busy, 0: free, -1: stop), has a difference with E0000300
 *  @return Return IMVS_EC_OK for success, and return Error Code for failure
 ****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetProcessWorkStatus(IN const void * const handle, IN const unsigned int nProcessID, OUT int * const pnWorkStatus);

/****************************************************************************
*  @fn     IMVS_PF_SetModuleResultBuffer
*  @brief  设置模块结果缓存配置
*  @param  handle                  [IN]       操作句柄
*  @param  bBufferEnable           [IN]       缓存使能
*  @param  nBufferNum              [IN]       缓存结果数量
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码

*  @fn     IMVS_PF_SetModuleResultBuffer
*  @brief  Set module result buffer configuration
*  @param  handle                  [IN]       Handle
*  @param  bBufferEnable           [IN]       Buffer enable
*  @param  nBufferNum              [IN]       Number of module result
*  @return Return IMVS_EC_OK for success, and return Error Code for failure
****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetModuleResultBuffer(IN const void * const handle, IN bool bBufferEnable, IN unsigned int nBufferNum);

/****************************************************************************
*  @fn     IMVS_PF_GetModuleResultBuffer
*  @brief  获取模块结果缓存配置
*  @param  handle                  [IN]       操作句柄
*  @param  pbBufferEnable          [OUT]      缓存使能
*  @param  pnBufferNum             [OUT]      缓存结果数量
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码

*  @fn     IMVS_PF_GetModuleResultBuffer
*  @brief  Get module result buffer configuration
*  @param  handle                  [IN]       Handle
*  @param  pbBufferEnable          [OUT]      Buffer enable
*  @param  pnBufferNum             [OUT]      Number of module result
*  @return Return IMVS_EC_OK for success, and return Error Code for failure
****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_GetModuleResultBuffer(IN const void * const handle, OUT bool * const pbBufferEnable, OUT unsigned int * const pnBufferNum);

/****************************************************************************
*  @fn     IMVS_PF_SetFileSuffixVerify
*  @brief  设置方案后缀是否校验
*  @param  handle                  [IN]       操作句柄
*  @param  bVerifyEnable              [IN]       校验使能
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码

*  @fn     IMVS_PF_SetFileSuffixVerify
*  @brief  Set whether the solution suffix is verified
*  @param  handle                  [IN]       Handle
*  @param  bVerifyEnable              [IN]       Verify enable
*  @return Return IMVS_EC_OK for success, and return Error Code for failure
****************************************************************************/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_SetFileSuffixVerify(IN const void * const handle, IN bool bVerifyEnable = true);



#ifdef __cplusplus
}
#endif

#endif // IMVS_6000_SDK4CLIENTC_H__
