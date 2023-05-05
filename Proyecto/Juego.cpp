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

    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()),this,SLOT(MoverJugador()));
    Timer->start(1);


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

void Juego::MoverJugador()
{
    Player->AplicarMovimiento();
}
