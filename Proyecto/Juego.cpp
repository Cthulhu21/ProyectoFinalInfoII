#include "Juego.h"

Juego::Juego(QWidget *parent)
{
    Pantalla = new QGraphicsScene;
    Pantalla->setSceneRect(0,0,200,200);
    setScene(Pantalla);
    Player = new Jugador;
    Pantalla->addItem(Player);
}
