#include "mainwindow.h"
#include <QApplication>
#include<QHBoxLayout>
#include<QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(800,500);
    w.show();

    return a.exec();
}

