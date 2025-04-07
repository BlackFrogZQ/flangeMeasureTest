/***************************************************************************************************
 * File：IVmCommManager.h
 * Note：CH: 通信管理模块接口声明 | En: Interface for the CommManagerModule tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_COMMMANAGER_H_
#define _IVM_COMMMANAGER_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"

namespace VisionMasterSDK
{
    namespace CommManagerModule
    {
        /*  Note: Note: This is the class for the CommManagerModule tool.  */
        class CommManagerModuleTool
        {
        protected:
            ///< Constructor and Destructor
            explicit CommManagerModuleTool() {}
            virtual ~CommManagerModuleTool() {}

        public:
            /**
             * @par 说明
             * 设置字符串型数据
             * @par 参数
             * nDeviceId  设备ID
             * strValue   字符串
             * nAddressId 只针对PLC与Modbus
             * @par 权限
             * 只读
             */
            virtual void SetString(IN int nDeviceId, IN const char * const strValue, IN int nAddressId = -1) = 0;

            /**
             * @par 说明
             * 设置整型数据（只支持PLC和Modbus通信协议设置）
             * @par 参数
             * nDeviceId  设备ID
             * nValue     整型数据
             * nNum       数量
             * nAddressId 只针对PLC与Modbus
             * @par 权限
             * 只读
             */
            virtual void SetInt(IN int nDeviceId, IN const int * const nValue, IN const int nNum, IN int nAddressId = -1) = 0;

            /**
             * @par 说明
             * 设置浮点型数据（只支持PLC和Modbus通信协议设置）
             * @par 参数
             * nDeviceId  设备ID
             * fValue     浮点型数据
             * nNum       数量
             * nAddressId 只针对PLC与Modbus
             * @par 权限
             * 只读
             */
            virtual void SetFloat(IN int nDeviceId, IN const float * const fValue, IN const int nNum, IN int nAddressId = -1) = 0;

            /**
             * @par 说明
             * 设置二进制型数据(不支持PLC)
             * @par 参数
             * nDeviceId  设备ID
             * btValue    二进制型数据
             * nLen       二进制型数据长度
             * nAddressId 只针对Modbus
             * @par 权限
             * 只读
             */
            virtual void SetBytes(IN int nDeviceId, IN const char * const btValue, IN const size_t nLen, IN int nAddressId = -1) = 0;

            /**
             * @par 说明
             * 获取读取数据
             * @par 参数
             * nDeviceId  设备ID
             * pData      二进制型数据
             * nLen       缓存区与实际长度(输入nLen数据长度应与实际数据长度一致)
             * nAddressId 只针对PLC与Modbus
             * @par 权限
             * 只读
             */
            virtual void GetReadData(IN int nDeviceId, OUT char * const pData, INOUT size_t * const nLen, IN int nAddressId = -1) = 0;

            /**
             * @par 说明
             * 通信设备是否处于连接状态
             * @par 参数
             * nDeviceId  设备ID
             * @par 权限
             * @return true: 连接, false: 未连接
             */
            virtual bool bIsDeviceConnect(IN int nDeviceId) = 0;

            /**
             * @par 说明
             * 获取通信设备参数值
             * @par 参数
             * nDeviceId  设备ID
             * strName    参数名
             * nValueSize 参数值接收区大小
             * strValue   参数值
             * nAddressId 设备地址
             * @par 权限
             * 只读
             */
            virtual void GetParamValue(IN int nDeviceId, IN const char * const strName, IN const unsigned int  nValueSize, OUT char * const strValue, IN int nAddressId = -1) = 0;

            /**
             * @par 说明
             * 设置通信设备参数值
             * @par 参数
             * nDeviceId  设备ID
             * strName    参数名
             * strValue   参数值
             * nAddressId 设备地址
             * @par 权限
             * 只读
             */
            virtual void SetParamValue(IN int nDeviceId, IN const char * const strName, IN const char * const strValue, IN int nAddressId = -1) = 0;

        private:
            CommManagerModuleTool(CommManagerModuleTool&);
            CommManagerModuleTool& operator=(CommManagerModuleTool&);
        };
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

    /*  Note: Get tool instance for CommManagerModule.  */
    IMVS_6000_PLATFORMSDK_API VisionMasterSDK::CommManagerModule::CommManagerModuleTool * __stdcall GetCommManagerToolInstance(void);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_COMMMANAGER_H_
