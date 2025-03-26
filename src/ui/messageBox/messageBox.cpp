#include "messageBox.h"
#include "../basic.h"

CMessageBox::CMessageBox(QWidget *parent)
    : QMessageBox(parent)
{
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint, true);
    setWindowFlag(Qt::WindowCloseButtonHint, false);
    setStyleSheet("QMessageBox{background-color:rgb(235,244,255);}");
}

CMessageBox::CMessageBox(Icon icon, const QString &title, const QString &text, StandardButtons buttons, StandardButton defaultButton, QWidget *parent)
    : CMessageBox(parent)
{
    setIcon(icon);
    setWindowTitle(title);
    setText(text);
    setStandardButtons(buttons);
    setDefaultButton(defaultButton);
}

CMessageBox::~CMessageBox()
{
}

int CMessageBox::information(QWidget *parent, const QString &title,
                             const QString &text, StandardButtons buttons,
                             StandardButton defaultButton)
{
    CMessageBox box(Information, title, text, buttons, defaultButton, parent);
    return box.exec();
}

int CMessageBox::question(QWidget *parent, const QString &title,
                          const QString &text, StandardButtons buttons,
                          StandardButton defaultButton)
{
    CMessageBox box(Question, title, text, buttons, defaultButton, parent);
    return box.exec();
}

int CMessageBox::warning(QWidget *parent, const QString &title,
                         const QString &text, StandardButtons buttons,
                         StandardButton defaultButton)
{
    CMessageBox box(Warning, title, text, buttons, defaultButton, parent);
    return box.exec();
}

int CMessageBox::critical(QWidget *parent, const QString &title,
                          const QString &text, StandardButtons buttons,
                          StandardButton defaultButton)
{
    CMessageBox box(Critical, title, text, buttons, defaultButton, parent);
    return box.exec();
}

void CMessageBox::about(QWidget *parent, const QString &title, const QString &text)
{
    CMessageBox box(NoIcon, title, text, Ok, NoButton, parent);
    box.exec();
}
