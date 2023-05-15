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
    //setBackgroundBrush(QBrush(Qt::black));
}

void Juego::Jugar()
{
    ContadorGlobal=0;

    ZonasGravitacionales = new QList<ZonaGravitacional*>;
    //ZonasGravitacionales->append(new ZonaGravitacional(1000,0,400,200,800,200,0.5));
    //ZonasGravitacionales->append(new ZonaGravitacional(1000,45,810,400,100,20));
    ZonasGravitacionales->append(new ZonaGravitacional(100,90,3000,0,3000,3000,0.1));
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
        Player->setAceleracion(0, -AceleracionExtra);
        break;
    case Qt::Key_A:
        break;
    case Qt::Key_D:
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

void Juego::MoverJugador(ZonaGravitacional *Zona, Jugador *Player)
{
    float PosX=Player->PosX, PosY=Player->PosY;
    float VelX=Player->VelocidadX, VelY=Player->VelocidadY;
    float AcelX=Player->AceleracionX, AcelY=Player->AceleracionY;
    float Fuerza=Zona->getFuerzaGravitacional();
    float FuerzaX=Fuerza*cos(Zona->getRotacion()*PI/180), FuerzaY=Fuerza*sin(Zona->getRotacion()*PI/180);
    float AcelFueX=FuerzaX/Player->getMasa(), AcelFueY=FuerzaY/Player->getMasa();

    if(abs(FuerzaX)<0.1)
        FuerzaX=0;
    if(abs(FuerzaY)<0.1)
        FuerzaY=0;

    PosX+=VelX*Delta+Delta*Delta*0.5*(AcelFueX+AcelX);
    PosY+=VelY*Delta+Delta*Delta*0.5*(AcelFueY+AcelY);

    VelX+=FuerzaX/Player->getMasa()*Delta;
    VelY+=FuerzaY/Player->getMasa()*Delta;

    Player->setAceleracion(AcelX,AcelY);
    Player->AumentarVelocidad(VelX, VelY);
    Player->SetPos(PosX, PosY);
}

void Juego::ValidarPosicion(float X, float Y)
{
    if(Player->PosX>PantallaSizeX)
    {
        Player->SetPos(X, Player->PosY);
    }
    else if(Player->PosY>PantallaSizeY-120)
    {
        Player->SetPos(Player->PosX, Y);
    }
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
                float X=Player->PosX, Y=Player->PosY;
                MoverJugador(Zona, Player);
                ValidarPosicion(X, Y);
            }
        }
    }
}
