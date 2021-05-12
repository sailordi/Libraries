#include "DB.h"

#include "SQL/Base/DB/DatabaseInfo.h"

//Public functions
DB::DB(QString connName,QObject* parent) : QObject(parent) {
    this->v_connName = connName;
}

DB::DB(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject* parent) : QObject(parent) {
    this->v_connName = connName;
}

DB::~DB() {
    QSqlDatabase d = QSqlDatabase::database(this->v_connName,false);

    if(d.isOpen() == true) {
        d.close();
    }

    d = QSqlDatabase();

    QSqlDatabase::removeDatabase(this->v_connName);

    emit this->removeConnection(this->v_connName);
}

void DB::setInfo(DatabaseInfo* i) {
    if(this->v_info != nullptr) {
        disconnect(this->v_info,&DatabaseInfo::infoChanged,this,&DB::dataChanged);
        this->v_info = nullptr;
    }

    if(i == nullptr) {
        return;
    }

    this->v_info = i;

    connect(this->v_info,&DatabaseInfo::infoChanged,this,&DB::dataChanged);
}

//Protected slot
void DB::dataChanged() {
    emit this->dataHasChanged();
}
