#include "TreeViewAdapterNoChildRows.h"

#include <QStandardItem>
#include <QStandardItemModel>

#include "Base/Adapter/StandardItemCreator.h"

//Public functions
TreeViewAdapterNoChildRows::TreeViewAdapterNoChildRows(QTreeView* view,bool del)
                                                        : TreeViewBaseAdapter(view,del) {

}

TreeViewAdapterNoChildRows::TreeViewAdapterNoChildRows(QTreeView* view,StandardItemCreator* itemCreator,bool del)
                                                        : TreeViewBaseAdapter(view,itemCreator,del) {

}

void TreeViewAdapterNoChildRows::addData(int pos,QList<QVariant> data) {
    QList<QStandardItem*> list;

        this->generateColumns(list,data);

        this->v_model->insertRow(pos,list);
}

void TreeViewAdapterNoChildRows::addDataBeginning(QList<QVariant> data) {
    this->addData(0,data);
}

void TreeViewAdapterNoChildRows::addDataEnd(QList<QVariant> data) {
    this->addData(this->v_model->rowCount(),data);
}

void TreeViewAdapterNoChildRows::removeData(int pos) {
    this->v_model->removeRow(pos);
}

QList<int> TreeViewAdapterNoChildRows::selectedRowsPosition(bool clearSelection) {
    QList<int> ret;
    QModelIndexList l = this->v_view->selectionModel()->selectedRows();

        if(l.isEmpty() == true) {
            return ret;
        }

        if(clearSelection == true) {
            this->v_view->selectionModel()->clearSelection();
        }

        for(int i = 0; i < l.size(); i++) {
            ret.push_back(l.at(i).row() );
        }

        return ret;
}
