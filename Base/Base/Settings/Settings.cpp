#include "Settings.h"

#include "Base/Settings/SettingsFile.h"

//Public functions
Settings::Settings(QString file,bool write) {
    this->v_file = file;
    this->v_write = write;
    this->v_groups = new QHash<SettingsKey,SettingsGroup*>();

    this->load();
}

Settings::~Settings() {
    this->save();

    QList<SettingsKey> gN = this->v_groups->keys();

    while(gN.size() > 0) {
        delete this->v_groups->take(gN.takeFirst() );
    }

    delete this->v_groups;
}

void Settings::startGroup(QString groupName) {
    if(this->v_groupN.isEmpty() == false) {
        throw QString("Group has not been ended can not start new group");
    }

    this->v_groupN = groupName;

    if(this->v_groups->contains(SettingsKey(this->v_groupN) ) == false) {
        this->v_groups->insert(SettingsKey(this->v_groupN,this->v_groups->size() ),new SettingsGroup() );
    }

}

void Settings::endGroup() {
    if(this->v_groupN.isEmpty() == true) {
        throw QString("Group has not been started can not end group");
    }
    if(this->v_arrayN.isEmpty() == false) {
        throw QString("Array has not been ended can not end group");
    }

    this->v_groupN = "";
}

void Settings::startArray(QString arrayName) {
    if(this->v_groupN.isEmpty() == true) {
        throw QString("Group has not been started can not start new array");
    }
    if(this->v_arrayN.isEmpty() == false) {
        throw QString("Array has not been ended can not start new array");
    }

    this->v_arrayN = arrayName;
}

void Settings::endArray() {
    if(this->v_groupN.isEmpty() == true) {
        throw QString("Group has not been started can not end array");
    }
    if(this->v_arrayN.isEmpty() == true) {
        throw QString("Array has not been started can not end array");
    }

    this->v_arrayN = "";
}

void Settings::addBlockData(QString key,QVariant val) {
    if(this->v_groupN.isEmpty() == true) {
        throw QString("Group has not been started can not add data [block]");
    }

    SettingsGroup* g = this->currentGroup();

    if(g == nullptr) {
        throw QString("Group can not be found [add data block] ")+this->v_groupN;
    }

    g->addBlockData(key,val);
}

void Settings::addArrayData(int pos,QList<QString> keys,QList<QVariant> vals) {
    if(this->v_groupN.isEmpty() == true) {
        throw QString("Group has not been started can not add data [array]");
    }
    if(this->v_arrayN.isEmpty() == true) {
        throw QString("Array has not been started can not add data [array] "+this->v_groupN);
    }

    SettingsGroup* g = this->currentGroup();

    if(g == nullptr) {
        throw QString("Group can not be found [add data array] ")+this->v_groupN+QString("/")+this->v_arrayN;
    }

    g->addArrayData(this->v_arrayN,pos,keys,vals);
}

void Settings::addArrayData(QList<QString> keys, QList<QVariant> vals) {
    if(this->v_groupN.isEmpty() == true) {
        throw QString("Group has not been started can not add data [array]");
    }
    if(this->v_arrayN.isEmpty() == true) {
        throw QString("Array has not been started can not add data [array] "+this->v_groupN);
    }

    SettingsGroup* g = this->currentGroup();

    if(g == nullptr) {
        throw QString("Group can not be found [add data array] ")+this->v_groupN+QString("/")+this->v_arrayN;
    }

    g->addArrayData(this->v_arrayN,keys,vals);
}

QVariant Settings::getBlockData(QString key,QVariant def) {
    if(this->v_groupN.isEmpty() == true) {
        throw QString("Group has not been started can not get data [block]");
    }

    SettingsGroup* g = this->currentGroup();

    if(g == nullptr) {
        throw QString("Group can not be found [get data block] ")+this->v_groupN+QString("/")+this->v_arrayN;
    }

    return g->blockData(key,def);
}

QList<QVariant> Settings::getArrayData(int pos,QList<QString> keys,QList<QVariant> defs) {
    if(this->v_groupN.isEmpty() == true) {
        throw QString("Group has not been started can not get data [get data array]");
    }
    if(this->v_arrayN.isEmpty() == true) {
        throw QString("Array has not been started can not get data [get data array] "+this->v_groupN);
    }

    if(keys.size() != defs.size() ) {
        throw QString("Keys and defs size has to be the same cannot get data [get data array] ")+QString::number(keys.size() )+" / "+QString::number(defs.size() );
    }

    SettingsGroup* g = this->currentGroup();

    if(g == nullptr) {
        throw QString("Group can not be found [get data array] ")+this->v_groupN+QString("/")+this->v_arrayN;
    }

    QList<SettingsBlocks>* bL = g->arrayData(this->v_arrayN);

    if(bL == nullptr) {
        return defs;
    }
    if(pos < 0 || pos >= bL->size() ) {
        return defs;
    }

    SettingsBlocks b = g->arrayData(this->v_arrayN,pos);
    QList<QVariant> ret;

    for(int i = 0; i < keys.size(); i++) {
        SettingsKey k(keys.at(i) );
        ret.push_back(b.value(k,defs.at(i) ) );
    }

    return ret;
}

