#pragma once
#include <QTextBrowser>
class CTextBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    CTextBrowser( QWidget * mainWindow, QWidget *parent = nullptr);
    ~CTextBrowser();
public slots:
    void execLogTextBrowser();

protected:
    bool eventFilter(QObject *, QEvent *) override;

protected:
     QWidget * m_pMainWindow;
};
