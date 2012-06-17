/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   17 Jun 2012
**************************************************************************/

#include "BirthdayStorage.h"

BirthdayStorage::BirthdayStorage(QObject *parent) :
    QObject(parent) {
}

void BirthdayStorage::addBirthday(const BirthdayEvent &event) {
    events.append(event);
    emit birthdayAdded(event);
}
