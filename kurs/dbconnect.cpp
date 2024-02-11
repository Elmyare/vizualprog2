#include "dbconnect.h"
#include <QDebug>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>


DatabaseConnection::DatabaseConnection(const QString &path)
{
    this->database = QSqlDatabase::addDatabase("QSQLITE");
    this->database.setDatabaseName(path);
    if (!this->database.open()) {
        qDebug() << "ERROR1";
    } else {
        qDebug() << "WORKING1!";
    }
}


void DatabaseConnection::addRecord(const QString date, const int money) {
    QSqlQuery query;
    query.prepare("INSERT INTO leaderboard (date, money) VALUES (:date, :money)");
    query.bindValue(":date", date);
    query.bindValue(":money", money);
    if (query.exec()) {
        qDebug() << "WORKING!";
    } else {
        qDebug() << "NOT WORKING(";
    }
}


QList<QList<QString> > DatabaseConnection::getRecords() {
    QSqlQuery query(this->database);
    QList<QList<QString> > records;
    if (query.exec("SELECT date, money FROM leaderboard ORDER BY date")) {
        while(query.next()) {
            QList<QString> tmp;
            QString date = query.value(0).toString();
            QString money =  query.value(1).toString();
            tmp.append(date);
            tmp.append(money);
            records.append(tmp);
        }
    } else {
        qDebug() << "FAIL";
        qDebug() << query.lastError();
    }

    return records;

}
