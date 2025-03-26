#include "paraModel.h"
#include "para/define/paraDef.h"
#include <QDebug>
#include <QToolTip>
#include <QTreeView>
using namespace TIGER_ParaDef;
CParaTreeModel::CParaTreeModel(QObject *parent)
    : QAbstractItemModel(parent),
      m_rootNode(nullptr)
{
}

CParaTreeModel::~CParaTreeModel()
{
    releaseParaNode();
}

void CParaTreeModel::releaseParaNode()
{
    if (m_rootNode != nullptr)
    {
        m_rootNode->release();
        delete m_rootNode;
        m_rootNode = nullptr;
    }
}

void CParaTreeModel::sepntRootNode(IParaNode *node)
{
    assert(node != nullptr);
    releaseParaNode();
    beginResetModel();
    m_rootNode = node;
    endResetModel();
}

Qt::ItemFlags CParaTreeModel::flags(const QModelIndex &index) const
{
    IParaNode *node = nodeFromIndex(index);
    return ((node->m_attributes.type == pntRoot) || index.column() == 0) ? QAbstractItemModel::flags(index) : QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QModelIndex CParaTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!m_rootNode || row < 0 || column < 0)
    {
        return QModelIndex();
    }
    IParaNode *parentNode = nodeFromIndex(parent);
    IParaNode *childNode = parentNode->getChildrenNodes().value(row);
    if (!childNode)
    {
        return QModelIndex();
    }
    return createIndex(row, column, childNode);
}

IParaNode *CParaTreeModel::nodeFromIndex(const QModelIndex &index) const
{
    if (index.isValid())
    {
        return static_cast<IParaNode *>(index.internalPointer());
    }
    else
    {
        return m_rootNode;
    }
}

int CParaTreeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0)
    {
        return 0;
    }
    IParaNode *parentNode = nodeFromIndex(parent);
    if (!parentNode)
    {
        return 0;
    }
    return parentNode->getChildrenNodes().size();
}

int CParaTreeModel::columnCount(const QModelIndex & /* parent */) const
{
    return 2;
}

QModelIndex CParaTreeModel::parent(const QModelIndex &child) const
{
    IParaNode *node = nodeFromIndex(child);
    if (!node)
    {
        return QModelIndex();
    }
    IParaNode *parentNode = node->m_parent;
    if (!parentNode)
    {
        return QModelIndex();
    }
    IParaNode *grandparentNode = parentNode->m_parent;
    if (!grandparentNode)
    {
        return QModelIndex();
    }
    int row = grandparentNode->getChildrenNodes().indexOf(parentNode);
    return createIndex(row, 0, parentNode);
}

QVariant CParaTreeModel::data(const QModelIndex &index, int role) const
{
    IParaNode *node = nodeFromIndex(index);
    if (!node)
    {
        return QVariant();
    }
    switch (role)
    {
    case Qt::ToolTipRole:
    {
        QAbstractItemView *view = static_cast<QAbstractItemView *>(QAbstractItemModel::parent());
        QToolTip::showText(QCursor::pos() + QPoint(0, -2 * view->sizeHintForRow(0)), node->m_attributes.remark);
    }
    break;
    case Qt::DisplayRole:
    {
        if (index.column() == 0)
        {
            return node->m_attributes.cnName;
        }
        else if (index.column() == 1)
        {
            return node->getValue();
        }
    }
    break;
    default:
        break;
    }
    return QVariant();
}

bool CParaTreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    { // 编辑完成,保存数据到model,并返回true
        nodeFromIndex(index)->setValue(value);
        emit dataChanged(index, index); // 重新实现setData()函数时，必须显式发出该信号。
        return true;
    }
    return false;
}

QVariant CParaTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        if (section == 0)
        {
            return QObject::tr("变量名称");
        }
        else if (section == 1)
        {
            return QObject::tr("变量值");
        }
    }
    return QVariant();
}