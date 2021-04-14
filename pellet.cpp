#include "pellet.h"

pellet::pellet( int x, int y)
{
    c=x;
    r=y;
    QPixmap img("pellet.png");
    img = img.scaledToHeight(50);
    img = img.scaledToWidth(50);
    setPixmap(img);
    setPos(50+(50*c), 50+(50*r));
}
