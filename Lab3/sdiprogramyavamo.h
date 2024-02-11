#ifndef SDIPROGRAMYAVAMO_H
#define SDIPROGRAMYAVAMO_H

#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include "docwindowyavamo.h"

namespace Ui {
class SDIProgramYavAmo;
}

class SDIProgramYavAmo : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgramYavAmo(QWidget *parent = 0) : QMainWindow(parent)
    {
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        DocWindowYavAmo* pdoc = new DocWindowYavAmo;

    pmnuFile->addAction("&Open...",
                        pdoc,
                        SLOT(slotLoad()),
                        QKeySequence("CTRL+O")
                        );
    pmnuFile->addAction("&Save",
                        pdoc,
                        SLOT(slotSave()),
                        QKeySequence("CTRL+S")
                        );
    pmnuFile->addAction("&Save As...",
                        pdoc,
                        SLOT(slotSaveAs()),
                        QKeySequence("CTRL+A")
                        );
    pmnuFile->addAction("&Color",
                        pdoc,
                        SLOT(slotColor()),
                        QKeySequence("CTRL+J")
                        );
    pmnuFile->addSeparator();
    pmnuFile->addAction("&Quit",
                        qApp,
                        SLOT(quit()),
                        QKeySequence("CTRL+Q")
                        );
    pmnuHelp->addAction("&About",
                        this,
                        SLOT(slotAbout()),
                        Qt::Key_F1
                        );

    menuBar()->addMenu(pmnuFile);
    menuBar()->addMenu(pmnuHelp);

    setCentralWidget(pdoc);

    connect(pdoc,
            SIGNAL(changeWindowTitle(const QString&)),
            SLOT(slotChangeWindowTitle(const QString&))
            );

    statusBar()->showMessage("Ready", 2000);
    }

    ~SDIProgramYavAmo();

private:
    Ui::SDIProgramYavAmo *ui;

public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "Application", "Yavorskiy_Amoshenko_IP-114");
    }

    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }

};

#endif // SDIPROGRAMYAVAMO_H
