#pragma once
#include <QWidget>

class QTextBrowser;
class CMainWindowMenuBar;
namespace TIGER_ProcessTool
{
    class CHikrobotEngine;
}

class CMainWindow: public QWidget
{
    Q_OBJECT
public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

	void printMsg(QString p_msg);

    void loadSolution(QString strSolPath, QString strPassword);

    void clickRenderBind();
    void clickExecuteOnce();
    void clickRenderUnBind();

    void clickImageResults();
    void clickCallBackImageResults();
    void clickProcessResults();

protected:
	void init();

private:
	QTextBrowser* m_pOutMsg;
    QWidget* m_pControl;
    CMainWindowMenuBar *m_pMenuBar;

    TIGER_ProcessTool::CHikrobotEngine* m_pHikrobotEngine;
};

CMainWindow* mainWindow();