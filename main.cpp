#include "mainwindow.h"
#include <QApplication>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString::fromUtf8("Traffic_signal checker"));
    w.show();

    return a.exec();
}
