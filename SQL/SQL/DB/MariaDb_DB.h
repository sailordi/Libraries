#ifndef MARIADB_DB_H
#define MARIADB_DB_H

#include <QObject>

#include "SQL/DB/MySQL_DB.h"
#include "SQL_global.h"

/*! \class MariaDb_DB
 * \brief The class handles MariaDb database functionality
 *
 * Incudes: QObject, SQL_global.h & DB
 *
 * Inherits: MySQL_DB
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2022-10-18
 * \date Last update: 2022-10-18
*/
class SQL_EXPORT MariaDb_DB : public MySQL_DB
{
    Q_OBJECT
public:
    /*! Constructor
     * \param connName - The connection name
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MariaDb_DB(QString connName,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param i - The DatabaseInfo
     * \param u - The DatabaseUser
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MariaDb_DB(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject *parent = nullptr);

};
#endif // MARIADB_DB_H
