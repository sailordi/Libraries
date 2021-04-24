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
