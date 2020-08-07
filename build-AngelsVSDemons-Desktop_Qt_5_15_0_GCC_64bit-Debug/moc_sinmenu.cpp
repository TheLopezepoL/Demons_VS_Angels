/****************************************************************************
** Meta object code from reading C++ file 'sinmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AngelsVSDemons/sinmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sinmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SinMenu_t {
    QByteArrayData data[9];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SinMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SinMenu_t qt_meta_stringdata_SinMenu = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SinMenu"
QT_MOC_LITERAL(1, 8, 16), // "on_TOP10_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "checked"
QT_MOC_LITERAL(4, 34, 15), // "on_TOP5_clicked"
QT_MOC_LITERAL(5, 50, 22), // "on_familyState_clicked"
QT_MOC_LITERAL(6, 73, 14), // "on_hLS_clicked"
QT_MOC_LITERAL(7, 88, 14), // "on_CFS_clicked"
QT_MOC_LITERAL(8, 103, 22) // "on_familyStats_clicked"

    },
    "SinMenu\0on_TOP10_clicked\0\0checked\0"
    "on_TOP5_clicked\0on_familyState_clicked\0"
    "on_hLS_clicked\0on_CFS_clicked\0"
    "on_familyStats_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SinMenu[] = {

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
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    1,   50,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void SinMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SinMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_TOP10_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_TOP5_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_familyState_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_hLS_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_CFS_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SinMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SinMenu.data,
    qt_meta_data_SinMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SinMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SinMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SinMenu.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SinMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
