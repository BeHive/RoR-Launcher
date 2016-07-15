#-------------------------------------------------
#
# Project created by QtCreator 2016-07-05T12:59:35
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RoR-Launcher
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    httpconnect.cpp

HEADERS  += mainwindow.h \
    httpconnect.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
