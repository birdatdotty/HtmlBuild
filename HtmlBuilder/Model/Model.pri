HEADERS += \
    $$PWD/Item.h \
    $$PWD/PageItem.h \
    $$PWD/ModelList.h \
    $$PWD/HeaderItem.h

SOURCES += \
    $$PWD/Item.cc \
    $$PWD/PageItem.cc \
    $$PWD/ModelList.cc \
    $$PWD/HeaderItem.cc


include($$PWD/Page/Page.pri)
