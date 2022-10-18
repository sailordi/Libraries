#ifndef SQLQUERYDATA_H
#define SQLQUERYDATA_H

#include <QSharedPointer>
#include <QString>
#include <QList>

#include "SQL_global.h"
#include "SQL/Base/Query/SqlQueryBind.h"

/*! \class SqlQueryData
 * \brief The class contains query data
 *
 * Incudes: QSharedPointer, QString, QList, SqlQueryBind & SQL_global.h
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-14
 * \date Last update: 2022-10-18
*/
class SQL_EXPORT SqlQueryData
{
public:
    QString v_qStr = "";
    QList<QSharedPointer<SqlQueryBind> > v_bindL;

    /*! Constructor */
    SqlQueryData();
    /*! Constructor
     * \param q - The query
    */
    SqlQueryData (QString q);
    /*! Deconstructor */
    virtual ~ SqlQueryData ();

    /*! Sets the query string
     * \param q - The query
    */
    void setQuery(QString q);

    /*! Sets the query and the SqlQueryBind list
     * \param q - The query
     * \param l - List of SqlQueryBind list
    */
    virtual void setQuery(QString q,QList<SqlQueryBind>& l);
    /*! Sets the query and the SqlQueryBind list
     * \param q - The query
     * \param l - List of SqlQueryBind list
    */
    virtual void setQuery(QString q,QList<SqlQueryBind*>& l);

    /*! Add SqlQueryBind value to the SqlQueryBind list
     * \param b - SqlQueryBind value
    */
    virtual void addBindValue(SqlQueryBind b);
    /*! Add SqlQueryBind value to the SqlQueryBind list
     * \param b - SqlQueryBind value
    */
    virtual void addBindValue(SqlQueryBind* b);

    /*! Adds SqlQueryBind values to the SqlQueryBind list
     * \param l - SqlQueryBind list
    */
    virtual void addBindVaues(QList<SqlQueryBind>& l);
    /*! Adds SqlQueryBind values to the SqlQueryBind list
     * \param l - SqlQueryBind list
    */
    virtual void addBindVaues(QList<SqlQueryBind*>& l);

    /*! Sets SqlQueryBind values to the SqlQueryBind list
     * \param l - SqlQueryBind list
    */
    virtual void setBindVaues(QList<SqlQueryBind>& l);
    /*! Sets SqlQueryBind values to the SqlQueryBind list
     * \param l - SqlQueryBind list
    */
    virtual void setBindVaues(QList<SqlQueryBind*>& l);

    /*! Clears all values */
    virtual void clear();

    /*! Checks if the SqlQueryBind list is empty
     * \returns bool
    */
    bool boundListEmpty();

};
#endif // SQLQUERYDATA_H
