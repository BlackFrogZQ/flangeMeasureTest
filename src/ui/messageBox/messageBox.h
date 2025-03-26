#pragma once
#include <QMessageBox>
class CMessageBox : public QMessageBox
{
    Q_OBJECT
public:
    CMessageBox(QWidget *parent = nullptr);
    ~CMessageBox();

    static int information(QWidget *parent, const QString &title,
                                      const QString &text, StandardButtons buttons = Ok,
                                      StandardButton defaultButton = NoButton);
    static int question(QWidget *parent, const QString &title,
                                   const QString &text, StandardButtons buttons = StandardButtons(Yes | No),
                                   StandardButton defaultButton = NoButton);
    static int warning(QWidget *parent, const QString &title,
                                  const QString &text, StandardButtons buttons = Ok,
                                  StandardButton defaultButton = NoButton);
    static int critical(QWidget *parent, const QString &title,
                                   const QString &text, StandardButtons buttons = Ok,
                                   StandardButton defaultButton = NoButton);
    static void about(QWidget *parent, const QString &title, const QString &text);

protected:
    CMessageBox(Icon icon, const QString &title, const QString &text, StandardButtons buttons,StandardButton defaultButton, QWidget *parent = nullptr);
};