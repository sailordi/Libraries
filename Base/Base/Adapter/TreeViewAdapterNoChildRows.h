#ifndef TREEVIEWADAPTERNOCHILDROWS_H
#define TREEVIEWADAPTERNOCHILDROWS_H

#include "Base/Adapter/TreeViewBaseAdapter.h"

/*! \class TreeViewAdapterNoChildRows
 * \brief The class is an adapter against a QTreeView without child rows
 *
 * Incudes: TreeViewBaseAdapter
 *
 * Inherits: TreeViewBaseAdapter
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-25
 * \date Last update: 2021-10-06
*/
class TreeViewAdapterNoChildRows : public TreeViewBaseAdapter
{
public:
    /*! Constructor
     * \param view - The view
     * \param del - If the view should be deleted [Default: true]
    */
    TreeViewAdapterNoChildRows(QTreeView* view,bool del = true);
    /*! Constructor
     * \param view - The view
     * \param itemCreator - The tree item creator
     * \param del - If the view should be deleted [Default: true]
    */
    TreeViewAdapterNoChildRows(QTreeView* view,StandardItemCreator* itemCreator,bool del = true);

    /*! Adds data to the view at a certain position
     * \param pos - The position
     * \param data - The data
    */
    virtual void addData(int pos,QList<QVariant> data);
    /*! Adds data to the beginning of the view
     * \param data - The data
    */
    virtual void addDataBeginning(QList<QVariant> data);
    /*! Adds data to the end of the view
     * \param data - The data
    */
    virtual void addDataEnd(QList<QVariant> data);

    /*! Removes a row
     * \param pos - The position
    */
    virtual void removeData(int pos);

    /*! Returns the selected rows position
     * \param clearSelection - Option to clear the views selection [Default: true]
     * \returns QList<int>
    */
    QList<int> selectedRowsPosition(bool clearSelection = true);

};
#endif // TREEVIEWADAPTERNOCHILDROWS_H
