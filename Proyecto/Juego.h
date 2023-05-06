#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <windows.h>

#include "Jugador.h"
#include "Paredes.h"

class Juego: public QGraphicsView
{
    Q_OBJECT
public:
    Juego(QWidget *parent = NULL );
    ~Juego();
private:
    QTimer *Timer;
    void keyPressEvent(QKeyEvent *evento);
    QGraphicsScene *Pantalla;
    Jugador *Player;
    Paredes *Pared;

private slots:
    void Actualizar();
};

#endif // JUEGO_H
