/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AngelsVSDemons/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "on_Start_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "on_Birth_clicked"
QT_MOC_LITERAL(4, 46, 23), // "on_SinGenerator_clicked"
QT_MOC_LITERAL(5, 70, 22), // "on_GAGenerator_clicked"
QT_MOC_LITERAL(6, 93, 15), // "on_Maps_clicked"
QT_MOC_LITERAL(7, 109, 7), // "checked"
QT_MOC_LITERAL(8, 117, 18), // "on_SinMenu_clicked"
QT_MOC_LITERAL(9, 136, 17), // "on_GAMenu_clicked"
QT_MOC_LITERAL(10, 154, 14), // "on_ABB_clicked"
QT_MOC_LITERAL(11, 169, 16), // "on_Maps2_clicked"
QT_MOC_LITERAL(12, 186, 20), // "on_SetWInner_clicked"
QT_MOC_LITERAL(13, 207, 20), // "on_Damnation_clicked"
QT_MOC_LITERAL(14, 228, 20), // "on_Salvation_clicked"
QT_MOC_LITERAL(15, 249, 15), // "on_Hell_clicked"
QT_MOC_LITERAL(16, 265, 17) // "on_Heaven_clicked"

    },
    "MainWindow\0on_Start_clicked\0\0"
    "on_Birth_clicked\0on_SinGenerator_clicked\0"
    "on_GAGenerator_clicked\0on_Maps_clicked\0"
    "checked\0on_SinMenu_clicked\0on_GAMenu_clicked\0"
    "on_ABB_clicked\0on_Maps2_clicked\0"
    "on_SetWInner_clicked\0on_Damnation_clicked\0"
    "on_Salvation_clicked\0on_Hell_clicked\0"
    "on_Heaven_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    1,   93,    2, 0x08 /* Private */,
      11,    1,   96,    2, 0x08 /* Private */,
      12,    1,   99,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    1,  104,    2, 0x08 /* Private */,
      16,    1,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Start_clicked(); break;
        case 1: _t->on_Birth_clicked(); break;
        case 2: _t->on_SinGenerator_clicked(); break;
        case 3: _t->on_GAGenerator_clicked(); break;
        case 4: _t->on_Maps_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_SinMenu_clicked(); break;
        case 6: _t->on_GAMenu_clicked(); break;
        case 7: _t->on_ABB_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_Maps2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_SetWInner_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_Damnation_clicked(); break;
        case 11: _t->on_Salvation_clicked(); break;
        case 12: _t->on_Hell_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_Heaven_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
