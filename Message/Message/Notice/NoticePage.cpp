#include "NoticePage.h"

#include <cassert>

#include "Message/Notice/NoticeList.h"

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

void NoticePage::add(NoticeList* n) {
    this->add(NoticeListP(n) );
}

void NoticePage::add(NoticeListP n) {
    this->v_list.push_back(n);
}

NoticeListP NoticePage::list(int pos) {
    assert(pos > -1 && pos < this->v_list.size() );

    return this->v_list.at(pos);
}

void NoticePage::setTitle(QString title) {
    this->v_title = title;
    this->v_tr = "";
}

void NoticePage::setTitle(QString title,QString tr) {
    this->v_title = title;
    this->v_tr = tr;
}

QString NoticePage::title() {
    return this->v_title;
}

bool NoticePage::isEmpty() {
    return (this->v_list.size() <= 0) ? true : false;
}

int NoticePage::size() {
    return this->v_list.size();
}

void NoticePage::reTranslate() {
    if(this->v_tr.isEmpty() == false) {
        this->v_title = NoticePage::tr(this->v_tr.toStdString().c_str() );
    }

    for(int i = 0; i < this->v_list.size(); i++) {
        this->v_list.at(i)->reTranslate();
    }
}
