#pragma once
#include <qt_windows.h>
#include <windows.h>
#include <windowsx.h>
#include <QWidget>
#include <QAxWidget>
#include "IVmSolution.h"

using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;

class QLabel;
class CDZSTMark;
class CHIK3DMVS;
class QTextBrowser;
class CMainWindowMenuBar;
const QString cStyleSheet = "border:1px groove gray;\nborder-radius:10px;\npadding:2px 3px;\nbackground:transparent;\nbackground-color: rgb(255, 255, 255,150);";

class CMainWindow: public QWidget
{
    Q_OBJECT
public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

	void printMsg(QString p_msg);
    bool nativeEvent(const QByteArray& eventType, void* message, long* result);

protected:
	void init();

private:
    HWND m_hWnd;
    CDZSTMark *m_pCDZSTMark;

    CHIK3DMVS *m_pCHIK3DMVS;

    QLabel *m_pImageLabel;
	QTextBrowser* m_pOutMsg;
    QWidget* m_pControl;
    CMainWindowMenuBar *m_pMenuBar;

    IVmSolution* m_pVmSol;
    QAxWidget *activex;
};

CMainWindow* mainWindow();