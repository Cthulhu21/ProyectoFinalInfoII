#include "Arma.h"

Arma::Arma()
{
    CargarSprite();
    TipoDeDisparo=Atractivo;
    Activa=false;
}

Arma::~Arma()
{

}

void Arma::CrearZona(QGraphicsScene *Escena)
{
    if(!Activa)
    {
        Activa=true;
        RangoArma = new ZonaGravitacional(1000, rotation(), pos(), 1000, 20);
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
    {
        RangoArma->setRotation(Angulo);
    }
}

void Arma::SetPos(QPointF Pos)
{
    setPos(Pos);
    if(Activa)
    {
        RangoArma->setPos({0,0});
    }
 }

void Arma::CargarSprite()
{
    setPixmap(QPixmap(":/Armas/1").transformed(QTransform().scale(0.05,0.05)));
}

ZonaGravitacional *Arma::getRangoArma() const
{
    return RangoArma;
}
