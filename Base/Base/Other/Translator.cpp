#include "Translator.h"

#include <QLocale>

//Public functions
Translator::Translator(QObject *parent) : QObject(parent) {

}

Translator::Translator(QString path,QLocale lang,QString fileFilter,QObject *parent) : QObject(parent) {

}
