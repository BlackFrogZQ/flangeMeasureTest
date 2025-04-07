/***************************************************************************************************
* 
* ��Ȩ��Ϣ����Ȩ���� (c) 2016, ��������Ȩ��
* 
* �ļ����ƣ�iMVS-6000SDK4ServerDefine.h
* ժ    Ҫ����iMVS-6000��Server��ͨ�ŵĽӿڳ�������
*
* ��    �ڣ�2016-12-12
* ��    ע���½�
***************************************************************************************************/
#ifndef IMVS_6000_SDK4SERVER_DEFINE_H__
#define IMVS_6000_SDK4SERVER_DEFINE_H__

#pragma warning(disable:4819)
#include <stdio.h>  //NULL
#include "ErrorCodeDefine.h"
#include "IVmExport.h"

using namespace VisionMasterSDK;

/*************************************************************************
 * ϵͳ�궨��
 *************************************************************************/

// ���������ʾ
#ifndef IN
#define IN
#endif

// ���������ʾ
#ifndef OUT
#define OUT
#endif

// �������������ʾ
#ifndef INOUT
#define INOUT
#endif

// �����ָ��
#ifndef IMVS_NULL
#ifdef __cplusplus
#define IMVS_NULL    0
#else
#define IMVS_NULL    ((void *)0)
#endif
#endif

/*************************************************************************
 * �����궨��
 *************************************************************************/
const static unsigned int IMVS_MAX_MODULE_NAME_LENGTH       = 64;                       // ���ģ�����Ƴ���
const static unsigned int IMVS_MAX_MODULE_NUM               = 1040;                     // ���ģ�����(ʵ���������+ȫ��ģ�����)
const static unsigned int IMVS_MAX_INPUT_NUM                = 64;                       // ����������
const static unsigned int IMVS_MAX_OUTPUT_NUM               = 64;                       // ����������
const static unsigned int IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH = 256;                      // ����������󳤶�
const static unsigned int IMVS_MAX_PLATFORM_NUM             = 16;                       // ƽ̨����
const static unsigned int IMVS_MAX_USERNAME_LENGTH          = 16;                       // ����û�������
const static unsigned int IMVS_MAX_PASSWORD_LENGTH          = 32;                       // ������볤��
const static unsigned int IMVS_MAX_VENDORNAME_LENGTH        = 16;                       // ��������̳���

const static unsigned int CM_MAX_MODULE_RESULT_OUTPUT_NUM   = 200;                      // ������200��ģ��

/************************* ���ο������� **************************/
const static unsigned int IMVS_DEFAUT_SOCKET_SENDBUF_LENGTH = 1024;                     // Ĭ�Ϸ����ֽڳ���
const static unsigned int IMVS_DEFINE_SOCKET_BUF_LENGTH     = 8192;                     // �Զ��巢�ͽ����ֽڳ���
const static unsigned int IMVS_MAX_DATATYPE_NUM             = 32;                       // ��������������
const static unsigned int IMVS_MAX_IMPORT_NUM               = 16;                       // ����������ļ�����
const static unsigned int IMVS_MAX_MODULE_PARAM_NUM         = 128;                      // ģ������������
const static unsigned int IMVS_MAX_PARAM_NAME_LENGTH        = 128;                      // ģ���������󳤶�
const static unsigned int IMVS_MAX_PARAM_VALUE_LENGTH       = 512;                      // ģ�����ֵ��󳤶�
const static unsigned int IMVS_MAX_PATH_LENGTH              = 260;                      // ���·������
const static unsigned int IMVS_DEFAULT_GUID_LEN             = 256;                      // Ĭ��GUID����

// ������������
const static unsigned int IMVS_DATATYPE_TEMPLATE            = 1;                        // ģ����������
const static unsigned int IMVS_DATATYPE_FONT                = 2;                        // �ֿ���������
const static unsigned int IMVS_DATATYPE_CALIB               = 3;                        // �궨�ļ���������
const static unsigned int IMVS_DATATYPE_DLFONT              = 4;                        // ���ѧϰ�ֿ�����
const static unsigned int IMVS_DATATYPE_IMAGE               = 5;                        // ͼ����������
const static unsigned int IMVS_DATATYPE_MARKINSP            = 6;                        // �ַ�ģ������
const static unsigned int IMVS_DATATYPE_EDGEFLAW            = 7;                        // ��Եȱ��ģ������
const static unsigned int IMVS_DATATYPE_COLORRECOGNITION     = 8;                        // ��ɫʶ��ģ������
const static unsigned int IMVS_DATATYPE_MARKFIND            = 9;                        // ͼ�ζ�λģ������
const static unsigned int IMVS_DATATYPE_GLUEPATHCONDUCT      = 10;                       // ·����ȡģ������
const static unsigned int IMVS_DATATYPE_IMGSTITCHCALIB       = 11;                       // ͼ��ƴ��ģ������
const static unsigned int IMVS_DATATYPE_INSPECT             = 12;                       // ȱ�ݶԱ�ģ������

/**************************** V3.0���� ****************************/
const static unsigned int IMVS_PROCEDURE_GLOBAL_CTRL_SHIELD     = 1;                    // ��������
const static unsigned int IMVS_PROCEDURE_GLOBAL_CTRL_NOT_SHIELD = 0;                    // ����������
const static unsigned int IMVS_MAX_PROCESS_NAME_LENGTH          = 64;                   // ����������󳤶�
const static unsigned int IMVS_MAX_PROCESS_NUM                  = 1000;                 // ������̸���
const static unsigned int IMVS_MAX_ADD_MODULE_NUM               = 1020;                 // �������������ģ������
const static unsigned int IMVS_MAX_DEL_MODULE_NUM               = 1020;                 // ���������ɾ��ģ������
const static unsigned int IMVS_MAX_TRANS_DATA_LENGTH            = 1024;                 // �㷨���������󳤶�
const static unsigned int IMVS_AUTO_LOAD_SOLU_STATE_STOP_EXECUTE     = 0;               // ����ʱ����Ҫִ��
const static unsigned int IMVS_AUTO_LOAD_SOLU_STATE_EXECUTE_ONCE     = 1;               // ����ʱִ��һ��
const static unsigned int IMVS_AUTO_LOAD_SOLU_STATE_CONTINUE_EXECUTE = 2;               // ����ʱ����ִ��
const static unsigned int IMVS_CLIENT_TAKE_OVER_STATE_NOT_NEED       = 0;               // ����Ҫ�ӹ�
const static unsigned int IMVS_CLIENT_TAKE_OVER_STATE_NEED           = 1;               // ��Ҫ�ӹ�
const static unsigned int IMVS_CLIENT_TAKE_OVER_STATE_HB_EXCEPTION   = 2;               // ���������쳣

/**************************** ģ������ ***************************/
const static unsigned int IMVS_MODULE_TYPE_NORMAL               = 0;                    // ��ͨģ������
const static unsigned int IMVS_MODULE_TYPE_PROCESS_CONTROL      = 1;                    // ���̿���ģ������
const static unsigned int IMVS_MODULE_TYPE_LOOP_CONTROL         = 2;                    // ѭ��ģ������
const static unsigned int IMVS_MODULE_TYPE_GLOBAL_COMMUNICAT    = 3;                    // ȫ��ͨ��ģ�����ͣ��ڷ����У����������̿���
const static unsigned int IMVS_MODULE_TYPE_GLOBAL_QUEUE         = 4;                    // ȫ�ֶ���ģ�飬�ڷ����У����������̿���
const static unsigned int IMVS_MODULE_TYPE_GLOBAL_VARIABLE      = 5;                    // ȫ�ֱ���ģ�飬�ڷ����У����������̿���
const static unsigned int IMVS_MODULE_TYPE_GLOBAL_CAMERA        = 6;                    // ȫ�����ģ��

/*************************** ���ܹ����ͳ��� ***********************/
const static unsigned int IMVS_DEFINE_DONGLE_TYPE_LENGTH        = 16;                   // ���ܹ����ͳ���

const static unsigned int IMVS_DEFINE_SUBSCRIBE_INDEX_LENGTH    = 256;                  // ����Index����
const static unsigned int IMVS_DEFINE_MODULE_RES_STRING_LENGTH  = 4096;                 // ģ���ַ����������
const static unsigned int IMVS_DEFINE_CUSTOM_OUTPUT_PAGE_SIZE   = 10;                   // ����������ȡ����������

/*************************** V3.2.0 �����Ż����� ***********************/
const static unsigned int IMVS_CAMPICINFO_LIST_NUM              = 256;                  // ���ͼ����Ϣ�б���Ŀ
const static unsigned int IMVS_MAX_CORE_NUM                     = 64;                   // ���CPU���ĸ���
const static unsigned int IMVS_MAX_RUN_POLICY_NUM               = 32;                   // �������в����������
const static unsigned int IMVS_MAX_SHARE_MEMORY_ADDR_LENGTH     = 260;                  // �����ڴ�����ַ����
const static unsigned int IMVS_MAX_PATH_UTF8_LENGTH             = IMVS_MAX_PATH_LENGTH * 3; // ���UTF8��ʽ·������
const static unsigned int IMVS_DEFINE_PUB_ADDRESS_LENGTH        = 64;                   // Pub��ַĬ�ϳ���
const static unsigned int IMVS_MAX_RESULT_PARAM_NAME_LENGTH     = 128;                  // ģ�����������Ƴ���
const static unsigned int IMVS_SOLUTION_VERSION_LENGTH          = 32;                   // �����汾����
const static unsigned int IMVS_BINARY_DATA_PARAM_LENGTH         = 256;                  // ���������ݳ���

/*************************** V3.4.0 �����Ż����� ***********************/
const static unsigned int IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH   = 256;                  // ���ģ����ʾ���Ƴ���

/*************************** V4.0 ���� ***********************/
const static unsigned int IMVS_MAX_THIRD_SOFTWARE_NUM = 16;                             // �����ο�����������
const static unsigned int IMVS_MAX_GLOBAL_TYPE_NUM    = 5;                              // ȫ��ģ����������

/*************************** V4.1 ���� ***********************/
const static unsigned int IMVS_MAX_MODULE_INPUT_IO_NUM          = 128;                  // ���ģ��IO��������
const static unsigned int IMVS_DEFAULT_BYTE_NUM                 = 4;                    // Ĭ�ϲ�������
const static unsigned int IMVS_DEFAULT_STYLE_NUM                = 32;                   // ��ʽ��������
const static unsigned int IMVS_MAX_OBJECT_IO_NUM                = 1024;                 // Group��ʵ�����IO����
const static unsigned int IMVS_DEFAULT_DATA_NUM                 = 512;                  //Ĭ�ϸ������ݸ���

/*************************** V4.2 ���� ***********************/
const static unsigned int IMVS_REENTRANT_MAX_CMD_LEN            = 16;                  // ��������󴥷��ַ�������
const static unsigned int IMVS_CAMERA_MAX_SN_LEN                = 64;                  // ���������кų���
const static unsigned int IMVS_DYNAMIC_BINARY_LENGTH            = 32 * 1024;                       // ��̬IO��ȡ���������ݳ��ȳ�ʼ��С

const static unsigned int IMVS_ALGORITHM_VERSION_LENGTH         = 64;                   // �㷨�汾��Ϣ����

/*************************************************************************
 * ö�ٶ���
 *************************************************************************/
/** @enum IMVS_MODULE_TYPE
 *  @brief ģ������
 */
typedef enum IMVS_MODULE_TYPE__
{
	IMVS_ENUM_MODULE_TYPE_NORMAL          = 0, //��ͨģ������
	IMVS_ENUM_MODULE_TYPE_PROCESS_CONTROL = 1, // ���̿���ģ������
	IMVS_ENUM_MODULE_TYPE_LOOP_CONTROL    = 2, // ѭ��ģ�����ͣ��ڷ����У������̿���
	IMVS_ENUM_MODULE_TYPE_GLOBAL_COMMUNICATION = 3, // ȫ��ͨ��ģ�����ͣ��ڷ����У����������̿���
	IMVS_ENUM_MODULE_TYPE_GLOBAL_QUEUE    = 4, // ȫ�ֶ���ģ�飬�ڷ����У����������̿���
	IMVS_ENUM_MODULE_TYPE_GLOBAL_VARIABLE = 5, // ȫ�ֱ���ģ�飬�ڷ����У����������̿���
	IMVS_ENUM_MODULE_TYPE_GLOBAL_CAMERA   = 6, // ȫ�����ģ�飬�ڷ����У����������̿���
	IMVS_ENUM_MODULE_TYPE_GLOBAL_LIGHT    = 7, // ȫ�ֹ�Դģ�飬�ڷ����У����������̿���
	IMVS_ENUM_MODULE_TYPE_GROUP           = 20 // Groupģ�飬�ڷ����У������̿���
} IMVS_MODULE_TYPE;

/** @enum IMVS_OUTPUT_PlATFORM_INFO_TYPE
 *  @brief �ص������е�����㷨ƽ̨��Ϣ����
 */
