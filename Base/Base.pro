QT  += core widgets
QT -= gui

CONFIG += c++14
TEMPLATE = lib
CONFIG += staticlib

CONFIG(release,debug|release)   { TARGET = Base }
CONFIG(debug,debug|release)     { TARGET = Base_D }

SOURCES += \
    Base/Adapter/ComboBoxAdapter.cpp \
    Base/Adapter/StandardItemCreator.cpp \
    Base/Adapter/TreeViewAdapterNoChildRows.cpp \
    Base/LayoutWidget/MultiLayoutWidget.cpp \
    Base/LayoutWidget/SingleLayoutWidget.cpp \
    Base/Other/Helper.cpp \
    Base/Other/QStringStream.cpp \
    Base/Other/Translator.cpp \
    Base/Settings/Settings.cpp \
    Base/Settings/SettingsFile.cpp \
    Base/Settings/SettingsGroup.cpp \
    Base/Thread/MutexTryLocker.cpp \
    Base/Thread/ThreadCalculator.cpp

HEADERS += \
    Base/Adapter/ComboBoxAdapter.h \
    Base/Adapter/StandardItemCreator.h \
    Base/Adapter/TreeViewAdapterNoChildRows.h \
    Base/LayoutWidget/MultiLayoutWidget.h \
    Base/LayoutWidget/SingleLayoutWidget.h \
    Base/Other/CustomIndexedKey.h \
    Base/Other/Helper.h \
    Base/Other/QStringStream.h \
    Base/Other/Translator.h \
    Base/Settings/Settings.h \
    Base/Settings/SettingsFile.h \
    Base/Settings/SettingsGroup.h \
    Base/Thread/MutexTryLocker.h \
    Base/Thread/ThreadCalculator.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
