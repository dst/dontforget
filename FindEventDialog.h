/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   24 Jun 2012
**************************************************************************/

#ifndef FINDEVENTDIALOG_H
#define FINDEVENTDIALOG_H

#include <QDialog>
#include <QMap>

#include"CalendarEvent.h"

namespace Ui {
class FindEventDialog;
}

class FindEventDialog : public QDialog {
    Q_OBJECT
    
public:
    FindEventDialog(const QList<CalendarEvent>& events, QWidget *parent = 0);
    ~FindEventDialog();

    const CalendarEvent getFoundEvent();
    
private slots:
    void goToEvent();

private:
    Ui::FindEventDialog *ui;
    QMap<QString, CalendarEvent> description2event;
    CalendarEvent foundEvent;

private:
    void createEventMap(const QList<CalendarEvent>& events);
    void configureEventLineEdit();
};

#endif // FINDEVENTDIALOG_H
