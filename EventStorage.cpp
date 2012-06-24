/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   17 Jun 2012
**************************************************************************/

#include "EventStorage.h"

#include <QDataStream>
#include <QFile>

static QString STORAGE_FILE = "/home/bulls/mygitrepo/apps/birthday/birthdayStorage";

EventStorage::EventStorage(QObject *parent) :
    QObject(parent) {
}

void EventStorage::save() {
    QFile file(STORAGE_FILE);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_8);
        out << events;
    }
}

void EventStorage::load() {
    QFile file(STORAGE_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_8);
        in >> events;
    }

    foreach(const CalendarEvent& event, events) {
        emit eventAdded(event);
    }
}

const QList<CalendarEvent> &EventStorage::getEvents() const {
    return events;
}

void EventStorage::addEvent(const CalendarEvent &event) {
    events.append(event);
    save();

    emit eventAdded(event);
}

QList<CalendarEvent> EventStorage::findCommingEvents(int days) {
    QDate now = QDate::currentDate();

    QList<CalendarEvent> closeEvents;
    foreach(const CalendarEvent& event, events) {
        if (now.daysTo(event.getClosestDate()) <= days) {
            closeEvents.append(event);
        }
    }
    return closeEvents;
}

void EventStorage::removeEvent(const CalendarEvent &event) {
    int count = events.removeAll(event);
    Q_ASSERT(count == 1);
    save();

    emit eventRemoved(event);
}

void EventStorage::updateEvent(const CalendarEvent &oldEvent, const CalendarEvent &newEvent) {
    removeEvent(oldEvent);
    addEvent(newEvent);
}
