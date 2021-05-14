#ifndef SQL_QUERYDATA_H
#define SQL_QUERYDATA_H

#include <QSharedPointer>
#include <QString>
#include <QList>

#include "SQL_global.h"
#include "SQL/Base/SQL/SQL_Bind.h"

/*! \class SQL_QueryData
 * \brief The class contains query data
 *
 * Incudes: QSharedPointer, QString, QList, SQL_Bind & SQL_global.h
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-14
 * \date Last update: 2021-05-14
*/
class SQL_EXPORT SQL_QueryData
{
public:
    QString v_qStr = "";
    QList<QSharedPointer<SQL_Bind> > v_bindL;

    /*! Constructor */
    SQL_QueryData ();
    /*! Constructor
     * \param q - The query
    */
    SQL_QueryData (QString q);
    /*! Deconstructor */
    virtual ~ SQL_QueryData ();

    /*! Sets the query string
     * \param q - The query
    */
    void setQuery(QString q);

    /*! Sets the query and the SQL_Bind list
     * \param q - The query
     * \param l - List of SQL_Bind list
    */
    virtual void setQuery(QString q,QList<SQL_Bind>& l);
    /*! Sets the query and the SQL_Bind list
     * \param q - The query
     * \param l - List of SQL_Bind list
    */
    virtual void setQuery(QString q,QList<SQL_Bind*>& l);

    /*! Add SQL_Bind value to the SQL_Bind list
     * \param b - SQL_Bind value
    */
    virtual void addBindValue(SQL_Bind b);
    /*! Add SQL_Bind value to the SQL_Bind list
     * \param b - SQL_Bind value
    */
    virtual void addBindValue(SQL_Bind* b);

    /*! Adds SQL_Bind values to the SQL_Bind list
     * \param l - SQL_Bind list
    */
    virtual void addBindVaues(QList<SQL_Bind>& l);
    /*! Adds SQL_Bind values to the SQL_Bind list
     * \param l - SQL_Bind list
    */
    virtual void addBindVaues(QList<SQL_Bind*>& l);

    /*! Sets SQL_Bind values to the SQL_Bind list
     * \param l - SQL_Bind list
    */
    virtual void setBindVaues(QList<SQL_Bind>& l);
    /*! Sets SQL_Bind values to the SQL_Bind list
     * \param l - SQL_Bind list
    */
    virtual void setBindVaues(QList<SQL_Bind*>& l);

};
#endif // SQL_QUERYDATA_H
