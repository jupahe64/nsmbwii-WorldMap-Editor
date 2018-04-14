/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qt5 source/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "actionOpen"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "actionSave"
QT_MOC_LITERAL(4, 34, 12), // "actionWorld1"
QT_MOC_LITERAL(5, 47, 12), // "actionWorld2"
QT_MOC_LITERAL(6, 60, 13), // "actionWorld3a"
QT_MOC_LITERAL(7, 74, 13), // "actionWorld3b"
QT_MOC_LITERAL(8, 88, 12), // "actionWorld4"
QT_MOC_LITERAL(9, 101, 12), // "actionWorld5"
QT_MOC_LITERAL(10, 114, 12), // "actionWorld6"
QT_MOC_LITERAL(11, 127, 12), // "actionWorld7"
QT_MOC_LITERAL(12, 140, 12), // "actionWorld8"
QT_MOC_LITERAL(13, 153, 12), // "actionWorld9"
QT_MOC_LITERAL(14, 166, 32), // "on_listPoints_currentTextChanged"
QT_MOC_LITERAL(15, 199, 11), // "currentText"
QT_MOC_LITERAL(16, 211, 31), // "on_listPoints_itemDoubleClicked"
QT_MOC_LITERAL(17, 243, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(18, 260, 4), // "item"
QT_MOC_LITERAL(19, 265, 31), // "on_listPaths_currentTextChanged"
QT_MOC_LITERAL(20, 297, 34), // "on_listExitAnims_itemDoubleCl..."
QT_MOC_LITERAL(21, 332, 40) // "on_listSecretExitAnims_itemDo..."

    },
    "MainWindow\0actionOpen\0\0actionSave\0"
    "actionWorld1\0actionWorld2\0actionWorld3a\0"
    "actionWorld3b\0actionWorld4\0actionWorld5\0"
    "actionWorld6\0actionWorld7\0actionWorld8\0"
    "actionWorld9\0on_listPoints_currentTextChanged\0"
    "currentText\0on_listPoints_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0"
    "on_listPaths_currentTextChanged\0"
    "on_listExitAnims_itemDoubleClicked\0"
    "on_listSecretExitAnims_itemDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    1,  111,    2, 0x08 /* Private */,
      16,    1,  114,    2, 0x08 /* Private */,
      19,    1,  117,    2, 0x08 /* Private */,
      20,    1,  120,    2, 0x08 /* Private */,
      21,    1,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actionOpen(); break;
        case 1: _t->actionSave(); break;
        case 2: _t->actionWorld1(); break;
        case 3: _t->actionWorld2(); break;
        case 4: _t->actionWorld3a(); break;
        case 5: _t->actionWorld3b(); break;
        case 6: _t->actionWorld4(); break;
        case 7: _t->actionWorld5(); break;
        case 8: _t->actionWorld6(); break;
        case 9: _t->actionWorld7(); break;
        case 10: _t->actionWorld8(); break;
        case 11: _t->actionWorld9(); break;
        case 12: _t->on_listPoints_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_listPoints_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->on_listPaths_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_listExitAnims_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 16: _t->on_listSecretExitAnims_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
