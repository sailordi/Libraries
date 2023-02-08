#include "SqLiteDb.h"

#include "Base/Other/Helper.h"

#include "SQL/Base/DB/DatabaseInfo.h"

//Public functions
SqLiteDb::SqLiteDb(QString connName,QObject* parent) : Db(connName,parent) {
    this->v_driver = "QSQLITE";
}

SqLiteDb::SqLiteDb(QString connName,DatabaseInfo* i,QObject* parent) : Db(connName,i,nullptr,parent) {
    this->v_driver = "QSQLITE";
}

SqLiteDb::SqLiteDb(QString connName,QString driver,QObject* parent) : Db(connName,parent) {
    this->v_driver = driver;
}

SqLiteDb::SqLiteDb(QString connName,QString driver,DatabaseInfo* i,QObject* parent) : Db(connName,i,nullptr,parent) {
    this->v_driver = driver;
}

void SqLiteDb::test() {
    QString er = "";

        if(this->v_info == nullptr) {
            er = "The Database Info is nullptr"+Helper::newRow();
        }
        else {
            try {
                QSqlDatabase db = this->open();
            } catch(QString s) {
                er = s;
            }
        }

        if(er.isEmpty() == false) {
            throw er;
        }
}

void SqLiteDb::infoChanged() {
    if(this->v_info  == nullptr) {
        throw QString("The DatabaseInfo is nullptr can not change info"+Helper::newRow() );
    }
    QSqlDatabase db = QSqlDatabase::database(this->v_connName,false);

    if(db.isOpen() == true) {
        Db::close(db);
    }

    db.setDatabaseName(this->v_info->databaseName() );
}
