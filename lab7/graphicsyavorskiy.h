#ifndef GRAPHICSYAVORSKIY_H
#define GRAPHICSYAVORSKIY_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>

class graphicsyavorskiy : public QGraphicsScene
{
    Q_OBJECT
public:
    graphicsyavorskiy(QObject* parent= nullptr);
    QGraphicsItem* itemCollidesWith(QGraphicsItem* item);

private:
    QGraphicsRectItem* walls[4];
    QGraphicsPixmapItem* crow;

    int speed;
    double dx, dy;

public slots:
    void MoveCrow();
    void keyPressEvent(QKeyEvent* event);
};

#endif // GRAPHICSYAVORSKIY_H
