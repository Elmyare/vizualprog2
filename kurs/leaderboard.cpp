#include "leaderboard.h"
#include "ui_leaderboard.h"
#include "dbconnect.h"
#include <QList>
#include <QString>
#include <QDebug>
#include <QCoreApplication>

LeaderBoard::LeaderBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LeaderBoard)
{
    ui->setupUi(this);
    DatabaseConnection databaseConnection = DatabaseConnection(QCoreApplication::applicationDirPath()+"/../../kurs/resources/database.db");
    auto records = databaseConnection.getRecords();
    for(int i = 0; i < records.size(); i++) {
        this->ui->tableWidget->insertRow(i);
        for(int j = 0; j < records[i].size(); j++) {
            qDebug() << records[i][j];
            this->ui->tableWidget->setItem(i, j, new QTableWidgetItem(records[i][j]));
        }
    }
}

LeaderBoard::~LeaderBoard()
{
    delete ui;
}
