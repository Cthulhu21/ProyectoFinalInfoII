#include "Enemigo.h"

Enemigo::Enemigo()
{
    VelocidadX=9;
    VelocidadY=0;
    Delta =0.01;
    Direccion=0;

    setPos(0,450);
    PosX=this->x();
    PosY=this->y();
    CargarSprites();
    FrameActual = 0;
    setPixmap(Sprites[FrameActual]);
}

void Enemigo::Mover()
{
    PosX += VelocidadX*Delta;
    PosY += VelocidadY*Delta;

    setPos(PosX, PosY);
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
}

void Enemigo::CargarSprites()
{
    for(int i=0; i<3; i++)
    {
        Sprites.append(QPixmap(":/Imagenes/Fantasma").copy(0,29*i,26,29));
    }
}

void Enemigo::SiguienteFrame()
{
    setPixmap(Sprites[FrameActual++]);
    if(FrameActual>Sprites.size()-1)
    {
        FrameActual=0;
    }
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
        VelocidadX=9;
        break;
    case 1:
        VelocidadX=0;
        VelocidadY=-9;
        break;
    case 2:
        VelocidadY=0;
        VelocidadX=-9;
        break;
    case 3:
        VelocidadX=0;
        VelocidadY=9;
        break;
    default:
        break;
    }
}
