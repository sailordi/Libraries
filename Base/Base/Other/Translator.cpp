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

QString Translator::getLocaleLettersFromFileName(const QString str) {
    QString tmp = str;
    int dotIndex = tmp.lastIndexOf('.');
    int dachIndex = tmp.indexOf('_');

        if(dotIndex >= 0)   {
            tmp.truncate(dotIndex);
        }
        if(dachIndex >= 0)  {
            tmp = tmp.remove(0,dachIndex + 1);
        }

        return this->getLocaleLetters(tmp);
}
