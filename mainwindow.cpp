/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   14 Jun 2012
**************************************************************************/

#include "mainwindow.h"

#include "birthdayevent.h"
#include "ui_CentralWidget.h"

#include <QCloseEvent>
#include <QDebug>
#include <QInputDialog>
#include <QMenuBar>
#include <QToolBar>
#include <QWhatsThis>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CentralWidget()) {

    QWidget* widget = new QWidget(this);
    ui->setupUi(widget);
    setCentralWidget(widget);

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
    BirthdayEvent event(QDate::currentDate(), name); //todo

    ui->listWidget->addItem(name);
}


void MainWindow::closeEvent(QCloseEvent *event) {
    qDebug() << "close";
    //TODO: save
    event->accept();
}
