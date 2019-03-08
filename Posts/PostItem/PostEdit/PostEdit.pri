SOURCES += \
    $$PWD/WidgetImg.cc \
    $$PWD/Widget.cc \
    $$PWD/PostWindow.cc \
    $$PWD/PostEditor.cc

HEADERS += \
    $$PWD/WidgetImg.h \
    $$PWD/Widget.h \
    $$PWD/PostWindow.h \
    $$PWD/PostEditor.h

RESOURCES += \
    $$PWD/img.qrc

include ($$PWD/AddImg/AddImg.pri)
