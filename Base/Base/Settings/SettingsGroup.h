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

    /*! Adds data to new settings block
     * \param key - The key
     * \param val - The value
    */
    void addBlockData(QString key,QVariant val);

    /*! Gets value from a settings block
      * \param key - The key
      * \param def - Default value [Defaiult: QVariant()]
      * \returns QVariant
     */
    QVariant blockData(QString key,QVariant def = QVariant() );

    /*! Returns all keys for the setting blocks
     * \returns QList<SettingsKey>
    */
    QList<SettingsKey> blockKeys();

private:
    SettingsBlocks* v_blocks = nullptr;
    QHash<SettingsKey,QList<SettingsBlocks>*>* v_arrays = nullptr;

};

inline uint qHash(const SettingsKey& c,uint seed) {
    return qHash(c.keyC(),seed);
}
#endif // SETTINGSGROUP_H
