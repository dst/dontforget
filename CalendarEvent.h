/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   16 Jun 2012
**************************************************************************/

#ifndef CALENDAREVENT_H
#define CALENDAREVENT_H

#include <QDataStream>
#include <QDate>
#include <QList>
#include <QMetaType>

class CalendarEvent {
public:
    CalendarEvent() {};
    CalendarEvent(const QDate& date, const QString& name);

    const QString& getName() const {
        return name;
    }

    void setName(const QString& name) {
        this->name = name;
    }

    QDate getClosestDate() const;
    QList<QDate> getDatesWithin(int yearsPast, int yearsFuture) const;

    bool operator==(const CalendarEvent& event) const;

    QString toString() const;

private:
    int month;
    int day;
    QString name;

    friend QDataStream& operator<< (QDataStream& stream, const CalendarEvent& event);
    friend QDataStream& operator>> (QDataStream& stream, CalendarEvent& event);
};

//todo: wpradzic shared pointer i go uzywac, bo jest duzo kopiowania

Q_DECLARE_METATYPE(CalendarEvent)

#endif // CALENDAREVENT_H
