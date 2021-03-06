#include "SQL_QueryData.h"

//Public functions
SQL_QueryData::SQL_QueryData() {

}

SQL_QueryData::SQL_QueryData(QString q) {
    this->v_qStr = q;
}

SQL_QueryData::~SQL_QueryData() {
    this->v_qStr = "";
    this->v_bindL.clear();
}

void SQL_QueryData::setQuery(QString q) {
    this->v_qStr = q;
}

void SQL_QueryData::setQuery(QString q,QList<SQL_Bind>& l) {
    this->clear();

    this->v_qStr = q;

    while(l.size() > 0) {
        this->v_bindL.push_back(QSharedPointer<SQL_Bind>(new SQL_Bind(l.takeFirst() ) ) );
    }

}

void SQL_QueryData::setQuery(QString q,QList<SQL_Bind*>& l) {
    this->clear();

    this->v_qStr = q;

    while(l.size() > 0) {
        this->v_bindL.push_back(QSharedPointer<SQL_Bind>(l.takeFirst() ) );
    }

}

void SQL_QueryData::addBindValue(SQL_Bind b) {
    this->v_bindL.push_back(QSharedPointer<SQL_Bind>(new SQL_Bind(b) ) );
}

void SQL_QueryData::addBindValue(SQL_Bind* b) {
    this->v_bindL.push_back(QSharedPointer<SQL_Bind>(new SQL_Bind(b) ) );
}

void SQL_QueryData::addBindVaues(QList<SQL_Bind>& l) {
    while(l.size() > 0) {
        this->v_bindL.push_front(QSharedPointer<SQL_Bind>(new SQL_Bind(l.takeFirst() ) ) );
    }
}

void SQL_QueryData::addBindVaues(QList<SQL_Bind*>& l) {
    while(l.size() > 0) {
        this->v_bindL.push_front(QSharedPointer<SQL_Bind>(l.takeFirst() ) );
    }
}

void SQL_QueryData::setBindVaues(QList<SQL_Bind>& l) {
    this->v_bindL.clear();

    while(l.size() > 0) {
        this->v_bindL.push_back(QSharedPointer<SQL_Bind>(new SQL_Bind(l.takeFirst() ) ) );
    }
}

void SQL_QueryData::setBindVaues(QList<SQL_Bind*>& l) {
    this->v_bindL.clear();

    while(l.size() > 0) {
        this->v_bindL.push_back(QSharedPointer<SQL_Bind>(l.takeFirst() ) );
    }
}

void SQL_QueryData::clear() {
    this->v_qStr = "";

    this->v_bindL.clear();
}

bool SQL_QueryData::boundListEmpty() {
    return this->v_bindL.isEmpty();
}
