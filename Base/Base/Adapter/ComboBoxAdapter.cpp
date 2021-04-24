#include "ComboBoxAdapter.h"

#include <QStringListModel>
#include <QLineEdit>

//Public functions
ComboBoxAdapter::ComboBoxAdapter(QComboBox* box,bool del,QString first) {
    this->v_box = box;
    this->v_first = first;

    this->v_box->setEditable(true);
    this->v_box->lineEdit()->setReadOnly(true);
    this->v_box->lineEdit()->setAlignment(Qt::AlignCenter);

    this->v_model = new QStringListModel();

    this->v_box->setModel(this->v_model);

    this->v_del = del;

}

ComboBoxAdapter::~ComboBoxAdapter() {
    this->v_box->setModel(new QStringListModel() );

    delete this->v_model;

    if(this->v_del == true) {
        delete this->v_box;
    }

}
