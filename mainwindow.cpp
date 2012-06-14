#include "mainwindow.h"
#include "ui_CentralWidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CentralWidget()) {

    QWidget* widget = new QWidget(this);
    ui->setupUi(widget);
    setCentralWidget(widget);
}

