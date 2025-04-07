/***************************************************************************************************
* 
* 版权信息：版权所有 (c) 2016, 保留所有权利
* 
* 文件名称：iMVS-6000SDK4ServerDefine.h
* 摘    要：与iMVS-6000的Server层通信的接口常见定义
*
* 日    期：2016-12-12
* 备    注：新建
***************************************************************************************************/
#ifndef IMVS_6000_SDK4SERVER_DEFINE_H__
#define IMVS_6000_SDK4SERVER_DEFINE_H__

#pragma warning(disable:4819)
#include <stdio.h>  //NULL
#include "ErrorCodeDefine.h"
#include "IVmExport.h"

using namespace VisionMasterSDK;

/*************************************************************************
 * 系统宏定义
 *************************************************************************/

// 定义输入表示
#ifndef IN
#define IN
#endif

// 定义输出表示
#ifndef OUT
#define OUT
#endif

// 定义输入输出表示
#ifndef INOUT
#define INOUT
#endif

// 定义空指针
#ifndef IMVS_NULL
#ifdef __cplusplus
#define IMVS_NULL    0
#else
#define IMVS_NULL    ((void *)0)
#endif
#endif

/*************************************************************************
 * 常见宏定义
 *************************************************************************/
const static unsigned int IMVS_MAX_MODULE_NAME_LENGTH       = 64;                       // 最大模块名称长度
const static unsigned int IMVS_MAX_MODULE_NUM               = 1040;                     // 最大模块个数(实际最大数量+全局模块个数)
const static unsigned int IMVS_MAX_INPUT_NUM                = 64;                       // 最大输入个数
const static unsigned int IMVS_MAX_OUTPUT_NUM               = 64;                       // 最大输出个数
const static unsigned int IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH = 256;                      // 订阅内容最大长度
const static unsigned int IMVS_MAX_PLATFORM_NUM             = 16;                       // 平台数量
const static unsigned int IMVS_MAX_USERNAME_LENGTH          = 16;                       // 最大用户名长度
const static unsigned int IMVS_MAX_PASSWORD_LENGTH          = 32;                       // 最大密码长度
const static unsigned int IMVS_MAX_VENDORNAME_LENGTH        = 16;                       // 最大生产商长度

const static unsigned int CM_MAX_MODULE_RESULT_OUTPUT_NUM   = 200;                      // 最多查找200个模板

/************************* 二次开发新增 **************************/
const static unsigned int IMVS_DEFAUT_SOCKET_SENDBUF_LENGTH = 1024;                     // 默认发送字节长度
const static unsigned int IMVS_DEFINE_SOCKET_BUF_LENGTH     = 8192;                     // 自定义发送接收字节长度
const static unsigned int IMVS_MAX_DATATYPE_NUM             = 32;                       // 数据类型最大个数
const static unsigned int IMVS_MAX_IMPORT_NUM               = 16;                       // 最大导入数据文件数量
const static unsigned int IMVS_MAX_MODULE_PARAM_NUM         = 128;                      // 模块最大参数数量
const static unsigned int IMVS_MAX_PARAM_NAME_LENGTH        = 128;                      // 模块参数名最大长度
const static unsigned int IMVS_MAX_PARAM_VALUE_LENGTH       = 512;                      // 模块参数值最大长度
const static unsigned int IMVS_MAX_PATH_LENGTH              = 260;                      // 最大路径长度
const static unsigned int IMVS_DEFAULT_GUID_LEN             = 256;                      // 默认GUID长度

// 导入数据类型
const static unsigned int IMVS_DATATYPE_TEMPLATE            = 1;                        // 模板数据类型
const static unsigned int IMVS_DATATYPE_FONT                = 2;                        // 字库数据类型
const static unsigned int IMVS_DATATYPE_CALIB               = 3;                        // 标定文件数据类型
const static unsigned int IMVS_DATATYPE_DLFONT              = 4;                        // 深度学习字库类型
const static unsigned int IMVS_DATATYPE_IMAGE               = 5;                        // 图像数据类型
const static unsigned int IMVS_DATATYPE_MARKINSP            = 6;                        // 字符模板类型
const static unsigned int IMVS_DATATYPE_EDGEFLAW            = 7;                        // 边缘缺陷模板类型
const static unsigned int IMVS_DATATYPE_COLORRECOGNITION     = 8;                        // 颜色识别模板类型
const static unsigned int IMVS_DATATYPE_MARKFIND            = 9;                        // 图形定位模板类型
const static unsigned int IMVS_DATATYPE_GLUEPATHCONDUCT      = 10;                       // 路径提取模板类型
const static unsigned int IMVS_DATATYPE_IMGSTITCHCALIB       = 11;                       // 图像拼接模板类型
const static unsigned int IMVS_DATATYPE_INSPECT             = 12;                       // 缺陷对比模板类型

/**************************** V3.0新增 ****************************/
const static unsigned int IMVS_PROCEDURE_GLOBAL_CTRL_SHIELD     = 1;                    // 屏蔽流程
const static unsigned int IMVS_PROCEDURE_GLOBAL_CTRL_NOT_SHIELD = 0;                    // 不屏蔽流程
const static unsigned int IMVS_MAX_PROCESS_NAME_LENGTH          = 64;                   // 流程名称最大长度
const static unsigned int IMVS_MAX_PROCESS_NUM                  = 1000;                 // 最大流程个数
const static unsigned int IMVS_MAX_ADD_MODULE_NUM               = 1020;                 // 流程中最大增加模块数量
const static unsigned int IMVS_MAX_DEL_MODULE_NUM               = 1020;                 // 流程中最大删除模块数量
const static unsigned int IMVS_MAX_TRANS_DATA_LENGTH            = 1024;                 // 算法结果数据最大长度
const static unsigned int IMVS_AUTO_LOAD_SOLU_STATE_STOP_EXECUTE     = 0;               // 启动时不需要执行
const static unsigned int IMVS_AUTO_LOAD_SOLU_STATE_EXECUTE_ONCE     = 1;               // 启动时执行一次
const static unsigned int IMVS_AUTO_LOAD_SOLU_STATE_CONTINUE_EXECUTE = 2;               // 启动时连续执行
const static unsigned int IMVS_CLIENT_TAKE_OVER_STATE_NOT_NEED       = 0;               // 不需要接管
const static unsigned int IMVS_CLIENT_TAKE_OVER_STATE_NEED           = 1;               // 需要接管
const static unsigned int IMVS_CLIENT_TAKE_OVER_STATE_HB_EXCEPTION   = 2;               // 界面心跳异常

/**************************** 模块类型 ***************************/
const static unsigned int IMVS_MODULE_TYPE_NORMAL               = 0;                    // 普通模块类型
const static unsigned int IMVS_MODULE_TYPE_PROCESS_CONTROL      = 1;                    // 流程控制模块类型
const static unsigned int IMVS_MODULE_TYPE_LOOP_CONTROL         = 2;                    // 循环模块类型
const static unsigned int IMVS_MODULE_TYPE_GLOBAL_COMMUNICAT    = 3;                    // 全局通信模块类型，在方案中，但不受流程控制
const static unsigned int IMVS_MODULE_TYPE_GLOBAL_QUEUE         = 4;                    // 全局队列模块，在方案中，但不受流程控制
const static unsigned int IMVS_MODULE_TYPE_GLOBAL_VARIABLE      = 5;                    // 全局变量模块，在方案中，但不受流程控制
const static unsigned int IMVS_MODULE_TYPE_GLOBAL_CAMERA        = 6;                    // 全局相机模块

/*************************** 加密狗类型长度 ***********************/
const static unsigned int IMVS_DEFINE_DONGLE_TYPE_LENGTH        = 16;                   // 加密狗类型长度

const static unsigned int IMVS_DEFINE_SUBSCRIBE_INDEX_LENGTH    = 256;                  // 订阅Index长度
const static unsigned int IMVS_DEFINE_MODULE_RES_STRING_LENGTH  = 4096;                 // 模块字符串结果长度
const static unsigned int IMVS_DEFINE_CUSTOM_OUTPUT_PAGE_SIZE   = 10;                   // 单次批量获取结果最大数量

/*************************** V3.2.0 性能优化新增 ***********************/
const static unsigned int IMVS_CAMPICINFO_LIST_NUM              = 256;                  // 相机图像信息列表数目
const static unsigned int IMVS_MAX_CORE_NUM                     = 64;                   // 最大CPU核心个数
const static unsigned int IMVS_MAX_RUN_POLICY_NUM               = 32;                   // 流程运行策略最大数量
const static unsigned int IMVS_MAX_SHARE_MEMORY_ADDR_LENGTH     = 260;                  // 共享内存最大地址长度
const static unsigned int IMVS_MAX_PATH_UTF8_LENGTH             = IMVS_MAX_PATH_LENGTH * 3; // 最大UTF8格式路径长度
const static unsigned int IMVS_DEFINE_PUB_ADDRESS_LENGTH        = 64;                   // Pub地址默认长度
const static unsigned int IMVS_MAX_RESULT_PARAM_NAME_LENGTH     = 128;                  // 模块结果参数名称长度
const static unsigned int IMVS_SOLUTION_VERSION_LENGTH          = 32;                   // 方案版本长度
const static unsigned int IMVS_BINARY_DATA_PARAM_LENGTH         = 256;                  // 二进制数据长度

/*************************** V3.4.0 性能优化新增 ***********************/
const static unsigned int IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH   = 256;                  // 最大模块显示名称长度

/*************************** V4.0 新增 ***********************/
const static unsigned int IMVS_MAX_THIRD_SOFTWARE_NUM = 16;                             // 最大二次开发进程数量
const static unsigned int IMVS_MAX_GLOBAL_TYPE_NUM    = 5;                              // 全局模块类型数量

/*************************** V4.1 新增 ***********************/
const static unsigned int IMVS_MAX_MODULE_INPUT_IO_NUM          = 128;                  // 最大模块IO参数个数
const static unsigned int IMVS_DEFAULT_BYTE_NUM                 = 4;                    // 默认参数个数
const static unsigned int IMVS_DEFAULT_STYLE_NUM                = 32;                   // 样式参数个数
const static unsigned int IMVS_MAX_OBJECT_IO_NUM                = 1024;                 // Group等实体最大IO个数
const static unsigned int IMVS_DEFAULT_DATA_NUM                 = 512;                  //默认附加数据个数

/*************************** V4.2 新增 ***********************/
const static unsigned int IMVS_REENTRANT_MAX_CMD_LEN            = 16;                  // 可重入最大触发字符串长度
const static unsigned int IMVS_CAMERA_MAX_SN_LEN                = 64;                  // 相机最大序列号长度
const static unsigned int IMVS_DYNAMIC_BINARY_LENGTH            = 32 * 1024;                       // 动态IO获取二进制数据长度初始大小

const static unsigned int IMVS_ALGORITHM_VERSION_LENGTH         = 64;                   // 算法版本信息长度

/*************************************************************************
 * 枚举定义
 *************************************************************************/
/** @enum IMVS_MODULE_TYPE
 *  @brief 模块类型
 */
typedef enum IMVS_MODULE_TYPE__
{
	IMVS_ENUM_MODULE_TYPE_NORMAL          = 0, //普通模块类型
	IMVS_ENUM_MODULE_TYPE_PROCESS_CONTROL = 1, // 流程控制模块类型
	IMVS_ENUM_MODULE_TYPE_LOOP_CONTROL    = 2, // 循环模块类型，在方案中，受流程控制
	IMVS_ENUM_MODULE_TYPE_GLOBAL_COMMUNICATION = 3, // 全局通信模块类型，在方案中，但不受流程控制
	IMVS_ENUM_MODULE_TYPE_GLOBAL_QUEUE    = 4, // 全局队列模块，在方案中，但不受流程控制
	IMVS_ENUM_MODULE_TYPE_GLOBAL_VARIABLE = 5, // 全局变量模块，在方案中，但不受流程控制
	IMVS_ENUM_MODULE_TYPE_GLOBAL_CAMERA   = 6, // 全局相机模块，在方案中，但不受流程控制
	IMVS_ENUM_MODULE_TYPE_GLOBAL_LIGHT    = 7, // 全局光源模块，在方案中，但不受流程控制
	IMVS_ENUM_MODULE_TYPE_GROUP           = 20 // Group模块，在方案中，受流程控制
} IMVS_MODULE_TYPE;

