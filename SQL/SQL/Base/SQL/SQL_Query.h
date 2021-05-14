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

    /*! Checks the number of rows affected by the query
     * \param select - If selection query was used [Default: true]
    */
    virtual int rowsAffected(bool select = true);

    /*! Executes a query
     * \param query - The query str
     * \throws QString
    */
    virtual void exec(QString query);
    /*! Executes a query
     * \param qD – The SQL_QueryData
     * \throws QString
    */
    virtual void exec(SQL_QueryData qD);

    /*! Finishes a query */
    void finishQuery();

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
    /*! Rolls back changes to database
     * \param er - Error string
    */
    void rollback(QString& er);

};
#endif // SQL_QUERY_H
