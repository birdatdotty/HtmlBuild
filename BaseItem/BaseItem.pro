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
win32:CONFIG(release, debug|release): LIBS += -L../Site/release/ -lSite
else:win32:CONFIG(debug, debug|release): LIBS += -L../Site/debug/ -lSite


INCLUDEPATH += ../Site
DEPENDPATH += ../Site

unix:!macx: PRE_TARGETDEPS += ../Site/libSite.a
# Site - END

header.files = BaseItem.h
header.path = /usr/local/include

target.path = /usr/local/lib
INSTALLS += target header

