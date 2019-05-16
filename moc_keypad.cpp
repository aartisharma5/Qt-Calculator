/****************************************************************************
** Meta object code from reading C++ file 'keypad.h'
**
** Created: Mon Jan 7 11:21:04 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "keypad.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keypad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Keypad[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,    8,    7,    7, 0x0a,
      51,    8,    7,    7, 0x08,
      74,    7,    7,    7, 0x08,
      80,    7,    7,    7, 0x08,
      86,    7,    7,    7, 0x08,
      92,    7,    7,    7, 0x08,
      98,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Keypad[] = {
    "Keypad\0\0text\0textChanged(QString)\0"
    "setText(QString)\0buttonClicked(QString)\0"
    "pls()\0min()\0mul()\0div()\0operate()\0"
};

const QMetaObject Keypad::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Keypad,
      qt_meta_data_Keypad, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Keypad::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Keypad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Keypad::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Keypad))
        return static_cast<void*>(const_cast< Keypad*>(this));
    return QWidget::qt_metacast(_clname);
}

int Keypad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: buttonClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: pls(); break;
        case 4: min(); break;
        case 5: mul(); break;
        case 6: div(); break;
        case 7: operate(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Keypad::textChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
