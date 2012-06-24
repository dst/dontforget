/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   14 Jun 2012
**************************************************************************/

#include "MainWindow.h"

#include "CalendarEvent.h"
#include "CalendarWidget.h"
#include "FindEventDialog.h"

#include <QDebug>
#include <QSettings>
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

    readSettings();

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

    findEventAction = new QAction(QIcon::fromTheme("find"), tr("&Find"), this);
    QString findHint = tr("Find event");
    findEventAction->setShortcut(QKeySequence::Find);
    findEventAction->setStatusTip(findHint);
    findEventAction->setToolTip(findHint);
    connect(findEventAction, SIGNAL(triggered()), SLOT(findEvent()));
}

void MainWindow::createMenu() {
    QMenu* eventMenu = menuBar()->addMenu(tr("&Events"));
    eventMenu->addAction(addEventAction);
    eventMenu->addAction(findEventAction);
}

void MainWindow::createToolbar() {
    QToolBar* toolBar = addToolBar("ToolBar");
    toolBar->addAction(addEventAction);
    toolBar->addAction(findEventAction);
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

void MainWindow::writeSettings() {
    QSettings settings;
    settings.setValue("size", size());
    settings.setValue("pos", pos());
}

void MainWindow::readSettings() {
    QSettings settings;
    if (settings.contains("size")) {
        // not first time
        resize(settings.value("size").toSize());
        move(settings.value("pos").toPoint());
    }
}

void MainWindow::addEvent() {
    QString name = QInputDialog::getText(this, tr("Adding event"), tr("Event name:"));
    qDebug() << name;
    if (!name.isEmpty()) {
        CalendarEvent event(calendar->getSelectedDate(), name);
        storage.addEvent(event);
    }
}

void MainWindow::findEvent() {
    FindEventDialog findDialog(storage.getEvents(), this);
    findDialog.exec();
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

void MainWindow::closeEvent(QCloseEvent *event) {
    qDebug() << "close";
    writeSettings();
    event->accept();
}
