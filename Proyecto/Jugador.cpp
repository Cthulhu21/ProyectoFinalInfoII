#include "Jugador.h"

Jugador::Jugador(QGraphicsItem *parent)
{
    VelocidadX=10;
    VelocidadY=0;
    Delta =0.01;
    Direccion=0;

    setPos(962.5-22.56,947.7-51.44*0.5);
    PosX=this->x();
    PosY=this->y();
    CargarSprites();
    FrameActual = 0;
    setPixmap(Sprites[FrameActual]);
    //setPixmap(Sprites[0]).transformed(QTransform().scale(0.025,0.025)));
}

void Jugador::AplicarMovimiento()
{
    // Se actualizan los datos de posicion

    PosX += VelocidadX*Delta;
    PosY += VelocidadY*Delta;

    setPos(PosX, PosY);
    if(this->pos().x()<-32)
    {
        SetPos(2000,this->y());
    }
}

void Jugador::CambiarDireccion(int Tecla)
{
    switch(Tecla)
    {
    case Qt::Key_W:
        VelocidadY=-10;
        VelocidadX=0;
        Direccion=-90;
        break;
    case Qt::Key_A:
        VelocidadX=-10;
        VelocidadY=0;
        Direccion=-180;
        break;
    case Qt::Key_S:
        VelocidadY=10;
        VelocidadX=0;
        Direccion=90;
        break;
    case Qt::Key_D:
        VelocidadX=10;
        VelocidadY=0;
        Direccion=0;
        break;
    default:
        break;
    }
}

void Jugador::SetPos(float X, float Y)
{
    this->setPos(X,Y);
    PosX=X;
    PosY=Y;
}

Jugador::~Jugador()
{

}

void Jugador::CargarSprites()
{
    for(int i=0; i<6; i++)
    {
        Sprites.append(QPixmap(":/Imagenes/SpritesPacman").copy(0,31*i,32,31));
    }
    for(int i=4; i>=0; i--)
    {
        Sprites.append(QPixmap(":/Imagenes/SpritesPacman").copy(0,31*i,32,31));
    }
}

void Jugador::SiguienteFrame()
{
    setPixmap(Sprites[FrameActual++].transformed(QTransform().rotate(Direccion)));
    if(FrameActual>Sprites.size()-1)
    {
        FrameActual=0;
    }
}
