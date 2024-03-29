#ifndef STANDARDITEMCREATOR_H
#define STANDARDITEMCREATOR_H

#include <QList>
#include <QStandardItem>
#include <QVariant>

/*! \class StandardItemCreator
 * \brief The class is used for creating QStandardItems
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-24
 * \date Last update: 2022-10-18
*/
class StandardItemCreator
{
public:
    /*! Constructor */
    StandardItemCreator();
    /*! Deconstructor */
    virtual ~StandardItemCreator();

    /*! Creates a editable standard item
     * \param data - The data for the column
     * \param aligment - The text aligment
     * \returns QStandardItem*
    */
    virtual QStandardItem* editable(QVariant data,Qt::AlignmentFlag aligment);

    /*! Creates a non editable standard item
     * \param data - The data for the column
     * \param aligment - The text aligment
     * \returns QStandardItem*
    */
    virtual QStandardItem* nonEditable(QVariant data,Qt::AlignmentFlag aligment);

    /*! Creates a editable checkbox standard item
     * \param data - The data for the column
     * \param aligment - The text aligment
     * \returns QStandardItem*
    */
    virtual QStandardItem* checkEdit(QVariant data,Qt::AlignmentFlag aligment);

};
#endif // STANDARDITEMCREATOR_H
