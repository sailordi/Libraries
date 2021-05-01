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

void Notice::addArgs(QList<ArgReplacer> l) {
    for(int i = 0; i < l.size(); i++) {
        this->v_data.push_back(l.at(i) );
    }
    if(this->v_msg.isEmpty() == false) {
        this->v_msg = "";
    }
}

void Notice::setArgs(QList<ArgReplacer> l) {
    this->v_data = l;
    if(this->v_msg.isEmpty() == false) {
        this->v_msg = "";
    }
}

QString Notice::msg() {
    if(this->v_msg.isEmpty() == false) {
        return this->v_msg;
    }

    this->v_msg = this->v_orig;

    if(this->v_data.isEmpty() == true) {
        return this->v_msg;
    }

    for(int i = 0; i < this->v_data.size(); i++) {
        ArgReplacer p = this->v_data.at(i);

        this->v_msg.replace(p.first,p.second);
    }

    return this->v_msg;
}
