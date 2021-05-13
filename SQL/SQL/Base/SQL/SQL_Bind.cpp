#include "SQL_Bind.h"

//Public functions
SQL_Bind::SQL_Bind(QString key,QObject* parent) : QObject(parent) {
    this->v_key = key;
}

SQL_Bind::SQL_Bind(QString key,QVariant val,QObject* parent) : QObject(parent) {
    this->v_key = key;
    this->v_val = val;
}

SQL_Bind::SQL_Bind(const SQL_Bind& b,QObject* parent) : QObject(parent) {
    if(parent == nullptr && b.parent() != nullptr) {
        this->setParent(b.parent() );
    }

    this->v_key = b.v_key;
    this->v_val = b.v_val;
}

SQL_Bind::SQL_Bind(const SQL_Bind* b,QObject* parent) : QObject(parent) {
    if(parent == nullptr && b->parent() != nullptr) {
        this->setParent(b->parent() );
    }

    this->v_key = b->v_key;
    this->v_val = b->v_val;
}

SQL_Bind::~SQL_Bind() {

}


//Protected functions
SQL_Bind::SQL_Bind(QObject* parent) : QObject(parent) {

}
