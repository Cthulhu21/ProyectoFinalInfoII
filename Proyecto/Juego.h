#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include "Jugador.h"

class Juego: public QGraphicsView
{
    Q_OBJECT
public:
    Juego(QWidget *parent = NULL );
    QGraphicsScene *Pantalla;
    Jugador *Player;
};

#endif // JUEGO_H
