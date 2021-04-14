#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include<string>
#include<QGraphicsScene>
class player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    int row, column;
    int data[16][14];

    int direction;

public:
    player(int, int, int[16][14]);
    void setRow(int);
    void setColumn(int);
    int getRow();
    int getColumn();
    void setPlayerDirection(QString);


};

#endif // PLAYER_H
