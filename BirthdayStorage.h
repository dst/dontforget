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

    void addEvent(const BirthdayEvent& event);

    QList<BirthdayEvent> findCommingEvents(int days);

public slots:
    void removeEvent(const BirthdayEvent& event);
    
signals:
    void eventAdded(const BirthdayEvent& event);
    void eventRemoved(const BirthdayEvent& event);

private:
    QList<BirthdayEvent> events;
};

#endif // BIRTHDAYSTORAGE_H
