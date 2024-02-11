#include <QButtonGroup>
#include <QPoint>
#include <QDebug>
#include <QDate>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "leaderboard.h"
#include "dbconnect.h"
#include <QPixmap>
#include <QImage>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    balance = 100;
    for (int i = 1; i <= 4; i++) {
        SeedAmount[i] = 0;
        SeedCost[i] = i*100;
        QImage image(imagePath+QString::number(i)+"_0.bmp");
        QPixmap pix = QPixmap::fromImage(image).scaled(QSize(70, 70), Qt::KeepAspectRatio, Qt::FastTransformation);
        QImage image2(imagePath+QString::number(i)+"_1.bmp");
        QPixmap pix2 = QPixmap::fromImage(image2).scaled(QSize(70, 70), Qt::KeepAspectRatio, Qt::FastTransformation);
        ungrowthed[i] = pix;
        growthed[i] = pix2;
    }
    SeedAmounts[1] = ui->SeedAmount_1;
    SeedAmounts[2] = ui->SeedAmount_2;
    SeedAmounts[3] = ui->SeedAmount_3;
    SeedAmounts[4] = ui->SeedAmount_4;
    //ui->Balance->setText(QString::number(1234));
    BuyButtonGroup->addButton(ui->BuyPushButton_1, 1);
    BuyButtonGroup->addButton(ui->BuyPushButton_2, 2);
    BuyButtonGroup->addButton(ui->BuyPushButton_3, 3);
    BuyButtonGroup->addButton(ui->BuyPushButton_4, 4);

    SeedButtonGroup->addButton(ui->SeedPushButton_1, 1);
    SeedButtonGroup->addButton(ui->SeedPushButton_2, 2);
    SeedButtonGroup->addButton(ui->SeedPushButton_3, 3);
    SeedButtonGroup->addButton(ui->SeedPushButton_4, 4);

    SellButtonGroup->addButton(ui->SellPushButton_1, 1);
    SellButtonGroup->addButton(ui->SellPushButton_2, 2);
    SellButtonGroup->addButton(ui->SellPushButton_3, 3);
    SellButtonGroup->addButton(ui->SellPushButton_4, 4);
    qDebug()<<imagePath;
    //QImage image(imagePath+"Картофель.bmp");
    //QPixmap pix = QPixmap::fromImage(image).scaled(ui->pushButton_1->size(), Qt::KeepAspectRatio, Qt::FastTransformation);
    //ui->pushButton_1->setIcon(pix);
    //ui->pushButton_1->setIconSize(pix.size());
    //ui->pushButton_1->setIcon(QIcon(pix));
    //ui->pushButton_1->setIconSize(ui->pushButton_1->size());
    //SeedAmounts[1] = ui->SeedAmount_1;
    //SeedAmounts[2] = ui->SeedAmount_2;
    //SeedAmounts[3] = ui->SeedAmount_3;
    //SeedAmounts[4] = ui->SeedAmount_4;
    //connect(BuyButtonGroup, QOverload<int>::of(&QButtonGroup::BuyButton), this, &MyWidget::buttonClicked);
    connect(BuyButtonGroup, SIGNAL(buttonClicked(QAbstractButton *)),this, SLOT(BuySeeds(QAbstractButton *)));
    connect(SeedButtonGroup, SIGNAL(buttonClicked(QAbstractButton *)),this, SLOT(SeedSeeds(QAbstractButton *)));
    connect(SellButtonGroup, SIGNAL(buttonClicked(QAbstractButton *)),this, SLOT(SellSeeds(QAbstractButton *)));
    connect(ui->CropField, SIGNAL(buttonClicked(QAbstractButton *)),this, SLOT(FieldClick(QAbstractButton *)));
    connect(ui->LeadersPushButton, &QPushButton::clicked, this, &MainWindow::showLeaderBoard);
}

MainWindow::~MainWindow()
{
    DatabaseConnection databaseConnection = DatabaseConnection(QCoreApplication::applicationDirPath()+"/../../kurs/resources/database.db");
    databaseConnection.addRecord(QDate::currentDate().toString(), balance);
    delete ui;
}

void MainWindow::BuySeeds(QAbstractButton* button)
{
    int id = BuyButtonGroup->id(button);
    qDebug()<<id;
    if (balance >= SeedCost[id]) {
        SeedAmount[id]++;
        balance -= SeedCost[id];
        ui->Balance->setText(QString::number(balance));
        qDebug()<<balance;
        SeedAmounts[id]->setText(QString::number(SeedAmount[id]));
        qDebug()<<"gotcha";
    }
    //qDebug()<<button->cursor().pos();//screen coordinates
    //qDebug()<<button->mapFromGlobal(ui->BuyButtonGroup->cursor().pos())
    //qDebug()<<button->
}

void MainWindow::SeedSeeds(QAbstractButton* button)
{
    int id = SeedButtonGroup->id(button);
    seed_id_to_seed = id;
    //qDebug()<<id;
    //qDebug()<<button->cursor().pos();//screen coordinates
    //qDebug()<<button->mapFromGlobal(ui->BuyButtonGroup->cursor().pos())
    //qDebug()<<button->
}

void MainWindow::SellSeeds(QAbstractButton* button)
{
    int id = SellButtonGroup->id(button);
    if (SeedAmount[id]>0) {
        SeedAmount[id]--;
        balance += SeedCost[id];
        SeedAmounts[id]->setText(QString::number(SeedAmount[id]));
        ui->Balance->setText(QString::number(balance));
    }
    qDebug()<<id;
    //qDebug()<<button->cursor().pos();//screen coordinates
    //qDebug()<<button->mapFromGlobal(ui->BuyButtonGroup->cursor().pos())
    //qDebug()<<button->
}

void MainWindow::FieldClick(QAbstractButton* button)
{
    QIcon icon = button->icon();
    if (icon.isNull() && seed_id_to_seed > 0) {
        int localidtoseed = seed_id_to_seed;
        if (SeedAmount[localidtoseed] > 0) {
            SeedAmount[localidtoseed]--;
            qDebug()<<button->size();
            SeedAmounts[localidtoseed]->setText(QString::number(SeedAmount[localidtoseed]));
            button->setIcon(QIcon(ungrowthed[localidtoseed]));
            button->setProperty("ID", localidtoseed);
            //button->setIconSize(pix.size());
            //button->setIcon(QIcon(pix));

            QTimer::singleShot(2000, [=]() {
                    button->setIcon(QIcon(growthed[localidtoseed]));;
                    //button->setIconSize(pix2.size());
                    button->setProperty("grown", true);
                });
        }
    } else {
        qDebug()<<icon.name();
        if (button->property("grown").toBool()) {
            qDebug()<<"tut";
            seed_id_to_seed = 0;
            int id = button->property("ID").toInt();
            button->setIcon(QIcon());
            SeedAmount[id] += 2;
            SeedAmounts[id]->setText(QString::number(SeedAmount[id]));
            button->setProperty("grown", false);
        }
    }
}

void MainWindow::showLeaderBoard() {
    qDebug()<<"HOH";
    auto leaderBoard = new LeaderBoard();
    leaderBoard->show();
    //this->resetGame();
}
