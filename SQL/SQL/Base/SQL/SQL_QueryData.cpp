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
    this->v_qStr = q;

    while(l.size() > 0) {
        this->v_bindL.push_back(QSharedPointer<SQL_Bind>(new SQL_Bind(l.takeFirst() ) ) );
    }

}

void SQL_QueryData::setQuery(QString q,QList<SQL_Bind*>& l) {
    this->v_qStr = q;

    while(l.size() > 0) {
        this->v_bindL.push_back(QSharedPointer<SQL_Bind>(l.takeFirst() ) );
    }

}
