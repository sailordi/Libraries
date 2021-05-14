#ifndef SQL_QUERY_H
#define SQL_QUERY_H

#include <QObject>
#include <QString>
#include <QSqlQuery>

#include "SQL_global.h"

class SQL_QueryData;
class QSqlDatabase;

/*! \class SQL_Query
 * \brief The class handles SQL queries
 *
 * Incudes: Object, QString, QSqlRecord, QSqlQuery & SQL_global.h
 *
 * Forward declarations: SQL_QueryData & QSqlDatabase
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-14
 * \date Last update: 2021-05-14
*/
class SQL_EXPORT SQL_Query : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param db - Pointer to the database
     * \param transaction - If transaction should be used
     * \param parent - The parent [Default: nullptr]
    */
    explicit SQL_Query(QSqlDatabase db,bool transaction,QObject* parent = nullptr);
    /*! Deconstructor */
    virtual ~SQL_Query();

protected:
    QSqlDatabase v_db;
    QSqlQuery* v_q = nullptr;
    bool v_transaction;

    /*! Beggins a transaction
     * \throws QString
    */
    void transaction();
    /*! Commits changes to the database
     * \throws QString
    */
    void commit();

};
#endif // SQL_QUERY_H
