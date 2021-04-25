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

QModelIndexList TreeViewAdapterNoChildRows::selectedIndexs(bool clearSelection) {
    QModelIndexList l = this->v_view->selectionModel()->selectedRows();

        if(l.isEmpty() == true) {
            return l;
        }

        if(clearSelection == true) {
            this->v_view->selectionModel()->clearSelection();
        }

        return l;
}

int TreeViewAdapterNoChildRows::rows() {
    return this->v_model->rowCount();
}

void TreeViewAdapterNoChildRows::setHeaders(QList<QFlags<Qt::AlignmentFlag> > aligments,QStringList headers) {
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

void TreeViewAdapterNoChildRows::setItemCreator(StandardItemCreator* itemCreator,bool deleteOld) {
    if(deleteOld == true) {
        delete this->v_itemCreator;
    }
    this->v_itemCreator = itemCreator;
}

void TreeViewAdapterNoChildRows::clear() {
    this->v_model->removeRows(0,this->rows() );
}

void TreeViewAdapterNoChildRows::resize() {
    for(int i = 0; i < this->v_model->columnCount(); i++) {
        this->v_view->resizeColumnToContents(i);
    }

}

//Protected functions
void TreeViewAdapterNoChildRows::generateColumns(QList<QStandardItem*>& l,QList<QVariant> data) {
    for(int i = 0; i < data.size(); i++) {
        l.push_back(this->v_itemCreator->nonEditable(data.at(i),Qt::AlignCenter) );
    }

}
