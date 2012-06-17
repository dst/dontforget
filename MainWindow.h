/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   14 Jun 2012
**************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "BirthdayStorage.h"

class CalendarWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = NULL);

protected:
    void closeEvent(QCloseEvent *event);

private:
    CalendarWidget* calendar;
    BirthdayStorage storage;
    QAction* addEventAction;

private:
    void createActions();
    void createMenu();
    void createToolbar();

private slots:
    void addEvent();
};

#endif // MAINWINDOW_H
