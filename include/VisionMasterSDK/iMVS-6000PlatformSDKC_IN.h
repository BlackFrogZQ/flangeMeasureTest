/***************************************************************************************************
 *
 * ��Ȩ��Ϣ����Ȩ���� (c) 2017, ��������Ȩ��
 *
 * �ļ����ƣ�iMVS-6000PlatformSDKC_IN.h
 * ժ    Ҫ: ���ο���SDK C�ӿ�ͷ�ļ�
 *
 * ��    ��: �Ӿ�ƽ̨��
 * ��    �ڣ�2019-05-18 16:46:42
 * ��    ע���½�
 ****************************************************************************************************/
#ifndef IMVS_6000_PLATFORMSDKC_IN_H__ // 2019-05-18 16:46:42
#define IMVS_6000_PLATFORMSDKC_IN_H__

#include "iMVS-6000SDK4ServerDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn     IMVS_GetLastError
 *  @brief  ������ȡϵͳ�Ļ��߱�SDK�Ĵ�����
 *  @return ���ر�SDK�Ĵ�������
 */
IMVS_6000_PLATFORMSDK_API const char * __stdcall IMVS_GetLastError();

/** @fn     IMVS_GetBuildVersion
 *  @brief  ��ȡ����汾
 *  @param  pnYear      [OUT]   ����汾���
 *  @param  pnMonth     [OUT]   ����汾�·�
 *  @param  pnDay       [OUT]   ����汾�շ�
 *  @return ���ص�ǰ����汾��Ϣ�ַ���
 */
IMVS_6000_PLATFORMSDK_API const char * __stdcall IMVS_GetBuildVersion(OUT unsigned int * const pnYear = IMVS_NULL, OUT unsigned int * const pnMonth = IMVS_NULL, OUT unsigned int * const pnDay = IMVS_NULL);

/** @fn     IMVS_CreateHandle
 *  @brief  �������
 *  @param  handle                  [OUT]       Ҫ���ɵľ��
 *  @param  pstPlatformBasicInfo    [IN]        �㷨ƽ̨������Ϣ
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CreateHandle(OUT void ** const handle, IN const IMVS_PLATFORM_BASIC_INFO * const pstPlatformBasicInfo, OUT int* waitingTime = nullptr);

/** @fn     IMVS_DestroyHandle
 *  @brief  ���پ��
 *  @param  handle        [IN]   �����ٵľ��
 *  @param  nTakeoverType [IN]   �ӹ�����
 *  @return �ɹ�������HKR_OK��ʧ�ܣ����ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DestroyHandle(IN const void * const handle, IN const unsigned int nTakeoverType = 0);

/** @fn     IMVS_RegisterOutputPlatformInfoCallBack
 *  @brief  ע��ص�����
 *  @param  handle                  [IN]        ���
 *  @param  cbOutputPlatformInfo    [IN]        �ص�����
 *  @param  pUser                   [IN]        pUser
 *  @return �ɹ�������CM_OK��ʧ�ܣ����ض�Ӧ������
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_RegisterOutputPlatformInfoCallBack(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/** @fn     IMVS_GetPlatformDetailedInfo
 *  @brief  ��ȡ���㷨ƽ̨������Ϣ
 *  @brief  һ��������㷨ƽ̨����קģ��Ͷ��ĺ�,������һ��ʱ��
 *  @brief  һ���¾�������㷨ƽ̨ʱ, ���ô˽ӿڿ��Ի�ȡ��ǰ�㷨ƽ̨��ģ�����Ϣ
 *  @brief  ���ĵ���Ϣ, ���ӵ���Ϣ,�Լ��㷨ƽ̨״̬��Ϣ�ȵ�
 *  @brief  ��ʱû�õ�, ���������õ�
 *  @param  handle                  [IN]        ���
 *  @param  pstPlatformDetailedInfo [OUT]       ƽ̨��ϸ��Ϣ
 *  @return �ɹ�������CM_OK��ʧ�ܣ����ض�Ӧ������
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetPlatformDetailedInfo(IN const void * const handle, OUT IMVS_PLATFORM_DETAILED_INFO * pstPlatformDetailedInfo);

/** @fn     IMVS_AddOneModule
 *  @brief  ���ݴ������������һ����Ӧģ��
 *  @param  handle                  [IN]       ���
 *  @param  strModuleName           [IN]       ģ������
 *  @return �ɹ�������CM_OK��ʧ�ܣ����ض�Ӧ������
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddOneModule(IN const void * const handle, IN const IMVS_SYNC_ADD_ONE_MODULE_INFO * const pstSyncAddModuInput, OUT IMVS_MODULE_INFO * const pstModuleInfo);

/** @fn     IMVS_CloseOneModule
 *  @brief  �ر�һ��ģ��
 *  @param  pstModuleInfo           [IN]    ģ����Ϣ
 *  @param  handle                  [IN]    ���
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CloseOneModule(IN const void * const handle, IN const unsigned int nModuleId);

/** @fn     IMVS_SelfExecuteOneModule
 *  @brief  ģ����ִ��:��ģ�����þɵ��������½���һ���㷨,�������������(���������ģ��)
 *  @param  nModuleId               [IN]    ģ��Id
 *  @param  handle                  [IN]    ���
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SelfExecuteOneModule(IN const void * const handle, IN const unsigned int nModuleId);

/** @fn     IMVS_ConnectOneModule
 *  @brief  ģ������:����ͼ--> Բ����
 *  @param  pstPreModuleInfo        [IN]    ǰ��ģ��
 *  @param  pstNextModuleInfo       [IN]    ���ģ��
 *  @param  handle                  [IN]    ���
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ConnectOneModule(IN const void * const handle, IN const unsigned int nPreModuleId, IN const unsigned int nNextModuleId);

/** @fn     IMVS_DisConnectOneModule
 *  @brief  ģ��Ͽ�����:����ͼ-x> Բ����
 *  @param  pstPreModuleInfo        [IN]    ǰ��ģ��
 *  @param  pstNextModuleInfo       [IN]    ���ģ��
 *  @param  handle                  [IN]    ���
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DisConnectOneModule(IN const void * const handle, IN const unsigned int nPreModuleId, IN const unsigned int nNextModuleId);

/** @fn     IMVS_ExecuteOnceOneModule
 *  @brief  ��ʱû�õ�,���ĳ��ģ��ִ��һ��,�������ֶ�����ˮ�߷ֱ�ִ��
 *  @param  pstModuleInfo        [IN]    ǰ��ģ��
 *  @param  nCycleID             [IN]    ����ID
 *  @param  handle               [IN]    ���
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExecuteOnceOneModule(IN const void * const handle, IN const IMVS_MODULE_INFO * const pstModuleInfo, IN const unsigned int nCycleID);

/** @fn     IMVS_ExecuteOnce
 *  @brief  ͳһ����Դͷִ��һ��
 *  @brief  strTrigger��ʾ�����ַ���,͸����ÿ��ģ��
 *  @param  strTrigger        [IN]    �����ַ���
 *  @param  handle            [IN]    ���
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExecuteOnce(IN const void * const handle, IN const char * const strTrigger);

/** @fn     IMVS_ContinousRunStart
 *  @brief  ����ִ�п�ʼ
 *  @param  handle            [IN]    ���
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ContinousRunStart(IN const void * const handle);

/** @fn     IMVS_StopExecute
 *  @brief  ִֹͣ��
 *  @param  handle            [IN]    ���
 *  @param  nWaitTime         [IN]    ��ʱʱ��(��λ����)
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_StopExecute(IN const void * const handle, IN const unsigned int nWaitTime);

/** @fn     IMVS_SetContinousRunInterval
 *  @brief  ��������ִ��ʱ����
 *  @param  handle            [IN]    ���
 *  @param  nMilliSecond      [IN]    ʱ����
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetContinousRunInterval(IN const void * const handle, IN const unsigned int nMilliSecond);

/** @fn     IMVS_SubscribeResultEx
 *  @brief  ����ģ��֮�䶩������
 *  @brief  V2.0.1 �汾�����ӿ�
 *  @param  handle            [IN]    ���
 *  @param  pstSubscribeInfo  [IN]    ������Ϣ
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SubscribeResultEx(IN const void * const handle, 
                                                              IN const IMVS_SUBSCRIBE_INFO * const pstSubscribeInfo);

/** @fn     IMVS_UnSubscribeResultEx
 *  @brief  ����ģ��֮��ⶩ������
 *  @param  handle            [IN]    ���
 *  @param  pstSubscribeInfo  [IN]    ������Ϣ
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_UnSubscribeResultEx(IN const void * const handle, 
                                                              IN const IMVS_SUBSCRIBE_INFO * const pstSubscribeInfo);

/** @fn     IMVS_CheckSolution
 *  @brief  ��鷽��������û������
 *  @param  strPath            [IN]     ����·��
 *  @param  pnHasPwd           [OUT]    �Ƿ��з������루1: �����룩
 *  @param  pnValidFormat      [OUT]    ������ʽ�Ƿ���Ч��1����ʽ��Ч��
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CheckSolution(
    IN const char * const strPath,      // ����·��
    OUT unsigned int * pnHasPwd,        // �Ƿ��з�������
    OUT unsigned int * pnValidFormat);  // ������ʽ�Ƿ���Ч

/** @fn     IMVS_CheckPassword
 *  @brief  ��֤��������
 *  @param  strPath            [IN]     ����·��
 *  @param  strPassWord        [IN]     ��������
 *  @param  pnIsCorrect        [OUT]    ���������Ƿ���ȷ
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CheckPassword(
    IN const char * const strPath,      // ����·��
    IN const char * const strPassWord,
    OUT int * pnIsCorrect);

/** @fn     IMVS_SaveSolution
 *  @brief  ���淽��
 *  @param  handle             [IN]     �������
 *  @param  strPath            [IN]     ����·��
 *  @param  strPassWord        [IN]     ��������
 *  @param  pData              [IN]     ��������
 *  @param  nDataLen           [IN]     �������ݳ���
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SaveSolution(
    IN const void * const handle,
    IN const char * const strPath,       // ����·��
    IN const char * const strPassWord,   // ��������
    IN const unsigned char * const pData,// ��������
    IN const unsigned int nDataLen
    );

/** @fn     IMVS_GetSolutionVersion
 *  @brief  ��ȡ�����汾
 *  @param  handle                 [IN]     �������
 *  @param  strPath                [IN]     ����·��
 *  @param  strPassWord            [IN]     ��������
 *  @param  pstSolutionVersionInfo [OUT]    �����汾��Ϣ
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetSolutionVersion(
    IN const void * const handle,
    IN const char * const strPath,
    IN const char * const strPassWord,
    OUT IMVS_SOLUTION_VERSION_INFO * pstSolutionVersionInfo);

/** @fn     IMVS_LoadSolution
 *  @brief  ���ط���
 *  @param  handle                 [IN]     �������
 *  @param  strPath                [IN]     ����·��
 *  @param  strPassWord            [IN]     ��������
 *  @param  bIsCheckSol            [IN]     У�鷽����ǣ�SDKУ�飬vm��У�飩
 *  @param  bReportSilenceRunFlag  [IN]     �ϱ���Ĭִ�б�ǣ�V4.3���ӣ����泷��ʱ���Բ��ϱ���Ĭ��
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_LoadSolution(
    IN const void * const handle,
    IN const char * const strPath,      // ����·��
    IN const char * const strPassWord,
	IN bool bIsCheckSol = true,
    IN bool bReportSilenceRunFlag = true);

/***************** ƽ̨SDK���ο������� ******************/
/** @fn     IMVS_SetParamValue
 *  @brief  ����ģ�����ֵ
 *  @param  handle                  [IN]       �������
 *  @param  nModuleID               [IN]       ģ��ID
 *  @param  strName                 [IN]       ������
 *  @param  strValue                [IN]       ����ֵ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetParamValue(IN const void * const handle ,
                                                          IN const unsigned int nModuleID ,
                                                          IN const char * const strName ,
                                                          IN const char * const strValue);

/** @fn     IMVS_SetParamValueForImageSource
*  @brief  ����ģ�����ֵ ���ӡ�ɾ��ͼƬ
*  @param  handle                  [IN]       �������
*  @param  nModuleID               [IN]       ģ��ID
*  @param  strName                 [IN]       ������
*  @param  strPath                 [IN]       ͼƬ·��
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetParamValueForImageSource(IN const void * const handle,
	IN const unsigned int nModuleID,
	IN const char * const strName,
	IN const char * const strPath);

/** @fn     IMVS_GetParamValue
 *  @brief  ��ȡģ�����ֵ
 *  @param  handle                  [IN]       �������
 *  @param  nModuleID               [IN]       ģ��ID
 *  @param  strName                 [IN]       ������
 *  @param  nStrValueSize           [IN]       ����ֵ�ķ����С
 *  @param  strValue                [OUT]      ����ֵ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetParamValue(IN const void * const handle ,
                                                          IN const unsigned int nModuleID ,
                                                          IN const char * const strName ,
                                                          IN const unsigned int nStrValueSize ,
                                                          OUT char * const strValue);

/** @fn     IMVS_GetParamList
 *  @brief  ��ȡģ������б�
 *  @param  handle                  [IN]       �������
 *  @param  nModuleID               [IN]       ģ��ID
 *  @param  pstModuleParamList      [OUT]      ģ������б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetParamList(IN const void * const handle ,
                                                         IN const unsigned int nModuleID ,
                                                         OUT IMVS_MODULE_PARAM_LIST * const pstModuleParamList);

/** @fn     IMVS_SetParamList
 *  @brief  ����ģ������б�
 *  @param  handle                  [IN]       �������
 *  @param  nModuleID               [IN]       ģ��ID
 *  @param  pstModuleParamList      [IN]       ģ������б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetParamList(IN const void * const handle ,
                                                         IN const unsigned int nModuleID ,
                                                         IN const IMVS_MODULE_PARAM_LIST * const pstModuleParamList);

/** @fn     IMVS_PF_GetSaveProgress
 *  @brief  ��ȡ����������ȡ�������(������)
 *  @param  handle                  [IN]       �������
 *  @param  pnSaveprogress          [OUT]      �����������
 *  @return �ɹ�,����IMVS_EC_OK; ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetSaveProgress(IN const void * const handle , OUT unsigned int * const pnSaveprogress);

/** @fn     IMVS_GetLoadProgress
 *  @brief  ��ȡ�������ؽ��ȡ����ؽ���������룩
 *  @param  handle                  [IN]       �������
 *  @param  pnLoadProgress          [OUT]      ���ؽ���
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetLoadProgress(IN const void * const handle , OUT unsigned int * const pnLoadProgress);

/** @fn     IMVS_CloseSolution
 *  @brief  �ر��㷨ƽ̨��ǰ����
 *  @param  handle                  [IN]       �������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CloseSolution(IN const void * const handle);

/** @fn     IMVS_GetAllModuleList
 *  @brief  ��ȡ��ǰ����ģ���б�
 *  @param  handle                  [IN]       �������
 *  @param  pstModuleInfoList       [OUT]      ����ģ����Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllModuleList(IN const void * const handle ,
                                                             OUT IMVS_MODULE_INFO_LIST * const pstModuleInfoList);

/** @fn     IMVS_ImportModuleData
 *  @brief  ��ָ����ģ�鵼�����ݣ����żѺ��ܺ���Լ����
 *  @param  handle                  [IN]       �������
 *  @param  pstImportData           [IN]       ����ģ��������Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportModuleData(IN const void * const handle , IN const IMVS_IMPORT_MODULE_DATA_INPUT * const pstImportData);


/** @fn     IMVS_ExportModuleData
 *  @brief  ָ����ģ�鵼�����ݣ�Mƽ̨ר��, Ŀǰ������
 *  @param  handle                  [IN]       �������
 *  @param  pstExportData           [IN]       ����ģ��������Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExportModuleData(IN const void * const handle , INOUT IMVS_EXPORT_MODULE_DATA_OUTPUT * const pstExportData);

/** @fn     IMVS_SetBinaryData
 *  @brief  ������SetParamValue,ֻ�������ݲ�ֻ���ַ���,�����Ƕ���������
 *  @param  handle                  [IN]       �������
 *  @param  nModuleID               [IN]       ģ��ID
 *  @param  pstSetBinaryDataInfo    [IN]       ���ö�����������Ϣ
 *  @param  nRecvWaitTime           [IN]       ������Ϣ��ʱ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetBinaryData(IN const void * const handle ,
                                                          IN const unsigned int nModuleID ,
                                                          IN IMVS_SET_BINARY_DATA_INFO * pstSetBinaryDataInfo , 
														  IN const unsigned int nRecvWaitTime = 0);

/** @fn     IMVS_GetBinaryLength
 *  @brief  GetBinaryData֮ǰ,�û���Ҫ֪�����ݴ�Сʱ���ô˽ӿ�
 *  @param  handle                  [IN]       �������
 *  @param  nModuleID               [IN]       ģ��ID
 *  @param  pstGetBinaryLengthInfo  [OUT]      ���������ݳ�����Ϣ
 *  @param  nRecvWaitTime           [IN]       ���ճ�ʱ����λ��ms��
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetBinaryLength(IN const void * const handle ,
                                                          IN const unsigned int nModuleID ,
                                                          OUT IMVS_GET_BINARY_LENGTH_INFO * pstGetBinaryLengthInfo ,
														  IN const unsigned int nRecvWaitTime = 0);

/** @fn     IMVS_GetBinaryData
 *  @brief  ������GetParamValue,ֻ�������ݲ�ֻ���ַ���,�����Ƕ���������
 *  @param  handle                  [IN]       �������
 *  @param  nModuleID               [IN]       ģ��ID
 *  @param  pstGetBinaryDataInfo    [OUT]      ������������Ϣ
 *  @param  nRecvWaitTime           [IN]       ���ճ�ʱ����λ��ms��
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetBinaryData(IN const void * const handle ,
                                                          IN const unsigned int nModuleID ,
                                                          OUT IMVS_GET_BINARY_DATA_INFO * pstGetBinaryDataInfo , 
														  IN const unsigned int nRecvWaitTime = 0);

/** @fn     IMVS_GetBinaryDataEx
*  @brief  ������IMVS_GetBinaryData,�ڴ�ӿ��ڲ�����
*  @param  handle                  [IN]       �������
*  @param  nModuleID               [IN]       ģ��ID
*  @param  pstGetBinaryDataInfo    [OUT]      ������������Ϣ
*  @param  nRecvWaitTime           [IN]       ���ճ�ʱ����λ��ms��
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetBinaryDataEx(IN const void * const handle,
    IN const unsigned int nModuleID,
    OUT IMVS_GET_BINARY_DATA_INFO * pstGetBinaryDataInfo,
    IN const unsigned int nRecvWaitTime = 0);

/***************** �㷨ƽ̨V3.0���� ******************/

