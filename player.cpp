#include "player.h"

Player::Player(int irow,int icolumn,int x[10][10])
{
for(int i=0;i<10;i++)
{
    for(int j=0;j<10;j++)
    {
        data[i][j]=x[i][j];
    }
}
row=irow;
column=icolumn;
QPixmap jerry("jerry cheese.png");
jerry=jerry.scaledToWidth(50);
jerry=jerry.scaledToHeight(50);
setPixmap(jerry);
setPos(50 +(50*column),50+(50*row));
}
