#include "MultiLayoutWidget.h"

//Public functions
MultiLayoutWidget::MultiLayoutWidget(QWidget *parent) : QWidget(parent) {
    this->v_p = new QWidget();
}

MultiLayoutWidget::~MultiLayoutWidget() {
    this->v_gLayouts.clear();
    this->v_hLayouts.clear();
    this->v_vLayouts.clear();

    delete this->v_p;
}

//Protected functions
QGridLayout* MultiLayoutWidget::gLayout(int pos) {
    if(pos < 0) {
       return nullptr;
    }else if(pos >= this->v_gLayouts.size() ) {
       return nullptr;
    }

    return this->v_gLayouts.at(pos);
}
