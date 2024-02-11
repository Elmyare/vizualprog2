#include "mainwindowyavorskiy.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowYavorskiy w;
    w.setFixedSize(850,580);
    w.show();

    return a.exec();
}
