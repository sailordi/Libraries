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
