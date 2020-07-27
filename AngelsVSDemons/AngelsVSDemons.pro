QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abb.cpp \
    angel.cpp \
    continent.cpp \
    demon.cpp \
    demonicheap.cpp \
    dlinklist.cpp \
    family.cpp \
    filemanager.cpp \
    heap.cpp \
    heaven.cpp \
    hell.cpp \
    humans.cpp \
    launcher.cpp \
    main.cpp \
    mainwindow.cpp \
    person.cpp \
    structcreator.cpp \
    triarbol.cpp \
    warzone.cpp \
    world.cpp

HEADERS += \
    abb.h \
    angel.h \
    continent.h \
    demon.h \
    demonicheap.h \
    dlinklist.h \
    family.h \
    filemanager.h \
    heap.h \
    heaven.h \
    hell.h \
    humans.h \
    launcher.h \
    mainwindow.h \
    person.h \
    structcreator.h \
    triarbol.h \
    warzone.h \
    world.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
