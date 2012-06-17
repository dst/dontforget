/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   15 Jun 2012
**************************************************************************/

#include "CalendarWidget.h"

#include "ui_CalendarWidget.h"

#include <QDebug>
#include <QTextFormat>
#include <QKeyEvent>

static int NR_YEARS_IN_PAST = 2;
static int NR_YEARS_IN_FUTURE = 3;

CalendarWidget::CalendarWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::CalendarWidget()) {

    ui->setupUi(this);
    connect(ui->calendarWidget, SIGNAL(selectionChanged()), this, SLOT(dataChanged()));
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

void CalendarWidget::addEvent(const BirthdayEvent &event) {
    QList<QDate> dates = event.getDatesWithin(NR_YEARS_IN_PAST, NR_YEARS_IN_FUTURE);

    foreach (const QDate& date, dates) {
        events.insert(date, event);
        markDateWithEvent(date);
    }

    dataChanged();
}

void CalendarWidget::removeEvent(const BirthdayEvent &event) {
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
        foreach (const BirthdayEvent& event, events.values(date)) {
            appendEvent(event);
        }
    }
}

bool CalendarWidget::existEventForDate(const QDate &date) {
    return events.contains(date);
}

void CalendarWidget::appendEvent(const BirthdayEvent &event) {
    QListWidgetItem* item = new QListWidgetItem(event.getName(), ui->listWidget);
    item->setData(Qt::UserRole, QVariant::fromValue(event));
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

    QListWidgetItem* selected = getSelectedItem();
    if (selected != NULL) {
        BirthdayEvent event = selected->data(Qt::UserRole).value<BirthdayEvent>();
        emit eventRemoved(event);
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
