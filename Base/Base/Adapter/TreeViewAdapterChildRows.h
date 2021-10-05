#ifndef TREEVIEWADAPTERCHILDROWS_H
#define TREEVIEWADAPTERCHILDROWS_H

#include "Base/Adapter/TreeViewBaseAdapter.h"

/*! \class TreeViewAdapterChildRows
 * \brief The class is an adapter against a QTreeView with child rows
 *
 * Incudes: TreeViewBaseAdapter
 *
 * Inherits: TreeViewBaseAdapter
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-26
 * \date Last update: 2021-10-06
*/
class TreeViewAdapterChildRows : public TreeViewBaseAdapter
{
public:
    /*! Constructor
     * \param view - The view
     * \param del - If the view should be deleted [Default: true]
    */
    TreeViewAdapterChildRows(QTreeView* view,bool del = true);
    /*! Constructor
     * \param view - The view
     * \param itemCreator - The tree item creator
     * \param del - If the view should be deleted [Default: true]
    */
    TreeViewAdapterChildRows(QTreeView* view,StandardItemCreator* itemCreator,bool del = true);

    /*! Adds data to the view at a certain position
     * \param pos - The position
     * \param data - The data
     * \param parentIndex - The parent index [Default: QModelIndex()]
     * \returns QModelIndex
    */
    virtual QModelIndex addData(int pos,QList<QVariant> data,QModelIndex parentIndex = QModelIndex() );

    /*! Removes a row
     * \param pos - The position
     * \param parentIndex - The parent index [Default: QModelIndex()]
    */
    virtual void removeRow(int pos,QModelIndex parentIndex = QModelIndex() );

};
#endif // TREEVIEWADAPTERCHILDROWS_H
