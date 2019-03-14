QT       += widgets
TARGET = BaseItem
TEMPLATE = lib
#CONFIG += staticlib

SOURCES += \
    $$PWD/BaseItem.cc

HEADERS += \
    $$PWD/BaseItem.h \
    $$PWD/../HtmlBuilder/config.h

# Site
unix:!macx: LIBS += -L../Site/ -lSite

INCLUDEPATH += ../Site
DEPENDPATH += ../Site

unix:!macx: PRE_TARGETDEPS += ../Site/libSite.a
# Site - END

header.files = BaseItem.h
header.path = /usr/local/include

target.path = /usr/local/lib
INSTALLS += target header

