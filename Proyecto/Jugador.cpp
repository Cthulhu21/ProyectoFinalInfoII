#include "Jugador.h"

Jugador::Jugador(float PosX_, float PosY_, QGraphicsItem *parent)
{

    Direccion=0;
    VelocidadX=0;
    VelocidadY=0;
    AceleracionX=0;
    AceleracionY=0;
    VelocidadInicialY=0;
    C1=VelocidadY-Masa*Gravedad/(KAire*KAire);

    PosX=PosX_;
    PosY=PosY_;
    PosicionInicialY=PosY;
    C2=PosicionInicialY - C1/KAire;

    Rectangulo = new QGraphicsRectItem(0,0,32,31);
    setPos(PosX,PosY);
    CargarSprites();
    FrameActual = 0;
    setPixmap(Sprites[FrameActual]);
    //setPixmap(Sprites[0]).transformed(QTransform().scale(0.025,0.025)));
}

void Jugador::Mover()
{
    // Se actualizan los datos de posicion

    /*
    AceleracionX= AceleracionX - KAire*Delta;
    AceleracionY= AceleracionY - KAire*Delta;
    VelocidadX = VelocidadX + AceleracionX*Delta - KAire*Delta;
    VelocidadY+=AceleracionY*Delta;
    PosX += VelocidadX*Delta+AceleracionX*0.5*Delta*Delta;
    PosY += VelocidadY*Delta+AceleracionY*0.5*Delta*Delta;
    */
    //C1=VelocidadY-Masa*Gravedad/KAire;
    if(PosY<900+52)
    {
        AceleracionY*=KAire;
        VelocidadY=VelocidadY+AceleracionY*Delta;
        PosY=PosY+Delta*VelocidadY+(Gravedad+AceleracionY)*0.5*Delta*Delta;
    }
    AceleracionX*=KAire;
    VelocidadX=VelocidadX-AceleracionX*Delta;
    PosX=PosX+Delta*VelocidadX;
    SetPos(PosX, PosY);
}


void Jugador::AplicarAceleracion(float AceleracionX_, float AceleracionY_)
{

    AceleracionX+=AceleracionX_;
    AceleracionY=AceleracionY_;
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
    for(int i=0; i<24; i++)
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
