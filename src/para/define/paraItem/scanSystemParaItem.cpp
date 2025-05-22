#include "scanSystemParaItem.h"
#include "hal/camera/iCameraDef.h"
#include "../paraNode.h"

using namespace TIGER_ParaDef;
using namespace TIGER_Camera;

namespace TIGER_ParaItemDef
{
    class CHikCameraPara : public IParaItem
    {
    public:
        CHikCameraPara() : IParaItem(cnStr("cameraParas"), cnStr("相机参数"), true)
        {
            for (size_t i = 0; i < Camera_Sum; i++)
            {
                auto &cameraPara = cameraParas()->cameraPara[i];
                CParaNode *node = nullptr;
                _AddRootNode2(m_currentNode, cnStr("camera%1paras").arg(i + 1), cnStr("相机%1参数").arg(i + 1), true, "");
                _AddNode(node, pntString, "ip", "ip", true, "ip", &cameraPara.ip);
                _AddNode(node, pntInt, "runSpeed", "运行速度", true, "mm/s", &cameraPara.runnSpeed);
                _AddNode(node, pntInt, "strokeLength", "行程长度", true, "mm/s", &cameraPara.strokeLength);
                _AddNode(node, pntInt, "xSinglePixelAccuracy", "X方向单像素精度", true, "um/pixel", &cameraPara.xSinglePixelAccuracy);
                _AddNode(node, pntInt, "ySinglePixelAccuracy", "y方向单像素精度", true, "um/pixel", &cameraPara.ySinglePixelAccuracy);
            }
        };
    };
    IParaItem *HikCameraParaItem()
    {
        static CHikCameraPara g_HikCameraConnectParasNode;
        return &g_HikCameraConnectParasNode;
    }

    class CCameraAndImageParas : public IParaItem
    {
    public:
        CCameraAndImageParas() : IParaItem(cnStr("cameraAndImageType"), cnStr("相机及采图类型"), true)
        {
            CParaNode *node = nullptr;
            _AddNode(m_currentNode, pntEnum, "useCameraType", "使用相机类型", true, "Virtual*Hik3DVision", &cameraType()->useCameraType);
            _AddNode(m_currentNode, pntEnum, "saveImageType", "保存图片类型", true, "TIFF*BMP*RAW", &cameraType()->saveImageType);
        };
    };
    IParaItem *CameraAndImageTypeItem()
    {
        static CCameraAndImageParas g_CameraAndImageTypeNode;
        return &g_CameraAndImageTypeNode;
    }
}