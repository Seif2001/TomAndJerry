
#include <QGraphicsView>
#include <QGraphicsScene>
#include<QGraphicsItem>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include<QTimer>
#include "plate.h"
#include "player.h"
#include"mouse.h"
#include"cat.h"
#include "pellet.h"
#include"cheese.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene;

    view.setWindowTitle("Tom and Jerry");
    view.setBackgroundBrush(QBrush(Qt::blue));
    view.setFixedSize(800,900);

    int boardData[16][14];
    QFile file("Board.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    for(int i = 0; i<16; i++){
        for(int j =0; j<14; j++){
            stream>>boardData[i][j];
        }
    }
    QPixmap q1("wall.png");
    q1 = q1.scaledToHeight(50);
    q1 = q1.scaledToWidth(50);
    QPixmap q2("grass.png");
    q2 = q2.scaledToHeight(50);
    q2 = q2.scaledToWidth(50);
    QGraphicsPixmapItem boardImages[16][14];
    for(int i = 0; i<16; i++){
        for(int j =0; j<14; j++){
            if(boardData[i][j] == -1){
                boardImages[i][j].setPixmap(q1);
            }
            else{
                boardImages[i][j].setPixmap(q2);

            }
            boardImages[i][j].setPos(50+(50*j),50+(50*i));
            scene.addItem(&boardImages[i][j]);
        }
    }



    cat tom(5,8,boardData);
    mouse jerry(1,1,boardData);

    scene.addItem(&tom);
    QTimer t1;
    t1.start(100);


    t1.connect(&t1,SIGNAL(timeout()),&tom,SLOT(move()));

    QTimer t2;
    t2.setSingleShot(true);
    t2.singleShot(5000,  &jerry,SLOT(removeInvisbility()));
    pellet p1(6,6);
    pellet p2(12,4);
    scene.addItem(&jerry);
    jerry.addCheeses();
    plate box;
    scene.addItem(&box);
scene.addItem(&p1);
scene.addItem(&p2);
    jerry.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    jerry.setFocus();
    view.setScene(&scene);
    view.show();
    return a.exec();
}
