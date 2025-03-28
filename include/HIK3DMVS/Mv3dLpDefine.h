
#ifndef _MV3D_LP_DEFINE_H_
#define _MV3D_LP_DEFINE_H_

#ifndef MV3D_LP_API
    #if (defined (_WIN32) || defined(WIN64))
        #if defined(MV3D_LP_EXPORTS)
            #define MV3D_LP_API __declspec(dllexport)
        #else
            #define MV3D_LP_API __declspec(dllimport)
        #endif
    #else
        #ifndef __stdcall
            #define __stdcall
        #endif

        #ifndef MV3D_LP_API
            #define  MV3D_LP_API
        #endif
    #endif
#endif

///< \~chinese 跨平台定义       \~english Cross Platform Definition
#ifdef WIN32
    typedef signed char                   int8_t;
    typedef unsigned char                 uint8_t;
    typedef short                         int16_t;
    typedef unsigned short                uint16_t;
    typedef int                           int32_t;
    typedef unsigned int                  uint32_t;
    typedef long long int                 int64_t;
    typedef unsigned long long            uint64_t;
    
    #define MV3D_LP_UNDEFINED             0xFFFFFFFF
#else
    #include <stdint.h>

    #define MV3D_LP_UNDEFINED             -1
#endif

/***********************************ch: 状态码 | en: Status Code******************************************/
///< \~chinese 正确码定义       \~english Definition of Correct Code
#define MV3D_LP_OK                        0x00000000              ///< \~chinese 成功，无错误       \~english Success, no error

///< \~chinese 通用错误码定义:范围0x80060000-0x800600FF         \~english Definition of General Error Code:from 0x80060000 to 0x800600FF
#define MV3D_LP_E_HANDLE                  0x80060000              ///< \~chinese 错误或无效的句柄   \~english Incorrect or invalid handle
#define MV3D_LP_E_SUPPORT                 0x80060001              ///< \~chinese 不支持的功能       \~english The function is not supported
#define MV3D_LP_E_BUFOVER                 0x80060002              ///< \~chinese 缓存已满           \~english The buffer is full
#define MV3D_LP_E_CALLORDER               0x80060003              ///< \~chinese 函数调用顺序错误   \~english Incorrect calling sequence
#define MV3D_LP_E_PARAMETER               0x80060004              ///< \~chinese 错误的参数         \~english Incorrect parameter
#define MV3D_LP_E_RESOURCE                0x80060005              ///< \~chinese 资源申请失败       \~english Resource request failed
#define MV3D_LP_E_NODATA                  0x80060006              ///< \~chinese 无数据             \~english No data
#define MV3D_LP_E_PRECONDITION            0x80060007              ///< \~chinese 前置条件有误，或运行环境已发生变化     \~english Incorrect precondition, or running environment has changed
#define MV3D_LP_E_VERSION                 0x80060008              ///< \~chinese 版本不匹配         \~english The version mismatched
#define MV3D_LP_E_NOENOUGH_BUF            0x80060009              ///< \~chinese 传入的内存空间不足 \~english Insufficient memory
#define MV3D_LP_E_ABNORMAL_IMAGE          0x8006000A              ///< \~chinese 异常图像，可能是丢包导致图像不完整     \~english Abnormal image. Incomplete image caused by packet loss
#define MV3D_LP_E_LOAD_LIBRARY            0x8006000B              ///< \~chinese 动态导入DLL失败    \~english Failed to load the dynamic link library dynamically
#define MV3D_LP_E_ALGORITHM               0x8006000C              ///< \~chinese 算法错误           \~english Algorithm error
#define MV3D_LP_E_DEVICE_OFFLINE          0x8006000D              ///< \~chinese 设备离线           \~english The device is offline 
#define MV3D_LP_E_ACCESS_DENIED           0x8006000E              ///< \~chinese 设备无访问权限     \~english No device access permission
#define MV3D_LP_E_OUTOFRANGE              0x8006000F              ///< \~chinese 值超出范围         \~english The value is out of range

