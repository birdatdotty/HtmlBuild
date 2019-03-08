HEADERS += \
    $$PWD/Item.h \
    $$PWD/Model.h \
    $$PWD/BaseItem.h \
    $$PWD/PageItem.h \
    $$PWD/ModelList.h \
    $$PWD/HeaderItem.h \
    $$PWD/AbstractPostItem.h

SOURCES += \
    $$PWD/Item.cc \
    $$PWD/Model.cc \
    $$PWD/BaseItem.cc \
    $$PWD/PageItem.cc \
    $$PWD/ModelList.cc \
    $$PWD/HeaderItem.cc \
    $$PWD/AbstractPostItem.cc


include($$PWD/Page/Page.pri)
