/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   15 Jun 2012
**************************************************************************/

#ifndef CALENDAR_H
#define CALENDAR_H

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

public slots:
    void birthdayAdded(const BirthdayEvent& event);
    
private:
    Ui::CalendarWidget* ui;
    
};

#endif // CALENDAR_H
