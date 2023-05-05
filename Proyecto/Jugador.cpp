#include "Jugador.h"

Jugador::Jugador(QGraphicsItem *parent)
{
    VelocidadX=10;
    VelocidadY=0;
    Angulo=0;
    AceleracionX=0;
    AceleracionY=0;
    Delta =0.01;
    Resistencia=0.08;
    setPixmap(QPixmap(":/Imagenes/Pacman").transformed(QTransform().scale(0.1,0.1)));
    PosX=this->x();
    PosY=this->y();
}

void Jugador::AplicarMovimiento()
{
    // Se actualizan los datos de posicion y velocidad

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
