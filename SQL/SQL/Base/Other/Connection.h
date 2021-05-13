#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QList>
#include <QString>
#include <QStringList>

#include "SQL_global.h"

/*! Conection names */
enum class ConnectionFlag {
    TEST, /*!< Test connection */
    INSERT, /*!< Insertion flag */
    SELECT, /*!< Selection flag */
    UPDATE, /*!< Update flag */
    CREATE, /*!< Creation flag */
    REMOVE, /*!< Removal flag */
    MODEL, /*!< Model flag */
    OTHER, /*!< Other flag */
    COUNT /*!< The flag count */
};

/*! \class Connection
 * \brief The class handles connection names
 *
 * Incudes: QObject, QList, QString & SQL_global.h
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

};
#endif // CONNECTION_H
