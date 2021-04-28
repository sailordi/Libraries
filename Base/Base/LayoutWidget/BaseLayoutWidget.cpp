#include "BaseLayoutWidget.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLayoutItem>
#include <QVBoxLayout>

//Public functions
BaseLayoutWidget::BaseLayoutWidget(QWidget *parent) : QWidget(parent) {
    this->v_p = new QWidget();
}

BaseLayoutWidget::~BaseLayoutWidget() {
    delete this->v_p;
}

//Protected functions
void BaseLayoutWidget::clearLayout(QGridLayout *l) {
    while(l->count() > 0) {
        QLayoutItem *item = l->takeAt(0);
        QWidget* w =item->widget();
        QGridLayout* gL = static_cast<QGridLayout*>(item->layout() );
        QHBoxLayout* hL = static_cast<QHBoxLayout*>(item->layout() );
        QVBoxLayout* vL = static_cast<QVBoxLayout*>(item->layout() );

        if(w) {
           delete w;
        }

        if(gL) {
            this->clearLayout(gL);
        }
        if(hL) {
            this->clearLayout(hL);
        }
        if(vL) {
            this->clearLayout(vL);
        }

        delete item;
    }

}

void BaseLayoutWidget::clearLayout(QHBoxLayout* l) {
    while(l->count() > 0) {
        QLayoutItem *item = l->takeAt(0);
        QWidget* w =item->widget();
        QGridLayout* gL = static_cast<QGridLayout*>(item->layout() );
        QHBoxLayout* hL = static_cast<QHBoxLayout*>(item->layout() );
        QVBoxLayout* vL = static_cast<QVBoxLayout*>(item->layout() );

        if(w) {
           delete w;
        }

        if(gL) {
            this->clearLayout(gL);
        }
        if(hL) {
            this->clearLayout(hL);
        }
        if(vL) {
            this->clearLayout(vL);
        }

        delete item;
    }

}

void BaseLayoutWidget::clearLayout(QVBoxLayout* l) {
    while(l->count() > 0) {
        QLayoutItem *item = l->takeAt(0);
        QWidget* w =item->widget();
        QGridLayout* gL = static_cast<QGridLayout*>(item->layout() );
        QHBoxLayout* hL = static_cast<QHBoxLayout*>(item->layout() );
        QVBoxLayout* vL = static_cast<QVBoxLayout*>(item->layout() );

        if(w) {
           delete w;
        }

        if(gL) {
            this->clearLayout(gL);
        }
        if(hL) {
            this->clearLayout(hL);
        }
        if(vL) {
            this->clearLayout(vL);
        }

        delete item;
    }

}
