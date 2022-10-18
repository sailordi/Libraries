#include "WindowNotice.h"
#include "ui_WindowNotice.h"

#include <QFont>
#include <QMenu>

#include "Base/Other/Helper.h"
#include "Base/Other/Translator.h"
#include "Base/Settings/Settings.h"

#include "Message/Notice/NoticeFlag.h"
#include "Message/Notice/NoticeList.h"
#include "Message/Notice/NoticePage.h"
#include "Message/WindowNoticeWidgets/NoticeTabWidget.h"
#include "Message/WindowNoticeWidgets/NoticPageWidget.h"

enum TABINDEX_WINDOWNOTICE{ERRORINDEX = 0,WARNINGINDEX,MESSAGEINDEX};

const int TAB_TEXT_LIST_SIZE = 6,PAGE_TEXT_LIST_SIZE = 4;

//Public functions
WindowNotice::WindowNotice(QWidget* parent) : QMainWindow(parent), v_ui(new Ui::WindowNotice) {
    this->v_ui->setupUi(this);

    this->init({"Errors","Error","Warnings","Warning","Messages","Message"},
               {"Next Message Page","Next Message List","Previous Message Page","Previous Message List"},
               false);
}

WindowNotice::WindowNotice(Translator* tr,bool manualTr,QStringList languageTitle,QStringList tabText,QStringList pageText,QWidget* parent) : QMainWindow(parent), v_ui(new Ui::WindowNotice) {
    this->v_ui->setupUi(this);

    this->v_translator = tr;

    this->v_languageTitle = languageTitle.takeFirst();
    this->v_languageTitleTr = languageTitle.takeFirst();

    this->v_languageM = new QMenu(this);

    this->v_ui->menubar->addMenu(this->v_languageM);

    this->v_languageTitle = languageTitle.takeFirst();
    this->v_languageTitleTr = languageTitle.takeFirst();

    this->v_translator->populateLanguageMenu(this->v_languageM,this->v_languageTitle);

    this->init(tabText,pageText,true);

    if(manualTr == false) {
        connect(this->v_translator,&Translator::reTranslate,this,&WindowNotice::reTranslate);

        this->reTranslate();
    }

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

void WindowNotice::setFont(QFont mF,QFont pageF,QFont errorTabF,QFont warningTabF,QFont messageTabF) {
    if(this->v_languageM != nullptr) {
        this->v_languageM->setFont(mF);
    }
    this->v_pageW->setFont(pageF);
    this->v_errorW->setFont(errorTabF);
    this->v_warningW->setFont(warningTabF);
    this->v_messageW->setFont(messageTabF);
}

void WindowNotice::setFont(QFont mF,QList<QFont> pageF,QList<QFont> errorTabF,QList<QFont> warningTabF,QList<QFont> messageTabF) {
    if(this->v_languageM != nullptr) {
        this->v_languageM->setFont(mF);
    }
    this->v_pageW->setFont(pageF);
    this->v_errorW->setFont(errorTabF);
    this->v_warningW->setFont(warningTabF);
    this->v_messageW->setFont(messageTabF);
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

//Public slots
void WindowNotice::reTranslate() {
    if(this->v_languageTitleTr.isEmpty() == false) {
        this->v_languageTitle = WindowNotice::tr(this->v_languageTitleTr.toStdString().c_str() );
    }

    if(this->v_translator != nullptr) {
        this->v_translator->reTranslateLanguageMenu(this->v_languageM,this->v_languageTitle);
    }
    this->v_pageW->reTranslate();

    this->v_errorW->reTranslate();
    this->v_warningW->reTranslate();
    this->v_messageW->reTranslate();
}

//Private slots:
void WindowNotice::listChange() {
    this->setTabsShown();
}

void WindowNotice::messageChange(int pos,NoticeFlag flag) {
    if(pos <= 0) {
        return;
    }

    NoticeTabWidget* tmp = nullptr;
    NoticeListP l = this->v_pageW->curretList();

    switch(flag) {
        case NoticeFlag::ERROR:
            tmp = this->v_errorW;
            break;
        case NoticeFlag::WARNING:
            tmp = this->v_warningW;
            break;
        case NoticeFlag::MESSAGE:
            tmp = this->v_messageW;
            break;
    }

    tmp->setText(l->msg(pos-1,flag),Qt::AlignCenter);
    tmp->setLabel(pos);
}

//Private functions
void WindowNotice::init(QStringList tabText,QStringList pageText,bool tr) {
    this->errorCheck(tabText,pageText,tr);

    this->v_errorW = new NoticeTabWidget(ERRORINDEX,this->v_ui->error_layout,this->v_ui->error_tab,
                                    this->v_ui->messages_widget,tabText,tr,NoticeFlag::ERROR);

    this->v_warningW = new NoticeTabWidget(WARNINGINDEX,this->v_ui->warning_layout,this->v_ui->warning_tab,
                                        this->v_ui->messages_widget,tabText,tr,NoticeFlag::WARNING);

    this->v_messageW = new NoticeTabWidget(MESSAGEINDEX,this->v_ui->message_layout,this->v_ui->message_tab,
                                         this->v_ui->messages_widget,tabText,tr,NoticeFlag::MESSAGE);

    this->v_pageW = new NoticPageWidget(pageText,this->v_ui->page_layout,this->v_ui->list_layout,tr);

    connect(this->v_errorW,&NoticeTabWidget::messageChanged,this,&WindowNotice::messageChange);
    connect(this->v_warningW,&NoticeTabWidget::messageChanged,this,&WindowNotice::messageChange);
    connect(this->v_messageW,&NoticeTabWidget::messageChanged,this,&WindowNotice::messageChange);

    connect(this->v_pageW,&NoticPageWidget::listChanged,this,&WindowNotice::listChange);

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

void WindowNotice::errorCheck(QStringList tabText,QStringList pageText,bool tr) {
    int tS = tabText.size();
    int pS = pageText.size();
    QString er = "";

        if(tS != TAB_TEXT_LIST_SIZE && tr == false) {
            er.append("Error tab text has to few / many arguments ["+QString::number(tS)+"]"+Helper::newRow(2) );
        }
        else if(tS != (TAB_TEXT_LIST_SIZE * 2) && tr == true) {
            er.append("Error transaction tab text has to few / many arguments ["+QString::number(tS)+"]"+Helper::newRow(2) );
        }

        if(pS != PAGE_TEXT_LIST_SIZE && tr == false) {
            er.append("Error page button text has to few / many arguments ["+QString::number(pS)+"]"+Helper::newRow(1) );
        }
        if(pS != (PAGE_TEXT_LIST_SIZE * 2) && tr == true) {
            er.append("Error translation page button text has to few / many arguments ["+QString::number(pS)+"]"+Helper::newRow(1) );
        }

        if(er.isEmpty() == false) {
            Helper::quitProgram(er,1);
        }

}
