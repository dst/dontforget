/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   18 Jun 2012
**************************************************************************/

#include "EventListWidgetItem.h"

EventListWidgetItem::EventListWidgetItem(const CalendarEvent& event, QListWidget* parent):
        QListWidgetItem(event.getName(), parent) {

    //todo: juz monza trzymac to jako pole w klasie
    setData(Qt::UserRole, QVariant::fromValue(event));
}

CalendarEvent EventListWidgetItem::getEvent() const {
    return data(Qt::UserRole).value<CalendarEvent>();
}
