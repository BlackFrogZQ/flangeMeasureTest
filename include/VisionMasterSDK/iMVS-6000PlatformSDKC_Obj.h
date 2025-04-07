/***************************************************************************************************
 *
 * ��Ȩ��Ϣ����Ȩ���� (c) 2017, ��������Ȩ��
 *
 * �ļ����ƣ�iMVS-6000PlatformSDKC_Obj.h
 * ժ    Ҫ: ���ο���SDK C�ӿ�ͷ�ļ�
 *
 * ��    ��: �Ӿ�ƽ̨��
 * ��    �ڣ�2020-01-14 16:59:32
 * ��    ע���½�
 ****************************************************************************************************/
#ifndef IMVS_6000_PLATFORMSDKC_OBJ_H__ // 2020-01-14 16:59:32
#define IMVS_6000_PLATFORMSDKC_OBJ_H__

#include "iMVS-6000SDK4ServerDefine.h"
#include "iMVS-6000PlatformSDKDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn     IMVS_PF_RegisterResultCallBack4CS_U
 *  @brief  ͨ���ص��ķ�ʽ���㷨ƽ̨�ײ�����ʱ�����ݷ������û�����C# ���ο���SDKʹ�ã�
 *  @param  handle                  [IN]       �������
 *  @param  cbOutputPlatformInfo    [IN]       �ص�����
 *  @param  pUser                   [IN]       �û����
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_RegisterResultCallBack4CS_U(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/** @fn     IMVS_PF_RegisterResultCallBack4CS_V32_U
 *  @brief  ע��ص�����(�ص��������)����C# ���ο���SDKʹ�ã�
 *  @param  handle                  [IN]        ���
 *  @param  cbOutputPlatformInfo    [IN]        �ص�����
 *  @param  pUser                   [IN]        pUser
 *  @return �ɹ�������CM_OK��ʧ�ܣ����ض�Ӧ������
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_PF_RegisterResultCallBack4CS_V32_U(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/** @fn     IMVS_SetInputInt
 *  @brief  ��������ģ������
 *  @param  handle                  [IN]     �������
 *  @param  nModuleID               [IN]     ģ��ID
 *  @param  pstIntListInfo          [IN]     ����������Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputInt(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_INPUT_INT_LIST_INFO * const pstIntListInfo);

/** @fn     IMVS_SetInputFloat
 *  @brief  ���ø�����ģ������
 *  @param  handle                  [IN]     �������
 *  @param  nModuleID               [IN]     ģ��ID
 *  @param  pstIntListInfo          [IN]     ������������Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputFloat(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_INPUT_FLOAT_LIST_INFO * const pstFloatListInfo);

/** @fn     IMVS_SetInputDouble
 *  @brief  �����ַ�����ģ������
 *  @param  handle                  [IN]     �������
 *  @param  nModuleID               [IN]     ģ��ID
 *  @param  pstDoubleListInfo       [IN]     ������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputDouble(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_INPUT_DOUBLE_LIST_INFO * const pstDoubleListInfo);

/** @fn     IMVS_SetInputString
*  @brief  �����ַ�����ģ������
*  @param  handle                  [IN]     �������
*  @param  nModuleID               [IN]     ģ��ID
*  @param  pstStringListInfo       [IN]     �ַ�����������Ϣ�б�
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputString(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_INPUT_STRING_LIST_INFO * const pstStringListInfo);

/** @fn     IMVS_SetInputImage
 *  @brief  ����ͼ����ģ������
 *  @param  handle                  [IN]     �������
 *  @param  nModuleID               [IN]     ģ��ID
 *  @param  pstImageInfo            [IN]     ͼ����������Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputImage(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_MODULE_INPUT_DATA_INFO * const pstImageInfo);

/** @fn     IMVS_SetInputPointset
 *  @brief  ���õ㼯��ģ������
 *  @param  handle                  [IN]     �������
 *  @param  nModuleID               [IN]     ģ��ID
 *  @param  pstPointsetInfo         [IN]     �㼯��������Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputPointset(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_MODULE_INPUT_DATA_INFO * const pstPointsetInfo);

/** @fn     IMVS_SetInputImage
 *  @brief  ���ö�����������ģ������
 *  @param  handle                  [IN]     �������
 *  @param  nModuleID               [IN]     ģ��ID
 *  @param  pstBytesInfo            [IN]     ��������������Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetInputBytes(IN const void * const handle, IN const unsigned int nModuleID, IN const IMVS_MODULE_INPUT_DATA_INFO * const pstBytesInfo);

/** @fn     IMVS_ImportIndependentGroup
 *  @brief  ����Group
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  strPath           [IN]       Group�ļ�����·��
 *  @param  strPassword       [IN]       Group�ļ����루Ԥ����
 *  @param  nIdAllocateWay    [IN]       ID���䷽ʽ (0���Զ�����ID��1�����ļ��е�ID����)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportIndependentGroup(IN const void * const handle, IN unsigned int nProcessID, IN const char * const strPath, IN const char * const strPassword, IN const unsigned int nIdAllocateWay, OUT IMVS_MODULE_INFO * const pstModuleInfo);

/** @fn     IMVS_SyncSelfExecuteOneModule
 *  @brief  ģ��ͬ����ִ��:��ģ�����þɵ��������½���һ���㷨,�������������(���������ģ��)
 *  @param  nModuleId               [IN]    ģ��Id
 *  @param  handle                  [IN]    ���
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncSelfExecuteOneModule(IN const void * const handle, IN const unsigned int nModuleId);

/** @fn     IMVS_SyncSelfExecuteOneModule
 *  @brief  ģ��ͬ����ִ��:��ģ�����þɵ��������½���һ���㷨,�������������(���������ģ��)
 *  @param  nModuleId               [IN]    ģ��Id
 *  @param  handle                  [IN]    ���
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncExecuteOne(IN const void * const handle, IN const char * const strCommand);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncExecuteOne_V30(IN const void * const handle, IN const unsigned int nProcessID, IN const char * const strCommand, bool bIsP2P = false);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncExecuteOnceEX_V30(IN const void * const handle, IN const unsigned int nProcessID, IN const char * const strCommand, OUT unsigned int * const pnExecuteCount);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_RegisterResultCallBack4Object(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_PF_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DestroyHandleWithServer(IN const void * const handle);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_QueryCurrentModuleResult(IN const void * const handle, IN const unsigned int nModuleID, OUT IMVS_QUERY_MODULE_RES_INFO_LIST *& pstQueryModuResInfoList, IN const bool bResBuffFirst = true);

IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetServerPath(IN const char * const strServerPath);

//TODO hucy �滻ö����
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncResetFlag(IN const unsigned int nOperation, IN const unsigned int nObjectID = 0);

//TODO hucy �滻ö����
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncWaitFlag(IN const unsigned int nOperation, IN const unsigned int nObjectID = 0);

#ifdef __cplusplus
}
#endif 

#endif    // IMVS_6000_PLATFORMSDKC_OBJ_H__
