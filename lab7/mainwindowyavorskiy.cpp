#include "mainwindowyavorskiy.h"
#include "ui_mainwindowyavorskiy.h"

#include <QGraphicsScene>
MainWindowYavorskiy::MainWindowYavorskiy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowYavorskiy)
{
    ui->setupUi(this);
    graphicsyavorskiy* scene = new graphicsyavorskiy;
    ui->graphicsView->setScene(scene);
}

MainWindowYavorskiy::~MainWindowYavorskiy()
{
    delete ui;
}
