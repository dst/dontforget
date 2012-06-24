/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   24 Jun 2012
**************************************************************************/

#ifndef FINDEVENTDIALOG_H
#define FINDEVENTDIALOG_H

#include <QDialog>

#include"CalendarEvent.h"

namespace Ui {
class FindEventDialog;
}

class FindEventDialog : public QDialog {
    Q_OBJECT
    
public:
    FindEventDialog(const QList<CalendarEvent>& events, QWidget *parent = 0);
    ~FindEventDialog();
    
private:
    Ui::FindEventDialog *ui;
};

#endif // FINDEVENTDIALOG_H
