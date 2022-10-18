#ifndef SQLQUERY_H
#define SQLQUERY_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>

#include "SQL_global.h"

class SqlQueryData;
class QSqlDatabase;

/*! \class SqlQuery
 * \brief The class handles SQL queries
 *
 * Incudes: Object, QString, QSqlRecord, QSqlQuery & SQL_global.h
 *
 * Forward declarations: SqlQueryData & QSqlDatabase
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-14
 * \date Last update: 2021-05-14
*/
class SQL_EXPORT SqlQuery : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param db - Pointer to the database
     * \param transaction - If transaction should be used
     * \param parent - The parent [Default: nullptr]
    */
    explicit SqlQuery(QSqlDatabase db,bool transaction,QObject* parent = nullptr);
    /*! Deconstructor */
    virtual ~SqlQuery();

    /*! Sets the database
     * \param db - The database
    */
    void setDatabase(QSqlDatabase db);

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
     * \param qD – The SqlQueryData
     * \throws QString
    */
    virtual void exec(SqlQueryData qD);

    /*! Finishes a query */
    void finishQuery();
    /*! Finishes the transaction
     * \throws QString
    */
    void finishTransaction();

    /*! Goes to the next record in the query */
    void nextRecord();
    /*! Returns the current record
     * \param nextRecord - If it should go to the next query [Default: false]
     * \returns QSqlRecord
    */
    QSqlRecord record(bool nextRecord = false);
    /*! Returns value of current record
     * \param c - The column name
     * \param nextRecord - If it should go to the next query [Default: false]
     * \returns QVariant
    */
    QVariant recordValue(QString c,bool nextRecord = false);
    /*! Returns value of current record
     * \param v - The column
     * \param nextRecord - If it should go to the next query [Default: false]
     * \returns QVariant
    */
    QVariant recordValue(int v,bool nextRecord = false);

public slots:
    /*! Slot for data change */
    void dataChange();

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
#endif // SQLQUERY_H
