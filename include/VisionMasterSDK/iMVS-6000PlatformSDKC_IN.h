/***************************************************************************************************
 *
 * 版权信息：版权所有 (c) 2017, 保留所有权利
 *
 * 文件名称：iMVS-6000PlatformSDKC_IN.h
 * 摘    要: 二次开发SDK C接口头文件
 *
 * 作    者: 视觉平台组
 * 日    期：2019-05-18 16:46:42
 * 备    注：新建
 ****************************************************************************************************/
#ifndef IMVS_6000_PLATFORMSDKC_IN_H__ // 2019-05-18 16:46:42
#define IMVS_6000_PLATFORMSDKC_IN_H__

#include "iMVS-6000SDK4ServerDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn     IMVS_GetLastError
 *  @brief  用来获取系统的或者本SDK的错误码
 *  @return 返回本SDK的错误描述
 */
IMVS_6000_PLATFORMSDK_API const char * __stdcall IMVS_GetLastError();

/** @fn     IMVS_GetBuildVersion
 *  @brief  获取编译版本
 *  @param  pnYear      [OUT]   编译版本年份
 *  @param  pnMonth     [OUT]   编译版本月份
 *  @param  pnDay       [OUT]   编译版本日份
 *  @return 返回当前编译版本信息字符串
 */
IMVS_6000_PLATFORMSDK_API const char * __stdcall IMVS_GetBuildVersion(OUT unsigned int * const pnYear = IMVS_NULL, OUT unsigned int * const pnMonth = IMVS_NULL, OUT unsigned int * const pnDay = IMVS_NULL);

/** @fn     IMVS_CreateHandle
 *  @brief  创建句柄
 *  @param  handle                  [OUT]       要生成的句柄
 *  @param  pstPlatformBasicInfo    [IN]        算法平台基本信息
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CreateHandle(OUT void ** const handle, IN const IMVS_PLATFORM_BASIC_INFO * const pstPlatformBasicInfo, OUT int* waitingTime = nullptr);

/** @fn     IMVS_DestroyHandle
 *  @brief  销毁句柄
 *  @param  handle        [IN]   待销毁的句柄
 *  @param  nTakeoverType [IN]   接管类型
 *  @return 成功，返回HKR_OK；失败，返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DestroyHandle(IN const void * const handle, IN const unsigned int nTakeoverType = 0);

/** @fn     IMVS_RegisterOutputPlatformInfoCallBack
 *  @brief  注册回调函数
 *  @param  handle                  [IN]        句柄
 *  @param  cbOutputPlatformInfo    [IN]        回调函数
 *  @param  pUser                   [IN]        pUser
 *  @return 成功，返回CM_OK；失败，返回对应错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_RegisterOutputPlatformInfoCallBack(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/** @fn     IMVS_GetPlatformDetailedInfo
 *  @brief  获取本算法平台所有信息
 *  @brief  一个句柄在算法平台中拖拽模块和订阅后,运行了一段时间
 *  @brief  一个新句柄连接算法平台时, 调用此接口可以获取当前算法平台的模块的信息
 *  @brief  订阅的信息, 连接的信息,以及算法平台状态信息等等
 *  @brief  暂时没用到, 后续可能用到
 *  @param  handle                  [IN]        句柄
 *  @param  pstPlatformDetailedInfo [OUT]       平台详细信息
 *  @return 成功，返回CM_OK；失败，返回对应错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetPlatformDetailedInfo(IN const void * const handle, OUT IMVS_PLATFORM_DETAILED_INFO * pstPlatformDetailedInfo);

/** @fn     IMVS_AddOneModule
 *  @brief  根据传入的名称拉起一个对应模块
 *  @param  handle                  [IN]       句柄
 *  @param  strModuleName           [IN]       模块名称
 *  @return 成功，返回CM_OK；失败，返回对应错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddOneModule(IN const void * const handle, IN const IMVS_SYNC_ADD_ONE_MODULE_INFO * const pstSyncAddModuInput, OUT IMVS_MODULE_INFO * const pstModuleInfo);

/** @fn     IMVS_CloseOneModule
 *  @brief  关闭一个模块
 *  @param  pstModuleInfo           [IN]    模块信息
 *  @param  handle                  [IN]    句柄
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CloseOneModule(IN const void * const handle, IN const unsigned int nModuleId);

/** @fn     IMVS_SelfExecuteOneModule
 *  @brief  模块自执行:该模块利用旧的输入重新进行一次算法,将结果发给界面(不发给后继模块)
 *  @param  nModuleId               [IN]    模块Id
 *  @param  handle                  [IN]    句柄
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SelfExecuteOneModule(IN const void * const handle, IN const unsigned int nModuleId);

/** @fn     IMVS_ConnectOneModule
 *  @brief  模块连接:本地图--> 圆查找
 *  @param  pstPreModuleInfo        [IN]    前接模块
 *  @param  pstNextModuleInfo       [IN]    后继模块
 *  @param  handle                  [IN]    句柄
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ConnectOneModule(IN const void * const handle, IN const unsigned int nPreModuleId, IN const unsigned int nNextModuleId);

/** @fn     IMVS_DisConnectOneModule
 *  @brief  模块断开连接:本地图-x> 圆查找
 *  @param  pstPreModuleInfo        [IN]    前接模块
 *  @param  pstNextModuleInfo       [IN]    后继模块
 *  @param  handle                  [IN]    句柄
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DisConnectOneModule(IN const void * const handle, IN const unsigned int nPreModuleId, IN const unsigned int nNextModuleId);

/** @fn     IMVS_ExecuteOnceOneModule
 *  @brief  暂时没用到,针对某个模块执行一次,用于区分多条流水线分别执行
 *  @param  pstModuleInfo        [IN]    前接模块
 *  @param  nCycleID             [IN]    流程ID
 *  @param  handle               [IN]    句柄
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExecuteOnceOneModule(IN const void * const handle, IN const IMVS_MODULE_INFO * const pstModuleInfo, IN const unsigned int nCycleID);

/** @fn     IMVS_ExecuteOnce
 *  @brief  统一所有源头执行一次
 *  @brief  strTrigger表示触发字符串,透传到每个模块
 *  @param  strTrigger        [IN]    触发字符串
 *  @param  handle            [IN]    句柄
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExecuteOnce(IN const void * const handle, IN const char * const strTrigger);

/** @fn     IMVS_ContinousRunStart
 *  @brief  连续执行开始
 *  @param  handle            [IN]    句柄
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ContinousRunStart(IN const void * const handle);

/** @fn     IMVS_StopExecute
 *  @brief  停止执行
 *  @param  handle            [IN]    句柄
 *  @param  nWaitTime         [IN]    超时时间(单位：秒)
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_StopExecute(IN const void * const handle, IN const unsigned int nWaitTime);

/** @fn     IMVS_SetContinousRunInterval
 *  @brief  设置连续执行时间间隔
 *  @param  handle            [IN]    句柄
 *  @param  nMilliSecond      [IN]    时间间隔
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetContinousRunInterval(IN const void * const handle, IN const unsigned int nMilliSecond);

/** @fn     IMVS_SubscribeResultEx
 *  @brief  两个模块之间订阅数据
 *  @brief  V2.0.1 版本新增接口
 *  @param  handle            [IN]    句柄
 *  @param  pstSubscribeInfo  [IN]    订阅信息
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SubscribeResultEx(IN const void * const handle, 
                                                              IN const IMVS_SUBSCRIBE_INFO * const pstSubscribeInfo);

/** @fn     IMVS_UnSubscribeResultEx
 *  @brief  两个模块之间解订阅数据
 *  @param  handle            [IN]    句柄
 *  @param  pstSubscribeInfo  [IN]    订阅信息
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_UnSubscribeResultEx(IN const void * const handle, 
                                                              IN const IMVS_SUBSCRIBE_INFO * const pstSubscribeInfo);

/** @fn     IMVS_CheckSolution
 *  @brief  检查方案里面有没有密码
 *  @param  strPath            [IN]     方案路径
 *  @param  pnHasPwd           [OUT]    是否有方案密码（1: 有密码）
 *  @param  pnValidFormat      [OUT]    方案格式是否有效（1：格式有效）
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CheckSolution(
    IN const char * const strPath,      // 方案路径
    OUT unsigned int * pnHasPwd,        // 是否有方案密码
    OUT unsigned int * pnValidFormat);  // 方案格式是否有效

/** @fn     IMVS_CheckPassword
 *  @brief  验证方案密码
 *  @param  strPath            [IN]     方案路径
 *  @param  strPassWord        [IN]     方案密码
 *  @param  pnIsCorrect        [OUT]    方案密码是否正确
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CheckPassword(
    IN const char * const strPath,      // 方案路径
    IN const char * const strPassWord,
    OUT int * pnIsCorrect);

/** @fn     IMVS_SaveSolution
 *  @brief  保存方案
 *  @param  handle             [IN]     操作句柄
 *  @param  strPath            [IN]     方案路径
 *  @param  strPassWord        [IN]     方案密码
 *  @param  pData              [IN]     界面数据
 *  @param  nDataLen           [IN]     界面数据长度
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SaveSolution(
    IN const void * const handle,
    IN const char * const strPath,       // 方案路径
    IN const char * const strPassWord,   // 方案密码
    IN const unsigned char * const pData,// 界面数据
    IN const unsigned int nDataLen
    );

/** @fn     IMVS_GetSolutionVersion
 *  @brief  获取方案版本
 *  @param  handle                 [IN]     操作句柄
 *  @param  strPath                [IN]     方案路径
 *  @param  strPassWord            [IN]     方案密码
 *  @param  pstSolutionVersionInfo [OUT]    方案版本信息
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetSolutionVersion(
    IN const void * const handle,
    IN const char * const strPath,
    IN const char * const strPassWord,
    OUT IMVS_SOLUTION_VERSION_INFO * pstSolutionVersionInfo);

/** @fn     IMVS_LoadSolution
 *  @brief  加载方案
 *  @param  handle                 [IN]     操作句柄
 *  @param  strPath                [IN]     方案路径
 *  @param  strPassWord            [IN]     方案密码
 *  @param  bIsCheckSol            [IN]     校验方案标记（SDK校验，vm不校验）
 *  @param  bReportSilenceRunFlag  [IN]     上报静默执行标记（V4.3增加，界面撤销时可以不上报静默）
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_LoadSolution(
    IN const void * const handle,
    IN const char * const strPath,      // 方案路径
    IN const char * const strPassWord,
	IN bool bIsCheckSol = true,
    IN bool bReportSilenceRunFlag = true);

/***************** 平台SDK二次开发新增 ******************/
/** @fn     IMVS_SetParamValue
 *  @brief  设置模块参数值
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  strName                 [IN]       参数名
 *  @param  strValue                [IN]       参数值
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetParamValue(IN const void * const handle ,
                                                          IN const unsigned int nModuleID ,
                                                          IN const char * const strName ,
                                                          IN const char * const strValue);

/** @fn     IMVS_SetParamValueForImageSource
*  @brief  设置模块参数值 增加、删除图片
*  @param  handle                  [IN]       操作句柄
*  @param  nModuleID               [IN]       模块ID
*  @param  strName                 [IN]       参数名
*  @param  strPath                 [IN]       图片路径
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetParamValueForImageSource(IN const void * const handle,
	IN const unsigned int nModuleID,
	IN const char * const strName,
	IN const char * const strPath);

/** @fn     IMVS_GetParamValue
 *  @brief  获取模块参数值
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  strName                 [IN]       参数名
 *  @param  nStrValueSize           [IN]       参数值的分配大小
 *  @param  strValue                [OUT]      参数值
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetParamValue(IN const void * const handle ,
                                                          IN const unsigned int nModuleID ,
                                                          IN const char * const strName ,
                                                          IN const unsigned int nStrValueSize ,
                                                          OUT char * const strValue);

/** @fn     IMVS_GetParamList
 *  @brief  获取模块参数列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pstModuleParamList      [OUT]      模块参数列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetParamList(IN const void * const handle ,
                                                         IN const unsigned int nModuleID ,
                                                         OUT IMVS_MODULE_PARAM_LIST * const pstModuleParamList);

/** @fn     IMVS_SetParamList
 *  @brief  设置模块参数列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pstModuleParamList      [IN]       模块参数列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetParamList(IN const void * const handle ,
                                                         IN const unsigned int nModuleID ,
                                                         IN const IMVS_MODULE_PARAM_LIST * const pstModuleParamList);

/** @fn     IMVS_PF_GetSaveProgress
 *  @brief  获取方案保存进度、保存结果(错误码)
 *  @param  handle                  [IN]       操作句柄
 *  @param  pnSaveprogress          [OUT]      方案保存进度
 *  @return 成功,返回IMVS_EC_OK; 失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetSaveProgress(IN const void * const handle , OUT unsigned int * const pnSaveprogress);

/** @fn     IMVS_GetLoadProgress
 *  @brief  获取方案加载进度、加载结果（错误码）
 *  @param  handle                  [IN]       操作句柄
 *  @param  pnLoadProgress          [OUT]      加载进度
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetLoadProgress(IN const void * const handle , OUT unsigned int * const pnLoadProgress);

/** @fn     IMVS_CloseSolution
 *  @brief  关闭算法平台当前方案
 *  @param  handle                  [IN]       操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CloseSolution(IN const void * const handle);

/** @fn     IMVS_GetAllModuleList
 *  @brief  获取当前所有模块列表
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstModuleInfoList       [OUT]      所有模块信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllModuleList(IN const void * const handle ,
                                                             OUT IMVS_MODULE_INFO_LIST * const pstModuleInfoList);

/** @fn     IMVS_ImportModuleData
 *  @brief  向指定的模块导入数据（方信佳和周浩雅约定）
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstImportData           [IN]       导入模块数据信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportModuleData(IN const void * const handle , IN const IMVS_IMPORT_MODULE_DATA_INPUT * const pstImportData);


/** @fn     IMVS_ExportModuleData
 *  @brief  指定的模块导出数据（M平台专用, 目前抛弃）
 *  @param  handle                  [IN]       操作句柄
 *  @param  pstExportData           [IN]       导入模块数据信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExportModuleData(IN const void * const handle , INOUT IMVS_EXPORT_MODULE_DATA_OUTPUT * const pstExportData);

/** @fn     IMVS_SetBinaryData
 *  @brief  类似于SetParamValue,只不过数据不只是字符串,可以是二进制数据
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pstSetBinaryDataInfo    [IN]       设置二进制数据信息
 *  @param  nRecvWaitTime           [IN]       接收消息超时
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetBinaryData(IN const void * const handle ,
                                                          IN const unsigned int nModuleID ,
                                                          IN IMVS_SET_BINARY_DATA_INFO * pstSetBinaryDataInfo , 
														  IN const unsigned int nRecvWaitTime = 0);

/** @fn     IMVS_GetBinaryLength
 *  @brief  GetBinaryData之前,用户想要知道数据大小时调用此接口
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pstGetBinaryLengthInfo  [OUT]      二进制数据长度信息
 *  @param  nRecvWaitTime           [IN]       接收超时（单位：ms）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetBinaryLength(IN const void * const handle ,
                                                          IN const unsigned int nModuleID ,
                                                          OUT IMVS_GET_BINARY_LENGTH_INFO * pstGetBinaryLengthInfo ,
														  IN const unsigned int nRecvWaitTime = 0);

/** @fn     IMVS_GetBinaryData
 *  @brief  类似于GetParamValue,只不过数据不只是字符串,可以是二进制数据
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  pstGetBinaryDataInfo    [OUT]      二进制数据信息
 *  @param  nRecvWaitTime           [IN]       接收超时（单位：ms）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetBinaryData(IN const void * const handle ,
                                                          IN const unsigned int nModuleID ,
                                                          OUT IMVS_GET_BINARY_DATA_INFO * pstGetBinaryDataInfo , 
														  IN const unsigned int nRecvWaitTime = 0);

/** @fn     IMVS_GetBinaryDataEx
*  @brief  类似于IMVS_GetBinaryData,内存接口内部申请
*  @param  handle                  [IN]       操作句柄
*  @param  nModuleID               [IN]       模块ID
*  @param  pstGetBinaryDataInfo    [OUT]      二进制数据信息
*  @param  nRecvWaitTime           [IN]       接收超时（单位：ms）
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetBinaryDataEx(IN const void * const handle,
    IN const unsigned int nModuleID,
    OUT IMVS_GET_BINARY_DATA_INFO * pstGetBinaryDataInfo,
    IN const unsigned int nRecvWaitTime = 0);

/***************** 算法平台V3.0新增 ******************/

