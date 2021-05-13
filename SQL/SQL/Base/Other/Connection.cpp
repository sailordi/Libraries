#include "Connection.h"

//Public functions
Connection::Connection(QObject* parent) : QObject(parent) {

}

Connection::Connection(Connection& c,QObject* parent) : QObject(parent) {
    if(parent == nullptr && c.parent() != nullptr) {
        this->setParent(c.parent() );
    }

    for(int i = 0; i < c.v_cons.size(); i++) {
        this->v_cons.push_back(c.v_cons.at(i) );
    }

}

Connection::Connection(Connection* c,QObject* parent) : QObject(parent) {
    if(parent == nullptr && c->parent() != nullptr) {
        this->setParent(c->parent() );
    }

    for(int i = 0; i < c->v_cons.size(); i++) {
        this->v_cons.push_back(c->v_cons.at(i) );
    }

}

Connection::~Connection() {
    this->v_cons.clear();
}

//Private functions
QStringList Connection::getBaseConnectionStr() {
    QStringList r({"TEST_CON_","INSERT_CON_","SELECT_CON_","UPDATE_CON_","CREATE_CON_","REMOVE_CON_","MODEL_CON_","OTHER_CON_"});

        return r;
}
