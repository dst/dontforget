/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   14 Jun 2012
**************************************************************************/

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.show();
    
    return app.exec();
}
