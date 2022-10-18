#include "SqlQueryData.h"

//Public functions
SqlQueryData::SqlQueryData() {

}

SqlQueryData::SqlQueryData(QString q) {
    this->v_qStr = q;
}

SqlQueryData::~SqlQueryData() {
    this->v_qStr = "";
    this->v_bindL.clear();
}

void SqlQueryData::setQuery(QString q) {
    this->v_qStr = q;
}

void SqlQueryData::setQuery(QString q,QList<SqlQueryBind>& l) {
    this->clear();

    this->v_qStr = q;

    while(l.size() > 0) {
        this->v_bindL.push_back(QSharedPointer<SqlQueryBind>(new SqlQueryBind(l.takeFirst() ) ) );
    }

}

void SqlQueryData::setQuery(QString q,QList<SqlQueryBind*>& l) {
    this->clear();

    this->v_qStr = q;

    while(l.size() > 0) {
        this->v_bindL.push_back(QSharedPointer<SqlQueryBind>(l.takeFirst() ) );
    }

}

void SqlQueryData::addBindValue(SqlQueryBind b) {
    this->v_bindL.push_back(QSharedPointer<SqlQueryBind>(new SqlQueryBind(b) ) );
}

void SqlQueryData::addBindValue(SqlQueryBind* b) {
    this->v_bindL.push_back(QSharedPointer<SqlQueryBind>(new SqlQueryBind(b) ) );
}

void SqlQueryData::addBindVaues(QList<SqlQueryBind>& l) {
    while(l.size() > 0) {
        this->v_bindL.push_front(QSharedPointer<SqlQueryBind>(new SqlQueryBind(l.takeFirst() ) ) );
    }
}

void SqlQueryData::addBindVaues(QList<SqlQueryBind*>& l) {
    while(l.size() > 0) {
        this->v_bindL.push_front(QSharedPointer<SqlQueryBind>(l.takeFirst() ) );
    }
}

void SqlQueryData::setBindVaues(QList<SqlQueryBind>& l) {
    this->v_bindL.clear();

    while(l.size() > 0) {
        this->v_bindL.push_back(QSharedPointer<SqlQueryBind>(new SqlQueryBind(l.takeFirst() ) ) );
    }
}

void SqlQueryData::setBindVaues(QList<SqlQueryBind*>& l) {
    this->v_bindL.clear();

    while(l.size() > 0) {
        this->v_bindL.push_back(QSharedPointer<SqlQueryBind>(l.takeFirst() ) );
    }
}

void SqlQueryData::clear() {
    this->v_qStr = "";

    this->v_bindL.clear();
}

bool SqlQueryData::boundListEmpty() {
    return this->v_bindL.isEmpty();
}