/** @fn     IMVS_AddOneModuleWithProcId
 *  @brief  �����Ӧģ��
 *  @param  handle            [IN]       �������
 *  @param  strModuleName     [IN]       ģ������
 *  @param  nProcessID        [IN]       ����ID
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddOneModuleWithProcId(
                      IN const void * const handle,
                      IN const char * const strModuleName,
                      IN const unsigned int nProcessID);

/** @fn     IMVS_ExecuteOnce_V30
 *  @brief  �ض�����ִ��һ��
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  strCommand        [IN]       �����ַ���
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExecuteOnce_V30(
                      IN const void * const handle,
                      IN const unsigned int nProcessID,
					  IN const char * const strCommand, 
					  IN bool bIsP2P = false);

/** @fn     IMVS_ContinousRunStart_V30
 *  @brief  �㷨ƽ̨�ض���������ִ�п�ʼ
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ContinousRunStart_V30(IN const void * const handle, IN const unsigned int nProcessID);

/** @fn     IMVS_StopExecute_V30
 *  @brief  �㷨ƽ̨�ض�����ֹͣ����ִ��
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  nWaitTime         [IN]       ��ʱʱ��(��λ����)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_StopExecute_V30(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nWaitTime);

/** @fn     IMVS_SetContinousRunInterval_V30
 *  @brief  �����ض�����ʱ����
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  nMilliSecond      [IN]       ��������֮��ʱ����
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetContinousRunInterval_V30(
                      IN const void * const handle,
                      IN const unsigned int nProcessID,
                      IN const unsigned int nMilliSecond);

/** @fn     IMVS_GetModuleListInProcess
 *  @brief  ��ȡ�ض����̵�ǰ����ģ���б�
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  pstModuleInfoList [OUT]      �ض���������ģ����Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuleListInProcess(
                      IN const void * const handle,
                      IN const unsigned int nProcessID,
                      OUT IMVS_MODULE_INFO_LIST * const pstModuleInfoList);

/** @fn     IMVS_AddOneProcess
 *  @brief  ���һ������
 *  @param  handle            [IN]       �������
 *  @param  strDisplayName    [IN]       ����Ĭ����ʾ����
 *  @param  pstPrcInfo        [OUT]      ������Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddOneProcess(IN const void * const handle, IN const char * const strDisplayName, OUT IMVS_PROCESS_INFO * const pstPrcInfo);

/** @fn     IMVS_DeleteOneProcess
 *  @brief  ɾ��һ������
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteOneProcess(IN const void * const handle, IN const unsigned int nProcessID);


/** @fn     IMVS_SetProcName
 *  @brief  ������������
 *  @param  handle             [IN]       �������
 *  @param  nProcessID         [IN]       ����ID
 *  @param  strProcName        [IN]       �������ƣ����ܺ����ʺ���ֺţ�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcName(
                      IN const void * const handle,
                      IN const unsigned int nProcessID,
                      IN const char * const strProcName);

/** @fn     IMVS_SetModuDisplayName
 *  @brief  ����ģ����ʾ����
 *  @param  handle             [IN]       �������
 *  @param  nModuleID          [IN]       ģ��ID
 *  @param  strDisplayName     [IN]       ģ����ʾ���ƣ����ܺ����ʺ���ֺţ�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetModuDisplayName(
                      IN const void * const handle,
                      IN const unsigned int nModuleID,
                      IN const char * const strDisplayName);

/** @fn     IMVS_GetAllProcessList
 *  @brief  ��ȡ��ǰ���������б�
 *  @param  handle             [IN]       �������
 *  @param  pstProcessInfoList [OUT]      ��ǰ���������б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllProcessList(IN const void * const handle,
                                                              OUT IMVS_PROCESS_INFO_LIST * const pstProcessInfoList);

/** @fn     IMVS_GetTakeoverStatus
 *  @brief  ��ȡ�ӹ�״̬
 *  @param  handle             [IN]       �������
 *  @param  pstTakeoverInfo    [OUT]      �ӹ�״̬
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetTakeoverStatus(IN const void * const handle,
                                                              OUT IMVS_STATUS_TAKEOVER_INFO * const pstTakeoverInfo);

/** @fn     IMVS_SetAutoLoadSolution
 *  @brief  �����Զ����ط�����Ϣ��ȷ���Ƿ����ӹܣ�
 *  @param  handle             [IN]       �������
 *  @param  pstAutoLoadInfo    [IN]       �Զ����ط�����Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetAutoLoadSolution(IN const void * const handle,
                                                                IN const IMVS_AUTO_LOAD_SOLUTION_INFO * const pstAutoLoadInfo);

/** @fn     IMVS_GetAutoLoadSolution
 *  @brief  ��ȡ�Զ����ط�����Ϣ
 *  @param  handle             [IN]       �������
 *  @param  pstAutoLoadInfo    [OUT]      �Զ����ط�����Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAutoLoadSolution(IN const void * const handle,
                                                                OUT IMVS_AUTO_LOAD_SOLUTION_INFO * const pstAutoLoadInfo);

/** @fn     IMVS_ShieldProcess
 *  @brief  ��������ȫ�ֿ���
 *  @param  handle             [IN]       �������
 *  @param  nProcessID         [IN]       ����ID
 *  @param  nShieldFlag        [IN]       �Ƿ����α�־
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ShieldProcess(IN const void * const handle,
                                                          IN const unsigned int nProcessID,
                                                          IN const unsigned int nShieldFlag);

/** @fn     IMVS_GetProcedureShieldGlobalCtrl
 *  @brief  ��ȡ����ȫ�ֿ�������״̬
 *  @param  handle             [IN]       �������
 *  @param  nProcessID         [IN]       ����ID
 *  @param  pnShieldFlag       [IN]       ����ȫ�ֿ�������״̬
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcedureShieldGlobalCtrl(IN const void * const handle,
                                                                         IN const unsigned int nProcessID,
                                                                         OUT unsigned int * const pnShieldFlag);

/** @fn     IMVS_GetModuleListByType
 *  @brief  ����ģ�����ͻ�ȡģ���б�
 *  @param  handle             [IN]       �������
 *  @param  pstModuleInfoList  [OUT]      ģ������Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuleListByType(IN const void * const handle, IN const unsigned int nModuleType,
                                                                OUT IMVS_MODULE_BASIC_INFO_LIST * const pstModuleInfoList);


/** @fn     IMVS_GetProcContinousRunInterval
 *  @brief  ��ȡĳһ���̵�����ִ��ʱ����
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  pnMilliSecond     [IN]       ָ��������������֮��ʱ����
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcContinousRunInterval(IN const void * const handle, IN const unsigned int nProcessID,
                                                                        OUT unsigned int * const pnMilliSecond);


/** @fn     IMVS_ShieldModuleCbResult
 *  @brief  ����ģ�����ص�
 *  @param  handle            [IN]       �������
 *  @param  nShiledFlag       [IN]       ���α�־λ��0�����Σ�1�������Σ�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ShieldModuleCbResult(IN const void * const handle, IN const unsigned int nShiledFlag = 0);


/** @fn     IMVS_EnableModule
 *  @brief  ģ����������ù���
 *  @param  handle            [IN]       �������
 *  @param  nModuleID         [IN]       ģ��ID
 *  @param  nEnableFlag       [IN]       ģ�鹦�ܽ��ñ�־λ��0�����ã�1�����ã�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_EnableModule(IN const void * const handle, IN const unsigned int nModuleID, IN const unsigned int nEnableFlag);

/** @fn     IMVS_GetModuleState
 *  @brief  ��ȡģ�����״̬
 *  @param  handle            [IN]       �������
 *  @param  nModuleID         [IN]       ģ��ID
 *  @param  pnModuleState     [OUT]      ģ�����״̬��0�����ã�1�����ã�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuleState(IN const void * const handle, IN const unsigned int nModuleID, OUT unsigned int * const pnModuleState);

/** @fn     IMVS_CopyModuleParam
 *  @brief  ����ģ�����
 *  @param  handle            [IN]       �������
 *  @param  nSrcModuID        [IN]       Դģ��ID
 *  @param  nDstModuID        [IN]       Ŀ��ģ��ID
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CopyModuleParam(IN const void * const handle, IN const unsigned int nSrcModuID, IN const unsigned int nDstModuID);

/** @fn     IMVS_OpenGlobalScriptInteface
 *  @brief  ��ȫ�ֽű��༭����
 *  @param  handle            [IN]       �������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_OpenGlobalScriptInteface(IN const void * const handle);

/** @fn     IMVS_ExecuteOnce4GlobalScript
 *  @brief  ȫ�ֽű�ִ��һ��
 *  @param  handle            [IN]       �������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExecuteOnce4GlobalScript(IN const void * const handle);

/** @fn     IMVS_ContinousRunStart4GlobalScript
 *  @brief  ȫ�ֽű�����ִ�п�ʼ
 *  @param  handle            [IN]       �������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ContinousRunStart4GlobalScript(IN const void * const handle);

/** @fn     IMVS_StopExecute4GlobalScript
 *  @brief  ȫ�ֽű�ִֹͣ��
 *  @param  handle            [IN]       �������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_StopExecute4GlobalScript(IN const void * const handle);

/** @fn     IMVS_SetCustomOutputSubscribeInfo
 *  @brief  �����û��Զ������������Ϣ
 *  @param  handle            [IN]       �������
 *  @param  pstCustomSubInfo  [IN]       �û��Զ������������Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetCustomOutputSubscribeInfo(IN const void * const handle, IN const IMVS_CUSTOM_SUBSCRIBE_INFO * const pstCustomSubInfo);

/** @fn     IMVS_GetCustomOutputSubscribeInfo
 *  @brief  ��ȡ�û��Զ������������Ϣ
 *  @param  handle               [IN]       �������
 *  @param  nProcessID           [IN]       ����ID
 *  @param  nIndexNum            [IN]       ���
 *  @param  pstCustomSubInfoList [IN]       �û��Զ������������Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetCustomOutputSubscribeInfo(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nIndexNum, OUT IMVS_GET_CUSTOM_SUBSCRIBE_INFO_LIST * const pstCustomSubInfoList);

/** @fn     IMVS_ClearCustomOutputInfo
 *  @brief  ���ָ�������������û��Զ����������
 *  @param  handle               [IN]       �������
 *  @param  nProcessID           [IN]       ����ID
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ClearCustomOutputInfo(IN const void * const handle, IN const unsigned int nProcessID);

/** @fn     IMVS_SetParamValue4GlobalScript
 *  @brief  ����ȫ�ֽű�ģ�����
 *  @param  handle                  [IN]       �������
 *  @param  strTranseData           [IN]       ��������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetParamValue4GlobalScript(IN const void * const handle,
																	    IN const char * const strTransData);

/** @fn     IMVS_GetParamValue4GlobalScript
 *  @brief  ��ȡȫ�ֽű�ģ�����
 *  @param  handle                  [IN]       �������
 *  @param  strReqData              [IN]       ��������
 *  @param  nTransDataSize          [IN]       ��Ӧ���ݵķ����С
 *  @param  strValue                [OUT]      ��Ӧ����
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetParamValue4GlobalScript(IN const void * const handle,
																	    IN const char * const strReqData,
																		IN const unsigned int nTransDataSize,
																		OUT char * const strTransData);

/** @fn     IMVS_StartGlobalScript
 *  @brief  ����ȫ�ֽű�ģ�����
 *  @param  handle                  [IN]       �������
 *  @param  nTransDataSize          [IN]       ����ȫ�ֽű����ݵķ����С
 *  @param  strValue                [OUT]      ����ȫ�ֽű�����
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_StartGlobalScript(IN const void * const handle, IN const unsigned int nTransDataSize, OUT char * const strTransData);

/** @fn     IMVS_SetVmRepAddr4GlobalScript
 *  @brief  ����VM����Rep��ַ
 *  @param  handle                  [IN]       �������
 *  @param  strVMRepAddr            [IN]       VM����Rep��ַ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetVmRepAddr4GlobalScript(IN const void * const handle, IN const char * const strVMRepAddr);

/** @fn     IMVS_RegisterOutputPlatformInfoCallBack_V32
 *  @brief  ע��ص�����(�ص��������)
 *  @param  handle                  [IN]        ���
 *  @param  cbOutputPlatformInfo    [IN]        �ص�����
 *  @param  pUser                   [IN]        pUser
 *  @return �ɹ�������CM_OK��ʧ�ܣ����ض�Ӧ������
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_RegisterOutputPlatformInfoCallBack_V32(IN const void * const handle, IN int(__stdcall * cbOutputPlatformInfo)(OUT IMVS_OUTPUT_PLATFORM_INFO * const pstOutputPlatformInfo, IN void * const pUser), IN void * const pUser);

/** @fn     IMVS_CtrlCallBackModuResult
 *  @brief  ��V3.2������ģ�鿪��/ֹͣ�ص���Ϣ
 *  @param  handle                  [IN]       �������
 *  @param  nModuleID               [IN]       ģ��ID
 *  @param  nCallbackStatus         [IN]       �ص�״̬��0��ֹͣ�ص���1�������ص���
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CtrlCallBackModuResult(IN const void * const handle, IN const unsigned int nModuleID, IN const unsigned int nCallbackStatus);

/** @fn     IMVS_SetServerReadyEvent
*  @brief  �����������غ�����¼�(������ɺ;�Ĭִ�����)
*  @param  handle            [IN]       �������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetServerReadyEvent(IN const void * const handle);

/** @fn     IMVS_MakeModulesPrepared
*  @brief  ģ����ԴԤ����ӿ�
*  @param  handle            [IN]       �������
*  @param  pstCamPicInfoList [IN]       ���ͼ��ģ����Ϣ
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_MakeModulesPrepared(IN const void * const handle, IN const IMVS_CAMERA_PIC_INFO_LIST * const pstCamPicInfoList);

/** @fn     IMVS_MakeModulesPreparedBySelfRun
*  @brief  ģ����ԴԤ����ӿ�(ģ����ִ�з�ʽ)
*  @param  handle            [IN]       �������
*  @param  pstCamPicInfoList [IN]       ���ͼ��ģ����Ϣ
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_MakeModulesPreparedBySelfRun(IN const void * const handle, IN const IMVS_CAMERA_PIC_INFO_LIST * const pstCamPicInfoList);

/** @fn     IMVS_SetProcedureRunPolicy
 *  @brief  �����������в��Խӿ�
 *  @param  handle               [IN]       �������
 *  @param  pstProcRunPolicyInfo [IN]       �������в�����Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcedureRunPolicy(IN const void * const handle, IN const IMVS_PROCEDURE_RUN_POLICY * const pstProcRunPolicyInfo);

/** @fn     IMVS_GetProcedureRunPolicy
 *  @brief  ��ȡ�������в��Խӿ�
 *  @param  handle               [IN]       �������
 *  @param  pstProcRunPolicyInfo [IN]       �������в�����Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcedureRunPolicy(IN const void * const handle, OUT IMVS_PROCEDURE_RUN_POLICY * const pstProcRunPolicyInfo);

/** @fn     IMVS_SetProcedureReentrant
*  @brief  �������̿�����ӿ�
*  @param  handle                  [IN]       �������
*  @param  bReentrantEnable        [IN]       ������ʹ��
*  @param  nReentrantNum           [IN]       ����������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcedureReentrant(IN const void * const handle, IN bool bReentrantEnable, IN unsigned int nReentrantNum);

/** @fn     IMVS_GetProcedureReentrant
*  @brief  ��ȡ���̿�����ӿ�
*  @param  handle                     [IN]       �������
*  @param  pbReentrantEnable          [IN]       ������ʹ��
*  @param  pnReentrantNum             [IN]       ����������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcedureReentrant(IN const void * const handle, OUT bool * const pbReentrantEnable, OUT unsigned int * const pnReentrantNum);

/** @fn     IMVS_GetSolutionPath
 *  @brief  ��ȡ����·���ӿ�
 *  @param  handle            [IN]       �������
 *  @param  nPathSize         [IN]       ·����������С
 *  @param  strSolPath        [OUT]      ����·��
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetSolutionPath(IN const void * const handle, IN const unsigned int nPathSize, OUT char * const strSolPath, OUT unsigned int * nRealPathSize = NULL);

/** @fn     IMVS_GetProcessorInfo
 *  @brief  ��ȡ�ײ����ڻ�����������Ϣ�ӿ�
 *  @param  handle            [IN]       �������
 *  @param  pstProcessorInfo  [OUT]      ��������Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcessorInfo(IN const void * const handle, OUT IMVS_PROCESSOR_INFO * const pstProcessorInfo);

/** @fn     IMVS_CopyModuleAlgParam
 *  @brief  ����ģ���㷨����
 *  @param  handle            [IN]       �������
 *  @param  nSrcModuID        [IN]       Դģ��ID
 *  @param  nDstModuID        [IN]       Ŀ��ģ��ID
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CopyModuleAlgParam(IN const void * const handle, IN const unsigned int nSrcModuID, IN const unsigned int nDstModuID);

/** @fn     IMVS_SetDefaultParamList
 *  @brief  ����Ĭ�ϲ����б�
 *  @param  handle            [IN]       �������
 *  @param  nModuleID         [IN]       ģ��ID
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetDefaultParamList(IN const void * const handle, IN const unsigned int nModuleID);

/** @fn     IMVS_AddGroupSonModule
 *  @brief  ���Group��ģ��
 *  @param  handle            [IN]       �������
 *  @param  pstGroupModuInfo  [IN]       Groupģ����Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddGroupSonModule(IN const void * const handle, IN const IMVS_GROUP_MODULE_INFO * const pstGroupModuInfo);

/** @fn     IMVS_RemoveGroupSonModule
 *  @brief  �Ƴ�Group��ģ��
 *  @param  handle            [IN]       �������
 *  @param  pstGroupModuInfo  [IN]       Groupģ����Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_RemoveGroupSonModule(IN const void * const handle, IN const IMVS_GROUP_MODULE_INFO * const pstGroupModuInfo);

/** @fn     IMVS_DeleteGroupModule
 *  @brief  ɾ��Group������ģ��
 *  @param  handle            [IN]       �������
 *  @param  nGroupModuleID    [IN]       Groupģ��ID
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteGroupModule(IN const void * const handle, IN const unsigned int nGroupModuleID);

/** @fn     IMVS_ExportGroupModule
 *  @brief  ����Group
 *  @param  handle            [IN]       �������
 *  @param  nGroupId          [IN]       Groupģ��ID
 *  @param  nGroupLevel       [IN]       ����Group�㼶
 *  @param  strPath           [IN]       Group�ļ�����·��
 *  @param  strPassword       [IN]       Group�ļ����루Ԥ����
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExportGroupModule(IN const void * const handle,
	                                                           IN unsigned int nGroupId,
															   IN unsigned int nGroupLevel,
															   IN const char * const strPath, 
															   IN const char * const strPassword);

/** @fn     IMVS_ExportGroupModule
 *  @brief  ����Group
 *  @param  handle            [IN]       �������
 *  @param  nGroupId          [IN]       Groupģ��ID
 *  @param  nGroupLevel       [IN]       ����Group�㼶
 *  @param  strPath           [IN]       Group�ļ�����·��
 *  @param  strPassword       [IN]       Group�ļ����루Ԥ����
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncExportGroupModule(IN const void * const handle,
	                                                               IN unsigned int nGroupId,
															       IN unsigned int nGroupLevel,
															       IN const char * const strPath, 
															       IN const char * const strPassword);

/** @fn     IMVS_ImportGroupModule
 *  @brief  ����Group
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  nGroupID          [IN]       Group ģ��ID
 *  @param  strPath           [IN]       Group�ļ�����·��
 *  @param  strPassword       [IN]       Group�ļ����루Ԥ����
 *  @param  nIdAllocateWay    [IN]       ID���䷽ʽ (0���Զ�����ID��1�����ļ��е�ID����)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportGroupModule(IN const void * const handle, IN unsigned int nProcessID, IN unsigned int nGroupID, IN const char * const strPath, IN const char * const strPassword, IN const unsigned int nIdAllocateWay);

/** @fn     IMVS_SyncImportGroupModule
 *  @brief  ͬ������Group
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  nGroupID          [IN]       Group ģ��ID
 *  @param  strPath           [IN]       Group�ļ�����·��
 *  @param  strPassword       [IN]       Group�ļ����루Ԥ����
 *  @param  nIdAllocateWay    [IN]       ID���䷽ʽ (0���Զ�����ID��1�����ļ��е�ID����)
 *  @param  pstModuleInfo     [OUT]      ����ģ����Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncImportGroupModule(IN const void * const handle, IN unsigned int nProcessID, IN unsigned int nGroupID, IN const char * const strPath, IN const char * const strPassword, IN const unsigned int nIdAllocateWay, OUT IMVS_MODULE_INFO * const pstModuleInfo);

/** @fn     IMVS_SetGroupIO
 *  @brief  ����Group���������Ϣ
 *  @param  handle            [IN]       �������
 *  @param  pstGroupIOInfoList[IN]       Group���������Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetGroupIO(IN const void * const handle, IN const IMVS_GROUP_IO_INFO_LIST * const pstGroupIOInfoList);

/** @fn     IMVS_BindGlobalVarParam
 *  @brief  ��ȫ�ֱ�������
 *  @param  handle            [IN]       �������
 *  @param  pstGlobalVarInfo  [IN]       ��ȫ�ֱ�����Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_BindGlobalVarParam(IN const void * const handle, IN const IMVS_BIND_GLOBALVAR_PARAM_INFO_LIST * const pstGlobalVarInfo);

/** @fn     IMVS_UnBindGlobalVarParam
 *  @brief  ȡ����ȫ�ֱ�������
 *  @param  handle            [IN]       �������
 *  @param  pstGlobalVarInfo  [IN]       ȡ����ȫ�ֱ�����Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_UnBindGlobalVarParam(IN const void * const handle, IN const IMVS_UNBIND_GLOBALVAR_PARAM_INFO_LIST * const pstGlobalVarInfo);

/** @fn     IMVS_GetBindGlobalVarParam
 *  @brief  ��ȡ��ȫ�ֱ�������
 *  @param  handle            [IN]       �������
 *  @param  nModuleId         [IN]       ȫ�ֱ���ģ��ID
 *  @param  nIndex            [IN]       ��ʼ����
 *  @param  nQueNum           [IN]       ��ѯ����
 *  @param  pstGlobalVarInfo  [OUT]      ��ȫ�ֱ�����Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetBindGlobalVarParam(IN const void * const handle, IN unsigned int nModuleId, IN int nIndex, IN int nQueNum, OUT IMVS_GET_BIND_GLOBALVAR_PARAM_INFO_LIST * const pstGlobalVarInfo);

/** @fn     IMVS_LightSaveSolution
 *  @brief  ���������淽��
 *  @param  handle            [IN]       �������
 *  @param  nRecvWaitTime     [IN]       ���ճ�ʱ����λ��ms��
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_LightSaveSolution(IN const void * const handle, IN const unsigned int nRecvWaitTime);

/** @fn     IMVS_NotifyLoadSolutionEnd
 *  @brief  ������֪ͨ���ط�������
 *  @param  handle            [IN]       �������
 *  @param  nClientType       [IN]       �ͻ���
 *  @param  nErrorCode        [IN]       ������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_NotifyLoadSolutionEnd(IN const void * const handle, IN unsigned int nClientType, IN int nErrorCode);

/** @fn     IMVS_ExportProcess
 *  @brief  ��������
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  strExportPath     [IN]       ����·��
 *  @param  strPassword       [IN]       �ļ�����(Ԥ��)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExportProcess(IN const void * const handle, 
														   IN const unsigned int nProcessID,
														   IN const char * const strExportPath,
														   IN const char * const strPassword);

/** @fn     IMVS_SyncExportProcess
 *  @brief  ��������
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  strExportPath     [IN]       ����·��
 *  @param  strPassword       [IN]       �ļ�����(Ԥ��)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncExportProcess(IN const void * const handle, 
															IN const unsigned int nProcessID,
															IN const char * const strExportPath,
															IN const char * const strPassword);

/** @fn     IMVS_ImportProcess
 *  @brief  ��������
 *  @param  handle            [IN]       �������
 *  @param  strProcessPath    [IN]       ���������ļ�·��
 *  @param  strPassword       [IN]       �ļ�����
 *  @param  nIsIgnoreGlobal   [IN]       �Ƿ����ȫ��ģ�� (1�����������ļ��е�ȫ��ģ�飬0��������ͬȫ��ģ������)
 *  @param  nIdAllocateWay    [IN]       ID���䷽ʽ (0���Զ�����ID��1�����ļ��е�ID����)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportProcess(IN const void * const handle, 
														   IN const char * const strProcessPath,
														   IN const char * const strPassword,
														   IN const unsigned int nIsIgnoreGlobal,
														   IN const unsigned int nIdAllocateWay
														   );

/** @fn     IMVS_SyncImportProcess
 *  @brief  ��������
 *  @param  handle            [IN]       �������
 *  @param  strProcessPath    [IN]       ���������ļ�·��
 *  @param  strPassword       [IN]       �ļ�����
 *  @param  nIsIgnoreGlobal   [IN]       �Ƿ����ȫ��ģ�� (1�����������ļ��е�ȫ��ģ�飬0��������ͬȫ��ģ������)
 *  @param  nIdAllocateWay    [IN]       ID���䷽ʽ (0���Զ�����ID��1�����ļ��е�ID����)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SyncImportProcess(IN const void * const handle,
															   IN const char * const strProcessPath,
															   IN const char * const strPassword,
															   IN const unsigned int nIsIgnoreGlobal,
															   IN const unsigned int nIdAllocateWay,
															   OUT IMVS_PROCESS_INFO * const pstProcessInfo);

/** @fn     IMVS_SendProcRunParam
 *  @brief  �����������в���
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  nStopNGAction     [IN]       ����NGʱֹͣ����, (1: ��; 0: ��)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcRunParam(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nStopNGAction);

/** @fn     IMVS_GetProcRunParam
 *  @brief  ��ȡ�������в���
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  pnStopNGAction    [OUT]      ����NGʱֹͣ����, (1: ��; 0: ��)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcRunParam(IN const void * const handle, IN const unsigned int nProcessID, OUT unsigned int * const pnStopNGAction);


/** @fn     IMVS_SetMaxModuleNum
*  @brief  ����ģ����������
*  @param  handle            [IN]       �������
*  @param  nMaxModuleNum    [IN]      ���ģ������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetMaxModuleNum(IN const void * const handle, IN const unsigned int nMaxModuleNum);


/** @fn     IMVS_GetObjectLimits
 *  @brief  ��ȡ������ģ����������
 *  @param  handle            [IN]       �������
 *  @param  pnMaxProcessNum   [OUT]      �����������
 *  @param  pnMaxModuleNum    [OUT]      ���ģ������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetObjectLimits(IN const void * const handle, OUT unsigned int * const pnMaxProcessNum, OUT unsigned int * const pnMaxModuleNum);

/** @fn     IMVS_SetUIParamValue
 *  @brief  ���ö���������
 *  @param  handle            [IN]       �������
 *  @param  nObjectID         [IN]       ����ID
 *  @param  strParamName      [IN]       �����������
 *  @param  pData             [IN]       �����������
 *  @param  nDataLen          [IN]       ����������ݳ���
 *  @param  nRecvWaitTime     [IN]       ���ճ�ʱ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetUIParamValue(IN const void * const handle, IN const unsigned int nObjectID, IN const char * const strParamName, IN const char * const pData, IN const unsigned int nDataLen, IN const unsigned int nRecvWaitTime);

/** @fn     IMVS_GetUIParamValueByKey
 *  @brief  ���ݶ���Key��ȡ����������ֵ�����ݿ�����ʹ�ýӿ��ͷ�ָ��-IMVS_ReleaseDynamicMemory
 *  @param  handle            [IN]       �������
 *  @param  nObjectID         [IN]       ����ID
 *  @param  strParamName      [IN]       �����������
 *  @param  pData             [OUT]      �����������
 *  @param  pnDataLen         [OUT]      ����������ݳ���
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetUIParamValueByKey(IN const void * const handle, IN const unsigned int nObjectID, IN const char * const strParamName, OUT char *& pData, OUT unsigned int * const pnDataLen, IN const unsigned int nRecvWaitTime);

/** @fn     IMVS_GetUIParamValueByObject
 *  @brief  �������ȡ����������ֵ�����ݿ�����ʹ�ýӿ��ͷ�ָ��-IMVS_ReleaseDynamicMemory
 *  @param  handle            [IN]       �������
 *  @param  nObjectID         [IN]       ����ID
 *  @param  pstUIObjParamInfoList [OUT]  ������������б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetUIParamValueByObject(IN const void * const handle, IN const unsigned int nObjectID, OUT IMVS_UI_OBJECT_PARAM_INFO_LIST *& pstUIObjParamInfoList);

/** @fn     IMVS_GetFirstLayerModuleTree
 *  @brief  ��ȡ��һ�㼶�����ڲ���ģ����
 *  @param  handle              [IN]     �������
 *  @param  nObjectID           [IN]     ������ID
 *  @param  pstNodeTreeInfoList [OUT]    ģ������Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetFirstLayerModuleTree(IN const void * const handle, IN const unsigned int nObjectID, IN const unsigned int nObjectType, OUT IMVS_NODE_TREE_INFO * const pstNodeTreeInfoList);

/** @fn     IMVS_GetModuleConnectInProc
 *  @brief  ��ȡ��һ�㼶������ģ�����ӹ�ϵ
 *  @param  handle                 [IN]     �������
 *  @param  nObjectID              [IN]     ������ID
 *  @param  pstModuConnectInfoList [OUT] ģ��������Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetFirstLayerModuleConnect(IN const void * const handle, IN const unsigned int nObjectID, IN const unsigned int nObjectType, OUT IMVS_MODULE_CONNECT_INFO_LIST *& pstModuConnectInfoList);

/** @fn     IMVS_GetFirstLayerModuleSubscribe
 *  @brief  ��ȡ��һ�㼶������ģ�鶩�Ĺ�ϵ
 *  @param  handle              [IN]     �������
 *  @param  nObjectID           [IN]     ������ID
 *  @param  pstModuSubInfoList  [OUT]    ģ�鶩����Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetFirstLayerModuleSubscribe(IN const void * const handle, IN const unsigned int nObjectID, IN const unsigned int nObjectType, OUT IMVS_MODULE_SUBSCRIBE_INFO_LIST *& pstModuSubInfoList);

/** @fn     IMVS_ReleaseUIParamData
 *  @brief  �ͷŻ�ȡ�����ڴ�
 *  @param  handle              [IN]     �������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ReleaseUIParamData(IN const void * const handle);

/** @fn     IMVS_SetReportModuleResult
 *  @brief  �ϴ�ָ��ģ����
 *  @param  handle                [IN]     �������
 *  @param  pstReportModuInfoList [IN]    ָ��ģ�����б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetReportModuleResult(IN const void * const handle, IN const IMVS_REPORT_MODULE_RES_INFO_LIST * const pstReportModuInfoList);
/** @fn     IMVS_SetReportModuleResult_V2
*  @brief  ���ο�������ص������ȼ�����IMVS_SetReportModuleResult��
*  @param  handle                [IN]     �������
*  @param  nMode                 [IN]     ����ģʽ
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetReportModuleResult_V2(IN const void * const handle, IN const E_REPORT_RESULT_TYPE nMode, IN const unsigned int nModuId = 0, IN const bool bIsEnable = false);

/** @fn     IMVS_SetAllReportModuleResult
 *  @brief  �ϴ�����ģ����
 *  @param  handle                [IN]     �������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetAllReportModuleResult(IN const void * const handle);

/** @fn     IMVS_SetNoneReportModuleResult
 *  @brief  ���ϴ�ģ����
 *  @param  handle                [IN]     �������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetNoneReportModuleResult(IN const void * const handle);

/** @fn    IMVS_KeepModuleLastResult
*  @brief  ����ģ���ϴν��
*  @param  handle                [IN]     �������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_KeepModuleLastResult(IN const void * const handle, IN const unsigned int nModuleID, IN bool bIsUnchanged);

/** @fn     IMVS_QueryModuleRunningState
*  @brief  ��ѯģ����ʷ״̬�����ݿ�����ʹ�ýӿ��ͷ�ָ��-IMVS_ReleaseDynamicMemory
*  @param  handle                  [IN]     �������
*  @param  pastModuleId            [IN]     ģ��ID�б�
*  @param  pstQueryModuStaInfoList [OUT]    ��ѯģ����ʷ״̬��Ϣ�б�
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_QueryModuleRunningState(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pastModuleId, OUT IMVS_REPORT_MODULE_STATUS_INFO_LIST *& pstQueryModuStaInfoList);

/** @fn     IMVS_QueryModuleHistoryResult
 *  @brief  ��ѯģ����ʷ���
 *  @param  handle                  [IN]     �������
 *  @param  nModuleID               [IN]     ģ��ID
 *  @param  nIndex                  [IN]     ����
 *  @param  nResultNum              [IN]     ������������40����
 *  @param  pstQueryModuResInfoList [OUT]    ��ѯģ����ʷ�����Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
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
 *  @brief  ��ȡģ�鵼�����ݣ����ݿ�����ʹ�ýӿ��ͷ�ָ��-IMVS_ReleaseDynamicMemory
 *  @param  handle                  [IN]     �������
 *  @param  nModuleID               [IN]     ģ��ID
 *  @param  strModuDisplayName      [IN]     ģ����ʾ����
 *  @param  nWaitTime               [IN]     ��ʱʱ��
 *  @param  pstModuExportData       [OUT]    ģ�鵼������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuleExportData(IN const void * const handle,
																 IN const unsigned int nModuleID,
																 IN const char * const strModuDisplayName,
																 IN const unsigned int nWaitTime,
																 OUT IMVS_EXPORT_MODULE_DATA_INFO *& pstModuExportData);

/** @fn     IMVS_ImportModuleDataEx
 *  @brief  ����ģ������
 *  @param  handle                  [IN]     �������
 *  @param  pstModuImportData       [IN]     ģ�鵼��������Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportModuleDataEx(IN const void * const handle, IN const IMVS_IMPORT_MODULE_DATA_INFO * const pstModuImportData, OUT IMVS_MODULE_INFO * const pstModuleInfo);

/** @fn     IMVS_DeleteUIParamValue
 *  @brief  ɾ������������
 *  @param  handle            [IN]       �������
 *  @param  nObjectID         [IN]       ����ID
 *  @param  strParamName      [IN]       �����������
 *  @param  nBlurDelete       [IN]       �Ƿ�ģ��ɾ����0����1���ǣ�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteUIParamValue(IN const void * const handle, IN const unsigned int nObjectID, IN const char * const strParamName, IN const unsigned int nBlurDelete);

/** @fn     IMVS_ExportMultiModuleData
 *  @brief  �������ģ�����ݣ����ݿ�����ʹ�ýӿ��ͷ�ָ��-IMVS_ReleaseDynamicMemory
 *  @param  handle            [IN]       �������
 *  @param  pastModuleId      [IN]       ����ģ��ID�б�
 *  @param  nWaitTime         [IN]       �ȴ���ʱ
 *  @param  pData             [OUT]      ��������
 *  @param  pnDataLen         [OUT]      �������ݳ���
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExportMultiModuleData(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pastModuleId, IN const unsigned int nWaitTime, OUT IMVS_EXPORT_MODULE_DATA_INFO *& pstModuExportData);

/** @fn     IMVS_ImportMultiModuleData
 *  @brief  ������ģ������
 *  @param  handle               [IN]       �������
 *  @param  pastModuleImportData [IN]       ����ģ��������Ϣ
 *  @param  pstModuleInfoList    [OUT]      ģ��ע����Ϣ�б�
 *  @param  pstImportNodeList    [OUT]      ģ�鸸����Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportMultiModuleData(IN const void * const handle, IN const IMVS_IMPORT_MODULE_LIST_DATA_INFO * const pastModuleImportData, OUT IMVS_MODULE_INFO_LIST * const pstModuleInfoList, OUT IMVS_IMPORT_NODE_LIST * const pstImportNodeList);

/** @fn     IMVS_GetMultiModuleConnect
 *  @brief  ��ȡ���ģ�����ӹ�ϵ�����ݿ�����ʹ�ýӿ��ͷ�ָ��-IMVS_ReleaseDynamicMemory
 *  @param  handle                 [IN]       �������
 *  @param  pastModuleId           [IN]       ģ��ID�б�
 *  @param  pstModuConnectInfoList [OUT]      ģ�����ӹ�ϵ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetMultiModuleConnect(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pastModuleId, OUT IMVS_MODULE_CONNECT_INFO_LIST *& pstModuConnectInfoList);

/** @fn     IMVS_GetMultiModuleSubscribe
 *  @brief  ��ȡ���ģ�鶩�Ĺ�ϵ�����ݿ�����ʹ�ýӿ��ͷ�ָ��-IMVS_ReleaseDynamicMemory
 *  @param  handle                 [IN]       �������
 *  @param  pastModuleId           [IN]       ģ��ID�б�
 *  @param  pstModuSubInfoList     [OUT]      ģ�����ӹ�ϵ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetMultiModuleSubscribe(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pastModuleId, OUT IMVS_MODULE_SUBSCRIBE_INFO_LIST *& pstModuSubInfoList);

/** @fn     IMVS_GetAllGlobalModule
 *  @brief  ��ȡ����ȫ��ģ��
 *  @param  handle                [IN]       �������
 *  @param  pstModuleInfoList     [OUT]      ȫ��ģ���б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllGlobalModule(IN const void * const handle, OUT IMVS_MODULE_INFO_LIST * const pstModuleInfoList);

/** @fn     IMVS_GetSolModifyInfo
 *  @brief  ��ȡ�����޸���Ϣ
 *  @param  handle            [IN]       �������
 *  @param  pnSolModify       [OUT]      �����Ƿ��޸� (1�����޸ģ�0�����޸�)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetSolModifyInfo(IN const void * const handle, OUT unsigned int * const pnSolModify);

/** @fn     IMVS_FuzzyQueryUIParamValue
 *  @brief  ģ����ѯ���������������ݿ�����ʹ�ýӿ��ͷ�ָ��-IMVS_ReleaseDynamicMemory
 *  @param  handle            [IN]       �������
 *  @param  pstModuList       [IN]       ����ID�б�
 *  @param  strParamName      [IN]       �����������
 *  @param  bIsFuzzyQuery     [IN]       �Ƿ�ģ����ѯ
 *  @param  pUiParamInfoList  [OUT]      ������������б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_FuzzyQueryUIParamValue(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pstModuList, IN const char * const strParamName, IN const bool bIsFuzzyQuery, OUT IMVS_UIPARAM_INFO_LIST *& pUiParamInfoList);

/** @fn     IMVS_DeleteAllUIParamValue
 *  @brief  ɾ���������н������
 *  @param  handle            [IN]       �������
 *  @param  nObjectID         [IN]       ����ID
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteAllUIParamValue(IN const void * const handle, IN const unsigned int nObjectID);

/** @fn    IMVS_SetSolModifyFlag
*  @brief  ���õ�ǰ�����Ƿ��޸ı��
*  @param  handle            [IN]       �������
*  @param  nModifyFlag       [IN]       �޸ı��
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetSolModifyFlag(IN const void * const handle, IN const unsigned int nModifyFlag);

/** @fn    IMVS_QueryIOBeSubscribed
*  @brief  ��ѯIO��������Ϣ�����ݿ�����ʹ�ýӿ��ͷ�ָ��-IMVS_ReleaseDynamicMemory
*  @param  handle            [IN]       �������
*  @param  nModuleId         [IN]       ģ��ID
*  @param  strIOName         [IN]       IO����
*  @param  pstIOSubInfoList  [OUT]      IO������Ϣ
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_QueryIOBeSubscribed(IN const void * const handle, 
    IN const unsigned int nModuleId, IN const char * const strIOName, 
    IN IMVS_IO_BE_SUBSCRIBED_TYPE eIoBeSubscribedType, 
    OUT IMVS_MODULE_SUBSCRIBE_INFO_LIST *& pstIOSubInfoList);

/** @fn    IMVS_DeleteIOBeSubscribedByPrams
*  @brief  ɾ��IO������������Ϣ
*  @param  handle            [IN]       �������
*  @param  nModuleId         [IN]       ģ��ID
*  @param  strIOName         [IN]       IO����
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteIOBeSubscribedByParams(IN const void * const handle, IN const unsigned int nModuleId, IN const char * const strIOName);


/** @fn    IMVS_ClearModuleHistoryResult
*  @brief  ���ģ����ʷ�����Ϣ
*  @param  handle            [IN]       �������
*  @param  nModuleId         [IN]       ģ��ID
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ClearModuleHistoryResult(IN const void * const handle, IN const unsigned int nModuleId);

/** @fn    IMVS_GetAllProcedureShieldState
*  @brief  ��ȡ������������״̬
*  @param  handle            [IN]       �������
*  @param  pnShieldFlag      [OUT]      ����״̬
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllProcedureShieldState(IN const void * const handle, OUT unsigned int * const pnShieldFlag);

/** @fn    IMVS_GetMultiModuEnableState
 *  @brief  ��ȡ���ģ�����״̬
 *  @param  handle            [IN]       �������
 *  @param  pstModuList       [IN]       ģ��ID�б�
 *  @param  pstModuStateInfo  [OUT]      ģ��״̬�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetMultiModuEnableState(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pstModuList, OUT IMVS_MODULE_STATE_LIST * const pstModuStateInfo);

/** @fn    IMVS_GetMultiObjectLoadState
*  @brief  ��ȡ���Ŀ�����״̬�����������̡�Group��ģ�飬0:δ���أ�1���Ѽ��أ�2���ڲ�����δ����
*  @param  handle            [IN]       �������
*  @param  pstModuList       [IN]       ģ��ID�б�
*  @param  pstModuStateInfo  [OUT]      ģ��״̬�б�
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetMultiObjectLoadState(IN const void * const handle, IN const IMVS_MODULE_ID_LIST * const pstModuList, OUT IMVS_MODULE_STATE_LIST * const pstModuStateInfo);

/** @fn    IMVS_GetAutoSaveSolState
 *  @brief  ��ȡ�Զ����淽��״̬��Ϣ
 *  @param  handle            [IN]       �������
 *  @param  pnStatus          [OUT]      �Զ����淽��״̬��1��������0���رգ�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAutoSaveSolState(IN const void * const handle, OUT unsigned int * const pnStatus);

/** @fn    IMVS_SetAutoSaveSolState
 *  @brief  �����Զ����淽��״̬��Ϣ
 *  @param  handle            [IN]       �������
 *  @param  nStatus           [IN]      �Զ����淽��״̬��1��������0���رգ�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetAutoSaveSolState(IN const void * const handle, IN const unsigned int nStatus);

/** @fn    IMVS_LightSaveSolutionEx
 *  @brief  �ͻ����������淽���ӿ�
 *  @param  handle            [IN]       �������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_LightSaveSolutionEx(IN const void * const handle);

/** @fn    IMVS_GetThirdSoftwareInfo
 *  @brief  ��ȡ�����������Ϣ�ӿ�
 *  @param  handle               [IN]       �������
 *  @param  pstThirdSoftwareInfo [OUT]      �����������Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetThirdSoftwareInfo(IN const void * const handle, OUT IMVS_THIRD_SOFTWARE_INFO_LIST * const pstThirdSoftwareInfo);

/** @fn     IMVS_SetProcedureIO
 *  @brief  ����Procedure���������Ϣ
 *  @param  handle            [IN]       �������
 *  @param  pstPrcIOInfoList  [IN]       Procedure���������Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcedureIO(IN const void * const handle, IN const IMVS_PROCEDURE_IO_INFO_LIST * const pstPrcIOInfoList);

/** @fn    IMVS_SetModuInputIOInfo
 *  @brief  ����ģ������IO��Ϣ
 *  @param  handle            [IN]       �������
 *  @param  nModuId           [IN]       ģ��ID
 *  @param  pstModuIOInfo     [IN]      ģ��IO��Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetModuInputIOInfo(IN const void * const handle, IN const unsigned int nObjectId, IN const IMVS_MODULE_IO_INFO_LIST * const pstModuInfoList);

/** @fn    IMVS_SetModuOutputIOInfo
 *  @brief  ����ģ�����IO��Ϣ
 *  @param  handle            [IN]       �������
 *  @param  nModuId           [IN]       ģ��ID
 *  @param  pstModuIOInfo     [IN]       ģ��IO��Ϣ�б�
 *  @param  pstDisplayModuInfo[IN]       ģ��IOչʾ��Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetModuOutputIOInfo(IN const void * const handle, IN const unsigned int nObjectId, IN const IMVS_MODULE_IO_INFO_LIST * const pstModuInfoList);

/** @fn    IMVS_GetModuInputIOInfo
 *  @brief  ��ȡģ������IO��Ϣ
 *  @param  handle            [IN]       �������
 *  @param  nModuId           [IN]       ģ��ID
 *  @param  pstModuIOInfo     [OUT]      ģ��IO��Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuInputIOInfo(IN const void * const handle, IN const unsigned int nModuId, OUT IMVS_MODULE_IO_INFO_LIST *& pstModuIOInfo);

/** @fn    IMVS_GetModuOutputIOInfo
 *  @brief  ��ȡģ�����IO��Ϣ
 *  @param  handle            [IN]       �������
 *  @param  nModuId           [IN]       ģ��ID
 *  @param  nDataType         [IN]       �������ͣ�2: ���, 3: ��ʾ��
 *  @param  pstModuIOInfo     [OUT]      ģ��IO��Ϣ�б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuOutputIOInfo(IN const void * const handle, IN const unsigned int nModuId, IN const unsigned int nDataType, OUT IMVS_MODULE_IO_INFO_LIST *& pstModuIOInfo);

/** @fn    IMVS_SetProcRelatedWithGlobal
 *  @brief  ���������̹�����ȫ��ģ��
 *  @param  handle               [IN]       �������
 *  @param  nProcID              [IN]       ����ID
 *  @param  pstRelateGlobalIDList[IN]       ����ȫ��ģ���б�
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcRelatedWithGlobal(IN const void * const handle, IN const unsigned int nProcID, IN const IMVS_RELATED_GLOBAL_MODU_ID_LIST * const pstRelateGlobalIDList);

/** @fn    IMVS_DeleteProcRelated
 *  @brief  ��������������̹�����ȫ��ģ��
 *  @param  handle               [IN]       �������
 *  @param  nProcID              [IN]       ����ID
 *  @param  eRelatedType         [IN]       ����ȫ��ģ������
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteProcRelated(IN const void * const handle, IN const unsigned int nProcID, IN const IMVS_RELATED_TYPE eRelatedType);

/** @fn    IMVS_GetProcRelatedInfo
 *  @brief  ��ȡȫ��ģ����Ϣ�ӿ�
 *  @param  handle               [IN]       �������
 *  @param  pstThirdSoftwareInfo [OUT]      �����������Ϣ
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcRelatedInfo(IN const void * const handle, IN const unsigned int nProcID, OUT IMVS_RELATED_GLOBAL_MODU_INFO_LIST * const pstRelateGlobalIDList);

/** @fn     IMVS_ExportMultiProcess
 *  @brief  �����������
 *  @param  handle            [IN]       �������
 *  @param  pstProcIdList     [IN]       ����ID�б�
 *  @param  strExportPath     [IN]       ����·��
 *  @param  strPassword       [IN]       �ļ�����(Ԥ��)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ExportMultiProcess(IN const void * const handle,
																IN const IMVS_PROCESS_ID_LIST * const pstProcIdList,
															    IN const char * const strExportPath,
															    IN const char * const strPassword);

/** @fn     IMVS_ImportMultiProcess
 *  @brief  ����������
 *  @param  handle            [IN]       �������
 *  @param  strProcessPath    [IN]       ���������ļ�·��
 *  @param  strPassword       [IN]       �ļ�����
 *  @param  nIsIgnoreGlobal   [IN]       �Ƿ����ȫ��ģ�� (1�����������ļ��е�ȫ��ģ�飬0��������ͬȫ��ģ������)
 *  @param  nIdAllocateWay    [IN]       ID���䷽ʽ (0���Զ�����ID��1�����ļ��е�ID����)
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ImportMultiProcess(IN const void * const handle,
															    IN const char * const strProcessPath,
															    IN const char * const strPassword,
															    IN const unsigned int nIsIgnoreGlobal,
															    IN const unsigned int nIdAllocateWay);
/** @fn     IMVS_GetPrcVersion
 *  @brief  ��ȡ�����ļ��汾
*  @param  handle                 [IN]     �������
*  @param  strPath                [IN]     ����·��
*  @param  strPassWord            [IN]     ��������
*  @param  pstFileVersionInfo     [OUT]    �汾��Ϣ
*  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetPrcVersion(IN const void * const handle,
														   IN const char * const strPath,
														   IN const char * const strPassWord,
														   OUT IMVS_FILE_VERSION_INFO * pstFileVersionInfo);

/** @fn     IMVS_GetGroVersion
*  @brief  ��ȡGroup�ļ��汾
*  @param  handle                 [IN]     �������
*  @param  strPath                [IN]     ����·��
*  @param  strPassWord            [IN]     ��������
*  @param  pstFileVersionInfo     [OUT]    �汾��Ϣ
*  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetGroVersion(IN const void * const handle,
														   IN const char * const strPath,
														   IN const char * const strPassWord,
														   OUT IMVS_FILE_VERSION_INFO * pstFileVersionInfo);

/** @fn     IMVS_SetModuleParamBinding
 *  @brief  ��ģ�������ؼ��ֲ������
 *  @param  handle                 [IN]     �������
 *  @param  pstModuParamInfo       [IN]     �󶨲����б�
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetModuleParamBinding(IN const void * const handle, IN const IMVS_BIND_MODULE_PARAM_INFO_LIST * const pstModuParamInfo);

/** @fn     IMVS_DelModuleParamBinding
 *  @brief  ɾ��ģ��ؼ��ֲ�����ģ������İ󶨹�ϵ
 *  @param  handle                 [IN]     �������
 *  @param  pstModuParamInfo       [IN]     �󶨲����б�
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DelModuleParamBinding(IN const void * const handle, IN const IMVS_UNBIND_MODULE_PARAM_INFO_LIST * const pstModuParamInfo);

/** @fn     IMVS_GetModuleParamBindingList
 *  @brief  ��ѯģ��ؼ��ֲ�����ģ������İ󶨹�ϵ
 *  @param  handle           [IN]     �������
 *  @param  nModuleId        [IN]     ģ��ID
 *  @param  nIndex           [IN]     ��ѯ����
 *  @param  nQueNum          [IN]     ��ѯ����
 *  @param  pstModuParamInfo [OUT]    �󶨲����б�
 *  @return �ɹ�,����IMVS_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetModuleParamBindingList(IN const void * const handle, 
																	   IN unsigned int nModuleId, 
																	   IN int nIndex, 
																	   IN int nQueNum, 
																	   OUT IMVS_GET_BIND_MODULE_PARAM_INFO_LIST * const pstModuParamInfo);

/** @fn     IMVS_SetProcedureWaitTime
 *  @brief  �����ض����̳�ʱʱ��
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  nWaitTime         [IN]       ���̳�ʱʱ��
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetProcedureWaitTime(IN const void * const handle, IN const unsigned int nProcessID, IN const unsigned int nWaitTime);

/** @fn     IMVS_GetProcedureWaitTime
 *  @brief  ��ȡ�ض����̳�ʱʱ��
 *  @param  handle            [IN]       �������
 *  @param  nProcessID        [IN]       ����ID
 *  @param  pnWaitTime        [OUT]      ���̳�ʱʱ��
 *  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
 */
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetProcedureWaitTime(IN const void * const handle, IN const unsigned int nProcessID, OUT unsigned int * const pnWaitTime);

