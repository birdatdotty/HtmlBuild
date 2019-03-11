HEADERS += \
    $$PWD/Item.h \
    $$PWD/BaseItem.h \
    $$PWD/PageItem.h \
    $$PWD/ModelList.h \
    $$PWD/HeaderItem.h

SOURCES += \
    $$PWD/Item.cc \
    $$PWD/BaseItem.cc \
    $$PWD/PageItem.cc \
    $$PWD/ModelList.cc \
    $$PWD/HeaderItem.cc


include($$PWD/Page/Page.pri)
