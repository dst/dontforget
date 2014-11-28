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
    calendar/CalendarWidget.cpp \
    calendar/EventListWidgetItem.cpp \
    find/FindEventDialog.cpp \
    model/CalendarEvent.cpp \
    storage/EventStorage.cpp \
    MainWindow.cpp

HEADERS  += \
    calendar/CalendarWidget.h \
    calendar/EventListWidgetItem.h \
    find/FindEventDialog.h \
    model/CalendarEvent.h \
    storage/EventStorage.h \
    MainWindow.h

FORMS    += \
    calendar/CalendarWidget.ui \
    find/FindEventDialog.ui

TRANSLATIONS = i18n/birthday_pl.ts \
               i18n/birthday_en.ts

RESOURCES = birthday.qrc
