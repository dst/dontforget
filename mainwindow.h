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
};

#endif // MAINWINDOW_H
