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
