#include "ObjetoMovible.h"

ObjetoMovible::ObjetoMovible(TipoDeObjeto Tipo_, int Masa_, QPointF Pos,
                             QPointF Vel,QPointF Acel,
                             float VelMax, float Fric, QGraphicsItem *parent)
{
    Tipo=Tipo_;

    Masa=Masa_;

    setPos(Pos);

    Size = new QPointF();
    CargarSprites();

    Posicion= new QPointF(Pos);
    Velocidad = new QPointF(Vel);
    Aceleracion= new QPointF(Acel);



    VelocidadMax=VelMax;

    Friccion=Fric;
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
    FrameActual%=Sprites.size();
    setPixmap(Sprites[FrameActual++]);
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

        for(int i=3; i<11; i++)
        {
            QString Ruta=":/Jugador/%1";
            QPixmap *Map = new QPixmap((Ruta.arg(i)));;
            Sprites.append(QPixmap(*Map));

        }
        *Size = {25,55};
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
