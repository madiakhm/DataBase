TEMPLATE=app
TARGET=main

QT = core gui
QT += sql

CONFIG += c++17 cmdline
greaterThan(QT_MAJOR_VERSION,4):
QT +=widgets

SOURCES += \
        dbmanager.cpp \
        main.cpp \
        visual.cpp


HEADERS += \
    dbmanager.h \
    visual.h
