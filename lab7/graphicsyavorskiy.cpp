#include "graphicsyavorskiy.h"
#include <iostream>
#include <QHBoxLayout>
#include <QLabel>
#include <QCoreApplication>

void graphicsyavorskiy::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Up){
        speed < 4 ? speed++ : speed;
    }
    if(event->key() == Qt::Key_Down){
        speed = qMax(speed - 1, 1);
    }
 }

void graphicsyavorskiy::MoveCrow(){
    if(!collidingItems(crow).isEmpty())
    {
        int tmp1 = qrand() % 3 - 1;
        int tmp2 = qrand() % 3 - 1;
        dx != tmp1 ? dx=tmp1 : dx*=-1;
        dy != tmp2 ? dy = tmp2 : dy *=-1;
    }
       crow->setTransform(crow->transform().translate(dx * speed, dy * speed));
}

graphicsyavorskiy::graphicsyavorskiy(QObject* parent):QGraphicsScene (parent)
{
//ГРЯДКА 1
    int StartY1 = 450;
    for (int j = 0; j < 6; j++, StartY1 -= 40)
    {
        int StartX1 = 10;
        for (int i = 0; i < 3; i++, StartX1 += 40)
        {
            QPolygon poligoneTube;
            poligoneTube << QPoint(0, 0) << QPoint(36, 0) << QPoint(36, 40) << QPoint(0, 40);
            QGraphicsPolygonItem* tube = addPolygon(poligoneTube, QPen(Qt::black), QBrush(QColor(1, 169, 127)));
            tube->setPos(StartX1, StartY1);
            tube->setFlags(QGraphicsItem::ItemIsMovable);
        }
    }

//ГРЯДКА 2
    int StartY2 = 450;
    for (int j = 0; j < 6; j++, StartY2 -= 40)
    {
        int StartX2 = 140;
        for (int i = 0; i < 3; i++, StartX2 += 40)
        {
            QPolygon poligoneTube;
            poligoneTube << QPoint(0, 0) << QPoint(36, 0) << QPoint(36, 40) << QPoint(0, 40);
            QGraphicsPolygonItem* tube = addPolygon(poligoneTube, QPen(Qt::black), QBrush(QColor(1, 169, 127)));
            tube->setPos(StartX2, StartY2);
            tube->setFlags(QGraphicsItem::ItemIsMovable);
        }
    }

//ГРЯДКА 3
    int StartY3 = 450;
    for (int j = 0; j < 6; j++, StartY3 -= 40)
    {
        int StartX3 = 270;
        for (int i = 0; i < 3; i++, StartX3 += 40)
        {
             QPolygon poligoneTube;
             poligoneTube << QPoint(0, 0) << QPoint(36, 0) << QPoint(36, 40) << QPoint(0, 40);
             QGraphicsPolygonItem* tube = addPolygon(poligoneTube, QPen(Qt::black), QBrush(QColor(1, 169, 127)));
             tube->setPos(StartX3, StartY3);
             tube->setFlags(QGraphicsItem::ItemIsMovable);
        }
     }

//ЛОВУШКИ
    QPixmap newImage;
    if (!newImage.load(QStringLiteral("C:\\Users\\79133\\QtProjects\\petlya.jpg")))return;    
    QGraphicsPixmapItem* window[4];
    for(int i=0; i<4; i++)
    {
            window[i] = addPixmap(newImage);
            window[i]->setScale(0.15);
            window[i]->setData(0, "Garden_Bed");
            window[i]->setFlags(QGraphicsItem::ItemIsMovable);
    }
    window[0]->setPos(53,13);
    window[1]->setPos(489,389);
    window[2]->setPos(760,100);
    window[3]->setPos(200,180);

//КУСТЫ ЯГОДЫ
   QPixmap newImage1;
   if (!newImage1.load(QStringLiteral("C:\\Users\\79133\\QtProjects\\yagoda.png")))return;
    QGraphicsPixmapItem* window1[18];
    for(int i=0; i<18; i++)
    {
            window1[i] = addPixmap(newImage1);
            window1[i]->setScale(0.15);
            window1[i]->setData(0, "Garden_Bed");
            window1[i]->setFlags(QGraphicsItem::ItemIsMovable);
    }

    window1[0]->setPos(10,250); window1[1]->setPos(50,250); window1[2]->setPos(90,250);
    window1[3]->setPos(10,290); window1[4]->setPos(50,290); window1[5]->setPos(90,290);
    window1[6]->setPos(10,330); window1[7]->setPos(50,330); window1[8]->setPos(90,330);
    window1[9]->setPos(10,370); window1[10]->setPos(50,370); window1[11]->setPos(90,370);
    window1[12]->setPos(10,410); window1[13]->setPos(50,410); window1[14]->setPos(90,410);
    window1[15]->setPos(10,450); window1[16]->setPos(50,450); window1[17]->setPos(90,450);

//ПОДСОЛНУХ
    QPixmap newImage2;
    if (!newImage2.load(QStringLiteral("C:\\Users\\ivanl\\Downloads\\kek.png")))return;
    QGraphicsPixmapItem* window2[9];
    for(int i=0; i<9; i++)
    {
            window2[i] = addPixmap(newImage2);
            window2[i]->setScale(0.15);
            window2[i]->setData(0, "Garden_Bed");
            window2[i]->setFlags(QGraphicsItem::ItemIsMovable);
    }

    window2[0]->setPos(125,255); window2[1]->setPos(165,255); window2[2]->setPos(205,255);
    window2[3]->setPos(125,335); window2[4]->setPos(165,335); window2[5]->setPos(205,335);
    window2[6]->setPos(125,415); window2[7]->setPos(165,415); window2[8]->setPos(205,415);

//РЕДИС
    QPixmap newImage3;
    if (!newImage3.load("C:/Users/ivanl/Documents/redis.png"))return;
    QGraphicsPixmapItem* window3[18];
    for(int i=0; i<18; i++)
    {
            window3[i] = addPixmap(newImage3);
            window3[i]->setScale(0.15);
            window3[i]->setData(0, "Garden_Bed");
            window3[i]->setFlags(QGraphicsItem::ItemIsMovable);
    }

    window3[0]->setPos(278,255); window3[1]->setPos(318,255); window3[2]->setPos(358,255);
    window3[3]->setPos(278,295); window3[4]->setPos(318,295); window3[5]->setPos(358,295);
    window3[6]->setPos(278,335); window3[7]->setPos(318,335); window3[8]->setPos(358,335);
    window3[9]->setPos(278,375); window3[10]->setPos(318,375); window3[11]->setPos(358,375);
    window3[12]->setPos(278,415); window3[13]->setPos(318,415); window3[14]->setPos(358,415);
    window3[15]->setPos(278,455); window3[16]->setPos(318,455); window3[17]->setPos(358,455);

    if (!newImage.load(QCoreApplication::applicationDirPath()+"/../../lab7/crow.png"))return;
    crow =addPixmap(newImage);
    crow->setScale(0.15);
    crow->setPos(600, 300);
    crow->setFlags(QGraphicsItem::ItemIsMovable);

    walls[0] = addRect(QRectF(0, 0, 6, 513), QPen(Qt::black), QBrush(QColor(86, 122, 72)));
    walls[1] = addRect(QRectF(800, 0, 6, 513), QPen(Qt::black), QBrush(QColor(86, 122, 72)));
    walls[2] = addRect(QRectF(0, 0, 800, 6), QPen(Qt::black), QBrush(QColor(86, 122, 72)));
    walls[3] = addRect(QRectF(0, 513, 806, 6), QPen(Qt::black), QBrush(QColor(86, 122, 72)));


    dx = 1;
    dy = 1;
    speed = 1; //скорость вороны
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MoveCrow()));
    timer->start(6);

}



