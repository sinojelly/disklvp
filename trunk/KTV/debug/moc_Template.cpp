/****************************************************************************
** Meta object code from reading C++ file 'Template.h'
**
** Created: Mon May 17 22:07:24 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/headers/Template.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Template.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Template[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      23,    9,    9,    9, 0x0a,
      34,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Template[] = {
    "Template\0\0ActionToDo()\0NextPage()\0"
    "PreviousPage()\0"
};

const QMetaObject Template::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Template,
      qt_meta_data_Template, 0 }
};

const QMetaObject *Template::metaObject() const
{
    return &staticMetaObject;
}

void *Template::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Template))
        return static_cast<void*>(const_cast< Template*>(this));
    if (!strcmp(_clname, "BaseTemplate"))
        return static_cast< BaseTemplate*>(const_cast< Template*>(this));
    return QWidget::qt_metacast(_clname);
}

int Template::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ActionToDo(); break;
        case 1: NextPage(); break;
        case 2: PreviousPage(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
