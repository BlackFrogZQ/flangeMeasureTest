#include "HIK3DMVSDef.h"

namespace TIGER_HIKROBOT3DCamera
{
    CHIK3DCameraSetParas *HIKCameraSetPara()
    {
        static CHIK3DCameraSetParas g_HIK3DCameraSetPara;
        return &g_HIK3DCameraSetPara;
    }
}