#include "SQLite_DB.h"

//Public functions
SQLite_DB::SQLite_DB(QString connName,QObject* parent) : DB(connName,parent) {
    this->v_driver = "QSQLITE";
}

SQLite_DB::SQLite_DB(QString connName,DatabaseInfo* i,QObject* parent) : DB(connName,i,nullptr,parent) {
    this->v_driver = "QSQLITE";
}

