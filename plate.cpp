#include "plate.h"

plate::plate()
{
    QPixmap img("plate0.png");
    img = img.scaledToHeight(100);
    img = img.scaledToWidth(100);
    setPixmap(img);
    setPos(350, 410);
}