typedef enum IMVS_OUTPUT_PlATFORM_INFO_TYPE__
{
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_ERROR            = 0,
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE           = 1,
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SUBSCRIBE        = 2,
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_UNSUBSCRIBE      = 3,
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_UNREGISTER       = 4,
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_RESULT    = 5,
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_UPDATE    = 6,
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_RESTART_BEGIN     = 7,
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_RESTART_END       = 8,
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_DONGLE           = 9,                // ���ܹ���Ϣ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SERVER           = 0xa,              // Server״̬��Ϣ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_RESULT_FLAG = 0xb,            // ��־�ص���״̬
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_HEART            = 0xc,              // ����״̬��Ϣ���������ã�ͳһ��IMVS_ENUM_OUTPUT_PlATFORM_INFO_SERVER��
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_RESULT_EXTRA_INFO  = 0xd,     // ģ�����������Ϣ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_WORK_STATUS  = 0xe,           // ģ���״̬��Ϣ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_XML_INFO  = 0xf,              // ģ���XML�����µ����������Ϣ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_SAVE_BEGIN      = 0x10,              // �������濪ʼ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_SAVE_END        = 0x11,              // �����������
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_SAVE_PROCESS    = 0x12,              // �����������
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_BEGIN      = 0x13,              // �������ؿ�ʼ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_END        = 0x14,              // �������ؽ���
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_PROCESS    = 0x15,              // �������ؽ���
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_INTERFACE_FILE  = 0x16,         // �������ؽ����ļ�
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_RESULT_EX         = 0x17,              // ģ�����ص�������һ������
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_CAMERA_COLLECT           = 0x18,              // ���ȡͼ������Ϣ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_COMMUNICATION_CONNECT    = 0x19,              // ͨ��������Ϣ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_CAMERA_COLLECT_START     = 0x20,              // ���ȡͼ��ʼ��Ϣ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_CAMERA_CONNECT_STATUS	= 0x21,              // �������״̬��Ϣ

    /****************************���ο�������*****************************/
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_HB_CLIENT                     = 0x100,         // ƽ̨���������쳣
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_HB_MODU                       = 0x101,         // ģ�������쳣��Ϣ
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_START_CONTINUOUSLY            = 0x102,         // ����ִ�п�ʼ��Ϣ
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_STOP_EXECUTE                  = 0x103,         // ִֹͣ��״̬��Ϣ
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_START_RUN                     = 0x104,         // ��ʼ����״̬��Ϣ
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_SOLUTION_SAVE_THIRD           = 0x105,         // ��ʼ����״̬��Ϣ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_DEVELOPER_DATA  = 0x106,         // ���������������ļ�����

    // V3.0 ����
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_PROCEDURE_REGISTER_INFO      = 0x301,         // ����ע����Ϣ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_ALGORITHM_INIT_RESULT        = 0x302,         // �㷨��ʼ�����
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_PROCESS_START_CONTINUOUSLY   = 0x303,         // ��������ִ�п�ʼ��Ϣ
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_PROCESS_STOP_EXECUTE         = 0x304,         // ����ִֹͣ��״̬��Ϣ
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_DETAIL_PLATFORM_BEGIN_INFO   = 0x305,         // ƽ̨��ʼ��ϸ��Ϣ
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_PLATFORM_PROCESS_INFO        = 0x306,         // ƽ̨����״̬��Ϣ
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_DETAIL_PLATFORM_END_INFO     = 0x307,         // ƽ̨������ϸ��Ϣ
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_RESOURCE_USAGE_INFO          = 0x308,         // ��Դռ��״̬��Ϣ
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_SP_PROXY_CRASH               = 0x309,         // ������̱���״̬��Ϣ

	// V3.2 ����
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_GLOBALSCRIPT_CRASH           = 0x310,         // ȫ�ֽű�����״̬��Ϣ
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_GLOBALSCRIPT_REPORT_DATA     = 0x311,         // ȫ�ֽű��ϱ�������Ϣ
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_LOAD_MODULE_WARN_INFO        = 0x312,         // ��������ʱģ����󾯸���Ϣ

	// V3.2.0.1�����Ż�����
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_EXECUTE_STATE_AFTER_LOAD_INFO = 0x313,        // ����������ɺ��Ƿ�ִ����Դ��ʼ��
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_PROCEDURE_UNREGISTER_INFO     = 0x314,        // ���̽�ע����Ϣ

	// V3.3.0 ����
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_EXPORT_GROUP_BEGIN            = 0x315,        // Group������ʼ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_GROUP_END              = 0x316,        // Group��������
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_GROUP_PROGRESS         = 0x317,        // Group��������
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_IMPORT_GROUP_BEGIN            = 0x318,        // Group���뿪ʼ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_GROUP_END              = 0x319,        // Group�������
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_GROUP_PROGRESS         = 0x320,        // Group�������
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_GROUP_NAME_NEWID       = 0x321,        // Group����ģ�������Լ���ID
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_GROUP_INTERFACE_FILE   = 0x322,        // Group�����ļ�����

	// V3.4.0 ����
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_UPDATE_PROCESS_NAME           = 0X323,        // �ϰ汾�������ؽ����������̵�������
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_UPDATE_MODULE_NAME            = 0X324,        // �ϰ汾�������ؽ�������ģ���������
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_EXPORT_PROCESS_BEGIN          = 0x325,        // ���̵�����ʼ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_PROCESS_END            = 0x326,        // ���̵�������
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_PROCESS_PROGRESS       = 0x327,        // ���̵�������
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_IMPORT_PROCESS_BEGIN          = 0x328,        // ���̵��뿪ʼ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_END            = 0x329,        // ���̵������
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_PROGRESS       = 0x330,        // ���̵������
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_INTERFACE_FILE = 0x331,        // ���̵����������
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_NEW_NAME_ID    = 0x332,        // ���̵���ģ�������Լ�ID
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_TAKEOVER_PRC_INTERFACE_FILE   = 0x333,        // ����ӹ����̽����ļ�����
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_TAKEOVER_SOL_INTERFACE_FILE   = 0x334,        // ����ӹܷ��������ļ�����
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_IGNOREGLOBALVAR = 0x335,       // ���̵������ȫ�ֱ�����Ϣ
    
	// V4.0 ����
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_UI_GLOBAL_PROCESS_OBJECT_ID    = 0x336,        // ���ط���ʱ֪ͨ�����ȡ�����ļ��е�ȫ�ֶ������̶�����Ϣ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_GET_UIDATA      = 0x337,        // ��������ʱ֪ͨ�����ȡ����
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_GROUP_GET_UIDATA        = 0x338,        // ����Groupʱ֪ͨ�����ȡ����
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_MODULE_STATUS_INFO      = 0x339,        // �ϱ�ģ��״̬��Ϣ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_CLOSE_SOLUTION_INFO     = 0x340,        // �ϱ��رշ�����Ϣ

	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_COMMU_RECV_DATA_INFO     = 0x400,       // �ϱ�ͨ�Ž��յ���������Ϣ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_COMMU_DEVICE_STATUS_INFO = 0x401,       // �ϱ�ͨ���豸״̬��Ϣ

    // V4.0.1 ����
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_FRAME_LOSS_INFO          = 0x500,        // �ϱ���֡��Ϣ

	// V4.2����
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_EXPORT_MULTIPROCESS_BEGIN = 0x341,        // �����̵�����ʼ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_MULTIPROCESS_END = 0x342,        // �����̵�������
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_MULTIPROCESS_PROGRESS = 0x343,        // �����̵�������
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_IMPORT_MULTIPROCESS_BEGIN = 0x344,        // �����̵��뿪ʼ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_MULTIPROCESS_END = 0x345,        // �����̵������
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_MULTIPROCESS_PROGRESS = 0x346,        // �����̵������
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_MULTIPROCESS_GET_UIDATA = 0x347,        // �����̵����ȡ��������

    IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_GLOBAL_CAMERA_COLLECT_INFO = 0x402,       // �ϱ�ȫ�����ȡͼ������Ϣ
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_OTHER_CLIENT_CONN_SERVER = 0x403,                // ��һ���ͻ������ӵ�Server
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_PROXY_IMAGE_INFO = 0x404,                 // ͸������ͼ�����ݵ�����
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_GLOBAL_CAMERA_COLLECT_START_INFO = 0x405,       // �ϱ�ȫ�����ȡͼ��ʼ��Ϣ
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_CAMERA_CONNECT_STATUS_INFO = 0x406,       // �ϱ����ģ������״̬��Ϣ
} IMVS_OUTPUT_PlATFORM_INFO_TYPE;

/*************************************************************************
 * �ṹ�嶨��
 *************************************************************************/

/** @struct IMVS_INPUT_INFO
 *  @brief ������Ϣ
 */
