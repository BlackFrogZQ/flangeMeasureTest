#include "cameraControl.h"
#include "iCamera.h"
#include <QThread>
#include <QMutex>

namespace TIGER_Camera
{
    CCameraControl::CCameraControl() : QObject(nullptr), m_pCameraThread(nullptr), m_pCamera(nullptr), m_cameraPara()
    {
    }

    CCameraControl::~CCameraControl()
    {

    }

    void CCameraControl::attachCamera(ICamera *p_camera, CCameraPara paras)
    {
        QWriteLocker locker(&m_rwLock);
        assert(p_camera != nullptr);

        m_cameraPara = paras;

        m_pCameraThread = new QThread;
        m_pCamera = p_camera;
        m_pCamera->moveToThread(m_pCameraThread);

        connect(m_pCameraThread, &QThread::started, m_pCamera, [pCamera = m_pCamera, paras]()
        {
            pCamera->init(paras);
        }, Qt::QueuedConnection);

        m_pCameraThread->start();
    }

    void CCameraControl::detachCamera()
    {

    }
}