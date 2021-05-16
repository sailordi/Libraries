#include "SQLite_DB.h"

#include "Base/Other/Helper.h"

#include "SQL/Base/DB/DatabaseInfo.h"

//Public functions
SQLite_DB::SQLite_DB(QString connName,QObject* parent) : DB(connName,parent) {
    this->v_driver = "QSQLITE";
}

SQLite_DB::SQLite_DB(QString connName,DatabaseInfo* i,QObject* parent) : DB(connName,i,nullptr,parent) {
    this->v_driver = "QSQLITE";
}

void SQLite_DB::test() {
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

void SQLite_DB::infoChanged() {
    if(this->v_info  == nullptr) {
        throw QString("The DatabaseInfo is nullptr can not change info"+Helper::newRow() );
    }
    QSqlDatabase db = QSqlDatabase::database(this->v_connName,false);

    if(db.isOpen() == true) {
        DB::close(db);
    }

    db.setDatabaseName(this->v_info->databaseName() );
}
