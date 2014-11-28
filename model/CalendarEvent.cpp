/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   16 Jun 2012
**************************************************************************/

#include "CalendarEvent.h"

CalendarEvent::CalendarEvent(const QDate& date, const QString& name):
    month(date.month()), day(date.day()), name(name) {
}

QString CalendarEvent::toString() const {
    return getName() + " : " + getClosestDate().toString();
}

QDate CalendarEvent::getClosestDate() const {
    int currentYear = QDate::currentDate().year();
    QDate date(currentYear, month, day);
    if (date < QDate::currentDate()) {
        date = date.addYears(1);
    }
    return date;
}

QList<QDate> CalendarEvent::getDatesWithin(int yearsPast, int yearsFuture) const {
    QDate date = getClosestDate().addYears(-yearsPast);
    QDate maxDate = date.addYears(yearsFuture + yearsPast);

    QList<QDate> dates;
    while (date < maxDate) {
        dates.append(date);
        date = date.addYears(1);
    }

    return dates;
}

bool CalendarEvent::operator <(const CalendarEvent &event) const {
    // watch out: no year 0
    return QDate(1, month, day) < QDate(1, event.month, event.day);
}

bool CalendarEvent::operator ==(const CalendarEvent &event) const {
    return day == event.day && month == event.month && name == event.name;
}

QTextStream& operator<<(QTextStream &stream, const CalendarEvent &event) {
    return stream << event.day << " " << event.month << " " << event.name << endl;
}

QTextStream& operator>>(QTextStream &stream, CalendarEvent &event) {
    stream >> event.day >> event.month;
    stream.skipWhiteSpace();
    event.name = stream.readLine();
    return stream;
}

