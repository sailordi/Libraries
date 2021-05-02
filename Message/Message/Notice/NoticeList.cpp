#include "NoticeList.h"

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
