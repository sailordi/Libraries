QT += core widgets sql
QT -= gui

! include( ../Common.pri ) {
    error( "Couldn't find the Common.pri file!" )
}

DEFINES += SQL_LIBRARY

CONFIG(release,debug|release) { TARGET = SQL }
CONFIG(debug,debug|release) { TARGET = SQL_D }

win32:!win32-g++ {
    contains(QMAKE_HOST.arch, x86_64) {
        QMAKE_LFLAGS += /MACHINE:X64
    } else {
        QMAKE_LFLAGS += /MACHINE:X86
    }
}

INCLUDEPATH += $$PWD/../Base
DEPENDPATH += $$PWD/../Base

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Base/ -lBase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Base/ -lBase_D
else:unix:!macx: LIBS += -L$$OUT_PWD/../Base/ -lBase_D

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Base/libBase.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Base/libBase_D.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Base/Base.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Base/Base_D.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../Base/libBase_D.a

SOURCES += \
    SQL/Base/DB/DB.cpp \
    SQL/Base/DB/DatabaseInfo.cpp \
    SQL/Base/DB/DatabaseUser.cpp \
    SQL/Base/Other/Connection.cpp \
    SQL/Base/Query/SqlQuery.cpp \
    SQL/Base/Query/SqlQueryBind.cpp \
    SQL/Base/Query/SqlQueryData.cpp \
    SQL/DB/SQLite_DB.cpp

HEADERS += SQL_global.h \
    SQL/Base/DB/DB.h \
    SQL/Base/DB/DatabaseInfo.h \
    SQL/Base/DB/DatabaseUser.h \
    SQL/Base/Other/Connection.h \
    SQL/Base/Other/ConnectionFlag.h \
    SQL/Base/Other/UpdateInfo.h \
    SQL/Base/Query/SqlQuery.h \
    SQL/Base/Query/SqlQueryBind.h \
    SQL/Base/Query/SqlQueryData.h \
    SQL/DB/SQLite_DB.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
