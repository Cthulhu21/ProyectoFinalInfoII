#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <windows.h>

#include "Jugador.h"

class Juego: public QGraphicsView
{
    Q_OBJECT
public:
    Juego(QWidget *parent = nullptr);

    QGraphicsScene *Pantalla;
    void Jugar();

private:
    Jugador *Player;
};

#endif // JUEGO_H
