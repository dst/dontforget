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

SOURCES += main.cpp \
    CalendarWidget.cpp \
    MainWindow.cpp \
    CalendarEvent.cpp \
    EventStorage.cpp \
    EventListWidgetItem.cpp \
    FindEventDialog.cpp

HEADERS  += \
    CalendarWidget.h \
    MainWindow.h \
    CalendarEvent.h \
    EventStorage.h \
    EventListWidgetItem.h \
    FindEventDialog.h

FORMS    += \
    CalendarWidget.ui \
    FindEventDialog.ui

TRANSLATIONS = birthday_pl.ts \
               birthday_en.ts

RESOURCES = birthday.qrc
