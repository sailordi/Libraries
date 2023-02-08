#ifndef SQLITE_Db_H
#define SQLITE_Db_H

#include <QObject>

#include "SQL/Base/DB/Db.h"
#include "SQL_global.h"

/*! \class SqLiteDb
 * \brief The class handles SQLite database functionality
 *
 * Incudes: QObject, SQL_global.h & Db
 *
 * Inherits: Db
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-16
 * \date Last update: 2023-03-08
*/
class SQL_EXPORT SqLiteDb : public Db
{
    Q_OBJECT
public:
    /*! Constructor
     * \param connName - The connection name
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit SqLiteDb(QString connName,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param i - The DatabaseInfo
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit SqLiteDb(QString connName,DatabaseInfo* i,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param driver - The driver
     * \param parent - The parent [Default: nullptr]
    */
    explicit SqLiteDb(QString connName,QString driver,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param driver - The driver
     * \param i - The DatabaseInfo
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit SqLiteDb(QString connName,QString driver,DatabaseInfo* i,QObject *parent = nullptr);

    /*! Function to test database
     * \throws QString
    */
    virtual void test() override;

    /*! Database info changed */
    virtual void infoChanged() override;

};
#endif // SQLITE_Db_H
