#ifndef CAT_H
#define CAT_H
#include "mouse.h"


class cat : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QString tUp = "tomU.png";
    QString tDown = "tomD.png";
    QString tLeft = "tomL.png";
    QString tRight = "tomR.png";
    int direction;
    int row, column;
    int data[16][14];

public:
   void setCatDirection(QString imageDir);
    cat(int x, int y, int bData[16][14]);
public slots:
    void move();
};

#endif // CAT_H
