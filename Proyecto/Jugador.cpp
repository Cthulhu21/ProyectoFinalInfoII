#include "Jugador.h"

Jugador::Jugador(float PosX_, float PosY_, QGraphicsItem *parent)
{

    Direccion=0;
    VelocidadX=0;
    VelocidadY=0;
    AceleracionX=0;
    AceleracionY=0;

    PosX=PosX_;
    PosY=PosY_;

    Rectangulo = new QGraphicsRectItem(0,0,22,52);
    setPos(PosX,PosY);
    CargarSprites();
    FrameActual = 0;
    setPixmap(Sprites[FrameActual]);
}

void Jugador::Mover()
{
    PosX+=VelocidadX*Delta;
    VelocidadX-=AceleracionX*Delta;
    if(abs(VelocidadX)<0.1)
    {
        VelocidadX=0;
        AceleracionX=0;
    }
    AceleracionX*=KAire;

    PosY+=VelocidadY*Delta;//+(Gravedad+AceleracionY)*0.5*Delta*Delta;
    VelocidadY-=AceleracionY*Delta;
    if(abs(VelocidadY)<0.1)
    {
        VelocidadY=0;
        AceleracionY=0;
    }
    AceleracionY*=KAire;

    SetPos(PosX, PosY);
}


void Jugador::AplicarAceleracion(float AceleracionX_, float AceleracionY_)
{

    if(AceleracionX<AceleracionMaxima)
    {
        AceleracionX+=AceleracionX_;
        VelocidadX=AceleracionX*Delta;
    }
    if(AceleracionY<AceleracionMaxima)
    {
        AceleracionY+=AceleracionY_;
        VelocidadY=AceleracionY*Delta;
    }
}

void Jugador::SetPos(float X, float Y)
{
    this->setPos(X,Y);
    PosX=X;
    PosY=Y;
    Rectangulo->setRect(X,Y,22,52);
}

Jugador::~Jugador()
{

}

int Jugador::getMasa() const
{
    return Masa;
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
    for(int i=3; i<11; i++)
    {
        QString Ruta=":/Jugador/%1";
        Sprites.append(QPixmap(Ruta.arg(i)));
    }
}

QGraphicsRectItem *Jugador::getRectangulo() const
{
    return Rectangulo;
}

void Jugador::SiguienteFrame()
{
    FrameActual%=Sprites.size();
    setPixmap(Sprites[FrameActual++]);
}
