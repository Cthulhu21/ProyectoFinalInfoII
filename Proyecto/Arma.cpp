#include "Arma.h"

Arma::Arma()
{
    CargarSprite();
    TipoDeDisparo=Atractivo;
    Activa=false;
    Size = {20,10};
}

Arma::~Arma()
{

}

void Arma::CrearZona(QGraphicsScene *Escena)
{
    if(!Activa)
    {
        Activa=true;
        RangoArma = new ZonaGravitacional(1000, 0, 180, {Size.x(),Size.y()/2}, 1000, 20,0.1);
        RangoArma->setParentItem(this);
        Escena->addItem(RangoArma);
    }
    else
    {
        Activa=false;
        Escena->removeItem(RangoArma);
        delete RangoArma;
    }
}

void Arma::Rotar(qreal Angulo)
{
    setRotation(Angulo);
    if(Activa)
        RangoArma->DireccionFuerza=Angulo+180;
}

void Arma::SetPos(QPointF Pos)
{
    setPos(Pos);
}

void Arma::CargarSprite()
{
    setPixmap(QPixmap(":/Armas/1").transformed(QTransform().scale(0.05,0.05)));
}

QPointF Arma::getSize() const
{
    return Size;
}

ZonaGravitacional *Arma::getRangoArma() const
{
    return RangoArma;
}
