#-------------------------------------------------
#
# Project created by QtCreator 2012-06-14T22:02:56
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = birthday
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

TRANSLATIONS = i18n/birthday_pl.ts \
               i18n/birthday_en.ts

RESOURCES = birthday.qrc
