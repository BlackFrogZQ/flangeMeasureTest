#include "../define/paraItem/scanSystemParaItem.h"
#include "../define/paraNode.h"
#include "../para.h"

namespace TIGER_ParaDef
{
    using namespace TIGER_ParaItemDef;
    void initParaRootNode()
    {
        paraRootNode()->appendChildren(HikCameraParaItem()->currentNode());
        paraRootNode()->appendChildren(CameraAndImageTypeItem()->currentNode());
        paraService()->setFileName(cnStr("Paras.xml"));
    }
}