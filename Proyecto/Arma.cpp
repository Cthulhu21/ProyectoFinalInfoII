#include "Arma.h"

Arma::Arma()
{
    CargarSprite();
    TipoDeDisparo=Atractivo;
    Activa=false;
    MoviblePegado=false;
    Size = {20,10};
    ObjetoPegado = new ObjetoMovible();
}

Arma::~Arma()
{

}

void Arma::CrearZona(QGraphicsScene *Escena)
{
    if(MoviblePegado)
        return;
    if(!Activa)
    {
        Activa=true;
        RangoArma = new ZonaRecta({Size.x(), Size.y()/2.7}, {1000,20}, 700, 0, 180, 0.3, true);
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
    MoverObjetoPegado();
}

void Arma::SetPos(QPointF Pos)
{
    setPos(Pos);
    MoverObjetoPegado();
}

void Arma::CargarSprite()
{
    setPixmap(QPixmap(":/Armas/1").transformed(QTransform().scale(0.05,0.05)));
}

ObjetoMovible *Arma::getObjetoPegado() const
{
    return ObjetoPegado;
}

void Arma::setObjetoPegado(ObjetoMovible *newObjetoPegado)
{
    ObjetoPegado = newObjetoPegado;
}

void Arma::MoverObjetoPegado()
{
    if(MoviblePegado)
    {
        qreal PosX=pos().x()+(Size.x()+10)*cos(rotation()*M_PI/180);
        qreal PosY=pos().y()+(Size.y()+25)*sin(rotation()*M_PI/180);
        ObjetoPegado->SetPos({PosX,PosY});
    }
}

QPointF Arma::getSize() const
{
    return Size;
}

ZonaRecta *Arma::getRangoArma() const
{
    return RangoArma;
}