/** @enum IMVS_OUTPUT_PlATFORM_INFO_TYPE
 *  @brief 回调函数中的输出算法平台信息类型
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
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_DONGLE           = 9,                // 加密狗信息
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SERVER           = 0xa,              // Server状态信息
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_RESULT_FLAG = 0xb,            // 标志回调的状态
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_HEART            = 0xc,              // 心跳状态信息（废弃不用，统一用IMVS_ENUM_OUTPUT_PlATFORM_INFO_SERVER）
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_RESULT_EXTRA_INFO  = 0xd,     // 模块输出附加信息
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_WORK_STATUS  = 0xe,           // 模块的状态信息
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_XML_INFO  = 0xf,              // 模块的XML的最新的输入输出信息
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_SAVE_BEGIN      = 0x10,              // 方案保存开始
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_SAVE_END        = 0x11,              // 方案保存结束
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_SAVE_PROCESS    = 0x12,              // 方案保存进度
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_BEGIN      = 0x13,              // 方案加载开始
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_END        = 0x14,              // 方案加载结束
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_PROCESS    = 0x15,              // 方案加载进度
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_INTERFACE_FILE  = 0x16,         // 方案加载界面文件
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_MODULE_RESULT_EX         = 0x17,              // 模块结果回调给界面一个整体
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_CAMERA_COLLECT           = 0x18,              // 相机取图结束信息
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_COMMUNICATION_CONNECT    = 0x19,              // 通信连接信息
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_CAMERA_COLLECT_START     = 0x20,              // 相机取图开始信息
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_CAMERA_CONNECT_STATUS	= 0x21,              // 相机连接状态信息

    /****************************二次开发新增*****************************/
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_HB_CLIENT                     = 0x100,         // 平台界面心跳异常
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_HB_MODU                       = 0x101,         // 模块心跳异常信息
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_START_CONTINUOUSLY            = 0x102,         // 连续执行开始信息
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_STOP_EXECUTE                  = 0x103,         // 停止执行状态信息
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_START_RUN                     = 0x104,         // 开始运行状态信息
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_SOLUTION_SAVE_THIRD           = 0x105,         // 开始运行状态信息
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_SOLUTION_LOAD_DEVELOPER_DATA  = 0x106,         // 第三方方案加载文件数据

    // V3.0 新增
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_PROCEDURE_REGISTER_INFO      = 0x301,         // 流程注册信息
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_ALGORITHM_INIT_RESULT        = 0x302,         // 算法初始化结果
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_PROCESS_START_CONTINUOUSLY   = 0x303,         // 流程连续执行开始信息
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_PROCESS_STOP_EXECUTE         = 0x304,         // 流程停止执行状态信息
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_DETAIL_PLATFORM_BEGIN_INFO   = 0x305,         // 平台开始详细信息
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_PLATFORM_PROCESS_INFO        = 0x306,         // 平台流程状态信息
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_DETAIL_PLATFORM_END_INFO     = 0x307,         // 平台结束详细信息
    IMVS_ENUM_OUTPUT_PLATFORM_INFO_RESOURCE_USAGE_INFO          = 0x308,         // 资源占用状态信息
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_SP_PROXY_CRASH               = 0x309,         // 代理进程崩溃状态信息

	// V3.2 新增
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_GLOBALSCRIPT_CRASH           = 0x310,         // 全局脚本崩溃状态信息
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_GLOBALSCRIPT_REPORT_DATA     = 0x311,         // 全局脚本上报数据信息
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_LOAD_MODULE_WARN_INFO        = 0x312,         // 方案加载时模块错误警告信息

	// V3.2.0.1性能优化新增
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_EXECUTE_STATE_AFTER_LOAD_INFO = 0x313,        // 方案加载完成后是否执行资源初始化
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_PROCEDURE_UNREGISTER_INFO     = 0x314,        // 流程解注册信息

	// V3.3.0 新增
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_EXPORT_GROUP_BEGIN            = 0x315,        // Group导出开始
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_GROUP_END              = 0x316,        // Group导出结束
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_GROUP_PROGRESS         = 0x317,        // Group导出进度
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_IMPORT_GROUP_BEGIN            = 0x318,        // Group导入开始
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_GROUP_END              = 0x319,        // Group导入结束
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_GROUP_PROGRESS         = 0x320,        // Group导入进度
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_GROUP_NAME_NEWID       = 0x321,        // Group导入模块名称以及新ID
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_GROUP_INTERFACE_FILE   = 0x322,        // Group界面文件数据

	// V3.4.0 新增
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_UPDATE_PROCESS_NAME           = 0X323,        // 老版本方案加载结束后反馈流程的新名称
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_UPDATE_MODULE_NAME            = 0X324,        // 老版本方案加载结束后反馈模块的新名称
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_EXPORT_PROCESS_BEGIN          = 0x325,        // 流程导出开始
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_PROCESS_END            = 0x326,        // 流程导出结束
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_PROCESS_PROGRESS       = 0x327,        // 流程导出进度
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_IMPORT_PROCESS_BEGIN          = 0x328,        // 流程导入开始
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_END            = 0x329,        // 流程导入结束
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_PROGRESS       = 0x330,        // 流程导入进度
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_INTERFACE_FILE = 0x331,        // 流程导入界面数据
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_NEW_NAME_ID    = 0x332,        // 流程导入模块名称以及ID
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_TAKEOVER_PRC_INTERFACE_FILE   = 0x333,        // 界面接管流程界面文件数据
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_TAKEOVER_SOL_INTERFACE_FILE   = 0x334,        // 界面接管方案界面文件数据
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_IGNOREGLOBALVAR = 0x335,       // 流程导入忽略全局变量信息
    
	// V4.0 新增
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_UI_GLOBAL_PROCESS_OBJECT_ID    = 0x336,        // 加载方案时通知界面获取方案文件中的全局对象、流程对象信息
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_PROCESS_GET_UIDATA      = 0x337,        // 导入流程时通知界面获取数据
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_GROUP_GET_UIDATA        = 0x338,        // 导入Group时通知界面获取数据
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_MODULE_STATUS_INFO      = 0x339,        // 上报模块状态信息
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_CLOSE_SOLUTION_INFO     = 0x340,        // 上报关闭方案信息

	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_COMMU_RECV_DATA_INFO     = 0x400,       // 上报通信接收到的数据信息
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_COMMU_DEVICE_STATUS_INFO = 0x401,       // 上报通信设备状态信息

    // V4.0.1 新增
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_FRAME_LOSS_INFO          = 0x500,        // 上报丢帧信息

	// V4.2新增
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_EXPORT_MULTIPROCESS_BEGIN = 0x341,        // 多流程导出开始
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_MULTIPROCESS_END = 0x342,        // 多流程导出结束
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_EXPORT_MULTIPROCESS_PROGRESS = 0x343,        // 多流程导出进度
	IMVS_ENUM_OUTPUT_PLATFORM_INFO_IMPORT_MULTIPROCESS_BEGIN = 0x344,        // 多流程导入开始
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_MULTIPROCESS_END = 0x345,        // 多流程导入结束
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_MULTIPROCESS_PROGRESS = 0x346,        // 多流程导入进度
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_IMPORT_MULTIPROCESS_GET_UIDATA = 0x347,        // 多流程导入获取界面数据

    IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_GLOBAL_CAMERA_COLLECT_INFO = 0x402,       // 上报全局相机取图结束信息
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_OTHER_CLIENT_CONN_SERVER = 0x403,                // 另一个客户端连接到Server
    IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_PROXY_IMAGE_INFO = 0x404,                 // 透传代理图像数据到界面
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_GLOBAL_CAMERA_COLLECT_START_INFO = 0x405,       // 上报全局相机取图开始信息
	IMVS_ENUM_OUTPUT_PlATFORM_INFO_REPORT_CAMERA_CONNECT_STATUS_INFO = 0x406,       // 上报相机模块连接状态信息
} IMVS_OUTPUT_PlATFORM_INFO_TYPE;

/*************************************************************************
 * 结构体定义
 *************************************************************************/

/** @struct IMVS_INPUT_INFO
 *  @brief 输入信息
 */
