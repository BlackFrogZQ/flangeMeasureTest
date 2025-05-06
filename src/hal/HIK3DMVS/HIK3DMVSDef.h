#pragma once
#include "system/basic.h"
#include "Mv3dLpDefine.h"

namespace TIGER_HIKROBOT3DCamera
{
#pragma region "海康3D相机设置参数"
    enum CSaveImageType: int
    {
        csitTIFF = 0,
        csitBMP,
        csitRAW,
        csitUnKnow
    };
    struct CHIK3DCameraSetParas
    {
        QString ip = "192.168.0.2";
        CSaveImageType saveImageType = csitTIFF;
    };
    CHIK3DCameraSetParas *HIKCameraSetPara();
#pragma endregion

#pragma region "海康3D相机获取参数"
    struct CHIK3DCameraGetParas
    {
        char chManufacturerName[32];                       //设备厂商
        char chModelName[32];                              //设备型号
        char chDeviceVersion[32];                          //设备版本
        char  chManufacturerSpecificInfo[48];              //设备厂商特殊信息
        char chSerialNumber[16];                           //设备序列号
        char chUserDefinedName[16];                        //设备用户自定义名称

        unsigned char chMacAddress[8];                     //Mac地址
        Mv3dLpIpCfgMode enIPCfgMode;                       //当前IP类型
        char chCurrentIp[16];                              //设备当前IP
        char chCurrentSubNetMask[16];                      //设备当前子网掩码
        char chDefultGateWay[16];                          //设备默认网关
        char chNetExport[16];                              //网口IP地址

        uint32_t nDevTypeInfo;                             //设备类型信息

        uint8_t nReserved[12];                             //保留字节
    };
#pragma endregion
}