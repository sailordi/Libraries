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
 * \date Last update: 2021-04-22
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