QList<QList<QVariant> > Settings::getArrayData(QList<QString> keys,QList<QVariant> defs) {
    if(this->v_groupN.isEmpty() == true) {
        throw QString("Group has not been started can not get data [get data array]");
    }
    if(this->v_arrayN.isEmpty() == true) {
        throw QString("Array has not been started can not get data [get data array] "+this->v_groupN);
    }

    if(keys.size() != defs.size() ) {
        throw QString("Keys and defs size has to be the same cannot get data [get data array] ")+QString::number(keys.size() )+" / "+QString::number(defs.size() );
    }

    SettingsGroup* g = this->currentGroup();

    if(g == nullptr) {
        throw QString("Group can not be found [get data array] ")+this->v_groupN+QString("/")+this->v_arrayN;
    }

    QList<SettingsBlocks>* bL = g->arrayData(this->v_arrayN);
    QList<QList<QVariant> > ret;

    if(bL == nullptr || (bL != nullptr && bL->size() == 0) ) {
        ret.push_back(defs);
        return ret;
    }

    for(int i = 0; i < bL->size(); i++) {
        QList<QVariant> tmp;
        SettingsBlocks b = bL->at(i);

        for(int j = 0; j < keys.size(); j++) {
            QString k = keys.at(j);
            QVariant d = defs.at(j);

            tmp.push_back(b.value(k,d) );
        }
        ret.push_back(tmp);
    }

    return ret;
}

void Settings::removeBlock(QString key, bool throwError) {
    if(this->v_groupN.isEmpty() == true && throwError == true) {
        throw QString("Group has not been started can not remove block");
    }
    else if(this->v_groupN.isEmpty() == true && throwError == false) {
        return;
    }

    if(key.isEmpty() == true && throwError == true) {
        throw QString("key was empty");
    }
    if(key.isEmpty() == true && throwError == false) {
        return;
    }

    SettingsGroup* g = this->currentGroup();

    if(g == nullptr && throwError == true) {
        throw QString("Group can not be found [remove block] ")+this->v_groupN+QString("/")+key;
    }
    if(g == nullptr && throwError == false) {
        return;
    }

    SettingsKey k(key);

    if(g->blocks()->contains(k) == false && throwError == true) {
        throw QString("Block can not be found [remove block] ")+key;
    }
    else if(g->blocks()->contains(k) == false && throwError == false) {
        return;
    }

    g->blocks()->take(k);
}

int Settings::arraySize() {
    if(this->v_groupN.isEmpty() == true) {
        throw QString("Group has not been started can not get array size");
    }
    if(this->v_arrayN.isEmpty() == true) {
        throw QString("Array has not been started can not get array size "+this->v_groupN);
    }

    SettingsGroup* g = this->currentGroup();

    if(g == nullptr) {
        throw QString("Group can not be found [get array size] ")+this->v_groupN+QString("/")+this->v_arrayN;
    }

    QList<SettingsBlocks>* bL = g->arrayData(this->v_arrayN);

    if(bL == nullptr) {
        return -1;
    }

    return bL->size();
}

void Settings::clearArray(bool throwError) {
    if(this->v_groupN.isEmpty() == true && throwError == true) {
        throw QString("Group has not been started can not clear array");
    }
    else if(this->v_groupN.isEmpty() == true && throwError == false) {
        return;
    }

    if(this->v_arrayN.isEmpty() == true && throwError == true) {
        throw QString("Array has not been started can not clear array "+this->v_groupN);
    }
    if(this->v_arrayN.isEmpty() == true && throwError == false) {
        return;
    }

    SettingsGroup* g = this->currentGroup();

    if(g == nullptr && throwError == true) {
        throw QString("Group can not be found [clear array] ")+this->v_groupN+QString("/")+this->v_arrayN;
    }
    if(g == nullptr && throwError == false) {
        return;
    }

    QList<SettingsBlocks>* bL = g->arrayData(this->v_arrayN);

    if(bL == nullptr && throwError == true) {
        throw QString("Array can not be found [clear array] ")+this->v_arrayN;
    }
    if(bL == nullptr && throwError == false) {
        return;
    }

    bL->clear();
}

//Private functions
void Settings::load() {
    SettingsFile f(this->v_file,true);

        if(f.open() == false) {
            throw QString("Could not open file loading settings [File: ")+this->v_file+QString("]");
        }

        int pos = 0;

        do{
            QString gN = "";
            SettingsGroup* g = new SettingsGroup();

            f.read(gN,g);

            if(gN.isEmpty() == true) {
                delete g;
                continue;
            }
            SettingsKey cK(gN,pos++);

            this->v_groups->insert(cK,g);

        }while(f.atEnd() == false);

}

void Settings::save() {
    if(this->v_write == false) {
        return;
    }

    SettingsFile f(this->v_file,false);

    if(f.open() == false) {
        throw QString("Could not open file saving settings [File: ")+this->v_file+QString("]");
    }

    QList<SettingsKey> gN = this->v_groups->keys();

    std::sort(gN.begin(),gN.end(),SettingsKey::sortAsc);

    for(int i = 0; i < gN.size(); i++) {
        SettingsKey cK = gN.at(i);
        SettingsGroup* g = this->v_groups->value(cK,nullptr);

        if(g == nullptr) {
            break;
        }

        f.write(cK.key(),g);
    }

}

SettingsGroup* Settings::currentGroup() {
    SettingsKey cK(this->v_groupN);

        return this->v_groups->value(cK,nullptr);
}
