/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   17 Jun 2012
**************************************************************************/

#ifndef BIRTHDAYSTORAGE_H
#define BIRTHDAYSTORAGE_H

#include <QObject>
#include <QList>

#include "BirthdayEvent.h"

class BirthdayStorage : public QObject {
    Q_OBJECT
public:
    explicit BirthdayStorage(QObject *parent = 0);

    void save();
    void load();
    void addBirthday(const BirthdayEvent& event);
    
signals:
    void birthdayAdded(const BirthdayEvent& event);
    void birthdayRemoved(const BirthdayEvent& event);

private:
    QList<BirthdayEvent> events;
};

#endif // BIRTHDAYSTORAGE_H
