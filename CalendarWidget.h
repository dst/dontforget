/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   15 Jun 2012
**************************************************************************/

#ifndef CALENDAR_H
#define CALENDAR_H

#include <QMultiMap>
#include <QWidget>

#include "CalendarEvent.h"

namespace Ui {
    class CalendarWidget;
}

class QListWidgetItem;


class CalendarWidget : public QWidget {
    Q_OBJECT
public:
    explicit CalendarWidget(QWidget *parent = 0);
    ~CalendarWidget();

    QDate getSelectedDate() const;
    void setSelectedDate(const QDate& date);

protected:
    void keyPressEvent(QKeyEvent *event);

signals:
    void eventRemoved(const CalendarEvent& event);
    void eventUpdated(const CalendarEvent &oldEvent, const CalendarEvent &newEvent);

public slots:
    void addEvent(const CalendarEvent& event);
    void removeEvent(const CalendarEvent& event);
    
private slots:
    void dataChanged();
    void editEvent(QListWidgetItem* item);

private:
    Ui::CalendarWidget* ui;
    QMultiMap<QDate, CalendarEvent> events;

private:
    bool existEventForDate(const QDate& date);
    void appendEvent(const CalendarEvent& event);
    void markDateWithEvent(const QDate& date);
    void markDateWithoutEvent(const QDate& date);
    void deleteSelectedEvent();
    QListWidgetItem * getSelectedItem();
};

#endif // CALENDAR_H
