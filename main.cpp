/**************************************************************************
**   Author: Dariusz Stefanski
**   Date:   14 Jun 2012
**************************************************************************/

#include "MainWindow.h"

#include <QApplication>
#include <QDebug>
#include <QLocale>
#include <QTranslator>

void installTranslator(QApplication& app);

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    installTranslator(app);

    MainWindow mainWin;
    mainWin.show();
    
    return app.exec();
}


void installTranslator(QApplication& app) {
    QString localeName = QLocale::system().name();
    qDebug() << "Detected locale: " << localeName;

    QTranslator translator;
    translator.load(":birthday_" + localeName);
    app.installTranslator(&translator);
}
