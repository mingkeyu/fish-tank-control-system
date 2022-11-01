/****************************************************************************
** Meta object code from reading C++ file 'frmtcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../form/frmtcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmtcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmTcpClient_t {
    QByteArrayData data[17];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmTcpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmTcpClient_t qt_meta_stringdata_frmTcpClient = {
    {
QT_MOC_LITERAL(0, 0, 12), // "frmTcpClient"
QT_MOC_LITERAL(1, 13, 8), // "initForm"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "initConfig"
QT_MOC_LITERAL(4, 34, 10), // "saveConfig"
QT_MOC_LITERAL(5, 45, 6), // "append"
QT_MOC_LITERAL(6, 52, 4), // "type"
QT_MOC_LITERAL(7, 57, 4), // "data"
QT_MOC_LITERAL(8, 62, 5), // "clear"
QT_MOC_LITERAL(9, 68, 9), // "connected"
QT_MOC_LITERAL(10, 78, 12), // "disconnected"
QT_MOC_LITERAL(11, 91, 8), // "readData"
QT_MOC_LITERAL(12, 100, 8), // "sendData"
QT_MOC_LITERAL(13, 109, 21), // "on_btnConnect_clicked"
QT_MOC_LITERAL(14, 131, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(15, 150, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(16, 170, 18) // "on_btnSend_clicked"

    },
    "frmTcpClient\0initForm\0\0initConfig\0"
    "saveConfig\0append\0type\0data\0clear\0"
    "connected\0disconnected\0readData\0"
    "sendData\0on_btnConnect_clicked\0"
    "on_btnSave_clicked\0on_btnClear_clicked\0"
    "on_btnSend_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmTcpClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    3,   82,    2, 0x08 /* Private */,
       5,    2,   89,    2, 0x28 /* Private | MethodCloned */,
       9,    0,   94,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    1,   97,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmTcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmTcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initForm(); break;
        case 1: _t->initConfig(); break;
        case 2: _t->saveConfig(); break;
        case 3: _t->append((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->append((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->connected(); break;
        case 6: _t->disconnected(); break;
        case 7: _t->readData(); break;
        case 8: _t->sendData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_btnConnect_clicked(); break;
        case 10: _t->on_btnSave_clicked(); break;
        case 11: _t->on_btnClear_clicked(); break;
        case 12: _t->on_btnSend_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmTcpClient::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_frmTcpClient.data,
    qt_meta_data_frmTcpClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmTcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmTcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmTcpClient.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int frmTcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
