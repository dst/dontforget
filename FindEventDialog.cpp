/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   24 Jun 2012
**************************************************************************/

#include "FindEventDialog.h"
#include "ui_FindEventDialog.h"

#include <QCompleter>

FindEventDialog::FindEventDialog(const QList<CalendarEvent>& events, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindEventDialog)
{
    ui->setupUi(this);

    QStringList eventNames;
    foreach(const CalendarEvent& event, events) {
        eventNames.append(event.toString());
    }

    QCompleter* completer = new QCompleter(eventNames, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->nameLineEdit->setCompleter(completer);
}

FindEventDialog::~FindEventDialog() {
    delete ui;
}
