#ifndef IVAN_H
#define IVAN_H

#include <QWidget>
#include <QAbstractButton>


namespace Ui {
class Ivan;
}

class Ivan : public QWidget
{
    Q_OBJECT

public:
    explicit Ivan(QWidget *parent = nullptr);
    ~Ivan();

private:
    Ui::Ivan *ui;
public slots:
    void recieveData(QString str);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
};

#endif // IVAN_H
