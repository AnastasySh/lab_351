QT += core network
QT -= gui
QT       += sql

TARGET = EchoServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mytcpserver.cpp \
    db.cpp

HEADERS += \
    mytcpserver.h \
    db.h

