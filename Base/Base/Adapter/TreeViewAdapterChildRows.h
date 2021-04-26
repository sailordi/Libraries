#ifndef TREEVIEWADAPTERCHILDROWS_H
#define TREEVIEWADAPTERCHILDROWS_H

#include <QList>
#include <QStringList>
#include <QTreeView>

class QStandardItem;
class QStandardItemModel;

class StandardItemCreator;

/*! \class TreeViewAdapterChildRows
 * \brief The class is an adapter against a QTreeView with child rows
 *
 * Incudes: QList, QStringList & QTreeView
 *
 * Forward declarations: QStandardItem, QStandardItemModel & StandardItemCreator
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-26
 * \date Last update: 2021-04-26
*/
class TreeViewAdapterChildRows
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
    /*! Deconstructor */
    virtual ~TreeViewAdapterChildRows();

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

    /*! Returns the selected rows indexes
     * \param clearSelection - Option to clear the views selection [Default: true]
     * \returns QModelIndexList
    */
    QModelIndexList selectedIndexs(bool clearSelection = true);

    /*! Returns number of rows in view
     * \returns int
    */
    virtual int rows();

protected:
    bool v_del;
    QTreeView* v_view = nullptr;
    QStandardItemModel* v_model = nullptr;
    StandardItemCreator* v_itemCreator = nullptr;

    /*! General function for generating columns
     * \param l - Column item list
     * \param data - The data to turn into columns
    */
    virtual void generateColumns(QList<QStandardItem*>& l,QList<QVariant> data);

};
#endif // TREEVIEWADAPTERCHILDROWS_H
