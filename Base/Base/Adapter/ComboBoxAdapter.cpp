#include "ComboBoxAdapter.h"

#include <QStringListModel>
#include <QLineEdit>

//Public functions
ComboBoxAdapter::ComboBoxAdapter(QComboBox* box,bool del,bool connectBoxToSlot,QString first,QObject* parent) : QObject(parent) {
    this->v_box = box;
    this->v_first = first;

    this->v_box->setEditable(true);
    this->v_box->lineEdit()->setReadOnly(true);
    this->v_box->lineEdit()->setAlignment(Qt::AlignCenter);

    this->v_model = new QStringListModel();

    this->v_box->setModel(this->v_model);

    this->clear();

    if(connectBoxToSlot == true) {
        connect(this->v_box,SIGNAL(currentIndexChanged(int) ),this,SLOT(indexChanged(int) ) );
    }

    this->v_del = del;

}

ComboBoxAdapter::~ComboBoxAdapter() {
    this->v_box->setModel(new QStringListModel() );

    delete this->v_model;

    if(this->v_del == true) {
        delete this->v_box;
    }

}

void ComboBoxAdapter::addData(int pos,QString data) {
    if(this->v_first.isEmpty() == false) {
        pos += 1;
    }

    this->v_model->insertRow(pos);
    this->v_model->setData(this->v_model->index(pos),data);
    this->v_model->setData(this->v_model->index(pos),Qt::AlignCenter,Qt::TextAlignmentRole);
}

void ComboBoxAdapter::addDataBeginning(QString data) {
    this->addData(0,data);
}

void ComboBoxAdapter::addDataEnd(QString data) {
    int pos = (this->v_first.isEmpty() == false) ? this->v_model->rowCount()-1 : this->v_model->rowCount();

    this->addData(pos,data);
}

void ComboBoxAdapter::removeData(int pos) {
    if(this->v_first.isEmpty() == false && pos <= 0) {
        return;
    }
    else if(this->v_first.isEmpty() == true && pos < 0) {
        return;
    }

    this->v_model->removeRow(pos);
}

int ComboBoxAdapter::selectedRow() {
    if(this->v_first.isEmpty() == false) {
        return this->v_box->currentIndex()-1;
    }

    return this->v_box->currentIndex();
}

QString ComboBoxAdapter::selectedText() {
    if(this->v_model->rowCount() <= 0) {
        return "";
    }

    return this->v_box->currentText();
}

int ComboBoxAdapter::rows() {
    return this->v_model->rowCount();
}

QStringList ComboBoxAdapter::data() {
    return this->v_model->stringList();
}

void ComboBoxAdapter::clear() {
    this->v_model->removeRows(0,this->v_model->rowCount() );

    if(this->v_first.isEmpty() == false) {
        this->addData(-1,this->v_first);
    }

}

QComboBox* ComboBoxAdapter::box() {
    return this->v_box;
}

//Protected slots
void ComboBoxAdapter::indexChanged(int index) {
    if(this->v_first.isEmpty() == false) {
        emit this->indexHasChanged(index-1);
    }
    else {
        emit this->indexHasChanged(index);
    }

}
