#include "iCameraDef.h"

namespace TIGER_Camera
{
    CCameraParas *cameraParas()
    {
        static CCameraParas g_cameraParas;
        return &g_cameraParas;
    };

    CCameraAndImageType *cameraType()
    {
        static CCameraAndImageType g_cameraType;
        return &g_cameraType;
    };
}