typedef struct IMVS_INPUT_INFO__
{
    char                            strInput[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];        // 模块输入参数字符串
    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_INPUT_INFO;

/** @struct IMVS_INPUT_INFO_LIST
 *  @brief 输入信息列表
 */
typedef struct IMVS_INPUT_INFO_LIST__
{
    unsigned int                    nNum;                                               // 模块输入参数个数
    IMVS_INPUT_INFO                 astInputInfoList[IMVS_MAX_INPUT_NUM];               // 模块输入参数列表
    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_INPUT_INFO_LIST;

/** @struct IMVS_OUTPUT_INFO
 *  @brief 输出信息
 */
typedef struct IMVS_OUTPUT_INFO__
{
    char                            strOutput[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];       // 模块输出参数字符串
    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_OUTPUT_INFO;

/** @struct IMVS_OUTPUT_INFO_LIST
 *  @brief 输出信息列表
 */
typedef struct IMVS_OUTPUT_INFO_LIST__
{
    unsigned int                    nNum;                                               // 模块输出参数个数
    IMVS_OUTPUT_INFO                astOutputInfoList[IMVS_MAX_OUTPUT_NUM];             // 模块输出参数列表
    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_OUTPUT_INFO_LIST;

/** @struct IMVS_MODULE_INFO
 *  @brief 模块信息
 */
typedef struct IMVS_MODULE_INFO__
{
    unsigned int                    nNodeID;                                            // 节点ID
	char                            strDisplayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH];// 界面显示名称
    char                            strModuleName[IMVS_MAX_MODULE_NAME_LENGTH];         // 模块名称
    unsigned int                    nIsFatherLoop;                                      // 是否是父循环
    unsigned int                    nAlgorithmInitResult;                               // 算法初始化结果,0表示OK，其他表示错误码
    unsigned int                    nProcessID;                                         // 流程ID（算法平台V3.0新增）
    unsigned int                    nModuleType;                                        // 模块类型（算法平台V3.0新增）
	char                            strModuleGUID[IMVS_DEFAULT_GUID_LEN];               // 模块GUID (V3.2.0 Group2.0新增)
	unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_MODULE_INFO;

/** @struct IMVS_MODULE_INFO_LIST
 *  @brief 模块信息列表
 */
typedef struct IMVS_MODULE_INFO_LIST__
{
    unsigned int                    nNum;                                               // 模块个数
    IMVS_MODULE_INFO                astModuleInfo[IMVS_MAX_MODULE_NUM];                 // 模块信息列表
    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_MODULE_INFO_LIST;

/** @struct IMVS_SUBSCRIBE_INFO
 *  @brief 订阅信息
 */
typedef struct IMVS_SUBSCRIBE_INFO__
{
    // LocalImageModule(模块ID为0) ------> IMVS_CircleFindModule(模块ID为1)
    unsigned int                    nSubModuleID;                                       // 订阅方
    char                            strSubInput[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];     // 内容:"SubID+Sub内容":"%d+%s" : (1+输入图像宽度)

    unsigned int                    nPubModuleID;                                       // 发布方（被订阅方）
    char                            strPubOutput[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];    // 内容:"PubAddress+PubID+Pub内容":"tcp://10.67.131.101+0+输出图像宽度)
    unsigned int                    nIsPubConstant; // 0表示可变的被订阅内容，1表示strPubOutput为固定不变的阿拉伯数字

    // 若想要订阅第0个结果,填法如下:
    // nIsIndexConstant = 1;
    // strIndex = "0";
    // 若想要订阅第5个结果,填法如下:
    // nIsIndexConstant = 1;
    // strIndex = "5";
    // 若想要的结果是不定的,填写如下:
    // nIsIndexConstant = 0;
    // 因为是下标是不定的,所以必须将下标订阅一个数据
    // nIndexModuleID 被订阅的模块的ID
    // strIndex 被订阅的模块的实际内容
    unsigned int                    nIndexModuleID;
	char                            strIndex[IMVS_DEFINE_SUBSCRIBE_INDEX_LENGTH];    // 默认填写"All"
    unsigned int                    nIsIndexConstant; // 默认填写1

    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_SUBSCRIBE_INFO;

typedef struct IMVS_CONNECT_INFO__
{
    unsigned int                    nPreModuleID;
    unsigned int                    nNextModuleID;
    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_CONNECT_INFO;

/** @struct IMVS_CONNECT_INFO_LIST
 *  @brief 连接信息列表
 */
typedef struct IMVS_CONNECT_INFO_LIST__
{
    unsigned int                    nNum;                                               // 订阅信息个数
    IMVS_CONNECT_INFO               astConnectInfo[IMVS_MAX_MODULE_NUM];                // 订阅信息列表
    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_CONNECT_INFO_LIST;

typedef struct IMVS_GLOBAL_SELECT_INFO__
{
    unsigned int                    nSelectIp;                                          // 选择方IP
    unsigned short                  nSelectPort;                                        // 选择方Port
    //unsigned int                    nSelectModuleID;
    char                            strSelect[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];       // 选择方内容
    unsigned int                    nBeSelectedIp;                                      // 被选择方IP
    unsigned short                  nBeSelectedPort;                                    // 被选择方Port
    char                            strBeSelected[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];   // 被选择方内容
    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_GLOBAL_SELECT_INFO;

typedef struct IMVS_GLOBAL_SELECT_INFO_LIST__
{
    unsigned int                    nNum;                                               // 全局选择个数
    IMVS_GLOBAL_SELECT_INFO         astGlobalSelectInfo[IMVS_MAX_MODULE_NUM];           // 全局选择信息信息列表
    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_GLOBAL_SELECT_INFO_LIST;

/** @struct IMVS_PLATFORM_INFO
 *  @brief 平台基本信息
 */
typedef struct IMVS_PLATFORM_BASIC_INFO__
{
    unsigned int                    nRepIp;                                             // 平台RepIP
    unsigned short                  nRepPort;                                           // 平台RepPort
	unsigned int                    nRep4SDKIp;                                         // 平台与SDK间RepIP
	unsigned short                  nRep4SDKPort;                                       // 平台与SDK间RepPort
    unsigned int                    nNetAdapterIp;                                      // 平台关联网卡
    char                            strUserName[IMVS_MAX_USERNAME_LENGTH];              // 用户名
    char                            strPassWord[IMVS_MAX_PASSWORD_LENGTH];              // 密码
    char                            strVendorName[IMVS_MAX_VENDORNAME_LENGTH];          // 生产商
    unsigned int                    nMacLow;                                            // Mac地址低4字节
    unsigned short                  nMacHigh;                                           // Mac地址高2字节

    /****************二次开发新增*****************/
    unsigned int                    nClientType;                                        // 客户端类型  0(VM)；1(二次开发) 配合句柄类型使用
    unsigned int                    nServerType;									    // 0表示x86， 1表示M平台
	unsigned int                    nHandleType;									    // 句柄类型   0(主界面或二次开发)；1(导出程序)；2(全局脚本)
	unsigned int                    nServerRepIp;                                       // 导出程序SDK与服务RepIP
	unsigned short                  nServerRepPort;                                     // 导出程序SDK与服务RepPort
	unsigned int                    nServerProcID;                                      // 导出程序中服务进程ID
    unsigned int                    nReserved[2];                                       // 保留字段
} IMVS_PLATFORM_BASIC_INFO;

/** @struct IMVS_PLATFORM_INFO_LIST
 *  @brief 平台基本信息列表
 */
typedef struct IMVS_PLATFORM_BASIC_INFO_LIST__
{
    unsigned int                    nNum;                                               // 平台个数
    IMVS_PLATFORM_BASIC_INFO        astPlatformBasicInfo[IMVS_MAX_PLATFORM_NUM];        // 平台基本信息列表
} IMVS_PLATFORM_BASIC_INFO_LIST;

typedef struct IMVS_PLATFORM_ABILITY_
{
    unsigned int                    nNum;
    char                            astrModuleName[IMVS_MAX_MODULE_NUM][IMVS_MAX_MODULE_NAME_LENGTH]; // 最多128个模块，每个模块名字最多64字节
    // 忘记保留字节
} IMVS_PLATFORM_ABILITY;

/** @struct IMVS_OUTPUT_PLATFORM_INFO
 *  @brief 输出算法平台信息结构体
 */
typedef struct IMVS_OUTPUT_PLATFORM_INFO__
{
    unsigned int                    nInfoType;                                          // 回调信息类型
    void *                          pData;                                              // 回调数据
    unsigned int                    nDataSize;                                          // 回调数据分配内存
    unsigned int                    nDataLen;                                           // 回调数据实际长度
    unsigned int                    nReserved[4];                                       // 保留字段
} IMVS_OUTPUT_PLATFORM_INFO;

/** @struct IMVS_UNREGISTER_INFO
 *  @brief 解注册信息
 */
typedef struct IMVS_UNREGISTER_INFO__
{
    unsigned int                    nPubIp;                                             // Pub的Ip
    unsigned short                  nPubPort;                                           // Pub的Port
    unsigned int                    nReserved[4];                                       // 保留字段
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

// 加密狗信息
typedef struct IMVS_DONGLE_INFO__
{
    int             nDongleStatus;     // 加密狗状态
	char            strDongleType[IMVS_DEFINE_DONGLE_TYPE_LENGTH]; // 加密狗类型
	int             nCameraNum;        // 相机数量
	int             nRemainTime;       // 剩余时间
    unsigned int    nReserved[4];      // 保留字段
} IMVS_DONGLE_INFO;

// Server信息
typedef struct IMVS_SERVER_INFO__
{
    int             nServerStatus;  // Server状态:0表示正常，其他表示错误码
    unsigned int    nReserved[4];   // 保留字段
} IMVS_SERVER_INFO;

// Server信息
typedef struct IMVS_RESULT_FLAG_INFO__
{
    unsigned int    nFlagType;      // Flag类型，1表示开始，2表示结束
    unsigned int    nResultNum;     // 当前模块的结果类型个数，比如半径，中心X，中心Y，圆度，那么该值为4
	char            strPubAddress[IMVS_DEFINE_PUB_ADDRESS_LENGTH]; // 该模块的Pub地址
    unsigned int    nIsSelfExecute;
    unsigned int    nReserved[4];   // 保留字段
} IMVS_RESULT_FLAG_INFO;

// Heart信息
typedef struct IMVS_HEART_INFO__
{
    int             nHeartStatus;   // Server 心跳状态:0 表示正常，其他表示错误码
    unsigned int    nReserved[4];   // 保留字段
} IMVS_HEART_INFO;

// 模块结果附加信息, 后续增加成员
typedef struct IMVS_MODULE_RESULT_EXTRA_INFO__
{
    unsigned int    nStatus;
    unsigned int    nCycleID;       // 流程ID
	char            strPubAddress[IMVS_DEFINE_PUB_ADDRESS_LENGTH]; // 该模块的Pub地址
    float           fModuleTime;    // 模块时间,从输入数据全部到达开始计算，从将所有数据发送出去结束计算
    float           fAlgorithmTime; // 算法时间
    float           fCallBackTime; // 用户回调开始到用户回调结束的时间
    float           fCallBackGetTime; // CallBack中的Get时间
    float           fCallBackSetTime; // CallBack中的Set时间
    float           fTotalCycleTime; // 从总流程开始我本模块结束时间
    float           fTimeTestA;
    float           fTimeTestB;
    float           fTimeTestC;
    float           fTimeTestD;
    float           fTimeTestE;
    unsigned int    nReserved[4];// 保留字节
} IMVS_MODULE_RESULT_EXTRA_INFO;

// 模块状态信息
typedef struct IMVS_MODULE_WORK_STAUS__
{
    unsigned int    nWorkStatus;    // 0是空闲，1是忙碌
    unsigned int    nProcessID;     // 流程ID
    unsigned int    nIsTimeValid;   // 表示流程时间这个字段是否有效，无效的情况下界面不要使用。
    float           fProcessTime;   // 整个流程时间
	unsigned int    nExecuteCount;  // 流程执行次数
    char            strReCommand[IMVS_REENTRANT_MAX_CMD_LEN];  //流程重入触发字符串
    unsigned int    nReserved[3];   // 保留字段
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
	unsigned int    nProcess;                   // 与界面确认后修改，应为整型
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
	char            strValue[IMVS_DEFINE_MODULE_RES_STRING_LENGTH];    // V3.0.1修改，原为260
    unsigned int    nReserved[4];
} IMVS_MODULE_STRING_VALUE_EX;

typedef struct IMVS_MODULE_IMAGE_VALUE_EX_
{
    char *          pData;  // 实际数据,根据nUseRealData判断是否有意义
    unsigned int    nLen;   // 实际数据长度
	char            strValue[IMVS_MAX_SHARE_MEMORY_ADDR_LENGTH];  // 共享内存地址,根据nUseRealData判断是否有意义
    unsigned int    nUseRealData;   // 0表示使用共享内存地址，1表示使用pData，2表示 指针_长度_共享内存
    unsigned int    nMemoryOwner;   // pData内存所有标识，0:代表本身所有，1：不是本身所有，不进行释放
    unsigned int    nReserved[2];
} IMVS_MODULE_IMAGE_VALUE_EX;

typedef struct IMVS_MODULE_CHUNK_VALUE_EX_
{
    char *          pData;  // 实际数据
    unsigned int    nLen;   // 实际数据长度
	char            strValue[IMVS_MAX_SHARE_MEMORY_ADDR_LENGTH];  // 共享内存地址
    unsigned int    nUseRealData;   // 0表示使用共享内存地址，1表示使用pData
	unsigned int    nMemoryOwner;   // pData内存所有标识，0:内部申请，1：外部申请，不需释放
    unsigned int    nReserved[2];
} IMVS_MODULE_CHUNK_VALUE_EX;

typedef struct IMVS_MODULE_BYTEDATA_VALUE_EX_
{
	char *          pData;  // 实际数据
	unsigned int    nLen;   // 实际数据长度
	unsigned int    nReserved[4];
} IMVS_MODULE_BYTEDATA_VALUE_EX;

// sdk4Server新接口回调修改
typedef struct IMVS_MODULE_RESULT_INFO_EX__
{
    int             nValueStatus;           // 单个输出参数的状态 1成功，其他值失败
	char            strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];    // 参数名称
    int             nParamType;             // 1整型 2浮点型 3字符串型 4表示图像 5表示大数据   7 double
    int             nValueNum;              // 模块结果数量
    int *           pIntValue;              // 暂时不用
    float *         pFloatValue;            // 暂时不用
	double *        pDoubleValue;
    IMVS_MODULE_STRING_VALUE_EX * pStringValue;         // 由于界面以及二次开发用户难以处理，暂时长度固定,且不用二维指针
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
    long long       nRstTime;            // 秒
    int             nMilliSec;           // 毫秒
    unsigned int    nReserved[61];
} IMVS_MODULE_RESULT_RESERVED_INFO;

typedef struct IMVS_MODULE_RESULT_INFO_LIST_EX__
{
    // 模块结果基本信息
    unsigned int    nStatus;                // 整个模块的状态 1成功; 2模块异常；3前序分支模块异常；4 前序模块异常
	unsigned int    nErrorCode;             // 底层返回错误码
    unsigned int    nCycleID;               // 流程ID
    unsigned int    nModuleID;              // 模块ID
    float           fModuleTime;            // 模块时间
    float           fAlgorithmTime;         // 算法时间
    unsigned int    bInCycle;               // 是否循环内模块

	char *          pstrModuleName;         // 模块名称	
	char *          pstrDisplayName;        // 模块显示名称
	IMVS_MODULE_RESULT_RESERVED_INFO * pstResultReservedInfo;
	char *          pReserved[7];

	char            strPubAddress[IMVS_DEFINE_PUB_ADDRESS_LENGTH];    // Pub地址
	unsigned int    bIsSelfExecute;         // 是否自执行
    unsigned int    nExecuteCount;          // 执行次数
    unsigned int    nReserved[1];           // 保留字段

    // 模块结果具体数据
    int             nResultNum;             // 结果数量
    IMVS_MODULE_RESULT_INFO_EX * pInfo;     // 结果信息

    char            strReCommand[IMVS_REENTRANT_MAX_CMD_LEN];  //流程重入触发字符串
    unsigned int    nReservedEx[4];         // 保留字段
} IMVS_MODULE_RESULT_INFO_LIST_EX;


/************************* 二次开发新增 **************************/
// 模块参数列表
typedef struct IMVS_MODULE_PARAM__
{
    char               strParamName[IMVS_MAX_PARAM_NAME_LENGTH];      // 参数名称
    char               strParamValue[IMVS_MAX_PARAM_VALUE_LENGTH];    // 参数值
    unsigned int       nReserved[4];                                  // 保留字段
}IMVS_MODULE_PARAM;

typedef struct IMVS_MODULE_PARAM_LIST__
{
    unsigned int       nParamNum;                                 // 参数个数
    IMVS_MODULE_PARAM  stModuleParamList[IMVS_MAX_MODULE_PARAM_NUM];    // 模块参数
    unsigned int       nReserved[4];                              // 保留字段
}IMVS_MODULE_PARAM_LIST;

// 动态参数关联关系
typedef struct IMVS_DYNAMIC_PARAM_RELATION__
{
    unsigned int     nObjectID;                              // ID
    char             strName[IMVS_MAX_PARAM_NAME_LENGTH];    // 参数名称
    unsigned int     nReserved[4];                           // 保留字段
}IMVS_DYNAMIC_PARAM_RELATION;

// 动态参数关联关系列表
typedef struct IMVS_DYNAMIC_PARAM_RELATION_LIST__
{
    unsigned int     nNum;                                   // 数量
    IMVS_DYNAMIC_PARAM_RELATION stRelationList[IMVS_MAX_MODULE_PARAM_NUM];    // 关联关系
    unsigned int     nReserved[4];                           // 保留字段
}IMVS_DYNAMIC_PARAM_RELATION_LIST;

// 向模块导入数据输入参数信息结构
typedef struct IMVS_IMPORT_MODULE_DATA__
{
    char *              pData;                          // 导入文件绝对路径或数据长度
    unsigned int        nDataLen;                       // 导入文件绝对路径或数据长度
    char *              pRealData;
    unsigned int        nRealDataLen;
    unsigned int        nRealDataSize;
    unsigned int        nReserved[1];                   // 保留字段
}IMVS_IMPORT_MODULE_DATA;

typedef struct IMVS_IMPORT_MODULE_DATA_INPUT__
{
    unsigned int               nModuleID;                                   // 模块ID
    unsigned int               nDataType;                                   // 导入数据类型
    unsigned int               nDataNum;                                    // 导入数据个数
    IMVS_IMPORT_MODULE_DATA    stImportModuData[IMVS_MAX_IMPORT_NUM];       // 导入数据
	unsigned int               nRecvTimeout;                                // 接收超时
    unsigned int               nReserved[3];                                // 保留字段
}IMVS_IMPORT_MODULE_DATA_INPUT;

typedef struct IMVS_IMPORT_MODULE_DATA_OUTPUT__
{
    unsigned int               nModuleID;                                   // 模块ID
    unsigned int               nDataType;                                   // 导入数据类型
    unsigned int               nDataNum;                                    // 导入数据个数
    IMVS_IMPORT_MODULE_DATA    stImportModuData[IMVS_MAX_IMPORT_NUM];       // 导入数据
    unsigned int               nReserved[4];                                // 保留字段
}IMVS_EXPORT_MODULE_DATA_OUTPUT;

// 模块心跳异常信息结构
typedef struct IMVS_EXCEPTION_HB_MODULE_INFO__
{
    unsigned int    nClientStatus;                                 // 命令码
    unsigned int    nModuleID;                                     // 模块ID
    unsigned int    nProcessID;                                    // 流程ID
    char            strModuleName[IMVS_MAX_MODULE_NAME_LENGTH];    // 模块名称
	char            strDisPlayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // 模块显示名称
    unsigned int    nReserved[4];                                  // 保留字段
} IMVS_EXCEPTION_HB_MODULE_INFO;

// 平台界面心跳异常信息结构
typedef struct IMVS_EXCEPTION_HB_CLIENT_INFO__
{
    unsigned int    nClientStatus;  // 命令码 
    unsigned int    nReserved[4];   // 保留字段
} IMVS_EXCEPTION_HB_CLIENT_INFO;

// 连续执行开始状态信息
typedef struct IMVS_STATUS_START_CONTINUOUSLY_INFO__
{
    unsigned int    nStatus;       // 状态值
    unsigned int    nReserved[4];  // 保留字段
} IMVS_STATUS_START_CONTINUOUSLY_INFO;

// 停止执行状态信息
typedef struct IMVS_STATUS_STOP_INFO__
{
    unsigned int    nStatus;       // 状态值
    unsigned int    nReserved[4];  // 保留字段
} IMVS_STATUS_STOP_INFO;

// 开始运行状态信息
typedef struct IMVS_STATUS_START_RUN_INFO__
{
    unsigned int    nStatus;       // 状态值
    unsigned int    nReserved[4];  // 保留字段
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
    char *          pBinaryData; // 由用户分配大小,先调用IMVS_GetBinaryLength接口
    unsigned int    nBinaryLength;
    unsigned int    nReserved[4];
} IMVS_GET_BINARY_DATA_INFO;

// 相机取图信息结构
typedef struct IMVS_CAMERA_COLLECT_INFO__
{
    unsigned int nCameraID;     // CH: 相机ID | EN: Camera ID
    unsigned int nFrameNum;     // CH: 图像帧号 | EN: Frame number
    char strCameraSN[IMVS_CAMERA_MAX_SN_LEN];  // CH: 相机SN | EN: Camera SN
	unsigned int nCollectStatus;// CH: 取图状态 | EN: Collect Status
    unsigned int nReserved[3];  // CH: 保留字段 | EN: Reserved
} IMVS_CAMERA_COLLECT_INFO;

// 相机连接状态信息结构
typedef struct IMVS_CAMERA_CONNECT_STATUS_INFO__
{
	unsigned int nCameraID;     // CH: 相机ID | EN: Camera ID
	char strCameraSN[IMVS_CAMERA_MAX_SN_LEN];  // CH: 相机SN | EN: Camera SN
	unsigned int nConnectStatus;// CH: 连接状态（0-下线，1-上线） | EN: Connect Status（0-down，1-up）
	unsigned int nReserved[4];  // CH: 保留字段 | EN: Reserved
} IMVS_CAMERA_CONNECT_STATUS_INFO;

// CH: 通信连接信息结构 | EN: Communication connect information structure
typedef struct IMVS_COMMUNICATION_CONNECT_INFO__
{
    unsigned int nDeviceStatus;                                // CH: 设备状态 | EN: Device Status
    unsigned int nDeviceID;                                    // CH: 设备ID | EN: Device ID
    unsigned int nReserved[4];                                 // CH: 保留字段 | EN: Reserved
}IMVS_COMMUNICATION_CONNECT_INFO_INFO;

/**************************算法平台V3.0新增**************************/
typedef struct IMVS_ADD_MODULE_INFO_LIST__
{
    unsigned int nAddNum;                              // 流程中增加模块数量
    unsigned int nAddModuleID[IMVS_MAX_ADD_MODULE_NUM];// 流程中增加模块ID
    unsigned int nReserved[4];                         // 保留字段
}IMVS_ADD_MODULE_INFO_LIST;

typedef struct IMVS_DEL_MODULE_INFO_LIST__
{
    unsigned int nDelNum;                              // 流程中删除模块数量
    unsigned int nDelModuleID[IMVS_MAX_DEL_MODULE_NUM];// 流程中删除模块ID
    unsigned int nReserved[4];                         // 保留字段
}IMVS_DEL_MODULE_INFO_LIST;

typedef struct IMVS_PROCESS_INFO__
{
    unsigned int                    nProcID;                                      // 流程ID
    char                            chProcName[IMVS_MAX_PROCESS_NAME_LENGTH];     // 流程名称
    unsigned int                    nModuleType;                                  // 模块类型
	char                            strProcGUID[IMVS_DEFAULT_GUID_LEN];           // 流程GUID (V3.2.0 新增)
	int                             nInitErrorCode;                               // 初始化结果,0表示OK，其他表示错误码
    unsigned int                    nReserved[4];                                 // 保留字段
}IMVS_PROCESS_INFO;

typedef struct IMVS_ALGORITHM_INIT_RESULT_INFO__
{
    unsigned int    nModuleID;                                   // 模块ID
    unsigned int    nType;                                       // 界面与模块传输内容类型
    char            strTransData[IMVS_MAX_TRANS_DATA_LENGTH];    // 算法结果数据
    unsigned int    nReserved[4];                                // 保留字段
}IMVS_ALGORITHM_INIT_RESULT_INFO;

typedef struct IMVS_COMMU_REPORT_DATA_INFO__
{
	int    nType;                                       // 通信类型
	char * pData;                                       // 上报数据
	int    nLen;                                        // 数据长度
	int    nReserved[4];                                // 保留字段
}IMVS_COMMU_REPORT_DATA_INFO;

typedef struct IMVS_PROCESS_INFO_LIST__
{
    unsigned int         nNum;                                    // 流程个数
    IMVS_PROCESS_INFO    astProcessInfo[IMVS_MAX_PROCESS_NUM];    // 流程信息列表
    unsigned int         nReserved[4];                            // 保留字段
} IMVS_PROCESS_INFO_LIST;

// 单个流程连续执行开始状态信息
typedef struct IMVS_STATUS_PROCESS_START_CONTINUOUSLY_INFO__
{
    unsigned int    nStatus;       // 状态值
    unsigned int    nProcessID;    // 流程ID
    unsigned int    nReserved[4];  // 保留字段
} IMVS_STATUS_PROCESS_START_CONTINUOUSLY_INFO;

// 单个流程停止执行状态信息
typedef struct IMVS_STATUS_PROCESS_STOP_INFO__
{
    unsigned int    nStatus;       // 状态值
    unsigned int    nProcessID;    // 流程ID
	unsigned int    nStopAction;   // 流程停止的原因 (0:无效; 1:正常停止; 2:流程NG; 3:模块请求停止流程)
    unsigned int    nReserved[3];  // 保留字段
} IMVS_STATUS_PROCESS_STOP_INFO;

// 平台详细信息
typedef struct IMVS_PLATFORM_DETAILED_INFO__
{
    char            strSolutionPath[IMVS_MAX_PATH_UTF8_LENGTH];    // 方案路径
    char            strPassWord[IMVS_MAX_PASSWORD_LENGTH];    // 方案密码
    unsigned int    nReserved[4];    // 保留字段
} IMVS_PLATFORM_DETAILED_INFO;

// 接管状态信息
typedef struct IMVS_STATUS_TAKEOVER_INFO__
{
    unsigned int    nTakeoverStatus;    // 状态值
    unsigned int    nReserved[4];       // 保留字段
} IMVS_STATUS_TAKEOVER_INFO;

// 自动加载方案信息结构
typedef struct IMVS_AUTO_LOAD_SOLUTION_INFO__
{
    unsigned int    nIfAutoLoad;             // 是否自动加载
	char            strSolutionPath[IMVS_MAX_PATH_UTF8_LENGTH];    // 方案路径
    char            strPassWord[IMVS_MAX_PASSWORD_LENGTH];         // 方案密码
    unsigned int    nExecuteStatus;          // 执行状态 （启动时不执行：0；执行一次：1；连续执行：2）
    unsigned int    nReserved[4];            // 保留字段
} IMVS_AUTO_LOAD_SOLUTION_INFO;

// 发送平台开始信息
typedef struct IMVS_DETAIL_PLATFORM_BEGIN_INFO__
{
    unsigned int    nClientType;             // 客户端类型
    unsigned int    nReserved[4];            // 保留字段
} IMVS_DETAIL_PLATFORM_BEGIN_INFO;

// 流程执行状态信息
typedef struct IMVS_PROC_CONTIEXECUTE_INFO__
{
    unsigned int    nProcessID;             // 流程ID
    unsigned int    nProcRunStatus;         // 流程连续执行状态（0：表示非执行状态；1：表示连续执行状态）
    unsigned int    nReserved[4];           // 保留字段
} IMVS_PROC_CONTIEXECUTE_INFO;

// 流程执行状态信息列表
typedef struct IMVS_PROC_CONTIEXECUTE_INFO_LIST__
{
    unsigned int                   nNum;                   // 流程数量
    IMVS_PROC_CONTIEXECUTE_INFO    stProcExecuteInfo[IMVS_MAX_PROCESS_NUM];    // 流程连续执行状态信息
    unsigned int                   nReserved[4];           // 保留字段
} IMVS_PROC_CONTIEXECUTE_INFO_LIST;

// 发送平台结束信息
typedef struct IMVS_DETAIL_PLATFORM_END_INFO__
{
    unsigned int    nClientType;             // 客户端类型
    int             nErrorCode;              // 错误码
    unsigned int    nReserved[4];            // 保留字段
} IMVS_DETAIL_PLATFORM_END_INFO;

// 资源占用状态信息
typedef struct IMVS_RESOURCE_USAGE_INFO__
{
    int             nMemUsage;               // 内存使用率
    int             nCPUUsage;               // CPU使用率
    int             nHardSpace;              // 程序所在硬盘剩余空间（单位MB）
	int             nNetWorkUsage;           // 网络使用率
    unsigned int    nReserved[3];            // 保留字段
} IMVS_RESOURCE_USAGE_INFO;

// 代理崩溃状态信息
typedef struct IMVS_PROXY_CRASH_SP_INFO__
{
	int             nHasSolStatu;            // 是否存在方案状态 0：方案不存在，1：方案存在
	unsigned int    nReserved[4];            // 保留字段
} IMVS_PROXY_CRASH_SP_INFO;

// 代理崩溃状态信息
typedef struct IMVS_GLOBALSCRIPT_CRASH_INFO__
{
	unsigned int    nStatus;                 // 全局脚本崩溃状态
	unsigned int    nReserved[4];            // 保留字段
} IMVS_GLOBALSCRIPT_CRASH_INFO;

// 全局脚本上报数据信息
typedef struct IMVS_GLOBALSCRIPT_REPORTDATA_INFO__
{
	unsigned char * pData;         // 全局脚本上报数据
	unsigned int    nDataLen;      // 上报数据长度
	unsigned int    nReserved[4];  // 保留字段
} IMVS_GLOBALSCRIPT_REPORTDATA_INFO;

// 加载方案是否执行资源预分配信息
typedef struct IMVS_EXECUTE_STATE_AFTER_LOAD_INFO__
{
	int             nStatus;                 // 加载方案是否执行状态
	unsigned int    nReserved[4];            // 保留字段
} IMVS_EXECUTE_STATE_AFTER_LOAD_INFO;

// 流程解注册信息 
typedef struct IMVS_PROCEDURE_UNREGISTER_INFO__
{
	unsigned int    nClientType;   // 客户端类型
	unsigned int    nProcessID;    // 删除流程ID
	int             nErrorCode;    // 删除流程状态
	char            strProcessName[IMVS_MAX_PROCESS_NAME_LENGTH]; // 流程名称
	unsigned int    nReserved[4];  // 保留字段
} IMVS_PROCEDURE_UNREGISTER_INFO;

// 模块基本结果信息
typedef struct IMVS_MODULE_BASIC_INFO__
{
    unsigned int   nModuleID;                                      // 模块ID
	char           strDisplayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // 界面显示名称
    char           strModuleName[IMVS_MAX_MODULE_NAME_LENGTH];     // 模块名称
    unsigned int   nReserved[16];                                  // 保留字段
} IMVS_MODULE_BASIC_INFO;

// 模块基本结果信息列表
typedef struct IMVS_MODULE_BASIC_INFO_LIST__
{
    unsigned int                    nNum;                                  // 模块个数
    IMVS_MODULE_BASIC_INFO          astModuleInfo[IMVS_MAX_MODULE_NUM];    // 模块信息列表
    unsigned int                    nReserved[4];                          // 保留字段
} IMVS_MODULE_BASIC_INFO_LIST;

/** @struct IMVS_CUSTOM_SUBSCRIBE_INFO
 *  @brief 订阅信息
 */
typedef struct IMVS_CUSTOM_SUBSCRIBE_INFO__
{
	unsigned int nIfDelete;                                                // 是否为删除配置信息 1-删除；0-设置
	unsigned int nOutputType;                                              // 输出数据类型：1-整型；2-浮点型；3-字符串型；4-图像型；5-大数据型
	unsigned int nSubProcessID;                                            // 订阅方 流程ID
	char         strInputParamName[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];     // 内容:用户自定义配置参数名称
	unsigned int nPubModuleID;                                             // 发布方（被订阅方模块ID）
	char         strOutputParamName[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];    // 内容:被订阅方模块参数名称
	unsigned int nIsPubConstant;                                           // 是否订阅常量：0-变量订阅；1-常量订阅
	unsigned int nIndexModuleID;                                           // 索引下标对应模块ID
	char         strIndexContent[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH];       // 索引下标订阅字段，默认全部订阅为"All"
	unsigned int nIsIndexConstant;                                         // 索引下标是否订阅常量：0-变量订阅；1-常量订阅
	unsigned int nReserved[4];                                             // 保留字段
} IMVS_CUSTOM_SUBSCRIBE_INFO;

typedef struct IMVS_VARIABLE_PARAM_VALUE__
{
	int  nModuleId;                     // 模块ID
	char chParamName[IMVS_MAX_PARAM_NAME_LENGTH];  // 参数名称
	char chReserve[64];                 // 保留字段
}IMVS_VARIABLE_PARAM_VALUE;

typedef struct IMVS_CUSTOM_SUBSCRIBE_VALUE__
{
	unsigned int            nOutputType;           // 输出数据类型：1-整型；2-浮点型；3-字符串型；4-图像型；5-大数据型
	unsigned int            nVarType;              // 被订阅变量类型
	char chOutputName[IMVS_MAX_PARAM_NAME_LENGTH]; // 用户配置参数名称
	char chConstantValue[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH]; // 常量
	IMVS_VARIABLE_PARAM_VALUE stVariableValue;               // 变量
}IMVS_CUSTOM_SUBSCRIBE_VALUE;

/** @struct IMVS_GET_CUSTOM_SUBSCRIBE_INFO_LIST
 *  @brief 用户自定义输出订阅获取信息
 */
typedef struct IMVS_GET_CUSTOM_SUBSCRIBE_INFO_LIST__
{
	unsigned int                nOutputNum;        // 输出字段数量
	unsigned int                nTotalNum;         // 输出字段总数
	IMVS_CUSTOM_SUBSCRIBE_VALUE stCustomSubInfo[IMVS_DEFINE_CUSTOM_OUTPUT_PAGE_SIZE]; // 模块输出订阅信息
	unsigned int    nReserved[4];                  // 保留字段
} IMVS_GET_CUSTOM_SUBSCRIBE_INFO_LIST;

/**************************** V3.2.0 性能优化新增 ***************************/
// 加载方案上报错误信息
typedef struct IMVS_LOAD_MODULE_ERROR_INFO__
{
	unsigned int nModuleID;                                  // 模块ID
	char         strModuleName[IMVS_MAX_MODULE_NAME_LENGTH]; // 模块名称
	int          nErrorCode;                                 // 错误码
} IMVS_LOAD_MODULE_ERROR_INFO;

// 加载方案上报错误信息列表
typedef struct IMVS_LOAD_MODULE_ERROR_INFO_LIST__
{
	unsigned int nClientType;                   // 客户端类型
	unsigned int nModuleNum;                    // 上报错误信息模块数量
	IMVS_LOAD_MODULE_ERROR_INFO astLoadModuErrInfo[IMVS_MAX_MODULE_NUM]; // 加载方案上报错误信息
	unsigned int nReserved[4];                  // 保留字段
} IMVS_LOAD_MODULE_ERROR_INFO_LIST;

// V3.2.0 性能优化新增
typedef struct IMVS_CAMERA_PIC_INFO__
{
	int  nCameraId;                            // 相机模块Id
	char szLocalPicPath[IMVS_MAX_PATH_UTF8_LENGTH]; // 本地图片路径，utf8编码
}IMVS_CAMERA_PIC_INFO;

// 相机图像信息列表
typedef struct IMVS_CAMERA_PIC_INFO_LIST__
{
	int nNum;                                                        // 列表实际大小
	IMVS_CAMERA_PIC_INFO stCamPicInfoList[IMVS_CAMPICINFO_LIST_NUM]; // 相机图像信息列表
	int                  nTimeout;                                   // 接口超时
	unsigned int         nIsAllModuRun;                              // 是否所有模块执行（0：深度学习模块，1：所有模块）
	unsigned int         nReserved[3];                               // 保留字段
}IMVS_CAMERA_PIC_INFO_LIST;

// 用户自定义流程运行策略信息结构
typedef struct IMVS_PROCEDURE_CUSTOM_RUN_POLICY__
{
	int          nProcessID;       // 流程ID
	int          nThreadNum;       // 指定流程其执行线程数目
	char         chCpuCore[IMVS_MAX_CORE_NUM]; // 指定流程运行的CPU核心 CPU核数组，0-无效，1-有效。
	                                           // byCpuCore[0]表示cpu0、byCpuCore[1]表示cpu1, byCpuCore[2]表示cpu2...
	unsigned int nReserved[4];     // 保留字段
}IMVS_PROCEDURE_CUSTOM_RUN_POLICY;

// 用户自定义流程运行策略信息列表结构
typedef struct IMVS_PROCEDURE_CUSTOM_RUN_POLICY_LIST__
{
	int nNum;                                           // 运行配置个数
	IMVS_PROCEDURE_CUSTOM_RUN_POLICY stPolicyList[IMVS_MAX_RUN_POLICY_NUM]; // 运行配置
	unsigned int nReserved[4];     // 保留字段
}IMVS_PROCEDURE_CUSTOM_RUN_POLICY_LIST;

// 流程运行策略枚举类型
typedef enum IMVS_PROCEDURE_RUN_POLICY_TYPE__
{
	PROCEDURE_RUN_POLICY_INVALID = 0,     // 无效
	PROCEDURE_RUN_POLICY_HIGH_SPEED = 1,  // 快速运行模式（默认）
	PROCEDURE_RUN_POLICY_CUSTOM = 2,       // 用户自定义运行方式
    PROCEDURE_RUN_POLICY_TIME_STABILITY = 3  // 保证耗时稳定性 V4.2新增
}IMVS_PROCEDURE_RUN_POLICY_TYPE;

// 流程运行策略
typedef struct IMVS_PROCEDURE_RUN_POLICY__
{
	unsigned int nRunPolicy;      // 流程运行方式 (IMVS_PROCEDURE_RUN_POLICY_TYPE中类型)
	int          nCustomIndex;    // 当nRunMode为 PROCEDURE_RUN_POLICY_CUSTOM时有效。获取时，当流程数量大于IMVS_MAX_RUN_POLICY_NUM时，指定取值起始索引
	IMVS_PROCEDURE_CUSTOM_RUN_POLICY_LIST stCustomRunPolicy; // 当nRunPolicy为 PROCEDURE_RUN_POLICY_CUSTOM 时有效
	unsigned int nReserved[4];    // 保留字段
}IMVS_PROCEDURE_RUN_POLICY;

// 底层所在机器处理器信息结构
typedef struct IMVS_PROCESSOR_INFO__
{
	int          nLogicProcessorNum;    // 逻辑处理器个数
	char         strReserved[512];      // 保留字段
	unsigned int nReserved[4];          // 保留字段
}IMVS_PROCESSOR_INFO;

/**************************** V3.3.0 新增 ***************************/
// Group2.0模块信息结构
typedef struct IMVS_GROUP_MODULE_INFO__
{
	unsigned int nGroupId;                        // Group模块ID
	int          nSonModuNum;                     // 子模块数量
	unsigned int anModuleId[IMVS_MAX_MODULE_NUM]; // Group子模块ID列表
	unsigned int nReserved[4];                    // 保留字段
}IMVS_GROUP_MODULE_INFO;

// Group导出开始信息
typedef struct IMVS_EXPORT_GROUP_BEGIN_INFO__
{
	unsigned int    nClientType;  // 客户端类型
	unsigned int    nReserved[4]; // 保留字段
} IMVS_EXPORT_GROUP_BEGIN_INFO;

// Group导出结束信息
typedef struct IMVS_EXPORT_GROUP_END_INFO__
{
	unsigned int    nGroupId;                           // Group模块ID
	unsigned int    nClientType;                        // 客户端类型
	char            strGroupPath[IMVS_MAX_PATH_UTF8_LENGTH]; // Group文件路径
	int             nErrorCode;                         // 错误码
	unsigned int    nReserved[4];                       // 保留字段
} IMVS_EXPORT_GROUP_END_INFO;

// Group导出进度信息
typedef struct IMVS_EXPORT_GROUP_PROGRESS_INFO__
{
	unsigned int    nProgress;     // 进度
	unsigned int    nReserved[4]; // 保留字段
} IMVS_EXPORT_GROUP_PROGRESS_INFO;

// Group导入开始信息
typedef struct IMVS_IMPORT_GROUP_BEGIN_INFO__
{
	unsigned int    nClientType;  // 客户端类型
	unsigned int    nReserved[4]; // 保留字段
} IMVS_IMPORT_GROUP_BEGIN_INFO;

// Group导入结束信息
typedef struct IMVS_IMPORT_GROUP_END_INFO__
{
	unsigned int    nProcessId;                         // 流程ID
	unsigned int    nClientType;                        // 客户端类型
	char            strGroupPath[IMVS_MAX_PATH_UTF8_LENGTH]; // Group文件路径
	int             nErrorCode;                         // 错误码
	unsigned int    nGroupNewId;                        // 导入Group模块新ID
	char            strGroupNewName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // 导入Group模块新名称
	unsigned int    nReserved[4];                       // 保留字段
} IMVS_IMPORT_GROUP_END_INFO;

// Group导入进度信息
typedef struct IMVS_IMPORT_GROUP_PROGRESS_INFO__
{
	unsigned int    nProgress;     // 进度
	unsigned int    nReserved[4]; // 保留字段
} IMVS_IMPORT_GROUP_PROGRESS_INFO;

// Group 导入模块名称与新ID信息
typedef struct IMVS_GROUP_NEW_MODULEID_NAME_INFO__
{
	unsigned int    nNewModuID;   // 新模块ID
	unsigned int    nOldModuID;   // 原模块ID
	char            strModuNewName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // 模块新名称
	unsigned int    nReserved[4]; // 保留字段
} IMVS_GROUP_NEW_MODULEID_NAME_INFO;

// Group 导入模块名称与新ID信息列表
typedef struct IMVS_GROUP_NEW_MODULEID_NAME_INFO_LIST__
{
	unsigned int    nNum;         // 模块数量
	IMVS_GROUP_NEW_MODULEID_NAME_INFO astModuIdName[IMVS_MAX_MODULE_NUM]; // 模块GUID与新ID信息
	unsigned int    nReserved[4]; // 保留字段
} IMVS_GROUP_NEW_MODULEID_NAME_INFO_LIST;

// Group 导入界面文件数据
typedef struct IMVS_GROUP_IMPORT_INTERFACE_FILE_INFO__
{
	char *          pData;
	unsigned int    nDataLen;
	unsigned int    nReserved[4];
} IMVS_GROUP_IMPORT_INTERFACE_FILE_INFO;

// Group输入输出信息
typedef struct IMVS_GROUP_IO_INFO__
{
	unsigned int    nValueType;    // 输入输出参数值类型: 1整型 2浮点型 3字符串型 4表示图像 5表示大数据
	char            strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH]; // 参数名称
} IMVS_GROUP_IO_INFO;

// Group输入输出信息列表
typedef struct IMVS_GROUP_IO_INFO_LIST__
{
	unsigned int       nGroupId;                                 // Group模块ID
	unsigned int       nInputNum;                                // Group输入信息数量
    IMVS_GROUP_IO_INFO stGroupInput[IMVS_MAX_OBJECT_IO_NUM];   // Group输入信息列表
	unsigned int       nOutputNum;                               // Group输出信息数量
    IMVS_GROUP_IO_INFO stGroupOutput[IMVS_MAX_OBJECT_IO_NUM];  // Group输出信息列表
	unsigned int       nReserved[4];                             // 保留字段
} IMVS_GROUP_IO_INFO_LIST;

// 流程输入输出信息
typedef struct IMVS_PROCEDURE_IO_INFO__
{
	unsigned int    nValueType;    // 输入输出参数值类型: 1整型 2浮点型 3字符串型 4表示图像 5表示大数据
	char            strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH]; // 参数名称
} IMVS_PROCEDURE_IO_INFO;

// 流程输入输出信息列表
typedef struct IMVS_PROCEDURE_IO_INFO_LIST__
{
	unsigned int       nProcedureId;                             // 流程模块ID
	unsigned int       nInputNum;                                // 流程输入信息数量
    IMVS_PROCEDURE_IO_INFO stProcInput[IMVS_MAX_OBJECT_IO_NUM];  // 流程输入信息列表
	unsigned int       nOutputNum;                               // 流程输出信息数量
    IMVS_PROCEDURE_IO_INFO stProcOutput[IMVS_MAX_OBJECT_IO_NUM]; // 流程输出信息列表
	unsigned int       nReserved[4];                             // 保留字段
} IMVS_PROCEDURE_IO_INFO_LIST;

// 被订阅模块变量的索引类型
typedef enum IMVS_ENUM_SUBSCRIBE_INDEX_TYPE__ : int
{
	SUBSCRIBE_INDEX_INVALID  = 0,  // 无效
	SUBSCRIBE_INDEX_ALL      = 1,  // 常量全部
	SUBSCRIBE_INDEX_CONSTANT = 2,  // 常量索引
	SUBSCRIBE_INDEX_VARIABLE = 3   // 变量
}IMVS_ENUM_SUBSCRIBE_INDEX_TYPE;

// 订阅模块信息结构
typedef struct IMVS_SUBSCRIBE_MODULE_PARAM_INFO__
{
	int  nModuleId;                                // 模块ID
	char byParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];  // 参数名
} IMVS_SUBSCRIBE_MODULE_PARAM_INFO;

// 变量订阅信息结构
typedef struct IMVS_VARIABLE_VALUE_INFO__
{
	IMVS_ENUM_SUBSCRIBE_INDEX_TYPE eIndexType;                // 被订阅变量类型
	char strIndexConstant[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH]; // 常量索引值 (全部订阅填All)
	IMVS_SUBSCRIBE_MODULE_PARAM_INFO stIndexVariable;         // 变量索引值
	IMVS_SUBSCRIBE_MODULE_PARAM_INFO stModuleParam;           // 被订阅模块变量
} IMVS_VARIABLE_VALUE_INFO;

// 被订阅变量类型
typedef enum IMVS_ENUM_SUBSCRIBE_VAR_TYPE__ : int
{
	SUBSCRIBE_VAR_INVAlID  = 0,   // 无效
	SUBSCRIBE_VAR_CONSTANT = 1,   // 常量
	SUBSCRIBE_VAR_GLOBAL   = 2,   // 全局字符串
	SUBSCRIBE_VAR_VARIABLE = 3    // 变量
}IMVS_ENUM_SUBSCRIBE_VAR_TYPE;

// 模块订阅信息结构
typedef struct IMVS_SUBSCRIBE_MODU_PARAM_INFO__
{
	IMVS_ENUM_SUBSCRIBE_VAR_TYPE eVarType;                    // 被订阅变量类型
	char strConstantValue[IMVS_MAX_SUBSCRIBE_CONTENT_LENGTH]; // 常量
	IMVS_VARIABLE_VALUE_INFO     stVariableValue;             // 变量
} IMVS_SUBSCRIBE_MODU_PARAM_INFO;

// 模块结果数据类型
typedef enum IMVS_ENUM_MODULE_RESULT_TYPE__ : unsigned int
{
	IMVS_MODURES_TYPE_INVALID = 0,                        // 无效数据
	IMVS_MODURES_TYPE_INT     = 1,                        // 整型数据
	IMVS_MODURES_TYPE_FLOAT   = 2,                        // 浮点型数据
	IMVS_MODURES_TYPE_STRING  = 3,                        // 字符串型数据
	IMVS_MODURES_TYPE_IMAGE   = 4,                        // 图像型数据
	IMVS_MODURES_TYPE_CHUNK   = 5,                        // 大数据类型数据
	IMVS_MODURES_TYPE_BYTEDATA= 6,                         // 二进制数据类型数据
	IMVS_MODURES_TYPE_DOUBLE = 7                        // DOUBLE数据类型数据
}IMVS_ENUM_MODULE_RESULT_TYPE;

// 全局变量绑定参数信息结构
typedef struct IMVS_BIND_GLOBALVAR_PARAM_INFO__
{
	unsigned int nModuleId;                              // 全局变量模块ID
	IMVS_ENUM_MODULE_RESULT_TYPE eGlobalVarType;         // 全局变量类型
	char strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];// 全局变量名称
	IMVS_SUBSCRIBE_MODU_PARAM_INFO stBindValue;          // 全局变量绑定值
} IMVS_BIND_GLOBALVAR_PARAM_INFO;

// 全局变量绑定参数信息列表结构
typedef struct IMVS_BIND_GLOBALVAR_PARAM_INFO_LIST__
{
	unsigned int nNum;                                   // 全局变量绑定参数数量
	IMVS_BIND_GLOBALVAR_PARAM_INFO astBindGlobalVarList[IMVS_MAX_MODULE_PARAM_NUM]; // 全局变量绑定参数信息
	unsigned int       nReserved[4];                     // 保留字段
} IMVS_BIND_GLOBALVAR_PARAM_INFO_LIST;

// 获取全局变量绑定参数信息列表结构
typedef struct IMVS_GET_BIND_GLOBALVAR_PARAM_INFO_LIST__
{
	unsigned int nTotalNum;                              // 全局变量绑定参数总数
	unsigned int nNum;                                   // 全局变量绑定参数数量
	IMVS_BIND_GLOBALVAR_PARAM_INFO astBindGlobalVarList[IMVS_MAX_MODULE_PARAM_NUM]; // 全局变量绑定参数信息
	unsigned int       nReserved[4];                     // 保留字段
} IMVS_GET_BIND_GLOBALVAR_PARAM_INFO_LIST;

// 取消全局变量绑定参数信息结构
typedef struct IMVS_UNBIND_GLOBALVAR_PARAM_INFO__
{
	unsigned int nModuleId;                              // 全局变量模块ID
	IMVS_ENUM_MODULE_RESULT_TYPE eGlobalVarType;         // 全局变量类型
	char strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];       // 全局变量名称
} IMVS_UNBIND_GLOBALVAR_PARAM_INFO;

// 取消全局变量绑定参数信息列表结构
typedef struct IMVS_UNBIND_GLOBALVAR_PARAM_INFO_LIST__
{
	unsigned int nNum;                                   // 全局变量绑定参数数量
	IMVS_UNBIND_GLOBALVAR_PARAM_INFO astBindGlobalVarList[IMVS_MAX_MODULE_PARAM_NUM]; // 全局变量绑定参数信息
	unsigned int       nReserved[4];                     // 保留字段
} IMVS_UNBIND_GLOBALVAR_PARAM_INFO_LIST;


// 模块输出绑定关键字参数信息结构
typedef struct IMVS_BIND_MODULE_PARAM_INFO__
{
	unsigned int nModuleId;                              // 模块ID
	IMVS_ENUM_MODULE_RESULT_TYPE eVarType;               // 变量类型
	char strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];// 变量名称
	IMVS_SUBSCRIBE_MODU_PARAM_INFO stBindValue;          // 变量绑定值
} IMVS_BIND_MODULE_PARAM_INFO;

// 模块输出绑定关键字参数信息列表结构
typedef struct IMVS_BIND_MODULE_PARAM_INFO_LIST__
{
	unsigned int nNum;                                   // 变量绑定参数数量
	IMVS_BIND_MODULE_PARAM_INFO astBindModuVarList[IMVS_MAX_MODULE_PARAM_NUM]; // 变量绑定参数信息
	unsigned int       nReserved[4];                     // 保留字段
} IMVS_BIND_MODULE_PARAM_INFO_LIST;

// 获取模块输出绑定关键字参数信息列表结构
typedef struct IMVS_GET_BIND_MODULE_PARAM_INFO_LIST__
{
	unsigned int nTotalNum;                              // 变量绑定参数总数
	unsigned int nNum;                                   // 变量绑定参数数量
	IMVS_BIND_MODULE_PARAM_INFO astBindModuVarList[IMVS_MAX_MODULE_PARAM_NUM]; // 变量绑定参数信息
	unsigned int       nReserved[4];                     // 保留字段
} IMVS_GET_BIND_MODULE_PARAM_INFO_LIST;

// 取消模块输出绑定关键字参数信息结构
typedef struct IMVS_UNBIND_MODULE_PARAM_INFO__
{
	unsigned int nModuleId;                              // 变量模块ID
	IMVS_ENUM_MODULE_RESULT_TYPE eVarType;               // 变量类型
	char strParamName[IMVS_MAX_RESULT_PARAM_NAME_LENGTH];// 变量名称
} IMVS_UNBIND_MODULE_PARAM_INFO;

// 取消模块输出绑定关键字参数信息列表结构
typedef struct IMVS_UNBIND_MODULE_PARAM_INFO_LIST__
{
	unsigned int nNum;                                   // 变量绑定参数数量
	IMVS_UNBIND_MODULE_PARAM_INFO astBindModuVarList[IMVS_MAX_MODULE_PARAM_NUM]; // 变量绑定参数信息
	unsigned int       nReserved[4];                     // 保留字段
} IMVS_UNBIND_MODULE_PARAM_INFO_LIST;
/**************************** V3.4.0 新增 ***************************/
// 加载结束流程更新名称信息结构
typedef struct IMVS_UPDATE_PROCESS_NAME_INFO__
{
	unsigned int nProcessID;       // 流程ID
	char         strProcessName[IMVS_MAX_PROCESS_NAME_LENGTH];       // 流程名称
} IMVS_UPDATE_PROCESS_NAME_INFO;

// 加载结束流程更新名称信息列表结构
typedef struct IMVS_UPDATE_PROCESS_NAME_INFO_LIST__
{
	int nNum;                     // 流程数量
	IMVS_UPDATE_PROCESS_NAME_INFO astProcNameInfoList[IMVS_MAX_PROCESS_NUM]; // 流程更新名称信息列表
} IMVS_UPDATE_PROCESS_NAME_INFO_LIST;

// 加载结束模块更新名称信息结构
typedef struct IMVS_UPDATE_MODULE_NAME_INFO__
{
	unsigned int nModuleID;       // 模块ID
	char         strModuleName[IMVS_MAX_MODULE_NAME_LENGTH];        // 模块名称
} IMVS_UPDATE_MODULE_NAME_INFO;

// 加载结束模块更新名称信息列表结构
typedef struct IMVS_UPDATE_MODULE_NAME_INFO_LIST__
{
	int nNum;                     // 模块数量
	IMVS_UPDATE_MODULE_NAME_INFO astModuleNameInfoList[IMVS_MAX_MODULE_NUM]; // 模块更新名称信息列表
} IMVS_UPDATE_MODULE_NAME_INFO_LIST;

// 导出流程开始
typedef struct IMVS_EXPORT_PROCESS_BEGIN_INFO__
{
	unsigned int    nProcessId;   // 导出流程ID
	unsigned int    nClientType;  // 客户端类型
	unsigned int    nReserved[4]; // 保留字段
} IMVS_EXPORT_PROCESS_BEGIN_INFO;

// 导出流程结束信息
typedef struct IMVS_EXPORT_PROCESS_END_INFO__
{
	unsigned int    nProcessId;                         // 流程ID
	unsigned int    nClientType;                        // 客户端类型
	char            strProcPath[IMVS_MAX_PATH_UTF8_LENGTH]; // 流程文件路径
	int             nErrorCode;                         // 错误码
	unsigned int    nReserved[4];                       // 保留字段
} IMVS_EXPORT_PROCESS_END_INFO;

// 流程导出进度信息
typedef struct IMVS_EXPORT_PROCESS_PROGRESS_INFO__
{
	unsigned int    nProgress;    // 进度
	unsigned int    nReserved[4]; // 保留字段
} IMVS_EXPORT_PROCESS_PROGRESS_INFO;

// 流程导入开始信息
typedef struct IMVS_IMPORT_PROCESS_BEGIN_INFO__
{
	unsigned int    nClientType;  // 客户端类型
	unsigned int    nReserved[4]; // 保留字段
} IMVS_IMPORT_PROCESS_BEGIN_INFO;

// 流程导入结束信息
typedef struct IMVS_IMPORT_PROCESS_END_INFO__
{
	unsigned int    nIgnoreGlobalModu;                  // 是否忽略全局模块
	unsigned int    nProcessId;                         // 流程ID
	char            strProcessName[IMVS_MAX_PROCESS_NAME_LENGTH]; // 流程名称
	unsigned int    nClientType;                        // 客户端类型
	char            strProcPath[IMVS_MAX_PATH_UTF8_LENGTH]; // 流程文件路径
	int             nErrorCode;                         // 错误码
	unsigned int    nReserved[4];                       // 保留字段
} IMVS_IMPORT_PROCESS_END_INFO;

// 流程导入进度信息
typedef struct IMVS_IMPORT_PROCESS_PROGRESS_INFO__
{
	unsigned int    nProgress;    // 进度
	unsigned int    nReserved[4]; // 保留字段
} IMVS_IMPORT_PROCESS_PROGRESS_INFO;

// 流程导入界面文件数据
typedef struct IMVS_PROCESS_IMPORT_INTERFACE_FILE_INFO__
{
	char *          pData;
	unsigned int    nDataLen;
	unsigned int    nReserved[4];
} IMVS_PROCESS_IMPORT_INTERFACE_FILE_INFO;

// 导入流程新模块ID信息
typedef struct IMVS_IMPORT_PROCESS_MODULE_ID_INFO__
{
	unsigned int    nOldId;              // 原ID
	unsigned int    nNewId;              // 新ID
	char strNewName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // 新名称
} IMVS_IMPORT_PROCESS_MODULE_ID_INFO;

// 导入流程新模块ID信息列表
typedef struct IMVS_IMPORT_PROCESS_MODULE_ID_INFO_LIST__
{
	int nProcessNum;                    // 流程数量
	int nModuleNum;                     // 模块数量
	IMVS_IMPORT_PROCESS_MODULE_ID_INFO astProcessIdInfoList[IMVS_MAX_PROCESS_NUM]; // 流程ID信息列表
	IMVS_IMPORT_PROCESS_MODULE_ID_INFO astModuleIdInfoList[IMVS_MAX_MODULE_NUM];   // 模块ID信息列表
	unsigned int    nReserved[4]; // 保留字段
} IMVS_IMPORT_PROCESS_MODULE_ID_INFO_LIST;

// 界面接管时回调流程界面数据
typedef struct IMVS_TAKEOVER_PRC_INTERFACE_DATA_INFO__
{
	char *          pData;             // 界面数据
	unsigned int    nDataLen;          // 界面数据长度
	unsigned int    nReserved[4];
} IMVS_TAKEOVER_PRC_INTERFACE_DATA_INFO;

// 界面接管时回调方案界面数据
typedef struct IMVS_TAKEOVER_SOL_INTERFACE_DATA_INFO__
{
	char *          pData;             // 界面数据
	unsigned int    nDataLen;          // 界面数据长度
	unsigned int    nReserved[4];
} IMVS_TAKEOVER_SOL_INTERFACE_DATA_INFO;

// 导入流程忽略全局变量状态信息
typedef struct IMVS_IMPORT_PROCESS_IGNOREGLOBALVAR_INFO__
{
	unsigned int    nStatus;       // 状态值
	unsigned int    nReserved[4];  // 保留字段
} IMVS_IMPORT_PROCESS_IGNOREGLOBALVAR_INFO;

// 界面参数数据信息
typedef struct IMVS_UI_OBJECT_PARAM_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH]; // 参数名称
	char *          pData;             // 界面参数数据
	unsigned int    nDataLen;          // 界面参数数据长度
} IMVS_UI_OBJECT_PARAM_INFO;

// 界面参数数据信息列表
typedef struct IMVS_UI_OBJECT_PARAM_INFO_LIST__
{
	int             nParamNum;         // 参数数量
	IMVS_UI_OBJECT_PARAM_INFO * pstUIObjParamInfo; // 参数数据
	unsigned int    nReserved[4];      // 保留字段
} IMVS_UI_OBJECT_PARAM_INFO_LIST;

// 流程界面参数数据信息
typedef struct IMVS_PROC_UI_OBJECT_PARAM_INFO__
{
	int             nObjectId;         // 对象Id
	IMVS_UI_OBJECT_PARAM_INFO_LIST stUIObjParamInfoList; // 参数数据列表
} IMVS_PROC_UI_OBJECT_PARAM_INFO;

// 流程界面参数数据信息列表
typedef struct IMVS_PROC_UI_OBJECT_PARAM_INFO_LIST__
{
	int             nObjectNum;         // 对象数量
	IMVS_PROC_UI_OBJECT_PARAM_INFO * pstProcUIObjParamInfo; // 流程参数数据
	unsigned int    nReserved[4];      // 保留字段
} IMVS_PROC_UI_OBJECT_PARAM_INFO_LIST;

// 第一层级模块树信息列表
typedef struct IMVS_NODE_TREE_INFO__
{
    int nChildNodeNum;               // 子节点数量
    IMVS_MODULE_INFO astChildNodeInfo[IMVS_MAX_MODULE_NUM]; // 子节点信息列表
} IMVS_NODE_TREE_INFO;

// 模块连接信息结构
typedef struct IMVS_MODULE_CONNECT_INFO__
{
	int nModuleId;                  // 模块ID
	int nNextModuNum;               // 后继模块数量
	unsigned int anNextModuleId[IMVS_MAX_MODULE_NUM]; // 后继模块ID
	int nPreModuNum;                // 前接模块数量
	unsigned int anPreModuleId[IMVS_MAX_MODULE_NUM]; // 前接模块ID
} IMVS_MODULE_CONNECT_INFO;

// 模块连接信息列表
typedef struct IMVS_MODULE_CONNECT_INFO_LIST__
{
	int nNum;               // 模块连接数量
	IMVS_MODULE_CONNECT_INFO * pstModuleConnectInfo; // 模块连接信息
	unsigned int    nReserved[4];      // 保留字段
} IMVS_MODULE_CONNECT_INFO_LIST;

// 订阅信息列表
typedef struct IMVS_MODULE_SUBSCRIBE_INFO_LIST__
{
	int                   nNum;             // 订阅信息个数
	IMVS_SUBSCRIBE_INFO * pstSubscribeInfo; // 订阅信息列表
	unsigned int          nReserved[4];     // 保留字段
} IMVS_MODULE_SUBSCRIBE_INFO_LIST;

// 上报指定模块结果模块列表
typedef struct IMVS_REPORT_MODULE_RES_INFO_LIST__
{
	int                   nNum;             // 上报模块个数
	unsigned int          anReportModuIds[IMVS_MAX_MODULE_NUM]; // 上报模块结果
	unsigned int          nReserved[4];     // 保留字段
} IMVS_REPORT_MODULE_RES_INFO_LIST;

// 查询模块历史结果信息结构
typedef struct IMVS_QUERY_MODULE_RES_INFO_LIST__
{
	int                   nNum;             // 上报模块个数
	IMVS_MODULE_RESULT_INFO_LIST_EX * pastModuResultList; // 模块历史结果数据
	int                   nTotalNum;         // 模块结果总数量
	unsigned int          nReserved[4];     // 保留字段
} IMVS_QUERY_MODULE_RES_INFO_LIST;

// 导出模块数据信息结构
typedef struct IMVS_EXPORT_MODULE_DATA_INFO__
{
	char *               pData;        // 数据指针
	unsigned int         nDataLen;     // 数据长度
	unsigned int         nReserved[4]; // 保留字段
} IMVS_EXPORT_MODULE_DATA_INFO;

// 导入模块数据信息结构
typedef struct IMVS_IMPORT_MODULE_DATA_INFO__
{
	unsigned int         nParentNodeID; // 父节点ID
	unsigned int         nModuleID;     // 模块ID
	char                 strModuDisplayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // 模块显示名称
	unsigned int         nWaitTime;     // 超时时间
	char *               pData;         // 数据指针
	unsigned int         nDataLen;      // 数据长度
	unsigned int         nReserved[4];  // 保留字段
} IMVS_IMPORT_MODULE_DATA_INFO;

// 同步添加模块输入信息结构
typedef struct IMVS_SYNC_ADD_ONE_MODULE_INFO__
{
	unsigned int nParentNodeType; // 父节点类型 流程：1，Group：20
	unsigned int nParentNodeID;   // 父节点ID
	char         strModuleDllName[IMVS_MAX_MODULE_NAME_LENGTH];       // 模块dll名称
	char         strDisplayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // 界面显示名称
	unsigned int nWaitTime;       // 超时时间
	unsigned int nReserved[4];  // 保留字段
} IMVS_SYNC_ADD_ONE_MODULE_INFO;

// 整型输入数据
typedef struct IMVS_INPUT_INT_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // 参数名称
	int             nValueNum;              // 数量
	int *           pIntValue;              // 整型数据
} IMVS_INPUT_INT_INFO;

// 浮点型输入数据
typedef struct IMVS_INPUT_FLOAT_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // 参数名称
	int             nValueNum;              // 数量
	float *         pFloatValue;            // 浮点型数据
} IMVS_INPUT_FLOAT_INFO;

