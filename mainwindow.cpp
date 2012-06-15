#include "mainwindow.h"

#include "ui_CentralWidget.h"

#include <QMenuBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CentralWidget()) {

    QWidget* widget = new QWidget(this);
    ui->setupUi(widget);
    setCentralWidget(widget);

    createActions();
    createMenu();
    createToolbar();

    // create status bar
    statusBar();
}

void MainWindow::createActions() {
    addEventAction = new QAction(tr("&Add event"), this);
    QString hint = tr("Add event to calendar");
    addEventAction->setStatusTip(hint);
    addEventAction->setToolTip(hint);
}

void MainWindow::createMenu() {
    QMenu* eventMenu = menuBar()->addMenu(tr("&Events"));
    eventMenu->addAction(addEventAction);
}

void MainWindow::createToolbar() {
    QToolBar* toolBar = addToolBar("Test");
    toolBar->addAction(addEventAction);
    addToolBar(toolBar);
}
