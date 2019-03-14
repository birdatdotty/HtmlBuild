QT       += widgets
TARGET = Site
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    $$PWD/Site.cc

HEADERS += \
    $$PWD/Site.h \
    $$PWD/../HtmlBuilder/config.h
    
## BaseItem
INCLUDEPATH += $$PWD/../BaseItem
DEPENDPATH += $$PWD/../BaseItem
## BaseItem - END

target.path = /usr/local/lib

header.files = Site.h
header.path = /usr/local/include


INSTALLS += target header

