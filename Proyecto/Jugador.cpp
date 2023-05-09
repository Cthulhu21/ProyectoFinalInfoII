#include "Jugador.h"

Jugador::Jugador(float PosX_, float PosY_, QGraphicsItem *parent)
{
    Direccion=0;
    VelocidadX=Velocidad;
    VelocidadY=0;
    PosX=PosX_;
    PosY=PosY_;
    Rectangulo = new QGraphicsRectItem(0,0,32,31);
    setPos(PosX,PosY);
    Invencible=true;
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

    SetPos(PosX, PosY);
    if(this->pos().x()<-32)
    {
        SetPos(2000,this->y());
    }
    else if(this->pos().x()>2000)
    {
        SetPos(-32,this->y());
    }
}

void Jugador::CambiarDireccion(int Tecla)
{
    switch(Tecla)
    {
    case Qt::Key_W:
        VelocidadY=-Velocidad;
        VelocidadX=0;
        Direccion=-90;
        break;
    case Qt::Key_A:
        VelocidadX=-Velocidad;
        VelocidadY=0;
        Direccion=-180;
        break;
    case Qt::Key_S:
        VelocidadY=Velocidad;
        VelocidadX=0;
        Direccion=90;
        break;
    case Qt::Key_D:
        VelocidadX=Velocidad;
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
    Rectangulo->setRect(X,Y,32,31);
}

Jugador::~Jugador()
{

}

bool Jugador::getInvencible() const
{
    return Invencible;
}

void Jugador::setInvencible(bool newInvencible)
{
    Invencible = newInvencible;
}

float Jugador::getPosX() const
{
    return PosX;
}

float Jugador::getPosY() const
{
    return PosY;
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

QGraphicsRectItem *Jugador::getRectangulo() const
{
    return Rectangulo;
}

void Jugador::SiguienteFrame()
{
    setPixmap(Sprites[FrameActual++%Sprites.size()].transformed(QTransform().rotate(Direccion)));
}
