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

signals:
    /*! Signal that data has changed */
    void dataHasChanged();

protected:
    QString v_driver = "",v_connName = "";

    DatabaseInfo* v_info = nullptr;
    DatabaseUser* v_user = nullptr;

};
#endif // DB_H
