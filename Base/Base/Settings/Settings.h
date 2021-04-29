#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QHash>
#include <QVariant>

#include "Base/Settings/SettingsGroup.h"

/*! \class Settings
 * \brief The class handles the setting logic
 *
 * Incudes: QString, QHash, QVariant & SettingsGroup
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-22
 * \date Last update: 2021-04-29
*/
class Settings
{
public:
    /*! Constructor
    * \param file - The file
    * \param write - If the file should be written to [Default: true]
    * \throws QString
    */
    Settings(QString file,bool write = true);
    /*! Deconstructor
    * \throws QString
    */
    ~Settings();

    /*! Starts the group
    * \param groupName - The group name
    * \throws QString
    */
    void startGroup(QString groupName);
    /*! Ends the group
    * \throws QString
    */
    void endGroup();

    /*! Starts the array
    * \param arrayName - The array name
    * \throws QString
    */
    void startArray(QString arrayName);
    /*! Ends the array
    * \throws QString
    */
    void endArray();

    /*! Adds data to a block for the current settings group
     * \param key - String used for the key
     * \param val - The value
     * \throws QString
    */
    void addBlockData(QString key,QVariant val);
    /*! Adds data to a settings array at a specific position for the current settings group
     * \param pos - The position
     * \param keys - Strings used for the keys
     * \param vals - The values
     * \throws QString
    */
    void addArrayData(int pos,QList<QString> keys,QList<QVariant> vals);
    /*! Adds data to a settings array for the current settings group
     * \param keys - Strings used for the keys
     * \param vals - The values
     * \throws QString
    */
    void addArrayData(QList<QString> keys,QList<QVariant> vals);

    /*! Gets the data from a block for the current settings group
     * \param key - String used fro the key
     * \param def - Default value [Defaiult: QVariant()]
     * \returns QVariant
     * \throws QString
    */
    QVariant getBlockData(QString key,QVariant def = QVariant()  );
    /*! Gets the data from a settings array at a specific position for the current settings group
     * \param pos - The position
     * \param keys - Strings used for the keys
     * \param defs - Default values
     * \returns QList<QVariant>
     * \throws QString
    */
    QList<QVariant> getArrayData(int pos,QList<QString> keys,QList<QVariant> defs);
    /*! Gets the data from a settings array for the current settings group
     * \param keys - Strings used for the keys
     * \param defs - Default values
     * \returns QList<QList<QVariant> >
     * \throws QString
    */
    QList<QList<QVariant> > getArrayData(QList<QString> keys,QList<QVariant> defs);

    /*! Gets the size of a settings array for the current settings group
     * \returns int
     * \throws QString
    */
    int arraySize();

    /*! Clears a settings array for the current settings group
     * \param throwError - If error should be thrown [Default: true]
     * \throws QString
    */
    void clearArray(bool throwError = true);

private:
   QString v_file = "",v_groupN = "",v_arrayN = "";
   bool v_write;

   QHash<SettingsKey,SettingsGroup*>* v_groups = nullptr;

   /*! Loads all settings groups from a file
    * \throws QString
   */
   void load();
   /*! Saves all settings groups to a file
    * \throws QString
   */
   void save();

   /*! Gets the currently active settings group
   * \returns SettingsGroup*
   */
   SettingsGroup* currentGroup();

};
#endif // SETTINGS_H