// 浮点型输入数据
typedef struct IMVS_INPUT_DOUBLE_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // 参数名称
	int             nValueNum;              // 数量
	double *         pDoubleValue;            // 浮点型数据
} IMVS_INPUT_DOUBLE_INFO;

// 字符串型数据信息结构
typedef struct IMVS_STRING_DATA_INFO__
{
	char strValue[IMVS_DEFINE_MODULE_RES_STRING_LENGTH];    // 字符串数据
} IMVS_STRING_DATA_INFO;

// 字符串型输入数据
typedef struct IMVS_INPUT_STRING_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // 参数名称
	int             nValueNum;              // 数量
	IMVS_STRING_DATA_INFO * pstStringValue; // 字符串型数据
} IMVS_INPUT_STRING_INFO;

// 整型输入数据列表
typedef struct IMVS_INPUT_INT_LIST_INFO__
{
	int nNum;    // 整型参数数量
	IMVS_INPUT_INT_INFO * pstIntValueList;    // 整型参数列表
} IMVS_INPUT_INT_LIST_INFO;

// 浮点型输入数据列表
typedef struct IMVS_INPUT_FLOAT_LIST_INFO__
{
	int nNum;    // 浮点型参数数量
	IMVS_INPUT_FLOAT_INFO * pstFloatValueList;    // 浮点型参数列表
} IMVS_INPUT_FLOAT_LIST_INFO;

