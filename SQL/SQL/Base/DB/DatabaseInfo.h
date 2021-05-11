#ifndef DATABASEINFO_H
#define DATABASEINFO_H

#include <QList>
#include <QObject>
#include <QString>
#include <QVariant>

#include "SQL_global.h"

/*! \class DatabaseInfo
 * \brief The class contains the info about the database
 *
 * It contains:
 *
 * The database name,host and port
 *
 * Incudes: QList, QObject, QString, QVariant & SQL_global.h
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-12
 * \date Last update: 2021-05-12
*/
class SQL_EXPORT DatabaseInfo : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit DatabaseInfo(QObject *parent = nullptr);
    /*! Constructor
     * \param n_h_p - The list with database name, host name & port
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit DatabaseInfo(QList<QVariant> n_h_p,QObject *parent = nullptr);
    /*! Copy constructor
     * \param dI - DatabaseInfo to copy
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit DatabaseInfo(const DatabaseInfo& dI,QObject *parent = nullptr);
    /*! Copy constructor
     * \param dI - DatabaseInfo to copy
     * \param parent - Thge parent [Default: nullptr]
    */
    explicit DatabaseInfo(const DatabaseInfo* dI,QObject *parent = nullptr);
    /*! Deconstructor */
    virtual ~DatabaseInfo();

signals:

private:
    QString v_dbName = "",v_hostName = "";
    int v_port = 0;

};
#endif // DATABASEINFO_H
