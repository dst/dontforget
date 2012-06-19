/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   18 Jun 2012
**************************************************************************/

#include "EventListWidgetItem.h"

EventListWidgetItem::EventListWidgetItem(const CalendarEvent& event, QListWidget* parent):
    QListWidgetItem(event.getName(), parent), event(event) {
}

const CalendarEvent& EventListWidgetItem::getEvent() const {
    return event;
}

const QString &EventListWidgetItem::getEventName() const {
    return event.getName();
}
