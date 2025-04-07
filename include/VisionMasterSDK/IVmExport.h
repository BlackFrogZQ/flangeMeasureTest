#ifndef _IVM_EXPORT_H__
#define _IVM_EXPORT_H__

#pragma warning(disable:4819)
/* note: Interface export definition of the namespace VisionMasterSDK */

namespace VisionMasterSDK
{
    #ifdef WIN32
        #if defined(IMVS6000PLATFORMSDK_EXPORTS)
            #define IMVS_6000_PLATFORMSDK_API __declspec(dllexport)
        #else
            #define IMVS_6000_PLATFORMSDK_API __declspec(dllimport)
        #endif
    #else
        #ifndef __stdcall
            #define __stdcall
        #endif
        #ifndef IMVS_6000_PLATFORMSDK_API
            #define IMVS_6000_PLATFORMSDK_API
        #endif
    #endif

    #ifndef IN
        #define IN
    #endif

    #ifndef OUT
        #define OUT
    #endif

    #ifndef INOUT
        #define INOUT
    #endif
}

//////////////////////////////////// 公共定义 //////////////////////////////////////
const static unsigned int MAX_PROCESS_NAME_LENGTH = 64;         // CH: 流程名称最大长度 | EN: Maximum length of process name
const static unsigned int MAX_PROCESS_NUM         = 1000;       // CH: 最大流程个数 | EN: Maximum number of processes
const static unsigned int MAX_MODULE_DISPLAY_NAME_LENGTH = 256; // CH: 模块显示名称最大长度 | EN: Maximum length of module display name
const static unsigned int MAX_MODULE_NAME_LENGTH  = 64;         // CH: 模块名称最大长度 | EN: Maximum length of module name
const static unsigned int MAX_MODULE_NUM          = 1040;       // CH: 最大模块个数 | EN: Maximum number of modules
const static unsigned int MAX_CORE_NUM            = 64;         // 最大CPU核心个数
const static unsigned int MAX_OBJECT_IO_NAME_LENGTH = 128;      // CH: IO名称最大长度 | EN: Maximum length of IO name
const static unsigned int MAX_OBJECT_IO_NUM = 1024;             // CH: IO最大个数 | EN: Maximum number of IO
const static unsigned int MAX_OBJECT_NUM = 1040;     // CH: 对象的最大个数 | EN: Maximum number of Objects
const static unsigned int MAX_CAMERA_SN_LEN      = 64;          // CH: 相机最大序列号长度 | EN: Maximum length of camera sn
const static unsigned int MAX_CAMERA_NAME_LEN    = 64;          // CH: 相机最大名称长度 | EN: Maximum length of camera name
const static unsigned int MAX_CAMERA_NUM         = 256;         // CH: 相机最大数量 | EN: Maximum length of camera number

// CH: VM对象类型 | EN: Objects type in VM
enum VMObjectType
{
    VMObjectType_Unknown = 0,       // 未知类型
    VMObjectType_Procedure = 1,     // 流程对象
    VMObjectType_Module = 2         // 模块对象
};

// CH: 对象信息列表结构 | EN: Objects information list structure
typedef struct ObjectList__
{
    VMObjectType        enType;                         // CH: 对象类型 | EN: Object type
    unsigned int        nNum;                           // CH: 对象个数 | EN: The number of Objects in the list
    void*               pObjects[MAX_OBJECT_NUM];       // CH: 对象信息列表 | EN: Object information
    unsigned int        nReserved[4];                   // CH: 保留字段 | EN: Reserved
} ObjectList;

// CH: 流程信息结构 | EN: Process information structure
typedef struct ProcessInfo__
{
    unsigned int nProcessID;                                    // CH: 流程ID | EN: Process ID
    char         strProcessName[MAX_PROCESS_NAME_LENGTH];       // CH: 流程名称 | EN: Process name
    unsigned int nReserved[4];                                  // CH: 保留字段 | EN: Reserved
} ProcessInfo;

// CH: 流程信息列表结构 | EN: Process information list structure
typedef struct ProcessInfoList__
{
    unsigned int         nNum;                                  // CH: 流程个数 | EN: The number of processes in the list
    ProcessInfo          astProcessInfo[MAX_PROCESS_NUM];       // CH: 流程信息列表 | EN: Process information
    unsigned int         nReserved[4];                          // CH: 保留字段 | EN: Reserved
} ProcessInfoList;

// CH: 单个相机信息结构 | EN: Camera information structure
typedef struct CameraInfo__
{
    char strCameraName[MAX_CAMERA_NAME_LEN];           // CH: 相机名称 | EN: Camera Name
    char strCameraSN[MAX_CAMERA_SN_LEN];               // CH: 相机SN | EN: Camera SN
    unsigned int nReserved[4];                         // CH: 保留字段 | EN: Reserved
} CameraInfo;

