#ifndef TREEVIEWADAPTERNOCHILDROWS_H
#define TREEVIEWADAPTERNOCHILDROWS_H

#include <QList>
#include <QStringList>
#include <QTreeView>

class QStandardItem;
class QStandardItemModel;

class StandardItemCreator;

/*! \class TreeViewAdapterNoChildRows
 * \brief The class is an adapter against a QTreeView without child rows
 *
 * Incudes: QList, QStringList & QTreeView
 *
 * Forward declarations: QStandardItem, QStandardItemModel & StandardItemCreator
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-25
 * \date Last update: 2021-04-26
*/
class TreeViewAdapterNoChildRows
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
    /*! Deconstructor */
    virtual ~TreeViewAdapterNoChildRows();

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
    /*! Returns the selected rows indexes
     * \param clearSelection - Option to clear the views selection [Default: true]
     * \returns QModelIndexList
    */
    QModelIndexList selectedIndexs(bool clearSelection = true);

    /*! Returns number of rows in view
     * \returns int
    */
    int rows();

    /*! Set´s the views heders
     * \param aligments - Aligment flags
     * \param headers - The headers
    */
    virtual void setHeaders(QList<QFlags<Qt::AlignmentFlag> > aligments,QStringList headers);

    /*! Set´s the views item creator
     * \param itemCreator - The standard item creator
     * \param deleteOld - Option to delete old item creator [Default: true]
    */
    void setItemCreator(StandardItemCreator* itemCreator,bool deleteOld = true);

    /*! Clear´s all rows from the view */
    void clear();

    /*! Resizes all columns to fit the content inside them */
    void resize();

    /*! Returns the view
     * \returns QTreeView*
    */
    QTreeView* view();

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
#endif // TREEVIEWADAPTERNOCHILDROWS_H
