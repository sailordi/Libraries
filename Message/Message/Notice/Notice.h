#ifndef NOTICE_H
#define NOTICE_H

#include <QObject>
#include <QString>
#include <QPair>

#include "Message_global.h"

/*! Typedef for argument & replacer
 * first - The argument
 * second - The replacer
*/
typedef QPair<QString,QString> ArgReplacer;

/*! \class Notice
 * \brief The class has all functionality that a message will use
 *
 * Incudes: QObject, QString, QPair & Message_global.h
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-01
 * \date Last update: 2021-05-01
*/
class MESSAGE_EXPORT Notice : public QObject
{
    Q_OBJECT
public:
    /*! Cosntrucctor
     * \param s - Message
     * \param parent - The parent [Default: nullptr]
    */
    explicit Notice(QString s,QObject* parent = nullptr);
    /*! Cosntrucctor
     * \param s - Message
     * \param tr - String to fetsh translation
     * \param parent - The parent [Default: nullptr]
    */
    explicit Notice(QString s,QString tr,QObject* parent = nullptr);
    /*! Cosntructor
     * \param l - Argument & replacer list
     * \param s - Message
     * \param parent - The parent [Default: nullptr]
    */
    explicit Notice(QList<ArgReplacer> l,QString s,QObject* parent = nullptr);
    /*! Cosntructor
     * \param l - Argument & replacer list
     * \param s - Message
     * \param tr - String to fetsh translation
     * \param parent - The parent [Default: nullptr]
    */
    explicit Notice(QList<ArgReplacer> l,QString s,QString tr,QObject* parent = nullptr);
    /*! Deconstructor */
    virtual ~Notice();

    /*! Adds a argument/replacer to the argument/replacer list
     * \param a - Argument/replacer
    */
    void addArg(ArgReplacer a);
    /*! Adds a list of argument/replacer to the argument/replacer list
     * \param l - Argument/replacer list
    */
    void addArgs(QList<ArgReplacer> l);
    /*! Set´s argument & replacer list
     * \param l - Argument & replacer list
    */
    void setArgs(QList<ArgReplacer> l);

protected:
    QString v_orig = "",v_msg = "",v_tr = "";
    QList<ArgReplacer> v_data;

};
#endif // NOTICE_H
