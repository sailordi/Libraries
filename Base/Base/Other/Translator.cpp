#include "Translator.h"

#include <QLocale>

//Public functions
Translator::Translator(QObject *parent) : QObject(parent) {

}

Translator::Translator(QString path,QLocale lang,QString fileFilter,QObject *parent) : QObject(parent) {

}

//Protected functions
QString Translator::getLocaleLetters(const QString str) {
    QString locale = str;

        locale.resize(2);
        locale = locale.toLower();

        return locale;
}
