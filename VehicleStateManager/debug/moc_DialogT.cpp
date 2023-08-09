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
    QByteArrayData data[14];
    char stringdata0[163];
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
QT_MOC_LITERAL(3, 29, 13), // "saveinivalues"
QT_MOC_LITERAL(4, 43, 4), // "path"
QT_MOC_LITERAL(5, 48, 10), // "groupename"
QT_MOC_LITERAL(6, 59, 4), // "Name"
QT_MOC_LITERAL(7, 64, 5), // "Value"
QT_MOC_LITERAL(8, 70, 13), // "readinivalues"
QT_MOC_LITERAL(9, 84, 16), // "onGSMBtn2clicked"
QT_MOC_LITERAL(10, 101, 17), // "onWIFIBtn2clicked"
QT_MOC_LITERAL(11, 119, 31), // "onComboBoxSECCurrentTextChanged"
QT_MOC_LITERAL(12, 151, 4), // "arg1"
QT_MOC_LITERAL(13, 156, 6) // "reject"

    },
    "DialogT\0onconnectBtnclicked\0\0saveinivalues\0"
    "path\0groupename\0Name\0Value\0readinivalues\0"
    "onGSMBtn2clicked\0onWIFIBtn2clicked\0"
    "onComboBoxSECCurrentTextChanged\0arg1\0"
    "reject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogT[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    4,   50,    2, 0x0a /* Public */,
       8,    3,   59,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    1,   68,    2, 0x08 /* Private */,
      13,    0,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

void DialogT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onconnectBtnclicked(); break;
        case 1: _t->saveinivalues((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 2: { QString _r = _t->readinivalues((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->onGSMBtn2clicked(); break;
        case 4: _t->onWIFIBtn2clicked(); break;
        case 5: _t->onComboBoxSECCurrentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->reject(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
