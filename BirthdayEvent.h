/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   16 Jun 2012
**************************************************************************/

#ifndef BIRTHDAYEVENT_H
#define BIRTHDAYEVENT_H

#include <QDataStream>
#include <QDate>
#include <QList>
#include <QMetaType>

class BirthdayEvent {
public:
    BirthdayEvent() {};
    BirthdayEvent(const QDate& date, const QString& name);

private:
    int month;
    int day;
    QString name;

public:
    const QString& getName() const {
        return name;
    }

    QList<QDate> getDatesWithin(int yearsPast, int yearsFuture) const;

    bool operator==(const BirthdayEvent& event) const;

    friend QDataStream& operator<< (QDataStream& stream, const BirthdayEvent& event);
    friend QDataStream& operator>> (QDataStream& stream, BirthdayEvent& event);

};

Q_DECLARE_METATYPE(BirthdayEvent)

#endif // BIRTHDAYEVENT_H
