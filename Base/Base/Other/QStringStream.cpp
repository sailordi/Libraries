#include "QStringStream.h"

//Public functions:
QStringStream::QStringStream() {
    this->v_str = "";
    this->v_steam = new QTextStream(&this->v_str);

    this->v_steam->setCodec("UTF-8");
}

QStringStream::~QStringStream() {
    this->v_steam->flush();
    this->v_str.clear();

    delete this->v_steam;
}

bool QStringStream::isEmpty() {
    return this->v_str.isEmpty();
}
