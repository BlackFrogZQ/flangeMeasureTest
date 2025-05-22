#pragma once
#include "iCameraDef.h"
#include <QObject>
#include <QReadWriteLock>

class QThread;

namespace TIGER_Camera
{
    class ICamera;
    class CCameraControl : public QObject
    {
        friend class CCameraCreator;
        Q_OBJECT
    public:
        CCameraControl();
        ~CCameraControl();

    protected:
        void attachCamera(ICamera *p_camera, CCameraPara paras);
        void detachCamera();

    protected:
        QThread *m_pCameraThread;
        mutable QReadWriteLock m_rwLock;

        ICamera *m_pCamera;
        CCameraPara m_cameraPara;
    };
}

TIGER_Camera::CCameraControl *cameraControl(TIGER_Camera::CMatrixCameraId id = TIGER_Camera::cmciCamera1);