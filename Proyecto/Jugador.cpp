#include "Jugador.h"

Jugador::Jugador(QGraphicsItem *parent)
{
    VelocidadX=10;
    VelocidadY=0;
    Delta =0.01;
    setPixmap(QPixmap(":/Imagenes/Pacman").transformed(QTransform().scale(0.025,0.025)));
    setPos(962.5-22.56,947.7-51.44*0.5);
    PosX=this->x();
    PosY=this->y();
}

void Jugador::AplicarMovimiento()
{
    // Se actualizan los datos de posicion

    PosX += VelocidadX*Delta;
    PosY += VelocidadY*Delta;

    setPos(PosX, PosY);
}

void Jugador::CambiarDireccion(int Tecla)
{
    switch(Tecla)
    {
    case Qt::Key_W:
        VelocidadY=-10;
        VelocidadX=0;
        break;
    case Qt::Key_A:
        VelocidadX=-10;
        VelocidadY=0;
        break;
    case Qt::Key_S:
        VelocidadY=10;
        VelocidadX=0;
        break;
    case Qt::Key_D:
        VelocidadX=10;
        VelocidadY=0;
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
