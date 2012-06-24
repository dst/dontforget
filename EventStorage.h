/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   17 Jun 2012
**************************************************************************/

#ifndef EVENTSTORAGE_H
#define EVENTSTORAGE_H

#include <QObject>
#include <QList>

#include "CalendarEvent.h"

class EventStorage : public QObject {
    Q_OBJECT
public:
    explicit EventStorage(QObject *parent = 0);

    void save();
    void load();

    const QList<CalendarEvent>& getEvents() const;
    void addEvent(const CalendarEvent& event);

    QList<CalendarEvent> findCommingEvents(int days);

public slots:
    void removeEvent(const CalendarEvent& event);
    void updateEvent(const CalendarEvent& oldEvent, const CalendarEvent& newEvent);
    
signals:
    void eventAdded(const CalendarEvent& event);
    void eventRemoved(const CalendarEvent& event);

private:
    QList<CalendarEvent> events;
};

#endif // EVENTSTORAGE_H
