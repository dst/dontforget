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
    QDate date;
    QString name;

public:
    const QDate& getDate() const {
        return date;
    }

    const QString& getName() const {
        return name;
    }

    QList<BirthdayEvent> getNextEvents(int count) const;

    bool operator==(const BirthdayEvent& event) const;

    friend QDataStream& operator<< (QDataStream& stream, const BirthdayEvent& event);
    friend QDataStream& operator>> (QDataStream& stream, BirthdayEvent& event);

};

Q_DECLARE_METATYPE(BirthdayEvent)

#endif // BIRTHDAYEVENT_H
