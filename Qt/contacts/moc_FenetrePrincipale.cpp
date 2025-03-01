/****************************************************************************
** Meta object code from reading C++ file 'FenetrePrincipale.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "FenetrePrincipale.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenetrePrincipale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FenetrePrincipale_t {
    const uint offsetsAndSize[22];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FenetrePrincipale_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FenetrePrincipale_t qt_meta_stringdata_FenetrePrincipale = {
    {
QT_MOC_LITERAL(0, 17), // "FenetrePrincipale"
QT_MOC_LITERAL(18, 14), // "slot_buttonAdd"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 17), // "slot_buttonSearch"
QT_MOC_LITERAL(52, 15), // "slotEnregistrer"
QT_MOC_LITERAL(68, 10), // "slotOuvrir"
QT_MOC_LITERAL(79, 23), // "slotCustomMenuRequested"
QT_MOC_LITERAL(103, 3), // "pos"
QT_MOC_LITERAL(107, 13), // "slot_afficher"
QT_MOC_LITERAL(121, 11), // "slot_editer"
QT_MOC_LITERAL(133, 14) // "slot_supprimer"

    },
    "FenetrePrincipale\0slot_buttonAdd\0\0"
    "slot_buttonSearch\0slotEnregistrer\0"
    "slotOuvrir\0slotCustomMenuRequested\0"
    "pos\0slot_afficher\0slot_editer\0"
    "slot_supprimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenetrePrincipale[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    0,   63,    2, 0x0a,    2 /* Public */,
       4,    0,   64,    2, 0x0a,    3 /* Public */,
       5,    0,   65,    2, 0x0a,    4 /* Public */,
       6,    1,   66,    2, 0x0a,    5 /* Public */,
       8,    0,   69,    2, 0x0a,    7 /* Public */,
       9,    0,   70,    2, 0x0a,    8 /* Public */,
      10,    0,   71,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FenetrePrincipale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenetrePrincipale *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slot_buttonAdd(); break;
        case 1: _t->slot_buttonSearch(); break;
        case 2: _t->slotEnregistrer(); break;
        case 3: _t->slotOuvrir(); break;
        case 4: _t->slotCustomMenuRequested((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 5: _t->slot_afficher(); break;
        case 6: _t->slot_editer(); break;
        case 7: _t->slot_supprimer(); break;
        default: ;
        }
    }
}

const QMetaObject FenetrePrincipale::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FenetrePrincipale.offsetsAndSize,
    qt_meta_data_FenetrePrincipale,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FenetrePrincipale_t
, QtPrivate::TypeAndForceComplete<FenetrePrincipale, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FenetrePrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenetrePrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenetrePrincipale.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FenetrePrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
