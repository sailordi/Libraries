#ifndef NOTICELIST_H
#define NOTICELIST_H

#include <QObject>
#include <QList>
#include <QSharedPointer>
#include <QString>

#include "Message_global.h"
#include "Message/Notice/Notice.h"

typedef QSharedPointer<Notice> NoticeP;

/*! \class NoticeList
 * \brief The class contains lists for errors, warnings and messages
 *
 * Incudes: QObject, QList, QSharedPointer, QString, Message_global.h & Notice
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-02
 * \date Last update: 2021-05-02
*/
class MESSAGE_EXPORT NoticeList : public QObject
{
    Q_OBJECT
public:
    /*! Cosntructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit NoticeList(QObject* parent = nullptr);
    /*! Deconstructor */
    virtual ~NoticeList();


protected:
    QList<NoticeP> v_errors,v_messages,v_warnings;

};
#endif // NOTICELIST_H
