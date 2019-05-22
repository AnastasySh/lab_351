/****************************************************************************
** Meta object code from reading C++ file 'moder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../1lab/moder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_moder_t {
    QByteArrayData data[12];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_moder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_moder_t qt_meta_stringdata_moder = {
    {
QT_MOC_LITERAL(0, 0, 5), // "moder"
QT_MOC_LITERAL(1, 6, 21), // "on_new_button_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 22), // "on_edit_button_clicked"
QT_MOC_LITERAL(4, 52, 24), // "on_delete_button_clicked"
QT_MOC_LITERAL(5, 77, 10), // "slot_read1"
QT_MOC_LITERAL(6, 88, 3), // "arr"
QT_MOC_LITERAL(7, 92, 18), // "on_ok_edit_clicked"
QT_MOC_LITERAL(8, 111, 17), // "on_del_ok_clicked"
QT_MOC_LITERAL(9, 129, 17), // "on_del_no_clicked"
QT_MOC_LITERAL(10, 147, 30), // "on_edit_search_editingFinished"
QT_MOC_LITERAL(11, 178, 18) // "on_refrash_clicked"

    },
    "moder\0on_new_button_clicked\0\0"
    "on_edit_button_clicked\0on_delete_button_clicked\0"
    "slot_read1\0arr\0on_ok_edit_clicked\0"
    "on_del_ok_clicked\0on_del_no_clicked\0"
    "on_edit_search_editingFinished\0"
    "on_refrash_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_moder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void moder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        moder *_t = static_cast<moder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_new_button_clicked(); break;
        case 1: _t->on_edit_button_clicked(); break;
        case 2: _t->on_delete_button_clicked(); break;
        case 3: _t->slot_read1((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->on_ok_edit_clicked(); break;
        case 5: _t->on_del_ok_clicked(); break;
        case 6: _t->on_del_no_clicked(); break;
        case 7: _t->on_edit_search_editingFinished(); break;
        case 8: _t->on_refrash_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject moder::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_moder.data,
    qt_meta_data_moder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *moder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *moder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_moder.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int moder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
