#include "SqlQueryBind.h"

//Public functions
SqlQueryBind::SqlQueryBind(QString key,QObject* parent) : QObject(parent) {
    this->v_key = key;
}

SqlQueryBind::SqlQueryBind(QString key,QVariant val,QObject* parent) : QObject(parent) {
    this->v_key = key;
    this->v_val = val;
}

SqlQueryBind::SqlQueryBind(const SqlQueryBind& b,QObject* parent) : QObject(parent) {
    if(parent == nullptr && b.parent() != nullptr) {
        this->setParent(b.parent() );
    }

    this->v_key = b.v_key;
    this->v_val = b.v_val;
}

SqlQueryBind::SqlQueryBind(const SqlQueryBind* b,QObject* parent) : QObject(parent) {
    if(parent == nullptr && b->parent() != nullptr) {
        this->setParent(b->parent() );
    }

    this->v_key = b->v_key;
    this->v_val = b->v_val;
}

SqlQueryBind::~SqlQueryBind() {

}

void SqlQueryBind::setKey(QString key) {
    this->v_key = key;
}

void SqlQueryBind::setValue(QVariant val) {
    this->v_val = val;
}

void SqlQueryBind::setData(QString key, QVariant val) {
    this->setKey(key);
    this->setValue(val);
}

QString SqlQueryBind::key() {
    return this->v_key;
}

QVariant SqlQueryBind::value() {
    return this->v_val;
}

//Protected functions
SqlQueryBind::SqlQueryBind(QObject* parent) : QObject(parent) {

}
