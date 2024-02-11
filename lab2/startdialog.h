#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog.h"

class StartDialog: public QPushButton{
    Q_OBJECT


public:
    bool isClicked = false;



    StartDialog(QWidget* pwgt = 0) : QPushButton(pwgt)
    {
        connect(this, SIGNAL(clicked(bool)), SLOT(slotButtonClicked()));

    }
public slots:
    void slotButtonClicked()
    {
        InputDialog* pInputDialog = new InputDialog;

        if (pInputDialog->exec() == QDialog::Accepted)
        {
            QString firstName = pInputDialog->firstName();
            QString lastName = pInputDialog->lastName();
            if (firstName != nullptr && lastName != nullptr) QMessageBox::information(nullptr, "Ваша информация: ", "Имя: " + firstName + " Фамилия: " + lastName);
            else QMessageBox::information(nullptr, "Ошибка", "Одно из полей оказалось пустым! Повторите ввод...");
        }
        delete pInputDialog;
    }
};

#endif // STARTDIALOG_H
