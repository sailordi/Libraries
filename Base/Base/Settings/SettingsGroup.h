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
 * \date Last update: 2021-04-29
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

    /*! Adds data to a settings array at a specific position
     * If position less than 0 adds data to front of array list
     * If position is more than/equal to the size adds data to end of array
     * If position is in the array list replace the alredy existing data
     * \param name - Array name
     * \param pos - The position
     * \param keys - The keys
     * \param vals - The values
    */
    void addArrayData(QString name,int pos,QList<QString> keys,QList<QVariant> vals);
    /*! Adds data to a settings array
     * \param name - Array name
     * \param keys - The keys
     * \param vals - The values
    */
    void addArrayData(QString name,QList<QString> keys,QList<QVariant> vals);

    /*! Returns the data from a settings array at a specific position
     * \param name - The array name
     * \param pos - The position
     * \returns SettingsBlocks
    */
    SettingsBlocks arrayData(QString name,int pos);
    /*! Returns the data from a settings array
     * \param name - The array name
     * \returns QList<SettingsBlocks>*
    */
    QList<SettingsBlocks>* arrayData(QString name);

    /*! Returns list of all settings array names
     * \returns QList<SettingsCustomKey>
    */
    QList<SettingsKey> arrayNames();

    /*! Returns a pointer to the settings blocks
     * \returns SettingsBlocks*
    */
    SettingsBlocks* blocks();

    /*! Returns a pointer to the settings arrays
     * \returns QHash<SettingsKey,QList<SettingsBlocks>* >*
    */
    QHash<SettingsKey,QList<SettingsBlocks>* >* arrays();

private:
    SettingsBlocks* v_blocks = nullptr;
    QHash<SettingsKey,QList<SettingsBlocks>*>* v_arrays = nullptr;

};

inline uint qHash(const SettingsKey& c,uint seed) {
    return qHash(c.keyC(),seed);
}
#endif // SETTINGSGROUP_H