#pragma region FTP������ؽӿ�
/****************************************************************************
*  @fn     IMVS_FtpInit
*  @brief  ���Ӳ���¼Զ��FTPServer
*  @param  strHost                 [IN]       Զ��IP
*  @param  uPort                   [IN]       Զ�̶˿�
*  @param  strLogin                [IN]       ��¼����
*  @param  strPassword             [IN]       ����
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpInit(IN const void * const handle, IN const char* const strHost, IN const unsigned int uPort, IN const char* const strLogin, IN const char* const strPassword);

/****************************************************************************
*  @fn     IMVS_FtpDownloadFile
*  @brief  ��Զ�����ص����ļ�������
*  @param  strOutputfile           [IN]       ���ر���·��
*  @param  strPath                 [IN]       Զ���ļ�·��
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpDownloadFile(IN const void * const handle, IN const char * const strOutputfile, IN const char * const strPath, IN bool bCover = false);

/****************************************************************************
*  @fn     IMVS_FtpDownloadDir
*  @brief  ��Զ�����������ļ��е�����
*  @param  strLocalDir           [IN]       ���ر���·��
*  @param  strRemoteDir          [IN]       Զ���ļ���·��
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpDownloadDir(IN const void * const handle, IN const char * const strLocalDir, IN const char * const strRemoteDir, IN bool bCover = false);

/****************************************************************************
*  @fn     IMVS_FtpUploadFile
*  @brief  �ӱ����ϴ������ļ���Զ��ָ��Ŀ¼
*  @param  strInputfile            [IN]       �����ļ�·��
*  @param  strPath                 [IN]       Զ��·��
*  @param  isCreatDir              [IN]       �����ļ���
*  @param  isCover                 [IN]       ����ͬ���ļ�
*  @return ������,����true;����,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpUploadFile(IN const void * const handle, IN const char * const strInputfile, IN const char * const strPath, IN bool isCreatDir = true, IN bool bCover = false);

/****************************************************************************
*  @fn     IMVS_FtpUploadDir
*  @brief  �ӱ����ϴ������ļ��е�Զ��Ŀ¼
*  @param  strLocalDir           [IN]       �����ļ���·��
*  @param  strRemoteDir          [IN]       Զ��Ŀ¼
*  @param  isCover               [IN]       ����ͬ���ļ�
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpUploadDir(IN const void * const handle, IN const char * const strLocalDir, IN const char * const strRemoteDir, IN bool bCover = false);

/****************************************************************************
*  @fn     IMVS_FtpCheckFileName
*  @brief  ���Զ��ָ��Ŀ¼���Ƿ���������ļ�
*  @param  strPath                 [IN]       Զ���ļ�·��
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpCheckFileName(IN const void * const handle, IN const char * const strPath);

/****************************************************************************
*  @fn     IMVS_FtpCreateDir
*  @brief  ��Զ���ϴ���Ŀ¼���������༶Ŀ¼
*  @param  strNewDir            [IN]       Ҫ������Ŀ¼·��
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpCreateDir(IN const void * const handle, IN const char * const strNewDir);

/****************************************************************************
*  @fn     FM_RemoveDir
*  @brief  �Ƴ�Զ���ϵ��ļ�
*  @param  strRemoteFile            [IN]       Ҫ�Ƴ����ļ�
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpRemoveFile(IN const void * const handle, IN const char * const strRemoteFile);

/****************************************************************************
*  @fn     FM_RemoveDir
*  @brief  �Ƴ�Զ���ϵ��ļ��У�������ɾ���༶Ŀ¼
*  @param  strRemoteDir            [IN]       Ҫ�Ƴ����ļ���
*  @param  bOnlyEmptyDir           [IN]       true:ֻ����ɾ����Ŀ¼��false:����ɾ���ǿ�Ŀ¼
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpRemoveDir(IN const void * const handle, IN const char * const strRemoteDir, IN bool bOnlyEmptyDir = true);

/****************************************************************************
*  @fn     IMVS_FtpRename
*  @brief  ������Զ���ļ�/�ļ���
*  @param  strOldName            [IN]       ԭ����
*  @param  strNewName            [IN]       ������
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpRename(IN const void * const handle, IN const char * const strOldName, IN const char * const strNewName);

///****************************************************************************
//*  @fn     FM_FileInfo
//*  @brief  ��ȡԶ���ϵĵ����ļ���Ϣ
//*  @param  strRemoteFile            [IN]       �ļ�·��
//*  @return �ɹ�,����true;ʧ��,����false
//****************************************************************************/
//IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpFileInfo(IN const void * const handle, IN const char * const strRemoteFile, OUT FileInfo* const oFileInfo);

