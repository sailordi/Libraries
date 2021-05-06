#include "WindowNotice.h"
#include "ui_WindowNotice.h"

#include <QFont>
#include <QMenu>

#include "Base/Other/Translator.h"

#include "Message/WindowNoticeWidgets/NoticeTabWidget.h"
#include "Message/WindowNoticeWidgets/NoticPageWidget.h"

//Public functions
WindowNotice::WindowNotice(QWidget* parent) : QMainWindow(parent), v_ui(new Ui::WindowNotice) {
    this->v_ui->setupUi(this);
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

