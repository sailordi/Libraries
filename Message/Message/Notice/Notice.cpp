#include "Notice.h"

//Public functions
Notice::Notice(QString s,QObject* parent) : QObject(parent) {
    this->v_orig = s;
}

Notice::Notice(QString s,QString tr,QObject* parent) : QObject(parent) {
    this->v_orig = s;
    this->v_tr = tr;
}

Notice::Notice(QList<ArgReplacer> l,QString s,QObject* parent) : QObject(parent) {
    this->v_orig = s;
    this->v_data = l;
}

Notice::Notice(QList<ArgReplacer> l,QString s,QString tr,QObject* parent) : QObject(parent) {
    this->v_orig = s;
    this->v_tr = tr;
    this->v_data = l;
}

Notice::~Notice() {
    this->v_data.clear();
    this->v_tr = "";
    this->v_msg = "";
    this->v_orig = "";
}

void Notice::addArg(ArgReplacer a) {
    this->v_data.push_back(a);
    if(this->v_msg.isEmpty() == false) {
        this->v_msg = "";
    }
}

