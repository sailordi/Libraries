#ifndef MYSQL_Db_H
#define MYSQL_Db_H

#include <QObject>

#include "SQL/Base/DB/Db.h"
#include "SQL_global.h"

/*! \class MySqlDb
 * \brief The class handles MySql database functionality
 *
 * Incudes: QObject, SQL_global.h & Db
 *
 * Inherits: Db
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2022-10-18
 * \date Last update: 2023-02-08
*/
class SQL_EXPORT MySqlDb : public Db
{
    Q_OBJECT
public:
    /*! Constructor
     * \param connName - The connection name
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MySqlDb(QString connName,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param i - The DatabaseInfo
     * \param u - The DatabaseUser
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MySqlDb(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param driver - The driver
     * \param parent - The parent [Default: nullptr]
    */
    explicit MySqlDb(QString connName,QString driver,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param driver - The driver
     * \param i - The DatabaseInfo
     * \param u - The DatabaseUser
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit MySqlDb(QString connName,QString driver,DatabaseInfo* i,DatabaseUser* u,QObject *parent = nullptr);

    /*! Function to test database
     * \throws QString
    */
    virtual void test() override;

    /*! Database info changed */
    virtual void infoChanged() override;


};
#endif // MYSQL_Db_H
