#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>

class Graphics : public QGraphicsScene
{
    Q_OBJECT
public:
    Graphics(QObject* parent= nullptr);
    QGraphicsItem* itemCollidesWith(QGraphicsItem* item);
private:
    QGraphicsRectItem* walls[4];
    QGraphicsPixmapItem* knight;

    int speed;
    double dx, dy;
public slots:
    void MoveKnight();
    void keyPressEvent(QKeyEvent* event);
};

#endif // GRAPHICS_H
