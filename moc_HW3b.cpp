/****************************************************************************
** Meta object code from reading C++ file 'HW3b.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hw3/HW3b.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HW3b.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HW3b_t {
    QByteArrayData data[8];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HW3b_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HW3b_t qt_meta_stringdata_HW3b = {
    {
QT_MOC_LITERAL(0, 0, 4), // "HW3b"
QT_MOC_LITERAL(1, 5, 13), // "changeDisplay"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "changeGeom"
QT_MOC_LITERAL(4, 31, 10), // "changeSize"
QT_MOC_LITERAL(5, 42, 11), // "changeSpeed"
QT_MOC_LITERAL(6, 54, 18), // "playPauseAnimation"
QT_MOC_LITERAL(7, 73, 7) // "timeOut"

    },
    "HW3b\0changeDisplay\0\0changeGeom\0"
    "changeSize\0changeSpeed\0playPauseAnimation\0"
    "timeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HW3b[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       3,    1,   47,    2, 0x0a /* Public */,
       4,    1,   50,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       6,    0,   56,    2, 0x0a /* Public */,
       7,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HW3b::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HW3b *_t = static_cast<HW3b *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeDisplay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeGeom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->playPauseAnimation(); break;
        case 5: _t->timeOut(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HW3b::staticMetaObject = { {
    &HW::staticMetaObject,
    qt_meta_stringdata_HW3b.data,
    qt_meta_data_HW3b,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HW3b::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HW3b::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HW3b.stringdata0))
        return static_cast<void*>(this);
    return HW::qt_metacast(_clname);
}

int HW3b::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = HW::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
