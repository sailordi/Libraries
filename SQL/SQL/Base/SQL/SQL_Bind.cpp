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

void SQL_Bind::setKey(QString key) {
    this->v_key = key;
}

void SQL_Bind::setValue(QVariant val) {
    this->v_val = val;
}

void SQL_Bind::setData(QString key, QVariant val) {
    this->setKey(key);
    this->setValue(val);
}

QString SQL_Bind::key() {
    return this->v_key;
}


//Protected functions
SQL_Bind::SQL_Bind(QObject* parent) : QObject(parent) {

}