/** @fn     IMVS_AddOneModuleWithProcId
 *  @brief  拉起对应模块
 *  @param  handle            [IN]       操作句柄
 *  @param  strModuleName     [IN]       模块名称
 *  @param  nProcessID        [IN]       流程ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddOneModuleWithProcId(
                      IN const void * const handle,
                      IN const char * const strModuleName,
                      IN const unsigned int nProcessID);

/** @fn     IMVS_ExecuteOnce_V30
 *  @brief  特定流程执行一次
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  strCommand        [IN]       命令字符串
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExecuteOnce_V30(
                      IN const void * const handle,
                      IN const unsigned int nProcessID,
					  IN const char * const strCommand, 
					  IN bool bIsP2P = false);

/** @fn     IMVS_ContinousRunStart_V30
 *  @brief  算法平台特定流程连续执行开始
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ContinousRunStart_V30(IN const void * const handle, IN const unsigned int nProcessID);

/** @fn     IMVS_StopExecute_V30
 *  @brief  算法平台特定流程停止连续执行
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  nWaitTime         [IN]       超时时间(单位：秒)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_StopExecute_V30(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nWaitTime);

/** @fn     IMVS_SetContinousRunInterval_V30
 *  @brief  设置特定流程时间间隔
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  nMilliSecond      [IN]       两次运行之间时间间隔
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetContinousRunInterval_V30(
                      IN const void * const handle,
                      IN const unsigned int nProcessID,
                      IN const unsigned int nMilliSecond);

/** @fn     IMVS_GetModuleListInProcess
 *  @brief  获取特定流程当前所有模块列表
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  pstModuleInfoList [OUT]      特定流程所有模块信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuleListInProcess(
                      IN const void * const handle,
                      IN const unsigned int nProcessID,
                      OUT IMVS_MODULE_INFO_LIST * const pstModuleInfoList);

/** @fn     IMVS_AddOneProcess
 *  @brief  添加一个流程
 *  @param  handle            [IN]       操作句柄
 *  @param  strDisplayName    [IN]       流程默认显示名称
 *  @param  pstPrcInfo        [OUT]      流程信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddOneProcess(IN const void * const handle, IN const char * const strDisplayName, OUT IMVS_PROCESS_INFO * const pstPrcInfo);

/** @fn     IMVS_DeleteOneProcess
 *  @brief  删除一个流程
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteOneProcess(IN const void * const handle, IN const unsigned int nProcessID);


/** @fn     IMVS_SetProcName
 *  @brief  设置流程名称
 *  @param  handle             [IN]       操作句柄
 *  @param  nProcessID         [IN]       流程ID
 *  @param  strProcName        [IN]       流程名称（不能含有问号与分号）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcName(
                      IN const void * const handle,
                      IN const unsigned int nProcessID,
                      IN const char * const strProcName);

/** @fn     IMVS_SetModuDisplayName
 *  @brief  设置模块显示名称
 *  @param  handle             [IN]       操作句柄
 *  @param  nModuleID          [IN]       模块ID
 *  @param  strDisplayName     [IN]       模块显示名称（不能含有问号与分号）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetModuDisplayName(
                      IN const void * const handle,
                      IN const unsigned int nModuleID,
                      IN const char * const strDisplayName);

/** @fn     IMVS_GetAllProcessList
 *  @brief  获取当前所有流程列表
 *  @param  handle             [IN]       操作句柄
 *  @param  pstProcessInfoList [OUT]      当前所有流程列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllProcessList(IN const void * const handle,
                                                              OUT IMVS_PROCESS_INFO_LIST * const pstProcessInfoList);

/** @fn     IMVS_GetTakeoverStatus
 *  @brief  获取接管状态
 *  @param  handle             [IN]       操作句柄
 *  @param  pstTakeoverInfo    [OUT]      接管状态
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetTakeoverStatus(IN const void * const handle,
                                                              OUT IMVS_STATUS_TAKEOVER_INFO * const pstTakeoverInfo);

/** @fn     IMVS_SetAutoLoadSolution
 *  @brief  设置自动加载方案信息（确定是否界面接管）
 *  @param  handle             [IN]       操作句柄
 *  @param  pstAutoLoadInfo    [IN]       自动加载方案信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetAutoLoadSolution(IN const void * const handle,
                                                                IN const IMVS_AUTO_LOAD_SOLUTION_INFO * const pstAutoLoadInfo);

/** @fn     IMVS_GetAutoLoadSolution
 *  @brief  获取自动加载方案信息
 *  @param  handle             [IN]       操作句柄
 *  @param  pstAutoLoadInfo    [OUT]      自动加载方案信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAutoLoadSolution(IN const void * const handle,
                                                                OUT IMVS_AUTO_LOAD_SOLUTION_INFO * const pstAutoLoadInfo);

/** @fn     IMVS_ShieldProcess
 *  @brief  屏蔽流程全局控制
 *  @param  handle             [IN]       操作句柄
 *  @param  nProcessID         [IN]       流程ID
 *  @param  nShieldFlag        [IN]       是否屏蔽标志
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ShieldProcess(IN const void * const handle,
                                                          IN const unsigned int nProcessID,
                                                          IN const unsigned int nShieldFlag);

/** @fn     IMVS_GetProcedureShieldGlobalCtrl
 *  @brief  获取流程全局控制屏蔽状态
 *  @param  handle             [IN]       操作句柄
 *  @param  nProcessID         [IN]       流程ID
 *  @param  pnShieldFlag       [IN]       流程全局控制屏蔽状态
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcedureShieldGlobalCtrl(IN const void * const handle,
                                                                         IN const unsigned int nProcessID,
                                                                         OUT unsigned int * const pnShieldFlag);

/** @fn     IMVS_GetModuleListByType
 *  @brief  根据模块类型获取模块列表
 *  @param  handle             [IN]       操作句柄
 *  @param  pstModuleInfoList  [OUT]      模块结果信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuleListByType(IN const void * const handle, IN const unsigned int nModuleType,
                                                                OUT IMVS_MODULE_BASIC_INFO_LIST * const pstModuleInfoList);


/** @fn     IMVS_GetProcContinousRunInterval
 *  @brief  获取某一流程的连续执行时间间隔
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  pnMilliSecond     [IN]       指定流程两次运行之间时间间隔
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcContinousRunInterval(IN const void * const handle, IN const unsigned int nProcessID,
                                                                        OUT unsigned int * const pnMilliSecond);


/** @fn     IMVS_ShieldModuleCbResult
 *  @brief  屏蔽模块结果回调
 *  @param  handle            [IN]       操作句柄
 *  @param  nShiledFlag       [IN]       屏蔽标志位（0：屏蔽，1：不屏蔽）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ShieldModuleCbResult(IN const void * const handle, IN const unsigned int nShiledFlag = 0);


/** @fn     IMVS_EnableModule
 *  @brief  模块禁用与启用功能
 *  @param  handle            [IN]       操作句柄
 *  @param  nModuleID         [IN]       模块ID
 *  @param  nEnableFlag       [IN]       模块功能禁用标志位（0：禁用，1：启用）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_EnableModule(IN const void * const handle, IN const unsigned int nModuleID, IN const unsigned int nEnableFlag);

/** @fn     IMVS_GetModuleState
 *  @brief  获取模块禁用状态
 *  @param  handle            [IN]       操作句柄
 *  @param  nModuleID         [IN]       模块ID
 *  @param  pnModuleState     [OUT]      模块禁用状态（0：禁用，1：启用）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuleState(IN const void * const handle, IN const unsigned int nModuleID, OUT unsigned int * const pnModuleState);

/** @fn     IMVS_CopyModuleParam
 *  @brief  复制模块参数
 *  @param  handle            [IN]       操作句柄
 *  @param  nSrcModuID        [IN]       源模块ID
 *  @param  nDstModuID        [IN]       目标模块ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CopyModuleParam(IN const void * const handle, IN const unsigned int nSrcModuID, IN const unsigned int nDstModuID);

/** @fn     IMVS_OpenGlobalScriptInteface
 *  @brief  打开全局脚本编辑界面
 *  @param  handle            [IN]       操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_OpenGlobalScriptInteface(IN const void * const handle);

/** @fn     IMVS_ExecuteOnce4GlobalScript
 *  @brief  全局脚本执行一次
 *  @param  handle            [IN]       操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExecuteOnce4GlobalScript(IN const void * const handle);

/** @fn     IMVS_ContinousRunStart4GlobalScript
 *  @brief  全局脚本连续执行开始
 *  @param  handle            [IN]       操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ContinousRunStart4GlobalScript(IN const void * const handle);

/** @fn     IMVS_StopExecute4GlobalScript
 *  @brief  全局脚本停止执行
 *  @param  handle            [IN]       操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_StopExecute4GlobalScript(IN const void * const handle);

/** @fn     IMVS_SetCustomOutputSubscribeInfo
 *  @brief  设置用户自定义输出订阅信息
 *  @param  handle            [IN]       操作句柄
 *  @param  pstCustomSubInfo  [IN]       用户自定义输出订阅信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetCustomOutputSubscribeInfo(IN const void * const handle, IN const IMVS_CUSTOM_SUBSCRIBE_INFO * const pstCustomSubInfo);

/** @fn     IMVS_GetCustomOutputSubscribeInfo
 *  @brief  获取用户自定义输出订阅信息
 *  @param  handle               [IN]       操作句柄
 *  @param  nProcessID           [IN]       流程ID
 *  @param  nIndexNum            [IN]       序号
 *  @param  pstCustomSubInfoList [IN]       用户自定义输出订阅信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetCustomOutputSubscribeInfo(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nIndexNum, OUT IMVS_GET_CUSTOM_SUBSCRIBE_INFO_LIST * const pstCustomSubInfoList);

/** @fn     IMVS_ClearCustomOutputInfo
 *  @brief  清空指定流程中所有用户自定义输出配置
 *  @param  handle               [IN]       操作句柄
 *  @param  nProcessID           [IN]       流程ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ClearCustomOutputInfo(IN const void * const handle, IN const unsigned int nProcessID);

/** @fn     IMVS_SetParamValue4GlobalScript
 *  @brief  设置全局脚本模块参数
 *  @param  handle                  [IN]       操作句柄
 *  @param  strTranseData           [IN]       设置数据
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetParamValue4GlobalScript(IN const void * const handle,
																	    IN const char * const strTransData);

/** @fn     IMVS_GetParamValue4GlobalScript
 *  @brief  获取全局脚本模块参数
 *  @param  handle                  [IN]       操作句柄
 *  @param  strReqData              [IN]       请求数据
 *  @param  nTransDataSize          [IN]       响应数据的分配大小
 *  @param  strValue                [OUT]      响应数据
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetParamValue4GlobalScript(IN const void * const handle,
																	    IN const char * const strReqData,
																		IN const unsigned int nTransDataSize,
																		OUT char * const strTransData);

/** @fn     IMVS_StartGlobalScript
 *  @brief  启动全局脚本模块参数
 *  @param  handle                  [IN]       操作句柄
 *  @param  nTransDataSize          [IN]       接收全局脚本数据的分配大小
 *  @param  strValue                [OUT]      接收全局脚本数据
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_StartGlobalScript(IN const void * const handle, IN const unsigned int nTransDataSize, OUT char * const strTransData);

/** @fn     IMVS_SetVmRepAddr4GlobalScript
 *  @brief  设置VM界面Rep地址
 *  @param  handle                  [IN]       操作句柄
 *  @param  strVMRepAddr            [IN]       VM界面Rep地址
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetVmRepAddr4GlobalScript(IN const void * const handle, IN const char * const strVMRepAddr);

/** @fn     IMVS_RegisterOutputPlatformInfoCallBack_V32
 *  @brief  注册回调函数(回调导出结果)
 *  @param  handle                  [IN]        句柄
 *  @param  cbOutputPlatformInfo    [IN]        回调函数
 *  @param  pUser                   [IN]        pUser
 *  @return 成功，返回CM_OK；失败，返回对应错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_RegisterOutputPlatformInfoCallBack_V32(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/** @fn     IMVS_CtrlCallBackModuResult
 *  @brief  【V3.2新增】模块开启/停止回调信息
 *  @param  handle                  [IN]       操作句柄
 *  @param  nModuleID               [IN]       模块ID
 *  @param  nCallbackStatus         [IN]       回调状态（0：停止回调；1：开启回调）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CtrlCallBackModuResult(IN const void * const handle, IN const unsigned int nModuleID, IN const unsigned int nCallbackStatus);

/** @fn     IMVS_SetServerReadyEvent
*  @brief  触发方案加载后就绪事件(加载完成和静默执行完成)
*  @param  handle            [IN]       操作句柄
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetServerReadyEvent(IN const void * const handle);

/** @fn     IMVS_MakeModulesPrepared
*  @brief  模块资源预分配接口
*  @param  handle            [IN]       操作句柄
*  @param  pstCamPicInfoList [IN]       相机图像模块信息
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_MakeModulesPrepared(IN const void * const handle, IN const IMVS_CAMERA_PIC_INFO_LIST * const pstCamPicInfoList);

/** @fn     IMVS_MakeModulesPreparedBySelfRun
*  @brief  模块资源预分配接口(模块自执行方式)
*  @param  handle            [IN]       操作句柄
*  @param  pstCamPicInfoList [IN]       相机图像模块信息
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_MakeModulesPreparedBySelfRun(IN const void * const handle, IN const IMVS_CAMERA_PIC_INFO_LIST * const pstCamPicInfoList);

/** @fn     IMVS_SetProcedureRunPolicy
 *  @brief  设置流程运行策略接口
 *  @param  handle               [IN]       操作句柄
 *  @param  pstProcRunPolicyInfo [IN]       流程运行策略信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcedureRunPolicy(IN const void * const handle, IN const IMVS_PROCEDURE_RUN_POLICY * const pstProcRunPolicyInfo);

/** @fn     IMVS_GetProcedureRunPolicy
 *  @brief  获取流程运行策略接口
 *  @param  handle               [IN]       操作句柄
 *  @param  pstProcRunPolicyInfo [IN]       流程运行策略信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcedureRunPolicy(IN const void * const handle, OUT IMVS_PROCEDURE_RUN_POLICY * const pstProcRunPolicyInfo);

/** @fn     IMVS_SetProcedureReentrant
*  @brief  设置流程可重入接口
*  @param  handle                  [IN]       操作句柄
*  @param  bReentrantEnable        [IN]       可重入使能
*  @param  nReentrantNum           [IN]       可重入数量
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcedureReentrant(IN const void * const handle, IN bool bReentrantEnable, IN unsigned int nReentrantNum);

/** @fn     IMVS_GetProcedureReentrant
*  @brief  获取流程可重入接口
*  @param  handle                     [IN]       操作句柄
*  @param  pbReentrantEnable          [IN]       可重入使能
*  @param  pnReentrantNum             [IN]       可重入数量
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcedureReentrant(IN const void * const handle, OUT bool * const pbReentrantEnable, OUT unsigned int * const pnReentrantNum);

/** @fn     IMVS_GetSolutionPath
 *  @brief  获取方案路径接口
 *  @param  handle            [IN]       操作句柄
 *  @param  nPathSize         [IN]       路径缓存区大小
 *  @param  strSolPath        [OUT]      方案路径
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetSolutionPath(IN const void * const handle, IN const unsigned int nPathSize, OUT char * const strSolPath, OUT unsigned int * nRealPathSize = NULL);

/** @fn     IMVS_GetProcessorInfo
 *  @brief  获取底层所在机器处理器信息接口
 *  @param  handle            [IN]       操作句柄
 *  @param  pstProcessorInfo  [OUT]      处理器信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcessorInfo(IN const void * const handle, OUT IMVS_PROCESSOR_INFO * const pstProcessorInfo);

/** @fn     IMVS_CopyModuleAlgParam
 *  @brief  复制模块算法参数
 *  @param  handle            [IN]       操作句柄
 *  @param  nSrcModuID        [IN]       源模块ID
 *  @param  nDstModuID        [IN]       目标模块ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CopyModuleAlgParam(IN const void * const handle, IN const unsigned int nSrcModuID, IN const unsigned int nDstModuID);

/** @fn     IMVS_SetDefaultParamList
 *  @brief  设置默认参数列表
 *  @param  handle            [IN]       操作句柄
 *  @param  nModuleID         [IN]       模块ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetDefaultParamList(IN const void * const handle, IN const unsigned int nModuleID);

/** @fn     IMVS_AddGroupSonModule
 *  @brief  添加Group子模块
 *  @param  handle            [IN]       操作句柄
 *  @param  pstGroupModuInfo  [IN]       Group模块信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddGroupSonModule(IN const void * const handle, IN const IMVS_GROUP_MODULE_INFO * const pstGroupModuInfo);

/** @fn     IMVS_RemoveGroupSonModule
 *  @brief  移除Group子模块
 *  @param  handle            [IN]       操作句柄
 *  @param  pstGroupModuInfo  [IN]       Group模块信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_RemoveGroupSonModule(IN const void * const handle, IN const IMVS_GROUP_MODULE_INFO * const pstGroupModuInfo);

/** @fn     IMVS_DeleteGroupModule
 *  @brief  删除Group及其子模块
 *  @param  handle            [IN]       操作句柄
 *  @param  nGroupModuleID    [IN]       Group模块ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteGroupModule(IN const void * const handle, IN const unsigned int nGroupModuleID);

/** @fn     IMVS_ExportGroupModule
 *  @brief  导出Group
 *  @param  handle            [IN]       操作句柄
 *  @param  nGroupId          [IN]       Group模块ID
 *  @param  nGroupLevel       [IN]       导出Group层级
 *  @param  strPath           [IN]       Group文件保存路径
 *  @param  strPassword       [IN]       Group文件密码（预留）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExportGroupModule(IN const void * const handle,
	                                                           IN unsigned int nGroupId,
															   IN unsigned int nGroupLevel,
															   IN const char * const strPath, 
															   IN const char * const strPassword);

/** @fn     IMVS_ExportGroupModule
 *  @brief  导出Group
 *  @param  handle            [IN]       操作句柄
 *  @param  nGroupId          [IN]       Group模块ID
 *  @param  nGroupLevel       [IN]       导出Group层级
 *  @param  strPath           [IN]       Group文件保存路径
 *  @param  strPassword       [IN]       Group文件密码（预留）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncExportGroupModule(IN const void * const handle,
	                                                               IN unsigned int nGroupId,
															       IN unsigned int nGroupLevel,
															       IN const char * const strPath, 
															       IN const char * const strPassword);

/** @fn     IMVS_ImportGroupModule
 *  @brief  导入Group
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  nGroupID          [IN]       Group 模块ID
 *  @param  strPath           [IN]       Group文件保存路径
 *  @param  strPassword       [IN]       Group文件密码（预留）
 *  @param  nIdAllocateWay    [IN]       ID分配方式 (0：自动分配ID，1：按文件中的ID分配)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportGroupModule(IN const void * const handle, IN unsigned int nProcessID, IN unsigned int nGroupID, IN const char * const strPath, IN const char * const strPassword, IN const unsigned int nIdAllocateWay);

/** @fn     IMVS_SyncImportGroupModule
 *  @brief  同步导入Group
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  nGroupID          [IN]       Group 模块ID
 *  @param  strPath           [IN]       Group文件保存路径
 *  @param  strPassword       [IN]       Group文件密码（预留）
 *  @param  nIdAllocateWay    [IN]       ID分配方式 (0：自动分配ID，1：按文件中的ID分配)
 *  @param  pstModuleInfo     [OUT]      返回模块信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncImportGroupModule(IN const void * const handle, IN unsigned int nProcessID, IN unsigned int nGroupID, IN const char * const strPath, IN const char * const strPassword, IN const unsigned int nIdAllocateWay, OUT IMVS_MODULE_INFO * const pstModuleInfo);

/** @fn     IMVS_SetGroupIO
 *  @brief  设置Group输入输出信息
 *  @param  handle            [IN]       操作句柄
 *  @param  pstGroupIOInfoList[IN]       Group输入输出信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetGroupIO(IN const void * const handle, IN const IMVS_GROUP_IO_INFO_LIST * const pstGroupIOInfoList);

/** @fn     IMVS_BindGlobalVarParam
 *  @brief  绑定全局变量参数
 *  @param  handle            [IN]       操作句柄
 *  @param  pstGlobalVarInfo  [IN]       绑定全局变量信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_BindGlobalVarParam(IN const void * const handle, IN const IMVS_BIND_GLOBALVAR_PARAM_INFO_LIST * const pstGlobalVarInfo);

/** @fn     IMVS_UnBindGlobalVarParam
 *  @brief  取消绑定全局变量参数
 *  @param  handle            [IN]       操作句柄
 *  @param  pstGlobalVarInfo  [IN]       取消绑定全局变量信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_UnBindGlobalVarParam(IN const void * const handle, IN const IMVS_UNBIND_GLOBALVAR_PARAM_INFO_LIST * const pstGlobalVarInfo);

/** @fn     IMVS_GetBindGlobalVarParam
 *  @brief  获取绑定全局变量参数
 *  @param  handle            [IN]       操作句柄
 *  @param  nModuleId         [IN]       全局变量模块ID
 *  @param  nIndex            [IN]       起始索引
 *  @param  nQueNum           [IN]       查询个数
 *  @param  pstGlobalVarInfo  [OUT]      绑定全局变量信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetBindGlobalVarParam(IN const void * const handle, IN unsigned int nModuleId, IN int nIndex, IN int nQueNum, OUT IMVS_GET_BIND_GLOBALVAR_PARAM_INFO_LIST * const pstGlobalVarInfo);

/** @fn     IMVS_LightSaveSolution
 *  @brief  轻量级保存方案
 *  @param  handle            [IN]       操作句柄
 *  @param  nRecvWaitTime     [IN]       接收超时（单位：ms）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_LightSaveSolution(IN const void * const handle, IN const unsigned int nRecvWaitTime);

/** @fn     IMVS_NotifyLoadSolutionEnd
 *  @brief  主界面通知加载方案结束
 *  @param  handle            [IN]       操作句柄
 *  @param  nClientType       [IN]       客户端
 *  @param  nErrorCode        [IN]       错误码
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_NotifyLoadSolutionEnd(IN const void * const handle, IN unsigned int nClientType, IN int nErrorCode);

/** @fn     IMVS_ExportProcess
 *  @brief  导出流程
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  strExportPath     [IN]       导出路径
 *  @param  strPassword       [IN]       文件密码(预留)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExportProcess(IN const void * const handle, 
														   IN const unsigned int nProcessID,
														   IN const char * const strExportPath,
														   IN const char * const strPassword);

/** @fn     IMVS_SyncExportProcess
 *  @brief  导出流程
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  strExportPath     [IN]       导出路径
 *  @param  strPassword       [IN]       文件密码(预留)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncExportProcess(IN const void * const handle, 
															IN const unsigned int nProcessID,
															IN const char * const strExportPath,
															IN const char * const strPassword);

/** @fn     IMVS_ImportProcess
 *  @brief  导入流程
 *  @param  handle            [IN]       操作句柄
 *  @param  strProcessPath    [IN]       导入流程文件路径
 *  @param  strPassword       [IN]       文件密码
 *  @param  nIsIgnoreGlobal   [IN]       是否忽视全局模块 (1：忽略流程文件中的全局模块，0：覆盖相同全局模块数据)
 *  @param  nIdAllocateWay    [IN]       ID分配方式 (0：自动分配ID，1：按文件中的ID分配)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportProcess(IN const void * const handle, 
														   IN const char * const strProcessPath,
														   IN const char * const strPassword,
														   IN const unsigned int nIsIgnoreGlobal,
														   IN const unsigned int nIdAllocateWay
														   );

/** @fn     IMVS_SyncImportProcess
 *  @brief  导入流程
 *  @param  handle            [IN]       操作句柄
 *  @param  strProcessPath    [IN]       导入流程文件路径
 *  @param  strPassword       [IN]       文件密码
 *  @param  nIsIgnoreGlobal   [IN]       是否忽视全局模块 (1：忽略流程文件中的全局模块，0：覆盖相同全局模块数据)
 *  @param  nIdAllocateWay    [IN]       ID分配方式 (0：自动分配ID，1：按文件中的ID分配)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncImportProcess(IN const void * const handle,
															   IN const char * const strProcessPath,
															   IN const char * const strPassword,
															   IN const unsigned int nIsIgnoreGlobal,
															   IN const unsigned int nIdAllocateWay,
															   OUT IMVS_PROCESS_INFO * const pstProcessInfo);

/** @fn     IMVS_SendProcRunParam
 *  @brief  设置流程运行参数
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  nStopNGAction     [IN]       流程NG时停止运行, (1: 是; 0: 否)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcRunParam(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nStopNGAction);

/** @fn     IMVS_GetProcRunParam
 *  @brief  获取流程运行参数
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  pnStopNGAction    [OUT]      流程NG时停止运行, (1: 是; 0: 否)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcRunParam(IN const void * const handle, IN const unsigned int nProcessID, OUT unsigned int * const pnStopNGAction);


/** @fn     IMVS_SetMaxModuleNum
*  @brief  设置模块上限数量
*  @param  handle            [IN]       操作句柄
*  @param  nMaxModuleNum    [IN]      最大模块数量
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetMaxModuleNum(IN const void * const handle, IN const unsigned int nMaxModuleNum);


/** @fn     IMVS_GetObjectLimits
 *  @brief  获取流程与模块上限数量
 *  @param  handle            [IN]       操作句柄
 *  @param  pnMaxProcessNum   [OUT]      最大流程数量
 *  @param  pnMaxModuleNum    [OUT]      最大模块数量
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetObjectLimits(IN const void * const handle, OUT unsigned int * const pnMaxProcessNum, OUT unsigned int * const pnMaxModuleNum);

/** @fn     IMVS_SetUIParamValue
 *  @brief  设置对象界面参数
 *  @param  handle            [IN]       操作句柄
 *  @param  nObjectID         [IN]       对象ID
 *  @param  strParamName      [IN]       界面参数名称
 *  @param  pData             [IN]       界面参数数据
 *  @param  nDataLen          [IN]       界面参数数据长度
 *  @param  nRecvWaitTime     [IN]       接收超时
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetUIParamValue(IN const void * const handle, IN const unsigned int nObjectID, IN const char * const strParamName, IN const char * const pData, IN const unsigned int nDataLen, IN const unsigned int nRecvWaitTime);

/** @fn     IMVS_GetUIParamValueByKey
 *  @brief  根据对象Key获取对象界面参数值，数据拷贝后使用接口释放指针-IMVS_ReleaseDynamicMemory
 *  @param  handle            [IN]       操作句柄
 *  @param  nObjectID         [IN]       对象ID
 *  @param  strParamName      [IN]       界面参数名称
 *  @param  pData             [OUT]      界面参数数据
 *  @param  pnDataLen         [OUT]      界面参数数据长度
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetUIParamValueByKey(IN const void * const handle, IN const unsigned int nObjectID, IN const char * const strParamName, OUT char *& pData, OUT unsigned int * const pnDataLen, IN const unsigned int nRecvWaitTime);

/** @fn     IMVS_GetUIParamValueByObject
 *  @brief  按对象获取对象界面参数值，数据拷贝后使用接口释放指针-IMVS_ReleaseDynamicMemory
 *  @param  handle            [IN]       操作句柄
 *  @param  nObjectID         [IN]       对象ID
 *  @param  pstUIObjParamInfoList [OUT]  界面参数数据列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetUIParamValueByObject(IN const void * const handle, IN const unsigned int nObjectID, OUT IMVS_UI_OBJECT_PARAM_INFO_LIST *& pstUIObjParamInfoList);

/** @fn     IMVS_GetFirstLayerModuleTree
 *  @brief  获取第一层级对象内部的模块树
 *  @param  handle              [IN]     操作句柄
 *  @param  nObjectID           [IN]     父对象ID
 *  @param  pstNodeTreeInfoList [OUT]    模块树信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetFirstLayerModuleTree(IN const void * const handle, IN const unsigned int nObjectID, IN const unsigned int nObjectType, OUT IMVS_NODE_TREE_INFO * const pstNodeTreeInfoList);

/** @fn     IMVS_GetModuleConnectInProc
 *  @brief  获取第一层级对象内模块连接关系
 *  @param  handle                 [IN]     操作句柄
 *  @param  nObjectID              [IN]     父对象ID
 *  @param  pstModuConnectInfoList [OUT] 模块连接信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetFirstLayerModuleConnect(IN const void * const handle, IN const unsigned int nObjectID, IN const unsigned int nObjectType, OUT IMVS_MODULE_CONNECT_INFO_LIST *& pstModuConnectInfoList);

/** @fn     IMVS_GetFirstLayerModuleSubscribe
 *  @brief  获取第一层级对象内模块订阅关系
 *  @param  handle              [IN]     操作句柄
 *  @param  nObjectID           [IN]     父对象ID
 *  @param  pstModuSubInfoList  [OUT]    模块订阅信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetFirstLayerModuleSubscribe(IN const void * const handle, IN const unsigned int nObjectID, IN const unsigned int nObjectType, OUT IMVS_MODULE_SUBSCRIBE_INFO_LIST *& pstModuSubInfoList);

/** @fn     IMVS_ReleaseUIParamData
 *  @brief  释放获取数据内存
 *  @param  handle              [IN]     操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ReleaseUIParamData(IN const void * const handle);

/** @fn     IMVS_SetReportModuleResult
 *  @brief  上传指定模块结果
 *  @param  handle                [IN]     操作句柄
 *  @param  pstReportModuInfoList [IN]    指定模块结果列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetReportModuleResult(IN const void * const handle, IN const IMVS_REPORT_MODULE_RES_INFO_LIST * const pstReportModuInfoList);
/** @fn     IMVS_SetReportModuleResult_V2
*  @brief  二次开发按需回调（优先级高于IMVS_SetReportModuleResult）
*  @param  handle                [IN]     操作句柄
*  @param  nMode                 [IN]     设置模式
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetReportModuleResult_V2(IN const void * const handle, IN const E_REPORT_RESULT_TYPE nMode, IN const unsigned int nModuId = 0, IN const bool bIsEnable = false);

/** @fn     IMVS_SetAllReportModuleResult
 *  @brief  上传所有模块结果
 *  @param  handle                [IN]     操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetAllReportModuleResult(IN const void * const handle);

/** @fn     IMVS_SetNoneReportModuleResult
 *  @brief  不上传模块结果
 *  @param  handle                [IN]     操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetNoneReportModuleResult(IN const void * const handle);

/** @fn    IMVS_KeepModuleLastResult
*  @brief  保持模块上次结果
*  @param  handle                [IN]     操作句柄
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_KeepModuleLastResult(IN const void * const handle, IN const unsigned int nModuleID, IN bool bIsUnchanged);

/** @fn     IMVS_QueryModuleRunningState
*  @brief  查询模块历史状态，数据拷贝后使用接口释放指针-IMVS_ReleaseDynamicMemory
*  @param  handle                  [IN]     操作句柄
*  @param  pastModuleId            [IN]     模块ID列表
*  @param  pstQueryModuStaInfoList [OUT]    查询模块历史状态信息列表
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_QueryModuleRunningState(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pastModuleId, OUT IMVS_REPORT_MODULE_STATUS_INFO_LIST *& pstQueryModuStaInfoList);

/** @fn     IMVS_QueryModuleHistoryResult
 *  @brief  查询模块历史结果
 *  @param  handle                  [IN]     操作句柄
 *  @param  nModuleID               [IN]     模块ID
 *  @param  nIndex                  [IN]     索引
 *  @param  nResultNum              [IN]     结果数量（最大40条）
 *  @param  pstQueryModuResInfoList [OUT]    查询模块历史结果信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_QueryModuleHistoryResult(
    IN const void * const handle,
    IN const unsigned int nModuleID,
    IN const int nIndex,
    IN const unsigned int nRequestNum,
    OUT IMVS_QUERY_MODULE_RES_INFO_LIST *& pstQueryModuResInfoList,
    IN const bool bResBuffFirst = true,
    IN const bool bNeedImage = true,
    IN const bool bUseResStructMap = true);

/** @fn     IMVS_GetModuleExportData
 *  @brief  获取模块导出数据，数据拷贝后使用接口释放指针-IMVS_ReleaseDynamicMemory
 *  @param  handle                  [IN]     操作句柄
 *  @param  nModuleID               [IN]     模块ID
 *  @param  strModuDisplayName      [IN]     模块显示名称
 *  @param  nWaitTime               [IN]     超时时间
 *  @param  pstModuExportData       [OUT]    模块导出数据
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuleExportData(IN const void * const handle,
																 IN const unsigned int nModuleID,
																 IN const char * const strModuDisplayName,
																 IN const unsigned int nWaitTime,
																 OUT IMVS_EXPORT_MODULE_DATA_INFO *& pstModuExportData);

/** @fn     IMVS_ImportModuleDataEx
 *  @brief  导入模块数据
 *  @param  handle                  [IN]     操作句柄
 *  @param  pstModuImportData       [IN]     模块导入数据信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportModuleDataEx(IN const void * const handle, IN const IMVS_IMPORT_MODULE_DATA_INFO * const pstModuImportData, OUT IMVS_MODULE_INFO * const pstModuleInfo);

/** @fn     IMVS_DeleteUIParamValue
 *  @brief  删除对象界面参数
 *  @param  handle            [IN]       操作句柄
 *  @param  nObjectID         [IN]       对象ID
 *  @param  strParamName      [IN]       界面参数名称
 *  @param  nBlurDelete       [IN]       是否模糊删除（0：否，1：是）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteUIParamValue(IN const void * const handle, IN const unsigned int nObjectID, IN const char * const strParamName, IN const unsigned int nBlurDelete);

/** @fn     IMVS_ExportMultiModuleData
 *  @brief  导出多个模块数据，数据拷贝后使用接口释放指针-IMVS_ReleaseDynamicMemory
 *  @param  handle            [IN]       操作句柄
 *  @param  pastModuleId      [IN]       导出模块ID列表
 *  @param  nWaitTime         [IN]       等待超时
 *  @param  pData             [OUT]      导出数据
 *  @param  pnDataLen         [OUT]      导出数据长度
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExportMultiModuleData(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pastModuleId, IN const unsigned int nWaitTime, OUT IMVS_EXPORT_MODULE_DATA_INFO *& pstModuExportData);

/** @fn     IMVS_ImportMultiModuleData
 *  @brief  导入多个模块数据
 *  @param  handle               [IN]       操作句柄
 *  @param  pastModuleImportData [IN]       导入模块数据信息
 *  @param  pstModuleInfoList    [OUT]      模块注册信息列表
 *  @param  pstImportNodeList    [OUT]      模块父子信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportMultiModuleData(IN const void * const handle, IN const IMVS_IMPORT_MODULE_LIST_DATA_INFO * const pastModuleImportData, OUT IMVS_MODULE_INFO_LIST * const pstModuleInfoList, OUT IMVS_IMPORT_NODE_LIST * const pstImportNodeList);

/** @fn     IMVS_GetMultiModuleConnect
 *  @brief  获取多个模块连接关系，数据拷贝后使用接口释放指针-IMVS_ReleaseDynamicMemory
 *  @param  handle                 [IN]       操作句柄
 *  @param  pastModuleId           [IN]       模块ID列表
 *  @param  pstModuConnectInfoList [OUT]      模块连接关系列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetMultiModuleConnect(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pastModuleId, OUT IMVS_MODULE_CONNECT_INFO_LIST *& pstModuConnectInfoList);

/** @fn     IMVS_GetMultiModuleSubscribe
 *  @brief  获取多个模块订阅关系，数据拷贝后使用接口释放指针-IMVS_ReleaseDynamicMemory
 *  @param  handle                 [IN]       操作句柄
 *  @param  pastModuleId           [IN]       模块ID列表
 *  @param  pstModuSubInfoList     [OUT]      模块连接关系列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetMultiModuleSubscribe(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pastModuleId, OUT IMVS_MODULE_SUBSCRIBE_INFO_LIST *& pstModuSubInfoList);

/** @fn     IMVS_GetAllGlobalModule
 *  @brief  获取所有全局模块
 *  @param  handle                [IN]       操作句柄
 *  @param  pstModuleInfoList     [OUT]      全局模块列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllGlobalModule(IN const void * const handle, OUT IMVS_MODULE_INFO_LIST * const pstModuleInfoList);

/** @fn     IMVS_GetSolModifyInfo
 *  @brief  获取方案修改信息
 *  @param  handle            [IN]       操作句柄
 *  @param  pnSolModify       [OUT]      方案是否修改 (1：有修改，0：无修改)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetSolModifyInfo(IN const void * const handle, OUT unsigned int * const pnSolModify);

/** @fn     IMVS_FuzzyQueryUIParamValue
 *  @brief  模糊查询对象界面参数，数据拷贝后使用接口释放指针-IMVS_ReleaseDynamicMemory
 *  @param  handle            [IN]       操作句柄
 *  @param  pstModuList       [IN]       对象ID列表
 *  @param  strParamName      [IN]       界面参数名称
 *  @param  bIsFuzzyQuery     [IN]       是否模糊查询
 *  @param  pUiParamInfoList  [OUT]      界面参数数据列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_FuzzyQueryUIParamValue(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pstModuList, IN const char * const strParamName, IN const bool bIsFuzzyQuery, OUT IMVS_UIPARAM_INFO_LIST *& pUiParamInfoList);

/** @fn     IMVS_DeleteAllUIParamValue
 *  @brief  删除对象所有界面参数
 *  @param  handle            [IN]       操作句柄
 *  @param  nObjectID         [IN]       对象ID
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteAllUIParamValue(IN const void * const handle, IN const unsigned int nObjectID);

/** @fn    IMVS_SetSolModifyFlag
*  @brief  设置当前方案是否修改标记
*  @param  handle            [IN]       操作句柄
*  @param  nModifyFlag       [IN]       修改标记
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetSolModifyFlag(IN const void * const handle, IN const unsigned int nModifyFlag);

/** @fn    IMVS_QueryIOBeSubscribed
*  @brief  查询IO被订阅信息，数据拷贝后使用接口释放指针-IMVS_ReleaseDynamicMemory
*  @param  handle            [IN]       操作句柄
*  @param  nModuleId         [IN]       模块ID
*  @param  strIOName         [IN]       IO名称
*  @param  pstIOSubInfoList  [OUT]      IO订阅信息
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_QueryIOBeSubscribed(IN const void * const handle, 
    IN const unsigned int nModuleId, IN const char * const strIOName, 
    IN IMVS_IO_BE_SUBSCRIBED_TYPE eIoBeSubscribedType, 
    OUT IMVS_MODULE_SUBSCRIBE_INFO_LIST *& pstIOSubInfoList);

/** @fn    IMVS_DeleteIOBeSubscribedByPrams
*  @brief  删除IO被参数订阅信息
*  @param  handle            [IN]       操作句柄
*  @param  nModuleId         [IN]       模块ID
*  @param  strIOName         [IN]       IO名称
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteIOBeSubscribedByParams(IN const void * const handle, IN const unsigned int nModuleId, IN const char * const strIOName);


/** @fn    IMVS_ClearModuleHistoryResult
*  @brief  清空模块历史结果信息
*  @param  handle            [IN]       操作句柄
*  @param  nModuleId         [IN]       模块ID
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ClearModuleHistoryResult(IN const void * const handle, IN const unsigned int nModuleId);

/** @fn    IMVS_GetAllProcedureShieldState
*  @brief  获取所有流程屏蔽状态
*  @param  handle            [IN]       操作句柄
*  @param  pnShieldFlag      [OUT]      屏蔽状态
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllProcedureShieldState(IN const void * const handle, OUT unsigned int * const pnShieldFlag);

/** @fn    IMVS_GetMultiModuEnableState
 *  @brief  获取多个模块禁用状态
 *  @param  handle            [IN]       操作句柄
 *  @param  pstModuList       [IN]       模块ID列表
 *  @param  pstModuStateInfo  [OUT]      模块状态列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetMultiModuEnableState(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pstModuList, OUT IMVS_MODULE_STATE_LIST * const pstModuStateInfo);

/** @fn    IMVS_GetMultiObjectLoadState
*  @brief  获取多个目标加载状态，可以是流程、Group、模块，0:未加载，1：已加载，2：内部包含未加载
*  @param  handle            [IN]       操作句柄
*  @param  pstModuList       [IN]       模块ID列表
*  @param  pstModuStateInfo  [OUT]      模块状态列表
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetMultiObjectLoadState(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pstModuList, OUT IMVS_MODULE_STATE_LIST * const pstModuStateInfo);

/** @fn    IMVS_GetAutoSaveSolState
 *  @brief  获取自动保存方案状态信息
 *  @param  handle            [IN]       操作句柄
 *  @param  pnStatus          [OUT]      自动保存方案状态（1：开启，0：关闭）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAutoSaveSolState(IN const void * const handle, OUT unsigned int * const pnStatus);

/** @fn    IMVS_SetAutoSaveSolState
 *  @brief  设置自动保存方案状态信息
 *  @param  handle            [IN]       操作句柄
 *  @param  nStatus           [IN]      自动保存方案状态（1：开启，0：关闭）
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetAutoSaveSolState(IN const void * const handle, IN const unsigned int nStatus);

/** @fn    IMVS_LightSaveSolutionEx
 *  @brief  客户端轻量保存方案接口
 *  @param  handle            [IN]       操作句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_LightSaveSolutionEx(IN const void * const handle);

/** @fn    IMVS_GetThirdSoftwareInfo
 *  @brief  获取第三方软件信息接口
 *  @param  handle               [IN]       操作句柄
 *  @param  pstThirdSoftwareInfo [OUT]      第三方软件信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetThirdSoftwareInfo(IN const void * const handle, OUT IMVS_THIRD_SOFTWARE_INFO_LIST * const pstThirdSoftwareInfo);

/** @fn     IMVS_SetProcedureIO
 *  @brief  设置Procedure输入输出信息
 *  @param  handle            [IN]       操作句柄
 *  @param  pstPrcIOInfoList  [IN]       Procedure输入输出信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcedureIO(IN const void * const handle, IN const IMVS_PROCEDURE_IO_INFO_LIST * const pstPrcIOInfoList);

/** @fn    IMVS_SetModuInputIOInfo
 *  @brief  设置模块输入IO信息
 *  @param  handle            [IN]       操作句柄
 *  @param  nModuId           [IN]       模块ID
 *  @param  pstModuIOInfo     [IN]      模块IO信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetModuInputIOInfo(IN const void * const handle, IN const unsigned int nObjectId, IN const IMVS_MODULE_IO_INFO_LIST * const pstModuInfoList);

/** @fn    IMVS_SetModuOutputIOInfo
 *  @brief  设置模块输出IO信息
 *  @param  handle            [IN]       操作句柄
 *  @param  nModuId           [IN]       模块ID
 *  @param  pstModuIOInfo     [IN]       模块IO信息列表
 *  @param  pstDisplayModuInfo[IN]       模块IO展示信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetModuOutputIOInfo(IN const void * const handle, IN const unsigned int nObjectId, IN const IMVS_MODULE_IO_INFO_LIST * const pstModuInfoList);

/** @fn    IMVS_GetModuInputIOInfo
 *  @brief  获取模块输入IO信息
 *  @param  handle            [IN]       操作句柄
 *  @param  nModuId           [IN]       模块ID
 *  @param  pstModuIOInfo     [OUT]      模块IO信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuInputIOInfo(IN const void * const handle, IN const unsigned int nModuId, OUT IMVS_MODULE_IO_INFO_LIST *& pstModuIOInfo);

/** @fn    IMVS_GetModuOutputIOInfo
 *  @brief  获取模块输出IO信息
 *  @param  handle            [IN]       操作句柄
 *  @param  nModuId           [IN]       模块ID
 *  @param  nDataType         [IN]       数据类型（2: 输出, 3: 显示）
 *  @param  pstModuIOInfo     [OUT]      模块IO信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuOutputIOInfo(IN const void * const handle, IN const unsigned int nModuId, IN const unsigned int nDataType, OUT IMVS_MODULE_IO_INFO_LIST *& pstModuIOInfo);

/** @fn    IMVS_SetProcRelatedWithGlobal
 *  @brief  设置与流程关联的全局模块
 *  @param  handle               [IN]       操作句柄
 *  @param  nProcID              [IN]       流程ID
 *  @param  pstRelateGlobalIDList[IN]       关联全局模块列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcRelatedWithGlobal(IN const void * const handle, IN const unsigned int nProcID, IN const IMVS_RELATED_GLOBAL_MODU_ID_LIST * const pstRelateGlobalIDList);

/** @fn    IMVS_DeleteProcRelated
 *  @brief  按类型清除与流程关联的全局模块
 *  @param  handle               [IN]       操作句柄
 *  @param  nProcID              [IN]       流程ID
 *  @param  eRelatedType         [IN]       关联全局模块类型
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteProcRelated(IN const void * const handle, IN const unsigned int nProcID, IN const IMVS_RELATED_TYPE eRelatedType);

/** @fn    IMVS_GetProcRelatedInfo
 *  @brief  获取全局模块信息接口
 *  @param  handle               [IN]       操作句柄
 *  @param  pstThirdSoftwareInfo [OUT]      第三方软件信息
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcRelatedInfo(IN const void * const handle, IN const unsigned int nProcID, OUT IMVS_RELATED_GLOBAL_MODU_INFO_LIST * const pstRelateGlobalIDList);

/** @fn     IMVS_ExportMultiProcess
 *  @brief  导出多个流程
 *  @param  handle            [IN]       操作句柄
 *  @param  pstProcIdList     [IN]       流程ID列表
 *  @param  strExportPath     [IN]       导出路径
 *  @param  strPassword       [IN]       文件密码(预留)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExportMultiProcess(IN const void * const handle,
																IN const IMVS_PROCESS_ID_LIST * const pstProcIdList,
															    IN const char * const strExportPath,
															    IN const char * const strPassword);

/** @fn     IMVS_ImportMultiProcess
 *  @brief  导入多个流程
 *  @param  handle            [IN]       操作句柄
 *  @param  strProcessPath    [IN]       导入流程文件路径
 *  @param  strPassword       [IN]       文件密码
 *  @param  nIsIgnoreGlobal   [IN]       是否忽视全局模块 (1：忽略流程文件中的全局模块，0：覆盖相同全局模块数据)
 *  @param  nIdAllocateWay    [IN]       ID分配方式 (0：自动分配ID，1：按文件中的ID分配)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportMultiProcess(IN const void * const handle,
															    IN const char * const strProcessPath,
															    IN const char * const strPassword,
															    IN const unsigned int nIsIgnoreGlobal,
															    IN const unsigned int nIdAllocateWay);
/** @fn     IMVS_GetPrcVersion
 *  @brief  获取流程文件版本
*  @param  handle                 [IN]     操作句柄
*  @param  strPath                [IN]     方案路径
*  @param  strPassWord            [IN]     方案密码
*  @param  pstFileVersionInfo     [OUT]    版本信息
*  @return 成功,返回IMVS_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetPrcVersion(IN const void * const handle,
														   IN const char * const strPath,
														   IN const char * const strPassWord,
														   OUT IMVS_FILE_VERSION_INFO * pstFileVersionInfo);

/** @fn     IMVS_GetGroVersion
*  @brief  获取Group文件版本
*  @param  handle                 [IN]     操作句柄
*  @param  strPath                [IN]     方案路径
*  @param  strPassWord            [IN]     方案密码
*  @param  pstFileVersionInfo     [OUT]    版本信息
*  @return 成功,返回IMVS_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetGroVersion(IN const void * const handle,
														   IN const char * const strPath,
														   IN const char * const strPassWord,
														   OUT IMVS_FILE_VERSION_INFO * pstFileVersionInfo);

/** @fn     IMVS_SetModuleParamBinding
 *  @brief  将模块输出与关键字参数相绑定
 *  @param  handle                 [IN]     操作句柄
 *  @param  pstModuParamInfo       [IN]     绑定参数列表
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetModuleParamBinding(IN const void * const handle, IN const IMVS_BIND_MODULE_PARAM_INFO_LIST * const pstModuParamInfo);

/** @fn     IMVS_DelModuleParamBinding
 *  @brief  删除模块关键字参数与模块输出的绑定关系
 *  @param  handle                 [IN]     操作句柄
 *  @param  pstModuParamInfo       [IN]     绑定参数列表
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DelModuleParamBinding(IN const void * const handle, IN const IMVS_UNBIND_MODULE_PARAM_INFO_LIST * const pstModuParamInfo);

/** @fn     IMVS_GetModuleParamBindingList
 *  @brief  查询模块关键字参数与模块输出的绑定关系
 *  @param  handle           [IN]     操作句柄
 *  @param  nModuleId        [IN]     模块ID
 *  @param  nIndex           [IN]     查询索引
 *  @param  nQueNum          [IN]     查询数量
 *  @param  pstModuParamInfo [OUT]    绑定参数列表
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuleParamBindingList(IN const void * const handle, 
																	   IN unsigned int nModuleId, 
																	   IN int nIndex, 
																	   IN int nQueNum, 
																	   OUT IMVS_GET_BIND_MODULE_PARAM_INFO_LIST * const pstModuParamInfo);

/** @fn     IMVS_SetProcedureWaitTime
 *  @brief  设置特定流程超时时间
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  nWaitTime         [IN]       流程超时时间
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcedureWaitTime(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nWaitTime);

/** @fn     IMVS_GetProcedureWaitTime
 *  @brief  获取特定流程超时时间
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  pnWaitTime        [OUT]      流程超时时间
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcedureWaitTime(IN const void * const handle, IN const unsigned int nProcessID, OUT unsigned int * const pnWaitTime);

#pragma region FTP操作相关接口
/****************************************************************************
*  @fn     IMVS_FtpInit
*  @brief  连接并登录远程FTPServer
*  @param  strHost                 [IN]       远程IP
*  @param  uPort                   [IN]       远程端口
*  @param  strLogin                [IN]       登录名称
*  @param  strPassword             [IN]       密码
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpInit(IN const void * const handle, IN const char* const strHost, IN const unsigned int uPort, IN const char* const strLogin, IN const char* const strPassword);

/****************************************************************************
*  @fn     IMVS_FtpDownloadFile
*  @brief  从远程下载单个文件到本地
*  @param  strOutputfile           [IN]       本地保存路径
*  @param  strPath                 [IN]       远程文件路径
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpDownloadFile(IN const void * const handle, IN const char * const strOutputfile, IN const char * const strPath, IN bool bCover = false);

/****************************************************************************
*  @fn     IMVS_FtpDownloadDir
*  @brief  从远程下载整个文件夹到本地
*  @param  strLocalDir           [IN]       本地保存路径
*  @param  strRemoteDir          [IN]       远程文件夹路径
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpDownloadDir(IN const void * const handle, IN const char * const strLocalDir, IN const char * const strRemoteDir, IN bool bCover = false);

/****************************************************************************
*  @fn     IMVS_FtpUploadFile
*  @brief  从本地上传单个文件到远程指定目录
*  @param  strInputfile            [IN]       本地文件路径
*  @param  strPath                 [IN]       远程路径
*  @param  isCreatDir              [IN]       创建文件夹
*  @param  isCover                 [IN]       覆盖同名文件
*  @return 不存在,返回true;存在,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpUploadFile(IN const void * const handle, IN const char * const strInputfile, IN const char * const strPath, IN bool isCreatDir = true, IN bool bCover = false);

/****************************************************************************
*  @fn     IMVS_FtpUploadDir
*  @brief  从本地上传整个文件夹到远程目录
*  @param  strLocalDir           [IN]       本地文件夹路径
*  @param  strRemoteDir          [IN]       远程目录
*  @param  isCover               [IN]       覆盖同名文件
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpUploadDir(IN const void * const handle, IN const char * const strLocalDir, IN const char * const strRemoteDir, IN bool bCover = false);

/****************************************************************************
*  @fn     IMVS_FtpCheckFileName
*  @brief  检查远程指定目录下是否存在重名文件
*  @param  strPath                 [IN]       远程文件路径
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpCheckFileName(IN const void * const handle, IN const char * const strPath);

/****************************************************************************
*  @fn     IMVS_FtpCreateDir
*  @brief  在远程上创建目录，允许创建多级目录
*  @param  strNewDir            [IN]       要创建的目录路径
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpCreateDir(IN const void * const handle, IN const char * const strNewDir);

/****************************************************************************
*  @fn     FM_RemoveDir
*  @brief  移除远程上的文件
*  @param  strRemoteFile            [IN]       要移除的文件
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpRemoveFile(IN const void * const handle, IN const char * const strRemoteFile);

/****************************************************************************
*  @fn     FM_RemoveDir
*  @brief  移除远程上的文件夹，不允许删除多级目录
*  @param  strRemoteDir            [IN]       要移除的文件夹
*  @param  bOnlyEmptyDir           [IN]       true:只允许删除空目录，false:允许删除非空目录
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpRemoveDir(IN const void * const handle, IN const char * const strRemoteDir, IN bool bOnlyEmptyDir = true);

/****************************************************************************
*  @fn     IMVS_FtpRename
*  @brief  重命名远程文件/文件夹
*  @param  strOldName            [IN]       原名称
*  @param  strNewName            [IN]       新名称
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpRename(IN const void * const handle, IN const char * const strOldName, IN const char * const strNewName);

///****************************************************************************
//*  @fn     FM_FileInfo
//*  @brief  获取远程上的单个文件信息
//*  @param  strRemoteFile            [IN]       文件路径
//*  @return 成功,返回true;失败,返回false
//****************************************************************************/
//IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpFileInfo(IN const void * const handle, IN const char * const strRemoteFile, OUT FileInfo* const oFileInfo);

