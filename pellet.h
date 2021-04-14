#ifndef PELLET_H
#define PELLET_H
#include<QGraphicsPixmapItem>

class pellet :public QGraphicsPixmapItem
{
private:
    int c,  r;
public:
    pellet(int, int);
};

#endif // PELLET_H
