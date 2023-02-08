#include "Db.h"

#include <QSqlDriver>
#include <QSqlError>

#include "Base/Other/Helper.h"
#include "SQL/Base/DB/DatabaseInfo.h"
#include "SQL/Base/DB/DatabaseUser.h"

//Public functions
Db::Db(QString connName,QObject* parent) : QObject(parent) {
    this->v_connName = connName;
}

Db::Db(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject* parent) : QObject(parent) {
    this->v_connName = connName;
    this->setData(i,u);
}

Db::~Db() {
    this->setData(nullptr,nullptr);

    QSqlDatabase d = QSqlDatabase::database(this->v_connName,false);

    if(d.isOpen() == true) {
        d.close();
    }

    d = QSqlDatabase();

    QSqlDatabase::removeDatabase(this->v_connName);

    emit this->removeConnection(this->v_connName);
}

void Db::setInfo(DatabaseInfo* i) {
    if(this->v_info != nullptr) {
        disconnect(this->v_info,&DatabaseInfo::infoChanged,this,&Db::dataChanged);
        this->v_info = nullptr;
    }

    if(i == nullptr) {
        return;
    }

    this->v_info = i;

    connect(this->v_info,&DatabaseInfo::infoChanged,this,&Db::dataChanged);
}

void Db::setUser(DatabaseUser* u) {
    if(this->v_user != nullptr) {
        disconnect(this->v_user,&DatabaseUser::infoChanged,this,&Db::dataChanged);

        this->v_user = nullptr;
    }

    if(u == nullptr) {
        return;
    }

    this->v_user = u;

    connect(this->v_user,&DatabaseUser::infoChanged,this,&Db::dataChanged);
}

void Db::setData(DatabaseInfo* i,DatabaseUser* u) {
    this->setInfo(i);
    this->setUser(u);
}

bool Db::hasSize(QSqlDatabase db) {
    if(db.isValid() == false) {
        return false;
    }

    return db.driver()->hasFeature(QSqlDriver::QuerySize);
}

bool Db::hasTransaction(QSqlDatabase db) {
    if(db.isValid() == false) {
        return false;
    }

    return db.driver()->hasFeature(QSqlDriver::Transactions);
}

void Db::initDb() {
    if(QSqlDatabase::connectionNames().contains(this->v_connName) == false) {
        QSqlDatabase d = QSqlDatabase::addDatabase(this->v_driver,this->v_connName);
    }
    this->infoChanged();
}

QSqlDatabase Db::open() {
    QSqlDatabase db = QSqlDatabase::database(this->v_connName);

    if(db.isValid() == false) {
        throw QString("Error database not valid can not open database:"+Helper::newRow() )+db.lastError().text();
    }
    if(db.isOpen() == false) {
        if(db.open() == false) {
            throw QString("Error can not open database:"+Helper::newRow() )+db.lastError().text();
        }
    }

    return db;
}

void Db::open(QSqlDatabase db) {
    if(db.isOpen() == false) {
        if(db.open() == false) {
            throw QString("Error can not open database:"+Helper::newRow() )+db.lastError().text();
        }
    }

}

void Db::close(QSqlDatabase db) {
    if(db.isOpen() == true) {
        db.close();
    }

}

//Protected slot
void Db::dataChanged() {
    emit this->dataHasChanged();

    this->infoChanged();
}
