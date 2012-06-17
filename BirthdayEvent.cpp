/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   16 Jun 2012
**************************************************************************/

#include "BirthdayEvent.h"

BirthdayEvent::BirthdayEvent(const QDate &date, const QString &name):
    date(date), name(name) {

}

QList<BirthdayEvent> BirthdayEvent::getNextEvents(int count) const {
    QDate maxDate = QDate::currentDate().addYears(count);

    BirthdayEvent eventCopy(*this);
    QDate eventDate = getDate();

    QList<BirthdayEvent> nextEvents;
    while (eventDate < maxDate) {
        eventDate = eventDate.addYears(1);
        eventCopy.date = eventDate;
        nextEvents.append(eventCopy);
    }

    return nextEvents;
}

bool BirthdayEvent::operator ==(const BirthdayEvent &event) const {
    return name == event.name;
}

QDataStream& operator<<(QDataStream &stream, const BirthdayEvent &event) {
    return stream << event.date << event.name;
}

QDataStream& operator>>(QDataStream &stream, BirthdayEvent &event) {
    return stream >> event.date >> event.name;
}

