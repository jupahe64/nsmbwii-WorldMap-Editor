greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nsmbwiiWorldMapEditor
TEMPLATE = app

SOURCES += \
    FileFormats/csv.cpp \
    FileFormats/filehelper.cpp \
    glview.cpp \
    main.cpp \
    mainwindow.cpp \
    worldmap.cpp \
    shapeview.cpp

HEADERS += \
    FileFormats/csv.h \
    FileFormats/filehelper.h \
    glview.h \
    mainwindow.h \
    worldmap.h \
    shapeview.h

FORMS += \
    mainwindow.ui

SUBDIRS += \
    nsmbwiiWorldMapEditor.pro

DISTFILES += \
    images/icon.png \
    images/w2.png \
    images/w3.png \
    Shaders/default.fsh \
    Shaders/default.vsh

RESOURCES += \
    resources.qrc

QT           += core
                widgets
                gui
                opengl
