#-------------------------------------------------
#
# Project created by QtCreator 2015-12-25T16:00:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tic-tac-toe
TEMPLATE = app
CONFIG += windows

SOURCES += main.cpp\
        mainwindow.cpp \
    tic-tac-toe.cpp

HEADERS  += mainwindow.h \
    tic.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
