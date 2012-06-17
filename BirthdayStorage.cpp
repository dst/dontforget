/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   17 Jun 2012
**************************************************************************/

#include "BirthdayStorage.h"

#include <QDataStream>
#include <QFile>

static QString STORAGE_FILE = "birtdayStorage";

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
        emit birthdayAdded(event);
    }
}

void BirthdayStorage::addBirthday(const BirthdayEvent &event) {
    events.append(event);
    emit birthdayAdded(event);
}
