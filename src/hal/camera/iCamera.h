#pragma once
#include <QObject>
#include <QImage>
#include <QMetaMethod>
#include "iCameraDef.h"
namespace TIGER_Camera
{
    class ICamera : public QObject
    {
        Q_OBJECT
    public:
        virtual ~ICamera(){};

    public slots:
        virtual void init(CCameraPara paras) = 0;
        // virtual void setIp(const QString &p_ip) = 0;
        // virtual void setGainRaw(const double &p_gainRaw) = 0;
        // virtual void setGamma(const double &p_gamma) = 0;
        // virtual void setExposureTime(const double &p_time) = 0;
        // virtual bool singleFrame() = 0;
        // virtual bool setAcquire(bool isAcquire) = 0;
        // virtual void setReverse(bool reverseX, bool reverseY) = 0;
        // virtual void setSwapXY(bool swapXY) = 0;
        // virtual void setHeartbeatTime(int heartbeatTime) = 0;

    signals:
        // void sigStateChanged();
        // void sigParaChanged();
        void sigUpdateImage(QImage p_image);
        void sigError(QString p_error);

    protected:
        // CCameraStateInfo m_stateInfo;
        CCameraPara m_paraInfo;
        QString m_error;
    };
}
