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

    /*! Adds a NoticeList to the page
     * \param n - The NoticeList to add
    */
    void add(NoticeList* n);
    /*! Adds a NoticeList to the page
     * \param n - The NoticeList to add
    */
    void add(NoticeListP n);

    /*! Returns a specific NoticeList
     * \param pos - The position
     * \returns NoticeListP
    */
    NoticeListP list(int pos);

    /*! Sets the pages title
     * \param title - Page title
    */
    void setTitle(QString title);
    /*! Sets the pages title
     * \param title - Page title
     * \param tr - String to fetch translation
    */
    void setTitle(QString title,QString tr);

    /*! Returns the page title
     * \returns QString
    */
    QString title();

    /*! Checks if the page does not have any NoticeLists
     * \returns bool
    */
    bool isEmpty();

    /*! Returns the number of NoticeLists there are
     * \returns int
    */
    int size();

    /*! Retranslates the all NoticeLists */
    virtual void reTranslate();

    /*! Clears all the NoticeLilsts from page */
    void clear();

protected:
    QString v_title = "",v_tr = "";
    QList<NoticeListP> v_list;

};
#endif // NOTICEPAGE_H
