#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T19:14:14
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tmatm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    taskstable.cpp \
    tasks.cpp \
    tasksbuttonswidget.cpp \
    pushbutton.cpp \
    trayicon.cpp \
	timer.cpp \
    tmatmtimer.cpp

HEADERS  += mainwindow.h \
    staticVariables.h \
    taskstable.h \
    tasks.h \
    tasksbuttonswidget.h \
    pushbutton.h \
    trayicon.h \
	timer.h \
    tmatmtimer.h

FORMS += \
    taskstable.ui

RESOURCES += \
    myicons.qrc
