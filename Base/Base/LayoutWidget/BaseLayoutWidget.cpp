#include "BaseLayoutWidget.h"

//Public functions
BaseLayoutWidget::BaseLayoutWidget(QWidget *parent) : QWidget(parent) {
    this->v_p = new QWidget();
}

BaseLayoutWidget::~BaseLayoutWidget() {
    delete this->v_p;
}
