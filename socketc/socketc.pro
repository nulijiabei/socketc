TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    listen.cpp \
    tcp.cpp \
    udp.cpp

HEADERS += \
    listen.h \
    tcp.h \
    udp.h


LIBS += -lev
