#include "TreeViewAdapterChildRows.h"

#include <QStandardItem>
#include <QStandardItemModel>

#include "Base/Adapter/StandardItemCreator.h"

//Public functions
TreeViewAdapterChildRows::TreeViewAdapterChildRows(QTreeView* view,bool del) {
    this->v_view = view;
    this->v_model = new QStandardItemModel();

    this->v_itemCreator = new StandardItemCreator();

    this->v_view->setModel(this->v_model);

    this->v_del = del;
}

TreeViewAdapterChildRows::TreeViewAdapterChildRows(QTreeView* view,StandardItemCreator* itemCreator,bool del) {
    this->v_view = view;
    this->v_model = new QStandardItemModel();

    this->v_itemCreator = itemCreator;

    this->v_view->setModel(this->v_model);

    this->v_del = del;
}

TreeViewAdapterChildRows::~TreeViewAdapterChildRows() {
    this->v_view->setModel(new QStandardItemModel() );

    delete this->v_model;

    if(this->v_itemCreator != nullptr) {
        delete this->v_itemCreator;
    }

    if(this->v_del == true) {
        delete this->v_view;
    }

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

//Protected functions
void TreeViewAdapterChildRows::generateColumns(QList<QStandardItem*>& l,QList<QVariant> data) {
    for(int i = 0; i < data.size(); i++) {
        l.push_back(this->v_itemCreator->nonEditable(data.at(i),Qt::AlignCenter) );
    }

}
