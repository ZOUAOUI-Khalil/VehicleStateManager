/****************************************************************************
** Meta object code from reading C++ file 'DialogT.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/DialogT.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogT.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogT_t {
    QByteArrayData data[7];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogT_t qt_meta_stringdata_DialogT = {
    {
QT_MOC_LITERAL(0, 0, 7), // "DialogT"
QT_MOC_LITERAL(1, 8, 19), // "onconnectBtnclicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "onGSMBtn2clicked"
QT_MOC_LITERAL(4, 46, 17), // "onWIFIBtn2clicked"
QT_MOC_LITERAL(5, 64, 33), // "on_comboBoxSEC_currentTextCha..."
QT_MOC_LITERAL(6, 98, 4) // "arg1"

    },
    "DialogT\0onconnectBtnclicked\0\0"
    "onGSMBtn2clicked\0onWIFIBtn2clicked\0"
    "on_comboBoxSEC_currentTextChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogT[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void DialogT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onconnectBtnclicked(); break;
        case 1: _t->onGSMBtn2clicked(); break;
        case 2: _t->onWIFIBtn2clicked(); break;
        case 3: _t->on_comboBoxSEC_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogT::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogT.data,
    qt_meta_data_DialogT,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogT::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogT.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
