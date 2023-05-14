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
    Juego(QWidget *parent = NULL );
    void Jugar();
    ~Juego();
private:
    QTimer *Timer;

    void keyPressEvent(QKeyEvent *evento);

    QGraphicsScene *Pantalla;
    Jugador *Player;
    void GameOver();

    unsigned int ContadorGlobal;

private slots:
    void Actualizar();
};

#endif // JUEGO_H
