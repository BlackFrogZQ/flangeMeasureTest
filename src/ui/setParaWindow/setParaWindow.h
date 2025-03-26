#pragma once
#include "ui/basic.h"
namespace TIGER_ParaDef
{
    class IParaNode;
}
class QTreeView;
class CParaTreeModel;
class CSetParaWindow : public TIGER_UIBasic::INoExcCancelDialog
{
    Q_OBJECT
public:
    CSetParaWindow(QWidget *parent = nullptr);
    ~CSetParaWindow();
    bool setShowNode(TIGER_ParaDef::IParaNode *p_node = nullptr);
    bool showRootNode();
    bool isSave();

protected:
    QTreeView *m_treeView;
    CParaTreeModel *m_pTreeModel;
    bool m_bIsSave;
};