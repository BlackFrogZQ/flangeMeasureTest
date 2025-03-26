#pragma once
#include <QWidget>

class CDZSTMark;

class CMultipointCorrect: public QWidget
{
public:
    CMultipointCorrect(QWidget *parent = nullptr, CDZSTMark *p_CDZSTMark = nullptr);
    ~CMultipointCorrect();

protected:
	void init();

private:
    CDZSTMark *m_pCDZSTMark;
};

