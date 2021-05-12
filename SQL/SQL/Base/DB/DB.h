#ifndef DB_H
#define DB_H

#include <QObject>
#include <QSqlDatabase>

#include "SQL_global.h"

class DatabaseInfo;
class DatabaseUser;

/*! \class DatabaseUser
 * \brief The class contains the info about the database user
 *
 * It contains:
 *
 * The username and passport
 *
 * Incudes: QObject, QString & SQL_global.h
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-12
 * \date Last update: 2021-05-12
*/
class SQL_EXPORT DB : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param connName - The connection name
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit DB(QString connName,QObject *parent = nullptr);
    /*! Constructor
     * \param connName - The connection name
     * \param i - The DatabaseInfo
     * \param u - The DatabaseUser
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit DB(QString connName,DatabaseInfo* i,DatabaseUser* u,QObject *parent = nullptr);
    /*! Deconstructor */
    virtual ~DB();

    /*! Sets the DatabaseInfo
     * \param i - The DatabaseInfo
    */
    void setInfo(DatabaseInfo* i);
    /*! Sets the DatabaseUser
     * \param u - The DatabaseUser
    */
    void setUser(DatabaseUser* u);
    /*! Sets the DatabaseInfo & the DatabaseUser
     * \param i - The DatabaseInfo
     * \param u - The DatabaseUser
    */
    void setData(DatabaseInfo* i,DatabaseUser* u);

    /*! Function to test database */
    virtual void test() = 0;

    /*! Checks if database can use size
     * \param db - The database
     * \returns bool
    */
    static bool hasSize(QSqlDatabase db);
    /*! Checks if database can use transactions
     * \param db - The database
     * \returns bool
    */
    static bool hasTransaction(QSqlDatabase db);

    /*! Initialises the database */
    virtual void initDB();
    /*! Database info changed */
    virtual void infoChanged() = 0;

    /*! Tries to open database
     * \returns QSqlDatabase
     * \throws QString
    */
    virtual QSqlDatabase open();
    /*! Tries to open database
     * \param db - The database
    */
    static void open(QSqlDatabase db);

    /*! Tries to close database
     * param db - The database
    */
    static void close(QSqlDatabase db);

signals:
    /*! Signal that data has changed */
    void dataHasChanged();

    /*! Signal for removal of connection
     * \param con - The connection name
    */
    void removeConnection(QString con);

protected slots:
    /*! Slot for the database has changed */
    void dataChanged();

protected:
    QString v_driver = "",v_connName = "";

    DatabaseInfo* v_info = nullptr;
    DatabaseUser* v_user = nullptr;

};
#endif // DB_H