// 浮点型输入数据列表
typedef struct IMVS_INPUT_DOUBLE_LIST_INFO__
{
	int nNum;    // 浮点型参数数量
	IMVS_INPUT_DOUBLE_INFO * pstDoubleValueList;    // 浮点型参数列表
} IMVS_INPUT_DOUBLE_LIST_INFO;

// 字符串型输入数据列表
typedef struct IMVS_INPUT_STRING_LIST_INFO__
{
	int nNum;    // 字符串型参数数量
	IMVS_INPUT_STRING_INFO * pstStringValueList;    // 字符串型参数列表
} IMVS_INPUT_STRING_LIST_INFO;

// 图像、点集、二进制型输入数据信息
typedef struct IMVS_MODULE_INPUT_DATA_INFO__
{
	char            strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // 参数名称
	unsigned int    nDataLen;               // 数据长度
	char *          pData;                  // 数据
} IMVS_MODULE_INPUT_DATA_INFO;

// 模块ID列表
typedef struct IMVS_MODULE_ID_LIST__
{
	int nNum;    // 导出模块数量
	unsigned int anModuleId[IMVS_MAX_MODULE_NUM]; // 导出模块ID
	unsigned int nReserved[4];  // 保留字段
} IMVS_MODULE_ID_LIST;

//  流程ID列表
typedef struct IMVS_PROCESS_ID_LIST__
{
	int nNum;    // 导出流程数量
	unsigned int anProcessId[IMVS_MAX_PROCESS_NUM]; // 导出流程ID
	unsigned int nReserved[4];  // 保留字段
} IMVS_PROCESS_ID_LIST;

