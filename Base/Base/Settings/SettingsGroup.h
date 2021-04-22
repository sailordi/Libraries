#ifndef SETTINGSGROUP_H
#define SETTINGSGROUP_H

#include <QHash>
#include <QString>
#include <QVariant>

#include "Base/Other/CustomIndexedKey.h"

typedef CustomIndexedKey<QString> SettingsKey;
typedef QHash<SettingsKey,QVariant> SettingsBlocks;

/*! \class SettingsGroup
 * \brief The class represents a group of settings
 *
 * Incudes: QHash, QString, QVariant & CustomIndexedKey
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-22
 * \date Last update: 2021-04-22
*/
class SettingsGroup
{
public:
    /*! Constructor */
    SettingsGroup();
    /*! Deconstructor */
    ~SettingsGroup();

private:
    SettingsBlocks* v_blocks = nullptr;
    QHash<SettingsKey,QList<SettingsBlocks>*>* v_arrays = nullptr;

};
#endif // SETTINGSGROUP_H