#define MV3D_LP_E_UNKNOW                  0x800600FF              ///< \~chinese 未知的错误         \~english Unknown error

/************************************ch:常量定义 | en: Macro Definition************************************/
#define MV3D_LP_MAX_STRING_LENGTH         256                     ///< \~chinese 最大字符串长度     \~english The maximum length of string
#define MV3D_LP_MAX_ENUM_COUNT            16                      ///< \~chinese 枚举型参数的最大枚举值数量     \~english The maximum number of enumerations

/************************************ch:像素类型 | en: Pixel Type******************************************/
#define MV3D_LP_PIXEL_MONO                0x01000000              
#define MV3D_LP_PIXEL_COLOR               0x02000000              
#define MV3D_LP_PIXEL_CUSTOM              0x80000000              
#define MV3D_LP_PIXEL_BIT_COUNT(n)        ((n) << 16)             

///< \~chinese 常用的设备参数键值定义       \~english Attribute Key Value Definition
#define MV3D_LP_INT_WIDTH                 "Width"                 ///< \~chinese 图像宽         \~english Image width
#define MV3D_LP_INT_HEIGHT                "Height"                ///< \~chinese 图像高         \~english Image height
#define MV3D_LP_ENUM_PIXELFORMAT          "PixelFormat"           ///< \~chinese 像素格式       \~english Pixel format
#define MV3D_LP_ENUM_IMAGEMODE            "ImageMode"             ///< \~chinese 图像模式       \~english Image mode
#define MV3D_LP_FLOAT_GAIN                "Gain"                  ///< \~chinese 增益           \~english Gain
#define MV3D_LP_FLOAT_EXPOSURETIME        "ExposureTime"          ///< \~chinese 曝光时间       \~english Exposure time
#define MV3D_LP_FLOAT_FRAMERATE           "AcquisitionFrameRate"  ///< \~chinese 采集帧率       \~english Acquired frame rate
#define MV3D_LP_ENUM_TRIGGERSELECTOR      "TriggerSelector"       ///< \~chinese 触发选择器     \~english Trigger selector
#define MV3D_LP_ENUM_TRIGGERMODE          "TriggerMode"           ///< \~chinese 触发模式       \~english Trigger mode
#define MV3D_LP_ENUM_TRIGGERSOURCE        "TriggerSource"         ///< \~chinese 触发源         \~english Trigger source
#define MV3D_LP_FLOAT_TRIGGERDELAY        "TriggerDelay"          ///< \~chinese 触发延迟时间   \~english Trigger delay
#define MV3D_LP_INT_LSL_COORDINATE_TYPE   "SDKCoordinateType"     ///< \~chinese 线激光坐标系类型   \~english Line laser coordinate type
#define MV3D_LP_INT_LSL_EMPTY_POINT       "SDKEmptyPoint"         ///< \~chinese 线激光空点     \~english Line laser empty point


typedef int32_t                           MV3D_LP_STATUS;         ///< \~chinese 返回值类型     \~english Return value type
typedef void*                             HANDLE;                 ///< \~chinese 句柄类型       \~english Handle type
typedef int32_t                           BOOL;                   ///< \~chinese BOOL类型       \~english Boolean type

#ifndef TRUE
#define TRUE                              1                       
#endif
#ifndef FALSE
#define FALSE                             0                       
#endif
#ifndef NULL
#define NULL                              0                       
#endif

/*******************ch:枚举 | en: Enumeration***************************/

///< \~chinese IP配置类型       \~english IP Address Mode
typedef enum Mv3dLpIpCfgMode
{
    IpCfgMode_Static            = 1,                                        ///< \~chinese 静态IP   \~english Static IP mode
    IpCfgMode_DHCP              = 2,                                        ///< \~chinese 自动分配IP(DHCP) \~english Automatically assigned IP address (DHCP)
    IpCfgMode_LLA               = 4                                         ///< \~chinese 自动分配IP(LLA)  \~english Automatically assigned IP address (LLA) 
} Mv3dLpIpCfgMode;

