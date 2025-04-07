/***************************************************************************************************
 *
 * 版权信息：版权所有 (c) 2021, 保留所有权利
 *
 * 文件名称： VmToolBase.h
 * 摘    要: VM工具基类
 *
 * 当前版本：4.3.0
 * 日    期：2021-12-29 19:24:30
 * 备    注：新建
 ****************************************************************************************************/
#ifndef CVMMODULE_TOOL_BASE_H__ // 2020-10-29 19:24:30
#define CVMMODULE_TOOL_BASE_H__

#pragma warning(disable:4819)
#include <memory>

namespace VisionMasterSDK
{
    /** @class CVmToolBase
     *  @brief 模块结果基类
     */
    class CVmToolBase
    {
    public:

        /** @fn     explicit CVmToolBase();
         *  @brief  构造函数,初始化成员变量
         *  @param  无
         *  @return 无
         */
        explicit CVmToolBase();

        /** @fn     virtual ~CVmToolBase();
         *  @brief  析构函数,销毁成员变量
         *  @param  无
         *  @return 无
         */
        virtual ~CVmToolBase();

    public:
        /** @fn     EnableResultCallback();
         *  @brief  使能上报模块结果，配合IVmSolution::DisableModulesCallback方法使用，当所有模块上报结果关闭后，根据需要开启某些工具的结果
         *  @param  无
         *  @return 类名
         */
        virtual void EnableResultCallback();

    protected:
        virtual unsigned int GetToolId() = 0; // 模块ID
    };
}

#endif // CVMMODULE_TOOL_BASE_H__
