#include <QApplication>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QFile>
#include<QTextStream>
#include<QGraphicsPixmapItem>
#include"player.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene;
    view.setWindowTitle("Tom and Jerry Board Game");
    view.setFixedSize(600,600);
    view.setBackgroundBrush(QBrush(Qt::white));
    int array[10][10];
    QFile fin("Board.txt");
    fin.open(QIODevice::ReadOnly);
    QTextStream stream(&fin);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            stream>>array[i][j];
        }
    }
    QPixmap bricks("BGB.jpg");
    bricks=bricks.scaledToHeight(50);
    bricks=bricks.scaledToWidth(50);
    QPixmap border("WHITEBRICK.png");
    border=border.scaledToHeight(50);
    border=border.scaledToWidth(50);
    QGraphicsPixmapItem boards[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(array[i][j]==-1)
            {
                boards[i][j].setPixmap(bricks);
                boards[i][j].setPos(50+(50*j),50+(50*i));
            }
            else
            {
                boards[i][j].setPixmap(border);
                boards[i][j].setPos(50+(50*j),50+(50*i));
            }
            scene.addItem(&boards[i][j]);
        }
    }
    Player x1(1,1,array);
    scene.addItem(&x1);



    view.setScene(&scene);
    view.show();

    return a.exec();
}