/****************************************************************************
*  @fn     FM_RemoteList
*  @brief  ��ȡԶ���ϵĵ����ļ�����Ϣ
*  @param  strRemoteFolder            [IN]       Զ���ļ���
*  @param  strList                    [IN]       �ļ�����Ϣ
*  @param  bOnlyName                  [IN]       �Ƿ�ֻ��ȡ����
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpRemoteList(IN const void * const handle, IN const char * const strRemoteFolder, OUT int *nDataLength, OUT char * const strList, IN bool bOnlyName = false);

/****************************************************************************
*  @fn     FM_RemoteList
*  @brief  ��ȡԶ���ϵĵ����ļ�����Ϣ
*  @param  strRemoteFolder            [IN]       Զ���ļ���
*  @param  nDataLength                [OUT]      ��Ϣ����
*  @param  struFTPFileInfo            [OUT]      �ļ������ļ���Ϣ
*  @param  bOnlyName                  [IN]       �Ƿ�ֻ��ȡ����
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpRemoteFileList(IN const void * const handle, IN const char * const strRemoteFolder, OUT IMVS::FTP::RemoteFileListInfo *struFTPFileInfo, IN bool bOnlyName = false);

/****************************************************************************
*  @fn     IMVS_FtpDeInit
*  @brief  �Ͽ�����
*  @return �ɹ�,����true;ʧ��,����false
****************************************************************************/
IMVS_6000_PLATFORMSDK_API bool __stdcall IMVS_FtpDeInit(IN const void * const handle);

