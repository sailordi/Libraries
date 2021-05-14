#include "SQL_Query.h"

#include <QSqlDatabase>
#include <QSqlError>

#include "Base/Other/Helper.h"

#include "SQL/Base/DB/DB.h"

//Public functions
SQL_Query::SQL_Query(QSqlDatabase db,bool transaction,QObject* parent) : QObject(parent) {
    this->v_db = db;
    this->v_transaction = transaction;

    this->transaction();
}

SQL_Query::~SQL_Query() {
    delete this->v_q;
    this->v_db = QSqlDatabase();
}

//Protected functions
void SQL_Query::transaction() {
    if(this->v_transaction == false) {
        return;
    }
    if(DB::hasTransaction(this->v_db) == false) {
        return;
    }

    if(this->v_db.transaction() == false) {
        QString er = this->v_db.lastError().text()+Helper::newRow(2);
        this->rollback(er);
        throw er;
    }

}

void SQL_Query::commit() {
    if(this->v_transaction == false) {
        return;
    }
    if(DB::hasTransaction(this->v_db) == false) {
        return;
    }

    if(this->v_db.commit() == false) {
        QString er = this->v_db.lastError().text()+Helper::newRow(2);
        this->rollback(er);
        throw er;
    }

}

void SQL_Query::rollback(QString& er) {
    if(this->v_transaction == false) {
        return;
    }
    if(DB::hasTransaction(this->v_db) == false) {
        return;
    }

    if(this->v_db.rollback() == false) {
        er.append(this->v_db.lastError().text()+Helper::newRow() );
    }

}
