#include "StandardItemCreator.h"

//Public functions
StandardItemCreator::StandardItemCreator() {

}

StandardItemCreator::~StandardItemCreator() {

}

QStandardItem* StandardItemCreator::editable(QVariant data,Qt::AlignmentFlag aligment) {
    QStandardItem* it = new QStandardItem();

        it->setData(data,Qt::EditRole);
        it->setData(QColor("black"),Qt::TextColorRole);
        it->setData(aligment,Qt::TextAlignmentRole);

        it->setFlags(it->flags() | Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);

        return it;
}

QStandardItem* StandardItemCreator::nonEditable(QVariant data,Qt::AlignmentFlag aligment) {
    QStandardItem* it = new QStandardItem();

        it->setData(data,Qt::EditRole);
        it->setData(QColor("black"),Qt::TextColorRole);
        it->setData(aligment,Qt::TextAlignmentRole);

        it->setFlags(it->flags() | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        it->setFlags(it->flags() ^ Qt::ItemIsEditable);

        return it;
}

QStandardItem* StandardItemCreator::checkEdit(QVariant data,Qt::AlignmentFlag aligment) {
    bool isBool = data.canConvert<bool>();
    QStandardItem* it = new QStandardItem();

        //Data is bool
        if(isBool == true && data.toBool() == true) {
            it->setData(Qt::Checked,Qt::CheckStateRole);
        }
        else if(isBool == true && data.toBool() == false) {
            it->setData(Qt::Unchecked,Qt::CheckStateRole);
        }
        //Data is string
        else if(isBool == false && data.toString().compare("true") == 0) {
            it->setData(Qt::Checked,Qt::CheckStateRole);
        }
        else if(isBool == false && data.toString().compare("true") != 0) {
            it->setData(Qt::Unchecked,Qt::CheckStateRole);
        }

        it->setData(aligment,Qt::TextAlignmentRole);

        it->setFlags(it->flags() | Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);

        return it;
}
