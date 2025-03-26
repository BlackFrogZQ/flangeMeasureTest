#pragma once
#include <QInputDialog>

struct CInputDoublePara
{
    QString label;
    double defValue;
    double minValue;
    double maxValue;
    double step;
    int decimals;
    CInputDoublePara(const QString &p_label,
                     double p_defValue = 0, double p_minValue = -2147483647, double p_maxValue = 2147483647,
                     double p_step = 1, int p_decimals = 3)
        : label(p_label),
          defValue(p_defValue), minValue(p_minValue), maxValue(p_maxValue),
          step(p_step), decimals(p_decimals){};
};

class CInputDialog : public QInputDialog
{
    Q_OBJECT
public:
    CInputDialog(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ~CInputDialog();

    static QString getText(const QString &title, const QString &label,
                           QLineEdit::EchoMode echo = QLineEdit::Normal,
                           const QString &text = QString(), QWidget *parent = nullptr);

    static bool getText(QString &text, const QString &title, const QString &label,
                        QLineEdit::EchoMode echo = QLineEdit::Normal, QWidget *parent = nullptr);

    static bool getInt(int &value, const QString &title, const QString &label,
                       int defValue = 0, int minValue = -2147483647, int maxValue = 2147483647, int step = 1, QWidget *parent = nullptr);

    static bool getDouble(double &value, const QString &title, const QString &label,
                          double defValue = 0, double minValue = -2147483647, double maxValue = 2147483647, double step = 1, int decimals = 3, QWidget *parent = nullptr);
    static bool getDouble(double &value, const QString &title, const CInputDoublePara &p_inputDoublePara, QWidget *parent = nullptr);
    static bool getDouble2(double &value1, const QString &title, const CInputDoublePara &p_inputDoublePara1, double &value2, const CInputDoublePara &p_inputDoublePara2, QWidget *parent = nullptr);
    static bool getItem(int &value, const QString &title,  const QString &label,const QStringList &items,int defValue = 0, QWidget *parent = nullptr);
};

class QDoubleSpinBox;
class CInputDouble2Dialog : public QDialog
{
    Q_OBJECT
public:
    CInputDouble2Dialog(const QString &title, const CInputDoublePara &p_inputDoublePara1, const CInputDoublePara &p_inputDoublePara2, QWidget *parent = nullptr);
    ~CInputDouble2Dialog();
    bool getValue(double &value1, double &value2);
signals:
    void sigValueChanged(double p_value1, double p_value2);

protected:
    QDoubleSpinBox *m_doubleSpinBox1;
    QDoubleSpinBox *m_doubleSpinBox2;
};
