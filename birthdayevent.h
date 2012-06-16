/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   16 Jun 2012
**************************************************************************/

#ifndef BIRTHDAYEVENT_H
#define BIRTHDAYEVENT_H

#include <QDate>

class BirthdayEvent {
public:
    BirthdayEvent(const QDate& date, const QString& name);

private:
    QDate date;
    QString name;
};

#endif // BIRTHDAYEVENT_H
