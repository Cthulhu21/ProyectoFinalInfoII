#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <windows.h>

#include "Jugador.h"
#include "ZonaGravitacional.h"

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
    QList<ZonaGravitacional*> *ZonasGravitacionales;

    void GameOver();

    unsigned int ContadorGlobal;

private slots:
    void Actualizar();
};

#endif // JUEGO_H
