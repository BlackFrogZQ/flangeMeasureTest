#pragma once
#include <QWidget>

class CDZSTMark;
class QTextBrowser;
class QPushButton;

class CControl: public QWidget
{
    Q_OBJECT
public:
    CControl(QWidget *parent = nullptr, CDZSTMark *p_CDZSTMark = nullptr);
    ~CControl();

protected:
	void init();

protected slots:
    void OnBnClickedButtonConnect();
    void OnBnClickedButtonDisconnect();
    void OnBnClickedButtonCreateUDM();
    void OnBnClickedButtonDownloadUDM();

    void OnBnClickedButtonStartMark();
    void OnBnClickedButtonPauseMark();
    void OnBnClickedButtonContinueMark();
    void OnBnClickedButtonStopMark();

private:
    CDZSTMark *m_pCDZSTMark;

    QPushButton *m_pConnect;
    QPushButton *m_pDisconnect;
    QPushButton *m_pCreateUDM;
    QPushButton *m_pDownloadUDM;

    QPushButton *m_pStartMark;
    QPushButton *m_pPauseMark;
    QPushButton *m_pContinueMark;
    QPushButton *m_pStopMark;
};
