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
}

ObjetoMovible::~ObjetoMovible()
{

}

QRectF ObjetoMovible::boundingRect() const
{
    return QRectF(QPointF(), *Size);
}

void ObjetoMovible::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(QPointF(), Sprites.at(FrameActual));
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

int ObjetoMovible::getMasa() const
{
    return Masa;
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
        *Size = {30,55};
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
