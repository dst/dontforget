/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   24 Jun 2012
**************************************************************************/

#include "FindEventDialog.h"
#include "ui_FindEventDialog.h"

#include <QCompleter>
#include <QDebug>

FindEventDialog::FindEventDialog(const QList<CalendarEvent>& events, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindEventDialog)
{
    ui->setupUi(this);

    createEventMap(events);
    configureEventLineEdit();
}

FindEventDialog::~FindEventDialog() {
    delete ui;
}

const CalendarEvent FindEventDialog::getFoundEvent() {
    return foundEvent;
}

void FindEventDialog::createEventMap(const QList<CalendarEvent> &events) {
    foreach(const CalendarEvent& event, events) {
        description2event[event.toString()] = event;
    }
}

void FindEventDialog::configureEventLineEdit() {
    QCompleter* completer = new QCompleter(description2event.keys(), this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->eventLineEdit->setCompleter(completer);

    connect(ui->eventLineEdit, SIGNAL(editingFinished()), SLOT(goToEvent()));
}

void FindEventDialog::goToEvent() {
    QString description = ui->eventLineEdit->text();
    qDebug() << "Selected: " << description;

    if (description2event.contains(description)) {
        foundEvent = description2event[description];
        accept();
    }
}
