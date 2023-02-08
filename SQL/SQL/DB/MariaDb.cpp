#include "MariaDb.h"

MariaDb::MariaDb(QString connName,QObject* parent) : MySqlDb(connName,"QMARIADB",parent) {

}

MariaDb::MariaDb(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject* parent) : MySqlDb(connName,"QMARIADB",i,u,parent) {

}

MariaDb::MariaDb(QString connName,QString driver,QObject* parent) : MySqlDb(connName,driver,parent) {

}

MariaDb::MariaDb(QString connName,QString driver,DatabaseInfo* i,DatabaseUser* u,QObject* parent) : MySqlDb(connName,driver,i,u,parent) {

}
