#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class CentralWidget;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = NULL);

private:
    Ui::CentralWidget* ui;
    QAction* addEventAction;

private:
    void createActions();
    void createMenu();
    void createToolbar();
};

#endif // MAINWINDOW_H