typedef struct IMVS_INPUT_INFO__
{
    char                            strInput[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];        // ģ����������ַ���
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_INPUT_INFO;

/** @struct IMVS_INPUT_INFO_LIST
 *  @brief ������Ϣ�б�
 */
typedef struct IMVS_INPUT_INFO_LIST__
{
    unsigned int                    nNum;                                               // ģ�������������
    IMVS_INPUT_INFO                 astInputInfoList[IMVS_MAX_INPUT_NUM];               // ģ����������б�
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_INPUT_INFO_LIST;

/** @struct IMVS_OUTPUT_INFO
 *  @brief �����Ϣ
 */
typedef struct IMVS_OUTPUT_INFO__
{
    char                            strOutput[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];       // ģ����������ַ���
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_OUTPUT_INFO;

/** @struct IMVS_OUTPUT_INFO_LIST
 *  @brief �����Ϣ�б�
 */
typedef struct IMVS_OUTPUT_INFO_LIST__
{
    unsigned int                    nNum;                                               // ģ�������������
    IMVS_OUTPUT_INFO                astOutputInfoList[IMVS_MAX_OUTPUT_NUM];             // ģ����������б�
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_OUTPUT_INFO_LIST;

/** @struct IMVS_MODULE_INFO
 *  @brief ģ����Ϣ
 */
typedef struct IMVS_MODULE_INFO__
{
    unsigned int                    nNodeID;                                            // �ڵ�ID
	char                            strDisplayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH];// ������ʾ����
    char                            strModuleName[IMVS_MAX_MODULE_NAME_LENGTH];         // ģ������
    unsigned int                    nIsFatherLoop;                                      // �Ƿ��Ǹ�ѭ��
    unsigned int                    nAlgorithmInitResult;                               // �㷨��ʼ�����,0��ʾOK��������ʾ������
    unsigned int                    nProcessID;                                         // ����ID���㷨ƽ̨V3.0������
    unsigned int                    nModuleType;                                        // ģ�����ͣ��㷨ƽ̨V3.0������
	char                            strModuleGUID[IMVS_DEFAULT_GUID_LEN];               // ģ��GUID (V3.2.0 Group2.0����)
	unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_MODULE_INFO;

/** @struct IMVS_MODULE_INFO_LIST
 *  @brief ģ����Ϣ�б�
 */
typedef struct IMVS_MODULE_INFO_LIST__
{
    unsigned int                    nNum;                                               // ģ�����
    IMVS_MODULE_INFO                astModuleInfo[IMVS_MAX_MODULE_NUM];                 // ģ����Ϣ�б�
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_MODULE_INFO_LIST;

/** @struct IMVS_SUBSCRIBE_INFO
 *  @brief ������Ϣ
 */
typedef struct IMVS_SUBSCRIBE_INFO__
{
    // LocalImageModule(ģ��IDΪ0) ------> IMVS_CircleFindModule(ģ��IDΪ1)
    unsigned int                    nSubModuleID;                                       // ���ķ�
    char                            strSubInput[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];     // ����:"SubID+Sub����":"%d+%s" : (1+����ͼ����)

    unsigned int                    nPubModuleID;                                       // �������������ķ���
    char                            strPubOutput[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];    // ����:"PubAddress+PubID+Pub����":"tcp://10.67.131.101+0+���ͼ����)
    unsigned int                    nIsPubConstant; // 0��ʾ�ɱ�ı��������ݣ�1��ʾstrPubOutputΪ�̶�����İ���������

    // ����Ҫ���ĵ�0�����,�����:
    // nIsIndexConstant = 1;
    // strIndex = "0";
    // ����Ҫ���ĵ�5�����,�����:
    // nIsIndexConstant = 1;
    // strIndex = "5";
    // ����Ҫ�Ľ���ǲ�����,��д����:
    // nIsIndexConstant = 0;
    // ��Ϊ���±��ǲ�����,���Ա��뽫�±궩��һ������
    // nIndexModuleID �����ĵ�ģ���ID
    // strIndex �����ĵ�ģ���ʵ������
    unsigned int                    nIndexModuleID;
	char                            strIndex[IMVS_DEFINE_SUBSCRIBE_INDEX_LENGTH];    // Ĭ����д"All"
    unsigned int                    nIsIndexConstant; // Ĭ����д1

    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_SUBSCRIBE_INFO;

typedef struct IMVS_CONNECT_INFO__
{
    unsigned int                    nPreModuleID;
    unsigned int                    nNextModuleID;
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_CONNECT_INFO;

/** @struct IMVS_CONNECT_INFO_LIST
 *  @brief ������Ϣ�б�
 */
typedef struct IMVS_CONNECT_INFO_LIST__
{
    unsigned int                    nNum;                                               // ������Ϣ����
    IMVS_CONNECT_INFO               astConnectInfo[IMVS_MAX_MODULE_NUM];                // ������Ϣ�б�
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_CONNECT_INFO_LIST;

typedef struct IMVS_GLOBAL_SELECT_INFO__
{
    unsigned int                    nSelectIp;                                          // ѡ��IP
    unsigned short                  nSelectPort;                                        // ѡ��Port
    //unsigned int                    nSelectModuleID;
    char                            strSelect[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];       // ѡ������
    unsigned int                    nBeSelectedIp;                                      // ��ѡ��IP
    unsigned short                  nBeSelectedPort;                                    // ��ѡ��Port
    char                            strBeSelected[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];   // ��ѡ������
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_GLOBAL_SELECT_INFO;

typedef struct IMVS_GLOBAL_SELECT_INFO_LIST__
{
    unsigned int                    nNum;                                               // ȫ��ѡ�����
    IMVS_GLOBAL_SELECT_INFO         astGlobalSelectInfo[IMVS_MAX_MODULE_NUM];           // ȫ��ѡ����Ϣ��Ϣ�б�
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_GLOBAL_SELECT_INFO_LIST;

/** @struct IMVS_PLATFORM_INFO
 *  @brief ƽ̨������Ϣ
 */
typedef struct IMVS_PLATFORM_BASIC_INFO__
{
    unsigned int                    nRepIp;                                             // ƽ̨RepIP
    unsigned short                  nRepPort;                                           // ƽ̨RepPort
	unsigned int                    nRep4SDKIp;                                         // ƽ̨��SDK��RepIP
	unsigned short                  nRep4SDKPort;                                       // ƽ̨��SDK��RepPort
    unsigned int                    nNetAdapterIp;                                      // ƽ̨��������
    char                            strUserName[IMVS_MAX_USERNAME_LENGTH];              // �û���
    char                            strPassWord[IMVS_MAX_PASSWORD_LENGTH];              // ����
    char                            strVendorName[IMVS_MAX_VENDORNAME_LENGTH];          // ������
    unsigned int                    nMacLow;                                            // Mac��ַ��4�ֽ�
    unsigned short                  nMacHigh;                                           // Mac��ַ��2�ֽ�

    /****************���ο�������*****************/
    unsigned int                    nClientType;                                        // �ͻ�������  0(VM)��1(���ο���) ��Ͼ������ʹ��
    unsigned int                    nServerType;									    // 0��ʾx86�� 1��ʾMƽ̨
	unsigned int                    nHandleType;									    // �������   0(���������ο���)��1(��������)��2(ȫ�ֽű�)
	unsigned int                    nServerRepIp;                                       // ��������SDK�����RepIP
	unsigned short                  nServerRepPort;                                     // ��������SDK�����RepPort
	unsigned int                    nServerProcID;                                      // ���������з������ID
    unsigned int                    nReserved[2];                                       // �����ֶ�
} IMVS_PLATFORM_BASIC_INFO;

/** @struct IMVS_PLATFORM_INFO_LIST
 *  @brief ƽ̨������Ϣ�б�
 */
typedef struct IMVS_PLATFORM_BASIC_INFO_LIST__
{
    unsigned int                    nNum;                                               // ƽ̨����
    IMVS_PLATFORM_BASIC_INFO        astPlatformBasicInfo[IMVS_MAX_PLATFORM_NUM];        // ƽ̨������Ϣ�б�
} IMVS_PLATFORM_BASIC_INFO_LIST;

typedef struct IMVS_PLATFORM_ABILITY_
{
    unsigned int                    nNum;
    char                            astrModuleName[IMVS_MAX_MODULE_NUM][IMVS_MAX_MODULE_NAME_LENGTH]; // ���128��ģ�飬ÿ��ģ���������64�ֽ�
    // ���Ǳ����ֽ�
} IMVS_PLATFORM_ABILITY;

/** @struct IMVS_OUTPUT_PLATFORM_INFO
 *  @brief ����㷨ƽ̨��Ϣ�ṹ��
 */
typedef struct IMVS_OUTPUT_PLATFORM_INFO__
{
    unsigned int                    nInfoType;                                          // �ص���Ϣ����
    void *                          pData;                                              // �ص�����
    unsigned int                    nDataSize;                                          // �ص����ݷ����ڴ�
    unsigned int                    nDataLen;                                           // �ص�����ʵ�ʳ���
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_OUTPUT_PLATFORM_INFO;

/** @struct IMVS_UNREGISTER_INFO
 *  @brief ��ע����Ϣ
 */
typedef struct IMVS_UNREGISTER_INFO__
{
    unsigned int                    nPubIp;                                             // Pub��Ip
    unsigned short                  nPubPort;                                           // Pub��Port
    unsigned int                    nReserved[4];                                       // �����ֶ�
} IMVS_UNREGISTER_INFO;

typedef struct IMVS_MODULE_RESTART_BEGIN__
{
	char                            strPubAddress[IMVS_DEFINE_PUB_ADDRESS_LENGTH];
    unsigned int                    nReserved[4];
} IMVS_MODULE_RESTART_BEGIN;

typedef struct IMVS_MODULE_RESTART_END__
{
	char                            strPubAddress[IMVS_DEFINE_PUB_ADDRESS_LENGTH];
    unsigned int                    nReserved[4];
} IMVS_MODULE_RESTART_END;

// ���ܹ���Ϣ
typedef struct IMVS_DONGLE_INFO__
{
    int             nDongleStatus;     // ���ܹ�״̬
	char            strDongleType[IMVS_DEFINE_DONGLE_TYPE_LENGTH]; // ���ܹ�����
	int             nCameraNum;        // �������
	int             nRemainTime;       // ʣ��ʱ��
    unsigned int    nReserved[4];      // �����ֶ�
} IMVS_DONGLE_INFO;

// Server��Ϣ
typedef struct IMVS_SERVER_INFO__
{
    int             nServerStatus;  // Server״̬:0��ʾ������������ʾ������
    unsigned int    nReserved[4];   // �����ֶ�
} IMVS_SERVER_INFO;

// Server��Ϣ
typedef struct IMVS_RESULT_FLAG_INFO__
{
    unsigned int    nFlagType;      // Flag���ͣ�1��ʾ��ʼ��2��ʾ����
    unsigned int    nResultNum;     // ��ǰģ��Ľ�����͸���������뾶������X������Y��Բ�ȣ���ô��ֵΪ4
	char            strPubAddress[IMVS_DEFINE_PUB_ADDRESS_LENGTH]; // ��ģ���Pub��ַ
    unsigned int    nIsSelfExecute;
    unsigned int    nReserved[4];   // �����ֶ�
} IMVS_RESULT_FLAG_INFO;

// Heart��Ϣ
typedef struct IMVS_HEART_INFO__
{
    int             nHeartStatus;   // Server ����״̬:0 ��ʾ������������ʾ������
    unsigned int    nReserved[4];   // �����ֶ�
} IMVS_HEART_INFO;

// ģ����������Ϣ, �������ӳ�Ա
typedef struct IMVS_MODULE_RESULT_EXTRA_INFO__
{
    unsigned int    nStatus;
    unsigned int    nCycleID;       // ����ID
	char            strPubAddress[IMVS_DEFINE_PUB_ADDRESS_LENGTH]; // ��ģ���Pub��ַ
    float           fModuleTime;    // ģ��ʱ��,����������ȫ�����￪ʼ���㣬�ӽ��������ݷ��ͳ�ȥ��������
    float           fAlgorithmTime; // �㷨ʱ��
    float           fCallBackTime; // �û��ص���ʼ���û��ص�������ʱ��
    float           fCallBackGetTime; // CallBack�е�Getʱ��
    float           fCallBackSetTime; // CallBack�е�Setʱ��
    float           fTotalCycleTime; // �������̿�ʼ�ұ�ģ�����ʱ��
    float           fTimeTestA;
    float           fTimeTestB;
    float           fTimeTestC;
    float           fTimeTestD;
    float           fTimeTestE;
    unsigned int    nReserved[4];// �����ֽ�
} IMVS_MODULE_RESULT_EXTRA_INFO;

// ģ��״̬��Ϣ
typedef struct IMVS_MODULE_WORK_STAUS__
{
    unsigned int    nWorkStatus;    // 0�ǿ��У�1��æµ
    unsigned int    nProcessID;     // ����ID
    unsigned int    nIsTimeValid;   // ��ʾ����ʱ������ֶ��Ƿ���Ч����Ч������½��治Ҫʹ�á�
    float           fProcessTime;   // ��������ʱ��
	unsigned int    nExecuteCount;  // ����ִ�д���
    char            strReCommand[IMVS_REENTRANT_MAX_CMD_LEN];  //�������봥���ַ���
    unsigned int    nReserved[3];   // �����ֶ�
} IMVS_MODULE_WORK_STAUS;

typedef struct IMVS_SOLUTION_SAVE_BEGEIN_INFO__
{
    unsigned int    nClientType;
	char            strSolPath[IMVS_MAX_PATH_UTF8_LENGTH];
    unsigned int    nReserved[4];
} IMVS_SOLUTION_SAVE_BEGEIN_INFO;

typedef struct IMVS_SOLUTION_SAVE_END_INFO__
{
    unsigned int    nClientType;
    unsigned int    nStatus;
	char            strSolPath[IMVS_MAX_PATH_UTF8_LENGTH];
    unsigned int    nReserved[4];
} IMVS_SOLUTION_SAVE_END_INFO;

typedef struct IMVS_SOLUTION_SAVE_PROCESS_INFO__
{
    unsigned int    nProcess;
    unsigned int    nReserved[4];
} IMVS_SOLUTION_SAVE_PROCESS_INFO;

typedef struct IMVS_SOLUTION_LOAD_BEGEIN_INFO__
{
    unsigned int    nClientType;
	char            strSolPath[IMVS_MAX_PATH_UTF8_LENGTH];
    unsigned int    nReserved[4];
} IMVS_SOLUTION_LOAD_BEGEIN_INFO;

typedef struct IMVS_SOLUTION_LOAD_END_INFO__
{
    unsigned int    nClientType;
    unsigned int    nStatus;
	char            strSolPath[IMVS_MAX_PATH_UTF8_LENGTH];
    unsigned int    nReserved[4];
} IMVS_SOLUTION_LOAD_END_INFO;

typedef struct IMVS_SOLUTION_LOAD_PROCESS_INFO__
{
	unsigned int    nProcess;                   // �����ȷ�Ϻ��޸ģ�ӦΪ����
    unsigned int    nReserved[4];
} IMVS_SOLUTION_LOAD_PROCESS_INFO;

typedef struct IMVS_SOLUTION_LOAD_INTERFACE_FILE_INFO__
{
    unsigned char * pData;
    unsigned int    nDataLen;
    unsigned int    nReserved[4];
} IMVS_SOLUTION_LOAD_INTERFACE_FILE_INFO;

typedef struct IMVS_MODULE_STRING_VALUE_EX__
{
	char            strValue[IMVS_DEFINE_MODULE_RES_STRING_LENGTH];    // V3.0.1�޸ģ�ԭΪ260
    unsigned int    nReserved[4];
} IMVS_MODULE_STRING_VALUE_EX;

typedef struct IMVS_MODULE_IMAGE_VALUE_EX_
{
    char *          pData;  // ʵ������,����nUseRealData�ж��Ƿ�������
    unsigned int    nLen;   // ʵ�����ݳ���
	char            strValue[IMVS_MAX_SHARE_MEMORY_ADDR_LENGTH];  // �����ڴ��ַ,����nUseRealData�ж��Ƿ�������
    unsigned int    nUseRealData;   // 0��ʾʹ�ù����ڴ��ַ��1��ʾʹ��pData��2��ʾ ָ��_����_�����ڴ�
    unsigned int    nMemoryOwner;   // pData�ڴ����б�ʶ��0:���������У�1�����Ǳ������У��������ͷ�
    unsigned int    nReserved[2];
} IMVS_MODULE_IMAGE_VALUE_EX;

typedef struct IMVS_MODULE_CHUNK_VALUE_EX_
{
    char *          pData;  // ʵ������
    unsigned int    nLen;   // ʵ�����ݳ���
	char            strValue[IMVS_MAX_SHARE_MEMORY_ADDR_LENGTH];  // �����ڴ��ַ
    unsigned int    nUseRealData;   // 0��ʾʹ�ù����ڴ��ַ��1��ʾʹ��pData
	unsigned int    nMemoryOwner;   // pData�ڴ����б�ʶ��0:�ڲ����룬1���ⲿ���룬�����ͷ�
    unsigned int    nReserved[2];
} IMVS_MODULE_CHUNK_VALUE_EX;

typedef struct IMVS_MODULE_BYTEDATA_VALUE_EX_
{
	char *          pData;  // ʵ������
	unsigned int    nLen;   // ʵ�����ݳ���
	unsigned int    nReserved[4];
} IMVS_MODULE_BYTEDATA_VALUE_EX;

// sdk4Server�½ӿڻص��޸�
typedef struct IMVS_MODULE_RESULT_INFO_EX__
{
    int             nValueStatus;           // �������������״̬ 1�ɹ�������ֵʧ��
	char            strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];    // ��������
    int             nParamType;             // 1���� 2������ 3�ַ����� 4��ʾͼ�� 5��ʾ������   7 double
    int             nValueNum;              // ģ��������
    int *           pIntValue;              // ��ʱ����
    float *         pFloatValue;            // ��ʱ����
	double *        pDoubleValue;
    IMVS_MODULE_STRING_VALUE_EX * pStringValue;         // ���ڽ����Լ����ο����û����Դ�����ʱ���ȹ̶�,�Ҳ��ö�άָ��
    IMVS_MODULE_IMAGE_VALUE_EX * pImageValue;
    IMVS_MODULE_CHUNK_VALUE_EX * pChunkValue;
	IMVS_MODULE_BYTEDATA_VALUE_EX * pByteValue;
    unsigned int    nReserved[4];
} IMVS_MODULE_RESULT_INFO_EX;

typedef struct IMVS_MODULE_RESULT_RESERVED_INFO__
{
    // char            strModuleName[128];
    unsigned int    nArrivalTimeStampLow;
    unsigned int    nArrivalTimeStampHigh;
    unsigned int    nLeaveTimeStampLow;
    unsigned int    nLeaveTimeStampHigh;
    long long       nRstTime;            // ��
    int             nMilliSec;           // ����
    unsigned int    nReserved[61];
} IMVS_MODULE_RESULT_RESERVED_INFO;

typedef struct IMVS_MODULE_RESULT_INFO_LIST_EX__
{
    // ģ����������Ϣ
    unsigned int    nStatus;                // ����ģ���״̬ 1�ɹ�; 2ģ���쳣��3ǰ���֧ģ���쳣��4 ǰ��ģ���쳣
	unsigned int    nErrorCode;             // �ײ㷵�ش�����
    unsigned int    nCycleID;               // ����ID
    unsigned int    nModuleID;              // ģ��ID
    float           fModuleTime;            // ģ��ʱ��
    float           fAlgorithmTime;         // �㷨ʱ��
    unsigned int    bInCycle;               // �Ƿ�ѭ����ģ��

	char *          pstrModuleName;         // ģ������	
	char *          pstrDisplayName;        // ģ����ʾ����
	IMVS_MODULE_RESULT_RESERVED_INFO * pstResultReservedInfo;
	char *          pReserved[7];

	char            strPubAddress[IMVS_DEFINE_PUB_ADDRESS_LENGTH];    // Pub��ַ
	unsigned int    bIsSelfExecute;         // �Ƿ���ִ��
    unsigned int    nExecuteCount;          // ִ�д���
    unsigned int    nReserved[1];           // �����ֶ�

    // ģ������������
    int             nResultNum;             // �������
    IMVS_MODULE_RESULT_INFO_EX * pInfo;     // �����Ϣ

    char            strReCommand[IMVS_REENTRANT_MAX_CMD_LEN];  //�������봥���ַ���
    unsigned int    nReservedEx[4];         // �����ֶ�
} IMVS_MODULE_RESULT_INFO_LIST_EX;


/************************* ���ο������� **************************/
// ģ������б�
typedef struct IMVS_MODULE_PARAM__
{
    char               strParamName[IMVS_MAX_PARAM_NAME_LENGTH];      // ��������
    char               strParamValue[IMVS_MAX_PARAM_VALUE_LENGTH];    // ����ֵ
    unsigned int       nReserved[4];                                  // �����ֶ�
}IMVS_MODULE_PARAM;

typedef struct IMVS_MODULE_PARAM_LIST__
{
    unsigned int       nParamNum;                                 // ��������
    IMVS_MODULE_PARAM  stModuleParamList[IMVS_MAX_MODULE_PARAM_NUM];    // ģ�����
    unsigned int       nReserved[4];                              // �����ֶ�
}IMVS_MODULE_PARAM_LIST;

// ��̬����������ϵ
typedef struct IMVS_DYNAMIC_PARAM_RELATION__
{
    unsigned int     nObjectID;                              // ID
    char             strName[IMVS_MAX_PARAM_NAME_LENGTH];    // ��������
    unsigned int     nReserved[4];                           // �����ֶ�
}IMVS_DYNAMIC_PARAM_RELATION;

// ��̬����������ϵ�б�
typedef struct IMVS_DYNAMIC_PARAM_RELATION_LIST__
{
    unsigned int     nNum;                                   // ����
    IMVS_DYNAMIC_PARAM_RELATION stRelationList[IMVS_MAX_MODULE_PARAM_NUM];    // ������ϵ
    unsigned int     nReserved[4];                           // �����ֶ�
}IMVS_DYNAMIC_PARAM_RELATION_LIST;

// ��ģ�鵼���������������Ϣ�ṹ
typedef struct IMVS_IMPORT_MODULE_DATA__
{
    char *              pData;                          // �����ļ�����·�������ݳ���
    unsigned int        nDataLen;                       // �����ļ�����·�������ݳ���
    char *              pRealData;
    unsigned int        nRealDataLen;
    unsigned int        nRealDataSize;
    unsigned int        nReserved[1];                   // �����ֶ�
}IMVS_IMPORT_MODULE_DATA;

typedef struct IMVS_IMPORT_MODULE_DATA_INPUT__
{
    unsigned int               nModuleID;                                   // ģ��ID
    unsigned int               nDataType;                                   // ������������
    unsigned int               nDataNum;                                    // �������ݸ���
    IMVS_IMPORT_MODULE_DATA    stImportModuData[IMVS_MAX_IMPORT_NUM];       // ��������
	unsigned int               nRecvTimeout;                                // ���ճ�ʱ
    unsigned int               nReserved[3];                                // �����ֶ�
}IMVS_IMPORT_MODULE_DATA_INPUT;

typedef struct IMVS_IMPORT_MODULE_DATA_OUTPUT__
{
    unsigned int               nModuleID;                                   // ģ��ID
    unsigned int               nDataType;                                   // ������������
    unsigned int               nDataNum;                                    // �������ݸ���
    IMVS_IMPORT_MODULE_DATA    stImportModuData[IMVS_MAX_IMPORT_NUM];       // ��������
    unsigned int               nReserved[4];                                // �����ֶ�
}IMVS_EXPORT_MODULE_DATA_OUTPUT;

// ģ�������쳣��Ϣ�ṹ
typedef struct IMVS_EXCEPTION_HB_MODULE_INFO__
{
    unsigned int    nClientStatus;                                 // ������
    unsigned int    nModuleID;                                     // ģ��ID
    unsigned int    nProcessID;                                    // ����ID
    char            strModuleName[IMVS_MAX_MODULE_NAME_LENGTH];    // ģ������
	char            strDisPlayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // ģ����ʾ����
    unsigned int    nReserved[4];                                  // �����ֶ�
} IMVS_EXCEPTION_HB_MODULE_INFO;

// ƽ̨���������쳣��Ϣ�ṹ
typedef struct IMVS_EXCEPTION_HB_CLIENT_INFO__
{
    unsigned int    nClientStatus;  // ������ 
    unsigned int    nReserved[4];   // �����ֶ�
} IMVS_EXCEPTION_HB_CLIENT_INFO;

// ����ִ�п�ʼ״̬��Ϣ
typedef struct IMVS_STATUS_START_CONTINUOUSLY_INFO__
{
    unsigned int    nStatus;       // ״ֵ̬
    unsigned int    nReserved[4];  // �����ֶ�
} IMVS_STATUS_START_CONTINUOUSLY_INFO;

// ִֹͣ��״̬��Ϣ
typedef struct IMVS_STATUS_STOP_INFO__
{
    unsigned int    nStatus;       // ״ֵ̬
    unsigned int    nReserved[4];  // �����ֶ�
} IMVS_STATUS_STOP_INFO;

// ��ʼ����״̬��Ϣ
typedef struct IMVS_STATUS_START_RUN_INFO__
{
    unsigned int    nStatus;       // ״ֵ̬
    unsigned int    nReserved[4];  // �����ֶ�
} IMVS_STATUS_START_RUN_INFO;

typedef struct IMVS_SOLUTION_VERSION_INFO_
{
	char            strTargetSolutionInfo[IMVS_SOLUTION_VERSION_LENGTH];
	char            strCurrentSolutionInfo[IMVS_SOLUTION_VERSION_LENGTH];
    unsigned int    nReserved[4];
} IMVS_SOLUTION_VERSION_INFO;

typedef struct IMVS_MODULE_RUN_INFO__
{
    unsigned int    nArrivalTimeStampLow;
    unsigned int    nArrivalTimeStampHigh;
    unsigned int    nLeaveTimeStampLow;
    unsigned int    nLeaveTimeStampHigh;
    unsigned int    nReserved[4];
} IMVS_MODULE_RUN_INFO;


typedef struct IMVS_SET_BINARY_DATA_INFO__
{
	char            strName[IMVS_BINARY_DATA_PARAM_LENGTH];
    char *          pBinaryData;
    unsigned int    nBinaryLenth;
    unsigned int    nReserved[4];
} IMVS_SET_BINARY_DATA_INFO;


typedef struct IMVS_GET_BINARY_LENGTH_INFO__
{
	char            strName[IMVS_BINARY_DATA_PARAM_LENGTH];
    unsigned int    nBinaryLength;
    unsigned int    nReserved[4];
} IMVS_GET_BINARY_LENGTH_INFO;

typedef struct IMVS_GET_BINARY_DATA_INFO__
{
	char            strName[IMVS_BINARY_DATA_PARAM_LENGTH];
    unsigned int    nBinaryDataMallocSize;
    char *          pBinaryData; // ���û������С,�ȵ���IMVS_GetBinaryLength�ӿ�
    unsigned int    nBinaryLength;
    unsigned int    nReserved[4];
} IMVS_GET_BINARY_DATA_INFO;

// ���ȡͼ��Ϣ�ṹ
typedef struct IMVS_CAMERA_COLLECT_INFO__
{
    unsigned int nCameraID;     // CH: ���ID | EN: Camera ID
    unsigned int nFrameNum;     // CH: ͼ��֡�� | EN: Frame number
    char strCameraSN[IMVS_CAMERA_MAX_SN_LEN];  // CH: ���SN | EN: Camera SN
	unsigned int nCollectStatus;// CH: ȡͼ״̬ | EN: Collect Status
    unsigned int nReserved[3];  // CH: �����ֶ� | EN: Reserved
} IMVS_CAMERA_COLLECT_INFO;

// �������״̬��Ϣ�ṹ
typedef struct IMVS_CAMERA_CONNECT_STATUS_INFO__
{
	unsigned int nCameraID;     // CH: ���ID | EN: Camera ID
	char strCameraSN[IMVS_CAMERA_MAX_SN_LEN];  // CH: ���SN | EN: Camera SN
	unsigned int nConnectStatus;// CH: ����״̬��0-���ߣ�1-���ߣ� | EN: Connect Status��0-down��1-up��
	unsigned int nReserved[4];  // CH: �����ֶ� | EN: Reserved
} IMVS_CAMERA_CONNECT_STATUS_INFO;

// CH: ͨ��������Ϣ�ṹ | EN: Communication connect information structure
typedef struct IMVS_COMMUNICATION_CONNECT_INFO__
{
    unsigned int nDeviceStatus;                                // CH: �豸״̬ | EN: Device Status
    unsigned int nDeviceID;                                    // CH: �豸ID | EN: Device ID
    unsigned int nReserved[4];                                 // CH: �����ֶ� | EN: Reserved
}IMVS_COMMUNICATION_CONNECT_INFO_INFO;

/**************************�㷨ƽ̨V3.0����**************************/
typedef struct IMVS_ADD_MODULE_INFO_LIST__
{
    unsigned int nAddNum;                              // ����������ģ������
    unsigned int nAddModuleID[IMVS_MAX_ADD_MODULE_NUM];// ����������ģ��ID
    unsigned int nReserved[4];                         // �����ֶ�
}IMVS_ADD_MODULE_INFO_LIST;

typedef struct IMVS_DEL_MODULE_INFO_LIST__
{
    unsigned int nDelNum;                              // ������ɾ��ģ������
    unsigned int nDelModuleID[IMVS_MAX_DEL_MODULE_NUM];// ������ɾ��ģ��ID
    unsigned int nReserved[4];                         // �����ֶ�
}IMVS_DEL_MODULE_INFO_LIST;

typedef struct IMVS_PROCESS_INFO__
{
    unsigned int                    nProcID;                                      // ����ID
    char                            chProcName[IMVS_MAX_PROCESS_NAME_LENGTH];     // ��������
    unsigned int                    nModuleType;                                  // ģ������
	char                            strProcGUID[IMVS_DEFAULT_GUID_LEN];           // ����GUID (V3.2.0 ����)
	int                             nInitErrorCode;                               // ��ʼ�����,0��ʾOK��������ʾ������
    unsigned int                    nReserved[4];                                 // �����ֶ�
}IMVS_PROCESS_INFO;

typedef struct IMVS_ALGORITHM_INIT_RESULT_INFO__
{
    unsigned int    nModuleID;                                   // ģ��ID
    unsigned int    nType;                                       // ������ģ�鴫����������
    char            strTransData[IMVS_MAX_TRANS_DATA_LENGTH];    // �㷨�������
    unsigned int    nReserved[4];                                // �����ֶ�
}IMVS_ALGORITHM_INIT_RESULT_INFO;

typedef struct IMVS_COMMU_REPORT_DATA_INFO__
{
	int    nType;                                       // ͨ������
	char * pData;                                       // �ϱ�����
	int    nLen;                                        // ���ݳ���
	int    nReserved[4];                                // �����ֶ�
}IMVS_COMMU_REPORT_DATA_INFO;

typedef struct IMVS_PROCESS_INFO_LIST__
{
    unsigned int         nNum;                                    // ���̸���
    IMVS_PROCESS_INFO    astProcessInfo[IMVS_MAX_PROCESS_NUM];    // ������Ϣ�б�
    unsigned int         nReserved[4];                            // �����ֶ�
} IMVS_PROCESS_INFO_LIST;

// ������������ִ�п�ʼ״̬��Ϣ
typedef struct IMVS_STATUS_PROCESS_START_CONTINUOUSLY_INFO__
{
    unsigned int    nStatus;       // ״ֵ̬
    unsigned int    nProcessID;    // ����ID
    unsigned int    nReserved[4];  // �����ֶ�
} IMVS_STATUS_PROCESS_START_CONTINUOUSLY_INFO;

// ��������ִֹͣ��״̬��Ϣ
typedef struct IMVS_STATUS_PROCESS_STOP_INFO__
{
    unsigned int    nStatus;       // ״ֵ̬
    unsigned int    nProcessID;    // ����ID
	unsigned int    nStopAction;   // ����ֹͣ��ԭ�� (0:��Ч; 1:����ֹͣ; 2:����NG; 3:ģ������ֹͣ����)
    unsigned int    nReserved[3];  // �����ֶ�
} IMVS_STATUS_PROCESS_STOP_INFO;

// ƽ̨��ϸ��Ϣ
typedef struct IMVS_PLATFORM_DETAILED_INFO__
{
    char            strSolutionPath[IMVS_MAX_PATH_UTF8_LENGTH];    // ����·��
    char            strPassWord[IMVS_MAX_PASSWORD_LENGTH];    // ��������
    unsigned int    nReserved[4];    // �����ֶ�
} IMVS_PLATFORM_DETAILED_INFO;

// �ӹ�״̬��Ϣ
typedef struct IMVS_STATUS_TAKEOVER_INFO__
{
    unsigned int    nTakeoverStatus;    // ״ֵ̬
    unsigned int    nReserved[4];       // �����ֶ�
} IMVS_STATUS_TAKEOVER_INFO;

// �Զ����ط�����Ϣ�ṹ
typedef struct IMVS_AUTO_LOAD_SOLUTION_INFO__
{
    unsigned int    nIfAutoLoad;             // �Ƿ��Զ�����
	char            strSolutionPath[IMVS_MAX_PATH_UTF8_LENGTH];    // ����·��
    char            strPassWord[IMVS_MAX_PASSWORD_LENGTH];         // ��������
    unsigned int    nExecuteStatus;          // ִ��״̬ ������ʱ��ִ�У�0��ִ��һ�Σ�1������ִ�У�2��
    unsigned int    nReserved[4];            // �����ֶ�
} IMVS_AUTO_LOAD_SOLUTION_INFO;

// ����ƽ̨��ʼ��Ϣ
typedef struct IMVS_DETAIL_PLATFORM_BEGIN_INFO__
{
    unsigned int    nClientType;             // �ͻ�������
    unsigned int    nReserved[4];            // �����ֶ�
} IMVS_DETAIL_PLATFORM_BEGIN_INFO;

// ����ִ��״̬��Ϣ
typedef struct IMVS_PROC_CONTIEXECUTE_INFO__
{
    unsigned int    nProcessID;             // ����ID
    unsigned int    nProcRunStatus;         // ��������ִ��״̬��0����ʾ��ִ��״̬��1����ʾ����ִ��״̬��
    unsigned int    nReserved[4];           // �����ֶ�
} IMVS_PROC_CONTIEXECUTE_INFO;

// ����ִ��״̬��Ϣ�б�
typedef struct IMVS_PROC_CONTIEXECUTE_INFO_LIST__
{
    unsigned int                   nNum;                   // ��������
    IMVS_PROC_CONTIEXECUTE_INFO    stProcExecuteInfo[IMVS_MAX_PROCESS_NUM];    // ��������ִ��״̬��Ϣ
    unsigned int                   nReserved[4];           // �����ֶ�
} IMVS_PROC_CONTIEXECUTE_INFO_LIST;

// ����ƽ̨������Ϣ
typedef struct IMVS_DETAIL_PLATFORM_END_INFO__
{
    unsigned int    nClientType;             // �ͻ�������
    int             nErrorCode;              // ������
    unsigned int    nReserved[4];            // �����ֶ�
} IMVS_DETAIL_PLATFORM_END_INFO;

// ��Դռ��״̬��Ϣ
typedef struct IMVS_RESOURCE_USAGE_INFO__
{
    int             nMemUsage;               // �ڴ�ʹ����
    int             nCPUUsage;               // CPUʹ����
    int             nHardSpace;              // ��������Ӳ��ʣ��ռ䣨��λMB��
	int             nNetWorkUsage;           // ����ʹ����
    unsigned int    nReserved[3];            // �����ֶ�
} IMVS_RESOURCE_USAGE_INFO;

// �������״̬��Ϣ
typedef struct IMVS_PROXY_CRASH_SP_INFO__
{
	int             nHasSolStatu;            // �Ƿ���ڷ���״̬ 0�����������ڣ�1����������
	unsigned int    nReserved[4];            // �����ֶ�
} IMVS_PROXY_CRASH_SP_INFO;

// �������״̬��Ϣ
typedef struct IMVS_GLOBALSCRIPT_CRASH_INFO__
{
	unsigned int    nStatus;                 // ȫ�ֽű�����״̬
	unsigned int    nReserved[4];            // �����ֶ�
} IMVS_GLOBALSCRIPT_CRASH_INFO;

// ȫ�ֽű��ϱ�������Ϣ
typedef struct IMVS_GLOBALSCRIPT_REPORTDATA_INFO__
{
	unsigned char * pData;         // ȫ�ֽű��ϱ�����
	unsigned int    nDataLen;      // �ϱ����ݳ���
	unsigned int    nReserved[4];  // �����ֶ�
} IMVS_GLOBALSCRIPT_REPORTDATA_INFO;

// ���ط����Ƿ�ִ����ԴԤ������Ϣ
typedef struct IMVS_EXECUTE_STATE_AFTER_LOAD_INFO__
{
	int             nStatus;                 // ���ط����Ƿ�ִ��״̬
	unsigned int    nReserved[4];            // �����ֶ�
} IMVS_EXECUTE_STATE_AFTER_LOAD_INFO;

// ���̽�ע����Ϣ 
typedef struct IMVS_PROCEDURE_UNREGISTER_INFO__
{
	unsigned int    nClientType;   // �ͻ�������
	unsigned int    nProcessID;    // ɾ������ID
	int             nErrorCode;    // ɾ������״̬
	char            strProcessName[IMVS_MAX_PROCESS_NAME_LENGTH]; // ��������
	unsigned int    nReserved[4];  // �����ֶ�
} IMVS_PROCEDURE_UNREGISTER_INFO;

// ģ����������Ϣ
typedef struct IMVS_MODULE_BASIC_INFO__
{
    unsigned int   nModuleID;                                      // ģ��ID
	char           strDisplayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // ������ʾ����
    char           strModuleName[IMVS_MAX_MODULE_NAME_LENGTH];     // ģ������
    unsigned int   nReserved[16];                                  // �����ֶ�
} IMVS_MODULE_BASIC_INFO;

// ģ����������Ϣ�б�
typedef struct IMVS_MODULE_BASIC_INFO_LIST__
{
    unsigned int                    nNum;                                  // ģ�����
    IMVS_MODULE_BASIC_INFO          astModuleInfo[IMVS_MAX_MODULE_NUM];    // ģ����Ϣ�б�
    unsigned int                    nReserved[4];                          // �����ֶ�
} IMVS_MODULE_BASIC_INFO_LIST;

/** @struct IMVS_CUSTOM_SUBSCRIBE_INFO
 *  @brief ������Ϣ
 */
typedef struct IMVS_CUSTOM_SUBSCRIBE_INFO__
{
	unsigned int nIfDelete;                                                // �Ƿ�Ϊɾ��������Ϣ 1-ɾ����0-����
	unsigned int nOutputType;                                              // ����������ͣ�1-���ͣ�2-�����ͣ�3-�ַ����ͣ�4-ͼ���ͣ�5-��������
	unsigned int nSubProcessID;                                            // ���ķ� ����ID
	char         strInputParamName[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];     // ����:�û��Զ������ò�������
	unsigned int nPubModuleID;                                             // �������������ķ�ģ��ID��
	char         strOutputParamName[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];    // ����:�����ķ�ģ���������
	unsigned int nIsPubConstant;                                           // �Ƿ��ĳ�����0-�������ģ�1-��������
	unsigned int nIndexModuleID;                                           // �����±��Ӧģ��ID
	char         strIndexContent[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];       // �����±궩���ֶΣ�Ĭ��ȫ������Ϊ"All"
	unsigned int nIsIndexConstant;                                         // �����±��Ƿ��ĳ�����0-�������ģ�1-��������
	unsigned int nReserved[4];                                             // �����ֶ�
} IMVS_CUSTOM_SUBSCRIBE_INFO;

typedef struct IMVS_VARIABLE_PARAM_VALUE__
{
	int  nModuleId;                     // ģ��ID
	char chParamName[IMVS_MAX_PARAM_NAME_LENGTH];  // ��������
	char chReserve[64];                 // �����ֶ�
}IMVS_VARIABLE_PARAM_VALUE;

typedef struct IMVS_CUSTOM_SUBSCRIBE_VALUE__
{
	unsigned int            nOutputType;           // ����������ͣ�1-���ͣ�2-�����ͣ�3-�ַ����ͣ�4-ͼ���ͣ�5-��������
	unsigned int            nVarType;              // �����ı�������
	char chOutputName[IMVS_MAX_PARAM_NAME_LENGTH]; // �û����ò�������
	char chConstantValue[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH]; // ����
	IMVS_VARIABLE_PARAM_VALUE stVariableValue;               // ����
}IMVS_CUSTOM_SUBSCRIBE_VALUE;

/** @struct IMVS_GET_CUSTOM_SUBSCRIBE_INFO_LIST
 *  @brief �û��Զ���������Ļ�ȡ��Ϣ
 */
typedef struct IMVS_GET_CUSTOM_SUBSCRIBE_INFO_LIST__
{
	unsigned int                nOutputNum;        // ����ֶ�����
	unsigned int                nTotalNum;         // ����ֶ�����
	IMVS_CUSTOM_SUBSCRIBE_VALUE stCustomSubInfo[IMVS_DEFINE_CUSTOM_OUTPUT_PAGE_SIZE]; // ģ�����������Ϣ
	unsigned int    nReserved[4];                  // �����ֶ�
} IMVS_GET_CUSTOM_SUBSCRIBE_INFO_LIST;

/**************************** V3.2.0 �����Ż����� ***************************/
// ���ط����ϱ�������Ϣ
typedef struct IMVS_LOAD_MODULE_ERROR_INFO__
{
	unsigned int nModuleID;                                  // ģ��ID
	char         strModuleName[IMVS_MAX_MODULE_NAME_LENGTH]; // ģ������
	int          nErrorCode;                                 // ������
} IMVS_LOAD_MODULE_ERROR_INFO;

// ���ط����ϱ�������Ϣ�б�
typedef struct IMVS_LOAD_MODULE_ERROR_INFO_LIST__
{
	unsigned int nClientType;                   // �ͻ�������
	unsigned int nModuleNum;                    // �ϱ�������Ϣģ������
	IMVS_LOAD_MODULE_ERROR_INFO astLoadModuErrInfo[IMVS_MAX_MODULE_NUM]; // ���ط����ϱ�������Ϣ
	unsigned int nReserved[4];                  // �����ֶ�
} IMVS_LOAD_MODULE_ERROR_INFO_LIST;

// V3.2.0 �����Ż�����
typedef struct IMVS_CAMERA_PIC_INFO__
{
	int  nCameraId;                            // ���ģ��Id
	char szLocalPicPath[IMVS_MAX_PATH_UTF8_LENGTH]; // ����ͼƬ·����utf8����
}IMVS_CAMERA_PIC_INFO;

// ���ͼ����Ϣ�б�
typedef struct IMVS_CAMERA_PIC_INFO_LIST__
{
	int nNum;                                                        // �б�ʵ�ʴ�С
	IMVS_CAMERA_PIC_INFO stCamPicInfoList[IMVS_CAMPICINFO_LIST_NUM]; // ���ͼ����Ϣ�б�
	int                  nTimeout;                                   // �ӿڳ�ʱ
	unsigned int         nIsAllModuRun;                              // �Ƿ�����ģ��ִ�У�0�����ѧϰģ�飬1������ģ�飩
	unsigned int         nReserved[3];                               // �����ֶ�
}IMVS_CAMERA_PIC_INFO_LIST;

// �û��Զ����������в�����Ϣ�ṹ
typedef struct IMVS_PROCEDURE_CUSTOM_RUN_POLICY__
{
	int          nProcessID;       // ����ID
	int          nThreadNum;       // ָ��������ִ���߳���Ŀ
	char         chCpuCore[IMVS_MAX_CORE_NUM]; // ָ���������е�CPU���� CPU�����飬0-��Ч��1-��Ч��
	                                           // byCpuCore[0]��ʾcpu0��byCpuCore[1]��ʾcpu1, byCpuCore[2]��ʾcpu2...
	unsigned int nReserved[4];     // �����ֶ�
}IMVS_PROCEDURE_CUSTOM_RUN_POLICY;

// �û��Զ����������в�����Ϣ�б�ṹ
typedef struct IMVS_PROCEDURE_CUSTOM_RUN_POLICY_LIST__
{
	int nNum;                                           // �������ø���
	IMVS_PROCEDURE_CUSTOM_RUN_POLICY stPolicyList[IMVS_MAX_RUN_POLICY_NUM]; // ��������
	unsigned int nReserved[4];     // �����ֶ�
}IMVS_PROCEDURE_CUSTOM_RUN_POLICY_LIST;

// �������в���ö������
typedef enum IMVS_PROCEDURE_RUN_POLICY_TYPE__
{
	PROCEDURE_RUN_POLICY_INVALID = 0,     // ��Ч
	PROCEDURE_RUN_POLICY_HIGH_SPEED = 1,  // ��������ģʽ��Ĭ�ϣ�
	PROCEDURE_RUN_POLICY_CUSTOM = 2,       // �û��Զ������з�ʽ
    PROCEDURE_RUN_POLICY_TIME_STABILITY = 3  // ��֤��ʱ�ȶ��� V4.2����
}IMVS_PROCEDURE_RUN_POLICY_TYPE;

// �������в���
typedef struct IMVS_PROCEDURE_RUN_POLICY__
{
	unsigned int nRunPolicy;      // �������з�ʽ (IMVS_PROCEDURE_RUN_POLICY_TYPE������)
	int          nCustomIndex;    // ��nRunModeΪ PROCEDURE_RUN_POLICY_CUSTOMʱ��Ч����ȡʱ����������������IMVS_MAX_RUN_POLICY_NUMʱ��ָ��ȡֵ��ʼ����
	IMVS_PROCEDURE_CUSTOM_RUN_POLICY_LIST stCustomRunPolicy; // ��nRunPolicyΪ PROCEDURE_RUN_POLICY_CUSTOM ʱ��Ч
	unsigned int nReserved[4];    // �����ֶ�
}IMVS_PROCEDURE_RUN_POLICY;

// �ײ����ڻ�����������Ϣ�ṹ
typedef struct IMVS_PROCESSOR_INFO__
{
	int          nLogicProcessorNum;    // �߼�����������
	char         strReserved[512];      // �����ֶ�
	unsigned int nReserved[4];          // �����ֶ�
}IMVS_PROCESSOR_INFO;

/**************************** V3.3.0 ���� ***************************/
// Group2.0ģ����Ϣ�ṹ
typedef struct IMVS_GROUP_MODULE_INFO__
{
	unsigned int nGroupId;                        // Groupģ��ID
	int          nSonModuNum;                     // ��ģ������
	unsigned int anModuleId[IMVS_MAX_MODULE_NUM]; // Group��ģ��ID�б�
	unsigned int nReserved[4];                    // �����ֶ�
}IMVS_GROUP_MODULE_INFO;

// Group������ʼ��Ϣ
typedef struct IMVS_EXPORT_GROUP_BEGIN_INFO__
{
	unsigned int    nClientType;  // �ͻ�������
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_EXPORT_GROUP_BEGIN_INFO;

// Group����������Ϣ
typedef struct IMVS_EXPORT_GROUP_END_INFO__
{
	unsigned int    nGroupId;                           // Groupģ��ID
	unsigned int    nClientType;                        // �ͻ�������
	char            strGroupPath[IMVS_MAX_PATH_UTF8_LENGTH]; // Group�ļ�·��
	int             nErrorCode;                         // ������
	unsigned int    nReserved[4];                       // �����ֶ�
} IMVS_EXPORT_GROUP_END_INFO;

// Group����������Ϣ
typedef struct IMVS_EXPORT_GROUP_PROGRESS_INFO__
{
	unsigned int    nProgress;     // ����
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_EXPORT_GROUP_PROGRESS_INFO;

// Group���뿪ʼ��Ϣ
typedef struct IMVS_IMPORT_GROUP_BEGIN_INFO__
{
	unsigned int    nClientType;  // �ͻ�������
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_IMPORT_GROUP_BEGIN_INFO;

// Group���������Ϣ
typedef struct IMVS_IMPORT_GROUP_END_INFO__
{
	unsigned int    nProcessId;                         // ����ID
	unsigned int    nClientType;                        // �ͻ�������
	char            strGroupPath[IMVS_MAX_PATH_UTF8_LENGTH]; // Group�ļ�·��
	int             nErrorCode;                         // ������
	unsigned int    nGroupNewId;                        // ����Groupģ����ID
	char            strGroupNewName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // ����Groupģ��������
	unsigned int    nReserved[4];                       // �����ֶ�
} IMVS_IMPORT_GROUP_END_INFO;

// Group���������Ϣ
typedef struct IMVS_IMPORT_GROUP_PROGRESS_INFO__
{
	unsigned int    nProgress;     // ����
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_IMPORT_GROUP_PROGRESS_INFO;

// Group ����ģ����������ID��Ϣ
typedef struct IMVS_GROUP_NEW_MODULEID_NAME_INFO__
{
	unsigned int    nNewModuID;   // ��ģ��ID
	unsigned int    nOldModuID;   // ԭģ��ID
	char            strModuNewName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // ģ��������
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_GROUP_NEW_MODULEID_NAME_INFO;

// Group ����ģ����������ID��Ϣ�б�
typedef struct IMVS_GROUP_NEW_MODULEID_NAME_INFO_LIST__
{
	unsigned int    nNum;         // ģ������
	IMVS_GROUP_NEW_MODULEID_NAME_INFO astModuIdName[IMVS_MAX_MODULE_NUM]; // ģ��GUID����ID��Ϣ
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_GROUP_NEW_MODULEID_NAME_INFO_LIST;

// Group ��������ļ�����
typedef struct IMVS_GROUP_IMPORT_INTERFACE_FILE_INFO__
{
	char *          pData;
	unsigned int    nDataLen;
	unsigned int    nReserved[4];
} IMVS_GROUP_IMPORT_INTERFACE_FILE_INFO;

// Group���������Ϣ
typedef struct IMVS_GROUP_IO_INFO__
{
	unsigned int    nValueType;    // �����������ֵ����: 1���� 2������ 3�ַ����� 4��ʾͼ�� 5��ʾ������
	char            strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH]; // ��������
} IMVS_GROUP_IO_INFO;

// Group���������Ϣ�б�
typedef struct IMVS_GROUP_IO_INFO_LIST__
{
	unsigned int       nGroupId;                                 // Groupģ��ID
	unsigned int       nInputNum;                                // Group������Ϣ����
    IMVS_GROUP_IO_INFO stGroupInput[IMVS_MAX_OBJECT_IO_NUM];   // Group������Ϣ�б�
	unsigned int       nOutputNum;                               // Group�����Ϣ����
    IMVS_GROUP_IO_INFO stGroupOutput[IMVS_MAX_OBJECT_IO_NUM];  // Group�����Ϣ�б�
	unsigned int       nReserved[4];                             // �����ֶ�
} IMVS_GROUP_IO_INFO_LIST;

// �������������Ϣ
typedef struct IMVS_PROCEDURE_IO_INFO__
{
	unsigned int    nValueType;    // �����������ֵ����: 1���� 2������ 3�ַ����� 4��ʾͼ�� 5��ʾ������
	char            strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH]; // ��������
} IMVS_PROCEDURE_IO_INFO;

// �������������Ϣ�б�
typedef struct IMVS_PROCEDURE_IO_INFO_LIST__
{
	unsigned int       nProcedureId;                             // ����ģ��ID
	unsigned int       nInputNum;                                // ����������Ϣ����
    IMVS_PROCEDURE_IO_INFO stProcInput[IMVS_MAX_OBJECT_IO_NUM];  // ����������Ϣ�б�
	unsigned int       nOutputNum;                               // ���������Ϣ����
    IMVS_PROCEDURE_IO_INFO stProcOutput[IMVS_MAX_OBJECT_IO_NUM]; // ���������Ϣ�б�
	unsigned int       nReserved[4];                             // �����ֶ�
} IMVS_PROCEDURE_IO_INFO_LIST;

// ������ģ���������������
typedef enum IMVS_ENUM_SUBSCRIBE_INDEX_TYPE__ : int
{
	SUBSCRIBE_INDEX_INVALID  = 0,  // ��Ч
	SUBSCRIBE_INDEX_ALL      = 1,  // ����ȫ��
	SUBSCRIBE_INDEX_CONSTANT = 2,  // ��������
	SUBSCRIBE_INDEX_VARIABLE = 3   // ����
}IMVS_ENUM_SUBSCRIBE_INDEX_TYPE;

// ����ģ����Ϣ�ṹ
typedef struct IMVS_SUBSCRIBE_MODULE_PARAM_INFO__
{
	int  nModuleId;                                // ģ��ID
	char byParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];  // ������
} IMVS_SUBSCRIBE_MODULE_PARAM_INFO;

// ����������Ϣ�ṹ
typedef struct IMVS_VARIABLE_VALUE_INFO__
{
	IMVS_ENUM_SUBSCRIBE_INDEX_TYPE eIndexType;                // �����ı�������
	char strIndexConstant[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH]; // ��������ֵ (ȫ��������All)
	IMVS_SUBSCRIBE_MODULE_PARAM_INFO stIndexVariable;         // ��������ֵ
	IMVS_SUBSCRIBE_MODULE_PARAM_INFO stModuleParam;           // ������ģ�����
} IMVS_VARIABLE_VALUE_INFO;

// �����ı�������
typedef enum IMVS_ENUM_SUBSCRIBE_VAR_TYPE__ : int
{
	SUBSCRIBE_VAR_INVAlID  = 0,   // ��Ч
	SUBSCRIBE_VAR_CONSTANT = 1,   // ����
	SUBSCRIBE_VAR_GLOBAL   = 2,   // ȫ���ַ���
	SUBSCRIBE_VAR_VARIABLE = 3    // ����
}IMVS_ENUM_SUBSCRIBE_VAR_TYPE;

// ģ�鶩����Ϣ�ṹ
typedef struct IMVS_SUBSCRIBE_MODU_PARAM_INFO__
{
	IMVS_ENUM_SUBSCRIBE_VAR_TYPE eVarType;                    // �����ı�������
	char strConstantValue[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH]; // ����
	IMVS_VARIABLE_VALUE_INFO     stVariableValue;             // ����
} IMVS_SUBSCRIBE_MODU_PARAM_INFO;

// ģ������������
typedef enum IMVS_ENUM_MODULE_RESULT_TYPE__ : unsigned int
{
	IMVS_MODURES_TYPE_INVALID = 0,                        // ��Ч����
	IMVS_MODURES_TYPE_INT     = 1,                        // ��������
	IMVS_MODURES_TYPE_FLOAT   = 2,                        // ����������
	IMVS_MODURES_TYPE_STRING  = 3,                        // �ַ���������
	IMVS_MODURES_TYPE_IMAGE   = 4,                        // ͼ��������
	IMVS_MODURES_TYPE_CHUNK   = 5,                        // ��������������
	IMVS_MODURES_TYPE_BYTEDATA= 6,                         // ������������������
	IMVS_MODURES_TYPE_DOUBLE = 7                        // DOUBLE������������
}IMVS_ENUM_MODULE_RESULT_TYPE;

// ȫ�ֱ����󶨲�����Ϣ�ṹ
typedef struct IMVS_BIND_GLOBALVAR_PARAM_INFO__
{
	unsigned int nModuleId;                              // ȫ�ֱ���ģ��ID
	IMVS_ENUM_MODULE_RESULT_TYPE eGlobalVarType;         // ȫ�ֱ�������
	char strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];// ȫ�ֱ�������
	IMVS_SUBSCRIBE_MODU_PARAM_INFO stBindValue;          // ȫ�ֱ�����ֵ
} IMVS_BIND_GLOBALVAR_PARAM_INFO;

// ȫ�ֱ����󶨲�����Ϣ�б�ṹ
typedef struct IMVS_BIND_GLOBALVAR_PARAM_INFO_LIST__
{
	unsigned int nNum;                                   // ȫ�ֱ����󶨲�������
	IMVS_BIND_GLOBALVAR_PARAM_INFO astBindGlobalVarList[IMVS_MAX_MODULE_PARAM_NUM]; // ȫ�ֱ����󶨲�����Ϣ
	unsigned int       nReserved[4];                     // �����ֶ�
} IMVS_BIND_GLOBALVAR_PARAM_INFO_LIST;

// ��ȡȫ�ֱ����󶨲�����Ϣ�б�ṹ
typedef struct IMVS_GET_BIND_GLOBALVAR_PARAM_INFO_LIST__
{
	unsigned int nTotalNum;                              // ȫ�ֱ����󶨲�������
	unsigned int nNum;                                   // ȫ�ֱ����󶨲�������
	IMVS_BIND_GLOBALVAR_PARAM_INFO astBindGlobalVarList[IMVS_MAX_MODULE_PARAM_NUM]; // ȫ�ֱ����󶨲�����Ϣ
	unsigned int       nReserved[4];                     // �����ֶ�
} IMVS_GET_BIND_GLOBALVAR_PARAM_INFO_LIST;

// ȡ��ȫ�ֱ����󶨲�����Ϣ�ṹ
typedef struct IMVS_UNBIND_GLOBALVAR_PARAM_INFO__
{
	unsigned int nModuleId;                              // ȫ�ֱ���ģ��ID
	IMVS_ENUM_MODULE_RESULT_TYPE eGlobalVarType;         // ȫ�ֱ�������
	char strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];       // ȫ�ֱ�������
} IMVS_UNBIND_GLOBALVAR_PARAM_INFO;

// ȡ��ȫ�ֱ����󶨲�����Ϣ�б�ṹ
typedef struct IMVS_UNBIND_GLOBALVAR_PARAM_INFO_LIST__
{
	unsigned int nNum;                                   // ȫ�ֱ����󶨲�������
	IMVS_UNBIND_GLOBALVAR_PARAM_INFO astBindGlobalVarList[IMVS_MAX_MODULE_PARAM_NUM]; // ȫ�ֱ����󶨲�����Ϣ
	unsigned int       nReserved[4];                     // �����ֶ�
} IMVS_UNBIND_GLOBALVAR_PARAM_INFO_LIST;


// ģ������󶨹ؼ��ֲ�����Ϣ�ṹ
typedef struct IMVS_BIND_MODULE_PARAM_INFO__
{
	unsigned int nModuleId;                              // ģ��ID
	IMVS_ENUM_MODULE_RESULT_TYPE eVarType;               // ��������
	char strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];// ��������
	IMVS_SUBSCRIBE_MODU_PARAM_INFO stBindValue;          // ������ֵ
} IMVS_BIND_MODULE_PARAM_INFO;

// ģ������󶨹ؼ��ֲ�����Ϣ�б�ṹ
typedef struct IMVS_BIND_MODULE_PARAM_INFO_LIST__
{
	unsigned int nNum;                                   // �����󶨲�������
	IMVS_BIND_MODULE_PARAM_INFO astBindModuVarList[IMVS_MAX_MODULE_PARAM_NUM]; // �����󶨲�����Ϣ
	unsigned int       nReserved[4];                     // �����ֶ�
} IMVS_BIND_MODULE_PARAM_INFO_LIST;

// ��ȡģ������󶨹ؼ��ֲ�����Ϣ�б�ṹ
typedef struct IMVS_GET_BIND_MODULE_PARAM_INFO_LIST__
{
	unsigned int nTotalNum;                              // �����󶨲�������
	unsigned int nNum;                                   // �����󶨲�������
	IMVS_BIND_MODULE_PARAM_INFO astBindModuVarList[IMVS_MAX_MODULE_PARAM_NUM]; // �����󶨲�����Ϣ
	unsigned int       nReserved[4];                     // �����ֶ�
} IMVS_GET_BIND_MODULE_PARAM_INFO_LIST;

// ȡ��ģ������󶨹ؼ��ֲ�����Ϣ�ṹ
typedef struct IMVS_UNBIND_MODULE_PARAM_INFO__
{
	unsigned int nModuleId;                              // ����ģ��ID
	IMVS_ENUM_MODULE_RESULT_TYPE eVarType;               // ��������
	char strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];// ��������
} IMVS_UNBIND_MODULE_PARAM_INFO;

// ȡ��ģ������󶨹ؼ��ֲ�����Ϣ�б�ṹ
typedef struct IMVS_UNBIND_MODULE_PARAM_INFO_LIST__
{
	unsigned int nNum;                                   // �����󶨲�������
	IMVS_UNBIND_MODULE_PARAM_INFO astBindModuVarList[IMVS_MAX_MODULE_PARAM_NUM]; // �����󶨲�����Ϣ
	unsigned int       nReserved[4];                     // �����ֶ�
} IMVS_UNBIND_MODULE_PARAM_INFO_LIST;
/**************************** V3.4.0 ���� ***************************/
// ���ؽ������̸���������Ϣ�ṹ
typedef struct IMVS_UPDATE_PROCESS_NAME_INFO__
{
	unsigned int nProcessID;       // ����ID
	char         strProcessName[IMVS_MAX_PROCESS_NAME_LENGTH];       // ��������
} IMVS_UPDATE_PROCESS_NAME_INFO;

// ���ؽ������̸���������Ϣ�б�ṹ
typedef struct IMVS_UPDATE_PROCESS_NAME_INFO_LIST__
{
	int nNum;                     // ��������
	IMVS_UPDATE_PROCESS_NAME_INFO astProcNameInfoList[IMVS_MAX_PROCESS_NUM]; // ���̸���������Ϣ�б�
} IMVS_UPDATE_PROCESS_NAME_INFO_LIST;

// ���ؽ���ģ�����������Ϣ�ṹ
typedef struct IMVS_UPDATE_MODULE_NAME_INFO__
{
	unsigned int nModuleID;       // ģ��ID
	char         strModuleName[IMVS_MAX_MODULE_NAME_LENGTH];        // ģ������
} IMVS_UPDATE_MODULE_NAME_INFO;

// ���ؽ���ģ�����������Ϣ�б�ṹ
typedef struct IMVS_UPDATE_MODULE_NAME_INFO_LIST__
{
	int nNum;                     // ģ������
	IMVS_UPDATE_MODULE_NAME_INFO astModuleNameInfoList[IMVS_MAX_MODULE_NUM]; // ģ�����������Ϣ�б�
} IMVS_UPDATE_MODULE_NAME_INFO_LIST;

// �������̿�ʼ
typedef struct IMVS_EXPORT_PROCESS_BEGIN_INFO__
{
	unsigned int    nProcessId;   // ��������ID
	unsigned int    nClientType;  // �ͻ�������
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_EXPORT_PROCESS_BEGIN_INFO;

// �������̽�����Ϣ
typedef struct IMVS_EXPORT_PROCESS_END_INFO__
{
	unsigned int    nProcessId;                         // ����ID
	unsigned int    nClientType;                        // �ͻ�������
	char            strProcPath[IMVS_MAX_PATH_UTF8_LENGTH]; // �����ļ�·��
	int             nErrorCode;                         // ������
	unsigned int    nReserved[4];                       // �����ֶ�
} IMVS_EXPORT_PROCESS_END_INFO;

// ���̵���������Ϣ
typedef struct IMVS_EXPORT_PROCESS_PROGRESS_INFO__
{
	unsigned int    nProgress;    // ����
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_EXPORT_PROCESS_PROGRESS_INFO;

// ���̵��뿪ʼ��Ϣ
typedef struct IMVS_IMPORT_PROCESS_BEGIN_INFO__
{
	unsigned int    nClientType;  // �ͻ�������
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_IMPORT_PROCESS_BEGIN_INFO;

// ���̵��������Ϣ
typedef struct IMVS_IMPORT_PROCESS_END_INFO__
{
	unsigned int    nIgnoreGlobalModu;                  // �Ƿ����ȫ��ģ��
	unsigned int    nProcessId;                         // ����ID
	char            strProcessName[IMVS_MAX_PROCESS_NAME_LENGTH]; // ��������
	unsigned int    nClientType;                        // �ͻ�������
	char            strProcPath[IMVS_MAX_PATH_UTF8_LENGTH]; // �����ļ�·��
	int             nErrorCode;                         // ������
	unsigned int    nReserved[4];                       // �����ֶ�
} IMVS_IMPORT_PROCESS_END_INFO;

// ���̵��������Ϣ
typedef struct IMVS_IMPORT_PROCESS_PROGRESS_INFO__
{
	unsigned int    nProgress;    // ����
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_IMPORT_PROCESS_PROGRESS_INFO;

// ���̵�������ļ�����
typedef struct IMVS_PROCESS_IMPORT_INTERFACE_FILE_INFO__
{
	char *          pData;
	unsigned int    nDataLen;
	unsigned int    nReserved[4];
} IMVS_PROCESS_IMPORT_INTERFACE_FILE_INFO;

// ����������ģ��ID��Ϣ
typedef struct IMVS_IMPORT_PROCESS_MODULE_ID_INFO__
{
	unsigned int    nOldId;              // ԭID
	unsigned int    nNewId;              // ��ID
	char strNewName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // ������
} IMVS_IMPORT_PROCESS_MODULE_ID_INFO;

// ����������ģ��ID��Ϣ�б�
typedef struct IMVS_IMPORT_PROCESS_MODULE_ID_INFO_LIST__
{
	int nProcessNum;                    // ��������
	int nModuleNum;                     // ģ������
	IMVS_IMPORT_PROCESS_MODULE_ID_INFO astProcessIdInfoList[IMVS_MAX_PROCESS_NUM]; // ����ID��Ϣ�б�
	IMVS_IMPORT_PROCESS_MODULE_ID_INFO astModuleIdInfoList[IMVS_MAX_MODULE_NUM];   // ģ��ID��Ϣ�б�
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_IMPORT_PROCESS_MODULE_ID_INFO_LIST;

// ����ӹ�ʱ�ص����̽�������
typedef struct IMVS_TAKEOVER_PRC_INTERFACE_DATA_INFO__
{
	char *          pData;             // ��������
	unsigned int    nDataLen;          // �������ݳ���
	unsigned int    nReserved[4];
} IMVS_TAKEOVER_PRC_INTERFACE_DATA_INFO;

// ����ӹ�ʱ�ص�������������
typedef struct IMVS_TAKEOVER_SOL_INTERFACE_DATA_INFO__
{
	char *          pData;             // ��������
	unsigned int    nDataLen;          // �������ݳ���
	unsigned int    nReserved[4];
} IMVS_TAKEOVER_SOL_INTERFACE_DATA_INFO;

// �������̺���ȫ�ֱ���״̬��Ϣ
typedef struct IMVS_IMPORT_PROCESS_IGNOREGLOBALVAR_INFO__
{
	unsigned int    nStatus;       // ״ֵ̬
	unsigned int    nReserved[4];  // �����ֶ�
} IMVS_IMPORT_PROCESS_IGNOREGLOBALVAR_INFO;

// �������������Ϣ
typedef struct IMVS_UI_OBJECT_PARAM_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH]; // ��������
	char *          pData;             // �����������
	unsigned int    nDataLen;          // ����������ݳ���
} IMVS_UI_OBJECT_PARAM_INFO;

// �������������Ϣ�б�
typedef struct IMVS_UI_OBJECT_PARAM_INFO_LIST__
{
	int             nParamNum;         // ��������
	IMVS_UI_OBJECT_PARAM_INFO * pstUIObjParamInfo; // ��������
	unsigned int    nReserved[4];      // �����ֶ�
} IMVS_UI_OBJECT_PARAM_INFO_LIST;

// ���̽������������Ϣ
typedef struct IMVS_PROC_UI_OBJECT_PARAM_INFO__
{
	int             nObjectId;         // ����Id
	IMVS_UI_OBJECT_PARAM_INFO_LIST stUIObjParamInfoList; // ���������б�
} IMVS_PROC_UI_OBJECT_PARAM_INFO;

// ���̽������������Ϣ�б�
typedef struct IMVS_PROC_UI_OBJECT_PARAM_INFO_LIST__
{
	int             nObjectNum;         // ��������
	IMVS_PROC_UI_OBJECT_PARAM_INFO * pstProcUIObjParamInfo; // ���̲�������
	unsigned int    nReserved[4];      // �����ֶ�
} IMVS_PROC_UI_OBJECT_PARAM_INFO_LIST;

// ��һ�㼶ģ������Ϣ�б�
typedef struct IMVS_NODE_TREE_INFO__
{
    int nChildNodeNum;               // �ӽڵ�����
    IMVS_MODULE_INFO astChildNodeInfo[IMVS_MAX_MODULE_NUM]; // �ӽڵ���Ϣ�б�
} IMVS_NODE_TREE_INFO;

// ģ��������Ϣ�ṹ
typedef struct IMVS_MODULE_CONNECT_INFO__
{
	int nModuleId;                  // ģ��ID
	int nNextModuNum;               // ���ģ������
	unsigned int anNextModuleId[IMVS_MAX_MODULE_NUM]; // ���ģ��ID
	int nPreModuNum;                // ǰ��ģ������
	unsigned int anPreModuleId[IMVS_MAX_MODULE_NUM]; // ǰ��ģ��ID
} IMVS_MODULE_CONNECT_INFO;

// ģ��������Ϣ�б�
typedef struct IMVS_MODULE_CONNECT_INFO_LIST__
{
	int nNum;               // ģ����������
	IMVS_MODULE_CONNECT_INFO * pstModuleConnectInfo; // ģ��������Ϣ
	unsigned int    nReserved[4];      // �����ֶ�
} IMVS_MODULE_CONNECT_INFO_LIST;

// ������Ϣ�б�
typedef struct IMVS_MODULE_SUBSCRIBE_INFO_LIST__
{
	int                   nNum;             // ������Ϣ����
	IMVS_SUBSCRIBE_INFO * pstSubscribeInfo; // ������Ϣ�б�
	unsigned int          nReserved[4];     // �����ֶ�
} IMVS_MODULE_SUBSCRIBE_INFO_LIST;

// �ϱ�ָ��ģ����ģ���б�
typedef struct IMVS_REPORT_MODULE_RES_INFO_LIST__
{
	int                   nNum;             // �ϱ�ģ�����
	unsigned int          anReportModuIds[IMVS_MAX_MODULE_NUM]; // �ϱ�ģ����
	unsigned int          nReserved[4];     // �����ֶ�
} IMVS_REPORT_MODULE_RES_INFO_LIST;

// ��ѯģ����ʷ�����Ϣ�ṹ
typedef struct IMVS_QUERY_MODULE_RES_INFO_LIST__
{
	int                   nNum;             // �ϱ�ģ�����
	IMVS_MODULE_RESULT_INFO_LIST_EX * pastModuResultList; // ģ����ʷ�������
	int                   nTotalNum;         // ģ����������
	unsigned int          nReserved[4];     // �����ֶ�
} IMVS_QUERY_MODULE_RES_INFO_LIST;

// ����ģ��������Ϣ�ṹ
typedef struct IMVS_EXPORT_MODULE_DATA_INFO__
{
	char *               pData;        // ����ָ��
	unsigned int         nDataLen;     // ���ݳ���
	unsigned int         nReserved[4]; // �����ֶ�
} IMVS_EXPORT_MODULE_DATA_INFO;

// ����ģ��������Ϣ�ṹ
typedef struct IMVS_IMPORT_MODULE_DATA_INFO__
{
	unsigned int         nParentNodeID; // ���ڵ�ID
	unsigned int         nModuleID;     // ģ��ID
	char                 strModuDisplayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // ģ����ʾ����
	unsigned int         nWaitTime;     // ��ʱʱ��
	char *               pData;         // ����ָ��
	unsigned int         nDataLen;      // ���ݳ���
	unsigned int         nReserved[4];  // �����ֶ�
} IMVS_IMPORT_MODULE_DATA_INFO;

// ͬ�����ģ��������Ϣ�ṹ
typedef struct IMVS_SYNC_ADD_ONE_MODULE_INFO__
{
	unsigned int nParentNodeType; // ���ڵ����� ���̣�1��Group��20
	unsigned int nParentNodeID;   // ���ڵ�ID
	char         strModuleDllName[IMVS_MAX_MODULE_NAME_LENGTH];       // ģ��dll����
	char         strDisplayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // ������ʾ����
	unsigned int nWaitTime;       // ��ʱʱ��
	unsigned int nReserved[4];  // �����ֶ�
} IMVS_SYNC_ADD_ONE_MODULE_INFO;

// ������������
typedef struct IMVS_INPUT_INT_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // ��������
	int             nValueNum;              // ����
	int *           pIntValue;              // ��������
} IMVS_INPUT_INT_INFO;

// ��������������
typedef struct IMVS_INPUT_FLOAT_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // ��������
	int             nValueNum;              // ����
	float *         pFloatValue;            // ����������
} IMVS_INPUT_FLOAT_INFO;

// ��������������
typedef struct IMVS_INPUT_DOUBLE_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // ��������
	int             nValueNum;              // ����
	double *         pDoubleValue;            // ����������
} IMVS_INPUT_DOUBLE_INFO;

// �ַ�����������Ϣ�ṹ
typedef struct IMVS_STRING_DATA_INFO__
{
	char strValue[IMVS_DEFINE_MODULE_RES_STRING_LENGTH];    // �ַ�������
} IMVS_STRING_DATA_INFO;

// �ַ�������������
typedef struct IMVS_INPUT_STRING_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // ��������
	int             nValueNum;              // ����
	IMVS_STRING_DATA_INFO * pstStringValue; // �ַ���������
} IMVS_INPUT_STRING_INFO;

// �������������б�
typedef struct IMVS_INPUT_INT_LIST_INFO__
{
	int nNum;    // ���Ͳ�������
	IMVS_INPUT_INT_INFO * pstIntValueList;    // ���Ͳ����б�
} IMVS_INPUT_INT_LIST_INFO;

// ���������������б�
typedef struct IMVS_INPUT_FLOAT_LIST_INFO__
{
	int nNum;    // �����Ͳ�������
	IMVS_INPUT_FLOAT_INFO * pstFloatValueList;    // �����Ͳ����б�
} IMVS_INPUT_FLOAT_LIST_INFO;

// ���������������б�
typedef struct IMVS_INPUT_DOUBLE_LIST_INFO__
{
	int nNum;    // �����Ͳ�������
	IMVS_INPUT_DOUBLE_INFO * pstDoubleValueList;    // �����Ͳ����б�
} IMVS_INPUT_DOUBLE_LIST_INFO;

// �ַ��������������б�
typedef struct IMVS_INPUT_STRING_LIST_INFO__
{
	int nNum;    // �ַ����Ͳ�������
	IMVS_INPUT_STRING_INFO * pstStringValueList;    // �ַ����Ͳ����б�
} IMVS_INPUT_STRING_LIST_INFO;

// ͼ�񡢵㼯��������������������Ϣ
typedef struct IMVS_MODULE_INPUT_DATA_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // ��������
	unsigned int    nDataLen;               // ���ݳ���
	char *          pData;                  // ����
} IMVS_MODULE_INPUT_DATA_INFO;

// ģ��ID�б�
typedef struct IMVS_MODULE_ID_LIST__
{
	int nNum;    // ����ģ������
	unsigned int anModuleId[IMVS_MAX_MODULE_NUM]; // ����ģ��ID
	unsigned int nReserved[4];  // �����ֶ�
} IMVS_MODULE_ID_LIST;

//  ����ID�б�
typedef struct IMVS_PROCESS_ID_LIST__
{
	int nNum;    // ������������
	unsigned int anProcessId[IMVS_MAX_PROCESS_NUM]; // ��������ID
	unsigned int nReserved[4];  // �����ֶ�
} IMVS_PROCESS_ID_LIST;

// ������ģ��������Ϣ�ṹ
typedef struct IMVS_IMPORT_MODULE_LIST_DATA_INFO__
{
	unsigned int         nParentId;     // ���ڵ�ID
	IMVS_MODULE_ID_LIST  stModuIdList;  // ģ��ID�б�
	unsigned int         nWaitTime;     // ��ʱʱ��
	char *               pData;         // ����ָ��
	unsigned int         nDataLen;      // ���ݳ���
	unsigned int         nReserved[4];  // �����ֶ�
} IMVS_IMPORT_MODULE_LIST_DATA_INFO;

// ģ��ڵ㵥Ԫ��Ϣ
typedef struct IMVS_NODE_UNIT_INFO__
{
	unsigned int nNodeId;    // �ڵ�ID
	char strDisplayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // ��ʾ����
} IMVS_NODE_UNIT_INFO;

// ����ģ��ڵ���Ϣ
typedef struct IMVS_IMPORT_NODE_INFO__
{
	IMVS_NODE_UNIT_INFO stParentNodeInfo; // ���ڵ���Ϣ
	int nSonModuNum;    // �ӽڵ�����
	IMVS_NODE_UNIT_INFO astSonNodeInfo[IMVS_MAX_MODULE_NUM]; // �ӽڵ���Ϣ
} IMVS_IMPORT_NODE_INFO;

// ����ģ��ڵ���Ϣ�б�
typedef struct IMVS_IMPORT_NODE_LIST__
{
	int nNum;    // �ڵ���Ϣ����
	IMVS_IMPORT_NODE_INFO astImportNodeInfo[IMVS_MAX_MODULE_NUM]; // �ڵ���Ϣ�б�
} IMVS_IMPORT_NODE_LIST;

// ����������������Ϣ
typedef struct IMVS_UIPARAM_VALUE__
{
	char strParamName[IMVS_MAX_PARAM_NAME_LENGTH]; // ��������
	char * pData;    // ��������
	size_t nLen;     // �������ݳ���
} IMVS_UIPARAM_VALUE;

// ����������������Ϣ
typedef struct IMVS_UIPARAM_INFO__
{
	int nObjectId; // ����ID
	int nValNum;   // �������
	IMVS_UIPARAM_VALUE * pastParamVal; // ��ѯ���
} IMVS_UIPARAM_INFO;

// ����������ģ����ѯ��Ϣ�б�
typedef struct IMVS_UIPARAM_INFO_LIST__
{
	int nNum;    // ����
	IMVS_UIPARAM_INFO astUiParamInfo[IMVS_MAX_MODULE_NUM]; // ģ����ѯ��Ϣ�б�
	unsigned int nReserved[4];  // �����ֶ�
} IMVS_UIPARAM_INFO_LIST;

// �����������Ϣ
typedef struct IMVS_THIRD_SOFTWARE_INFO__
{
	unsigned int nPid; // ����ID
	char strProcName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // ��������
} IMVS_THIRD_SOFTWARE_INFO;

// �����������Ϣ�б�
typedef struct IMVS_THIRD_SOFTWARE_INFO_LIST__
{
	int nNum; // ��������
	IMVS_THIRD_SOFTWARE_INFO astSoftwareInfo[IMVS_MAX_THIRD_SOFTWARE_NUM]; // �����Ϣ�б�
} IMVS_THIRD_SOFTWARE_INFO_LIST;

// �������ͣ�1��ȫ�������2����Դ�豸��3��ǰ��ͨ���豸��4������ͨ���豸��5���ֲ�������
typedef enum IMVS_RELATED_TYPE__
{
	GLOBAL_TYPE_INVALID = 0,
	GLOBAL_TYPE_CAMERA = 1,
	GLOBAL_TYPE_LIGHT  = 2,
	GLOBAL_TYPE_PRE_COMMUNICATION = 3,
	GLOBAL_TYPE_AFTER_COMMUNICATION = 4,
	GLOBAL_TYPE_AFTER_TRIGER = 5,
} IMVS_RELATED_TYPE;

// �����̹�����ȫ��ģ��ID�б�
typedef struct IMVS_RELATED_GLOBAL_MODU_ID_LIST__
{
	IMVS_RELATED_TYPE eRelatedType; // ��������
	int nNum;    // ȫ��ģ������
	unsigned int anModuleId[IMVS_MAX_MODULE_NUM]; // ȫ��ģ��ID
	unsigned int nReserved[4];  // �����ֶ�
} IMVS_RELATED_GLOBAL_MODU_ID_LIST;

// �����̹�����ȫ��ģ��ID�б�
typedef struct IMVS_RELATED_GLOBAL_MODU_INFO_LIST__
{
	int nNum;                   // �б�����
	IMVS_RELATED_GLOBAL_MODU_ID_LIST astGlobalModuInfo[IMVS_MAX_GLOBAL_TYPE_NUM]; // ȫ��ģ��ID
	unsigned int nReserved[4];  // �����ֶ�
} IMVS_RELATED_GLOBAL_MODU_INFO_LIST;


// ģ����ûص�״̬��Ϣ
typedef struct IMVS_MODULE_STATE_INFO__
{
	unsigned int nModuleId;  // ģ��ID
	unsigned int nEnable;    // ʹ��״̬
	unsigned int nCallback;  // �ص�״̬
} IMVS_MODULE_STATE_INFO;

// ģ����ûص�״̬�б�
typedef struct IMVS_MODULE_STATE_LIST__
{
	int nNum;    // ����
	IMVS_MODULE_STATE_INFO astModuState[IMVS_MAX_MODULE_NUM]; // ģ��״̬�б�
	unsigned int nReserved[4];  // �����ֶ�
} IMVS_MODULE_STATE_LIST;

/** @enum IMVS_VALUE_TYPE
 *  @brief ֵ����
 */
typedef enum IMVS_VALUE_TYPE__
{
	VALUE_TYPE_INT    = 1, // ����
	VALUE_TYPE_FLOAT  = 2, // ������
	VALUE_TYPE_STRING = 3, // �ַ�����
	VALUE_TYPE_IMAGE  = 4, // ͼ����
	VALUE_TYPE_POINTSET = 5, // �㼯��
	VALUE_TYPE_BYTE   = 6, // ������
} IMVS_VALUE_TYPE;

/** @enum IMVS_SILENT_EXECUTE_TYPE
*  @brief ��Ĭִ������
*/
typedef enum IMVS_SILENT_EXECUTE_TYPE__
{
    SILENT_EXECUTE_TYPE_DLANDSHELL = 0, // ���ѧϰ�ͽű�ģ��
    SILENT_EXECUTE_TYPE_ALL = 1,        // ȫ��ģ��
    SILENT_EXECUTE_TYPE_DL = 2,         // ���ѧϰģ��
    SILENT_EXECUTE_TYPE_SHELL = 3,      // �ű�ģ��
} IMVS_SILENT_EXECUTE_TYPE;

/** @enum IMVS_COMBINATION_TYPE
 *  @brief �������
 */
typedef enum IMVS_COMBINATION_STYLE__
{
	COMBINATION_TYPE_COMBINATION = 0, // ���
	COMBINATION_TYPE_IMAGE       = 1, // ͼ��	
	COMBINATION_TYPE_POINT       = 2, // ��
	COMBINATION_TYPE_ROIBOX      = 3, // ROI
	COMBINATION_TYPE_ROIANNULUS  = 4, // Բ��ROI
	COMBINATION_TYPE_FIXTURE     = 5, // ������Ϣ
	COMBINATION_TYPE_CLASSINFO   = 6, // �����Ϣ
	COMBINATION_TYPE_LINE        = 7, // ֱ��
	COMBINATION_TYPE_CIRCLE      = 8, // Բ
	COMBINATION_TYPE_ACQUIMAGE   = 9, // �ɼ�ͼ�񣨶�ͼ�ںϣ�
	COMBINATION_TYPE_PIXELIMAGE  = 10, // 
	COMBINATION_TYPE_ANNULUS     = 11, // Բ��
	COMBINATION_TYPE_CONTOURPOINT = 12, // ������
	COMBINATION_TYPE_RECT        = 13, // ����
	COMBINATION_TYPE_DEBUG       = 14, // DEBUG
} IMVS_COMBINATION_STYLE;

// �������ݽṹ
typedef struct IMVS_BASE_DATA_VALUE_
{
	char *          pData;  // ʵ������
	unsigned int    nLen;   // ʵ�����ݳ���	
} IMVS_BASE_DATA_VALUE;

/*
//���������Ϣ
typedef struct IMVS_COMBINATION_IO_INFO__
{
	char strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // ��������
	IMVS_VALUE_INFO stValInfo;                        // ������Ϣ
	IMVS_BASE_DATA_VALUE  stExtraData;              // ��������
} IMVS_COMBINATION_IO_INFO;

// ���������Ϣ�б�
typedef struct IMVS_COMBINATION_IO_INFO_LIST__
{
	int nNum;                                         // �����Ϣ����
	IMVS_COMBINATION_IO_INFO stCombinationInfo[IMVS_MAX_MODULE_INPUT_IO_NUM]; // �����Ϣ�б�
} IMVS_COMBINATION_IO_INFO_LIST;

// ģ��IO������Ϣ
typedef struct IMVS_MODULE_IO_INNER_INFO__
{
	int  nType;                                       // �������ͣ�1: ֵ����, 2: ������ͣ�
	char strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // ��������
	char strStyle[IMVS_DEFAULT_STYLE_NUM];            // ��������
	char strAccessMode[IMVS_DEFAULT_BYTE_NUM];        // ��������
	IMVS_VALUE_INFO stValInfo;                        // ������Ϣ
	IMVS_COMBINATION_STYLE eCombinationType;          // �������
	IMVS_COMBINATION_IO_INFO_LIST stCombinaInfoList;  // �����Ϣ�б�
	//IMVS_BASE_DATA_VALUE stExtraData;               // ����Э������
} IMVS_MODULE_IO_INNER_INFO;

typedef struct IMVS_MODULE_IO_INNER_INFO_LIST__
{
	int nNum;                                         // �����Ϣ����
	IMVS_MODULE_IO_INNER_INFO stCombinationInfo[IMVS_MAX_MODULE_INPUT_IO_NUM]; // �����Ϣ�б�
} IMVS_MODULE_IO_INNER_INFO_LIST;*/

// ģ��IO��Ϣ
typedef struct IMVS_VALUE_INFO__
{
	IMVS_VALUE_TYPE eValType;          // ֵ����
	int   nIntVal;                     // ����ֵ
	float fFloatVal;                   // ������ֵ
	IMVS_BASE_DATA_VALUE stStringInfo; // �ַ���
	IMVS_BASE_DATA_VALUE stImgInfo;    // ͼ������	

	//bool bIsForce;                     // ��������
	//bool bIsShow;                      // ��������
	//char strAccessMode[IMVS_DEFAULT_BYTE_NUM]; // ��������
} IMVS_VALUE_INFO;

/** @enum IMVS_COMBINATION_TYPE
*  @brief IO��Ϣ����
*/
typedef enum IMVS_DATA_TYPE__
{
	DATA_TYPE_MIN = 0,                  // ö����Сֵ(��ʼֵ)
	DATA_TYPE_FILTER = 1,               // ֵ����
	DATA_TYPE_COMBINATION = 2,          // �������
	DATA_TYPE_MAX = 3                   // ö�����ֵ
} IMVS_DATA_TYPE;

/** @enum IMVS_COMBINATION_TYPE
*  @brief IO�����������
*/
typedef enum IMVS_IO_CLASS_TYPE__
{
	IO_CLASS_MIN = 0,                  // ö����Сֵ(��ʼֵ)
	IO_CLASS_INPUT = 1,                // ��������
	IO_CLASS_OUTPUT = 2,               // �������
	IO_CLASS_MAX = 3                   // ö�����ֵ
} IMVS_IO_CLASS_TYPE;

typedef struct IMVS_MODULE_IO_INFO__
{
	int  nDataType;                                     // �������ͣ�1: ֵ����, 2:IMVS_MODULE_IO_INFO��
	char szParamName[IMVS_MAX_PARAM_NAME_LENGTH];       // ��������
	char szParamType[IMVS_MAX_PARAM_NAME_LENGTH];       // ����������
	int nNum;                                           // pstCombInfoָ��ʵ�ʸ���
	IMVS_MODULE_IO_INFO__* pstCombInfo;                 //Combination�е�ÿһ�����ݣ�ָ��ֵ���ͻ��߽ṹ�屾��  32
	char szExtraData[IMVS_DEFAULT_DATA_NUM];            //��������

	/*IMVS_MODULE_IO_INFO__()
	{
		nDataType = 0;
		memset(szParamName, 0, IMVS_MAX_PARAM_NAME_LENGTH * sizeof(char));
		memset(szParamType, 0, IMVS_MAX_PARAM_NAME_LENGTH * sizeof(char));
		nNum = 0;
		pstCombInfo = NULL;
		memset(szExtraData, 0, IMVS_DEFAULT_DATA_NUM * sizeof(char));
	}*/

	void Release()
	{
		if (1 == nDataType)
		{
			return;
		}
		else if (2 == nDataType)
		{
			if (NULL != pstCombInfo)
			{
				for (int nNu = 0; nNu < nNum; ++nNu)
				{
					pstCombInfo[nNu].Release();
				}
				delete[] pstCombInfo;
				pstCombInfo = NULL;
			}
		}
	}
} IMVS_MODULE_IO_INFO;

// ģ��IO������Ϣ�б�
typedef struct IMVS_MODULE_IO_INFO_LIST__
{
	int nIoClass;                                        // �������ͣ�1: ����, 2: �����
	int nNum;                                            // ����
	IMVS_MODULE_IO_INFO *pstModuIoInfo;                  // ģ��IO��Ϣ
	unsigned int nReserved[4];                           // �����ֶ�

	/*IMVS_MODULE_IO_INFO_LIST__()
	{
	nIoClass = 0;
	nNum = 0;
	pstModuIoInfo = NULL;
	memset(nReserved, 0, 4 * sizeof(unsigned int));
	}*/
	~IMVS_MODULE_IO_INFO_LIST__()
	{
		if (NULL != pstModuIoInfo)
		{
			for (int nNu = 0; nNu < nNum; ++nNu)
			{
				pstModuIoInfo[nNu].Release();
			}
			delete[] pstModuIoInfo;
			pstModuIoInfo = NULL;
		}
	}
} IMVS_MODULE_IO_INFO_LIST;

// �����뷽���ļ��汾��Ϣ
typedef struct IMVS_FILE_VERSION_INFO_
{
	char            strCurrentVesionInfo[IMVS_SOLUTION_VERSION_LENGTH];
	unsigned int    nReserved[4];
} IMVS_FILE_VERSION_INFO;

// ������ȫ�ֶ���/���̶�����Ϣ
typedef struct IMVS_GLOBAL_PROCESS_UI_OBJECT_INFO__
{
	int             nStatus;      // ״̬
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_GLOBAL_PROCESS_UI_OBJECT_INFO;

// ��������ʱ֪ͨ�����ȡ������Ϣ
typedef struct IMVS_IMPORT_PROCESS_GET_UIDATA_INFO__
{
	unsigned int    nProcessId;                         // ������ID
	char            strProcessName[IMVS_MAX_PROCESS_NAME_LENGTH]; // ����������
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_IMPORT_PROCESS_GET_UIDATA_INFO;

// ����Groupʱ֪ͨ�����ȡ������Ϣ
typedef struct IMVS_IMPORT_GROUP_GET_UIDATA_INFO__
{
	unsigned int    nGroupId;                        // ��ģ��ID
	char            strGroupName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // ģ��������
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_IMPORT_GROUP_GET_UIDATA_INFO;

// ģ��״̬�ϱ���Ϣ
typedef struct IMVS_REPORT_MODULE_STATUS_INFO__
{
	unsigned int    nModuleID;              // ģ��ID
	unsigned int    nModuProcessStatus;     // ģ��ִ��״̬ 1�ɹ�; 2ģ���쳣��3ǰ���֧ģ���쳣��4 ǰ��ģ���쳣
	unsigned int    nModuleStatus;          // ģ����״̬ 1�ɹ�; 0ģ�����쳣
	float           fModuleTime;            // ģ��ʱ��
	float           fAlgorithmTime;         // �㷨ʱ��
	float           fProcessTime;           // ����ʱ��
	int             bIsSelfRun;             // �Ƿ���ִ��(0:����ִ�� 1:��ִ��)
} IMVS_REPORT_MODULE_STATUS_INFO;

// ģ��״̬�ϱ���Ϣ�б�
typedef struct IMVS_REPORT_MODULE_STATUS_INFO_LIST__
{
	int nNum;    // ģ������
	unsigned int                     nProcessId;            // ����ID
	IMVS_REPORT_MODULE_STATUS_INFO * pstModuleStatuInfo;    // ģ��״̬��Ϣ�б�
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_REPORT_MODULE_STATUS_INFO_LIST;

// �ϱ����ݶ�����Ϣ
typedef struct IMVS_REPORT_DATAQUEUE_INFO__
{
    int             nModuleId;    // ģ��ID
    char *          pData;        // ����
    size_t          nLen;         // ���ݳ���
    unsigned int    nReserved[4]; // �����ֶ�
} IMVS_REPORT_DATAQUEUE_INFO;

// �رշ���״̬��Ϣ
typedef struct IMVS_CLOSE_SOLUTION_STATUS_INFO__
{
	int             nClientType;  // �ͻ�������
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_CLOSE_SOLUTION_STATUS_INFO;

// ���������̿�ʼ
typedef struct IMVS_EXPORT_MULTIPROCESS_BEGIN_INFO__
{
	IMVS_PROCESS_ID_LIST anProcessId; // ��������ID
	unsigned int    nClientType;      // �ͻ�������
	unsigned int    nReserved[4];     // �����ֶ�
} IMVS_EXPORT_MULTIPROCESS_BEGIN_INFO;

// ���������̽�����Ϣ
typedef struct IMVS_EXPORT_MULTIPROCESS_END_INFO__
{
	IMVS_PROCESS_ID_LIST anProcessId;                   // ����ID
	unsigned int    nClientType;                        // �ͻ�������
	char            strProcPath[IMVS_MAX_PATH_UTF8_LENGTH]; // �����ļ�·��
	int             nErrorCode;                         // ������
	unsigned int    nReserved[4];                       // �����ֶ�
} IMVS_EXPORT_MULTIPROCESS_END_INFO;

// �����̵���������Ϣ
typedef struct IMVS_EXPORT_MULTIPROCESS_PROGRESS_INFO__
{
	unsigned int    nProgress;    // ����
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_EXPORT_MULTIPROCESS_PROGRESS_INFO;

// �����̵��뿪ʼ��Ϣ
typedef struct IMVS_IMPORT_MULTIPROCESS_BEGIN_INFO__
{
	unsigned int    nClientType;  // �ͻ�������
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_IMPORT_MULTIPROCESS_BEGIN_INFO;

// �����̻�����Ϣ
typedef struct IMVS_PROCESS_BASE_INFO__
{
	unsigned int    nProcessId;                         // ����ID
	char            strProcessName[IMVS_MAX_PROCESS_NAME_LENGTH]; // ��������
} IMVS_PROCESS_BASE_INFO;

// �����̻�����Ϣ�б�
typedef struct IMVS_PROCESS_BASE_INFO_LIST__
{
	int nNum;    // ��������
	IMVS_PROCESS_BASE_INFO stProcBaseInfoList[IMVS_MAX_PROCESS_NUM]; // ������Ϣ�б�	 
} IMVS_PROCESS_BASE_INFO_LIST;

// �����̵��������Ϣ
typedef struct IMVS_IMPORT_MULTIPROCESS_END_INFO__
{
	unsigned int    nIgnoreGlobalModu;                  // �Ƿ����ȫ��ģ��	
	unsigned int    nClientType;                        // �ͻ�������
	char            strProcPath[IMVS_MAX_PATH_UTF8_LENGTH]; // �����ļ�·��
	int             nErrorCode;                         // ������
	IMVS_PROCESS_BASE_INFO_LIST stProcBaseInfo;         // ���̻�����Ϣ�б�
	unsigned int    nReserved[4];                       // �����ֶ�
} IMVS_IMPORT_MULTIPROCESS_END_INFO;

// �����̵��������Ϣ
typedef struct IMVS_IMPORT_MULTIPROCESS_PROGRESS_INFO__
{
	unsigned int    nProgress;    // ����
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_IMPORT_MULTIPROCESS_PROGRESS_INFO;

// ���������ʱ֪ͨ�����ȡ������Ϣ
typedef struct IMVS_IMPORT_MULTIPROCESS_UIDATA_INFO__
{
	IMVS_PROCESS_BASE_INFO_LIST stUiData;
	unsigned int    nReserved[4]; // �����ֶ�
} IMVS_IMPORT_MULTIPROCESS_UIDATA_INFO;

// �ļ���Ϣ�ṹ
typedef struct FileInfo_
{
	char* tFileMTime;
	double dFileSize;
} FileInfo;

typedef enum report_result_type__
{
    REPORT_RESULT_TYPE_INVALID = 0,//��Ч
    REPORT_RESULT_TYPE_NONE = 1,//����ģ������ϱ�
    REPORT_RESULT_TYPE_ALL = 2,//����ģ�鶼�ϱ�
    REPORT_RESULT_TYPE_PART = 3//����ģ���ϱ�
} E_REPORT_RESULT_TYPE;

/** @enum IMVS_RELEASE_MEMORY_TYPE
*  @brief �ڴ��ͷ�����
*/
typedef enum IMVS_RELEASE_MEMORY_TYPE__
{
    RELEASE_MEMORY_BASE_VOID = 0,                          // �ڴ�����
    RELEASE_MEMORY_BASE_POINTER = 1,                       // ָ������
    RELEASE_MEMORY_BASE_ARRAY = 2,                         // ��������
    RELEASE_MEMORY_STRUCT_UI_OBJECT_PARAM_LIST = 3,        // �����������
    RELEASE_MEMORY_STRUCT_UI_PARAM_INFO_LIST = 4,          // �����������
    RELEASE_MEMORY_STRUCT_MODU_CONNECT_INFO_LIST = 5,      // ������������
    RELEASE_MEMORY_STRUCT_MODU_SUBSCRIBE_INFO_LIST = 6,    // ���涩������
    RELEASE_MEMORY_STRUCT_MODU_STATUS_INFO_LIST = 7,       // ģ��ִ��״̬
    RELEASE_MEMORY_STRUCT_MODU_EXPORT_DATA_INFO = 8,       // ģ�鵼������
    RELEASE_MEMORY_STRUCT_MODU_HISTORY_RES_INFO_LIST = 9,  // ģ����ʷ���
}IMVS_RELEASE_MEMORY_TYPE;

/** @enum IMVS_MEMORY_OWNER_TYPE
*  @brief �ڴ���������
*/
typedef enum IMVS_MEMORY_OWNER_TYPE__
{
    MEMORY_OWNER_TYPE_INTERNAL = 0,                          // �ڲ�����
    MEMORY_OWNER_TYPE_EXTERNAL = 1,                       // �ⲿ����
}IMVS_MEMORY_OWNER_TYPE;

//fuzzy match
typedef enum IMVS_FUZZY_MATCH__
{
	FUZZY_MATCH_NO = 0,        //��
	FUZZY_MATCH_YES = 1        //��
}IMVS_FUZZY_MATCH;

/** �����ӿڣ�@enum IMVS_IO_BE_SUBSCRIBED_TYPE
*  @brief IO����������
*/
typedef enum IMVS_IO_BE_SUBSCRIBED_TYPE__
{
    IO_BE_SUBSCRIBED_TYPE_GENARAL = 0,           // ��ͨ����
    IO_BE_SUBSCRIBED_TYPE_RUNPARAMS = 1,         // ���в�������
}IMVS_IO_BE_SUBSCRIBED_TYPE;

namespace IMVS
{
    // �㷨�汾��Ϣ
    struct AlgorithmVersionInfo
    {
        char Normal[IMVS_ALGORITHM_VERSION_LENGTH];         // 2d����
        char Deeplearning[IMVS_ALGORITHM_VERSION_LENGTH];   // �������
    };

    // ��ģ���REAL_MODE_IAMGE_TRANS_INFO_�ṹ�屣��һ��
    struct RealModeImageTransInfo
    {
        int nModuleId;
        int nWidth;
        int nHeight;
        unsigned long long nPixelFormat;
        int nDataLen;//��ʵ���ݴ�С
        int nFrameNum;
        int nLostFrameCount;
        int nLostPacketCount;
        int nReserved[4];
    };

    // ����͸�������ȡ������
    struct RealModeImageTransInfoWithData
    {
        RealModeImageTransInfo ImageInfo;   // ͼƬ��Ϣ
        const char* ImageData;              // ͼƬ���ݣ�������ImageInfo.nDataLen����
    };

    namespace FTP
    {
        // const int MAX_USER_FILE_NUM = 100;
        const int MAX_USER_FILE_INFO_NUM = 255;

        // ��FTPClientDefine.h�еĶ��屣��һ��
        struct RemoteFileInfo
        {
            char Permission[MAX_USER_FILE_INFO_NUM];    //�ļ�����
            int  HardLink;                              //Ӳ����
            char User[MAX_USER_FILE_INFO_NUM];          //������
            char Group[MAX_USER_FILE_INFO_NUM];         //�����û���
            int  Size;                                  //�ļ���С
            char Time[MAX_USER_FILE_INFO_NUM];          //�޸�ʱ��
            char Name[MAX_USER_FILE_INFO_NUM];          //�ļ���
        };

        struct RemoteFileListInfo
        {
            RemoteFileInfo* pFileInfos;
            int Num;
        };
    }
}

#endif // IMVS_6000_SDK4SERVER_DEFINE_H__