///< \~chinese 异常类型         \~english Exception Type
typedef enum Mv3dLpDevExceptionType
{
    DevExceptionType_Undefined  = MV3D_LP_UNDEFINED,
    DevExceptionType_Disconnect = 1                                         ///< \~chinese 设备断开连接     \~english The device is disconnected
} Mv3dLpDevExceptionType;

///< \~chinese 参数类型         \~english Parameter Type
typedef enum Mv3dLpParamType
{
    ParamType_Undefined         = MV3D_LP_UNDEFINED,                        
    ParamType_Bool              = 1,                                        ///< \~chinese 布尔型参数       \~english Boolean
    ParamType_Int               = 2,                                        ///< \~chinese 整型参数         \~english Int
    ParamType_Float             = 3,                                        ///< \~chinese 浮点型参数       \~english Float
    ParamType_Enum              = 4,                                        ///< \~chinese 枚举型参数       \~english Enumeration
    ParamType_String            = 5                                         ///< \~chinese 字符串参数       \~english String
} Mv3dLpParamType;

typedef enum Mv3dLpImageType
{
    ImageType_Undefined         = MV3D_LP_UNDEFINED,
    ImageType_Mono8             = (MV3D_LP_PIXEL_MONO  | MV3D_LP_PIXEL_BIT_COUNT(8)  | 0x0001),   //0x01080001,(Mono8)
    ImageType_Depth             = (MV3D_LP_PIXEL_MONO  | MV3D_LP_PIXEL_BIT_COUNT(16) | 0x00B8),   //0x011000B8,(C16)
    ImageType_Profile           = (MV3D_LP_PIXEL_COLOR | MV3D_LP_PIXEL_BIT_COUNT(48) | 0x00B9),   //0x023000B9,(ABC16)
    ImageType_PointCloud        = (MV3D_LP_PIXEL_COLOR | MV3D_LP_PIXEL_BIT_COUNT(96) | 0x00C0),   //0x026000C0,(ABC32f)
    ImageType_RGB24_Packed      = (MV3D_LP_PIXEL_COLOR | MV3D_LP_PIXEL_BIT_COUNT(24) | 0x0014),   //0x02180014,(RGB24)
    ImageType_Jpeg              = (MV3D_LP_PIXEL_CUSTOM| MV3D_LP_PIXEL_BIT_COUNT(24) | 0x0001),   //0x80180001,(JPEG)
    ImageType_Profile_ABC32     = (MV3D_LP_PIXEL_CUSTOM| MV3D_LP_PIXEL_COLOR | MV3D_LP_PIXEL_BIT_COUNT(96) | 0x3001),//0x82603001,(ABC32)
} Mv3dLpImageType;

///< \~chinese 3D文件格式       \~english 3D File Type
typedef enum Mv3dLpFileType
{
    FileType_Undefined          = MV3D_LP_UNDEFINED,
    FileType_PLY                = 1,                                        ///< \~chinese PLY文件          \~english PLY(ascii)
    FileType_CSV                = 2,                                        ///< \~chinese CSV文件          \~english CSV
    FileType_OBJ                = 3,                                        ///< \~chinese OBJ文件          \~english OBJ
    FileType_BMP                = 4,                                        ///< \~chinese BMP文件          \~english BMP
    FileType_JPG                = 5,                                        ///< \~chinese JPG文件          \~english JPG
    FileType_TIFF               = 6,                                        ///< \~chinese TIFF文件(S16)    \~english TIFF(S16)
    FileType_TIFF_U16           = 7,                                        ///< \~chinese TIFF文件(U16)    \~english TIFF(U16)
    FileType_TIFF_F32           = 8,                                        ///< \~chinese TIFF文件(F32)    \~english TIFF(F32)
    FileType_PLY_BINARY         = 9,                                        ///< \~chinese 二进制PLY文件    \~english PLY(binary)
    FileType_PLY_TEXTURE        = 10                                        ///< \~chinese 纹理PLY文件      \~english PLY(texture)
}Mv3dLpFileType;

