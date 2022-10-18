#include "SqlQuery.h"

#include <QSqlDatabase>
#include <QSqlError>

#include "Base/Other/Helper.h"

#include "SQL/Base/DB/DB.h"
#include "SQL/Base/Query/SqlQueryBind.h"
#include "SQL/Base/Query/SqlQueryData.h"

//Public functions
SqlQuery::SqlQuery(QSqlDatabase db,bool transaction,QObject* parent) : QObject(parent) {
    this->v_db = db;
    this->v_transaction = transaction;

    this->transaction();
}

SqlQuery::~SqlQuery() {
    this->finishTransaction();
    this->finishQuery();

    this->v_db = QSqlDatabase();
}

void SqlQuery::setDatabase(QSqlDatabase db) {
    this->v_db = db;
}

int SqlQuery::rowsAffected(bool select) {
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

void SqlQuery::exec(QString query) {
    if(this->v_q == nullptr) {
        this->v_q = new QSqlQuery(this->v_db);
    }

    if(this->v_q->exec(query+";") == false) {
        throw this->v_q->lastError().text()+Helper::newRow();
    }

}

void SqlQuery::exec(SqlQueryData qD) {
    if(qD.v_bindL.size() == 0) {
        this->exec(qD.v_qStr);
        return;
    }

    if(this->v_q == nullptr) {
        this->v_q = new QSqlQuery(this->v_db);
    }

    this->v_q->prepare(qD.v_qStr+";");

    for(int i = 0; i < qD.v_bindL.size(); i++) {
        SqlQueryBind b = *qD.v_bindL.at(i);
        this->v_q->bindValue(b.key(),b.value() );
    }

    if(this->v_q->exec() == false) {
        throw this->v_q->lastError().text()+Helper::newRow();
    }

}

void SqlQuery::finishQuery() {
    if(this->v_q != nullptr) {
        this->v_q->finish();

        delete this->v_q;
        this->v_q = nullptr;
    }

}

void SqlQuery::finishTransaction() {
    this->commit();
}

void SqlQuery::nextRecord() {
    this->v_q->next();
}

QSqlRecord SqlQuery::record(bool nextRecord) {
    QSqlRecord r = this->v_q->record();

        if(nextRecord == true) {
            this->nextRecord();
        }

        return r;
}

QVariant SqlQuery::recordValue(QString c,bool nextRecord) {
    QVariant r = this->v_q->value(c);

        if(nextRecord == true) {
            this->nextRecord();
        }

        return r;
}

QVariant SqlQuery::recordValue(int v,bool nextRecord) {
    QVariant r = this->v_q->value(v);

        if(nextRecord == true) {
            this->nextRecord();
        }

        return r;
}

//Public slots
void SqlQuery::dataChange() {
    this->finishTransaction();
    this->finishQuery();
    this->v_db = QSqlDatabase();
}

//Protected functions
void SqlQuery::transaction() {
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

void SqlQuery::commit() {
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

void SqlQuery::rollback(QString& er) {
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
