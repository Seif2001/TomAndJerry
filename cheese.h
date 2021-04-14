#ifndef CHEESE_H
#define CHEESE_H
#include<QGraphicsPixmapItem>

class cheese: public QGraphicsPixmapItem
{
private:
int c,r;
bool inTheBox;
public:
    cheese();
    cheese(int, int);
    cheese(cheese&);
    void setRow(int);
    void setColumn(int);
    int getRow();
    int getColumn();
    void returnToOriginal();

};



#endif // CHEESE_H
