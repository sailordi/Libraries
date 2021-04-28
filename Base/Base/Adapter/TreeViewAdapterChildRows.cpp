#include "TreeViewAdapterChildRows.h"

#include <QStandardItem>
#include <QStandardItemModel>

#include "Base/Adapter/StandardItemCreator.h"

//Public functions
TreeViewAdapterChildRows::TreeViewAdapterChildRows(QTreeView* view,bool del)
                                                    : TreeViewBaseAdapter(view,del) {

}

TreeViewAdapterChildRows::TreeViewAdapterChildRows(QTreeView* view,StandardItemCreator* itemCreator,bool del)
                                                    : TreeViewBaseAdapter(view,itemCreator,del) {

}

QModelIndex TreeViewAdapterChildRows::addData(int pos,QList<QVariant> data,QModelIndex parentIndex) {
    QList<QStandardItem*> list;

        this->generateColumns(list,data);

        if(this->v_model->itemFromIndex(parentIndex) != nullptr) {
            this->v_model->itemFromIndex(parentIndex)->insertRow(pos,list);
        }
        else {
            this->v_model->insertRow(pos,list);
        }

        return this->v_model->index(pos,0,parentIndex);
}

void TreeViewAdapterChildRows::removeRow(int pos,QModelIndex parentIndex) {
    if(this->v_model->itemFromIndex(parentIndex) != nullptr) {
        this->v_model->itemFromIndex(parentIndex)->removeRow(pos);
    }
    else {
        this->v_model->removeRow(pos);
    }

}
