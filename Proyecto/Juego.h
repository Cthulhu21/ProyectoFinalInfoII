#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <windows.h>
#include <QMessageBox>

#include "Jugador.h"
#include "Paredes.h"
#include "Enemigo.h"
#include "Comestible.h"

class Juego: public QGraphicsView
{
    Q_OBJECT
public:
    Juego(QWidget *parent = NULL );
    void Jugar();
    ~Juego();
private:
    QGraphicsTextItem *vidasLabel;
    int Vidas;

    int TiempoInvencible;

    QGraphicsTextItem *scoreLabel;
    int Puntuacion;
    void AumentarPuntuacion();

    QTimer *Timer;
    QTimer *TimerAnimaciones;

    void keyPressEvent(QKeyEvent *evento);

    QGraphicsScene *Pantalla;
    Jugador *Player;
    QList<Enemigo*> *Fantasmas;
    QList<Comestible*> *Comestibles;
    Paredes *Pared;

    void GameOver();

private slots:
    void Actualizar();
    void ActualizarFrames();
};

#endif // JUEGO_H
