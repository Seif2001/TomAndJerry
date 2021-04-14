#include "mouse.h"

mouse::mouse(int x, int y, int bData[16][14]): player(x,y,bData)
{
    //setting image
 mo =y;
 seif=x;
QPixmap img(jRight);
img = img.scaledToWidth(50);
img = img.scaledToHeight(50);
setPixmap(img);
score =0;
hasCheese = false;
isInvisible = false;
lives = 4;
cHas = NULL;
//setting pos
setPos(50+(50*column), 50+(50*row));
}

void mouse::addCheeses()
{
   c1.setColumn(1);
   c1.setRow(14);
   c2.setColumn(12);
   c2.setRow(1);
   c3.setColumn(12);
   c3.setRow(14);
   c4.setColumn(3);
   c4.setRow(3);
   scene()->addItem(&c1);
   scene()->addItem(&c2);
   scene()->addItem(&c3);
   scene()->addItem(&c4);
}

void mouse::removeInvisbility()
{
    if(isInvisible){
    isInvisible = false;
    }
}


void mouse::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up && data[row-1][column]!=-1){
        row--;
        direction =1;
        if(hasCheese == false){
        this->setPlayerDirection(jUp);
        }else{
            this->setPlayerDirection(jCUp);
        }
    }
    else if(event->key() == Qt::Key_Down && data[row+1][column]!=-1){
        row++;
         direction =2;
         if(hasCheese == false){
             this->setPlayerDirection(jDown);
         }else{
             this->setPlayerDirection(jCDown);
         }

    }
    else if(event->key() == Qt::Key_Left && data[row][column-1]!=-1){
        column--;
         direction =3;
         if(hasCheese == false){
             this->setPlayerDirection(jLeft);
         }else{
             this->setPlayerDirection(jCLeft);
         }

    }
    else if(event->key() == Qt::Key_Right && data[row][column+1]!=-1){
         column++;
         direction =4;
         if(hasCheese == false){
             this->setPlayerDirection(jRight);
         }else{
             this->setPlayerDirection(jCRight);
         }

    }
    setPos(50+(50*column), 50+(50*row));
    QList<QGraphicsItem*> items = collidingItems();
    for(int i =0; i<items.size(); i++){
        if(typeid(*items[i]) == typeid(pellet)){
            scene()->removeItem(items[i]);
            isInvisible = true;
        }
        if(items[i] == &c1 && hasCheese ==false){
            cHas = &c1;
            scene()->removeItem(items[i]);
            hasCheese = true;
        }
        if(items[i] == &c2 && hasCheese ==false){
            cHas = &c2;
            scene()->removeItem(items[i]);
            hasCheese = true;
        }
        if(items[i] == &c3 && hasCheese ==false){
            cHas = &c3;
            scene()->removeItem(items[i]);
            hasCheese = true;
        }
        if(items[i] == &c4 && hasCheese ==false){
            cHas = &c4;
            scene()->removeItem(items[i]);
            hasCheese = true;
        }
        if(typeid(*items[i]) == typeid(plate) && hasCheese ==true){
            hasCheese = false;
            cHas = NULL;
            score++;
        }
        if((typeid(*items[i]) == typeid(cat) && !isInvisible )){
                lives--;

            resetToOriginal();
        }

    }

}
void mouse::resetToOriginal() {
    if(hasCheese && cHas!=NULL){
        hasCheese=false;
        cHas->returnToOriginal();
        scene()->addItem(cHas);
    }
    row=mo;
    column=seif;
    setPos(50+(50*seif), 50+(50*mo));
}

