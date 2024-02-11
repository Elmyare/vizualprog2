#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QMap>
#include <QLabel>
#include <QString>
#include <QCoreApplication>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QButtonGroup *BuyButtonGroup = new QButtonGroup(this);
    QButtonGroup *SeedButtonGroup = new QButtonGroup(this);
    QButtonGroup *SellButtonGroup = new QButtonGroup(this);
    QMap<int, int> SeedAmount;
    QMap<int, int> SeedCost;
    QMap<int, QLabel*> SeedAmounts;
    QMap<int, QPixmap> ungrowthed;
    QMap<int, QPixmap> growthed;
    int seed_id_to_seed = 0;

    QString imagePath = QCoreApplication::applicationDirPath()+"/../resources/";

    int balance;
           // Создаем кнопки с их уникальными идентификаторами

           // Добавляем кнопки в группу

           // Соединяем сигнал buttonClicked() группы кнопок со слотом
    //connect(buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this, &MyWidget::buttonClicked);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void BuySeeds(QAbstractButton*);
    void SeedSeeds(QAbstractButton*);
    void SellSeeds(QAbstractButton*);
    void FieldClick(QAbstractButton*);
    void showLeaderBoard();
};

#endif // MAINWINDOW_H
