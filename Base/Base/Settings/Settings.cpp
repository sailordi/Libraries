#include "Settings.h"

//Public functions
Settings::Settings(QString file,bool write) {
    this->v_file = file;
    this->v_write = write;
    this->v_groups = new QHash<SettingsKey,SettingsGroup*>();
}

Settings::~Settings() {

    QList<SettingsKey> gN = this->v_groups->keys();

    while(gN.size() > 0) {
        delete this->v_groups->take(gN.takeFirst() );
    }

    delete this->v_groups;
}
