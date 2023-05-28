#include "ObjetoMovible.h"

ObjetoMovible::ObjetoMovible(TipoDeObjeto Tipo_, int Masa_, QPointF Pos,
                             QPointF Vel,QPointF Acel,
                             float VelMax, float Fric, QGraphicsItem *parent)
{
    Tipo=Tipo_;

    Masa=Masa_;

    setPos(Pos);

    Size = new QPointF();

    Posicion= new QPointF(Pos);
    Velocidad = new QPointF(Vel);
    Aceleracion= new QPointF(Acel);


    ObjetoPegado=false;

    VelocidadMax=VelMax;

    Friccion=Fric;

    CargarSprites();
    setParentItem(parent);
}

ObjetoMovible::ObjetoMovible(const ObjetoMovible &Otro):
    ObjetoMovible(Otro.Tipo, Otro.Masa, *Otro.Posicion, *Otro.Velocidad, *Otro.Aceleracion, Otro.VelocidadMax, Otro.Friccion)
{
}

ObjetoMovible::ObjetoMovible()
{

}


ObjetoMovible::~ObjetoMovible()
{

}


void ObjetoMovible::SetPos(QPointF Pos)
{
    *Posicion=Pos;
    setPos(Pos);
}

void ObjetoMovible::SiguienteFrame()
{
    setPixmap(Sprites[FrameActual++]);
    FrameActual%=Sprites.size();
}

QRectF ObjetoMovible::boundingRect() const
{
    return QRectF(QPointF(), *Size);
}

void ObjetoMovible::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(QPointF(), Sprites.at(FrameActual));
}

int ObjetoMovible::getMasa() const
{
    return Masa;
}

TipoDeObjeto ObjetoMovible::getTipo() const
{
    return Tipo;
}

QPointF *ObjetoMovible::getSize() const
{
    return Size;
}

void ObjetoMovible::CargarSprites()
{
    switch(Tipo)
    {
    case Controlable:

        for(int i=3; i<4; i++)//11 para el sprite completo
        {
            QString Ruta=":/Jugador/%1";
            QPixmap *Map = new QPixmap((Ruta.arg(i)));;
            Sprites.append(QPixmap(*Map));

        }
        *Size = {30,60};
        break;
    case Cubo:
        Sprites.append(QPixmap(":/Imagenes/Cubo"));
        *Size={30,31};
        break;
    default:
        break;
    }
    FrameActual=0;
    setPixmap(Sprites.at(FrameActual));
}
