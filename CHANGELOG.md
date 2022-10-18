## V1
```
Created the main .pro file for the subdir project
Created the static library Base which contains base classes
```
## V2
```
Created a class that contains common functionality shared by the layout widgets
Added inheritance to the ComboBoxAdapter class
Added a slot and a signal for when the index has changed it will take into account if the first string is empty or not
Added a function that sets the Combobox selected row
Added a function that sets the first string of the Combobox
Added functions to add array data at a specific possition
Added functions to return array data from a specific possition
Added a function that returns a pointer to the setting blocks
Added a function that returns a pointer to the setting arrays
Added a function that removes a settings array
Added a function that removes a settings block
Created a class that is an base adapter against a QTreeView, contains common functions between TreeView adapters
Added the base view adapter to the view adapters
```
## V3
```
Created the file Common .pri the file contains common elements that all libraries .pro files share
Created a .pro for the shared library Message witch contains base classes for messages
Fixed problem where deconstructor was missing
```
## V3_1
```
Fixed some comment errors
Added the option to only translate the windowNotice manually
Added a function that checks for errors with the tab / page text
Refactoring: removed error checks from WindowNoticeWidgets classes
```
## V4
```
Created the shared library SQL which contains all SQL clases
```
## V4_1
```
Fixed issue where the file was not created on file being read in the class SettingsFile
Fixed issue where multiple things was not removed from the header file in the TreeViewAdapters
Added a constructor to ComboBoxAdapter
Fixed an issue where arrays were not red from settings files correctly and updated how the array is written
```
## V5
```
Updated the c++ to 17
Updated code to Qt6
Renamed the folder SQL to Query
Renamed a bunch of files to better represent what they do
Created the class MySQL_DB
Created the class MariaDb_DB
Uppdated how the retranslation works in notice classes
Uppdated how the fonts are sett in the notice classes