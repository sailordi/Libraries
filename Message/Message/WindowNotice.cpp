#include "WindowNotice.h"
#include "ui_WindowNotice.h"

#include <QFont>
#include <QMenu>

#include "Base/Other/Translator.h"
#include "Base/Settings/Settings.h"

#include "Message/Notice/NoticeFlag.h"
#include "Message/Notice/NoticeList.h"
#include "Message/Notice/NoticePage.h"
#include "Message/WindowNoticeWidgets/NoticeTabWidget.h"
#include "Message/WindowNoticeWidgets/NoticPageWidget.h"

enum TABINDEX_WINDOWNOTICE{ERRORINDEX = 0,WARNINGINDEX,MESSAGEINDEX};

//Public functions
WindowNotice::WindowNotice(QWidget* parent) : QMainWindow(parent), v_ui(new Ui::WindowNotice) {
    this->v_ui->setupUi(this);

    this->init({"Errors","Error","Warnings","Warning","Messages","Message"},
               {"Next Message Page","Next Message List","Previous Message Page","Previous Message List"},
               false);
}

WindowNotice::WindowNotice(Translator* tr,QStringList languageTitle,QStringList tabText,QStringList pageText,QWidget* parent) : QMainWindow(parent), v_ui(new Ui::WindowNotice) {
    this->v_ui->setupUi(this);

    this->v_translator = tr;

    this->v_languageTitle = languageTitle.takeFirst();
    this->v_languageTitleTr = languageTitle.takeFirst();

    this->v_languageM = new QMenu(this);

    QFont f = QFont("Times New Roman",16);
    f.setBold(true);

    this->v_languageM->setFont(f);

    this->v_ui->menubar->addMenu(this->v_languageM);

    this->v_languageTitle = languageTitle.takeFirst();
    this->v_languageTitleTr = languageTitle.takeFirst();

    this->v_translator->populateLanguageMenu(this->v_languageM,this->v_languageTitle);

    this->init(tabText,pageText,true);
}

WindowNotice::~WindowNotice() {
    delete this->v_errorW;
    delete this->v_warningW;
    delete this->v_messageW;

    delete this->v_pageW;

    if(this->v_languageM != nullptr) {
        delete this->v_languageM;
    }

    delete this->v_ui;
}

void WindowNotice::loadSettings(Settings* s) {
    s->startGroup("WindowNotice");

    QPoint p = s->getBlockData("Pos",QPoint(100,100) ).toPoint();

    this->move(p);

    s->endGroup();
}

void WindowNotice::saveSettings(Settings* s) {
    s->startGroup("WindowNotice");

    s->addBlockData("Pos",this->pos() );

    s->endGroup();
}

void WindowNotice::add(NoticePage* p) {
    this->v_pageW->add(p);
}

void WindowNotice::add(QSharedPointer<NoticePage> p) {
    this->v_pageW->add(p);
}

void WindowNotice::clear() {
    this->v_pageW->clear();
}

void WindowNotice::prepare() {
    this->v_pageW->resetIndex(ResetFlag::BOTH);

    this->setTabsShown();
}

//Private functions
void WindowNotice::init(QStringList tabText,QStringList pageText,bool tr) {
    this->v_errorW = new NoticeTabWidget(ERRORINDEX,this->v_ui->error_layout,this->v_ui->error_tab,
                                    this->v_ui->messages_widget,tabText,tr,NoticeFlag::ERROR);

    this->v_warningW = new NoticeTabWidget(WARNINGINDEX,this->v_ui->warning_layout,this->v_ui->warning_tab,
                                        this->v_ui->messages_widget,tabText,tr,NoticeFlag::WARNING);

    this->v_messageW = new NoticeTabWidget(MESSAGEINDEX,this->v_ui->message_layout,this->v_ui->message_tab,
                                         this->v_ui->messages_widget,tabText,tr,NoticeFlag::MESSAGE);

    this->v_pageW = new NoticPageWidget(pageText,this->v_ui->page_layout,this->v_ui->list_layout);

    QFont f = QFont("Times New Roman",16);

    this->v_errorW->setFont(f);
    this->v_warningW->setFont(f);
    this->v_messageW->setFont(f);
    this->v_pageW->setFont(f);

    this->v_errorW->setChild(this->v_warningW);
    this->v_warningW->setChild(this->v_messageW);

    QRect defG(0,0,1150,720);

    this->setMinimumSize(defG.width(),defG.height() );
}

void WindowNotice::setTabsShown() {
    this->v_errorW->resetTab(true);

    NoticeListP tmp =  this->v_pageW->curretList();

    int errorS    = (tmp.isNull() == true) ? 0 : tmp->size(NoticeFlag::ERROR);
    int warningS  = (tmp.isNull() == true) ? 0 : tmp->size(NoticeFlag::WARNING);
    int messageS  = (tmp.isNull() == true) ? 0 : tmp->size(NoticeFlag::MESSAGE);

    this->v_errorW->setData(errorS,1);
    this->v_warningW->setData(warningS,1);
    this->v_messageW->setData(messageS,1);
}
