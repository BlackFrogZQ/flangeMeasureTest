#pragma once
#include "ui/basic.h"
#include "system/logSystem/logDef.h"

class QToolButton;
class QLineEdit;
class QAction;
class QTextBrowser;
class QTreeWidget;
class QLabel;

class CLogBrowser :public TIGER_UIBasic::IDialog
{
    Q_OBJECT
public:
    CLogBrowser(QWidget *parent = nullptr);
    ~CLogBrowser();
    void showLogs(QList<CLogMonthInfo> p_infos);

protected slots:
    void findNext();
    void findBackwardNext();

protected:
    void updateLayout();
    void updateTreeWidget();
    void findText(bool isBackward = false);
    void findText(QString text);
    void updateSelectedTextColor();
    void clearSelectedText();

protected:
    bool CLogBrowser::eventFilter(QObject *pObject, QEvent *pEvent) override;

protected:
    QList<CLogMonthInfo> m_infos;
    QTextBrowser *m_pTextBrowser;
    QToolButton *m_pBackwardPb;
    QToolButton *m_pNextPb;
    QLabel *m_pName;
    QLineEdit *m_pFindTextEd;
    QAction *m_pClearAction;
    QAction *m_pFindAction;
    QTreeWidget *m_pTreeWidget;
};
