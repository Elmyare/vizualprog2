#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

#define DEFAULT_DATABASE_PATH ""

class DatabaseConnection
{
public:
    DatabaseConnection(const QString &path);
    void addRecord(const QString date, const int money);
    QList<QList<QString> >  getRecords();
private:
    QSqlDatabase database;
};

#endif // DBCONNECT_H
