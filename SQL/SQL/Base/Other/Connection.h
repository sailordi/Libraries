#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QList>
#include <QString>
#include <QStringList>

#include "SQL_global.h"
#include "SQL/Base/Other/ConnectionFlag.h"

/*! \class Connection
 * \brief The class handles connection names
 *
 * Incudes: QObject, QList, QString, ConnectionFlag.h & SQL_global.h
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-13
 * \date Last update: 2021-05-13
*/
class SQL_EXPORT Connection : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit Connection(QObject *parent = nullptr);
    /*! Copy constructor
     * \param c - Connector to copy
     * \param parent - The parent [Default: nullptr]
    */
    explicit Connection(Connection& c,QObject *parent = nullptr);
    /*! Copy constructor
     * \param c - Connector to copy
     * \param parent - The parent [Default: nullptr]
    */
    explicit Connection(Connection* c,QObject *parent = nullptr);
    /*! Deconstructor */
    ~Connection();

    /*! Returns number of connections for a specific ConnectionFlag
     * \param f - The ConnectionFlag [TEST, INSERT, SELECT, UPDATE, CREATE, REMOVE, MODEL, OTHER, COUNT]
     * \returns int
    */
    int connections(ConnectionFlag f);

    /*! Returns the connection str
     * \param f - The ConnectionFlag [TEST, INSERT, SELECT, UPDATE, CREATE, REMOVE, MODEL, OTHER, COUNT]
     * \returns QString
    */
    QString connectionName(ConnectionFlag f);

public slots:
    /*! Slot for connection removed
     * \param str - The connection str
    */
    void connectionRemoved(QString str);

private:
    QList<int> v_cons;

    /*! Returns the list of base connection strings
     *  \returns QStringList
    */
    QStringList getBaseConnectionStr();

    /*! Converst a ConnectionFlag into a number
     *  \param f - The connection flag
     *  \returns int
    */
    int connectionFlagToNum(ConnectionFlag f);

    /*! Strips the string back down to the base connection string
     * \param str - The string to strip
     * \param rC - Character to strip to
     * \returns QString
    */
    QString stripExtraToBaseConnectionStr(QString str,QChar rC);

    /*! Converts string into connection flag
     * \param str - The string to convert
     * \returns ConnectionFlag
    */
    ConnectionFlag strToConnectionFlag (QString str);

};
#endif // CONNECTION_H
