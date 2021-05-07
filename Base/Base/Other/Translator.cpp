#include "Translator.h"

#include <cassert>

#include <QAction>
#include <QActionGroup>
#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QLocale>
#include <QMenu>

//Public functions
Translator::Translator(QObject *parent) : QObject(parent) {

}

Translator::Translator(QString path,QLocale lang,QString fileFilter,QObject *parent) : QObject(parent) {
    this->setData(path,lang,fileFilter);
}

Translator::~Translator() {
    qApp->removeTranslator(&this->v_trans);
}

void Translator::setData(QString path,QLocale lang,QString fileFilter) {
    this->v_langPath = path;
    this->v_fileFilter = fileFilter;

    this->switchLanguage(QLocale::languageToString(lang.language() ) );
}

void Translator::populateLanguageMenu(QMenu* m,QString title) {
    assert(m != nullptr);

        QList<QAction*> l = m->actions();

        for(int i = 0; i < l.size(); i++) {
            m->removeAction(l.takeFirst() );
        }

        QActionGroup* langGroup = new QActionGroup(m);

        langGroup->setExclusive(true);

        m->setTitle(title);

        if(this->v_found == false) {
            this->addActionToLangMenu(this->v_currentLang,m,langGroup,this->v_currentLang);
            return;
        }

        connect(langGroup,&QActionGroup::triggered,this,&Translator::languageChanged);
        QDir dir(this->v_langPath);
        QStringList fileNames = dir.entryList(QStringList(this->v_fileFilter) );

        for(int i = 0; i < fileNames.size(); i++) {
            QString localeL = this->getLocaleLettersFromFileName(fileNames.at(i) );
            QString lang = QLocale::languageToString(QLocale(localeL).language() );

            this->addActionToLangMenu(lang,m,langGroup,this->v_currentLang);
        }

}

void Translator::reTranslateLanguageMenu(QMenu* m,QString title) {
    assert(m != NULL);

        m->setTitle(title);

        QList<QAction*> l = m->actions();

        for(int i = 0; i < l.size(); i++) {
            QAction* a = l.at(i);
            a->setText(Translator::tr(a->data().toString().toStdString().c_str() ) );
        }

}

//Private slots
void Translator::languageChanged(QAction* a) {
    this->switchLanguage(a->data().toString() );

    emit this->reTranslate();
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
