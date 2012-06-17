/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   15 Jun 2012
**************************************************************************/

#ifndef CALENDAR_H
#define CALENDAR_H

#include <QMultiMap>
#include <QWidget>

#include "BirthdayEvent.h"

namespace Ui {
    class CalendarWidget;
}

class CalendarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CalendarWidget(QWidget *parent = 0);

    QDate getSelectedDate();

public slots:
    void addEvent(const BirthdayEvent& event);
    
private slots:
    void dataChanged();

private:
    Ui::CalendarWidget* ui;
    QMultiMap<QDate, BirthdayEvent> events;

private:
    void appendEvent(const BirthdayEvent& event);
    void markDateWithEvent(const QDate& date);
    
};

#endif // CALENDAR_H
