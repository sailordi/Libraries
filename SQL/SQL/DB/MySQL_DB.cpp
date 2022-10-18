#include "MySQL_DB.h"

#include "Base/Other/Helper.h"

#include "SQL/Base/DB/DatabaseInfo.h"
#include "SQL/Base/DB/DatabaseUser.h"

//Public functions
MySQL_DB::MySQL_DB(QString connName,QObject* parent) : DB(connName,parent) {
    this->v_driver = "QMYSQL";
}

MySQL_DB::MySQL_DB(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject* parent) : DB(connName,i,u,parent) {
    this->v_driver = "QMYSQL";
}

void MySQL_DB::test() {
    QString er = "";

        if(this->v_info == nullptr) {
            er = "The Database Info is nullptr"+Helper::newRow();
        }
        if(this->v_user == nullptr) {
            er = "The Database user is nullptr"+Helper::newRow();
        }

        if(this->v_info != nullptr && this->v_user != nullptr) {
            try {
                QSqlDatabase db = this->open();
            } catch(QString s) {
                er = s;
            }
        }

        if(er.isEmpty() == false) {
            throw er;
        }
}

void MySQL_DB::infoChanged() {
    if(this->v_info  == nullptr && this->v_user == nullptr) {
        throw QString("The DatabaseInfo is nullptr can not change info"+Helper::newRow()+"The Database user is nullptr"+Helper::newRow() );
    }
    if(this->v_info  == nullptr && this->v_user != nullptr) {
        throw QString("The DatabaseInfo is nullptr can not change info"+Helper::newRow() );
    }
    if(this->v_info  != nullptr && this->v_user == nullptr) {
        throw QString("The Database user is nullptr"+Helper::newRow() );
    }

    QSqlDatabase db = QSqlDatabase::database(this->v_connName,false);

    if(db.isOpen() == true) {
        DB::close(db);
    }

    db.setDatabaseName(this->v_info->databaseName() );
    db.setHostName(this->v_info->hostName() );
    if(this->v_info->port() >= 0) {
        db.setPort(this->v_info->port() );
    }
    db.setUserName(this->v_user->username() );
    db.setPassword(this->v_user->password() );
}

//Protected functions
MySQL_DB::MySQL_DB(QString connName,QString driver,QObject* parent) : DB(connName,parent) {
    this->v_driver = driver;
}

MySQL_DB::MySQL_DB(QString connName,DatabaseInfo* i,DatabaseUser* u,QString driver,QObject* parent) : DB(connName,i,u,parent) {
    this->v_driver = driver;
}
