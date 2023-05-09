#include "Comestible.h"

Comestible::Comestible(unsigned int Sprite, float PosX, float PosY)
{
    if(Sprite==0)
    {
        Fruta=true;
    }
    setPixmap(QPixmap(":/Imagenes/Comestibles").copy(0,90*Sprite,84,90).transformed(QTransform().scale(0.5,0.5)));
    setPos(PosX, PosY);
}

Comestible::~Comestible()
{

}
