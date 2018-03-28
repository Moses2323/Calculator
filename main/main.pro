include(../include/build.pri)

TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

# DEFINES += TESTING

LIBS += \
    -lcalculator
