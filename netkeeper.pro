#-------------------------------------------------
#
# Project created by QtCreator 2012-11-26T22:27:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = netkeeper
TEMPLATE = app


SOURCES += main.cpp\
        rasdial.cpp \
    source/MD5.cpp \
    source/CXKUsername.cpp \
    source/CString.cpp

HEADERS  += rasdial.h \
    source/MD5.h \
    source/dail.h \
    source/CXKUsername.h \
    source/CString.h

FORMS    += rasdial.ui

LIBS     += -lws2_32 -lrasapi32 -lWininet

DEFINES  -= -DUNICODE

CONFIG   += -static
