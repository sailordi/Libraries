#ifndef TREEVIEWBASEADAPTER_H
#define TREEVIEWBASEADAPTER_H

#include <QList>
#include <QStringList>
#include <QTreeView>

class QStandardItem;
class QStandardItemModel;

class StandardItemCreator;

/*! \class TreeViewBaseAdapter
 * \brief The class is an base adapter against a QTreeView
 * Contains common functions between TreeView adapters
 *
 * Incudes: QList, QStringList & QTreeView
 *
 * Forward declarations: QStandardItem, QStandardItemModel & StandardItemCreator
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-28
 * \date Last update: 2021-04-28
*/
class TreeViewBaseAdapter
{
public:
    /*! Constructor
     * \param view - The view
     * \param del - If the view should be deleted [Default: true]
    */
    TreeViewBaseAdapter(QTreeView* view,bool del = true);
    /*! Constructor
     * \param view - The view
     * \param itemCreator - The tree item creator
     * \param del - If the view should be deleted [Default: true]
    */
    TreeViewBaseAdapter(QTreeView* view,StandardItemCreator* itemCreator,bool del = true);
    /*! Deconstructor */
    virtual ~TreeViewBaseAdapter();

    /*! Initializes the header view */
    virtual void initHeaderView();

    /*! Returns the number of selected rows
     * \returns int
    */
    virtual int numberOfSelectedRows();

    /*! Returns the selected rows indexes
     * \param clearSelection - Option to clear the views selection [Default: true]
     * \returns QModelIndexList
    */
    QModelIndexList selectedIndexs(bool clearSelection = true);

    /*! Returns number of rows in view
     * \returns int
    */
    virtual int rows();

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

    /*! Constructor */
    TreeViewBaseAdapter();

    /*! General function for generating columns
     * \param l - Column item list
     * \param data - The data to turn into columns
    */
    virtual void generateColumns(QList<QStandardItem*>& l,QList<QVariant> data);

};
#endif // TREEVIEWBASEADAPTER_H
