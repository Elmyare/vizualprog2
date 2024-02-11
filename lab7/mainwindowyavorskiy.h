#ifndef MAINWINDOWYAVORSKIY_H
#define MAINWINDOWYAVORSKIY_H

#include "graphicsyavorskiy.h"
#include <QMainWindow>


namespace Ui {
class MainWindowYavorskiy;
}

class MainWindowYavorskiy : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowYavorskiy(QWidget *parent = 0);
    ~MainWindowYavorskiy();

private:
    Ui::MainWindowYavorskiy *ui;
};

#endif // MAINWINDOWYAVORSKIY_H
