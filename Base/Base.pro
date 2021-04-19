QT  += core widgets
QT -= gui

CONFIG += c++14
TEMPLATE = lib
CONFIG += staticlib

CONFIG(release,debug|release)   { TARGET = Base }
CONFIG(debug,debug|release)     { TARGET = Base_D }

SOURCES +=

HEADERS +=

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
