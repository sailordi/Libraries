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

int SQL_Query::rowsAffected(bool select) {
    if(this->v_q == nullptr) {
        return -1;
    }

    if(DB::hasSize(this->v_db) == true && select == false) {
        return this->v_q->numRowsAffected();
    }
    else if(DB::hasSize(this->v_db) == true && select == true) {
        return this->v_q->size();
    }

    this->v_q->last();

    int ret = this->v_q->at() + 1;

    this->v_q->first();

    return ret;
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
