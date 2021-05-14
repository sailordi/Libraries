#include "SQL_Query.h"

#include <QSqlDatabase>
#include <QSqlError>

#include "Base/Other/Helper.h"

#include "SQL/Base/DB/DB.h"
#include "SQL/Base/SQL/SQL_Bind.h"
#include "SQL/Base/SQL/SQL_QueryData.h"

//Public functions
SQL_Query::SQL_Query(QSqlDatabase db,bool transaction,QObject* parent) : QObject(parent) {
    this->v_db = db;
    this->v_transaction = transaction;

    this->transaction();
}

SQL_Query::~SQL_Query() {
    this->finishTransaction();
    this->finishQuery();

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

void SQL_Query::exec(QString query) {
    if(this->v_q == nullptr) {
        this->v_q = new QSqlQuery(this->v_db);
    }

    if(this->v_q->exec(query+";") == false) {
        throw this->v_q->lastError().text()+Helper::newRow();
    }

}

void SQL_Query::exec(SQL_QueryData qD) {
    if(qD.v_bindL.size() == 0) {
        this->exec(qD.v_qStr);
        return;
    }

    if(this->v_q == nullptr) {
        this->v_q = new QSqlQuery(this->v_db);
    }

    this->v_q->prepare(qD.v_qStr+";");

    for(int i = 0; i < qD.v_bindL.size(); i++) {
        SQL_Bind b = *qD.v_bindL.at(i);
        this->v_q->bindValue(b.key(),b.value() );
    }

    if(this->v_q->exec() == false) {
        throw this->v_q->lastError().text()+Helper::newRow();
    }

}

void SQL_Query::finishQuery() {
    if(this->v_q != nullptr) {
        this->v_q->finish();

        delete this->v_q;
        this->v_q = nullptr;
    }

}

void SQL_Query::finishTransaction() {
    this->commit();
}

void SQL_Query::nextRecord() {
    this->v_q->next();
}

QSqlRecord SQL_Query::record(bool nextRecord) {
    QSqlRecord r = this->v_q->record();

        if(nextRecord == true) {
            this->nextRecord();
        }

        return r;
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
