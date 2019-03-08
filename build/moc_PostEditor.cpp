/****************************************************************************
** Meta object code from reading C++ file 'PostEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Posts/PostItem/PostEdit/PostEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PostEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PostEditor_t {
    QByteArrayData data[19];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PostEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PostEditor_t qt_meta_stringdata_PostEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PostEditor"
QT_MOC_LITERAL(1, 11, 12), // "updateSignal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "textBold"
QT_MOC_LITERAL(4, 34, 10), // "textItalic"
QT_MOC_LITERAL(5, 45, 28), // "mergeFormatOnWordOrSelection"
QT_MOC_LITERAL(6, 74, 15), // "QTextCharFormat"
QT_MOC_LITERAL(7, 90, 6), // "format"
QT_MOC_LITERAL(8, 97, 11), // "fontChanged"
QT_MOC_LITERAL(9, 109, 1), // "f"
QT_MOC_LITERAL(10, 111, 6), // "addImg"
QT_MOC_LITERAL(11, 118, 4), // "path"
QT_MOC_LITERAL(12, 123, 24), // "currentCharFormatChanged"
QT_MOC_LITERAL(13, 148, 9), // "textAlign"
QT_MOC_LITERAL(14, 158, 8), // "QAction*"
QT_MOC_LITERAL(15, 167, 1), // "a"
QT_MOC_LITERAL(16, 169, 21), // "cursorPositionChanged"
QT_MOC_LITERAL(17, 191, 16), // "alignmentChanged"
QT_MOC_LITERAL(18, 208, 13) // "Qt::Alignment"

    },
    "PostEditor\0updateSignal\0\0textBold\0"
    "textItalic\0mergeFormatOnWordOrSelection\0"
    "QTextCharFormat\0format\0fontChanged\0f\0"
    "addImg\0path\0currentCharFormatChanged\0"
    "textAlign\0QAction*\0a\0cursorPositionChanged\0"
    "alignmentChanged\0Qt::Alignment"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PostEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   67,    2, 0x0a /* Public */,
       4,    0,   68,    2, 0x0a /* Public */,
       5,    1,   69,    2, 0x0a /* Public */,
       8,    1,   72,    2, 0x0a /* Public */,
      10,    1,   75,    2, 0x0a /* Public */,
      12,    1,   78,    2, 0x08 /* Private */,
      13,    1,   81,    2, 0x08 /* Private */,
      16,    0,   84,    2, 0x08 /* Private */,
      17,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QFont,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   15,

       0        // eod
};

void PostEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PostEditor *_t = static_cast<PostEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->textBold(); break;
        case 2: _t->textItalic(); break;
        case 3: _t->mergeFormatOnWordOrSelection((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 4: _t->fontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 5: _t->addImg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->currentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 7: _t->textAlign((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 8: _t->cursorPositionChanged(); break;
        case 9: _t->alignmentChanged((*reinterpret_cast< Qt::Alignment(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PostEditor::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PostEditor::updateSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PostEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PostEditor.data,
      qt_meta_data_PostEditor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PostEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PostEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PostEditor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PostEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void PostEditor::updateSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
