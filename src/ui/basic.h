#pragma once
#include "system/basic.h"
#include <QDialog>
#include <QToolButton>
#include <QString>

class QTableWidgetItem;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;

namespace TIGER_UIBasic
{
    int warningBox(QWidget *parent, const QString &title, const QString &text);
    int questionBox(QWidget *parent, const QString &title, const QString &text);
    void showToolTip(QWidget *p_pWidget, const QString &p_tip);
    QPushButton *noKeyPushButton(QString p_name = "");
    QToolButton *getToolBtn(QWidget *p_pParent, QString text = "",int p_h = 30,  Qt::ToolButtonStyle p_toolBtnStyle = Qt::ToolButtonTextOnly);
    QTableWidgetItem *getTableWidgetItem(const QString &p_text, int p_textAlignment = Qt::AlignCenter);
    QHBoxLayout *getHLableLayout(QString p_lbName, QWidget *p_w, int p_h = 30);
    QVBoxLayout *getVLableLayout(QString p_lbName, QWidget *p_widget, int p_w = 0);
    QLabel *getLabel(QString p_name, int p_h = 35, Qt::Alignment p_aalignment = Qt::AlignVCenter | Qt::AlignRight);
    void deleteLayout(QLayout *p_layout);

    class IDialog : public QDialog
    {
    public:
        using QDialog::QDialog;

    protected:
        virtual void paintEvent(QPaintEvent *event) override;
    };

    class INoExcCancelDialog : public TIGER_UIBasic::IDialog
    {
    public:
        using IDialog::IDialog;

    protected:
        virtual void keyPressEvent(QKeyEvent *event) override;
        QMetaObject::Connection m_connect;
    };
};

class CUiBasic
{
public:
    static double getDefScale();
    static QPixmap getBackgroundImg();
    static double getScale();
    static void updateScale(int p_w, int p_h);
    static bool isTop;

protected:
    static void getScreen(int &p_w, int &p_h);
    static double stScale;
};