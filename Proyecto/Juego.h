#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>

#include "Mapa.h"

#define PI 3.14159265

class Juego: public QGraphicsView
{
    Q_OBJECT
public:
    Juego(QWidget *parent = nullptr);
    ~Juego();

    void EmpezarJuego(unsigned int IDMapa=1);

private:
    QTimer *Timer;
    QGraphicsScene *Pantalla;
    Jugador *Player;
    Mapa *MapaActual;

    bool JuegoActivo=false;

    void SiguienteMapa();
    void GameOver();

    void InteraccionZonas(ZonaGravitacional *Zona, ObjetoMovible *Objeto, bool *Parar);
    void PegarObjetoAArma(ObjetoMovible *Objeto);
    void MomentoEnergia(ObjetoMovible *Objeto1, ObjetoMovible *Objeto2);

    unsigned int ContadorGlobal;

    int PantallaSizeX;
    int PantallaSizeY;

    const float Delta=0.1;

    void keyPressEvent(QKeyEvent *evento);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void Actualizar();
};

#endif // JUEGO_H
