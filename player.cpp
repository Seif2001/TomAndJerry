#include "player.h"

player::player(int iRow, int iColumn, int board[16][14])
{
    row = iRow;
    column = iColumn;
    for(int i = 0; i<16; i++){
        for(int j =0; j<14; j++){
            data[i][j] = board[i][j];
        }
    }

}

void player::setRow(int Row)
{
    row = Row;
}

void player::setColumn(int Column)
{
    column = Column;
}

int player::getRow()
{
    return row;
}

int player::getColumn()
{
    return column;
}

void player::setPlayerDirection(QString imageDir)
{
 QPixmap img(imageDir);
 img = img.scaledToWidth(50);
 img = img.scaledToHeight(50);
 setPixmap(img);
}


