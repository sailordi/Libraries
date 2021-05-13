#ifndef SQL_BIND_H
#define SQL_BIND_H

#include <QObject>
#include <QString>
#include <QVariant>

#include "SQL_global.h"

/*! \class SQL_Bind
 * \brief The class contains a key and a value to be bound to a SQL query
 *
 * Incudes: QObject, QString, QVariant & SQL_global.h
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-05-13
 * \date Last update: 2020-05-13
*/
class SQL_EXPORT SQL_Bind : QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param key - The bind key
     * \param parent - The parent [Default: nullptr]
    */
    SQL_Bind(QString key,QObject* parent = nullptr);
    /*! Constructor
     * \param key - The bind key
     * \param val - The bind value
     * \param parent - The parent [Default: nullptr]
    */
    SQL_Bind(QString key,QVariant val,QObject* parent = nullptr);
    /*! Constructor
     * \param b - The parameter to be copied
     * \param parent - The parent [Default: nullptr]
    */
    SQL_Bind(const SQL_Bind& b,QObject* parent = nullptr);
    /*! Constructor
     * \param b - The parameter to be copied
     * \param parent - The parent [Default: nullptr]
    */
    SQL_Bind(const SQL_Bind* b,QObject* parent = nullptr);
    /*! Deconstructor */
    virtual ~SQL_Bind();

    /*! Sets the bind key
     * \param key - The bind key
    */
    virtual void setKey(QString key);
    /*! Sets the bind value
     * \param val - The bind value
    */
    virtual void setValue(QVariant val);

protected:
    QString v_key = "";
    QVariant v_val;

    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    SQL_Bind(QObject* parent = nullptr);

};
#endif // SQL_BIND_H
