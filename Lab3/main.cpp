#include "sdiprogramyavamo.h"
#include <QApplication>
#include <QSplashScreen>
#include <QtWidgets>

void loadModules(QSplashScreen* psplash){
    QTime time;
    time.start();

    for (int i = 0; i < 100;){
        if (time.elapsed()>40){
            time.start();
            i++;
        }

        psplash->showMessage("Loading modules: " + QString::number(i) + "%",
                             Qt::AlignCenter, Qt::green);
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap("D:\\Моя учеба\\СибГУТИ\\ТРЕТИЙ КУРС\\V СЕМЕСТР\\Виз прог и чел-маш взаимод (часть 2)\\labs\\1.jpg"));
    splash.show();
    SDIProgramYavAmo w;
    loadModules(&splash);
    splash.finish(&w);
    w.show();

    return a.exec();
}