///< \~chinese 3D显示图像类型       \~english 3D Image Display Type
typedef enum Mv3dLpDisplayType
{
    DisplayType_Undefined       = MV3D_LP_UNDEFINED,
    DisplayType_Auto            = 1,
    DisplayType_Manual          = 2,
}Mv3dLpDisplayType;

/*******************ch: 结构体 | en: Struct***********************/

typedef struct _MV3D_LP_DEVICE_INFO_
{
    char                      chManufacturerName[32];                       ///< \~chinese 设备厂商         \~english Manufacturer
    char                      chModelName[32];                              ///< \~chinese 设备型号         \~english Device model
    char                      chDeviceVersion[32];                          ///< \~chinese 设备版本         \~english Device version
    char                      chManufacturerSpecificInfo[48];               ///< \~chinese 设备厂商特殊信息 \~english The specific information about manufacturer
    char                      chSerialNumber[16];                           ///< \~chinese 设备序列号       \~english Device serial number
    char                      chUserDefinedName[16];                        ///< \~chinese 设备用户自定义名称   \~english User-defined name of device

    unsigned char             chMacAddress[8];                              ///< \~chinese Mac地址          \~english MAC address
    Mv3dLpIpCfgMode           enIPCfgMode;                                  ///< \~chinese 当前IP类型       \~english Current IP type
    char                      chCurrentIp[16];                              ///< \~chinese 设备当前IP       \~english Device‘s IP address
    char                      chCurrentSubNetMask[16];                      ///< \~chinese 设备当前子网掩码 \~english Device’s subnet mask
    char                      chDefultGateWay[16];                          ///< \~chinese 设备默认网关     \~english Device‘s default gateway
    char                      chNetExport[16];                              ///< \~chinese 网口IP地址       \~english Network interface IP address

    uint32_t                  nDevTypeInfo;                                 ///< \~chinese 设备类型信息     \~english Device type info

    uint8_t                   nReserved[12];                                ///< \~chinese 保留字节         \~english Reserved

} MV3D_LP_DEVICE_INFO;

typedef struct _MV3D_LP_IP_CONFIG_
{
    Mv3dLpIpCfgMode           enIPCfgMode;                                  ///< \~chinese IP配置模式       \~english IP configuration mode
    char                      chDestIp[16];                                 ///< \~chinese 设置的目标IP,仅静态IP模式下有效          \~english The IP address which is to be attributed to the target device. It is valid in the static IP mode only
    char                      chDestNetMask[16];                            ///< \~chinese 设置的目标子网掩码,仅静态IP模式下有效    \~english The subnet mask of target device. It is valid in the static IP mode only
    char                      chDestGateWay[16];                            ///< \~chinese 设置的目标网关,仅静态IP模式下有效        \~english The gateway of target device. It is valid in the static IP mode only

    uint8_t                   nReserved[16];                                ///< \~chinese 保留字节         \~english Reserved
} MV3D_LP_IP_CONFIG;

