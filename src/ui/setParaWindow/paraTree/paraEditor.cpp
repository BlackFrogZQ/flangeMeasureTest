#include "paraEditor.h"
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QComboBox>
using namespace TIGER_ParaDef;
CParaEditor::CParaEditor(QWidget *parent, const TIGER_ParaDef::CParaNodeAttributes &p_nodeAttributes, const int &w, const int &h) : QWidget(parent), editor(nullptr)
{
    this->type = p_nodeAttributes.type;
#define _NewEditor(QWidgetName)                       \
    this->editor = new QWidgetName(this);             \
    this->editor->setStyleSheet("color:rgb(0,0,0);"); \
    QWidgetName *pEditor = (QWidgetName *)this->editor
    switch (this->type)
    {
    case pntRoot:
        break;
    case pntDouble:
    {
        _NewEditor(QDoubleSpinBox);
        pEditor->setMaximum(INT32_MAX);
        pEditor->setMinimum(INT32_MIN);
        pEditor->setDecimals(cDoubleDecimals);
        pEditor->setAlignment(Qt::AlignCenter);
        connect(pEditor, &QDoubleSpinBox::editingFinished, this, &CParaEditor::editingFinished);
    }
    break;
    case pntBool:
    {
        _NewEditor(QRadioButton);
        connect(pEditor, &QRadioButton::clicked, this, &CParaEditor::editingFinished);
        pEditor->setCheckable(true);
        pEditor->setStyleSheet(
            QString("QRadioButton::indicator{width:%1px;height:%2px;}"
                    "QRadioButton::indicator:unchecked{image: url(%3);}"
                    "QRadioButton::indicator:checked {image: url(%4);}")
                .arg(w)
                .arg(h)
                .arg(cBoolCloseIco)
                .arg(cBoolOpenIco));
    }
    break;
    case pntEnum:
    {
        _NewEditor(QComboBox);
        pEditor->addItems(p_nodeAttributes.remark.split("*"));
        connect(pEditor, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &CParaEditor::editingFinished);
    }
    break;
    case pntInt:
    {
        _NewEditor(QSpinBox);
        connect(pEditor, &QSpinBox::editingFinished, this, &CParaEditor::editingFinished);
        pEditor->setAlignment(Qt::AlignCenter);
        pEditor->setSingleStep(1);
        pEditor->setMaximum(0x7FFFFFFF);
    }
    break;
    case pntString:
    {
        _NewEditor(QLineEdit);
        pEditor->setAlignment(Qt::AlignCenter);
        connect(pEditor, &QLineEdit::editingFinished, this, &CParaEditor::editingFinished);
    }
    break;
    case pntUInt:
    {
        _NewEditor(QSpinBox);
        pEditor->setAlignment(Qt::AlignCenter);
        connect(pEditor, &QSpinBox::editingFinished, this, &CParaEditor::editingFinished);
        pEditor->setMaximum(0x7FFFFFFF);
        pEditor->setMinimum(0);
        pEditor->setSingleStep(1);
    }
    break;
    default:
        assert(false);
    }
#undef newEditor

    this->setFixedSize(w, h);
    this->editor->setFixedSize(w, h);
    this->setStyle(this->editor->style());
}

CParaEditor::~CParaEditor()
{
}

void CParaEditor::setValue(QVariant p_value)
{
#define _Editor(QWidgetName) QWidgetName *pEditor = (QWidgetName *)this->editor

    switch (this->type)
    {
    case pntRoot:
        break;
    case pntDouble:
    {
        _Editor(QDoubleSpinBox);
        pEditor->setValue(p_value.toDouble());
    }
    break;
    case pntBool:
    {
        _Editor(QRadioButton);
        pEditor->setChecked(p_value.toBool());
    }
    break;
    case pntEnum:
    {
        _Editor(QComboBox);
        pEditor->setCurrentIndex(p_value.toUInt());
    }
    break;
    case pntInt:
    {
        _Editor(QSpinBox);
        pEditor->setValue(p_value.toInt());
    }
    break;
    case pntString:
    {
        _Editor(QLineEdit);
        pEditor->setText(p_value.toString());
    }
    break;
    case pntUInt:
    {
        _Editor(QSpinBox);
        pEditor->setValue(p_value.toInt());
    }
    break;
    default:
        assert(false);
    }
#undef _Editor
}

QVariant CParaEditor::value()
{
#define _Editor(QWidgetName) QWidgetName *pEditor = (QWidgetName *)this->editor

    switch (this->type)
    {
    case pntRoot:
        break;
    case pntDouble:
    {
        _Editor(QDoubleSpinBox);
        return pEditor->value();
    }
    case pntBool:
    {
        _Editor(QRadioButton);
        return pEditor->isChecked();
    }
    case pntEnum:
    {
        _Editor(QComboBox);
        return pEditor->currentIndex();
    }
    case pntInt:
    {
        _Editor(QSpinBox);
        return pEditor->value();
    }
    case pntString:
    {
        _Editor(QLineEdit);
        return pEditor->text();
    }
    break;
    case pntUInt:
    {
        _Editor(QSpinBox);
        return pEditor->value();
    }
    default:
        assert(false);
    }
#undef _Editor
    return QVariant();
}

void CParaEditor::mouseDoubleClickEvent(QMouseEvent *event)
{
    this->editor->setFocus();
}

void CParaEditor::wheelEvent(QWheelEvent *event)
{
}