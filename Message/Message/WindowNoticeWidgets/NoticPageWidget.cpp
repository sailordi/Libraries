#include "NoticPageWidget.h"

#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "Base/Other/Helper.h"

//Public functions
NoticPageWidget::NoticPageWidget(QStringList btnText,QGridLayout* gL,QHBoxLayout* hL,QWidget* parent) : SingleLayoutWidget(parent) {
    this->clearLayout(gL);
    this->clearLayout(hL);

    this->v_gLayout = gL;
    this->v_hLayout = hL;

    if(btnText.size() == 8) {
        this->v_nextPageText = btnText.takeFirst();
        this->v_nextPageTr = btnText.takeFirst();

        this->v_nextListText = btnText.takeFirst();
        this->v_nextListTr = btnText.takeFirst();

        this->v_prevPageText = btnText.takeFirst();
        this->v_prevPageTr = btnText.takeFirst();

        this->v_prevListText = btnText.takeFirst();
        this->v_prevListTr = btnText.takeFirst();
    }
    else if(btnText.size() == 4) {
        this->v_nextPageText = btnText.takeFirst();
        this->v_nextListText = btnText.takeFirst();
        this->v_prevPageText = btnText.takeFirst();
        this->v_prevListText = btnText.takeFirst();
    }
    else {
        Helper::quitProgram("Error button text to few / many arguments ["+QString::number(btnText.size() )+"]",1);
    }

}
NoticPageWidget::~NoticPageWidget() {
    this->v_pages.clear();
}

void NoticPageWidget::setFont(QFont f) {
    if(this->v_pageLabel != nullptr) {
        this->v_pageLabel->setFont(f);
    }

    if(this->v_prevPageB != nullptr) {
        this->v_prevPageB->setFont(f);
    }
    if(this->v_nextPageB != nullptr) {
        this->v_nextPageB->setFont(f);
    }

    if(this->v_prevListB != nullptr) {
        this->v_prevListB->setFont(f);
    }
    if(this->v_nextListB != nullptr) {
        this->v_nextListB->setFont(f);
    }

}