/** @fn     IMVS_SetFilePathFromWindows
*  @brief  ��windows�µ��ļ����ݵ�linux���ϲ㴫������ļ�·��
*  @brief  ���nOutPathSizeΪ0����ӿڻ�����ļ�������Ȼ�󴫵ݵ�ģ��
*  @brief  ���nOutPathSizeΪ��0����ͨ��FTP�ϴ��ļ���linux��Ȼ���linux·����ģ�飬ͬʱ��linux�е�·����������
*  @param  handle                  [IN]        ���
*  @param  pInFile                 [IN]        �����windows�ļ�·��
*  @param  pParamName              [IN]        ����ģ�����ʱ�Ĳ������ƣ����û�п�����NULL���������ã�
*  @param  nModuleID               [IN]        ����ģ�����ʱģ��ID
*  @param  pOutFilePath            [OUT]       ����ļ���Ҫ�ϴ���linux������߻ḳֵliunx�ļ�·��
*  @param  nOutPathSize            [IN]        ������ΪpOutFilePath����ĳ��ȣ�Ĭ��Ϊ0
*  @return �ɹ�������CM_OK��ʧ�ܣ����ض�Ӧ������
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetFilePathFromWindows(IN const void * const handle, IN const char * const pInFile, IN const char * const pParamName = 0,
    IN  const unsigned int nModuleID = -1,
    OUT char * const pOutFilePath = 0,
    IN  int * const nOutPathSize = 0);

/** @fn    IMVS_GenerateFileToWindows
*  @brief  SDK�Ȳ���һ��linux����ʱ·�����ݵ��ײ㣬�ӿڸ���bDelTempFile����ѡ���������
*  @param  pPath               [IN]  �ļ�·��
*  @param  pTempPath           [OUT] ������linux�µ���ʱ�ļ�·��
*  @param  bDelTempFile        [IN]  true����SDK��Ҫ��linux�ļ�������pPath��Ȼ��ɾ��linux�µ��ļ���false���򲻽���ɾ������
*  @return �ɹ�������CM_OK��ʧ�ܣ����ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GenerateFileToWindows(IN const void * const handle, IN const char * const pPath,
    IN const char * const pParamName = 0,
    IN  const unsigned int nModuleID = -1,
    OUT char * const pTempPath = 0,
    IN const bool bDelTempFile = true);

#pragma endregion

/** @fn    IMVS_VersionUpgradeFlag
*  @brief  �汾���ݹ��߱�ʶ
*  @return �ɹ�������CM_OK��ʧ�ܣ����ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_VersionUpgradeFlag(IN const void * const handle, IN bool bToolFlag);

/** @fn     IMVS_AddDynamicParam
*  @brief  ��Ӷ�̬����
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       ������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddDynamicParam(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName);

/** @fn     IMVS_ModifyDynamicParam
*  @brief  �޸Ķ�̬����
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strNameOld              [IN]       ������
*  @param  strNameNew              [IN]       ������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ModifyDynamicParam(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strNameOld,
    IN const char * const strNameNew);

/** @fn     IMVS_DeleteDynamicParam
*  @brief  ɾ����̬����
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       ������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteDynamicParam(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName);

/** @fn     IMVS_GetAllDynamicParam
*  @brief  ��ȡ���ж�̬����
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  pstParamList            [OUT]      �����б�
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllDynamicParam(IN const void * const handle,
    IN const unsigned int nObjectID,
    OUT IMVS_MODULE_PARAM_LIST * const pstParamList);

/** @fn     IMVS_AddDynamicParamRelation
*  @brief  ��Ӷ�̬����������ϵ
*  @param  handle                  [IN]       �������
*  @param  nDestinID               [IN]       Ŀ��ID
*  @param  strDestinName           [IN]       Ŀ�������
*  @param  nSourceID               [IN]       ��ԴID
*  @param  strSourceName           [IN]       ��Դ������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_AddDynamicParamRelation(IN const void * const handle,
    IN const unsigned int nDestinID,
    IN const char * const strDestinName,
    IN const unsigned int nSourceID,
    IN const char * const strSourceName);

/** @fn     IMVS_GetDynamicParamRelationByKey
*  @brief  ��ȡ��̬����������ϵ
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       ������
*  @param  pstRelationList         [OUT]      ������ϵ�б�
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetDynamicParamRelationByKey(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    OUT IMVS_DYNAMIC_PARAM_RELATION_LIST * const pstRelationList);

/** @fn     IMVS_DeleteDynamicParamRelation
*  @brief  ɾ����̬����������ϵ
*  @param  handle                  [IN]       �������
*  @param  nDestinID               [IN]       Ŀ��ID
*  @param  strDestinName           [IN]       Ŀ�������
*  @param  nSourceID               [IN]       ��ԴID
*  @param  strSourceName           [IN]       ��Դ������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteDynamicParamRelation(IN const void * const handle,
    IN const unsigned int nDestinID,
    IN const char * const strDestinName,
    IN const unsigned int nSourceID,
    IN const char * const strSourceName);

/** @fn     IMVS_SetDynamicRunParamValue
*  @brief  ���ö�̬���в���ֵ
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       ������
*  @param  strValue                [IN]       ����ֵ
*  @param  strOptionalParam        [IN]       ��ѡ������Ĭ������ַ����������ѡ��ģ��Ĳ�������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetDynamicRunParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    IN const char * const strValue,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn     IMVS_GetDynamicRunParamValue
*  @brief  ��ȡ��̬���в���ֵ
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       ������
*  @param  nValueSize              [IN]       ����ֵ�ķ����С
*  @param  strValue                [OUT]      ����ֵ
*  @param  strOptionalParam        [IN]       ��ѡ������Ĭ������ַ����������ѡ��ģ��Ĳ�������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetDynamicRunParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    IN const unsigned int nValueSize,
    OUT const char * const strValue,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn     IMVS_SetDynamicBinaryParamValue
*  @brief  ���ö�̬�����Ʋ���ֵ
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       ������
*  @param  pData                   [IN]       ��������
*  @param  nDataLen                [IN]       ���ݳ���
*  @param  strOptionalParam        [IN]       ��ѡ������Ĭ������ַ����������ѡ��ģ��Ĳ�������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetDynamicBinaryParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    IN const char * const pData,
    IN const unsigned int nDataLen,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn     IMVS_GetDynamicBinaryParamValue
*  @brief  ��ȡ��̬�����Ʋ���ֵ�����ݿ�����ʹ�ýӿ��ͷ�ָ��-IMVS_ReleaseDynamicMemory
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       ������
*  @param  pData                   [OUT]      ��������
*  @param  pnDataLen               [OUT]      ���ݳ���
*  @param  strOptionalParam        [IN]       ��ѡ������Ĭ������ַ����������ѡ��ģ��Ĳ�������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetDynamicBinaryParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    OUT char *& pData,
    OUT unsigned int * const pnDataLen,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn     IMVS_SetDynamicUIParamValue
*  @brief  ���ö�̬UI����ֵ
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       ������
*  @param  pData                   [IN]       ��������
*  @param  nDataLen                [IN]       ���ݳ���
*  @param  strOptionalParam        [IN]       ��ѡ������Ĭ������ַ����������ѡ��ģ��Ĳ�������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetDynamicUIParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    IN const char * const pData,
    IN const unsigned int nDataLen,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn     IMVS_GetDynamicUIParamValue
*  @brief  ��ȡ��̬UI����ֵ
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       ������
*  @param  pData                   [OUT]      ��������
*  @param  pnDataLen               [OUT]      ���ݳ���
*  @param  strOptionalParam        [IN]       ��ѡ������Ĭ������ַ����������ѡ��ģ��Ĳ�������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetDynamicUIParamValue(IN const void * const handle,
    IN const unsigned int nObjectID,
    IN const char * const strName,
    OUT char *& pData,
    OUT unsigned int * const pnDataLen,
    IN const char * const strOptionalParam/* = ""*/);

