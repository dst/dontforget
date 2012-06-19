/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   18 Jun 2012
**************************************************************************/

#ifndef EVENTLISTWIDGETITEM_H
#define EVENTLISTWIDGETITEM_H

#include "CalendarEvent.h"

#include <QListWidgetItem>

class EventListWidgetItem : public QListWidgetItem {
public:
    EventListWidgetItem(const CalendarEvent& event, QListWidget* parent = NULL);
    const CalendarEvent& getEvent() const;
    const QString& getEventName() const;

private:
    CalendarEvent event;
};

#endif // EVENTLISTWIDGETITEM_H
