#include "ObjetoMovible.h"

ObjetoMovible::ObjetoMovible(int Masa_, QPointF Pos,
                             QPointF Size_, QPointF Vel,QPointF Acel,
                             float VelMax, float Fric, QGraphicsItem *parent)
{
    Masa=Masa_;

    setPos(Pos);

    Size = new QPointF(Size_);

    Posicion= new QPointF(Pos);
    Velocidad = new QPointF(Vel);
    Aceleracion= new QPointF(Acel);
    Sprites = new QList<QPixmap*>;


    ObjetoPegado=false;

    VelocidadMax=VelMax;

    Friccion=Fric;
    FrameActual=0;
}

ObjetoMovible::~ObjetoMovible()
{
    delete Size;
    delete Posicion;
    delete Velocidad;
    delete Aceleracion;
}


void ObjetoMovible::SetPos(QPointF Pos)
{
    *Posicion=Pos;
    setPos(Pos);
}

void ObjetoMovible::SiguienteFrame()
{

    setPixmap(*Sprites->at(FrameActual++));
    FrameActual%=Sprites->size();
}

QRectF ObjetoMovible::boundingRect() const
{
    return QRectF(QPointF(), *Size);
}

void ObjetoMovible::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(!Sprites->isEmpty())
        painter->drawPixmap(QPointF(), *Sprites->at(FrameActual));
}

int ObjetoMovible::getMasa() const
{
    return Masa;
}

void ObjetoMovible::CargarSprites()
{

}
