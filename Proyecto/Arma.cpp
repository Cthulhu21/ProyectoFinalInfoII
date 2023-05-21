#include "Arma.h"

Arma::Arma()
{
    CargarSprite();
    TipoDeDisparo=Atractivo;
    Activa=false;
}

<<<<<<< Updated upstream
=======
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
        /*
        // Calcular la nueva posición relativa en función de la rotación
        qreal distancia = 0; // Distancia entre el arma principal y RangoArma (ajusta este valor según sea necesario)
        qreal radians = qDegreesToRadians(Angulo);
        qreal dx = distancia * qCos(radians);
        qreal dy = distancia * qSin(radians);
        QPointF nuevaPos = mapToParent(QPointF(dx, dy));

        // Establecer la nueva posición de RangoArma
        RangoArma->setPos(nuevaPos);
        RangoArma->setRotation(Angulo);*/
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

>>>>>>> Stashed changes
void Arma::CargarSprite()
{
    setPixmap(QPixmap(":/Armas/1").transformed(QTransform().scale(0.05,0.05)));
}

ZonaGravitacional *Arma::getRangoArma() const
{
    return RangoArma;
}
