#include "inputDialog.h"
#include "../basic.h"
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>
const QString cStyle =
    "QLineEdit{border:2px solid;padding:4px;padding-left:10px;border-radius:3px;color:rgb(105,105,105);font:11pt \"Microsoft YaHei\";}"
    "QLineEdit:focus{border:2px solid rgb(208,208,208);}"
    "QLineEdit:disabled{background-color:rgb(238,238,238);}"
    "QLabel{color:rgb(85,85,85); font:11pt \"Microsoft YaHei\"; font-weight:bold;}"
    "QInputDialog{background-color:rgb(235,244,255); }";
CInputDialog::CInputDialog(QWidget *parent, Qt::WindowFlags flags) : QInputDialog(parent, flags)
{
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    setWindowFlag(Qt::WindowCloseButtonHint, false);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint, true);
    setWindowFlag(Qt::WindowStaysOnTopHint, CUiBasic::isTop);
    this->setMinimumWidth(420);
    setStyleSheet(cStyle);
}

CInputDialog::~CInputDialog()
{
}

QString CInputDialog::getText(const QString &title, const QString &label,
                              QLineEdit::EchoMode echo,
                              const QString &text, QWidget *parent)
{
    CInputDialog dialog(parent);
    dialog.setWindowTitle(title);
    dialog.setInputMode(QInputDialog::InputMode::TextInput);
    dialog.setTextEchoMode(echo);
    dialog.setLabelText(label);
    dialog.setTextValue(text);
    QString msg;
    if (dialog.exec())
    {
        msg = dialog.textValue();
    }
    return msg;
}

bool CInputDialog::getText(QString &text, const QString &title, const QString &label,
                           QLineEdit::EchoMode echo, QWidget *parent)
{
    QString str = getText(title, label, echo, text, parent);
    bool changed = (str != text);
    if (changed)
    {
        text = str;
    }
    return changed;
}

bool CInputDialog::getInt(int &value, const QString &title, const QString &label,
                          int defValue, int minValue, int maxValue, int step, QWidget *parent)
{
    CInputDialog dialog(parent);
    dialog.setWindowTitle(title);
    dialog.setInputMode(QInputDialog::InputMode::IntInput);
    dialog.setIntRange(minValue, maxValue);
    dialog.setIntStep(step);
    dialog.setLabelText(label);
    dialog.setIntValue(defValue);
    bool ok = dialog.exec();
    if (ok)
    {
        value = dialog.intValue();
    }
    return ok;
}

bool CInputDialog::getDouble(double &value, const QString &title, const QString &label,
                             double defValue, double minValue, double maxValue, double step, int decimals, QWidget *parent)
{
    CInputDialog dialog(parent);
    dialog.setWindowTitle(title);
    dialog.setInputMode(QInputDialog::InputMode::DoubleInput);
    dialog.setDoubleRange(minValue, maxValue);
    dialog.setDoubleStep(step);
    dialog.setLabelText(label);
    dialog.setDoubleValue(defValue);
    dialog.setDoubleDecimals(decimals);
    bool ok = dialog.exec();
    if (ok)
    {
        value = dialog.doubleValue();
    }
    return ok;
}

bool CInputDialog::getDouble(double &value, const QString &title, const CInputDoublePara &p_inputDoublePara, QWidget *parent)
{
    return getDouble(value,
                     title, p_inputDoublePara.label,
                     p_inputDoublePara.defValue, p_inputDoublePara.minValue, p_inputDoublePara.maxValue,
                     p_inputDoublePara.step, p_inputDoublePara.decimals, parent);
}

bool CInputDialog::getDouble2(double &value1, const QString &title, const CInputDoublePara &p_inputDoublePara1, double &value2, const CInputDoublePara &p_inputDoublePara2, QWidget *parent)
{
    CInputDouble2Dialog dialog(title, p_inputDoublePara1, p_inputDoublePara2, parent);
    return dialog.getValue(value1, value2);
}

bool CInputDialog::getItem(int &value, const QString &title, const QString &label, const QStringList &items, int defValue, QWidget *parent)
{
    CInputDialog dialog(parent);
    dialog.setWindowTitle(title);
    dialog.setComboBoxItems(items);
    dialog.setComboBoxEditable(false);
    dialog.setLabelText(label);
    dialog.setTextValue(items[defValue]);
    bool ok = dialog.exec();
    if (ok)
    {
        value = items.indexOf(dialog.textValue());
    }
    return ok;
}

CInputDouble2Dialog::CInputDouble2Dialog(const QString &title, const CInputDoublePara &p_inputDoublePara1, const CInputDoublePara &p_inputDoublePara2, QWidget *parent)
{
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    setWindowFlag(Qt::WindowCloseButtonHint, false);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint, true);
    setWindowFlag(Qt::WindowStaysOnTopHint, CUiBasic::isTop);
    setMinimumWidth(420);
    setStyleSheet(cStyle);
    auto getDoubleSpinBox = [this](const CInputDoublePara &p_inputDoublePara)
    {
        QDoubleSpinBox *spinbox1 = new QDoubleSpinBox(this);
        spinbox1->setRange(p_inputDoublePara.minValue, p_inputDoublePara.maxValue);
        spinbox1->setSingleStep(p_inputDoublePara.step);
        spinbox1->setDecimals(p_inputDoublePara.decimals);
        spinbox1->setValue(p_inputDoublePara.defValue);
        spinbox1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        return spinbox1;
    };

    QFormLayout *pFormLayout = new QFormLayout;
    pFormLayout->addRow(new QLabel(title));
    m_doubleSpinBox1 = getDoubleSpinBox(p_inputDoublePara1);
    m_doubleSpinBox2 = getDoubleSpinBox(p_inputDoublePara2);
    pFormLayout->addRow(p_inputDoublePara1.label, m_doubleSpinBox1);
    pFormLayout->addRow(p_inputDoublePara2.label, m_doubleSpinBox2);
    QDialogButtonBox *pButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                                        Qt::Horizontal);
    pFormLayout->addRow(pButtonBox);
    QObject::connect(pButtonBox, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(pButtonBox, SIGNAL(rejected()), this, SLOT(reject()));
    QObject::connect(m_doubleSpinBox1, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, [this](double p_value1)
                     { emit sigValueChanged(p_value1, m_doubleSpinBox2->value()); });
    QObject::connect(m_doubleSpinBox2, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, [this](double p_value2)
                     { emit sigValueChanged(m_doubleSpinBox1->value(), p_value2); });
    setLayout(pFormLayout);
}

CInputDouble2Dialog::~CInputDouble2Dialog()
{
}

bool CInputDouble2Dialog::getValue(double &value1, double &value2)
{
    bool ok = this->exec();
    if (ok)
    {
        value1 = m_doubleSpinBox1->value();
        value2 = m_doubleSpinBox2->value();
    }
    return ok;
}
