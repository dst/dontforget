/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   14 Jun 2012
**************************************************************************/

#include "MainWindow.h"

#include "BirthdayEvent.h"
#include "CalendarWidget.h"

#include <QCloseEvent>
#include <QDebug>
#include <QInputDialog>
#include <QMenuBar>
#include <QToolBar>
#include <QWhatsThis>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {

    calendar = new CalendarWidget(this);
    connect(&storage, SIGNAL(birthdayAdded(BirthdayEvent)),
            calendar, SLOT(addEvent(BirthdayEvent)));
    setCentralWidget(calendar);

    createActions();
    createMenu();
    createToolbar();

    // create status bar (needed for status tips)
    statusBar();

    setWindowTitle(tr("Birthday manager"));
}

void MainWindow::createActions() {
    addEventAction = new QAction(QIcon::fromTheme("add"), tr("&Add"), this);
    addEventAction->setShortcut(Qt::CTRL + Qt::Key_A);
    QString hint = tr("Add event to calendar");
    addEventAction->setStatusTip(hint);
    addEventAction->setToolTip(hint);
    addEventAction->setWhatsThis(hint);

    connect(addEventAction, SIGNAL(triggered()), SLOT(addEvent()));
}

void MainWindow::createMenu() {
    QMenu* eventMenu = menuBar()->addMenu(tr("&Events"));
    eventMenu->addAction(addEventAction);
}

void MainWindow::createToolbar() {
    QToolBar* toolBar = addToolBar("ToolBar");
    toolBar->addAction(addEventAction);
    toolBar->addAction(QWhatsThis::createAction(this));
}

void MainWindow::addEvent() {
    QString name = QInputDialog::getText(this, tr("Adding event"), tr("Event name:"));
    qDebug() << name;
    if (!name.isEmpty()) {
        BirthdayEvent event(calendar->getSelectedDate(), name);
        storage.addBirthday(event);
    }
}


void MainWindow::closeEvent(QCloseEvent *event) {
    qDebug() << "close";
    //TODO: save
    event->accept();
}
