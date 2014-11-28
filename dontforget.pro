#-------------------------------------------------
#
# Project created by QtCreator 2012-06-14T22:02:56
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = dontforget
TEMPLATE = app

CONFIG += debug

INSTALLS += target
target.path = ~/bin/

OBJECTS_DIR = .obj
MOC_DIR =.moc
UI_DIR = .ui
RCC_DIR = .rcc

HEADERS  += MainWindow.h

SOURCES += \
    main.cpp \
    MainWindow.cpp

include(model/model.pri)
include(calendar/calendar.pri)
include(find/find.pri)
include(storage/storage.pri)

TRANSLATIONS = i18n/dontforget_pl.ts \
               i18n/dontforget_en.ts

RESOURCES = dontforget.qrc
