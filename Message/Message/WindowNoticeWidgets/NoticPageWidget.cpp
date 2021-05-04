#include "NoticPageWidget.h"

#include <QGridLayout>
#include <QHBoxLayout>

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
