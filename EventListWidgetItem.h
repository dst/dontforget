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

    CalendarEvent getEvent() const;
};

#endif // EVENTLISTWIDGETITEM_H
