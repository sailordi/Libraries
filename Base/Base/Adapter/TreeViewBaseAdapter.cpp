#include "TreeViewBaseAdapter.h"

#include <QHeaderView>
#include <QStandardItem>
#include <QStandardItemModel>

#include "Base/Adapter/StandardItemCreator.h"

//Public functions
#include <QHeaderView>
#include <QStandardItem>
#include <QStandardItemModel>

#include "Base/Adapter/StandardItemCreator.h"

//Public functions
TreeViewBaseAdapter::TreeViewBaseAdapter(QTreeView* view,bool del) {
    this->v_view = view;
    this->v_model = new QStandardItemModel();

    this->v_itemCreator = new StandardItemCreator();

    this->v_view->setModel(this->v_model);

    this->v_del = del;
}

TreeViewBaseAdapter::TreeViewBaseAdapter(QTreeView* view,StandardItemCreator* itemCreator,bool del) {
    this->v_view = view;
    this->v_model = new QStandardItemModel();

    this->v_itemCreator = itemCreator;

    this->v_view->setModel(this->v_model);

    this->v_del = del;
}

TreeViewBaseAdapter::~TreeViewBaseAdapter() {
    this->v_view->setModel(new QStandardItemModel() );

    delete this->v_model;

    if(this->v_itemCreator != nullptr) {
        delete this->v_itemCreator;
    }

    if(this->v_del == true) {
        delete this->v_view;
    }
}
