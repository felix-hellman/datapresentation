#-------------------------------------------------
#
# Project created by QtCreator 2016-02-10T18:09:56
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += printsupport
CONFIG   += C++14
LIBS     += -lcurl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataPresentation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    linegraphdata.cpp \
    bargraphdata.cpp \
    graphdatahandler.cpp \
    googleparser.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    linegraphdata.h \
    bargraphdata.h \
    graphdata.h \
    graphdatahandler.h \
    googleparser.h

FORMS    += mainwindow.ui

DISTFILES += \
    qmlfile.qml
