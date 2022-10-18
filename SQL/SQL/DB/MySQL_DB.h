#ifndef MYSQL_DB_H
#define MYSQL_DB_H

#include <QObject>

#include "SQL/Base/DB/DB.h"
#include "SQL_global.h"

/*! \class MySQL_DB
 * \brief The class handles MySql database functionality
 *
 * Incudes: QObject, SQL_global.h & DB
 *
 * Inherits: DB
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2022-10-18
 * \date Last update: 2022-10-18
*/
class SQL_EXPORT MySQL_DB : public DB
{
    Q_OBJECT
public:
    /*! Constructor
     * \param connName - The connection name
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MySQL_DB(QString connName,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param i - The DatabaseInfo
     * \param u - The DatabaseUser
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MySQL_DB(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject *parent = nullptr);

    /*! Function to test database
     * \throws QString
    */
    virtual void test() override;

    /*! Database info changed */
    virtual void infoChanged() override;

protected:
    /*! Constructor
     * \param connName - The connection name
     * \param driver - The driver
     * \param parent - The parent [Default: nullptr]
    */
    explicit MySQL_DB(QString connName,QString driver,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param i - The DatabaseInfo
     * \param u - The DatabaseUser
     * \param driver - The driver
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MySQL_DB(QString connName,DatabaseInfo* i,DatabaseUser* u,QString driver,QObject *parent = nullptr);

};
#endif // MYSQL_DB_H
