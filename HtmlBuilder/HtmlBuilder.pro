#-------------------------------------------------
#
# Project created by QtCreator 2019-03-13T10:18:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HtmlBuilder
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cc \
        MainWindow.cc \
        HtmlBuild.cc

HEADERS += \
        MainWindow.h \
        HtmlBuild.h \
        config.h

include (InputPath/InputPath.pri)
include (Model/Model.pri)
include (Delegate/Delegate.pri)
include (PageEdit/PageEdit.pri)
include (Posts/Posts.pri)

# Site
unix:!macx: LIBS += -L../Site/ -lSite
win32:CONFIG(release, debug|release): LIBS += -L../Site/release/ -lSite
else:win32:CONFIG(debug, debug|release): LIBS += -L../Site/debug/ -lSite


INCLUDEPATH += ../Site
DEPENDPATH += ../Site

unix:!macx: PRE_TARGETDEPS += ../Site/libSite.a
# Site - END


## BaseItem
unix:!macx: LIBS += -L../BaseItem/ -lBaseItem
win32:CONFIG(release, debug|release): LIBS += -L../BaseItem/release/ -lBaseItem
else:win32:CONFIG(debug, debug|release): LIBS += -L../BaseItem/debug/ -lBaseItem


INCLUDEPATH += ../BaseItem
DEPENDPATH += ../BaseItem
## BaseItem - END


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /usr/local/bin
!isEmpty(target.path): INSTALLS += target

