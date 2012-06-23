/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   14 Jun 2012
**************************************************************************/

#include "MainWindow.h"

#include "CalendarEvent.h"
#include "CalendarWidget.h"

#include <QDebug>
#include <QTimer>

static const int DAYS_TRESHOLD = 7;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {

    calendar = new CalendarWidget(this);
    setCentralWidget(calendar);

    makeConnections();

    createActions();
    createMenu();
    createToolbar();
    // create status bar (needed for status tips)
    statusBar();
    createTrayIcon();

    setWindowTitle(tr("Birthday manager"));

    // to not block showing GUI
    QTimer::singleShot(0, this, SLOT(loadEvents()));
    QTimer::singleShot(0, this, SLOT(checkCommingEvents()));
}

void MainWindow::makeConnections() {
    connect(&storage, SIGNAL(eventAdded(CalendarEvent)),
            calendar, SLOT(addEvent(CalendarEvent)));
    connect(&storage, SIGNAL(eventRemoved(CalendarEvent)),
            calendar, SLOT(removeEvent(CalendarEvent)));

    connect(calendar, SIGNAL(eventRemoved(CalendarEvent)),
            &storage, SLOT(removeEvent(CalendarEvent)));
    connect(calendar, SIGNAL(eventUpdated(CalendarEvent,CalendarEvent)),
            &storage, SLOT(updateEvent(CalendarEvent,CalendarEvent)));
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

void MainWindow::createTrayIcon() {
    trayIcon = new QSystemTrayIcon(QIcon::fromTheme("x-office-calendar"), this);
    addTrayActions();
    trayIcon->show();
}

void MainWindow::addTrayActions() {
    QAction* showAction = new QAction("&Show", this);
    connect(showAction, SIGNAL(triggered()), this, SLOT(raise()));

    QAction* quitAction = new QAction("&Quit", this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu* trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(showAction);
    trayIconMenu->addAction(quitAction);

    trayIcon->setContextMenu(trayIconMenu);
}

void MainWindow::addEvent() {
    QString name = QInputDialog::getText(this, tr("Adding event"), tr("Event name:"));
    qDebug() << name;
    if (!name.isEmpty()) {
        CalendarEvent event(calendar->getSelectedDate(), name);
        storage.addEvent(event);
    }
}

void MainWindow::loadEvents() {
    storage.load();
}

void MainWindow::checkCommingEvents() {
    QList<CalendarEvent> closeEvents = storage.findCommingEvents(DAYS_TRESHOLD);
    foreach (const CalendarEvent& event, closeEvents) {
        trayIcon->showMessage(tr("Comming event"), event.toString());
        QMessageBox::information(this, tr("Comming event"), event.toString());
    }
}
