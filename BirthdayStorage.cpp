/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   17 Jun 2012
**************************************************************************/

#include "BirthdayStorage.h"

#include <QDataStream>
#include <QFile>

static QString STORAGE_FILE = "birthdayStorage";

BirthdayStorage::BirthdayStorage(QObject *parent) :
    QObject(parent) {
}

void BirthdayStorage::save() {
    QFile file(STORAGE_FILE);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_8);
        out << events;
    }
}

void BirthdayStorage::load() {
    QFile file(STORAGE_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_8);
        in >> events;
    }

    foreach(const BirthdayEvent& event, events) {
        emit eventAdded(event);
    }
}

void BirthdayStorage::addEvent(const BirthdayEvent &event) {
    events.append(event);
    emit eventAdded(event);
}

void BirthdayStorage::removeEvent(const BirthdayEvent &event) {
    int count = events.removeAll(event);
    Q_ASSERT(count == 1);
    emit eventRemoved(event);
}
