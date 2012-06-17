/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   16 Jun 2012
**************************************************************************/

#ifndef BIRTHDAYEVENT_H
#define BIRTHDAYEVENT_H

#include <QDataStream>
#include <QDate>

class BirthdayEvent {
public:
    BirthdayEvent() {};
    BirthdayEvent(const QDate& date, const QString& name);

private:
    QDate date;
    QString name;

public:
    const QDate& getDate() const {
        return date;
    }

    const QString& getName() const {
        return name;
    }


    friend QDataStream& operator<< (QDataStream& stream, const BirthdayEvent& event);
    friend QDataStream& operator>> (QDataStream& stream, BirthdayEvent& event);

};

#endif // BIRTHDAYEVENT_H
