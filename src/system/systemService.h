#pragma once
#include "./basic.h"

class ISystemService
{
    friend void closeSystemService();

public:
    virtual void printMsg(QString p_msg) = 0;
    virtual void restartSys() const = 0;
    // virtual void restartCamera(TIGER_Camera::CMatrixCameraId id = TIGER_Camera::visionCamera) = 0;
    virtual void updateParas() = 0;
    virtual void load() = 0;
    virtual void save() = 0;

protected:
    virtual ~ISystemService(){};
};
ISystemService *sys();