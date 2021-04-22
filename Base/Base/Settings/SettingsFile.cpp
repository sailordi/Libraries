#include "SettingsFile.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

//Public functions
SettingsFile::SettingsFile(QString file,bool read) {
    this->v_f = new QFile(file);
    this->v_read = read;

    QFileInfo i(file);
    QDir d = i.absoluteDir();

    if(d.exists() == false) {
        d.mkdir(d.absolutePath() );
    }

    if(this->v_read == false) {
        if(this->v_f->open(QFile::WriteOnly) == false) {
           return;
        }
    }
    else {
        if(this->v_f->open(QFile::ReadOnly) == false) {
           return;
        }
    }

    this->v_s = new QTextStream(this->v_f);
    this->v_s->setCodec("UTF-8");

    this->v_s->seek(0);
}

SettingsFile::~SettingsFile() {
    if(this->v_s != nullptr) {
        this->v_s->flush();

        delete this->v_s;
    }

    if(this->v_f != nullptr) {
        this->v_f->flush();

        this->v_f->close();

        delete this->v_f;
    }

}

//Private functions
bool SettingsFile::isGoup(QString s) {
    return (s.isEmpty() == true) ? false : s.contains(QRegExp("\\[|\\]") );
}

bool SettingsFile::isArray(QString s) {
    return (s.isEmpty() == true) ? false : s.contains(QRegExp("\\¤") );
}

bool SettingsFile::isBlock(QString s) {
    if(this->isGoup(s) ==  true) {
        return false;
    }
    if(this->isArray(s) == true) {
        return false;
    }

    return (s.isEmpty() == true) ? false : s.contains(QRegExp("\\=") );
}
