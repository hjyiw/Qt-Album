/****************************************************************************
** Meta object code from reading C++ file 'piclistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../piclistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'piclistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PicListWidget_t {
    QByteArrayData data[10];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PicListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PicListWidget_t qt_meta_stringdata_PicListWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PicListWidget"
QT_MOC_LITERAL(1, 14, 16), // "SigDoubleClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "path"
QT_MOC_LITERAL(4, 37, 10), // "SlotUpList"
QT_MOC_LITERAL(5, 48, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 65, 4), // "item"
QT_MOC_LITERAL(7, 70, 16), // "SlotSelectedItem"
QT_MOC_LITERAL(8, 87, 17), // "SlotDoubleClicked"
QT_MOC_LITERAL(9, 105, 16) // "QListWidgetItem*"

    },
    "PicListWidget\0SigDoubleClicked\0\0path\0"
    "SlotUpList\0QTreeWidgetItem*\0item\0"
    "SlotSelectedItem\0SlotDoubleClicked\0"
    "QListWidgetItem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PicListWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       7,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 9,    6,

       0        // eod
};

void PicListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PicListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->SigDoubleClicked((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SlotUpList((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->SlotSelectedItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->SlotDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (PicListWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PicListWidget::SigDoubleClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PicListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QListWidget::staticMetaObject>(),
    qt_meta_stringdata_PicListWidget.data,
    qt_meta_data_PicListWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PicListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PicListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PicListWidget.stringdata0))
        return static_cast<void*>(this);
    return QListWidget::qt_metacast(_clname);
}

int PicListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
int PicListWidget::SigDoubleClicked(QString _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
