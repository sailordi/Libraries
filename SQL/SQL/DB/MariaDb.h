#ifndef MARIADb_Db_H
#define MARIADb_Db_H

#include <QObject>

#include "SQL/DB/MySqlDb.h"
#include "SQL_global.h"

/*! \class MariaDb
 * \brief The class handles MariaDb database functionality
 *
 * Incudes: QObject, SQL_global.h & Db
 *
 * Inherits: MySqlDb
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2022-10-18
 * \date Last update: 2023-03-08
*/
class SQL_EXPORT MariaDb : public MySqlDb
{
    Q_OBJECT
public:
    /*! Constructor
     * \param connName - The connection name
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MariaDb(QString connName,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param i - The DatabaseInfo
     * \param u - The DatabaseUser
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MariaDb(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param driver - The driver
     * \param parent - The parent [Default: nullptr]
    */
    explicit MariaDb(QString connName,QString driver,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param driver - The driver
     * \param i - The DatabaseInfo
     * \param u - The DatabaseUser
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MariaDb(QString connName,QString driver,DatabaseInfo* i,DatabaseUser* u,QObject *parent = nullptr);


};
#endif // MARIADb_Db_H
