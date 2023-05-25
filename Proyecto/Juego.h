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
#include "ZonaRadial.h"
#include "ZonaRecta.h"

#define PI 3.14159265

class Juego: public QGraphicsView
{
    Q_OBJECT
public:
    Juego(QWidget *parent = nullptr );
    ~Juego();
    void Jugar();

private:
    QTimer *Timer;
    QGraphicsScene *Pantalla;
    Jugador *Player;
    QList<ZonaGravitacional*> *ZonasGravitacionales;
    void InteraccionZonas(ZonaGravitacional *Zona, ObjetoMovible *Objeto);
    QList<ObjetoMovible*> *Objetos;
    QList<ObjetoEstatico*> *ObjetosEstaticos;

    void GameOver();
    void MomentoEnergia(ObjetoMovible *Objeto1, ObjetoMovible *Objeto2);

    unsigned int ContadorGlobal;
    int PantallaSizeX;
    int PantallaSizeY;
    const float Delta=0.1;

    void keyPressEvent(QKeyEvent *evento);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void Actualizar();
};

#endif // JUEGO_H
