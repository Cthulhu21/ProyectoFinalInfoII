#include "Enemigo.h"

Enemigo::Enemigo(float PosX_, float PosY_, QGraphicsItem *parent)
{
    VelocidadX=Velocidad;
    VelocidadY=0;
    Direccion=0;


    PosX=PosX_;
    PosY=PosY_;
    Rectangulo = new QGraphicsRectItem(PosX,PosY,26,29);
    SetPos(PosX,PosY);

    CargarSprites();
    FrameActual = 0;
    setPixmap(Sprites[FrameActual]);

}

void Enemigo::Mover()
{
    PosX += VelocidadX*Delta;
    PosY += VelocidadY*Delta;

    SetPos(PosX, PosY);
    if(this->pos().x()<-26)
    {
        SetPos(2000,this->y());
    }
    else if(this->pos().x()>2500)
    {
        SetPos(-26,this->y());
    }
}

void Enemigo::SetPos(float X, float Y)
{
    this->setPos(X,Y);
    PosX=X;
    PosY=Y;
    Rectangulo->setRect(X,Y,26,29);
}

void Enemigo::CargarSprites()
{
    for(int i=0; i<3; i++)
    {
        Sprites.append(QPixmap(":/Imagenes/Fantasma").copy(0,29*i,26,29));
    }
}

QGraphicsRectItem *Enemigo::getRectangulo() const
{
    return Rectangulo;
}

void Enemigo::SiguienteFrame()
{
    setPixmap(Sprites[FrameActual++%Sprites.size()]);
    /*if(FrameActual>Sprites.size()-1)
    {
        FrameActual=0;
    }*/
}

Enemigo::~Enemigo()
{

}

void Enemigo::CambiarDireccion()
{
    //do
    Direccion=rand()%4;
    //}while(Direccion%4);
    switch(Direccion)
    {
    case 0:
        VelocidadY=0;
        VelocidadX=Velocidad;
        break;
    case 1:
        VelocidadX=0;
        VelocidadY=-Velocidad;
        break;
    case 2:
        VelocidadY=0;
        VelocidadX=-Velocidad;
        break;
    case 3:
        VelocidadX=0;
        VelocidadY=Velocidad;
        break;
    default:
        break;
    }
}
