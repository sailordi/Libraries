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
 * \date Last update: 2021-04-25
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

protected:
    bool v_del;
    QTreeView* v_view = nullptr;
    QStandardItemModel* v_model = nullptr;
    StandardItemCreator* v_itemCreator = nullptr;

};
#endif // TREEVIEWADAPTERNOCHILDROWS_H
