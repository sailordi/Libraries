#include "SQL_Query.h"

#include <QSqlDatabase>

//Public functions
SQL_Query::SQL_Query(QSqlDatabase db,bool transaction,QObject* parent) : QObject(parent) {
    this->v_db = db;
    this->v_transaction = transaction;
}

SQL_Query::~SQL_Query() {
    delete this->v_q;
    this->v_db = QSqlDatabase();
}
