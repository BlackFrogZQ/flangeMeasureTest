#include "cameraCreator.h"
#include "cameraControl.h"
#include "iCameraDef.h"
#include "system/basic.h"
#include "hik3DMVS/HIK3DMVS.h"

namespace TIGER_Camera
{
    CCameraControl *CCameraCreator::m_instance[maxCamera] = { nullptr };

    void CCameraCreator::createCamera(TIGER_Camera::CCameraType p_type, CMatrixCameraId id)
    {
        assert(id >= 0 && id < TIGER_Camera::maxCamera);
        ICamera *pCamera = nullptr;
        switch (p_type)
        {
        case TIGER_Camera::cctHik3DVision:
            pCamera = new TIGER_Camera::CHIK3DMVS();
            break;
        case TIGER_Camera::cctVirtual:
            // pCamera = new TIGER_Camera::CSoftCamera;
            break;
        default:
            break;
        }
        assert(pCamera != nullptr);

        TIGER_Camera::CCameraPara paras;
        if(m_instance[id] == nullptr)
        {
            m_instance[id] = new CCameraControl();
            auto setParas = TIGER_Camera::cameraParas()->cameraPara[id];
            paras.ip = setParas.ip;
            paras.runnSpeed = setParas.runnSpeed;
            paras.strokeLength = setParas.strokeLength;
            paras.xSinglePixelAccuracy = setParas.xSinglePixelAccuracy;
            paras.ySinglePixelAccuracy = setParas.ySinglePixelAccuracy;
        }
        else
        {
            myInfo << cnStr("相机类型错误");
        }

        m_instance[id]->attachCamera(pCamera, paras);
    }

    CCameraControl *CCameraCreator::cameraInstance(CMatrixCameraId id)
    {
        return m_instance[id];
    }
}

TIGER_Camera::CCameraControl *cameraControl(TIGER_Camera::CMatrixCameraId id)
{
    return TIGER_Camera::CCameraCreator::cameraInstance(id);
}