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
