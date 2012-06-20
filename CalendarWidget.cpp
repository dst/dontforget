/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   15 Jun 2012
**************************************************************************/

#include "CalendarWidget.h"

#include "EventListWidgetItem.h"
#include "ui_CalendarWidget.h"

#include <QDebug>
#include <QInputDialog>
#include <QTextFormat>
#include <QKeyEvent>

static int NR_YEARS_IN_PAST = 2;
static int NR_YEARS_IN_FUTURE = 3;

CalendarWidget::CalendarWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::CalendarWidget()) {

    ui->setupUi(this);

    connect(ui->calendarWidget, SIGNAL(selectionChanged()),
            this, SLOT(dataChanged()));

    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(editEvent(QListWidgetItem*)));
}

QDate CalendarWidget::getSelectedDate() {
    return ui->calendarWidget->selectedDate();
}

void CalendarWidget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete) {
        deleteSelectedEvent();
    } else {
        QWidget::keyPressEvent(event);
    }
}

void CalendarWidget::addEvent(const CalendarEvent &event) {
    QList<QDate> dates = event.getDatesWithin(NR_YEARS_IN_PAST, NR_YEARS_IN_FUTURE);

    foreach (const QDate& date, dates) {
        events.insert(date, event);
        markDateWithEvent(date);
    }

    dataChanged();
}

void CalendarWidget::removeEvent(const CalendarEvent &event) {
    QList<QDate> dates = event.getDatesWithin(NR_YEARS_IN_PAST, NR_YEARS_IN_FUTURE);

    foreach (const QDate& date, dates) {
        int count = events.remove(date, event);
        Q_ASSERT(count == 1);

        if (!existEventForDate(date)) {
            markDateWithoutEvent(date);
        }
    }

    dataChanged();
}

void CalendarWidget::dataChanged() {
    QDate date = getSelectedDate();
    qDebug() << date;

    ui->listWidget->clear();

    if (events.contains(date)) {
        /* the most recently added events go to the end of list */
        QListIterator<CalendarEvent> eventIt(events.values(date));
        eventIt.toBack();
        while(eventIt.hasPrevious()) {
            appendEvent(eventIt.previous());
        }
    }
}

void CalendarWidget::editEvent(QListWidgetItem *item) {
    EventListWidgetItem* eventItem = (EventListWidgetItem*) item;
    QString newName = QInputDialog::getText(this, tr("Editing event"), tr("Event name:"),
        QLineEdit::Normal, eventItem->getEventName());

    qDebug() << "New event name: " << newName;

    const CalendarEvent& oldEvent = eventItem->getEvent();
    CalendarEvent newEvent(oldEvent);
    newEvent.setName(newName);

    emit eventUpdated(oldEvent, newEvent);
}

bool CalendarWidget::existEventForDate(const QDate &date) {
    return events.contains(date);
}

void CalendarWidget::appendEvent(const CalendarEvent &event) {
    EventListWidgetItem* item = new EventListWidgetItem(event, ui->listWidget);
    ui->listWidget->addItem(item);
}

void CalendarWidget::markDateWithEvent(const QDate &date) {
    QTextCharFormat format;
    format.setBackground(QBrush(Qt::green));
    ui->calendarWidget->setDateTextFormat(date, format);
}

void CalendarWidget::markDateWithoutEvent(const QDate &date) {
    QTextCharFormat format;
    format.setBackground(QBrush(Qt::white));
    ui->calendarWidget->setDateTextFormat(date, format);
}

void CalendarWidget::deleteSelectedEvent() {
    qDebug() << __FUNCTION__;

    EventListWidgetItem* selected = (EventListWidgetItem*) getSelectedItem();
    if (selected != NULL) {
        emit eventRemoved(selected->getEvent());
    }
}

QListWidgetItem* CalendarWidget::getSelectedItem() {
    QList<QListWidgetItem *> selectedItems = ui->listWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        return NULL;
    } else {
        Q_ASSERT(selectedItems.size() == 1);
        return selectedItems.first();
    }
}
