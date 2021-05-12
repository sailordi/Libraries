#include "DB.h"

#include <QSqlDriver>
#include <QSqlError>

#include "Base/Other/Helper.h"
#include "SQL/Base/DB/DatabaseInfo.h"
#include "SQL/Base/DB/DatabaseUser.h"

//Public functions
DB::DB(QString connName,QObject* parent) : QObject(parent) {
    this->v_connName = connName;
}

DB::DB(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject* parent) : QObject(parent) {
    this->v_connName = connName;
    this->setData(i,u);
}

DB::~DB() {
    this->setData(nullptr,nullptr);

    QSqlDatabase d = QSqlDatabase::database(this->v_connName,false);

    if(d.isOpen() == true) {
        d.close();
    }

    d = QSqlDatabase();

    QSqlDatabase::removeDatabase(this->v_connName);

    emit this->removeConnection(this->v_connName);
}

void DB::setInfo(DatabaseInfo* i) {
    if(this->v_info != nullptr) {
        disconnect(this->v_info,&DatabaseInfo::infoChanged,this,&DB::dataChanged);
        this->v_info = nullptr;
    }

    if(i == nullptr) {
        return;
    }

    this->v_info = i;

    connect(this->v_info,&DatabaseInfo::infoChanged,this,&DB::dataChanged);
}

void DB::setUser(DatabaseUser* u) {
    if(this->v_user != nullptr) {
        disconnect(this->v_user,&DatabaseUser::infoChanged,this,&DB::dataChanged);

        this->v_user = nullptr;
    }

    if(u == nullptr) {
        return;
    }

    this->v_user = u;

    connect(this->v_user,&DatabaseUser::infoChanged,this,&DB::dataChanged);
}

void DB::setData(DatabaseInfo* i,DatabaseUser* u) {
    this->setInfo(i);
    this->setUser(u);
}

bool DB::hasSize(QSqlDatabase db) {
    if(db.isValid() == false) {
        return false;
    }

    return db.driver()->hasFeature(QSqlDriver::QuerySize);
}

bool DB::hasTransaction(QSqlDatabase db) {
    if(db.isValid() == false) {
        return false;
    }

    return db.driver()->hasFeature(QSqlDriver::Transactions);
}

void DB::initDB() {
    if(QSqlDatabase::connectionNames().contains(this->v_connName) == false) {
        QSqlDatabase d = QSqlDatabase::addDatabase(this->v_driver,this->v_connName);
    }
    this->infoChanged();
}

QSqlDatabase DB::open() {
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

void DB::open(QSqlDatabase db) {
    if(db.isOpen() == false) {
        if(db.open() == false) {
            throw QString("Error can not open database:"+Helper::newRow() )+db.lastError().text();
        }
    }

}

//Protected slot
void DB::dataChanged() {
    emit this->dataHasChanged();

    this->infoChanged();
}
