#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <windows.h>

#include "Jugador.h"
#include "ZonaGravitacional.h"

#define PI 3.14159265

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
    void CalcularPosicion(ZonaGravitacional *Zona, Jugador *Player, float *X, float *Y);

    unsigned int ContadorGlobal;
    int PantallaSizeX;
    int PantallaSizeY;

    QRectF *Borde;

    const float Delta=0.1;

private slots:
    void Actualizar();
};

#endif // JUEGO_H
