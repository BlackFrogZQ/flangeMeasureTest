#pragma once
#include "userDef.h"
#include <QLabel>
class QToolButton;

class CMainWindowMenuBar : public QLabel
{
    Q_OBJECT
public:
    CMainWindowMenuBar(QWidget *p_pParent = nullptr);
    ~CMainWindowMenuBar();
    void initLayout();
    CUserType currentUser() const;
    bool checkPassword();
    void setUsedSetParaPB(bool p_used = true);

public slots:
    void setUserType(CUserType type);
    void slotSetPara();
    void slotSignInClicked();

private:
    CUserType m_userType;
    QToolButton *m_pUserPB;
    QToolButton *m_pSetParaPB;
};

CMainWindowMenuBar *mainWindowMenuBar();
