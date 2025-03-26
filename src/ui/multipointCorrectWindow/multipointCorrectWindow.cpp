#include "multipointCorrectWindow.h"
#include "system/basic.h"
#include "hal/DZSTMark/DZSTMark.h"
#include <QLabel>
#include <QGridLayout>

CMultipointCorrect::CMultipointCorrect(QWidget *parent, CDZSTMark *p_CDZSTMark): QWidget(parent), m_pCDZSTMark(p_CDZSTMark)
{
    init();
}

CMultipointCorrect::~CMultipointCorrect()
{
}

void CMultipointCorrect::init()
{
    QLabel* pCorrectRange = new QLabel(cnStr("校正范围"));
    QLabel* pMarkRange = new QLabel(cnStr("打标范围"));
    QLabel* pMarkRow = new QLabel(cnStr("打标行数"));
    QLabel* pMarkCol = new QLabel(cnStr("打标列数"));
    QLabel* pRowSpace = new QLabel(cnStr("行间距"));
    QLabel* pColSpace = new QLabel(cnStr("列间距"));
    QLabel* pMarkImage = new QLabel(cnStr("打标图形"));
    QLabel* pImageRadius = new QLabel(cnStr("图形半径"));

    QGridLayout *pGridLayout = new QGridLayout;
    pGridLayout->addWidget(pCorrectRange, 0, 0, 1, 1);
    this->setLayout(pGridLayout);
}

