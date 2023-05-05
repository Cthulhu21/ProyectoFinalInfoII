#include "Jugador.h"

Jugador::Jugador(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/Imagenes/Pacman").transformed(QTransform().scale(0.1,0.1)));
}
