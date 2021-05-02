#include "NoticeList.h"

#include <cassert>

//Public functions
NoticeList::NoticeList(QObject *parent) : QObject(parent) {

}

NoticeList::~NoticeList() {
    this->v_errors.clear();
    this->v_warnings.clear();
    this->v_messages.clear();
}

void NoticeList::add(Notice* n,NoticeFlag flag) {
    this->add(NoticeP(n),flag);
}

void NoticeList::add(NoticeP n,NoticeFlag flag) {
    switch(flag) {
        case NoticeFlag::ERROR :
            this->v_errors.push_back(n);
            break;
        case NoticeFlag::WARNING:
            this->v_warnings.push_back(n);
            break;
        case NoticeFlag::MESSAGE:
            this->v_messages.push_back(n);
            break;
    }
}

bool NoticeList::hasMessage(NoticeFlag flag) {
    switch(flag) {
        case NoticeFlag::ERROR :
            return (this->v_errors.size() > 0) ? true : false;
        case NoticeFlag::WARNING:
            return (this->v_warnings.size() > 0) ? true : false;
        case NoticeFlag::MESSAGE:
            return (this->v_messages.size() > 0) ? true : false;
    }

    return false;
}

bool NoticeList::hasMessage() {
    if(this->hasMessage(NoticeFlag::ERROR) == true) {
        return true;
    }
    if(this->hasMessage(NoticeFlag::WARNING) == true) {
        return true;
    }
    if(this->hasMessage(NoticeFlag::MESSAGE) == true) {
        return true;
    }

    return false;
}

int NoticeList::size(NoticeFlag flag) {
    switch(flag) {
        case NoticeFlag::ERROR:
            return this->v_errors.size();
        case NoticeFlag::WARNING:
            return this->v_warnings.size();
        case NoticeFlag::MESSAGE:
            return this->v_messages.size();
    }

    return -1;
}

QString NoticeList::msg(int pos,NoticeFlag flag) {
    assert(pos > -1 && pos < this->size(flag) );

    switch(flag) {
        case NoticeFlag::ERROR:
            return this->v_errors.at(pos)->msg();
        case NoticeFlag::WARNING:
            return this->v_warnings.at(pos)->msg();
        case NoticeFlag::MESSAGE:
            return this->v_messages.at(pos)->msg();
    }

    return "";
}

void NoticeList::reTranslate() {
    for(int i = 0; i < this->v_errors.size(); i++) {
        this->v_errors.at(i)->reTranslate();
    }
    for(int i = 0; i < this->v_warnings.size(); i++) {
        this->v_warnings.at(i)->reTranslate();
    }
    for(int i = 0; i < this->v_messages.size(); i++) {
        this->v_messages.at(i)->reTranslate();
    }
}

void NoticeList::clear() {
    this->v_errors.clear();
    this->v_warnings.clear();
    this->v_messages.clear();
}
