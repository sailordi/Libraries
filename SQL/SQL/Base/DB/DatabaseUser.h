#ifndef DATABASEUSER_H
#define DATABASEUSER_H

#include <QObject>
#include <QString>

#include "SQL_global.h"

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
class SQL_EXPORT DatabaseUser : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit DatabaseUser(QObject *parent = nullptr);
    /*! Copy constructor
     * \param dU - DatabaseUser to copy
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit DatabaseUser(DatabaseUser& dU,QObject *parent = nullptr);
    /*! Copy constructor
     * \param dU - DatabaseUser to copy
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit DatabaseUser(DatabaseUser* dU,QObject *parent = nullptr);
    /*! Deconstructor */
    virtual ~DatabaseUser();

signals:

protected:
    QString v_usr = "",v_pass = "";

};
#endif // DATABASEUSER_H
