#include "mainwindow.h"
#include <QApplication>
#include "startdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog startDialog;
    startDialog.resize(400, 300);
    startDialog.setText("Нажми Сюда!");
    startDialog.show();

    return a.exec();
}
