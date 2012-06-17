/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   16 Jun 2012
**************************************************************************/

#include "BirthdayEvent.h"

BirthdayEvent::BirthdayEvent(const QDate &date, const QString &name):
    date(date), name(name) {

}

bool BirthdayEvent::operator ==(const BirthdayEvent &event) {
    return name == event.name && date == event.date;
}

QDataStream& operator<<(QDataStream &stream, const BirthdayEvent &event) {
    return stream << event.date << event.name;
}

QDataStream& operator>>(QDataStream &stream, BirthdayEvent &event) {
    return stream >> event.date >> event.name;
}

