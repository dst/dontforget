/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   15 Jun 2012
**************************************************************************/

#include "CalendarWidget.h"

#include "ui_CalendarWidget.h"

CalendarWidget::CalendarWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::CalendarWidget()) {

    ui->setupUi(this);
}

void CalendarWidget::birthdayAdded(const BirthdayEvent &event) {
   ui->listWidget->addItem(event.getName());
}
