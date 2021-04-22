#include "SettingsGroup.h"

#include "Base/Other/Helper.h"

//Public functions
SettingsGroup::SettingsGroup() {
    this->v_blocks = new Blocks();
    this->v_arrays = new QHash<CustomKey,QList<Blocks>*>();
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

QList<SettingsBlocks>* SettingsGroup::arrayData(QString name) {
    SettingsKey n(name);

        return this->v_arrays->value(n,nullptr);
}

QList<SettingsKey> SettingsGroup::arrayNames() {
    return this->v_arrays->keys();
}
