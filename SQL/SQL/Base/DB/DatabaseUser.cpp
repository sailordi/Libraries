#include "DatabaseUser.h"

//Public functions
DatabaseUser::DatabaseUser(QObject* parent) : QObject (parent) {

}

DatabaseUser::DatabaseUser(DatabaseUser& dU,QObject* parent) : QObject (parent) {
    if(parent == nullptr && dU.parent() != nullptr) {
        this->setParent(dU.parent() );
    }

    this->v_usr = dU.v_usr;
    this->v_pass = dU.v_pass;
}

DatabaseUser::DatabaseUser(DatabaseUser* dU,QObject* parent) : QObject (parent) {
    if(parent == nullptr && dU->parent() != nullptr) {
        this->setParent(dU->parent() );
    }

    this->v_usr = dU->v_usr;
    this->v_pass = dU->v_pass;
}

DatabaseUser::~DatabaseUser() {

}

void DatabaseUser::setUsername(QString usr,bool emitsignal) {
    this->v_usr = usr;

    if(emitsignal == true) {
        emit this->infoChanged();
    }

}

void DatabaseUser::setPassword(QString pass,bool emitsignal) {
    this->v_pass = pass;

    if(emitsignal == true) {
        emit this->infoChanged();
    }

}

void DatabaseUser::setData(QString usr,QString pass,bool emitsignal) {
    this->setUsername(usr,false);
    this->setPassword(pass,emitsignal);
}
