#include "nodeItemDef.h"
#include "../paraNode.h"
namespace TIGER_ParaItemDef
{
    using namespace TIGER_ParaDef;
    IParaItem::IParaItem(const QString &p_name, const QString &p_cnName, const bool &p_visible, const QString &p_remark) : m_currentNode(nullptr)
    {
        m_currentNode = new CParaNode({pntRoot, p_name, p_cnName, p_visible, p_remark}, nullptr);
    }

    IParaItem::~IParaItem()
    {
        m_currentNode->release();
        delete m_currentNode;
        m_currentNode = nullptr;
    }

    CParaNode *IParaItem::currentNode() const
    {
        return m_currentNode;
    }
};