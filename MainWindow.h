/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   14 Jun 2012
**************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

#include "EventStorage.h"

class CalendarWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = NULL);

protected:
    void closeEvent(QCloseEvent *event);

private:
    CalendarWidget* calendar;
    EventStorage storage;
    QSystemTrayIcon* trayIcon;
    QAction* addEventAction;

private:
    void makeConnections();
    void createActions();
    void createMenu();
    void createToolbar();
    void createTrayIcon();
    void addTrayActions();

    void writeSettings();
    void readSettings();

private slots:
    void addEvent();
    void loadEvents();
    void checkCommingEvents();
};

#endif // MAINWINDOW_H
