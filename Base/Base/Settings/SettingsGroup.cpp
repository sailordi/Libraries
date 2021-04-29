#include "SettingsGroup.h"

#include "Base/Other/Helper.h"

//Public functions
SettingsGroup::SettingsGroup() {
    this->v_blocks = new SettingsBlocks();
    this->v_arrays = new QHash<SettingsKey,QList<SettingsBlocks>*>();
}

SettingsGroup::~SettingsGroup() {
    if(this->v_blocks != nullptr) {
        delete this->v_blocks;
    }

    if(this->v_arrays != nullptr) {
        QList<SettingsKey> keys = this->v_arrays->keys();

        for(int i = 0; i < keys.size(); i++) {
            delete this->v_arrays->take(keys.at(i) );
        }

        delete this->v_arrays;
    }

}

void SettingsGroup::addBlockData(QString key,QVariant val) {
    SettingsKey k1(key);

        if(this->v_blocks->contains(k1) == false) {
            SettingsKey k2(key,this->v_blocks->size()+1);

            this->v_blocks->insert(k2,val);
        }
        else {
            this->v_blocks->insert(k1,val);
        }
}

QVariant SettingsGroup::blockData(QString key,QVariant def) {
    SettingsKey k(key);

        return this->v_blocks->value(k,def);
}

QList<SettingsKey> SettingsGroup::blockKeys() {
    return this->v_blocks->keys();
}

void SettingsGroup::addArrayData(QString name,int pos,QList<QString> keys,QList<QVariant> vals) {
    SettingsKey n1(name);
    QList<SettingsBlocks>* l = nullptr;

        if(this->v_arrays->contains(n1) == false) {
            l = new QList<SettingsBlocks>();
            SettingsKey n2(name,this->v_arrays->size() );
            this->v_arrays->insert(n2,l);
        }  else {
            l = this->v_arrays->value(n1,nullptr);
        }

        if(l == nullptr) {
            Helper::quitProgram("Error could not get or create list of blocks for "+name,1);
        }

        SettingsBlocks b;

        for(int i = 0; i < keys.size(); i++) {
            SettingsKey k(keys.at(i),i);
            b.insert(k,vals.at(i) );
        }

        if(pos < 0) {
            l->push_front(b);
        }
        else if(pos >= l->size() ) {
            l->push_back(b);
        }
        else {
            l->replace(pos,b);
        }

}

void SettingsGroup::addArrayData(QString name,QList<QString> keys,QList<QVariant> vals) {
    SettingsKey n1(name);
    QList<SettingsBlocks>* l = nullptr;

        if(this->v_arrays->contains(n1) == false) {
            l = new QList<SettingsBlocks>();
            SettingsKey n2(name,this->v_arrays->size() );
            this->v_arrays->insert(n2,l);
        }  else {
            l = this->v_arrays->value(n1,nullptr);
        }

        if(l == nullptr) {
            Helper::quitProgram("Error could not get or create list of blocks for "+name,1);
        }

        SettingsBlocks b;

        for(int i = 0; i < keys.size(); i++) {
            SettingsKey k(keys.at(i),i);
            b.insert(k,vals.at(i) );
        }

        l->push_back(b);
}

SettingsBlocks SettingsGroup::arrayData(QString name,int pos) {
    QList<SettingsBlocks>* tmp = this->arrayData(name);

        if(tmp == nullptr) {
            Helper::quitProgram("Error could not get list of blocks for "+name,1);
        }

        if(pos < 0) {
            Helper::quitProgram("Error position is less than 0 "+name,1);
        }
        else if(pos >= tmp->size() ) {
            Helper::quitProgram("Error position larger than list size "+name,1);
        }

        return tmp->at(pos);
}

QList<SettingsBlocks>* SettingsGroup::arrayData(QString name) {
    SettingsKey n(name);

        return this->v_arrays->value(n,nullptr);
}

QList<SettingsKey> SettingsGroup::arrayNames() {
    return this->v_arrays->keys();
}

SettingsBlocks* SettingsGroup::blocks() {
    return this->v_blocks;
}

QHash<SettingsKey, QList<SettingsBlocks>*>* SettingsGroup::arrays() {
    return this->v_arrays;
}
