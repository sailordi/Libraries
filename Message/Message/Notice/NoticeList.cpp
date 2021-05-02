#include "NoticeList.h"

//Public functions
NoticeList::NoticeList(QObject *parent) : QObject(parent) {

}

NoticeList::~NoticeList() {
    this->v_errors.clear();
    this->v_warnings.clear();
    this->v_messages.clear();
}
