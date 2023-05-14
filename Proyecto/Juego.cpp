#include "Juego.h"

Juego::Juego(QWidget *parent)
{
    //GetSystemMetrics(SM_CXSCREEN);
    Pantalla = new QGraphicsScene;
    Pantalla->setSceneRect(0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
    setFixedSize(GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(Pantalla);
    setBackgroundBrush(QBrush(Qt::black));
}

void Juego::Jugar()
{
    ContadorGlobal=0;

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
    int AceleracionExtra=1000;
    switch(evento->key())
    {
    case Qt::Key_W:
        Player->AplicarAceleracion(0,-AceleracionExtra);
        break;
    case Qt::Key_A:
        Player->AplicarAceleracion(-AceleracionExtra,0);
        break;
    case Qt::Key_D:
        Player->AplicarAceleracion(AceleracionExtra,0);
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
        float PosX=Player->getPosX(), PosY=Player->getPosY();
        Player->Mover();
        if(Player->getPosX()>GetSystemMetrics(SM_CXSCREEN))
        {
            Player->SetPos(PosX, Player->getPosY());
        }
        else if(Player->getPosY()>GetSystemMetrics(SM_CYSCREEN))
        {
            Player->setPos(Player->getPosX(), PosY);
        }

    }
}