///< \~chinese 图像数据         \~english Image Data
typedef struct _MV3D_LP_IMAGE_DATA_
{
    Mv3dLpImageType           enImageType;                                  ///< \~chinese 图像格式         \~english Image type
    uint32_t                  nWidth;                                       ///< \~chinese 宽度             \~english Image width
    uint32_t                  nHeight;                                      ///< \~chinese 高度             \~english Image height
    uint8_t*                  pData;                                        ///< \~chinese 图像数据         \~english Image data, which is outputted by the camera
    uint32_t                  nDataLen;                                     ///< \~chinese 图像数据长度(字节)           \~english Image data length (bytes)
    uint8_t*                  pIntensityData;                               ///< \~chinese 亮度图像数据     \~english Intensity image data, which is outputted by the camera
    uint32_t                  nIntensityDataLen;                            ///< \~chinese 亮度图像数据长度(字节)       \~english Intensity image data length (bytes)
    uint32_t                  nFrameNum;                                    ///< \~chinese 帧号             \~english Frame number, which indicates the frame sequence
    int64_t                   nTimeStamp;                                   ///< \~chinese 设备上报的时间戳 \~english Timestamp uploaded by the device. It starts from 0 when the device is powered on. Refer to the device user manual for detailed rules
    BOOL                      bValid;                                       ///< \~chinese 数据有效标记，如有丢包则无效 \~english Image valid flag,invalid if there is packet loss
    float                     fXScale;                                      ///< \~chinese X方向采样间隔    \~english X scale
    float                     fYScale;                                      ///< \~chinese Y方向采样间隔    \~english Y scale
    float                     fZScale;                                      ///< \~chinese Z方向采样间隔    \~english Z scale
    int32_t                   nXOffset;                                     ///< \~chinese X方向偏移        \~english X offset
    int32_t                   nYOffset;                                     ///< \~chinese Y方向偏移        \~english Y offset
    int32_t                   nZOffset;                                     ///< \~chinese Z方向偏移        \~english Z offset

    uint8_t                   nReserved[16];                                ///< \~chinese 保留字节         \~english Reserved
} MV3D_LP_IMAGE_DATA;

///< \~chinese Int类型参数值        \~english Int Type Value
typedef struct _MV3D_LP_INTPARAM_
{
    int64_t                   nCurValue;                                    ///< \~chinese 当前值           \~english Current value
    int64_t                   nMax;                                         ///< \~chinese 最大值           \~english The maximum value
    int64_t                   nMin;                                         ///< \~chinese 最小值           \~english The minimum value
    int64_t                   nInc;                                         ///< \~chinese 增量值           \~english The increment value
} MV3D_LP_INTPARAM;

///< \~chinese Enum类型参数值       \~english Enumeration Type Value
typedef struct _MV3D_LP_ENUMPARAM_
{
    uint32_t                  nCurValue;                                    ///< \~chinese 当前值           \~english Current value
    uint32_t                  nSupportedNum;                                ///< \~chinese 有效数据个数     \~english The number of valid data
    uint32_t                  nSupportValue[MV3D_LP_MAX_ENUM_COUNT];        ///< \~chinese 支持的枚举类型   \~english The type of supported enumerations
} MV3D_LP_ENUMPARAM;

///< \~chinese Float类型参数值      \~english Float Type Value
typedef struct _MV3D_LP_FLOATPARAM_
{
    float                     fCurValue;                                    ///< \~chinese 当前值           \~english Current value
    float                     fMax;                                         ///< \~chinese 最大值           \~english The maximum value
    float                     fMin;                                         ///< \~chinese 最小值           \~english The minimum value
} MV3D_LP_FLOATPARAM;

///< \~chinese String类型参数值     \~english String Type Value
typedef struct _MV3D_LP_STRINGPARAM_
{
    char                      chCurValue[MV3D_LP_MAX_STRING_LENGTH];        ///< \~chinese 当前值           \~english Current value
    uint32_t                  nMaxLength;                                   ///< \~chinese 属性节点能设置字符的最大长度     \~english The maximum length of string
} MV3D_LP_STRINGPARAM;

///< \~chinese 设备参数值           \~english Device Parameters
typedef struct _MV3D_LP_PARAM_
{
    Mv3dLpParamType           enParamType;                                  ///< \~chinese 设置属性值类型   \~english Parameter data type
    union
    {
        BOOL                  bBoolParam;                     
        MV3D_LP_INTPARAM      stIntParam;                     
        MV3D_LP_FLOATPARAM    stFloatParam;                   
        MV3D_LP_ENUMPARAM     stEnumParam;                    
        MV3D_LP_STRINGPARAM   stStringParam;                  
    } ParamInfo;

    uint8_t                   nReserved[16];                                ///< \~chinese 保留字节         \~english Reserved
} MV3D_LP_PARAM;

