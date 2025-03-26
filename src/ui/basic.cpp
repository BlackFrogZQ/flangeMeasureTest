#include "basic.h"
#include "messageBox/messageBox.h"
#include <QKeyEvent>
#include <QScreen>
#include <QGuiApplication>
#include <QPushButton>
#include <QLayout>
#include <QTableWidgetItem>
#include <QPainter>
#include <QPainterPath>
#include <QLabel>
#include <QToolTip>
namespace TIGER_UIBasic
{
    int warningBox(QWidget *parent, const QString &title, const QString &text)
    {
        return CMessageBox::warning(parent, title, text);
    }

    int questionBox(QWidget *parent, const QString &title, const QString &text)
    {
        return CMessageBox::question(parent, title, text);
    }

    void showToolTip(QWidget *p_pWidget, const QString &p_tip)
    {
        QFont font = QToolTip::font();
        font.setBold(true);
        font.setPointSize(12);
        QToolTip::setFont(font);
        int w = QFontMetrics(font).maxWidth();
        const QString st = "<b style=\"color:red; bordet-radius:5px; background-color: white;\">%1</b>";
        QToolTip::showText(QCursor::pos() + QPoint(w, 0), st.arg(p_tip), p_pWidget, QRect(), 3000);
        myInfo << p_tip;
    }
    QTableWidgetItem *getTableWidgetItem(const QString &p_text, int p_textAlignment)
    {
        QTableWidgetItem *pItem = new QTableWidgetItem(p_text);
        pItem->setTextAlignment(p_textAlignment);
        return pItem;
    }
    QPushButton *noKeyPushButton(QString p_name)
    {
        auto p = new QPushButton(p_name);
        p->setFocusPolicy(Qt::NoFocus);
        return p;
    }

    QToolButton *getToolBtn(QWidget *p_pParent, QString text,int p_h,  Qt::ToolButtonStyle p_toolBtnStyle)
    {
        auto pToolBtn = new QToolButton(p_pParent);
        pToolBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        pToolBtn->setFixedHeight(p_h);
        pToolBtn->setToolButtonStyle(p_toolBtnStyle);
        pToolBtn->setText(text);
        return pToolBtn;
    }

    QHBoxLayout *getHLableLayout(QString p_lbName, QWidget *p_w, int p_h)
    {
        QLabel *lb = getLabel(p_lbName, p_h);
        lb->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        p_w->setFixedHeight(p_h);
        QHBoxLayout *pLayout = new QHBoxLayout;
        pLayout->addWidget(lb);
        pLayout->addWidget(p_w);
        pLayout->setMargin(0);
        pLayout->setSpacing(0);
        return pLayout;
    }
    QVBoxLayout *getVLableLayout(QString p_lbName, QWidget *p_widget, int p_w)
    {
        QLabel *lb = getLabel(p_lbName);
        lb->setAlignment(Qt::AlignCenter);
        if (p_w == 0)
        {
            lb->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
            p_widget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        }
        else
        {
            lb->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            lb->setFixedWidth(qMax(double(p_w), p_w * CUiBasic::getScale()));
            p_widget->setFixedWidth(qMax(double(p_w), p_w * CUiBasic::getScale()));
            p_widget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        }
        QVBoxLayout *pLayout = new QVBoxLayout;
        pLayout->addWidget(lb);
        pLayout->addWidget(p_widget);
        pLayout->setMargin(0);
        pLayout->setSpacing(0);
        return pLayout;
    }

    QLabel *getLabel(QString p_name, int p_h, Qt::Alignment p_aalignment)
    {
        QLabel *lb = new QLabel(p_name);
        lb->setAlignment(p_aalignment);
        lb->setFixedHeight(p_h);
        lb->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        return lb;
    }

    void TIGER_UIBasic::deleteLayout(QLayout *p_layout)
    {
        if (p_layout == nullptr)
        {
            return;
        }

        int itemCount = p_layout->count();
        for (int i = (itemCount - 1); i >= 0; --i)
        {
            QLayoutItem *item = p_layout->takeAt(i);
            if (item != NULL)
            {
                p_layout->removeWidget(item->widget());
            }
        }
        delete p_layout;
        p_layout = nullptr;
    };

    void IDialog::paintEvent(QPaintEvent *event)
    {
        QPainter paint;
        paint.begin(this);
        paint.setRenderHint(QPainter::Antialiasing);
        QPainterPath path;
        path.addRoundedRect(this->rect(), 5, 5);
        // Qt默认颜色

        paint.fillPath(path, QColor(235, 244, 255));
        paint.setPen(QPen(QColor(197, 197, 197), 2));
        paint.drawPath(path);
        QDialog::paintEvent(event);
    }

    void INoExcCancelDialog::keyPressEvent(QKeyEvent *event)
    {
        switch (event->key())
        {
        case Qt::Key_Escape:
            break;
        default:
            IDialog::keyPressEvent(event);
        }
    }
};

double CUiBasic::stScale = CUiBasic::getDefScale();
bool CUiBasic::isTop = false;
double CUiBasic::getDefScale()
{
    constexpr int cImageW = 1626;
    constexpr int cImageH = 1236;
    constexpr double cScale = 1.0 * cImageW / cImageH;
    return cScale; // 1440/1080
}

QPixmap CUiBasic::getBackgroundImg()
{
    return QPixmap(":/res/login.jpg");
}

double CUiBasic::getScale()
{
    return stScale;
}

void CUiBasic::updateScale(int p_w, int p_h)
{
    int W, H;
    getScreen(W, H);
    QSize defSize(p_w, p_h);
    defSize.scale(W, H, Qt::KeepAspectRatio);
    if (defSize.width() == W)
    {
        stScale = 1.0 * W / p_w;
    }
    else
    {
        stScale = 1.0 * H / p_h;
    }

    // stScale = 1.0 * W / p_w;
    // if (1.0 * W / H > getDefScale())
    // {
    //     stScale = 1.0 * H / p_h;
    // }
    // stScale = (stScale < 1.0 ? 1 : stScale);
}

void CUiBasic::getScreen(int &p_w, int &p_h)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect size = screen->availableGeometry();
    p_w = size.width();
    p_h = size.height();
    // screen->primaryOrientation();
}