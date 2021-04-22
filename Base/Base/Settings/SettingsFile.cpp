#include "SettingsFile.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QRect>
#include <QRectF>
#include <QRegExp>
#include <QPoint>
#include <QPointF>
#include <QSize>
#include <QSizeF>
#include <QTextStream>
#include <QVariant>

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

QStringList SettingsFile::separate(QString type,QString str) {
    if(type.isEmpty() == false) {
        str.replace(type,"");
        str.replace("(","");
        str.replace(")","");
    }
    return str.split(QRegExp("\\s+") );
}

QString SettingsFile::variantToString(QVariant v) {
    switch(v.type() ) {
        case QVariant::Invalid:
            return QString("@Invalid()");
        case QVariant::Rect: {
            QRect r = v.toRect();
            return QString("@Rect(%1 %2 %3 %4)").arg(r.x() ).arg(r.y() ).arg(r.width() ).arg(r.height() );
        }
        case QVariant::RectF: {
            QRectF r = v.toRectF();
            return QString("@RectF(%1 %2 %3 %4)").arg(r.x() ).arg(r.y() ).arg(r.width() ).arg(r.height() );
        }
        case QVariant::Size:{
            QSize s = v.toSize();
            return QString("@Size(%1 %2)").arg(s.width() ).arg(s.height() );
        }
        case QVariant::SizeF:{
            QSizeF s = v.toSizeF();
            return QString("@SizeF(%1 %2)").arg(s.width() ).arg(s.height() );
        }
        case QVariant::Point:{
            QPoint p = v.toPoint();
            return QString("@Point(%1 %2)").arg(p.x() ).arg(p.y() );
        }
        case QVariant::PointF:{
            QPointF p = v.toPointF();
            return QString("@PointF(%1 %2)").arg(p.x() ).arg(p.y() );
        }
        default:
            return v.toString();
    }

}
