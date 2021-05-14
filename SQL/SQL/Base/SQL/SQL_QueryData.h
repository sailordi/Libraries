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

};
#endif // SQL_QUERYDATA_H
