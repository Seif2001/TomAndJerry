#ifndef PLAYER_H
#define PLAYER_H
#include<QObject>
#include<QGraphicsPixmapItem>


class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
private:
    int row,column;
    int data[10][10];
public:
    Player(int irow,int icolumn,int x[10][10]);
};

#endif // PLAYER_H