/** @fn    IMVS_DeleteDynamicRelateUIParamValue
*  @brief  ɾ��������UserData����
*  @param  handle                  [IN]       �������
*  @param  nObjectID               [IN]       ID
*  @param  strName                 [IN]       ������
*  @param  strValue                [IN]       ģ��������ƣ�����Ϊ�գ�
*  @param  eIsFuzzyMatch           [IN]       �Ƿ�ģ��ƥ��
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_DeleteDynamicRelateUIParamValue(IN const void * const handle,
	IN const unsigned int nObjectID,
	IN const char * const strName,
	IN IMVS_FUZZY_MATCH eIsFuzzyMatch,
	IN const char * const strOptionalParam);

/** @fn    IMVS_ReleaseDynamicMemory
*  @brief  �ͷŶ�̬�ڴ�
*  @param  handle                  [IN]       �������
*  @param  eMemType                [IN]       �ڴ�����
*  @param  pData                   [IN]       ָ��
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ReleaseDynamicMemory(IN const void * const handle, IMVS_RELEASE_MEMORY_TYPE eMemType, IN char * pData);

/** @fn    IMVS_ReportData
*  @brief  �ϱ���Ϣ
*  @param  handle[IN]      �������
*  @param  pData[IN]       ����ָ��
*  @return �ɹ�, ����IMVS_EC_OK; ʧ��, ���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ReportData(IN const void * const handle, IN const char * pData, IN const unsigned int nDataLen);

/** @fn     IMVS_CheckUIParamExist
*  @brief  �ж�UI�����Ƿ����
*  @param  handle            [IN]       �������
*  @param  nObjectID         [IN]       ����ID
*  @param  strParamName      [IN]       �����������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CheckUIParamExist(IN const void * const handle, IN const unsigned int nObjectID, IN const char * const strParamName);

/** @fn     IMVS_GetAllExecutableProcedure
*  @brief  ��ȡ��ǰ�����п�ִ�е�����
*  @param  handle            [IN]       �������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAllExecutableProcedure(IN const void * const handle, OUT IMVS_PROCESS_INFO_LIST * const pstProcessInfoList);


/** @fn    IMVS_SetAllExecutableProcedureId
*  @brief  ���õ�ǰ�����п�ִ�е�����ID
*  @param  handle                        [IN]       �������
*  @param  pstProcessInfoList            [IN]       ��ִ�������б�
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetAllExecutableProcedureId(IN const void * const handle, IN IMVS_PROCESS_INFO_LIST * const pstProcessInfoList);

/** @fn    IMVS_ModifySubInputName
*  @brief  �޸�ģ�鶩�Ĺ�ϵ����������
*  @param  handle                        [IN]       �������
*  @param  nModuleID                     [IN]       ģ��ID
*  @param  strSubInputNameOld            [IN]       �ϵĶ�����������
*  @param  strSubInputNameNew            [IN]       �µĶ�����������
*  @return �ɹ�������IMVS_EC_OK��ʧ�ܣ����ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ModifyModuleSubInputName(IN const void * const handle, IN const unsigned int nModuleID, IN const char * const strSubInputNameOld, IN const char * const strSubInputNameNew);

#pragma region Linux�����ӿ�

/** @fn     IMVS_CheckServerPasswordStatus
*  @brief  ��ȡServer������״̬�����ʹ�ã����ýӿ���CreateHandleǰ���ã���IMVS_SetServerPassword���ʹ��
*  @param  serverIP            [IN]  ����IP
*  @param  serverPort          [IN]  ����˿�
*  @param  waitingTime         [OUT] �ȴ�ʱ�䣬����ʱ��Ч
*  @return IMVS_EC_OK������ʱ���أ������������루IMVS_EC_AUTH_REMOTE_NO_PASSWORD�����������루IMVS_EC_AUTH_ASSWORD_IS_EXIST�����˻���������IMVS_EC_AUTH_USER_LOCKOUT��
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_CheckServerPasswordStatus(IN const char* serverIP, IN unsigned int serverPort, OUT unsigned int* waitingTime);

/** @fn     IMVS_SetServerPassword
*  @brief  ����Server���룬 �ýӿ���CreateHandleǰ���ã���IMVS_CheckServerPasswordStatus���ʹ��
*  @param  serverIP            [IN]  ����IP
*  @param  serverPort          [IN]  ����˿�
*  @param  password            [IN]  ����
*  @return �ɹ�������IMVS_EC_OK��ʧ�ܣ����ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetServerPassword(IN const char* serverIP, IN unsigned int serverPort, IN const char* password);

/** @fn     IMVS_ModifyServerPassword
*  @brief  �޸�Server���룬�ýӿ���Ҫ���ӷ���ɹ����������
*  @param  oldPassword         [IN]  ������
*  @param  newPassword         [IN]  ������
*  @return �ɹ�������IMVS_EC_OK��ʧ�ܣ����ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_ModifyServerPassword(IN const char* oldPassword, IN const char* newPassword);

/** @fn     IMVS_StartupVmFrontendWindowOnLinux
*  @brief  ����ǰ�����н��棬��DestroyHandle��ִ��
*  @param  serverAddress       [IN]  �����ַ����ʽ��: 127.0.0.1:5556
*  @return �ɹ�������IMVS_EC_OK��ʧ�ܣ����ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_StartupVmFrontendWindowOnLinux(IN const char* serverAddress);

/** @fn     IMVS_GetAlgorithmVersion
*  @brief  ��ȡ���Ӱ汾�ţ�����2d���Ӻ��������
*  @param  normalVersion       [OUT]  2d���Ӱ汾
*  @param  deeplearningVersion [OUT]  ������Ӱ汾
*  @return �ɹ�������IMVS_EC_OK��ʧ�ܣ����ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_GetAlgorithmVersion(OUT IMVS::AlgorithmVersionInfo* versions);

/** @fn    IMVS_SetExecuteDelayTime
*  @brief  ����ȫ��ִ���ӳ�ʱ��
*  @param  handle                [IN]     �������
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
IMVS_6000_PLATFORMSDK_API int __stdcall IMVS_SetExecuteDelayTime(IN const void * const handle, IN const unsigned int nDelayTime);

#pragma endregion

#ifdef __cplusplus
}
#endif 

#endif    // IMVS_6000_PLATFORMSDKC_IN_H__
