#include "mainwindow.h"
#include <QApplication>
#include <QLoggingCategory>
#include <QFontDatabase>
int main(int argc, char *argv[])
{
    QLoggingCategory::setFilterRules("qt.network.ssl.warning=false");
    QApplication a(argc, argv);
    QFontDatabase fontDatabase;
    fontDatabase.addApplicationFont(":/resources/Resources/ageofreckoning.ttf");
    MainWindow w;
    w.show();

    return a.exec();
}
