#pragma once
#include "system/basic.h"

namespace TIGER_ProcessTool
{
    class IProcessToolFun
    {
    public:
        virtual ~IProcessToolFun(){};
        virtual void init() = 0;
        QString getErrorMsg() const { return m_error; };

    protected:
        QString m_error;
    };
};