/****************************************************************************
*  @fn     FM_RemoteList
*  @brief  获取远程上的单个文件夹信息
*  @param  strRemoteFolder            [IN]       远程文件夹
*  @param  strList                    [IN]       文件夹信息
*  @param  bOnlyName                  [IN]       是否只获取名称
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpRemoteList(IN const void * const handle, IN const char * const strRemoteFolder, OUT int *nDataLength, OUT char * const strList, IN bool bOnlyName = false);

/****************************************************************************
*  @fn     FM_RemoteList
*  @brief  获取远程上的单个文件夹信息
*  @param  strRemoteFolder            [IN]       远程文件夹
*  @param  nDataLength                [OUT]      信息长度
*  @param  struFTPFileInfo            [OUT]      文件夹中文件信息
*  @param  bOnlyName                  [IN]       是否只获取名称
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpRemoteFileList(IN const void * const handle, IN const char * const strRemoteFolder, OUT IMVS::FTP::RemoteFileListInfo *struFTPFileInfo, IN bool bOnlyName = false);

/****************************************************************************
*  @fn     IMVS_FtpDeInit
*  @brief  断开连接
*  @return 成功,返回true;失败,返回false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpDeInit(IN const void * const handle);

/** @fn     IMVS_SetFilePathFromWindows
*  @brief  把windows下的文件传递到linux，上层传入的是文件路径
*  @brief  如果nOutPathSize为0，则接口会读出文件中内容然后传递到模块
*  @brief  如果nOutPathSize为非0，则通过FTP上传文件到linux，然后把linux路径给模块，同时把linux中的路径给调用者
*  @param  handle                  [IN]        句柄
*  @param  pInFile                 [IN]        传入的windows文件路径
*  @param  pParamName              [IN]        设置模块参数时的参数名称，如果没有可以置NULL（比如设置）
*  @param  nModuleID               [IN]        设置模块参数时模块ID
*  @param  pOutFilePath            [OUT]       如果文件需要上传到linux，则里边会赋值liunx文件路径
*  @param  nOutPathSize            [IN]        调用者为pOutFilePath分配的长度，默认为0
*  @return 成功，返回CM_OK；失败，返回对应错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetFilePathFromWindows(IN const void * const handle, IN const char * const pInFile, IN const char * const pParamName = 0,
    IN  const unsigned int nModuleID = -1,
    OUT char * const pOutFilePath = 0,
    IN  int * const nOutPathSize = 0);

/** @fn    IMVS_GenerateFileToWindows
*  @brief  SDK先产生一个linux的临时路径传递到底层，接口根据bDelTempFile配置选择操作步骤
*  @param  pPath               [IN]  文件路径
*  @param  pTempPath           [OUT] 产生的linux下的临时文件路径
*  @param  bDelTempFile        [IN]  true：则SDK需要把linux文件拷贝到pPath，然后删除linux下的文件。false：则不进行删除操作
*  @return 成功，返回CM_OK；失败，返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GenerateFileToWindows(IN const void * const handle, IN const char * const pPath,
    IN const char * const pParamName = 0,
    IN  const unsigned int nModuleID = -1,
    OUT char * const pTempPath = 0,
    IN const bool bDelTempFile = true);

#pragma endregion

/** @fn    IMVS_VersionUpgradeFlag
*  @brief  版本兼容工具标识
*  @return 成功，返回CM_OK；失败，返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_VersionUpgradeFlag(IN const void * const handle, IN bool bToolFlag);

/** @fn     IMVS_AddDynamicParam
*  @brief  添加动态参数
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       参数名
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddDynamicParam(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName);

/** @fn     IMVS_ModifyDynamicParam
*  @brief  修改动态参数
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strNameOld              [IN]       参数名
*  @param  strNameNew              [IN]       参数名
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ModifyDynamicParam(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strNameOld,
    IN const char * const strNameNew);

/** @fn     IMVS_DeleteDynamicParam
*  @brief  删除动态参数
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       参数名
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteDynamicParam(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName);

/** @fn     IMVS_GetAllDynamicParam
*  @brief  获取所有动态参数
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  pstParamList            [OUT]      参数列表
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllDynamicParam(IN const void * const handle,
    IN const unsigned int nObjectID,
    OUT IMVS_MODULE_PARAM_LIST * const pstParamList);

/** @fn     IMVS_AddDynamicParamRelation
*  @brief  添加动态参数关联关系
*  @param  handle                  [IN]       操作句柄
*  @param  nDestinID               [IN]       目标ID
*  @param  strDestinName           [IN]       目标参数名
*  @param  nSourceID               [IN]       来源ID
*  @param  strSourceName           [IN]       来源参数名
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddDynamicParamRelation(IN const void * const handle,
    IN const unsigned int nDestinID,
    IN const char * const strDestinName,
    IN const unsigned int nSourceID,
    IN const char * const strSourceName);

/** @fn     IMVS_GetDynamicParamRelationByKey
*  @brief  获取动态参数关联关系
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       参数名
*  @param  pstRelationList         [OUT]      关联关系列表
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetDynamicParamRelationByKey(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    OUT IMVS_DYNAMIC_PARAM_RELATION_LIST * const pstRelationList);

/** @fn     IMVS_DeleteDynamicParamRelation
*  @brief  删除动态参数关联关系
*  @param  handle                  [IN]       操作句柄
*  @param  nDestinID               [IN]       目标ID
*  @param  strDestinName           [IN]       目标参数名
*  @param  nSourceID               [IN]       来源ID
*  @param  strSourceName           [IN]       来源参数名
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteDynamicParamRelation(IN const void * const handle,
    IN const unsigned int nDestinID,
    IN const char * const strDestinName,
    IN const unsigned int nSourceID,
    IN const char * const strSourceName);

/** @fn     IMVS_SetDynamicRunParamValue
*  @brief  设置动态运行参数值
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       参数名
*  @param  strValue                [IN]       参数值
*  @param  strOptionalParam        [IN]       可选参数，默认填空字符串，界面可选填模块的参数名称
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetDynamicRunParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    IN const char * const strValue,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn     IMVS_GetDynamicRunParamValue
*  @brief  获取动态运行参数值
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       参数名
*  @param  nValueSize              [IN]       参数值的分配大小
*  @param  strValue                [OUT]      参数值
*  @param  strOptionalParam        [IN]       可选参数，默认填空字符串，界面可选填模块的参数名称
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetDynamicRunParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    IN const unsigned int nValueSize,
    OUT const char * const strValue,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn     IMVS_SetDynamicBinaryParamValue
*  @brief  设置动态二进制参数值
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       参数名
*  @param  pData                   [IN]       参数数据
*  @param  nDataLen                [IN]       数据长度
*  @param  strOptionalParam        [IN]       可选参数，默认填空字符串，界面可选填模块的参数名称
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetDynamicBinaryParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    IN const char * const pData,
    IN const unsigned int nDataLen,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn     IMVS_GetDynamicBinaryParamValue
*  @brief  获取动态二进制参数值，数据拷贝后使用接口释放指针-IMVS_ReleaseDynamicMemory
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       参数名
*  @param  pData                   [OUT]      参数数据
*  @param  pnDataLen               [OUT]      数据长度
*  @param  strOptionalParam        [IN]       可选参数，默认填空字符串，界面可选填模块的参数名称
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetDynamicBinaryParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    OUT char *& pData,
    OUT unsigned int * const pnDataLen,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn     IMVS_SetDynamicUIParamValue
*  @brief  设置动态UI参数值
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       参数名
*  @param  pData                   [IN]       参数数据
*  @param  nDataLen                [IN]       数据长度
*  @param  strOptionalParam        [IN]       可选参数，默认填空字符串，界面可选填模块的参数名称
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetDynamicUIParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    IN const char * const pData,
    IN const unsigned int nDataLen,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn     IMVS_GetDynamicUIParamValue
*  @brief  获取动态UI参数值
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       参数名
*  @param  pData                   [OUT]      参数数据
*  @param  pnDataLen               [OUT]      数据长度
*  @param  strOptionalParam        [IN]       可选参数，默认填空字符串，界面可选填模块的参数名称
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetDynamicUIParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    OUT char *& pData,
    OUT unsigned int * const pnDataLen,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn    IMVS_DeleteDynamicRelateUIParamValue
*  @brief  删除关联的UserData数据
*  @param  handle                  [IN]       操作句柄
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       参数名
*  @param  strValue                [IN]       模块参数名称（不可为空）
*  @param  eIsFuzzyMatch           [IN]       是否模糊匹配
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteDynamicRelateUIParamValue(IN const void * const handle,
	IN const unsigned int nObjectID,
	IN const char * const strName,
	IN IMVS_FUZZY_MATCH eIsFuzzyMatch,
	IN const char * const strOptionalParam);

/** @fn    IMVS_ReleaseDynamicMemory
*  @brief  释放动态内存
*  @param  handle                  [IN]       操作句柄
*  @param  eMemType                [IN]       内存类型
*  @param  pData                   [IN]       指针
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ReleaseDynamicMemory(IN const void * const handle, IMVS_RELEASE_MEMORY_TYPE eMemType, IN char * pData);

/** @fn    IMVS_ReportData
*  @brief  上报消息
*  @param  handle[IN]      操作句柄
*  @param  pData[IN]       数据指针
*  @return 成功, 返回IMVS_EC_OK; 失败, 返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ReportData(IN const void * const handle, IN const char * pData, IN const unsigned int nDataLen);

/** @fn     IMVS_CheckUIParamExist
*  @brief  判断UI参数是否存在
*  @param  handle            [IN]       操作句柄
*  @param  nObjectID         [IN]       对象ID
*  @param  strParamName      [IN]       界面参数名称
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CheckUIParamExist(IN const void * const handle, IN const unsigned int nObjectID, IN const char * const strParamName);

/** @fn     IMVS_GetAllExecutableProcedure
*  @brief  获取当前方案中可执行的流程
*  @param  handle            [IN]       操作句柄
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllExecutableProcedure(IN const void * const handle, OUT IMVS_PROCESS_INFO_LIST * const pstProcessInfoList);


/** @fn    IMVS_SetAllExecutableProcedureId
*  @brief  设置当前方案中可执行的流程ID
*  @param  handle                        [IN]       操作句柄
*  @param  pstProcessInfoList            [IN]       可执行流程列表
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetAllExecutableProcedureId(IN const void * const handle, IN IMVS_PROCESS_INFO_LIST * const pstProcessInfoList);

/** @fn    IMVS_ModifySubInputName
*  @brief  修改模块订阅关系中输入名称
*  @param  handle                        [IN]       操作句柄
*  @param  nModuleID                     [IN]       模块ID
*  @param  strSubInputNameOld            [IN]       老的订阅输入名称
*  @param  strSubInputNameNew            [IN]       新的订阅输入名称
*  @return 成功，返回IMVS_EC_OK；失败，返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ModifyModuleSubInputName(IN const void * const handle, IN const unsigned int nModuleID, IN const char * const strSubInputNameOld, IN const char * const strSubInputNameNew);

#pragma region Linux新增接口

/** @fn     IMVS_CheckServerPasswordStatus
*  @brief  获取Server的密码状态（跨机使用），该接口在CreateHandle前调用，与IMVS_SetServerPassword配合使用
*  @param  serverIP            [IN]  服务IP
*  @param  serverPort          [IN]  服务端口
*  @param  waitingTime         [OUT] 等待时间，锁定时有效
*  @return IMVS_EC_OK（本机时返回）、需设置密码（IMVS_EC_AUTH_REMOTE_NO_PASSWORD）、已有密码（IMVS_EC_AUTH_ASSWORD_IS_EXIST）、账户已锁定（IMVS_EC_AUTH_USER_LOCKOUT）
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CheckServerPasswordStatus(IN const char* serverIP, IN unsigned int serverPort, OUT unsigned int* waitingTime);

/** @fn     IMVS_SetServerPassword
*  @brief  设置Server密码， 该接口在CreateHandle前调用，与IMVS_CheckServerPasswordStatus配合使用
*  @param  serverIP            [IN]  服务IP
*  @param  serverPort          [IN]  服务端口
*  @param  password            [IN]  密码
*  @return 成功，返回IMVS_EC_OK；失败，返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetServerPassword(IN const char* serverIP, IN unsigned int serverPort, IN const char* password);

/** @fn     IMVS_ModifyServerPassword
*  @brief  修改Server密码，该接口需要连接服务成功后才能运行
*  @param  oldPassword         [IN]  旧密码
*  @param  newPassword         [IN]  新密码
*  @return 成功，返回IMVS_EC_OK；失败，返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ModifyServerPassword(IN const char* oldPassword, IN const char* newPassword);

/** @fn     IMVS_StartupVmFrontendWindowOnLinux
*  @brief  拉起前端运行界面，在DestroyHandle后执行
*  @param  serverAddress       [IN]  服务地址，形式如: 127.0.0.1:5556
*  @return 成功，返回IMVS_EC_OK；失败，返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_StartupVmFrontendWindowOnLinux(IN const char* serverAddress);

/** @fn     IMVS_GetAlgorithmVersion
*  @brief  获取算子版本号，包括2d算子和深度算子
*  @param  normalVersion       [OUT]  2d算子版本
*  @param  deeplearningVersion [OUT]  深度算子版本
*  @return 成功，返回IMVS_EC_OK；失败，返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAlgorithmVersion(OUT IMVS::AlgorithmVersionInfo* versions);

/** @fn    IMVS_SetExecuteDelayTime
*  @brief  设置全局执行延迟时间
*  @param  handle                [IN]     操作句柄
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetExecuteDelayTime(IN const void * const handle, IN const unsigned int nDelayTime);

#pragma endregion

#ifdef __cplusplus
}
#endif 

#endif    // IMVS_6000_PLATFORMSDKC_IN_H__
