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

class QListWidgetItem;


class CalendarWidget : public QWidget {
    Q_OBJECT
public:
    explicit CalendarWidget(QWidget *parent = 0);

    QDate getSelectedDate();

protected:
    void keyPressEvent(QKeyEvent *event);

signals:
    void eventRemoved(const BirthdayEvent& event);

public slots:
    void addEvent(const BirthdayEvent& event);
    void removeEvent(const BirthdayEvent& event);
    
private slots:
    void dataChanged();

private:
    Ui::CalendarWidget* ui;
    QMultiMap<QDate, BirthdayEvent> events;

private:
    bool existEventForDate(const QDate& date);
    void appendEvent(const BirthdayEvent& event);
    void markDateWithEvent(const QDate& date);
    void markDateWithoutEvent(const QDate& date);
    void deleteSelectedEvent();
    QListWidgetItem * getSelectedItem();
    
};

#endif // CALENDAR_H
