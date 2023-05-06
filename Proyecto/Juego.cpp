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

    Player = new Jugador;
    Pantalla->addItem(Player);

    Fantasma = new Enemigo;
    Pantalla->addItem(Fantasma);

    Pared = new Paredes;
    Pantalla->addItem(Pared);

    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()),this,SLOT(Actualizar()));
    Timer->start(1);

    TimerAnimaciones = new QTimer;
    connect(TimerAnimaciones, SIGNAL(timeout()), this, SLOT(ActualizarFrames()));
    TimerAnimaciones->start(100);
}

Juego::~Juego()
{

}

void Juego::keyPressEvent(QKeyEvent *evento)
{
    switch(evento->key())
    {
    case Qt::Key_W:
    case Qt::Key_A:
    case Qt::Key_S:
    case Qt::Key_D:
        Player->CambiarDireccion(evento->key());
        break;

    default:
        break;
    }
}

void Juego::Actualizar()
{
    //Mueve al jugador
    {
        const float PosX_=Player->getPosX(), PosY_=Player->getPosY();
        Player->AplicarMovimiento();
        if(Player->getRectangulo()->collidesWithItem(Pared))
        {
            Player->SetPos(PosX_,PosY_);
        }
    }
    //Mover a los fantasmas
    {
        QPointF Posicion = Fantasma->pos();
        Fantasma->Mover();
        if(Fantasma->collidesWithItem(Pared))
        {
            Fantasma->SetPos(Posicion.x(), Posicion.y());
            Fantasma->CambiarDireccion();
        }
    }
}

void Juego::ActualizarFrames()
{
    //Jugador
    {
        Player->SiguienteFrame();
    }
    //Enemigo
    {
        Fantasma->SiguienteFrame();
    }
}
