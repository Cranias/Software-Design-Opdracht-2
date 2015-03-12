TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    auto.cpp \
    snelheid.cpp \
    digitalemeter.cpp \
    analogemeter.cpp \
    Observer.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    auto.h \
    snelheid.h \
    digitalemeter.h \
    analogemeter.h \
    Observer.h

