#-------------------------------------------------
#
# Project created by QtCreator 2012-06-14T22:02:56
#
#-------------------------------------------------

QT       += core gui

TARGET = birthday
TEMPLATE = app


SOURCES += main.cpp \
    CalendarWidget.cpp \
    MainWindow.cpp \
    CalendarEvent.cpp \
    EventStorage.cpp \
    EventListWidgetItem.cpp

HEADERS  += \
    CalendarWidget.h \
    MainWindow.h \
    CalendarEvent.h \
    EventStorage.h \
    EventListWidgetItem.h

FORMS    += \
    CalendarWidget.ui

TRANSLATIONS = birthday_pl.ts \
               birthday_en.ts

RESOURCES = birthday.qrc
