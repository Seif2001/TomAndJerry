#ifndef MOUSE_H
#define MOUSE_H
#include "player.h"
#include "cheese.h"
#include"plate.h"
#include"cat.h"
#include "cheese.h"
#include "pellet.h"
class mouse: public player
{
private:
    int mo,seif;
    QString jUp = "jerryU.png";
    QString jDown = "jerryD.png";
    QString jRight = "jerryR.png";
    QString jLeft = "jerryL.png";
    QString jCUp = "cjerryU.png";
    QString jCDown = "cjerryD.png";
    QString jCRight = "cjerryR.png";
    QString jCLeft = "cjerryL.png";
    int score =0;
    bool hasCheese;
    int lives;
    cheese c1;
    cheese c2;
    cheese c3;
    cheese c4;
    cheese* cHas;
    bool isInvisible;
public:
    void resetToOriginal() ;
    mouse(int, int, int data[16][14]);
    QGraphicsPixmapItem* addbox();
    void addCheeses();

private slots:
   void keyPressEvent(QKeyEvent *event);
    void removeInvisbility();
};

#endif // MOUSE_H
