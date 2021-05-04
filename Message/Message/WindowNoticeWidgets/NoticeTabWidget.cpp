#include "NoticeTabWidget.h"

#include <QGridLayout>
#include <QList>
#include <QTabWidget>

#include "Base/Other/Helper.h"
#include "Message/Notice/NoticeFlag.h"

//Public functions
NoticeTabWidget::NoticeTabWidget(int in,QGridLayout* gL,QWidget* tab,QTabWidget* tabW,QStringList& text,bool trans,NoticeFlag f,QWidget* parent) :  SingleLayoutWidget(parent) {
    this->clearLayout(gL);

    this->v_gLayout = gL;
    this->v_tab = tab;
    this->v_tabW = tabW;
    this->v_flag = f;
    this->v_index = this->v_originalIndex = in;

    if(QList<int>({4,8,12}).contains(text.size() ) == true && trans == true) {
        this->v_tabText = text.takeFirst();
        this->v_trTab = text.takeFirst();
        this->v_labelText = text.takeFirst();
        this->v_trLabel = text.takeFirst();
    }else if(QList<int>({2,4,6}).contains(text.size() ) == true && trans == false) {
        this->v_tabText = text.takeFirst();
        this->v_labelText = text.takeFirst();
    }else {
        Helper::quitProgram("Error text to few / many arguments ["+QString::number(text.size() )+"]",1);
    }

}
