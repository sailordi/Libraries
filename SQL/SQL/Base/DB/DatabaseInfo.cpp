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

void DatabaseInfo::setDatabaseName(QString name,bool emitSignal) {
    this->v_dbName = name;

    if(emitSignal == true) {
        emit this->infoChanged();
    }

}

void DatabaseInfo::setHostName(QString hostName,bool emitSignal) {
    this->v_hostName = hostName;

    if(emitSignal == true) {
        emit this->infoChanged();
    }

}

void DatabaseInfo::setPort(int port,bool emitSignal) {
    this->v_port = port;

    if(emitSignal == true) {
        emit this->infoChanged();
    }

}
