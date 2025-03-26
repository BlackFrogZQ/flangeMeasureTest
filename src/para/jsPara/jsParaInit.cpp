#include "../define/paraItem/scanSystemParaItem.h"
#include "../define/paraNode.h"
#include "../para.h"

namespace TIGER_ParaDef
{
    using namespace TIGER_ParaItemDef;
    void initParaRootNode()
    {
        paraRootNode()->appendChildren(DZSTMarkParaItem()->currentNode());
        paraRootNode()->appendChildren(scanSystemParaItem()->currentNode());
        paraRootNode()->appendChildren(laserParasItem()->currentNode());
        paraService()->setFileName(cnStr("Paras.xml"));
    }
}