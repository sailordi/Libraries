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
