#include "logBrowser.h"
#include "ui//basic.h"
#include "system/url/scheme/locationFileScheme.h"
#include <QTextBrowser>
#include <QToolButton>
#include <QLineEdit>
#include <QDesktopServices>
#include <QPainter>
#include <QTreeWidget>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QFileInfo>
#include <QKeyEvent>
#include <QLabel>
#include <QTextStream>
#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QEvent>
CLogBrowser::CLogBrowser(QWidget *parent) : TIGER_UIBasic::IDialog(parent)
{
    setWindowTitle(cnStr("日志"));
    setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    m_pTextBrowser = new QTextBrowser(this);
    m_pTextBrowser->installEventFilter(this);
    m_pTextBrowser->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    m_pTextBrowser->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
    m_pTextBrowser->setOpenLinks(false);
    m_pTextBrowser->setOpenExternalLinks(false);
    m_pTextBrowser->setTextInteractionFlags(Qt::TextEditorInteraction | Qt::LinksAccessibleByMouse | Qt::LinksAccessibleByKeyboard);
    const QString cStyleSheet = "border:1px groove rgb(203,217,235);border-radius:3px;background:transparent;background-color: rgba(255, 255, 255,150);";
    m_pTextBrowser->setStyleSheet(cStyleSheet);
    connect(m_pTextBrowser, &QTextBrowser::anchorClicked, [](const QUrl &p_url)
            { QDesktopServices::openUrl(p_url); });

    auto getToolPb = [](QString p_name, QIcon p_icon)
    {
        QToolButton *pToolButton = new QToolButton;
        pToolButton->setStyleSheet(
            "QToolButton:checked{background:rgb(0,255,0);}"
            "QToolButton{border-radius:5px;border:none; padding:0px;}"
            "QToolButton:hover:!checked{background:rgb(210,220,230);}");
        pToolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        pToolButton->setIcon(p_icon);
        pToolButton->setIconSize(QSize(30, 30));
        pToolButton->setToolTip(p_name);
        pToolButton->setFixedSize(30, 30);
        return pToolButton;
    };

    m_pBackwardPb = getToolPb(cnStr("向上搜素"), QIcon(":res/up.png"));
    m_pNextPb = getToolPb(cnStr("向下搜素"), QIcon(":res/down.png"));
    connect(m_pBackwardPb, &QToolButton::clicked, this, &CLogBrowser::findBackwardNext);
    connect(m_pNextPb, &QToolButton::clicked, this, &CLogBrowser::findNext);

    m_pFindAction = new QAction(QIcon(":res/find.png"), cnStr("查找"), this);
    connect(m_pFindAction, &QAction::triggered, this, &CLogBrowser::findBackwardNext);
    m_pName = new QLabel(this);
    m_pName->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_pFindTextEd = new QLineEdit(this);
    m_pFindTextEd->setMaximumWidth(600);
    m_pFindTextEd->setMinimumWidth(300);
    m_pFindTextEd->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_pFindTextEd->setPlaceholderText(cnStr("查找"));
    m_pFindTextEd->setFixedHeight(30);
    m_pClearAction = new QAction(QIcon(":res/clear.png"), cnStr("清除"), this);
    connect(m_pClearAction, &QAction::triggered, this, [this]
            { m_pFindTextEd->setText("");
                clearSelectedText(); });
    connect(m_pFindTextEd, &QLineEdit::textChanged, this, [this](QString text)
            { m_pClearAction->setVisible(text.size() > 0); });
    m_pFindTextEd->addAction(m_pFindAction, QLineEdit::TrailingPosition);
    m_pFindTextEd->addAction(m_pClearAction, QLineEdit::TrailingPosition);
    m_pFindTextEd->setStyleSheet(
        "QLineEdit{border:2px solid;padding:4px;padding-left:10px;border-radius:3px;color:rgb(105,105,105);font:20px \"Microsoft YaHei\";}"
        "QLineEdit:focus{border:2px solid rgb(208,208,208);}"
        "QLineEdit:disabled{background-color:rgb(238,238,238);}");
    m_pClearAction->setVisible(false);
    m_pTreeWidget = new QTreeWidget(this);
    m_pTreeWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_pTreeWidget->setStyleSheet(cStyleSheet);
    m_pTreeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    m_pTreeWidget->header()->hide();
    connect(m_pTreeWidget, &QTreeWidget::currentItemChanged, this, [this](QTreeWidgetItem *item, QTreeWidgetItem *previous)
            {
                if (item == nullptr)
                {
                    return;
                }
                auto path = item->toolTip(0);
                if (path.isEmpty())
                {
                    return;
                }
                QFile file(path);
                if (!file.open(QIODevice::ReadOnly))
                {
                    TIGER_UIBasic::warningBox(this, cnStr("警告"), cnStr("打开日志文件:%1失败").arg(path));
                    return;
                }
                auto name = item->text(0);
                m_pName->setText(name);
                m_pFindTextEd->setPlaceholderText(cnStr("在%1中查找").arg(name));
                m_pTextBrowser->clear();
                while (!file.atEnd())
                {
                    m_pTextBrowser->append(file.readLine().trimmed());
                }
                file.close();
                m_pTextBrowser->moveCursor(m_pTextBrowser->textCursor().End);
                m_pTextBrowser->setFocus(); });
    connect(m_pTreeWidget, &QTreeWidget::customContextMenuRequested, this, [this](const QPoint &point)
            {
                QTreeWidgetItem *curItem = m_pTreeWidget->itemAt(point);
                if (curItem == nullptr || curItem->toolTip(0).isEmpty())
                {
                    return;
                }
                QAction openDir(cnStr("打开%1所在文件夹").arg(curItem->text(0)), this);
                // 在界面上删除该item
                connect(&openDir, &QAction::triggered, this, [file = curItem->toolTip(0)]
                {
                    QDesktopServices::openUrl(TIGER_Url::CBSUrlLocationFileScheme::getLocationFileUrl(QFileInfo(file).absoluteFilePath()));
                });
                QMenu menu(this);
                menu.addAction(&openDir);
                menu.exec(QCursor::pos()); });
    updateLayout();
    m_pTreeWidget->setFixedWidth(200);
    m_pTextBrowser->setMinimumWidth(500);
}

