#include "SettingsGroup.h"

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
