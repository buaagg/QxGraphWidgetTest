#-------------------------------------------------
#
# Project created by QtCreator 2013-10-25T18:00:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QxGraphWidgetTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:INCLUDEPATH = C:/boost/boost_1_54_0

msvc:QMAKE_CXXFLAGS+= -openmp
msvc:QMAKE_LFLAGS +=  -openmp
