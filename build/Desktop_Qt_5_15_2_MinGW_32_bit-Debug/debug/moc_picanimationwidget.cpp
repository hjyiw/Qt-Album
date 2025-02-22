/****************************************************************************
** Meta object code from reading C++ file 'picanimationwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../picanimationwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'picanimationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PicAnimationWidget_t {
    QByteArrayData data[13];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PicAnimationWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PicAnimationWidget_t qt_meta_stringdata_PicAnimationWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "PicAnimationWidget"
QT_MOC_LITERAL(1, 19, 9), // "SigUpList"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 47, 15), // "SigSelectedItem"
QT_MOC_LITERAL(5, 63, 14), // "SigPalyChanged"
QT_MOC_LITERAL(6, 78, 19), // "SigMusicStartOrStop"
QT_MOC_LITERAL(7, 98, 12), // "SlotTimerOut"
QT_MOC_LITERAL(8, 111, 11), // "SlotNextPic"
QT_MOC_LITERAL(9, 123, 10), // "SlotPrePic"
QT_MOC_LITERAL(10, 134, 13), // "SlotUpdatePic"
QT_MOC_LITERAL(11, 148, 4), // "path"
QT_MOC_LITERAL(12, 153, 15) // "SlotPlayOrPause"

    },
    "PicAnimationWidget\0SigUpList\0\0"
    "QTreeWidgetItem*\0SigSelectedItem\0"
    "SigPalyChanged\0SigMusicStartOrStop\0"
    "SlotTimerOut\0SlotNextPic\0SlotPrePic\0"
    "SlotUpdatePic\0path\0SlotPlayOrPause"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PicAnimationWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       5,    1,   65,    2, 0x06 /* Public */,
       6,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   71,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,
      10,    1,   74,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void PicAnimationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PicAnimationWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SigUpList((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->SigSelectedItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->SigPalyChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->SigMusicStartOrStop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->SlotTimerOut(); break;
        case 5: _t->SlotNextPic(); break;
        case 6: _t->SlotPrePic(); break;
        case 7: _t->SlotUpdatePic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->SlotPlayOrPause(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PicAnimationWidget::*)(QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PicAnimationWidget::SigUpList)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PicAnimationWidget::*)(QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PicAnimationWidget::SigSelectedItem)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PicAnimationWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PicAnimationWidget::SigPalyChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PicAnimationWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PicAnimationWidget::SigMusicStartOrStop)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PicAnimationWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PicAnimationWidget.data,
    qt_meta_data_PicAnimationWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PicAnimationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PicAnimationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PicAnimationWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PicAnimationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void PicAnimationWidget::SigUpList(QTreeWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PicAnimationWidget::SigSelectedItem(QTreeWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PicAnimationWidget::SigPalyChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PicAnimationWidget::SigMusicStartOrStop(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
