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
