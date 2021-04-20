#include "Translator.h"

#include <QAction>
#include <QActionGroup>
#include <QApplication>
#include <QDebug>
#include <QLocale>
#include <QMenu>

//Public functions
Translator::Translator(QObject *parent) : QObject(parent) {

}

Translator::Translator(QString path,QLocale lang,QString fileFilter,QObject *parent) : QObject(parent) {
    this->setData(path,lang,fileFilter);
}

void Translator::setData(QString path,QLocale lang,QString fileFilter) {
    this->v_langPath = path;
    this->v_fileFilter = fileFilter;

    this->switchLanguage(QLocale::languageToString(lang.language() ) );
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

void Translator::addActionToLangMenu(QString lang,QMenu* m,QActionGroup* g,QString currentLang) {
    QAction *a = new QAction(Translator::tr(lang.toStdString().c_str() ),m);

        a->setCheckable(true);
        a->setData(this->getLocaleLettersFromFileName(lang) );

        m->addAction(a);
        g->addAction(a);

        if(currentLang == lang) {
            a->setChecked(true);
        }
}

void Translator::switchLanguage(const QString& newLanguage) {
    if(this->v_currentLang == newLanguage) {
            return;
    }

    qApp->removeTranslator(&this->v_trans);

    this->v_currentLang = newLanguage;

    QString f = this->v_fileFilter;
    QString tmp = f.replace("*",this->getLocaleLetters(this->v_currentLang) );

    if(this->v_trans.load(tmp,this->v_langPath) == false) {
        qDebug().noquote()<<"Could not load "<<this->v_langPath+tmp;
        this->v_found = false;
        return;
    }

    this->v_found = true;

    qApp->installTranslator(&this->v_trans);
}
