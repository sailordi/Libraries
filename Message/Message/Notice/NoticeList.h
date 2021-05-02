#ifndef NOTICELIST_H
#define NOTICELIST_H

#include <QObject>
#include <QList>
#include <QSharedPointer>
#include <QString>

#include "Message_global.h"
#include "Message/Notice/Notice.h"
#include "Message/Notice/NoticeFlag.h"

typedef QSharedPointer<Notice> NoticeP;

/*! \class NoticeList
 * \brief The class contains lists for errors, warnings and messages
 *
 * Incudes: QObject, QList, QSharedPointer, QString, Message_global.h, Notice & NoticeFlag
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

    /*! Adds a Notice to the list
     * \param n - The Notice to add
     * \param flag - The NoticeFlag [ERROR, WARNING, MESSAGE]
    */
    void add(Notice* n,NoticeFlag flag);
    /*! Adds a Notice to the list
     * \param n - The Notice to add
     * \param flag - The NoticeFlag [ERROR, WARNING, MESSAGE]
    */
    void add(NoticeP n,NoticeFlag flag);

protected:
    QList<NoticeP> v_errors,v_messages,v_warnings;

};
#endif // NOTICELIST_H
