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
void setAppName();

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    installTranslator(app);

    setAppName();

    MainWindow mainWin;
    mainWin.show();
    
    return app.exec();
}

void setAppName() {
    // QSettings uses it
    QCoreApplication::setOrganizationName("DarekCorporation");
    QCoreApplication::setApplicationName("dontforget");
}


void installTranslator(QApplication& app) {
    QString localeName = QLocale::system().name();
    qDebug() << "Detected locale: " << localeName;

    QTranslator translator;
    // : - take file from resources
    QString filename = ":/i18n/dontforget_" + localeName;
    if (!translator.load(filename)) {
        Q_ASSERT(!"Translation file not found!");
    }
    app.installTranslator(&translator);
}
