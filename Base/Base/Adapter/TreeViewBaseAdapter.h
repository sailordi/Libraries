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

protected:
    bool v_del;
    QTreeView* v_view = nullptr;
    QStandardItemModel* v_model = nullptr;
    StandardItemCreator* v_itemCreator = nullptr;

    /*! Constructor */
    TreeViewBaseAdapter();

};
#endif // TREEVIEWBASEADAPTER_H
