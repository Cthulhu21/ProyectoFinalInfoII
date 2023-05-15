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

    Pistola = new Arma();
    Pistola->setPos(PosX+15, PosY+10);

}

void Jugador::AumentarVelocidad(float VelX, float VelY)
{
    if(VelocidadX+VelX<=VelMax)
        VelocidadX+=VelX;
    if(VelocidadY+VelY<=VelMax)
        VelocidadY+=VelY;
}

void Jugador::setAceleracion(float AcelX, float AcelY)
{
    AceleracionX=AcelX*KAire;

    AceleracionY=AcelY*KAire;
}

void Jugador::SetPos(float X, float Y)
{
    this->setPos(X,Y);
    PosX=X;
    PosY=Y;
    Pistola->setPos(X+15, Y+10);
    Rectangulo->setRect(X,Y,22,52);
}

Jugador::~Jugador()
{

}

int Jugador::getMasa() const
{
    return Masa;
}

void Jugador::CargarSprites()
{
    for(int i=3; i<11; i++)
    {
        QString Ruta=":/Jugador/%1";
        Sprites.append(QPixmap(Ruta.arg(i)));
    }
}

Arma *Jugador::getPistola() const
{
    return Pistola;
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

void Jugador::AgregarArma(QGraphicsScene *Pantalla)
{
    Pantalla->addItem(Pistola);
}
