#include "SingleLayoutWidget.h"

//Public functions
SingleLayoutWidget::SingleLayoutWidget(QWidget *parent) : QWidget(parent) {
    this->v_p = new QWidget();
}

SingleLayoutWidget::~SingleLayoutWidget() {
    delete this->v_p;
}
