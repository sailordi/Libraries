#include "TreeViewAdapterNoChildRows.h"

#include <QStandardItem>
#include <QStandardItemModel>

#include "Base/Adapter/StandardItemCreator.h"

//Public functions
TreeViewAdapterNoChildRows::TreeViewAdapterNoChildRows(QTreeView* view,bool del) {
    this->v_view = view;
    this->v_model = new QStandardItemModel();

    this->v_itemCreator = new StandardItemCreator();

    this->v_view->setModel(this->v_model);

    this->v_del = del;
}

TreeViewAdapterNoChildRows::TreeViewAdapterNoChildRows(QTreeView* view,StandardItemCreator* itemCreator,bool del) {
    this->v_view = view;
    this->v_model = new QStandardItemModel();

    this->v_itemCreator = itemCreator;

    this->v_view->setModel(this->v_model);

    this->v_del = del;
}

TreeViewAdapterNoChildRows::~TreeViewAdapterNoChildRows() {
    this->v_view->setModel(new QStandardItemModel() );

    delete this->v_model;

    if(this->v_itemCreator != nullptr) {
        delete this->v_itemCreator;
    }

    if(this->v_del == true) {
        delete this->v_view;
    }

}

void TreeViewAdapterNoChildRows::addData(int pos,QList<QVariant> data) {
    QList<QStandardItem*> list;

        this->generateColumns(list,data);

        this->v_model->insertRow(pos,list);
}

//Protected functions
void TreeViewAdapterNoChildRows::generateColumns(QList<QStandardItem*>& l,QList<QVariant> data) {
    for(int i = 0; i < data.size(); i++) {
        l.push_back(this->v_itemCreator->nonEditable(data.at(i),Qt::AlignCenter) );
    }

}