// 导入多个模块数据信息结构
typedef struct IMVS_IMPORT_MODULE_LIST_DATA_INFO__
{
	unsigned int         nParentId;     // 父节点ID
	IMVS_MODULE_ID_LIST  stModuIdList;  // 模块ID列表
	unsigned int         nWaitTime;     // 超时时间
	char *               pData;         // 数据指针
	unsigned int         nDataLen;      // 数据长度
	unsigned int         nReserved[4];  // 保留字段
} IMVS_IMPORT_MODULE_LIST_DATA_INFO;

// 模块节点单元信息
typedef struct IMVS_NODE_UNIT_INFO__
{
	unsigned int nNodeId;    // 节点ID
	char strDisplayName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // 显示名称
} IMVS_NODE_UNIT_INFO;

// 导入模块节点信息
typedef struct IMVS_IMPORT_NODE_INFO__
{
	IMVS_NODE_UNIT_INFO stParentNodeInfo; // 父节点信息
	int nSonModuNum;    // 子节点数量
	IMVS_NODE_UNIT_INFO astSonNodeInfo[IMVS_MAX_MODULE_NUM]; // 子节点信息
} IMVS_IMPORT_NODE_INFO;

// 导入模块节点信息列表
typedef struct IMVS_IMPORT_NODE_LIST__
{
	int nNum;    // 节点信息数量
	IMVS_IMPORT_NODE_INFO astImportNodeInfo[IMVS_MAX_MODULE_NUM]; // 节点信息列表
} IMVS_IMPORT_NODE_LIST;

