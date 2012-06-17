/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   15 Jun 2012
**************************************************************************/

#include "CalendarWidget.h"

#include "ui_CalendarWidget.h"

#include <QDebug>
#include <QTextFormat>

CalendarWidget::CalendarWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::CalendarWidget()) {

    ui->setupUi(this);
    connect(ui->calendarWidget, SIGNAL(selectionChanged()), this, SLOT(dataChanged()));
}

QDate CalendarWidget::getSelectedDate() {
    return ui->calendarWidget->selectedDate();
}

void CalendarWidget::addEvent(const BirthdayEvent &event) {
    events.insert(event.getDate(), event);
    markDateWithEvent(event.getDate());
    dataChanged();
}

void CalendarWidget::dataChanged() {
    QDate date = getSelectedDate();
    qDebug() << date;

    ui->listWidget->clear();

    if (events.contains(date)) {
        foreach (const BirthdayEvent& event, events.values(date)) {
            appendEvent(event);
        }
    }
}

void CalendarWidget::appendEvent(const BirthdayEvent &event) {
    ui->listWidget->addItem(event.getName());
}

void CalendarWidget::markDateWithEvent(const QDate &date) {
    QTextCharFormat format;
    format.setBackground(QBrush(Qt::green));
    ui->calendarWidget->setDateTextFormat(date, format);
}
