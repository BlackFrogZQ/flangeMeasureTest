﻿#pragma once
#include <qt_windows.h>
#include <windows.h>
#include <windowsx.h>
#include <QWidget>
#include "Mv3dLpApi.h"
#include "Mv3dLpDefine.h"
#include "Mv3dLpImgProc.h"

class QLabel;
class CDZSTMark;
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

    QLabel *m_pImageLabel;
	QTextBrowser* m_pOutMsg;
    QWidget* m_pControl;
    CMainWindowMenuBar *m_pMenuBar;
};

CMainWindow* mainWindow();