///< \~chinese 异常信息             \~english Exception Information
typedef struct _MV3D_LP_EXCEPTION_INFO_
{
    Mv3dLpDevExceptionType    enExceptionType;                              ///< \~chinese 异常类型         \~english Exception type
    char                      chExceptionDesc[MV3D_LP_MAX_STRING_LENGTH];   ///< \~chinese 异常描述         \~english Exception description

    uint8_t                   nReserved[4];                                 ///< \~chinese 保留字节         \~english Reserved
} MV3D_LP_EXCEPTION_INFO;

///< \~chinese 回调接口             \~english Callback Api
typedef void(__stdcall* MV3D_LP_ImageDataCallBack)         (MV3D_LP_IMAGE_DATA* pstImageData, void* pUser);
typedef void(__stdcall* MV3D_LP_ExceptionCallBack)         (MV3D_LP_EXCEPTION_INFO* pstExceptInfo, void* pUser);

/************************************************************************
*  @brief  废弃数据

*  @brief  Discard Data 
************************************************************************/
#if 1
///< \~chinese 3D点（S16）          \~english 3D Point（S16）
typedef struct _MV3D_LP_POINT_XYZ_S16_
{
    int16_t nX;
    int16_t nY;
    int16_t nZ;
}MVB3D_LP_POINT_XYZ_S16;

///< \~chinese 3D点（F32）          \~english 3D Point（F32）
typedef struct _MV3D_LP_POINT_XYZ_F32_
{
    float fX;
    float fY;
    float fZ;
}MVB3D_LP_POINT_XYZ_F32;

///< \~chinese 轮廓数据             \~english Profile Data
typedef struct _MV3D_LP_PROFILE_DATA_
{
    uint32_t                  nLinePntNum;                                  ///< \~chinese 单行轮廓点数     \~english Number of points on a single line
    uint32_t                  nProfileCnt;                                  ///< \~chinese 轮廓行数         \~english Profile count
    MVB3D_LP_POINT_XYZ_S16*   pData;                                        ///< \~chinese 轮廓数据         \~english Profile data
    uint32_t                  nDataLen;                                     ///< \~chinese 轮廓数据长度(字节)           \~english Profile data length (bytes)
    uint32_t                  nFrameNum;                                    ///< \~chinese 帧号             \~english Frame number, which indicates the frame sequence
    int64_t                   nTimeStamp;                                   ///< \~chinese 设备上报的时间戳 \~english Timestamp uploaded by the device. It starts from 0 when the device is powered on. Refer to the device user manual for detailed rules
    BOOL                      bValid;                                       ///< \~chinese 数据有效标记，如有丢包则无效 \~english Image valid flag,invalid if there is packet loss
    float                     fXScale;                                      ///< \~chinese X方向采样间隔    \~english X scale
    float                     fYScale;                                      ///< \~chinese Y方向采样间隔    \~english Y scale
    float                     fZScale;                                      ///< \~chinese Z方向采样间隔    \~english Z scale
    int32_t                   nXOffset;                                     ///< \~chinese X方向偏移        \~english X offset
    int32_t                   nYOffset;                                     ///< \~chinese Y方向偏移        \~english Y offset
    int32_t                   nZOffset;                                     ///< \~chinese Z方向偏移        \~english Z offset

    uint8_t                   nReserved[16];                                ///< \~chinese 保留字节         \~english Reserved
} MV3D_LP_PROFILE_DATA;

