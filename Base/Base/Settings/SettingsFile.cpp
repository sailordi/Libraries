#include "SettingsFile.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QRect>
#include <QRectF>
#include <QRegularExpression>
#include <QPoint>
#include <QPointF>
#include <QSize>
#include <QSizeF>
#include <QTextStream>
#include <QVariant>

#include "Base/Other/Helper.h"
#include "Base/Settings/SettingsGroup.h"

QRegularExpression reg;

//Public functions
SettingsFile::SettingsFile(QString file,bool read) {
    this->v_f = new QFile(file);
    this->v_read = read;

    QFileInfo i(file);
    QDir d = i.absoluteDir();

    if(d.exists() == false) {
        d.mkdir(d.absolutePath() );
    }

    if(i.exists() == false && this->v_read == true) {
        QFile t(file);

        t.open(QFile::WriteOnly);
        t.flush();
        t.close();
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
    this->v_s->setEncoding(QStringConverter::Utf8);

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

void SettingsFile::write(QString groupName,SettingsGroup* gD) {
    if(this->v_read == true) {
         throw QString("SettingsFile is not in write mode");
     }

     *this->v_s<<QString("[")<<groupName<<QString("]")<<Helper::newRow();

     QList<SettingsKey> keys = gD->blockKeys();
     QList<SettingsKey> names = gD->arrayNames();

     std::sort(keys.begin(),keys.end(),SettingsKey::sortAsc);
     std::sort(names.begin(),names.end(),SettingsKey::sortAsc);
     //Write Blocks
     for(int i = 0; i < keys.size(); i++) {
         SettingsKey k = keys.at(i);
         writeKeyValue(this->v_s,k.key(),gD->blockData(k.key() ) );
     }
     //Write Arrays
     for(int i = 0; i < names.size(); i++) {
         SettingsKey n = names.at(i);
         QList<SettingsBlocks>* bL = gD->arrayData(n.key() );

         *this->v_s<<QString("[")<<n.key()<<QString("]")<<QString::number(bL->size() )<<Helper::newRow();

         for(int j = 0,col = 1; j < bL->size(); j++,col++) {
             SettingsBlocks b = bL->at(j);
             QList<SettingsKey> kL = b.keys();

             std::sort(kL.begin(),kL.end(),SettingsKey::sortAsc);

             for(int k = 0; k < kL.size(); k++) {
                 SettingsKey t = kL.at(k);
                 *this->v_s<<QString::number(col)<<QString("¤");
                 writeKeyValue(this->v_s,t.key(),b.value(t,QVariant() ) );
             }

         }

     }

}

void SettingsFile::read(QString& groupName,SettingsGroup* gD) {
    if(this->v_read == false) {
        throw QString("SettingsFile is not in read mode");
    }

    QString str = "";
    qint64 pos;
    bool first = true;

    do {
        pos = this->v_s->pos();
        str = this->v_s->readLine();

        if(str.isEmpty() == true) {
            return;
        }

        if(isGoup(str) == true && first == true) {
            groupName = this->parseGroupName(str);
        }
        else if(isGoup(str) == true && first == false) {
            this->v_s->seek(pos);
            return;
        }

        if(isBlock(str) == true) {
            this->parseBlock(str,gD);
        }

        if(isArray(str) == true) {
            this->v_s->seek(pos);
            this->parseArray(this->v_s,gD);
        }

        if(first == true) {
            first = false;
        }

    }while(true);

}

bool SettingsFile::atEnd() {
    if(this->v_f == nullptr) {
        return false;
    }
    if(this->v_s == nullptr) {
        return false;
    }

    return this->v_s->atEnd();
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
    reg.setPattern("\\[.*\\]$");

    return (s.isEmpty() == true) ? false : s.contains(reg);
}

bool SettingsFile::isArray(QString s) {
    reg.setPattern("\\[.*\\]\\d.");

    return (s.isEmpty() == true) ? false : s.contains(reg);
}

bool SettingsFile::isBlock(QString s) {
    if(this->isGoup(s) ==  true) {
        return false;
    }
    if(this->isArray(s) == true) {
        return false;
    }
    reg.setPattern("\\=");

    return (s.isEmpty() == true) ? false : s.contains(reg);
}

QStringList SettingsFile::separate(QString type,QString str) {
    if(type.isEmpty() == false) {
        str.replace(type,"");
        str.replace("(","");
        str.replace(")","");
    }
    reg.setPattern("\\s+");

    return str.split(reg);
}

QString SettingsFile::variantToString(QVariant v) {
    switch(v.typeId() ) {
        case QMetaType::QRect: {
            QRect r = v.toRect();
            return QString("@Rect(%1 %2 %3 %4)").arg(r.x() ).arg(r.y() ).arg(r.width() ).arg(r.height() );
        }
        case QMetaType::QRectF: {
            QRectF r = v.toRectF();
            return QString("@RectF(%1 %2 %3 %4)").arg(r.x() ).arg(r.y() ).arg(r.width() ).arg(r.height() );
        }
        case QMetaType::QSize:{
            QSize s = v.toSize();
            return QString("@Size(%1 %2)").arg(s.width() ).arg(s.height() );
        }
        case QMetaType::QSizeF:{
            QSizeF s = v.toSizeF();
            return QString("@SizeF(%1 %2)").arg(s.width() ).arg(s.height() );
        }
        case QMetaType::QPoint:{
            QPoint p = v.toPoint();
            return QString("@Point(%1 %2)").arg(p.x() ).arg(p.y() );
        }
        case QMetaType::QPointF:{
            QPointF p = v.toPointF();
            return QString("@PointF(%1 %2)").arg(p.x() ).arg(p.y() );
        }
        default:
            return v.toString();
    }

}

QVariant SettingsFile::stringToVariant(QString s) {
    reg.setPattern("\\@");

    if(s.contains(reg) == false)  { return QVariant(s); }

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
    reg.setPattern("\\=");

    QStringList l = str.split(reg);

    (l.size() == 2) ? gD->addBlockData(l.first(),this->stringToVariant(l.last() ) ) : gD->addBlockData(l.first(),"");
}

void SettingsFile::parseArray(QTextStream* s,SettingsGroup* gD) {
    QString currentLine = s->readLine();

    reg.setPattern("\\[|\\]");

    QStringList l = currentLine.split(reg);
    QString name = (l.size() == 2) ? l.first() : l.at(1);
    int size = l.last().toInt();

        for(int i = 0; i < size; i++) {
            QList<QString> keys;
            QList<QVariant> vals;
            bool stopLoop = false;

            do{
                currentLine = s->readLine();
                qint64 pos = s->pos();
                QString nextLine = s->readLine();

                reg.setPattern("\\¤");

                QStringList c = currentLine.split(reg);
                int ent = c.takeFirst().toInt();
                int nextEnt = -1;

                if(this->isArray(nextLine) == false && nextLine.isEmpty() == false) {
                    QStringList n = nextLine.split(reg);
                    nextEnt = n.takeFirst().toInt();
                }

                reg.setPattern("\\=");

                QStringList d = c.first().split(reg);

                keys.push_back(d.first() );
                (d.size() == 2) ? vals.push_back(stringToVariant(d.last() ) ) : vals.push_back("");

                if(ent != nextEnt) {
                    stopLoop = true;
                }

                s->seek(pos);

            }while(stopLoop == false);

            gD->addArrayData(name,keys,vals);
        }

}
