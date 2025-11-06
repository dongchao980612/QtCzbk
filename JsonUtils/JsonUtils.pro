QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++17

SOURCES += \
        main.cpp

HEADERS += \
    jsonutils.h \
    model.h
