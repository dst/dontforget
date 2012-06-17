/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   15 Jun 2012
**************************************************************************/

#include "CalendarWidget.h"

#include "ui_CalendarWidget.h"

#include <QDebug>
#include <QTextFormat>
#include <QKeyEvent>

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
    events.insert(event.getDate(), event);
    markDateWithEvent(event.getDate());
    dataChanged();
}

void CalendarWidget::removeEvent(const BirthdayEvent &event) {
    int count = events.remove(event.getDate(), event);
    Q_ASSERT(count == 1);

    if (!events.contains(event.getDate())) {
        markDateWithoutEvent(event.getDate());
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
