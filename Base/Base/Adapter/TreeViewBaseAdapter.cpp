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

void TreeViewBaseAdapter::initHeaderView() {
    this->v_view->header()->setStretchLastSection(false);
    this->v_view->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

int TreeViewBaseAdapter::numberOfSelectedRows() {
    return this->v_view->selectionModel()->selectedRows().size();
}

QModelIndexList TreeViewBaseAdapter::selectedIndexs(bool clearSelection) {
    QModelIndexList l = this->v_view->selectionModel()->selectedRows();

        if(l.isEmpty() == true) {
            return l;
        }

        if(clearSelection == true) {
            this->v_view->selectionModel()->clearSelection();
        }

        return l;
}

int TreeViewBaseAdapter::rows() {
    return this->v_model->rowCount();
}

void TreeViewBaseAdapter::setHeaders(QList<QFlags<Qt::AlignmentFlag> > aligments,QStringList headers) {
    this->v_model->setColumnCount(0);

    if(headers.isEmpty() == true) {
        return;
    }

    this->v_model->setHorizontalHeaderLabels(headers);

    if(aligments.isEmpty() == true) {
        return;
    }

    for(int i = 0; i < headers.size(); i++) {
        if(aligments.size() > 0) {
            QFlags<Qt::AlignmentFlag> f = aligments.takeFirst();
            this->v_model->horizontalHeaderItem(i)->setTextAlignment(f);
        }
        else {
            return;
        }

    }

}

void TreeViewBaseAdapter::setItemCreator(StandardItemCreator* itemCreator,bool deleteOld) {
    if(deleteOld == true) {
        delete this->v_itemCreator;
    }
    this->v_itemCreator = itemCreator;
}

void TreeViewBaseAdapter::clear() {
    this->v_model->removeRows(0,this->rows() );
}

void TreeViewBaseAdapter::resize() {
    for(int i = 0; i < this->v_model->columnCount(); i++) {
        this->v_view->resizeColumnToContents(i);
    }

}

QTreeView* TreeViewBaseAdapter::view() {
    return this->v_view;
}

//Protected functions
void TreeViewBaseAdapter::generateColumns(QList<QStandardItem*>& l,QList<QVariant> data) {
    for(int i = 0; i < data.size(); i++) {
        l.push_back(this->v_itemCreator->nonEditable(data.at(i),Qt::AlignCenter) );
    }

}
