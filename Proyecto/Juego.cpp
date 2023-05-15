#include "Juego.h"

Juego::Juego(QWidget *parent)
{
    //GetSystemMetrics(SM_CXSCREEN);
    Pantalla = new QGraphicsScene;
    PantallaSizeX=GetSystemMetrics(SM_CXSCREEN);
    PantallaSizeY=GetSystemMetrics(SM_CYSCREEN);
    Pantalla->setSceneRect(0,0,PantallaSizeX,PantallaSizeY);
    setFixedSize(PantallaSizeX,PantallaSizeY);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(Pantalla);
    Borde = new QRectF(0,0,Pantalla->sceneRect().width(),Pantalla->sceneRect().height()-120);
}

void Juego::Jugar()
{
    ContadorGlobal=0;

    ZonasGravitacionales = new QList<ZonaGravitacional*>;
    ZonasGravitacionales->append(new ZonaGravitacional(100,90,3000,0,3000,3000,0));
    for(int i=0; i<ZonasGravitacionales->size(); i++)
    {
        Pantalla->addItem(ZonasGravitacionales->at(i));
    }


    Player = new Jugador(810,300);
    Pantalla->addItem(Player);

    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()),this,SLOT(Actualizar()));

}

Juego::~Juego()
{

}

void Juego::keyPressEvent(QKeyEvent *evento)
{
    int AceleracionExtra=7000;
    switch(evento->key())
    {
    case Qt::Key_W:
        Player->setAceleracion(Player->AceleracionX, -AceleracionExtra);
        break;
    case Qt::Key_A:
        Player->setAceleracion(-AceleracionExtra*0.3,Player->AceleracionY);
        break;
    case Qt::Key_D:
        Player->setAceleracion(AceleracionExtra*0.3,Player->AceleracionY);
        break;
    case Qt::Key_Space:
        if(Timer->isActive())
            Timer->stop();
        else
            Timer->start(10);
        break;
    case Qt::Key_R:
        Pantalla->clear();
        delete Timer;
        Jugar();
        break;
    default:
        break;
    }
}

void Juego::GameOver()
{
    Pantalla->clear();
    Timer->stop();
    close();
}

void Juego::CalcularPosicion(ZonaGravitacional *Zona, Jugador *Player, float *X, float *Y)
{
    float PosX=Player->PosX, PosY=Player->PosY;
    float VelX=Player->VelocidadX, VelY=Player->VelocidadY;
    float AcelX=Player->AceleracionX, AcelY=Player->AceleracionY;
    float Fuerza=Zona->getFuerzaGravitacional();
    float FuerzaX=Fuerza*cos(Zona->getRotacion()*PI/180), FuerzaY=Fuerza*sin(Zona->getRotacion()*PI/180);
    float AcelFueX=FuerzaX/Player->getMasa(), AcelFueY=FuerzaY/Player->getMasa();

    if(abs(AcelFueX)<0.1)
        AcelFueX=0;
    if(abs(AcelFueY)<0.1)
        AcelFueY=0;

    PosX+=VelX*Delta+Delta*Delta*0.5*(AcelFueX+AcelX);
    PosY+=VelY*Delta+Delta*Delta*0.5*(AcelFueY+AcelY);

    VelX+=AcelFueX*Delta;
    VelY+=AcelFueY*Delta;

    if(abs(AcelX)<0.1)
    {
        AcelX=0;
    }
    if(abs(AcelY)<0.1)
    {
        AcelY=0;
    }
    Player->setAceleracion(AcelX,AcelY);
    Player->AumentarVelocidad(VelX, VelY);
    *X=PosX;
    *Y=PosY;
}

void Juego::Actualizar()
{
    ContadorGlobal+=1;
    ContadorGlobal%=10;
    //Actualizar el frame
    if(ContadorGlobal%5==0)
    {
        Player->SiguienteFrame();
    }
    {
        QList<QGraphicsItem*> Items=Player->collidingItems();
        for(QGraphicsItem *Item : Items)
        {
            ZonaGravitacional *Zona=dynamic_cast<ZonaGravitacional*>(Item);
            if(Zona)
            {
                float X0=Player->PosX, Y0=Player->PosY;
                float X, Y;
                CalcularPosicion(Zona, Player, &X, &Y);
                if(Borde->contains(X,Y))
                {
                    Player->SetPos(X,Y);
                }
                else
                {
                    Player->SetPos(X0,Y0);
                }
            }
        }
    }
}
