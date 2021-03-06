#include "DatabaseInfo.h"

//Public functions
DatabaseInfo::DatabaseInfo(QObject *parent) : QObject(parent) {

}

DatabaseInfo::DatabaseInfo(QList<QVariant> n_h_p,QObject* parent) : QObject(parent) {
    this->setData(n_h_p);
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

void DatabaseInfo::setData(QList<QVariant> n_h_p,bool emitSignal) {
    this->v_dbName = n_h_p.takeFirst().toString();
    this->v_hostName = n_h_p.takeFirst().toString();
    this->v_port = n_h_p.takeFirst().toInt();

    if(emitSignal == true) {
        emit this->infoChanged();
    }

}

QString DatabaseInfo::databaseName() {
    return this->v_dbName;
}

QString DatabaseInfo::hostName() {
    return this->v_hostName;
}

int DatabaseInfo::port() {
    return this->v_port;
}
