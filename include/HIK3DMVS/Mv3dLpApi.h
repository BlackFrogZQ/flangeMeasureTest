
#ifndef _MV3D_LP_API_H_
#define _MV3D_LP_API_H_

#include "Mv3dLpDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
*  @~chinese
*  @brief  获取SDK版本号
*  @param  
*  @return 返回版本号。示例：1.0.0

*  @~english
*  @brief  Get DLL version
*  @param  
*  @return Return version info.Eg:1.0.0
 ************************************************************************/
MV3D_LP_API const char* MV3D_LP_GetVersion();

/************************************************************************
*  @~chinese
*  @brief  SDK运行环境初始化
*  @param
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Initializes the DLL
*  @param
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_Initialize();

/************************************************************************
*  @~chinese
*  @brief  SDK运行环境释放
*  @param
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Finalize DLL
*  @param
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_Finalize();

/************************************************************************
*  @~chinese
*  @brief  获取当前环境中设备数量
*  @param  pDeviceNumber               [OUT]           设备数量
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Gets the number of devices in the current environment
*  @param  pDeviceNumber               [OUT]           device number
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_GetDeviceNumber(uint32_t* pDeviceNumber);

/************************************************************************
*  @~chinese
*  @brief  获取设备列表
*  @param  pstDeviceInfos              [IN OUT]        设备列表
*  @param  nMaxDeviceCount             [IN]            设备列表缓存最大个数
*  @param  pDeviceCount                [OUT]           填充列表中设备个数
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码 

*  @~english
*  @brief  Gets 3D cameras list
*  @param  pstDeviceInfos              [IN OUT]        devices list
*  @param  nMaxDeviceCount             [IN]            Max Number of device list caches
*  @param  pDeviceCount                [OUT]           number of devices in the fill list
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_GetDeviceList(MV3D_LP_DEVICE_INFO* pstDeviceInfos, uint32_t nMaxDeviceCount, uint32_t* pDeviceCount);

/************************************************************************
*  @~chinese
*  @brief  通过IP打开设备
*  @param  handle                      [IN OUT]        设备句柄
*  @param  chIP                        [IN]            IP地址
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Open device by ip
*  @param  handle                      [IN OUT]        device handle
*  @param  chIP                        [IN]            IP
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_OpenDeviceByIP(HANDLE *handle, const char* chIP);

/************************************************************************
*  @~chinese
*  @brief  通过序列号打开设备
*  @param  handle                      [IN OUT]        设备句柄
*  @param  chSN                        [IN]            序列号
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Open device by serial number
*  @param  handle                      [IN OUT]        device handle
*  @param  chSN                        [IN]            serial number
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_OpenDeviceBySN(HANDLE *handle, const char* chSN);

/************************************************************************
*  @~chinese
*  @brief  关闭设备
*  @param  handle                      [IN]            设备句柄
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Close device
*  @param  handle                      [IN]            device handle
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_CloseDevice(HANDLE *handle);

/************************************************************************
*  @~chinese
*  @brief  配置IP,仅网口设备有效
*  @param  chSerialNumber              [IN]            序列号
*  @param  pstIPConfig                 [IN]            IP配置，静态IP，DHCP等
*  @return 成功,MV3D_LP_OK,失败,返回错误码

*  @~english
*  @brief  IP configuration，only network device is valid 
*  @param  chSerialNumber              [IN]            serial number
*  @param  pstIPConfig                 [IN]            IP Config, Static IP，DHCP
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_SetIpConfig(const char* chSerialNumber, MV3D_LP_IP_CONFIG* pstIPConfig);

/************************************************************************
*  @~chinese
*  @brief  注册异常消息回调
*  @param  handle                      [IN]            设备句柄
*  @param  cbException                 [IN]            异常回调函数指针
*  @param  pUser                       [IN]            用户自定义变量
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Register Exception Message CallBack
*  @param  handle                      [IN]            device handle
*  @param  cbException                 [IN]            Exception Message CallBack Function Pointer
*  @param  pUser                       [IN]            User defined variable
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_RegisterExceptionCallBack(HANDLE handle, MV3D_LP_ExceptionCallBack cbException, void* pUser);

/***********************************************************************
*  @~chinese
*  @brief  开始测量
*  @param  handle                      [IN]            设备句柄
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Start measurements
*  @param  handle                      [IN]            device handle
*  @return Success, return MV3D_LP_OK. Failure, return error code
***********************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_StartMeasure(HANDLE handle);

/***********************************************************************
*  @~chinese
*  @brief  停止测量
*  @param  handle                      [IN]            设备句柄
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Stop measurements
*  @param  handle                      [IN]            device handle
*  @return Success, return MV3D_LP_OK. Failure, return error code
***********************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_StopMeasure(HANDLE handle);

/************************************************************************
*  @~chinese
*  @brief  执行设备软触发
*  @param  handle                      [IN]            设备句柄
*  @return 成功,返回MV3D_LP_OK,失败,返回错误码

*  @~english
*  @brief  Execute device software trigger
*  @param  handle                      [IN]            device handle
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_SoftTrigger(HANDLE handle);

/************************************************************************
*  @~chinese
*  @brief  获取图像数据
*  @param  handle                      [IN]            设备句柄
*  @param  pstImageData                [IN OUT]        数据指针
*  @param  nTimeOut                    [IN]            超时时间（单位:毫秒）
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Get image data
*  @param  handle                      [IN]            device handle
*  @param  pstImageData                [IN OUT]        data set pointer
*  @param  nTimeout                    [IN]            timevalue（Unit: ms）
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_GetImage(HANDLE handle, MV3D_LP_IMAGE_DATA* pstImageData, uint32_t nTimeout);

/***********************************************************************
*  @~chinese
*  @brief  注册图像数据回调
*  @param  handle                      [IN]            设备句柄
*  @param  cbOutput                    [IN]            回调函数指针
*  @param  pUser                       [IN]            用户自定义变量
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  register image data callback
*  @param  handle                      [IN]            device handle
*  @param  cbOutput                    [IN]            Callback function pointer
*  @param  pUser                       [IN]            User defined variable
*  @return Success, return MV3D_LP_OK. Failure, return error code
***********************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_RegisterImageDataCallBack(HANDLE handle, MV3D_LP_ImageDataCallBack cbOutput, void* pUser);

/***********************************************************************
*  @~chinese
*  @brief  清除数据缓存
*  @param  handle                      [IN]            设备句柄
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Clear data buffer
*  @param  handle                      [IN]            device handle
*  @return Success, return MV3D_LP_OK. Failure, return error code
***********************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_ClearDataBuffer(HANDLE handle);

/************************************************************************
*  @~chinese
*  @brief  获取设备参数值
*  @param  handle                      [IN]            设备句柄
*  @param  strKey                      [IN]            参数键值
*  @param  pstParam                    [IN OUT]        返回的设备参数结构体指针
*  @return 成功,返回MV3D_LP_OK,失败,返回错误码

*  @~english
*  @brief  Get device param value
*  @param  handle                      [IN]            device handle
*  @param  strKey                      [IN]            Key value
*  @param  pstParam                    [IN OUT]        Structure pointer of device param
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_GetParam(HANDLE handle, const char* strKey, MV3D_LP_PARAM* pstParam);

/************************************************************************
*  @~chinese
*  @brief  设置设备参数值
*  @param  handle                      [IN]            设备句柄
*  @param  strKey                      [IN]            参数键值
*  @param  pstParam                    [IN]            输入的设备参数结构体指针
*  @return 成功,返回MV3D_LP_OK,失败,返回错误码

*  @~english
*  @brief  Set device param value
*  @param  handle                      [IN]            device handle
*  @param  strKey                      [IN]            Key value
*  @param  pstParam                    [IN]            Structure pointer of device param
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_SetParam(HANDLE handle, const char* strKey, MV3D_LP_PARAM* pstParam);

/************************************************************************
*  @~chinese
*  @brief  执行设备Command命令
*  @param  handle                      [IN]            设备句柄
*  @param  strKey                      [IN]            参数键值
*  @return 成功,返回MV3D_LP_OK,失败,返回错误码

*  @~english
*  @brief  Execute device command
*  @param  handle                      [IN]            device handle
*  @param  strKey                      [IN]            Key value
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_Execute(HANDLE handle, const char* strKey);


/************************************************************************
*  @~chinese
*  @brief  废弃接口

*  @~english
*  @brief  Discard API
************************************************************************/
#if 1
/************************************************************************
*  @~chinese
*  @brief  获取指定设备的IP
*  @param  nDeviceIndex                [IN]            设备索引
*  @param  chIP                        [IN OUT]        设备IP
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Get device ip
*  @param  nDeviceIndex                [IN]            device index
*  @param  chIP                        [IN OUT]        devices IP
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_GetDeviceIP(uint32_t nDeviceIndex, char* chIP);

/************************************************************************
*  @~chinese
*  @brief  获取指定设备的序列号
*  @param  nDeviceIndex                [IN]            设备索引
*  @param  chSN                        [IN OUT]        设备序列号
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Get device ip
*  @param  nDeviceIndex                [IN]            device index
*  @param  chSN                        [IN OUT]        devices serial number
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_GetDeviceSN(uint32_t nDeviceIndex, char* chSN);

/************************************************************************
*  @~chinese
*  @brief  获取轮廓数据（设备图像模式配置为轮廓数据）
*  @param  handle                      [IN]            设备句柄
*  @param  nProfileCount               [IN]            期望获取的轮廓数量
*  @param  pstProfileData              [IN OUT]        数据指针
*  @param  nTimeOut                    [IN]            超时时间（单位:毫秒）
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Get profile data
*  @param  handle                      [IN]            device handle
*  @param  nProfileCount               [IN]            the number of profile to get
*  @param  pstProfileData              [IN OUT]        data set pointer
*  @param  nTimeout                    [IN]            timevalue（Unit: ms）
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_GetProfile(HANDLE handle, uint32_t nProfileCount, MV3D_LP_PROFILE_DATA* pstProfileData, uint32_t nTimeout);

/************************************************************************
*  @~chinese
*  @brief  获取深度数据（设备图像模式配置为深度数据）
*  @param  handle                      [IN]            设备句柄
*  @param  pstDepthData                [IN OUT]        数据指针
*  @param  nTimeOut                    [IN]            超时时间（单位:毫秒）
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Get batch profile data
*  @param  handle                      [IN]            device handle
*  @param  pstDepthData                [IN OUT]        data set pointer
*  @param  nTimeout                    [IN]            timevalue（Unit: ms）
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_GetBatchProfile(HANDLE handle, MV3D_LP_DEPTH_DATA* pstDepthData, uint32_t nTimeout);

/************************************************************************
*  @~chinese
*  @brief  获取亮度数据（即轮廓数据或深度数据对应的亮度数据）
*  @param  handle                      [IN]            设备句柄
*  @param  pstIntensityData            [IN OUT]        数据指针
*  @param  nTimeOut                    [IN]            超时时间（单位:毫秒）
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  Get intensity data
*  @param  handle                      [IN]            device handle
*  @param  pstIntensityData            [IN OUT]        data set pointer
*  @param  nTimeout                    [IN]            timevalue（Unit: ms）
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_GetIntensityData(HANDLE handle, MV3D_LP_INTENSITY_DATA* pstIntensityData, uint32_t nTimeout);

/***********************************************************************
*  @~chinese
*  @brief  注册图像数据回调（设备图像模式配置为轮廓数据，回调中同时获取轮廓数据和亮度数据）
*  @param  handle                      [IN]            设备句柄
*  @param  cbOutput                    [IN]            回调函数指针
*  @param  nProfileCount               [IN]            回调函数被调用的频率(即回调中期望获取的轮廓数量)
*  @param  pUser                       [IN]            用户自定义变量
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  register image data callback
*  @param  handle                      [IN]            device handle
*  @param  cbOutput                    [IN]            Callback function pointer
*  @param  nProfileCount               [IN]            the frequency to call the callback function
*  @param  pUser                       [IN]            User defined variable
*  @return Success, return MV3D_LP_OK. Failure, return error code
***********************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_RegisterProfileCallBack(HANDLE handle, MV3D_LP_ProfileDataCallBack cbOutput, uint32_t nProfileCount, void* pUser);

/***********************************************************************
*  @~chinese
*  @brief  注册图像数据回调（设备图像模式配置为深度数据，回调中同时获取深度数据和亮度数据）
*  @param  handle                      [IN]            设备句柄
*  @param  cbOutput                    [IN]            回调函数指针
*  @param  pUser                       [IN]            用户自定义变量
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  register image data callback
*  @param  handle                      [IN]            device handle
*  @param  cbOutput                    [IN]            Callback function pointer
*  @param  pUser                       [IN]            User defined variable
*  @return Success, return MV3D_LP_OK. Failure, return error code
***********************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_RegisterBatchProfileCallBack(HANDLE handle, MV3D_LP_BatchProfileDataCallBack cbOutput, void* pUser);
#endif

#ifdef __cplusplus
}
#endif

#endif // _MV3D_LP_API_H_
