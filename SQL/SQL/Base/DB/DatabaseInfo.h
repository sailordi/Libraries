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

    /*! Sets the database name
     * \param name - The database name
     * \param emitSignal - If signal should be emited [Default: true]
    */
    void setDatabaseName(QString name,bool emitSignal = true);
    /*! Sets the host name
     * \param hostName - The host name
     * \param emitSignal - If signal should be emited [Default: true]
    */
    void setHostName(QString hostName,bool emitSignal = true);
    /*! Sets the port
     * \param port - The port
     * \param emitSignal - If signal should be emited [Default: false]
    */
    void setPort(int port,bool emitSignal = false);
    /*! Sets the database name,host name & port
     * \param n_h_p - The list with database name, host name & port
     * \param emitSignal - If signal should be emited [Default: true]
    */
    void setData(QList<QVariant> n_h_p,bool emitSignal = true);

    /*! Returns database name
     * \returns QString
    */
    QString databaseName();
    /*! Returns host name
     * \returns QString
    */
    QString hostName();

signals:
    /*! Signal that the database info has changed */
    void infoChanged();

private:
    QString v_dbName = "",v_hostName = "";
    int v_port = 0;

};
#endif // DATABASEINFO_H