// 对象界面参数数据信息
typedef struct IMVS_UIPARAM_VALUE__
{
	char strParamName[IMVS_MAX_PARAM_NAME_LENGTH]; // 参数名称
	char * pData;    // 界面数据
	size_t nLen;     // 界面数据长度
} IMVS_UIPARAM_VALUE;

// 对象界面参数数据信息
typedef struct IMVS_UIPARAM_INFO__
{
	int nObjectId; // 对象ID
	int nValNum;   // 结果数量
	IMVS_UIPARAM_VALUE * pastParamVal; // 查询结果
} IMVS_UIPARAM_INFO;

// 对象界面参数模糊查询信息列表
typedef struct IMVS_UIPARAM_INFO_LIST__
{
	int nNum;    // 数量
	IMVS_UIPARAM_INFO astUiParamInfo[IMVS_MAX_MODULE_NUM]; // 模糊查询信息列表
	unsigned int nReserved[4];  // 保留字段
} IMVS_UIPARAM_INFO_LIST;

// 第三方软件信息
typedef struct IMVS_THIRD_SOFTWARE_INFO__
{
	unsigned int nPid; // 进程ID
	char strProcName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // 进程名称
} IMVS_THIRD_SOFTWARE_INFO;

// 第三方软件信息列表
typedef struct IMVS_THIRD_SOFTWARE_INFO_LIST__
{
	int nNum; // 进程数量
	IMVS_THIRD_SOFTWARE_INFO astSoftwareInfo[IMVS_MAX_THIRD_SOFTWARE_NUM]; // 软件信息列表
} IMVS_THIRD_SOFTWARE_INFO_LIST;

// 关联类型，1：全局相机，2：光源设备，3：前置通信设备，4：后置通信设备，5：局部触发。
typedef enum IMVS_RELATED_TYPE__
{
	GLOBAL_TYPE_INVALID = 0,
	GLOBAL_TYPE_CAMERA = 1,
	GLOBAL_TYPE_LIGHT  = 2,
	GLOBAL_TYPE_PRE_COMMUNICATION = 3,
	GLOBAL_TYPE_AFTER_COMMUNICATION = 4,
	GLOBAL_TYPE_AFTER_TRIGER = 5,
} IMVS_RELATED_TYPE;

// 与流程关联的全局模块ID列表
typedef struct IMVS_RELATED_GLOBAL_MODU_ID_LIST__
{
	IMVS_RELATED_TYPE eRelatedType; // 关联类型
	int nNum;    // 全局模块数量
	unsigned int anModuleId[IMVS_MAX_MODULE_NUM]; // 全局模块ID
	unsigned int nReserved[4];  // 保留字段
} IMVS_RELATED_GLOBAL_MODU_ID_LIST;

// 与流程关联的全局模块ID列表
typedef struct IMVS_RELATED_GLOBAL_MODU_INFO_LIST__
{
	int nNum;                   // 列表数量
	IMVS_RELATED_GLOBAL_MODU_ID_LIST astGlobalModuInfo[IMVS_MAX_GLOBAL_TYPE_NUM]; // 全局模块ID
	unsigned int nReserved[4];  // 保留字段
} IMVS_RELATED_GLOBAL_MODU_INFO_LIST;


// 模块禁用回调状态信息
typedef struct IMVS_MODULE_STATE_INFO__
{
	unsigned int nModuleId;  // 模块ID
	unsigned int nEnable;    // 使能状态
	unsigned int nCallback;  // 回调状态
} IMVS_MODULE_STATE_INFO;

// 模块禁用回调状态列表
typedef struct IMVS_MODULE_STATE_LIST__
{
	int nNum;    // 数量
	IMVS_MODULE_STATE_INFO astModuState[IMVS_MAX_MODULE_NUM]; // 模块状态列表
	unsigned int nReserved[4];  // 保留字段
} IMVS_MODULE_STATE_LIST;

/** @enum IMVS_VALUE_TYPE
 *  @brief 值类型
 */
typedef enum IMVS_VALUE_TYPE__
{
	VALUE_TYPE_INT    = 1, // 整型
	VALUE_TYPE_FLOAT  = 2, // 浮点型
	VALUE_TYPE_STRING = 3, // 字符串型
	VALUE_TYPE_IMAGE  = 4, // 图像型
	VALUE_TYPE_POINTSET = 5, // 点集型
	VALUE_TYPE_BYTE   = 6, // 数据型
} IMVS_VALUE_TYPE;

/** @enum IMVS_SILENT_EXECUTE_TYPE
*  @brief 静默执行类型
*/
typedef enum IMVS_SILENT_EXECUTE_TYPE__
{
    SILENT_EXECUTE_TYPE_DLANDSHELL = 0, // 深度学习和脚本模块
    SILENT_EXECUTE_TYPE_ALL = 1,        // 全体模块
    SILENT_EXECUTE_TYPE_DL = 2,         // 深度学习模块
    SILENT_EXECUTE_TYPE_SHELL = 3,      // 脚本模块
} IMVS_SILENT_EXECUTE_TYPE;

/** @enum IMVS_COMBINATION_TYPE
 *  @brief 组合类型
 */
typedef enum IMVS_COMBINATION_STYLE__
{
	COMBINATION_TYPE_COMBINATION = 0, // 组合
	COMBINATION_TYPE_IMAGE       = 1, // 图像	
	COMBINATION_TYPE_POINT       = 2, // 点
	COMBINATION_TYPE_ROIBOX      = 3, // ROI
	COMBINATION_TYPE_ROIANNULUS  = 4, // 圆弧ROI
	COMBINATION_TYPE_FIXTURE     = 5, // 修正信息
	COMBINATION_TYPE_CLASSINFO   = 6, // 类别信息
	COMBINATION_TYPE_LINE        = 7, // 直线
	COMBINATION_TYPE_CIRCLE      = 8, // 圆
	COMBINATION_TYPE_ACQUIMAGE   = 9, // 采集图像（多图融合）
	COMBINATION_TYPE_PIXELIMAGE  = 10, // 
	COMBINATION_TYPE_ANNULUS     = 11, // 圆弧
	COMBINATION_TYPE_CONTOURPOINT = 12, // 轮廓点
	COMBINATION_TYPE_RECT        = 13, // 矩形
	COMBINATION_TYPE_DEBUG       = 14, // DEBUG
} IMVS_COMBINATION_STYLE;

// 基本数据结构
typedef struct IMVS_BASE_DATA_VALUE_
{
	char *          pData;  // 实际数据
	unsigned int    nLen;   // 实际数据长度	
} IMVS_BASE_DATA_VALUE;

/*
//组合类型信息
typedef struct IMVS_COMBINATION_IO_INFO__
{
	char strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // 参数名称
	IMVS_VALUE_INFO stValInfo;                        // 数据信息
	IMVS_BASE_DATA_VALUE  stExtraData;              // 附加数据
} IMVS_COMBINATION_IO_INFO;

// 组合类型信息列表
typedef struct IMVS_COMBINATION_IO_INFO_LIST__
{
	int nNum;                                         // 组合信息数量
	IMVS_COMBINATION_IO_INFO stCombinationInfo[IMVS_MAX_MODULE_INPUT_IO_NUM]; // 组合信息列表
} IMVS_COMBINATION_IO_INFO_LIST;

// 模块IO输入信息
typedef struct IMVS_MODULE_IO_INNER_INFO__
{
	int  nType;                                       // 数据类型（1: 值类型, 2: 组合类型）
	char strParamName[IMVS_MAX_PARAM_NAME_LENGTH];    // 参数名称
	char strStyle[IMVS_DEFAULT_STYLE_NUM];            // 附加数据
	char strAccessMode[IMVS_DEFAULT_BYTE_NUM];        // 附加数据
	IMVS_VALUE_INFO stValInfo;                        // 数据信息
	IMVS_COMBINATION_STYLE eCombinationType;          // 组合类型
	IMVS_COMBINATION_IO_INFO_LIST stCombinaInfoList;  // 组合信息列表
	//IMVS_BASE_DATA_VALUE stExtraData;               // 附加协议数据
} IMVS_MODULE_IO_INNER_INFO;

typedef struct IMVS_MODULE_IO_INNER_INFO_LIST__
{
	int nNum;                                         // 组合信息数量
	IMVS_MODULE_IO_INNER_INFO stCombinationInfo[IMVS_MAX_MODULE_INPUT_IO_NUM]; // 组合信息列表
} IMVS_MODULE_IO_INNER_INFO_LIST;*/

