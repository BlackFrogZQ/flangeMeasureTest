/***************************************************************************************************
 *
 * 版权信息：版权所有 (c) 2020, 保留所有权利
 *
 * 文件名称： VMException.h
 * 摘    要: VM异常类声明
 *
 * 当前版本：4.3.0
 * 日    期：2020-11-04
 * 备    注：新建
 ****************************************************************************************************/
#ifndef VM_EXCEPTION_H__ // 2020-11-04
#define VM_EXCEPTION_H__

#pragma warning(disable:4819)
#include "MVD_ErrorDefine.h"
#include "ErrorCodeDefine.h"
#include "iMVS-6000PlatformSDKC.h"
#include "iMVS-6000PlatformSDKC_IN.h"
#include "iMVS-6000PlatformSDKC_Obj.h"
#include <iostream>
using std::string;

namespace VisionMasterSDK
{
    /** @class CVmException
    *  @brief
    */
    class CVmException
    {
    public:
        /** @fn     CVmException
         *  @brief  构造函数,初始化成员变量
         *  @param  nErrCode  错误码
         *  @param  strErrDes 错误信息
         *  @return 无
         */
        CVmException(int nErrCode, const char * const strErrDes)
        {
            m_nErrorCode = nErrCode;
            if (NULL == strErrDes)
            {
                memset(m_strErrDescription, 0, 1024);
            }
            else
            {
                _snprintf_s(m_strErrDescription, 1024, 1023, "%s", strErrDes);
            }
        }

        /** @fn     CVmException
         *  @brief  构造函数,初始化成员变量
         *  @param  nErrCode 错误码
         *  @return 无
         */
        CVmException(int nErrCode)
        {
            m_nErrorCode = nErrCode;
            _snprintf_s(m_strErrDescription, 1024, 1023, "%s", GetErrorMsg(nErrCode));
        }

        /** @fn     virtual ~CVmException();
         *  @brief  析构函数,销毁成员变量
         *  @param  无
         *  @return 无
         */
        virtual ~CVmException() {}

    public:
        virtual const int GetErrorCode(void) const throw()
        {
            return m_nErrorCode;
        }

        virtual const char * GetDescription(void) const throw()
        {
            return m_strErrDescription;
        }

    private:
        /** @fn     CVmException();
         *  @brief  构造函数,初始化成员变量
         *  @param  void
         *  @return 无
         */
        explicit CVmException()
        {
            m_nErrorCode = IMVS_EC_UNKNOWN;
            memset(m_strErrDescription, 0, 1024);
        }

        /** @fn     GetErrorMsg
         *  @brief  获取错误信息
         *  @param  nErrCode 错误码
         *  @return 错误信息
         */
        const char * GetErrorMsg(int nErrCode)
        {
            return IMVS_PF_GetErrorMsg(nErrCode);
        }

    private:
        char m_strErrDescription[1024];
        int  m_nErrorCode;
    };
}

#endif // VM_EXCEPTION_H__