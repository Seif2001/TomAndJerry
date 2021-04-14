#include "cat.h"
cat::cat(int x, int y, int bData[16][14])
{
    row = y;
    column = x;
    //setting image
QPixmap img(tRight);
  img = img.scaledToWidth(50);
img = img.scaledToHeight(50);
setPixmap(img);
direction =0;
for(int i = 0; i<16; i++){
    for(int j =0; j<14; j++){
        data[i][j] = bData[i][j];
    }
}

//setting pos
setPos(50+(50*column), 50+(50*row));
}

void cat::move()
{

    if(data[row-1][column]==-1 || data[row+1][column]==-1 || data[row][column+1]==-1 || data[row][column -1]==-1){
        direction=rand()%4;
    }
    if(direction == 0 && data[row-1][column]!=-1){
        row--;
        setCatDirection(tUp);
        direction =0;
    }
    else if(direction == 1 && data[row+1][column]!=-1){
        row++;
        this->setCatDirection(tDown);
        direction =1;

    }
    else if(direction == 2 && data[row][column-1]!=-1){
        column--;
        direction =2;

        setCatDirection(tLeft);


    }
    else if(direction == 3 && data[row][column+1]!=-1){
         column++;
direction =3;

             setCatDirection(tRight);
    }


 setPos(50+(50*column), 50+(50*row));
 QList<QGraphicsItem*> items = collidingItems();
 for(int i =0; i<items.size(); i++){
    if((typeid(*items[i]) == typeid(mouse) )){

    }
 }
}

void cat::setCatDirection(QString imageDir)
{
 QPixmap img(imageDir);
 img = img.scaledToWidth(50);
 img = img.scaledToHeight(50);
 setPixmap(img);
}
