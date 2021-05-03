#ifndef NOTICEPAGE_H
#define NOTICEPAGE_H

#include <QList>
#include <QObject>
#include <QString>
#include <QSharedPointer>

#include "Message_global.h"

class NoticeList;

typedef QSharedPointer<NoticeList> NoticeListP;

/*! \class NoticePage
 * \brief The class contains a list of notice lists and a title
 *
 * Incudes: QList, QObject, QString, QSharedPointer, QPalette & Message_global.h
 *
 * Forward declarations: NoticeList
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-03
 * \date Last update: 2021-05-03
*/
class MESSAGE_EXPORT NoticePage : public QObject
{
    Q_OBJECT
public:
    /*! Cosntructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit NoticePage(QObject* parent = nullptr);
    /*! Cosntructor
     * \param title - Page title
     * \param parent - The parent [Default: nullptr]
    */
    explicit NoticePage(QString title,QObject* parent = nullptr);
    /*! Cosntructor
     * \param title - Page title
     * \param tr - String to fetch translation
     * \param parent - The parent [Default: nullptr]
    */
    explicit NoticePage(QString title,QString tr,QObject* parent = nullptr);
    /*! Deconstructor */
    virtual ~NoticePage();

protected:
    QString v_title = "",v_tr = "";
    QList<NoticeListP> v_list;

};
#endif // NOTICEPAGE_H
