/***************************************************************************************************
 *
 * 版权信息：版权所有 (c) 2017, 保留所有权利
 *
 * 文件名称：iMVS-6000PlatformSDKC_Obj.h
 * 摘    要: 二次开发SDK C接口头文件
 *
 * 作    者: 视觉平台组
 * 日    期：2020-01-14 16:59:32
 * 备    注：新建
 ****************************************************************************************************/
#ifndef IMVS_6000_PLATFORMSDKC_OBJ_H__ // 2020-01-14 16:59:32
#define IMVS_6000_PLATFORMSDKC_OBJ_H__

#include "iMVS-6000SDK4ServerDefine.h"
#include "iMVS-6000PlatformSDKDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn     IMVS_PF_RegisterResultCallBack4CS_U
 *  @brief  通过回调的方式将算法平台底层运行时的数据反馈给用户（供C# 二次开发SDK使用）
 *  @param  handle                  [IN]       操作句柄
 *  @param  cbOutputPlatformInfo    [IN]       回调函数
 *  @param  pUser                   [IN]       用户句柄
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_RegisterResultCallBack4CS_U(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/** @fn     IMVS_PF_RegisterResultCallBack4CS_V32_U
 *  @brief  注册回调函数(回调导出结果)（供C# 二次开发SDK使用）
 *  @param  handle                  [IN]        句柄
 *  @param  cbOutputPlatformInfo    [IN]        回调函数
 *  @param  pUser                   [IN]        pUser
 *  @return 成功，返回CM_OK；失败，返回对应错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_RegisterResultCallBack4CS_V32_U(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/** @fn     IMVS_SetInputInt
 *  @brief  设置整型模块输入
 *  @param  handle                  [IN]     操作句柄
 *  @param  nModuleID               [IN]     模块ID
 *  @param  pstIntListInfo          [IN]     整型数据信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputInt(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_INPUT_INT_LIST_INFO * const pstIntListInfo);

/** @fn     IMVS_SetInputFloat
 *  @brief  设置浮点型模块输入
 *  @param  handle                  [IN]     操作句柄
 *  @param  nModuleID               [IN]     模块ID
 *  @param  pstIntListInfo          [IN]     浮点型数据信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputFloat(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_INPUT_FLOAT_LIST_INFO * const pstFloatListInfo);

/** @fn     IMVS_SetInputDouble
 *  @brief  设置字符串型模块输入
 *  @param  handle                  [IN]     操作句柄
 *  @param  nModuleID               [IN]     模块ID
 *  @param  pstDoubleListInfo       [IN]     浮点型
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputDouble(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_INPUT_DOUBLE_LIST_INFO * const pstDoubleListInfo);

/** @fn     IMVS_SetInputString
*  @brief  设置字符串型模块输入
*  @param  handle                  [IN]     操作句柄
*  @param  nModuleID               [IN]     模块ID
*  @param  pstStringListInfo       [IN]     字符串型数据信息列表
*  @return 成功,返回IMVS_EC_OK;失败,返回错误码
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputString(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_INPUT_STRING_LIST_INFO * const pstStringListInfo);

/** @fn     IMVS_SetInputImage
 *  @brief  设置图像型模块输入
 *  @param  handle                  [IN]     操作句柄
 *  @param  nModuleID               [IN]     模块ID
 *  @param  pstImageInfo            [IN]     图像型数据信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputImage(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_MODULE_INPUT_DATA_INFO * const pstImageInfo);

/** @fn     IMVS_SetInputPointset
 *  @brief  设置点集型模块输入
 *  @param  handle                  [IN]     操作句柄
 *  @param  nModuleID               [IN]     模块ID
 *  @param  pstPointsetInfo         [IN]     点集型数据信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputPointset(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_MODULE_INPUT_DATA_INFO * const pstPointsetInfo);

/** @fn     IMVS_SetInputImage
 *  @brief  设置二进制数据型模块输入
 *  @param  handle                  [IN]     操作句柄
 *  @param  nModuleID               [IN]     模块ID
 *  @param  pstBytesInfo            [IN]     二进制型数据信息列表
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputBytes(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_MODULE_INPUT_DATA_INFO * const pstBytesInfo);

/** @fn     IMVS_ImportIndependentGroup
 *  @brief  导入Group
 *  @param  handle            [IN]       操作句柄
 *  @param  nProcessID        [IN]       流程ID
 *  @param  strPath           [IN]       Group文件保存路径
 *  @param  strPassword       [IN]       Group文件密码（预留）
 *  @param  nIdAllocateWay    [IN]       ID分配方式 (0：自动分配ID，1：按文件中的ID分配)
 *  @return 成功,返回IMVS_EC_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportIndependentGroup(IN const void * const handle, IN unsigned int nProcessID, IN const char * const strPath, IN const char * const strPassword, IN const unsigned int nIdAllocateWay, OUT IMVS_MODULE_INFO * const pstModuleInfo);

/** @fn     IMVS_SyncSelfExecuteOneModule
 *  @brief  模块同步自执行:该模块利用旧的输入重新进行一次算法,将结果发给界面(不发给后继模块)
 *  @param  nModuleId               [IN]    模块Id
 *  @param  handle                  [IN]    句柄
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncSelfExecuteOneModule(IN const void * const handle, IN const unsigned int nModuleId);

/** @fn     IMVS_SyncSelfExecuteOneModule
 *  @brief  模块同步自执行:该模块利用旧的输入重新进行一次算法,将结果发给界面(不发给后继模块)
 *  @param  nModuleId               [IN]    模块Id
 *  @param  handle                  [IN]    句柄
 *  @return 成功,返回IMVS_OK;失败,返回错误码
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncExecuteOne(IN const void * const handle, IN const char * const strCommand);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncExecuteOne_V30(IN const void * const handle, IN const unsigned int nProcessID, IN const char * const strCommand, bool bIsP2P = false);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncExecuteOnceEX_V30(IN const void * const handle, IN const unsigned int nProcessID, IN const char * const strCommand, OUT unsigned int * const pnExecuteCount);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_RegisterResultCallBack4Object(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DestroyHandleWithServer(IN const void * const handle);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_QueryCurrentModuleResult(IN const void * const handle, IN const unsigned int nModuleID, OUT IMVS_QUERY_MODULE_RES_INFO_LIST *& pstQueryModuResInfoList, IN const bool bResBuffFirst = true);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetServerPath(IN const char * const strServerPath);

//TODO hucy 替换枚举量
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncResetFlag(IN const unsigned int nOperation, IN const unsigned int nObjectID = 0);

//TODO hucy 替换枚举量
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncWaitFlag(IN const unsigned int nOperation, IN const unsigned int nObjectID = 0);

#ifdef __cplusplus
}
#endif 

#endif    // IMVS_6000_PLATFORMSDKC_OBJ_H__
