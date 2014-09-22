TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    listen.cpp \
    tcp.cpp \
    udp.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    listen.h \
    tcp.h \
    udp.h

