#include "DatabaseInfo.h"

//Public functions
DatabaseInfo::DatabaseInfo(QObject *parent) : QObject(parent) {

}

DatabaseInfo::DatabaseInfo(QList<QVariant> n_h_p,QObject* parent) : QObject(parent) {

}

DatabaseInfo::DatabaseInfo(const DatabaseInfo& dI,QObject* parent) : QObject(parent) {
    if(parent == nullptr && dI.parent() != nullptr) {
        this->setParent(dI.parent() );
    }

    this->v_dbName = dI.v_dbName;
    this->v_hostName = dI.v_hostName;
    this->v_port = dI.v_port;
}

DatabaseInfo::DatabaseInfo(const DatabaseInfo* dI,QObject* parent) : QObject(parent) {
    if(parent == nullptr && dI->parent() != nullptr) {
        this->setParent(dI->parent() );
    }

    this->v_dbName = dI->v_dbName;
    this->v_hostName = dI->v_hostName;
    this->v_port = dI->v_port;
}

DatabaseInfo::~DatabaseInfo() {

}
