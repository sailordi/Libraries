QT += core widgets gui

! include( ../Common.pri ) {
    error( "Couldn't find the Common.pri file!" )
}

DEFINES += MESSAGE_LIBRARY

CONFIG(release,debug|release) { TARGET = Message }
CONFIG(debug,debug|release) { TARGET = Message_D }

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
    Message/Notice/Notice.cpp

HEADERS += Message_global.h \
    Message/Notice/Notice.h \
    Message/Notice/NoticeFlag.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
