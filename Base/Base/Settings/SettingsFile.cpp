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

#include "Base/Other/Helper.h"
#include "Base/Settings/SettingsGroup.h"

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

bool SettingsFile::open() {
    if(this->v_f == nullptr) {
        return false;
    }
    if(this->v_s == nullptr) {
        return false;
    }

    return this->v_f->isOpen();
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

QVariant SettingsFile::stringToVariant(QString s) {
    if(s.contains(QRegExp("\\@") ) == false)  { return QVariant(s); }
    if(s.contains(QRegExp("\\@Invalid") ) == true)  { return QVariant(); }

    if(s.contains("@RectF") == true) {
        QStringList l = this->separate("@RectF",s);
        return QVariant(QRectF(l.at(0).toDouble(),l.at(1).toDouble(),l.at(2).toDouble(),l.at(3).toDouble() ) );
    }
    if(s.contains("@Rect") == true) {
        QStringList l = this->separate("@Rect",s);
        return QVariant(QRect(l.at(0).toInt(),l.at(1).toInt(),l.at(2).toInt(),l.at(3).toInt() ) );
    }

    if(s.contains("@SizeF") == true) {
        QStringList l = this->separate("@SizeF",s);
        return QVariant(QSizeF(l.at(0).toDouble(),l.at(1).toDouble() ) );
    }
    if(s.contains("@Size") == true) {
        QStringList l = this->separate("@Size",s);
        return QVariant(QSize(l.at(0).toInt(),l.at(1).toInt() ) );
    }

    if(s.contains("@PointF") == true) {
        QStringList l = this->separate("@PointF",s);
        return QVariant(QPointF(l.at(0).toDouble(),l.at(1).toDouble() ) );
    }
    if(s.contains("@Point") == true) {
        QStringList l = this->separate("@Point",s);
        return QVariant(QPoint(l.at(0).toInt(),l.at(1).toInt() ) );
    }

    return QVariant();
}

void SettingsFile::writeKeyValue(QTextStream* s,QString key,QVariant val) {
    *s<<key<<QString("=")<<this->variantToString(val)<<Helper::newRow();
}

QString SettingsFile::parseGroupName(QString str) {
    str.replace("[","");
    str.replace("]","");

    return str;
}

void SettingsFile::parseBlock(QString str,SettingsGroup* gD) {
    QStringList l = str.split(QRegExp("\\=") );

    (l.size() == 2) ? gD->addBlockData(l.first(),this->stringToVariant(l.last() ) ) : gD->addBlockData(l.first(),"");
}

void SettingsFile::parseArray(QTextStream* s,SettingsGroup* gD) {
    qint64 pos = s->pos();
    QString currentLine = s->readLine();

    QStringList l = currentLine.split(QRegExp("\\[|\\]") );
    QString name = l.first();
    int size = l.last().toInt();

        for(int i = 0; i < size; i++) {
            QList<QString> keys;
            QList<QVariant> vals;
            bool stopLoop = false;

            do{
                currentLine = s->readLine();
                pos = s->pos();
                QString nextLine = s->readLine();

                QStringList c = currentLine.split(QRegExp("\\¤") );
                int columns = c.takeFirst().toInt();

                if(isArray(nextLine) == false && nextLine.isEmpty() == false) {
                    QStringList n = nextLine.split(QRegExp("\\¤") );

                    if(columns != n.first().toInt() ) {
                        stopLoop = true;
                    }
                }
                else {
                    stopLoop = true;
                }
                QStringList d = c.first().split(QRegExp("\\=") );

                keys.push_back(d.first() );
                (d.size() == 2) ? vals.push_back(stringToVariant(d.last() ) ) : vals.push_back("");

                s->seek(pos);

            }while(stopLoop == false);

            gD->addArrayData(name,keys,vals);
        }

}