// 模块IO信息
typedef struct IMVS_VALUE_INFO__
{
	IMVS_VALUE_TYPE eValType;          // 值类型
	int   nIntVal;                     // 整型值
	float fFloatVal;                   // 浮点型值
	IMVS_BASE_DATA_VALUE stStringInfo; // 字符串
	IMVS_BASE_DATA_VALUE stImgInfo;    // 图像数据	

	//bool bIsForce;                     // 附加数据
	//bool bIsShow;                      // 附加数据
	//char strAccessMode[IMVS_DEFAULT_BYTE_NUM]; // 附加数据
} IMVS_VALUE_INFO;

/** @enum IMVS_COMBINATION_TYPE
*  @brief IO信息类型
*/
typedef enum IMVS_DATA_TYPE__
{
	DATA_TYPE_MIN = 0,                  // 枚举最小值(初始值)
	DATA_TYPE_FILTER = 1,               // 值类型
	DATA_TYPE_COMBINATION = 2,          // 组合类型
	DATA_TYPE_MAX = 3                   // 枚举最大值
} IMVS_DATA_TYPE;

/** @enum IMVS_COMBINATION_TYPE
*  @brief IO输入输出类型
*/
typedef enum IMVS_IO_CLASS_TYPE__
{
	IO_CLASS_MIN = 0,                  // 枚举最小值(初始值)
	IO_CLASS_INPUT = 1,                // 输入类型
	IO_CLASS_OUTPUT = 2,               // 输出类型
	IO_CLASS_MAX = 3                   // 枚举最大值
} IMVS_IO_CLASS_TYPE;

typedef struct IMVS_MODULE_IO_INFO__
{
	int  nDataType;                                     // 数据类型（1: 值类型, 2:IMVS_MODULE_IO_INFO）
	char szParamName[IMVS_MAX_PARAM_NAME_LENGTH];       // 参数名称
	char szParamType[IMVS_MAX_PARAM_NAME_LENGTH];       // 参数类型名
	int nNum;                                           // pstCombInfo指针实际个数
	IMVS_MODULE_IO_INFO__* pstCombInfo;                 //Combination中的每一条数据，指向值类型或者结构体本身  32
	char szExtraData[IMVS_DEFAULT_DATA_NUM];            //附加数据

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

// 模块IO输入信息列表
typedef struct IMVS_MODULE_IO_INFO_LIST__
{
	int nIoClass;                                        // 参数类型（1: 输入, 2: 输出）
	int nNum;                                            // 数量
	IMVS_MODULE_IO_INFO *pstModuIoInfo;                  // 模块IO信息
	unsigned int nReserved[4];                           // 保留字段

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

// 流程与方案文件版本信息
typedef struct IMVS_FILE_VERSION_INFO_
{
	char            strCurrentVesionInfo[IMVS_SOLUTION_VERSION_LENGTH];
	unsigned int    nReserved[4];
} IMVS_FILE_VERSION_INFO;

// 方案中全局对象/流程对象信息
typedef struct IMVS_GLOBAL_PROCESS_UI_OBJECT_INFO__
{
	int             nStatus;      // 状态
	unsigned int    nReserved[4]; // 保留字段
} IMVS_GLOBAL_PROCESS_UI_OBJECT_INFO;

// 导入流程时通知界面获取数据信息
typedef struct IMVS_IMPORT_PROCESS_GET_UIDATA_INFO__
{
	unsigned int    nProcessId;                         // 新流程ID
	char            strProcessName[IMVS_MAX_PROCESS_NAME_LENGTH]; // 新流程名称
	unsigned int    nReserved[4]; // 保留字段
} IMVS_IMPORT_PROCESS_GET_UIDATA_INFO;

// 导入Group时通知界面获取数据信息
typedef struct IMVS_IMPORT_GROUP_GET_UIDATA_INFO__
{
	unsigned int    nGroupId;                        // 新模块ID
	char            strGroupName[IMVS_MAX_MODULE_DISPLAY_NAME_LENGTH]; // 模块新名称
	unsigned int    nReserved[4]; // 保留字段
} IMVS_IMPORT_GROUP_GET_UIDATA_INFO;

// 模块状态上报信息
typedef struct IMVS_REPORT_MODULE_STATUS_INFO__
{
	unsigned int    nModuleID;              // 模块ID
	unsigned int    nModuProcessStatus;     // 模块执行状态 1成功; 2模块异常；3前序分支模块异常；4 前序模块异常
	unsigned int    nModuleStatus;          // 模块结果状态 1成功; 0模块结果异常
	float           fModuleTime;            // 模块时间
	float           fAlgorithmTime;         // 算法时间
	float           fProcessTime;           // 流程时间
	int             bIsSelfRun;             // 是否自执行(0:流程执行 1:自执行)
} IMVS_REPORT_MODULE_STATUS_INFO;

// 模块状态上报信息列表
typedef struct IMVS_REPORT_MODULE_STATUS_INFO_LIST__
{
	int nNum;    // 模块数量
	unsigned int                     nProcessId;            // 流程ID
	IMVS_REPORT_MODULE_STATUS_INFO * pstModuleStatuInfo;    // 模块状态信息列表
	unsigned int    nReserved[4]; // 保留字段
} IMVS_REPORT_MODULE_STATUS_INFO_LIST;

// 上报数据队列信息
typedef struct IMVS_REPORT_DATAQUEUE_INFO__
{
    int             nModuleId;    // 模块ID
    char *          pData;        // 数据
    size_t          nLen;         // 数据长度
    unsigned int    nReserved[4]; // 保留字段
} IMVS_REPORT_DATAQUEUE_INFO;

// 关闭方案状态信息
typedef struct IMVS_CLOSE_SOLUTION_STATUS_INFO__
{
	int             nClientType;  // 客户端类型
	unsigned int    nReserved[4]; // 保留字段
} IMVS_CLOSE_SOLUTION_STATUS_INFO;

// 导出多流程开始
typedef struct IMVS_EXPORT_MULTIPROCESS_BEGIN_INFO__
{
	IMVS_PROCESS_ID_LIST anProcessId; // 导出流程ID
	unsigned int    nClientType;      // 客户端类型
	unsigned int    nReserved[4];     // 保留字段
} IMVS_EXPORT_MULTIPROCESS_BEGIN_INFO;

// 导出多流程结束信息
typedef struct IMVS_EXPORT_MULTIPROCESS_END_INFO__
{
	IMVS_PROCESS_ID_LIST anProcessId;                   // 流程ID
	unsigned int    nClientType;                        // 客户端类型
	char            strProcPath[IMVS_MAX_PATH_UTF8_LENGTH]; // 流程文件路径
	int             nErrorCode;                         // 错误码
	unsigned int    nReserved[4];                       // 保留字段
} IMVS_EXPORT_MULTIPROCESS_END_INFO;

// 多流程导出进度信息
typedef struct IMVS_EXPORT_MULTIPROCESS_PROGRESS_INFO__
{
	unsigned int    nProgress;    // 进度
	unsigned int    nReserved[4]; // 保留字段
} IMVS_EXPORT_MULTIPROCESS_PROGRESS_INFO;

// 多流程导入开始信息
typedef struct IMVS_IMPORT_MULTIPROCESS_BEGIN_INFO__
{
	unsigned int    nClientType;  // 客户端类型
	unsigned int    nReserved[4]; // 保留字段
} IMVS_IMPORT_MULTIPROCESS_BEGIN_INFO;

// 多流程基础信息
typedef struct IMVS_PROCESS_BASE_INFO__
{
	unsigned int    nProcessId;                         // 流程ID
	char            strProcessName[IMVS_MAX_PROCESS_NAME_LENGTH]; // 流程名称
} IMVS_PROCESS_BASE_INFO;

// 多流程基础信息列表
typedef struct IMVS_PROCESS_BASE_INFO_LIST__
{
	int nNum;    // 流程数量
	IMVS_PROCESS_BASE_INFO stProcBaseInfoList[IMVS_MAX_PROCESS_NUM]; // 流程信息列表	 
} IMVS_PROCESS_BASE_INFO_LIST;

// 多流程导入结束信息
typedef struct IMVS_IMPORT_MULTIPROCESS_END_INFO__
{
	unsigned int    nIgnoreGlobalModu;                  // 是否忽略全局模块	
	unsigned int    nClientType;                        // 客户端类型
	char            strProcPath[IMVS_MAX_PATH_UTF8_LENGTH]; // 流程文件路径
	int             nErrorCode;                         // 错误码
	IMVS_PROCESS_BASE_INFO_LIST stProcBaseInfo;         // 流程基础信息列表
	unsigned int    nReserved[4];                       // 保留字段
} IMVS_IMPORT_MULTIPROCESS_END_INFO;

// 多流程导入进度信息
typedef struct IMVS_IMPORT_MULTIPROCESS_PROGRESS_INFO__
{
	unsigned int    nProgress;    // 进度
	unsigned int    nReserved[4]; // 保留字段
} IMVS_IMPORT_MULTIPROCESS_PROGRESS_INFO;

// 导入多流程时通知界面获取数据信息
typedef struct IMVS_IMPORT_MULTIPROCESS_UIDATA_INFO__
{
	IMVS_PROCESS_BASE_INFO_LIST stUiData;
	unsigned int    nReserved[4]; // 保留字段
} IMVS_IMPORT_MULTIPROCESS_UIDATA_INFO;

// 文件信息结构
typedef struct FileInfo_
{
	char* tFileMTime;
	double dFileSize;
} FileInfo;

typedef enum report_result_type__
{
    REPORT_RESULT_TYPE_INVALID = 0,//无效
    REPORT_RESULT_TYPE_NONE = 1,//所有模块均不上报
    REPORT_RESULT_TYPE_ALL = 2,//所有模块都上报
    REPORT_RESULT_TYPE_PART = 3//个别模块上报
} E_REPORT_RESULT_TYPE;

/** @enum IMVS_RELEASE_MEMORY_TYPE
*  @brief 内存释放类型
*/
typedef enum IMVS_RELEASE_MEMORY_TYPE__
{
    RELEASE_MEMORY_BASE_VOID = 0,                          // 内存类型
    RELEASE_MEMORY_BASE_POINTER = 1,                       // 指针类型
    RELEASE_MEMORY_BASE_ARRAY = 2,                         // 数组类型
    RELEASE_MEMORY_STRUCT_UI_OBJECT_PARAM_LIST = 3,        // 界面参数数据
    RELEASE_MEMORY_STRUCT_UI_PARAM_INFO_LIST = 4,          // 界面参数数据
    RELEASE_MEMORY_STRUCT_MODU_CONNECT_INFO_LIST = 5,      // 界面连线数据
    RELEASE_MEMORY_STRUCT_MODU_SUBSCRIBE_INFO_LIST = 6,    // 界面订阅数据
    RELEASE_MEMORY_STRUCT_MODU_STATUS_INFO_LIST = 7,       // 模块执行状态
    RELEASE_MEMORY_STRUCT_MODU_EXPORT_DATA_INFO = 8,       // 模块导出数据
    RELEASE_MEMORY_STRUCT_MODU_HISTORY_RES_INFO_LIST = 9,  // 模块历史结果
}IMVS_RELEASE_MEMORY_TYPE;

/** @enum IMVS_MEMORY_OWNER_TYPE
*  @brief 内存所属类型
*/
typedef enum IMVS_MEMORY_OWNER_TYPE__
{
    MEMORY_OWNER_TYPE_INTERNAL = 0,                          // 内部申请
    MEMORY_OWNER_TYPE_EXTERNAL = 1,                       // 外部申请
}IMVS_MEMORY_OWNER_TYPE;

//fuzzy match
typedef enum IMVS_FUZZY_MATCH__
{
	FUZZY_MATCH_NO = 0,        //否
	FUZZY_MATCH_YES = 1        //是
}IMVS_FUZZY_MATCH;

/** 新增接口：@enum IMVS_IO_BE_SUBSCRIBED_TYPE
*  @brief IO被订阅类型
*/
typedef enum IMVS_IO_BE_SUBSCRIBED_TYPE__
{
    IO_BE_SUBSCRIBED_TYPE_GENARAL = 0,           // 普通订阅
    IO_BE_SUBSCRIBED_TYPE_RUNPARAMS = 1,         // 运行参数订阅
}IMVS_IO_BE_SUBSCRIBED_TYPE;

namespace IMVS
{
    // 算法版本信息
    struct AlgorithmVersionInfo
    {
        char Normal[IMVS_ALGORITHM_VERSION_LENGTH];         // 2d算子
        char Deeplearning[IMVS_ALGORITHM_VERSION_LENGTH];   // 深度算子
    };

    // 与模块的REAL_MODE_IAMGE_TRANS_INFO_结构体保持一致
    struct RealModeImageTransInfo
    {
        int nModuleId;
        int nWidth;
        int nHeight;
        unsigned long long nPixelFormat;
        int nDataLen;//真实数据大小
        int nFrameNum;
        int nLostFrameCount;
        int nLostPacketCount;
        int nReserved[4];
    };

    // 代理透传的相机取流数据
    struct RealModeImageTransInfoWithData
    {
        RealModeImageTransInfo ImageInfo;   // 图片信息
        const char* ImageData;              // 图片数据，长度由ImageInfo.nDataLen定义
    };

    namespace FTP
    {
        // const int MAX_USER_FILE_NUM = 100;
        const int MAX_USER_FILE_INFO_NUM = 255;

        // 与FTPClientDefine.h中的定义保持一致
        struct RemoteFileInfo
        {
            char Permission[MAX_USER_FILE_INFO_NUM];    //文件属性
            int  HardLink;                              //硬链接
            char User[MAX_USER_FILE_INFO_NUM];          //所有者
            char Group[MAX_USER_FILE_INFO_NUM];         //所属用户组
            int  Size;                                  //文件大小
            char Time[MAX_USER_FILE_INFO_NUM];          //修改时间
            char Name[MAX_USER_FILE_INFO_NUM];          //文件名
        };

        struct RemoteFileListInfo
        {
            RemoteFileInfo* pFileInfos;
            int Num;
        };
    }
}

#endif // IMVS_6000_SDK4SERVER_DEFINE_H__
