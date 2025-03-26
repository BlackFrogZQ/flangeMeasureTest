#include "paraNode.h"
#include <QDebug>
namespace TIGER_ParaDef
{

    QString getNodePathName(IParaNode *p_node)
    {
        QString path;
        while (p_node != paraRootNode())
        {
            path = p_node->m_attributes.name + "*" + path;
            p_node = p_node->m_parent;
        }
        return path.left(path.size() - 1);
    }

    CParaNode::CParaNode(const CParaNodeAttributes &p_attributes, void *p_pValue)
        : IParaNode(p_attributes),
          m_value(p_pValue)
    {
    }

    CParaNode::~CParaNode()
    {
    }

    void CParaNode::setValuePtr(void *p_pValue)
    {
        assert(p_pValue != nullptr);
        m_value = p_pValue;
    }

    void *CParaNode::getValuePtr() const
    {
        return m_value;
    }

    void CParaNode::setVisible(bool p_visible)
    {
        m_attributes.visible = p_visible;
    }

    IParaNode *CParaNode::copyNode(bool p_onlyVisible)
    {
        CParaNode *node = nullptr;
        if (p_onlyVisible && (!m_attributes.visible))
        {
            return node;
        }

        node = new CParaNode(m_attributes, m_value);
        for (auto childrenNode : m_childrenNodes)
        {
            IParaNode *childrenCopy = nullptr;
            childrenCopy = childrenNode->copyNode(p_onlyVisible);
            if (childrenCopy != nullptr)
            {
                if (childrenCopy->m_attributes.type != pntRoot || childrenCopy->getChildrenNodes().size() > 0)
                {
                    node->appendChildren(childrenCopy);
                }
                else
                {
                    delete node;
                    node = nullptr;
                }
            }
        }
        return node;
    }

    CParaNode *CParaNode::appendRootNode(const CParaNodeAttributes &p_attributes)
    {
        assert(p_attributes.type == pntRoot);
        int id = findNode(p_attributes.name, pntRoot);
        if (id >= 0)
        {
            return static_cast<CParaNode *>(m_childrenNodes[id]);
        }
        auto pNode = new CParaNode(p_attributes, NULL);
        appendChildren(pNode);
        return pNode;
    }

    void CParaNode::appendNode(const CParaNodeAttributes &p_attributes, void *p_pValue)
    {
        int id = findNode(p_attributes.name, p_attributes.type);
        if (id >= 0)
        {
            myDebug << cnStr("发现相同子节点->名:%1,类型%2").arg(getNodePathName(m_childrenNodes.at(id))).arg(p_attributes.type);
            return;
        }
        appendChildren(new CParaNode(p_attributes, p_pValue));
    }

    void CParaNode::setValue(QVariant p_value)
    {
        switch (this->m_attributes.type)
        {
        case pntRoot:
            break;
        case pntDouble:
            *((double *)this->m_value) = p_value.toDouble();
            break;
        case pntBool:
            *((bool *)this->m_value) = p_value.toBool();
            break;
        case pntEnum:
            if (p_value.toUInt() >= m_attributes.remark.split("*").size())
            {
                myTrace(cnStr("枚举参数值超过备注项数：name:'%1', cnName: '%2', value:'%3', remark:'%4'").arg(getNodePathName(this)).arg(m_attributes.cnName).arg(p_value.toUInt()).arg(m_attributes.remark));
                *((uint *)this->m_value) = 0;
                break;
            }
            *((int *)this->m_value) = p_value.toUInt();
            break;
        case pntInt:
            *((int *)this->m_value) = p_value.toDouble();
            break;
        case pntString:
            *((QString *)this->m_value) = p_value.toString();
            break;
        case pntUInt:
            *((uint *)this->m_value) = p_value.toUInt();
            break;
        default:
            assert(false);
        }
    }

    QVariant CParaNode::getValue() const
    {
        switch (this->m_attributes.type)
        {
        case pntRoot:
            break;
        case pntDouble:
            return *((double *)this->m_value);
        case pntBool:
            return *((bool *)this->m_value);
        case pntEnum:
            return *((uint *)this->m_value);
        case pntInt:
            return *((int *)this->m_value);
        case pntString:
            return *((QString *)this->m_value);
        case pntUInt:
            return *((uint *)this->m_value);
        default:
            assert(false);
        }
        return QVariant("");
    };
};