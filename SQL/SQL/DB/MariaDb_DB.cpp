#include "MariaDb_DB.h"

MariaDb_DB::MariaDb_DB(QString connName,QObject* parent) : MySQL_DB(connName,"MARIADB",parent) {

}

MariaDb_DB::MariaDb_DB(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject* parent) : MySQL_DB(connName,i,u,"MARIADB",parent) {

}
