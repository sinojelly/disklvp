/****************************************************************************
** Meta object code from reading C++ file 'HomeWidget.h'
**
** Created: Mon May 17 22:07:22 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/headers/HomeWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HomeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HomeWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      27,   11,   11,   11, 0x0a,
      45,   11,   11,   11, 0x0a,
      61,   11,   11,   11, 0x0a,
      80,   11,   11,   11, 0x0a,
     100,   11,   11,   11, 0x0a,
     130,   11,   11,   11, 0x0a,
     151,   11,   11,   11, 0x0a,
     169,   11,   11,   11, 0x0a,
     188,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HomeWidget[] = {
    "HomeWidget\0\0AllSongClick()\0NewestSongClick()\0"
    "HotOrderClick()\0PrivateSongClick()\0"
    "PinyinFilterClick()\0LanguageCategoryFilterClick()\0"
    "DigitalFilterClick()\0StarFilterClick()\0"
    "BihuaFilterClick()\0CategoryFilterClick()\0"
};

const QMetaObject HomeWidget::staticMetaObject = {
    { &Template::staticMetaObject, qt_meta_stringdata_HomeWidget,
      qt_meta_data_HomeWidget, 0 }
};

const QMetaObject *HomeWidget::metaObject() const
{
    return &staticMetaObject;
}

void *HomeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HomeWidget))
        return static_cast<void*>(const_cast< HomeWidget*>(this));
    return Template::qt_metacast(_clname);
}

int HomeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Template::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: AllSongClick(); break;
        case 1: NewestSongClick(); break;
        case 2: HotOrderClick(); break;
        case 3: PrivateSongClick(); break;
        case 4: PinyinFilterClick(); break;
        case 5: LanguageCategoryFilterClick(); break;
        case 6: DigitalFilterClick(); break;
        case 7: StarFilterClick(); break;
        case 8: BihuaFilterClick(); break;
        case 9: CategoryFilterClick(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
