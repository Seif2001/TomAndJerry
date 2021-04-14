#include "cheese.h"

cheese::cheese()
{
    inTheBox = false;
    c=0;
    r=0;
    QPixmap img("cheese.png");
    img = img.scaledToHeight(50);
    img = img.scaledToWidth(50);
    setPixmap(img);
    setPos(50+(50*c), 50+(50*r));
}

cheese::cheese(int inRow, int inColumn)
{
inTheBox = false;
c=inColumn;
r=inRow;
QPixmap img("cheese.png");
img = img.scaledToHeight(50);
img = img.scaledToWidth(50);
setPixmap(img);
setPos(50+(50*c), 50+(50*r));

}

cheese::cheese(cheese & cheese)
{
    c = cheese.getColumn();
    r = cheese.getRow();
    QPixmap img("cheese.png");
    img = img.scaledToHeight(50);
    img = img.scaledToWidth(50);
    setPixmap(img);
    setPos(50+(50*c), 50+(50*r));
}

void cheese::setRow(int nRow)
{
    r=nRow;
        setPos(50+(50*c), 50+(50*r));
}

void cheese::setColumn(int nCol)
{
    c = nCol;
        setPos(50+(50*c), 50+(50*r));
}


int cheese::getColumn()
{
    return c;

}

void cheese::returnToOriginal()
{
    setPos(50+(50*c), 50+(50*r));

}

int cheese::getRow()
{
    return r;
}



