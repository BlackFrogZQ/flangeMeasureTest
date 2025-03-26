#pragma once
#include "system/basic.h"
enum CUserType : uint8_t
{
    cutAdministrators,
    cutOperator,
    cutUndefine
};
#define cUserTypeStr (QStringList() << cnStr("管理员") << cnStr("操作员") << cnStr("未登录"))