// CH: 相机信息列表结构 | EN: Camera information list structure
typedef struct CameraInfoList__
{
    unsigned int nNum;                                          // CH: 相机数量 | EN: Camera Number
    CameraInfo astCameraInfo[MAX_CAMERA_NUM];                   // CH: 相机信息 | EN: Camera Info
    unsigned int nReserved[4];                                  // CH: 保留字段 | EN: Reserved
} CameraInfoList;

// CH: 单个模块信息结构 | EN: Module information structure
typedef struct ModuInfo__
{
    unsigned int    nModuleID;                                      // CH: 模块ID | EN: Module ID
    unsigned int    nProcessID;                                     // CH: 流程ID | EN: Process ID
    char            strDisplayName[MAX_MODULE_DISPLAY_NAME_LENGTH]; // CH: 界面显示名称 | EN: Displayed module name
    char            strModuleName[MAX_MODULE_NAME_LENGTH];          // CH: 模块名称 | EN: Module name
    unsigned int    nReserved[128];                                 // CH: 保留字段 | EN: Reserved
} ModuInfo;

// CH: 模块信息列表结构 | EN: Module information list structure
typedef struct ModuleInfoList__
{
    unsigned int           nNum;                                     // CH: 模块个数 | EN: Number of modules in list
    ModuInfo               astModuleInfo[MAX_MODULE_NUM];            // CH: 模块信息列表 | EN: Information details of a module
    unsigned int           nReserved[4];                             // CH: 保留字段 | EN: Reserved
} ModuleInfoList;

// CH: Group模块信息结构 | EN: Group module information structure
typedef struct GroupModuInfo__
{
    unsigned int    nModuleID;                                      // CH: 模块ID | EN: Module ID
    char            strDisplayName[MAX_MODULE_DISPLAY_NAME_LENGTH]; // CH: 界面显示名称 | EN: Displayed module name
    char            strModuleName[MAX_MODULE_NAME_LENGTH];          // CH: 模块名称 | EN: Module name
    unsigned int    nReserved[128];                                 // CH: 保留字段 | EN: Reserved
} GroupModuInfo;

// CH: Group模块信息列表结构 | EN: Group module information list structure
typedef struct GroupModuInfoList__
{
    unsigned int           nNum;                                     // CH: 模块个数 | EN: Number of modules in list
    GroupModuInfo          astModuleInfo[MAX_MODULE_NUM];            // CH: 模块信息列表 | EN: Information details of a module
    unsigned int           nReserved[4];                             // CH: 保留字段 | EN: Reserved
} GroupModuInfoList;

// 用户自定义流程运行策略信息结构
typedef struct ProcedureRunPolicy__
{
    int          nThreadNum;       // 指定流程其执行线程数目
    char         chCpuCore[MAX_CORE_NUM]; // 指定流程运行的CPU核心 CPU核数组，0-无效，1-有效。
                                          // chCpuCore[0]表示cpu0、chCpuCore[1]表示cpu1, chCpuCore[2]表示cpu2...
    unsigned int nReserved[4];     // 保留字段
}ProcedureRunPolicy;

// CH: 模块导入数据信息结构 | EN: Module import data structure
typedef struct ModuleImportData__
{
    char *             pData;               // CH: 导入文件绝对路径 | EN: The imported file's path
    unsigned int       nReserved[4];         // CH: 保留字段 | EN: Reserved
}ModuleImportData;

// 输出算法平台信息
typedef struct OutputPlatformInfo__
{
    unsigned int  nInfoType;                                // 回调信息类型
    unsigned int  nDataSize;                                // 回调数据分配内存
    unsigned int  nDataLen;                                 // 回调数据实际长度
    void *        pData;                                    // 回调数据
    unsigned int  nReserved[4];                             // 保留字段
} OutputPlatformInfo;

// 单个动态IO信息结构
typedef struct DynamicIOInfoItem__
{
    unsigned int     nIOType;                    // 动态IO类型：1-整型；2-浮点型；3-字符串型；4-图像型；5-大数据型
    char chIOName[MAX_OBJECT_IO_NAME_LENGTH];   // 动态IO名称
}DynamicIOInfoItem;

// 动态IO列表信息结构
typedef struct DynamicIOInfoList__
{
    unsigned int      nIONum;                                 // 动态IO数量
    DynamicIOInfoItem astIOInfo[MAX_OBJECT_IO_NUM];           // 动态IO集合
    unsigned int      nReserved[4];                           // 保留字段
}DynamicIOInfoList;

#endif    ///< _IVM_EXPORT_H__
