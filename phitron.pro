#-------------------------------------------------
#
# Project created by QtCreator 2015-07-13T23:22:03
#
#-------------------------------------------------

QT       -= core gui

TARGET = phitron
TEMPLATE = lib

DEFINES += PHITRON_LIBRARY

SOURCES += \
    p2.cpp \
    p3.cpp

HEADERS += phitron.h \
    p2.h \
    v2.h \
    v3.h \
    p3.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
