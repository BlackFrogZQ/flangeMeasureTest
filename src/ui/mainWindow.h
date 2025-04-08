#pragma once
#include <QWidget>

namespace VisionMasterSDK
{
    namespace VmSolution
    {
        class IVmSolution;
    }
}

class QTextBrowser;
class QAxWidget;
class CMainWindowMenuBar;

class CMainWindow: public QWidget
{
    Q_OBJECT
public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

	void printMsg(QString p_msg);

protected:
	void init();

private:
	QTextBrowser* m_pOutMsg;
    QWidget* m_pControl;
    CMainWindowMenuBar *m_pMenuBar;

    VisionMasterSDK::VmSolution::IVmSolution* m_pVmSol;
    QAxWidget *m_pActivex;
};

CMainWindow* mainWindow();