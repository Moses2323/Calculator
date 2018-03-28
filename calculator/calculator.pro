include(../include/build.pri)

TEMPLATE = lib
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += CALCULATOR_LIBRARY

SOURCES += \
	src/Calculator.cpp \
	src/DefaultCalculator.cpp \
	src/defcalcoperations.cpp

HEADERS += \
	../include/abstroperations.h \
	../include/Calculator.h \
	../include/DefaultCalculator.h \
	../include/defcalcoperations.h \
	../include/ForMistakes.h
