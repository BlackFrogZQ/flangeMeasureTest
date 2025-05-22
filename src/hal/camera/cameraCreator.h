#pragma once
#include "iCameraDef.h"
#include "iCamera.h"
#include <QString>
#include <QObject>

namespace TIGER_Camera
{
    class CCameraControl;
    class CCameraCreator
    {
    public:
        static void createCamera(TIGER_Camera::CCameraType p_type, CMatrixCameraId id = cmciCamera1);
        static CCameraControl *cameraInstance(CMatrixCameraId id = cmciCamera1);

    private:
        static CCameraControl *m_instance[maxCamera];
    };
};