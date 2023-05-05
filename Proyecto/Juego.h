#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include "Jugador.h"
#include <windows.h>

class Juego: public QGraphicsView
{
    Q_OBJECT
public:
    Juego(QWidget *parent = NULL );
    QGraphicsScene *Pantalla;
    Jugador *Player;
private:
    QTimer *Timer;
    void keyPressEvent(QKeyEvent *evento);
private slots:
    void MoverJugador();
};

#endif // JUEGO_H
