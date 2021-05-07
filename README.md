# Libraries
A Qt subdir project with multiple libraries

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