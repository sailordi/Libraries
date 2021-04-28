#include "MultiLayoutWidget.h"

//Public functions
MultiLayoutWidget::MultiLayoutWidget(QWidget *parent) : BaseLayoutWidget(parent) {
}

MultiLayoutWidget::~MultiLayoutWidget() {
    this->v_gLayouts.clear();
    this->v_hLayouts.clear();
    this->v_vLayouts.clear();
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

QHBoxLayout* MultiLayoutWidget::hLayout(int pos) {
    if(pos < 0) {
        return nullptr;
    }else if(pos >= this->v_hLayouts.size() ) {
        return nullptr;
    }

    return this->v_hLayouts.at(pos);
}

QVBoxLayout* MultiLayoutWidget::vLayout(int pos) {
    if(pos < 0) {
        return nullptr;
    }else if(pos >= this->v_vLayouts.size() ) {
        return nullptr;
    }

    return this->v_vLayouts.at(pos);
}
