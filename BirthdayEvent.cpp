/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   16 Jun 2012
**************************************************************************/

#include "BirthdayEvent.h"

BirthdayEvent::BirthdayEvent(const QDate& date, const QString& name):
    month(date.month()), day(date.day()), name(name) {

}

QList<QDate> BirthdayEvent::getDatesWithin(int yearsPast, int yearsFuture) const {
    int currentYear = QDate::currentDate().year();
    QDate date(currentYear - yearsPast, month, day);
    QDate maxDate = date.addYears(yearsFuture + yearsPast);

    QList<QDate> dates;
    while (date < maxDate) {
        dates.append(date);
        date = date.addYears(1);
    }

    return dates;
}

bool BirthdayEvent::operator ==(const BirthdayEvent &event) const {
    return day == event.day && month == event.month && name == event.name;
}

QDataStream& operator<<(QDataStream &stream, const BirthdayEvent &event) {
    return stream << event.day << event.month << event.name;
}

QDataStream& operator>>(QDataStream &stream, BirthdayEvent &event) {
    return stream >> event.day >> event.month >> event.name;
}

