#include "para\define\paraDef.h"
#include "paraNode.h"

namespace TIGER_ParaDef
{
    IParaNode *paraRootNode()
    {
        static CParaNode g_rootNode({pntRoot, cFirstRootNode,cFirstRootNode,true});
        return &g_rootNode;
    };

    IParaNode::IParaNode(const CParaNodeAttributes &p_attributes)
        : m_attributes(p_attributes), m_parent(nullptr)
    {
    }

    IParaNode::~IParaNode()
    {
        m_childrenNodes.clear();
    }

    void IParaNode::release()
    {
        for (auto pNode : m_childrenNodes)
        {
            pNode->release();
            delPtr(pNode);
        }
        m_childrenNodes.clear();
    }
    QList<IParaNode *> IParaNode::getChildrenNodes() const
    {
        return m_childrenNodes;
    }

    int IParaNode::findChildNode(const QString &p_name)
    {
        for (int i = 0; i < m_childrenNodes.size(); i++)
        {
            if (m_childrenNodes.at(i)->m_attributes.name == p_name)
            {
                return i;
            }
        }
        return -1;
    }

    int IParaNode::findNode(const QString &p_name, const CParaNodeType &p_type)
    {
        for (int i = 0; i < m_childrenNodes.size(); i++)
        {
            if (m_childrenNodes.at(i)->m_attributes.name == p_name && m_childrenNodes.at(i)->m_attributes.type == p_type)
            {
                return i;
            }
        }
        return -1;
    }

    void IParaNode::appendChildren(IParaNode *p_children)
    {
        p_children->m_parent = this;
        m_childrenNodes << p_children;
    }
}