QT       += core gui network

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
    counter.cpp \
    demon.cpp \
    demonicheap.cpp \
    dlinklist.cpp \
    email.cpp \
    emailaddress.cpp \
    family.cpp \
    filemanager.cpp \
    hash.cpp \
    heap.cpp \
    heaven.cpp \
    humans.cpp \
    launcher.cpp \
    main.cpp \
    mainwindow.cpp \
    mimeattachment.cpp \
    mimecontentformatter.cpp \
    mimefile.cpp \
    mimehtml.cpp \
    mimeinlinefile.cpp \
    mimemessage.cpp \
    mimemultipart.cpp \
    mimepart.cpp \
    mimetext.cpp \
    person.cpp \
    quotedprintable.cpp \
    smtpclient.cpp \
    soul.cpp \
    structcreator.cpp \
    triarbol.cpp \
    warzone.cpp \
    world.cpp

HEADERS += \
    SmtpMime \
    abb.h \
    angel.h \
    counter.h \
    demon.h \
    demonicheap.h \
    dlinklist.h \
    email.h \
    emailaddress.h \
    family.h \
    filemanager.h \
    hash.h \
    heap.h \
    heaven.h \
    humans.h \
    launcher.h \
    mainwindow.h \
    mimeattachment.h \
    mimecontentformatter.h \
    mimefile.h \
    mimehtml.h \
    mimeinlinefile.h \
    mimemessage.h \
    mimemultipart.h \
    mimepart.h \
    mimetext.h \
    person.h \
    quotedprintable.h \
    smtpclient.h \
    smtpexports.h \
    soul.h \
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
