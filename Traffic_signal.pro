#-------------------------------------------------
#
# Project created by QtCreator 2016-07-13T09:59:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Traffic_signal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    type_config.cpp \
    Shape_configuration.cpp \
    Object_management.cpp \
    path_configuration.cpp \
    picture_frame.cpp

HEADERS  += \
    type_config.h \
    Shape_configuration.h \
    Object_management.h \
    path_configuration.h \
    picture_frame.h \
    mainwindow.h

FORMS    += mainwindow.ui \
    type_config.ui
