#pragma once
#include <QWidget>

class QTextBrowser;
class CMainWindowMenuBar;
class ImageView;
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

protected:
	void init();


public slots:
    void slotUpdateImage(QImage p_image);

private:
	QTextBrowser* m_pOutMsg;
    QWidget* m_pControl;
    CMainWindowMenuBar *m_pMenuBar;
    ImageView *m_pImageView;

    TIGER_ProcessTool::CHikrobotEngine* m_pHikrobotEngine;
};

CMainWindow* mainWindow();