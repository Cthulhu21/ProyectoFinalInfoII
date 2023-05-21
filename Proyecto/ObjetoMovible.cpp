#include "ObjetoMovible.h"

ObjetoMovible::ObjetoMovible(TipoDeObjeto Tipo_, int Masa_, QPointF Pos,
                             QPointF Vel,QPointF Acel,
                             float VelMax, float Fric, QGraphicsItem *parent)
{
    Tipo=Tipo_;

    Masa=Masa_;

    setPos(Pos);
    CargarSprites();

    Posicion= new QPointF(Pos);
    Velocidad = new QPointF(Vel);
    Aceleracion= new QPointF(Acel);

    Size = new QPointF();

    VelocidadMax=VelMax;

    Friccion=Fric;
}


void ObjetoMovible::SetPos(QPointF Pos)
{
    *Posicion=Pos;
    setPos(Pos);
    Bordes->moveTo(Pos);
    //Bordes = new QRectF(x(),y(),Size[0], Size[1]);
}

void ObjetoMovible::SiguienteFrame()
{
    FrameActual%=Sprites.size();
    setPixmap(Sprites[FrameActual++]);
}

int ObjetoMovible::getMasa() const
{
    return Masa;
}

QRectF *ObjetoMovible::getBordes() const
{
    return Bordes;
}

void ObjetoMovible::CargarSprites()
{
    Bordes = new QRectF();
    switch(Tipo)
    {
    case Controlable:

        for(int i=3; i<11; i++)
        {
            QString Ruta=":/Jugador/%1";
            QPixmap *Map = new QPixmap((Ruta.arg(i)));
            QRectF RectSprite = Map->rect();
            Sprites.append(QPixmap(*Map));
            if(Bordes->isEmpty())
            {
                *Bordes = RectSprite;
            }
            else
            {
                *Bordes = RectSprite.united(RectSprite);
            }
        }
        break;
    case Cubo:
        Sprites.append(QPixmap(":/Imagenes/Cubo"));
        Bordes = new QRectF(x(),y(),29,30);
        break;
    default:
        break;
    }

    Bordes->moveTo(x(),y());
    FrameActual=0;
    setPixmap(Sprites.at(FrameActual));
}

void ObjetoMovible::AumentarVelocidad(float VelX, float VelY)
{
}

void ObjetoMovible::setAceleracion(float AcelX, float AcelY)
{
}
