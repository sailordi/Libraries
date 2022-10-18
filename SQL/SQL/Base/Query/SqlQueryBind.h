#ifndef SQLQUERYBIND_H
#define SQLQUERYBIND_H

#include <QObject>
#include <QString>
#include <QVariant>

#include "SQL_global.h"

/*! \class SqlQueryBind
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
 * \date Last update: 2022-10-18
*/
class SQL_EXPORT SqlQueryBind : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param key - The bind key
     * \param parent - The parent [Default: nullptr]
    */
    SqlQueryBind(QString key,QObject* parent = nullptr);
    /*! Constructor
     * \param key - The bind key
     * \param val - The bind value
     * \param parent - The parent [Default: nullptr]
    */
    SqlQueryBind(QString key,QVariant val,QObject* parent = nullptr);
    /*! Constructor
     * \param b - The parameter to be copied
     * \param parent - The parent [Default: nullptr]
    */
    SqlQueryBind(const SqlQueryBind& b,QObject* parent = nullptr);
    /*! Constructor
     * \param b - The parameter to be copied
     * \param parent - The parent [Default: nullptr]
    */
    SqlQueryBind(const SqlQueryBind* b,QObject* parent = nullptr);
    /*! Deconstructor */
    virtual ~SqlQueryBind();

    /*! Sets the bind key
     * \param key - The bind key
    */
    virtual void setKey(QString key);
    /*! Sets the bind value
     * \param val - The bind value
    */
    virtual void setValue(QVariant val);
    /*! Sets the bind key & bind value
     * \param key - The bind key
     * \param val - The bind value
    */
    virtual void setData(QString key,QVariant val);

    /*! Returns bind key
     * \returns QString
    */
    virtual QString key();
    /*! Returns value
     * \returns QVariant
    */
    virtual QVariant value();

protected:
    QString v_key = "";
    QVariant v_val;

    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    SqlQueryBind(QObject* parent = nullptr);

};
#endif // SQLQUERYBIND_H