///< \~chinese 深度数据             \~english Depht Data
typedef struct _MV3D_LP_DEPTH_DATA_
{
    uint32_t                  nWidth;                                       ///< \~chinese 宽度             \~english Image width
    uint32_t                  nHeight;                                      ///< \~chinese 高度             \~english Image height
    int16_t*                  pData;                                        ///< \~chinese 深度数据         \~english Depth data
    uint32_t                  nDataLen;                                     ///< \~chinese 深度数据长度(字节)           \~english  Depth data length (bytes)
    uint32_t                  nFrameNum;                                    ///< \~chinese 帧号             \~english Frame number, which indicates the frame sequence
    int64_t                   nTimeStamp;                                   ///< \~chinese 设备上报的时间戳 \~english Timestamp uploaded by the device. It starts from 0 when the device is powered on. Refer to the device user manual for detailed rules
    BOOL                      bValid;                                       ///< \~chinese 数据有效标记，如有丢包则无效 \~english Image valid flag,invalid if there is packet loss
    float                     fXScale;                                      ///< \~chinese X方向采样间隔    \~english X scale
    float                     fYScale;                                      ///< \~chinese Y方向采样间隔    \~english Y scale
    float                     fZScale;                                      ///< \~chinese Z方向采样间隔    \~english Z scale
    int32_t                   nXOffset;                                     ///< \~chinese X方向偏移        \~english X offset
    int32_t                   nYOffset;                                     ///< \~chinese Y方向偏移        \~english Y offset
    int32_t                   nZOffset;                                     ///< \~chinese Z方向偏移        \~english Z offset

    uint8_t                   nReserved[16];                                ///< \~chinese 保留字节         \~english Reserved
} MV3D_LP_DEPTH_DATA;

///< \~chinese 亮度数据             \~english Intensity Data
typedef struct _MV3D_LP_INTENSITY_DATA_
{
    uint32_t                  nWidth;                                       ///< \~chinese 宽度             \~english Image width
    uint32_t                  nHeight;                                      ///< \~chinese 高度             \~english Image height
    uint8_t*                  pData;                                        ///< \~chinese 亮度数据         \~english Intensity data
    uint32_t                  nDataLen;                                     ///< \~chinese 亮度数据长度(字节)           \~english  Intensity data length (bytes)
    uint32_t                  nFrameNum;                                    ///< \~chinese 帧号             \~english Frame number, which indicates the frame sequence
    int64_t                   nTimeStamp;                                   ///< \~chinese 设备上报的时间戳 \~english Timestamp uploaded by the device. It starts from 0 when the device is powered on. Refer to the device user manual for detailed rules
    BOOL                      bValid;                                       ///< \~chinese 数据有效标记，如有丢包则无效 \~english Image valid flag,invalid if there is packet loss

    uint8_t                   nReserved[16];                                ///< \~chinese 保留字节         \~english Reserved
} MV3D_LP_INTENSITY_DATA;

///< \~chinese 点云数据             \~english PointCloud Data
typedef struct _MV3D_LP_POINTCLOUD_DATA_
{    
    MVB3D_LP_POINT_XYZ_F32*   pData;                                        ///< \~chinese 点云数据         \~english Pointcloud data
    uint32_t                  nDataLen;                                     ///< \~chinese 点云数据长度(字节)           \~english  Pointcloud data length (bytes)
    uint32_t                  nFrameNum;                                    ///< \~chinese 帧号             \~english Frame number, which indicates the frame sequence
    int64_t                   nTimeStamp;                                   ///< \~chinese 设备上报的时间戳 \~english Timestamp uploaded by the device. It starts from 0 when the device is powered on. Refer to the device user manual for detailed rules
    BOOL                      bValid;                                       ///< \~chinese 数据有效标记，如有丢包则无效 \~english Image valid flag,invalid if there is packet loss

    uint8_t                   nReserved[16];                                ///< \~chinese 保留字节         \~english Reserved
} MV3D_LP_POINTCLOUD_DATA;

///< \~chinese 回调接口             \~english Callback Api
typedef void(__stdcall* MV3D_LP_ProfileDataCallBack)       (MV3D_LP_PROFILE_DATA* pstProfileData, MV3D_LP_INTENSITY_DATA* pstIntensityData, void* pUser);
typedef void(__stdcall* MV3D_LP_BatchProfileDataCallBack)  (MV3D_LP_DEPTH_DATA* pstDepthData, MV3D_LP_INTENSITY_DATA* pstIntensityData, void* pUser);

#endif

#endif  //  _MV3D_LP_DEFINE_H_
