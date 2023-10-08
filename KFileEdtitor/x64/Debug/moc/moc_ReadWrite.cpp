/****************************************************************************
** Meta object code from reading C++ file 'ReadWrite.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ReadWrite.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReadWrite.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReadWrite_t {
    QByteArrayData data[13];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReadWrite_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReadWrite_t qt_meta_stringdata_ReadWrite = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ReadWrite"
QT_MOC_LITERAL(1, 10, 15), // "readFinishedSig"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "Data*"
QT_MOC_LITERAL(4, 33, 2), // "re"
QT_MOC_LITERAL(5, 36, 8), // "readData"
QT_MOC_LITERAL(6, 45, 8), // "filepath"
QT_MOC_LITERAL(7, 54, 13), // "QTextBrowser*"
QT_MOC_LITERAL(8, 68, 7), // "display"
QT_MOC_LITERAL(9, 76, 13), // "writeDataRoot"
QT_MOC_LITERAL(10, 90, 4), // "data"
QT_MOC_LITERAL(11, 95, 9), // "writeData"
QT_MOC_LITERAL(12, 105, 9) // "testSlots"

    },
    "ReadWrite\0readFinishedSig\0\0Data*\0re\0"
    "readData\0filepath\0QTextBrowser*\0display\0"
    "writeDataRoot\0data\0writeData\0testSlots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReadWrite[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   42,    2, 0x0a /* Public */,
       9,    2,   47,    2, 0x0a /* Public */,
      11,    2,   52,    2, 0x0a /* Public */,
      12,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    6,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    6,   10,
    QMetaType::Void,

       0        // eod
};

void ReadWrite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ReadWrite *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readFinishedSig((*reinterpret_cast< Data*(*)>(_a[1]))); break;
        case 1: _t->readData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTextBrowser*(*)>(_a[2]))); break;
        case 2: _t->writeDataRoot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Data*(*)>(_a[2]))); break;
        case 3: _t->writeData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Data*(*)>(_a[2]))); break;
        case 4: _t->testSlots(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTextBrowser* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ReadWrite::*)(Data * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadWrite::readFinishedSig)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ReadWrite::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ReadWrite.data,
    qt_meta_data_ReadWrite,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ReadWrite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReadWrite::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReadWrite.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ReadWrite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ReadWrite::readFinishedSig(Data * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