CLogBrowser::~CLogBrowser()
{
    delPtr(m_pClearAction);
    delPtr(m_pFindAction);
}

void CLogBrowser::showLogs(QList<CLogMonthInfo> p_infos)
{
    assert(!p_infos.isEmpty());
    m_infos = p_infos;
    updateTreeWidget();
    this->exec();
}

void CLogBrowser::findNext()
{
    findText(false);
}

void CLogBrowser::findBackwardNext()
{
    findText(true);
}

void CLogBrowser::findText(QString text)
{
    m_pFindTextEd->setFocus();
    m_pFindTextEd->setText(text);
}

void CLogBrowser::findText(bool isBackward)
{
    const QString cStr = m_pFindTextEd->text();
    if (cStr.size() == 0)
    {
        clearSelectedText();
        return;
    }
    if (isBackward ? m_pTextBrowser->find(cStr, QTextDocument::FindBackward) : m_pTextBrowser->find(cStr))
    {
        updateSelectedTextColor();
    }
    else
    {
        TIGER_UIBasic::warningBox(this, cnStr("查找"), cnStr("没有找到内容"));
    }
}

void CLogBrowser::updateLayout()
{
    TIGER_UIBasic::deleteLayout(this->layout());
    QVBoxLayout *pLayout = new QVBoxLayout;
    {
        QHBoxLayout *pFindLayout = new QHBoxLayout;
        pFindLayout->addWidget(m_pName);
        pFindLayout->addWidget(m_pFindTextEd);
        pFindLayout->addWidget(m_pNextPb);
        pFindLayout->addWidget(m_pBackwardPb);
        pFindLayout->setMargin(0);
        pFindLayout->setSpacing(5);
        pLayout->addLayout(pFindLayout);
    }
    pLayout->addWidget(m_pTextBrowser);
    pLayout->setMargin(0);
    pLayout->setSpacing(0);

    QHBoxLayout *pMainLayout = new QHBoxLayout;
    pMainLayout->addWidget(m_pTreeWidget);
    pMainLayout->addLayout(pLayout);
    pMainLayout->setMargin(5);
    pMainLayout->setSpacing(5);
    this->setLayout(pMainLayout);
}

void CLogBrowser::updateSelectedTextColor()
{
    QPalette palette = m_pTextBrowser->palette();
    palette.setColor(QPalette::Highlight, palette.color(QPalette::Active, QPalette::Highlight));
    m_pTextBrowser->setPalette(palette);
}
void CLogBrowser::clearSelectedText()
{
    auto textCursor = m_pTextBrowser->textCursor();
    textCursor.clearSelection();
    m_pTextBrowser->setTextCursor(textCursor);
    m_pTextBrowser->moveCursor(textCursor.EndOfWord);
    m_pTextBrowser->setTextInteractionFlags(Qt::TextEditorInteraction | Qt::LinksAccessibleByMouse | Qt::LinksAccessibleByKeyboard);
    m_pTextBrowser->setFocus();
}

void CLogBrowser::updateTreeWidget()
{
    assert(!m_infos.isEmpty());
    m_pTreeWidget->clear();
    QTreeWidgetItem *pLast = nullptr;
    for (const auto &monthInfo : m_infos)
    {
        QTreeWidgetItem *pMonthItem = new QTreeWidgetItem(m_pTreeWidget);
        pMonthItem->setText(0, monthInfo.yearMonth);
        for (const auto &dayInfo : monthInfo.dayLogPaths)
        {
            QTreeWidgetItem *pDayItem = new QTreeWidgetItem;
            pDayItem->setText(0, QString("%1.%2").arg(monthInfo.yearMonth).arg(iToStr(dayInfo.day), 2, '0'));
            pDayItem->setToolTip(0, dayInfo.path);
            pMonthItem->addChild(pDayItem);
            pLast = pDayItem;
        }
    }
    assert(pLast != nullptr);
    m_pTreeWidget->expandAll();
    m_pTreeWidget->setCurrentItem(pLast);
}

bool CLogBrowser::eventFilter(QObject *pObject, QEvent *pEvent)
{
    if (pObject == m_pTextBrowser)
    {
        switch (pEvent->type())
        {
        case QEvent::KeyPress:
            if (static_cast<QKeyEvent *>(pEvent)->matches(QKeySequence::Copy))
            {
                return false;
            }
            if (static_cast<QKeyEvent *>(pEvent)->matches(QKeySequence::Find))
            {
                auto text = m_pTextBrowser->textCursor().selectedText();
                if (text.size() > 0)
                {
                    updateSelectedTextColor();
                }
                findText(text);
            }
            return true;
            break;
        case QEvent::InputMethod:
            return true;
            break;
        default:
            break;
        }
    }

    return IDialog::eventFilter(pObject, pEvent);
}