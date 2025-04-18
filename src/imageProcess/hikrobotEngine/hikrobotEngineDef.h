#pragma once
#include "system/basic.h"

enum CCOMObject : int32_t
{
    ccoVmFrontendControlWinform = 0,
    ccoVmVmGlobalToolWinform,
    ccoVmVmMainViewControlWinform,
    ccoVmParamsControlWinform,
    ccoVmVmParamsRenderControlWinform,
    ccoVmProcedureControlWinform,
    ccoVmVmRealTimeAcqControlWinform,
    ccoVmRenderControlWinform,
    ccoVmVmSingleModulesetControlWinform,
    ccoMax
};

const QStringList cCOMObjectName = {"VmFrontendControlWinform.VmUserControl", "VmGlobalToolWinform.VmUserControl", "VmMainViewControlWinform.VmUserControl", "VmParamsControlWinform.VmUserControl", "VmParamsRenderControlWinform.VmUserControl", "VmProcedureControlWinform.VmUserControl", "VmRealTimeAcqControlWinform.VmUserControl", "VmRenderControlWinform.VmUserControl", "VmSingleModulesetControlWinform.VmUserControl"};
#define cCOMObjectCnName (QStringList() << QObject::tr("前端配置") << QObject::tr("全局工具") << QObject::tr("主视图配置") << QObject::tr("参数配置") << QObject::tr("参数渲染") << QObject::tr("流程配置") << QObject::tr("实时采集") << QObject::tr("图像渲染") << QObject::tr("单模块配置"))