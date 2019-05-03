QT += core network
QT -= gui
QT       += sql

TARGET = EchoServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mytcpserver.cpp \
    ../lab3/untitled/db.cpp

HEADERS += \
    mytcpserver.h \
    ../lab3/untitled/db.h

