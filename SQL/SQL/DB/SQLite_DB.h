#ifndef SQLITE_DB_H
#define SQLITE_DB_H

#include <QObject>

#include "SQL/Base/DB/DB.h"
#include "SQL_global.h"

/*! \class SQLite_DB
 * \brief The class handles SQLite database functionality
 *
 * Incudes: QObject, SQL_global.h & DB
 *
 * Inherits: DB
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-16
 * \date Last update: 2021-05-16
*/
class SQL_EXPORT SQLite_DB : public DB
{
    Q_OBJECT
public:
    /*! Constructor
     * \param connName - The connection name
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit SQLite_DB(QString connName,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param i - The DatabaseInfo
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit SQLite_DB(QString connName,DatabaseInfo* i,QObject *parent = nullptr);

    /*! Function to test database
     * \throws QString
    */
    virtual void test() override;

};
#endif // SQLITE_DB_H
