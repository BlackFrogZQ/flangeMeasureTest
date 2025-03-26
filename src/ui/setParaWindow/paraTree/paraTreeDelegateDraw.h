#include <QPainter>
#include <QDebug>
#include "para/define/paraDef.h"
using namespace TIGER_ParaDef;

int getIndentation(IParaNode *node)
{
    assert(node != nullptr);
    int indentation = -1;
    while (node != nullptr && (node != (IParaNode *)paraRootNode()) && (indentation < cExpandNum))
    {
        indentation++;
        node = node->m_parent;
    };
    return indentation;
}

IParaNode *nodeFromIndex(const QModelIndex &index)
{
    if (index.isValid())
    {
        return static_cast<IParaNode *>(index.internalPointer());
    }
    return NULL;
}

void drawBack(QPainter *painter, const QStyleOptionViewItem &option, const QRect &fillRect, CParaNodeType p_type, int p_col) // 根据事件画背景
{
    int x = option.rect.x();
    int y = option.rect.y();
    int width = option.rect.width();
    int height = option.rect.height();
    painter->fillRect(fillRect, QColor(255,255,255)); // 未选中
    QFont font = option.font;
    font.setBold(true);
    painter->setFont(font);

    if (option.state & QStyle::State_Selected)
    {
        painter->fillRect(fillRect, QColor(210, 220, 230)); // 选中
        painter->setPen(Qt::red);
        if (p_type != pntRoot)
        {
            assert(p_col == 1 || p_col == 0);
            if (p_col == 1)
            {
                painter->drawText(x + width - height, y, height, height, Qt::AlignCenter, "<");
            }
            else
            {
                painter->drawText(x, y, height, height, Qt::AlignCenter, ">");
            }
        }
        else if (p_col == 1)
        {
            painter->drawText(x + width - height, y, height, height, Qt::AlignCenter, "<");
        }
    }
    else if (option.state & QStyle::State_MouseOver)
    {
        painter->fillRect(fillRect, QColor(203, 217, 235)); // 鼠标移入
        assert(p_col == 1 || p_col == 0);
        painter->setPen(Qt::black);
        if (p_col == 1)
        {
            painter->drawText(x + width - height, y, height, height, Qt::AlignCenter, "<");
        }
        else if (p_type != pntRoot)
        {
            painter->drawText(x, y, height, height, Qt::AlignCenter, ">");
        }
    }

    if (p_type == pntRoot && p_col == 0)
    {
        painter->setPen(Qt::red);
        if (option.state & QStyle::State_Open)
        {
            painter->drawText(x, y, height, height, Qt::AlignCenter, "-");
        }
        else
        {
            painter->drawText(x, y, height, height, Qt::AlignCenter, "+");
        }
    }
}

void drawText(QPainter *painter, const QStyleOptionViewItem &option, const CParaNodeAttributes &attributes, const QModelIndex &index)
{
    int x = option.rect.x();
    int y = option.rect.y();
    int width = option.rect.width();
    int height = option.rect.height();

    QString text;
    if (index.column() == 0)
    {
        text = attributes.cnName;
    }
    else
    {
        switch (attributes.type)
        {
        case pntBool:
        {
            QPixmap pix = QPixmap(index.data().toBool() ? cBoolOpenIco : cBoolCloseIco).scaled(width, height, Qt::KeepAspectRatio);
            painter->drawPixmap(x + (width - pix.width()) / 2, y + (height - pix.height()) / 2, pix.width(), pix.height(), pix);
            return;
        }
        case pntEnum:
            text = attributes.remark.split("*")[index.data().toUInt()];
            break;
        case pntDouble:
            text = dToStr(index.data().toDouble(), cDoubleDecimals);
            break;
        default:
            if (attributes.type != pntRoot)
            {
                text = index.data().toString();
            }
            break;
        }
    }
    if (!text.isEmpty())
    {
        QFont font = option.font;
        QColor textColor = Qt::black;
        if (option.state & QStyle::State_Selected)
        {
            font.setBold(true);
            textColor = QColor(Qt::black);
        }
        else if (option.state & QStyle::State_MouseOver)
        {
            font.setBold(true);
            textColor = QColor(255, 0, 128);
        }
        painter->setPen(textColor);
        painter->setFont(font);
        if (index.column() == 0)
        {
            painter->drawText(x + height, y, width - height, height, (attributes.type != pntRoot ? Qt::AlignHCenter : Qt::AlignLeft) | Qt::AlignVCenter, text);
        }
        else
        {
            painter->drawText(x, y, width, height, (attributes.type != pntRoot ? Qt::AlignHCenter : Qt::AlignLeft) | Qt::AlignVCenter, text);
        }
    }
}

void drawGrid(QPainter *painter, const QStyleOptionViewItem &option, const CParaNodeType &p_type, int p_col)
{
    int x = option.rect.x();
    int y = option.rect.y();
    int width = option.rect.width();
    int height = option.rect.height();
    painter->setPen(Qt::darkGray);
    painter->drawLine(x, y + height - 1, x + width, y + height - 1);
    if (p_type != pntRoot && p_col == 0)
    {
        painter->drawLine(x + width, y, x + width, y + height - 1);
    }
}