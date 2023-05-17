#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <windows.h>
#include <QMouseEvent>

#include "Jugador.h"
#include "ZonaGravitacional.h"
#include "ObjetoMovible.h"
#include "Plataforma.h"

#define PI 3.14159265

class Juego: public QGraphicsView
{
    Q_OBJECT
public:
    Juego(QWidget *parent = NULL );
    ~Juego();
    void Jugar();

private:
    QTimer *Timer;

    void keyPressEvent(QKeyEvent *evento);

    QGraphicsScene *Pantalla;
    Jugador *Player;
    QList<ZonaGravitacional*> *ZonasGravitacionales;
    void InteraccionZonas(ZonaGravitacional *Zona, ObjetoMovible *Objeto);
    QList<ObjetoMovible*> *Objetos;
    QList<ObjetoEstatico*> *ObjetosEstaticos;

    void GameOver();

    void CalcularPosicion(ZonaGravitacional *Zona, ObjetoMovible *Objeto, float *X, float *Y);
    bool VerificarLimites(QRectF *Borde);

    unsigned int ContadorGlobal;
    int PantallaSizeX;
    int PantallaSizeY;

    QRectF *Borde;

    const float Delta=0.1;

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void Actualizar();
};

#endif // JUEGO_H
