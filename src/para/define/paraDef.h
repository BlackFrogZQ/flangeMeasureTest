#pragma once

/*
    参数自动持久化：
    1.在para\define文件夹里生成一个cpp文件
    2.重写其构造函数，在构造函数里面写保存的数据和对应的字段
    3.声明一个该类的静态变量
    4.把该cpp文件引用到cmakeLists.txt
    5.参看ncDef.h和ncDef.cpp
*/
#include "system/basic.h"
#include <QString>
#include <QVariant>

namespace TIGER_ParaDef
{
#define _AddRootNode(pNode, name, cnName, visible, remark) node = pNode->appendRootNode({pntRoot,cnStr(name), cnStr(cnName),visible, cnStr(remark)});
#define _AddRootNode2(pNode, name, cnName, visible, remark) node = pNode->appendRootNode({pntRoot,name, cnName,visible, remark});
#define _AddNode(pNode,type, name, cnName, visible, remark,ValuePtr)  pNode->appendNode({type,cnStr(name), cnStr(cnName),visible, cnStr(remark)},ValuePtr);
#define _AddNode2(pNode,type, name, cnName, visible, remark,ValuePtr)  pNode->appendNode({type,name, cnName,visible, remark},ValuePtr);

    enum CParaNodeType
    {
        pntDouble = 0,
        pntInt,
        pntUInt,
        pntString,
        pntBool,
        pntEnum,
        pntRoot,
        pntSum,
    };
    const QString cBoolCloseIco = ":/res/para/close.png";
    const QString cBoolOpenIco = ":/res/para/open.png";
    const QString cValueName = "value";
    const QString cCnName = "cnName";
    const QString cRemark = "remark";
    const QString cVisible = "visible";
    const QString cFirstRootNode = "ParameterRoot";

    const int cExpandNum = 3; // 设置界面展开级数
    const int cDoubleDecimals = 3; // 设置double精度
    struct CParaNodeAttributes
    {
        CParaNodeType type;
        QString name;
        QString cnName;
        bool visible;
        QString remark;
    };

    class IParaNode
    {
    public:
        IParaNode(const CParaNodeAttributes &p_attributes = {pntSum, "", cnStr("中文名"), false, "/"});
        virtual ~IParaNode();
        virtual void release();
        virtual void setValue(QVariant p_value) = 0;
        virtual QVariant getValue() const = 0;
        virtual IParaNode* copyNode(bool p_onlyVisible = true) = 0;
        QList<IParaNode *> getChildrenNodes() const;
        int findChildNode(const QString &p_name); // 发现当前节点的子节点,不进入下一层,返回id -1为未发现
        void appendChildren(IParaNode *p_children);
    public:
        CParaNodeAttributes m_attributes;
        IParaNode *m_parent;

    protected:
        int findNode(const QString &p_name, const CParaNodeType &p_type);

    protected:
        QList<IParaNode *> m_childrenNodes;
    };
    void initParaRootNode();
    IParaNode *paraRootNode();
};