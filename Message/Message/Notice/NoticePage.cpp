#include "NoticePage.h"

//Public functions
NoticePage::NoticePage(QObject* parent) : QObject(parent) {

}

NoticePage::NoticePage(QString title,QObject* parent) : QObject(parent) {
    this->v_title = title;
}

NoticePage::NoticePage(QString title,QString tr,QObject* parent) : QObject(parent) {
    this->v_title = title;
    this->v_tr = tr;
}

NoticePage::~NoticePage() {
    this->v_list.clear();
    this->v_title = "";
    this->v_tr = "";
}
