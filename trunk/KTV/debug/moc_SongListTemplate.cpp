/****************************************************************************
** Meta object code from reading C++ file 'SongListTemplate.h'
**
** Created: Mon May 17 22:07:29 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/headers/SongListTemplate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SongListTemplate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SongListTemplate[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SongListTemplate[] = {
    "SongListTemplate\0\0ItemClick()\0"
};

const QMetaObject SongListTemplate::staticMetaObject = {
    { &Template::staticMetaObject, qt_meta_stringdata_SongListTemplate,
      qt_meta_data_SongListTemplate, 0 }
};

const QMetaObject *SongListTemplate::metaObject() const
{
    return &staticMetaObject;
}

void *SongListTemplate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SongListTemplate))
        return static_cast<void*>(const_cast< SongListTemplate*>(this));
    return Template::qt_metacast(_clname);
}

int SongListTemplate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Template::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ItemClick(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
