/****************************************************************************
** Meta object code from reading C++ file 'KtvMainScreen.h'
**
** Created: Mon May 17 22:07:30 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/headers/KtvMainScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KtvMainScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KtvMainScreen[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      26,   14,   14,   14, 0x0a,
      41,   14,   14,   14, 0x0a,
      52,   14,   14,   14, 0x0a,
      59,   14,   14,   14, 0x0a,
      74,   14,   14,   14, 0x0a,
      82,   14,   14,   14, 0x0a,
      91,   14,   14,   14, 0x0a,
     107,   14,   14,   14, 0x0a,
     120,   14,   14,   14, 0x0a,
     129,   14,   14,   14, 0x0a,
     139,   14,   14,   14, 0x0a,
     150,   14,   14,   14, 0x0a,
     159,   14,   14,   14, 0x0a,
     170,   14,   14,   14, 0x0a,
     181,   14,   14,   14, 0x0a,
     194,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KtvMainScreen[] = {
    "KtvMainScreen\0\0NextPage()\0PreviousPage()\0"
    "HomePage()\0Back()\0PlayAndPouse()\0"
    "Magic()\0Silent()\0OriginalVoice()\0"
    "Atmosphere()\0Resing()\0Service()\0"
    "SingWith()\0Effect()\0NextSong()\0"
    "VolumeUp()\0VolumeDown()\0ViewSelected()\0"
};

const QMetaObject KtvMainScreen::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_KtvMainScreen,
      qt_meta_data_KtvMainScreen, 0 }
};

const QMetaObject *KtvMainScreen::metaObject() const
{
    return &staticMetaObject;
}

void *KtvMainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KtvMainScreen))
        return static_cast<void*>(const_cast< KtvMainScreen*>(this));
    if (!strcmp(_clname, "BaseTemplate"))
        return static_cast< BaseTemplate*>(const_cast< KtvMainScreen*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int KtvMainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: NextPage(); break;
        case 1: PreviousPage(); break;
        case 2: HomePage(); break;
        case 3: Back(); break;
        case 4: PlayAndPouse(); break;
        case 5: Magic(); break;
        case 6: Silent(); break;
        case 7: OriginalVoice(); break;
        case 8: Atmosphere(); break;
        case 9: Resing(); break;
        case 10: Service(); break;
        case 11: SingWith(); break;
        case 12: Effect(); break;
        case 13: NextSong(); break;
        case 14: VolumeUp(); break;
        case 15: VolumeDown(); break;
        case 16: ViewSelected(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
